/*
 * rel_decktutorial.prx — reconstructed code (matching decompilation)
 *
 * Compiler:     Metrowerks CodeWarrior for PSP — MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,s -sdatathreshold 0
 * Verification: scripts/mwcc_build.sh src/rel_decktutorial.c
 *               scripts/mwcc_diff.py asm/rel_decktutorial/text.s build/mwcc/rel_decktutorial.o
 *
 * Every function below is byte-identical to the shipped module — each was
 * accepted only on a MATCH verdict from scripts/mwcc_diff.py, and the whole
 * file is re-verified after assembly (scripts/assemble_module.py).
 * Functions are in ADDRESS ORDER, which is what the linker needs.
 *
 * Import names are resolved from the module's NID tables and are identical
 * across all 28 modules — see docs/nids/README.md.
 *
 * STATUS: 48 functions matched here. The rest of the module is not
 * yet decompiled; build/auto/<module>.json has the status of every attempt.
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
extern char D_00029540;
extern char D_00029CC4;
extern char D_00029CCD;
extern u16 D_00029CCE;
extern char D_00029CD0;
extern char D_00029CD8;
extern char D_00029D14;
extern char D_00029D18;
extern char D_00029D24;
extern char D_00029F6C;
extern char D_0002B7D8;
extern char D_0002C160;
extern s32 D_0002C10C;
extern s32 D_0002C26C;
extern int ehsys_06380DFA();
extern int ehsys_56D1651D();
extern int ehsys_5F00A362(int);
extern int ehsys_60B55A50();
extern int ehsys_942B03D0();
extern int ehsys_98E07D26();
extern int ehsys_A4AFF8E6();
extern int ehsys_AB962AE7();
extern int ehsys_B89D38DC();
extern int ehsys_B8AD96EA();
extern int ehsys_BC8E65D7(int, int, int, int, int);
extern int ehsys_CC7A2A21();
extern int ehsys_E1139F1A();
extern int ehsys_E5738C32();
extern int ehsys_E58C0FDC();
extern int ehsys_E62CCE79();
extern int ehsys_EF9B5D06();
extern int ehsys_memcpy();
extern int ehsys_memset();
extern int func_000032CC();
extern int func_000033B4();
extern int func_000168C0();
extern int func_00017B1C();
extern int func_00019974();
extern int func_00019AB0();
extern int func_0001A0DC();
extern int func_0001A1A4();
extern int func_0001A220();
extern int func_0001A2E0();
extern int func_0001A390();
extern int func_0001D804();
extern int func_0001D8E4();
extern int func_0001D978();
extern int func_0001DA94();
extern int func_0001DC98();
extern int func_0001E76C();
extern int func_0001E8E4();
extern int ehsys_3BB2BAC6();

/* ---- forward declarations ---- */
s32 func_0001CB4C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
s32 func_000210D8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
int func_0001CB68(int arg0);
int func_0001FF00(int a0, int a1, int a2, int a3);
s32 func_0000353C(u16 *arg0, u16 *arg1);
s32 func_000035C4(void);
s32 func_00006D14(s32 arg0, s32 arg1, s32 arg2, int arg3);
s32 func_00007C60(u16 *arg0);
s32 func_00007EFC(void);
s32 func_00007F34(void);
s32 func_00009674(s32 arg0, s32 arg1, s32 arg2, int arg3);
s32 func_00009D4C(s32 arg0, s32 arg1);
s32 func_00009DAC(s32 arg0, s32 arg1);
s32 func_00009E10(s32 arg0, s32 arg1);
s32 func_0000A148(s32 arg0, s32 arg1);
s32 func_0000B9F8(s32 arg0, s32 arg1, s32 arg2, int arg3);
s32 func_000165A0(s32 arg0);
s32 func_000165CC(u16 *arg0, u16 *arg1);
s32 func_00019124(s32 arg0, s32 arg1, s32 arg2, int arg3);
s32 func_00019694(s32 arg0, s32 arg1, s32 arg2);
s32 func_0001B854(s32 arg0, s32 arg1, s32 arg2, int arg3);
s32 func_0001D798(s32 arg0, s32 arg1, s32 arg2, int arg3);
s32 func_0001DA80(s32 arg0, s32 arg1, s32 arg2, int arg3);
s32 func_0001F5A4(s32 arg0, s32 arg1, s32 arg2);
s32 func_0001FAF8(s32 arg0, s32 arg1, s32 arg2, int arg3);
s32 func_00021100(void);
u32 func_00007F0C(void);
u32 func_00007F20(void);
void func_00001CCC(void);
void func_00001F98(void);
void func_000020D4(void);
void func_0000242C(void);
void func_00002488(void);
void func_00002500(void);
void func_000026B0(void);
void func_000032C4(void);
void func_00007C58(void);
void func_00017D20(void);
void func_00019088(s32 arg0, int arg1, int arg2, int arg3);
void func_000210F4(s32 arg0);
void func_000211A8(void);
void func_0001D7AC(void);
void func_0001FF08(s32 arg0, s32 arg1, s32 arg2, int arg3);
void func_0001FF74(s32 arg0, s32 arg1, s32 arg2, int arg3);
void func_0001FFE0(s32 arg0, s32 arg1, s32 arg2, int arg3);
void func_0002004C(s32 arg0, s32 arg1, s32 arg2, int arg3);
void func_000200B8(s32 arg0, s32 arg1, s32 arg2, int arg3);
void func_000218A4(void);

