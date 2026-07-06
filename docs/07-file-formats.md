# 07 — Tag Force 5 file formats

Summary of what the modding community has already figured out about the file formats
of the Tag Force series. It's worth starting here instead of reinventing the wheel:
many tools already exist, and the same engine (`ehsys`) is shared across the various
Tag Force titles. **Warning**: almost all the tools have been tested on TF1/TF6; on
TF5 they need to be verified against the real files (the format has small variations
between games).

> No tool should be committed to the repo; install them under `tools/` (already
> gitignored). The repos linked below are third-party — treat them as reference
> material, not as trusted dependencies to use blindly.

## `.ehp` archives ("EhFolder") — the main container

The game's assets are packed into `.ehp` files (e.g. `title_menu_e.ehp`,
`story_scr_e.ehp`, `all_e.ehp`). This is the engine's container format.

- **ehppack** — https://github.com/xan1242/ehppack — unpack/repack from the command
  line, claimed to be compatible with "any Tag Force game". This is the closest thing
  to a format specification (the logic lives in the C++ source).
- **EHPScanner** — https://github.com/xan1242/EHPScanner — scans the decrypted EBOOT
  to find EhFolders **embedded in the executable** and extract them as `.ehp`. It
  reveals an important fact: **the EBOOT contains embedded EHPs** (e.g. `cname.ehp`,
  `interface.ehp`, `sysmsg.ehp`, `rcpset.ehp`, `packset.ehp`, `load_fl.ehp`).
- **EHP Suite** (web) — https://syruskyury.github.io/ehp_suite/ — extract/edit/
  repack in the browser, with a hex viewer.
- Edge-case note: some `.ehp` files (`deck/tutorial.ehp`, `deck/deckswap.ehp` in
  ARC-V TFS) fail with ehppack directly but open fine if first re-saved with
  EHPScanner → the format **isn't perfectly uniform** across games/tools.

## `.cip` / `.cpm` archives — card images

- **CIPTool** — https://github.com/xan1242/CIPTool — unpack/repack the card artwork
  packages. The internal images are **DXT1**; it uses a modified GIMConv.

## `.gim` images and `.gmo` models (generic Sony formats)

- **GIM** = standard PSP texture (magic `GIM 1.00`), block-based (Root/Picture/Image/
  Palette), CLUT4/8/16/32 and DXT formats. Convertible with **GIMConv** (Sony SDK) or
  tools such as **TextER** (romhacking.net/utilities/659). Generic docs:
  psdevwiki / vg-resource (not Tag Force-specific).
- **GMO** = PSP 3D models (header with a magic like `OMG..1PSP`). Generic Sony format.

### Tag Force-specific models: `.tms` / `.tmt`

Character/duel models use a proprietary format that has been **partially**
reverse-engineered (`.tms` geometry, `.tmt` animation). Discussion on ResHax
(https://reshax.com/topic/1858-...): mesh table at offset 0x04 (12-byte entries),
bone count at 0x14, variable-size FVF. There's a partial Noesis script
(`fmt_tms.py`, kurokozerefx) that reads the geometry but **not** the skeleton.
Status: incomplete → a good candidate for this project's RE work.

## Card database

Inside `cardinfo_*.ehp` (or the equivalents on disc) there are several related
binaries:

| File | Content |
|---|---|
| `CARD_Name_*.bin` | card names |
| `CARD_Desc_*.bin` | text/descriptions |
| `CARD_Huff_*.bin` | **Huffman-compressed** descriptions |
| `CARD_Indx_*.bin` | index |
| `DICT_*.bin` | dictionary for Huffman decompression |

- **TFCardEdit** / **TFCardEditGUI** — https://github.com/xan1242/TFCardEdit — edit
  name/level/ATK/DEF/type/attribute/rarity/password/flags. **Crucial warning from the
  README**: *"cards will have no effect if it doesn't already exist in the game's
  logic/code"*.
- **ogy** — https://github.com/exsilium/ogy — documents the layout and the
  Huffman+dictionary compression well; notes a **cap of ~877,000 bytes** for
  `cardinfo.ehp` beyond which the game crashes.

> ★ **Direct consequence for the decomp**: **card effects are hardcoded in the
> engine** (`rel_duel_eng.prx`), not in the data. Anyone who wants to add cards or
> understand the rules *has to* decompile the code — editing the `.bin` files isn't
> enough. This is exactly the added value of this project compared to existing
> modding.

## Text and string tables

- **tagforcestring** — https://github.com/xan1242/tagforcestring — converts
  `strtbl`/`wordstbl` and the language `.bin` files into ini-like text and back.
  Handles UTF-8 / UTF-16LE / Shift-JIS. Naming convention:
  `<name><type_char><language_char>.bin`. Useful for the `story_scr_*.ehp` files.

## Decks and recipes: `.ydc`

- Binary deck files `.ydc` (8-byte header; ~60% start with magic `01 FC`; typically
  96–140 bytes), also present **inside the EBOOT**.
- **Deck Converter** — https://github.com/SyrusKyury/Yu-Gi-Oh-Tag-Force-Deck-Converter
  — `.ydc` ↔ `.ydk` (EDOPro).
- **TFRandomizer** — https://github.com/xan1242/TFRandomizer — **tested on TF5**:
  randomizes shop boxes and recipes. Useful constants found for TF5 (**US** build,
  ULUS-10555): `BoxInfoOffset = 0x23090`, **60 boxes**. (For our EU build
  ULES-01474 the offset still needs to be reconfirmed, but the structure is the
  same.)

## Audio: `psp_snddat.bin`

- A single 151 MB sound bank. **TFSndEdit** — https://github.com/xan1242/TFSndEdit —
  repacks it; repacking requires an **SHDS** header block extracted from the EBOOT.
  Likely codec is **VAG/ADPCM** (not AT3, contrary to what one might assume).
- The movies in `USRDIR/movie/*.pmf` are standard Sony **PSMF** (M2V + Atrac3),
  playable via `libpsmfplayer.prx` (present in `USRDIR/module/`).

## `INSDIR/` directory (508 `FILE*.DAT` files)

508 files of ~17 KB each, all similar: these are the data for the "Memory Stick
install" typical of Tag Force games (to reduce UMD access). Low priority for the
code decomp; possibly useful for understanding the runtime install system.

## Priority table for format RE

| Format | Needs a new tool? | Decomp priority |
|---|---|---|
| `.ehp` | no (ehppack) | high — it's the entry point to all assets |
| Card DB `.bin` | no (ogy/TFCardEdit) | medium — it's data; the logic is in the code |
| strings/text | no (tagforcestring) | low |
| `.ydc` decks | no (Deck Converter) | low |
| `psp_snddat.bin` | no (TFSndEdit) | low |
| `.tms/.tmt` models | **yes** (incomplete RE) | medium (if interested in graphics) |
| engine/card logic | **is the decomp itself** | ★ highest |
