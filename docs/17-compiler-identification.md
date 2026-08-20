# Compiler identification: the fingerprint is NOT diagnostic, and NOT our blocker

> **READ THIS FIRST — conclusion revised 2026-08-19.** This document originally
> argued that our size ceiling (nothing above 160 instructions has ever matched)
> was caused by using the wrong compiler. **That argument is now substantially
> refuted.** `Xeeynamo/sotn-decomp` matches PSP functions far larger than
> anything we have achieved, using `mwccpsp_3.0.1_219` — our exact compiler.
> Their `src/dra_psp/menu.c` is 4,466 lines with **zero `INCLUDE_ASM` stubs**
> and contains a single **822-line** matched function. So 219 is demonstrably
> capable of large PSP functions, and our ceiling is far more likely a
> methodology problem than a compiler problem. See "What actually changed" at
> the end.
>
> **SETTLED 2026-08-20.** The remaining pillar of the compiler argument — the
> `.comment` fingerprint mismatch — is now **falsified by experiment**. The
> Metrowerks linker writes `.comment` ITSELF; it does not merge or forward the
> strings its input objects carry. Two objects compiled by 2.3.1.01 link into a
> binary reporting 2.4.1.01. So the shipped modules' `MW MIPS C Compiler
> (2.4.1.01)` describes **mwldpsp, not mwccpsp**, and says nothing whatsoever
> about which compiler built the code. Everything below that reasons from the
> fingerprint is dead. See "THE FINGERPRINT IS A LINKER STAMP" at the end.


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

### COUNTER-EVIDENCE, recorded 2026-08-18 — this thesis is NOT settled

Two findings weaken the conclusion above, and both must be resolved before
anyone acts on it.

**1. A mature PSP decomp matches large functions with mwccpsp_219.**
`Xeeynamo/sotn-decomp` decompiles Castlevania: Symphony of the Night for PSP
(Dracula X Chronicles, **Konami, 2007** — same publisher, same era as Tag
Force) and ships `bin/mwccpsp_219.tar.gz.sha256`: the exact compiler this
project uses. Their PSP tree contains matched C files up to 357 KB. So 219
demonstrably CAN match large PSP functions, which is precisely what this
document argues it cannot do. Either SOTN was built with a different compiler
than TF5, or our size ceiling has a cause other than the compiler.

**2. The falsification test used the WRONG LINKER.** The mixed-compiler link
experiment above — which concluded that two compiler versions produce two
`.comment` strings, and therefore that TF5's single string proves a single
compiler — was run with **GNU ld**, not with Metrowerks' `mwldpsp`. If the
Metrowerks linker emits only one `.comment` (its own, or the first object's),
the whole argument collapses and `2.4.1.01` could be inherited from a crt0 or
SDK object after all. This has NOT been tested.

**The decisive experiment, still unrun:** read `.comment` from a Castlevania
Dracula X Chronicles PSP binary. If it reports `3.0.0`, this document's thesis
survives — 219 is correct for SOTN, and TF5's `2.4.1.01` is genuinely a
different toolchain. If it reports `2.4.1.01`, the thesis is dead: `.comment`
is not diagnostic, 219 is the right compiler, and our size ceiling is caused by
technique or flags rather than by the compiler binary. Either answer is worth
more than any further analysis here.

**3. The flag space is barely explored.** sotn-decomp builds PSP with:

    -Op -opt nointrinsics -char unsigned -lang c -fl divbyzerocheck
    -sdatathreshold 0 -gccinc -Iinclude

This project has only ever tried `-O4,s`, `-O4,p` and `-O2,s` plus
`-sdatathreshold 0`. `-char unsigned` alone decides `lb` versus `lbu` for every
plain `char` in the codebase. Tested against `rel_movie_viewer` these flags
changed nothing (still 15/16, `func_00000294` still +13 words), but they were
tested only on source already tuned for the current flags, and only on one
module. The flag space deserves a systematic sweep before the compiler is
blamed further.

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


## What actually changed (2026-08-19)

The decisive evidence came from `Xeeynamo/sotn-decomp`, a mature decompilation
of Castlevania: Symphony of the Night for PSP (Dracula X Chronicles — Konami,
2007, the same publisher, console and era as Tag Force 5).

**They use `mwccpsp_3.0.1_219`** (`bin/mwccpsp_219.tar.gz.sha256`) and match
functions an order of magnitude larger than our best. `src/dra_psp/menu.c`:
4,466 lines, no `INCLUDE_ASM`, an 822-line `MenuHandle()` plus 238-, 173- and
144-line functions. Our largest match ever is 153 *instructions*.

That kills the central inference of this document. The size-rate collapse
(11.3% under 80 instructions, 0% above 160) cannot be blamed on 219 being
incapable of large functions, because 219 demonstrably is capable.

### What we are missing that they have

None of it requires finding a different compiler:

1. **Real PSP SDK headers.** They build with `-Iinclude/pspsdk`. Correct struct
   definitions decide load widths and signedness, which is the single most
   common cause of one-word diffs. We have no SDK headers at all.
2. **Per-file optimization levels.** `tools/builds/gen.py` defaults to `-Op`
   and exposes a `PSPO` override *per source file*. That is exactly the
   multi-TU / mixed-flags reality this project hypothesised as workstream C —
   they simply implemented it.
3. **A much fuller flag set:**
   `-gccinc -lang c -char unsigned -fl divbyzerocheck -opt nointrinsics -sdatathreshold 0`
   against our `-O4,s -sdatathreshold 0`. `-char unsigned` alone decides `lb`
   versus `lbu` for every plain `char`.
4. **`metrowrap` / `mwccgap`** — a wrapper that lets `mwcc` mix C with
   `INCLUDE_ASM` assembly. This is the hybrid build we said did not exist and
   that blocks 19 of 28 modules from ever completing.
5. **Splat config technique:** `migrate_rodata_to_functions`, `disassemble_all`,
   `asm_jtbl_label_macro`, per-segment symbol generation.

### What remains genuinely unexplained

The fingerprint mismatch is still real: our binaries say `2.4.1.01`, every
mwccpsp build says `3.0.0`. Two possibilities, neither tested:

- Tag Force 5 really was built with a different compiler than SOTN. Both are
  Konami PSP titles but three years and probably different studios apart, and
  the binary formats differ (our Sony PRX modules versus their Metrowerks
  `mwo_header` overlays and `PS.ELF`).
- `.comment` is inherited from a crt0 or prebuilt SDK object rather than
  written by the compiler that built `.text`. **The experiment that supposedly
  ruled this out used GNU ld, not Metrowerks' linker, so it proves nothing
  about a Metrowerks-linked binary.**

`readelf -p .comment` on a Dracula X Chronicles PSP binary would separate these,
and their repo cannot answer it — `assets/`, `asm/` and `disks/` are all
gitignored, and no issue or PR in the repository ever mentions `2.4.1.01`.

### Revised recommendation

**Stop treating the compiler as the blocker.** Adopt the five items above
first; they are all available today and none depends on the compiler question.
If the size ceiling lifts, the mismatch was a red herring. If it does not, the
compiler hunt resumes with much better evidence than a fingerprint alone.


### Linker re-test, 2026-08-19: the fingerprint evidence is restored

The earlier caveat — that the mixed-compiler `.comment` experiment used GNU ld
rather than Metrowerks' own linker — has been retested with `mwldps2.exe
-partial`. Linking a 2.3.1.01 object with a 2.4.1.01 object yields a `.comment`
carrying BOTH strings, identical to GNU ld's behaviour. **A single string means
a single compiler.** The "inherited from crt0/SDK object" explanation is dead.

Combined with sotn-decomp matching large PSP functions using 219 (which reports
3.0.0), the remaining consistent reading is that **Tag Force 5 and Castlevania
were built with different compilers** — ours predating the 3.0.0 front-end.


---

## THE FINGERPRINT IS A LINKER STAMP — experiment, 2026-08-20

The decisive experiment named above ("re-run the mixed-compiler link test with
`mwldpsp`, not GNU ld") has been run. It kills the compiler thesis outright.

**There is no `mwldpsp` in this repo** — `tools/` carries only the PS2 line's
`mwldps2.exe`. That is a limitation, and it is stated plainly in the caveats
below; it does not weaken the result, because the effect turns out not to be
version-specific or even object-dependent at all.

### Setup

Two trivial objects, compiled by two PS2 compilers that fingerprint differently:

    tools/mwcps2-2.3.3-000906/mwccps2.exe  ->  MW MIPS C Compiler (2.3.1.01)
    tools/mwcps2-2.4-001213/mwccps2.exe    ->  MW MIPS C Compiler (2.4.1.01)

### Results

| # | linker | input objects | resulting `.comment` |
|---|---|---|---|
| A | mwldps2 2.4 | 2.3.1.01 + 2.4.1.01 | `(2.4.1.01)\0PlayStation2` |
| B | mwldps2 2.3.3 | 2.3.1.01 + 2.4.1.01 | `(2.4.1.01)\0PlayStation2` |
| C | mwldps2 2.4 | reversed order | `(2.4.1.01)\0PlayStation2` |
| D | **mwldps2 2.4** | **2.3.1.01 + 2.3.1.01** | **`(2.4.1.01)\0PlayStation2`** |
| E | **mwldps2 2.3.3** | **2.3.1.01 + 2.3.1.01** | **`(2.4.1.01)\0PlayStation2`** |
| — | GNU ld | 2.3.1.01 + 2.4.1.01 | `(2.3.1.01)` **and** `(2.4.1.01)`, both |

**Rows D and E are the whole argument.** Every input object was compiled by
2.3.1.01, and the linked output claims 2.4.1.01 regardless. The string is not
merged from the objects, not taken from the first object, not order-sensitive,
and not even the linker's own nominal version (row E's linker is 2.3.3). The
Metrowerks linker simply emits a fixed string of its own.

The byte layout confirms it is the same mechanism that produced the game's:

    mwldps2 output    4d57...(2.4.1.01)\0PlayStation2\0     0x2b bytes
    shipped TF5 .prx  4d57...(2.4.1.01)\0PSP\0              0x22 bytes

Identical construction — the same version string, then a platform tag. This is
a **linker** signature with the platform name swapped, which is exactly what one
expects from `mwldps2` versus `mwldpsp`.

### What this falsifies

The original argument ran: the shipped binary contains exactly ONE compiler
string, therefore every object linked into it came from ONE compiler, therefore
that compiler reported 2.4.1.01, therefore our 3.0.0 compilers are all wrong.
The first inference is now known to be false — a Metrowerks-linked binary
contains one string no matter how many compilers contributed to it, and that
string need not be any of theirs.

The earlier "both strings appear, therefore `.comment` is trustworthy" result
was **an artifact of testing with GNU ld**, which does merge them (last row).
That was flagged as a possible flaw at the time; it was.

Consequences:

- **`readelf -p .comment` is not a compiler test for a linked binary.** The
  "ten-second, binary accept/reject per candidate" screen recommended earlier in
  this document is invalid. Do not reject a compiler on it. (It remains valid on
  an unlinked `.o`, which is what the compiler itself stamps.)
- **"The compiler is not publicly catalogued" is unsupported.** It rested
  entirely on the fingerprint. `mwccpsp_3.0.1_219` is not excluded by anything.
- **Hunting other PSP games' `.comment` strings is pointless** — it would
  fingerprint their linkers.
- The size ceiling is a **methodology** problem. This now agrees with the
  sotn-decomp counter-evidence rather than sitting in tension with it.

### Caveats, stated honestly

1. The linker tested is `mwldps2`, not `mwldpsp` — no PSP linker exists in this
   repo. The claim generalises only if the PSP linker shares the behaviour.
   Rows D/E make that very likely (neither PS2 linker forwards object strings,
   and the shipped PSP layout is structurally identical), but it is inference.
2. The test objects are trivial. A real link pulls in crt0 and SDK libraries;
   none of them changed the outcome here, but none were present either.

Neither caveat can rescue the original argument: showing that *some* Metrowerks
linker manufactures the string is enough to break the inference that the string
identifies the compiler.

### What to do with the freed effort

The 36 PS2 compilers in `tools/` were fetched to chase this and can be dropped.
The remaining prescriptions from the "How to settle it" section are still worth
running, but for a different reason — they are about flags and technique, not
identity:

1. Sweep the flag space scored by **word count on a corpus of verified
   functions**, not by match count against over-fitted `src/`.
   `-char unsigned` alone decides `lb` vs `lbu` for every plain `char`.
2. Re-derive one medium function from scratch, without the 219-tuned levers.
3. Keep the real acceptance criterion: **match rate must stop collapsing with
   function size.**

Reproduce with: `scripts/comment_fingerprint_test.sh`.
