/*
 * rel_tutoriallist.prx — reconstructed code (matching decompilation)
 *
 * Compiler:     Metrowerks CodeWarrior for PSP — MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,s -sdatathreshold 0
 * Verification: scripts/mwcc_build.sh src/rel_tutoriallist.c
 *               scripts/mwcc_diff.py asm/rel_tutoriallist/text.s build/mwcc/rel_tutoriallist.o
 *
 * Every function below is byte-identical to the shipped module — each was
 * accepted only on a MATCH verdict from scripts/mwcc_diff.py, and the whole
 * file is re-verified after assembly (scripts/assemble_module.py).
 * Functions are in ADDRESS ORDER, which is what the linker needs.
 *
 * Import names are resolved from the module's NID tables and are identical
 * across all 28 modules — see docs/nids/README.md.
 *
 * STATUS: 22 of 30 matchable functions matched here (func_00001264 is
 * hand-written assembly and permanently excluded). Remaining: func_0000231C
 * (41/42 words, shared-delay-slot layout), func_00000FD8 ($s0/$s1 register
 * swap resisting the usual fixes), func_000017E0 (target keeps a null-check
 * guard on a provably-nonnull stack address that MWCC's own optimizer keeps
 * folding away from equivalent C), and func_00000000/func_00000678/
 * func_000014E8/func_00001880/func_00001C68 (large, not yet attempted this
 * session). build/auto/<module>.json has the status of every attempt.
 *
 * NOTE: assembled by scripts/assemble_module.py from drafts produced by
 * scripts/auto_decomp.py (m2c + source reshapes + verification). Local names
 * are therefore still m2c's (temp_v0, var_s1); renaming them and adding
 * per-function commentary is safe as long as every edit is re-verified.
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

/* ---- imports and globals ---- */
extern char D_00007C04;
extern char D_00007D0C;
extern char D_00007D10;
extern char D_00007D14;
extern char D_00007BC0;
extern char D_00007C00;
extern u16 D_00007C10;
extern u16 D_00007CBC[];
extern int ehsys_09794DF0();
extern int ehsys_13A4081A();
extern int ehsys_20E340D9();
extern int ehsys_3BB2BAC6();
extern int ehsys_41AABF28();
extern int ehsys_450CD6C5();
extern int ehsys_5CBB9E43();
extern int ehsys_60B55A50();
extern int ehsys_7187E0F0();
extern int ehsys_8288EEBC();
extern int ehsys_85F89FE8();
extern int ehsys_89812D8A();
extern int ehsys_8EA6B1E7();
extern int ehsys_942B03D0();
extern int ehsys_97BB99A5();
extern int ehsys_9EA6989A();
extern int ehsys_A4AFF8E6();
extern int ehsys_AB962AE7();
extern s32 *ehsys_B2B9FEFA();
extern int ehsys_B89D38DC();
extern int ehsys_B8AD96EA();
extern int ehsys_CABEA834();
extern int ehsys_D2A768F4();
extern int ehsys_D470D0B2();
extern int ehsys_E58C0FDC();
extern int ehsys_E6E4401F();
extern int ehsys_ED1410E0();
extern int ehsys_F462EE6E();
extern int ehsys_F6414A71();
extern int ehsys_FDD168CA();
extern int ehsys_get_language();
extern int ehsys_C07BB470();
extern int ehsys_D979E9BF();
extern int ehsys_1856E536();
extern int ehsys_sceKernelChangeCurrentThreadAttr();
extern int ehsys_C9D9E989();
extern int ehsys_4AA58320();
extern int ehsys_33ED567B();
extern int ehsys_D853F15C();
extern u16 D_00007C16;
extern int ehsys_memset();
extern int ehsys_qsort();
extern int func_000017E0();
extern int func_00001880();
extern int func_00001C68();
extern int func_0000231C();
extern int func_000024B4();
extern int ehsys_sprintf();
extern int ehsys_C6C15111();

typedef struct {
    s32 id;
    s32 cache;
    char *fmt;
} TutorialTextEntry;
extern TutorialTextEntry D_00007B90[];
extern char D_00007BDC[6];

