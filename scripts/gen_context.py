#!/usr/bin/env python3
"""
Generate an m2c context file giving every callee its REAL argument count.

    scripts/gen_context.py rel_duel_eng      # -> build/ctx/rel_duel_eng.h
    scripts/gen_context.py --all

WHY THIS EXISTS. m2c decides how many arguments a call passes by looking at the
call site, and it only reliably sees $a0-$a3. Arguments five to eight travel in
$t0-$t3 under this EABI, and a tail-call trampoline sets some of them and then
`j`s to the callee without ever touching the rest, so nothing at the call site
reveals them. The result is a draft that calls the function with too few
arguments and therefore compiles to too FEW instructions:

    target:  lui $t0, %hi(func_000CD7DC) / addiu $a2, 0x1E / addiu $a3, 3
             j func_000C2DA8 / addiu $t0, $t0, %lo(...)
    m2c:     func_000C2DA8(0x1E, 3);          <- two of five arguments

That is the dominant SIZE MISMATCH in the automated pass: on a sample of 40
unmatched small rel_duel_eng functions, 21 were size mismatches and most were
SHORTER than the target.

Telling m2c the real prototype fixes it at the source. Arity is derived the same
way scripts/eboot_signatures.py derives it for the engine: a register READ
BEFORE IT IS WRITTEN is an incoming argument, propagated backwards across tail
calls to a fixed point, because a trampoline passes arguments through without
ever reading them.

Engine imports (ehsys_*) get their arity from nids/ehsys_signatures.csv, which
was measured from the engine's own disassembled bodies.
"""
import argparse
import csv
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ARG_REGS = ["$a0", "$a1", "$a2", "$a3", "$t0", "$t1", "$t2", "$t3"]

WRITES = re.compile(
    r"^(addiu|addu|addi|add|and|andi|or|ori|xor|xori|nor|sll|srl|sra|sllv|srlv|srav|"
    r"slt|slti|sltu|sltiu|sub|subu|mul|movn|movz|lui|li|move|"
    r"lb|lbu|lh|lhu|lw|lwl|lwr|lwc1|mfhi|mflo|mfc1|neg|negu|not|seb|seh|"
    r"max|min|ext|ins|clz|clo|rotr)$")
INSN = re.compile(r"\s*/\* [0-9A-F]+ ([0-9A-F]+) [0-9A-F]{8} \*/\s+(\S+)\s*(.*)")


def parse(module):
    """{func: (argc_local, written_args, call_args, returns)}

    `call_args` is (callee, arg registers written by this point) for EVERY call
    the body makes, engine imports included. A register the callee needs that we
    have not written by then is one we received from our own caller and are
    forwarding, so it is an incoming argument of ours too. Only tail calls used
    to be tracked; forwarding through an ordinary `jal` is the common case.
    """
    path = os.path.join(ROOT, "asm", module, "text.s")
    out, cur, written, argc, warg, calls, ret = {}, None, set(), 0, set(), [], 0
    for line in open(path, errors="replace"):
        g = re.match(r"glabel (func_[0-9A-F]+)", line)
        if g:
            cur, written, argc, warg, calls, ret = g.group(1), set(), 0, set(), [], 0
            continue
        if line.startswith("endlabel") and cur:
            out[cur] = (argc, warg, calls, ret)
            cur = None
            continue
        m = INSN.match(line)
        if not m or cur is None:
            continue
        mnem, ops = m.group(2), m.group(3).strip()
        toks = re.findall(r"\$\w+", ops)
        w = bool(WRITES.match(mnem)) and bool(toks)
        for r in toks[(1 if w else 0):]:
            if r in ARG_REGS and r not in written:
                argc = max(argc, ARG_REGS.index(r) + 1)
        if w:
            written.add(toks[0])
            if toks[0] in ARG_REGS:
                warg.add(toks[0])
            if toks[0] == "$v0":
                ret = 1
        if mnem in ("j", "jal"):
            callee = ops.strip().split(",")[0]
            if callee.startswith(("func_", "ehsys_")):
                calls.append((callee, frozenset(warg), mnem == "j"))
    return out


