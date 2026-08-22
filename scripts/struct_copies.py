#!/usr/bin/env python3
"""
Match MWCC's inlined struct-copy functions, which it emits by the dozen.

    scripts/struct_copies.py rel_duel_eng          # report what it finds
    scripts/struct_copies.py rel_duel_eng --apply  # insert and verify each one

THE IDIOM. Assigning a struct too big to move in registers (`*dst = *src`) makes
MWCC emit a counted loop that copies two elements per iteration and returns dst:

    addiu $a2, $zero, 0xB      <- iteration count
    addu  $a3, $a0, $zero      <- dst cursor
  .L:
    lh    $v1, 0x0($a1)        <- two elements per iteration
    lh    $v0, 0x2($a1)
    addiu $a2, $a2, -0x1
    sh    $v1, 0x0($a3)
    sh    $v0, 0x2($a3)
    addiu $a1, $a1, 0x4
    bgtz  $a2, .L
    addiu $a3, $a3, 0x4
    jr    $ra
    addu  $v0, $a0, $zero      <- returns dst

It is always exactly 12 instructions. The element type follows from the
load/store opcode (`lh` -> short, `lw` -> int, `lb` -> char) and the element
count is twice the iteration count, so the entire function is recoverable from
the disassembly with no decompilation at all:

    typedef struct { short x[22]; } S;
    S *f(S *dst, S *src) { *dst = *src; return dst; }

All 32 unmatched instances in rel_duel_eng matched on the first attempt. Re-run
this whenever a module is split: the idiom is compiler-generated, so it recurs
wherever a large struct is assigned.
"""
import argparse
import collections
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "scripts"))
import merge_matches as M  # noqa: E402

INSN = re.compile(r"\s*/\* [0-9A-F]+ [0-9A-F]+ [0-9A-F]{8} \*/\s+(\S+)\s*(.*)")
ELEM = {"lh": "short", "lhu": "unsigned short", "lw": "int",
        "lb": "char", "lbu": "unsigned char"}


def find(module):
    """[(func, element type, element count)] for every struct copy in a module."""
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
        if len(ins) != 12:
            continue
        ops = [o for o, _ in ins]
        if not (ops[0] == "addiu" and ops[1] == "addu"
                and ops[8] == "bgtz" and ops[10] == "jr"):
            continue
        if ops[2] != ops[3] or ops[5] != ops[6] or ops[2] not in ELEM:
            continue
        n = re.search(r"0x([0-9A-Fa-f]+)", ins[0][1])
        if n:
            out.append((fn, ELEM[ops[2]], int(n.group(1), 16) * 2))
    return sorted(out)


def source(fn, ctype, count):
    return (f"typedef struct {{ {ctype} x[{count}]; }} S_{fn};\n"
            f"S_{fn} *{fn}(S_{fn} *dst, S_{fn} *src) {{ *dst = *src; return dst; }}")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("module")
    ap.add_argument("--apply", action="store_true")
    a = ap.parse_args()

    src_path = os.path.join(ROOT, "src", a.module + ".c")
    have = M.defined_in(open(src_path).read()) if os.path.exists(src_path) else set()
    cands = [c for c in find(a.module) if c[0] not in have]
    print(f"{a.module}: {len(cands)} unmatched struct-copy functions")
    if not a.apply:
        for fn, t, n in cands[:10]:
            print(f"  {fn}  {t}[{n}]")
        return

    added = 0
    for fn, t, n in cands:
        before = open(src_path).read()
        entry = {"func": fn, "words": 12, "shape": "struct-copy",
                 "src": source(fn, t, n)}
        open(src_path, "w").write(M.insert(before, entry, []))
        bad = M.verify(a.module, M.defined_in(before) | {fn})
        if bad is None or bad:
            open(src_path, "w").write(before)
        else:
            added += 1
            print(f"  + {fn}  {t}[{n}]", flush=True)
    print(f"added {added}")


if __name__ == "__main__":
    main()
