# ygo-tf-5-decomp

Progetto di **decompilazione (matching)** di *Yu-Gi-Oh! 5D's Tag Force 5* per PSP
(disco **ULES-01474**, Konami 2010, CPU MIPS Allegrex).

Obiettivo: ricostruire a mano il codice C dei moduli del gioco in modo che,
ricompilati con il compilatore originale, producano binari **byte-per-byte identici**
a quelli sul disco — e da lì poter capire, correggere ed estendere il gioco (a
partire dalla logica dei duelli, che è hardcoded nel codice, non nei dati).

> ⚠️ **Nessun contenuto Konami/Sony va nel repository.** ISO, `.prx`, EBOOT e asset
> estratti sono esclusi da `.gitignore`. Serve una propria copia legale del gioco per
> estrarre i file. Le mod si distribuiscono come patch, mai come ISO complete.

## Stato attuale

Fase di **setup completata**: analisi del disco fatta, toolchain installata e
verificata, EBOOT decifrato, documentazione e skill pronte. È pronta anche la rampa di
lancio per la decomp vera e propria: il tutorial del **primo match** con due funzioni
già individuate in `rel_movie_viewer` (vedi `docs/09-primo-match.md`). Prossimo passo
operativo: portare quelle funzioni al 100% su decomp.me.

Cosa è già accertato e funzionante:

- **28 moduli `rel_*.prx` sono ELF Allegrex in chiaro** → analizzabili subito.
- **EBOOT.BIN decifrato**: con pspdecrypt si ottiene `build/EBOOT.elf` (engine
  `modehsys`, ELF32 Allegrex, 1,5 MB; sha1 `cc92ddd4…`). `BOOT.BIN` è un dummy azzerato.
- **Compilatore originale: Metrowerks CodeWarrior** (`MW MIPS C Compiler (2.4.1.01)`,
  confermato anche sull'EBOOT) → il match si fa con `mwccpsp`, non con psp-gcc.
- Pipeline provata end-to-end su un modulo reale: estrazione ISO → decrypt EBOOT →
  disassembly Allegrex (rabbitizer) → **splat produce asm etichettato con rilocazioni
  risolte**.
- `checksums.sha1` con gli hash di tutti i moduli + EBOOT.elf = target del match.

## Struttura del repository

```
README.md              questo file
docs/                  documentazione (in italiano) — vedi indice sotto
scripts/               setup_tools.sh, extract_iso.sh, decrypt_eboot.sh
config/                config splat (rel_movie_viewer.example.yaml = esempio verificato)
requirements.txt       toolchain Python (splat/spimdisasm/rabbitizer)
checksums.sha1         hash sha1 dei moduli originali (target del match)
.claude/skills/        skill per Claude Code (tf5-decomp, psp-allegrex-tools, tf5-formati)
.gitignore             esclude ISO/asset/binari/build

# generati/ignorati (non in git):
iso_extracted/         output di extract_iso.sh
tools/                 asm-differ, m2c, decomp-permuter, pspdecrypt (clonati)
.venv/                 virtualenv Python
build/                 EBOOT.elf decifrato, output di build
```

## Quick start

```bash
# 1. dipendenze di sistema (una volta) — richiede sudo
sudo apt install -y p7zip-full build-essential libssl-dev python3-venv cmake ninja-build

# 2. toolchain del progetto (venv + tool git)
scripts/setup_tools.sh

# 3. estrai il disco (usa la tua ISO)
scripts/extract_iso.sh "Yu-Gi-Oh 5D's Tag Force 5 (E)(M5)(ZER0)/0-ygotf5.iso"

# 4. (opzionale) decifra l'EBOOT — engine condiviso modehsys
make -C tools/pspdecrypt        # dopo libssl-dev
scripts/decrypt_eboot.sh

# 5. prova lo split su un modulo piccolo
. .venv/bin/activate
splat split config/rel_movie_viewer.example.yaml
```

Ghidra + ghidra-allegrex e PPSSPP si installano a mano: vedi `docs/03-strumenti.md`.

## Documentazione

Leggere in ordine per una comprensione completa:

1. [`docs/01-panoramica.md`](docs/01-panoramica.md) — cos'è una decomp matching, flusso, note legali, aspettative
2. [`docs/02-analisi-iso.md`](docs/02-analisi-iso.md) — struttura del disco, moduli, compilatore identificato
3. [`docs/03-strumenti.md`](docs/03-strumenti.md) — installazione della toolchain su Linux
4. [`docs/04-estrazione-e-decrypt.md`](docs/04-estrazione-e-decrypt.md) — estrarre la ISO, decifrare l'EBOOT
5. [`docs/05-ghidra.md`](docs/05-ghidra.md) — analisi con Ghidra + ghidra-allegrex, NID
6. [`docs/06-splat-e-matching.md`](docs/06-splat-e-matching.md) — split, m2c, asm-differ, decomp.me, mwccpsp
7. [`docs/07-formati-file.md`](docs/07-formati-file.md) — formati asset (EHP/CIP/carte/audio/modelli)
8. [`docs/08-risorse.md`](docs/08-risorse.md) — link, community, progetto di riferimento (sotn-decomp)
9. [`docs/09-primo-match.md`](docs/09-primo-match.md) — **tutorial pratico**: il primo match su decomp.me

## Rischio principale

La `.comment` dei binari indica CodeWarrior `2.4.1.01`, mentre le build di `mwccpsp`
disponibili pubblicamente (decomp.me) sono etichettate `3.0.1_NNN`. Trovare la build
che produce un match è l'incognita più grossa del progetto — vedi `docs/06`.

## Riferimento di processo

[**sotn-decomp**](https://github.com/Xeeynamo/sotn-decomp) è l'unica decomp matching
con un target PSP funzionante e usa la nostra stessa impostazione (splat + mwccpsp via
wibo + verifica sha1 + frogress). È il modello da seguire.
