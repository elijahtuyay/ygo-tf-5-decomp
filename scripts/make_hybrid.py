#!/usr/bin/env python3
"""
Build a hybrid C file: our matched C plus INCLUDE_ASM for everything else.

    scripts/make_hybrid.py rel_soundtest

WHY. `make MODULE=x SRC=1` replaces a module's entire .text with our compiled
object, so a module can only pass once EVERY function matches. 19 of the 28
modules contain hand-written assembly that can never come from C, so under that
rule they could never be completed at all (docs/13). The fix is the standard
decomp one: compile the functions we have, assemble the rest, and splice them
into one object.

mwcc cannot do this alone — it rejects GCC-style `__asm__(".include ...")`,
which is why include/include_asm.h has never actually worked with the real
compiler. tools/mwccgap does the splicing instead: it replaces each INCLUDE_ASM
body with correctly-sized nops, compiles, assembles the .s separately, then
transplants the bytes and fixes up symbols and relocations.

This script emits build/hybrid/<module>.c, which is src/<module>.c with an
INCLUDE_ASM line added, IN ADDRESS ORDER, for every function the C does not
define. Address order matters: the linker lays functions out sequentially, so
the file order must match the shipped layout exactly.
"""
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "scripts"))
import progress  # noqa: E402


def split_asm(module):
    """One .s per function, with the file's header directives preserved."""
    # Split the PREPARED disassembly, not the raw one. asm/<m>/text.s still
    # contains Allegrex opcodes gas cannot assemble (`min`, `max`, the VFPU
    # block); scripts/asm_prepare.py rewrites exactly those into .word with the
    # identical encoding. Without this every module using them fails to
    # assemble here even though the normal build handles them fine.
    src = os.path.join(ROOT, "build/asm", module, "text.s")
    if not os.path.exists(src):
        os.makedirs(os.path.dirname(src), exist_ok=True)
        subprocess.run([sys.executable, os.path.join(ROOT, "scripts/asm_prepare.py"),
                        os.path.join(ROOT, "asm", module, "text.s"), src, "--",
                        "mips-linux-gnu-as", "-march=mips32r2", "-mabi=32", "-EL",
                        "--no-pad-sections", "-I", os.path.join(ROOT, "include"),
                        "-I", os.path.join(ROOT, "asm", module)], check=True, cwd=ROOT)
    out_dir = os.path.join(ROOT, "build/hybrid/asm", module)
    os.makedirs(out_dir, exist_ok=True)
    lines = open(src, errors="replace").read().splitlines()
    # mwccgap's .s preprocessor only accepts a bare `.section .text` or
    # `.section .rodata`; splat emits `.section .text, "ax"`, which it rejects.
    # It also does its own .set handling, so the header is normalised here.
    header = ['.include "macro.inc"', ".set noat", ".set noreorder",
              ".section .text"]
    chunks, cur = {}, None
    for line in lines:
        m = re.match(r"glabel (func_[0-9A-F]+)", line)
        if m:
            cur = m.group(1)
            chunks[cur] = []
        if cur is not None:
            chunks[cur].append(line)
        if line.startswith("endlabel"):
            cur = None

    # Splitting one .text into a file per function leaves any reference that
    # CROSSES a function boundary dangling, because gas keeps `.L` labels out
    # of the symbol table:
    #
    #     undefined reference to `.L00013B2C'
    #
    # In rel_cutin_viewer these are not branches. They are absolute address
    # references — `lui %hi(.L00010B48)` / `sw %lo(.L00010B48)($v0)` — from one
    # function to a location splat labelled inside another. Every such name
    # encodes its own vram, so the Makefile resolves them exactly as it already
    # resolves D_XXXXXXXX and jtbl_XXXXXXXX: PROVIDE the address to the linker.
    # See the srcsyms.ld rule.
    #
    # Two alternatives were tried and rejected. `.globl` on the label breaks
    # mwccgap, which sizes its nop placeholder by counting lines it does not
    # recognise as directives and has no case for `.globl` — each one inflates
    # the placeholder and trips its own "Not enough assembly to fill" assertion;
    # patching mwccgap is no good either, since tools/ is gitignored so the fix
    # would neither be committed nor reproduce. Merging the two functions into
    # one .s is wrong for a different reason: it assumes splat split one real
    # function, and here the referenced functions are not even adjacent.
    # `alabel` marks an alternate entry point inside a function, and macro.inc
    # expands it to `.global NAME`. A GLOBAL symbol cannot be resolved by the
    # assembler — it might be interposed at link time — so every branch to one
    # becomes a relocation instead of a computed offset, and mwccgap's transplant
    # does not carry those through correctly. rel_field failed with ten of them:
    #
    #     func_00036160: (.text+0x40): relocation truncated to fit:
    #                    R_MIPS_PC16 against `func_000361B0'
    #
    # The distance is 0x10. Nothing is out of range; the relocation is simply
    # wrong. Where an alternate entry is only ever reached from inside its own
    # function and is never named by the C, it does not need to be global at
    # all. Emitting it as a plain label lets gas resolve the branch at assembly
    # time and no relocation is produced.
    c_path = os.path.join(ROOT, "src", module + ".c")
    c_text = open(c_path).read() if os.path.exists(c_path) else ""
    demoted = 0
    for name, body in chunks.items():
        local = set()
        for line in body:
            m = re.match(r"\s*alabel\s+(\S+)", line)
            if not m:
                continue
            sym = m.group(1)
            elsewhere = any(sym in l for n2, b2 in chunks.items()
                            if n2 != name for l in b2)
            if not elsewhere and not re.search(r"\b" + re.escape(sym) + r"\b", c_text):
                local.add(sym)
        if local:
            # Neither keeping nor renaming these symbols works, so remove them.
            #
            # Kept as `alabel`, macro.inc makes them .global, and mwccgap
            # defines them at an offset relative to the FUNCTION rather than the
            # section: rel_tutorial's func_00006818 came out at 0x60, which is
            # exactly 0x6818 - 0x67B8. Every jump through it then lands
            # somewhere arbitrary, which is why the module built to the right
            # size and still failed its sha1.
            #
            # Renamed to `.L`, they become local symbols, and mwccgap's
            # relocation fix-up indexes rodata_section_indices[0] whenever any
            # local symbol was inserted — IndexError on a module with no
            # .rodata at all.
            #
            # mwccgap cannot be patched: tools/ is gitignored, so the fix would
            # not be committed. But nothing actually needs the symbol. The
            # disassembly records each instruction's exact encoding, so every
            # reference can be emitted as that literal word — no symbol, no
            # relocation, byte-exact by construction. asm_prepare.py already
            # does this for the Allegrex opcodes gas cannot assemble.
            out_body, rewritten = [], 0
            for line in body:
                m = re.match(r"^\s*alabel\s+(\S+)\s*$", line)
                if m and m.group(1) in local:
                    continue                       # label no longer needed
                m = re.match(r"^(\s*/\* [0-9A-F]+ [0-9A-F]+ ([0-9A-F]{8}) \*/)(\s+)(.*)$",
                             line)
                if m and any(re.search(r"\b" + re.escape(sym) + r"\b", m.group(4))
                             for sym in local):
                    raw = m.group(2)
                    word = int.from_bytes(bytes.fromhex(raw), "little")
                    line = f"{m.group(1)}{m.group(3)}.word 0x{word:08X}"
                    rewritten += 1
                out_body.append(line)
            body = out_body
            chunks[name] = body
            demoted += rewritten
        with open(os.path.join(out_dir, name + ".s"), "w") as fh:
            fh.write("\n".join(header) + "\n")
            fh.write("\n".join(body) + "\n")
    if demoted:
        print(f"  {demoted} reference(s) to intra-function alternate entry "
              f"points emitted as literal words")
    return len(chunks)