/* func_00001CCC — 13 words. MATCH 100% (shape: m2c). */
void func_00001CCC(void) {
    ehsys_E1139F1A(&D_00029D24);
    D_00029CCE &= 0xFFFE;
}

/* func_00001F98 — 6 words. MATCH 100% (shape: m2c). */
void func_00001F98(void) {
    D_00029CCE &= 0xFFFD;
}

/* func_000020D4 — 17 words. MATCH 100% (shape: m2c). */
void func_000020D4(void) {
    ehsys_memset(&D_00029CD8, 0, 0x28);
    *(int *)&D_00029D14 = 0;
    D_00029CCE &= 0xFFFB;
}

/* func_000022C4 — 9 words. MATCH 100% (verified). */
extern int func_00007324();
void func_000022C4(void) {
    struct bf1 { unsigned bit0 : 1; };
    extern struct bf1 D_0002954C;
    u8 old = *(u8 *)&D_0002954C;
    D_0002954C.bit0 = 0;
    func_00007324(old);
}

/* func_0000242C — 23 words. MATCH 100% (shape: manual thunk). */
void func_0000242C(void) {
    s32 sp1C;

    ehsys_memcpy(&sp1C, *(int *)&D_00029CD0, 4);
    *(int *)&D_00029D18 = sp1C;
    *(int *)&D_00029CC4 = 0;
    *(int *)&D_00029CD0 += 4;
    D_00029CCD = 0x10;
}

/* func_00002488 — 17 words. MATCH 100% (shape: m2c). */
void func_00002488(void) {
    ehsys_memset(&D_00029CD8, 0, 0x28);
    *(int *)&D_00029D18 = 0;
    D_00029CCE &= 0xFFEF;
}

/* func_00002500 — 22 words. MATCH 100% (shape: manual thunk). */
void func_00002500(void) {
    s32 sp1C;

    ehsys_memcpy(&sp1C, *(int *)&D_00029CD0, 2);
    func_00019974(ehsys_E58C0FDC(func_000033B4(0x1040), *(u16 *)&sp1C));
    *(int *)&D_00029CD0 += 2;
}

/* func_000026B0 — 13 words. MATCH 100% (shape: m2c). */
void func_000026B0(void) {
    ehsys_E1139F1A(&D_00029F6C);
    D_00029CCE &= 0xFFBF;
}

/* func_00002848 — 27 words. MATCH 100% (verified). */
extern int func_00002EB8();
void func_00002848(void *arg0) {
    extern int D_00029D1C;
    extern unsigned short D_00029D20;
    extern short D_00029D7C;
    extern short D_00029D7E;
    if ((D_00029CCE & 1) && (D_00029D20 != 0)) {
        func_00002EB8(D_00029D7C, D_00029D7E, D_00029D20);
    }
    *(int *)((char *)arg0 + 0xE0) = ~D_00029D1C;
    D_00029CCD = 0;
}

/* func_00003198 — 27 words. MATCH 100% (verified). */
extern int ehsys_memset();
extern int ehsys_qsort();
extern int func_00016644();
void func_00003198(void) {
    struct bf1 { unsigned bit0 : 1; };
    extern struct bf1 D_00028D40;
    extern char D_00027EB0;
    func_00016644();
    ehsys_memset(&D_00028D40, 0, 2);
    D_00028D40.bit0 = 1;
    ehsys_qsort(&D_00027EB0, 9, 0xC, func_0000353C);
}

