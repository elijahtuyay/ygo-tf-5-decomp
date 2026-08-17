/*
 * rel_deckswap.prx -- reconstructed code (matching decompilation, partial)
 *
 * Compiler:     Metrowerks CodeWarrior for PSP -- MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,s -sdatathreshold 0   (same config confirmed on rel_movie_viewer)
 * Verification: scripts/mwcc_build.sh src/rel_deckswap.c
 *               scripts/mwcc_diff.py asm/rel_deckswap/text.s build/mwcc/rel_deckswap.o
 *
 * Read src/rel_movie_viewer.c's file header first: every convention and every
 * MWCC lever documented there (volatile-global-via-local-pointer, switch vs if
 * branch shapes, int[] indexing of a state blob, the __builtin_allegrex_*
 * intrinsics, and the -O2+ address re-materialisation trap) applies here too.
 *
 * WHAT THIS MODULE IS. The in-game deck-swap screen (libdeck_swap_rel), which
 * also imports libduel_draw_rel -- it renders duel-style card art while the
 * player swaps cards between decks. Strings in .data reference
 * deck/deckswap.ehp, ocg/tcg pack list/name tables, and the usual UI .gim/.ehf
 * assets (see docs/modules/rel_deckswap.md for the full survey).
 *
 * STATUS -- this is a MECHANICAL first pass, not a hand-audited module: 36 of
 * 245 functions are byte-identical to the target (mwccpsp_3.0.1_219, -O4,s
 * -sdatathreshold 0), verified with mwcc_diff.py. Every match below is a
 * standalone leaf "thunk" (tail-call wrapper around an ehsys_ import or
 * another internal func_XXXXXXXX with some argument massaging) or a tiny
 * routine -- the large stateful functions are still unmatched. Every function
 * present in this file is tagged "MATCH 100%"; nothing here is a draft.
 *
 * NEW MWCC LEVERS FOUND WORKING THIS MODULE (all reusable elsewhere):
 *  1. Tail-call thunks that mask/shift an argument before forwarding it emit
 *     a single `j <target>` with the mask/shift instruction in the BRANCH
 *     DELAY SLOT (executed after the jump target is computed, before control
 *     transfers) -- e.g. `return f(a0 & 0xFFFF);` or `return f(a0 << 6);`
 *     compiles to `j f` / `andi $a0,$a0,0xFFFF` (delay slot). A bare
 *     `void f(void){g();}` wrapper compiles to `j g`/`nop` instead, so a
 *     nonzero delay-slot instruction other than `nop` is the tell that an
 *     argument transform is missing from the C.
 *  2. Several `ehsys_` imports (confirmed for ehsys_BC8E65D7, ehsys_3BB2BAC6)
 *     take MORE arguments than fit in $a0-$a3: arguments 5+ are passed in
 *     $t0, $t1, $t2, ... (NOT the o32 stack-based convention). Declaring the
 *     extern with the full arg count (e.g. `int ehsys_BC8E65D7(int,int,int,
 *     int,int)`) and simply passing 5 C arguments reproduces this register
 *     assignment exactly -- no inline asm needed.
 *  3. A thunk's own trailing formal parameter is often forwarded to the
 *     callee UNCHANGED, and MWCC then emits NO instruction to set that
 *     register at all (it is already correct from the thunk's own calling
 *     convention) -- e.g. func_00006A2C's 4th parameter lands directly in
 *     $a3/$t0 for ehsys_BC8E65D7's 4th/5th argument with zero setup
 *     instructions. A "missing" register write for the correct value, not a
 *     dead one, is the sign this is happening: check whether an earlier
 *     formal parameter's register already holds the exact value the callee
 *     needs.
 *  4. A bitfield extract done as `(x << 27) >> 29` (explicit shift pair,
 *     unsigned) compiles to the target's literal `sll`+`srl` pair; the
 *     "obvious" `(x >> 2) & 7` form gets folded by MWCC into the single
 *     Allegrex `ext` instruction instead, which is one word SHORTER than the
 *     target and therefore a guaranteed non-match whenever the target used
 *     the two-instruction shift-pair form (func_0000B55C).
 *  5. Raw absolute-address volatile pointers (`*(volatile int *)0x8E73B4 = x;`)
 *     to the SAME %hi(0x8E....) upper-16-bits as a second store CSE into one
 *     shared `lui` on this compiler UNLESS the addresses are literal integer
 *     constants the compiler folds at compile time -- this one (func_00015210
 *     in rel_shop, not this module, but recorded here since it was found
 *     during this module's sweep) could not be forced to re-materialise the
 *     `lui` a second time from any portable-C phrasing tried; left NONMATCHING.
 *
 * CAUTION recorded from this module: scripts/mwcc_diff.py's relocation
 * leniency (matching R_MIPS_HI16/LO16/26 by symbol+kind only) does NOT check
 * that the two sides use the same LOAD/STORE WIDTH for that relocation -- a
 * candidate `extern char G;` producing `lb`/`sb` against a target `lw`/`sw`
 * on the SAME symbol was reported "MATCH" even though the object code truly
 * differs (func_0000BB8C's original char-typed globals). Always declare a
 * word-accessed global as `int`/pointer, never `char`/`short`, even if the
 * differ does not currently catch the mismatch -- confirmed on func_0000BB8C
 * (D_0001E89C, D_0001F984) here and func_0000F040/func_00001F54 in
 * rel_select_card, func_0000F8F4 in rel_shop.
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

/* ---- imports / externs used by the matched functions below ---- */
extern char D_0001D548;
extern char D_0001D668;
extern char D_0001D930;
extern char D_0001D944;
extern char D_0001DE60;
extern char D_0001E2E0;
extern int D_0001E2E4;
extern int D_0001E884;
extern int D_0001E88C;
extern int D_0001E890;
extern int D_0001E894;
extern int D_0001E8A0;
extern int D_0001E8A4;
extern int D_0001E8A8;
extern int D_0001E8AC;
extern int D_0001E8B0;
extern int D_0001E8B4;
extern char D_0001E8C0;
extern char D_0001F040;
extern int D_0001E89C;
extern unsigned short D_0001E88A;
extern int duel_draw_2E8EDDC8();
extern int duel_draw_6D200A3F();
extern int ehsys_1460C6FD();
extern int ehsys_1856E536();
extern int ehsys_20E340D9(int, void *);
extern int ehsys_291D6262();
extern int ehsys_33ED567B();
extern int ehsys_3BB2BAC6(int, int, int, int, int, int, int);
extern int ehsys_41AABF28();
extern int ehsys_4AA58320();
extern int ehsys_5F00A362(int);
extern int ehsys_60B55A50();
extern int ehsys_942B03D0();
extern int ehsys_98E07D26();
extern int ehsys_A4AFF8E6();
extern int ehsys_B89D38DC(); /* called with 3 OR 4 args depending on site (see below) */
extern int ehsys_B8AD96EA();
extern int ehsys_BC8E65D7(int, int, int, int, int);
extern int ehsys_C07BB470(void *, int, int, int, int, int);
extern int ehsys_C9D9E989();
extern int ehsys_D853F15C();
extern int ehsys_D979E9BF();
extern int ehsys_E5738C32();
extern int ehsys_E58C0FDC();
extern int ehsys_E62CCE79();
extern int ehsys_EF9B5D06();
extern int ehsys_FE91A2EC();
extern int ehsys_get_language();
extern int ehsys_memset(void *, int, int);
extern int ehsys_sceKernelChangeCurrentThreadAttr();
extern int ehsys_CC7A2A21();
extern int func_00000CF8(void *, int);
extern int func_00014CB4();
extern int func_0000C314();
extern int func_00007FD0(int);
extern int func_0000C440();
extern int func_0000C5E8();
extern int func_0000D7DC();
extern int func_0000EE58();
extern int func_0000FFAC();
extern int func_00010068();
extern int func_000100EC();
extern int func_000102F0();
extern int func_00010CA4();
extern int func_00010E1C();
extern int func_0001101C();
extern int func_00011278();
extern int func_0001283C(int, void *, int, int, int, int);
extern int func_000152E0();
extern int func_000153A8();
extern int func_00015424();
extern int func_000154E4();
extern int func_00015594();
extern unsigned char *D_0001F984;

