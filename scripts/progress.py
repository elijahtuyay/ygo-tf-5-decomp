#!/usr/bin/env python3
"""
Project progress: how much of each module is decompiled and verified.

    scripts/progress.py            # table + totals
    scripts/progress.py --md       # markdown, for pasting into docs

Counts a function only if it is present in src/<module>.c AND the freshly
compiled object reports MATCH against the shipped code. Function counts are the
headline number, but BYTES are the honest one: a module is not half done because
half its functions match, if those are the small ones.
"""
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def module_functions(module):
    """{name: size_in_bytes} for every function in the shipped module."""
    path = os.path.join(ROOT, "asm", module, "text.s")
    out, cur, words = {}, None, 0
    if not os.path.exists(path):
        return out
    for line in open(path, errors="replace"):
        m = re.match(r"glabel (\w+)", line)
        if m:
            cur, words = m.group(1), 0
        elif cur and re.match(r"\s*/\* [0-9A-F]+ ", line):
            words += 1
        elif cur and line.startswith("endlabel"):
            out[cur] = words * 4
            cur = None
    return out


def matched(module):
    src = os.path.join(ROOT, "src", module + ".c")
    if not os.path.exists(src):
        return set()
    r = subprocess.run([os.path.join(ROOT, "scripts/mwcc_build.sh"), src],
                       capture_output=True, text=True, cwd=ROOT)
    if r.returncode != 0:
        return set()
    d = subprocess.run([sys.executable, os.path.join(ROOT, "scripts/mwcc_diff.py"),
                        os.path.join(ROOT, "asm", module, "text.s"),
                        os.path.join(ROOT, "build/mwcc", module + ".o")],
                       capture_output=True, text=True, cwd=ROOT)
    return {m.group(1) for m in
            (re.match(r"^(func_[0-9A-F]+): MATCH", l) for l in d.stdout.splitlines()) if m}


def main():
    md = "--md" in sys.argv
    mods = sorted(f[:-4] for f in
                  os.listdir(os.path.join(ROOT, "iso_extracted/PSP_GAME/USRDIR/gmodule"))
                  if f.endswith(".prx"))
    rows, tf, tfm, tb, tbm = [], 0, 0, 0, 0
    for mod in mods:
        funcs = module_functions(mod)
        if not funcs:
            continue
        ok = matched(mod) & set(funcs)
        b, bm = sum(funcs.values()), sum(funcs[f] for f in ok)
        rows.append((mod, len(ok), len(funcs), bm, b))
        tf += len(funcs); tfm += len(ok); tb += b; tbm += bm
    rows.sort(key=lambda r: -r[3])

    if md:
        print("| module | functions | bytes of .text | % of code |")
        print("|---|---|---|---:|")
        for mod, fm, f, bm, b in rows:
            print(f"| `{mod}` | {fm} / {f} | {bm:,} / {b:,} | {100*bm/b:.1f}% |")
        print(f"| **total** | **{tfm} / {tf}** | **{tbm:,} / {tb:,}** | **{100*tbm/tb:.2f}%** |")
    else:
        print(f"{'module':<20}{'functions':>14}{'bytes':>20}{'%':>8}")
        for mod, fm, f, bm, b in rows:
            print(f"{mod:<20}{fm:>6} /{f:>6}{bm:>10,} /{b:>8,}{100*bm/b:>7.1f}%")
        print(f"{'TOTAL':<20}{tfm:>6} /{tf:>6}{tbm:>10,} /{tb:>8,}{100*tbm/tb:>7.2f}%")


if __name__ == "__main__":
    main()
