#!/usr/bin/env python3
"""
Automated per-function matching loop — the rel_movie_viewer process, mechanised.

    scripts/auto_decomp.py rel_gallery                 # whole module
    scripts/auto_decomp.py rel_gallery --max-words 24  # only small functions
    scripts/auto_decomp.py rel_gallery --only func_00000123

For every function in a module it: slices the function out of splat's text.s,
asks m2c for a draft, rewrites the draft through a series of source shapes that
are known to change MWCC's codegen, compiles each candidate with the real
compiler, and keeps a candidate ONLY if scripts/mwcc_diff.py reports a
byte-identical match. Nothing unverified is ever recorded as matched.

Results go to build/auto/<module>.matched.json (verified source, per function)
and build/auto/<module>.json (every function's status, so a human knows where to
start on the rest).

The shape list is the accumulated knowledge from the two modules matched by
hand — see the file headers of src/rel_movie_viewer.c and src/rel_html_view.c
for why each one exists. Add to SHAPES as new levers are found; every module run
afterwards benefits.
"""
import argparse
import json
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
MWCC = os.path.join(ROOT, "tools/mwccpsp_3.0.1_219/mwccpsp.exe")
WIBO = os.path.join(ROOT, "tools/wibo-bin/wibo")
FLAGS = ["-O4,s", "-sdatathreshold", "0"]

# Most of the game is -O4,s, but not all of it. rel_title contains functions that
# only match at -O2,s: level 3 is where MWCC turns on instruction scheduling, so a
# target with an UNFILLED branch delay slot cannot have been built at -O4. A module
# is linked from several translation units and they were not all compiled alike, so
# each candidate is tried at both levels.
FLAG_SETS = [["-O4,s", "-sdatathreshold", "0"],
             ["-O2,s", "-sdatathreshold", "0"]]

# m2c writes its output in terms of these; MWCC has no stdint and no m2c header.
PRELUDE = """typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
#define NULL 0
#define M2C_UNK int
"""


# ---------------------------------------------------------------- asm slicing
def load_functions(module):
    """[(name, [asm lines], word count)] in address order."""
    path = os.path.join(ROOT, "asm", module, "text.s")
    funcs, cur, lines = [], None, []
    for line in open(path, errors="replace"):
        m = re.match(r"glabel (\w+)", line)
        if m:
            cur, lines = m.group(1), [line]
            continue
        if cur:
            lines.append(line)
            if line.startswith("endlabel"):
                words = sum(1 for l in lines if re.match(r"\s*/\* [0-9A-F]+ ", l))
                funcs.append((cur, lines, words))
                cur = None
    return funcs


def symbols(module):
    """Every name the linker knows about, so trials can declare what they use."""
    out = {}
    p = os.path.join(ROOT, "config/symbols", module + ".txt")
    if os.path.exists(p):
        for line in open(p):
            m = re.match(r"(\w+) = 0x([0-9A-Fa-f]+);(.*)", line)
            if m:
                out[m.group(1)] = "func" if "type:func" in m.group(3) else "data"
    return out


# Global types measured across the WHOLE module by scripts/gen_types.py, rather
# than guessed per function. 95% of named globals are accessed at exactly one
# width everywhere they appear, so the type is already decided by the binary.
# This matters most for big functions: the number of independent type decisions
# grows with size (median 3 at <=20 instructions, 22 above 160), and a function
# only matches if EVERY one is right, which is why the match rate collapses from
# 11% to 0% across that range. Using the measured type removes the guess.
_TYPE_CACHE = {}


def measured_types(module):
    if module in _TYPE_CACHE:
        return _TYPE_CACHE[module]
    out = {}
    path = os.path.join(ROOT, "include/globals", module + ".h")
    if os.path.exists(path):
        for line in open(path):
            m = re.match(r"extern (\w+) (\w+);", line)
            if m:
                out[m.group(2)] = m.group(1)
    _TYPE_CACHE[module] = out
    return out



# Width of a named global as used by THIS function. scripts/gen_types.py decides
# a type from every access across the module and deliberately declines when the
# module disagrees with itself — a global accessed as both a byte and a halfword
# is usually two fields sharing a base. Declining is right at module scope but
# useless here: the function in front of us uses exactly one width, and its own
# instructions say which. This recovers the ambiguous cases (66 globals, but
# they appear in far more functions) that would otherwise fall back to `char`
# and emit `sb` where the target has `sh`.
LOCAL_GLOBAL_ACCESS = re.compile(
    r"\*/\s+(l[bhw]u?|s[bhw]|lwc1|swc1)\s+\$\w+,\s*%lo\(([A-Za-z_]\w*)\)")