/* ============================================================
 * Matched functions, in address order (required for linking).
 * ============================================================ */

/* func_00000000 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_00000000(void) {
    return 0;
}

/* func_00000008 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00000008(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_v0;

    ehsys_memset(&D_0001E2E0, 0, 0x5D8);
    ehsys_memset(&D_0001E8C0, 0, 0x780);

    if (arg3 == 1) {
        temp_v0 = ehsys_C07BB470(&D_0001D548, 2, 0, 0x56E000, 1, 0);
        D_0001E8AC = temp_v0;
        ehsys_D979E9BF(temp_v0, &D_0001E8B0, 0);
        temp_v0 = ehsys_1856E536(D_0001E8B0, 0x56E000);
        D_0001E89C = temp_v0;
        temp_v0 = ehsys_41AABF28(temp_v0, 0x13C000);
        D_0001E8B4 = temp_v0;
        D_0001E8A0 = ehsys_291D6262(temp_v0, 0x13C000, 0);
    } else {
        D_0001E8A4 = duel_draw_6D200A3F();
        D_0001E8A0 = duel_draw_2E8EDDC8();
        temp_v0 = ehsys_41AABF28(D_0001E8A4, 0x432000);
        D_0001E8A8 = temp_v0;
        D_0001E89C = ehsys_1856E536(temp_v0, 0x432000);
    }
    D_0001E884 = 0;
    D_0001E88C = arg0;
    D_0001E890 = arg1;
    D_0001E894 = arg2;
    ehsys_sceKernelChangeCurrentThreadAttr(0, 0x4000);
    func_0000C314();
    ehsys_C9D9E989(1);
    ehsys_4AA58320(1);
    if (ehsys_get_language() == 0) {
        ehsys_33ED567B(1);
        ehsys_D853F15C(0);
    } else {
        ehsys_33ED567B(0);
        ehsys_D853F15C(1);
    }
    D_0001E2E4 = 0;
}

/* func_00005644 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_00005644(s32 arg0) {
    s32 sp1C;

    sp1C = arg0;
    ehsys_EF9B5D06(&sp1C, &D_0001F040);
    return sp1C;
}

/* func_0000627C -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_0000627C(int a0, unsigned short a1, int a2, int a3) {
    return func_0001283C(a0, &D_0001D668 + (a1 + 1) * 6, a2, a3 + 1, 0xA4, 0);
}

/* func_00006A0C -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_00006A0C(int a0, int a1, int a2) {
    return ehsys_B89D38DC(a0 << 6, a1 << 6, (0x1E0 - a0) << 6, a2);
}

/* func_00006A2C -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_00006A2C(int a0, int a1, int a2, int a3) {
    return ehsys_BC8E65D7(a0 << 6, a1 << 6, a2 << 6, a3, -1);
}

/* func_000077C0 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_000077C0(s32 arg0, s32 arg1) {
    s32 temp_a0;
    s32 var_v0;

    temp_a0 = arg0 & 0xFFFF;
    if ((u32) (temp_a0 - 0x1386) < 3U) {
        var_v0 = 1;
    } else {
        var_v0 = func_00014CB4(ehsys_CC7A2A21(temp_a0) & 0xFFFF);
    }
    if (arg1 & (1 << var_v0)) {
        return 1;
    }
    return 0;
}

/* func_00007820 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_00007820(s32 arg0, s32 arg1) {
    s32 temp_s0;

    temp_s0 = arg0 & 0xFFFF;
    if ((ehsys_E5738C32(temp_s0) != 0) && (arg1 & (1 << ehsys_98E07D26(temp_s0)))) {
        return 1;
    }
    return 0;
}

/* func_00007884 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_00007884(s32 arg0, s32 arg1) {
    s32 temp_s0;

    temp_s0 = arg0 & 0xFFFF;
    if ((ehsys_E5738C32(temp_s0) != 0) && (arg1 & (1 << ehsys_E62CCE79(temp_s0)))) {
        return 1;
    }
    return 0;
}

/* func_00007B70 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_00007B70(s32 arg0, s32 arg1) {
    return (arg1 & (1 << ehsys_FE91A2EC(arg0 & 0xFFFF))) != 0;
}

/* func_0000A1B8 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_0000A1B8(int a0, unsigned short a1, int a2, int a3) {
    return func_0001283C(a0, &D_0001D930 + a1 * 6, a2, a3 + 1, 0xE8, 0);
}

/* func_0000A1E4 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_0000A1E4(int a0, unsigned short a1, int a2, int a3) {
    return func_0001283C(a0, &D_0001D944 + a1 * 6, a2, a3 + 1, 0xE8, 0);
}

/* func_0000A210 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_0000A210(int a0) {
    return func_00007FD0(a0 & 0xFFFF);
}

/* func_0000B55C -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_0000B55C(void) {
    unsigned char *p = D_0001F984;
    unsigned short h = *(unsigned short *) (p + 2);
    unsigned int field = (unsigned int) (p[6] << 27) >> 29;
    return func_00000CF8(&D_0001E2E0 + field * 32 + 0xC, h);
}

/* func_0000BB8C -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_0000BB8C(void) {
    if (D_0001F984 != 0) {
        ehsys_20E340D9(D_0001E89C, D_0001F984);
        D_0001F984 = 0;
    }
}

/* func_0000C29C -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_0000C29C(u16 *arg0, u16 *arg1) {
    return *arg0 - *arg1;
}

/* func_0000C438 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_0000C438(void) {
    func_0000C440();
}

/* func_0000D21C -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_0000D21C(int a0, unsigned short a1, int a2, int a3) {
    return func_0001283C(a0, &D_0001DE60 + (a1 + 1) * 6, a2, a3 + 1, 0x88, 0);
}

/* func_0000D9D8 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_0000D9D8(void) {
    func_0000D7DC();
}

/* func_0000EDBC -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_0000EDBC(s32 arg0, int arg1, int arg2, int arg3) {
    s32 temp_s0;

    temp_s0 = ehsys_E58C0FDC(func_0000C5E8(0x8033), 0x9A);
    ehsys_B8AD96EA(arg0);
    ehsys_942B03D0(0xC, 0xC);
    ehsys_60B55A50(-1);
    func_0000EE58(arg1, arg2, arg3, temp_s0);
    ehsys_A4AFF8E6();
}

/* func_0000EE58 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_0000EE58(int a0, int a1, int a2, int a3) {
    return ehsys_BC8E65D7(a0 << 6, a1 << 6, a2 << 6, a3, -1);
}

/* func_0000EE6C -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_0000EE6C(s32 arg0, int arg1, s32 arg2, int arg3) {
    s32 var_s4;
    s32 temp_s4;

    if (D_0001E88A == 0) {
        var_s4 = 0x99;
    } else {
        var_s4 = 0x98;
    }
    temp_s4 = ehsys_E58C0FDC(func_0000C5E8(0x8033), var_s4);
    ehsys_B8AD96EA(arg0);
    ehsys_942B03D0(0xC, 0xC);
    ehsys_60B55A50(0xFF000000);
    func_0000EE58(arg1, arg2 - 2, arg3, temp_s4);
    ehsys_A4AFF8E6();
}

/* func_0000F3A4 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_0000F3A4(int a0, int a1, int a2) {
    return ehsys_B89D38DC(a0 << 6, a1 << 6, (0x1E0 - a0) << 6, a2);
}

/* func_0000F3C4 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_0000F3C4(int a0, int a1, int a2) {
    return ehsys_B89D38DC(a0 << 6, a1 << 6, a2 << 6);
}

/* func_0000FF1C -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_0000FF1C(int a0, int a1, int a2, int a3) {
    return ehsys_BC8E65D7(a0 << 6, a1 << 6, a2 << 6, a3, -1);
}

/* func_0000FF30 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_0000FF30(void) {
    s32 var_s0;

    var_s0 = func_00010E1C(func_00010CA4(func_000102F0(func_00011278(func_000100EC(func_00010068(func_0000FFAC()), (u8) D_0001E8C0 & 0xF)))));
    if (ehsys_1460C6FD() != 0) {
        var_s0 = func_0001101C(var_s0);
    }
    return var_s0;
}

/* func_00010C90 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_00010C90(int a0, int a1, int a2, int a3) {
    return ehsys_BC8E65D7(a0 << 6, a1 << 6, a2 << 6, a3, -1);
}

/* func_00011120 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_00011120(int a0, int a1, int a2) {
    return ehsys_B89D38DC(a0 << 6, a1 << 6, (0x1E0 - a0) << 6, a2);
}

/* func_00011DC0 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_00011DC0(int a0, int a1, int a2) {
    return ehsys_B89D38DC(a0 << 6, a1 << 6, a2 << 6);
}

/* func_00012618 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_00012618(int a0, int a1, int a2, int a3) {
    return ehsys_BC8E65D7(a0, a1, a2, a3, -1);
}

/* func_00012620 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00012620(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    func_000152E0(arg0, (arg1 & 0xFFFF) | ((arg2 & 0xFFFF) << 0x10), arg3, func_0000C5E8(0x8007));
}

/* func_0001268C -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_0001268C(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    func_000153A8(arg0, (arg1 & 0xFFFF) | ((arg2 & 0xFFFF) << 0x10), arg3, func_0000C5E8(0x8007));
}

/* func_000126F8 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_000126F8(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    func_00015424(arg0, (arg1 & 0xFFFF) | ((arg2 & 0xFFFF) << 0x10), arg3, func_0000C5E8(0x8007));
}

/* func_00012764 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00012764(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    func_000154E4(arg0, (arg1 & 0xFFFF) | ((arg2 & 0xFFFF) << 0x10), arg3, func_0000C5E8(0x800A));
}

/* func_000127D0 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_000127D0(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    func_00015594(arg0, (arg1 & 0xFFFF) | ((arg2 & 0xFFFF) << 0x10), arg3, func_0000C5E8(0x800A));
}

/* func_000146CC -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_000146CC(int a0, int a1, int a2, int a3) {
    return ehsys_BC8E65D7(a0 << 6, a1 << 6, a2 << 6, a3, -1);
}

/* func_000169A4 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_000169A4(int a0, int a1, int a2, int a3) {
    return ehsys_BC8E65D7(a0 << 6, a1 << 6, a2 << 6, a3, -1);
}

/* func_00017C9C -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_00017C9C(int a0, int a1, int a2, int a3, int a4) {
    return ehsys_3BB2BAC6(a0 << 6, a1 << 6, a2 << 6, a3 << 6, a4, -1, 0);
}

/* func_00017CB8 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_00017CB8(int a0) {
    return ehsys_5F00A362(a0 << 6);
}
