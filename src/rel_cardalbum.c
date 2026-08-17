/*
 * rel_cardalbum.prx — reconstructed code (matching decompilation)
 *
 * Compiler:     Metrowerks CodeWarrior for PSP — MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,s -sdatathreshold 0
 * Verification: scripts/mwcc_build.sh src/rel_cardalbum.c
 *               scripts/mwcc_diff.py asm/rel_cardalbum/text.s build/mwcc/rel_cardalbum.o
 *
 * Every function below is byte-identical to the shipped module — each was
 * accepted only on a MATCH verdict from scripts/mwcc_diff.py, and the whole
 * file is re-verified after assembly (scripts/assemble_module.py).
 * Functions are in ADDRESS ORDER, which is what the linker needs.
 *
 * Import names are resolved from the module's NID tables and are identical
 * across all 28 modules — see docs/nids/README.md.
 *
 * STATUS: 13 functions matched here. The rest of the module is not
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
extern int ehsys_558B2DCB();
extern int ehsys_831C5769();
extern int ehsys_B8770B92();
extern int func_00005F04();
extern int func_0000608C();
extern s32 D_0000F074;
extern s32 D_0000C3F0[];
extern s32 ehsys_B89D38DC(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 ehsys_41AABF28(s32 arg0, s32 arg1);
extern s32 ehsys_20E340D9(s32 arg0, s32 arg1);

/* ---- forward declarations ---- */
s32 func_000008A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_00001708(void);
s32 func_00001C48(s32 arg0);
s32 func_00002E24(s32 arg0);
s32 func_00002E34(s32 arg0);
s32 func_000043E8(s32 arg0);
s32 func_000063E4(u16 *arg0, u16 *arg1);
void func_00006480(u16 arg0);
void func_00006800(void);
s32 func_00006A84(void);
void func_000052C4(void);
void func_00005C90(void);
void func_00005EFC(void);

/* func_000008A8 — 4 words. MATCH 100% (shape: m2c). */
s32 func_000008A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return ehsys_B89D38DC(arg0 << 6, arg1 << 6, arg2 << 6, arg3);
}

/* func_00001708 — 27 words. MATCH 100% (shape: m2c, extern-symbol lever). */
void func_00001708(void) {
    extern int ehsys_E1139F1A();
    extern s32 D_0000CA74;
    extern s32 D_0000CA84;

    if (D_0000CA74 != 0) {
        ehsys_20E340D9(D_0000F074, D_0000CA74);
        D_0000CA74 = 0;
    }
    if (D_0000CA84 != 0) {
        ehsys_E1139F1A(D_0000CA84);
        ehsys_20E340D9(D_0000F074, D_0000CA84);
        D_0000CA84 = 0;
    }
}

/* func_00001C48 — 11 words. MATCH 100% (shape: m2c, extern-symbol lever). */
s32 func_00001C48(s32 arg0) {
    extern int ehsys_EF9B5D06();
    extern s32 D_0000CA84;
    s32 sp1C;

    sp1C = arg0;
    ehsys_EF9B5D06(&sp1C, D_0000CA84);
    return sp1C;
}

/* func_00002E24 — 4 words. MATCH 100% (shape: m2c). */
s32 func_00002E24(s32 arg0) {
    return ehsys_41AABF28(D_0000F074, arg0);
}

/* func_00002E34 — 4 words. MATCH 100% (shape: m2c). */
s32 func_00002E34(s32 arg0) {
    return ehsys_20E340D9(D_0000F074, arg0);
}

/* func_000043E8 — 17 words. MATCH 100% (shape: m2c). */
s32 func_000043E8(s32 arg0) {
    u16 val = (u16) arg0;
    s32 i;
    s32 v0;

    for (i = 0; (v0 = D_0000C3F0[i]) >= 0; i++) {
        if (val == v0) {
            return 1;
        }
    }
    return 0;
}

/* func_000052C4 — 27 words. MATCH 100% (shape: m2c). */
void func_000052C4(void) {
    int sp1C;
    s32 sp18;
    s32 temp_a1;
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0 = func_0000608C(0x1010);
    if (temp_v0 != 0) {
        ehsys_B8770B92(temp_v0, &sp1C, &sp18);
        temp_v0_2 = ehsys_558B2DCB(temp_v0);
        if (sp18 > 0) {
            temp_a1 = sp18 - 1;
            if (temp_v0_2 >= temp_a1) {
                ehsys_831C5769(temp_v0, temp_a1, sp18);
            }
        }
    }
}

/* func_00005C90 — 32 words. MATCH 100% (shape: m2c, bitfield lever). */
void func_00005C90(void) {
    extern int ehsys_memset();
    extern int ehsys_qsort();
    extern u8 D_0000C694;
    extern u8 D_0000C96C;
    struct bf1 { unsigned bit0 : 1; };
    extern struct bf1 D_0000CAD0;

    ehsys_memset(&D_0000CAD0, 0, 0x26);
    D_0000CAD0.bit0 = 1;
    ehsys_qsort(&D_0000C694, 0x21, 0x10, func_000063E4);
    ehsys_qsort(&D_0000C96C, 5, 0x14, func_000063E4);
}

/* func_00005EFC — 2 words. MATCH 100% (shape: m2c). */
void func_00005EFC(void) {
    func_00005F04();
}

/* func_000063E4 — 4 words. MATCH 100% (shape: m2c). */
s32 func_000063E4(u16 *arg0, u16 *arg1) {
    return *arg0 - *arg1;
}

/* func_00006480 — 16 words. MATCH 100% (shape: m2c, u16 array lhu). */
void func_00006480(u16 arg0) {
    extern u16 D_0000CAD0[];
    s32 i;

    for (i = 0; i < 0x12; i++) {
        if (D_0000CAD0[i + 1] != 0) {
            continue;
        }
        D_0000CAD0[i + 1] = arg0;
        break;
    }
}

/* func_00006800 — 18 words. MATCH 100% (shape: m2c, extern-symbol + while lever). */
void func_00006800(void) {
    extern int ehsys_20E340D9();
    extern s32 D_0000CB18;
    extern s32 D_0000F074;
    s32 temp_s0;
    s32 var_a1;

    var_a1 = D_0000CB18;
    D_0000CB18 = 0;
    while (var_a1 != 0) {
        temp_s0 = (*(int *)((char *)var_a1 + 0xB0));
        ehsys_20E340D9(D_0000F074, (void *) var_a1);
        var_a1 = temp_s0;
    }
}

/* func_00006A84 — 2 words. MATCH 100% (shape: m2c). */
s32 func_00006A84(void) {
    return 0;
}