def defined_in_c(text):
    return set(re.findall(r"^[A-Za-z_][\w \*]*?\b(func_[0-9A-F]+)\s*\([^;]*$",
                          text, re.M))


def _split_extern(rest):
    """('void * D_00027918') -> ('D_00027918', 'void*'). None if unparsable."""
    t = re.sub(r"\(\s*[^)]*\)\s*$", "", rest.strip())   # trailing (args)
    t = re.sub(r"\[[^\]]*\]\s*$", "", t.strip())        # trailing [n]
    m = re.search(r"([A-Za-z_]\w*)\s*$", t)
    if not m:
        return None, None
    return m.group(1), re.sub(r"\s+", "", t[:m.start(1)])


_EXTERN_RE = re.compile(r"^(\s*)extern\s+(.*);\s*$")


def _typedef_map(lines):
    """The file's own scalar typedefs, so `s32` and `int` compare equal."""
    out = {}
    for line in lines:
        m = re.match(r"^typedef\s+(.+?)\s+([A-Za-z_]\w*)\s*;\s*$", line.strip())
        if m:
            out[m.group(2)] = re.sub(r"\s+", "", m.group(1))
    # Resolve chains (typedef int s32; typedef s32 foo;).
    for _ in range(4):
        out = {k: out.get(v, v) for k, v in out.items()}
    return out


