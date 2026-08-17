# Reproducing the rel_movie_viewer pipeline on any module

`rel_movie_viewer` was matched by hand. This is everything that made that
possible, written down so it can be applied to any of the other 27 modules —
and so the automated loop (`scripts/auto_decomp.py`) can be understood, trusted
and extended.

## The standard

A function counts as done **only** when `scripts/mwcc_diff.py` reports `MATCH`:
recompiled with the original toolchain it is byte-for-byte identical. Anything
else — "close", "one word off", "same instruction count" — counts as nothing.
A module is done when `make MODULE=<name> SRC=1` prints OK.

## Software

| what | where | why |
|---|---|---|
| `.venv` with splat64, spimdisasm, rabbitizer | repo `.venv/` | disassembles the PRX into `asm/` and generates the linker script |
| `binutils-mips-linux-gnu` | system (`apt`) | `as` / `ld` / `objdump` / `objcopy` for relinking and diffing |
| **mwccpsp 3.0.1_219** (MWCC 1.3 SP7) | `tools/mwccpsp_3.0.1_219/` | **the original compiler.** Nothing else reproduces the code |
| **wibo** | `tools/wibo-bin/` | runs that Windows compiler binary on Linux |
| m2c | `tools/m2c/` | turns a function's assembly into a first-draft C |
| decomp-permuter | `tools/decomp-permuter/` | brute-forces source shapes when a function is 1-4 words off |
| pspdecrypt | `tools/pspdecrypt/` | decrypts `EBOOT.BIN` -> `build/EBOOT.elf` (needed once, for NIDs) |
| Ghidra + ghidra-allegrex | system | reading the EBOOT when identifying engine functions |

`scripts/setup_tools.sh` fetches wibo and mwccpsp. The compiler configuration is
**`-O4,s -sdatathreshold 0`** — size, not speed; absolute addressing, not
gp-relative. This was pinned empirically (see `docs/09-first-match.md`) and is
not negotiable.

## Scripts in this repo

| script | does |
|---|---|
| `scripts/module_survey.py` | generates a 100%-coverage splat config + a survey doc for a module |
| `scripts/resolve_nids.py` | names every import in every module (see `docs/nids/README.md`) |
| `scripts/auto_decomp.py` | the automated match loop: m2c draft -> source reshapes -> compile -> verify |
| `scripts/mwcc_build.sh` | compiles a `src/*.c` with the real compiler |
| `scripts/mwcc_diff.py` | relocation-aware diff of one function against the target |
| `scripts/asm_prepare.py` | rewrites Allegrex opcodes GNU as cannot assemble into `.word` |
| `Makefile` | relinks a whole module and checks its sha1 |

## The pipeline, per module

```bash
source .venv/bin/activate

# 1. config + disassembly + survey (once per module)
python3 scripts/module_survey.py rel_gallery
#    -> config/rel_gallery.yaml, asm/rel_gallery/, assets/rel_gallery/,
#       build/rel_gallery.ld, docs/modules/rel_gallery.md

# 2. import names (already done for all 28; re-run after editing nids/*.csv)
python3 scripts/resolve_nids.py
#    -> config/symbols/rel_gallery.txt, merged into the splat config

# 3. prove the config: relink from the disassembly, compare sha1
make MODULE=rel_gallery

# 4. automated matching pass
python3 scripts/auto_decomp.py rel_gallery
#    -> build/auto/rel_gallery.matched.json  (verified source per function)
#    -> build/auto/rel_gallery.json          (status of every function)

# 5. hand-iterate what step 4 missed, one function at a time
cd build/auto/rel_gallery
../../../tools/wibo-bin/wibo ../../../tools/mwccpsp_3.0.1_219/mwccpsp.exe \
    -c -O4,s -sdatathreshold 0 -o func_00000123.o func_00000123.c
cd -
scripts/mwcc_diff.py asm/rel_gallery/text.s build/auto/rel_gallery/func_00000123.o func_00000123

# 6. assemble src/rel_gallery.c (functions IN ADDRESS ORDER) and verify the lot
scripts/mwcc_build.sh src/rel_gallery.c
scripts/mwcc_diff.py asm/rel_gallery/text.s build/mwcc/rel_gallery.o

# 7. the real gate: rebuild the module from OUR source
make MODULE=rel_gallery SRC=1
```

