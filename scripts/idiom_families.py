#!/usr/bin/env python3
"""
Group unmatched functions by opcode sequence, so compiler idioms surface.

    scripts/idiom_families.py                     # every module, ranked
    scripts/idiom_families.py --min 4 --max-words 30
    scripts/idiom_families.py --show 3            # print family #3's representative

WHY. This is the most productive technique found so far: it produced 119 matched
functions in one session, most without decompiling anything.

A module's unmatched functions are not N independent puzzles. Compiler-generated
code — struct assignment, bitfield access, guarded calls — repeats verbatim, and
so do hand-written helpers that the same programmer wrote fifty times. Reduce
each function to its sequence of mnemonics with every operand discarded, and
identical sequences are almost always the same source construct:

    126 shape families with >=3 unmatched members, covering 562 functions

Solve one member by hand, then read the per-instance operands (globals,
constants, callee names, struct offsets, shift amounts) straight out of the
disassembly and generate the C for every other member mechanically. Verify each
insertion against the whole file, exactly as merge_matches does.

WHICH FAMILIES ARE WORTH THE EFFORT. Straight-line ones — a fixed sequence of
loads, a call, a store — have matched on the first or second attempt. Families
whose shape contains `beql`/`bnel` control flow have mostly NOT converged: the
branch-likely selection is one of the documented dead ends. Sort by member count
but skip to the next family as soon as two attempts fail; there is always
another.

Families solved so far are listed in docs/11 under "Idiom mining".
"""
import argparse
import collections
import json
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "scripts"))

INSN = re.compile(r"\s*/\* [0-9A-F]+ [0-9A-F]+ [0-9A-F]{8} \*/\s+(\S+)\s*(.*)")


def module_bodies(module):
    cur, body = None, collections.defaultdict(list)
    path = os.path.join(ROOT, "asm", module, "text.s")
    if not os.path.exists(path):
        return body
    for line in open(path, errors="replace"):
        g = re.match(r"glabel (func_[0-9A-F]+)", line)
        if g:
            cur = g.group(1)
            continue
        m = INSN.match(line)
        if m and cur:
            body[cur].append((m.group(1), m.group(2).strip()))
    return body


def families(min_members, max_words):
    base = json.load(open(os.path.join(ROOT, "config/progress-baseline.json")))
    shapes = collections.defaultdict(list)
    for module in base["modules"]:
        done = set(base["modules"][module])
        for fn, ins in module_bodies(module).items():
            if fn in done or len(ins) > max_words:
                continue
            shapes[tuple(o for o, _ in ins)].append((module, fn))
    out = [(k, v) for k, v in shapes.items() if len(v) >= min_members]
    out.sort(key=lambda kv: -len(kv[1]))
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--min", type=int, default=4)
    ap.add_argument("--max-words", type=int, default=30)
    ap.add_argument("--show", type=int, default=None,
                    help="print the representative function of family N")
    ap.add_argument("--top", type=int, default=15)
    a = ap.parse_args()

    fams = families(a.min, a.max_words)
    total = sum(len(v) for _, v in fams)
    print(f"{len(fams)} families with >={a.min} unmatched members "
          f"(<={a.max_words} instructions), covering {total} functions\n")

    if a.show is not None:
        ops, mem = fams[a.show]
        module, fn = mem[0]
        print(f"family #{a.show}: {len(mem)} members, {len(ops)} instructions")
        print("members: " + ", ".join(f"{m}/{f}" for m, f in mem[:12]))
        print(f"\nrepresentative {fn} in {module}:\n")
        for mnem, operands in module_bodies(module)[fn]:
            print(f"    {mnem:<10} {operands}")
        return

    for i, (ops, mem) in enumerate(fams[:a.top]):
        mods = collections.Counter(m for m, _ in mem)
        branchy = " [branch-likely: usually a dead end]" if any(
            o in ("beql", "bnel", "beqzl", "bnezl") for o in ops) else ""
        print(f"[{i:>2}] {len(mem):>3} members  {len(ops):>2} instrs  "
              f"{mem[0][1]} ({mem[0][0]}){branchy}")
        print(f"     {' '.join(ops)[:88]}")
        if len(mods) > 1:
            print(f"     spans: {dict(mods)}")


if __name__ == "__main__":
    main()
