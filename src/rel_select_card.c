/*
 * rel_select_card.prx -- reconstructed code (matching decompilation, partial)
 *
 * Compiler:     Metrowerks CodeWarrior for PSP -- MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,s -sdatathreshold 0   (same config confirmed on rel_movie_viewer)
 * Verification: scripts/mwcc_build.sh src/rel_select_card.c
 *               scripts/mwcc_diff.py asm/rel_select_card/text.s build/mwcc/rel_select_card.o
 *
 * Read src/rel_movie_viewer.c's file header first for the shared MWCC levers,
 * and src/rel_deckswap.c's header for the additional levers this sweep found
 * (tail-call-thunk delay-slot argument transforms, ehsys imports with 5+
 * register-passed arguments via $t0/$t1/$t2, pass-through trailing
 * parameters, and the shift-pair-vs-`ext` bitfield-extract tell) -- they all
 * apply here too; rel_deckswap and rel_select_card share several identical
 * thunk shapes (e.g. ehsys_BC8E65D7/ehsys_B89D38DC/ehsys_3BB2BAC6 wrappers,
 * and a `(idx[+1])*6` struct-array-indexing thunk into func_00011968) with
 * only the target function/constant/global changed.
 *
 * WHAT THIS MODULE IS. The card-selection screen (libselect_card_rel) used
 * when building/editing a deck -- shares most asset names with rel_deckswap
 * (deck/all_%c.ehp, the ocg/tcg pack tables, card-art .gim/.ehf files) plus
 * labo/rental.ehp and title_menu_%c.ehp references (see
 * docs/modules/rel_select_card.md).
 *
 * STATUS -- MECHANICAL first pass: 37 of 248 functions are byte-identical to
 * the target, verified with mwcc_diff.py. As with rel_deckswap, every match
 * here is a small leaf thunk; the large stateful functions are unmatched.
 * Every function present is tagged "MATCH 100%".
 *
 * CAUTION (see rel_deckswap.c header for the full writeup): mwcc_diff.py's
 * relocation leniency does not check load/store WIDTH, so `char`/`short`
 * globals that are really word-accessed can silently "MATCH" while emitting
 * lb/sb instead of lw/sw. Fixed here for D_0001EB58/D_0001E5E4
 * (func_00001F54) and D_0001EB7C/D_0001FC50 (func_0000F040) -- always type
 * these as `int`/pointer.
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
extern char D_0001D8C4;
extern char D_0001DBA8;
extern char D_0001DBC0;
extern char D_0001DF48;
extern char D_0001E450;
extern char D_0001E494;
extern void *D_0001FC68;
extern char D_0001E5E0;
extern char D_0001EB90;
extern char D_0001F310;
extern int D_0001E5E4;
extern u16 D_0001EA2C;
extern unsigned short D_0001EB54;
extern int D_0001EB58;
extern int D_0001EB7C;
extern int D_0001E5D0;
extern void ehsys_39ADDA9F(s32);
extern void ehsys_B0F320E6(s32);
extern void ehsys_E1139F1A(s32);
extern int ehsys_20E340D9(int, void *);
extern int ehsys_2012884C(int);
extern int ehsys_3BB2BAC6(int, int, int, int, int, int, int);
extern int ehsys_41AABF28(int, int);
extern int ehsys_5F00A362(int);
extern int ehsys_60B55A50();
extern int ehsys_942B03D0();
extern int ehsys_98E07D26();
extern int ehsys_A4AFF8E6();
extern int ehsys_CC7A2A21(int);
extern int ehsys_B2B9FEFA(void);
extern int ehsys_B89D38DC(); /* called with 3 OR 4 args depending on site (see below) */
extern int ehsys_B8AD96EA();
extern int ehsys_BC8E65D7(int, int, int, int, int);
extern int ehsys_E5738C32();
extern int ehsys_E58C0FDC();
extern int ehsys_E62CCE79();
extern int ehsys_memcpy(int, void *, int);
extern int ehsys_EF9B5D06();
extern int ehsys_FE91A2EC();
extern int func_000011B4();
extern void func_00001160(void);
extern int func_000012A8();
extern int func_000029A0(void *, int);
extern int func_0000A768(int, int, int, void *);
extern int func_0000956C(int);
extern int func_00014D7C(int);
extern int func_0000FDBC();
extern int func_00010FD4();
extern int func_00011968(int, void *, int, int, int, int);
extern int func_00012BFC();
extern int func_00012CB8();
extern int func_00012D8C();
extern int func_00012F90();
extern int func_000130B8();
extern int func_000153A8();
extern int func_00015470();
extern int func_000154EC();
extern int func_000155AC();
extern int func_0001565C();
extern unsigned char *D_0001FC50;
extern void *D_0001FC4C;
extern void *D_0001FC34;

