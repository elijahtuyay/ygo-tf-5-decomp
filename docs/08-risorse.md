# 08 — Risorse, community e riferimenti

Raccolta di link verificati utili al progetto. Le date/versioni sono al luglio 2026.

## Progetto di riferimento assoluto: sotn-decomp

**Xeeynamo/sotn-decomp** — https://github.com/Xeeynamo/sotn-decomp — Castlevania:
Symphony of the Night. È **l'unica decomp matching con un target PSP funzionante**
(`pspeu`, estratto da *Dracula X Chronicles*). Da studiare come modello: fa
esattamente ciò che vogliamo fare noi.

- Build: `make` + `CMakeLists.txt`; target `extract_pspeu`, `build_pspeu`.
- Compilatore PSP: **mwccpsp build 219** eseguito via **wibo**.
- Usa **splat** con una config YAML per overlay (`config/splat.pspeu.*.yaml`).
- Verifica match: `config/check.pspeu.sha` (un SHA-1 per output).
- Struttura: `config/ src/ include/ tools/ bin/ disks/ docs/ cmake/ Makefile`.
- Progressi: **frogress** (https://progress.deco.mp), dashboard https://sotn.xee.dev/.
- Wiki con pagine "Decompilation (PSP edition)" e "PSP overlay header raw notes".

> Nessuna decomp di alcun Tag Force è mai esistita: saremmo i primi. sotn-decomp è il
> "template" di processo; l'ecosistema Tag Force (sotto) fornisce la conoscenza degli
> asset.

## Toolchain PSP / decomp

| Strumento | URL | A cosa serve |
|---|---|---|
| ghidra-allegrex | https://github.com/kotcrab/ghidra-allegrex | processore Allegrex+VFPU per Ghidra |
| psp-ghidra-scripts | https://github.com/pspdev/psp-ghidra-scripts | script NID/import per Ghidra |
| splat | https://github.com/ethteck/splat | split del binario (piattaforma `psp`) |
| spimdisasm / rabbitizer | (pip, deps di splat) | disassembly MIPS Allegrex |
| m2c | https://github.com/matt-kempster/m2c | asm MIPS → bozza C |
| asm-differ | https://github.com/simonlindholm/asm-differ | diff asm target vs build |
| objdiff | https://github.com/encounter/objdiff | diff a oggetti, MIPS PSP + demangle MWCC |
| decomp-permuter | https://github.com/simonlindholm/decomp-permuter | permutazioni per trovare il match |
| wibo | https://github.com/decompals/wibo | esegue mwccpsp.exe su Linux (no WINE) |
| decompme/compilers | https://github.com/decompme/compilers | immagini compilatori (`platforms/psp/`) |
| pspdecrypt | https://github.com/John-K/pspdecrypt | decifra EBOOT (~PSP) |
| prxtool / pspdev | https://github.com/pspdev/pspdev | psp-gcc, psp-objdump, prxtool, NID |
| uofw | https://github.com/uofw/uofw | firmware RE: database NID con nomi/firme |
| PPSSPP | https://github.com/hrydgard/ppsspp | emulatore + debugger/disasm/memory/GE |
| frogress | https://github.com/decompals/frogress | tracciamento avanzamento |
| kotcrab/mist | https://github.com/kotcrab/mist | toolkit Allegrex (disasm/symbolic/recompile) |

## decomp.me

https://decomp.me — editor online per matchare funzioni. Supporta PSP come piattaforma
con le famiglie **mwccpsp** (11 build, `3.0.1_121…219`), **pspsnc** (SN Systems), e
**psp-gcc**. È il modo più rapido per iniziare a matchare senza montare la toolchain
locale. Preset da usare: PSP + `mwccpsp` (poi bisezione della build, vedi doc 06).

## Documentazione di formato (PSP)

- Formato PRX: https://www.psdevwiki.com/psp/PRX_File_Format
- "yapspd" (CPU/VFPU, file format PRX/PBP):
  https://hitmen.c02.at/files/yapspd/psp_doc/chap4.html e `.../chap26.html`
- VFPU: https://pspdev.github.io/vfpu-docs/
- NID cracking (perché i NID sono 4 byte di SHA-1): https://blog.paulsajna.com/nid-cracking/
- Memory map PSP: https://github.com/uofw/upspd/wiki/Memory-map
- SN Systems ProDG (fingerprint compilatore): https://www.retroreversing.com/sn-systems-pro-dg-psp-sdk
- Architettura PSP (panoramica): https://www.copetti.org/writings/consoles/playstation-portable/

## Guide per iniziare una decomp PSP

- **PSP Reverse Engineering HQ**: https://psp-re.github.io/ e
  https://psp-re.github.io/quickstart/ (decrypt → Ghidra+allegrex → NID → tipi).
- **uofw RE tutorial**: https://github.com/uofw/uofw/wiki/Reverse-Engineering-Tutorial
- **sotn-decomp wiki** (Build / Decompilation / PSP edition):
  https://github.com/Xeeynamo/sotn-decomp/wiki

## Ecosistema modding Tag Force (asset/formati)

Autore principale dei tool: **xan1242**.

| Tool | URL | Formato |
|---|---|---|
| ehppack | https://github.com/xan1242/ehppack | archivi `.ehp` (unpack/repack) |
| EHPScanner | https://github.com/xan1242/EHPScanner | EHP embedded nell'EBOOT |
| CIPTool | https://github.com/xan1242/CIPTool | `.cip`/`.cpm` artwork carte (DXT1) |
| tagforcestring | https://github.com/xan1242/tagforcestring | tabelle stringhe/testi |
| TFCardEdit(GUI) | https://github.com/xan1242/TFCardEditGUI | database carte |
| TFSndEdit | https://github.com/xan1242/TFSndEdit | `psp_snddat.bin` audio |
| **TFRandomizer** | https://github.com/xan1242/TFRandomizer | **testato su TF5** (box/recipe) |
| ogy | https://github.com/exsilium/ogy | testi carte (Huffman+dizionario) |
| Deck Converter | https://github.com/SyrusKyury/Yu-Gi-Oh-Tag-Force-Deck-Converter | `.ydc`↔`.ydk` |
| EHP Suite (web) | https://syruskyury.github.io/ehp_suite/ | EHP nel browser |
| YGTool | https://github.com/matheuscardoso96/YGTool | formati Yu-Gi-Oh PSP/NDS |
| Noesis `fmt_tms.py` | vedi thread ResHax sotto | modelli `.tms` (parziale) |

Dettagli sui formati: `07-formati-file.md`.

## Community

- **Discord "Yu-Gi-Oh! Tag Force: Modding Community"**: invito `discord.gg/E5vK4eRJ`
  (Disboard: https://disboard.org/server/1105525843905753138). Modder di riferimento:
  chrisfand, omarrrio.
- **PSP Homebrew Discord** (RE generale): https://discord.gg/bePrj9W
- GBAtemp — archivi EHP/CIP: https://gbatemp.net/threads/archives-ehp-cip-in-yu-gi-oh-tag-force-games.310162/
- PPSSPP forum — TF5 EU (ULES-01474): https://forums.ppsspp.org/showthread.php?tid=17344
- PPSSPP forum — TF5 US (ULUS-10555): https://forums.ppsspp.org/showthread.php?tid=7302
- ResHax — modelli TMS/TMT: https://reshax.com/topic/1858-psp-yu-gi-oh-tag-force-model-format-tmstmt-help/

## Mappe RAM / CWCheat (indirizzi "caldi" per il RE)

Nessuna pagina gamehacking.org dedicata a TF5; i codici circolano su siti cheat.

- **TF5 US (ULUS-10555)** — https://almarsguides.com/retro/walkthroughs/PSP/Games/YuGiOh5DsTagForce5/CWCheat/USA/
  - `All Cards`/`No Card Bans`: coppia `0x80338CD4` / `0x80338CD2` (opcode `0x12CA0002`
    vs `0x12CA0004`) → suggerisce **una singola funzione di controllo legalità carte**.
  - `Max DP`: `0x40335874`; `Partner Control` (funzionante in emu): `0x01637A48`.
  - `BoxInfoOffset` (da TFRandomizer): **0x23090**, 60 box negozio.
- **TF5 EU (ULES-01474)** — https://forums.ppsspp.org/showthread.php?tid=17344 :
  codici per DP/LP, instant win, no banlist, all BGM/cards/NPC/video, edit deck
  partner, Exodia. Indirizzo citato: `0x0000D2E4`.
  CWCheat EU di omarrrio: https://yu-gi-oh-compilation.forumactif.org/t4052

> Questi indirizzi sono per le build US/EU **in RAM**; vanno mappati agli offset del
> nostro ELF EU decifrato, ma indicano già dove guardare (legalità carte, valuta DP,
> tabelle box/recipe).

## Note sulle incognite (onestà intellettuale)

- **Build esatta di mwccpsp**: la `.comment` dice `2.4.1.01`; le build su decomp.me
  sono `3.0.1_NNN`. Va verificato quale (se alcuna) matcha — è il rischio principale
  del progetto (vedi doc 06).
- **Codec audio** di `psp_snddat.bin`: probabile VAG/ADPCM (non confermato AT3).
- **Formato `.tms/.tmt`**: reverse engineering incompleto in community.
- Molti tool Tag Force sono testati su TF1/TF6: su TF5 vanno riconfermati sui file.