/* func_000032C4 — 2 words. MATCH 100% (shape: m2c). */
void func_000032C4(void) {
    func_000032CC();
}

/* func_0000353C — 4 words. MATCH 100% (shape: m2c). */
s32 func_0000353C(u16 *arg0, u16 *arg1) {
    return *arg0 - *arg1;
}

/* func_000035C4 — 2 words. MATCH 100% (shape: m2c). */
s32 func_000035C4(void) {
    return 0;
}
/* func_00004C14 — 0 words. MATCH 100% (shape: harvested). */
void func_00004C14(void) {
    extern int D_0002951C;
    extern int D_0002B7B4;
    extern int ehsys_20E340D9();
    extern int ehsys_E1139F1A();
    extern int func_00004C14();
    s32 temp_a0;
    s32 temp_a1;

    temp_a0 = (*(int *)((char *)D_0002B7B4 + 0x14));
    if (temp_a0 != 0) {
        ehsys_E1139F1A(temp_a0);
        ehsys_20E340D9(D_0002951C, (*(int *)((char *)D_0002B7B4 + 0x14)));
        (*(int *)((char *)D_0002B7B4 + 0x14)) = 0;
    }
    ehsys_E1139F1A((*(int *)((char *)D_0002B7B4 + 0x10)));
    temp_a1 = (*(int *)((char *)D_0002B7B4 + 0x10));
    if (temp_a1 != 0) {
        ehsys_20E340D9(D_0002951C, temp_a1);
        (*(int *)((char *)D_0002B7B4 + 0x10)) = 0;
    }
    ehsys_20E340D9(D_0002951C, D_0002B7B4);
    D_0002B7B4 = 0;
}

/* func_00006D14 — 5 words. MATCH 100% (shape: thunk, tail call w/ shifted args). */
s32 func_00006D14(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    return ehsys_BC8E65D7(arg0 << 6, arg1 << 6, arg2 << 6, arg3, -1);
}

/* func_000071B4 — 31 words. MATCH 100% (verified). */
extern int ehsys_1CC5878C();
extern int func_000168C0();
void func_000071B4(void) {
    extern int D_00029520;
    s32 sp[9];

    ehsys_memset(&sp[0], 0, 0x24);
    sp[0] = func_000168C0(0x8007);
    sp[1] = func_000168C0(0x8009);
    sp[2] = func_000168C0(0x8024);
    sp[3] = func_000168C0(0x8011);
    sp[4] = func_000168C0(0x8010);
    sp[7] = D_00029520;
    ehsys_1CC5878C(&sp[0]);
    func_00007324();
}

/* func_00007BF8 — 24 words. MATCH 100% (verified). */
s32 func_00007BF8(void *arg0) {
    extern unsigned short D_00029370;
    extern char D_00028D50;
    char *addr;

    if (D_00029370 == 0) {
        return 0;
    }
    D_00029370 = D_00029370 - 1;
    addr = (char *)&D_00028D50 + (D_00029370 * 0xA) + 0x622;
    ehsys_memcpy(arg0, addr, 0xA);
    return 1;
}

/* func_00007C58 — 2 words. MATCH 100% (shape: m2c). */
void func_00007C58(void) {

}

/* func_00007C60 — 14 words. MATCH 100% (shape: m2c). */
s32 func_00007C60(u16 *arg0) {
    u16 temp_v1;

    temp_v1 = *arg0;
    if ((temp_v1 != 4) && (temp_v1 != 2) && (temp_v1 != 0)) {
        return 0;
    }
    return 1;
}

/* func_00007EFC — 4 words. MATCH 100% (shape: m2c). */
s32 func_00007EFC(void) {
    extern char D_00028E9C;
    return (u8) D_00028E9C & 3;
}

/* func_00007F0C — 5 words. MATCH 100% (shape: m2c). */
u32 func_00007F0C(void) {
    extern char D_00028E9C;
    return (u32) ((u8) D_00028E9C << 0x1C) >> 0x1E;
}

/* func_00007F20 — 5 words. MATCH 100% (shape: m2c; local extern re-declares
 * D_00028E9C at u16 width so this site loads lhu instead of lb). */
u32 func_00007F20(void) {
    extern u16 D_00028E9C;
    return (u32) (D_00028E9C << 20) >> 24;
}

