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
    for name, body in chunks.items():
        with open(os.path.join(out_dir, name + ".s"), "w") as fh:
            fh.write("\n".join(header) + "\n")
            fh.write("\n".join(body) + "\n")
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
    starts_in_file = {}
    for i, line in enumerate(lines):
        if not line or line[0].isspace() or line[0] in "/*#}":
            continue
        # Strip comments before deciding: a forward declaration often carries a
        # trailing note, and `void func_0000F928(void); /* defined below */`
        # does not end in a semicolon as written.
        code = re.sub(r"/\*.*?\*/", "", line)
        code = re.sub(r"/\*.*$", "", code).split("//")[0].rstrip()
        if not code or code.endswith(";"):
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
        body_end = a
        for i in range(a, len(lines)):
            if lines[i].rstrip() == "}":
                body_end = i
                break
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
