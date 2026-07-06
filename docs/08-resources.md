# 08 — Resources, community, and references

A collection of verified links useful to the project. Dates/versions are as of
July 2026.

## Absolute reference project: sotn-decomp

**Xeeynamo/sotn-decomp** — https://github.com/Xeeynamo/sotn-decomp — Castlevania:
Symphony of the Night. It's **the only matching decomp with a working PSP target**
(`pspeu`, extracted from *Dracula X Chronicles*). Worth studying as a model: it does
exactly what we want to do.

- Build: `make` + `CMakeLists.txt`; targets `extract_pspeu`, `build_pspeu`.
- PSP compiler: **mwccpsp build 219** run via **wibo**.
- Uses **splat** with a YAML config for overlays (`config/splat.pspeu.*.yaml`).
- Match verification: `config/check.pspeu.sha` (one SHA-1 per output).
- Structure: `config/ src/ include/ tools/ bin/ disks/ docs/ cmake/ Makefile`.
- Progress: **frogress** (https://progress.deco.mp), dashboard https://sotn.xee.dev/.
- Wiki with "Decompilation (PSP edition)" and "PSP overlay header raw notes" pages.

> No decomp of any Tag Force game has ever existed: we'd be the first. sotn-decomp is
> the process "template"; the Tag Force ecosystem (below) provides the asset
> knowledge.

## PSP toolchain / decomp

| Tool | URL | What it's for |
|---|---|---|
| ghidra-allegrex | https://github.com/kotcrab/ghidra-allegrex | Allegrex+VFPU processor for Ghidra |
| psp-ghidra-scripts | https://github.com/pspdev/psp-ghidra-scripts | NID/import scripts for Ghidra |
| splat | https://github.com/ethteck/splat | binary splitting (`psp` platform) |
| spimdisasm / rabbitizer | (pip, splat deps) | MIPS Allegrex disassembly |
| m2c | https://github.com/matt-kempster/m2c | MIPS asm → C draft |
| asm-differ | https://github.com/simonlindholm/asm-differ | target vs build asm diff |
| objdiff | https://github.com/encounter/objdiff | object diffing, MIPS PSP + MWCC demangling |
| decomp-permuter | https://github.com/simonlindholm/decomp-permuter | permutations to find the match |
| wibo | https://github.com/decompals/wibo | runs mwccpsp.exe on Linux (no WINE) |
| decompme/compilers | https://github.com/decompme/compilers | compiler images (`platforms/psp/`) |
| pspdecrypt | https://github.com/John-K/pspdecrypt | decrypts EBOOT (~PSP) |
| prxtool / pspdev | https://github.com/pspdev/pspdev | psp-gcc, psp-objdump, prxtool, NID |
| uofw | https://github.com/uofw/uofw | firmware RE: NID database with names/signatures |
| PPSSPP | https://github.com/hrydgard/ppsspp | emulator + debugger/disasm/memory/GE |
| frogress | https://github.com/decompals/frogress | progress tracking |
| kotcrab/mist | https://github.com/kotcrab/mist | Allegrex toolkit (disasm/symbolic/recompile) |

## decomp.me

https://decomp.me — online editor for matching functions. Supports PSP as a
platform with the **mwccpsp** family (11 builds, `3.0.1_121…219`), **pspsnc** (SN
Systems), and **psp-gcc**. It's the fastest way to start matching without setting
up a local toolchain. Preset to use: PSP + `mwccpsp` (then bisect the build, see
doc 06).

## Format documentation (PSP)

- PRX format: https://www.psdevwiki.com/psp/PRX_File_Format
- "yapspd" (CPU/VFPU, PRX/PBP file format):
  https://hitmen.c02.at/files/yapspd/psp_doc/chap4.html and `.../chap26.html`
- VFPU: https://pspdev.github.io/vfpu-docs/
- NID cracking (why NIDs are 4 bytes of SHA-1): https://blog.paulsajna.com/nid-cracking/
- PSP memory map: https://github.com/uofw/upspd/wiki/Memory-map
- SN Systems ProDG (compiler fingerprint): https://www.retroreversing.com/sn-systems-pro-dg-psp-sdk
- PSP architecture (overview): https://www.copetti.org/writings/consoles/playstation-portable/

## Guides for starting a PSP decomp

- **PSP Reverse Engineering HQ**: https://psp-re.github.io/ and
  https://psp-re.github.io/quickstart/ (decrypt → Ghidra+allegrex → NID → types).
- **uofw RE tutorial**: https://github.com/uofw/uofw/wiki/Reverse-Engineering-Tutorial
- **sotn-decomp wiki** (Build / Decompilation / PSP edition):
  https://github.com/Xeeynamo/sotn-decomp/wiki

## Tag Force modding ecosystem (assets/formats)

Main tool author: **xan1242**.

| Tool | URL | Format |
|---|---|---|
| ehppack | https://github.com/xan1242/ehppack | `.ehp` archives (unpack/repack) |
| EHPScanner | https://github.com/xan1242/EHPScanner | EHP embedded in the EBOOT |
| CIPTool | https://github.com/xan1242/CIPTool | `.cip`/`.cpm` card artwork (DXT1) |
| tagforcestring | https://github.com/xan1242/tagforcestring | string/text tables |
| TFCardEdit(GUI) | https://github.com/xan1242/TFCardEditGUI | card database |
| TFSndEdit | https://github.com/xan1242/TFSndEdit | `psp_snddat.bin` audio |
| **TFRandomizer** | https://github.com/xan1242/TFRandomizer | **tested on TF5** (boxes/recipes) |
| ogy | https://github.com/exsilium/ogy | card text (Huffman+dictionary) |
| Deck Converter | https://github.com/SyrusKyury/Yu-Gi-Oh-Tag-Force-Deck-Converter | `.ydc`↔`.ydk` |
| EHP Suite (web) | https://syruskyury.github.io/ehp_suite/ | EHP in the browser |
| YGTool | https://github.com/matheuscardoso96/YGTool | Yu-Gi-Oh PSP/NDS formats |
| Noesis `fmt_tms.py` | see ResHax thread below | `.tms` models (partial) |

Format details: `07-file-formats.md`.

## Community

- **Discord "Yu-Gi-Oh! Tag Force: Modding Community"**: invite `discord.gg/E5vK4eRJ`
  (Disboard: https://disboard.org/server/1105525843905753138). Notable modders:
  chrisfand, omarrrio.
- **PSP Homebrew Discord** (general RE): https://discord.gg/bePrj9W
- GBAtemp — EHP/CIP archives: https://gbatemp.net/threads/archives-ehp-cip-in-yu-gi-oh-tag-force-games.310162/
- PPSSPP forum — TF5 EU (ULES-01474): https://forums.ppsspp.org/showthread.php?tid=17344
- PPSSPP forum — TF5 US (ULUS-10555): https://forums.ppsspp.org/showthread.php?tid=7302
- ResHax — TMS/TMT models: https://reshax.com/topic/1858-psp-yu-gi-oh-tag-force-model-format-tmstmt-help/

## RAM maps / CWCheat ("hot" addresses for RE)

No dedicated gamehacking.org page for TF5; codes circulate on cheat sites.

- **TF5 US (ULUS-10555)** — https://almarsguides.com/retro/walkthroughs/PSP/Games/YuGiOh5DsTagForce5/CWCheat/USA/
  - `All Cards`/`No Card Bans`: pair `0x80338CD4` / `0x80338CD2` (opcode `0x12CA0002`
    vs `0x12CA0004`) → suggests **a single card legality check function**.
  - `Max DP`: `0x40335874`; `Partner Control` (working in emu): `0x01637A48`.
  - `BoxInfoOffset` (from TFRandomizer): **0x23090**, 60 shop boxes.
- **TF5 EU (ULES-01474)** — https://forums.ppsspp.org/showthread.php?tid=17344 :
  codes for DP/LP, instant win, no banlist, all BGM/cards/NPC/video, edit partner
  deck, Exodia. Address cited: `0x0000D2E4`.
  omarrrio's EU CWCheat: https://yu-gi-oh-compilation.forumactif.org/t4052

> These addresses are for the US/EU builds **in RAM**; they need to be mapped to
> the offsets of our decrypted EU ELF, but they already indicate where to look
> (card legality, DP currency, box/recipe tables).

## Notes on unknowns (intellectual honesty)

- **Exact mwccpsp build**: the `.comment` section says `2.4.1.01`; the builds on
  decomp.me are `3.0.1_NNN`. It still needs to be verified which one (if any)
  matches — this is the project's main risk (see doc 06).
- **Audio codec** of `psp_snddat.bin`: likely VAG/ADPCM (AT3 not confirmed).
- **`.tms/.tmt` format**: reverse engineering incomplete in the community.
- Many Tag Force tools are tested on TF1/TF6: on TF5 they need to be reconfirmed
  against the actual files.
