#!/usr/bin/env python3
"""
Set up decomp-permuter for one function, and optionally run it.

    scripts/permute.py rel_html_view func_00000470 [--run] [-j 3]

The permuter brute-forces equivalent source shapes for a function that is
already close, which makes it the right tool for exactly one failure mode: a
diff that is a pure instruction-scheduling permutation — same word count, same
instructions, wrong order. It is the wrong tool when the candidate is the wrong
SIZE, because no reshuffling of equivalent C will conjure or remove
instructions; fix the shape by hand first (docs/11-reproducing-the-pipeline.md).

It needs a directory holding four things, which this builds:

  base.c      the module's declarations plus ONLY the target function
  target.o    the shipped function, assembled from asm/<module>/text.s
  compile.sh  mwccpsp under wibo, with the project's real flags
  settings.toml

Score 0 means a match; the permuter writes the winning source to an
`output-*/` directory beside base.c. Anything it finds still has to be merged
into src/<module>.c and re-verified against the WHOLE FILE — a function can
match alone and still regress a neighbour.
"""
import argparse
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def function_defs(lines):
    """Line index -> name, for real definitions only (never prototypes)."""
    out = {}
    for i, line in enumerate(lines):
        m = re.match(r"^[A-Za-z_][\w \*]*?\b(func_[0-9A-F]+)\s*\(", line)
        if m and (line.rstrip().endswith("{") or
                  (i + 1 < len(lines) and lines[i + 1].strip() == "{")):
            out[i] = m.group(1)
    return out


def extract(module, func):
    """The file's shared declarations + just this function's body."""
    path = os.path.join(ROOT, "src", module + ".c")
    lines = open(path).read().split("\n")
    defs = function_defs(lines)
    if func not in defs.values():
        sys.exit(f"{func} is not defined in src/{module}.c")
    start = next(i for i, n in defs.items() if n == func)
    header = "\n".join(lines[:min(defs)])

    i, depth, started = start, 0, False
    while i < len(lines):
        depth += lines[i].count("{") - lines[i].count("}")
        started = started or "{" in lines[i]
        i += 1
        if started and depth <= 0:
            break
    return header + "\n\n" + "\n".join(lines[start:i]) + "\n"


def target_object(module, func, out_dir):
    """Assemble the shipped function on its own, for the permuter to match."""
    text = os.path.join(ROOT, "asm", module, "text.s")
    body, keep = [], False
    for line in open(text, errors="replace"):
        if re.match(rf"glabel {func}$", line.strip()):
            keep = True
            body.append(f"{func}:")
            continue
        if keep and line.startswith("endlabel"):
            break
        if keep:
            body.append(line.rstrip("\n"))
    if not body:
        sys.exit(f"{func} not found in asm/{module}/text.s")

    asm = os.path.join(out_dir, "target.s")
    with open(asm, "w") as fh:
        fh.write(".set noreorder\n.set noat\n.section .text\n"
                 f".globl {func}\n" + "\n".join(body) + "\n")

    prepared = os.path.join(out_dir, "target_prep.s")
    r = subprocess.run([sys.executable, os.path.join(ROOT, "scripts/asm_prepare.py"), asm],
                       capture_output=True, text=True)
    open(prepared, "w").write(r.stdout if r.returncode == 0 and r.stdout
                              else open(asm).read())

    obj = os.path.join(out_dir, "target.o")
    r = subprocess.run(["mips-linux-gnu-as", "-EL", "-march=allegrex", "-mabi=32",
                        "-o", obj, prepared], capture_output=True, text=True)
    if r.returncode != 0:
        sys.exit("assembling the target failed:\n" + r.stderr)
    return obj


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("module")
    ap.add_argument("func")
    ap.add_argument("--run", action="store_true", help="start the permuter now")
    ap.add_argument("-j", default="3", help="permuter threads")
    args = ap.parse_args()

    out_dir = os.path.join(ROOT, "build/permuter", f"{args.module}_{args.func}")
    os.makedirs(out_dir, exist_ok=True)

    open(os.path.join(out_dir, "base.c"), "w").write(extract(args.module, args.func))
    target_object(args.module, args.func, out_dir)

    sh = os.path.join(out_dir, "compile.sh")
    open(sh, "w").write(
        "#!/bin/bash\n"
        "# decomp-permuter invokes this as: compile.sh <input.c> -o <output.o>\n"
        f'exec "{ROOT}/tools/wibo-bin/wibo" '
        f'"{ROOT}/tools/mwccpsp_3.0.1_219/mwccpsp.exe" '
        '-c -O4,s -sdatathreshold 0 -o "$3" "$1"\n')
    os.chmod(sh, 0o755)

    open(os.path.join(out_dir, "settings.toml"), "w").write(
        f'func_name = "{args.func}"\ncompiler_type = "mwcc"\n')

    r = subprocess.run([sh, os.path.join(out_dir, "base.c"), "-o",
                        os.path.join(out_dir, "base.o")], capture_output=True, text=True)
    if r.returncode != 0:
        sys.exit(f"base.c does not compile on its own:\n{r.stdout}\n{r.stderr}")

    print(f"{out_dir} ready")
    if args.run:
        subprocess.run([sys.executable, os.path.join(ROOT, "tools/decomp-permuter/permuter.py"),
                        out_dir, "-j", args.j, "--stop-on-zero"])
    else:
        print(f"  python3 tools/decomp-permuter/permuter.py {out_dir} -j {args.j} --stop-on-zero")


if __name__ == "__main__":
    main()
