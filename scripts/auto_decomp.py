#!/usr/bin/env python3
"""
Automated per-function matching loop — the rel_movie_viewer process, mechanised.

    scripts/auto_decomp.py rel_gallery                 # whole module
    scripts/auto_decomp.py rel_gallery --max-words 24  # only small functions
    scripts/auto_decomp.py rel_gallery --only func_00000123

For every function in a module it: slices the function out of splat's text.s,
asks m2c for a draft, rewrites the draft through a series of source shapes that
are known to change MWCC's codegen, compiles each candidate with the real
compiler, and keeps a candidate ONLY if scripts/mwcc_diff.py reports a
byte-identical match. Nothing unverified is ever recorded as matched.

Results go to build/auto/<module>.matched.json (verified source, per function)
and build/auto/<module>.json (every function's status, so a human knows where to
start on the rest).

The shape list is the accumulated knowledge from the two modules matched by
hand — see the file headers of src/rel_movie_viewer.c and src/rel_html_view.c
for why each one exists. Add to SHAPES as new levers are found; every module run
afterwards benefits.
"""
import argparse
import json
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
MWCC = os.path.join(ROOT, "tools/mwccpsp_3.0.1_219/mwccpsp.exe")
WIBO = os.path.join(ROOT, "tools/wibo-bin/wibo")
FLAGS = ["-O4,s", "-sdatathreshold", "0"]

# m2c writes its output in terms of these; MWCC has no stdint and no m2c header.
PRELUDE = """typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
"""


# ---------------------------------------------------------------- asm slicing
def load_functions(module):
    """[(name, [asm lines], word count)] in address order."""
    path = os.path.join(ROOT, "asm", module, "text.s")
    funcs, cur, lines = [], None, []
    for line in open(path, errors="replace"):
        m = re.match(r"glabel (\w+)", line)
        if m:
            cur, lines = m.group(1), [line]
            continue
        if cur:
            lines.append(line)
            if line.startswith("endlabel"):
                words = sum(1 for l in lines if re.match(r"\s*/\* [0-9A-F]+ ", l))
                funcs.append((cur, lines, words))
                cur = None
    return funcs


def symbols(module):
    """Every name the linker knows about, so trials can declare what they use."""
    out = {}
    p = os.path.join(ROOT, "config/symbols", module + ".txt")
    if os.path.exists(p):
        for line in open(p):
            m = re.match(r"(\w+) = 0x([0-9A-Fa-f]+);(.*)", line)
            if m:
                out[m.group(1)] = "func" if "type:func" in m.group(3) else "data"
    return out


def referenced(asm_lines, symtab, self_name=None, data_type="char"):
    """Declarations a candidate needs: imports it calls, globals it touches.

    m2c decides on its own whether a global is used as a scalar or a pointer, so
    a single declaration flavour cannot satisfy every draft — the caller retries
    with each of DATA_FLAVOURS until one compiles."""
    text = "".join(asm_lines)
    names = set(re.findall(r"\b\w+\b", text))
    decls = []
    for n in sorted(names & set(symtab)):
        decls.append(f"extern int {n}();" if symtab[n] == "func" else f"extern {data_type} {n};")
    for n in sorted(set(re.findall(r"\b(?:D|jtbl)_[0-9A-F]{4,8}\b", text))):
        if n not in symtab:
            decls.append(f"extern {data_type} {n};")
    for n in sorted(set(re.findall(r"\bfunc_[0-9A-F]{8}\b", text))):
        if n != self_name:                     # never re-declare the function we define
            decls.append(f"extern int {n}();")
    return [d for d in decls if f" {self_name}(" not in d and f" {self_name};" not in d]


# ------------------------------------------------------------------ m2c draft
def m2c_draft(module, fn, ctx_path=None):
    r = subprocess.run(
        [sys.executable, os.path.join(ROOT, "tools/m2c/m2c.py"), "-f", fn]
        + (["--context", ctx_path] if ctx_path else [])
        + [os.path.join(ROOT, "asm", module, "text.s")],
        capture_output=True, text=True, cwd=ROOT)
    if r.returncode != 0:
        return None
    # keep everything from the function's definition line onward; m2c prints a
    # block of guessed prototypes above it, and we supply our own declarations
    lines = r.stdout.splitlines()
    start = None
    for i, line in enumerate(lines):
        if re.search(rf"\b{fn}\s*\(", line) and "{" in line:
            start = i
            break
    if start is None:
        return None
    body = lines[start:]
    src = "\n".join(body).strip()
    if not src or f"{fn}(" not in src:
        return None
    # m2c writes unknown types as '?'; make them compilable
    src = re.sub(r"\?\s*\*", "void *", src)
    src = re.sub(r"(?<![\w*])\?(?!\w)", "int", src)
    src = src.replace("static ", "")
    return src


# ------------------------------------------------------------------- reshapes
def shape_identity(src):
    return src


def shape_while_to_goto(src):
    """MWCC rotates `while (c) {b}` to a bottom test with an entry branch; the
    explicit goto form keeps the target's top test (rel_html_view func_00000034)."""
    m = re.search(r"(\s*)while \((.+?)\) \{\n(.*?)\n\1\}", src, re.S)
    if not m:
        return None
    ind, cond, body = m.groups()
    return src[:m.start()] + (
        f"\n{ind}_loop:\n{ind}if (!({cond})) goto _done;\n{body}\n{ind}goto _loop;\n{ind}_done:;"
    ) + src[m.end():]


