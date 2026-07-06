# Contributing

Thanks for your interest in helping decompile *Yu-Gi-Oh! 5D's Tag Force 5*! This is the
first decompilation effort for any Tag Force game, so there is a huge amount of
low-hanging fruit and every matched function moves the project forward.

This guide gets you from zero to your first pull request.

## Ground rules

- **Never commit copyrighted content.** No ISOs, `.prx` files, EBOOT, extracted assets,
  or disassembly of the original binary. The `.gitignore` already blocks these. You must
  provide your own legally-obtained copy of the game.
- Only hand-written reconstructed C source, tooling, configs, and documentation belong
  in the repo.
- Be kind and patient in reviews and discussions.

## Setup

1. Read [`docs/01-overview.md`](docs/01-overview.md) for the big picture, then
   [`docs/09-first-match.md`](docs/09-first-match.md) for a hands-on walkthrough.
2. Install the toolchain:
   ```bash
   sudo apt install -y p7zip-full build-essential libssl-dev python3-venv cmake ninja-build
   scripts/setup_tools.sh
   ```
3. Extract your own copy of the game and (optionally) decrypt the EBOOT:
   ```bash
   scripts/extract_iso.sh "path/to/your.iso"
   make -C tools/pspdecrypt && scripts/decrypt_eboot.sh
   ```

## The confirmed compiler configuration

All matching uses **Metrowerks CodeWarrior for PSP**. On [decomp.me](https://decomp.me):

- **Platform:** PSP
- **Compiler:** `MWCC 1.3 SP7 (3.0.1 219)` (the exact build is still being narrowed;
  180–219 all match simple functions)
- **Flags:** `-O4,p -sdatathreshold 0`

Two project-specific conventions discovered so far (see
[`docs/09-first-match.md`](docs/09-first-match.md)):

- `-sdatathreshold 0` is required (the game uses absolute addressing, not gp-relative).
- Game **state globals are `volatile`** and are accessed via a local pointer, e.g.
  `volatile int *p = &G; if (*p) { ...; *p = 0; }`.

## Matching a function (the workflow)

1. **Pick an unclaimed function.** Start small. The `rel_movie_viewer` module is a good
   first target. Announce which function you're taking (issue/PR/Discord) to avoid
   duplicate work.
2. **Get the target assembly.** Split the module with splat (see
   [`docs/06-splitting-and-matching.md`](docs/06-splitting-and-matching.md)):
   ```bash
   . .venv/bin/activate
   splat split config/rel_movie_viewer.example.yaml   # writes asm/ (git-ignored)
   ```
   Or read it in Ghidra (`scripts/run_ghidra.sh`).
3. **Understand it** in Ghidra (with the ghidra-allegrex extension), resolving NID
   imports so the pseudo-C is readable — see [`docs/05-ghidra.md`](docs/05-ghidra.md).
4. **Match it** on decomp.me: paste the target asm, write the C, and iterate with the
   config above until the score is **0 (100%)**. `m2c` gives a first draft:
   ```bash
   python tools/m2c/m2c.py --target mips-mwcc-c asm/rel_movie_viewer/text.s
   ```
5. **Add the matched C** to the appropriate file in `src/` (see existing
   [`src/rel_movie_viewer.c`](src/rel_movie_viewer.c) for style), with a short comment
   noting the function's purpose (if known) and that it is a confirmed 100% match.

## Opening a pull request

- One PR per function (or a small, related group) keeps reviews fast.
- In the description, include the decomp.me scratch link showing 100%.
- Use placeholder names (`func_XXXXXXXX`, `D_XXXXXXXX`) until a symbol's purpose is
  understood; rename with a follow-up once it's clear.
- Keep style consistent with the surrounding code and the original codegen conventions.

## Other ways to help

Not into assembly? There's plenty else to do:

- **Documentation** — improve or extend the `docs/`.
- **File formats** — the asset formats (`.ehp`, `.cip`, models, card DB) are partly
  reverse-engineered; see [`docs/07-file-formats.md`](docs/07-file-formats.md).
- **Tooling** — splat configs for more modules, build system, progress tracking.
- **NID / symbol naming** — mapping SDK imports and naming functions in Ghidra.

## Questions

Open an issue, or join the Tag Force modding community (links in
[`docs/08-resources.md`](docs/08-resources.md)). The
[sotn-decomp](https://github.com/Xeeynamo/sotn-decomp) project is the best reference for
how PSP matching decompilation is done in practice.
