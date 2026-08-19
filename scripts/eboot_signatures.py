#!/usr/bin/env python3
"""
Recover signatures and behaviour hints for the 1729 functions modehsys exports.

    scripts/eboot_signatures.py                 # write nids/ehsys_signatures.csv
    scripts/eboot_signatures.py --top 40        # also print the most-called ones

WHY THIS IS THE HIGHEST-LEVERAGE ANALYSIS IN THE PROJECT. Every one of the 28
rel_*.prx modules imports libehsys_rel from modehsys (the decrypted EBOOT), and
about 1000 of its exports are actually called somewhere. Those calls are a major
source of SIZE MISMATCH when matching module functions, because getting a
callee's arity wrong changes the caller's whole argument setup.

scripts/infer_arity.py guesses arity from CALL SITES, which is register-only and
therefore UNDERCOUNTS any function taking more than 8 arguments (args 9+ arrive
on the stack and are invisible to that method). This script reads the actual
function BODIES in the engine instead, which is far stronger evidence: a
register that is READ before it is WRITTEN is an incoming argument.

Everything here is compiler-independent — it reads the shipped engine, not
anything we compile — so it is valid work regardless of the open question in
docs/17-compiler-identification.md.

Output columns (nids/ehsys_signatures.csv):
    nid          0xXXXXXXXX, the export NID (same in all 28 modules)
    vram         address inside modehsys
    func         func_XXXXXXXX as splat named it
    words        function length in instructions
    call_sites   how many times the 28 modules call it
    argc         number of incoming integer args proven by register reads
    stack_args   1 if the body reads incoming stack args (arity > 8)
    returns      1 if $v0 is written in the body
    leaf         1 if it makes no calls at all
    sdk_calls    ; separated SDK functions it calls DIRECTLY
    reaches      ; separated SDK libraries it reaches TRANSITIVELY, propagated
                 up the call graph — the usable behaviour hint, since only ~100
                 exports call an SDK import directly but ~360 reach one
    sdk_reexport non-empty when this export is not engine code at all but a
                 re-exported PSP SDK import, as "Lib:name(paramkinds)"

A NOTE ON THE RE-EXPORTS, which is the most immediately useful thing here: the
engine re-exports 139 SDK imports under their ORIGINAL SDK NID. ehsys_109F50BC
is 0x109F50BC is sceIoOpen. So any module calling one of these NIDs is calling
the PSP SDK function directly through the engine, and the module source should
name it sceIoOpen rather than ehsys_109F50BC — no address mapping required.
"""
import argparse
import csv
import glob
import os
import re
import struct
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

ELF = os.path.join(ROOT, "build/EBOOT.elf")
TEXT = os.path.join(ROOT, "asm/modehsys/text.s")
V2F = 0x54                      # vram -> file offset for this module
ENTRY_TABLE = 0x6EE78           # libehsys_rel entry table (from .lib.ent)
N_FUNCS, N_VARS = 1729, 2

ARG_REGS = ["$a0", "$a1", "$a2", "$a3", "$t0", "$t1", "$t2", "$t3"]


def u32(d, vram):
    return struct.unpack_from("<I", d, vram + V2F)[0]


def cstr(d, vram):
    off = vram + V2F
    return d[off:d.index(b"\0", off)].decode("ascii", "replace")


def import_stubs(d):
    """{stub_vram: 'LibName:0xNID'} for all 339 SDK imports."""
    mi = 0x6EBC0
    stub_top, stub_end = struct.unpack_from("<2I", d, mi + 0x2C + V2F)
    out, p = {}, stub_top
    while p < stub_end:
        npt, _ver, _fl, slen, _vc, fcnt = struct.unpack_from("<IHHBBH", d, p + V2F)
        nid_tbl, stub_tbl = struct.unpack_from("<2I", d, p + 0x0C + V2F)
        lib = cstr(d, npt) if npt else "?"
        for i in range(fcnt):
            out[stub_tbl + 8 * i] = f"{lib}:0x{u32(d, nid_tbl + 4 * i):08X}"
        p += slen * 4
    return out


NID_DB_ENTRY = re.compile(
    r'\{\s*(0[xX][0-9A-Fa-f]{8})\s*,[^,]*,\s*"([A-Za-z_]\w*)"\s*,'
    r"\s*'(.)'\s*,\s*\"([^\"]*)\"")


