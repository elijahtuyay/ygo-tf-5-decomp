#!/usr/bin/env python3
"""
Why don't the drafts compile? Classify the first mwcc error, by frequency.

    scripts/gate1_census.py --sample 60
    scripts/gate1_census.py rel_field --sample 40
    scripts/gate1_census.py --sample 60 --show "illegal implicit"   # print examples

WHY. Roughly 5,000 unmatched functions never reach the differ at all: the draft
does not compile, so no amount of codegen cleverness helps. docs/20 established
that this is gate 1 and that it dominates, and that guessing which artifact
dominates WITHIN it is a good way to waste a day — its first census ran on 31
functions, picked the wrong target, and a re-run on 300 pointed somewhere else
entirely.

So this measures rather than guesses. It takes the same draft auto_decomp.py
would build, compiles it once, and records the compiler's first error verbatim.
No shapes, no retries: the question is only "what stops it compiling".
"""
import argparse
import collections
import json
import os
import random
import re
import subprocess
import sys
import tempfile

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "scripts"))
import auto_decomp as A  # noqa: E402


def first_error(text):
    """The compiler's first complaint, normalised so like groups with like."""
    lines = [l.strip() for l in text.splitlines()]
    for i, l in enumerate(lines):
        if l.startswith("#   Error:"):
            for m in lines[i + 1:]:
                if m.startswith("#") and not m.startswith("#   Error:"):
                    msg = m.lstrip("# ").strip()
                    if not msg:
                        continue
                    # strip the specific identifier so classes collapse
                    msg = re.sub(r"'[^']*'", "'X'", msg)
                    return msg
    return "(no error text)"


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("modules", nargs="*")
    ap.add_argument("--sample", type=int, default=60)
    ap.add_argument("--max-words", type=int, default=120)
    ap.add_argument("--seed", type=int, default=1)
    ap.add_argument("--show", help="print drafts whose error matches this text")
    ap.add_argument("--pool", metavar="FILE",
                    help="read the sample from FILE (written on first use). "
                         "THE SAMPLE IS NOT STABLE WITHOUT THIS: it is drawn "
                         "from the functions not in the baseline, so matching "
                         "anything changes which functions are eligible and an "
                         "A/B taken across a baseline refresh compares two "
                         "different samples. That mistake cost a correct result "
                         "here once — a change measured as -10 was really +1.")
    args = ap.parse_args()

    base = json.load(open(os.path.join(ROOT, "config/progress-baseline.json")))["modules"]
    mods = args.modules or sorted(base)

    pool = []
    for mod in mods:
        done = set(base.get(mod, []))
        for fn, lines, words in A.load_functions(mod):
            if fn not in done and words <= args.max_words:
                pool.append((mod, fn, lines, words))
    random.Random(args.seed).shuffle(pool)

    if args.pool:
        if os.path.exists(args.pool):
            want = [tuple(l.split()) for l in open(args.pool).read().split("\n") if l.strip()]
            index = {(m, f): (m, f, l, w) for m, f, l, w in pool}
            pool = [index[k] for k in want if k in index]
        else:
            with open(args.pool, "w") as fh:
                for m, f, _, _ in pool[:args.sample]:
                    fh.write(f"{m} {f}\n")

    counts = collections.Counter()
    shown = 0
    tried = compiled = 0
    with tempfile.TemporaryDirectory() as work:
        for mod, fn, lines, words in pool:
            if tried >= args.sample:
                break
            symtab = A.symbols(mod)
            ctx = os.path.join(ROOT, "build/ctx", mod + ".h")
            asm = A.slice_path(mod, fn, lines, work)
            draft = A.m2c_draft(mod, fn, ctx if os.path.exists(ctx) else None, asm)
            if not draft:
                counts["(m2c produced nothing)"] += 1
                tried += 1
                continue
            decls = A.referenced(lines, symtab, fn, A.DATA_FLAVOURS[0],
                                 A.measured_types(mod))
            # M2C_W is auto_decomp's OWN placeholder for a struct field whose
            # width m2c could not infer, and its pipeline resolves it before
            # compiling — first from the widths the target proves, then by
            # trying each candidate width. Compiling the raw draft instead just
            # measures that placeholder, which is how the first run of this
            # census came back "63% undefined identifier".
            body = A.apply_field_widths(draft, A.field_widths(lines))
            if "M2C_W" in body:
                body = body.replace("M2C_W", A.FIELD_WIDTHS[0])
            src = A.candidate_source(decls, body)
            open(os.path.join(work, f"{fn}.c"), "w").write(src)
            r = subprocess.run([A.WIBO, A.MWCC, "-c", *A.FLAGS,
                                "-o", f"{fn}.o", f"{fn}.c"],
                               capture_output=True, text=True, cwd=work)
            tried += 1
            if r.returncode == 0:
                compiled += 1
                counts["(compiles)"] += 1
                continue
            err = first_error(r.stdout + r.stderr)
            counts[err] += 1
            if args.show and args.show.lower() in err.lower() and shown < 3:
                shown += 1
                print(f"\n----- {mod}/{fn} ({words} words): {err}\n{body}\n")

    print(f"\n{tried} drafts, {compiled} compiled ({100*compiled//max(tried,1)}%)\n")
    print(f"{'count':>6}  first error")
    for err, c in counts.most_common(25):
        print(f"{c:6}  {err}")


if __name__ == "__main__":
    main()
