# 03 — Strumenti e installazione

Guida all'installazione della toolchain su Ubuntu/Linux. Gran parte è già
automatizzata da `scripts/setup_tools.sh`; qui il dettaglio di cosa serve e perché.

## Stato su questa macchina (verificato)

| Strumento | Stato | Note |
|---|---|---|
| 7-Zip (`7z`) | ✅ installato | estrazione ISO |
| Python 3.12 + venv | ✅ | per splat/m2c |
| splat64 `[mips]` | ✅ installato in `.venv` | piattaforma `psp` presente |
| spimdisasm 1.42.2 | ✅ | dipendenza splat |
| rabbitizer 1.16.2 | ✅ | categoria `R4000ALLEGREX` (VFPU inclusa) |
| asm-differ / m2c / decomp-permuter | ✅ clonati in `tools/` | — |
| pspdecrypt | ✅ **compilato** e funzionante | EBOOT già decifrato (vedi sotto) |
| cmake / ninja / make / gcc / java | ✅ | build tool generici |
| Ghidra **12.0** | ❌ da installare | ⚠️ **non** la 12.1.x — vedi sotto |
| ghidra-allegrex v21.3 | ❌ da installare | estensione per Ghidra 12.0.x |
| PPSSPP | ❌ opzionale | emulatore/RE (EBOOT già decifrato senza) |
| pspdev (psp-gcc, prxtool) | ❌ opzionale | vedi sotto |
| wibo | ❌ da installare | per far girare mwccpsp su Linux |

## 1. Setup automatico (Python + tool git)

```bash
scripts/setup_tools.sh
```

Crea `.venv`, installa `requirements.txt` (splat/spimdisasm/rabbitizer + utilità) e
clona `asm-differ`, `m2c`, `decomp-permuter`, `pspdecrypt` in `tools/`. Idempotente.

## 2. Dipendenze di sistema (richiedono `sudo`)

Su questa macchina `sudo` chiede la password, quindi vanno lanciate manualmente. Nel
prompt di Claude Code puoi eseguirle con il prefisso `!`:

```bash
sudo apt update
sudo apt install -y p7zip-full build-essential libssl-dev git python3-venv \
                    cmake ninja-build
```

`libssl-dev` serve **solo** a compilare pspdecrypt (usa le SHA di OpenSSL).

## 3. pspdecrypt (decifrare l'EBOOT)

Dopo aver installato `libssl-dev`:

```bash
make -C tools/pspdecrypt
```

Uso tramite `scripts/decrypt_eboot.sh`. Repo: https://github.com/John-K/pspdecrypt
Alternativa senza compilare nulla: dump da PPSSPP (vedi `04-estrazione-e-decrypt.md`).

## 4. Ghidra + ghidra-allegrex (analisi statica principale)

Ghidra è il disassembler/decompiler principale. Richiede **JDK 21**. Il `java` di
Android Studio (JBR) può bastare, ma è più pulito installare un JDK dedicato:

```bash
sudo apt install -y openjdk-21-jdk
```

> ⚠️ **Versione critica**: l'estensione ghidra-allegrex v21.3 è compilata per
> **Ghidra 12.0.x** (fornisce zip per 12.0, 12.0.1 … 12.0.4). **NON** usare la Ghidra
> 12.1.x più recente: l'estensione non si caricherebbe. Installa **Ghidra 12.0**.

```bash
# 1) Ghidra 12.0 (release ufficiale NSA) — asset verificato
cd ~ && wget https://github.com/NationalSecurityAgency/ghidra/releases/download/Ghidra_12.0_build/ghidra_12.0_PUBLIC_20251205.zip
unzip ghidra_12.0_PUBLIC_20251205.zip        # crea ~/ghidra_12.0_PUBLIC
# avvio:
~/ghidra_12.0_PUBLIC/ghidraRun
```

**ghidra-allegrex** (kotcrab) aggiunge il processore Allegrex: rilocazioni PSP
(`PT_SCE_PSPREL`/`PSPREL2`), istruzioni Allegrex, **disassembly/decompilazione VFPU**,
import/export dei simboli `.sym` di PPSSPP, rilevamento automatico dell'ELF PSP.