def sdk_names():
    """NID -> (name, ret, params) for PSP SDK functions.

    Two sources. nids/sdk.csv holds the handful already hash-verified by
    scripts/resolve_nids.py. tools/nid_db/*.cpp are PPSSPP's HLE tables, which
    carry ~450 more entries INCLUDING a type signature: the trailing
    {..., 'i', "ix"} fields are the return kind and the parameter kinds, so an
    engine function that re-exports one of these gets a real prototype rather
    than just a name.
    """
    out = {}
    # 1. pspdev/psplibdoc — the community's Sony NID database, ~6300 entries.
    #    Names only, no signatures, but it resolves 93% of this engine's 339
    #    SDK imports against PPSSPP's 12%. Clone with scripts/setup_tools.sh.
    for path in glob.glob(os.path.join(ROOT, "tools/psplibdoc/PSPLibDoc/*/*.csv")):
        for r in csv.reader(open(path, errors="replace")):
            if len(r) >= 4 and r[1].strip() in ("fun", "var"):
                try:
                    out.setdefault(int(r[2].strip(), 16), (r[3].strip(), "", ""))
                except ValueError:
                    pass
    # 2. PPSSPP's HLE tables add a TYPE SIGNATURE for the subset they cover,
    #    so they win over a bare psplibdoc name.
    for path in sorted(glob.glob(os.path.join(ROOT, "tools/nid_db/*.cpp"))):
        for m in NID_DB_ENTRY.finditer(open(path, errors="replace").read()):
            out[int(m.group(1), 16)] = (m.group(2), m.group(3), m.group(4))
    p = os.path.join(ROOT, "nids/sdk.csv")
    if os.path.exists(p):
        for r in csv.DictReader(open(p)):
            try:  # locally verified names win over the imported database
                nid = int(r["nid"], 16)
                out[nid] = (r["name"],) + out.get(nid, ("", "", ""))[1:]
            except Exception:
                pass
    return out


def propagate_behaviour(facts):
    """Spread SDK-library usage up the call graph to a fixed point.

    Only 63 of the engine's exports call an SDK import DIRECTLY; the rest sit
    one or more hops above one that does. Knowing that a function eventually
    reaches IoFileMgrForUser or sceSasCore is most of what you need to name it,
    so the label is propagated caller-wards until nothing changes. Libraries,
    not individual functions, are the useful granularity at distance: "this
    eventually touches file I/O" is informative, "this eventually reaches
    sceIoLseek" is noise five hops up.
    """
    changed, rounds = True, 0
    while changed and rounds < 100:
        changed, rounds = False, rounds + 1
        for f in facts.values():
            for c in f["callees"]:
                t = facts.get(c)
                if t and not t["libs"] <= f["libs"]:
                    f["libs"] |= t["libs"]
                    changed = True
    return rounds


def parse_functions():
    """[(func, vram, [(mnemonic, operands), ...])] in address order."""
    funcs, cur, body, vram = [], None, [], None
    for line in open(TEXT, errors="replace"):
        g = re.match(r"glabel (func_[0-9A-F]+)", line)
        if g:
            cur, body, vram = g.group(1), [], None
            continue
        if line.startswith("endlabel") and cur:
            funcs.append((cur, vram, body))
            cur = None
            continue
        m = re.match(r"\s*/\* [0-9A-F]+ ([0-9A-F]+) [0-9A-F]{8} \*/\s+(\S+)\s*(.*)", line)
        if m and cur is not None:
            if vram is None:
                vram = int(m.group(1), 16)
            body.append((m.group(2), m.group(3).strip()))
    return funcs


WRITES_FIRST_OPERAND = re.compile(
    r"^(addiu|addu|addi|add|and|andi|or|ori|xor|xori|nor|sll|srl|sra|sllv|srlv|srav|"
    r"slt|slti|sltu|sltiu|sub|subu|mul|movn|movz|lui|li|move|"
    r"lb|lbu|lh|lhu|lw|lwl|lwr|lwc1|mfhi|mflo|mfc1|neg|negu|not|seb|seh|"
    r"max|min|ext|ins|clz|clo|rotr)$")


