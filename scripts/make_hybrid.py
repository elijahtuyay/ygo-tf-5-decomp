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
    fh, count = None, 0
    for line in lines:
        m = re.match(r"glabel (func_[0-9A-F]+)", line)
        if m:
            fh = open(os.path.join(out_dir, m.group(1) + ".s"), "w")
            fh.write("\n".join(header) + "\n")
            count += 1
        if fh:
            fh.write(line + "\n")
        if line.startswith("endlabel") and fh:
            fh.close()
            fh = None
    return count


def defined_in_c(text):
    return set(re.findall(r"^[A-Za-z_][\w \*]*?\b(func_[0-9A-F]+)\s*\([^;]*$",
                          text, re.M))


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
    starts_in_file = {}
    for i, line in enumerate(lines):
        m = re.match(r"^[A-Za-z_][\w \*]*?\b(func_[0-9A-F]+)\s*\([^;]*$", line)
        if m:
            starts_in_file[m.group(1)] = i
    # Boundaries must be computed over EVERY definition in the file, not just
    # the ones being kept: a function's block runs to the start of the next
    # definition, so filtering first would make an excluded function's body get
    # swallowed into the preceding block and compiled anyway.
    order = sorted(starts_in_file, key=lambda f: starts_in_file[f])
    bounds = {}
    for k, f in enumerate(order):
        end = starts_in_file[order[k + 1]] if k + 1 < len(order) else len(lines)
        bounds[f] = (starts_in_file[f], end)
    preamble = lines[:starts_in_file[order[0]]] if order else lines
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
            out += lines[a:b]
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