LOCAL_WIDTH_TYPE = {"lb": "char", "lbu": "unsigned char", "sb": "unsigned char",
                    "lh": "short", "lhu": "unsigned short", "sh": "unsigned short",
                    "lw": "int", "sw": "int", "lwc1": "float", "swc1": "float"}


def local_global_types(asm_lines):
    """{global: C type} from the widths this one function uses."""
    seen = {}
    for line in asm_lines:
        m = LOCAL_GLOBAL_ACCESS.search(line)
        if not m:
            continue
        t = LOCAL_WIDTH_TYPE.get(m.group(1))
        if t is None:
            continue
        prev = seen.get(m.group(2))
        if prev is None:
            seen[m.group(2)] = t
        elif prev != t:
            seen[m.group(2)] = None          # even locally inconsistent: give up
    return {k: v for k, v in seen.items() if v}

def referenced(asm_lines, symtab, self_name=None, data_type="char", types=None):
    """Declarations a candidate needs: imports it calls, globals it touches.

    m2c decides on its own whether a global is used as a scalar or a pointer, so
    a single declaration flavour cannot satisfy every draft — the caller retries
    with each of DATA_FLAVOURS until one compiles."""
    # module-wide measured types first, then this function's own usage for the
    # globals the module could not decide
    types = dict(local_global_types(asm_lines), **{k: v for k, v in (types or {}).items()})
    text = "".join(asm_lines)
    names = set(re.findall(r"\b\w+\b", text))
    decls = []
    for n in sorted(names & set(symtab)):
        decls.append(f"extern int {n}();" if symtab[n] == "func" else f"extern {data_type} {n};")
    for n in sorted(set(re.findall(r"\b(?:D|jtbl)_[0-9A-F]{4,8}\b", text))):
        if n not in symtab:
            decls.append(f"extern {(types or {}).get(n, data_type)} {n};")
    for n in sorted(set(re.findall(r"\bfunc_[0-9A-F]{8}\b", text))):
        if n != self_name:                     # never re-declare the function we define
            decls.append(f"extern int {n}();")
    return [d for d in decls if f" {self_name}(" not in d and f" {self_name};" not in d]


ASM_HEADER = '.include "macro.inc"\n\n.set noat\n.set noreorder\n\n.section .text, "ax"\n\n'


def slice_path(module, fn, lines, workdir):
    """m2c re-parses whatever .s you hand it, so give it ONE function. On
    rel_duel_eng (3 MB of text.s, 7487 functions) parsing the whole file per
    function would dominate the runtime."""
    p = os.path.join(workdir, f"{fn}.s")
    open(p, "w").write(ASM_HEADER + "".join(lines))
    return p