def analyse(body, stubs, names):
    """Local facts for one function.

    Returns (argc, written_args, tail_target, returns, leaf, sdk_calls).

    `argc` here is only what the BODY proves by reading a register before
    writing it. That undercounts every function that FORWARDS an argument: a
    function that calls `func_X` after setting only $a2 still receives $a0/$a1
    from its own caller and passes them straight through without ever reading
    them. Those registers are arguments but are invisible to a read-before-write
    scan, so main() propagates arity backwards across calls to a fixed point.

    This applies to `jal` exactly as it does to `j`. Only the tail-call form used
    to be propagated, and measuring against scripts/infer_arity.py showed what
    that cost: the body-derived count came out BELOW the call-site-derived one
    for 473 exports covering 21,627 call sites. Forwarding through an ordinary
    call is the common case, not the tail-call special case.

    `call_args` therefore holds (target, args written so far) for every call. The
    snapshot has to be taken AT the call: a register written later in the body
    says nothing about whether this call received it from our caller.
    """
    written, argc, returns, calls, sdk = set(), 0, 0, 0, []
    written_args, tail_target = set(), None
    call_args = []
    callees, libs = [], set()
    for mnem, ops in body:
        toks = re.findall(r"\$\w+", ops)
        writes = bool(WRITES_FIRST_OPERAND.match(mnem)) and bool(toks)
        # an argument register READ before being WRITTEN is an incoming argument
        for r in toks[(1 if writes else 0):]:
            if r in ARG_REGS and r not in written:
                argc = max(argc, ARG_REGS.index(r) + 1)
        if writes:
            written.add(toks[0])
            if toks[0] in ARG_REGS:
                written_args.add(toks[0])
            if toks[0] == "$v0":
                returns = 1
        if mnem in ("jal", "j") and ops.startswith("func_"):
            calls += 1
            try:
                v = int(ops.strip().split("_")[1], 16)
            except Exception:
                v = None
            # Any call's arguments are supplied partly by us and partly by our
            # caller; whichever this call needs and we have not written by now,
            # we must have received. `j func_X` additionally leaves via the
            # callee, which is why tail_target is still tracked separately.
            if v is not None:
                call_args.append((v, frozenset(written_args)))
                if mnem == "j":
                    tail_target = v
            if v in stubs:
                lib, nid = stubs[v].split(":")
                libs.add(lib)
                sdk.append(names.get(int(nid, 16), (f"{lib}_{nid[2:]}",))[0])
            elif v is not None:
                callees.append(v)
        elif mnem == "jalr":
            calls += 1
    return (argc, written_args, tail_target, returns,
            (1 if calls == 0 else 0), sdk, callees, libs, call_args)


def call_arg_cap(export):
    """{vram: largest argument count any of the 28 modules sets up}.

    scripts/infer_arity.py measures this from the call sites. It is an upper
    bound — nothing passes an argument it never loads — and propagate_calls
    needs one, for the reason documented there.
    """
    cap, by_nid = {}, {}
    p = os.path.join(ROOT, "nids/ehsys_arity.csv")
    if os.path.exists(p):
        for r in csv.DictReader(open(p)):
            m = re.match(r"ehsys_([0-9A-Fa-f]{8})$", r["name"])
            if m:
                try:
                    by_nid[int(m.group(1), 16)] = int(r["max_args"])
                except ValueError:
                    pass
    for vram, nid in export.items():
        if nid in by_nid:
            cap[vram] = by_nid[nid]
    return cap


