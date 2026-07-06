# 06 — Split del binario e workflow di matching

Questa è la fase centrale: dal binario alle funzioni C ricostruite, verificando che
la ricompilazione produca byte identici all'originale.

## 0. Il compilatore da eguagliare: Metrowerks CodeWarrior PSP

Dato accertato dalla sezione `.comment` di tutti i moduli (vedi `02-analisi-iso.md`):

```
MW MIPS C Compiler (2.4.1.01)   +   "PSP"
```

Il matching richiede **quello stesso compilatore**, non psp-gcc. Implicazioni:

- Su [decomp.me](https://decomp.me) la famiglia di compilatori si chiama **`mwccpsp`**
  (Metrowerks CodeWarrior for PSP). È l'ambiente più comodo per iniziare a "matchare"
  singole funzioni senza montare la toolchain in locale.
- In locale, `mwccpsp` è un eseguibile Windows: si lancia via **WINE** o con
  **[wibo](https://github.com/decompals/wibo)** (loader PE minimale usato dai progetti
  decomp per far girare i compilatori MW/SN sotto Linux/CI).
- I flag esatti (livello di ottimizzazione, `-inline`, allineamenti…) vanno trovati
  per tentativi confrontando l'output: è la parte "artigianale" del match.

> ⚠️ **Nota sulla versione (da verificare)**: la `.comment` riporta la stringa
> `MW MIPS C Compiler (2.4.1.01)`. decomp.me ospita build di `mwccpsp` etichettate
> `3.0.1_121 … 3.0.1_219` (11 build). Il progetto di riferimento **sotn-decomp**
> (PSP) usa la build **219**. La stringa `2.4.1.01` di TF5 potrebbe corrispondere a
> una CodeWarrior più vecchia di quelle su decomp.me: non dare per scontato che una
> build lì presente matchi al primo colpo. Prima funzione da matchare → **bisezione**
> tra le build disponibili per trovare quella giusta (o procurarsi la build esatta se
> nessuna combacia). È l'incognita più grossa del progetto: annotarne l'esito qui.

> psp-gcc (pspdev, vedi `03-strumenti.md`) resta utilissimo per `psp-objdump`,
> per capire gli header e per costruire stub, ma **non** produrrà mai un match
> byte-identico contro codice MWCC.

## 1. Split con splat

[splat](https://github.com/ethteck/splat) prende un binario + una config YAML e lo
divide in `asm/` (uno `.s` per funzione/file) e `assets/`, generando anche il linker
script. **Supporta nativamente la piattaforma `psp`** e, tramite `rabbitizer`, l'intero
set Allegrex inclusa la VFPU (categoria `R4000ALLEGREX`).

Installazione (già in `requirements.txt`):

```bash
. .venv/bin/activate
pip install "splat64[mips]"     # tira dentro spimdisasm + rabbitizer
```

### Esempio verificato su un modulo reale

Con la config `config/rel_movie_viewer.example.yaml`:

```bash
splat split config/rel_movie_viewer.example.yaml
```

produce `asm/text.s` con funzioni etichettate e rilocazioni risolte simbolicamente —
testato, output reale:

```asm
glabel func_00000000
    /* 54 00000000 F0FFBD27 */  addiu  $sp, $sp, -0x10
    /* 58 00000004 0000043C */  lui    $a0, %hi(func_00000034)
    /* 5C 00000008 0000053C */  lui    $a1, %hi(func_000001C0)
    /* 60 0000000C 0000063C */  lui    $a2, %hi(D_00005AC0)
    ...
    /* 7C 00000028 21100000 */  addu   $v0, $zero, $zero
    /* 80 0000002C 0800E003 */  jr     $ra
endlabel func_00000000
```

splat individua da solo i confini di funzione e le `%hi/%lo`. Restano da mappare in
config le sezioni PSP-specifiche (`.sceStub.text`, `.rodata.sceNid`, `.lib.stub`,
`.data`, `.bss`) per generare anche il linker script: vedi i commenti nel file di
esempio, con il layout reale delle sezioni.

### Particolarità dei PRX (importante)

I `.prx` sono ELF **rilocabili** con `vram = 0`. Le istruzioni `lui/addiu` di
indirizzamento hanno gli operandi azzerati nel file e i valori veri stanno nella
sezione `.rel.text`. Sia rabbitizer che Ghidra applicano queste rilocazioni; quando
scriverai le config splat, tieni presente che gli indirizzi assoluti dipendono
dall'indirizzo di load (tipicamente `0x08804000` per il modulo principale, mentre i
moduli `rel_*` vengono caricati dinamicamente dall'engine).

## 2. Bozza C automatica con m2c

[m2c](https://github.com/matt-kempster/m2c) (ex mips_to_c) traduce l'assembly MIPS in
una prima bozza di C, da rifinire a mano finché non matcha:

```bash
python tools/m2c/m2c.py --target mips-mwcc-c asm/funzione.s > src/funzione.c
```

m2c gestisce MIPS Allegrex (è lo stesso ISA base). Il target `mwcc` orienta lo stile
di output verso le convenzioni CodeWarrior. La bozza **non** sarà matching: serve come
scheletro leggibile da correggere.

## 3. Confronto: asm-differ e decomp.me

Il ciclo di match è: *scrivi C → compila → confronta l'asm prodotto con il target →
correggi → ripeti*, finché il diff è vuoto.

**In locale** con [asm-differ](https://github.com/simonlindholm/asm-differ):

```bash
tools/asm-differ/diff.py -mwo funzione     # -m match, -w watch (ricompila e ridiffa)
```

Mostra affiancati l'asm target e quello della tua build, evidenziando le differenze.

**Online**, [decomp.me](https://decomp.me) fa la stessa cosa nel browser: incolli
l'asm target, scegli lo "scratch" con preset **PSP / `mwccpsp`**, scrivi il C e vedi
la percentuale di match in tempo reale. È il modo consigliato per le prime funzioni,
perché la toolchain MWCC è già pronta lato server.

Quando una funzione resiste, [decomp-permuter](https://github.com/simonlindholm/decomp-permuter)
prova automaticamente varianti equivalenti del sorgente per trovare quella che matcha:

```bash
tools/decomp-permuter/permuter.py funzione_dir/
```

## 4. Build system e verifica del match

L'obiettivo è un `Makefile`/`ninja` che:

1. compili i `src/*.c` con **mwccpsp** (via wibo/WINE) con i flag giusti;
2. assembli i `.s` ancora non decompilati;
3. linki tutto col linker script prodotto da splat;
4. verifichi: `sha1sum` dell'ELF/PRX ricostruito **==** quello originale.

Gli hash target sono già in `checksums.sha1` (generato in fase di estrazione). La
verifica è binaria: o combacia o no. La percentuale di completamento del progetto =
quante funzioni sono "matched" sul totale.

## 5. Ordine di attacco consigliato

1. **`rel_movie_viewer.prx`** (26 KB) — il più piccolo, per rodare tutta la pipeline
   (split → m2c → mwccpsp → match → link → sha1) end-to-end su qualcosa di gestibile.
2. Altri moduli piccoli e isolati (`rel_html_view` 27 KB, `rel_soundtest` 32 KB,
   `rel_tutoriallist` 37 KB).
3. **`modehsys`** (l'EBOOT decifrato): l'engine condiviso — file system, EHP loader,
   grafica, input. Sblocca la comprensione di tutti gli `import libehsys_rel` dei moduli.
4. **`rel_duel_eng.prx`** (4,3 MB) — il motore delle regole. Enorme ma è il cuore del
   gioco; la logica delle carte è **hardcoded qui** (confermato dalla community: le
   carte non sono data-driven), quindi è ciò che più ripaga la decompilazione.

## 6. Tracciamento dei progressi

Convenzioni dei progetti decomp maturi, adottabili qui:

- **objdiff** (`encounter/objdiff`) o **frogress** per un cruscotto di avanzamento.
- una funzione è "OK" (matching) o "NONMATCHING" (equivalente ma non identica):
  spimdisasm marca le seconde con `nonmatching` nell'asm, utile come TODO list.
- niente asset o binari originali nel repo: solo `src/`, `asm/` (derivato, opzionale),
  `config/`, `tools/`, `docs/`. Vedi `.gitignore`.