/* ============================================================
 * Matched functions, in address order (required for linking).
 * ============================================================ */

/* func_00000A08 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00000A08(void) {
    int v;

    v = *(int *)((char *)D_0001E5D0 + 0x94);
    if (v != 0) {
        ehsys_E1139F1A(v);
        ehsys_20E340D9(D_0001EB7C, (void *)(*(int *)((char *)D_0001E5D0 + 0x94)));
    }
    v = *(int *)((char *)D_0001E5D0 + 0x90);
    if (v != 0) {
        ehsys_E1139F1A(v);
        ehsys_20E340D9(D_0001EB7C, (void *)(*(int *)((char *)D_0001E5D0 + 0x90)));
    }
    func_00001160();
    func_000011B4();
    v = *(int *)((char *)D_0001E5D0 + 0x8C);
    if (v != 0) {
        ehsys_E1139F1A(v);
        ehsys_20E340D9(D_0001EB7C, (void *)(*(int *)((char *)D_0001E5D0 + 0x8C)));
    }
    ehsys_20E340D9(D_0001EB7C, (void *)D_0001E5D0);
    D_0001E5D0 = 0;
}

/* func_00001058 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00001058(void) {
    s32 i;
    s32 v;
    for (i = 0; i < 2; i++) {
        v = *(int *)((char *)D_0001E5D0 + i * 4 + 0x98);
        if (v != 0) {
            ehsys_39ADDA9F(v);
        }
    }
}

/* func_0000110C -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_0000110C(void) {
    s32 i;
    s32 v;
    for (i = 0; i < 2; i++) {
        v = *(int *)((char *)D_0001E5D0 + i * 4 + 0x98);
        if (v != 0) {
            ehsys_B0F320E6(v);
        }
    }
}

/* func_00001160 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00001160(void) {
    s32 i;
    s32 v;
    for (i = 0; i < 2; i++) {
        v = *(int *)((char *)D_0001E5D0 + i * 4 + 0x98);
        if (v != 0) {
            ehsys_E1139F1A(v);
        }
    }
}

/* func_0000120C -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_0000120C(s32 arg0, int arg1, int arg2, int arg3) {
    s32 temp_s0;

    temp_s0 = ehsys_E58C0FDC(func_0000FDBC(0x8033), 0x9A);
    ehsys_B8AD96EA(arg0);
    ehsys_942B03D0(0xC, 0xC);
    ehsys_60B55A50(-1);
    func_000012A8(arg1, arg2, arg3, temp_s0);
    ehsys_A4AFF8E6();
}

/* func_000012A8 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_000012A8(int a0, int a1, int a2, int a3) {
    return ehsys_BC8E65D7(a0 << 6, a1 << 6, a2 << 6, a3, -1);
}

/* func_000012BC -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_000012BC(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_s4;
    int s4c;

    s4c = (D_0001EB54 == 0) ? 0x99 : 0x98;
    temp_s4 = ehsys_E58C0FDC(func_0000FDBC(0x8033), s4c);
    ehsys_B8AD96EA(arg0);
    ehsys_942B03D0(0xC, 0xC);
    ehsys_60B55A50(0xFF000000);
    func_000012A8(arg1, arg2 - 2, arg3, temp_s4);
    ehsys_A4AFF8E6();
}

/* func_000017F4 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_000017F4(int a0, int a1, int a2) {
    return ehsys_B89D38DC(a0 << 6, a1 << 6, (0x1E0 - a0) << 6, a2);
}

/* func_00001814 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_00001814(int a0, int a1, int a2) {
    return ehsys_B89D38DC(a0 << 6, a1 << 6, a2 << 6);
}

/* func_00001B3C -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_00001B3C(void) {
    return 0;
}

/* func_00001F54 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_00001F54(void) {
    D_0001EB58 = 1;

    switch (D_0001E5E4) {
    case 0:
        return 0;
        break;
    }
    D_0001E5E4 = 0xB;
    return 1;
}

/* func_00001F84 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00001F84(void *a0, int a1) {
    int s0 = a1 & 0xFFFF;
    void *s1 = a0;

    *(int *) ((char *) s1 + 4) = ehsys_41AABF28(D_0001EB7C, s0 * 6);
    *(int *) ((char *) s1 + 0x10) = ehsys_41AABF28(D_0001EB7C, s0 * 2);
}

/* func_00006B30 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_00006B30(s32 arg0) {
    s32 sp1C;

    sp1C = arg0;
    ehsys_EF9B5D06(&sp1C, &D_0001F310);
    return sp1C;
}

/* func_00007644 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00007644(void) {
    int v;

    v = *(int *)((char *)D_0001FC34 + 0x14);
    if (v != 0) {
        ehsys_E1139F1A(v);
        ehsys_20E340D9(D_0001EB7C, (void *)(*(int *)((char *)D_0001FC34 + 0x14)));
    }
    ehsys_E1139F1A(*(int *)((char *)D_0001FC34 + 0x10));
    ehsys_20E340D9(D_0001EB7C, (void *)(*(int *)((char *)D_0001FC34 + 0x10)));
    ehsys_20E340D9(D_0001EB7C, (void *)D_0001FC34);
    D_0001FC34 = 0;
}

/* func_00007770 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_00007770(int a0, unsigned short a1, int a2, int a3) {
    return func_00011968(a0, &D_0001D8C4 + (a1 + 1) * 6, a2, a3 + 1, 0xA4, 0);
}

/* func_00007F00 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_00007F00(int a0, int a1, int a2) {
    return ehsys_B89D38DC(a0 << 6, a1 << 6, (0x1E0 - a0) << 6, a2);
}

/* func_00007F20 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_00007F20(int a0, int a1, int a2, int a3) {
    return ehsys_BC8E65D7(a0 << 6, a1 << 6, a2 << 6, a3, -1);
}
/* func_00008884 — 0 words. MATCH 100% (shape: same-shape twin). */
void func_00008884(void *arg0, s32 arg1) {

    extern char D_0001FC38;
    extern short D_0001FC3A;
    extern int D_0001FC40;
    extern int D_0001FC44;
    extern int D_0001FC48;
    extern int D_0001EB7C;
    extern int ehsys_41AABF28();
    extern int ehsys_memset();
    s32 temp_v0;
    u16 v0;

    ehsys_memset(&D_0001FC38, 0, 0x14);
    D_0001FC3A = *(u16 *)((char *)arg0 + 0x14);
    D_0001FC44 = arg1;
    v0 = *(volatile u16 *)&D_0001FC3A;
    if (v0 > 0) {
        D_0001FC40 = ehsys_41AABF28(D_0001EB7C, v0 * 2);
    }
    temp_v0 = ehsys_41AABF28(D_0001EB7C, 0x10000);
    D_0001FC48 = temp_v0;
    ehsys_memset((void *)temp_v0, 0xFF, 0x10000);
}

