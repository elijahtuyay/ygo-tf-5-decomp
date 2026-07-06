# 01 — Overview: decompiling a PSP game

## What a "matching" decompilation is

A **matching decompilation** is the reconstruction of a game's C/C++ source code
such that, when recompiled with **the same compiler and the same options** used at
the time, it produces a binary that is **byte-for-byte identical** to the original.
This is the approach used by the best-known projects (Super Mario 64, Ocarina of
Time, etc.), and it provides two guarantees:

1. **Provable correctness**: if the output is identical, the reconstructed source is
   functionally equivalent by definition.
2. **A foundation for ports and mods**: once completed (even partially), the code can
   be modified, ported to PC, fixed, or extended.

The lighter-weight alternatives are **non-matching decomp** (equivalent but not
identical code) and plain **documentary reverse engineering** (understanding formats
and logic without reconstructing the source). A real-world project usually mixes all
three levels: matching where it matters (engine, game logic), documentary for
formats and assets.

## The workflow in summary

```
ISO UMD
 │  extraction (7z / mount)
 ▼
Encrypted EBOOT.BIN ──► decrypt (pspdecrypt / PPSSPP) ──► plaintext ELF
Game PRX modules (already plaintext)                              │
 ▼                                                                 ▼
Static analysis (Ghidra + Allegrex extension, prxtool, NID database)
 │  identify functions, data, SDK imports
 ▼
Binary splitting (splat: YAML config → asm/ + assets/ per segment)
 │
 ▼
Function-by-function decomp:  m2c (C draft) → by hand → asm-differ / decomp.me
 │                                                    (target asm vs. build comparison)
 ▼
Build system (make/ninja + MWCC via WINE/wibo) → rebuilt ELF
 │
 ▼
Verification: sha1sum rebuilt ELF == original ELF  → match percentage grows over time
```

The details of each phase are covered in documents 03–06.

## Why Tag Force 5 is a good candidate

From the ISO analysis (see `02-iso-analysis.md`):

- **28 plaintext PRX modules** with self-explanatory names (`rel_duel_eng`,
  `rel_story`, …): work can start immediately, without decryption, on small,
  self-contained modules.
- **Compiler identified with certainty** (MWCC PSP 2.4.1.01, from the `.comment`
  section): no blind compiler hunting, which is usually the most uncertain part of
  matching.
- **Modular architecture** (`ehsys` engine + feature modules): clean boundaries
  between subsystems = measurable progress module by module.
- **Existing modding community** for the Tag Force series (tools for `.ehp`
  archives, fan-made translations): asset formats are already partly documented.
- There is even a **debug menu** (`rel_debug_menu.prx`) left on the disc.

## Legal note (in brief)

- Working on a backup copy of a game **you own**, for study / interoperability /
  preservation purposes, is standard practice for serious decompilation projects.
- Golden rule of public projects: **never commit assets, original binaries, ISOs,
  or Konami/Sony copyrighted code to the repository** — only the hand-reconstructed
  code, the tools, and the documentation. This repo's `.gitignore` already excludes
  extracted ISOs/assets.
- No distribution of complete patched ISOs: mods are distributed as patches
  (xdelta) to be applied to the copy the user owns.
- Public matching projects (SM64, OOT, etc.) publish the reconstructed source and
  require the original ISO/ROM to extract assets: that is the model to follow.

## Realistic expectations

A complete decomp of a PSP game is a **multi-year** effort, typically done by a
team. Sensible intermediate goals, in order:

1. Reproducible pipeline: ISO extraction + EBOOT decryption, documented and
   scripted.
2. Ghidra project with modules loaded, SDK imports resolved via NID, functions
   named.
3. One small module (e.g. `rel_movie_viewer.prx`, 26 KB) split with splat and
   rebuilt 100% matching.
4. Asset formats (`.ehp`, card database) documented with pack/unpack tools.
5. Progressive expansion to `rel_duel_eng` and the main module `modehsys`.
