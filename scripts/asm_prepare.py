#!/usr/bin/env python3
"""
Make a splat .s file assemblable by GNU as, by turning the instructions gas does
not know into raw .word directives.

    scripts/asm_prepare.py in.s out.s -- mips-linux-gnu-as -march=mips32r2 ...

WHY. rabbitizer disassembles the full Allegrex instruction set, but binutils
does not implement its custom opcodes — `min`, `max` and the whole VFPU block
are rejected with "opcode not supported on this processor". 20 of the 28 modules
contain at least one, so without this they cannot be reassembled at all.

HOW. Every line splat emits carries the original encoding in its comment:

    /* 3AC 00000358 F0FFBD27 */  min  $a0, $v1, $a0

so an unassemblable line can be replaced by `.word 0x...` with the exact same
bytes. Rather than maintaining a list of which mnemonics binutils supports, this
runs the assembler, rewrites precisely the lines it complained about, and
repeats until it is happy. That way it self-corrects as binutils changes, and it
can never rewrite an instruction gas would have assembled correctly.

The bytes are identical either way, so the resulting object is unaffected — only
the readability of the intermediate file changes, and the intermediate lives in
build/ while asm/ keeps the real disassembly.
"""
import os
import re
import subprocess
import sys
import tempfile

MAX_ROUNDS = 400   # rel_duel_draw has 121 handwritten VFPU functions and gas
                   # reports only a subset of errors per pass, so it needs many rounds
# "file.s:1234: Error: opcode not supported on this processor: ..."
ERR = re.compile(r"^[^:]+:(\d+): Error: (opcode not supported|unrecognized opcode|invalid operands)")
# /* rom vram WORD */  mnemonic operands
LINE = re.compile(r"^(\s*)/\* ([0-9A-Fa-f]+) ([0-9A-Fa-f]+) ([0-9A-Fa-f]{8}) \*/(\s*)(.*)$")


def to_word(le_hex):
    """splat prints the 4 bytes in file order; .word wants the value."""
    return int.from_bytes(bytes.fromhex(le_hex), "little")



def add_missing_local_labels(lines):
    """Define any .L label that is branched to but never emitted.

    splat occasionally fails to place a local label on an instruction that a
    branch elsewhere targets — it happens where it mis-identifies a function
    boundary and treats the region as data. The reference then survives into the
    object as an undefined symbol and the module cannot be linked:

        undefined reference to `.L0000B07C'

    Every such label encodes its own vram, and splat prints the vram of every
    instruction, so the definition can simply be restored at the right line.
    This affected rel_cutin_viewer and rel_duel_draw, the only two modules that
    failed the `make MODULE=x` relink gate.
    """
    defined, referenced = set(), set()
    for line in lines:
        m = re.match(r"\s*(\.L[0-9A-Fa-f]+):", line)
        if m:
            defined.add(m.group(1))
        for r in re.findall(r"(\.L[0-9A-Fa-f]{4,})\b", line):
            if not re.match(r"\s*" + re.escape(r) + ":", line):
                referenced.add(r)
    missing = referenced - defined
    if not missing:
        return 0
    want = {}
    for label in missing:
        try:
            want[int(label[2:], 16)] = label
        except ValueError:
            pass
    added = 0
    for i, line in enumerate(lines):
        m = LINE.match(line)
        if not m:
            continue
        vram = int(m.group(3), 16)
        if vram in want:
            lines[i] = f"{want[vram]}:\n" + line
            del want[vram]
            added += 1
    return added


def main():
    src, dst = sys.argv[1], sys.argv[2]
    assert sys.argv[3] == "--", "usage: asm_prepare.py in.s out.s -- <as> <flags...>"
    as_cmd = sys.argv[4:]

    lines = open(src, errors="replace").read().splitlines(keepends=True)
    rewritten = 0
    restored = add_missing_local_labels(lines)

    for _ in range(MAX_ROUNDS):
        with tempfile.NamedTemporaryFile("w", suffix=".s", delete=False,
                                         dir=os.path.dirname(os.path.abspath(dst))) as fh:
            fh.writelines(lines)
            probe = fh.name
        obj = probe + ".o"
        r = subprocess.run(as_cmd + [probe, "-o", obj], capture_output=True, text=True)
        for f in (probe, obj):
            try:
                os.unlink(f)
            except OSError:
                pass
        if r.returncode == 0:
            break

        bad = sorted({int(m.group(1)) for m in
                      (ERR.match(l) for l in r.stderr.splitlines()) if m})
        if not bad:
            sys.stderr.write(r.stderr)
            sys.exit("asm_prepare: assembler failed for a reason this cannot fix")

        # gas reports only ~30 errors per invocation, so rewriting just the
        # lines it named needs one round per 30 instructions — rel_duel_draw
        # has thousands of VFPU instructions across its 121 handwritten
        # functions and never converged. Generalise instead: whenever a
        # mnemonic is rejected once, rewrite EVERY line using that mnemonic.
        # Rounds then scale with the number of distinct unsupported opcodes
        # (a few dozen) rather than with the instruction count.
        progress = False
        bad_mnemonics = set()
        for n in bad:
            m = LINE.match(lines[n - 1])
            if m:
                bad_mnemonics.add(m.group(6).split()[0] if m.group(6).split() else "")
        for i, line in enumerate(lines):
            m = LINE.match(line)
            if not m:
                continue
            indent, rom, vram, word, _, insn = m.groups()
            parts = insn.split()
            if not parts or parts[0] not in bad_mnemonics:
                continue
            lines[i] = (f"{indent}/* {rom} {vram} {word} */  "
                        f".word 0x{to_word(word):08X}  /* {insn.strip()} */\n")
            rewritten += 1
            progress = True
        if not progress:
            sys.stderr.write(r.stderr)
            sys.exit("asm_prepare: could not rewrite the offending lines")
    else:
        sys.exit(f"asm_prepare: still failing after {MAX_ROUNDS} rounds")

    open(dst, "w").writelines(lines)
    if rewritten:
        print(f"asm_prepare: {os.path.basename(src)}: "
              f"{rewritten} Allegrex instruction(s) emitted as .word")
    if restored:
        print(f"asm_prepare: {os.path.basename(src)}: "
              f"{restored} local label(s) splat failed to emit were restored")


if __name__ == "__main__":
    main()