## The compiler levers

MWCC treats as different several constructs a programmer would call equivalent.
This list is the whole reason `rel_movie_viewer` and `rel_html_view` matched;
`scripts/auto_decomp.py` applies the mechanical ones automatically.

1. **`switch` is not `if`.** A switch branches *into* an out-of-line case body;
   an `if` inverts the branch and inlines it, 1-2 words shorter. This holds even
   for a **single-case** switch.
2. **Case tests come out in reverse source order**, while case *bodies* stay in
   source order. To get tests 3, 2, 4, 1 write the cases 1, 4, 2, 3.
3. **A duplicated `return r;`** — once inside the failure branch, once after it
   — gives a plain `bgez`; a single shared return gives the branch-*likely* form
   with the return-value move in the delay slot.
4. **Loop rotation.** `while (f())` becomes a bottom test with an entry branch;
   an explicit `goto` loop keeps a top test.
5. **Where a value lives.** Testing a variable that is also used later puts it in
   a saved register (`bltz $s0`); testing a call's result directly tests `$v0`.
6. **Index state blobs as `int[]`** (`state[0x194D]`), not recomputed byte
   offsets — that folds the offset into each load/store immediate.
7. **Volatile globals through a local pointer** reproduce the reload behaviour of
   game state (`volatile int *p = &G;`).
8. **`__builtin_allegrex_min` / `_max`** are intrinsics, not something MWCC folds
   out of a `?:` clamp. If the target has `min`/`max`, the source called them.
9. **Pointer vs int typing decides address caching.** A global's address stored
   through `*(void **)&cfg[n]` stays in a saved register; the same value cast to
   `int` becomes a temp that gets CSE'd — or, accessed directly rather than
   through a pointer variable, re-materialised at all 31 use sites (the
   `func_00000294` trap).
10. **A dead argument register can double as a switch constant** — a call site
    that sets up no argument register is not necessarily a no-argument function.

### Found during the automated sweep (2026-08-17 night)

