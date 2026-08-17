#!/usr/bin/env python3
"""
Draft C for leaf "trampoline" functions: one call, no branches, a handful of
struct-field reads feeding the call, a small comparison on the result.

    scripts/leaf_trampolines.py rel_duel_eng
        -> build/auto/rel_duel_eng.trampolines.json

Feed the output to scripts/merge_matches.py, which already knows how to add
entries in this {"func","words","shape","src"} format, insert them in address
order, and roll back anything that fails to verify:

    scripts/merge_matches.py rel_duel_eng

WHY THIS SHAPE EXISTS
----------------------
A huge share of a module's unmatched functions are not hand-written logic —
they are the compiler's own glue. A handful of shared engine dispatchers
(func_001621C4 and friends in rel_duel_eng, called from 80-200+ sites each)
take a long, awkward argument list, so the source has hundreds of thin
wrappers that each read 1-3 fields off a struct pointer, add a constant or a
function-pointer symbol, and forward the lot. Compiled at -O4 these become a
single straight-line block: `addiu $sp` / `sw $ra` (prologue), a handful of
`lhu`/`lbu`/`lw` field reads and register copies, exactly one `jal`, then a
comparison on `$v0` and the epilogue. No branches, no loops, no VFPU. That
shape is mechanical to reconstruct once you trust two things: which incoming
register produced each outgoing argument, and which C idiom the compiler
used to turn the call's raw return value into a boolean.

THE SYMBOLIC EVALUATION
------------------------
`classify()` walks the instructions before the `jal` (plus its delay slot,
which is still argument setup) and keeps a symbol table of what every
register currently holds, in terms even m2c would not recover automatically
because the source register (usually $a0) gets overwritten before the callee
is reached:

  ('param', name)        untouched since function entry — this is the
                          function's OWN incoming parameter of that name.
                          Every argument register starts here; if nothing
                          ever writes it, the call forwards the caller's own
                          value straight through (see docs/11, lever 2).
  ('imm', text)           addiu $reg, $zero, N  (or lui+ori for values that
                          need both halves) — a literal passed to the call.
  ('field', param, off, width)
                          lhu/lh/lbu/lb/lw $reg, OFF($src) where $src is
                          itself a ('param', ...) — a struct field read off
                          one of the function's own pointer arguments.
  ('addr', symbol)        lui %hi(SYM) + addiu %lo(SYM) — the address of a
                          global or function is being passed (a callback
                          pointer, or an output slot the callee writes back).

`addu $dst, $src, $zero` (a bare register copy) just propagates whatever
`$src` currently resolves to, so a value can pass through $v0 as scratch
before landing in its real argument register — the classifier follows that
chain rather than only looking at the instruction immediately before `jal`.
Any register whose source cannot be reduced to one of the four kinds above
(a computed struct index, a second call, a loop) fails classification: this
tool only ever proposes code for the mechanical case, never a guess.

THE BOOLEAN-IDIOM CLASSIFICATION
----------------------------------
MWCC does not have one canonical way to turn an `int` into 0/1, and it is
not free to pick whichever produces the same *value* — it matches byte for
byte only when the C written matches the exact instruction sequence chosen
for that comparison operator. The mapping below is hard-won from manually
matching hundreds of these across a single module this session:

  sltu $v0,$zero,$v0                        (CALL) != 0
  sltu ... ; xori $v0,$v0,1                 (CALL) == 0        -- NOT "!x"
  slt  $v0,$zero,$v0                        (CALL) > 0
  slt  ... ; xori 1                         !((CALL) > 0)
  slt  $v0,$v0,$zero                        (CALL) < 0
  slt  ... ; xori 1                         !((CALL) < 0)
  slti $v0,$v0,K                            (CALL) < K
  slti ... ; xori 1                         !((CALL) < K)      -- NOT ">= K"
  sltiu $v0,$v0,K                           (unsigned int)(CALL) < K
  xori $v0,$v0,K ; sltiu $v0,$v0,1          (CALL) == K
  andi $v0,$v0,K                            (CALL) & K

Writing the "obviously equivalent" C (`x == 0` where the target used `!x`,
or `x >= K` where the target used `!(x < K)`) silently costs one word almost
every time: the compiler reaches for a different instruction pair for each
surface form even when the truth table is identical. Match the shape, not
just the semantics.

WHAT THIS DOES NOT ATTEMPT
----------------------------
- Anything with a branch in the body (conditional argument setup, loops):
  those need a human to read the control flow.
- Values assembled from more than one register hop, or from a global load
  (`lui %hi(D_X); lw ..., %lo(D_X)`) rather than a struct field or param.
- Return shapes outside the table above (multi-instruction sequences that
  write back through a saved pointer, `mult`/`mflo` index arithmetic, and
  so on) — these get counted and reported, not guessed at.
- Picking how many of a callee's registers are "real" arguments: the
  per-module nids/func_arity/<module>.csv (and nids/ehsys_arity.csv for
  engine imports) written by scripts/infer_arity.py is trusted as the
  ceiling, and any argument registers past what THIS call site actually set
  are trimmed rather than invented.
"""
import csv
import json
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

