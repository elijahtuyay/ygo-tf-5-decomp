---
name: tf5-formati
description: >
  Riferimento sui formati file di Yu-Gi-Oh! Tag Force 5 e sui tool della community per
  aprirli: archivi .ehp (EhFolder), .cip/.cpm (artwork carte, DXT1), immagini .gim,
  modelli .gmo/.tms/.tmt, database carte (CARD_*.bin + Huffman/DICT), tabelle stringhe,
  deck .ydc, audio psp_snddat.bin, filmati .pmf. Attiva quando si estraggono, si
  ispezionano o si documentano asset del gioco, o si cerca il tool giusto per un
  formato. Trigger: "ehp", "cip", "gim", "gmo", "tms", "carta"/"card database",
  "psp_snddat", "ydc", "pmf", "asset", "texture", "estrarre file di gioco".
---

# Formati file di Tag Force 5

Lo stesso engine (`ehsys`) è condiviso tra i Tag Force → i tool della community
(quasi tutti di **xan1242**) spesso funzionano cross-game. **Ma** sono testati per lo
più su TF1/TF6: su TF5 vanno riverificati sui file reali. Non committare tool né asset
nel repo (gitignored); installali in `tools/`.

## Mappa formato → tool
| Formato | Dove | Tool | Note |
|---|---|---|---|
| `.ehp` (EhFolder) | ovunque + **embedded in EBOOT** | ehppack; EHPScanner (per EBOOT) | contenitore asset principale |
| `.cip`/`.cpm` | artwork carte | CIPTool | immagini **DXT1** |
| `.gim` | texture | GIMConv / TextER | formato Sony generico |
| `.gmo` | modelli 3D | (generico PSP) | magic `OMG..1PSP` |
| `.tms`/`.tmt` | modelli/anim TF | Noesis `fmt_tms.py` (parziale) | **RE incompleto** |
| `CARD_Name/Desc/Huff/Indx.bin`, `DICT.bin` | database carte (in `cardinfo_*.ehp`) | ogy; TFCardEdit(GUI) | desc **Huffman+dizionario**; tetto ~877 KB |
| tabelle stringhe/testi | `story_scr_*.ehp` ecc. | tagforcestring | UTF-8/UTF-16LE/Shift-JIS |
| `.ydc` deck | in EBOOT | Deck Converter (↔.ydk) | header 8 byte, magic `01 FC` |
| `psp_snddat.bin` | `USRDIR/snd/` (151 MB) | TFSndEdit | codec prob. **VAG/ADPCM**; repack usa header SHDS da EBOOT |
| `.pmf` | `USRDIR/movie/` | PSMF (Sony) | M2V+Atrac3; `libpsmfplayer.prx` |
| `INSDIR/FILE*.DAT` | 508 file ~17KB | — | dati "install su Memory Stick", bassa priorità |

## Repo dei tool (riferimento, terze parti)
- ehppack https://github.com/xan1242/ehppack · EHPScanner https://github.com/xan1242/EHPScanner
- CIPTool https://github.com/xan1242/CIPTool · tagforcestring https://github.com/xan1242/tagforcestring
- TFCardEditGUI https://github.com/xan1242/TFCardEditGUI · TFSndEdit https://github.com/xan1242/TFSndEdit
- **TFRandomizer** https://github.com/xan1242/TFRandomizer — **testato su TF5** (US box offset `0x23090`, 60 box)
- ogy https://github.com/exsilium/ogy · Deck Converter https://github.com/SyrusKyury/Yu-Gi-Oh-Tag-Force-Deck-Converter
- EHP Suite (web) https://syruskyury.github.io/ehp_suite/

## Fatto chiave per la decomp
Gli **effetti delle carte NON sono nei dati**: sono **hardcoded nell'engine**
(`rel_duel_eng.prx`). Editare i `CARD_*.bin` cambia nomi/statistiche ma non il
comportamento. Capire/aggiungere regole = decompilare il codice del duello. È il
motivo per cui questo progetto ha valore oltre il modding di asset esistente.

Dettagli completi: `docs/07-formati-file.md`. Community/link: `docs/08-risorse.md`.
