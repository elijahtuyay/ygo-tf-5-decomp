#!/usr/bin/env python3
"""
Side-by-side target vs candidate for one function — our asm-differ.

    scripts/show_diff.py rel_field func_00001234 /tmp/try.c
    scripts/show_diff.py rel_field func_00001234           # use src/<module>.c
    scripts/show_diff.py rel_field func_00001234 /tmp/t.c --context 4

WHY NOT tools/asm-differ. It expects a project layout it can build on its own
(its own `diff_settings.py`, a make target producing a comparable object). Our
build is mwccpsp-under-wibo plus a relocation-aware comparator that already
knows how to equate a baked address with a relocation, which asm-differ does
not. Re-teaching it all of that is more work than printing the two columns.

WHAT IT SHOWS. Every instruction of the target beside the candidate, with
differing rows marked. That is the piece scripts/mwcc_diff.py leaves out: it
says word 17 differs and what both sides hold, but not what surrounds it, and
for anything longer than a few instructions the surrounding rows are what tell
you WHY — a missing sign-extension, an argument set in the wrong place, a
branch that went the other way.

Rows are aligned by index, so a size mismatch makes everything after the first
insertion look wrong. That is expected: fix the length first, then the contents.
docs/11 "Iteration discipline" says the same thing.
"""
import argparse
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TARGET = re.compile(r"\s*/\* [0-9A-F]+ ([0-9A-F]+) ([0-9A-F]{8}) \*/\s+(\S+)\s*(.*)")



def normalise(text, base=0):
    """Compare semantically, not textually.

    The two sides use different notations for the same instruction: splat prints
    `sw $a0, %lo(D_00351854)($v1)` while objdump prints `sw a0,0(v1)` with the
    relocated symbol appended on its own line. Comparing raw strings marks every
    relocated instruction as differing and buries the one row that actually
    matters. Normalise to (mnemonic, registers, symbol) and drop the immediate
    wherever a relocation supplies it.
    """
    # A branch target is a label in splat (`.L00015778`) and a byte offset in
    # objdump (`7c <func+0x7c>`). Resolve both to the offset from the start of
    # the function so they compare equal.
    text = re.sub(r"\.L([0-9A-F]{6,8})",
                  lambda m: str(int(m.group(1), 16) - base), text)
    text = re.sub(r"\b[0-9a-f]+ <\w+\+0x([0-9a-f]+)>", lambda m: str(int(m.group(1), 16)), text)
    text = re.sub(r"\b([0-9a-f]+) <\w+>", lambda m: str(int(m.group(1), 16)), text)
    t = text.replace("$", "").replace(",", " ")
    t = re.sub(r"%hi\(([^)]*)\)", r"\1", t)
    t = re.sub(r"%lo\(([^)]*)\)", r"\1", t)
    t = re.sub(r"\b0x0\b", "0", t)
    # objdump leaves a 0 placeholder in the relocated immediate; splat puts the
    # symbol there instead. Drop bare zeros so the two agree.
    t = t.replace("(", " ").replace(")", " ")   # `0(v1)` and `SYM(v1)` -> tokens
    # `li a3,3` is `addiu a3,zero,3`; drop the implicit zero so both agree
    # splat prints immediates in hex, objdump in decimal
    def num(tok):
        # splat prints hex (and negative hex, `-0xFF`), objdump decimal
        try:
            neg = tok.startswith("-")
            body = tok[1:] if neg else tok
            v = int(body, 16) if body.lower().startswith("0x") else int(body)
            return str(-v if neg else v)
        except ValueError:
            return tok
    t = " ".join(num(tok) for tok in t.split() if tok not in ("0", "zero"))
    t = re.sub(r"\bli\b", "addiu", t)          # objdump prints addiu x,zero,N as li
    t = re.sub(r"\bmove\b", "addu", t)         # ...and addu x,y,zero as move
    t = re.sub(r"\bnop\b", "sll 0 0 0", t)
    return " ".join(t.split())

def target_insns(module, func):
    out, cur = [], False
    for line in open(os.path.join(ROOT, "asm", module, "text.s"), errors="replace"):
        if line.strip() == f"glabel {func}":
            cur = True
            continue
        if cur and line.startswith("endlabel"):
            break
        if cur:
            m = TARGET.match(line)
            if m:
                out.append((m.group(1), f"{m.group(3)} {m.group(4)}".strip()))
    return out


def candidate_insns(obj, func):
    r = subprocess.run(["mips-linux-gnu-objdump", "-dr", obj],
                       capture_output=True, text=True)
    out, cur = [], False
    for line in r.stdout.splitlines():
        if re.match(rf"[0-9a-f]+ <{func}>:", line):
            cur = True
            continue
        if cur and (not line.strip() or re.match(r"[0-9a-f]+ <", line)):
            break
        if cur:
            m = re.match(r"\s*[0-9a-f]+:\s+[0-9a-f]{8}\s+(\S+)\s*(.*)", line)
            if m:
                out.append(f"{m.group(1)} {m.group(2)}".strip())
            elif "R_MIPS" in line and out:
                out[-1] = out[-1] + "  " + line.split()[-1]
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("module")
    ap.add_argument("func")
    ap.add_argument("cfile", nargs="?")
    ap.add_argument("--context", type=int, default=0,
                    help="show only N rows either side of each difference")
    a = ap.parse_args()

    src = a.cfile or os.path.join(ROOT, "src", a.module + ".c")
    build = subprocess.run([os.path.join(ROOT, "scripts/mwcc_build.sh"), src],
                           capture_output=True, text=True, cwd=ROOT)
    if build.returncode != 0:
        print("COMPILE FAILED")
        print("\n".join(l for l in build.stdout.splitlines() if l.startswith("#"))[:1500])
        return 1

    obj = os.path.join(ROOT, "build/mwcc", os.path.basename(src)[:-2] + ".o")
    tgt = target_insns(a.module, a.func)
    cand = candidate_insns(obj, a.func)
    if not tgt:
        print(f"{a.func} not found in asm/{a.module}/text.s")
        return 1
    if not cand:
        print(f"{a.func} not present in the compiled object")
        return 1

    n = max(len(tgt), len(cand))
    def same(i):
        base = int(tgt[0][0], 16) if tgt else 0
        t = normalise(tgt[i][1], base) if i < len(tgt) else None
        c = normalise(cand[i], base) if i < len(cand) else None
        if t is None or c is None:
            return False
        # objdump appends the relocated symbol; splat has it inline, so a row
        # matches if one side's tokens are a subset of the other's
        return t == c or set(t.split()) == set(c.split())

    diff_rows = {i for i in range(n) if not same(i)}
    show = set()
    for i in diff_rows:
        show.update(range(max(0, i - a.context), min(n, i + a.context + 1)))

    print(f"{a.func}: target {len(tgt)} instructions, candidate {len(cand)}"
          f"{'  SIZE MISMATCH' if len(tgt) != len(cand) else ''}\n")
    print(f"{'':>4}  {'target':<44}candidate")
    skipped = False
    for i in range(n):
        if a.context and i not in show:
            if not skipped:
                print("      ...")
                skipped = True
            continue
        skipped = False
        t = tgt[i][1] if i < len(tgt) else ""
        c = cand[i] if i < len(cand) else ""
        mark = " " if i not in diff_rows else ">"
        print(f"{mark}{i:>3}  {t:<44}{c}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