ARGREGS = ["$a0", "$a1", "$a2", "$a3", "$t0", "$t1", "$t2", "$t3"]
ARGNAMES = ["a0", "a1", "a2", "a3", "t0", "t1", "t2", "t3"]

BRANCHY = {"beq", "bne", "blez", "bgtz", "bltz", "bgez", "b",
           "beql", "bnel", "bnez", "beqz", "bltzl", "blezl", "bgezl", "bgtzl"}

WIDTHS = {"lhu": "unsigned short", "lh": "short",
          "lbu": "unsigned char", "lb": "signed char", "lw": "int"}


class Fail(Exception):
    """A candidate doesn't fit the shape; not an error, just 'skip it'."""


def load_arity(module):
    """{callee_name: max_args}, engine imports plus this module's own funcs."""
    arity = {}
    for rel in ("nids/ehsys_arity.csv", f"nids/func_arity/{module}.csv"):
        p = os.path.join(ROOT, rel)
        if not os.path.exists(p):
            continue
        with open(p, newline="") as fh:
            for row in csv.DictReader(fh):
                arity[row["name"]] = int(row["max_args"])
    return arity


def parse_blocks(module):
    """{name: (size_bytes, [(mnemonic, operand_str), ...], is_handwritten)}."""
    path = os.path.join(ROOT, "asm", module, "text.s")
    text = open(path).read()
    out = {}
    for b in re.split(r"\n(?=nonmatching func_)", text):
        m = re.match(r"nonmatching (func_[0-9A-F]+), (0x[0-9A-Fa-f]+)", b)
        if not m:
            continue
        name, size = m.group(1), int(m.group(2), 16)
        handwritten = "Handwritten function" in b
        instrs = []
        for line in b.splitlines():
            parts = line.split("*/")
            if len(parts) < 2:
                continue
            toks = parts[1].strip().split(None, 1)
            if not toks:
                continue
            instrs.append((toks[0], toks[1] if len(toks) > 1 else ""))
        out[name] = (size, instrs, handwritten)
    return out


def split_ops(ops):
    return [o.strip() for o in ops.split(",")]


def trace_registers(pre, delay):
    """Symbol table after replaying every setup instruction (see module doc)."""
    regs = {"$" + a: ("param", a) for a in ARGNAMES}

    def step(mn, ops):
        parts = split_ops(ops)
        if not parts or not parts[0].startswith("$"):
            return
        dst = parts[0]
        if mn == "addu" and len(parts) == 3 and parts[2] == "$zero":
            regs[dst] = regs.get(parts[1], ("unknown",))
        elif mn == "addu" and len(parts) == 3 and parts[1] == "$zero":
            regs[dst] = regs.get(parts[2], ("unknown",))
        elif mn == "addiu" and len(parts) == 3 and parts[1] == "$zero":
            regs[dst] = ("imm", parts[2])
        elif mn in ("lhu", "lh", "lbu", "lb", "lw") and len(parts) == 2:
            m2 = re.match(r"(-?0x[0-9A-Fa-f]+|-?\d+)\((\$\w+)\)", parts[1])
            src = regs.get(m2.group(2), ("unknown",)) if m2 else ("unknown",)
            if m2 and src[0] == "param":
                regs[dst] = ("field", src[1], m2.group(1), WIDTHS[mn])
            else:
                regs[dst] = ("unknown",)
        elif mn == "lui" and len(parts) == 2:
            hm = re.search(r"%hi\((\w+)\)", parts[1])
            if hm:
                regs[dst] = ("addr_hi", hm.group(1))
            else:
                # a 32-bit immediate split across lui+ori (e.g. 0x10000)
                hm2 = re.match(r"\((0x[0-9A-Fa-f]+)\s*>>\s*16\)", parts[1])
                regs[dst] = ("imm_hi", int(hm2.group(1), 16)) if hm2 else ("unknown",)
        elif (mn == "addiu" and len(parts) == 3
              and regs.get(parts[1], (None,))[0] == "addr_hi"):
            lm = re.search(r"%lo\((\w+)\)", parts[2])
            hi_sym = regs[parts[1]][1]
            regs[dst] = ("addr", hi_sym) if lm and lm.group(1) == hi_sym else ("unknown",)
        elif (mn == "ori" and len(parts) == 3
              and regs.get(parts[1], (None,))[0] == "imm_hi"):
            om = re.search(r"\((0x[0-9A-Fa-f]+)", parts[2])
            regs[dst] = (("imm", hex(regs[parts[1]][1] | int(om.group(1), 16)))
                         if om else ("unknown",))
        else:
            regs[dst] = ("unknown",)

    for mn, ops in pre:
        step(mn, ops)
    step(*delay)
    return regs


