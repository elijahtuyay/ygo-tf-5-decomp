#!/usr/bin/env python3
"""
Derive each global's C type from every access to it, across a whole module.

    scripts/gen_types.py rel_duel_eng     # report
    scripts/gen_types.py --all --write    # emit include/globals/<module>.h

WHY THIS IS THE THING THAT BREAKS THE SIZE CLIFF.

Match rate collapses with function size — 11% at 80 instructions, 0.08% at 160,
0% beyond — and the cause is not that big functions are vaguely "harder". It is
that a function must get EVERY type right simultaneously, and the number of
independent type decisions grows with size:

    function size   median distinct memory operands touched
    <= 20 words     3
    21-80 words     6
    81-160 words    12
    > 160 words     22

If each guess is right with probability p, then observing 11% success at 6
decisions implies p ~ 0.69, which predicts 0.9% at 12 decisions and 0.02% at 22.
That is what we measure. The cliff is a compounding-guess failure, and it cannot
be fixed by trying harder on individual functions.

It CAN be fixed by not guessing. The access width of a global is stated by every
instruction that touches it, and across a whole module those statements agree:

    3,344 of 3,526 named globals (95%) are accessed at exactly ONE width

So the type is already determined by the binary; the project simply throws that
information away by re-deciding it per function. scripts/auto_decomp.py declares
`extern int D_x;` and retries `char`/`short`/`void *` per candidate;
scripts/merge_matches.py rediscovers the same thing again at merge time.

This script aggregates every access in a module and emits one header where each
global has the single type the binary proves. Feed that to the drafting and
merging steps and p goes to ~1 for globals, which flattens the cliff.

Ambiguous globals — accessed at two widths, usually a union or a struct sharing
a base — are emitted as commented-out lines rather than guessed, so they stay
visible instead of silently becoming wrong.
"""
import argparse
import collections
import json
import os
import re

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

# The declared type of a global decides the load width MWCC emits, so the width
# the ORIGINAL used tells us the declaration. Signedness follows the same rule:
# `lb` is signed char, `lbu` unsigned.
# A STORE reveals the width but says nothing about signedness — `sb` is what
# MWCC emits for both `char` and `unsigned char`. Only a load distinguishes
# them (`lb` vs `lbu`). Treating stores as if they voted on signedness marks a
# global that is stored with `sh` and loaded with `lh` as "seen as s16, u16"
# and therefore ambiguous, when its width was never in doubt. That mistake hid
# most of the 182 supposedly-ambiguous globals.
WIDTH = {"lb": 1, "lbu": 1, "sb": 1,
         "lh": 2, "lhu": 2, "sh": 2,
         "lw": 4, "sw": 4,
         "lwc1": 4, "swc1": 4}
SIGNED_LOAD = {"lb": True, "lbu": False, "lh": True, "lhu": False}
FLOAT_OPS = {"lwc1", "swc1"}
BY_WIDTH = {1: ("s8", "u8"), 2: ("s16", "u16"), 4: ("s32", "s32")}
ACCESS = re.compile(r"\*/\s+(l[bhw]u?|s[bhw]|lwc1|swc1)\s+\$\w+,\s*%lo\(([A-Za-z_]\w*)\)")
ADDR_OF = re.compile(r"%hi\(([A-Za-z_]\w*)\)")


