# 02 — ISO analysis

Analysis performed on `Yu-Gi-Oh 5D's Tag Force 5 (E)(M5)(ZER0)/0-ygotf5.iso` (1,660,289,024 bytes, ISO9660 UMD).

## Game identification

| Field | Value |
|---|---|
| Title | Yu-Gi-Oh! 5D's Tag Force 5 |
| Disc ID | **ULES-01474** (Europe, multi-language E/F/G/I/S) |
| Publisher | Konami (2010) |
| APP_VER / DISC_VERSION | 01.00 / 1.01 |
| Required firmware (`PSP_SYSTEM_VER`) | 6.31 |
| UMD_DATA.BIN | `ULES-01474\|9E0D979135AB4068\|0001\|G` |
| ISO mastering date | 2010-09-24 |
| Target CPU | MIPS Allegrex (little-endian, ELF32) |

The equivalent US version is ULUS10555, and the Japanese one is
NPJH50313/ULJM-05734 (useful to know when comparing patches, cheat tables, and
community research).

## ISO structure

```
UMD_DATA.BIN                    # disc ID
PSP_GAME/
├── PARAM.SFO                   # metadata (title, disc id, fw)
├── ICON0.PNG
├── INSDIR/                     # 508 FILE*.DAT files (~17 KB each) — "UMD install" data
├── SYSDIR/
│   ├── EBOOT.BIN               # ★ main executable, ENCRYPTED (magic ~PSP)
│   ├── BOOT.BIN                # dummy: entirely zeroed out (NOT the plaintext ELF)
│   ├── OPNSSMP.BIN             # boot audio module
│   └── UPDATE/                 # firmware 6.31 updater (irrelevant for the decomp)
└── USRDIR/
    ├── gmodule/                # ★ 28 game .prx modules — PLAINTEXT ELF
    ├── module/                 # standard Sony modules (libfont, psmf, libpsmfplayer)
    ├── card/ database/ deck/ duel/ duelsys/ field/ ...   # game assets
    ├── script/                 # story_scr_{b,e,f,g,i,s}.ehp — story script
    ├── shop/ title_menu/ tutorial/ help/ menu/ minigame/ labo/ main/
    ├── movie/                  # .pmf videos
    └── snd/psp_snddat.bin      # audio archive (151 MB)
```

Total: 2,449 files, 51 folders. Assets with the `_e/_f/_g/_i/_s` suffix are the 5
languages (English, French, German, Italian, Spanish); `_b` = ??? (probably the
"base"/Japanese version of the scripts).

## Key facts for the decompilation

### 1. EBOOT.BIN is encrypted, BOOT.BIN is a dummy

```
EBOOT.BIN: 7e 50 53 50 ...   → "~PSP", encrypted header, module name "modehsys"
BOOT.BIN : 00 00 00 00 ...   → 1,575,180 bytes of zeros
```

The main module (`modehsys`) therefore needs to be **decrypted** before it can be
analyzed: either with `pspdecrypt` from the command line, or by having PPSSPP dump
the decrypted EBOOT (see `04-extraction-and-decryption.md`).

### 2. The 28 game modules in gmodule/ are plaintext ELF

Each `.prx` in `USRDIR/gmodule/` is a **relocatable MIPS PSP ELF32** (e_type=0xFFA0),
unencrypted, ready to analyze immediately with Ghidra. Naming convention: `rel_X.prx`
→ module `modX`, exports `libX_rel`, imports `libehsys_rel` from the main module.

| Module | Size | Presumed content |
|---|---|---|
| `rel_duel_eng.prx` | 4.3 MB | ★ duel engine (card rules) — the heart of the game |
| `rel_field.prx` | 410 KB | overworld / map |
| `rel_title.prx` | 388 KB | title screen |
| `rel_duel_draw.prx` | 669 KB | duel rendering |
| `rel_deck.prx` / `rel_deckswap.prx` / `rel_decktutorial.prx` | 248/161/225 KB | deck editor |
| `rel_story.prx` | 222 KB | story mode |
| `rel_shop.prx` | 201 KB | shop |
| `rel_cutin_viewer.prx` | 193 KB | character cut-ins |
| `rel_charalist.prx` | 172 KB | character list |
| `rel_duel_mgr.prx` | 165 KB | duel management |
| `rel_select_card.prx` | 163 KB | card selection |
| **`rel_debug_menu.prx`** | 53 KB | **debug menu left in the game** |
| + 16 other minor modules | | card album, passwords, gallery, sound test, tutorial, html view, umd_replace, etc. |

Resulting strategy: work can start on the decomp of the small modules (e.g.
`rel_movie_viewer.prx`, 26 KB) **without even decrypting the EBOOT**, before tackling
`modehsys` (shared engine: graphics, file system, EHP, input...).

### 3. Original compiler identified: Metrowerks CodeWarrior

The `.comment` section of **all 28** PRX files reports:

```
MW MIPS C Compiler (2.4.1.01)
PSP
```

→ The game is compiled with **Metrowerks CodeWarrior for PSP, MWCC 2.4.1.01** (on
decomp.me the family is `mwccpsp`). This determines the entire matching toolchain:
mwccpsp is required (runs via WINE/wibo), not psp-gcc. The binaries are stripped (no
`.symtab`, no visible C++ mangled strings, no debug asserts).

### 4. Shared "ehsys" engine of the series

The main module is called `modehsys` and exports `libehsys_rel`; the asset archives
use the `.ehp` extension (presumably "EH package"). The same engine is used by the
other Tag Force games → tools and knowledge from the Tag Force community (EHP
unpacker, text editor) are reusable, and vice versa: what we decompile here applies
to half the series.

## Reference hashes

```
md5(encrypted EBOOT.BIN)  = 9168f5461e5786e096dc403839f03607
md5(dummy BOOT.BIN)       = e05bd8e057c1976f82d5268355df8b7c
```

(The hashes of the decrypted ELF will be recorded in
`04-extraction-and-decryption.md` once produced, since they will be the verification
target for the matching build.)
