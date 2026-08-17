/*
 * rel_debug_menu.prx — reconstructed code (matching decompilation)
 *
 * Compiler:     Metrowerks CodeWarrior for PSP — MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,s -sdatathreshold 0   (SIZE, not ,p — see docs/09)
 * Verification: local build with wibo + mwccpsp_3.0.1_219 (see docs/03-tools.md
 *               "local matching" section) — compare with
 *               `mips-linux-gnu-objdump -dr` against asm/rel_debug_menu/text.s,
 *               treating any word with a matching relocation (HI16/LO16/26,
 *               same symbol) on both sides as equal regardless of its baked
 *               immediate. Only functions marked "MATCH 100%" below have been
 *               confirmed this way; 19/44 functions in the module currently are
 *               (the other 25 are large or still need hand-matching — see
 *               docs/modules/rel_debug_menu.md and build/auto/rel_debug_menu.json
 *               for the survey of what remains).
 *
 * What this module does: the in-game debug/test menu (title screen visible
 * in `.rodata` strings: "YUGI OH 5Ds -TAGFORCE- TEST MODE", "SOUND TEST",
 * "story test", "duel test", "shop test", "movie test", ... "gallery"). It is
 * dead code in a retail build but was compiled in and left in the PRX.
 *
 * Conventions (see docs/09-first-match.md and src/rel_movie_viewer.c's
 * header, which documents every MWCC codegen lever discovered so far):
 *  - `func_XXXXXXXX` / `D_XXXXXXXX` = placeholders (address), to be renamed
 *    as their purpose becomes clear;
 *  - D_00009C90/94/98/9C sit right past the end of `.data` (vram 0x9C90),
 *    i.e. they are `.bss` debug-menu state (case index, sub-state, a repeat
 *    counter). 0x809CF0/0x809CF4 (used raw, un-named, in func_00000CE4) are
 *    the SAME state blob addressed with the absolute PSP virtual address
 *    instead of a relocated symbol — same "two addressing idioms for one
 *    blob" pattern documented in rel_movie_viewer.c's header, just with the
 *    high byte (0x80 vs 0x00) present here because this blob is further
 *    along and the compiler apparently baked the full runtime VA rather than
 *    emitting a relocation for it.
 *
 * MWCC codegen levers confirmed here that are NOT yet in rel_movie_viewer.c's
 * header:
 *  - a 3-arg call in the m2c output can secretly be a 4-arg call: the target
 *    can materialize a 4th register (here $a3, holding the original 3rd
 *    arg unchanged) that m2c's arg-count inference dropped because the
 *    3rd arg is passed straight through without being touched. Symptom:
 *    candidate is a fixed number of words SHORTER than target and the
 *    disassembly shows an `addu $a3, $aN, $zero`/similar register-copy in
 *    the target that has no counterpart in the candidate. See
 *    func_00000BE4/func_0000289C/func_00003B64 (the call actually passes
 *    `(arg0<<6, arg1<<6, (0x1E0-arg0)<<6, arg2)`, not the 3-arg guess);
 *  - `switch` case COMPARE ORDER is the REVERSE of source declaration
 *    order, not source order and not value order. Declaring `case 1: ...
 *    case 2: ... case 3: ...` in that order makes MWCC emit the compare
 *    chain as 3, then 2, then 1. Confirmed independently in
 *    func_00001BBC (3 cases), func_00001C74/func_00001CFC (2 cases), and
 *    func_000015AC (fallthrough cases 3/2 sharing a body, case 1 separate);
 *  - `!func()` and `func() == 0` are NOT interchangeable at -O4,s even
 *    though they're logically identical: `!func()` folds straight into a
 *    `beqz`/`bnez` on the raw return value, while `func() == 0` first
 *    materializes a full boolean (`sltu`+`xori`) and branches on THAT. Only
 *    the `!func()` phrasing matches when the target uses the direct branch
 *    (func_00001C18);
 *  - MWCC implements combined `/`+`%` by the same constant with ONE `div`
 *    plus a reconstructed remainder (`a - (a/c)*c`), and it strength-reduces
 *    that multiply-back into shift/subtract chains itself — writing the
 *    multiply literally (`t*108000`) in portable C is enough; no manual
 *    strength reduction needed (func_0000026C's d/h/m-style split);
 *  - an uninitialized local passed as a "phantom" leading argument (never
 *    written, so it takes whatever garbage is in that register at the call
 *    site) is sometimes real: the target genuinely leaves that register
 *    untouched before the call. `ehsys_DFCA450B(garbage, &sp1C)` matches
 *    the target exactly where `ehsys_DFCA450B(&sp1C)` does not
 *    (func_00000C38) — the callee apparently ignores its first argument, or
 *    the original C had a same real bug. Do not silently "fix" it by
 *    dropping the arg;
 *  - assigning INSIDE the call expression — `f(x = g())` instead of
 *    `x = g(); f(x);` — changes whether the immediately-following use of the
 *    same value reads the fresh return register (`$v0`) or the just-stored
 *    copy (`$s0`/other saved reg), even though both are provably the same
 *    value. Only the inline-assignment phrasing matched func_00000C38's
 *    third instruction.
 *
 * Layout notes:
 *  - jump tables `jtbl_000095B4..9674` and 92 distinct globals (31 of them
 *    past end of `.data`) are referenced across the 25 still-unmatched
 *    functions; see docs/modules/rel_debug_menu.md for the full survey.
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

/* resolved imports (config/symbols/rel_debug_menu.txt) */
extern void ehsys_B4471B5E(void (*)(void), void (*)(void), void *);
extern void ehsys_C2E59A21(int, int, int);
extern int ehsys_DFCA450B(int, void *);
extern void ehsys_1EC5342B(int);
extern void ehsys_4DFEDFFA(int);
extern int ehsys_6F0D36D3(void);
extern void ehsys_5836AFF1(void);
extern int ehsys_4E3BEA66(void);
extern void ehsys_13A4081A(int);
extern void ehsys_551A8EF2(int, int, int);
extern void ehsys_6FFA2A28(int, int);
extern int ehsys_778817A2(void);
extern void ehsys_memset(void *, int, int);
extern void ehsys_sceGuStart(int, int, int);
extern int ehsys_sceGuFinish(void);
extern void ehsys_60B55A50(int);
extern void ehsys_B89D38DC(int, int, int, int);
extern void ehsys_frame_sync(void);
extern void ehsys_C644C679(void *);
extern void ehsys_FC53D253(void);
extern int ehsys_3C1C1F65(void);
extern void ehsys_3A7E4F65(void *, int, int);

