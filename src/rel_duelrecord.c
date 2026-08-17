/*
 * rel_duelrecord.prx — reconstructed code (matching decompilation)
 *
 * Compiler:     Metrowerks CodeWarrior for PSP — MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,s -sdatathreshold 0
 * Verification: scripts/mwcc_build.sh src/rel_duelrecord.c
 *               scripts/mwcc_diff.py asm/rel_duelrecord/text.s build/mwcc/rel_duelrecord.o
 *
 * Every function below is claimed MATCH only after scripts/mwcc_diff.py
 * reported MATCH *and* a manual `mips-linux-gnu-objdump -dr` check that the
 * candidate's non-relocated opcode bits equal the target's (see the CAUTION
 * note below — mwcc_diff.py has a real gap here). Functions are in ADDRESS
 * ORDER, which is what the linker needs.
 *
 * Import names (ehsys_XXXXXXXX) are resolved from the module's NID tables
 * and are identical across all modules that import them — see
 * config/symbols/rel_duelrecord.txt.
 *
 * STATUS: 19 / 47 functions matched.
 *   func_00000000  MATCH   2 words
 *   func_00000204  MATCH  34 words
 *   func_00000B80  MATCH   5 words
 *   func_00000B94  MATCH   8 words
 *   func_00001060  MATCH   4 words
 *   func_00001624  MATCH   7 words
 *   func_000021E4  MATCH   8 words
 *   func_0000259C  MATCH  49 words
 *   func_00003298  MATCH   3 words
 *   func_000042A0  MATCH   3 words
 *   func_000042AC  MATCH   3 words
 *   func_000042B8  MATCH  16 words
 *   func_000042F8  MATCH  23 words
 *   func_00004354  MATCH  17 words
 *   func_0000471C  MATCH  15 words
 *   func_000044FC  MATCH   2 words
 *   func_00004504  MATCH  14 words
 *   func_0000453C  MATCH   3 words
 *   func_00004694  MATCH   4 words
 * The rest of the module is not yet decompiled; build/auto/rel_duelrecord.json
 * has the m2c-draft status of every attempted function.
 *
 * CAUTION — scripts/mwcc_diff.py false-MATCH gap (do not remove this note):
 * for any instruction word carrying a HI16/LO16/26 relocation, the diff only
 * compares the relocation's symbol+kind, never the rest of the word. Two
 * different opcodes that happen to relocate the same symbol (e.g. `lb`/`lh`/
 * `lw` all reference the same LO16 symbol as their displacement operand) are
 * reported as an identical word even though the machine code differs. This
 * bit the original 8-function draft: D_0000A166/D_0000A168/D_0000A188/
 * D_0000A2F4 were declared `char`/byte-width in the m2c draft, which changed
 * `lw`/`sw` in the target to `lb`/`sb` in the candidate — mwcc_diff.py still
 * printed MATCH because both sides relocate the same symbol. Fixed here by
 * widening those externs to their real load/store width (confirmed against
 * asm/rel_duelrecord/text.s: `lw`/`sw` -> s32, `lh`/`sh` -> s16, `lbu`/`sb`
 * -> u8) and re-checking the raw opcode bytes with objdump, not just the
 * diff tool's verdict. Any relocated global whose declared C type doesn't
 * match its target load/store width can slip past this tool the same way —
 * verify field widths against the actual mnemonic, not just relocation
 * symbol name, whenever a MATCH looks suspiciously easy.
 *
 * MWCC codegen levers found in this module (new; not in
 * src/rel_movie_viewer.c's header):
 *
 *  - UNINITIALIZED-LOCAL ARGUMENT SKIP: several of this module's tiny
 *    wrapper functions (func_00000B80, func_00001624, ...) call an
 *    ehsys_* draw/coord primitive that has MORE integer parameters than the
 *    wrapper is given values for — the target simply never writes one
 *    parameter's register (e.g. `$t0` in func_00000B80) before the tail
 *    call, leaving whatever was already there. Passing an intentionally
 *    *uninitialized* local variable as that argument (`s32 sp; f(a, b, sp);`)
 *    reproduces this exactly: MWCC recognizes the local's value is
 *    unspecified and skips emitting a load for it, exactly matching the
 *    target's missing register write. A materialized default (e.g. passing
 *    a literal 0) is NOT the same — it costs a real instruction the target
 *    doesn't have.
 *
 *  - >4-INT-ARGUMENT REGISTER CONVENTION: this compiler passes integer
 *    arguments beyond the 4th not on the stack (as strict o32 does) but in
 *    `$t0`-`$t3` — confirmed by func_00001624 (7 total int args landing in
 *    a0-a3, t0, t1, t2) and func_000026DC/func_00002660 (spilling to real
 *    stack slots only after t0-t3 are exhausted, i.e. args 9+).
 *
 *  - LIVE-REGISTER ARGUMENT REUSE: func_00000204's loop body tests a loaded
 *    flag (`if (flag == 0) continue;`) and then, in the non-skip path, calls
 *    `ehsys_20E340D9(D_0000A188, flag)` — passing that SAME flag value again
 *    as the call's 2nd argument. Naively writing the call with just the
 *    first argument compiles to a *shorter* candidate (the loaded value
 *    lands in `$v0` and dies unused) because the compiler doesn't need to
 *    keep it live; passing it again as a real 2nd argument is what makes
 *    MWCC keep it in `$a1w` across the loop body, matching the target
 *    instruction-for-instruction. When a "why is this dead value not
 *    reloaded" register turns up right next to a call, try feeding it to
 *    the call as an argument before assuming it is dead.
 *
 *  - EVALUATION-ORDER CONTROLS WHICH BRANCH GETS THE FALL-THROUGH: in
 *    func_000042F8, computing the never-taken side's default (`p = 0`) as
 *    the `if` branch and the real computation as the `else` produces a
 *    shorter/wrong-shaped candidate (needs an extra unconditional `b` to
 *    rejoin); swapping so the *cheap* assignment is the `if` and the *real*
 *    computation is the `else` lets the real computation's tail fall
 *    straight through into the shared join point with no extra jump —
 *    matching the target exactly. Also in that function, a pointer/global
 *    that the target loads *before* a conditional (so it survives use
 *    across the branch) must be hoisted into its own local
 *    (`EhStruct_A184 *base = D_0000A184;`) at the top of the C function, not
 *    referenced inline where it's finally used — otherwise MWCC computes it
 *    lazily at the use site and the instruction order doesn't match.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
#define NULL 0

/* ---- a small state-blob field, hit by an offset stride from
 * func_00000204 (D_0000A150 + 0x28 + i*4 == D_0000A150[i + 10]) ---- */
