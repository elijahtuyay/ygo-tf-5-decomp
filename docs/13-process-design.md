# Process design: matching 28 modules to the byte

This document is the operating design for the rest of the project. It is
written to be handed to a fresh agent (or a fresh human) with no other context:
it audits what exists, names every known hazard, and specifies the process that
turns the remaining ~10,500 matchable functions into verified matches without
losing work to the failure modes we have already paid for once.

The ultimate goal is unchanged and non-negotiable: **a 100% byte-identical
reconstruction of every `rel_*.prx`**, and eventually of the full binaries
including the parts we currently carry over verbatim. 100% is the only
acceptable accuracy. Nothing in this design trades accuracy for speed; the
design exists to spend the speed budget where it cannot corrupt correctness.

---

## Part 1 — Audit: what exists and what state it is in

### 1.1 Confirmed ground truth

| fact | status |
|---|---|
| Compiler | MWCC 1.3 SP7 (`mwccpsp_3.0.1_219`) under wibo — confirmed on real functions |
| Flags | `-O4,s -sdatathreshold 0`; **some TUs were `-O2,s`** (unfilled delay slots prove it — see `scripts/auto_decomp.py` header). Modules are links of several TUs not all compiled alike |
| Denominator | 14,083 functions; **13,835 matchable** (248 are hand-written asm, marked `/* Handwritten function */`) |
| Progress (2026-08-18) | 3,312 functions / 124,016 bytes = 2.37% of `.text`, measured by `scripts/progress.py` (rebuild + `\bMATCH\b` only) |
| NID resolution | Done project-wide: 986 engine functions called, 275 module-to-module, 47 SDK; one shared 1729-entry table names imports in all 28 modules |
| Splat configs | All 28 modules, 100% file coverage, one `module/<name>` branch each |

### 1.2 The three verification gates (all exist, all work)

1. **Per function** — `scripts/mwcc_build.sh src/<m>.c` + `scripts/mwcc_diff.py
   asm/<m>/text.s build/mwcc/<m>.o` — relocation-aware, the local equivalent of
   a decomp.me score of 0.
2. **Module from disassembly** — `make MODULE=<m>` — proves the splat config's
   layout byte-exactly against `checksums.sha1`.
3. **Module from our C** — `make MODULE=<m> SRC=1` — the definition of done for
   a module; passes only when every function matches.

### 1.3 Tooling inventory (13 scripts, all working, with known limits)

| script | role | known limit |
|---|---|---|
| `module_survey.py` | config + split + survey doc | — |
| `resolve_nids.py` | names imports into `config/symbols/` | — |
| `mwcc_build.sh` / `mwcc_diff.py` | the match loop | cannot verify `%hi(SYM + 0x4)` addend forms (undercounts — correct direction); `KNOWN_ADDR` is a hardcoded table |
| `auto_decomp.py` | m2c draft → shape rewrites → verify | shape list is the codified lever catalogue; extend it, never fork it |
| `merge_matches.py` | add verified functions to `src/`, roll back on any regression | rediscovers data flavours by retry |
| `assemble_module.py` | rebuild a `src/` file from scratch | **destroys hand curation — use `merge_matches.py` instead on curated files** |
| `find_twins.py` | duplicate detection within/across modules; `--apply` | same-shape tier needs hand adaptation |
| `leaf_trampolines.py` | drafts C for single-call leaves | only productive in `rel_duel_eng` |
| `infer_arity.py` | arity for imports + 6,330 internal functions | register-only: **undercounts stack-arg callees (9+ args)** |
| `progress.py` | the only trusted counter | rebuilds everything (~minutes); that cost is the feature |
| `prune_module.py` | removes broken functions | previously destroyed files; now bounded + regression-tested |
| `permute.py` | decomp-permuter scaffold | 777k iterations produced zero matches — do not lean on it |

### 1.4 The knowledge base

