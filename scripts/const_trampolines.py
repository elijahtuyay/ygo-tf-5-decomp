#!/usr/bin/env python3
"""
Match two-instruction tail calls that pass one constant argument.

    scripts/const_trampolines.py rel_duel_eng            # report
    scripts/const_trampolines.py rel_duel_eng --apply    # insert and verify
    scripts/const_trampolines.py --all --apply

THE IDIOM. The whole function is a jump plus its delay slot:

    j     func_0000EB18
    addiu $a0, $zero, 0x1

which is `return func_0000EB18(1);`. Every other argument the callee takes comes
straight through from our own caller, untouched, in the register it arrived in.

WHY THE AUTOMATED PASS MISSES THESE. m2c decides a call's arguments from what it
can see at the call site, and here the call site sets exactly one register. It
emits `func_0000EB18()` with no arguments, so the delay slot comes out as a
`nop` and the function is exactly one instruction wrong. In a sample of 40
unmatched one-diff functions, **23 were this shape** — by far the largest single
cause of near-misses in the whole project.

The fix needs the callee's real arity, which scripts/gen_context.py measures
(read-before-write, propagated across tail calls). Given arity N and the
register index R that the delay slot loads:

    parameters  p0..p(N-1)      - so each lands in the right register
    call        callee(p0, .., CONST at R, .., p(N-1))

p<R> is declared and deliberately unused: it is the register we overwrite, and
declaring it is what pushes the later parameters into $a3/$t0 correctly. Without
it every argument after the constant would be passed one register too early.
"""
import argparse
import collections
import json
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "scripts"))
import merge_matches as M  # noqa: E402

INSN = re.compile(r"\s*/\* [0-9A-F]+ [0-9A-F]+ [0-9A-F]{8} \*/\s+(\S+)\s*(.*)")
ARG_REGS = ["$a0", "$a1", "$a2", "$a3", "$t0", "$t1", "$t2", "$t3"]


def prototypes(module):
    """{func: argc} from scripts/gen_context.py, generating it if needed."""
    path = os.path.join(ROOT, "build/ctx", module + ".h")
    if not os.path.exists(path):
        subprocess.run([sys.executable, os.path.join(ROOT, "scripts/gen_context.py"), module],
                       capture_output=True, cwd=ROOT)
    out = {}
    if os.path.exists(path):
        for line in open(path):
            m = re.match(r"(?:s32|void)\s+(\w+)\(([^)]*)\);", line)
            if m:
                args = m.group(2).strip()
                out[m.group(1)] = 0 if args in ("", "void") else args.count(",") + 1
    return out


def find(module, protos):
    """[(func, callee, reg index, constant)] for every constant trampoline."""
    cur, body = None, collections.defaultdict(list)
    for line in open(os.path.join(ROOT, "asm", module, "text.s"), errors="replace"):
        g = re.match(r"glabel (func_[0-9A-F]+)", line)
        if g:
            cur = g.group(1)
            continue
        m = INSN.match(line)
        if m and cur:
            body[cur].append((m.group(1), m.group(2).strip()))
    out = []
    for fn, ins in body.items():
        if len(ins) != 2 or ins[0][0] != "j" or ins[1][0] != "addiu":
            continue
        callee = ins[0][1].strip()
        m = re.match(r"(\$\w+),\s*\$zero,\s*(-?(?:0x)?[0-9A-Fa-f]+)$", ins[1][1])
        if not m or not callee.startswith("func_") or callee not in protos:
            continue
        if m.group(1) not in ARG_REGS:
            continue
        raw = m.group(2)
        const = int(raw, 16) if raw.startswith(("0x", "-0x")) else int(raw, 10)
        out.append((fn, callee, ARG_REGS.index(m.group(1)), const))
    return sorted(out)


def source(fn, callee, reg, const, argc):
    n = max(argc, reg + 1)
    params = ", ".join(f"int p{i}" for i in range(n)) or "void"
    args = ", ".join(f"0x{const:X}" if i == reg else f"p{i}" for i in range(argc))
    return (f"extern int {callee}();\n"
            f"int {fn}({params}) {{ return {callee}({args}); }}")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("modules", nargs="*")
    ap.add_argument("--all", action="store_true")
    ap.add_argument("--apply", action="store_true")
    a = ap.parse_args()

    mods = a.modules
    if a.all:
        base = json.load(open(os.path.join(ROOT, "config/progress-baseline.json")))
        mods = sorted(base["modules"])

    grand = 0
    for module in mods:
        src_path = os.path.join(ROOT, "src", module + ".c")
        if not os.path.exists(src_path):
            continue
        protos = prototypes(module)
        have = M.defined_in(open(src_path).read())
        cands = [c for c in find(module, protos) if c[0] not in have]
        if not cands:
            continue
        print(f"{module}: {len(cands)} constant trampolines")
        if not a.apply:
            continue
        added = 0
        for fn, callee, reg, const in cands:
            body = source(fn, callee, reg, const, protos.get(callee, reg + 1))
            before = open(src_path).read()
            open(src_path, "w").write(
                M.insert(before, {"func": fn, "words": 2,
                                  "shape": "const-trampoline", "src": body}, []))
            bad = M.verify(module, M.defined_in(before) | {fn})
            if bad is None or bad:
                open(src_path, "w").write(before)
            else:
                added += 1
                print(f"  + {fn} -> {callee}(.., 0x{const:X} at a{reg})", flush=True)
        print(f"{module}: added {added}")
        grand += added
    if a.apply:
        print(f"TOTAL added {grand}")


if __name__ == "__main__":
    main()
