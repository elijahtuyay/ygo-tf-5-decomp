# 09 — Il primo match (tutorial pratico)

Guida passo-passo per portare a **100% di match** la tua prima funzione, usando
[decomp.me](https://decomp.me) (nessuna toolchain da montare in locale). Lavoriamo sul
modulo più piccolo, `rel_movie_viewer.prx`.

Ricorda il concetto di fondo (vedi `06-splat-e-matching.md`): l'obiettivo non è scrivere
C "che fa la stessa cosa", ma C che **ricompilato con mwccpsp produca gli stessi byte**
dell'originale. decomp.me confronta i due assembly e ti dà una percentuale in tempo reale.

## Prerequisiti

- Un account su https://decomp.me (login con GitHub).
- L'assembly **target** (= quello originale) della funzione. Per le due funzioni di
  questo tutorial te lo do già qui sotto; per una funzione qualsiasi vedi l'ultima
  sezione ("Generare l'asm di una funzione").

---

## Passo 1 — La funzione vuota (verifica il setup)

Nel `.text` di `rel_movie_viewer` ci sono due funzioni **completamente vuote** a `0x1C0`
e `0x6B4` (sono callback no-op registrate dal modulo, es. un handler di stop). Sono il
"hello world" ideale: se non ottieni 100% con una funzione vuota, il problema è il
**compilatore/flag**, non il tuo C. Isola una variabile per volta.

**Assembly target** (funzione `func_000001C0`) — output verbatim di splat:

```mips
glabel func_000001C0
    /* 214 000001C0 0800E003 */  jr    $ra
    /* 218 000001C4 00000000 */   nop
```

I commenti `/* … */` (offset file, indirizzo, byte) sono ignorati da decomp.me: puoi
incollarli o toglierli. Nota: nell'asm generato la funzione è preceduta dalla riga
`nonmatching func_000001C0, 0x8` — è solo un **marcatore "da fare"** di spimdisasm, non
un errore.

**Procedura su decomp.me:**

1. Vai su https://decomp.me → **New scratch**.
2. **Platform**: `PSP`. **Compiler**: `mwccpsp` (scegli una build qualsiasi, es. la più
   recente disponibile — es. `3.0.1_219`).
3. Nel riquadro **Target assembly** incolla le due righe qui sopra.
4. Nel riquadro **Source** (C) scrivi:

   ```c
   void func_000001C0(void) {
   }
   ```

5. Premi **Compile**. La percentuale in alto deve essere **100%** (match). ✅

Se **non** è 100% su una funzione vuota: cambia build di mwccpsp, o togli/aggiungi
`-O` nei *Compiler flags*. Quando la funzione vuota matcha, il tuo ambiente è a posto.

> Questo passo è anche un **test diagnostico** del compilatore: vedi la sezione
> "L'incognita del compilatore" più sotto.

---

## Passo 2 — Una funzione con logica vera (`func_00000184`)

Ora qualcosa di reale. La funzione a `0x184` legge un puntatore globale, e se non è
nullo lo "libera" e lo azzera.

**Assembly target** (dall'output di splat; i nomi `D_0009DB00`/`func_00000CEC` sono
segnaposto a piacere — splat di default lo chiama `D_9DB00`):

```mips
glabel func_00000184
    /* 1D8 00000184 F0FFBD27 */  addiu  $sp, $sp, -0x10
    /* 1DC 00000188 0C00BFAF */  sw     $ra, 0xC($sp)
    /* 1E0 0000018C 0800B0AF */  sw     $s0, 0x8($sp)
    /* 1E4 00000190 0A00033C */  lui    $v1, %hi(D_0009DB00)
    /* 1E8 00000194 00DB638C */  lw     $v1, %lo(D_0009DB00)($v1)
    /* 1EC 00000198 0A00103C */  lui    $s0, %hi(D_0009DB00)
    /* 1F0 0000019C 04006010 */  beqz   $v1, .L000001B0
    /* 1F4 000001A0 00DB1026 */   addiu $s0, $s0, %lo(D_0009DB00)
    /* 1F8 000001A4 3B03000C */  jal    func_00000CEC
    /* 1FC 000001A8 0000048E */   lw    $a0, 0x0($s0)
    /* 200 000001AC 000000AE */  sw     $zero, 0x0($s0)
  .L000001B0:
    /* 204 000001B0 0C00BF8F */  lw     $ra, 0xC($sp)
    /* 208 000001B4 0800B08F */  lw     $s0, 0x8($sp)
    /* 20C 000001B8 0800E003 */  jr     $ra
    /* 210 000001BC 1000BD27 */   addiu $sp, $sp, 0x10
```

Qui entrano in gioco due **simboli con rilocazione** (verificati nella `.rel.text`):
`D_0009DB00` è un global del modulo (rilocazioni `R_MIPS_HI16/LO16`, indirizzo
0x9DB00) e `func_00000CEC` è la funzione chiamata dalla `jal` (`R_MIPS_26`). Su
decomp.me vanno **dichiarati nel contesto** (riquadro *Context*) perché l'asm assembli,
per esempio:

```c
extern int D_0009DB00;
void func_00000CEC(int);
```

**Bozza C** (generata con `m2c`, da rifinire — NON è detto che matchi così com'è):

```c
void func_00000184(void) {
    if (D_0009DB00 != 0) {
        func_00000CEC(D_0009DB00);
        D_0009DB00 = 0;
    }
}
```

**Come procedere:**

1. Nuovo scratch (stessa Platform/Compiler del Passo 1).
2. Incolla l'asm target e la bozza C.
3. Compila e guarda il **diff affiancato**: a sinistra il target, a destra il tuo.
   Le righe evidenziate sono le differenze.
4. Aggiusta il C finché il diff è vuoto (100%). Cose che spesso spostano il match:
   - livello di ottimizzazione nei *Compiler flags* (`-O4,p` ecc. per mwcc);
   - il **tipo** del globale (`int`, `void*`, una struct…): cambia le istruzioni di load;
   - l'ordine delle operazioni;
   - se `func_00000CEC` restituisce qualcosa o no.

Non serve conoscere i nomi veri: `func_00000184`, `D_0009DB00`, `func_00000CEC` sono
segnaposto. Li rinominerai quando avrai capito a cosa servono (Ghidra aiuta qui).

---

## Come leggere il match

- **100%**: byte identici → funzione "matched". Fatto.
- **<100%**: decomp.me evidenzia le istruzioni diverse. Spesso è UNA differenza
  (un load `lw` vs `lhu`, un registro diverso, un branch invertito) che rivela il
  tipo di un dato o un flag di compilazione sbagliato.
- Se sei bloccato su una manciata di istruzioni, esiste **decomp-permuter**
  (`tools/decomp-permuter/`) che prova automaticamente varianti equivalenti del C.

## L'incognita del compilatore (importante)

I binari di TF5 riportano `MW MIPS C Compiler (2.4.1.01)` (sezione `.comment`), mentre
decomp.me ospita build etichettate `mwccpsp 3.0.1_NNN`. Due possibilità:

- La funzione **vuota** matcherà con quasi ogni build (non discrimina).
- Su funzioni reali, se **nessuna** build di decomp.me arriva al 100% pur avendo il C
  giusto, è il segnale che ci serve la **build esatta** di CodeWarrior usata da Konami,
  non presente su decomp.me. In tal caso la si procura a parte (immagini di
  https://github.com/decompme/compilers `platforms/psp/`, o la CodeWarrior originale) e
  si passa al match in locale con **wibo + mwccpsp** (vedi `03-strumenti.md`).

Quindi il Passo 2 è anche l'esperimento che ci dice **quanto è vicino** l'ambiente
pubblico al nostro. Annota qui l'esito quando lo scopri:

> ⏳ *Esito bisezione build mwccpsp: (da compilare — quale build/flag matcha le funzioni
> reali di TF5?)*

## Quando una funzione è "fatta"

1. 100% su decomp.me.
2. Salva lo scratch (decomp.me dà un URL) e/o riporta il C in `src/` del progetto.
3. Segna la funzione come completata (in futuro: tracciamento con frogress/objdiff).

## Generare l'asm di una funzione qualsiasi

L'asm target lo produce **splat** dal PRX estratto (vedi `06-splat-e-matching.md`):

```bash
. .venv/bin/activate
splat split config/rel_movie_viewer.example.yaml   # crea asm/…  (rigenerato, non versionato)
```

In `asm/` trovi un file per funzione, nel formato che spimdisasm/decomp.me capiscono
(etichette `glabel`, rilocazioni `%hi/%lo`). Copi la funzione che ti interessa e la
incolli su decomp.me. In alternativa, per un colpo d'occhio veloce, Ghidra mostra
l'assembly nel *Listing* (finestra a sinistra del decompilatore).

---

## Ordine consigliato per fare pratica

1. `func_000001C0` (vuota) — verifica setup. ✅
2. `func_00000184` (libera-e-azzera) — prima logica vera.
3. Le altre funzioni piccole di `rel_movie_viewer` (`readelf`/splat ne elenca ~14 nel
   `.text`), dalle più corte alle più lunghe.
4. Poi si passa agli altri moduli piccoli e, infine, a `modehsys`/`rel_duel_eng`.