`docs/11-reproducing-the-pipeline.md` holds 62 numbered compiler levers, the
function-family catalogue, the dead-end catalogue, and the differ's known
limitations. It is the project's real asset: every lever was paid for in
compile iterations, and `auto_decomp.py`'s SHAPES list is its executable form.
**The ratchet rule: any newly discovered lever gets a numbered entry in docs/11
and, where mechanisable, a shape in auto_decomp.py — same commit.**

### 1.5 Audit findings that need fixing (ordered by severity)

1. **The one-TU-per-module fiction is the likely root cause of the biggest
   unexplained blocker.** ~85 `rel_duel_eng` candidates match in isolation but
   regress *distant* functions when inserted (a 3-word insertion flipped two
   far-away functions from `lw`/`sw` to `lb`/`sb`). The shipped modules are
   links of **multiple TUs with different optimization levels**; our
   `src/<module>.c` compiles everything as one TU, so file-scope state
   (declared types, string pooling, `#pragma` scope) couples functions the
   original never coupled. See Part 2, workstream C.
2. **Module relink gate is red for 2 of 28** (`make MODULE=x`):
   `rel_cutin_viewer` and `rel_duel_draw` fail to link with undefined
   references to local labels (e.g. `.L0000B07C`) inside handwritten/VFPU
   regions — `asm_prepare.py` rewrites the lines gas rejects into `.word`, and
   when a rewritten line *carried* a label that a surviving branch still
   targets, the label vanishes. Until they pass, those modules have no level-2
   gate and every match in them rests on the differ alone. (Verified
   2026-08-18 by a clean-build sweep of all 28.)
3. **The Makefile's SRC and non-SRC builds share output paths**
   (`build/<m>.elf` / `build/<m>.prx`), so switching modes without
   `make MODULE=<m> clean` links stale objects — a non-SRC verify after an
   `SRC=1` run can FAIL on a correct config, and, worse, a stale *pass* is
   equally possible. Found when a full sweep reported `rel_movie_viewer` and
   `rel_html_view` failing; both pass from clean. Every verify must be
   mode-stamped or clean-built.
4. **Differ addend blindness.** `%hi(D_0005F900 + 0x4)` target forms are
   unverifiable and reported non-matching (e.g. `func_00011964`, `rel_field`).
   Fix properly (resolve both sides to absolute addresses) — never by
   loosening, which once minted 171 false matches.
5. **`src/rel_html_view.c` violates the src invariant** — it deliberately
   carries NONMATCHING `func_00000470`, so every sweep shows a phantom
   regression. Matched-only `src/` is what makes regression detection binary;
   the exception must move behind an explicit marker the tools understand.
6. **`docs/modules/README.md` carries a stale duplicate progress table**
   (2,277 total) below the current one (3,312). A fresh agent will read the
   wrong one.
7. **No regression gate at commit time.** The `rel_html_view` truncation
   (15 → 0 matched, committed silently) was only caught by a full sweep hours
   later. Nothing today stops that recurring.
8. **`KNOWN_ADDR` hardcoded in `mwcc_diff.py`** — 8 entries from 2 modules;
   will not scale to 28.
9. **37% of all bytes are carried over, not reconstructed** (import stubs,
   module tables, `.data`, ELF metadata). Real 100% needs a prxgen-style
   generation step that does not exist yet. Not urgent, but it is the visible
   end of the road and should stop being implicit.

---

## Part 2 — The process design

### 2.0 Principles (each one bought with lost work)

- **Only `scripts/progress.py` counts.** Running totals drift; they hid a
  200-function overcount in one night. Any number not produced by a fresh
  rebuild is an estimate and must be labelled as one.
- **A per-function match is a candidate, not a result.** Only the whole-file
  rebuild (`mwcc_build.sh` + `mwcc_diff.py` with no function argument) turns a
  candidate into a match; only `make MODULE=x SRC=1` finishes a module.
- **Diagnose functions individually, never as a group.** Four blanket
  exclusions ("commutative addu family", "beyond the register model", the
  `mult`/`mflo` bucket, the level-2 pragma set) were each overturned when the
  members were examined one at a time. Grouping by symptom is how reachable
  work gets lost. Groups may be used to *prioritise*, never to *exclude*.