/* not yet matched in this file, but called from functions that are */
extern void func_00000034(void);
extern void func_00000264(void);
extern void func_00000C80(int);
extern void func_000037D0(void *, int);

/* .bss debug-menu state (see file header) */
extern int D_00009C90;
extern int D_00009C98;
extern int D_00009C9C;
extern int D_00009CE4;

/* opaque buffers, only ever address-taken */
extern char D_809CF8;
extern char D_809D04;
extern char D_80A498;
extern char D_80A49C;
extern char D_80AB9C;
extern char D_80B330;
extern char D_80BA2C;

/* module entry point: registers func_00000034 (update) and func_00000264
 * (draw, currently a stub) with the engine, and hands over &D_809CF8 as
 * the menu's context/state block. MATCH 100% */
s32 func_00000000(void) {
    ehsys_B4471B5E(func_00000034, func_00000264, &D_809CF8);
    return 0;
}

/* draw callback stub (unused/not-yet-implemented in this build).
 * MATCH 100% */
void func_00000264(void) {
}

/* splits a frame/tick count `arg0` into d/h/m-style fields at out[0..2]:
 * out[0] = arg0 / 108000, out[1] = (arg0 % 108000) / 1800,
 * out[2] = (arg0 % 108000) % 1800 / 30. MATCH 100% */
