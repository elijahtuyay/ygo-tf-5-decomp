/*
 * rel_charalist.prx — reconstructed code (matching decompilation)
 *
 * Compiler:     Metrowerks CodeWarrior for PSP — MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,s -sdatathreshold 0   (same config confirmed on rel_movie_viewer)
 * Verification: scripts/mwcc_build.sh src/rel_charalist.c
 *               scripts/mwcc_diff.py asm/rel_charalist/text.s build/mwcc/rel_charalist.o
 *
 * Read src/rel_movie_viewer.c's file header first (and build/mwcc/rel_html_view.c,
 * which has the same header but is not checked in under src/ yet): every
 * convention and every MWCC lever documented there (volatile-global-via-local-
 * pointer, switch vs if branch shapes, int[] indexing of a state blob, the
 * __builtin_allegrex_* intrinsics, tail calls via `j` instead of `jal`+`jr`,
 * and the -O2+ address re-materialisation trap) applies here too.
 *
 * WHAT THIS MODULE IS. The character-select ("charalist") screen: it loads
 * per-character portrait/UI assets (bg.gim, tab.gim, main_face01/02.gim,
 * mdl_bup*.gim, d_menu*.gim, team_name01_*.gim, ...) from
 * database/charalist.ehp and picks language-suffixed string tables
 * (strTbl_{j,e,g,f,i,s}.bin) — see docs/modules/rel_charalist.md for the
 * mechanically-extracted survey (section table, string dump, function-size
 * histogram) this file was scoped from.
 *
 * STATUS — 18 of the module's 120 functions are byte-identical to the target
 * (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0), verified with mwcc_diff.py:
 *   func_0000006C, func_000002A8, func_00000B18, func_00000B6C,
 *   func_00001484, func_00001F28, func_00005950, func_000059EC,
 *   func_00005A94, func_00005C58, func_00006A08, func_000062DC,
 *   func_000063E8, func_00008D18, func_00008D70, func_00008D78,
 *   func_00008D80, func_00008D88.
 * The remaining functions (build/auto/rel_charalist.json has the full status
 * list) are either untried or close-but-nonmatching drafts; none of those are
 * included here — only functions individually tagged "MATCH 100%" below have
 * been verified byte-for-byte. NOTE: build/auto/rel_charalist.matched.json
 * mirrors this same 18-function set so scripts/assemble_module.py's
 * "never clobber a better file" guard keeps this file intact.
 *
 * LEVERS CONFIRMED/ADDED WHILE MATCHING THIS MODULE (see auto_decomp.py's
 * SHAPES list — these are worth mechanising there):
 *  - A "no-argument" tail call whose asm delay slot sets an argument register
 *    to 0 (`j callee` / `addu $aN, $zero, $zero`) is NOT a no-arg call: the
 *    callee genuinely takes that argument as a literal 0. Write the 0
 *    explicitly as a real argument rather than dropping it, or MWCC schedules
 *    the zero-load differently and the tail-call form doesn't come out byte
 *    identical (func_000002A8, func_00006A08, func_00008D80).
 *  - A leaf function that returns one of several incoming argument registers
 *    unchanged (`jr $ra` / `addu $v0, $aN, $zero`) needs ALL the leading
 *    arguments declared even if unused, so the returned one lands in the
 *    right register (func_00008D78 returns arg2, needs 3 declared params;
 *    func_00008D88 returns arg1, needs 2).
 *  - Indexing a blob of N-byte records with a raw `int *`/`short *` pointer
 *    lets the compiler fold the record stride together with the pointee's
 *    `sizeof`, producing an extra shift the target does not have. Casting to
 *    `char *` first and back after the multiply keeps the byte stride literal
 *    (func_000059EC: `*(s32 *)((char *)&D_0000E3F8 + i * 0x10)` matches;
 *    plain `int *` arithmetic over-shifts by 2. Same fix needed by
 *    func_00005A94's `s16` read at an 8-byte stride).
 *  - `D_00027918` is itself a pointer-sized int holding an address: reading it
 *    as `*(s32 *)D_00027918` (dereferencing the VALUE, not `&D_00027918`)
 *    while ALSO forwarding the raw value as the next argument reproduces the
 *    target's two-register pattern (func_000063E8): `a1 = D_00027918;
 *    a0 = *(int*)a1`.
 *  - The `x << 6` / `(0x1E0 - x) << 6` fixed-point idiom recurs across the
 *    UI-coordinate helpers (func_00001484, func_00001F28); when a helper
 *    forwards its own leading argument BOTH shifted directly and shifted
 *    after being subtracted from a screen-space constant, both uses need to
 *    be written out — m2c's draft only kept one and undershot the target's
 *    word count by exactly the missing `sll`.
 *  - When the SAME imported symbol is called with different argument counts
 *    from different functions in one translation unit (e.g. ehsys_B89D38DC
 *    as both 3-arg and 4-arg here), MWCC's C dialect still enforces a single
 *    prototype per TU. Declare it old-style (`extern void f();`, no
 *    parameter list) so every call site is accepted — this is what lets a
 *    single-file assembly keep both shapes matching.
 *  - A call site whose target register setup is IDENTICAL to the caller's
 *    own incoming argument registers (a genuine pass-through with zero
 *    marshalling instructions) requires the callee to be declared and CALLED
 *    with the exact same argument count/order the caller received — if a
 *    later definition of the same function pins down a stricter prototype
 *    (e.g. adds an argument), a K&R-style (unprototyped) function
 *    *definition* for the callee keeps calls elsewhere in the file legal
 *    without forcing extra register-zeroing code (func_00005A94's call to
 *    func_000059EC(): the target's jal has no `$a0` setup at all, matching a
 *    K&R-defined, argument-less call site even though func_000059EC's own
 *    body does use an incoming argument register).
 */

