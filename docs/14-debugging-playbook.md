# Debugging playbook: from diff to diagnosis

How to debug **every run** of the match loop. This is procedure; the lever
catalogue it dispatches into is `docs/11-reproducing-the-pipeline.md`, and the
guide to reading a function *before* drafting it is `docs/15`. The standard is
absolute: a function is matched when `scripts/mwcc_diff.py` prints `MATCH` for
it **and** for the whole file — the local equivalent of pasting on decomp.me
and getting the purple check, score 0. There is no partial credit, no "close
enough", and nothing non-MATCH is ever recorded as matched. 100% or bust.

## 0. The trust chain — know what each output actually proves

| output | proves | does NOT prove |
|---|---|---|
| `mwcc_diff.py` per-function `MATCH` | this function, compiled alone or in the current file, is byte/reloc-identical | that it stays matched inside the full `src/<m>.c` (file-scope state couples functions) |
| `mwcc_diff.py` whole-file, all `MATCH` | every function in the TU matches | the module links and lays out correctly |
| `make MODULE=<m>` OK | splat config layout is byte-exact | anything about our C |
| `make MODULE=<m> SRC=1` OK | the module is done | the carried blobs (stubs, `.data`, metadata) are reconstructed |

Corollaries, each paid for once:
- **A per-function match is a candidate.** Only the whole-file diff (`mwcc_build.sh` + `mwcc_diff.py` with no function argument) makes it a result.
- **`grep '\bMATCH\b'`, never `grep MATCH`** — the latter also matches `SIZE MISMATCH` and has burned three agents.
- **SRC and non-SRC builds write different outputs** (`build/<m>.src.prx` vs `build/<m>.prx`). If you ever see a verify result that contradicts a clean build, `make MODULE=<m> clean` and re-run before believing anything.
- **Never loosen `mwcc_diff.py`.** Every historical loosening minted false matches (171 once). If it reports a diff you believe is spurious, the differ has a *named* blind spot (§5) or you are wrong — and outside the addend form, assume you are wrong.

## 1. Debug the run before the diff

In order, on every run:

1. **Did mwccpsp actually compile?** Check the exit status and stderr of
   `scripts/mwcc_build.sh`. A syntax error means the diff you are reading is
   against a stale `.o`. Illegal-in-C89 constructs (declarations after
   statements) are the usual cause.
2. **Is the function in the object?** `NOT COMPILED` from the differ means the
   name is missing from the `.o`: typo in the name, or the whole file failed
   to build (see 1).
3. **Are you diffing the right target?** The target is
   `asm/<module>/text.s`. If `asm/` was re-split recently, symbol names may
   have changed (imports get named once `config/symbols/` lands).
4. **Is the function even matchable?**
   `grep -A2 'glabel func_XXXXXXXX$' asm/<m>/text.s | grep -c Handwritten` —
   248 functions are hand-written assembly and can never match from C. Check
   this before any effort, not after an hour.

## 2. The diff decision tree

`mwcc_diff.py` emits a small set of line shapes. Each one has an ordered cause
list; work top-down, change ONE thing per compile, and keep a note of what
moved (a change that makes the diff worse is information, not failure).

### 2.1 `SIZE MISMATCH target=N candidate=M`

Structure is wrong before contents matter. In order of likelihood:

1. **Arity wrong.** Check existing call sites in the target asm — a caller
   already proves how many args are passed. Remember args 9+ go on the stack
   (`0x0($sp)`, `0x4($sp)`), and `infer_arity.py` is register-only so it
   *undercounts* exactly those. K&R declarations accept any arg count silently.
2. **Optimization level.** An unfilled branch delay slot (`nop` after a
   branch) in the target means that TU was `-O2,s` — try
   `#pragma optimization_level 2`. Scheduling and tail-call optimization start
   at level 3.
3. **Missing or extra statements** — usually a duplicated `return`, an early
   exit, or a store the draft folded away. Compare basic-block counts (count
   the branches) before staring at instructions.
4. **Candidate much smaller:** MWCC deleted code you wrote as dead, or CSE'd a
   reload the original kept — see the `volatile` local-pointer lever.
5. **Candidate much larger:** you blocked an optimisation the original had —
   often a struct-typed parameter vs separate loads.

### 2.2 Raw word diff: `[i] target=0x… (op) candidate=0x… (op)`

Decode both instructions and classify:

| what differs | diagnosis | action |
|---|---|---|
| load/store **width** (`lb`/`lbu`/`lh`/`lhu`/`lw`) | declared type of the global/field is wrong | see the width table in docs/15 §3; fix the `extern` flavour or struct field type |
| same op, **operands swapped** (`addu a,b,c` vs `addu a,c,b`) | operand order in the source expression | swap the C operands; if it refuses, check the `byte = (byte & ~1) \| (arg & 1)` dead-end in docs/11 |
| same ops, **different scratch register** (`$at` vs `$v0`, `$s0`/`$s1` roles swapped) | **DEADEND signature** — register allocation, not source shape | tag `DEADEND`, park with one line, move on |
| an extra/missing **spill around a call** | callee signature or visibility; often resolves as more of the call graph matches | tag `RETRY`, re-test later; do not grind now |
| extra **compare in a delay slot** | two-step lookahead filling — **DEADEND signature** | tag `DEADEND` |
| `lui`/`addiu` pair where you have one instruction (or vice versa) | address materialisation vs rematerialisation — the MWCC -O2+ propagation trap (docs/11 lever 9) | restructure with a local pointer / block the propagation |
| two **relocations swapped** with nothing else | argument evaluation order — **DEADEND** (docs/11 item 27) | tag `DEADEND` |