11. **Integer arguments 5-8 go in `$t0`-`$t3`, not on the stack.** mwccpsp uses
    an 8-register integer convention (the PSP's EABI), confirmed by an 8-argument
    passthrough test and by matched functions in `rel_tutorial`. This was behind a
    whole family of "mystery register" functions that looked unreachable from C:
    they just need more declared parameters. Probably the highest-value single
    fact on this list.
12. **Thunks.** A tiny function that shifts or masks an argument and then `j`s to
    another function is `return callee(arg0 << 6, arg1 << 6, ...)`, with the
    transform sitting in the branch delay slot. m2c cannot see a parameter that is
    forwarded without being touched, so it drops trailing arguments — add them
    back as passthroughs. These make up a large share of the UI modules.
13. **`return f(...)` versus a bare `f(...);`** decides tail call (`j`) versus
    `jal` + return. Worth a word, and 280 functions were exactly one word short.
14. **Load width follows the declared type.** A global declared `char` compiles to
    `lb`; if the target uses `lw` or `lhu`, cast at the use site
    (`*(int *)&D_XXXX`). This one silently produced false matches until the differ
    was tightened — see below.
15. **Raw baked addresses.** When the original baked an absolute address with no
    relocation, the source must be `*(int *)0xADDR`; declaring `extern int D_XXXX`
    forces a HI16/LO16 relocation and can never match.
16. **`(x << 27) >> 29` is not `(x >> 2) & 7`** — the latter folds into a single
    Allegrex `ext`, one word shorter, and can never match a `sll`+`srl` target.

17. **Not every function was compiled at -O4,s.** Some targets have an UNFILLED
    branch delay slot, or a real `jal`+stack frame where MWCC would tail-call
    optimise. Per `mwccpsp -help all`, **instruction scheduling and tail-call
    optimisation both start at level 3** — so those functions cannot have been
    built at -O4. They match at `-O2,s`.

    This does not mean changing the project's flags: `#pragma optimization_level 2`
    around the function reproduces it exactly inside the normal `-O4,s` build,
    verified on 6 functions in `rel_title`. `scripts/auto_decomp.py` now tries both
    levels and tags the shape, and the merge tooling emits the pragma
    automatically. The tell is a target whose delay slot is a `nop` that our
    version fills, or a call the target makes with `jal` that we turn into `j`.

    A related shape in the same family: a large stack frame for a trivial body
    (e.g. 0x60 bytes to hold one value) comes from a `volatile` local array —
    `volatile s32 sp[24]; sp[0] = x; return sp[0];` matched a 6-word target that
    no -O4 phrasing could reach.

18. **Signedness picks the load opcode, not just the width.** `extern char D_X`
    gives `lb`; a target using `lbu` needs `unsigned char` at the *read* site.
    The declared type governs reads as tightly as it governs stores.
19. **Boolean idioms are not interchangeable.** For a target ending in
    `sltiu $v0, $v0, 1` write `(unsigned int)x < 1`; for one using
    `sltu $v0, $zero, $v0` + `xori $v0, $v0, 1` write plain `!x`. Logically
    identical, one word apart.
20. **`(x >> n) & 1` folds into a single Allegrex `ext` at -O4.** A target with
    discrete `sll`/`srl` needs the two-shift phrasing instead:
    `((unsigned int)x << (31 - n)) >> 31`. Same family as lever 16.
21. **A narrow global type silently deletes stores.** Writing through
    `(char *)&D_X` at an offset past the declared size of `D_X` lets MWCC drop
    the store as dead. Give the global a placeholder struct big enough to cover
    every offset touched — `typedef struct { u8 pad[0x60]; } Big; extern Big D_X;`
    — then go through a local `char *`.
22. **K&R definitions keep a typed body call-compatible with `extern int f();`.**
    Writing `void f(a, b) int a; int b; { ... }` lets a function be defined with
    real types while an untyped forward declaration elsewhere in the file still
    accepts the register-forwarding tail calls that need it. Without this you
    get "too few arguments" the moment a sibling forwards registers untouched.
23. **An unprototyped `extern s32 f();` promotes float arguments to double**,
    emitting `__extendsfdf2` and a much bigger call. Always give a full
    prototype to anything taking floats.
24. **`return void_expr;` is rejected by MWCC** even though ISO C allows it. To
    get the `j` tail-call form, caller and callee must share a non-void return
    type, even when every real caller discards the value.
25. **Branch polarity is inverted more often than not.** If the instructions are
    right but the if and else bodies are swapped and the condition negated, just
    flip the condition and swap the bodies — nothing else needs to change.
26. **The rematerialisation trap runs both ways.** A local pointer variable
    forces a named global's address to be computed once and reused. But for a
    RAW literal address with no symbol, MWCC's constant folder re-CSEs the `lui`
    across independent statements, and neither `volatile`, distinct pointer
    variables, nor oversized types defeat it. Several `rel_field` functions
    (`func_0002D17C`, `func_0002DC78`, `func_0002FB4C`, `func_0001A140`,
    `func_00022708`, `func_0002D064`) are stuck on exactly this.

27. **Bitfields are real.** A counter-plus-flag global updated as
    `(x & ~0xFE) | (((f + 1) & 0x7F) * 2)` is a C bitfield in the original;
    declaring a struct with the actual bitfield members makes MWCC's own
    read-modify-write codegen reproduce the target exactly. This shape recurred
    across five or more globals in different modules.
28. **Baked-address guessing runs both ways** — and getting it wrong was the
    single highest-yield error found. Lever 15 says a word carrying no
    relocation must be `*(int *)0xADDR`; the converse matters just as much, as
    plenty of targets that *look* like baked constants do carry real HI16/LO16
    relocations and need an `extern`. Check the relocation, never the shape.
29. **Where `default:` sits textually** decides where MWCC lays out the shared
    exit block and whether the last branch's delay slot gets filled.
30. **A switch case needs an explicit `goto` to a shared return**, not
    source-level fallthrough, when its call site precedes the shared label.
31. **Signed versus unsigned `-1`** picks `addiu` or `ori` for an otherwise
    identical constant return.
32. **Assigning a global then re-reading it once through a volatile local**
    (rather than a fresh volatile read per use) matches a target that writes,
    reloads once, and then reuses the loaded value.

33. **m2c's `p->unkNN` does not compile under mwccpsp at all** — it is a hard
    error, not a mismatch, because nothing declares the struct. Rewrite it as
    `*(type *)((char *)p + 0xNN)` with the width taken from the target's actual
    load instruction. This was the single biggest source of compile failures in
    the automated pass (3,527 of ~4,900 attempts in `rel_duel_eng`), and getting
    the WIDTH right is half the value: `scripts/auto_decomp.py` forced `int`
    everywhere until it was taught to try `unsigned short` and `unsigned char`.
34. **A dummy frame without side effects**: `volatile int pad[N]; (void)pad;`
    enlarges the stack frame to match a target whose frame is bigger than its
    real locals justify, without emitting a spurious store.
35. **A caller may have to forward an argument the callee ignores.** Even when
    the callee takes no real parameters, the original source sometimes declared
    one at the call site, which changes register and callee-saved behaviour.
    Lever 10's dead-argument rule applies on the calling side too.

36. **One symbol-table entry per external identifier, file-wide.** MWCC merges
    declarations across the whole translation unit, so a new function calling a
    helper that is already declared `extern int f();` elsewhere must reuse that
    exact declaration. Adding a stricter local prototype is a redeclaration
    error, which is why lever 22's K&R definitions matter so much in practice.
37. **A dead store before a call is not dead.** `sw $a0, n($sp)` immediately
    followed by the same slot being overwritten with a call result comes from
    `s32 local = arg0; local = f(...);` — the compiler must spill the incoming
    register before the call clobbers it. Do not "simplify" it away.
38. **A chain of `beq`s against named constants is a `switch`**, not an
    if/else-if chain, even when it reads like one. Combined with lever 2
    (reverse-order case tests) this is a reliable identification.
39. **Twin functions are a two-for-one.** Several modules ship byte-identical
    functions at two addresses (`func_00002E10`/`func_0002D540`,
    `func_00002DF0`/`func_0002D520` in `rel_field`). The moment one matches, try
    the same body at its twin.

40. **A global holding a POINTER is not a global holding a struct.** For
    `D_00034484` and friends, m2c's draft re-dereferences the global at every
    field access, emitting an extra `lui`/`lw` per field. The original wrote
    `extern s32 D_XXXXXXXX;` then `char *p = (char *)D_XXXXXXXX;` once and
    indexed every field off `p`. Same idea for an accessor function: call it
    once into a local (`void *p = (void *)func_00002358();`) and index off that.
41. **Do not hoist a store out of an if/else.** Writing it once after the branch
    makes MWCC materialise an address register the target does not have; the
    original duplicated the store in both branches, exactly as m2c drafts it
    before anyone "simplifies" it. Confirmed independently in `rel_story`
    (`func_00002420`) and `rel_deckswap` (`func_000024CC`), so this is a rule
    rather than a coincidence. The tell is a target carrying two separate `lui`
    for the same symbol where one would obviously do.
42. **Two freshly-loaded globals in one address expression fix their own load
    order.** This is the precise form of what first looked like a blanket
    "commutative `addu`" dead end. `base + index * stride` is NOT generally
    unreachable — six `rel_story` functions with exactly that shape matched once
    someone tested instead of assuming. What is unreachable is the case where
    BOTH the base and the index are globals loaded in the same expression
    (`D_00034580` paired with `D_00034584`): MWCC emits the two loads in its own
    order regardless of source order, temporaries, loop phrasing or
    optimisation level. Roughly 96 `rel_story` functions sit behind this, and
    ten structural variations on the closest one (equal word count, single
    load-order diff) all produced the identical result. When one operand is a
    live local instead — a loop induction variable, say — the wall disappears.

43. **Each comparison operator has exactly one right idiom.** Lever 19
    generalises: `==`, `!=`, `<` and `>=` each need their own phrasing
    (`x == 0`, `!x`, `(unsigned)x < 1`, `!(x < K)`), because MWCC picks a
    different pair from `sltu`+`xori` / `slt`+`xori` / `slti`+`xori` /
    `xor`+`sltiu` for each. Guessing wrong costs exactly one word, every time.
44. **A frame bigger than its locals is not a free parameter.** Where a function
    passes `&local` to a helper and reads a field back, MWCC's stack layout is
    not a simple function of the declared array size; the frame offsets have to
    be matched by trying sizes. Lever 34's `volatile int pad[N]` is the blunt
    version of the same thing.

45. **A store can sit in a `jal`'s delay slot**, so it executes BEFORE the
    callee. A store appearing textually just after a `jal` in the disassembly
    must be written before that call in the C, not after.
46. **Do not cache a repeated field read across a loop.** Hoisting the recurring
    expression into a local costs an extra register and a move per call that the
    target does not have; let the redundant reload happen.
47. **A strict ANSI prototype can regress the CALLER.** Giving a function a
    prototype made MWCC insert a truncating `andi` at a call site that the
    target does not have; the K&R definition of lever 22 avoided it. When adding
    a function regresses its caller, the prototype is the first suspect.
48. **Judge a candidate by its diff, not by its shape.** An `array + i * 0x5C`
    expression that looked like the commutative-`addu` dead end (lever 42) in
    fact matched fine. Resemblance to a known dead end is not proof.

### Function families worth recognising

Several shapes recur dozens of times, so identifying one pays for itself many
times over. Recognise these before starting from m2c:

- **vec2f / vec2s struct copies** — float-pair and short-pair copy helpers
  using `lwc1`/`swc1`. Seventeen-plus in `rel_duel_eng` alone.
- **Ternary between two globals** (13 words) — `jal` a shared zero-argument
  predicate, then `beql` selecting one of two globals:
  `return pred() ? D_A : D_B;`.
- **Call-then-store-forwarded-arg** (11 words) — saves the incoming `$a0`
  across a call, forcing an `$s0` spill, then stores it to a global:
  `f(a0); D_X = a0;`.
- **Halfword-field predicates** — `!f(*(u16 *)(a0 + N), ...)` and friends. The
  single richest seam in `rel_duel_eng`; it runs through most of the module's
  per-struct-field accessors.
- **Shared-object accessors** — call an accessor once into a local, then read or
  write fixed offsets off it. Forty-one members in `rel_story`.
- **Tail-jump thunks with a delay-slot constant** — `j callee` with
  `addiu $t1, $zero, N` in the delay slot. m2c drops both the forwarded
  register and the immediate.

49. **A small `memset` was written out by hand, not called.** Where the target
    zeroes a few bytes of a local with an inlined byte-copy loop and a `beqz`
    null guard — no `jal` anywhere — declaring `extern void *memset(...)` does
    NOT make MWCC inline it; it emits the call. Writing the loop explicitly,
    `do { *p = 0; p++; } while (--n);` with an unsigned counter and a
    pre-decrement test, reproduces both the null guard and the bottom-test loop
    shape. Expect this wherever a target "calls" `ehsys_memset` with a small
    constant size but shows no call instruction.

50. **Three phrasings of a byte comparison, one right answer.** `b == CONST`,
    `(b ^ CONST) == 0` and `!(b ^ CONST)` produce `xori`+`sltiu` versus
    `sltu`+`xori`+`andi`. Same family as lever 43; try all three.
51. **A truncating `andi 0xff` needs somewhere to live.** When an existing
    `int`-typed forward declaration forces a function away from a `u8` return,
    the mask the target has only reappears if the result is assigned to an
    explicit `u8` local and returned through it. A bare boolean expression in an
    `int`-returning function skips the mask entirely.
52. **Declare a function pointer with FEWER arguments than it appears to take.**
    Several vtable thunks are typed `fn(void)` while the caller has a live
    second argument, which is what produces the silent dead-forward through an
    untouched register. Lever 35 again, through a function pointer.
53. **Early return, if/else, and if-with-trailing-return are three different
    shapes**, and which one the original used is not predictable from the logic.
    Several functions converged only after trying two or all three.
54. **Known unsolved, seen three times** (`func_0001B6BC`, `func_0002F5F0`,
    `func_000687BC`): the read-modify-write bit shape
    `byte = (byte & ~1) | (arg & 1);` always compiles with the mask and bit
    operands swapped relative to the target, under every declaration order,
    temporary and statement split tried.

55. **Not everything in a delay slot is an argument.** An instruction in a
    `jal`'s delay slot that stores through `$v0` (or any non-argument register)
    is a field store that merely shares the slot, not a second argument. Read
    WHICH register it touches before adding a parameter — one `rel_deck`
    function went from a two-word near-miss to an exact match purely by
    dropping an argument that was never there. The companion to lever 45.

56. **Arguments 9 and beyond go on the stack, and they are ordinary
    parameters.** Lever 11 covers arguments 1-8 in `$a0`-`$a3` then `$t0`-`$t3`;
    everything after that is stored to plain slots at `0x0($sp)`, `0x4($sp)`,
    ... in call order immediately before the `jal`. Declare them as normal `int`
    parameters and pass them positionally — no special idiom is needed. Seven
    `rel_duel_eng` functions were written off as "beyond the register model"
    until this was tried, and six matched on the first or second attempt.
    It applies to a function's own signature too: `func_001EED48` reads two of
    its own parameters from its caller's stack and forwards eleven onward.

    Caveat: `nids/func_arity/*.csv` is register-only, so it UNDERCOUNTS any
    callee that takes stack arguments. For a heavily-reused dispatcher the CSV's
    `max_args` is a floor, not the answer.

57. **A struct field defeats an address CSE that pointer arithmetic cannot —
    but only across a call.** Where a target reads the same field twice, once as
    a call argument and once afterwards, and keeps the base pointer untouched in
    a saved register re-deriving the offset both times, every pointer phrasing
    (`*(u16 *)((char *)a0 + 2)` repeated, `((u16 *)a0)[1]`, a local variable)
    gets folded into computing `a0 + 2` once — one instruction short, every time.
    Declaring the parameter as a pointer to a small struct and reading
    `a0->field2` twice stops the fold and matches.

    The boundary matters: the same trick does NOT work without an intervening
    call. For three consecutive float reads from a global with no call between
    them, struct field, array index and offset pointer all produce identical
    code. So this is a lever about crossing a call boundary, not about struct
    syntax being generally "stronger" than pointer syntax.

### Matching order matters: some functions unlock others

Working UP the call graph — matching leaf callees first, then their callers —
demonstrably pays off. In `rel_duel_draw`, matching `func_00031974` unlocked
three direct callers plus two more functions in the same round, because once a
callee's real signature and return type are settled the callers stop being
guesswork.

**A correction, recorded deliberately.** This section originally claimed the
mechanism was that MWCC only keeps a value in a caller-saved register across a
call when it can *see* the callee's body in the same translation unit. That was
my inference, not a tested result, and it is **wrong — or at least not
sufficient**. Retrying `func_0006E640` with its callee fully defined and visible
in the same file, across four variants (statement-sequenced, expression-nested,
K&R and ANSI prototypes, and a version calling an already-matched function three
times), MWCC still spilled to `$s0` rather than trusting `$a1`. Something else
about the original source shape is responsible and nobody has isolated it yet.

So: the practice is right, the explanation is not.

- A near-miss whose only diff is an extra spill around a call belongs on a RETRY
  list rather than the abandoned pile — cheap to re-test, and it does sometimes
  start matching as more of the call graph lands.
- Prefer working up the call graph. But do not expect callee visibility alone to
  unlock a caller; that specific claim is confirmed insufficient in isolation.
- Check a function's EXISTING call sites before assuming its arity. K&R forward
  declarations accept any number of arguments silently, so a caller elsewhere in
  the file may already prove the signature your draft is guessing at.

### A harder category than levers

Everything numbered above is a rule: a source shape that reproducibly produces a
particular codegen. There is a second category that no amount of source
restructuring has moved, where MWCC has simply made a register-allocation or
scheduling choice of its own:

- **Scratch-register choice.** `func_00000A98` in `rel_story` reaches the exact
  word count with eleven content diffs, every one of them our `$v0` against the
  target's `$at` for the same comparison scratch, plus the ordering effects that
  follow. Operand order, temporaries, compound conditions and loop-versus-flat
  control flow all leave it unchanged.
- **Two-step lookahead delay-slot filling.** `func_00011D70` reaches 49 of 53
  words, semantically exact; the extra four are MWCC re-testing the previous
  range threshold as delay-slot filler at some branch transitions but not
  others. Thirteen compile iterations over `&&`/`||` shapes, early and late base
  caching, and reordering did not reproduce it.

Recognise this category early. A near-miss whose diff is "same instructions,
different scratch register" or "extra redundant compare in a delay slot" is not
waiting for a cleverer phrasing; it needs either the literal original source or
a systematic search. Spend the time on a fresh function instead.

### A known limitation of the differ

`scripts/mwcc_diff.py` cannot verify a function whose target references a symbol
with an addend, `%hi(D_0005F900 + 0x4)`. That form is spimdisasm naming a baked
address as nearest-symbol-plus-offset, not a real ELF addend, and `norm_sym()`
has no way to equate it with a candidate that uses a different symbol at the
same absolute address (`func_00011964` in `rel_field` is the example). Such
functions are reported as non-matching even when the bytes are equivalent, so
the project's counts are a slight UNDER-estimate. That is the correct direction
to err: relaxing this check is how the differ once accepted `lb` for `lw` and
recorded 171 functions as matched that were not.

27. **Argument evaluation order is not always reachable from C.** At `-O4` MWCC's
    scheduler can evaluate a call's second argument before its first even when
    both are plain global loads with no side effects, contradicting the source
    order. Temporaries and explicit sequencing do not move it, and
    `#pragma optimization_level 2` changes the word count instead of the order.
    When a diff is nothing but two relocations swapped, this is probably why —
    it is a known dead end, not a phrasing you have not found yet.

### A function that matches alone can still fail in the file

Matching a function in isolation is not the same as matching it inside
`src/<module>.c`, and the gap was almost entirely self-inflicted:

- `scripts/merge_matches.py` injected its own block-scope externs into every
  candidate, including ones that already declared their own. The second set won,
  changed the load widths, and broke functions that had verified cleanly. It now
  skips the injection when the body already contains `extern`. That one change
  recovered 135 functions in `rel_duel_eng`.
- Those injected externs were always `char`, so any function whose target used
  `lw`/`sw` was rejected for a single word. The merge now retries `int`, `char`,
  `unsigned short` and `void *` per candidate.

What remains is genuine: a handful of candidates match on their own and still
regress a distant function in the same translation unit. Always verify the whole
file — `scripts/mwcc_build.sh` + `scripts/mwcc_diff.py` with no function
argument — and treat a per-function trial as a candidate, never as a result.

### 248 functions are hand-written assembly

spimdisasm marks them `/* Handwritten function */` in `asm/<module>/text.s` — they
use instruction patterns a compiler does not emit, so they can never be matched
from C and should eventually be carried as assembly rather than decompiled. They
are concentrated where you would expect:

| module | handwritten | | module | handwritten |
|---|---:|---|---|---:|
| `rel_duel_draw` | 121 | | `rel_shop` | 14 |
| `rel_field` | 50 | | `rel_gallery` | 6 |
| `rel_cutin_viewer` | 24 | | `rel_cardalbum` | 6 |
| 16 others | 1-4 each | | **total** | **248** |

So the matchable denominator is 13,835 functions, not 14,083 — and in
`rel_duel_draw` nearly 8% of the module is off the table for a C decompilation.
Check for the marker before spending time on a stubborn function:

    grep -A2 'glabel func_XXXXXXXX$' asm/<module>/text.s | grep -c Handwritten

### A verification bug worth remembering

`scripts/mwcc_diff.py` originally treated two words as equal whenever both
carried the same relocation kind against the same symbol — without checking the
rest of the instruction. That let `lb` pass for `lw`, and even a different
destination register, as a MATCH. It now compares the whole instruction word with
only the relocated immediate masked out. Tightening it invalidated 171 functions
that had been recorded as verified, all of which were removed. If a matching
rule ever feels generous, it probably is.

## Verification, three levels

1. **Per function** — `scripts/mwcc_diff.py`. Relocation-aware: a word matches
   if the bytes are equal *or* both sides carry the same relocation against the
   same symbol. This is the local equivalent of a decomp.me score of 0.
2. **Whole module from the disassembly** — `make MODULE=x`. Proves the splat
   config's layout is exact. 26 of the 28 modules pass today.
3. **Whole module from our source** — `make MODULE=x SRC=1`. The real gate;
   passes only when every function in the module matches.

Note what level 2 and 3 do *not* yet do: the import stubs, module tables, `.data`
and ELF metadata are carried over from the shipped module, not reconstructed.
Across the 28 modules that is 37% of the bytes. Full 100% additionally requires
generating those from source declarations (a `psp-prxgen`-style step).
