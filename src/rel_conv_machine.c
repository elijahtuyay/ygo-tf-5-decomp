/*
 * rel_conv_machine.prx — reconstructed code (matching decompilation)
 *
 * Module: the card-conversion / reward "machine" screen (see
 *         docs/modules/rel_conv_machine.md for the asset/string survey this
 *         was sized up from).
 *
 * Compiler:     Metrowerks CodeWarrior for PSP — MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,s -sdatathreshold 0
 * Verification: local build with wibo + mwccpsp_3.0.1_219 (see docs/03-tools.md
 *               "local matching" section) — compare with
 *               `mips-linux-gnu-objdump -dr` against asm/rel_conv_machine/text.s,
 *               treating any word with a matching relocation (HI16/LO16/26,
 *               same symbol) on both sides as equal regardless of its baked
 *               immediate. Only functions marked "MATCH 100%" below have been
 *               confirmed this way; 24/62 functions in this module currently
 *               are (build with `scripts/mwcc_build.sh src/rel_conv_machine.c`
 *               then `scripts/mwcc_diff.py asm/rel_conv_machine/text.s
 *               build/mwcc/rel_conv_machine.o`).
 *
 * STATUS (24 of 62 functions matched — see individual comments below):
 *   func_00000000  MATCH 100%   u16 3-way compare (qsort-style callback)
 *   func_00000330  MATCH 100%   trampoline -> func_00000338
 *   func_00000780  MATCH 100%   u16 3-way compare (qsort-style callback)
 *   func_00000808  MATCH 100%   stub, returns 0
 *   func_00000A10  MATCH 100%   trampoline -> func_000018D8
 *   func_00000A18  MATCH 100%   trampoline -> ehsys_6E42DDCD
 *   func_00000A20  MATCH 100%   caches 3 sensor/input values into 0x7D044 blob
 *   func_000017DC  MATCH 100%   sets up a 0xFF000000 clear + draws via func_00001840
 *   func_00001840  MATCH 100%   scales 3 coords by 64 and tail-calls ehsys_BC8E65D7
 *   func_00001854  MATCH 100%   inits D_47D410 block + registers 18B8/18C8 callbacks
 *   func_000018B8  MATCH 100%   trampoline -> ehsys_41AABF28 with cached D_0007D404
 *   func_000018C8  MATCH 100%   trampoline -> ehsys_20E340D9 with cached D_0007D404
 *   func_00002458  MATCH 100%   Vec4 copy
 *   func_000027C8  MATCH 100%   Vec2 copy
 *   func_00002DC8  MATCH 100%   scales 4 coords by 64 and tail-calls ehsys_3BB2BAC6
 *   func_00002DE4  MATCH 100%   getter for D_0047D5B0
 *   func_00002DF0  MATCH 100%   setter for D_0047D5C0
 *   func_00002DFC  MATCH 100%   getter, returns &D_47D4B4
 *   func_00002EA4  MATCH 100%   sets D_0047D460 state field to 1
 *   func_00002EB4  MATCH 100%   sets D_0047D460 state field to 3
 *   func_00002EC4  MATCH 100%   state-machine predicate over D_47D460
 *   func_00002F7C  MATCH 100%   state == 1 || state == 3 predicate
 *   func_000030C4  MATCH 100%   bumps D_47D460.unk164 when func_00002EC4() is false
 *   func_00003570  MATCH 100%   trampoline -> ehsys_06380DFA / ehsys_AB962AE7(0)
 *
 * Conventions (see docs/09-first-match.md and src/rel_movie_viewer.c's header
 * for the full lever list; only NEW findings specific to this module are
 * repeated here):
 *  - names `func_XXXXXXXX` / `D_XXXXXXXX` = placeholders (address), to be
 *    renamed as their purpose becomes clear. `ehsys_XXXXXXXX` names are the
 *    RESOLVED import names from config/symbols/rel_conv_machine.txt (this
 *    module's imports are hash-named at the source level — there is no
 *    friendlier alias available yet).
 *  - EXTENDED REGISTER ARGUMENT ABI (new lever, not in rel_movie_viewer.c):
 *    this compiler passes up to 8 integer/pointer arguments in registers —
 *    $a0-$a3 for args 1-4, then $t0-$t3 for args 5-8 — before spilling to the
 *    stack for a 9th+. m2c does not know this convention and reports
 *    "M2C_ERROR(/* Read from unset register $t0 */)" for any function that
 *    receives more than 4 arguments; the fix is simply to declare the extra
 *    C parameters (arg4.. use s32, matching whatever the target treats them
 *    as) — MWCC places them in $t0-$t3 on its own. Confirmed by isolated
 *    experiment: a 6-int-parameter function that just forwards all 6 to
 *    another function compiles to a bare `j`. Used by func_00001840 (5
 *    params, ehsys_BC8E65D7 has an unused-passthrough 4th param riding in
 *    $a3 and a literal -1 5th param riding in $t0) and func_00002DC8 (5
 *    params forwarding to a 7-argument ehsys_3BB2BAC6).
 *  - UNUSED PASSTHROUGH PARAMETER: a formal parameter this function never
 *    reads is still a live register at the point of a later tail/leaf call,
 *    and if that call needs an argument in that exact register slot, MWCC
 *    happily leaves the caller's original value sitting there — i.e. an
 *    "unused" parameter can be silently forwarded to a callee without ever
 *    being named in an expression, as long as its declared position lines up
 *    with the register the callee's corresponding argument would use. This
 *    is what func_00001840's arg3 does for ehsys_BC8E65D7's 4th parameter.
 *  - LOCAL POINTER CACHES A GLOBAL'S ADDRESS ACROSS STRAIGHT-LINE BRANCHES
 *    (no call needed): rel_movie_viewer.c's header notes that a saved
 *    register base is sometimes achieved by keeping a pointer live across a
 *    CALL. Here, func_00002EC4/func_000030C4 show it also happens across a
 *    chain of plain `if`/`return` branches (no calls at all) — declaring
 *    `D47D460_t *p = &D_47D460;` at the top and using `p->field` everywhere
 *    (instead of re-deriving `D_47D460.field` at each site) is what makes
 *    MWCC reuse one `lui/addiu` for the whole function instead of
 *    rematerializing it per access.
 *  - Field access through a mid-blob byte offset that spimdisasm cannot
 *    resolve to a relocation (same situation as D_0009DB00+0x6408 in
 *    rel_movie_viewer.c) shows up here as raw literals like 0x7D044,
 *    0x47D460, 0x47D5B0 with no %hi/%lo symbol; that is intentional and
 *    matches the target — do not "fix" it into a named extern unless a
 *    later function proves the field crosses into a differently-shaped
 *    access (as D_47D460 does, once enough fields justify the struct).
 *  - func_000025D4 (NOT matched, left out of this file): logically solved —
 *    6 register-ABI params written into a state blob at 0x47D530.. — but the
 *    target recomputes `lui $v0,(0x480000>>16)` before EVERY one of the 6
 *    stores (5 extra `lui`s) while every portable-C phrasing tried here
 *    (raw pointer cast, `volatile` pointer cast, distinct extern symbols per
 *    field) either merges them into one `lui` or gets the right word count
 *    but the wrong relocation shape (target's mid-blob stores are
 *    relocation-free raw immediates, but a named extern per field forces a
 *    real relocation). Same root cause as the address-rematerialization
 *    trap documented in rel_movie_viewer.c/docs/10, just going the opposite
 *    direction (target rematerializes, portable C here refuses to). Left as
 *    a documented near-miss rather than guessed into the file.
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