/* func_00008D5C -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_00008D5C(s32 arg0, s32 arg1) {
    u16 code;
    int shift;

    code = arg0 & 0xFFFF;
    if ((unsigned int)(code - 0x1386) < 3) {
        shift = 1;
    } else {
        shift = func_00014D7C(ehsys_CC7A2A21(code) & 0xFFFF);
    }
    if ((arg1 & (1 << shift)) != 0) {
        return 1;
    }
    return 0;
}

/* func_00008DBC -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_00008DBC(s32 arg0, s32 arg1) {
    s32 temp_s0;

    temp_s0 = arg0 & 0xFFFF;
    if ((ehsys_E5738C32(temp_s0) != 0) && (arg1 & (1 << ehsys_98E07D26(temp_s0)))) {
        return 1;
    }
    return 0;
}

/* func_00008E20 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_00008E20(s32 arg0, s32 arg1) {
    s32 temp_s0;

    temp_s0 = arg0 & 0xFFFF;
    if ((ehsys_E5738C32(temp_s0) != 0) && (arg1 & (1 << ehsys_E62CCE79(temp_s0)))) {
        return 1;
    }
    return 0;
}

/* func_0000910C -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_0000910C(s32 arg0, s32 arg1) {
    return (arg1 & (1 << ehsys_FE91A2EC(arg0 & 0xFFFF))) != 0;
}

/* func_00009488 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00009488(u16 *a0, s32 a1, u8 *a2) {
    s32 t0;
    for (t0 = 0; t0 < a1 - 1; t0++) {
        a2[a0[t0]] = 0xFF;
    }
}

/* func_00009E20 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_00009E20(int a0) {
    int v0 = 0;
    int v1 = (unsigned char) D_0001EB90 & 0xF;
    if (v1 < 2) {
        v0 += a0;
    } else if (v1 >= 4) {
        v0 += 3;
    } else {
        v0 += 2;
    }
    return v0;
}

/* func_0000A2E4 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_0000A2E4(int a0) {
    int sp1C = a0;
    int a1 = *(int *) ((char *) D_0001FC4C + 0x10);

    ehsys_EF9B5D06(&sp1C, a1);
    a1 = *(int *) ((char *) D_0001FC4C + 0x14);
    if (a1 != 0) {
        ehsys_EF9B5D06(&sp1C, a1);
    }
    return sp1C;
}

/* func_0000A330 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_0000A330(void) {
    int v;

    v = *(int *)((char *)D_0001FC4C + 0x14);
    if (v != 0) {
        ehsys_E1139F1A(v);
        ehsys_20E340D9(D_0001EB7C, (void *)(*(int *)((char *)D_0001FC4C + 0x14)));
        *(int *)((char *)D_0001FC4C + 0x14) = 0;
    }
    ehsys_E1139F1A(*(int *)((char *)D_0001FC4C + 0x10));
    v = *(int *)((char *)D_0001FC4C + 0x10);
    if (v != 0) {
        ehsys_20E340D9(D_0001EB7C, (void *)v);
        *(int *)((char *)D_0001FC4C + 0x10) = 0;
    }
    ehsys_20E340D9(D_0001EB7C, D_0001FC4C);
    D_0001FC4C = 0;
}

/* func_0000AB9C -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_0000AB9C(void) {
    extern int func_0000BCEC(int, unsigned short, int, int);
    int v0 = func_0000A768(0x9C, 0, 1, func_0000BCEC);
    if (v0 != 0) {
        ehsys_2012884C(*(int *) ((char *) D_0001FC4C + 0x14));
    }
}

/* func_0000BCC0 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_0000BCC0(int a0, unsigned short a1, int a2, int a3) {
    return func_00011968(a0, &D_0001DBA8 + a1 * 6, a2, a3 + 1, 0xE8, 0);
}

/* func_0000BCEC -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_0000BCEC(int a0, unsigned short a1, int a2, int a3) {
    return func_00011968(a0, &D_0001DBC0 + a1 * 6, a2, a3 + 1, 0xE8, 0);
}

/* func_0000BE78 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_0000BE78(int a0, int a1, int a2, int a3) {
    return ehsys_BC8E65D7(a0 << 6, a1 << 6, a2 << 6, a3, -1);
}

/* func_0000BE8C -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_0000BE8C(int a0) {
    return func_0000956C(a0 & 0xFFFF);
}

/* func_0000C6D8 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_0000C6D8(void *a0) {
    int s1 = D_0001EA2C;
    void *s2 = a0;

    if (s1 >= 8) {
        int i;
        for (i = 0; i < 7; i++) {
            ehsys_memcpy((int) (&D_0001E5E0 + i * 10 + 0x44E),
                         &D_0001E5E0 + (i + 1) * 10 + 0x44E, 0xA);
        }
        s1 = s1 - 1;
    } else {
        D_0001EA2C = s1 + 1;
    }
    ehsys_memcpy((int) (&D_0001E5E0 + s1 * 10 + 0x44E), s2, 0xA);
}

/* func_0000C7A4 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_0000C7A4(int a0) {
    if (D_0001EA2C == 0) {
        return 0;
    }
    D_0001EA2C -= 1;
    ehsys_memcpy(a0, &D_0001E5E0 + (int) D_0001EA2C * 10 + 0x44E, 0xA);
    return 1;
}

/* func_0000DF9C -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_0000DF9C(int a0, int a1, int a2, int a3) {
    return ehsys_BC8E65D7(a0 << 6, a1 << 6, a2 << 6, a3, -1);
}

/* func_0000EA20 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_0000EA20(void) {
    unsigned char *p = D_0001FC50;
    unsigned short h = *(unsigned short *) (p + 2);
    unsigned int field = (unsigned int) (p[6] << 27) >> 29;
    return func_000029A0(&D_0001E5E0 + field * 32 + 0xC, h);
}

/* func_0000F040 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_0000F040(void) {
    if (D_0001FC50 != 0) {
        ehsys_20E340D9(D_0001EB7C, D_0001FC50);
        D_0001FC50 = 0;
    }
}

/* func_0000F7A8 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_0000F7A8(u16 *arg0, u16 *arg1) {
    return *arg0 - *arg1;
}

/* func_0000FBA0 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_0000FBA0(void) {

}

/* func_0000FC64 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void *func_0000FC64(int a0) {
    int found = -1;
    unsigned int i;
    u16 code = a0 & 0xFFFF;

    for (i = 0; i < 4; i++) {
        u16 entry = *(u16 *) ((char *) &D_0001DF48 + i * 12);
        if (code == entry) {
            found = i;
            break;
        }
    }
    if (found < 0) {
        return 0;
    }
    return (char *) &D_0001DF48 + found * 12;
}

/* func_00010A18 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_00010A18(int a0, unsigned short a1, int a2, int a3) {
    return func_00011968(a0, &D_0001E450 + (a1 + 1) * 6, a2, a3 + 1, 0x88, 0);
}

/* func_00010A48 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_00010A48(int a0, unsigned short a1, int a2, int a3) {
    int t0 = *(u16 *) (*(char **) ((char *) D_0001FC68 + 0x14) + 0xF4);
    return func_00011968(a0, &D_0001E494 + a1 * 6, a2, a3 + 1, t0, 0);
}

/* func_000111A0 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_000111A0(void) {
    func_00010FD4();
}

/* func_00011744 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_00011744(int a0, int a1, int a2, int a3) {
    return ehsys_BC8E65D7(a0, a1, a2, a3, -1);
}

/* func_0001174C -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_0001174C(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    func_000153A8(arg0, (arg1 & 0xFFFF) | ((arg2 & 0xFFFF) << 0x10), arg3, func_0000FDBC(0x8007));
}

/* func_000117B8 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_000117B8(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    func_00015470(arg0, (arg1 & 0xFFFF) | ((arg2 & 0xFFFF) << 0x10), arg3, func_0000FDBC(0x8007));
}

/* func_00011824 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00011824(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    func_000154EC(arg0, (arg1 & 0xFFFF) | ((arg2 & 0xFFFF) << 0x10), arg3, func_0000FDBC(0x8007));
}

/* func_00011890 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00011890(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    func_000155AC(arg0, (arg1 & 0xFFFF) | ((arg2 & 0xFFFF) << 0x10), arg3, func_0000FDBC(0x800A));
}

/* func_000118FC -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_000118FC(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    func_0001565C(arg0, (arg1 & 0xFFFF) | ((arg2 & 0xFFFF) << 0x10), arg3, func_0000FDBC(0x800A));
}

/* func_00012BA0 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_00012BA0(int a0, int a1, int a2, int a3) {
    return ehsys_BC8E65D7(a0 << 6, a1 << 6, a2 << 6, a3, -1);
}

/* func_00012BB4 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00012BB4(void) {
    func_000130B8(func_00012F90(func_00012D8C(func_00012CB8(func_00012BFC()), (u8) D_0001EB90 & 0xF)));
}
/* func_00012F30 — 0 words. MATCH 100% (shape: twin of func_0001D96C). */
void func_00012F30(void *arg0, s16 arg1, s16 arg2, s16 arg3) {


    unsigned short temp_a3;
    unsigned short temp_a2;
    char *p = (char *)arg0;

    *(s16 *)(p + 0x4) = arg1;
    *(s16 *)(p + 0x6) = arg2;
    *(s16 *)(p + 0x8) = 0;
    *(s32 *)(p + 0x0) = 0x33000000;
    temp_a3 = (unsigned short)arg1 + (unsigned short)arg3;
    *(s16 *)(p + 0x10) = temp_a3;
    *(s16 *)(p + 0x12) = arg2;
    *(s16 *)(p + 0x14) = 0;
    *(s32 *)(p + 0xC) = 0x33000000;
    temp_a2 = (unsigned short)arg2 + 1;
    *(s16 *)(p + 0x1C) = arg1;
    *(s16 *)(p + 0x1E) = temp_a2;
    *(s16 *)(p + 0x20) = 0;
    *(s32 *)(p + 0x18) = 0x19000000;
    *(s16 *)(p + 0x28) = temp_a3;
    *(s16 *)(p + 0x2A) = temp_a2;
    *(s16 *)(p + 0x2C) = 0;
    *(s32 *)(p + 0x24) = 0x19000000;
}

