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
    return set(re.findall(r"^[A-Za-z_][\w \*]*?\b(func_[0-9A-F]+)\s*\([^;\n]*$",
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


def body_of(module, func):
    """The source text of an already-matched function, from src/<module>.c."""
    path = os.path.join(ROOT, "src", module + ".c")
    lines = open(path).read().split("\n")
    start = None
    for i, line in enumerate(lines):
        if not re.match(rf"^[A-Za-z_][\w \*]*?\b{func}\s*\(", line):
            continue
        # The body brace follows immediately for an ANSI definition, but a K&R
        # one puts its parameter declarations in between:
        #     void f(a, b)
        #     int a;  int b;
        #     {
        # Those declarations are exactly what lever 22 needs, so look ahead a
        # few lines rather than rejecting the definition outright.
        if line.rstrip().endswith("{"):
            start = i
            break
        for j in range(i + 1, min(i + 8, len(lines))):
            stripped = lines[j].strip()
            if stripped == "{" or stripped.endswith("{"):
                start = i
                break
            if not stripped or not stripped.endswith(";"):
                break
        if start is not None:
            break
    if start is None:
        return None
    i, depth, started = start, 0, False
    while i < len(lines):
        depth += lines[i].count("{") - lines[i].count("}")
        started = started or "{" in lines[i]
        i += 1
        if started and depth <= 0:
            break
    return "\n".join(lines[start:i])


def apply_twins(groups, done):
    """Copy each matched body onto its unmatched duplicates and verify."""
    sys.path.insert(0, os.path.join(ROOT, "scripts"))
    import merge_matches as M

    added = 0
    for members in groups.values():
        have = [m for m in members if m in done]
        want = [m for m in members if m not in done]
        if not have or not want:
            continue
        src = body_of(*have[0])
        if not src:
            continue
        for mod, func in want:
            path = os.path.join(ROOT, "src", mod + ".c")
            if not os.path.exists(path):
                continue
            before = open(path).read()
            if func in M.defined_in(before):
                continue
            # Rename the definition only; anything it calls keeps its own name.
            renamed = re.sub(rf"\b{have[0][1]}\b(?=\s*\()", func, src, count=1)
            entry = {"func": func, "words": 0, "shape": f"twin of {have[0][1]}",
                     "src": renamed}
            open(path, "w").write(M.insert(before, entry, []))
            bad = M.verify(mod, M.defined_in(before) | {func})
            if bad is None or bad:
                open(path, "w").write(before)
            else:
                done.add((mod, func))
                added += 1
                print(f"  + {mod} {func}  (twin of {have[0][0]} {have[0][1]})",
                      flush=True)
    return added


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
    if "--apply" in sys.argv:
        # Only the exact tier is safe to copy blind; the shape tier differs in
        # constants and symbols, so those still need a human edit.
        print("copying matched bodies onto their exact duplicates:")
        n = apply_twins(by_words, done)
        print(f"\nadded {n} functions")
        return

    print("=== identical instruction words ===")
    report("identical", by_words, done, show_all)
    print("=== identical once immediates and symbols are masked ===")
    report("same-shape", by_shape, done, show_all)


if __name__ == "__main__":
    main()
