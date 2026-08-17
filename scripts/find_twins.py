#!/usr/bin/env python3
"""
Find functions that are duplicates of each other, within and across modules.

    scripts/find_twins.py                 # every module, actionable groups only
    scripts/find_twins.py rel_field       # one module
    scripts/find_twins.py --all           # include groups with nothing matched yet

Konami shipped the same function at several addresses many times over — often
the same code linked into two modules, sometimes twice inside one module. Once
any member of such a group matches, every other member is a free match: paste
the same body under the other name and verify.

Two tiers are reported:

  identical   the raw instruction words are equal. Same source, guaranteed.
  same-shape  equal once immediates, symbols and branch targets are masked out.
              Same source modulo constants and which symbol is referenced, so
              the body transfers with small edits rather than verbatim.

The shape tier exists because a naive raw-word comparison misses real twins:
two copies of one function that reference different globals differ in their
`lui`/`lo` words, and two copies with different branch targets differ in every
branch word. A previous by-hand pass missed two genuine `rel_field` pairs for
exactly that reason.

Groups are reported only when at least one member is already matched and at
least one is not — those are the ones worth acting on. `--all` shows the rest.
"""
import os
import re
import sys
from collections import defaultdict

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

# `/* 4C4 00000470 F0FFBD27 */  addiu  $sp, $sp, -0x10`
INSN = re.compile(r"/\* [0-9A-F]+ [0-9A-F]+ ([0-9A-F]{8}) \*/\s+(\S+)\s*(.*)")


def modules():
    d = os.path.join(ROOT, "iso_extracted/PSP_GAME/USRDIR/gmodule")
    return sorted(f[:-4] for f in os.listdir(d) if f.endswith(".prx"))


def shape(mnemonic, operands):
    """Operands with anything address-like removed, registers kept.

    Immediates, symbol references and branch labels all vary between two copies
    of the same source; the register allocation and the opcode sequence do not.
    """
    ops = re.sub(r"%(hi|lo)\([^)]*\)", "S", operands)
    ops = re.sub(r"\.L[0-9A-Fa-f]+|\b[a-zA-Z_]\w{3,}\b", "S", ops)
    ops = re.sub(r"-?\b0x[0-9A-Fa-f]+\b|-?\b\d+\b", "I", ops)
    return mnemonic + " " + " ".join(ops.split())


def parse(module):
    """{name: (raw_words, shape_lines)} for one module."""
    path = os.path.join(ROOT, "asm", module, "text.s")
    out, cur, words, shapes, hand = {}, None, [], [], False
    if not os.path.exists(path):
        return out
    for line in open(path, errors="replace"):
        m = re.match(r"glabel (\w+)", line)
        if m:
            cur, words, shapes, hand = m.group(1), [], [], False
            continue
        if cur is None:
            continue
        if "Handwritten function" in line:
            hand = True
        if line.startswith("endlabel"):
            if words and not hand:          # handwritten ones can never match
                out[cur] = ("".join(words), "\n".join(shapes))
            cur = None
            continue
        m = INSN.match(line.strip())
        if m:
            words.append(m.group(1))
            shapes.append(shape(m.group(2), m.group(3)))
    return out


def defined_in(module):
    p = os.path.join(ROOT, "src", module + ".c")
    if not os.path.exists(p):
        return set()
    return set(re.findall(r"^[A-Za-z_][\w \*]*?\b(func_[0-9A-F]+)\s*\([^;]*$",
                          open(p).read(), re.M))


def report(title, groups, done, show_all):
    actionable = 0
    for key, members in sorted(groups.items(), key=lambda kv: -len(kv[1])):
        if len(members) < 2:
            continue
        have = [m for m in members if m in done]
        want = [m for m in members if m not in done]
        if not show_all and (not have or not want):
            continue
        actionable += len(want)
        print(f"  {len(members)} copies, {len(have)} matched:")
        for m in have:
            print(f"      DONE {m[1]:<20} {m[0]}")
        for m in want[:8]:
            print(f"      todo {m[1]:<20} {m[0]}")
        if len(want) > 8:
            print(f"           ... and {len(want) - 8} more")
    print(f"{title}: {actionable} functions obtainable by copying a matched twin\n")


def main():
    args = [a for a in sys.argv[1:] if not a.startswith("-")]
    show_all = "--all" in sys.argv
    mods = args or modules()

    by_words, by_shape, done = defaultdict(list), defaultdict(list), set()
    for mod in mods:
        have = defined_in(mod)
        for name, (words, shapes) in parse(mod).items():
            key = (mod, name)
            by_words[words].append(key)
            by_shape[shapes].append(key)
            if name in have:
                done.add(key)

    print(f"{len(mods)} module(s), {sum(len(v) for v in by_words.values())} "
          f"matchable functions, {len(done)} already matched\n")
    print("=== identical instruction words ===")
    report("identical", by_words, done, show_all)
    print("=== identical once immediates and symbols are masked ===")
    report("same-shape", by_shape, done, show_all)


if __name__ == "__main__":
    main()