def _canon_type(typ, typedefs):
    """Normalise a declaration's type so equivalent spellings collapse."""
    stars = typ.count("*")
    base = typedefs.get(typ.replace("*", ""), typ.replace("*", ""))
    return base + "*" * stars


def _contested_externs(lines):
    """Symbols this file declares extern at genuinely DIFFERENT types.

    Compared after resolving the file's typedefs: src/rel_story.c declares
    D_0002F128 as `s32` in one place and `int` in another, which is the same
    type spelled two ways. Treating those as a conflict would push a shared
    declaration down into one function's body and hide it from the others,
    which is exactly the bug this guards against.
    """
    typedefs = _typedef_map(lines)
    seen = {}
    for line in lines:
        m = _EXTERN_RE.match(line)
        if not m:
            continue
        name, typ = _split_extern(m.group(2))
        if name:
            seen.setdefault(name, set()).add(_canon_type(typ, typedefs))
    return {n for n, types in seen.items() if len(types) > 1}


def _param_count(code, start):
    """Number of parameters in the definition beginning at line `start`."""
    text, depth = "", 0
    for i in range(start, min(start + 12, len(code))):
        for ch in code[i]:
            if ch == "(":
                depth += 1
                if depth == 1:
                    continue
            elif ch == ")":
                depth -= 1
                if depth == 0:
                    inner = text.strip()
                    if not inner or inner == "void":
                        return 0
                    return inner.count(",") + 1
            if depth >= 1:
                text += ch
    return None


def _call_arg_counts(code, a, b, name, skip_lines):
    """Argument counts of every call to `name` in code[a:b]."""
    counts = []
    pat = re.compile(r"\b" + name + r"\s*\(")
    for i in range(a, b):
        # `extern int func_X();` is a declaration, not a call. Counting those as
        # zero-argument calls flagged 1,131 of rel_duel_eng's 1,318 C functions
        # when the compiler finds exactly two real conflicts.
        if "extern" in code[i] or i in skip_lines:
            continue                      # a declaration or a definition head
        for m in pat.finditer(code[i]):
            depth, args, seen, text = 0, 0, False, ""
            j, k = i, m.end() - 1
            while j < min(b, i + 8):
                line = code[j]
                while k < len(line):
                    ch = line[k]
                    if ch == "(":
                        depth += 1
                    elif ch == ")":
                        depth -= 1
                        if depth == 0:
                            inner = text.strip()
                            # Only argument-bearing calls are evidence. A bare
                            # `func_X()` is overwhelmingly a declaration in this
                            # source, and a genuine zero-argument call against a
                            # visible prototype would be caught by the compiler
                            # anyway.
                            if inner:
                                counts.append(args + 1)
                            seen = True
                            break
                    elif ch == "," and depth == 1:
                        args += 1
                    if depth >= 1 and not (depth == 1 and ch == "("):
                        text += ch
                    k += 1
                if seen:
                    break
                j += 1
                k = 0
    return counts