- **When a matching rule feels generous, it is.** The differ must only ever be
  tightened; every loosening so far produced false matches (171 once). Err
  toward undercounting.
- **Recognise the dead-end category early** (docs/11 "A harder category than
  levers"): scratch-register choice, `$s0`/`$s1` role swaps, two-step
  delay-slot lookahead, unexplained saved registers, argument evaluation
  order. A near-miss with one of these signatures gets a `DEADEND` tag and no
  further hand iteration — not because it is impossible, but because the
  marginal hour is worth 3–5 matches elsewhere.
- **The docs are a ratchet, not a diary.** Corrections get recorded as
  corrections (docs/11 keeps its disproved call-graph claim, marked wrong, so
  it cannot be re-derived). Never document an inference as a tested result.

### 2.1 Phase 0 — hygiene (do once, before any new matching)

Small, closed work items; each independently committable, total well under a
day. They exist because every one of them either blocks a gate or will silently
corrupt future work.

| # | item | done when |
|---|---|---|
| 0.1 | Fix the two failing relink modules: make `asm_prepare.py` preserve any label carried on a line it rewrites to `.word` (`rel_cutin_viewer`, `rel_duel_draw`) | `make MODULE=x` passes 28/28 from clean |
| 0.2 | Separate SRC and non-SRC build outputs (`build/<m>.src.elf` vs `build/<m>.elf`, or a mode stamp forcing relink) so a mode switch can never verify stale objects | `make MODULE=x` then `SRC=1` then `MODULE=x` again all report correctly without `clean` |
| 0.3 | Differ addend fix: in `norm_sym()`, resolve `SYM + 0xN` and bare `D_XXXXXXXX`/`jtbl_XXXXXXXX` names to absolute addresses and compare *addresses*, keeping the full-instruction mask check exactly as is | `func_00011964` (rel_field) verifies; the 171-false-match regression case still fails |
| 0.4 | Move `KNOWN_ADDR` to `config/known_addr/<module>.txt`, loaded per module | table additions no longer touch the script |
| 0.5 | Add `scripts/check_regressions.py`: reads a checked-in `progress-baseline.json` (per-module matched-function *lists*, not counts, e.g. `{"rel_gallery": ["func_00000138", ...]}`), rebuilds only the modules whose `src/` changed, fails if any previously-matched function stopped matching; refresh baseline as part of every matching commit | the html_view truncation scenario cannot merge silently |
| 0.6 | Give `src/rel_html_view.c` an explicit `NONMATCHING` convention: keep the draft inside `#ifdef NONMATCHING` (excluded from the build) so `src/` returns to matched-only, and teach check_regressions to assert zero un-guarded mismatches | sweeps show 0 phantom regressions |
| 0.7 | Delete the stale progress table from `docs/modules/README.md`; make `progress.py --md` output the *only* table, with the measurement date | one table, dated |
| 0.8 | Remove stray `eboot_funcs` from the repo root (or move under `docs/nids/` if it is data worth keeping) | clean `git status` |

### 2.2 The per-module loop (the offloadable unit)

This is the state machine one agent runs against one module. It is the
rel_movie_viewer process, mechanised where safe and hand-driven where not.

**Step 1 — Prove the gates before touching anything.**
`make MODULE=<m>` must pass; run `progress.py`-equivalent for the module
(build `src/<m>.c`, diff whole file) and record the baseline list of matched
functions. If the baseline differs from `progress-baseline.json`, stop and
report — something upstream is broken, and matching on a broken base
compounds it.

**Step 2 — Survey for families before functions.** A module's yield is decided
by its shape, not its size (`rel_title`: third-largest, worst yield). In order:
`find_twins.py` (exact + same-shape tiers), `leaf_trampolines.py`,
`infer_arity.py`, the ≤16-word tier, and a read of `docs/modules/<m>.md` plus
the family catalogue in docs/11. Output of this step is a written triage: which
families exist, estimated members each, and the attack order (leaves first, up
the call graph).

**Step 3 — Automated passes, in this order, verifying after each:**
1. `find_twins.py --apply` (free matches from duplicates of already-matched code)
2. `auto_decomp.py <m>` (drafts × shape catalogue × both opt levels)
3. `merge_matches.py <m>` (insert, verify whole file, roll back per function)

**Step 4 — Hand loop on what remains**, ordered by the Step-2 triage. Per
function: check for the `Handwritten` marker first; check existing call sites
before assuming arity (K&R declarations hide it, and `infer_arity` undercounts
stack args); draft; iterate against the lever catalogue; classify.

**Step 5 — Classify every function you touch.** `build/auto/<m>.json` is
machine state; the human-readable triage lives at the top of `src/<m>.c`:

| tag | criterion | consequence |
|---|---|---|
| `MATCH` | whole-file verified | merged, baseline updated |
| `RETRY` | only diff is an extra spill/save around a call | re-test cheaply as more of its call graph lands; never abandon |
| `DEADEND` | diff has a known dead-end signature (2.0) | park with one line saying *which* signature; revisit only with new evidence |
| `HANDWRITTEN` | spimdisasm marker | carried as asm forever; excluded from denominator |
| `DIFFER-BLIND` | target uses an addend form the differ can't check | fixed by 0.3; until then, park, do not hand-wave a match |

**Step 6 — Commit discipline.** Name specific files (`git add src/<m>.c` — the
blanket `git add -A src/` swept a mid-edit file and a truncated file into
commits). Conventional commits with the module as scope. Run
`check_regressions.py` before every commit; refresh the baseline in the same
commit as the matches it reflects.

**Step 7 — Feed the ratchet.** New lever → numbered docs/11 entry + SHAPES
entry. New family → catalogue entry. New dead-end signature → dead-end list.
Wrong assumption disproved → recorded as a correction, not silently edited.

**Definition of done for the module:** `make MODULE=<m> SRC=1` prints OK, plus
a `HANDWRITTEN`/`DEADEND` appendix accounting for every non-C function.

### 2.3 Module priority

Ordered by expected yield per hour, using what the overnight run measured:

1. **Close the almost-done**: `rel_movie_viewer` and `rel_html_view` (1
   function each — both currently `DEADEND`-adjacent; timebox, do not grind),
   `rel_tutoriallist` (8 remaining of 30 matchable), `rel_labo`,
   `rel_soundtest`. Finished modules prove the `SRC=1` gate end-to-end, which
   nothing has yet.
2. **The ≤16-word tiers of `rel_duel_draw` (595) and `rel_story` (336)** — the
   densest matchable veins outside the engine.
3. **The shared card-list widget** (`rel_limitlist` or `rel_recipeviewer`
   first): six modules statically link the same code; matching it once
   transfers to `rel_deck` (8× bigger), `rel_deckswap`, `rel_decktutorial`,
   `rel_select_card`, `rel_conv_machine`.
4. **`rel_duel_eng` families** — trampolines around the three dispatchers, and
   whatever workstream C (below) unblocks. It is 56% of all code and the
   actual point of the project; everything above is leverage-building for it.
5. **`rel_title` last among the big ones** — surveyed, family-poor, its one
   vein mined out.

### 2.4 Workstream C — the TU-boundary investigation (highest-leverage open problem)

The ~85 match-alone-regress-distant candidates in `rel_duel_eng` are blocked on
physics we don't understand, and the one-giant-TU layout is the prime suspect.
Design:

1. **Bisection harness** (mechanical, agent-safe): given a candidate that
   regresses distant functions, binary-search the *file prefix* it is inserted
   after, to find the minimal pair (existing declaration/function ↔ candidate)
   that reproduces the flip. The overnight example — 3-word `func_00000578`
   flipping load widths in two distant functions — is the first test case.
2. **Recover the original TU boundaries.** Evidence available without source:
   alignment padding between functions, `.rodata`/string-pool locality,
   opt-level changes mid-module (delay-slot fill patterns), `jtbl` placement
   runs, and the address ranges the `-O2,s` functions cluster in. Produce a
   per-module partition hypothesis: `src/<m>/tu_00.c … tu_NN.c`.
3. **Split `src/rel_duel_eng.c` along the hypothesis** and re-run the 85
   parked candidates. The build already links multiple objects; the Makefile
   change is small. Success criterion: candidates that matched alone match in
   their TU.
4. If confirmed, apply the same split to every module with `-O2,s` islands and
   record the method in docs/11 — it converts an unexplained blocker into a
   named lever.

This workstream is the one to keep on the strongest model; it is research, not
mechanical iteration.

### 2.5 Workstream D — the endgame: full-file reconstruction

37% of bytes are carried blobs. When modules start passing `SRC=1`, the next
gate is generating those bytes from source: `.lib.stub`/`.lib.ent` and the NID
table from import/export declarations (`resolve_nids.py` already has the data),
`.data` from splat-extracted initialisers, module info + ELF layout from a
prxgen-style emitter. Design it as one script (`scripts/emit_module.py`) proved
first on `rel_movie_viewer`, gated by the same sha1. Do not start this before
at least one module passes `SRC=1` — it layers a second unknown onto an
unproven gate.

---

## Part 3 — Offloading protocol (running this with Sonnet/Opus agents)

One module per agent, `src/<module>.c` owned exclusively by its agent for the
session — the file is the unit of conflict. The orchestrator only merges via
`check_regressions.py`.

Every offloaded agent reads three companion docs before starting:
`docs/14-debugging-playbook.md` (how to debug every run),
`docs/15-matching-playbook.md` (what to look for in a function before
drafting), and `docs/16-testing-methodology.md` (the gate cadence and
regression protocol).

Hard rules for every agent prompt, verbatim — each traces to a real incident:

1. Never run anything in the background (`&`, `nohup`, monitor-and-wait). Five
   agents lost entire sessions this way.
2. `grep '\bMATCH\b'`, never `grep MATCH` — the latter also matches
   `SIZE MISMATCH` and burned three agents.
3. A function verified alone is a candidate. Only the whole-file diff counts;
   only `make MODULE=x SRC=1` finishes a module.
4. `git add` names specific files. Never `-A`, never a directory.
5. Never loosen `mwcc_diff.py`. If a rule feels generous, it is.
6. Never exclude a group of functions for a shared symptom. Park individuals
   with individual diagnoses.
7. Check for `/* Handwritten function */` before spending time on any stubborn
   function.
8. Never commit ISOs, `.prx`, EBOOT, extracted assets, `iso_extracted/`,
   `build/`, `asm/`. Push only to `fork`, never `origin`.
9. Report numbers only from `scripts/progress.py`; label everything else an
   estimate.
10. New levers/families/dead-ends go into docs/11 in the same commit as the
    match that revealed them.

Agent tiering: mechanical steps (2.2 step 3, twin application, RETRY re-tests,
baseline refreshes) are Sonnet-shaped; the hand loop on non-family functions is
Opus-shaped; workstream C stays on the strongest available model. Every agent's
deliverable is: commits on its module branch, an updated triage block, and a
short report of levers found and dead-ends hit — *the report is input to
docs/11, not a substitute for it*.

---

## Part 4 — What "done" looks like, measured

| milestone | gate |
|---|---|
| M1 | 28/28 pass `make MODULE=x`; regression gate live; differ addend-fixed |
| M2 | First module passes `make MODULE=x SRC=1` (proves the full loop end-to-end) |
| M3 | All small-tier modules (≤100 funcs) pass `SRC=1` or have complete DEADEND/HANDWRITTEN appendices |
| M4 | TU-boundary method confirmed or refuted on rel_duel_eng's 85 parked candidates |
| M5 | `rel_duel_eng` majority-matched; card logic readable |
| M6 | First module byte-perfect with *zero* carried blobs (workstream D proved) |

Progress is bytes, not function counts, and it is whatever
`scripts/progress.py` printed most recently — nothing else.