void func_0000026C(s32 arg0, s32 *out) {
    s32 t0, r0, t1, r1;

    t0 = arg0 / 108000;
    r0 = arg0 - t0 * 108000;
    out[0] = t0;
    t1 = r0 / 1800;
    r1 = r0 - t1 * 1800;
    out[1] = t1;
    out[2] = r1 / 30;
}

/* draws a screen-space rectangle/scissor region: (x<<6, y<<6, (480-x)<<6,
 * flags). MATCH 100% */
void func_00000BE4(s32 arg0, s32 arg1, int arg2) {
    ehsys_B89D38DC(arg0 << 6, arg1 << 6, (0x1E0 - arg0) << 6, arg2);
}

/* advances the GU display-list cursor by (frame-timer + sceGuFinish()) - 8.
 * MATCH 100% */
void func_00000C04(void) {
    s32 temp_s0;

    temp_s0 = ehsys_6F0D36D3();
    ehsys_1EC5342B((temp_s0 + ehsys_sceGuFinish()) - 8);
}

/* begins a GU display list (list type 2) into a fresh command buffer.
 * MATCH 100% */
void func_00000C38(void) {
    s32 sp1C;
    s32 garbage;
    s32 temp_v0;

    ehsys_4DFEDFFA(temp_v0 = ehsys_DFCA450B(garbage, &sp1C));
    ehsys_sceGuStart(2, temp_v0, sp1C);
}

/* unused/stub. MATCH 100% */
void func_00000C78(void) {
}

/* per-frame menu-list housekeeping: lazily initializes the entry list via
 * func_00000C80 the first time through (*(s32*)0x809CF0 == 0), then either
 * advances the "settle" counter D_00009C9C (below 7 frames) and pings
 * ehsys_60B55A50 with a per-frame animation phase, or bumps the outer
 * state D_00009C90 once settled. MATCH 100% */
void func_00000CE4(void) {
    s32 temp_v1;

    if (*(s32 *)0x809CF0 == 0) {
        func_00000C80(0);
    }
    if (D_00009C9C < 7) {
        temp_v1 = D_00009C9C + 1;
        D_00009C9C = temp_v1;
        ehsys_60B55A50(((temp_v1 * 2) + 1) * 0x11111111);
        return;
    }
    D_00009C90 += 1;
}

/* menu-input dispatch: cases 2/3 reset D_00009C90/98/9C to 0 (back out of
 * the current sub-menu), case 1 is a no-op (already-handled selection).
 * MATCH 100% */
void func_000015AC(void) {
    s32 temp_v0;

    temp_v0 = ehsys_778817A2();
    switch (temp_v0) {
    case 1:
        return;
    case 2:
    case 3:
        D_00009C90 = 0;
        D_00009C98 = 0;
        D_00009C9C = 0;
        return;
    }
}

/* advances the menu's blink/highlight cursor D_00009C90, driven by cursor
 * position D_00009CE4. MATCH 100% */
void func_00001B84(void) {
    ehsys_6FFA2A28(3, D_00009CE4);
    D_00009C90 += 1;
}

/* menu-input dispatch: cases 1/2/3 all confirm the current selection
 * (D_00009C90 = 0x5C, a shared "committed" state), everything else is
 * ignored. MATCH 100% */
void func_00001BBC(void) {
    s32 temp_v0;

    temp_v0 = ehsys_778817A2();

    switch (temp_v0) {
    case 1:
        goto done;
    case 2:
        goto label2;
    case 3:
        goto label3;
    }
    goto done;

label2:
    D_00009C90 = 0x5C;
    goto done;

label3:
    D_00009C90 = 0x5C;

done:
    return;
}

/* blocks (spinning on ehsys_frame_sync) until ehsys_4E3BEA66 reports ready,
 * bracketed by ehsys_13A4081A(1)/(0) (likely a "busy"/input-lock flag), then
 * clears D_00009C90. MATCH 100% */