def _arity_conflicts(code, order, starts_in_file, bounds, have):
    """C definitions whose parameter list disagrees with a call to them.

    src/rel_duel_eng.c defines func_000FF294 with four parameters and calls it
    with two. In FILE order the call precedes the definition, so C89 lets it
    through on an implicit declaration; in ADDRESS order the definition comes
    first and mwcc rejects the call outright. Neither side can be rewritten
    without risking the codegen of a function that currently matches, so the
    definition is carried as assembly instead — the shipped bytes are identical
    either way, and the disagreement is a real defect in the source worth
    reporting.
    """
    params = {}
    for f in have:
        n = _param_count(code, starts_in_file[f])
        if n is not None:
            params[f] = n
    def_lines = set(starts_in_file.values())
    bad = set()
    for f in order:
        if f not in have:
            continue
        a, b = bounds[f]
        for callee, n in params.items():
            if callee in bad:
                continue
            for got in _call_arg_counts(code, a, b, callee, def_lines):
                if got != n:
                    bad.add(callee)
                    break
    return bad


def _code_only(lines):
    """Per-line copy with comments blanked and string/char bodies emptied.

    Brace counting and "does this line end in a semicolon" are both wrong if a
    brace or semicolon inside a comment or a literal is allowed to count.
    """
    out, in_block = [], False
    for line in lines:
        res, i, n = [], 0, len(line)
        while i < n:
            two = line[i:i + 2]
            if in_block:
                if two == "*/":
                    in_block = False
                    i += 2
                else:
                    i += 1
                continue
            if two == "/*":
                in_block = True
                i += 2
                continue
            if two == "//":
                break
            ch = line[i]
            if ch in "\"'":
                quote, i = ch, i + 1
                while i < n:
                    if line[i] == "\\":
                        i += 2
                        continue
                    if line[i] == quote:
                        i += 1
                        break
                    i += 1
                res.append(quote * 2)
                continue
            res.append(ch)
            i += 1
        out.append("".join(res))
    return out


def _body_end(code, start):
    """Index of the line closing the body that opens at or after `start`.

    Counting braces rather than looking for a line that is exactly `}`, because
    src/rel_duel_eng.c writes whole bodies on one line:

        int func_0000EC04(int a0, ...) {
            extern int func_0000EC04(); return func_0000EB18(...); }

    Matching on a bare `}` runs straight past that and swallows every function
    after it, which then get emitted twice and fail to compile as "redefined".
    """
    depth, seen = 0, False
    for i in range(start, len(code)):
        for ch in code[i]:
            if ch == "{":
                depth += 1
                seen = True
            elif ch == "}":
                depth -= 1
                if seen and depth <= 0:
                    return i
        if seen and depth <= 0:
            return i
    return start


def _is_knr_definition(lines, i):
    """Does line `i` open a K&R definition rather than close a declaration?

    The merge tooling emits old-style definitions, which end in a semicolon and
    so look exactly like a forward declaration:

        int func_0006DE84(arg0) s32 arg0;
        {
            ...

    Missing one is not benign — the function ends up carried as INCLUDE_ASM
    while its body is still emitted inside a neighbouring block, and the module
    fails to link with "multiple definition". Distinguish them by looking ahead:
    a definition reaches a bare `{` past nothing but more parameter
    declarations.
    """
    if re.match(r"^\s*extern\b", lines[i]):
        return False
    for j in range(i + 1, min(i + 10, len(lines))):
        st = lines[j].strip()
        if not st:
            continue
        if st == "{":
            return True
        # more K&R parameter declarations may intervene
        if re.match(r"^[A-Za-z_][\w \*]*\s+\*?\w+(\[[^\]]*\])?\s*;$", st):
            continue
        return False
    return False