/* ---- forward declarations ---- */
s32 func_00000454(s32 arg0);
s32 func_00000510(s32 arg0);
s32 func_00000B9C(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_00000D58(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
s32 func_00000D74(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
s32 func_00000FD8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
s32 func_000017C0(void);
s32 func_00002404(void);
s32 func_00002630(u16 *arg0, u16 *arg1);
s32 func_00002640(s32 arg0, u16 *arg1, s32 arg2, s32 arg3);
s32 func_000025A0(s32 arg0, s32 arg1);
s32 func_000026B8(void);
s32 func_00002908(void);
s32 func_000027E4(void);
void func_000022B8(void);
void func_00000658(s32 arg0, s32 arg1, int arg2);
void func_00000B8C(s32 arg0, s32 arg1, s32 arg2);
void func_00001C5C(s32 arg0, s32 arg1);
void func_000023C4(void);
void func_000023CC(void);
void func_000026C0(s32 arg0, s32 arg1);

/* func_00000454 — 47 words. Same ehsys UI-chain shape; the stack buffer
 * has to be sized to the full 0x60-byte memset (not just the single word
 * actually read back) or MWCC allocates too small a frame. MATCH 100%. */
s32 func_00000454(s32 arg0) {
    s32 sp10[24];
    s32 temp_v0;
    s32 v;

    temp_v0 = func_000024B4(0x1011);
    if (temp_v0 == 0) {
        return arg0;
    }
    ehsys_memset(sp10, 0, 0x60);
    sp10[0] = *ehsys_B2B9FEFA();
    arg0 = ehsys_85F89FE8(arg0);
    v = ehsys_7187E0F0(arg0, temp_v0, sp10);
    v = ehsys_89812D8A(v);
    v = ehsys_F462EE6E(v, 4);
    v = ehsys_09794DF0(v, 0, 1);
    return ehsys_5CBB9E43(v, 0, 2, 3, 0, 0);
}

/* func_00000510 — 82 words. Long chain of ehsys UI helper calls; only
 * matches once the first call's result is kept in a distinct local
 * (aliasing arg0 itself, matching the target's register reuse) rather than
 * nested straight into the next call. MATCH 100%. */
s32 func_00000510(s32 arg0) {
    s32 temp_s0;
    s32 temp_v0;

    temp_v0 = func_000024B4(0x1003);
    if (temp_v0 == 0) {
        return arg0;
    }
    arg0 = ehsys_9EA6989A(arg0, temp_v0);
    temp_s0 = ehsys_FDD168CA(
        ehsys_8EA6B1E7(
            ehsys_FDD168CA(
                ehsys_FDD168CA(
                    ehsys_8EA6B1E7(
                        ehsys_E6E4401F(
                            ehsys_CABEA834(arg0, -1),
                            0, 0),
                        0xC, 0x17, 0xC, 0x17),
                    0, 0, 0, 0, 0x14, 0, 0),
                0x1D4, 0, 0, 0xD, 0x14, 0, 0),
            1, 0x17, 0x1C8, 0x17),
        0xC, 0, 0, 0xC, 0x14, 0, 0);
    ehsys_942B03D0(0xE, 0xE);
    ehsys_60B55A50(-1);
    ehsys_B8AD96EA(temp_s0);
    func_00000658(8, 4, ehsys_E58C0FDC(func_000024B4(0x1020), 1));
    return ehsys_A4AFF8E6();
}

/* func_00000658 — 8 words. MATCH 100% (shape: hand). */
void func_00000658(s32 arg0, s32 arg1, int arg2) {
    ehsys_B89D38DC(arg0 << 6, arg1 << 6, (0x1E0 - arg0) << 6, arg2);
}

/* func_00000B8C — 4 words. MATCH 100% (shape: hand). */
void func_00000B8C(s32 arg0, s32 arg1, s32 arg2) {
    ehsys_B89D38DC(arg0 << 6, arg1 << 6, arg2 << 6);
}

/* func_00000B9C — 111 words. Same ehsys UI-chain shape as func_00000510,
 * plus a language-dependent width pick and forwards into func_00000D74 /
 * func_000017E0 / func_00000D58. MATCH 100%. */
s32 func_00000B9C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_v0;
    s32 temp2;
    s32 temp_s3;
    s32 temp_s4;
    s32 var_v0;
    s32 v;

    temp_v0 = func_000024B4(0x1003);
    if (temp_v0 == 0) {
        return arg0;
    }
    arg0 = ehsys_9EA6989A(arg0, temp_v0);
    temp2 = ehsys_FDD168CA(
                ehsys_8EA6B1E7(
                    ehsys_E6E4401F(
                        ehsys_CABEA834(arg0, -1),
                        0, 0),
                    0x19, 0x15, 0x19, 0x15),
                arg1, arg2 + 1, 0, 0, 0x2B, 0, 0);
    temp_s3 = D_00007CBC[arg3] * 0x18;
    temp_s4 = func_00000D74(temp2, arg1 + 0x1B, arg2, 0x11B, temp_s3 - 1);
    if (ehsys_get_language() == 0) {
        ehsys_AB962AE7(0x280);
    } else {
        ehsys_AB962AE7(0x180);
    }
    ehsys_B8AD96EA(temp_s4);
    ehsys_942B03D0(0xC, 0xE);
    ehsys_60B55A50(-1);
    if (arg3 >= 8) {
        var_v0 = arg3 - 8;
    } else {
        var_v0 = arg3;
    }
    func_000017E0(arg1 + 4, arg2 + 4, var_v0 + 1);
    ehsys_942B03D0(0xE, 0xE);
    ehsys_60B55A50(0xFF000000);
    v = ehsys_E58C0FDC(func_000024B4(0x1020), arg3 + 4);
    func_00000D58(arg1 + 0x20, arg2 + 5, 0x110, temp_s3 - 7, v);
    ehsys_AB962AE7(0);
    return ehsys_A4AFF8E6();
}

/* func_00000D58 — 7 words. Thunk: forwards 4 shifted args plus a dead
 * passthrough arg4 and two literal constants straight into ehsys_3BB2BAC6
 * via a tail call. MATCH 100%. */
s32 func_00000D58(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return ehsys_3BB2BAC6(arg0 << 6, arg1 << 6, arg2 << 6, arg3 << 6, arg4, -1, 0);
}

/* func_00000D74 — 153 words. Same ehsys chain-call shape as func_00000510
 * / func_00000B9C, laying out a 3x3 grid of sub-calls from two 5-arg base
 * points (temp_s0, temp_s5) computed mid-chain. MATCH 100%. */
s32 func_00000D74(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 v;
    s32 temp_s0;
    s32 temp_s5;

    v = func_000024B4(0x1003);
    if (v == 0) {
        return arg0;
    }
    arg0 = ehsys_9EA6989A(arg0, v);
    v = ehsys_CABEA834(arg0, -1);
    v = ehsys_E6E4401F(v, 0, 0);
    v = ehsys_8EA6B1E7(v, 6, 6, 6, 6);
    v = ehsys_FDD168CA(v, arg1, arg2, 0, 0x19, 0x2F, 0, 0);
    temp_s0 = arg2 + arg4 - 6;
    v = ehsys_FDD168CA(v, arg1, temp_s0, 0, 0x19, 0x3A, 0, 0);
    v = ehsys_8EA6B1E7(v, 6, 6, 6, 6);
    temp_s5 = arg1 + arg3 - 6;
    v = ehsys_FDD168CA(v, temp_s5, arg2, 0, 0x24, 0x2F, 0, 0);
    v = ehsys_FDD168CA(v, temp_s5, temp_s0, 0, 0x24, 0x3A, 0, 0);
    v = ehsys_8EA6B1E7(v, 1, 6, arg3 - 0xC, 6);
    v = ehsys_FDD168CA(v, arg1 + 6, arg2, 0, 0x1F, 0x2F, 0, 0);
    v = ehsys_FDD168CA(v, arg1 + 6, temp_s0, 0, 0x1F, 0x3A, 0, 0);
    v = ehsys_8EA6B1E7(v, 6, 1, 6, arg4 - 0xC);
    v = ehsys_FDD168CA(v, arg1, arg2 + 6, 0, 0x19, 0x35, 0, 0);
    v = ehsys_FDD168CA(v, temp_s5, arg2 + 6, 0, 0x24, 0x35, 0, 0);
    v = ehsys_8EA6B1E7(v, 1, 1, arg3 - 0xC, arg4 - 0xC);
    return ehsys_FDD168CA(v, arg1 + 6, arg2 + 6, 0, 0x1F, 0x35, 0, 0);
}


/* func_000017C0 — 8 words. Calls ehsys_B2B9FEFA (returns a pointer) and
 * reads back its second word. MATCH 100%. */
s32 func_000017C0(void) {
    s32 *p = ehsys_B2B9FEFA();
    return p[1];
}

/* func_00001C5C — 3 words. MATCH 100% (shape: hand). */
void func_00001C5C(s32 arg0, s32 arg1) {
    ehsys_97BB99A5(arg0, arg1, 0, 0);
}

/* func_000022B8 — 25 words. Clears D_00007C00, sets its low bit via a
 * bitfield write (see rel_shop.c header / func_00003540 in rel_limitlist
 * for the (x & ~1) | 1 lever), then qsorts a tutorial-step list. MATCH
 * 100%. */
void func_000022B8(void) {
    typedef struct {
        unsigned bit0 : 1;
        unsigned rest : 7;
    } Flags_C00;

    ehsys_memset(&D_00007C00, 0, 2);
    ((Flags_C00 *) &D_00007C00)->bit0 = 1;
    ehsys_qsort(D_00007B90, 4, 0xC, func_00002630);
}


/* func_000023C4 — 2 words. MATCH 100% (shape: m2c). */
void func_000023C4(void) {
    func_000023CC();
}

/* func_000023CC — 14 words. MATCH 100% (shape: hand). */
void func_000023CC(void) {
    if (*(int *) &D_00007C04 != 0) {
        ehsys_20E340D9(*(int *) &D_00007D0C, *(int *) &D_00007C04);
        *(int *) &D_00007C04 = 0;
    }
}

/* func_00002404 — 44 words. Bit0 of D_00007C00 gates a one-shot re-run of
 * a tutorial step: cleared via a bitfield write (see rel_shop.c header for
 * the (x & ~1) | 0 lever), then reconfigures the current step through
 * ehsys_D2A768F4/ehsys_41AABF28 and redraws it via ehsys_8288EEBC (which
 * takes the step's own redraw callback, func_000025A0, as its 5th arg).
 * `default:` written before `case 0:` in source is what gets MWCC to fold
 * the frame-restore into the branch's delay slot — reordering the cases
 * doesn't change codegen for the case bodies, only which delay slot the
 * scheduler had available when it reached the shared exit. MATCH 100%. */
s32 func_00002404(void) {
    typedef struct {
        unsigned bit0 : 1;
        unsigned rest : 7;
    } Flags_C00;
    s32 temp_v0;
    s32 temp_v0_2;

    switch (*(int *) &D_00007C04) {
    default:
        return *(int *) &D_00007C04;
    case 0:
        if (((Flags_C00 *) &D_00007C00)->bit0) {
            ((Flags_C00 *) &D_00007C00)->bit0 = 0;
            temp_v0 = ehsys_D2A768F4(3, &D_00007BC0);
            temp_v0_2 = ehsys_41AABF28(*(int *) &D_00007D0C, temp_v0);
            *(int *) &D_00007C04 = temp_v0_2;
            ehsys_8288EEBC(3, &D_00007BC0, temp_v0_2, temp_v0, func_000025A0, temp_v0_2);
        }
        return 0;
    }
}

/* func_000024B4 — 59 words. Looks up a cached formatted tutorial string by
 * id; the entry pointer lives in $s0 and the current step index in $s1.
 * Only matches once the func_00002404() call result is routed through an
 * extra intermediate temp before being stored into `step` -- without that
 * extra temp MWCC swaps the two variables' callee-saved registers even
 * though every other aspect of the code is identical. MATCH 100%. */
s32 func_000024B4(s32 arg0) {
    s32 idx;
    char sp20[256];
    char sp18[6];
    s32 step;
    TutorialTextEntry *e;
    s32 ret;
    char *src;
    char *dst;
    s32 n;

    idx = func_00002640(arg0, (u16 *) D_00007B90, 4, 0xC);
    if (idx < 0) {
        return 0;
    }
    e = &D_00007B90[idx];
    if (e->cache != 0) {
        return e->cache;
    }
    {
        s32 tmp = func_00002404();
        step = tmp;
    }
    src = D_00007BDC;
    dst = sp18;
    n = 3;
    do {
        dst[0] = src[0];
        dst[1] = src[1];
        src += 2;
        dst += 2;
        n -= 1;
    } while (n > 0);
    if (step == 0) {
        return 0;
    }
    ehsys_sprintf(sp20, e->fmt, sp18[ehsys_get_language()]);
    ret = ehsys_C6C15111(step, sp20, 0);
    e->cache = ret;
    return ret;
}

/* func_000025A0 — 36 words. Bumps the 7-bit step counter packed into bits
 * 1-7 of D_00007C00 (declared as a real bitfield here, which lets MWCC's
 * bitfield-store codegen do the wrap/mask automatically instead of the
 * explicit shift-pair-and-mask arithmetic an m2c draft produces), then
 * always sets bit0. Same call/bitfield shapes as func_00002404 and
 * func_00004634 (rel_duelrecord). MATCH 100%. */
s32 func_000025A0(s32 arg0, s32 arg1) {
    typedef struct {
        unsigned bit0 : 1;
        unsigned field : 7;
    } Flags_C00;
    s32 temp_s0;

    temp_s0 = arg1 > 0;
    if (temp_s0 != 0) {
        if (arg0 != 0) {
            ehsys_4B0DABFA(0, arg0);
        }
        ((Flags_C00 *) &D_00007C00)->field = ((Flags_C00 *) &D_00007C00)->field + 1;
    }
    ((Flags_C00 *) &D_00007C00)->bit0 = 1;
    return temp_s0;
}

/* func_00002630 — 4 words. MATCH 100% (shape: m2c). */
s32 func_00002630(u16 *arg0, u16 *arg1) {
    return *arg0 - *arg1;
}

/* func_00002640 — 30 words. Binary search over a u16 array with a
 * variable stride (arg3 is a byte offset, halved and rounded toward zero
 * to get the element stride). MATCH 100%. */
s32 func_00002640(s32 arg0, u16 *arg1, s32 arg2, s32 arg3) {
    s32 lo, hi, stride, key;

    stride = arg3 >> 1;
    if (arg3 < 0) {
        stride = (arg3 + 1) >> 1;
    }
    hi = arg2 - 1;
    key = arg0 & 0xFFFF;
    lo = 0;
    while (lo <= hi) {
        s32 mid = (lo + hi) >> 1;
        u16 val;
        if (lo + hi < 0) {
            mid = (lo + hi + 1) >> 1;
        }
        val = arg1[mid * stride];
        if (key == val) {
            return mid;
        }
        if ((s32) val < key) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return -1;
}

/* func_000026B8 — 2 words. MATCH 100% (shape: m2c). */
s32 func_000026B8(void) {
    return 0;
}

/* func_000026C0 — 73 words. Init/reset for the tutorial list module. arg0
 * has to be declared s32 (not s16, despite only ever holding a small index
 * that's later truncated into a u16 global) -- a s16 parameter makes MWCC
 * insert an extra `seh` before the sign test, one word longer than the
 * target. The final language-branch condition also needed flipping (`== 0`
 * first, bodies swapped) to get the target's `bnel` instead of `beqzl` --
 * same tell as func_000027E4/func_00002950. MATCH 100%. */
void func_000026C0(s32 arg0, s32 arg1) {
    extern char D_00007BE4;
    s32 v;
    s32 h;

    ehsys_memset(&D_00007C10, 0, 0x10C);
    if (arg1 == 0) {
        h = ehsys_C07BB470(&D_00007BE4, 2, 0, 0x200000, 1, 0);
        *(int *) &D_00007D10 = h;
        ehsys_D979E9BF(h, &D_00007D14, 0);
        v = ehsys_1856E536(*(int *) &D_00007D14, 0x200000);
        *(int *) &D_00007D0C = v;
    } else {
        *(int *) &D_00007D0C = arg1;
    }
    ehsys_sceKernelChangeCurrentThreadAttr(0, 0x4000);
    func_000022B8();
    if ((s32) arg0 >= 0) {
        D_00007C16 = arg0;
    } else {
        D_00007C16 = 8;
    }
    ehsys_C9D9E989(1);
    ehsys_4AA58320(1);
    ehsys_AB962AE7(0);
    if (ehsys_get_language() == 0) {
        ehsys_33ED567B(1);
        ehsys_D853F15C(0);
        return;
    }
    ehsys_33ED567B(0);
    ehsys_D853F15C(1);
}

/* func_000027E4 — 73 words. Tutorial-step state machine: D_00007C10 is a
 * u16 step index (lhu/sh, not char -- see rel_shop.c/rel_movie_viewer.c
 * header for the load-width lever) driving a switch over 5 states. `default`
 * has to be the LAST case in source, after case 4, for MWCC to place the
 * shared `return 0;` block physically after all case bodies -- writing it
 * between case 0 and case 1 (its natural textual position given the
 * `goto block_19` targets) still compiles, but leaves case 4 needing an
 * extra branch to skip over the shared block since MWCC then lays it out
 * mid-function. The final if/else assigning 1 vs 2 also had to have its
 * condition sense flipped (`!= 0` first) to get the target's `beql`
 * (branch-likely-equal) rather than `bnezl` -- same tell as func_00002950's
 * -1 return. MATCH 100%. */
s32 func_000027E4(void) {
    extern char D_00007C14;
    s32 var_v0;

    switch (D_00007C10) {
    case 0:
        if (func_0000231C() != 0) {
            func_00001880();
            D_00007C10 = 1;
            ehsys_D470D0B2(1, 0xFF000000, 0x10);
            ehsys_13A4081A(0);
        }
        goto block_19;
    case 1:
        if (ehsys_450CD6C5() != 0) {
            D_00007C10 = 2;
        }
        goto block_19;
    case 2:
        func_00001C68();
        goto block_19;
    case 3:
        if (ehsys_450CD6C5() != 0) {
            D_00007C10 = 4;
        }
        goto block_19;
    case 4:
        if (func_00002908() != 0) {
            if (((u32) ((u8) D_00007C14 << 0x1B) >> 0x1F) != 0) {
                var_v0 = 2;
            } else {
                var_v0 = 1;
            }
            return var_v0;
        }
        goto block_19;
    default:
block_19:
        return 0;
    }
}

/* func_00002908 — 18 words. MATCH 100% (shape: hand). */
s32 func_00002908(void) {
    func_000023C4();
    if (*(int *) &D_00007D10 > 0) {
        ehsys_F6414A71(*(int *) &D_00007D10, *(int *) &D_00007D14);
        ehsys_ED1410E0(*(int *) &D_00007D10);
    }
    return 1;
}

/* func_00002950 — 11 words. Bit 3 of D_00007C14 (extracted with the
 * shift-pair form, not `(x >> N) & 1` -- see rel_movie_viewer.c for why
 * those aren't interchangeable to MWCC) gates whether the current
 * highlighted tutorial index (D_00007C16) is valid; returns -1 (as a
 * genuine signed int literal, which compiles to `addiu $v0,-1` -- an
 * unsigned/u16 -1 constant folds to `ori` instead and is one word
 * different in opcode form) when it isn't. MATCH 100%. */
s32 func_00002950(void) {
    extern char D_00007C14;
    extern u16 D_00007C16;

    if (((u32) ((u8) D_00007C14 << 0x1B) >> 0x1F) != 0) {
        return -1;
    }
    return D_00007C16;
}

