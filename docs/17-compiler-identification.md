# The compiler is wrong: MW MIPS C Compiler 2.4.1.01, not 3.0.0

**Finding, 2026-08-18: every compiler build this project has ever used is the
wrong compiler.** Not the wrong flags — a different compiler version, from a
different release line. The compilers say so themselves.

## The evidence

Metrowerks compilers stamp their own version into `.comment` of every object
they emit. Comparing what ours emit against what the shipped game contains:

```
our builds 121,134,139,147,151,180,192,201,205,210,219
    .comment = "MW MIPS C Compiler (3.0.0)"                    (0x1B bytes)

shipped rel_movie_viewer / rel_duel_eng / rel_title / rel_duel_draw
    .comment = "MW MIPS C Compiler (2.4.1.01)\0PSP\0"          (0x22 bytes)
```

All **eleven** mwccpsp builds available on decomp.me (products MWCC 1.0 through
1.3 SP7, internal builds `3.0.1_121`–`3.0.1_219`) report **3.0.0**. Every one of
the 28 shipped modules reports **2.4.1.01**, byte-identical, `.comment` size
0x22 in all of them — a single compiler string per module, so the modules are
not a mixture of toolchains. The target also emits a `PSP` string that none of
our builds produce.

## The assumption this falsifies

`docs/09-first-match.md` and the project skill both recorded:

> These are **different axes**: `2.4.1.01` should NOT be looked for in the
> dropdown.

That was an inference, and it is **wrong**. Our compilers write their version
into the same field, in the same format, as the target does. The fields are
directly comparable — and they do not match. `2.4.1.01` is not an unrelated
numbering scheme; it is the version of the compiler that built Tag Force 5,
and it is older than anything in the decomp.me PSP set.

The consequence is that the exhaustive 11-build bisection recorded in
`docs/09` was searching a candidate set that **does not contain the answer**.
Its conclusion — "the remaining gap is in the C, not in the compiler build" —
does not follow, because no correct build was ever among the candidates.

## Why this went undetected for so long

Because being close is enough for small functions. Compilers in the same family
emit identical code for simple bodies; they diverge as functions grow and
register allocation, scheduling and delay-slot filling start to matter. The
project's match statistics show exactly that curve:

| function size | attempted | matched | rate |
|---|---:|---:|---:|
| ≤ 80 words | 14,260 | 1,616 | **11.3%** |
| 81–160 words | 1,201 | 1 | **0.08%** |
| > 160 words | 826 | 0 | **0.0%** |

The largest function ever matched is 153 words; the median is 7. Large
functions were not skipped — 2,027 attempts above 80 words produced one match.
That is the signature of a near-miss toolchain: per-instruction divergence
probability is small but non-zero, so it compounds with length until long
functions become unreachable.

It also explains the documented "unreachable codegen" categories (scratch
register choice, `$s0`/`$s1` role swaps, delay-slot lookahead, saved registers
with no visible purpose) and why decomp-permuter found nothing in 777,000
iterations. Those are not laws of nature. They are what a different compiler
version looks like from the inside.

## How to test a candidate compiler — the cheap test first

**You do not need to match a function to evaluate a compiler.** Compile
anything at all and read the version it stamps:

```sh
MWCCPSP_BUILD=<build> scripts/mwcc_build.sh src/rel_movie_viewer.c
readelf -p .comment build/mwcc/rel_movie_viewer.o
```

Accept only a compiler that emits `MW MIPS C Compiler (2.4.1.01)`. This is a
ten-second, binary accept/reject per candidate, and it should be run *before*
any functional testing. A candidate that fails it cannot be the right compiler
no matter how many small functions it matches.

Then confirm functionally, in this order:

1. **`scripts/mwcc_bisect.sh`** across a module with many verified matches —
   a correct compiler must not regress any currently-matched function.