# ------------------------------------------------------------------ m2c draft
def m2c_draft(module, fn, ctx_path=None, asm_path=None):
    r = subprocess.run(
        [sys.executable, os.path.join(ROOT, "tools/m2c/m2c.py"), "-f", fn]
        + (["--context", ctx_path] if ctx_path else [])
        + [asm_path or os.path.join(ROOT, "asm", module, "text.s")],
        capture_output=True, text=True, cwd=ROOT)
    if r.returncode != 0:
        return None
    # keep everything from the function's definition line onward; m2c prints a
    # block of guessed prototypes above it, and we supply our own declarations
    lines = r.stdout.splitlines()
    start = None
    for i, line in enumerate(lines):
        if re.search(rf"\b{fn}\s*\(", line) and "{" in line:
            start = i
            break
    if start is None:
        return None
    body = lines[start:]
    src = "\n".join(body).strip()
    if not src or f"{fn}(" not in src:
        return None
    # m2c writes unknown types as '?'; make them compilable
    src = re.sub(r"\?\s*\*", "int *", src)   # int* not void*: m2c dereferences these
    src = re.sub(r"(?<![\w*])\?(?!\w)", "int", src)
    src = src.replace("static ", "")
    # --valid-syntax marks what m2c could not infer; make those compile. A
    # function containing M2C_ERROR is usually unmatchable anyway (m2c read an
    # unset register), but it costs nothing to let the compiler judge.
    src = re.sub(r"M2C_ERROR\([^)]*\)", "0", src)
    src = src.replace("M2C_UNK", "int")
    # m2c renders a load from an address it knows nothing about as *(void *)addr,
    # which is not a legal dereference; a word load is what the asm actually does
    src = src.replace("*(void *)", "*(int *)").replace("*(void*)", "*(int *)")
    # m2c writes unknown struct fields as `p->unk34`, which MWCC rejects because
    # nothing declares that struct. Rewrite to an explicit byte offset — the same
    # access the asm performs. This is the single biggest source of compile
    # failures in rel_duel_eng (3527 of ~4900 attempts).
    # The width is left as a placeholder rather than fixed at `int`: the access
    # width is whatever the target's load instruction does, and guessing `lw`
    # everywhere silently dooms every halfword and byte field. shape_field_width
    # below tries the alternatives.
    # m2c computes an address inside a global as `&D_0034E660 + (i * 0xB3C)`.
    # That offset is in BYTES, but `&D_x` now has the global's measured type, so
    # C scales it by the element size and the address is wrong — and assigning
    # the result to a local is an illegal pointer/int conversion besides.
    # Casting the base to int makes the arithmetic byte-accurate again and the
    # result assignable; the arrow rewriter above re-casts to `char *` wherever
    # the result is used as a base. Only `&D_x` followed by + or - is touched,
    # so `func(&D_x)` keeps passing a real address.
    src = re.sub(r"&((?:D|jtbl)_[0-9A-Fa-f]{4,8})(\s*[+-]\s)", r"((int)&\1)\2", src)
    src = rewrite_arrow_fields(src)
    src = fix_int_derefs(src)
    # m2c also declares PARAMETERS `void *` when it thinks a register holds a
    # pointer. The locals were retyped to int above; the parameters must follow
    # or `arg0 + 0x30` is "illegal operands 'void *' + 'int'".
    src = re.sub(r"\bvoid \*(arg\d+)\b", r"int \1", src)
    # NOT DONE: rewriting a bare `*temp_v0` to `*(int *)temp_v0`. Tried, and it
    # made compile failures WORSE (23 -> 29 on a fixed 60-function sample):
    # m2c uses those names for genuine pointers too, and forcing the cast broke
    # drafts that were already valid. Measured, reverted, recorded.

    # m2c declares a temp `void *` when it thinks a register holds a pointer,
    # then assigns it a plain int load (`temp = *(int *)0xB7AB0C;`), which MWCC
    # rejects as an illegal implicit conversion. Both are 32 bits and live in
    # the same register, so declaring the temp `int` makes every use legal —
    # the later `(char *)temp + 0x10` is then an explicit cast, which is fine.
    # This was the largest remaining compile failure for medium functions.
    # ...and the same for any other pointer-typed local m2c invents (`int *sp4C`,
    # `s32 *temp_v0`). It assigns int-returning calls and raw loads to these, so
    # every one is an illegal implicit conversion. All are 32 bits in the same
    # register, and the later uses are explicit casts, so `int` is safe.
    src = re.sub(r"^(\s*)(?:void|[su]?\d*int|s8|u8|s16|u16|s32|u32|f32|char|short|long)\s*\*(\w+);\s*$",
                 r"\1int \2;", src, flags=re.M)
    # A call through a struct field arrives as `(*(int *)(...))(args)`, which is
    # a call of a non-function. Cast it to a function pointer first.
    # NOT ATTEMPTED: casting `(*(int *)(...))(args)` to a function pointer.
    # The inner expression is parenthesised, and a regex cannot tell where it
    # ends — a non-greedy match happily runs past the closing paren to a later
    # `))(` on the same line and emits unbalanced output, breaking drafts that
    # would otherwise compile. docs/11 already recorded this trap for the arrow
    # form; it applies here too. Worth ~3 functions, needs a real parser.

    # A field access through a dereferenced literal address, which m2c writes
    # as `(*(int *)0xB7AB0C)->unk0`. Bounded enough to rewrite safely: the left
    # side is exactly a dereferenced hex constant, so there is no paren
    # ambiguity to get wrong.
    src = re.sub(r"\(\*\(int \*\)(0x[0-9A-Fa-f]+)\)->unk_?([0-9A-Fa-f]+)",
                 lambda m: f"(*(M2C_W *)((char *)*(int *){m.group(1)} + 0x{m.group(2)}))", src)
    # And the mirror of the void*-temp fix: m2c loads through `*(void **)ADDR`
    # for the same registers it declared `void *`. Those declarations are now
    # `int`, so the loads must be `*(int *)` too or the conversion is illegal.
    src = src.replace("*(void **)", "*(int *)")
    # m2c also renders a field of a GLOBAL it believes is a struct with a dot,
    # `D_00054BD0.unk10`, which MWCC rejects with "not a struct/union/class"
    # because our declaration is a scalar. Same rewrite, taking the address
    # instead of using the pointer. This is the single biggest compile failure
    # for medium functions — 12 of 27 in a sample of 81-160 instruction drafts,
    # where the arrow form barely appears.
    src = re.sub(r"\b([A-Za-z_]\w*)\.unk_?([0-9A-Fa-f]+)",
                 lambda m: f"(*(M2C_W *)((char *)&{m.group(1)} + 0x{m.group(2)}))", src)
    # Only the simple `identifier->unkNN` case is rewritten. A parenthesised
    # left-hand side needs balanced-paren handling that a regex cannot do safely —
    # an earlier attempt produced unbalanced output and broke otherwise-valid
    # drafts, so those are left for the compiler to reject.
    return src