void func_00001C18(void) {
    ehsys_13A4081A(1);
    ehsys_5836AFF1();
    goto test;
loop:
    ehsys_frame_sync();
test:
    if (!ehsys_4E3BEA66()) {
        goto loop;
    }
    ehsys_13A4081A(0);
    D_00009C90 = 0;
}

/* confirmation-prompt entry: locks input, waits a frame, then submits a
 * message-box-style call (kind 1, x = arg0 & 0xFFFF, y = arg1 & 0xFFFF).
 * Always returns 1. MATCH 100% */
s32 func_00001D84(s32 arg0, s32 arg1) {
    ehsys_C2E59A21(0, 0, 0);
    ehsys_13A4081A(1);
    ehsys_frame_sync();
    ehsys_551A8EF2(1, arg0 & 0xFFFF, arg1 & 0xFFFF);
    return 1;
}

/* returns 10^(arg0-1) for arg0 != 0 (else 1) — a decimal-place multiplier,
 * used by a digit-formatting caller elsewhere in the module. MATCH 100% */
s32 func_00002044(s32 arg0) {
    s32 v0;
    s32 t;

    v0 = 1;
    goto test;
body:
    v0 = v0 * 10;
test:
    t = arg0;
    arg0 -= 1;
    if (t != 0) {
        goto body;
    }
    return v0;
}

/* resets a large sub-menu's working buffers: D_809D04 (0xE98 bytes) and
 * D_80A498 (0x6C bytes) are zeroed, then D_80A49C is initialized from
 * ehsys_3C1C1F65()'s return value. MATCH 100% */
void func_0000206C(void) {
    ehsys_memset(&D_809D04, 0, 0xE98);
    ehsys_FC53D253();
    ehsys_memset(&D_80A498, 0, 0x6C);
    ehsys_3A7E4F65(&D_80A49C, ehsys_3C1C1F65(), 0xF);
}

/* draws a screen-space rectangle/scissor region (same shape as
 * func_00000BE4/func_00003B64 — likely all three are the same source line
 * reused across different UI panels at -O4,s, each keeping its own copy
 * rather than being merged into one call site). MATCH 100% */
void func_0000289C(s32 arg0, s32 arg1, int arg2) {
    ehsys_B89D38DC(arg0 << 6, arg1 << 6, (0x1E0 - arg0) << 6, arg2);
}

/* resets a sub-menu's working buffer D_80AB9C (0xE90 bytes). MATCH 100% */
void func_000028BC(void) {
    ehsys_memset(&D_80AB9C, 0, 0xE90);
    ehsys_FC53D253();
}
/* func_00002D44 — 21 words. MATCH 100% (shape: m2c). */
void func_00002D44(void) {
    extern char D_80AFA0;
    extern int ehsys_8852C022();
    extern int ehsys_EF9EFF0F();
    extern int ehsys_F5E3080C();
    extern int func_00002D44();
    s32 temp_s0;

    temp_s0 = ehsys_F5E3080C();
    *(s32 *)0x80AB9C = 4;
    ehsys_EF9EFF0F(&D_80AFA0);
    if ((*(int *)((char *)temp_s0 + 0x1C)) & 0x4000) {
        ehsys_8852C022();
    }
}

/* draws a screen-space rectangle/scissor region (see func_00000BE4).
 * MATCH 100% */
void func_00003B64(s32 arg0, s32 arg1, int arg2) {
    ehsys_B89D38DC(arg0 << 6, arg1 << 6, (0x1E0 - arg0) << 6, arg2);
}

/* initializes D_80BA2C via ehsys_C644C679, then calls func_000037D0 on
 * D_80B330 twice with the same argument (5) — looks redundant but matches
 * byte-for-byte, so kept as-is rather than "cleaned up". MATCH 100% */
void func_00003B84(void) {
    ehsys_C644C679(&D_80BA2C);
    func_000037D0(&D_80B330, 5);
    func_000037D0(&D_80B330, 5);
}
