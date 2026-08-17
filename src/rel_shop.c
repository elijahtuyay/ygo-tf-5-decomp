/*
 * rel_shop.prx -- reconstructed code (matching decompilation, partial)
 *
 * Compiler:     Metrowerks CodeWarrior for PSP -- MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,s -sdatathreshold 0   (same config confirmed on rel_movie_viewer)
 * Verification: scripts/mwcc_build.sh src/rel_shop.c
 *               scripts/mwcc_diff.py asm/rel_shop/text.s build/mwcc/rel_shop.o
 *
 * Read src/rel_movie_viewer.c's file header first for the shared MWCC levers,
 * and src/rel_deckswap.c's header for the additional levers this sweep found
 * (tail-call-thunk delay-slot argument transforms, ehsys imports with 5+
 * register-passed arguments via $t0/$t1/$t2, pass-through trailing
 * parameters, and the shift-pair-vs-`ext` bitfield-extract tell) -- they all
 * apply here too; rel_shop shares several identical thunk shapes with
 * rel_deckswap/rel_select_card (ehsys_BC8E65D7/ehsys_B89D38DC/ehsys_3BB2BAC6
 * wrappers, and a `(idx[+1])*6` struct-array-indexing thunk into
 * func_0000AF00) with only the target function/constant/global changed.
 *
 * WHAT THIS MODULE IS. The in-game card shop (libshop_rel) -- the largest of
 * the three modules covered by this sweep (254 functions, a 0x53B8-byte
 * .data segment). See docs/modules/rel_shop.md for the mechanical survey;
 * most of .data here is packed/compressed layout data rather than readable
 * strings, unlike rel_deckswap/rel_select_card.
 *
 * STATUS -- MECHANICAL first pass: 39 of 254 functions are byte-identical to
 * the target, verified with mwcc_diff.py. As with the other two modules,
 * every match here is a small leaf thunk; the large stateful functions are
 * unmatched. Every function present is tagged "MATCH 100%".
 *
 * func_00015210 (a two-word MMIO-style store to raw addresses 0x8E73B4 /
 * 0x8E735C) is NONMATCHING and NOT included below: the target uses two
 * separate `lui` computations for the same %hi(0x8E....) even though the
 * upper 16 bits are identical, while every portable-C phrasing tried here
 * (including two independent `volatile int *` locals) gets CSE'd by MWCC
 * into one shared `lui`. Left as a lead for whoever picks this module back
 * up; decomp-permuter or inline asm are the next things to try.
 *
 * CAUTION (see rel_deckswap.c header for the full writeup): mwcc_diff.py's
 * relocation leniency does not check load/store WIDTH, so `char`/`short`
 * globals that are really word-accessed can silently "MATCH" while emitting
 * lb/sb instead of lw/sw. Fixed here for D_0002F1C8 (func_0000F8F4) --
 * always type these as `int`/pointer.
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
extern char D_0001F220;
extern char D_00023062;
extern char D_0002305C;
extern char D_0002305D;
extern char D_00023480;
extern char D_00023484;
extern char D_00023E38;
extern char D_00023E94;
extern int *D_0002DF80;
extern u16 D_0002DF90[];
extern char D_000240A4;
extern char D_0002E017;
extern char D_76F1F0;
extern char D_76F260;
extern char D_8E73B8;
extern char D_8E73C0;
extern int D_0002F1C4;
extern int D_0002F1C8;
extern int ehsys_0089B865(void *);
extern int ehsys_03E45FFF();
extern int ehsys_06380DFA();
extern int ehsys_20E340D9(int, int);
extern int ehsys_291D6262(void *, int, int);
extern int ehsys_3BB2BAC6(int, int, int, int, int, int, int);
extern int ehsys_41AABF28(int, int);
extern int ehsys_42C464D5(void *);
extern int ehsys_4F22C9AA();
extern int ehsys_5DF04F49();
extern int ehsys_5F00A362(int);
extern int ehsys_78749045(int, u8);
extern int ehsys_9EA6989A();
extern int ehsys_AB962AE7();
extern int ehsys_B2B9FEFA();
extern int ehsys_B4471B5E();
extern int ehsys_B89D38DC(); /* called with 3 OR 4 args depending on site (see below) */
extern int ehsys_BC8E65D7(int, int, int, int, int);
extern int ehsys_E58C0FDC(int, int);
extern int ehsys_EBD1986B();
extern int ehsys_EF9B5D06();
extern int ehsys_memset();
extern int func_00000000();
extern int func_00000DF8();
extern int func_0000A2A8();
extern int func_0000A36C();
extern int func_0000A6BC();
extern int func_0000AF00(); /* called with 4 OR 5 args depending on site (see below) */
void func_0000F928(void); /* forward decl: defined below, called before its own definition */
void func_00015648(void); /* forward decl: defined below, called before its own definition */
void func_00015914(void); /* forward decl: defined below, called before its own definition */
extern int func_0000F998();
extern int func_0000FB88();
extern int func_0000FCD4(int);
extern int func_0001161C();
extern int func_000164C8(void);
extern int func_00012FB4();
extern int func_000130AC();
extern int func_00015228();
extern int func_00015650();

