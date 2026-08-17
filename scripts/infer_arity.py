#!/usr/bin/env python3
"""
Infer how many arguments each engine import takes, from its call sites.

    scripts/infer_arity.py            # writes nids/ehsys_arity.csv

Getting an import's argument count wrong is the most common reason a small
function fails to match: mwccpsp passes integer arguments 1-8 in $a0-$a3 then
$t0-$t3, and m2c only sees the ones the caller touches, so a parameter that is
forwarded untouched disappears from the draft.

Every module's disassembly is full of call sites for the same 1729 engine
functions. This walks backwards from each `jal`/`j` to an import and records
which argument registers were written in the preceding straight-line block. The
maximum across all call sites project-wide is a lower bound on the real arity —
and a far better starting guess than m2c's.
"""
import csv
import os
import re
from collections import Counter, defaultdict

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ARGREGS = ["$a0", "$a1", "$a2", "$a3", "$t0", "$t1", "$t2", "$t3"]
STOP = re.compile(r"\b(jal|jr|b|beq|bne|blez|bgtz|bltz|bgez|beql|bnel)\b")
WRITE = re.compile(r"^\s*/\*[^*]*\*/\s+\S+\s+(\$\w+)")


def import_names(module):
    out = set()
    p = os.path.join(ROOT, "config/symbols", module + ".txt")
    if os.path.exists(p):
        for line in open(p):
            m = re.match(r"(\w+) = 0x[0-9A-Fa-f]+;.*type:func", line)
            if m:
                out.add(m.group(1))
    return out


def scan(module, arity, sites):
    path = os.path.join(ROOT, "asm", module, "text.s")
    if not os.path.exists(path):
        return
    known = import_names(module)
    lines = open(path, errors="replace").read().splitlines()
    for i, line in enumerate(lines):
        m = re.search(r"\b(?:jal|j)\s+(\w+)\s*$", line)
        if not m or m.group(1) not in known:
            continue
        callee = m.group(1)
        sites[callee] += 1
        written = set()
        for j in range(max(0, i - 12), i):
            if STOP.search(lines[j]):
                written = set()          # only the block immediately before the call
                continue
            w = WRITE.match(lines[j])
            if w and w.group(1) in ARGREGS:
                written.add(w.group(1))
        if i + 1 < len(lines):            # the delay slot sets up arguments too
            w = WRITE.match(lines[i + 1])
            if w and w.group(1) in ARGREGS:
                written.add(w.group(1))
        if written:
            arity[callee][max(ARGREGS.index(r) for r in written) + 1] += 1


def main():
    mods = sorted(f[:-4] for f in
                  os.listdir(os.path.join(ROOT, "iso_extracted/PSP_GAME/USRDIR/gmodule"))
                  if f.endswith(".prx"))
    arity, sites = defaultdict(Counter), Counter()
    for m in mods:
        scan(m, arity, sites)

    rows = []
    for name, counts in arity.items():
        if counts:
            rows.append((name, sites[name], max(counts), counts.most_common(3)))
    rows.sort(key=lambda r: -r[1])

    out = os.path.join(ROOT, "nids/ehsys_arity.csv")
    with open(out, "w", newline="") as fh:
        w = csv.writer(fh)
        w.writerow(["name", "call_sites", "max_args", "distribution"])
        for name, n, mx, dist in rows:
            w.writerow([name, n, mx, "; ".join(f"{a} args x{c}" for a, c in dist)])
    print(f"{len(rows)} imports with call sites; wrote {out}")
    print("\nmost-called, with inferred arity:")
    for name, n, mx, dist in rows[:15]:
        print(f"  {name:<36} {n:>5} sites  max={mx}  most common: {dist[0][0]} args")


if __name__ == "__main__":
    main()
