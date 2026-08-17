# Reproducing the rel_movie_viewer pipeline on any module

`rel_movie_viewer` was matched by hand. This is everything that made that
possible, written down so it can be applied to any of the other 27 modules —
and so the automated loop (`scripts/auto_decomp.py`) can be understood, trusted
and extended.

## The standard

A function counts as done **only** when `scripts/mwcc_diff.py` reports `MATCH`:
recompiled with the original toolchain it is byte-for-byte identical. Anything
else — "close", "one word off", "same instruction count" — counts as nothing.
A module is done when `make MODULE=<name> SRC=1` prints OK.

## Software

| what | where | why |
|---|---|---|
| `.venv` with splat64, spimdisasm, rabbitizer | repo `.venv/` | disassembles the PRX into `asm/` and generates the linker script |
| `binutils-mips-linux-gnu` | system (`apt`) | `as` / `ld` / `objdump` / `objcopy` for relinking and diffing |
| **mwccpsp 3.0.1_219** (MWCC 1.3 SP7) | `tools/mwccpsp_3.0.1_219/` | **the original compiler.** Nothing else reproduces the code |
| **wibo** | `tools/wibo-bin/` | runs that Windows compiler binary on Linux |
| m2c | `tools/m2c/` | turns a function's assembly into a first-draft C |
| decomp-permuter | `tools/decomp-permuter/` | brute-forces source shapes when a function is 1-4 words off |
| pspdecrypt | `tools/pspdecrypt/` | decrypts `EBOOT.BIN` -> `build/EBOOT.elf` (needed once, for NIDs) |
| Ghidra + ghidra-allegrex | system | reading the EBOOT when identifying engine functions |

`scripts/setup_tools.sh` fetches wibo and mwccpsp. The compiler configuration is
**`-O4,s -sdatathreshold 0`** — size, not speed; absolute addressing, not
gp-relative. This was pinned empirically (see `docs/09-first-match.md`) and is
not negotiable.

## Scripts in this repo

| script | does |
|---|---|
| `scripts/module_survey.py` | generates a 100%-coverage splat config + a survey doc for a module |
| `scripts/resolve_nids.py` | names every import in every module (see `docs/nids/README.md`) |
| `scripts/auto_decomp.py` | the automated match loop: m2c draft -> source reshapes -> compile -> verify |
| `scripts/mwcc_build.sh` | compiles a `src/*.c` with the real compiler |
| `scripts/mwcc_diff.py` | relocation-aware diff of one function against the target |
| `scripts/asm_prepare.py` | rewrites Allegrex opcodes GNU as cannot assemble into `.word` |
| `Makefile` | relinks a whole module and checks its sha1 |

## The pipeline, per module

```bash
source .venv/bin/activate

# 1. config + disassembly + survey (once per module)
python3 scripts/module_survey.py rel_gallery
#    -> config/rel_gallery.yaml, asm/rel_gallery/, assets/rel_gallery/,
#       build/rel_gallery.ld, docs/modules/rel_gallery.md

# 2. import names (already done for all 28; re-run after editing nids/*.csv)
python3 scripts/resolve_nids.py
#    -> config/symbols/rel_gallery.txt, merged into the splat config

# 3. prove the config: relink from the disassembly, compare sha1
make MODULE=rel_gallery

# 4. automated matching pass
python3 scripts/auto_decomp.py rel_gallery
#    -> build/auto/rel_gallery.matched.json  (verified source per function)
#    -> build/auto/rel_gallery.json          (status of every function)

# 5. hand-iterate what step 4 missed, one function at a time
cd build/auto/rel_gallery
../../../tools/wibo-bin/wibo ../../../tools/mwccpsp_3.0.1_219/mwccpsp.exe \
    -c -O4,s -sdatathreshold 0 -o func_00000123.o func_00000123.c
cd -
scripts/mwcc_diff.py asm/rel_gallery/text.s build/auto/rel_gallery/func_00000123.o func_00000123

# 6. assemble src/rel_gallery.c (functions IN ADDRESS ORDER) and verify the lot
scripts/mwcc_build.sh src/rel_gallery.c
scripts/mwcc_diff.py asm/rel_gallery/text.s build/mwcc/rel_gallery.o

# 7. the real gate: rebuild the module from OUR source
make MODULE=rel_gallery SRC=1
```

## The compiler levers

MWCC treats as different several constructs a programmer would call equivalent.
This list is the whole reason `rel_movie_viewer` and `rel_html_view` matched;
`scripts/auto_decomp.py` applies the mechanical ones automatically.

1. **`switch` is not `if`.** A switch branches *into* an out-of-line case body;
   an `if` inverts the branch and inlines it, 1-2 words shorter. This holds even
   for a **single-case** switch.
2. **Case tests come out in reverse source order**, while case *bodies* stay in
   source order. To get tests 3, 2, 4, 1 write the cases 1, 4, 2, 3.
3. **A duplicated `return r;`** — once inside the failure branch, once after it
   — gives a plain `bgez`; a single shared return gives the branch-*likely* form
   with the return-value move in the delay slot.
4. **Loop rotation.** `while (f())` becomes a bottom test with an entry branch;
   an explicit `goto` loop keeps a top test.
5. **Where a value lives.** Testing a variable that is also used later puts it in
   a saved register (`bltz $s0`); testing a call's result directly tests `$v0`.
6. **Index state blobs as `int[]`** (`state[0x194D]`), not recomputed byte
   offsets — that folds the offset into each load/store immediate.
7. **Volatile globals through a local pointer** reproduce the reload behaviour of
   game state (`volatile int *p = &G;`).
8. **`__builtin_allegrex_min` / `_max`** are intrinsics, not something MWCC folds
   out of a `?:` clamp. If the target has `min`/`max`, the source called them.
9. **Pointer vs int typing decides address caching.** A global's address stored
   through `*(void **)&cfg[n]` stays in a saved register; the same value cast to
   `int` becomes a temp that gets CSE'd — or, accessed directly rather than
   through a pointer variable, re-materialised at all 31 use sites (the
   `func_00000294` trap).
10. **A dead argument register can double as a switch constant** — a call site
    that sets up no argument register is not necessarily a no-argument function.

## Verification, three levels

1. **Per function** — `scripts/mwcc_diff.py`. Relocation-aware: a word matches
   if the bytes are equal *or* both sides carry the same relocation against the
   same symbol. This is the local equivalent of a decomp.me score of 0.
2. **Whole module from the disassembly** — `make MODULE=x`. Proves the splat
   config's layout is exact. 26 of the 28 modules pass today.
3. **Whole module from our source** — `make MODULE=x SRC=1`. The real gate;
   passes only when every function in the module matches.

Note what level 2 and 3 do *not* yet do: the import stubs, module tables, `.data`
and ELF metadata are carried over from the shipped module, not reconstructed.
Across the 28 modules that is 37% of the bytes. Full 100% additionally requires
generating those from source declarations (a `psp-prxgen`-style step).