```bash
# 2) estensione ghidra-allegrex per Ghidra 12.0 (zip che combacia con la versione)
cd ~ && wget https://github.com/kotcrab/ghidra-allegrex/releases/download/v21.3/ghidra_12.0_PUBLIC_20260310_ghidra-allegrex.zip
# poi dentro Ghidra:
#   File ▸ Install Extensions ▸ (+) ▸ seleziona lo zip scaricato ▸ OK ▸ riavvia Ghidra
```

Repo: https://github.com/kotcrab/ghidra-allegrex — se aggiorni Ghidra, scarica lo zip
dell'estensione con il numero di versione corrispondente.

Script utili di corredo: https://github.com/pspdev/psp-ghidra-scripts (fix import/
export) e il flusso NID di PSP RE HQ (vedi `05-ghidra.md`).

## 5. PPSSPP (emulatore come strumento di RE)

Utile per: disassembler/debugger integrato, memory viewer, GE debugger (grafica),
esportare simboli `.sym`. **Non serve più per decifrare l'EBOOT** (già fatto con
pspdecrypt), quindi è opzionale.

Metodo consigliato su Zorin/Ubuntu — **Flatpak** (Zorin ha già flatpak+Flathub):

```bash
flatpak install -y flathub org.ppsspp.PPSSPP
flatpak run org.ppsspp.PPSSPP
```

Se flatpak non fosse configurato:

```bash
sudo apt install -y flatpak
flatpak remote-add --if-not-exists flathub https://flathub.org/repo/flathub.flatpakrepo
```

(Non esiste un PPA `apt` ufficiale affidabile.) Sito/AppImage:
https://www.ppsspp.org/download/ — Repo: https://github.com/hrydgard/ppsspp

## 6. wibo (per compilare il match con mwccpsp)

`mwccpsp.exe` è un binario Windows: **wibo** (decompals) lo esegue su Linux senza WINE,
com'è prassi nei progetti decomp (lo usa sotn-decomp per il target PSP).

```
Repo: https://github.com/decompals/wibo   (build con cmake; poi:  wibo mwccpsp.exe ...)
```

Il compilatore `mwccpsp` in sé non è ridistribuibile qui: si ottiene da decomp.me
(scratch PSP) o dalle immagini di https://github.com/decompme/compilers
(`platforms/psp/`). Vedi `06-splat-e-matching.md` per la questione della **build**.

## 7. pspdev toolchain (opzionale ma comodo)

La toolchain omebrew Sony/pspdev dà `psp-gcc`, `psp-objdump`, `psp-readelf`,
`prxtool`, `psp-prxgen` e gli header `sce*`. **Non** serve per il match (il gioco è
MWCC, non GCC), ma è utile per ispezionare ELF/PRX e capire l'SDK.

```
Repo:  https://github.com/pspdev/pspdev   (installer: ./pspdev.sh, oppure release
       precompilate; setta $PSPDEV e $PATH)
prxtool (standalone): dump PRX↔ELF, risoluzione NID, disassembly.
```

## 8. objdiff (alternativa/complemento ad asm-differ)

[objdiff](https://github.com/encounter/objdiff) (Rust) fa diff locale a livello di
oggetto, supporta **MIPS PSP** e il demangling **CodeWarrior**, e alimenta il
cruscotto decomp.dev. Più comodo di asm-differ per progetti a molti oggetti; si guida
con un `objdiff.json`. Installazione: binari precompilati dalle release del repo.

## Riepilogo comandi minimi per partire

```bash
# 1. dipendenze di sistema (una volta)
sudo apt install -y p7zip-full build-essential libssl-dev python3-venv cmake ninja-build

# 2. toolchain del progetto
scripts/setup_tools.sh
make -C tools/pspdecrypt          # dopo libssl-dev

# 3. estrai + (opz.) decifra
scripts/extract_iso.sh "Yu-Gi-Oh 5D's Tag Force 5 (E)(M5)(ZER0)/0-ygotf5.iso"
scripts/decrypt_eboot.sh

# 4. Ghidra + ghidra-allegrex e PPSSPP: installazione manuale (sez. 4–5)
```