def classify_return(tail):
    """Match `tail` (the instructions between the call and the epilogue,
    with $ra/saved-register restores already stripped) against one of the
    boolean idioms in the module docstring, or a bare constant/passthrough.
    Returns (mode, expr) where expr uses the literal string "CALL" as a
    placeholder for the call expression, substituted in by the caller."""
    if not tail:
        return "passthrough", "CALL"

    def opstr(t):
        return t[0] + t[1].replace(" ", "")

    seq = [opstr(t) for t in tail]

    def match(pats):
        if len(seq) != len(pats):
            return None
        groups = []
        for s, pat in zip(seq, pats):
            m = re.match(pat, s)
            if not m:
                return None
            groups.append(m.groups())
        return groups

    g = match([r"addiu\$v0,\$zero,(.+)"])
    if g:
        return "constant", g[0][0]
    if match([r"addu\$v0,\$zero,\$zero"]):
        return "constant", "0"

    IDIOMS = [
        ([r"sltu\$v0,\$zero,\$v0"], "(CALL) != 0"),
        ([r"sltu\$v0,\$zero,\$v0", r"xori\$v0,\$v0,(.+)"], "(CALL) == 0"),
        ([r"slt\$v0,\$zero,\$v0"], "(CALL) > 0"),
        ([r"slt\$v0,\$zero,\$v0", r"xori\$v0,\$v0,(.+)"], "!((CALL) > 0)"),
        ([r"slt\$v0,\$v0,\$zero"], "(CALL) < 0"),
        ([r"slt\$v0,\$v0,\$zero", r"xori\$v0,\$v0,(.+)"], "!((CALL) < 0)"),
        ([r"slti\$v0,\$v0,(.+)"], "(CALL) < {0}"),
        ([r"slti\$v0,\$v0,(.+)", r"xori\$v0,\$v0,(.+)"], "!((CALL) < {0})"),
        ([r"sltiu\$v0,\$v0,(.+)"], "(unsigned int)(CALL) < {0}"),
        ([r"xori\$v0,\$v0,(.+)", r"sltiu\$v0,\$v0,(.+)"], "(CALL) == {0}"),
        ([r"andi\$v0,\$v0,(.+)"], "(CALL) & {0}"),
    ]
    for pats, template in IDIOMS:
        g = match(pats)
        if not g:
            continue
        # every idiom's trailing xori/sltiu, if present, must be comparing to 1
        if len(g) > 1 and g[-1][0] not in ("0x1", "1"):
            continue
        return "expr", template.format(g[0][0] if g[0] else None)

    raise Fail(f"unhandled return shape: {tail}")