# Field widths read from the target instead of guessed. m2c renders an unknown
# struct field as `p->unkNN`; the width of that access is not a mystery — the
# load or store the target performs at that offset states it exactly. Reading it
# beats trying one global width for every field in the function, which can never
# be right when a function touches both a byte field and a word field.
OPCODE_TYPE = {"lb": "char", "lbu": "unsigned char", "lh": "short",
               "lhu": "unsigned short", "lw": "int",
               "sb": "unsigned char", "sh": "unsigned short", "sw": "int"}
LOADSTORE = re.compile(r"\*/\s+(l[bhw]u?|s[bhw])\s+\$\w+,\s*(-?0x[0-9A-Fa-f]+|0)\(\$\w+\)")


def field_widths(asm_lines):
    """{byte offset: C type} for every field the target loads or stores.

    An offset accessed at two different widths is ambiguous (two structs sharing
    a base register) and is left out, so the caller falls back to the search."""
    out = {}
    for line in asm_lines:
        m = LOADSTORE.search(line)
        if not m:
            continue
        raw = m.group(2)
        off = int(raw, 16) if raw.startswith(("0x", "-0x")) else int(raw)
        t = OPCODE_TYPE.get(m.group(1))
        if t is None:
            continue
        if off in out and out[off] != t:
            out[off] = None
        else:
            out.setdefault(off, t)
    return {k: v for k, v in out.items() if v}


def apply_field_widths(src, widths):
    """Substitute each M2C_W with the width the target proves for that offset."""
    def repl(m):
        off = int(m.group(2), 16)
        t = widths.get(off)
        return (f"(*({t} *)((char *){m.group(1)} + 0x{m.group(2)}))" if t
                else m.group(0))
    return re.sub(r"\(\*\(M2C_W \*\)\(\(char \*\)(\w+) \+ 0x([0-9A-Fa-f]+)\)\)",
                  repl, src)




def fix_int_derefs(src):
    """Restore the pointer cast on a dereference of int address arithmetic.

    Casting `&D_x` to int (above) makes byte offsets scale correctly, but m2c
    also writes plain `*(base + off)` for a word load. Once base is an int that
    dereference is illegal, and it became the single largest compile failure
    (68 of 200 sampled drafts) — a class this pipeline introduced itself while
    fixing the scaling.

    Rewrite `*(EXPR)` to `*(int *)(EXPR)` when EXPR contains the `(int)&` marker
    and is not already cast. Uses a paren scanner rather than a regex for the
    same reason as rewrite_arrow_fields: the expression is parenthesised and its
    end cannot be found by pattern alone.
    """
    out, i = src, 0
    while True:
        j = out.find("*(", i)
        if j < 0:
            break
        # skip forms that already carry a cast, e.g. `*(int *)(...)`
        after = out[j + 2:j + 40]
        if re.match(r"\s*(?:unsigned |signed )?\w+\s*\*\s*\)", after):
            i = j + 2
            continue
        depth, k = 0, j + 1
        while k < len(out):
            if out[k] == "(":
                depth += 1
            elif out[k] == ")":
                depth -= 1
                if depth == 0:
                    break
            k += 1
        if k >= len(out):
            break
        inner = out[j + 2:k]
        if "(int)&" in inner:
            out = out[:j] + "*(int *)(" + inner + ")" + out[k + 1:]
            i = j + 9 + len(inner)
        else:
            i = j + 2
    return out

