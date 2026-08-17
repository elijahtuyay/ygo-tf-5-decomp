#!/usr/bin/env python3
"""
Add newly-matched functions to an existing module source file, one at a time.

    scripts/merge_matches.py rel_gallery

`assemble_module.py` rebuilds a file from scratch and throws away hand-written
headers, comments and hand-fixed functions. This only ever ADDS: it takes the
functions in build/auto/<module>.matched.json that are not yet in
src/<module>.c, inserts each in address order, and re-verifies the whole file
after every insertion. If an insertion breaks anything — itself or a neighbour —
it is rolled back and the next one is tried.

That makes it safe to run against files that agents or humans are curating: the
worst case is that nothing is added.
"""
import json
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def symbols(module):
    out = {}
    p = os.path.join(ROOT, "config/symbols", module + ".txt")
    if os.path.exists(p):
        for line in open(p):
            m = re.match(r"(\w+) = 0x([0-9A-Fa-f]+);(.*)", line)
            if m:
                out[m.group(1)] = "func" if "type:func" in m.group(3) else "data"
    return out


def defined_in(text):
    return set(re.findall(r"^[A-Za-z_][\w \*]*?\b(func_[0-9A-F]+)\s*\([^;]*$", text, re.M))


def block_decls(src, symtab):
    """Externs for one function, at block scope (widths differ between users)."""
    out = []
    for n in sorted(set(re.findall(r"\b\w+\b", src))):
        if n in symtab:
            out.append(f"    extern int {n}();" if symtab[n] == "func"
                       else f"    extern char {n};")
        elif re.match(r"^(D|jtbl)_[0-9A-F]{4,8}$", n):
            out.append(f"    extern char {n};")
        elif re.match(r"^func_[0-9A-F]{8}$", n):
            out.append(f"    extern int {n}();")
    return out


def verify(module, names):
    r = subprocess.run([os.path.join(ROOT, "scripts/mwcc_build.sh"),
                        os.path.join(ROOT, "src", module + ".c")],
                       capture_output=True, text=True, cwd=ROOT)
    if r.returncode != 0:
        return None
    d = subprocess.run([sys.executable, os.path.join(ROOT, "scripts/mwcc_diff.py"),
                        os.path.join(ROOT, "asm", module, "text.s"),
                        os.path.join(ROOT, "build/mwcc", module + ".o")],
                       capture_output=True, text=True, cwd=ROOT)
    bad = set()
    for line in d.stdout.splitlines():
        m = re.match(r"^(func_[0-9A-F]+): (.*)$", line)
        if m and m.group(1) in names and not m.group(2).startswith("MATCH"):
            bad.add(m.group(1))
    return bad


def insert(text, entry, decls):
    """Place a function in address order among the existing definitions."""
    addr = int(entry["func"][5:], 16)
    body = entry["src"]
    m = re.search(r"\{", body)
    if m:
        body = body[:m.end()] + "\n" + "\n".join(decls) + body[m.end():]
    # Some functions only match at optimisation level 2 — level 3 is where MWCC
    # turns on instruction scheduling and tail-call optimisation, and these
    # targets have unfilled delay slots or real jal+frame calls. A per-function
    # `#pragma optimization_level` reproduces that inside the project's normal
    # -O4,s build, so the module still compiles as one translation unit.
    if "-O2" in entry.get("shape", ""):
        body = ("#pragma optimization_level 2\n" + body +
                "\n#pragma optimization_level 4")
    chunk = (f"\n/* {entry['func']} — {entry['words']} words. MATCH 100% "
             f"(shape: {entry['shape']}). */\n{body}\n")
    lines = text.split("\n")
    for i, line in enumerate(lines):
        m = re.match(r"^[A-Za-z_][\w \*]*?\bfunc_([0-9A-F]+)\s*\([^;]*$", line)
        if m and int(m.group(1), 16) > addr:
            back = i
            while back > 0 and (lines[back - 1].strip().startswith(("/*", "*", "*/"))
                                or not lines[back - 1].strip()):
                back -= 1
            return "\n".join(lines[:back]) + chunk + "\n".join(lines[back:])
    return text.rstrip("\n") + "\n" + chunk


def harvest_objects(module):
    """Trial objects in build/auto/<module>/ that MATCH but were never recorded.

    auto_decomp only records the first shape that matches, and agents leave
    behind trials they verified by hand; one agent found 87 already-matching
    functions in rel_duel_draw this way. Re-diff every object and recover them."""
    d = os.path.join(ROOT, "build/auto", module)
    found = []
    if not os.path.isdir(d):
        return found
    for obj in sorted(os.listdir(d)):
        if not obj.endswith(".o"):
            continue
        fn = obj[:-2]
        if not re.match(r"^func_[0-9A-F]+$", fn):
            continue
        csrc = os.path.join(d, fn + ".c")
        if not os.path.exists(csrc):
            continue
        r = subprocess.run([sys.executable, os.path.join(ROOT, "scripts/mwcc_diff.py"),
                            os.path.join(ROOT, "asm", module, "text.s"),
                            os.path.join(d, obj), fn], capture_output=True, text=True, cwd=ROOT)
        if not re.match(rf"^{fn}: MATCH", r.stdout.strip()):
            continue
        text = open(csrc).read()
        m = re.search(rf"^[A-Za-z_][\w \*]*?\b{fn}\s*\(", text, re.M)
        if m:
            found.append({"func": fn, "words": 0, "shape": "harvested",
                          "src": text[m.start():].strip()})
    return found


def main():
    module = sys.argv[1]
    path = os.path.join(ROOT, "src", module + ".c")
    mj = os.path.join(ROOT, f"build/auto/{module}.matched.json")
    if not os.path.exists(path) or not os.path.exists(mj):
        print(f"{module}: nothing to do")
        return
    entries = json.load(open(mj))
    if "--scan-objects" in sys.argv:
        known = {e["func"] for e in entries}
        extra = [e for e in harvest_objects(module) if e["func"] not in known]
        print(f"{module}: harvested {len(extra)} matching trial objects")
        entries += extra
    symtab = symbols(module)
    have = defined_in(open(path).read())
    todo = [e for e in entries if e["func"] not in have]
    if not todo:
        print(f"{module}: nothing new ({len(have)} already present)")
        return

    added = 0
    for e in todo:
        before = open(path).read()
        names = defined_in(before) | {e["func"]}
        open(path, "w").write(insert(before, e, block_decls(e["src"], symtab)))
        bad = verify(module, names)
        if bad is None or bad:
            open(path, "w").write(before)      # roll back, try the next one
        else:
            added += 1
    print(f"{module}: added {added} of {len(todo)} candidates "
          f"({len(defined_in(open(path).read()))} now in file)")


if __name__ == "__main__":
    main()
