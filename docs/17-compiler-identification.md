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

## Where to look

The decomp.me PSP set is now exhaustively falsified — all 11 report 3.0.0, so
none of them is the answer. Candidates worth pursuing:

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