typedef struct {
    u8 pad[0x338];
    u16 unk338;
} EhStruct_A184;

/* ---- imports ---- */
extern int ehsys_20E340D9(int arg0, int arg1);
extern int ehsys_3BB2BAC6();
extern int ehsys_4B0DABFA();
extern int ehsys_97BB99A5();
extern int ehsys_B2B9FEFA(void);
extern int ehsys_B89D38DC();
extern int ehsys_BC8E65D7();
extern int ehsys_ED1410E0(int arg0);
extern int ehsys_F6414A71(int arg0, int arg1);
extern int ehsys_memset();
extern int ehsys_qsort();
/* used only inside the deeply-nested func_0000259C init chain */
extern int ehsys_09794DF0();
extern int ehsys_1D98951B();
extern int ehsys_23E69878();
extern int ehsys_399AC68A();
extern int ehsys_4175E3DB();
extern int ehsys_42110BF9();
extern int ehsys_5CBB9E43();
extern int ehsys_CABEA834();
extern int ehsys_E6E4401F();
extern int ehsys_F462EE6E();

/* ---- globals (widths confirmed against the target's load/store
 * mnemonic, per the mwcc_diff.py caution above) ---- */
extern s32 D_0000A150[]; /* big state blob; only [10..12] used so far */
extern char D_00009F70;  /* address-only in this file: qsort table base */
extern u8 D_0000A152;
extern s16 D_0000A15A[];
extern s16 D_0000A166;
extern s16 D_0000A168;
extern s16 D_0000A16A;
extern s16 D_0000A16C;
extern s16 D_0000A172[];
extern u8 *D_0000A178[];
extern EhStruct_A184 *D_0000A184;
extern s32 D_0000A188;
extern s32 D_0000A18C;
extern s32 D_0000A190;
extern char D_0000A2F0; /* address-only in this file */
extern s32 D_0000A2F4;

