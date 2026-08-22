# Matching playbook: reading a function before drafting it

What to look for when decompiling a TF5 function — everything you should know
about a function *before* the first m2c draft, and the drafting workflow that
follows. Debugging the resulting diffs is `docs/14`; the lever catalogue is
`docs/11`. The bar never moves: `scripts/mwcc_diff.py` `MATCH`, function and
whole file — the decomp.me purple check, score 0, verified locally on every
change. 100% or bust.

## 1. Pre-flight checklist (five minutes that save five hours)

Run through ALL of these before writing any C:

1. **Handwritten?** `grep -A2 'glabel func_XXXXXXXX$' asm/<m>/text.s | grep Handwritten`
   — if marked, it can never match from C. Stop; record `HANDWRITTEN`.
2. **Already solved somewhere?** `find_twins.py` — Konami shipped the same
   function at many addresses, within and across modules. An exact twin of a
   matched function is a free, verified match; a same-shape twin is a template
   needing only symbol adaptation. The deck modules (`rel_deck`,
   `rel_deckswap`, `rel_decktutorial`) and the six card-list-widget modules
   share whole source files.
3. **Family member?** Compare against the catalogue in docs/11 ("Function
   families worth recognising"): dispatcher trampolines, accessor sets on a
   shared object, the module-entry registration triple (`func_00000000` +
   main + teardown appears in at least 10 modules with the same 3-argument
   registration call). A family member starts from the family's matched
   source, not from m2c.
4. **Status already known?** `build/auto/<m>.json` records what the automated
   pass concluded; the triage block at the top of `src/<m>.c` records human
   classifications (`RETRY`/`DEADEND` with signatures). Do not re-fight a
   documented dead end without new evidence.
5. **What do the CALLERS prove?** Search the target asm for `jal <this func>`.
   Call sites pin the real arity and argument types better than any inference:
   which of `$a0..$t3` are loaded before the call, and whether `0x0($sp)` /
   `0x4($sp)` are written (args 9+ go on the stack — `infer_arity.py` is
   register-only and undercounts exactly these).
6. **What do the CALLEES tell you?** List every `jal` inside the function.
   Named engine imports (`ehsys_*`) have known NIDs and often known arities
   (`nids/ehsys_arity.csv`, `nids/func_arity/<m>.csv`). Callees already
   matched in `src/` have settled signatures — trust those over m2c's guesses.
   Prefer attacking functions whose callees are already matched (work up the
   call graph, leaves first).

## 2. Reading the target asm — the anatomy pass

Before drafting, extract these facts from the assembly:

**Prologue → frame facts.** `addiu $sp, $sp, -N` gives the frame size; the
`sw $sN` set gives the saved registers; presence of `sw $ra` distinguishes
leaf from non-leaf. A leaf with no frame is a pure expression — usually an
accessor or trampoline. Saved registers mean values live across calls: expect
locals that must survive, or the `volatile` reload pattern (§3).

**Calling convention (MIPS EABI).** Integer args 1–8 arrive in
`$a0`–`$a3`, `$t0`–`$t3`; args 9+ at `0x0($sp)`, `0x4($sp)`, …; return in
`$v0`. If the function reads `$t0`–`$t3` before writing them, it takes more
than four arguments — a fact m2c regularly misses.

**Optimization level.** A `nop` in a branch delay slot means no scheduling:
that TU was `-O2,s` → the draft needs `#pragma optimization_level 2`.
Scheduled slots, tail calls (`j` to another function) → `-O4,s`. Modules mix
both; detect per function, don't assume per module.

**Control-flow skeleton.** Count branches and map the basic blocks before
reading instructions. A `jtbl_XXXXXXXX` load + `jr` is a `switch` (the differ
verifies table contents; case ORDER in your C must produce the same table). A
backwards branch is a loop; note whether the test is at top or bottom —
MWCC's loop shape follows the source (`while` vs `do-while`).

## 3. Types: the instruction tells you the declaration

The single highest-value fact in this project: **the declared type of a
global or struct field decides the memory opcode.** Getting a type wrong is
the #1 cause of one-word diffs, and blanket-typing externs broke whole files.

| target opcode | declared type |
|---|---|
| `lb` / `sb` | `char` (signed) |
| `lbu` | `unsigned char` |
| `lh` | `short` |
| `lhu` | `unsigned short` |
| `lw` / `sw` | `int`, pointer |
| `lwc1` / `swc1` | `float` |

What to look for around globals:

- **`lui`/`addiu` pair** → address of a symbol (`-sdatathreshold 0`: absolute
  addressing everywhere, never `$gp`-relative). **`lui`/`lw`** → load of its
  value. The pattern chosen for *repeated* access is lever 9 territory
  (address rematerialisation) — see docs/11.
- **Reload instead of reuse**: the target loads the same global twice with a
  call or store between → the global is `volatile`. The matching idiom is a
  local pointer: `volatile int *p = &G; if (*p) { ... *p = 0; }` — this
  reproduces both the reloads and the saved-register usage.
- **No relocation on an address-looking constant** → the original baked the
  address; the differ's known-address table handles it (docs/14 §2.5).
- **Struct fields**: constant offsets off one base register are fields of one
  struct. Field *widths* come from the opcodes (table above). When m2c emits
  `->unkNN`, the automated pass tries `int` / `unsigned short` /
  `unsigned char` per field — do the same by hand, guided by the opcode.
- **A struct-typed parameter vs an int/pointer parameter changes codegen**
  (CSE of field loads) — if the candidate is smaller than the target around
  repeated field access, try passing the struct pointer type explicitly.

## 4. Drafting workflow

1. Slice the function from `asm/<m>/text.s` — **no leading comments in the
   `.s` given to m2c** (it chokes), context file is **declarations only**,
   symbol names **literal**.
2. m2c draft → clean to C89 (declarations first, no `//`).
3. Apply the anatomy facts from §2–3 *before* first compile: correct arity,
   correct extern flavours, pragma if `-O2,s`, volatile pattern where reloads
   are visible.
4. Compile + diff: `scripts/mwcc_build.sh` + `scripts/mwcc_diff.py`, then
   iterate per docs/14 (one lever per compile, size before contents).
5. On `MATCH`: insert via `merge_matches.py` (never `assemble_module.py` on a
   curated file), which re-verifies the WHOLE file and rolls back on any
   regression. Then `scripts/check_regressions.py` before committing.
6. Classify everything you touched (`MATCH`/`RETRY`/`DEADEND`/`HANDWRITTEN`/
   `DIFFER-BLIND`) in the module's triage block, and feed new levers to
   docs/11 in the same commit.

## 5. What NOT to spend time on

- Functions whose diff shows a **dead-end signature** (docs/14 §2.2): scratch
  register choice, `$s0`/`$s1` role swap, delay-slot lookahead, saved register
  with no visible reason, swapped argument evaluation. Classify and move on.
- **decomp-permuter grinding** — 777k iterations on a real target produced
  nothing. It is a last resort, not a loop stage.
- Functions the automated pass already exhausted, unless you bring a NEW
  lever, a newly-matched callee, or a family insight it lacked.
- Anything while its module's `make MODULE=<m>` gate is red — matches there
  rest on the differ alone and cannot be fully trusted until the config gate
  passes.

## 6. Naming and NIDs

Every import call must use its resolved name (`ehsys_XXXXXXXX`, `sce*`,
`<module>_XXXXXXXX` from `config/symbols/<m>.txt`) — never a raw stub
address. PSP NIDs are the first 4 bytes of SHA-1(name), little-endian; the
same `ehsys_*` name is the same engine function in all 28 modules, so a
signature learned in one module is a signature learned everywhere. When you
pin down what an engine import actually does (arity, types, behaviour),
record it in `nids/` — it pays out 28 times.