/* ---- imports (resolved names from config/symbols/rel_conv_machine.txt) ---- */
extern int ehsys_41AABF28();
extern int ehsys_20E340D9();
extern int ehsys_DFCA450B();
extern int ehsys_1EC5342B();
extern int ehsys_EBD1986B();
extern int ehsys_459B889D();
extern int ehsys_6E42DDCD();
extern int ehsys_memset();
extern int ehsys_942B03D0();
extern int ehsys_60B55A50();
extern int ehsys_3BB2BAC6();
extern int ehsys_BC8E65D7();
extern int ehsys_06380DFA();
extern int ehsys_AB962AE7();
extern int ehsys_B8AD96EA();
extern int ehsys_A4AFF8E6();
extern int ehsys_6533F67D();
extern int ehsys_6FE21799();
extern int ehsys_F352F222();

/* ---- other module-local functions referenced but not yet matched ---- */
extern int func_00000338();
extern int func_000018D8();

/* ---- module data ---- */
extern char D_47D410;
extern void *D_47D4B4;

/* D_47D460 is a much larger state blob; only the fields proven by the
 * functions below are named here. See STATUS list for which functions use
 * which fields. */
typedef struct {
    s32 unk0;
    s8 pad4[0xE8 - 4];
    s32 unkE8;
    s8 padEC[0x154 - 0xE8 - 4];
    s32 unk154;
    s8 pad158[0x164 - 0x154 - 4];
    s32 unk164;
    s8 pad168[0x184 - 0x164 - 4];
} D47D460_t;
extern D47D460_t D_47D460;

/* forward decls for callbacks registered by func_00001854 before their own
 * definitions appear (address order requires func_00001854 before them) */
void func_000018B8(s32 arg0);
void func_000018C8(s32 arg0);

/* qsort-style 3-way compare on a pair of u16 values. */
s32 func_00000000(u16 *arg0, u16 *arg1) {
    return *arg0 - *arg1;
}

/* trampoline */
void func_00000330(void) {
    func_00000338();
}

/* qsort-style 3-way compare on a pair of u16 values (identical shape to
 * func_00000000; distinct callback for a different list). */
s32 func_00000780(u16 *arg0, u16 *arg1) {
    return *arg0 - *arg1;
}

/* stub */
s32 func_00000808(void) {
    return 0;
}

/* trampoline */
void func_00000A10(void) {
    func_000018D8();
}

/* trampoline */
void func_00000A18(void) {
    ehsys_6E42DDCD();
}

