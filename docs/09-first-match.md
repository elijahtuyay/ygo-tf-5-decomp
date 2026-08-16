# 09 — The first match (hands-on tutorial)

Step-by-step guide to bringing your first function to a **100% match**, using
[decomp.me](https://decomp.me) (no local toolchain to set up). We'll work on the
smallest module, `rel_movie_viewer.prx`.

Remember the underlying concept (see `06-splitting-and-matching.md`): the goal isn't
to write C "that does the same thing", but C that, **when recompiled with mwccpsp,
produces the same bytes** as the original. decomp.me compares the two assemblies and
gives you a percentage in real time.

## Prerequisites

- An account on https://decomp.me (login with GitHub).
- The **target** assembly (= the original one) of the function. For the two
  functions in this tutorial it's already provided below; for any other function
  see the last section ("Generating the asm of a function").

### decomp.me's three panes (what goes where)

| Pane | What it contains | Counts toward the match? |
|---|---|---|
| **Target assembly** | the function's **original** assembly (what you want to match) | it's the reference |
| **Source** (Scratch/C) | **your** C code, the one you write and recompile | yes |
| **Context** | supporting C declarations (prototypes, `extern`, structs, `#include`) needed for your Source to compile | no (not part of the diff) |

Rule of thumb: in **Context** put only the **declarations** of the external symbols
the function uses (other called functions, global variables), NOT their
implementation. It's only there to make your Source compile.

---

## Step 1 — The empty function (verify the setup)

In the `.text` of `rel_movie_viewer` there are two **completely empty** functions at
`0x1C0` and `0x6B4` (they're no-op callbacks registered by the module, e.g. a stop
handler). They're the ideal "hello world": if you don't get 100% with an empty
function, the problem is the **compiler/flags**, not your C. Isolate one variable at
a time.

**Target assembly** (function `func_000001C0`) — verbatim splat output:

```mips
glabel func_000001C0
    /* 214 000001C0 0800E003 */  jr    $ra
    /* 218 000001C4 00000000 */   nop
```

The `/* … */` comments (file offset, address, bytes) are ignored by decomp.me: you
can paste them or strip them. Note: in the generated asm the function is preceded by
the line `nonmatching func_000001C0, 0x8` — it's just a spimdisasm "TODO" **marker**,
not an error.

**Procedure on decomp.me:**

1. Go to https://decomp.me → **New scratch**.
2. **Platform**: `PSP`. **Compiler**: choose **`MWCC 1.3 SP7 (3.0.1 219)`** — it's
   the most recent one and the one used by the reference PSP project of the same
   era (Dracula X Chronicles, 2009). For the empty function almost any MWCC works
   fine.
3. In the **Target assembly** pane paste the two lines above.
4. In the **Source** (C) pane write:

   ```c
   void func_000001C0(void) {
   }
   ```

5. Press **Compile**. The percentage at the top should be **100%** (match). ✅

If it's **not** 100% on an empty function: switch mwccpsp builds, or remove/add
`-O` in the *Compiler flags*. Once the empty function matches, your environment is
set up correctly.

> This step also works as a **diagnostic test** for the compiler: see the
> "The compiler unknown" section further below.

---

## Step 2 — A function with real logic (`func_00000184`)

Now something real. The function at `0x184` reads a global pointer, and if it's not
null, "frees" it and zeroes it out.

**Target assembly** (from splat's output; the names `D_0009DB00`/`func_00000CEC` are
arbitrary placeholders — splat names it `D_9DB00` by default):

```mips
glabel func_00000184
    /* 1D8 00000184 F0FFBD27 */  addiu  $sp, $sp, -0x10
    /* 1DC 00000188 0C00BFAF */  sw     $ra, 0xC($sp)
    /* 1E0 0000018C 0800B0AF */  sw     $s0, 0x8($sp)
    /* 1E4 00000190 0A00033C */  lui    $v1, %hi(D_0009DB00)
    /* 1E8 00000194 00DB638C */  lw     $v1, %lo(D_0009DB00)($v1)
    /* 1EC 00000198 0A00103C */  lui    $s0, %hi(D_0009DB00)
    /* 1F0 0000019C 04006010 */  beqz   $v1, .L000001B0
    /* 1F4 000001A0 00DB1026 */   addiu $s0, $s0, %lo(D_0009DB00)
    /* 1F8 000001A4 3B03000C */  jal    func_00000CEC
    /* 1FC 000001A8 0000048E */   lw    $a0, 0x0($s0)
    /* 200 000001AC 000000AE */  sw     $zero, 0x0($s0)
  .L000001B0:
    /* 204 000001B0 0C00BF8F */  lw     $ra, 0xC($sp)
    /* 208 000001B4 0800B08F */  lw     $s0, 0x8($sp)
    /* 20C 000001B8 0800E003 */  jr     $ra
    /* 210 000001BC 1000BD27 */   addiu $sp, $sp, 0x10
```

Here two **relocated symbols** come into play (verified in the `.rel.text`):
`D_0009DB00` is a module global (`R_MIPS_HI16/LO16` relocations, address 0x9DB00)
and `func_00000CEC` is the function called by the `jal` (`R_MIPS_26`). On decomp.me
they must be **declared in the context** (*Context* pane) so the asm can assemble,
for example:

```c
extern int D_0009DB00;
void func_00000CEC(int);
```

**C draft** (generated with `m2c`, needs refining — it's not guaranteed to match
as-is):

```c
void func_00000184(void) {
    if (D_0009DB00 != 0) {
        func_00000CEC(D_0009DB00);
        D_0009DB00 = 0;
    }
}
```

**How to proceed:**

1. New scratch (same Platform/Compiler as Step 1).
2. Paste the target asm and the C draft.
3. Compile and look at the **side-by-side diff**: the target on the left, yours on
   the right. The highlighted lines are the differences.
4. Adjust the C until the diff is empty (100%). Things that often shift the match:
   - the optimization level in *Compiler flags* (`-O4,p` etc. for mwcc);
   - the global's **type** (`int`, `void*`, a struct…): it changes the load
     instructions;
   - the order of operations;
   - whether `func_00000CEC` returns something or not.

You don't need to know the real names: `func_00000184`, `D_0009DB00`,
`func_00000CEC` are placeholders. You'll rename them once you understand what
they're for (Ghidra helps here).

---

## How to read the match

- **100%**: identical bytes → function "matched". Done.
- **<100%**: decomp.me highlights the differing instructions. Often it's ONE
  difference (a `lw` load vs `lhu`, a different register, an inverted branch) that
  reveals a data type or a wrong compiler flag.
- If you're stuck on a handful of instructions, there's **decomp-permuter**
  (`tools/decomp-permuter/`), which automatically tries equivalent variants of the
  C code.

## Real case solved: gp-relative vs absolute (`-sdatathreshold 0`)

On the first attempt at `func_00000184` (MWCC compiler, default flags) the diff
shows the **correct logic** but different addressing of the global:

- **target**: `lui $v1, %hi(D)` + `lw %lo(D)($v1)` → 32-bit **absolute** addressing,
  with the address kept in `$s0` (saved register) across the `jal` (hence the
  `sw $s0`/`lw $s0` in the prologue/epilogue).
- **your build**: `lw $v1, %gp_rel(D)($gp)` → **gp-relative** addressing (small
  data).

Cause: by default MWCC puts small data (`int`, ≤ threshold) into the *small data
area* addressed via `$gp`. TF5 does **not** use this scheme. Fix — in the
**Options** tab (top left, where the compiler and flags are) add to the flags:

```
-sdatathreshold 0
```

This disables the small data area → the compiler uses `lui/%hi/%lo`, matching the
target. This is the same flag used by **sotn-decomp** (the reference PSP project).

### Second step: optimization (`-O4,p`)

With just `-sdatathreshold 0`, the addressing is right but two differences remain:

- **`nop`s in the delay slots** (the compiler doesn't fill them);
- the global's address is **recalculated multiple times** using temporary
  registers, instead of being computed once into `$s0` (saved register) and reused
  across the `jal`.

These are symptoms of **no optimization**. Fix: add the optimization level:

```
-O4,p -sdatathreshold 0     # SUPERSEDED — the correct flag is -O4,s, see "Third step" below
```

An optimization level is needed (fills delay slots, allocates registers), but
beware: **`-O4,p` over-optimizes** compared to TF5 — it generates `beqzl`
(branch-likely) where the target uses `beqz`, and keeps the value in `$a0` instead
of the address in `$s0`.

### Third step: finding the exact level (or the build)

> ✅ **RESOLVED (2026-08-16): the level is `-O4,s`.** The suspicion recorded in
> this section was right — `-O4,p` does over-optimize. The `,p`/`,s` suffix is
> optimize-for-speed vs optimize-for-size, and TF5 was built for size. Simple
> functions match under both settings, which is why `-O4,p` survived so long
> unchallenged. `func_00000034` is the first function that discriminates: at
> `-O4,p` MWCC rotates its main loop and drops the entry test (63 words vs the
> target's 65); at `-O4,s` it keeps the test and matches. Rebuilding the whole
> module at `-O4,s` took `rel_movie_viewer` from 14/16 to 15/16 with no
> regressions. Bare `-O4` gives a byte-identical object, so size is the
> default. The remaining steps below are still worth reading for technique,
> but the level question itself is settled.

The target is optimized **less aggressively** than `-O4,p`. With
`-sdatathreshold 0` fixed, try the levels on build 219 in this order, watching
whether `beqzl` becomes `beqz` and whether `$s0` appears:

```
-O2,p -sdatathreshold 0      →  -O3,p ...      →  -O1,p ...      →  -O4,s ...
```

If lowering the optimization isn't enough (the `beqzl` remains and `$s0` doesn't
appear), the problem is no longer the compiler but the **data type**: see below.

### Fourth step: the right type — `volatile` + local pointer ✅ SOLVED

No build/level went below ~37–47%. The target, in fact:
- **rereads the value twice** (once for the test, once as the argument) → the
  global is **`volatile`** (no caching of the value in a register);
- **keeps `&D` in `$s0`** (saved register), reusing it → this is achieved by
  computing the address **once into a local pointer**.

Translating exactly this gets you to **100% (score 0)**:

**Context:**
```c
extern volatile int D_0009DB00;
void func_00000CEC(int);
```

**Source (100% match):**
```c
void func_00000184(void) {
    volatile int *p = &D_0009DB00;
    if (*p != 0) {
        func_00000CEC(*p);
        *p = 0;
    }
}
```

**Compiler/flags:** `MWCC 1.3 SP7 (3.0.1 219)` + `-O4,s -sdatathreshold 0`.

> ✅ **CONFIRMED project findings** (first matched function, `func_00000184`):
> 1. **`-sdatathreshold 0`** — absolute addressing, not gp-relative.
> 2. **`-O4`** (`,p` and `,s` are equivalent on this function).
> 3. **State globals are `volatile`**: they must be accessed via a local pointer
>    `volatile int *p = &G;` to reproduce the reload + use of `$s0`.
> 4. **Build**: this function matches the whole **180–219** family
>    (MWCC 1.2 SP3 → 1.3 SP7); too simple to pin down the exact build. Default to
>    **219** (like sotn-decomp); this will narrow down with more complex functions.
>
> Project's base flag set: `-O4,s -sdatathreshold 0` (corrected from `-O4,p`
> on 2026-08-16, see "Third step" above; plus, still to be confirmed,
> `-lang c -char unsigned -fl divbyzerocheck` as in sotn-decomp — these three
> are NOT currently passed and remain untested).

## The compiler unknown (important)

### The three numbering schemes (so you don't get confused)

- TF5 binaries' `.comment`: **`MW MIPS C Compiler (2.4.1.01)`** → this is the
  version of the *compiler component* (MIPS backend).
- decomp.me shows the *product* names of CodeWarrior for PSP (**MWCC 1.0 … 1.3
  SP7**).
- In parentheses, the Metrowerks *internal build* (**3.0.1_121 … 3.0.1_219**).

These are **different axes**: `2.4.1.01` should NOT be looked for in the dropdown.
It's very likely that our compiler is **one of these builds** (same family); it
needs to be found empirically by matching a real function.

### Compilers available on decomp.me (PSP), July 2026

| Name (decomp.me) | Build | | Name (decomp.me) | Build |
|---|---|---|---|---|
| MWCC 1.0 | 3.0.1 121 | | MWCC 1.2 | 3.0.1 180 |
| MWCC 1.0 Hotfix 2 | 3.0.1 134 | | MWCC 1.2 SP3 | 3.0.1 192 |
| MWCC 1.0 Hotfix 3 | 3.0.1 139 | | MWCC 1.3 | 3.0.1 201 |
| MWCC 1.1 | 3.0.1 147 | | MWCC 1.3 SP1 | 3.0.1 205 |
| MWCC 1.1 SP1 | 3.0.1 151 | | MWCC 1.3 SP2 | 3.0.1 210 |
| | | | **MWCC 1.3 SP7** | **3.0.1 219** |

(plus `GCC 3.3.3+allegrex-2.2.1-psp-1.3.1` and `SN 1.2.7503.0` — not ours.)

### Bisection strategy

1. The **empty** function matches with almost all of them: it's not discriminating.
2. On a **real** function (Step 2), once you have the right C, try the builds in
   this order (TF5 is from 2010 → the higher builds of the 1.3 series are more
   likely): **219 → 210 → 205 → 201 → 192 → 180 → …**. Change only the compiler,
   keep the same C.
3. If **one** reaches 100% → that's (probably) ours: lock it in for the whole
   project.
4. If **none** matches even with the correct C, we need the exact build that isn't
   on decomp.me: get it separately (images from
   https://github.com/decompme/compilers `platforms/psp/`, or the original
   CodeWarrior) and switch to local matching with **wibo + mwccpsp** (see
   `03-tools.md`).

Note the outcome here as soon as you find out:

> ✅ **Update**: build **219** (MWCC 1.3 SP7) with `-O4,p -sdatathreshold 0` has now
> been confirmed on 9 real functions of `rel_movie_viewer` (not just the trivial
> empty one), verified locally with `wibo` + the real `mwccpsp_3.0.1_219` binary
> (see `docs/06-splitting-and-matching.md` "Local matching").

### ✅ Bisection performed — all 11 builds tested

The bisection planned above has now been **run exhaustively**. All 11 mwccpsp
builds were fetched and `src/rel_movie_viewer.c` compiled against each, with
every function diffed against the target
(`scripts/mwcc_bisect.sh`, flags `-O4,p -sdatathreshold 0`):

```
function        121   134   139   147   151   180   192   201   205   210   219
func_00000000    d4    OK    OK    OK    OK    OK    OK    OK    OK    OK    OK
func_00000034    -1    -1    -1    -3    -3    -5    -5    -5    -5    -5    -5
func_00000138    d9    d6    OK    OK    OK    OK    OK    OK    OK    OK    OK
func_00000184    +2    +2    +2    +2    +2    OK    OK    OK    OK    OK    OK
func_000001C8    -1    -1    -1    -1    -1    -4    -4    -4    -4    -4    -4
func_0000024C    d7    OK    OK    OK    OK    OK    OK    OK    OK    OK    OK
func_00000294   +15   +15   +17   +17   +17   +20   +15   +15   +15   +15   +15
func_00000470    +5    +5    +5    +5    +5    +6    +3    +3    +3    +3    +3
func_00000540    d4    OK    OK    OK    OK    OK    OK    OK    OK    OK    OK
func_000005C8    +6    +6    +6    +4    +4    +1    +1    +1    +1    +1    +1
func_000006BC   +10   +10   +10    +8    +8    +7    +4    +4    +4    +4    +4
func_000007C8    +2    +2    +2    +1    +1    d4    d4    d4    d4    d4    d4
(4 always-OK trivial functions omitted)  totals:  4  7  8  8  8  9  9  9  9  9  9
```

Cells: `OK` = matches, `dN` = N differing words, `±N` = word-count delta.

**Three conclusions:**

1. **Builds 121–151 are RULED OUT.** `func_00000184` — independently confirmed
   correct — is 2 words too long on all of them and matches only from **180**
   upward. That is a falsification, not a preference.
2. **Builds 192–219 are indistinguishable**: identical results in every cell.
   219 is still not proven UNIQUE, but the candidate set is now
   **{192, 201, 205, 210, 219}**. Keep 219 as the project default.
3. **Build 180 is measurably worse than 192+** on three functions (`func_00000294`
   +20 vs +15, `func_00000470` +6 vs +3, `func_000006BC` +7 vs +4). None match on
   either, so this is soft evidence — but it consistently favours 192+.

**Most important:** no build matches ANY of the 7 outstanding functions. The
remaining gap is therefore **in the C, not in the compiler build** — the
"uncontrollable MWCC codegen" notes in the header of `src/rel_movie_viewer.c`
are confirmed as the real obstacle, and switching builds is not a way around
them. Re-run `scripts/mwcc_bisect.sh` on a future module if a function ever
matches on a build other than 219; that would finally pin the build exactly.

## When a function is "done"

1. 100% on decomp.me, **or** `MATCH (N words)` from `scripts/mwcc_diff.py` (see
   `06-splitting-and-matching.md` "Local matching" — no decomp.me account needed).
2. Save the scratch (decomp.me gives you a URL) and/or bring the C back into the
   project's `src/`.
3. Tag the function's comment `MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0)`
   in `src/*.c` (in the future: tracking with frogress/objdiff).

## Generating the asm of any function

The target asm is produced by **splat** from the extracted PRX (see
`06-splitting-and-matching.md`):

```bash
. .venv/bin/activate
splat split config/rel_movie_viewer.yaml   # creates asm/…  (regenerated, not versioned)
```

In `asm/` you'll find one file per function, in the format spimdisasm/decomp.me
understand (`glabel` labels, `%hi/%lo` relocations). Copy the function you're
interested in and paste it into decomp.me. Alternatively, for a quick look, Ghidra
shows the assembly in the *Listing* (window to the left of the decompiler).

---

## Recommended practice order

1. `func_000001C0` (empty) — verify setup. ✅
2. `func_00000184` (free-and-zero) — first real logic.
3. The other small functions of `rel_movie_viewer` (`readelf`/splat lists ~14 in
   the `.text`), from shortest to longest.
4. Then move on to the other small modules and, finally, to `modehsys`/
   `rel_duel_eng`.