def classify(name, size, instrs, arity):
    mnems = [i[0] for i in instrs]
    if mnems.count("jal") != 1:
        raise Fail("not exactly one jal")
    jal_idx = mnems.index("jal")
    callee = instrs[jal_idx][1].strip()

    if any(mn.startswith("v") or mn in ("mfv", "mtv") or mn.startswith(("lv.", "sv."))
           for mn in mnems):
        raise Fail("vfpu")
    if any(mn in BRANCHY for mn in mnems):
        raise Fail("branchy")
    if mnems[0] != "addiu" or mnems[1] != "sw":
        raise Fail("not a leaf prologue")
    if mnems[-2] != "jr" or mnems[-1] != "addiu":
        raise Fail("not a leaf epilogue")

    pre, delay = instrs[:jal_idx], instrs[jal_idx + 1]
    post = instrs[jal_idx + 2:-2]
    regs = trace_registers(pre, delay)

    n = arity.get(callee)
    if n is None or n > 8:
        raise Fail(f"unknown/oversized arity for {callee}")

    all_args = [regs.get(r, ("unknown",)) for r in ARGREGS[:n]]
    # A trailing $t0.. slot nothing ever wrote is not a real argument at THIS
    # call site (infer_arity's max is a ceiling across every site, not a
    # promise this one uses them all); drop it rather than emit a param that
    # was never live. An 'unknown' before the last set arg means a register
    # got its value some way we don't model — bail rather than guess.
    while all_args and all_args[-1][0] == "unknown":
        all_args.pop()
    if any(v[0] == "unknown" for v in all_args):
        raise Fail("unresolved argument register")

    # $ra and any saved callee registers get restored before the epilogue;
    # they're bookkeeping, not part of what the function returns.
    tail = [(mn, ops) for mn, ops in post
            if not (mn == "lw" and re.search(r"\$(ra|s\d),", ops))]
    ret_mode, ret_expr = classify_return(tail)

    return dict(name=name, size=size, callee=callee, args=all_args,
                ret_mode=ret_mode, ret_expr=ret_expr)


def render_arg(a):
    kind = a[0]
    if kind == "param":
        return a[1]
    if kind == "imm":
        return a[1]
    if kind == "field":
        _, param, off, width = a
        return f"(*({width} *)((char *)({param}) + {off}))"
    if kind == "addr":
        return f"((int)&{a[1]})"
    raise Fail(f"cannot render argument {a}")


def render_source(r):
    params = ARGNAMES[:len(r["args"])]
    call = f"{r['callee']}(" + ", ".join(render_arg(a) for a in r["args"]) + ")"
    # address-of arguments reference a symbol besides the callee itself
    # (a callback, or another global) that also needs its own declaration
    extra_syms = sorted({a[1] for a in r["args"] if a[0] == "addr"})
    decls = "".join(f"    extern int {s}();\n" for s in extra_syms)

    if r["ret_mode"] == "constant":
        body = f"    {call};\n    return {r['ret_expr']};"
    else:
        body = f"    return {r['ret_expr'].replace('CALL', call)};"

    return (f"int {r['name']}(" + ", ".join(f"int {p}" for p in params) + ") {\n"
            f"    extern int {r['callee']}();\n"
            f"{decls}"
            f"    extern int {r['name']}();\n"
            f"{body}\n"
            "}")


def main():
    if len(sys.argv) != 2:
        print(__doc__)
        sys.exit(1)
    module = sys.argv[1]

    sys.path.insert(0, os.path.join(ROOT, "scripts"))
    import merge_matches as M

    src_path = os.path.join(ROOT, "src", module + ".c")
    have = M.defined_in(open(src_path).read()) if os.path.exists(src_path) else set()

    arity = load_arity(module)
    blocks = parse_blocks(module)

    entries, fails = [], {}
    for name, (size, instrs, handwritten) in blocks.items():
        if name in have or handwritten:
            continue
        try:
            r = classify(name, size, instrs, arity)
        except Fail as e:
            fails[str(e)] = fails.get(str(e), 0) + 1
            continue
        entries.append({"func": name, "words": size // 4, "shape": "trampoline",
                         "src": render_source(r)})

    out_dir = os.path.join(ROOT, "build/auto")
    os.makedirs(out_dir, exist_ok=True)
    out_path = os.path.join(out_dir, module + ".trampolines.json")
    json.dump(entries, open(out_path, "w"), indent=1)

    print(f"{module}: {len(entries)} candidate(s) -> {out_path}")
    if fails:
        print("not classified:")
        for reason, count in sorted(fails.items(), key=lambda kv: -kv[1])[:12]:
            print(f"  {count:>5}  {reason}")
    print(f"\nnext: scripts/merge_matches.py {module}")


if __name__ == "__main__":
    main()