def rewrite_arrow_fields(src):
    """Rewrite `EXPR->unkNN` for ANY left-hand side, not just a bare identifier.

    m2c writes a field of a computed address as `(base + i*0x14)->unk34`, which
    MWCC rejects because nothing declares that struct. The bare-identifier case
    has always been rewritten; the parenthesised case is the single biggest
    compile failure left (28 of 300 sampled functions, plus much of the
    "pointer/array required" class).

    docs/11 records an earlier attempt with a regex that emitted unbalanced
    parentheses and broke working drafts, because a regex cannot find where a
    parenthesised expression starts. This scans backwards with a paren counter
    instead, which can: from the `->` walk left over a balanced group, or over a
    plain identifier, and take that as the base.
    """
    out = src
    while True:
        m = re.search(r"->unk_?([0-9A-Fa-f]+)", out)
        if not m:
            break
        off, end = m.group(1), m.end()
        i = m.start() - 1
        while i >= 0 and out[i] == " ":
            i -= 1
        if i < 0:
            break
        if out[i] == ")":
            depth, j = 0, i
            while j >= 0:
                if out[j] == ")":
                    depth += 1
                elif out[j] == "(":
                    depth -= 1
                    if depth == 0:
                        break
                j -= 1
            if j < 0:
                break
            start = j
        else:
            j = i
            while j >= 0 and (out[j].isalnum() or out[j] == "_"):
                j -= 1
            start = j + 1
            if start > i:
                break
        base = out[start:i + 1]
        out = out[:start] + f"(*(M2C_W *)((char *){base} + 0x{off}))" + out[end:]
    return out


# ------------------------------------------------------------------- reshapes
def shape_identity(src):
    return src


def shape_while_to_goto(src):
    """MWCC rotates `while (c) {b}` to a bottom test with an entry branch; the
    explicit goto form keeps the target's top test (rel_html_view func_00000034)."""
    m = re.search(r"(\s*)while \((.+?)\) \{\n(.*?)\n\1\}", src, re.S)
    if not m:
        return None
    ind, cond, body = m.groups()
    return src[:m.start()] + (
        f"\n{ind}_loop:\n{ind}if (!({cond})) goto _done;\n{body}\n{ind}goto _loop;\n{ind}_done:;"
    ) + src[m.end():]


def shape_dup_return(src):
    """A shared `return r;` makes MWCC pick the branch-likely form and schedule
    the return-value move into the delay slot; duplicating it inside the failure
    branch gives the plain branch (rel_html_view func_00000178/278)."""
    m = re.search(r"if \((\w+) < 0\) \{\n(.*?)\n(\s*)\}\n(\s*)return \1;", src, re.S)
    if not m:
        return None
    var, body, ind, ind2 = m.groups()
    return (src[:m.start()] +
            f"if ({var} < 0) {{\n{body}\n{ind}    return {var};\n{ind}}}\n{ind2}return {var};" +
            src[m.end():])


def shape_single_switch(src):
    """MWCC compiles a switch by branching INTO the case body; an equivalent if
    inlines it and comes out shorter. Even a one-case switch is distinct
    (rel_movie_viewer func_000001C8)."""
    m = re.search(r"(\s*)if \((\w+) == (\w+)\) \{\n(.*?)\n\1\}", src, re.S)
    if not m:
        return None
    ind, var, val, body = m.groups()
    return (src[:m.start()] +
            f"\n{ind}switch ({var}) {{\n{ind}case {val}:\n{body}\n{ind}    break;\n{ind}}}" +
            src[m.end():])


DATA_FLAVOURS = ["char", "void *", "int"]

# Widths tried for m2c's unknown struct fields (the M2C_W placeholder). The
# access width is whatever the target's load does; forcing `int` everywhere
# quietly dooms every halfword and byte field, which is how a family of 35
# rel_story getters and setters ended up needing to be fixed by hand.
FIELD_WIDTHS = ["int", "unsigned short", "unsigned char"]

def shape_baked_address(src):
    """Some globals are baked into the ORIGINAL as raw absolute immediates with
    no relocation at all. Declaring them as extern symbols forces a HI16/LO16
    relocation and can never match; a literal `*(int *)0xADDR` reproduces the
    baked constant. (Found on rel_umd_replace func_00003898.)"""
    out = re.sub(r"&(D_([0-9A-F]{4,8}))\b", lambda m: f"(int *)0x{m.group(2)}", src)
    out = re.sub(r"\bD_([0-9A-F]{4,8})\b(?!\s*\()", lambda m: f"(*(int *)0x{m.group(1)})", out)
    return out if out != src else None


