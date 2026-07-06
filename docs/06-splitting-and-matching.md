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
  `09-first-match.md`): **`-O4,p -sdatathreshold 0`** on **MWCC 1.3 SP7 (3.0.1 219)**.
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

With the `config/rel_movie_viewer.example.yaml` config:

```bash
splat split config/rel_movie_viewer.example.yaml
```

produces `asm/text.s` with labeled functions and symbolically resolved relocations —
tested, real output:

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

splat figures out function boundaries and `%hi/%lo` on its own. What's left is
mapping the PSP-specific sections in the config (`.sceStub.text`, `.rodata.sceNid`,
`.lib.stub`, `.data`, `.bss`) so the linker script is also generated: see the
comments in the example file, with the real section layout.

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
