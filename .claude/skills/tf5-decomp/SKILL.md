---
name: tf5-decomp
description: >
  Orientamento e workflow per la decompilazione (matching) di Yu-Gi-Oh! 5D's Tag
  Force 5 (PSP, ULES-01474). Attiva questa skill ogni volta che si lavora in questo
  repository su decomp, reverse engineering, analisi dei moduli PRX/EBOOT, split del
  binario, matching di funzioni, o formati dei file del gioco. Trigger: "decomp",
  "decompilare", "matching", "PRX", "EBOOT", "Allegrex", "splat", "duel_eng",
  "Tag Force", "modehsys", "reverse engineering PSP".
---

# Decomp di Tag Force 5 — guida operativa

Progetto: ricostruzione matching del codice di **Yu-Gi-Oh! 5D's Tag Force 5**
(PSP, MIPS Allegrex, Konami 2010, disco **ULES-01474**).

## Fatti di progetto da NON riscoprire ogni volta

- **Compilatore originale = Metrowerks CodeWarrior `MW MIPS C Compiler (2.4.1.01)`**
  (dalla sezione `.comment` di tutti i PRX). Il match si fa con **`mwccpsp`**, non con
  psp-gcc. Su decomp.me il preset è PSP/`mwccpsp`; in locale gira via **wibo**/WINE.
- **I 28 moduli `USRDIR/gmodule/rel_*.prx` sono ELF Allegrex IN CHIARO**: analizzabili
  subito, senza decifrare nulla. Convenzione: `rel_X.prx` = modulo `modX`, esporta
  `libX_rel`, importa `libehsys_rel` dall'engine principale.
- **`SYSDIR/EBOOT.BIN` è CIFRATO** (magic `~PSP`, modulo `modehsys`). `BOOT.BIN` è un
  dummy azzerato (NON è l'ELF in chiaro). Va decifrato con pspdecrypt o PPSSPP.
- **Nessuna decomp Tag Force è mai esistita**: siamo i primi. La logica delle carte è
  **hardcoded** in `rel_duel_eng.prx`, non nei dati → decompilare il codice è l'unico
  modo di capirla davvero.
- **Toolchain locale già installata e verificata**: splat64 (piattaforma `psp`),
  spimdisasm, rabbitizer (categoria `R4000ALLEGREX`, con VFPU), in `.venv`;
  asm-differ, m2c, decomp-permuter, pspdecrypt in `tools/`.

## Regole ferree del repository

- **MAI committare** ISO, `.prx`, EBOOT, asset estratti, `iso_extracted/`, `build/`.
  Il `.gitignore` li esclude già. Solo `src/`, `config/`, `scripts/`, `docs/`, `tools/`
  (submodule/clonati) vanno in git.
- Le mod si distribuiscono come **patch xdelta**, mai come ISO complete.

## La pipeline (dettagli in docs/)

```
ISO ──scripts/extract_iso.sh──► iso_extracted/
EBOOT.BIN (~PSP) ──scripts/decrypt_eboot.sh──► build/EBOOT.elf   (serve libssl-dev)
PRX in chiaro / EBOOT.elf
   ──Ghidra+ghidra-allegrex / prxtool──►  analisi, NID, nomi funzioni
   ──splat (config/*.yaml)──►  asm/  +  linker script
   ──m2c──►  bozza src/*.c
   ──mwccpsp + asm-differ / decomp.me──►  match byte-per-byte
   ──make + sha1sum vs checksums.sha1──►  verifica
```

## Come attaccare un nuovo modulo (checklist)

1. `readelf -S modulo.prx` → annota layout sezioni (.text/.rodata.sceNid/.data/.bss).
2. Scrivi/adatta una config splat (parti da `config/rel_movie_viewer.example.yaml`).
3. `splat split config/modulo.yaml` → genera `asm/`.
4. Risolvi gli import: la `.rodata.sceNid` elenca i NID delle funzioni SDK importate;
   nominale con un database NID (vedi skill `psp-allegrex-tools`).
5. Per ogni funzione: `m2c` → bozza C → mwccpsp/decomp.me → itera con asm-differ finché
   il diff è vuoto → segna "matched".
6. Ricostruisci e verifica lo sha1 contro `checksums.sha1`.

## Ordine consigliato dei moduli

`rel_movie_viewer` (26 KB, per rodare la pipeline) → altri moduli piccoli
(`rel_html_view`, `rel_soundtest`) → **`modehsys`** (EBOOT: engine condiviso, sblocca
`libehsys_rel`) → **`rel_duel_eng`** (4,3 MB: motore delle regole, il cuore del gioco).

## Documentazione completa

- `docs/01-panoramica.md` — cos'è una decomp matching, aspettative, note legali
- `docs/02-analisi-iso.md` — struttura ISO, moduli, compilatore
- `docs/03-strumenti.md` — installazione toolchain
- `docs/04-estrazione-e-decrypt.md` — estrarre ISO, decifrare EBOOT
- `docs/05-ghidra.md` — Ghidra + ghidra-allegrex, prxtool, NID
- `docs/06-splat-e-matching.md` — split, m2c, asm-differ, decomp.me, mwccpsp
- `docs/07-formati-file.md` — EHP/CIP/card DB/audio/modelli + tool community
- `docs/08-risorse.md` — link, community, repo di riferimento
- `docs/09-primo-match.md` — tutorial: primo match su decomp.me (funzioni `func_000001C0`
  vuota e `func_00000184` in rel_movie_viewer; bozza C da m2c inclusa)

Skill correlate: **psp-allegrex-tools** (toolchain RE), **tf5-formati** (asset).