/* func_00007F34 — 8 words. MATCH 100% (shape: m2c). */
s32 func_00007F34(void) {
    return func_00007F0C() != 0;
}

/* func_00009674 — 5 words. MATCH 100% (shape: thunk, tail call w/ shifted args). */
s32 func_00009674(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    return ehsys_BC8E65D7(arg0 << 6, arg1 << 6, arg2 << 6, arg3, -1);
}

/* func_00009D4C — 24 words. MATCH 100% (shape: m2c). */
s32 func_00009D4C(s32 arg0, s32 arg1) {
    s32 temp_a0;
    s32 var_v0;

    temp_a0 = arg0 & 0xFFFF;
    if ((u32) (temp_a0 - 0x1386) < 3U) {
        var_v0 = 1;
    } else {
        var_v0 = func_00019AB0(ehsys_CC7A2A21(temp_a0) & 0xFFFF);
    }
    if (arg1 & (1 << var_v0)) {
        return 1;
    }
    return 0;
}

/* func_00009DAC — 25 words. MATCH 100% (shape: m2c). */
s32 func_00009DAC(s32 arg0, s32 arg1) {
    s32 temp_s0;

    temp_s0 = arg0 & 0xFFFF;
    if ((ehsys_E5738C32(temp_s0) != 0) && (arg1 & (1 << ehsys_98E07D26(temp_s0)))) {
        return 1;
    }
    return 0;
}

/* func_00009E10 — 25 words. MATCH 100% (shape: m2c). */
s32 func_00009E10(s32 arg0, s32 arg1) {
    s32 temp_s0;

    temp_s0 = arg0 & 0xFFFF;
    if ((ehsys_E5738C32(temp_s0) != 0) && (arg1 & (1 << ehsys_E62CCE79(temp_s0)))) {
        return 1;
    }
    return 0;
}

/* func_0000A148 — 19 words. MATCH 100% (shape: m2c). */
s32 func_0000A148(s32 arg0, s32 arg1) {
    return (arg1 & (1 << ehsys_56D1651D(func_00007F34(), arg0 & 0xFFFF))) != 0;
}
/* func_0000A4AC — 0 words. MATCH 100% (shape: twin of func_00007EEC). */
void func_0000A4AC(u16 *a0, s32 a1, u8 *a2) {

    s32 t0;
    for (t0 = 0; t0 < a1 - 1; t0++) {
        a2[a0[t0]] = 0xFF;
    }
}
/* func_0000B0F0 — 35 words. MATCH 100% (shape: m2c). */
void func_0000B0F0(void) {
    extern int D_0002951C;
    extern int D_0002B7CC;
    extern int ehsys_20E340D9();
    extern int ehsys_E1139F1A();
    extern int func_0000B0F0();
    s32 temp_a0;

    temp_a0 = (*(int *)((char *)D_0002B7CC + 0x14));
    if (temp_a0 != 0) {
        ehsys_E1139F1A(temp_a0);
        ehsys_20E340D9(D_0002951C, (*(int *)((char *)D_0002B7CC + 0x14)));
    }
    ehsys_E1139F1A((*(int *)((char *)D_0002B7CC + 0x10)));
    ehsys_20E340D9(D_0002951C, (*(int *)((char *)D_0002B7CC + 0x10)));
    ehsys_20E340D9(D_0002951C, D_0002B7CC);
    D_0002B7CC = 0;
}

/* func_0000B9F8 — 5 words. MATCH 100% (shape: thunk, tail call w/ shifted args). */
s32 func_0000B9F8(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    return ehsys_BC8E65D7(arg0 << 6, arg1 << 6, arg2 << 6, arg3, -1);
}
/* func_000137A0 — 31 words. MATCH 100% (shape: m2c). */
void func_000137A0(void) {
    extern int D_000294D0;
    extern int D_0002951C;
    extern int D_0002B7D0;
    extern int ehsys_20E340D9();
    extern int ehsys_834A6E13();
    extern int func_000137A0();
    s32 temp_a1;

    ehsys_834A6E13(&D_000294D0, (*(int *)((char *)D_0002B7D0 + 0x24C)));
    temp_a1 = (*(int *)((char *)D_0002B7D0 + 0x24C));
    if (temp_a1 != 0) {
        ehsys_20E340D9(D_0002951C, temp_a1);
        (*(int *)((char *)D_0002B7D0 + 0x24C)) = 0;
    }
    if (D_0002B7D0 != 0) {
        ehsys_20E340D9(D_0002951C, D_0002B7D0);
    }
    D_0002B7D0 = 0;
}