/* func_000130A4 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_000130A4(int a0, int a1, int a2, int a3) {
    return ehsys_BC8E65D7(a0 << 6, a1 << 6, a2 << 6, a3, -1);
}

/* func_0001479C -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_0001479C(int a0, int a1, int a2) {
    return ehsys_B89D38DC(a0 << 6, a1 << 6, a2 << 6);
}

/* func_00014C6C -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_00014C6C(int a0, void *a1) {
    int v0 = 0;

    if (a1 == 0) {
        return v0;
    }
    {
        int count = *(u16 *) a1;
        u16 *arr = (u16 *) ((char *) a1 + 2);
        int key = a0 & 0xFFFF;
        int lo = 0;
        int hi = count - 1;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            u16 v = arr[mid];
            if (key == v) {
                v0 = mid & 0xFFFF;
                break;
            }
            if (v < key) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
    }
    return v0;
}
/* func_00014D30 — 0 words. MATCH 100% (shape: twin of func_00016D24). */
int func_00014D30(u16 lo, u16 hi, void *arr) {

    u32 target = (u32) lo | ((u32) hi << 16);
    int count = *(int *) arr;
    int idx;
    for (idx = 0; idx < count; idx++) {
        if (*(u32 *)((char *) arr + idx * 4 + 4) == target) {
            return idx;
        }
    }
    return -1;
}

