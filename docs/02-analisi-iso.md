# 02 — Analisi della ISO

Analisi effettuata su `Yu-Gi-Oh 5D's Tag Force 5 (E)(M5)(ZER0)/0-ygotf5.iso` (1.660.289.024 byte, ISO9660 UMD).

## Identificazione del gioco

| Campo | Valore |
|---|---|
| Titolo | Yu-Gi-Oh! 5D's Tag Force 5 |
| Disc ID | **ULES-01474** (Europa, multi-lingua E/F/G/I/S) |
| Publisher | Konami (2010) |
| APP_VER / DISC_VERSION | 01.00 / 1.01 |
| Firmware richiesto (`PSP_SYSTEM_VER`) | 6.31 |
| UMD_DATA.BIN | `ULES-01474\|9E0D979135AB4068\|0001\|G` |
| Data masterizzazione ISO | 2010-09-24 |
| CPU target | MIPS Allegrex (little-endian, ELF32) |

La versione USA equivalente è ULUS10555, quella giapponese NPJH50313/ULJM-05734 (utile saperlo per confrontare patch, cheat table e ricerche della community).

## Struttura della ISO

```
UMD_DATA.BIN                    # ID disco
PSP_GAME/
├── PARAM.SFO                   # metadati (titolo, disc id, fw)
├── ICON0.PNG
├── INSDIR/                     # 508 file FILE*.DAT (~17 KB l'uno) — dati "UMD install"
├── SYSDIR/
│   ├── EBOOT.BIN               # ★ eseguibile principale, CIFRATO (magic ~PSP)
│   ├── BOOT.BIN                # dummy: interamente azzerato (NON è l'ELF in chiaro)
│   ├── OPNSSMP.BIN             # modulo audio di boot
│   └── UPDATE/                 # updater firmware 6.31 (irrilevante per la decomp)
└── USRDIR/
    ├── gmodule/                # ★ 28 moduli di gioco .prx — ELF IN CHIARO
    ├── module/                 # moduli Sony standard (libfont, psmf, libpsmfplayer)
    ├── card/ database/ deck/ duel/ duelsys/ field/ ...   # asset di gioco
    ├── script/                 # story_scr_{b,e,f,g,i,s}.ehp — script della storia
    ├── shop/ title_menu/ tutorial/ help/ menu/ minigame/ labo/ main/
    ├── movie/                  # filmati .pmf
    └── snd/psp_snddat.bin      # archivio audio (151 MB)
```

Totale: 2.449 file, 51 cartelle. Gli asset con suffisso `_e/_f/_g/_i/_s` sono le 5 lingue (inglese, francese, tedesco, italiano, spagnolo); `_b` = ???  (probabilmente versione "base"/giapponese degli script).

## Fatti chiave per la decompilazione

### 1. EBOOT.BIN è cifrato, BOOT.BIN è un dummy

```
EBOOT.BIN: 7e 50 53 50 ...   → "~PSP", header cifrato, module name "modehsys"
BOOT.BIN : 00 00 00 00 ...   → 1.575.180 byte di zeri
```

Il modulo principale (`modehsys`) va quindi **decifrato** prima di poterlo analizzare:
o con `pspdecrypt` da riga di comando, o facendo dumpare a PPSSPP l'EBOOT decifrato
(vedi `04-estrazione-e-decrypt.md`).

### 2. I 28 moduli di gioco in gmodule/ sono ELF in chiaro

Ogni `.prx` in `USRDIR/gmodule/` è un **ELF32 MIPS rilocabile PSP** (e_type=0xFFA0), non
cifrato, analizzabile subito con Ghidra. Convenzione dei nomi: `rel_X.prx` → modulo
`modX`, esporta `libX_rel`, importa `libehsys_rel` dal modulo principale.

| Modulo | Dimensione | Contenuto presunto |
|---|---|---|
| `rel_duel_eng.prx` | 4,3 MB | ★ motore dei duelli (regole carte) — il cuore del gioco |
| `rel_field.prx` | 410 KB | overworld / mappa |
| `rel_title.prx` | 388 KB | schermata titolo |
| `rel_duel_draw.prx` | 669 KB | rendering dei duelli |
| `rel_deck.prx` / `rel_deckswap.prx` / `rel_decktutorial.prx` | 248/161/225 KB | editor deck |
| `rel_story.prx` | 222 KB | modalità storia |
| `rel_shop.prx` | 201 KB | negozio |
| `rel_cutin_viewer.prx` | 193 KB | cut-in dei personaggi |
| `rel_charalist.prx` | 172 KB | lista personaggi |
| `rel_duel_mgr.prx` | 165 KB | gestione duelli |
| `rel_select_card.prx` | 163 KB | selezione carte |
| **`rel_debug_menu.prx`** | 53 KB | **menu di debug lasciato nel gioco** |
| + altri 16 moduli minori | | album carte, password, gallery, soundtest, tutorial, html view, umd_replace, ecc. |

Strategia conseguente: si può partire dalla decomp dei moduli piccoli (es.
`rel_movie_viewer.prx`, 26 KB) **senza nemmeno decifrare l'EBOOT**, per poi
affrontare `modehsys` (engine condiviso: grafica, file system, EHP, input...).

### 3. Compilatore originale identificato: Metrowerks CodeWarrior

La sezione `.comment` di **tutti e 28** i PRX riporta:

```
MW MIPS C Compiler (2.4.1.01)
PSP
```

→ Il gioco è compilato con **Metrowerks CodeWarrior for PSP, MWCC 2.4.1.01**
(su decomp.me la famiglia è `mwccpsp`). Questo determina l'intera toolchain di
matching: serve mwccpsp (gira via WINE/wibo), non psp-gcc. I binari sono stripped
(nessun `.symtab`, nessuna stringa di mangling C++ visibile, niente assert di debug).

### 4. Engine "ehsys" condiviso della serie

Il modulo principale si chiama `modehsys` e esporta `libehsys_rel`; gli archivi asset
usano l'estensione `.ehp` (verosimilmente "EH package"). Lo stesso engine è usato
dagli altri Tag Force → tool e conoscenze della community Tag Force (unpacker EHP,
editor testi) sono riusabili, e viceversa quello che decompiliamo qui vale per
mezza serie.

## Hash di riferimento

```
md5(EBOOT.BIN cifrato)  = 9168f5461e5786e096dc403839f03607
md5(BOOT.BIN dummy)     = e05bd8e057c1976f82d5268355df8b7c
```

(Gli hash dell'ELF decifrato andranno registrati in `04-estrazione-e-decrypt.md`
appena prodotto, perché saranno il target di verifica della build matching.)
