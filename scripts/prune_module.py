#!/usr/bin/env python3
"""
Remove non-matching functions from a module source file, keeping everything else.

    scripts/prune_module.py rel_story

`scripts/assemble_module.py` rebuilds a file from scratch and would throw away
hand-written headers, comments and hand-fixed functions. This instead edits the
file in place: compile, diff, delete only the functions that do not report
MATCH (with the comment block immediately above them), repeat until every
function left in the file is byte-identical to the shipped module.

Written because tightening scripts/mwcc_diff.py — it used to accept two words as
equal when they carried the same relocation, without checking that the rest of
the instruction agreed, so `lb` could pass for `lw` — invalidated a number of
previously "verified" functions. Anything this removes was never really matched.
"""
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def failing(module, path):
    r = subprocess.run([os.path.join(ROOT, "scripts/mwcc_build.sh"), path],
                       capture_output=True, text=True, cwd=ROOT)
    if r.returncode != 0:
        return None
    d = subprocess.run([sys.executable, os.path.join(ROOT, "scripts/mwcc_diff.py"),
                        os.path.join(ROOT, "asm", module, "text.s"),
                        os.path.join(ROOT, "build/mwcc", module + ".o")],
                       capture_output=True, text=True, cwd=ROOT)
    bad, ok = set(), set()
    for line in d.stdout.splitlines():
        m = re.match(r"^(func_[0-9A-F]+): (.*)$", line)
        if not m:
            continue
        if "NOT COMPILED" in m.group(2):
            continue
        (ok if m.group(2).startswith("MATCH") else bad).add(m.group(1))
    return bad, ok


def cut(text, names):
    """Delete each named function DEFINITION and the comment block above it.

    A definition is a line that names the function and whose body brace follows
    on that line or the next; a prototype (`int func_X();`) must never match, or
    the brace scan runs on into the next function and eats it."""
    lines = text.split("\n")
    out, i = [], 0
    while i < len(lines):
        m = re.match(r"^[A-Za-z_][\w \*]*?\b(func_[0-9A-F]+)\s*\(", lines[i])
        is_def = bool(m) and (lines[i].rstrip().endswith("{") or
                              (i + 1 < len(lines) and lines[i + 1].strip() == "{"))
        if is_def and m.group(1) in names:
            while out and not out[-1].strip():
                out.pop()
            if out and out[-1].rstrip().endswith("*/"):
                block = []
                while out and not out[-1].lstrip().startswith("/*"):
                    block.append(out.pop())
                if out:
                    out.pop()
            depth, started = 0, False
            while i < len(lines):
                depth += lines[i].count("{") - lines[i].count("}")
                started = started or "{" in lines[i]
                i += 1
                if started and depth <= 0:
                    break
            continue
        out.append(lines[i])
        i += 1
    return "\n".join(out)


def main():
    module = sys.argv[1]
    path = os.path.join(ROOT, "src", module + ".c")
    for _ in range(10):
        res = failing(module, path)
        if res is None:
            print(f"{module}: does not compile — needs a human")
            return
        bad, ok = res
        if not bad:
            print(f"{module}: clean — {len(ok)} functions, all MATCH")
            return
        print(f"{module}: removing {len(bad)} non-matching", flush=True)
        open(path, "w").write(cut(open(path).read(), bad))
    print(f"{module}: still failing after 10 rounds")


if __name__ == "__main__":
    main()