def shape_tail_return(src):
    """m2c often ends a function with a bare call where the original wrote
    `return f(...);`. MWCC turns the latter into a real tail call (`j f` with the
    last argument in the delay slot) and the former into jal+return, so the two
    differ by a word or more. 280 functions across the project were exactly one
    word short of their target — this is the shape that closes them."""
    m = re.search(r"\n([ \t]*)([A-Za-z_]\w*\([^;{}]*\));\n\}\s*$", src)
    if not m:
        return None
    out = src[:m.start()] + f"\n{m.group(1)}return {m.group(2)};\n}}\n"
    return re.sub(r"^void(\s+\w+\s*\()", r"int\1", out, count=1, flags=re.M)


def make_thunk_shape(extra):
    """m2c only sees arguments the function TOUCHES. A thunk that forwards its
    trailing parameter untouched (zero instructions for that register) therefore
    comes out with too few parameters, and no reshuffling of the body can fix it.
    These variants re-add passthrough parameters and make the call a tail call,
    which is the shape the originals use throughout the UI modules.

    CONFIRMED: mwccpsp passes integer arguments 5..8 in $t0-$t3, not on the
    stack (verified by an 8-argument passthrough test and by matched functions
    in rel_tutorial). So parameters beyond the fourth are worth trying — this is
    why the range goes past 4."""
    def shape(src):
        m = re.match(r"\s*([\w \*]+?)\s+(func_[0-9A-F]+)\s*\(([^)]*)\)\s*\{\s*"
                     r"(?:return\s+)?([A-Za-z_]\w*)\s*\(([^;]*)\)\s*;\s*\}\s*$", src, re.S)
        if not m:
            return None
        _ret, fn, params, callee, args = m.groups()
        params = [] if params.strip() in ("", "void") else [p.strip() for p in params.split(",")]
        args = [a.strip() for a in args.split(",")] if args.strip() else []
        for i in range(extra):
            params.append(f"s32 pass{i}")
            args.append(f"pass{i}")
        return (f"int {fn}({', '.join(params) or 'void'}) {{\n"
                f"    return {callee}({', '.join(args)});\n}}\n")
    return shape


def make_leading_dummy_shape(n):
    """When the target only ever touches $a1 (or $a2) and passes $a0 straight
    through, m2c declares one parameter, which the compiler places in $a0. Adding
    unused LEADING parameters pushes the real one into the register the target
    actually uses. (Found on rel_duel_draw — about 10 of 23 fixes in one batch.)"""
    def shape(src):
        m = re.match(r"(\s*[\w \*]+?\s+func_[0-9A-F]+\s*\()([^)]*)(\))", src, re.S)
        if not m:
            return None
        params = m.group(2).strip()
        if params in ("", "void"):
            return None
        dummies = ", ".join(f"s32 unused{i}" for i in range(n))
        return src[:m.end(1)] + dummies + ", " + params + src[m.start(3):]
    return shape


def shape_bool_fold(src):
    """At -O4,s only `!f()` folds into beqz/bnez; `f() == 0` materialises the
    comparison. m2c writes the explicit comparison, so try the negation form."""
    out = re.sub(r"\(([\w\.\->\[\]]+(?:\([^()]*\))?) == 0\)", r"(!\1)", src)
    out = re.sub(r"\(([\w\.\->\[\]]+(?:\([^()]*\))?) != 0\)", r"(\1)", out)
    return out if out != src else None


def shape_void_return(src):
    """If the target never sets $v0 before `jr $ra` the function is void; a
    phantom `return 0;` makes MWCC emit an extra `move $v0, $zero`. m2c adds one
    whenever it cannot tell, so try dropping it."""
    m = re.search(r"\n\s*return 0;\s*\n\}\s*$", src)
    if not m:
        return None
    out = src[:m.start()] + "\n}\n"
    return re.sub(r"^(?:int|s32|u32)(\s+func_[0-9A-F]+\s*\()", r"void\1", out, count=1, flags=re.M)


