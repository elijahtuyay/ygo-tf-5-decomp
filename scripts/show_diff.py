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
    diff_rows = {i for i in range(n)
                 if (tgt[i][1] if i < len(tgt) else None) != (cand[i] if i < len(cand) else None)}
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
        mark = " " if t == c else ">"
        print(f"{mark}{i:>3}  {t:<44}{c}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
