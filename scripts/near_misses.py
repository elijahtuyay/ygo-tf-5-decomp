#!/usr/bin/env python3
"""
The work queue: unmatched functions ranked by how close the automated pass got.

    scripts/near_misses.py                  # every module, closest first
    scripts/near_misses.py rel_field        # one module
    scripts/near_misses.py --max-delta 3    # only the ones a person could finish

WHY THIS EXISTS. `scripts/auto_decomp.py` records a verdict for every function
it tries, then throws the near-misses away: anything short of MATCH is equally
worthless to the merge step. But those verdicts are exactly the triage a human
needs. A draft that compiles and lands within one or two instructions of the
target is a completely different proposition from one that will not compile at
all, and the two should not sit in the same undifferentiated pile of "not done".

sotn-decomp works from a difficulty-sorted list for the same reason. This is
ours, built from data the pipeline already produces.

WHAT THE COLUMNS MEAN, and which are worth your time:

  +/-Nw      candidate words minus target words; the size is wrong by N.
  N diffs    the size is RIGHT and only contents differ — usually the best
             candidates, and often one lever from docs/11 away.
  compile    the draft does not compile. Not a matching problem at all; see
             docs/11 "Why the size cliff exists" for the artifact classes.

Functions whose diff is a known dead end (scratch-register choice, branch-likely
selection, commutative operand order) are NOT filtered out, because the verdict
string alone cannot identify them. Check docs/11 before spending long on
anything that looks like one.
"""
import argparse
import json
import os
import re

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

SIZE = re.compile(r"target=(\d+) words candidate=(\d+) words")
DIFFS = re.compile(r": (\d+) diff")


def baseline():
    """Functions already verified as matching, so stale verdicts are dropped.

    build/auto/*.json is a cache of whatever the last run of auto_decomp saw,
    including sharded files from old runs. Plenty of those functions have since
    been matched by other means (twins, idioms, hand work). Reporting them as
    near-misses would send a person to re-solve solved problems — which is
    exactly what happened the first time this was written."""
    path = os.path.join(ROOT, "config/progress-baseline.json")
    if not os.path.exists(path):
        return {}
    return {m: set(v) for m, v in json.load(open(path))["modules"].items()}


DONE = None


def load(module):
    global DONE
    if DONE is None:
        DONE = baseline()
    path = os.path.join(ROOT, "build/auto", module + ".json")
    if not os.path.exists(path):
        return []
    try:
        data = json.load(open(path))
    except Exception:
        return []
    out = []
    res = data.get("results", []) if isinstance(data, dict) else data
    # a sharded cache file is named rel_x.1of6 but its functions live in rel_x
    real = module.split(".")[0]
    done = DONE.get(real, set())
    for e in res if isinstance(res, list) else []:
        if not isinstance(e, dict) or e.get("status") == "MATCH":
            continue
        if e.get("func") in done:
            continue
        closest = str(e.get("closest") or "")
        words = e.get("words") or 0
        if closest == "compile-error":
            out.append((10 ** 6, "compile", real, e.get("func"), words))
            continue
        m = SIZE.search(closest)
        if m:
            d = int(m.group(2)) - int(m.group(1))
            out.append((abs(d) * 10 + 5, f"{d:+d}w", real, e.get("func"), words))
            continue
        n = DIFFS.search(closest)
        if n:
            out.append((int(n.group(1)), f"{n.group(1)} diffs", real, e.get("func"), words))
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("modules", nargs="*")
    ap.add_argument("--max-delta", type=int, default=None,
                    help="only rows this close (word delta or diff count)")
    ap.add_argument("--top", type=int, default=40)
    a = ap.parse_args()

    mods = a.modules
    if not mods:
        auto = os.path.join(ROOT, "build/auto")
        if not os.path.isdir(auto):
            print("no build/auto — run scripts/auto_decomp.py <module> first")
            return
        mods = sorted(f[:-5] for f in os.listdir(auto)
                      if f.endswith(".json") and not f.endswith(".matched.json"))

    rows = []
    for m in mods:
        rows.extend(load(m))
    if not rows:
        print("no auto_decomp results yet — run scripts/auto_decomp.py <module> first")
        return
    rows.sort()

    shown = [r for r in rows
             if r[1] != "compile" and (a.max_delta is None or r[0] <= a.max_delta * 10 + 5)]
    compile_errors = sum(1 for r in rows if r[1] == "compile")
    print(f"{len(rows)} unmatched functions with a recorded verdict "
          f"({compile_errors} do not compile, {len(rows) - compile_errors} do)\n")
    print(f"{'closeness':<12}{'words':>6}  function")
    for _, label, module, fn, words in shown[:a.top]:
        print(f"{label:<12}{words:>6}  {module}/{fn}")


if __name__ == "__main__":
    main()