def propagate_calls(facts, cap=None):
    """Fixed point: a function receives every argument any callee needs that it
    has not itself set by the time it makes that call.

    Monotone — argc only ever grows — so the fixed point is unique and the
    iteration order does not matter. Recursion and call cycles are therefore
    safe: they simply stop contributing once nothing grows.
    """
    local = {v: f["argc"] for v, f in facts.items()}
    changed, rounds = True, 0
    while changed and rounds < 50:
        changed, rounds = False, rounds + 1
        for f in facts.values():
            for target, written_here in f["call_args"]:
                tgt = facts.get(target)
                if not tgt:
                    continue
                for i in range(tgt["argc"]):
                    if ARG_REGS[i] not in written_here and f["argc"] < i + 1:
                        f["argc"] = i + 1
                        changed = True
    # Clamp to the call-site upper bound, never below what the body proves.
    # Uncapped, propagating across ordinary calls saturates: a linear
    # read-before-write scan cannot see a register written inside a branch, so
    # any eight-argument callee makes its callers look like eight-argument
    # functions too, and that cascades up the call graph.
    for vram, bound in (cap or {}).items():
        if vram in facts:
            facts[vram]["argc"] = max(local[vram], min(facts[vram]["argc"], bound))
    return rounds


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--top", type=int, default=0)
    args = ap.parse_args()

    d = open(ELF, "rb").read()
    stubs = import_stubs(d)
    names = sdk_names()

    nids = [u32(d, ENTRY_TABLE + 4 * i) for i in range(N_FUNCS + N_VARS)]
    addrs = [u32(d, ENTRY_TABLE + 4 * (N_FUNCS + N_VARS) + 4 * i)
             for i in range(N_FUNCS + N_VARS)]
    export = {addrs[i]: nids[i] for i in range(N_FUNCS)}

    call_sites = {}
    p = os.path.join(ROOT, "nids/ehsys.csv")
    if os.path.exists(p):
        for r in csv.DictReader(open(p)):
            try:
                call_sites[int(r["nid"], 16)] = int(r["call_sites"])
            except Exception:
                pass

    # Analyse EVERY function, not just the exported ones: a trampoline's tail
    # target is often an internal function, and its arity is what we need.
    facts = {}
    for fn, vram, body in parse_functions():
        (argc, warg, tail, returns, leaf, sdk,
         callees, libs, call_args) = analyse(body, stubs, names)
        facts[vram] = {"func": fn, "words": len(body), "argc": argc,
                       "written_args": warg, "tail_target": tail,
                       "returns": returns, "leaf": leaf, "sdk": sdk,
                       "callees": callees, "libs": libs, "call_args": call_args}
    r1 = propagate_calls(facts, call_arg_cap(export))
    r2 = propagate_behaviour(facts)
    print(f"arity propagation converged in {r1} rounds, behaviour in {r2}, "
          f"over {len(facts)} functions")

    rows = []
    for vram, f in facts.items():
        nid = export.get(vram)
        if nid is None:
            continue
        rows.append({
            "nid": f"0x{nid:08X}", "vram": f"0x{vram:06X}", "func": f["func"],
            "words": f["words"], "call_sites": call_sites.get(nid, 0),
            "argc": f["argc"], "stack_args": 0, "returns": f["returns"],
            "leaf": f["leaf"], "sdk_calls": ";".join(dict.fromkeys(f["sdk"])),
            "reaches": ";".join(sorted(f["libs"])),
            "sdk_reexport": "",
        })

    # Exports whose address lands in .sceStub.text are not engine functions at
    # all: the engine RE-EXPORTS a PSP SDK import so modules can reach the OS
    # through it. Those are free names — the SDK function is already known —
    # and PPSSPP's tables also give a return kind and parameter kinds.
    reexports = 0
    for vram, nid in export.items():
        if vram not in stubs:
            continue
        lib, snid = stubs[vram].split(":")
        name, ret, params = names.get(int(snid, 16), ("", "", ""))
        rows.append({
            "nid": f"0x{nid:08X}", "vram": f"0x{vram:06X}",
            "func": name or f"{lib}_{snid[2:]}",
            "words": 0, "call_sites": call_sites.get(nid, 0),
            "argc": len(params), "stack_args": 0,
            "returns": 1 if ret and ret != "v" else 0,
            "leaf": 1, "sdk_calls": name, "reaches": lib,
            "sdk_reexport": f"{lib}:{name}({params})" if name else lib,
        })
        reexports += 1
    print(f"  re-exported SDK imports resolved: {reexports} "
          f"({sum(1 for r in rows if r['sdk_reexport'] and r['sdk_calls'])} with a known name)")

    rows.sort(key=lambda r: -r["call_sites"])
    out = os.path.join(ROOT, "nids/ehsys_signatures.csv")
    with open(out, "w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=list(rows[0]))
        w.writeheader()
        w.writerows(rows)
    called = [r for r in rows if r["call_sites"] > 0]
    print(f"{len(rows)} exported functions resolved, {len(called)} of them called "
          f"by the 28 modules -> {out}")
    print(f"  with SDK calls (behaviour hint): {sum(1 for r in rows if r['sdk_calls'])}")
    print(f"  leaves: {sum(1 for r in rows if r['leaf'])}")

    if args.top:
        print(f"\n{'nid':<12}{'func':<18}{'words':>6}{'calls':>7}{'argc':>5}{'ret':>4}  sdk")
        for r in rows[:args.top]:
            print(f"{r['nid']:<12}{r['func']:<18}{r['words']:>6}{r['call_sites']:>7}"
                  f"{r['argc']:>5}{r['returns']:>4}  {r['sdk_calls'][:52]}")


if __name__ == "__main__":
    main()
