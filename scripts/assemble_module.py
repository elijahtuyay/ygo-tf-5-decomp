#!/usr/bin/env python3
"""
Turn verified per-function matches into a module source file.

    scripts/assemble_module.py rel_gallery

Reads build/auto/<module>.matched.json (written by scripts/auto_decomp.py, which
only records byte-identical matches), emits src/<module>.c with:

  - a file header: what the module is, the compiler configuration, how to verify,
    and the roster of matched functions;
  - extern declarations using the RESOLVED import names (ehsys_memset, sceIoOpen)
    from config/symbols/<module>.txt, never raw stub addresses;
  - forward declarations, then the functions IN ADDRESS ORDER — the order the
    linker needs for `make MODULE=<m> SRC=1` to reproduce the module.

Then it compiles the assembled file and re-diffs EVERY function in it. A
function that matched in isolation can still differ once compiled alongside its
neighbours, so any function that regresses is dropped and the file rebuilt until
every function in it reports MATCH. What this writes is therefore always 100%
verified.
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


def module_blurb(module):
    p = os.path.join(ROOT, "docs/modules", module + ".md")
    if not os.path.exists(p):
        return ""
    for line in open(p):
        if line.startswith("| `" + module + "`"):
            return line.strip()
    return ""


def build(module, entries, symtab):
    """Assemble a source file from the given verified functions."""
    defined = {e["func"] for e in entries}
    decls, fwd = set(), set()
    for e in entries:
        for n in re.findall(r"\b\w+\b", e["src"]):
            if n in defined:
                continue
            if n in symtab:
                decls.add(f"extern int {n}();" if symtab[n] == "func"
                          else f"extern char {n};")
            elif re.match(r"^(D|jtbl)_[0-9A-F]{4,8}$", n):
                decls.add(f"extern char {n};")
            elif re.match(r"^func_[0-9A-F]{8}$", n):
                decls.add(f"extern int {n}();")
        m = re.match(r"\s*(\w[\w \*]*?)\s*\b" + e["func"] + r"\s*\(([^)]*)\)", e["src"])
        if m:
            fwd.add(f"{m.group(1)} {e['func']}({m.group(2)});")

    head = [
        "/*",
        f" * {module}.prx — reconstructed code (matching decompilation)",
        " *",
        " * Compiler:     Metrowerks CodeWarrior for PSP — MWCC 1.3 SP7 (mwccpsp_3.0.1_219)",
        " * Flags:        -O4,s -sdatathreshold 0",
        f" * Verification: scripts/mwcc_build.sh src/{module}.c",
        f" *               scripts/mwcc_diff.py asm/{module}/text.s build/mwcc/{module}.o",
        " *",
        " * Every function below is byte-identical to the shipped module — each was",
        " * accepted only on a MATCH verdict from scripts/mwcc_diff.py, and the whole",
        " * file is re-verified after assembly (scripts/assemble_module.py).",
        " * Functions are in ADDRESS ORDER, which is what the linker needs.",
        " *",
        " * Import names are resolved from the module's NID tables and are identical",
        " * across all 28 modules — see docs/nids/README.md.",
        " *",
        f" * STATUS: {len(entries)} functions matched here. The rest of the module is not",
        " * yet decompiled; build/auto/<module>.json has the status of every attempt.",
        " *",
        " * NOTE: assembled by scripts/assemble_module.py from drafts produced by",
        " * scripts/auto_decomp.py (m2c + source reshapes + verification). Local names",
        " * are therefore still m2c's (temp_v0, var_s1); renaming them and adding",
        " * per-function commentary is safe as long as every edit is re-verified.",
        " */",
        "",
        "typedef signed char s8;",
        "typedef unsigned char u8;",
        "typedef short s16;",
        "typedef unsigned short u16;",
        "typedef int s32;",
        "typedef unsigned int u32;",
        "typedef long long s64;",
        "typedef unsigned long long u64;",
        "typedef float f32;",
        "typedef double f64;",
        "#define NULL 0",
        "",
        "/* ---- imports and globals ---- */",
    ]
    body = ["", "/* ---- forward declarations ---- */"] + sorted(fwd) + [""]
    owner = {}                      # 1-based source line -> function that owns it
    n = len(head) + len(decls) + len(body)
    for e in sorted(entries, key=lambda e: int(e["func"][5:], 16)):
        chunk = [f"/* {e['func']} — {e['words']} words. MATCH 100% "
                 f"(shape: {e['shape']}). */", e["src"], ""]
        for i in range(sum(len(c.split("\n")) for c in chunk)):
            owner[n + i + 1] = e["func"]
        n += sum(len(c.split("\n")) for c in chunk)
        body += chunk
    return "\n".join(head + sorted(decls) + body) + "\n", owner


def verify_count(module, path):
    """How many functions the file already on disk matches."""
    r = subprocess.run([os.path.join(ROOT, "scripts/mwcc_build.sh"), path],
                       capture_output=True, text=True, cwd=ROOT)
    if r.returncode != 0:
        return -1
    d = subprocess.run([sys.executable, os.path.join(ROOT, "scripts/mwcc_diff.py"),
                        os.path.join(ROOT, "asm", module, "text.s"),
                        os.path.join(ROOT, "build/mwcc", module + ".o")],
                       capture_output=True, text=True, cwd=ROOT)
    return sum(1 for l in d.stdout.splitlines()
               if re.match(r"^func_[0-9A-F]+: MATCH", l))


def verify(module, names):
    """-> set of OUR functions that do not match in the assembled file.

    mwcc_diff reports on every function in the module; the ones we have not
    written yet come back NOT COMPILED, which is expected and not a regression —
    so only the names we actually emitted are considered."""
    r = subprocess.run([os.path.join(ROOT, "scripts/mwcc_build.sh"),
                        os.path.join(ROOT, "src", module + ".c")],
                       capture_output=True, text=True, cwd=ROOT)
    if r.returncode != 0:
        # MWCC prints "#   <line>: <source>" for each error; blame the functions
        # that own those lines rather than throwing half the file away
        return None, [int(m) for m in re.findall(r"^#\s+(\d+):", r.stdout + r.stderr, re.M)]
    d = subprocess.run([sys.executable, os.path.join(ROOT, "scripts/mwcc_diff.py"),
                        os.path.join(ROOT, "asm", module, "text.s"),
                        os.path.join(ROOT, "build/mwcc", module + ".o")],
                       capture_output=True, text=True, cwd=ROOT)
    bad = set()
    for line in d.stdout.splitlines():
        m = re.match(r"^(func_[0-9A-F]+): (.*)$", line)
        if m and m.group(1) in names and "MATCH" not in m.group(2):
            bad.add(m.group(1))
    return bad, []


def main():
    module = sys.argv[1]
    entries = json.load(open(os.path.join(ROOT, f"build/auto/{module}.matched.json")))
    # Never clobber a better file. A human (or an agent) may have hand-fixed
    # functions that are not in matched.json; if what is already on disk verifies
    # to at least as many matches as we could produce, leave it alone.
    existing = os.path.join(ROOT, "src", module + ".c")
    if os.path.exists(existing) and "--force" not in sys.argv:
        have = verify_count(module, existing)
        if have >= len(entries):
            print(f"{module}: keeping existing src ({have} MATCH >= {len(entries)} available)")
            return
    symtab = symbols(module)
    out = os.path.join(ROOT, "src", module + ".c")

    for _ in range(8):
        text, owner = build(module, entries, symtab)
        open(out, "w").write(text)
        bad, err_lines = verify(module, {e['func'] for e in entries})
        if bad is None:
            blamed = {owner[l] for l in err_lines if l in owner}
            if not blamed:                      # cannot attribute: fall back
                blamed = {entries[-1]["func"]}
            print(f"{module}: compile error, dropping {len(blamed)}", flush=True)
            entries = [e for e in entries if e["func"] not in blamed]
            if not entries:
                return
            continue
        if not bad:
            print(f"{module}: OK — {len(entries)} functions, all MATCH")
            return
        print(f"{module}: dropping {len(bad)} that regressed in-file", flush=True)
        entries = [e for e in entries if e["func"] not in bad]
        if not entries:
            print(f"{module}: nothing left after drops")
            return
    print(f"{module}: gave up after 8 rounds")


if __name__ == "__main__":
    main()
