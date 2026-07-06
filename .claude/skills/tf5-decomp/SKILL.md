---
name: tf5-decomp
description: >
  Orientation and workflow for the matching decompilation of Yu-Gi-Oh! 5D's Tag
  Force 5 (PSP, ULES-01474). Activate this skill whenever working in this repository on
  decompilation, reverse engineering, PRX/EBOOT module analysis, binary splitting,
  function matching, or the game's file formats. Triggers: "decomp", "decompile",
  "matching", "PRX", "EBOOT", "Allegrex", "splat", "duel_eng", "Tag Force", "modehsys",
  "PSP reverse engineering".
---

# Tag Force 5 decomp — operating guide

Project: matching reconstruction of the code of **Yu-Gi-Oh! 5D's Tag Force 5**
(PSP, MIPS Allegrex, Konami 2010, disc **ULES-01474**).

## Project facts NOT to rediscover every time

- **Original compiler = Metrowerks CodeWarrior `MW MIPS C Compiler (2.4.1.01)`**
  (from the `.comment` section of every PRX). Matching uses **`mwccpsp`**, not psp-gcc.
  On decomp.me the PSP builds use the product names **MWCC 1.0 … 1.3 SP7** (internal
  builds 3.0.1_121…219); `2.4.1.01` is a different numbering axis, do NOT look for it
  in the list. Bisect from the high builds (219→210→205…) on a real function to find the
  right one; locally it runs via **wibo**. Details in `docs/09-first-match.md`.
- **CONFIRMED config**: compiler **MWCC 1.3 SP7 (mwccpsp_3.0.1_219)**, flags
  **`-O4,p -sdatathreshold 0`**. `-sdatathreshold 0` = absolute addressing (not
  gp-relative). Confirmed on 9 real functions of `rel_movie_viewer` (not just the
  trivial empty one) — build 219 is proven SUFFICIENT, not yet proven unique
  (adjacent builds 210/205/... untried on these same functions).
- **Matching works fully locally now, no decomp.me account needed**:
  `scripts/mwcc_build.sh src/file.c` (wibo + real mwccpsp_3.0.1_219, both
  auto-fetched by `setup_tools.sh`) then `scripts/mwcc_diff.py asm/.../text.s
  build/mwcc/file.o` — relocation-aware, treats a word as matching if either the
  raw bytes are equal or both sides reference the same relocation (HI16/LO16/26)
  against the same symbol (unlinked `.o`s have zeroed placeholders; some globals
  are baked as absolute constants in the shipped PRX with NO relocation at all —
  see `docs/06-splitting-and-matching.md` "Local matching" for the full story
  and the `KNOWN_ADDR` table to extend). Needs `binutils-mips-linux-gnu` (`sudo
  apt install`) for a MIPS-aware `objdump`.
- **Technique**: game **state globals are `volatile`**; to match, access them via a
  local pointer: `volatile int *p = &G; if (*p) { ... *p ...; *p = 0; }` — this
  reproduces the value reload + use of saved registers (`$s0`). Full case in
  `docs/09-first-match.md`.
- **The 28 `USRDIR/gmodule/rel_*.prx` modules are PLAINTEXT Allegrex ELF**: analyzable
  immediately, no decryption needed. Convention: `rel_X.prx` = module `modX`, exports
  `libX_rel`, imports `libehsys_rel` from the main engine.
- **`SYSDIR/EBOOT.BIN` is ENCRYPTED** (magic `~PSP`, module `modehsys`). `BOOT.BIN` is a
  zeroed dummy (NOT the plaintext ELF). Decrypt it with pspdecrypt or PPSSPP.
- **No Tag Force decomp has ever existed**: we're the first. Card logic is **hardcoded**
  in `rel_duel_eng.prx`, not in data → decompiling the code is the only way to really
  understand it.
- **Local toolchain already installed and verified**: splat64 (platform `psp`),
  spimdisasm, rabbitizer (category `R4000ALLEGREX`, with VFPU), in `.venv`;
  asm-differ, m2c, decomp-permuter, pspdecrypt, wibo, mwccpsp_3.0.1_219 in
  `tools/`; Ghidra 12.0 + ghidra-allegrex installed system-wide.

## Hard repository rules

- **NEVER commit** ISOs, `.prx`, EBOOT, extracted assets, `iso_extracted/`, `build/`,
  `asm/`. The `.gitignore` already excludes them. Only `src/`, `config/`, `scripts/`,
  `docs/` (and the git-ignored `tools/`) belong in git.
- Mods are distributed as **xdelta patches**, never as complete ISOs.

## The pipeline (details in docs/)

```
ISO ──scripts/extract_iso.sh──► iso_extracted/
EBOOT.BIN (~PSP) ──scripts/decrypt_eboot.sh──► build/EBOOT.elf   (needs libssl-dev)
plaintext PRX / EBOOT.elf
   ──Ghidra+ghidra-allegrex / prxtool──►  analysis, NIDs, function names
   ──splat (config/*.yaml)──►  asm/  +  linker script
   ──m2c──►  draft src/*.c
   ──mwccpsp + asm-differ / decomp.me──►  byte-for-byte match
   ──make + sha1sum vs checksums.sha1──►  verify
```

## How to attack a new module (checklist)

1. `readelf -SW module.prx` → note the section layout (.text/.sceStub.text/.rodata.sceNid/.data/.bss).
2. Write/adapt a splat config (start from `config/rel_movie_viewer.yaml`, a complete
   section-accurate example covering 100% of the file — see its header comments for
   the byte-offset table and a linker-script-ordering gotcha).
3. `splat split config/module.yaml` → generates `asm/`.
4. Resolve imports: `.rodata.sceNid` lists the NIDs of imported SDK functions; name them
   with a NID database (see the `psp-allegrex-tools` skill).
5. For each function: `m2c` → draft C → iterate until the diff is empty, verifying
   either on decomp.me OR **locally** with `scripts/mwcc_build.sh` +
   `scripts/mwcc_diff.py` (wibo + real mwccpsp_3.0.1_219, both fetched by
   `setup_tools.sh` — no decomp.me account needed) → mark "MATCH 100%" in the
   function's comment.
6. Rebuild and verify the sha1 against `checksums.sha1`.

## Recommended module order

`rel_movie_viewer` (26 KB, to shake down the pipeline) → other small modules
(`rel_html_view`, `rel_soundtest`) → **`modehsys`** (EBOOT: shared engine, unlocks
`libehsys_rel`) → **`rel_duel_eng`** (4.3 MB: the rules engine, the heart of the game).

## Full documentation

- `docs/01-overview.md` — what a matching decomp is, expectations, legal notes
- `docs/02-iso-analysis.md` — ISO structure, modules, compiler
- `docs/03-tools.md` — toolchain installation
- `docs/04-extraction-and-decryption.md` — extracting the ISO, decrypting the EBOOT
- `docs/05-ghidra.md` — Ghidra + ghidra-allegrex, prxtool, NIDs
- `docs/06-splitting-and-matching.md` — splitting, m2c, asm-differ, decomp.me, mwccpsp
- `docs/07-file-formats.md` — EHP/CIP/card DB/audio/models + community tools
- `docs/08-resources.md` — links, community, reference project
- `docs/09-first-match.md` — tutorial: first match on decomp.me (empty `func_000001C0`
  and `func_00000184` in rel_movie_viewer; m2c C draft included)

Related skills: **psp-allegrex-tools** (RE toolchain), **tf5-formats** (assets).