/* forward declarations of same-module callees used by the matched functions
 * below (call graph is not in address order; none of these bodies are
 * matched yet, so no return type beyond their observed use is claimed) */
extern void func_00000580(void);
extern int func_000002B0(int);
extern int func_00005C90(void);
extern void func_00006FAC(int);
extern int ehsys_2630B590(void);
extern int ehsys_6A55182E(int, int);
extern void ehsys_97BB99A5(int, int, int, int);
extern void ehsys_99FF9D51(int, int);
extern void ehsys_B89D38DC();

/* func_0000006C — always-0 stub. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_0000006C(void) {
    return 0;
}

/* func_000002A8 — tail-calls func_000002B0 with a literal 0 first argument.
 * MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_000002A8(void) {
    func_000002B0(0);
}

/* func_00000B18 — plain tail call, no arguments.
 * MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00000B18(void) {
    func_00000580();
}

/* func_00000B6C — always-0 stub (same shape as func_0000006C).
 * MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_00000B6C(void) {
    return 0;
}

/* func_00001484 — UI-coordinate helper: converts three ints to 26.6 fixed
 * point and forwards to ehsys_B89D38DC (a 3-arg draw/layout primitive here;
 * see func_00001F28 below for the 4-arg call to the same import).
 * MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00001484(int arg0, int arg1, int arg2) {
    ehsys_B89D38DC(arg0 << 6, arg1 << 6, arg2 << 6);
}

/* func_00001F28 — like func_00001484, but arg0 is ALSO mirrored against the
 * 0x1E0 (480, PSP screen width) right edge for the third coordinate.
 * MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00001F28(int arg0, int arg1, int arg2) {
    ehsys_B89D38DC(arg0 << 6, arg1 << 6, (0x1E0 - arg0) << 6, arg2);
}

/* func_00005950 — forwards its own two args plus two literal 0s to
 * ehsys_97BB99A5 (4-arg draw/layout primitive).
 * MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00005950(int arg0, int arg1) {
    ehsys_97BB99A5(arg0, arg1, 0, 0);
}

/* func_000059EC — linear search: first record (16-byte stride array at
 * D_0000E3F8) whose leading s32 field equals arg0; -1 if a negative
 * sentinel is hit first, else the record index. Defined K&R-style so
 * func_00005A94's argument-less call below stays legal C (see file header).
 * MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
extern int D_0000E3F8;
int func_000059EC(arg0)
int arg0;
{
    int temp_v1;
    int var_v0;

    var_v0 = 0;
loop_1:
    temp_v1 = *(int *)((char *)&D_0000E3F8 + var_v0 * 0x10);
    if (temp_v1 < 0) {
        return -1;
    }
    if (arg0 != temp_v1) {
        var_v0 += 1;
        goto loop_1;
    }
    return var_v0;
}

/* func_00005A94 — looks up func_000059EC()'s match in an 8-byte-stride
 * table at D_00024EAC and returns its leading s16 field.
 * MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
extern int D_00024EAC;
short func_00005A94(void) {
    /* target's call site does not set up $a0 before the jal (it relies on
     * whatever was already there) — func_000059EC is defined K&R-style above
     * so this old-style no-argument call is legal C and does not force MWCC
     * to emit a `move $a0, $zero` the target doesn't have. */
    return *(short *)((char *)&D_00024EAC + func_000059EC() * 8);
}

/* func_00005C58 — if ehsys_2630B590() (a state/availability check) is
 * false, calls func_00005C90() and reports success (1); otherwise reports
 * failure (0) without running func_00005C90.
 * MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_00005C58(void) {
    if (ehsys_2630B590() != 0) {
        return 0;
    }
    func_00005C90();
    return 1;
}

/* func_00006A08 — plain tail call to func_00006FAC with a literal 0 first
 * argument (same shape as func_000002A8).
 * MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00006A08(void) {
    func_00006FAC(0);
}

/* func_000062DC — difference of two u16 values read through pointers.
 * MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_000062DC(unsigned short *arg0, unsigned short *arg1) {
    return *arg0 - *arg1;
}

/* func_000063E8 — D_00027918 holds a pointer value; this loads that value
 * and also dereferences it, forwarding both to ehsys_20E340D9.
 * MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
extern int D_00027918;
extern void ehsys_20E340D9(int, int);
void func_000063E8(void) {
    ehsys_20E340D9(*(int *)D_00027918, D_00027918);
}

/* func_00008D18 — runs ehsys_6A55182E(arg1, arg2) and forwards its result
 * plus the original three arguments into func_00008D70.
 * MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00008D18(int arg0, int arg1, int arg2) {
    func_00008D70(ehsys_6A55182E(arg1, arg2), arg0, arg1, arg2);
}

/* func_00008D70 — identity on its first argument.
 * MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_00008D70(int arg0) {
    return arg0;
}

/* func_00008D78 — returns its third argument unchanged (needs all three
 * leading params declared so the value lands in $a2).
 * MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_00008D78(int arg0, int arg1, int arg2) {
    return arg2;
}

/* func_00008D80 — tail-calls ehsys_99FF9D51, forwarding its own argument
 * and a literal 0 second argument.
 * MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00008D80(int arg0) {
    ehsys_99FF9D51(arg0, 0);
}

/* func_00008D88 — returns its second argument unchanged (needs both leading
 * params declared so the value lands in $a1).
 * MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_00008D88(int arg0, int arg1) {
    return arg1;
}