def shape_dup_return(src):
    """A shared `return r;` makes MWCC pick the branch-likely form and schedule
    the return-value move into the delay slot; duplicating it inside the failure
    branch gives the plain branch (rel_html_view func_00000178/278)."""
    m = re.search(r"if \((\w+) < 0\) \{\n(.*?)\n(\s*)\}\n(\s*)return \1;", src, re.S)
    if not m:
        return None
    var, body, ind, ind2 = m.groups()
    return (src[:m.start()] +
            f"if ({var} < 0) {{\n{body}\n{ind}    return {var};\n{ind}}}\n{ind2}return {var};" +
            src[m.end():])


def shape_single_switch(src):
    """MWCC compiles a switch by branching INTO the case body; an equivalent if
    inlines it and comes out shorter. Even a one-case switch is distinct
    (rel_movie_viewer func_000001C8)."""
    m = re.search(r"(\s*)if \((\w+) == (\w+)\) \{\n(.*?)\n\1\}", src, re.S)
    if not m:
        return None
    ind, var, val, body = m.groups()
    return (src[:m.start()] +
            f"\n{ind}switch ({var}) {{\n{ind}case {val}:\n{body}\n{ind}    break;\n{ind}}}" +
            src[m.end():])


DATA_FLAVOURS = ["char", "void *", "int"]

SHAPES = [
    ("m2c", shape_identity),
    ("goto-loop", shape_while_to_goto),
    ("dup-return", shape_dup_return),
    ("single-switch", shape_single_switch),
]


# -------------------------------------------------------------------- compile
def try_candidate(module, fn, decls, body, workdir):
    src = PRELUDE + "\n" + "\n".join(decls) + "\n\n" + body + "\n"
    open(os.path.join(workdir, f"{fn}.c"), "w").write(src)
    r = subprocess.run([WIBO, MWCC, "-c", *FLAGS, "-o", f"{fn}.o", f"{fn}.c"],
                       capture_output=True, text=True, cwd=workdir)
    if r.returncode != 0:
        return None, "compile-error"
    d = subprocess.run([sys.executable, os.path.join(ROOT, "scripts/mwcc_diff.py"),
                        os.path.join(ROOT, "asm", module, "text.s"),
                        os.path.join(workdir, f"{fn}.o"), fn],
                       capture_output=True, text=True, cwd=ROOT)
    verdict = d.stdout.strip().splitlines()[0] if d.stdout.strip() else "no-output"
    return ("MATCH" in verdict and "MISMATCH" not in verdict), verdict


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("module")
    ap.add_argument("--max-words", type=int, default=10**9)
    ap.add_argument("--only")
    ap.add_argument("--limit", type=int, default=10**9)
    args = ap.parse_args()

    mod = args.module
    workdir = os.path.join(ROOT, "build/auto", mod)
    os.makedirs(workdir, exist_ok=True)
    symtab = symbols(mod)

    results, matched = [], []
    funcs = load_functions(mod)
    todo = [f for f in funcs if f[2] <= args.max_words and
            (not args.only or f[0] == args.only)][:args.limit]
    print(f"{mod}: {len(funcs)} functions, trying {len(todo)}", flush=True)

    for i, (fn, lines, words) in enumerate(todo):
        best, hit = None, False
        for flavour in DATA_FLAVOURS:
            decls = referenced(lines, symtab, fn, flavour)
            ctx = os.path.join(workdir, f"{fn}.ctx.c")
            open(ctx, "w").write(PRELUDE + "\n" + "\n".join(decls) + "\n")
            draft = m2c_draft(mod, fn, ctx)
            if not draft:
                continue
            for name, shape in SHAPES:
                body = shape(draft)
                if not body:
                    continue
                ok, verdict = try_candidate(mod, fn, decls, body, workdir)
                if ok:
                    matched.append({"func": fn, "words": words, "shape": name,
                                    "flavour": flavour, "src": body})
                    results.append({"func": fn, "words": words, "status": "MATCH",
                                    "shape": name})
                    hit = True
                    break
                if best is None or (best == "compile-error" and verdict != "compile-error"):
                    best = verdict
            if hit:
                break
        if not draft and not hit and best is None:
            results.append({"func": fn, "words": words, "status": "m2c-failed"})
            continue
        if not hit:
            results.append({"func": fn, "words": words, "status": "no-match", "closest": best})
        if (i + 1) % 25 == 0:
            n = sum(1 for r in results if r["status"] == "MATCH")
            print(f"  {i+1}/{len(todo)} tried, {n} matched", flush=True)

    n = sum(1 for r in results if r["status"] == "MATCH")
    out = {"module": mod, "tried": len(todo), "matched": n, "results": results}
    json.dump(out, open(os.path.join(ROOT, f"build/auto/{mod}.json"), "w"), indent=1)
    json.dump(matched, open(os.path.join(ROOT, f"build/auto/{mod}.matched.json"), "w"), indent=1)
    print(f"{mod}: MATCHED {n}/{len(todo)}  -> build/auto/{mod}.matched.json")


if __name__ == "__main__":
    main()