/* caches 3 input/sensor readings into the 0x7D044 scratch block */
void func_00000A20(void) {
    *(s16 *)0x7D044 = ehsys_6533F67D();
    *(s32 *)0x7D048 = ehsys_6FE21799() & 0xFFFF;
    *(s16 *)0x7D04C = ehsys_F352F222();
}

/* clears the screen to opaque black and draws via func_00001840 */
void func_000017DC(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    ehsys_B8AD96EA();
    ehsys_942B03D0(0x18, 0x18);
    ehsys_60B55A50(0xFF000000);
    func_00001840(arg2, arg3, 0x180, *(s32 *)0x7D0E0);
    ehsys_A4AFF8E6();
}

/* scales 3 coords by 64 (fixed point) and tail-calls ehsys_BC8E65D7; arg3 is
 * an unused parameter that is simply forwarded through to ehsys_BC8E65D7's
 * 4th argument (see header note on "unused passthrough parameter"), and the
 * literal -1 is ehsys_BC8E65D7's 5th argument. */
void func_00001840(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    ehsys_BC8E65D7(arg0 << 6, arg1 << 6, arg2 << 6, arg3, -1);
}

/* inits the D_47D410 (0x50-byte) block and registers the func_000018B8 /
 * func_000018C8 pair as callbacks. */
void func_00001854(void) {
    s32 temp_s0;

    ehsys_memset(&D_47D410, 0, 0x50);
    temp_s0 = ehsys_459B889D(ehsys_DFCA450B(0, 0));
    ehsys_EBD1986B(func_000018B8, func_000018C8);
    ehsys_1EC5342B(temp_s0);
}

/* trampoline, forwarding arg0 plus a cached value from 0x7D404 */
void func_000018B8(s32 arg0) {
    ehsys_41AABF28(*(s32 *)0x7D404, arg0);
}

/* trampoline, forwarding arg0 plus a cached value from 0x7D404 */
void func_000018C8(s32 arg0) {
    ehsys_20E340D9(*(s32 *)0x7D404, arg0);
}

typedef struct { f32 unk0; f32 unk4; f32 unk8; f32 unkC; } Vec4;

/* Vec4 copy, returns arg0 */
Vec4 *func_00002458(Vec4 *arg0, Vec4 *arg1) {
    arg0->unk0 = arg1->unk0;
    arg0->unk4 = arg1->unk4;
    arg0->unk8 = arg1->unk8;
    arg0->unkC = arg1->unkC;
    return arg0;
}

typedef struct { f32 unk0; f32 unk4; } Vec2;

/* Vec2 copy, returns arg0 */
Vec2 *func_000027C8(Vec2 *arg0, Vec2 *arg1) {
    arg0->unk0 = arg1->unk0;
    arg0->unk4 = arg1->unk4;
    return arg0;
}

/* scales 4 coords by 64 (fixed point) and tail-calls ehsys_3BB2BAC6; arg4 is
 * an unused parameter forwarded through to ehsys_3BB2BAC6's 5th argument,
 * with literal -1 and 0 as its 6th/7th arguments. */
void func_00002DC8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    ehsys_3BB2BAC6(arg0 << 6, arg1 << 6, arg2 << 6, arg3 << 6, arg4, -1, 0);
}

/* getter */
s32 func_00002DE4(void) {
    return *(s32 *)0x47D5B0;
}

/* setter */
void func_00002DF0(s32 arg0) {
    *(s32 *)0x47D5C0 = arg0;
}

/* getter, returns the address of the D_47D4B4 record */
void **func_00002DFC(void) {
    return &D_47D4B4;
}

/* sets the conv-machine state field to 1 */
void func_00002EA4(void) {
    *(s32 *)0x47D460 = 1;
}

/* sets the conv-machine state field to 3 */
void func_00002EB4(void) {
    *(s32 *)0x47D460 = 3;
}

/* state-machine predicate: true only when D_47D460 is fully idle
 * (unk154 == 0, unkE8 != 0) and its unk0 state code is 2. */
s32 func_00002EC4(void) {
    D47D460_t *p = &D_47D460;
    if (*(s32 *)0x47D5AC != 0) {
        return 0;
    }
    if (p->unk154 != 0) {
        return 0;
    }
    if (p->unkE8 == 0) {
        return 0;
    }
    return p->unk0 == 2;
}

/* true when the conv-machine state (see func_00002EA4/func_00002EB4) is 1 or 3 */
s32 func_00002F7C(void) {
    s32 temp_v1;

    temp_v1 = *(s32 *)0x47D460;
    if ((temp_v1 != 3) && (temp_v1 != 1)) {
        return 0;
    }
    return 1;
}

/* bumps D_47D460.unk164 (a retry/attempt counter) whenever func_00002EC4()
 * says the machine is NOT idle. */
void func_000030C4(void) {
    D47D460_t *p = &D_47D460;
    if (func_00002EC4() == 0) {
        p->unk164 = p->unk164 + 1;
    }
}

/* trampoline */
void func_00003570(void) {
    ehsys_06380DFA();
    ehsys_AB962AE7(0);
}