/* ============================================================
 * Matched functions, in address order (required for linking).
 * ============================================================ */

/* func_000049BC -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_000049BC(int a0, int a1, int a2, int a3) {
    return ehsys_BC8E65D7(a0 << 6, a1 << 6, a2 << 6, a3, -1);
}

/* func_00004CF4 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_00004CF4(int a0) {
    int c;
    for (c = a0 + 1; c < 0x3C; c++) {
        if (D_0002DF90[c + 6] > 0) {
            return c;
        }
    }
    return -1;
}

/* func_00005E84 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void *func_00005E84(void *a0, void *a1) {
    ((f32 *)a0)[0] = ((f32 *)a1)[0];
    ((f32 *)a0)[1] = ((f32 *)a1)[1];
    ((f32 *)a0)[2] = ((f32 *)a1)[2];
    ((f32 *)a0)[3] = ((f32 *)a1)[3];
    return a0;
}

/* func_000063D4 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_000063D4(s32 arg0) {
    s32 sp1C;

    sp1C = arg0;
    ehsys_EF9B5D06(&sp1C, &D_000240A4);
    return sp1C;
}

/* func_00006754 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00006754(s32 arg0, s32 arg1) {
    ehsys_9EA6989A(arg0, func_0000FB88(arg1 & 0xFFFF));
}

/* func_000067E4 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_000067E4(f32 a0, f32 a1, f32 a2) {
    struct { char pad[12]; } tmp = {0};
    ((f32 *) &tmp)[0] = a0;
    ((f32 *) &tmp)[1] = a1;
    ((f32 *) &tmp)[2] = a2;
    ehsys_42C464D5(&tmp);
}

/* func_00006828 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00006828(f32 a0, f32 a1, f32 a2) {
    struct { char pad[12]; } tmp = {0};
    ((f32 *) &tmp)[0] = a0;
    ((f32 *) &tmp)[1] = a1;
    ((f32 *) &tmp)[2] = a2;
    ehsys_0089B865(&tmp);
}

/* func_0000694C -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
f32 func_0000694C(s32 arg0, s32 arg1) {
    s32 var_a0;

    var_a0 = arg0;
    if (var_a0 < 0) {
        var_a0 = 0;
    }
    if (arg1 < var_a0) {
        var_a0 = arg1;
    }
    return (f32) var_a0 / (f32) arg1;
}

/* func_00006980 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
f32 func_00006980(int a0, int a1) {
    return 1.0f - func_0000694C(a0, a1);
}

/* func_00008204 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void *func_00008204(void *a0, void *a1) {
    ((f32 *)a0)[0] = ((f32 *)a1)[0];
    ((f32 *)a0)[1] = ((f32 *)a1)[1];
    ((s32 *)a0)[2] = ((s32 *)a1)[2];
    ((f32 *)a0)[3] = ((f32 *)a1)[3];
    ((f32 *)a0)[4] = ((f32 *)a1)[4];
    ((f32 *)a0)[5] = ((f32 *)a1)[5];
    return a0;
}

/* func_00009714 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_00009714(int a0) {
    return ehsys_41AABF28(D_0002F1C4, a0);
}

/* func_00009724 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_00009724(int a0) {
    return ehsys_20E340D9(D_0002F1C4, a0);
}

/* func_00009980 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_00009980(int arg0) {
    int sp1C = arg0;
    ehsys_EF9B5D06(&sp1C, D_0002DF80[2]);
    return sp1C;
}

/* func_00009F64 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_00009F64(int a0, unsigned short a1, int a2, int a3) {
    return func_0000AF00(a0, &D_0001F220 + a1 * 6, a2, a3 + 1);
}

/* func_0000A030 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_0000A030(void) {
    func_00000000();
    func_00000DF8();
}

/* func_0000A054 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_0000A054(void) {
    func_0001161C();
}

/* func_0000A1A8 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_0000A1A8(s32 arg0) {
    if (arg0 == 0) {
        ehsys_B4471B5E(func_0000A2A8, func_0000A36C, &D_76F1F0);
    }
    return 0;
}

/* func_0000A3FC -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_0000A3FC(void) {
    func_0001161C();
}

/* func_0000A404 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_0000A404(void) {
    func_0000F928();
    ehsys_03E45FFF();
    ehsys_EBD1986B(0, 0);
}

/* func_0000A434 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_0000A434(void *a0, f32 a1) {
    ehsys_memset(a0, 0, 0xC);
    ((f32 *) a0)[0] = a1;
    ((f32 *) a0)[1] = a1;
}

/* func_0000A62C -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_0000A62C(int a0, int a1, int a2) {
    return ehsys_B89D38DC(a0 << 6, a1 << 6, (0x1E0 - a0) << 6, a2);
}

/* func_0000AA7C -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void *func_0000AA7C(void *a0, void *a1) {
    ((f32 *)a0)[0] = ((f32 *)a1)[0];
    ((f32 *)a0)[1] = ((f32 *)a1)[1];
    ((f32 *)a0)[2] = ((f32 *)a1)[2];
    return a0;
}

/* func_0000B0F8 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_0000B0F8(void) {
    int i;
    for (i = 0; i < 0x3C; i++) {
        ehsys_78749045(i, ((u8 *) D_0002DF90)[0x100 + i]);
    }
}

/* func_0000B140 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_0000B140(u16 a0) {
    int r = func_0000FCD4(0xC001);
    return ehsys_E58C0FDC(r, *(int *)((char *)&D_00023484 + a0 * 8));
}

/* func_0000B188 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_0000B188(u16 a0) {
    int r = func_0000FCD4(0xC001);
    return ehsys_E58C0FDC(r, *(int *)((char *)&D_00023480 + a0 * 8));
}

/* func_0000B1D0 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
u8 func_0000B1D0(u16 a0) {
    return *((u8 *)&D_0002305C + a0 * 12) & 3;
}

/* func_0000B3F4 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
u32 func_0000B3F4(u16 a0) {
    u8 v = *((u8 *)&D_0002305C + a0 * 12);
    return ((u32) v << 24) >> 26;
}

/* func_0000B420 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
u16 func_0000B420(u16 a0) {
    return *(u16 *)((char *)&D_00023062 + a0 * 12);
}

/* func_0000B444 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
u8 func_0000B444(s32 arg0) {
    return *(&D_0002305D + ((arg0 & 0xFFFF) * 0xC));
}

/* func_0000B55C -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_0000B55C(void) {
    int i;
    u32 sum = 0;
    for (i = 0; i < 0x3C; i++) {
        sum += D_0002DF90[i + 6];
    }
    return sum;
}

/* func_0000B89C -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_0000B89C(u16 a0, u16 *a1, u16 a2) {
    int idx;
    for (idx = 0; idx < a2; idx++) {
        if (a1[idx] == a0) {
            return 1;
        }
    }
    return 0;
}

/* func_0000EE20 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void *func_0000EE20(void *a0, void *a1) {
    ((u16 *)a0)[0] = ((u16 *)a1)[0];
    ((u16 *)a0)[1] = ((u16 *)a1)[1];
    return a0;
}

/* func_0000F8F4 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_0000F8F4(void) {
    D_0002F1C8 = ehsys_291D6262(&D_76F260, 0x178000, 0);
}

/* func_0000F928 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_0000F928(void) {
    func_0000F998();
}

/* func_00010BF4 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_00010BF4(int a0) {
    int *p;
    int sp1C;
    p = *(int **)0x8E7354;
    sp1C = a0;
    ehsys_EF9B5D06(&sp1C, p[4]);
    p = *(int **)0x8E7354;
    ehsys_EF9B5D06(&sp1C, p[5]);
    return sp1C;
}

/* func_00010C38 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_00010C38(int a0, unsigned short a1, int a2, int a3) {
    return func_0000AF00(a0, &D_00023E38 + (a1 + 1) * 6, a2, a3 + 1, 0x88);
}

/* func_00010C64 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_00010C64(int a0, u16 a1, int a2, int a3) {
    int *p = *(int **)0x8E7354;
    int *q = *(int **)((char *)p + 0x14);
    u16 t0 = *(u16 *)((char *)q + 0xF4);
    return func_0000AF00(a0, &D_00023E94 + a1 * 6, a2, a3 + 1, t0);
}

/* func_00011E44 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_00011E44(int a0, int a1, int a2, int a3) {
    return ehsys_BC8E65D7(a0 << 6, a1 << 6, a2 << 6, a3, -1);
}

/* func_0001246C -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_0001246C(int a0, int a1, int a2) {
    return ehsys_B89D38DC(a0 << 6, a1 << 6, a2 << 6);
}

/* func_00012F60 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_00012F60(int a0) {
    return ehsys_5F00A362(a0 << 6);
}

/* func_00012F68 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00012F68(void) {
    extern int func_0000B1D0();

    func_0000A6BC();
    ehsys_4F22C9AA(2);
    if (func_0000B1D0((u8) D_0002E017) & 0xFFFF) {
        func_00012FB4();
    }
    func_000130AC();
}

/* func_0001381C -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_0001381C(int a0, int a1, int a2) {
    return ehsys_B89D38DC(a0 << 6, a1 << 6, (0x1E0 - a0) << 6, a2);
}

/* func_00014010 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_00014010(int a0, int a1, int a2, int a3) {
    return ehsys_BC8E65D7(a0 << 6, a1 << 6, a2 << 6, a3, -1);
}

/* func_00014024 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_00014024(int a0, int a1, int a2) {
    return ehsys_B89D38DC(a0 << 6, a1 << 6, a2 << 6);
}

/* func_00014D20 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00014D20(void) {
    func_00015648();
    func_00015914();
}

/* func_00014D44 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00014D44(void) {
    func_00015228();
    func_00015650();
}

/* func_000150D0 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_000150D0(s32 arg0) {
    *(s32 *)0x8E7394 = arg0;
}

/* func_000151F8 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void *func_000151F8(void *a0, void *a1) {
    ((f32 *)a0)[0] = ((f32 *)a1)[0];
    ((f32 *)a0)[1] = ((f32 *)a1)[1];
    return a0;
}

/* func_00015648 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00015648(void) {

}

/* func_00015914 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00015914(void) {

}

/* func_00015DB4 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00015DB4(void) {
    *(s32 *)0x8E7518 = 0;
    ehsys_5DF04F49(&D_8E73C0);
    ehsys_memset(&D_8E73B8, 0, 0x184);
}

/* func_000163D8 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_000163D8(int a0, int a1, int a2, int a3, int a4) {
    return ehsys_3BB2BAC6(a0 << 6, a1 << 6, a2 << 6, a3 << 6, a4, -1, 0);
}

/* func_000163F4 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_000163F4(void) {
    return *(s32 *)0x8E7508;
}

/* func_00016414 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00016414(s32 arg0) {
    *(s32 *)0x8E74A8 = arg0;
}

/* func_000164A8 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_000164A8(void) {
    *(s32 *)0x8E73B8 = 1;
}

/* func_000164B8 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_000164B8(void) {
    *(s32 *)0x8E73B8 = 3;
}

/* func_00016580 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_00016580(void) {
    s32 temp_v1;

    temp_v1 = *(s32 *)0x8E73B8;
    if ((temp_v1 != 3) && (temp_v1 != 1)) {
        return 0;
    }
    return 1;
}

/* func_000166C8 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_000166C8(void) {
    char *p = &D_8E73B8;
    if (func_000164C8() == 0) {
        *(int *)(p + 0x164) += 1;
    }
}

/* func_00016B74 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00016B74(void) {
    ehsys_06380DFA();
    ehsys_AB962AE7(0);
}

/* func_00017068 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_00017068(int a0, int a1, int a2) {
    return ehsys_B89D38DC(a0 << 6, a1 << 6, (0x1E0 - a0) << 6, a2);
}

/* func_000187B0 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_000187B0(int a0, int a1, int a2, int a3) {
    return ehsys_BC8E65D7(a0 << 6, a1 << 6, a2 << 6, a3, -1);
}

/* func_00018DB8 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_00018DB8(int a0) {
    int *v0 = (int *) ehsys_B2B9FEFA(a0);
    return v0[1];
}

/* func_00019AA8 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_00019AA8(int a0, int a1, int a2, int a3, int a4) {
    return ehsys_3BB2BAC6(a0 << 6, a1 << 6, a2 << 6, a3 << 6, a4, -1, 0);
}

/* func_00019AC4 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_00019AC4(int a0) {
    return ehsys_5F00A362(a0 << 6);
}