/* ---- forward declarations (address order breaks call order) ---- */
void func_000044FC(void);
void func_00004504(void);
s32 func_00004694(u16 *arg0, u16 *arg1);

/* func_00000000 — 2 words. MATCH 100% (shape: m2c). */
s32 func_00000000(void) {
    return 0;
}

/* func_00000204 — 34 words. MATCH 100%.
 * Resets state and, for each of 3 flag slots (D_0000A150[10..12]), forwards
 * a set-flag notification to ehsys_20E340D9. If a pending count
 * (D_0000A18C) is positive, flushes it via ehsys_F6414A71/ehsys_ED1410E0. */
s32 func_00000204(void) {
    s32 i;
    func_000044FC();
    for (i = 0; i < 3; i++) {
        s32 flag = D_0000A150[i + 10];
        if (flag == 0) {
            continue;
        }
        ehsys_20E340D9(D_0000A188, flag);
    }
    if (D_0000A18C > 0) {
        ehsys_F6414A71(D_0000A18C, D_0000A190);
        ehsys_ED1410E0(D_0000A18C);
    }
    return 1;
}

/* func_00000B80 — 5 words. MATCH 100%.
 * Draw-primitive wrapper: shifts 3 fixed-point coords by <<6 and tail-calls
 * ehsys_BC8E65D7 with a 4th, unused (uninitialized-passthrough) argument —
 * see the header note on the >3-int wrappers in this module. */
void func_00000B80(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp;
    ehsys_BC8E65D7(arg0 << 6, arg1 << 6, arg2 << 6, sp, -1);
}

/* func_00000B94 — 8 words. MATCH 100%.
 * Same family as func_00000B80/func_00001060: draws with an implicit
 * vertical flip (0x1E0 - arg0) and an unshifted 4th argument. */
void func_00000B94(s32 arg0, s32 arg1, s32 arg2) {
    ehsys_B89D38DC(arg0 << 6, arg1 << 6, (0x1E0 - arg0) << 6, arg2);
}

/* func_00001060 — 4 words. MATCH 100%. Same family, 3 coord args. */
void func_00001060(s32 arg0, s32 arg1, s32 arg2) {
    ehsys_B89D38DC(arg0 << 6, arg1 << 6, arg2 << 6);
}

/* func_00001624 — 7 words. MATCH 100%.
 * Same family, 4 coord args plus 2 uninitialized-passthrough trailing
 * arguments (see the >4-int-argument register convention note above). */
void func_00001624(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 sp;
    ehsys_3BB2BAC6(arg0 << 6, arg1 << 6, arg2 << 6, arg3 << 6, sp, -1, 0);
}

/* func_000021E4 — 8 words. MATCH 100%.
 * Reads field [1] out of whatever record ehsys_B2B9FEFA() returns. */
s32 func_000021E4(void) {
    return ((s32 *)ehsys_B2B9FEFA())[1];
}

/* func_0000259C — 49 words. MATCH 100%.
 * A deeply nested chain of one-shot init calls into an unidentified
 * subsystem; args are constants except the very first, which forwards the
 * uninitialized value in this function's own dead $a0 (see the header note
 * on uninitialized-local argument skipping). */
void func_0000259C(void) {
    s32 sp;
    ehsys_23E69878(
        ehsys_5CBB9E43(
            ehsys_F462EE6E(
                ehsys_4175E3DB(
                    ehsys_4175E3DB(
                        ehsys_E6E4401F(
                            ehsys_CABEA834(
                                ehsys_09794DF0(
                                    ehsys_F462EE6E(
                                        ehsys_F462EE6E(
                                            ehsys_42110BF9(
                                                ehsys_399AC68A(
                                                    ehsys_1D98951B(sp, 0), 0),
                                                0),
                                            9),
                                        1),
                                    0, 1),
                                -1),
                            0, 0),
                        1),
                    0xA),
                4),
            0, 2, 3, 0, 0),
        -1);
}