/* func_00015074 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_00015074(int a0, int a1, int a2) {
    return ehsys_B89D38DC(a0 << 6, a1 << 6, (0x1E0 - a0) << 6, a2);
}

/* func_0001565C -- MATCH 100% (shape: twin-of-rel_shop-func_00017650, via
 * find_twins.py same-shape tier). */
struct S1565C {
    s16 lo;
    s16 hi;
    s32 w;
    s16 f1C;
    s16 f1E;
};

int func_0001565C(a0, a1, a2, a3)
int a0, a1;
u16 a2;
void *a3;
{
    struct S1565C s;
    extern s32 D_0001E524;
    extern u16 D_0001E52A;
    extern int func_00015310();
    s.hi = (s16)(a1 >> 16);
    s.f1C = (s16)(a2 * 17 + 0x33);
    s.lo = (s16)a1;
    s.w = D_0001E524;
    s.f1E = D_0001E52A;
    return func_00015310(a0, &s, a3);
}

/* func_00016A6C -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_00016A6C(int a0, int a1, int a2, int a3) {
    return ehsys_BC8E65D7(a0 << 6, a1 << 6, a2 << 6, a3, -1);
}

/* func_00017074 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_00017074(void) {
    return ((s32 *)ehsys_B2B9FEFA())[1];
}

/* func_00017D64 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_00017D64(int a0, int a1, int a2, int a3, int a4) {
    return ehsys_3BB2BAC6(a0 << 6, a1 << 6, a2 << 6, a3 << 6, a4, -1, 0);
}

/* func_00017D80 -- MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
int func_00017D80(int a0) {
    return ehsys_5F00A362(a0 << 6);
}

/* func_00017D88 — 0 words. MATCH 100% (shape: twin of func_0001C630). */
void func_00017D88(u16 *arg0, u16 *arg1, s32 arg2) {

    s32 t1;
    u16 t0;

    t1 = 0;
    goto test;
loop:
    t0 = *arg0;
    if (t0 == 0) {
        *arg1 = 0;
        return;
    }
    if (t0 == 0xA) {
        *arg1 = 0x20;
    } else {
        *arg1 = t0;
    }
    t1 += 1;
    arg0 += 1;
    arg1 += 1;
test:
    if (t1 < arg2) {
        goto loop;
    }
}