def scan(module):
    """{global: {types}} plus the globals only ever used as an address.

    Width comes from every access; signedness only from loads, which are the
    only instructions that carry it."""
    widths = collections.defaultdict(set)
    signed = collections.defaultdict(set)
    floats = set()
    addressed = set()
    path = os.path.join(ROOT, "asm", module, "text.s")
    for line in open(path, errors="replace"):
        m = ACCESS.search(line)
        if m:
            op, name = m.group(1), m.group(2)
            if op in WIDTH:
                widths[name].add(WIDTH[op])
            if op in FLOAT_OPS:
                floats.add(name)
            if op in SIGNED_LOAD:
                signed[name].add(SIGNED_LOAD[op])
        for g in ADDR_OF.findall(line):
            addressed.add(g)

    types = {}
    for name, w in widths.items():
        if len(w) != 1:
            types[name] = {f"w{x}" for x in sorted(w)}   # genuinely ambiguous width
            continue
        width = next(iter(w))
        if name in floats:
            types[name] = {"f32"}
            continue
        sign = signed.get(name, set())
        if len(sign) > 1:
            # loaded both signed and unsigned: same width, so the width is safe
            # but the declaration has to pick one. Prefer the unsigned form,
            # which is what a store-heavy global usually is.
            types[name] = {BY_WIDTH[width][1]}
        elif sign:
            types[name] = {BY_WIDTH[width][0 if next(iter(sign)) else 1]}
        else:
            types[name] = {BY_WIDTH[width][1]}           # stores only
    return types, addressed


def emit(module, types, addressed):
    determined = {g: next(iter(t)) for g, t in types.items() if len(t) == 1}
    ambiguous = {g: sorted(t) for g, t in types.items() if len(t) > 1}
    array_only = sorted(addressed - set(types))

    out = [
        "/* Generated by scripts/gen_types.py - do not edit.",
        " *",
        " * Each global's type is taken from the width EVERY instruction in the",
        " * module uses to access it, not guessed per function. Where the module",
        " * disagrees with itself the global is left commented out rather than",
        " * guessed, because a wrong width silently changes the load opcode and",
        " * breaks whichever function uses it.",
        " */",
        f"#ifndef GLOBALS_{module.upper()}_H",
        f"#define GLOBALS_{module.upper()}_H", "",
        "typedef signed char s8;   typedef unsigned char u8;",
        "typedef short s16;        typedef unsigned short u16;",
        "typedef int s32;          typedef unsigned int u32;",
        "typedef float f32;", "",
        f"/* {len(determined)} globals with a type the binary determines */",
    ]
    for g in sorted(determined):
        out.append(f"extern {determined[g]} {g};")
    if ambiguous:
        out += ["", f"/* {len(ambiguous)} accessed at more than one width — a union, or two",
                " * structs sharing a base. Decide these by hand before using them. */"]
        for g in sorted(ambiguous):
            out.append(f"/* extern ? {g};   seen as {', '.join(ambiguous[g])} */")
    if array_only:
        out += ["", f"/* {len(array_only)} only ever have their ADDRESS taken (arrays,",
                " * structs, string literals); the element type is not implied. */"]
        for g in array_only[:400]:
            out.append(f"/* extern ? {g}; */")
    out += ["", f"#endif /* GLOBALS_{module.upper()}_H */"]
    return "\n".join(out) + "\n", len(determined), len(ambiguous), len(array_only)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("modules", nargs="*")
    ap.add_argument("--all", action="store_true")
    ap.add_argument("--write", action="store_true")
    a = ap.parse_args()

    mods = a.modules
    if a.all:
        base = json.load(open(os.path.join(ROOT, "config/progress-baseline.json")))
        mods = sorted(base["modules"])

    td = ta = tq = 0
    for m in mods:
        if not os.path.exists(os.path.join(ROOT, "asm", m, "text.s")):
            continue
        types, addressed = scan(m)
        text, d, amb, arr = emit(m, types, addressed)
        td += d
        ta += amb
        tq += arr
        if a.write:
            dst = os.path.join(ROOT, "include/globals", m + ".h")
            os.makedirs(os.path.dirname(dst), exist_ok=True)
            open(dst, "w").write(text)
        print(f"{m:<20} {d:>5} determined  {amb:>3} ambiguous  {arr:>4} address-only")
    print(f"{'TOTAL':<20} {td:>5} determined  {ta:>3} ambiguous  {tq:>4} address-only")


if __name__ == "__main__":
    main()