def _classify_prelude(prelude):
    """Split a function's prelude into (hoistable, contested-so-far, keep).

    Returns (decls, others): `decls` are complete file-scope declarations that
    can be shared, `others` is everything else (comments, multi-line constructs)
    which stays attached to the function.
    """
    decls, others = [], []
    for line in prelude:
        st = line.strip()
        if not st:
            continue
        if (_EXTERN_RE.match(line) or re.match(r"^(typedef|struct|union|enum)\b", st)):
            # Only single-line, complete declarations. A multi-line struct body
            # would be split apart by hoisting, so it stays where it is.
            if st.endswith(";"):
                decls.append(st)
                continue
        others.append(line)
    return decls, others


def main():
    module = sys.argv[1]
    n = split_asm(module)
    funcs = progress.module_functions(module)
    starts = {}
    cur = None
    for line in open(os.path.join(ROOT, "build/asm", module, "text.s"), errors="replace"):
        m = re.match(r"glabel (func_[0-9A-F]+)", line)
        if m:
            cur = m.group(1)
        m = re.match(r"\s*/\* [0-9A-F]+ ([0-9A-F]+) ", line)
        if m and cur and cur not in starts:
            starts[cur] = int(m.group(1), 16)

    c_path = os.path.join(ROOT, "src", module + ".c")
    lines = open(c_path).read().splitlines()

    # Keep only functions that VERIFY. A function can sit in src/<m>.c and still
    # not match — src/rel_html_view.c deliberately carries a NONMATCHING
    # func_00000470, and a merge can leave a near-miss behind. Selecting on
    # "defined in C" then compiles the wrong bytes and the module can never
    # link byte-exactly. Selecting on the verified baseline instead carries any
    # such function as assembly, which is what makes the module completable.
    verified = set()
    bl = os.path.join(ROOT, "config/progress-baseline.json")
    if os.path.exists(bl):
        import json
        verified = set(json.load(open(bl)).get("modules", {}).get(module, []))

    # Locate each C function definition: the line its return type starts on,
    # through to the line before the next definition (or EOF).
    # A definition is a line at COLUMN ZERO that names a function and opens a
    # body. The old pattern required the return type to be plain identifier and
    # star characters, so it silently missed definitions that return a function
    # pointer —
    #
    #     s32 (*func_00001EC8(void))() {
    #
    # — because of the parenthesis before the name. A missed definition is worse
    # than it sounds: the function is not in `starts_in_file`, so it is carried
    # as INCLUDE_ASM, while its C body still gets emitted as part of a
    # neighbouring block. The object then defines it twice and the module fails
    # to link with "multiple definition of func_00001EC8".
    code_lines = _code_only(lines)
    starts_in_file = {}
    for i, line in enumerate(lines):
        if not line or line[0].isspace() or line[0] in "/*#}":
            continue
        code = code_lines[i].rstrip()
        if not code:
            continue
        if code.endswith(";") and not _is_knr_definition(lines, i):
            continue                      # a declaration, not a definition
        m = re.search(r"\b(func_[0-9A-F]+)\s*\(", code)
        if m:
            starts_in_file.setdefault(m.group(1), i)
    # Boundaries must be computed over EVERY definition in the file, not just
    # the ones being kept: filtering first would make an excluded function's
    # body get swallowed into a neighbouring block and compiled anyway.
    order = sorted(starts_in_file, key=lambda f: starts_in_file[f])

    # A function's block was originally taken as [its definition, the NEXT
    # definition) — which attaches the text BETWEEN two functions to the one
    # ABOVE it. That attribution is backwards. The merge tooling emits each
    # function's prelude (its `/* func_XXXX - N words. MATCH */` header and the
    # file-scope `extern` declarations it needs) immediately BEFORE the
    # definition, so that text belongs to the function BELOW it.
    #
    # Getting this backwards deletes a kept function's declarations whenever the
    # function above it happens to be carried as assembly. That is what broke
    # rel_charalist ('D_00027918' redeclared), rel_cutin_viewer (undefined
    # V4_58A0_40E8) and rel_duel_eng (incomplete struct s_000E30E8).
    #
    # Hoisting the gaps into the preamble instead does NOT work, and the reason
    # is worth recording: these preludes deliberately declare the SAME global at
    # different types for different functions (src/rel_story.c declares
    # D_00034488 as both `char` and `s32`). Collecting them together makes those
    # collide at file scope, which is the failure docs/20 section 4 describes.
    # Keeping each prelude attached to its own function reproduces exactly the
    # declaration set the original file has, so no new collision can arise.
    bounds = {}
    prev_end = starts_in_file[order[0]] if order else 0
    for f in order:
        a = starts_in_file[f]
        body_end = _body_end(code_lines, a)
        bounds[f] = (prev_end, body_end + 1)
        prev_end = body_end + 1
    preamble = lines[:starts_in_file[order[0]]] if order else lines

    # Functions are emitted in ADDRESS order, but src/<module>.c is in neither
    # address nor any other stable order, so reordering can float a FILE-scope
    # `extern` above a block-scope declaration of the same global at a different
    # type — and then they collide:
    #
    #     extern void *D_00027918;   (block scope, func_00005C58)
    #     extern int   D_00027918;   (FILE scope, prelude of func_000063E8)
    #
    # In file order the block-scope one comes first and is scoped away, so
    # src/rel_charalist.c compiles. In address order the file-scope one leads and
    # poisons every later block-scope declaration.
    #
    # docs/20 section 4 already states the rule: declare externs at BLOCK scope,
    # always — two block-scope declarations in different functions can never
    # conflict, a file-scope one conflicts with all of them. Rather than edit 28
    # sources, demote the offenders here, and ONLY the offenders: a file-scope
    # extern whose symbol is declared at a different type elsewhere in the file
    # is moved inside the body of the function whose prelude carries it.
    # Uncontested file-scope externs are left exactly where they are, so modules
    # that already build byte-exactly cannot be disturbed.
    contested = _contested_externs(lines)

    # `#pragma optimization_level N` is FILE-ORDER STATE: it applies to every
    # function after it until the next one. Emitting functions in ADDRESS order
    # detaches each pragma from the function it governs, and the function then
    # compiles at the wrong level. rel_title is the only module that uses them
    # (50 of them, alternating 2 and 4) and it is the only module where this
    # mattered — four thunks lost their tail call and grew from 8 words to 15,
    # putting every later function 0x1C further out and the module 112 bytes
    # over. So resolve the level in effect at each function's ORIGINAL position
    # and restate it in the output.
    #
    # 4 is the base: the command line compiles at -O4,s.
    pragma_at, level = {}, 4
    for i, line in enumerate(lines):
        m = re.match(r"\s*#pragma\s+optimization_level\s+(\d+)", line)
        if m:
            level = int(m.group(1))
        pragma_at[i] = level
    uses_pragmas = any(re.match(r"\s*#pragma\s+optimization_level", l) for l in lines)

    # A prelude declaration is not necessarily for its own function: rel_story
    # declares D_0002F128 once and uses it from several. Attaching it to one
    # function loses it the moment that function is carried as assembly. So
    # UNCONTESTED declarations are hoisted into the preamble, where every
    # function can see them and no collision is possible — there is only one
    # type for the symbol in the whole file.
    #
    # CONTESTED ones cannot be hoisted (that is the rel_story D_00034488 /
    # rel_charalist D_00027918 collision above), so they are pushed the other
    # way instead: down into the body of the function whose prelude carries
    # them, where block scope makes them private to it.
    # Every file-scope extern of a contested symbol, with the line it sits on,
    # so each function can be given the one that was in scope for it.
    file_scope = {}
    for f in order:
        for i in range(bounds[f][0], starts_in_file[f]):
            m = _EXTERN_RE.match(lines[i])
            if m and not m.group(1):
                name = _split_extern(m.group(2))[0]
                if name:
                    file_scope.setdefault(name, []).append((i, lines[i].strip()))

    def file_scope_decl(sym, before):
        best = None
        for i, text in file_scope.get(sym, []):
            if i < before:
                best = text
        return best

    hoisted, seen_hoist = [], set()
    for f in order:
        decls, _ = _classify_prelude(lines[bounds[f][0]:starts_in_file[f]])
        for d in decls:
            m = _EXTERN_RE.match(d)
            if m and _split_extern(m.group(2))[0] in contested:
                continue
            if d not in seen_hoist:
                seen_hoist.add(d)
                hoisted.append(d)
    if hoisted:
        preamble = list(preamble) + [
            "", "/* File-scope declarations gathered from the per-function",
            " * preludes by scripts/make_hybrid.py. A declaration may be used by",
            " * more functions than the one it sits above, so it cannot be",
            " * dropped just because that function is carried as assembly. */",
            ""] + hoisted

    have = set(starts_in_file)
    if verified:
        have &= verified          # anything unverified falls through to INCLUDE_ASM

    conflicts = _arity_conflicts(code_lines, order, starts_in_file, bounds, have)
    if conflicts:
        have -= conflicts
        print(f"  {len(conflicts)} function(s) carried as asm: their parameter "
              f"list disagrees with a call site "
              f"({', '.join(sorted(conflicts)[:4])}"
              f"{', ...' if len(conflicts) > 4 else ''})")

    missing = sorted(set(funcs) - have, key=lambda f: starts.get(f, 0))

    # Emit every function in SHIPPED ADDRESS ORDER, interleaving C bodies and
    # INCLUDE_ASM lines. The linker lays .text out sequentially, so file order
    # must equal address order or every function after the first mismatch
    # lands at the wrong address.
    out = ['#include "hybrid_asm.h"', ""] + list(preamble)
    out += ["", "/* Functions not yet decompiled are spliced in from assembly by",
            " * tools/mwccgap. Order below is SHIPPED ADDRESS ORDER — do not sort. */", ""]
    for f in sorted(funcs, key=lambda f: starts.get(f, 0)):
        if f in have:
            a, b = bounds[f]
            _, others = _classify_prelude(lines[a:starts_in_file[f]])
            body = lines[starts_in_file[f]:b]
            # Uncontested declarations are already in the preamble. A contested
            # symbol gets the declaration that was visible AT THIS FUNCTION'S
            # ORIGINAL POSITION — the nearest preceding file-scope one — injected
            # at block scope. A file-scope declaration serves every function
            # after it, not just the one it sits above (src/rel_story.c declares
            # D_00034488 once as `char` and four later functions rely on it), so
            # attaching it to a single function loses it for the others.
            inject = []
            for sym in contested:
                if not any(re.search(r"\b" + sym + r"\b", ln) for ln in body):
                    continue
                if any(_EXTERN_RE.match(ln) and
                       _split_extern(_EXTERN_RE.match(ln).group(2))[0] == sym
                       for ln in body):
                    continue          # already declared at block scope inside
                decl = file_scope_decl(sym, starts_in_file[f])
                if decl:
                    inject.append("    " + decl)
            if inject:
                for i, line in enumerate(body):
                    if line.rstrip().endswith("{"):
                        body = body[:i + 1] + inject + body[i + 1:]
                        break
            # Drop any pragma that travelled here in the prelude; the
            # authoritative one is restated below from the original position.
            others = [l for l in others
                      if not re.match(r"\s*#pragma\s+optimization_level", l)]
            if uses_pragmas:
                others = others + [
                    f"#pragma optimization_level {pragma_at[starts_in_file[f]]}"]
            out += others + body
        else:
            out.append(f'INCLUDE_ASM("build/hybrid/asm/{module}", {f});')
            out.append("")
    dst = os.path.join(ROOT, "build/hybrid", module + ".c")
    os.makedirs(os.path.dirname(dst), exist_ok=True)
    open(dst, "w").write("\n".join(out) + "\n")

    print(f"{module}: {n} per-function .s, {len(have)} in C, {len(missing)} INCLUDE_ASM")
    print(f"  -> {dst} (interleaved in address order)")


if __name__ == "__main__":
    main()