def solve(facts, seed=None, cap=None):
    """Propagate arity backwards over every call to a fixed point.

    `seed` supplies the arity of callees this module cannot see — the engine
    imports, measured from modehsys by scripts/eboot_signatures.py. Forwarding
    an argument into an engine call is invisible without it.

    Monotone (argc only grows), so the fixed point is unique and call cycles and
    recursion are safe.

    `cap` is what keeps this honest, and it is not optional. Propagating across
    every call SATURATES without it: a linear read-before-write scan cannot see
    that a register was set inside a branch, so any callee wanting eight
    arguments makes its caller appear to want eight too, and that cascades. Run
    uncapped on rel_duel_eng, 5,401 of 7,487 functions came out at eight
    arguments, and the fixed sample got worse, not better (58 -> 60 size
    mismatches).

    So the two estimators are combined instead of trusting either:

      * the body read-before-write count is a LOWER bound and is sound — those
        registers are demonstrably read before they are written;
      * the largest argument count any CALL SITE sets up (scripts/infer_arity.py)
        is an upper bound — no caller passes what it never loads.

    The propagated value is clamped between them. A function whose callers never
    pass more than three arguments does not take eight, whatever a chain of
    forwarding inference concluded.
    """
    argc = {k: v[0] for k, v in facts.items()}
    argc.update({k: v for k, v in (seed or {}).items() if k not in argc})
    for _ in range(50):
        changed = False
        for fn, (_, _, calls, _) in facts.items():
            for callee, written_here, _tail in calls:
                if callee not in argc:
                    continue
                for i in range(argc[callee]):
                    if ARG_REGS[i] not in written_here and argc[fn] < i + 1:
                        argc[fn] = i + 1
                        changed = True
        if not changed:
            break
    # Where there IS call-site evidence, clamp to it. Where there is none the
    # function is never called from inside this module, so nothing bounds the
    # propagation and it saturates; fall back to the conservative tail-call-only
    # result for those. Capping only the functions with evidence still left
    # 3,992 of 7,487 at eight arguments in rel_duel_eng.
    tail_only = _tail_only(facts, seed)
    for fn, (local, _, _, _) in facts.items():
        if fn in (cap or {}):
            argc[fn] = max(local, min(argc[fn], cap[fn]))
        else:
            argc[fn] = max(local, tail_only[fn])
    return argc


def _tail_only(facts, seed=None):
    """The pre-existing conservative estimate: propagate over tail calls only.

    A `j callee` really does leave through the callee, so every argument the
    callee needs and we did not set must have come from our caller. That
    inference is safe without any call-site bound, which is why it is the
    fallback wherever a bound is missing.
    """
    argc = {k: v[0] for k, v in facts.items()}
    argc.update({k: v for k, v in (seed or {}).items() if k not in argc})
    for _ in range(50):
        changed = False
        for fn, (_, _, calls, _) in facts.items():
            for callee, written_here, tail in calls:
                if callee not in argc or not tail:
                    continue
                for i in range(argc[callee]):
                    if ARG_REGS[i] not in written_here and argc[fn] < i + 1:
                        argc[fn] = i + 1
                        changed = True
        if not changed:
            break
    return argc


DIST = re.compile(r"(\d+) args x(\d+)")


def dominant(distribution, max_args, floor=0.10):
    """The largest argument count that a real share of call sites agrees on.

    NOT the maximum. infer_arity records, for example,
    `4 args x218; 5 args x9; 3 args x5` for func_00040550. The maximum is 5 and
    it is wrong: the target passes four and a fifth prototype argument costs an
    extra instruction at every call site. Those nine outliers are measurement
    noise — a register set near the call for an unrelated reason looks exactly
    like an argument to a call-site scan.

    Taking the largest count holding at least `floor` of the call sites keeps
    the genuine 8-argument functions (where the high count IS the bulk) and
    drops the noise tail.
    """
    counts = [(int(n), int(c)) for n, c in DIST.findall(distribution or "")]
    total = sum(c for _, c in counts)
    if not total:
        return max_args
    keep = [n for n, c in counts if c / total >= floor]
    return max(keep) if keep else max_args


def call_site_cap(module):
    """{func: argument count the call sites agree on}, from infer_arity."""
    out = {}
    p = os.path.join(ROOT, "nids/func_arity", module + ".csv")
    if os.path.exists(p):
        for r in csv.DictReader(open(p)):
            try:
                out[r["name"]] = dominant(r.get("distribution"), int(r["max_args"]))
            except ValueError:
                pass
    return out


def engine_sigs():
    out = {}
    p = os.path.join(ROOT, "nids/ehsys_signatures.csv")
    if os.path.exists(p):
        for r in csv.DictReader(open(p)):
            out["ehsys_" + r["nid"][2:]] = (int(r["argc"]), int(r["returns"]))
    return out


def emit(module):
    facts = parse(module)
    sigs = engine_sigs()
    argc = solve(facts, {k: v[0] for k, v in sigs.items()}, call_site_cap(module))
    lines = ["/* generated by scripts/gen_context.py - do not edit */",
             "typedef signed char s8;", "typedef unsigned char u8;",
             "typedef short s16;", "typedef unsigned short u16;",
             "typedef int s32;", "typedef unsigned int u32;",
             "typedef float f32;", "typedef double f64;"]
    for fn in sorted(facts):
        n = argc[fn]
        ret = "s32" if facts[fn][3] else "void"
        args = ", ".join(["s32"] * n) or "void"
        lines.append(f"{ret} {fn}({args});")
    for name, (n, ret) in sorted(sigs.items()):
        args = ", ".join(["s32"] * n) or "void"
        lines.append(f"{'s32' if ret else 'void'} {name}({args});")
    dst = os.path.join(ROOT, "build/ctx", module + ".h")
    os.makedirs(os.path.dirname(dst), exist_ok=True)
    open(dst, "w").write("\n".join(lines) + "\n")
    return len(facts), dst


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("modules", nargs="*")
    ap.add_argument("--all", action="store_true")
    a = ap.parse_args()
    mods = a.modules
    if a.all:
        mods = sorted(d for d in os.listdir(os.path.join(ROOT, "asm"))
                      if os.path.exists(os.path.join(ROOT, "asm", d, "text.s")))
    for m in mods:
        n, dst = emit(m)
        print(f"{m}: {n} prototypes -> {dst}")


if __name__ == "__main__":
    main()