### 2.3 `SAME RELOC but different instruction`

The symbol is right, the instruction around it is not. Almost always a width or
signedness problem on the referenced global (the declared type sets the
opcode). Occasionally a wrong destination register — which is the spill/scratch
case above.

### 2.4 `RELOC MISMATCH target=… vs candidate=…`

1. You referenced the **wrong symbol** — nearest-named vs actual. Check the
   address encoded in the `D_XXXXXXXX` name against the target's `%hi/%lo`.
2. Target uses an **addend form** `%hi(SYM + 0x4)` — the differ's known blind
   spot (§5). Tag `DIFFER-BLIND`; do not hand-wave it as matched and do not
   loosen the differ.
3. `jtbl_` mismatches are usually fine — the differ verifies jump tables by
   contents and says so; a real `JUMP TABLE CONTENTS DIFFER` means your switch
   cases are in the wrong order or a case body was merged.

### 2.5 `candidate has reloc … but target raw word=0x…`

The original **baked the global's address as an absolute constant with no
relocation**. If the symbol is in the known-address table the differ checks the
immediates; if it reports "unknown addr", add the symbol (its address is in its
name) to the table — that is a differ-data fix, not a loosening.

### 2.6 `target has reloc … but candidate raw word (missing relocation!)`

You wrote a literal constant where the original referenced a symbol. Replace
the magic number with the extern.

## 3. Iteration discipline

- **Size first, contents second.** Never tune instruction diffs while the word
  count is wrong.
- **One lever per compile.** Two changes that jointly fix a diff teach you
  nothing and poison the docs/11 entry you will write.
- **Prologue/epilogue first.** Frame size and the saved-register set are
  decided by call presence and live ranges; if they are wrong, everything
  after them is noise. Fix by adding/removing calls, locals, or `volatile`
  reload pressure — not by tweaking body expressions.
- **Check the family before the function.** If this function resembles one
  already matched (accessor, trampoline, twin), start from that source, not
  from m2c. `find_twins.py` knows.
- **Timebox.** A function that resists 10–15 focused iterations with no
  progress on the diff *signature* (not just the count) gets classified
  (`RETRY`/`DEADEND` with the signature named) and parked. The marginal hour
  is worth 3–5 matches elsewhere. Parked ≠ abandoned: `RETRY` items are
  re-tested cheaply as their call graph lands.
- **Never exclude a group.** Classify each function by its own diff. Every
  blanket exclusion so far ("commutative addu family", "beyond the register
  model", the `mult`/`mflo` bucket) was overturned when members were examined
  individually.

## 4. "It matched alone but broke the file" — the bisection procedure

File-scope state (extern flavours, string pooling, pragma scope) couples
functions the original never coupled, because our TU layout is not the
original's. When `merge_matches.py` rolls a candidate back, or a whole-file
diff regresses a function you did not touch:

1. Reproduce minimally: insert ONLY that candidate into the file; whole-file
   diff; list exactly which functions flipped and how (usually load widths).
2. Bisect the file: keep the candidate, delete the *bottom* half of the other
   functions, re-diff; binary-search to the minimal pair
   (candidate ↔ one existing declaration/function) that reproduces the flip.
3. The colliding piece is almost always a **shared extern with two different
   flavour needs** — which means one of the two typings is wrong, or the
   functions belonged to different TUs originally (docs/13, workstream C).
4. Record the pair in the module's triage block. Do not force the candidate
   in; do not silently drop it.

## 5. When the differ is the bug (the complete list)

Exactly two known blind spots; anything else is your code:

1. **Addend forms** `%hi(SYM + 0xN)` — spimdisasm naming a baked address as
   nearest-symbol-plus-offset. Reported as non-matching even when equivalent.
   Tag `DIFFER-BLIND`, park until the addend fix (docs/13 item 0.3) lands.
2. **Unknown baked addresses** — §2.5; fix by adding the symbol to the
   known-address data, never by relaxing comparison logic.

The differ has been generous before and it cost 171 false matches. The
asymmetry is deliberate: it may undercount, it must never overcount.

## 6. Leaving the run better than you found it

Every debugging session ends with the ratchet, in the same commit:

- New lever proven (a source shape that reproducibly moves codegen) → numbered
  entry in docs/11 + a shape in `auto_decomp.py`'s SHAPES.
- New dead-end signature → docs/11's dead-end list.
- A disproved assumption → recorded as a correction, never silently edited.
- The module's triage block at the top of `src/<m>.c` updated with every
  classification you made.

An agent's chat report is input to the docs, not a substitute for them.
