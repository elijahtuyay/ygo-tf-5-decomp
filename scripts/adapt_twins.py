#!/usr/bin/env python3
"""
Adapt a matched function's C onto its SAME-SHAPE twins, automatically.

    scripts/adapt_twins.py            # every adaptable group
    scripts/adapt_twins.py rel_shop   # only twins landing in this module
    scripts/adapt_twins.py --limit 20 # stop after N successful adaptations

scripts/find_twins.py reports two tiers. The `identical` tier is free: the raw
words are equal, so the body copies verbatim (that pass is already automated by
find_twins --apply). The `same-shape` tier — 156 functions at time of writing —
is equal only once immediates, symbols and branch targets are masked out, so the
body needs its symbol references rewritten before it will match. That tier has
never been exploited because doing it by hand is tedious.

It does not have to be done by hand. scripts/mwcc_diff.py already reports, per
differing word, exactly which symbol the TARGET references versus which one our
candidate references:

    [12] RELOC MISMATCH target=lw ... (LO16 D_0015E790) vs candidate=... (LO16 D_0009DB00)

That is a substitution instruction. This script compiles the template body under
the twin's name, reads the mismatches, rewrites candidate symbols to target
symbols, and repeats until the function matches or stops improving. Every
accepted result is verified against the WHOLE file, exactly as merge_matches
does, and rolled back if anything else regresses.
"""
import argparse
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "scripts"))
import merge_matches as M  # noqa: E402
import find_twins as T     # noqa: E402

RELOC = re.compile(r"RELOC MISMATCH target=.*?\((\w+) (\S+)\) vs candidate=.*?\((\w+) (\S+)\)")


def diff_func(module, func):
    """Return the differ's report for one function of the current src file."""
    r = subprocess.run([os.path.join(ROOT, "scripts/mwcc_build.sh"),
                        os.path.join(ROOT, "src", module + ".c")],
                       capture_output=True, text=True, cwd=ROOT)
    if r.returncode != 0:
        return None
    d = subprocess.run([sys.executable, os.path.join(ROOT, "scripts/mwcc_diff.py"),
                        os.path.join(ROOT, "asm", module, "text.s"),
                        os.path.join(ROOT, "build/mwcc", module + ".o"), func],
                       capture_output=True, text=True, cwd=ROOT)
    return d.stdout


def score(report):
    """Lower is better. None when the function is absent or the size is wrong."""
    if report is None:
        return None
    if re.search(r"\bMATCH\b", report):
        return 0
    m = re.search(r": (\d+) diff", report)
    return int(m.group(1)) if m else None


def adapt(module, func, body, rounds=6):
    """Insert `body` as `func` and iteratively rewrite symbols toward the target.

    Returns the matching source, or None. The file is always restored."""
    path = os.path.join(ROOT, "src", module + ".c")
    original = open(path).read()
    if func in M.defined_in(original):
        return None
    best = None
    cur = body
    try:
        for _ in range(rounds):
            entry = {"func": func, "words": 0, "shape": "same-shape twin", "src": cur}
            open(path, "w").write(M.insert(original, entry, []))
            rep = diff_func(module, func)
            s = score(rep)
            if s == 0:
                best = cur
                break
            if s is None:
                break
            subs = {}
            for tkind, tsym, ckind, csym in RELOC.findall(rep):
                if tkind == ckind and csym != tsym and re.match(r"^[A-Za-z_]\w*$", csym):
                    subs[csym] = tsym
            if not subs:
                break
            new = cur
            for c, t in subs.items():
                new = re.sub(rf"\b{re.escape(c)}\b", t, new)
            if new == cur:
                break
            cur = new
    finally:
        open(path, "w").write(original)
    return best


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("modules", nargs="*")
    ap.add_argument("--limit", type=int, default=0)
    args = ap.parse_args()

    from collections import defaultdict
    mods = args.modules or T.modules()
    by_shape, done = defaultdict(list), set()
    for mod in mods if not args.modules else T.modules():
        have = T.defined_in(mod)
        for name, (words, shapes) in T.parse(mod).items():
            key = (mod, name)
            by_shape[shapes].append(key)
            if name in have:
                done.add(key)
    groups = [m for m in by_shape.values() if len(m) > 1]
    print(f"{len(groups)} shape groups, {len(done)} functions already matched", flush=True)

    added = 0
    for members in groups:
        have = [m for m in members if m in done]
        want = [m for m in members if m not in done]
        if not have or not want:
            continue
        src = T.body_of(*have[0])
        if not src:
            continue
        for mod, fn in want:
            if args.modules and mod not in args.modules:
                continue
            path = os.path.join(ROOT, "src", mod + ".c")
            if not os.path.exists(path):
                continue
            renamed = re.sub(rf"\b{have[0][1]}\b(?=\s*\()", fn, src, count=1)
            got = adapt(mod, fn, renamed)
            if not got:
                continue
            before = open(path).read()
            entry = {"func": fn, "words": 0, "shape": "same-shape twin", "src": got}
            open(path, "w").write(M.insert(before, entry, []))
            bad = M.verify(mod, M.defined_in(before) | {fn})
            if bad is None or bad:
                open(path, "w").write(before)
            else:
                done.add((mod, fn))
                added += 1
                print(f"  + {mod} {fn}  (adapted from {have[0][0]} {have[0][1]})", flush=True)
                if args.limit and added >= args.limit:
                    print(f"\nadapted {added} functions")
                    return
    print(f"\nadapted {added} functions")


if __name__ == "__main__":
    main()
