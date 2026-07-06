---
name: psp-allegrex-tools
description: >
  Riferimento operativo della toolchain di reverse engineering PSP/MIPS Allegrex per
  questo progetto: splat, spimdisasm/rabbitizer, Ghidra + ghidra-allegrex, prxtool,
  m2c, asm-differ/objdiff, decomp-permuter, mwccpsp+wibo, pspdecrypt, PPSSPP, NID.
  Attiva quando si installa/usa uno di questi strumenti, si disassembla o decompila
  codice Allegrex, si risolvono i NID/import SDK, o si imposta il build di matching.
  Trigger: "splat", "ghidra", "allegrex", "VFPU", "NID", "prxtool", "m2c",
  "asm-differ", "objdiff", "mwccpsp", "wibo", "pspdecrypt", "decompilare funzione".
---

# Toolchain RE per PSP Allegrex

Comandi e fatti verificati. Assumi il virtualenv attivo: `. .venv/bin/activate`.

## Stato locale (verificato)
- `.venv`: splat64[mips] 0.41.0, spimdisasm 1.42.2, rabbitizer 1.16.2 (categoria
  `R4000ALLEGREX`, VFPU inclusa). `tools/`: asm-differ, m2c, decomp-permuter, pspdecrypt.
- **pspdecrypt compilato**; EBOOT già decifrato → `build/EBOOT.elf` (engine `modehsys`,
  sha1 `cc92ddd45f550ac1b906842d587c883fba22be34`).
- Da installare a mano: **Ghidra 12.0** (NON 12.1.x) + ghidra-allegrex **v21.3**
  (zip `ghidra_12.0_..._ghidra-allegrex.zip`), poi wibo + mwccpsp; PPSSPP opzionale.

## Disassembly rapido (senza config) — utile per orientarsi
rabbitizer decodifica Allegrex direttamente. Estrarre `.text` da un PRX e disassemblare:
```python
import struct, rabbitizer
data=open('modulo.prx','rb').read()
# ... trova offset/size di .text via header ELF (readelf -S) ...
ins=rabbitizer.Instruction(word, vram=addr, category=rabbitizer.InstrCategory.R4000ALLEGREX)
print(ins.disassemble())
```
Verificato: produce codice corretto sui PRX di TF5 (es. `module_start` di rel_movie_viewer).

## splat (produzione asm/ + linker script)
```bash
readelf -S modulo.prx          # 1) leggi layout sezioni
# 2) adatta config/<modulo>.yaml (parti da config/rel_movie_viewer.example.yaml)
splat split config/<modulo>.yaml
```
Note PRX: sono ELF rilocabili con `vram=0`; le sezioni PSP-specifiche
(`.sceStub.text`, `.rodata.sceNid`, `.lib.stub/.lib.ent`, `.data`, `.bss`) vanno messe
come subsegment perché venga generato il linker script. `platform: psp`.

## Ghidra + ghidra-allegrex
Estensione kotcrab: rilocazioni PSP (`PT_SCE_PSPREL`/`PSPREL2`), VFPU, PPSSPP `.sym`.
Install: Ghidra ▸ File ▸ Install Extensions ▸ (+) ▸ zip ▸ riavvia. Carica i PRX in
chiaro direttamente; per `modehsys` serve prima `build/EBOOT.elf` decifrato.

## NID (import SDK) — obbligatorio per leggibilità
I NID = primi 4 byte di SHA-1(nome), little-endian; tabella in `.rodata.sceNid`.
Database nomi/firme: **uofw** (https://github.com/uofw/uofw). Flusso PSP RE HQ:
script risoluzione NID + archivi tipi `PSPSDK.gdt`/`uOFW.gdt`
(https://psp-re.github.io/quickstart/). Oppure `prxtool` da CLI.

## m2c → bozza C
```bash
python tools/m2c/m2c.py --target mips-mwcc-c asm/func.s > src/func.c
```

## Matching loop
- Online: decomp.me, preset **PSP / mwccpsp** (vedi caveat build nel README/doc 06).
- Locale: `tools/asm-differ/diff.py -mwo <func>` oppure **objdiff** (supporta MIPS PSP
  + demangle CodeWarrior). Ostinato → `tools/decomp-permuter/permuter.py`.
- Compilatore: **mwccpsp** via **wibo** (`wibo mwccpsp.exe ...`), NON psp-gcc.

## Decrypt EBOOT
```bash
make -C tools/pspdecrypt              # dopo: sudo apt install libssl-dev
scripts/decrypt_eboot.sh              # -> build/EBOOT.elf + sha1
```
Alternativa: PPSSPP ▸ Developer Tools ▸ "Dump decrypted EBOOT on game boot".

## Verifica match
`sha1sum` dell'output ricostruito vs `checksums.sha1` (già generato in fase estrazione).

Dettagli estesi: `docs/03-strumenti.md`, `docs/05-ghidra.md`, `docs/06-splat-e-matching.md`.
