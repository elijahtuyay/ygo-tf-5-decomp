#!/usr/bin/env python3
"""
Resolve every import of every gmodule PRX to a stable, project-wide name.

    scripts/resolve_nids.py            # rebuild nids/*.csv and config/symbols/*.txt

WHY THIS WORKS AT ALL
---------------------
A PSP import is identified by (library name, NID), where the NID is the first
4 bytes of SHA-1(function name), little-endian. Three kinds occur here:

  libehsys_rel  1729 functions, the engine that lives in the encrypted EBOOT.
                Every module links a stub for ALL 1729 exports whether it calls
                them or not, and the NID array is BYTE-IDENTICAL in all 28
                modules and in the EBOOT's own export table (sha1 820088858e31).
                So stub i is the same engine function in every module, and the
                EBOOT's .lib.ent pairs each NID with its address. No external
                data needed.

  lib*_rel      module-to-module imports (rel_labo calls into rel_cardalbum,
                rel_title into nine others, ...). Resolved the same way against
                the owning module's own .lib.ent.

  sce*          real SDK libraries. Names come from a candidate corpus
                (tools/nid_db/*.cpp, PPSSPP's HLE tables) and are then VERIFIED
                by recomputing the NID from the name — a match is proof, not a
                guess, so a wrong corpus can never introduce a wrong name.

NAMING
------
  sce* imports      real SDK name            sceHttpInit
  libehsys_rel      ehsys_<NID>              ehsys_B4471B5E
  lib<mod>_rel      <mod>_<NID>              cardalbum_1A2B3C4D

The NID is the identity: stable across modules, independent of load address,
and renameable in one place (nids/ehsys.csv `name` column) once a function is
actually identified — everything regenerates from there.

OUTPUTS
-------
  nids/sdk.csv        lib, nid, name                      (47 rows, all verified)
  nids/ehsys.csv      index, nid, eboot_vaddr, callers, name
  nids/modules.csv    lib, nid, owner, export_vaddr, callers, name
  config/symbols/<module>.txt   splat symbol_addrs: stub vram -> name
"""
import csv
import glob
import hashlib
import os
import re
import struct
import subprocess
from collections import Counter

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
GMODULE = os.path.join(ROOT, "iso_extracted/PSP_GAME/USRDIR/gmodule")
EBOOT = os.path.join(ROOT, "build/EBOOT.elf")
FILE_BASE = 0x54  # vaddr -> file offset for these single-PT_LOAD images


def nid_of(name):
    return struct.unpack("<I", hashlib.sha1(name.encode()).digest()[:4])[0]


def sections(path):
    out = subprocess.run(["readelf", "-SW", path], capture_output=True, text=True).stdout
    r = {}
    for line in out.splitlines():
        m = re.match(r"\s*\[\s*\d+\]\s+(\S+)\s+\S+\s+([0-9a-f]+)\s+([0-9a-f]+)\s+([0-9a-f]+)", line)
        if m:
            r[m.group(1)] = (int(m.group(2), 16), int(m.group(3), 16), int(m.group(4), 16))
    return r


def cstr(d, vaddr):
    o = vaddr + FILE_BASE
    return d[o:d.index(b"\0", o)].decode(errors="replace")


def parse_stubs(d, off, size):
    """.lib.stub -> [(lib, funcs, nid_vaddr, stub_vaddr)]"""
    out, i = [], 0
    while i < size:
        name, _vf, lenv, nidp, stubp = struct.unpack_from("<IIIII", d, off + i)
        ln, fc = lenv & 0xFF, (lenv >> 16) & 0xFFFF
        out.append((cstr(d, name), fc, nidp, stubp))
        i += ln * 4
    return out


def parse_ents(d, off, size):
    """.lib.ent -> [(lib, funcs, vars, entry_vaddr)]"""
    out, i = [], 0
    while i < size:
        name, _ver, _attr, ln, vc, fc, ent = struct.unpack_from("<IHHBBHI", d, off + i)
        out.append((cstr(d, name) if name else "(syslib)", fc, vc, ent))
        i += ln * 4
    return out


def exports(d, ents, lib):
    """lib's exports as [(nid, vaddr)] — the entry table is fcount+vcount NIDs
    followed by fcount+vcount addresses."""
    for name, fc, vc, ent in ents:
        if name == lib:
            nids = struct.unpack_from(f"<{fc}I", d, ent + FILE_BASE)
            addrs = struct.unpack_from(f"<{fc}I", d, ent + FILE_BASE + 4 * (fc + vc))
            return list(zip(nids, addrs))
    return []


def sdk_names():
    """NID -> name from the candidate corpus, each one re-hashed to prove it."""
    names = set()
    for f in glob.glob(os.path.join(ROOT, "tools/nid_db/*.cpp")):
        t = open(f, errors="replace").read()
        names |= set(re.findall(r'"([A-Za-z_][A-Za-z0-9_]{3,})"', t))
        names |= set(re.findall(r"\b([A-Za-z_][A-Za-z0-9_]{3,})\s*\(", t))
    table = {}
    for n in names:
        table.setdefault(nid_of(n), n)
    return table


def called_stubs(module, stub_vrams):
    """Which stub addresses .text actually calls."""
    p = os.path.join(ROOT, "asm", module, "text.s")
    hits = Counter()
    if not os.path.exists(p):
        return hits
    for line in open(p, errors="replace"):
        m = re.search(r"\b(?:jal|j)\s+func_([0-9A-F]+)", line)
        if m:
            v = int(m.group(1), 16)
            if v in stub_vrams:
                hits[v] += 1
    return hits