SHAPES = [
    ("m2c", shape_identity),
    ("void-return", shape_void_return),
    ("bool-fold", shape_bool_fold),
    ("lead-dummy1", make_leading_dummy_shape(1)),
    ("lead-dummy2", make_leading_dummy_shape(2)),
    ("thunk+1", make_thunk_shape(1)),
    ("thunk+2", make_thunk_shape(2)),
    ("thunk+3", make_thunk_shape(3)),
    ("thunk+4", make_thunk_shape(4)),
    ("thunk+5", make_thunk_shape(5)),
    ("thunk+0", make_thunk_shape(0)),
    ("tail-return", shape_tail_return),
    ("baked-address", shape_baked_address),
    ("goto-loop", shape_while_to_goto),
    ("dup-return", shape_dup_return),
    ("single-switch", shape_single_switch),
]


# -------------------------------------------------------------------- compile
def try_candidate(module, fn, decls, body, workdir, flags=None):
    src = PRELUDE + "\n" + "\n".join(decls) + "\n\n" + body + "\n"
    open(os.path.join(workdir, f"{fn}.c"), "w").write(src)
    r = subprocess.run([WIBO, MWCC, "-c", *(flags or FLAGS), "-o", f"{fn}.o", f"{fn}.c"],
                       capture_output=True, text=True, cwd=workdir)
    if r.returncode != 0:
        return None, "compile-error"
    d = subprocess.run([sys.executable, os.path.join(ROOT, "scripts/mwcc_diff.py"),
                        os.path.join(ROOT, "asm", module, "text.s"),
                        os.path.join(workdir, f"{fn}.o"), fn],
                       capture_output=True, text=True, cwd=ROOT)
    verdict = d.stdout.strip().splitlines()[0] if d.stdout.strip() else "no-output"
    return ("MATCH" in verdict and "MISMATCH" not in verdict), verdict



# Prototypes with the REAL argument count, from scripts/gen_context.py. m2c
# decides how many arguments a call passes by looking at the call site, and it
# only reliably sees $a0-$a3; arguments five to eight travel in $t0-$t3, and a
# tail-call trampoline sets some and jumps without touching the rest, so nothing
# at the call site reveals them. m2c then emits a call with too few arguments
# and the draft compiles to FEWER instructions than the target. Feeding it real
# prototypes fixes that at the source.
#
# These go ONLY into m2c's context, never into the compiled source: the compiled
# source keeps K&R `extern int f();` declarations, because a strict prototype
# makes MWCC reject perfectly good drafts that pass a pointer where the
# prototype says s32.
def load_prototypes(module):
    path = os.path.join(ROOT, "build/ctx", module + ".h")
    if not os.path.exists(path):
        return {}
    out = {}
    for line in open(path):
        m = re.match(r"(?:s32|void)\s+(\w+)\(", line)
        if m:
            out[m.group(1)] = line.strip()
    return out


