---
name: tf5-formats
description: >
  Reference for Yu-Gi-Oh! Tag Force 5 file formats and the community tools that open
  them: .ehp (EhFolder) archives, .cip/.cpm (card artwork, DXT1), .gim images,
  .gmo/.tms/.tmt models, card database (CARD_*.bin + Huffman/DICT), string tables,
  .ydc decks, psp_snddat.bin audio, .pmf movies. Activate when extracting, inspecting,
  or documenting game assets, or when looking for the right tool for a format.
  Triggers: "ehp", "cip", "gim", "gmo", "tms", "card database", "psp_snddat", "ydc",
  "pmf", "asset", "texture", "extract game file".
---

# Tag Force 5 file formats

The same engine (`ehsys`) is shared across the Tag Force games → community tools (mostly
by **xan1242**) often work cross-game. **But** they are mostly tested on TF1/TF6: on TF5
they must be re-verified against the real files. Do not commit tools or assets to the
repo (git-ignored); install them under `tools/`.

## Format → tool map
| Format | Where | Tool | Notes |
|---|---|---|---|
| `.ehp` (EhFolder) | everywhere + **embedded in EBOOT** | ehppack; EHPScanner (for EBOOT) | main asset container |
| `.cip`/`.cpm` | card artwork | CIPTool | **DXT1** images |
| `.gim` | textures | GIMConv / TextER | generic Sony format |
| `.gmo` | 3D models | (generic PSP) | magic `OMG..1PSP` |
| `.tms`/`.tmt` | TF models/anim | Noesis `fmt_tms.py` (partial) | **incomplete RE** |
| `CARD_Name/Desc/Huff/Indx.bin`, `DICT.bin` | card database (in `cardinfo_*.ehp`) | ogy; TFCardEdit(GUI) | desc **Huffman+dictionary**; ~877 KB cap |
| string/text tables | `story_scr_*.ehp` etc. | tagforcestring | UTF-8/UTF-16LE/Shift-JIS |
| `.ydc` decks | in EBOOT | Deck Converter (↔.ydk) | 8-byte header, magic `01 FC` |
| `psp_snddat.bin` | `USRDIR/snd/` (151 MB) | TFSndEdit | likely **VAG/ADPCM** codec; repack uses an SHDS header from EBOOT |
| `.pmf` | `USRDIR/movie/` | PSMF (Sony) | M2V+Atrac3; `libpsmfplayer.prx` |
| `INSDIR/FILE*.DAT` | 508 files ~17KB | — | "Memory Stick install" data, low priority |

## Tool repos (reference, third-party)
- ehppack https://github.com/xan1242/ehppack · EHPScanner https://github.com/xan1242/EHPScanner
- CIPTool https://github.com/xan1242/CIPTool · tagforcestring https://github.com/xan1242/tagforcestring
- TFCardEditGUI https://github.com/xan1242/TFCardEditGUI · TFSndEdit https://github.com/xan1242/TFSndEdit
- **TFRandomizer** https://github.com/xan1242/TFRandomizer — **tested on TF5** (US box offset `0x23090`, 60 boxes)
- ogy https://github.com/exsilium/ogy · Deck Converter https://github.com/SyrusKyury/Yu-Gi-Oh-Tag-Force-Deck-Converter
- EHP Suite (web) https://syruskyury.github.io/ehp_suite/

## Key fact for the decomp
**Card effects are NOT in the data**: they are **hardcoded in the engine**
(`rel_duel_eng.prx`). Editing the `CARD_*.bin` files changes names/stats but not
behavior. Understanding/adding rules = decompiling the duel code. This is why this
project has value beyond the existing asset modding.

Full details: `docs/07-file-formats.md`. Community/links: `docs/08-resources.md`.
