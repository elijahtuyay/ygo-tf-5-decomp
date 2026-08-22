# Autonomous session, 2026-08-19

Work done unattended over roughly two hours, following the decision (docs/17) to
stop chasing the compiler and pursue everything else.

## Results

| | before | after |
|---|---:|---:|
| functions matched | 3,369 | **3,391** |
| bytes of `.text` | 128,264 | **130,200** (2.49%) |
| modules passing `make MODULE=x` | 26 / 28 | **28 / 28** |

## 1. A new automation: same-shape twin adaptation (+22 functions)

`scripts/find_twins.py` reports two tiers of duplicate function. The `identical`
tier was already automated. The `same-shape` tier — 156 functions whose bodies
match only once immediates, symbols and branch targets are masked — had never
been exploited, because adapting each one by hand is tedious.

It turns out not to need a hand. `scripts/mwcc_diff.py` already reports, per
differing word, exactly which symbol the target expects versus which one we
emitted:

    [12] RELOC MISMATCH target=... (LO16 D_0015E790) vs candidate=... (LO16 D_0009DB00)

That is a substitution instruction. **`scripts/adapt_twins.py`** compiles the
template body under the twin's name, reads the mismatches, rewrites candidate
symbols to target symbols, and iterates until the function matches or stops
improving — then verifies against the whole file and rolls back on any
regression, exactly as `merge_matches.py` does.

22 functions across 11 modules, in three passes. A fourth pass found nothing, so
this vein is mined out until more templates exist; re-run it after any
significant batch of new matches.

## 2. The relink gate is green for the first time: 28 / 28

Both modules that failed `make MODULE=x` are fixed, and they failed for
different reasons.

**`rel_cutin_viewer` — splat omitted a local label.** `.L0000B07C` was branched
to but never defined, so the module could not link. splat mis-identified a
function boundary and treated the region as data. Since every such label encodes
its own vram and splat prints the vram of every instruction, the definition can
simply be restored; `asm_prepare.py` now does that automatically.

**`rel_duel_draw` — asm_prepare could not converge.** It rewrote only the lines
gas named, and gas reports about 30 errors per invocation, so a module with
thousands of VFPU instructions across 121 hand-written functions needed
thousands of rounds. It now generalises: when a mnemonic is rejected once, every
line using that mnemonic is rewritten. Rounds scale with the number of distinct
unsupported opcodes rather than with the instruction count.

(A batch sweep reported `rel_duel_eng` failing; it passes when built on its own.
The 3 MB module simply did not finish inside the batch. Sweeps of that module
need their own time budget.)

## 3. The `.comment` fingerprint evidence is restored

docs/17 carried a caveat: the experiment showing that two compilers produce two
`.comment` strings had used GNU ld, not Metrowerks' linker, so it proved nothing
about a Metrowerks-linked binary. **Retested with `mwldps2.exe -partial`** —
linking a 2.3.1.01 object with a 2.4.1.01 object yields both strings, exactly as
GNU ld did, and the linker adds no string of its own.

So a single string really does mean a single compiler, and Tag Force 5's
`2.4.1.01` is not inherited from a crt0 or SDK object. Combined with sotn-decomp
matching large PSP functions using 219 (which reports 3.0.0), the consistent
reading is that **Tag Force 5 and Castlevania were built with different
compilers.**

## 4. Engine prototypes from disassembled bodies

`include/ehsys.h` now carries prototypes for the **985 engine functions the
modules actually call**, with arity proven by register reads plus tail-call
propagation rather than guessed from call sites. It is reference material, not
a build include: our sources declare engine imports K&R style, and swapping in
real prototypes would change argument promotion and could regress matched code.
Use it to check a callee's arity before guessing one — the single biggest cause
of SIZE MISMATCH.

## 5. THE HYBRID BUILD WORKS — 7 modules now rebuild byte-exactly

**`make MODULE=rel_soundtest HYBRID=1` prints OK.** That is the first time in
this project's history that a module has been rebuilt from our source and
matched the shipped binary's sha1.

Seven modules now do: `rel_cardalbum`, `rel_conv_machine`, `rel_gallery`,
`rel_labo`, `rel_password`, `rel_soundtest`, `rel_story` — the last of those
being 640 functions.

`HYBRID=1` compiles the functions we have matched from C and assembles the rest,
splicing them into one object with `tools/mwccgap`. Plain `SRC=1` replaces the
whole `.text`, so it can only pass when EVERY function matches — impossible for
the 19 modules containing hand-written assembly. The hybrid path carries those
verbatim, which is how every matching decompilation handles them.

### What the wiring needed

Three things, each of which failed silently in a different way:

1. **An `INCLUDE_ASM` macro mwcc accepts.** `include/include_asm.h` has never
   worked with the real compiler — mwcc rejects GCC-style
   `__asm__(".include ...")` with `')' expected`. `include/hybrid_asm.h`
   defines it as a bare extern instead: it parses, and it leaves the function
   ABSENT from the object, which is exactly what mwccgap requires.
2. **`--macro-inc-path`**, because the per-function `.s` files open with
   `.include "macro.inc"` and the assembler otherwise cannot find it.
3. **Never passing `--as-flags`.** mwccgap sets its option prefix to `~`, so
   `--as-flags` (nargs="*") greedily swallows every following `-flag` and leaves
   the compiler with no flags at all — which presents as a compile error with no
   obvious cause.

`scripts/make_hybrid.py` splits the PREPARED disassembly (`build/asm/<m>/text.s`),
not the raw one: `asm/<m>/text.s` still contains Allegrex `min`/`max`/VFPU
opcodes that gas cannot assemble, and `asm_prepare.py` rewrites exactly those.
Functions are emitted in shipped ADDRESS ORDER, because the linker lays `.text`
out sequentially and any deviation moves every later function.

## 6. Earlier scaffolding notes

`scripts/make_hybrid.py` generates a module source interleaving matched C with
`INCLUDE_ASM` for everything else, in shipped address order, and
`include/hybrid_asm.h` provides an `INCLUDE_ASM` macro mwcc accepts. Verified:
the generated file compiles cleanly with the C functions present and the
assembly ones absent, which is exactly what `tools/mwccgap` requires; and gas
assembles the extracted per-function `.s` files without error.

`mwccgap` itself still fails on its first internal compile step. Both sides of
that step are known good, so this is a wiring problem rather than a design one.

Worth recording: **`include/include_asm.h` has never worked with the real
compiler.** mwcc rejects GCC-style `__asm__(".include ...")` outright with
`')' expected`. That header only functions under GCC, which is precisely why
mwccgap and metrowrap exist.

## What to pick up next

1. Finish the mwccgap wiring — it unblocks `SRC=1` for the 19 modules that
   contain hand-written assembly and currently cannot be completed at all.
2. Re-run `adapt_twins.py` after any batch of new matches; each new template
   can unlock more.
3. The splat options sotn-decomp uses and we do not
   (`migrate_rodata_to_functions`, `disassemble_all`, and five others) remain
   untested — the missing-label bug above suggests our disassembly config is
   worth revisiting.