/* func_00013C28 — 11 words. MATCH 100% (verified). */
extern int func_00014FDC();
void func_00013C28(void) {
    extern int D_0002B7D0;
    extern char D_00028D50;
    u8 byte = *(u8 *)(D_0002B7D0 + 0x6);
    unsigned short half = *(unsigned short *)(D_0002B7D0 + 0x2);
    u32 idx = ((u32)(byte << 27)) >> 29;
    func_00014FDC((char *)&D_00028D50 + (idx << 5), half);
}

/* func_000165A0 — 11 words. MATCH 100% (shape: m2c). */
s32 func_000165A0(s32 arg0) {
    s32 sp1C;

    sp1C = arg0;
    ehsys_EF9B5D06(&sp1C, &D_0002B7D8);
    return sp1C;
}

/* func_000165CC — 4 words. MATCH 100% (shape: m2c). */
s32 func_000165CC(u16 *arg0, u16 *arg1) {
    return *arg0 - *arg1;
}

/* func_00017D20 — 2 words. MATCH 100% (shape: m2c). */
void func_00017D20(void) {
    func_00017B1C();
}
/* func_00018880 — 0 words. MATCH 100% (shape: harvested). */
void func_00018880(void) {
    extern int D_0002951C;
    extern int D_0002C108;
    extern int ehsys_20E340D9();
    extern int ehsys_E1139F1A();
    extern int func_00018880();
    extern int func_00018FDC();
    extern int func_00019030();
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a0_3;

    temp_a0 = (*(int *)((char *)D_0002C108 + 0x94));
    if (temp_a0 != 0) {
        ehsys_E1139F1A(temp_a0);
        ehsys_20E340D9(D_0002951C, (*(int *)((char *)D_0002C108 + 0x94)));
    }
    temp_a0_2 = (*(int *)((char *)D_0002C108 + 0x90));
    if (temp_a0_2 != 0) {
        ehsys_E1139F1A(temp_a0_2);
        ehsys_20E340D9(D_0002951C, (*(int *)((char *)D_0002C108 + 0x90)));
    }
    func_00018FDC();
    func_00019030();
    temp_a0_3 = (*(int *)((char *)D_0002C108 + 0x8C));
    if (temp_a0_3 != 0) {
        ehsys_E1139F1A(temp_a0_3);
        ehsys_20E340D9(D_0002951C, (*(int *)((char *)D_0002C108 + 0x8C)));
    }
    ehsys_20E340D9(D_0002951C, D_0002C108);
    D_0002C108 = 0;
}

/* func_00019088 — 39 words. MATCH 100% (shape: m2c). */
void func_00019088(s32 arg0, int arg1, int arg2, int arg3) {
    s32 temp_s0;

    temp_s0 = ehsys_E58C0FDC(func_000168C0(0x8033), 0x9A);
    ehsys_B8AD96EA(arg0);
    ehsys_942B03D0(0xC, 0xC);
    ehsys_60B55A50(-1);
    func_00019124(arg1, arg2, arg3, temp_s0);
    ehsys_A4AFF8E6();
}

/* func_00019124 — 5 words. MATCH 100% (shape: thunk, tail call w/ shifted args). */
s32 func_00019124(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    return ehsys_BC8E65D7(arg0 << 6, arg1 << 6, arg2 << 6, arg3, -1);
}

/* func_00019694 — 4 words. MATCH 100% (shape: thunk, tail call w/ shifted args). */
s32 func_00019694(s32 arg0, s32 arg1, s32 arg2) {
    return ehsys_B89D38DC(arg0 << 6, arg1 << 6, arg2 << 6);
}

/* func_0001B854 — 5 words. MATCH 100% (shape: thunk, tail call w/ shifted args). */
s32 func_0001B854(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    return ehsys_BC8E65D7(arg0 << 6, arg1 << 6, arg2 << 6, arg3, -1);
}

/* func_0001CB4C — bulk-matched thunk into ehsys_3BB2BAC6. */
s32 func_0001CB4C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return ehsys_3BB2BAC6(arg0 << 6, arg1 << 6, arg2 << 6, arg3 << 6, arg4, -1, 0);
}

