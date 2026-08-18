#!/usr/bin/env python3
"""
Regression gate: every function that ever verified as MATCH must stay matched.

    scripts/check_regressions.py                     # modules with uncommitted src/ changes
    scripts/check_regressions.py rel_story rel_deck  # specific modules
    scripts/check_regressions.py --all               # every module with a baseline or a src file
    scripts/check_regressions.py --update [modules]  # refresh the baseline AFTER a verified gain
    scripts/check_regressions.py --update --force    # allow the baseline to SHRINK (rare, deliberate)

The baseline (config/progress-baseline.json) is the committed list of matched
function NAMES per module — lists, not counts, so a regression names the exact
functions lost. Verification is the real thing, not bookkeeping: each checked
module is recompiled with mwccpsp and re-diffed by scripts/mwcc_diff.py, the
local equivalent of a decomp.me score of 0.

Rules this gate enforces (each bought with a real incident):
  - A module may only ever gain matches. Losing one fails the gate (exit 1)
    and names the lost functions. The rel_html_view truncation (15 -> 0,
    committed silently) is the motivating case.
  - --update refuses to shrink the baseline without --force, so a regression
    cannot be laundered into a new baseline by accident.
  - Refresh the baseline in the SAME commit as the matches it reflects.

The baseline is data, never hand-edited. If it disagrees with a fresh measure
and you did not just match something, the code regressed — not the baseline.
"""
import argparse
import datetime
import json
import os
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
BASELINE = os.path.join(ROOT, "config/progress-baseline.json")

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import progress  # noqa: E402  (module_functions, matched — the only trusted measure)


def load_baseline():
    if not os.path.exists(BASELINE):
        return {"generated": None, "modules": {}}
    with open(BASELINE) as f:
        return json.load(f)


def save_baseline(data):
    data["generated"] = datetime.date.today().isoformat()
    data["modules"] = {m: sorted(fs) for m, fs in sorted(data["modules"].items())}
    with open(BASELINE, "w") as f:
        json.dump(data, f, indent=1)
        f.write("\n")


def changed_modules():
    """Modules whose src/<m>.c differs from HEAD (staged, unstaged or untracked)."""
    r = subprocess.run(["git", "status", "--porcelain", "--", "src"],
                       capture_output=True, text=True, cwd=ROOT)
    mods = set()
    for line in r.stdout.splitlines():
        path = line[3:].strip().split(" -> ")[-1]
        if path.startswith("src/") and path.endswith(".c"):
            mods.add(os.path.basename(path)[:-2])
    return sorted(mods)


def all_modules(base):
    mods = set(base["modules"])
    src = os.path.join(ROOT, "src")
    mods.update(f[:-2] for f in os.listdir(src) if f.endswith(".c"))
    return sorted(mods)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("modules", nargs="*")
    ap.add_argument("--all", action="store_true")
    ap.add_argument("--update", action="store_true")
    ap.add_argument("--force", action="store_true",
                    help="with --update: allow the baseline to shrink")
    args = ap.parse_args()

    base = load_baseline()
    if args.modules:
        mods = args.modules
    elif args.all:
        mods = all_modules(base)
    else:
        mods = changed_modules()
        if not mods:
            print("no src/ changes vs HEAD; nothing to check (use --all for a full sweep)")
            return 0

    failed = False
    for m in mods:
        funcs = progress.module_functions(m)
        cur = progress.matched(m) & set(funcs)
        old = set(base["modules"].get(m, []))
        lost, new = sorted(old - cur), sorted(cur - old)
        if lost:
            print(f"REGRESSION {m}: {len(lost)} previously-matched function(s) no longer match:")
            for fn in lost:
                print(f"    {fn}")
            failed = True
        if new:
            print(f"gain {m}: +{len(new)} ({', '.join(new[:8])}{', ...' if len(new) > 8 else ''})")
        if not lost and not new:
            print(f"ok   {m}: {len(cur)} matched, unchanged")
        if args.update:
            if lost and not args.force:
                print(f"     refusing to shrink baseline for {m} without --force")
            else:
                base["modules"][m] = sorted(cur)

    if args.update:
        save_baseline(base)
        print(f"baseline written: {BASELINE}")

    return 1 if failed else 0


if __name__ == "__main__":
    sys.exit(main())