def contextualise(decls, protos):
    """Swap K&R externs for measured prototypes, for m2c's eyes only."""
    out = []
    for d in decls:
        m = re.match(r"extern \w+ ((?:func|ehsys)_[0-9A-F]+)\(\)", d)
        if m and m.group(1) in protos:
            out.append(protos[m.group(1)])
        else:
            out.append(d)
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("module")
    ap.add_argument("--max-words", type=int, default=10**9)
    ap.add_argument("--only")
    ap.add_argument("--dump", metavar="DIR",
                    help="on a NEAR MISS, write the closest candidate's source to "
                         "DIR/<func>.c. The pipeline otherwise throws it away, "
                         "which makes the near-miss queue impossible to classify "
                         "in bulk: you can see that a function is one instruction "
                         "off but not what the instruction is.")
    ap.add_argument("--limit", type=int, default=10**9)
    ap.add_argument("--shard", default="1/1",
                    help="i/N — process every Nth function, so N processes can run "
                         "in parallel on one module (results merge by filename)")
    args = ap.parse_args()

    mod = args.module
    workdir = os.path.join(ROOT, "build/auto", mod)
    os.makedirs(workdir, exist_ok=True)
    symtab = symbols(mod)
    # Real argument counts for every callee (scripts/gen_context.py).
    # Generated on demand so a fresh clone needs no extra step.
    if not os.path.exists(os.path.join(ROOT, 'build/ctx', mod + '.h')):
        subprocess.run([sys.executable, os.path.join(ROOT, 'scripts/gen_context.py'), mod],
                       capture_output=True, cwd=ROOT)
    protos = load_prototypes(mod)

    results, matched = [], []
    funcs = load_functions(mod)
    todo = [f for f in funcs if f[2] <= args.max_words and
            (not args.only or f[0] == args.only)][:args.limit]
    si, sn = (int(x) for x in args.shard.split("/"))
    tag = "" if sn == 1 else f".{si}of{sn}"
    if sn > 1:
        todo = todo[si - 1::sn]
    print(f"{mod}: {len(funcs)} functions, trying {len(todo)}", flush=True)

    for i, (fn, lines, words) in enumerate(todo):
        best, hit, best_src = None, False, None
        for flavour in DATA_FLAVOURS:
            decls = referenced(lines, symtab, fn, flavour, measured_types(mod))
            ctx = os.path.join(workdir, f"{fn}.ctx.c")
            open(ctx, "w").write(PRELUDE + "\n"
                                 + "\n".join(contextualise(decls, protos)) + "\n")
            draft = m2c_draft(mod, fn, ctx, slice_path(mod, fn, lines, workdir))
            fw = field_widths(lines)
            if not draft:
                continue
            compiled = False
            for name, shape in SHAPES:
                shaped = shape(draft)
                if not shaped:
                    continue
                ok = False
                # Only iterate widths when the draft actually has unknown fields,
                # so functions without them cost nothing extra.
                # Try the widths the TARGET proves first, then fall back to the
                # blind search for any offset the asm did not disambiguate.
                if "M2C_W" in shaped:
                    exact = apply_field_widths(shaped, fw)
                    widths = ([("asm", exact)] if "M2C_W" not in exact else []) + \
                             [(w, shaped.replace("M2C_W", w)) for w in FIELD_WIDTHS]
                else:
                    widths = [(FIELD_WIDTHS[0], shaped)]
                for width, body in widths:
                    for fl in FLAG_SETS:
                        ok, verdict = try_candidate(mod, fn, decls, body, workdir, fl)
                        if ok:
                            if width != FIELD_WIDTHS[0]:
                                name += f" {width}-fields"
                            name = name if fl is FLAG_SETS[0] else name + " -O2"
                            break
                    if ok:
                        break
                if verdict != "compile-error":
                    compiled = True
                if ok:
                    matched.append({"func": fn, "words": words, "shape": name,
                                    "flavour": flavour, "src": body})
                    results.append({"func": fn, "words": words, "status": "MATCH",
                                    "shape": name})
                    hit = True
                    break
                if best is None or (best == "compile-error" and verdict != "compile-error"):
                    best, best_src = verdict, body
            # the declaration flavour exists only to make the draft COMPILE; once
            # it does, the other flavours would just recompile the same code
            if hit or compiled:
                break
        if not draft and not hit and best is None:
            results.append({"func": fn, "words": words, "status": "m2c-failed"})
            continue
        if not hit:
            results.append({"func": fn, "words": words, "status": "no-match", "closest": best})
            if args.dump and best_src:
                os.makedirs(args.dump, exist_ok=True)
                open(os.path.join(args.dump, fn + ".c"), "w").write(
                    f"/* {fn}: {best} */\n"
                    + "\n".join(referenced(lines, symtab, fn, DATA_FLAVOURS[0],
                                            measured_types(mod)))
                    + "\n" + best_src + "\n")
        if (i + 1) % 25 == 0:
            n = sum(1 for r in results if r["status"] == "MATCH")
            print(f"  {i+1}/{len(todo)} tried, {n} matched", flush=True)
            # checkpoint: a long run must never lose its results to a kill
            json.dump({"module": mod, "tried": i + 1, "matched": n, "results": results},
                      open(os.path.join(ROOT, f"build/auto/{mod}{tag}.json"), "w"), indent=1)
            json.dump(matched,
                      open(os.path.join(ROOT, f"build/auto/{mod}{tag}.matched.json"), "w"), indent=1)

    n = sum(1 for r in results if r["status"] == "MATCH")
    if args.only:      # a single-function probe must never clobber the module's results
        # print the closest verdict too: a probe is almost always run to see WHY
        # a function fails, and "no match" alone forces a second, slower run.
        detail = next((r.get("closest") for r in results if r.get("closest")), None)
        print(f"{mod} {args.only}: {'MATCH' if n else 'no match'}"
              + (f" [{detail}]" if detail and not n else ""))
        return
    out = {"module": mod, "tried": len(todo), "matched": n, "results": results}
    json.dump(out, open(os.path.join(ROOT, f"build/auto/{mod}{tag}.json"), "w"), indent=1)
    json.dump(matched, open(os.path.join(ROOT, f"build/auto/{mod}{tag}.matched.json"), "w"), indent=1)
    print(f"{mod}: MATCHED {n}/{len(todo)}  -> build/auto/{mod}.matched.json")


if __name__ == "__main__":
    main()