/* func_0001CB68 — 2 words. MATCH 100% (shape: thunk, arg0<<6). */
int func_0001CB68(int arg0) {
    return ehsys_5F00A362(arg0 << 6);
}
/* func_0001CFDC — 0 words. MATCH 100% (shape: twin of func_0001C630). */
void func_0001CFDC(u16 *arg0, u16 *arg1, s32 arg2) {

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

/* func_0001D798 — 5 words. MATCH 100% (shape: thunk, tail call w/ shifted args). */
s32 func_0001D798(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    return ehsys_BC8E65D7(arg0 << 6, arg1 << 6, arg2 << 6, arg3, -1);
}

/* func_0001D7AC — 22 words. MATCH 100% (shape: m2c). */
void func_0001D7AC(void) {
    func_0001E8E4(func_0001E76C(func_0001DC98(func_0001D978(func_0001DA94(func_0001D8E4(func_0001D804()), (u8) D_00029540 & 0xF)))));
}

/* func_0001DA80 — 5 words. MATCH 100% (shape: thunk, tail call w/ shifted args). */
s32 func_0001DA80(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    return ehsys_BC8E65D7(arg0 << 6, arg1 << 6, arg2 << 6, arg3, -1);
}

/* func_0001F5A4 — 4 words. MATCH 100% (shape: thunk, tail call w/ shifted args). */
s32 func_0001F5A4(s32 arg0, s32 arg1, s32 arg2) {
    return ehsys_B89D38DC(arg0 << 6, arg1 << 6, arg2 << 6);
}

/* func_0001FAF8 — 5 words. MATCH 100% (shape: thunk, tail call w/ shifted args). */
s32 func_0001FAF8(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    return ehsys_BC8E65D7(arg0 << 6, arg1 << 6, arg2 << 6, arg3, -1);
}

/* func_0001FF00 — 2 words. MATCH 100% (shape: thunk, passthrough + t0=-1). */
int func_0001FF00(int a0, int a1, int a2, int a3) {
    return ehsys_BC8E65D7(a0, a1, a2, a3, -1);
}

/* func_0001FF08 — 27 words. MATCH 100% (shape: m2c). */
void func_0001FF08(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    func_0001A0DC(arg0, (arg1 & 0xFFFF) | ((arg2 & 0xFFFF) << 0x10), arg3, func_000168C0(0x8007));
}

/* func_0001FF74 — 27 words. MATCH 100% (shape: m2c). */
void func_0001FF74(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    func_0001A1A4(arg0, (arg1 & 0xFFFF) | ((arg2 & 0xFFFF) << 0x10), arg3, func_000168C0(0x8007));
}

/* func_0001FFE0 — 27 words. MATCH 100% (shape: m2c). */
void func_0001FFE0(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    func_0001A220(arg0, (arg1 & 0xFFFF) | ((arg2 & 0xFFFF) << 0x10), arg3, func_000168C0(0x8007));
}

/* func_0002004C — 27 words. MATCH 100% (shape: m2c). */
void func_0002004C(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    func_0001A2E0(arg0, (arg1 & 0xFFFF) | ((arg2 & 0xFFFF) << 0x10), arg3, func_000168C0(0x800A));
}

/* func_000200B8 — 27 words. MATCH 100% (shape: m2c). */
void func_000200B8(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    func_0001A390(arg0, (arg1 & 0xFFFF) | ((arg2 & 0xFFFF) << 0x10), arg3, func_000168C0(0x800A));
}

/* func_000210D8 — bulk-matched thunk into ehsys_3BB2BAC6. */
s32 func_000210D8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return ehsys_3BB2BAC6(arg0 << 6, arg1 << 6, arg2 << 6, arg3 << 6, arg4, -1, 0);
}

/* func_000210F4 — 3 words. MATCH 100% (shape: m2c). */
void func_000210F4(s32 arg0) {
    D_0002C26C = arg0;
}

/* func_00021100 — 3 words. MATCH 100% (shape: m2c). */
s32 func_00021100(void) {
    return (s32) &D_0002C160;
}

/* func_000211A8 — 4 words. MATCH 100% (shape: m2c). */
void func_000211A8(void) {
    D_0002C10C = 1;
}

/* func_000218A4 — 9 words. MATCH 100% (shape: m2c). */
void func_000218A4(void) {
    ehsys_06380DFA();
    ehsys_AB962AE7(0);
}

