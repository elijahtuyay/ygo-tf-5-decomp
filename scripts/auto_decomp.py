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


def referenced(asm_lines, symtab, self_name=None, data_type="char"):
    """Declarations a candidate needs: imports it calls, globals it touches.

    m2c decides on its own whether a global is used as a scalar or a pointer, so
    a single declaration flavour cannot satisfy every draft — the caller retries
    with each of DATA_FLAVOURS until one compiles."""
    text = "".join(asm_lines)
    names = set(re.findall(r"\b\w+\b", text))
    decls = []
    for n in sorted(names & set(symtab)):
        decls.append(f"extern int {n}();" if symtab[n] == "func" else f"extern {data_type} {n};")
    for n in sorted(set(re.findall(r"\b(?:D|jtbl)_[0-9A-F]{4,8}\b", text))):
        if n not in symtab:
            decls.append(f"extern {data_type} {n};")
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
    src = re.sub(r"([A-Za-z_]\w*)->unk_?([0-9A-Fa-f]+)",
                 lambda m: f"(*(M2C_W *)((char *){m.group(1)} + 0x{m.group(2)}))", src)
    # Only the simple `identifier->unkNN` case is rewritten. A parenthesised
    # left-hand side needs balanced-paren handling that a regex cannot do safely —
    # an earlier attempt produced unbalanced output and broke otherwise-valid
    # drafts, so those are left for the compiler to reject.
    return src


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


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("module")
    ap.add_argument("--max-words", type=int, default=10**9)
    ap.add_argument("--only")
    ap.add_argument("--limit", type=int, default=10**9)
    ap.add_argument("--shard", default="1/1",
                    help="i/N — process every Nth function, so N processes can run "
                         "in parallel on one module (results merge by filename)")
    args = ap.parse_args()

    mod = args.module
    workdir = os.path.join(ROOT, "build/auto", mod)
    os.makedirs(workdir, exist_ok=True)
    symtab = symbols(mod)

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
        best, hit = None, False
        for flavour in DATA_FLAVOURS:
            decls = referenced(lines, symtab, fn, flavour)
            ctx = os.path.join(workdir, f"{fn}.ctx.c")
            open(ctx, "w").write(PRELUDE + "\n" + "\n".join(decls) + "\n")
            draft = m2c_draft(mod, fn, ctx, slice_path(mod, fn, lines, workdir))
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
                widths = FIELD_WIDTHS if "M2C_W" in shaped else FIELD_WIDTHS[:1]
                for width in widths:
                    body = shaped.replace("M2C_W", width)
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
                    best = verdict
            # the declaration flavour exists only to make the draft COMPILE; once
            # it does, the other flavours would just recompile the same code
            if hit or compiled:
                break
        if not draft and not hit and best is None:
            results.append({"func": fn, "words": words, "status": "m2c-failed"})
            continue
        if not hit:
            results.append({"func": fn, "words": words, "status": "no-match", "closest": best})
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
        print(f"{mod} {args.only}: {'MATCH' if n else 'no match'}")
        return
    out = {"module": mod, "tried": len(todo), "matched": n, "results": results}
    json.dump(out, open(os.path.join(ROOT, f"build/auto/{mod}{tag}.json"), "w"), indent=1)
    json.dump(matched, open(os.path.join(ROOT, f"build/auto/{mod}{tag}.matched.json"), "w"), indent=1)
    print(f"{mod}: MATCHED {n}/{len(todo)}  -> build/auto/{mod}.matched.json")


if __name__ == "__main__":
    main()
