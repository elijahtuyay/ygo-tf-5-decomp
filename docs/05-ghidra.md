# 05 — Analisi statica con Ghidra + ghidra-allegrex

Ghidra (con l'estensione Allegrex) è lo strumento principale per capire il codice:
disassembla, decompila in pseudo-C, permette di nominare funzioni/dati e navigare le
chiamate. È complementare a splat: Ghidra per **capire**, splat per **produrre l'asm
da matchare**.

## Perché serve ghidra-allegrex

Ghidra "vanilla" ha il processore MIPS ma non conosce le specificità PSP. L'estensione
[**ghidra-allegrex**](https://github.com/kotcrab/ghidra-allegrex) (kotcrab) aggiunge:

- rilocazioni PSP: `PT_SCE_PSPREL` (`0x700000A0`) e `PT_SCE_PSPREL2` (compressa);
- rebase dell'immagine dopo il load;
- istruzioni **Allegrex** custom e **disassembly/decompilazione della VFPU** (COP2:
  128 registri, 8 matrici 4×4, `vmmul`, `vdot`, `vsin`, prefissi/swizzle…);
- riconoscimento automatico dell'ELF PSP e convenzione di chiamata PSP;
- import/export dei simboli `.sym` di **PPSSPP** (ponte con il debugging dinamico).

> Limiti noti (da PSP RE HQ): il supporto VFPU non è completissimo e i valori di
> ritorno/argomenti a 64 bit su più registri non sono sempre gestiti bene.

Installazione: vedi `03-strumenti.md` §4.

## Cosa caricare

- **Moduli `rel_*.prx`**: caricabili direttamente (sono ELF Allegrex in chiaro).
  L'header ha `e_type = 0xFFA0` (verificato: Ghidra/readelf lo mostrano come
  "Processor Specific: (ffa0)").
- **`modehsys`** (l'engine): serve prima l'ELF decifrato `build/EBOOT.elf`
  (vedi `04-estrazione-e-decrypt.md`), poi si carica come gli altri.

Indirizzo di load: convenzionalmente `0x08804000` per il modulo utente principale; i
moduli `rel_*` sono rilocabili (vram 0) e caricati dinamicamente dall'engine — Ghidra
applica le rilocazioni della `.rel.text`.

## Risolvere gli import: i NID

La PSP non importa le funzioni SDK per nome ma per **NID** = primi 4 byte di
`SHA-1(nome_funzione)`, in little-endian. Nel PRX:

- `.lib.stub` elenca i moduli importati (es. `sceGu`, `sceIo`, `sceCtrl`) e punta a…
- `.rodata.sceNid`, la tabella dei NID richiesti;
- `.sceStub.text` contiene gli stub (`jr $ra`/`nop`) patchati al load.

Senza tradurre i NID in nomi, il decompilato è illeggibile. Fonti/strumenti:

- **uofw/uofw** — https://github.com/uofw/uofw — reimplementazione clean-room del
  firmware PSP: è la fonte pubblica standard di NID **con nome e firma tipizzata**.
- **Script NID** (PSP RE HQ): un `SonyPSPResolveNIDs.py` mappa i NID e carica gli
  archivi di tipi Ghidra `PSPSDK.gdt` (per i giochi) o `uOFW.gdt` (per i moduli
  kernel). Quickstart: https://psp-re.github.io/quickstart/
- **psp-ghidra-scripts** — https://github.com/pspdev/psp-ghidra-scripts — fix
  import/export.
- **prxtool** (pspdev) risolve anch'esso i NID da riga di comando.

Flusso tipico all'apertura di un modulo:

1. Auto-analisi Ghidra (con ghidra-allegrex attivo).
2. Esegui lo script di risoluzione NID → gli stub prendono i nomi `sce*`.
3. Applica gli archivi di tipi (`PSPSDK.gdt`) → firme corrette delle funzioni SDK.
4. Da qui, naviga `module_start` e le funzioni esportate in `.lib.ent`.

## Ponte con PPSSPP (analisi dinamica)

PPSSPP ha disassembler, debugger, memory viewer e GE debugger integrati. Utile per:

- confermare a runtime cosa fa una funzione (breakpoint, watch di memoria);
- ricavare indirizzi reali di strutture dati;
- esportare i simboli `.sym` e importarli in Ghidra (e viceversa) con gli script di
  ghidra-allegrex.

I CWCheat noti per TF5 (vedi `08-risorse.md`) danno già indirizzi "caldi" da cui
partire: es. la coppia US `0x80338CD4/0x80338CD2` (All Cards / No Card Bans) indica
una funzione di **controllo legalità delle carte**, punto di partenza concreto.

## Convenzione dei nomi (mantenere coerenza con splat)

Quando nomini funzioni/dati in Ghidra, usa nomi che poi riporterai nei file di simboli
di splat (`config/symbols.*.txt`), così l'asm generato e il decompilato parlano la
stessa lingua. Esempi di schema da progetti maturi (sotn-decomp):

```
config/symbols.<modulo>.txt     # indirizzo = nome
config/symexport.<modulo>.txt   # simboli esportati
```

## Riferimenti

- ghidra-allegrex: https://github.com/kotcrab/ghidra-allegrex
- PSP RE HQ quickstart: https://psp-re.github.io/quickstart/
- uofw (NID/firme): https://github.com/uofw/uofw — tutorial:
  https://github.com/uofw/uofw/wiki/Reverse-Engineering-Tutorial
- Formato PRX: https://www.psdevwiki.com/psp/PRX_File_Format
- VFPU: https://pspdev.github.io/vfpu-docs/