2. **The discriminating functions.** `func_00000294` (rel_movie_viewer) is
   +13 words on every build we own and has resisted every documented lever;
   `func_00000470` (rel_html_view) survived 777k permuter iterations.
   The right compiler should make these tractable.
3. **The size curve.** The acceptance criterion that actually matters: match
   rate must **not** collapse as function size grows. If ≥160-word functions
   still never match, the compiler is still wrong.

## Where it is: the PlayStation 2 line, not the PSP line

**decomp.me's PSP dropdown is exhausted** — it offers exactly 13 entries (GCC
3.3.3+allegrex, SN 1.2.7503.0, and the 11 MWCC builds), and every MWCC one
reports 3.0.0. The compiler is not there and never was.

The `decompme/compilers` release, however, carries a **PlayStation 2** line the
PSP dropdown does not expose. Fingerprinting it:

```
mwcps2-2.4-001213     ->  MW MIPS C Compiler (2.4.1.01)    MATCHES TARGET
mwcps2-3.0-011126     ->  MW MIPS C Compiler (2.4.1.01)    MATCHES TARGET
mwcps2-3.0.3-020716   ->  MW MIPS C Compiler (2.4.1.01)    MATCHES TARGET
mwcps2-2.3.3-000906   ->  MW MIPS C Compiler (2.3.1.01)    ruled out
all 11 mwccpsp        ->  MW MIPS C Compiler (3.0.0)       ruled out
```

This is consistent: the compiler identifies itself as **`MW MIPS C Compiler`**,
generic MIPS, not "PSP compiler". Metrowerks' PS2 products from 2.4 onward all
sit on the **2.4.1.01 front-end**; the PSP products moved to 3.0.0. Tag Force 5
was built on the older front-end.

The `PSP` string in the shipped `.comment` does not contradict this — neither
our PSP nor our PS2 compilers emit it, so it is contributed by the linker or by
SDK objects, not by the compiler.

### Status: fingerprint matched, function matching NOT yet confirmed

Compiling `src/rel_movie_viewer.c` with `mwcps2-2.4-001213` currently yields
only 2-3 of 16 functions versus 15 of 16 on mwccpsp_219. **This does not refute
the hypothesis**, for three reasons that must be controlled before drawing any
conclusion:

1. **The C is over-fitted.** Every function in `src/` was iterated for months
   against 219's codegen using the docs/11 lever catalogue. It encodes 219's
   preferences. Testing a different compiler against it is biased against that
   compiler by construction.
2. **Flags are unexplored.** The PS2 compiler's flag semantics differ;
   `-sdatathreshold` in particular changes addressing globally.
3. **Target differences.** mwccps2 targets R5900; the PSP is R4000 Allegrex.

One signal cuts the other way and is worth chasing: with plain `-O4,s`,
`mwcps2-2.4-001213` compiles `func_00000294` to **114 words against a target of
116**. Every PSP build produces 129 (+13), and that function has resisted every
documented lever plus 777,000 permuter iterations. Nothing has ever been that
close to it.

### How to settle it

Do not judge a candidate compiler on the existing over-fitted sources.

1. Sweep the flag space per candidate, using **word count on a corpus of
   verified functions** as the objective, not the current `src/` match count.
2. Test on **trivial functions first** — an empty function and a one-line
   accessor must match on any ABI-compatible compiler. If they do not, the
   candidate is structurally wrong (calling convention / ABI) and no flag will
   save it.
3. Re-derive one medium function's C **from scratch** against the candidate,
   without the 219-tuned levers, and see whether it converges more easily.
4. Then apply the real acceptance criterion: **match rate must stop collapsing
   with function size.**

### The public catalogue is now EXHAUSTED (2026-08-18)

Every Metrowerks MIPS compiler published by `decompme/compilers` has been
fetched and fingerprinted — 33 of them: the PSP line, the PS2 line, all betas,
and the bundled `ps2_compilers.tar.xz`. The version string turns out to be a
**generational marker with a hard cutoff**, not a per-build identifier:

```
released 1999           mwcps2-2.3-991202                     -> 2.3.1.01
released 2000-09/2002   mwcps2-2.4, 3.0, 3.0.1, 3.0.3,
                        mwcps2-3.0b22-{011126,020123,
                                       020716,020926}         -> 2.4.1.01   <- the game
released 2003 onward    all mwcps2 3.0b3x / 3.0.1bNN betas
                        AND ALL ELEVEN mwccpsp PSP BUILDS     -> 3.0.0
```

Eight public compilers carry the game's fingerprint. **All eight fail
functionally**: against `src/rel_movie_viewer.c`, across four flag combinations
each, the best matches 3 of 16 functions — and those three are 2- and 3-word
bodies that any MIPS compiler emits identically. The fingerprint-mismatched
`mwccpsp_3.0.1_219` still matches 15 of 16.

Two further facts, both established by experiment rather than inference:

- **The PS2 compilers default to 64-bit MIPS** (R5900). GNU ld refuses to link
  their output with 32-bit PSP objects at all.
- **`.comment` is trustworthy as a whole-binary fingerprint.** Linking an
  object built by 2.3.1.01 with one built by 2.4.1.01 produces a `.comment`
  containing BOTH strings, concatenated. Every shipped module and the engine
  contains exactly ONE compiler string in 0x22 bytes. Therefore every object
  linked into every Tag Force 5 binary came from a compiler reporting
  2.4.1.01 — this is not a stale string inherited from a prebuilt SDK library
  or a crt0 object. That alternative hypothesis is **falsified**.

**Conclusion: the compiler that built Tag Force 5 is not publicly catalogued
where decompilation projects normally look.** It is almost certainly an early
CodeWarrior for PSP built on the 2.4.1.01 front-end, predating decomp.me's
earliest PSP entry (MWCC 1.0 / `3.0.1_121`, which already reports 3.0.0).
Metrowerks moved the front-end from 2.4.1.01 to 3.0.0 somewhere between
September 2002 and March 2003; the PSP product line as catalogued is entirely
post-cutoff, so the pre-cutoff PSP releases are the gap.

### Where to hunt next (needs resources outside this repo)

1. **Fingerprint other PSP games.** `readelf -p .comment` on any PSP module
   takes seconds. Finding other titles reporting 2.4.1.01 identifies which
   shipped games share this toolchain — and any of those with an existing
   decompilation has, by definition, a working compiler to ask about.
2. **Early CodeWarrior for PSP** in SDK archives, BetaArchive, or collector
   hands: anything predating "MWCC 1.0".
3. **The PSP decomp community directly.** Any project matching large PSP
   functions has solved this.

### Still unexplored

The `mwcps2-3.0.1b*` beta series (builds 44, 51, 74, 75, 87, 95, 103, 119, 145,
151, 198, 205, 210) is listed in the release but the names above did not resolve
to downloadable assets; the exact filenames need to be read off the release
asset list. That series is numbered like the PSP builds and is the most
interesting remaining gap.

Other avenues:

- Earlier **CodeWarrior for PSP** releases predating the decomp.me set.
- The earlier **CodeWarrior for MIPS / embedded** line, from which the PSP
  product was derived — 2.4.1.01 sits below 3.0.0 on that lineage.
- Other PSP titles' PRXs can be fingerprinted the same way (`readelf -p
  .comment`) to learn which shipped games share our compiler, and any existing
  PSP decomp that matches large functions has, by definition, a working
  toolchain worth asking about.

## What this does not change

The tooling, the splat configs, the NID resolution, the differ, the regression
gate and the 3,369 verified matches all remain valid — small functions match on
both compilers, which is precisely why they matched. Expect the current match
set to survive a compiler change largely intact, and verify that with
`scripts/check_regressions.py --all` when a candidate arrives.
