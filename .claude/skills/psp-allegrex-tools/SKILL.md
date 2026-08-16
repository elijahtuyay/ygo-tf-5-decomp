---
name: psp-allegrex-tools
description: >
  Operational reference for this project's PSP/MIPS Allegrex reverse-engineering
  toolchain: splat, spimdisasm/rabbitizer, Ghidra + ghidra-allegrex, prxtool, m2c,
  asm-differ/objdiff, decomp-permuter, mwccpsp+wibo, pspdecrypt, PPSSPP, NIDs.
  Activate when installing/using any of these tools, disassembling or decompiling
  Allegrex code, resolving NIDs/SDK imports, or setting up the matching build.
  Triggers: "splat", "ghidra", "allegrex", "VFPU", "NID", "prxtool", "m2c",
  "asm-differ", "objdiff", "mwccpsp", "wibo", "pspdecrypt", "decompile function".
---

# PSP Allegrex RE toolchain

Verified commands and facts. Assume the virtualenv is active: `. .venv/bin/activate`.

## Local state (verified)
- `.venv`: splat64[mips] 0.41.0, spimdisasm 1.42.2, rabbitizer 1.16.2 (category
  `R4000ALLEGREX`, VFPU included). `tools/`: asm-differ, m2c, decomp-permuter, pspdecrypt.
- **pspdecrypt built**; EBOOT already decrypted → `build/EBOOT.elf` (engine `modehsys`,
  sha1 `cc92ddd45f550ac1b906842d587c883fba22be34`).
- Install manually: **Ghidra 12.0** (NOT 12.1.x) + ghidra-allegrex **v21.3**
  (zip `ghidra_12.0_..._ghidra-allegrex.zip`), then wibo + mwccpsp; PPSSPP optional.

## Quick disassembly (no config) — useful for orientation
rabbitizer decodes Allegrex directly. Extract `.text` from a PRX and disassemble:
```python
import struct, rabbitizer
data=open('module.prx','rb').read()
# ... find .text offset/size via the ELF header (readelf -S) ...
ins=rabbitizer.Instruction(word, vram=addr, category=rabbitizer.InstrCategory.R4000ALLEGREX)
print(ins.disassemble())
```
Verified: produces correct code on the TF5 PRXs (e.g. `module_start` of rel_movie_viewer).

## splat (produces asm/ + linker script)
```bash
readelf -S module.prx          # 1) read the section layout
# 2) adapt config/<module>.yaml (start from config/rel_movie_viewer.example.yaml)
splat split config/<module>.yaml
```
PRX notes: they are relocatable ELFs with `vram=0`; the PSP-specific sections
(`.sceStub.text`, `.rodata.sceNid`, `.lib.stub/.lib.ent`, `.data`, `.bss`) must be added
as subsegments for the linker script to be generated. `platform: psp`.

## Ghidra + ghidra-allegrex
kotcrab extension: PSP relocations (`PT_SCE_PSPREL`/`PSPREL2`), VFPU, PPSSPP `.sym`.
Install: Ghidra ▸ File ▸ Install Extensions ▸ (+) ▸ zip ▸ restart. Load the plaintext
PRXs directly; for `modehsys` you first need the decrypted `build/EBOOT.elf`. Launch
with `scripts/run_ghidra.sh`.

## NIDs (SDK imports) — required for readability
NIDs = first 4 bytes of SHA-1(name), little-endian; table in `.rodata.sceNid`.
Name/signature database: **uofw** (https://github.com/uofw/uofw). PSP RE HQ flow:
NID resolution script + type archives `PSPSDK.gdt`/`uOFW.gdt`
(https://psp-re.github.io/quickstart/). Or `prxtool` from the CLI.

## m2c → C draft
```bash
python tools/m2c/m2c.py --target mips-mwcc-c asm/func.s > src/func.c
```

## Matching loop
- Online: decomp.me, **PSP / mwccpsp** preset. **CONFIRMED config: MWCC 1.3 SP7
  (mwccpsp_3.0.1_219), flags `-O4,s -sdatathreshold 0`.** (SIZE, not `,p` — corrected 2026-08-16) State globals are `volatile`
  (access via a local pointer). See `docs/09-first-match.md`.
- Local: `tools/asm-differ/diff.py -mwo <func>` or **objdiff** (supports MIPS PSP +
  CodeWarrior demangling). Stubborn → `tools/decomp-permuter/permuter.py`.
- Compiler: **mwccpsp** via **wibo** (`wibo mwccpsp.exe ...`), NOT psp-gcc.

## Decrypt EBOOT
```bash
make -C tools/pspdecrypt              # after: sudo apt install libssl-dev
scripts/decrypt_eboot.sh              # -> build/EBOOT.elf + sha1
```
Alternative: PPSSPP ▸ Developer Tools ▸ "Dump decrypted EBOOT on game boot".

## Match verification
`sha1sum` of the rebuilt output vs `checksums.sha1` (generated during extraction).

Extended details: `docs/03-tools.md`, `docs/05-ghidra.md`, `docs/06-splitting-and-matching.md`.