def main():
    mods = sorted(f[:-4] for f in os.listdir(GMODULE) if f.endswith(".prx"))
    sdk = sdk_names()

    # --- the engine's export table, from the decrypted EBOOT
    ed = open(EBOOT, "rb").read()
    es = sections(EBOOT)
    ents = parse_ents(ed, es[".lib.ent"][1], es[".lib.ent"][2])
    ehsys = exports(ed, ents, "libehsys_rel")
    assert len(ehsys) == 1729, f"expected 1729 libehsys_rel exports, got {len(ehsys)}"
    ehsys_index = {n: i for i, (n, _) in enumerate(ehsys)}

    # --- every module's own exports, so lib*_rel imports resolve too
    mod_exports = {}   # lib -> {nid: (owner, vaddr)}
    for m in mods:
        path = os.path.join(GMODULE, m + ".prx")
        d = open(path, "rb").read()
        s = sections(path)
        if ".lib.ent" not in s:
            continue
        for name, fc, vc, ent in parse_ents(d, s[".lib.ent"][1], s[".lib.ent"][2]):
            if name.endswith("_rel"):
                nids = struct.unpack_from(f"<{fc}I", d, ent + FILE_BASE)
                addrs = struct.unpack_from(f"<{fc}I", d, ent + FILE_BASE + 4 * (fc + vc))
                mod_exports.setdefault(name, {}).update(
                    {n: (m, a) for n, a in zip(nids, addrs)})

    def name_for(lib, nid):
        if not lib.endswith("_rel"):
            return sdk.get(nid, f"{lib}_{nid:08X}")
        if lib == "libehsys_rel":
            return f"ehsys_{nid:08X}"
        short = lib[3:-4] if lib.startswith("lib") else lib
        return f"{short}_{nid:08X}"

    eh_callers = Counter()
    rel_callers = Counter()
    sdk_rows = {}
    unresolved_sdk = []
    os.makedirs(os.path.join(ROOT, "config/symbols"), exist_ok=True)

    for m in mods:
        path = os.path.join(GMODULE, m + ".prx")
        d = open(path, "rb").read()
        s = sections(path)
        stubs = parse_stubs(d, s[".lib.stub"][1], s[".lib.stub"][2])
        vram_name, vram_meta = {}, {}
        # 26 of libehsys_rel's 1729 exports are listed TWICE (both entries point
        # at the same EBOOT address — genuine aliases), so a plain NID name is
        # not unique. Suffix repeats by occurrence order; the NID array is
        # identical in every module, so the same stub gets the same suffix
        # everywhere and the names stay cross-module stable.
        used = Counter()
        for lib, fc, nidp, stubp in stubs:
            nids = struct.unpack_from(f"<{fc}I", d, nidp + FILE_BASE)
            for k, n in enumerate(nids):
                v = stubp + k * 8
                nm = name_for(lib, n)
                used[nm] += 1
                if used[nm] > 1:
                    nm = f"{nm}_alias{used[nm]}"
                vram_name[v] = nm
                vram_meta[v] = (lib, n)
                if not lib.endswith("_rel"):
                    if n in sdk:
                        sdk_rows[(lib, n)] = sdk[n]
                    else:
                        unresolved_sdk.append((lib, n))
        for v, c in called_stubs(m, set(vram_name)).items():
            lib, n = vram_meta[v]
            if lib == "libehsys_rel":
                eh_callers[n] += c
            elif lib.endswith("_rel"):
                rel_callers[(lib, n)] += c

        with open(os.path.join(ROOT, "config/symbols", m + ".txt"), "w") as fh:
            fh.write(f"// Import stub names for {m}, generated by scripts/resolve_nids.py.\n"
                     "// Names are NID-derived and therefore IDENTICAL across all 28 modules:\n"
                     "// the same ehsys_XXXXXXXX is the same engine function everywhere.\n")
            for v in sorted(vram_name):
                fh.write(f"{vram_name[v]} = 0x{v:08X}; // type:func\n")

    os.makedirs(os.path.join(ROOT, "nids"), exist_ok=True)
    with open(os.path.join(ROOT, "nids/sdk.csv"), "w", newline="") as fh:
        w = csv.writer(fh)
        w.writerow(["lib", "nid", "name", "verified"])
        for (lib, n), nm in sorted(sdk_rows.items()):
            w.writerow([lib, f"0x{n:08X}", nm, "yes" if nid_of(nm) == n else "NO"])
        for lib, n in sorted(set(unresolved_sdk)):
            w.writerow([lib, f"0x{n:08X}", "", "unresolved"])

    with open(os.path.join(ROOT, "nids/ehsys.csv"), "w", newline="") as fh:
        w = csv.writer(fh)
        w.writerow(["index", "nid", "eboot_vaddr", "call_sites", "name"])
        for n, a in ehsys:
            w.writerow([ehsys_index[n], f"0x{n:08X}", f"0x{a:08X}", eh_callers.get(n, 0), ""])

    with open(os.path.join(ROOT, "nids/modules.csv"), "w", newline="") as fh:
        w = csv.writer(fh)
        w.writerow(["lib", "nid", "owner", "export_vaddr", "call_sites", "name"])
        for lib in sorted(mod_exports):
            for n, (owner, a) in sorted(mod_exports[lib].items()):
                w.writerow([lib, f"0x{n:08X}", owner, f"0x{a:08X}",
                            rel_callers.get((lib, n), 0), ""])

    print(f"modules: {len(mods)}")
    print(f"libehsys_rel: 1729 exports, {len(eh_callers)} called project-wide")
    print(f"sdk: {len(sdk_rows)} resolved, {len(set(unresolved_sdk))} unresolved")
    print(f"inter-module libs: {len(mod_exports)}, {len(rel_callers)} exports called")
    print("wrote nids/*.csv and config/symbols/*.txt")


if __name__ == "__main__":
    main()
