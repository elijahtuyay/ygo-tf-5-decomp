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

### Found during the automated sweep (2026-08-17 night)

11. **Integer arguments 5-8 go in `$t0`-`$t3`, not on the stack.** mwccpsp uses
    an 8-register integer convention (the PSP's EABI), confirmed by an 8-argument
    passthrough test and by matched functions in `rel_tutorial`. This was behind a
    whole family of "mystery register" functions that looked unreachable from C:
    they just need more declared parameters. Probably the highest-value single
    fact on this list.
12. **Thunks.** A tiny function that shifts or masks an argument and then `j`s to
    another function is `return callee(arg0 << 6, arg1 << 6, ...)`, with the
    transform sitting in the branch delay slot. m2c cannot see a parameter that is
    forwarded without being touched, so it drops trailing arguments — add them
    back as passthroughs. These make up a large share of the UI modules.
13. **`return f(...)` versus a bare `f(...);`** decides tail call (`j`) versus
    `jal` + return. Worth a word, and 280 functions were exactly one word short.
14. **Load width follows the declared type.** A global declared `char` compiles to
    `lb`; if the target uses `lw` or `lhu`, cast at the use site
    (`*(int *)&D_XXXX`). This one silently produced false matches until the differ
    was tightened — see below.
15. **Raw baked addresses.** When the original baked an absolute address with no
    relocation, the source must be `*(int *)0xADDR`; declaring `extern int D_XXXX`
    forces a HI16/LO16 relocation and can never match.
16. **`(x << 27) >> 29` is not `(x >> 2) & 7`** — the latter folds into a single
    Allegrex `ext`, one word shorter, and can never match a `sll`+`srl` target.

17. **Not every function was compiled at -O4,s.** Some targets have an UNFILLED
    branch delay slot, or a real `jal`+stack frame where MWCC would tail-call
    optimise. Per `mwccpsp -help all`, **instruction scheduling and tail-call
    optimisation both start at level 3** — so those functions cannot have been
    built at -O4. They match at `-O2,s`.

    This does not mean changing the project's flags: `#pragma optimization_level 2`
    around the function reproduces it exactly inside the normal `-O4,s` build,
    verified on 6 functions in `rel_title`. `scripts/auto_decomp.py` now tries both
    levels and tags the shape, and the merge tooling emits the pragma
    automatically. The tell is a target whose delay slot is a `nop` that our
    version fills, or a call the target makes with `jal` that we turn into `j`.

    A related shape in the same family: a large stack frame for a trivial body
    (e.g. 0x60 bytes to hold one value) comes from a `volatile` local array —
    `volatile s32 sp[24]; sp[0] = x; return sp[0];` matched a 6-word target that
    no -O4 phrasing could reach.

18. **Argument evaluation order is not always reachable from C.** At `-O4` MWCC's
    scheduler can evaluate a call's second argument before its first even when
    both are plain global loads with no side effects, contradicting the source
    order. Temporaries and explicit sequencing do not move it, and
    `#pragma optimization_level 2` changes the word count instead of the order.
    When a diff is nothing but two relocations swapped, this is probably why —
    it is a known dead end, not a phrasing you have not found yet.

### A function that matches alone can still fail in the file

Matching a function in isolation is not the same as matching it inside
`src/<module>.c`, and the gap was almost entirely self-inflicted:

- `scripts/merge_matches.py` injected its own block-scope externs into every
  candidate, including ones that already declared their own. The second set won,
  changed the load widths, and broke functions that had verified cleanly. It now
  skips the injection when the body already contains `extern`. That one change
  recovered 135 functions in `rel_duel_eng`.
- Those injected externs were always `char`, so any function whose target used
  `lw`/`sw` was rejected for a single word. The merge now retries `int`, `char`,
  `unsigned short` and `void *` per candidate.

What remains is genuine: a handful of candidates match on their own and still
regress a distant function in the same translation unit. Always verify the whole
file — `scripts/mwcc_build.sh` + `scripts/mwcc_diff.py` with no function
argument — and treat a per-function trial as a candidate, never as a result.

### 248 functions are hand-written assembly

spimdisasm marks them `/* Handwritten function */` in `asm/<module>/text.s` — they
use instruction patterns a compiler does not emit, so they can never be matched
from C and should eventually be carried as assembly rather than decompiled. They
are concentrated where you would expect:

| module | handwritten | | module | handwritten |
|---|---:|---|---|---:|
| `rel_duel_draw` | 121 | | `rel_shop` | 14 |
| `rel_field` | 50 | | `rel_gallery` | 6 |
| `rel_cutin_viewer` | 24 | | `rel_cardalbum` | 6 |
| 16 others | 1-4 each | | **total** | **248** |

So the matchable denominator is 13,835 functions, not 14,083 — and in
`rel_duel_draw` nearly 8% of the module is off the table for a C decompilation.
Check for the marker before spending time on a stubborn function:

    grep -A2 'glabel func_XXXXXXXX$' asm/<module>/text.s | grep -c Handwritten

### A verification bug worth remembering

`scripts/mwcc_diff.py` originally treated two words as equal whenever both
carried the same relocation kind against the same symbol — without checking the
rest of the instruction. That let `lb` pass for `lw`, and even a different
destination register, as a MATCH. It now compares the whole instruction word with
only the relocated immediate masked out. Tightening it invalidated 171 functions
that had been recorded as verified, all of which were removed. If a matching
rule ever feels generous, it probably is.

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