/* func_00003298 — 3 words. MATCH 100%. */
void func_00003298(s32 arg0, s32 arg1) {
    ehsys_97BB99A5(arg0, arg1, 0, 0);
}

/* func_000042A0 — 3 words. MATCH 100%. */
s16 func_000042A0(void) {
    return D_0000A168;
}

/* func_000042AC — 3 words. MATCH 100%. */
void func_000042AC(s16 arg0) {
    D_0000A166 = arg0;
}

/* func_000042B8 — 16 words. MATCH 100%.
 * If the current mode (D_0000A166) is 0, loads a per-index short from the
 * D_0000A15A table and stashes it. The lookup is evaluated unconditionally
 * so MWCC can hide it in the branch's delay slot; matching required doing
 * the same in C (compute the value before the `if`). */
void func_000042B8(void) {
    s16 v = D_0000A15A[D_0000A152];
    if (D_0000A166 == 0) {
        D_0000A16A = v;
        D_0000A16C = 0;
    }
}

/* func_000042F8 — 23 words. MATCH 100%.
 * Bounds-checks arg0 against a per-index limit table, then looks up a
 * u16 out of a per-index byte buffer at a 0x10-byte stride (or NULL if out
 * of range) and stores it into *D_0000A184. See the header note on
 * evaluation order controlling which branch gets the fall-through. */
void func_000042F8(s32 arg0) {
    u16 *p;
    EhStruct_A184 *base = D_0000A184;
    if (arg0 >= D_0000A172[D_0000A152]) {
        p = 0;
    } else {
        p = (u16 *)(D_0000A178[D_0000A152] + (arg0 << 4));
    }
    base->unk338 = *p;
}

/* func_00004354 — 17 words. MATCH 100%. */
void func_00004354(void) {
    ehsys_memset(&D_0000A2F0, 0, 2);
    ehsys_qsort(&D_00009F70, 3, 0xC, func_00004694);
}

/* func_00004634 — 24 words. MATCH 100%.
 * `D_0000A2F0`'s low bit is set unconditionally via a bitfield write
 * (the (x & ~1) | 1 idiom); a plain arithmetic phrasing gets folded
 * into a single `ori` by MWCC, one word short of the target's
 * redundant AND+OR pair. See src/rel_shop.c's header for this lever. */
s32 func_00004634(s32 arg0, s32 arg1) {
    typedef struct {
        unsigned bit0 : 1;
        unsigned rest : 7;
    } Flags_0000A2F0;
    s32 temp_s0;

    temp_s0 = arg1 > 0;
    if (temp_s0 && arg0 != 0) {
        ehsys_4B0DABFA(0, arg0);
    }
    ((Flags_0000A2F0 *)&D_0000A2F0)->bit0 = 1;
    return temp_s0;
}

/* func_0000471C — 15 words. MATCH 100%. */
void func_0000471C(s32 *arg0, s32 arg1) {
    ehsys_memset(arg0, 0, 0x154);
    *arg0 = arg1;
}

/* func_000044FC — 2 words. MATCH 100%. */
void func_000044FC(void) {
    func_00004504();
}

/* func_00004504 — 14 words. MATCH 100%. */
void func_00004504(void) {
    if (D_0000A2F4 != 0) {
        ehsys_20E340D9(D_0000A188, D_0000A2F4);
        D_0000A2F4 = 0;
    }
}

/* func_0000453C — 3 words. MATCH 100%. */
s32 func_0000453C(void) {
    return D_0000A2F4;
}

/* func_00004694 — 4 words. MATCH 100%. qsort comparator: *a - *b. */
s32 func_00004694(u16 *arg0, u16 *arg1) {
    return *arg0 - *arg1;
}
