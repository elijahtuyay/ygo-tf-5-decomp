# 06 — Binary Splitting and Matching Workflow

This is the central phase: going from the binary to reconstructed C functions,
verifying that recompilation produces bytes identical to the original.

## 0. The compiler to match: Metrowerks CodeWarrior PSP

Fact confirmed from the `.comment` section of all modules (see `02-iso-analysis.md`):

```
MW MIPS C Compiler (2.4.1.01)   +   "PSP"
```

Matching requires **that exact compiler**, not psp-gcc. Implications:

- On [decomp.me](https://decomp.me) the compiler family is called **`mwccpsp`**
  (Metrowerks CodeWarrior for PSP). It's the most convenient environment to start
  "matching" individual functions without setting up the toolchain locally.
- Locally, `mwccpsp` is a Windows executable: it's run via **WINE** or with
  **[wibo](https://github.com/decompals/wibo)** (a minimal PE loader used by decomp
  projects to run MW/SN compilers on Linux/CI).
- The exact flags (optimization level, `-inline`, alignments…) have to be found by
  trial and error, comparing the output: this is the "artisanal" part of matching.
- **CONFIRMED flags for TF5** (first function matched 100%, `func_00000184`, see
  `09-first-match.md`): **`-O4,s -sdatathreshold 0`** on **MWCC 1.3 SP7 (3.0.1 219)**.

> **Correction (2026-08-16): the flag is `-O4,s`, not `-O4,p`.** The `,p`/`,s`
> suffix selects optimize-for-speed vs optimize-for-size. `-O4,p` was adopted
> when only simple functions had been matched, and those match under BOTH
> settings, so it was never actually discriminating. `func_00000034` is the
> first function that tells them apart: under `-O4,p` MWCC rotates its main
> loop and elides the entry test (63 words vs the target's 65), while under
> `-O4,s` it keeps the test and matches exactly. Switching the whole module to
> `-O4,s` took `rel_movie_viewer` from 14/16 to 15/16 with **zero regressions**
> — every function previously confirmed at `-O4,p` still matches byte-for-byte.
> Bare `-O4` produces a byte-identical object to `-O4,s`, i.e. size is the
> compiler's default. `scripts/mwcc_build.sh` now defaults to `-O4,s`.

  `-sdatathreshold 0` = absolute addressing (not gp-relative). The exact build still
  needs to be narrowed down (the function matches across the whole 180–219 family).
  Base flags (sotn-decomp): `-O4,p -lang c -sdatathreshold 0 -char unsigned -fl divbyzerocheck`.
- **Confirmed technique**: **state globals are `volatile`** and must be accessed via
  a local pointer (`volatile int *p = &G;`) to reproduce the value reload + use of
  saved registers. See the case in `09-first-match.md`.

> ⚠️ **Note on the version**: the `.comment` section reports `MW MIPS C Compiler (2.4.1.01)`
> (the *component* compiler version). On decomp.me, PSP compilers are named after the
> CodeWarrior *product* — **MWCC 1.0 … 1.3 SP7** — with internal builds **3.0.1_121
> … 219**. These are **different** numbering schemes: `2.4.1.01` doesn't appear in the
> dropdown, but it's plausible ours is one of those builds. The contemporary reference
> project **sotn-decomp** (PSP, 2009) uses build **219** (= MWCC 1.3 SP7). For the first
> real function → **bisect** starting from the high builds (219, 210, 205, …). The full
> compiler table and strategy are in `09-first-match.md`. This is the project's biggest
> unknown: make sure to record the outcome.

> psp-gcc (pspdev, see `03-tools.md`) remains very useful for `psp-objdump`,
> for understanding headers and building stubs, but it will **never** produce a
> byte-identical match against MWCC code.

## 1. Splitting with splat

[splat](https://github.com/ethteck/splat) takes a binary + a YAML config and splits
it into `asm/` (one `.s` per function/file) and `assets/`, also generating the linker
script. **It natively supports the `psp` platform** and, via `rabbitizer`, the entire
Allegrex instruction set including the VFPU (`R4000ALLEGREX` category).

Installation (already in `requirements.txt`):

```bash
. .venv/bin/activate
pip install "splat64[mips]"     # pulls in spimdisasm + rabbitizer
```

### Verified example on a real module

`config/rel_movie_viewer.yaml` is a **complete, section-accurate** config for the
smallest module (superseding the earlier `.example.yaml`, kept only as a minimal
`.text`-only reference):

```bash
splat split config/rel_movie_viewer.yaml
```

produces `asm/rel_movie_viewer/text.s` + `sceStub_text.s` (both disassembled as
code, so `.sceStub.text` import stubs get proper `func_XXXXXXXX` labels too —
needed since the game's own code jumps into them directly, see e.g.
`func_00000CEC` in `src/rel_movie_viewer.c`) and one `.bin` blob per remaining
raw section (`.lib.ent`/`.lib.stub` tables, `.rodata.sceModuleInfo`,
`.rodata.sceNid`, `.data`, and the tail ELF/relocation metadata) — tested, real
output:

```asm
glabel func_00000000
    /* 54 00000000 F0FFBD27 */  addiu  $sp, $sp, -0x10
    /* 58 00000004 0000043C */  lui    $a0, %hi(func_00000034)
    /* 5C 00000008 0000053C */  lui    $a1, %hi(func_000001C0)
    /* 60 0000000C 0000063C */  lui    $a2, %hi(D_00005AC0)
    ...
    /* 7C 00000028 21100000 */  addu   $v0, $zero, $zero
    /* 80 0000002C 0800E003 */  jr     $ra
endlabel func_00000000
```

splat figures out function boundaries and `%hi/%lo` on its own. Full byte
coverage is verified: concatenating every extracted piece in order reproduces
the original `.prx` exactly (same sha1) — see the comments in
`config/rel_movie_viewer.yaml` for the byte-offset table and a caveat about
splat's auto-generated linker script (it groups by output section, so a `bin`
subsegment placed BEFORE an `asm` one in the same `code` segment silently
breaks physical ordering — put it in its own top-level segment instead).

### PRX quirks (important)

`.prx` files are **relocatable** ELFs with `vram = 0`. The `lui/addiu` addressing
instructions have their operands zeroed out in the file, and the real values live
in the `.rel.text` section. Both rabbitizer and Ghidra apply these relocations;
when you write splat configs, keep in mind that absolute addresses depend on the
load address (typically `0x08804000` for the main module, while `rel_*` modules
are loaded dynamically by the engine).

## 2. Automatic C draft with m2c

[m2c](https://github.com/matt-kempster/m2c) (formerly mips_to_c) translates MIPS
assembly into a first C draft, to be refined by hand until it matches:

```bash
python tools/m2c/m2c.py --target mips-mwcc-c asm/funzione.s > src/funzione.c
```

m2c handles MIPS Allegrex (it's the same base ISA). The `mwcc` target steers the
output style toward CodeWarrior conventions. The draft **won't** match: it's meant
as a readable skeleton to fix up.

## 3. Comparison: asm-differ and decomp.me

The matching cycle is: *write C → compile → compare the produced asm against the
target → fix → repeat*, until the diff is empty.

**Locally**, with [asm-differ](https://github.com/simonlindholm/asm-differ):

```bash
tools/asm-differ/diff.py -mwo funzione     # -m match, -w watch (recompiles and rediffs)
```

Shows the target asm and your build's asm side by side, highlighting differences.

**Online**, [decomp.me](https://decomp.me) does the same thing in the browser: you
paste in the target asm, pick the **PSP / `mwccpsp`** scratch preset, write the C,
and see the match percentage in real time. It's the recommended way to start on the
first functions, because the MWCC toolchain is already set up server-side.

When a function resists, [decomp-permuter](https://github.com/simonlindholm/decomp-permuter)
automatically tries equivalent variants of the source to find one that matches:

```bash
tools/decomp-permuter/permuter.py funzione_dir/
```

### 3b. Local matching (no decomp.me account, no asm-differ project scaffolding)

`tools/asm-differ` expects a full project layout (a `build.map`, an `expected/`
tree mirroring your build dir) that this repo doesn't have yet. Until that's set
up, two small scripts give the exact same relocation-aware verification decomp.me
does, working directly off a single `src/*.c` and splat's target asm:

```bash
scripts/mwcc_build.sh src/rel_movie_viewer.c        # compiles with wibo+mwccpsp
scripts/mwcc_diff.py asm/rel_movie_viewer/text.s build/mwcc/rel_movie_viewer.o
#   -> per function: "MATCH (N words)" or a list of differing instructions
```

`mwcc_build.sh` accepts extra args to override the default `-O4,s -sdatathreshold 0`
flags. `mwcc_diff.py` optionally takes function names to restrict the report.

**Why "relocation-aware" matters**: a freshly compiled, unlinked `.o` has ZEROED
placeholder immediates at every `lui`/`addiu`/`jal` that references an external
symbol — the real address is only filled in at link time. splat's target asm
(from the actual shipped PRX) is already fully baked. A naive byte-for-byte
comparison would therefore report false mismatches on every single global/call
reference. `mwcc_diff.py` instead treats two instruction words as equal when
EITHER their raw bytes match, OR both carry the same relocation kind
(`HI16`/`LO16`/`26`) against the same symbol — this is exactly what decomp.me and
asm-differ do under the hood, and it's how `func_00000184` was confirmed to
compile identically byte-for-byte (register allocation, delay slots, and all)
purely from a local build, no browser involved.

**A real gotcha found this way**: some globals in this game are referenced via a
genuinely BAKED absolute address with **no relocation entry at all** in the
shipped PRX (e.g. `D_0009DB00` is sometimes emitted as `lui $v1,(0xA0000>>16)` +
a `-0x2500` low offset — numerically `%hi`/`%lo` of `0x9DB00`, but with no
`R_MIPS_HI16` record backing it, because the address is a fixed constant the
original static link fully resolved, not something that depends on this PRX's
own load base). `mwcc_diff.py`'s `KNOWN_ADDR` table handles this: for any
symbol whose real absolute address you've confirmed (by matching a function that
DOES carry a normal relocation for it), add it there, and the script will
recognize a target's baked immediate as equivalent to your candidate's
relocation against that symbol. Extend this table as more addresses get
confirmed.

**Whether a state-blob field shares a base register or gets a fresh symbol is a
per-function fact you have to check against the target asm, not a rule you can
guess**: some functions reuse one `volatile T *p = &D_0009DB00;` across several
distant offsets (a saved register kept alive across calls), others recompute a
completely independent `lui/addiu` per field even though the fields are
adjacent in memory. Get this wrong and the function still "looks right" in C
but never reaches 0 diffs — see the file header of `src/rel_movie_viewer.c` for
the specific functions where each style was confirmed.

### 3c. MWCC codegen levers (confirmed on `rel_movie_viewer`)

Things that look like "the compiler just chose differently" but are actually
driven by the C you write. Each of these was the last blocker on a function
that now matches 100%.

- **Allegrex `min`/`max` are intrinsics, not a compiler fold.** MWCC never
  emits them from portable C — no `(x < 0) ? 0 : x` phrasing, no `-O` level
  and none of the 11 installed builds. The original source called
  `__builtin_allegrex_min` / `__builtin_allegrex_max` directly. Argument
  order is `__builtin_allegrex_max(rs, rt)` -> `max rd, rs, rt`.
  **Gotcha:** `mips-linux-gnu-objdump` does not know the Allegrex opcodes and
  prints them as a bare `.word`, so a working intrinsic call looks like a
  failed one. Check the encoding instead (`max` = funct 0x2C, `min` = 0x2D).
  The full list is recoverable from the compiler binary:
  `strings tools/mwccpsp_3.0.1_219/mwccpsp.exe | grep __builtin_allegrex`
  — bitrev, clz/clo, ctz/cto, ext/ins, rotl/rotr, seb/seh, wsbh/wsbw,
  sqrt_s, and the float round/floor/ceil/trunc.

- **A single-case `switch` is not the same as an `if`.** MWCC compiles a
  `switch` by branching INTO the case body (`beql`, with a body instruction
  in the delay slot) and giving the fall-through path its own `b` to the
  epilogue. Every `if`/`goto` phrasing of the same test folds those into one
  `bnel`-skip that is a word shorter, and it also changes how the
  fall-through block's delay slots get filled. Conversely a `switch` over
  several cases is sorted ASCENDING regardless of source order, so a target
  that tests its cases descending needs a `goto` chain instead. Try both.

- **Index a state blob as `int[]`, not a recomputed byte offset.** Writing
  `*(volatile int *)((volatile char *)base + 0x6408)` more than once makes
  MWCC hoist the address into its own cached register (costing the lui/addiu
  pair, plus a saved register to spill and restore). `base[0x1902]` keeps the
  offset in each load/store immediate, which is what the targets do.

- **Bitfields.** A target that does lbu / mask / shift / `or` / sb per field,
  with the source value truncated once up front, is MWCC's bitfield-insert
  idiom. It cannot come from hand-rolled `(b & ~N) | (v << k)`, which MWCC
  folds away entirely when `v` is 0. Declare `unsigned char x : 1` fields.
  But model only ONE byte per bitfield struct: with two adjacent bitfield
  bytes MWCC merges the second insert into the first and stores to the wrong
  address (confirmed in isolation).

- **Known mwccpsp bug — silently dropped byte stores.** In a store-dense
  function where two pointers share a base (one derived from the other, by
  `&p->member`, a cast, or a nested access), MWCC drops byte stores whose
  immediate value also appears in a nearby halfword store. Not
  volatile-specific, present in all 11 builds, and it does not reproduce in
  a small isolated function. **Always count stores** (`sb`/`sh`/`sw`) against
  the target before believing a smaller word count is progress — a wrong
  object that is closer on size is not closer. This is what currently blocks
  `func_00000294`.

## 4. Build system and match verification

The goal is a `Makefile`/`ninja` that:

1. compiles the `src/*.c` files with **mwccpsp** (via wibo/WINE) with the right flags;
2. assembles the `.s` files not yet decompiled;
3. links everything with the linker script produced by splat;
4. verifies: `sha1sum` of the rebuilt ELF/PRX **==** the original one.

The target hashes are already in `checksums.sha1` (generated during the extraction
phase). Verification is binary: it either matches or it doesn't. The project's
completion percentage = how many functions are "matched" out of the total.

## 5. Recommended order of attack

1. **`rel_movie_viewer.prx`** (26 KB) — the smallest, to shake down the whole
   pipeline (split → m2c → mwccpsp → match → link → sha1) end-to-end on something
   manageable.
2. Other small, self-contained modules (`rel_html_view` 27 KB, `rel_soundtest`
   32 KB, `rel_tutoriallist` 37 KB).
3. **`modehsys`** (the decrypted EBOOT): the shared engine — file system, EHP
   loader, graphics, input. Unlocks understanding of all the modules'
   `libehsys_rel` imports.
4. **`rel_duel_eng.prx`** (4.3 MB) — the rules engine. Huge, but it's the heart
   of the game; the card logic is **hardcoded here** (confirmed by the community:
   the cards are not data-driven), so it's what pays off the most to decompile.

## 6. Tracking progress

Conventions from mature decomp projects, adoptable here:

- **objdiff** (`encounter/objdiff`) or **frogress** for a progress dashboard.
- a function is either "OK" (matching) or "NONMATCHING" (equivalent but not
  identical): spimdisasm marks the latter with `nonmatching` in the asm, useful
  as a TODO list.
- no original assets or binaries in the repo: only `src/`, `asm/` (derived,
  optional), `config/`, `tools/`, `docs/`. See `.gitignore`.
