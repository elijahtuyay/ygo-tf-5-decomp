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
 * STATUS: 32 functions matched here. The rest of the module is not
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
extern char D_00028E9C;
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
extern int ehsys_06380DFA();
extern int ehsys_56D1651D();
extern int ehsys_5F00A362(int);
extern int ehsys_60B55A50();
extern int ehsys_942B03D0();
extern int ehsys_98E07D26();
extern int ehsys_A4AFF8E6();
extern int ehsys_AB962AE7();
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
extern int func_00019124();
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

/* ---- forward declarations ---- */
int func_0001CB68(int arg0);
int func_0001FF00(int a0, int a1, int a2, int a3);
s32 func_0000353C(u16 *arg0, u16 *arg1);
s32 func_000035C4(void);
s32 func_00007C60(u16 *arg0);
s32 func_00007EFC(void);
s32 func_00007F34(void);
s32 func_00009D4C(s32 arg0, s32 arg1);
s32 func_00009DAC(s32 arg0, s32 arg1);
s32 func_00009E10(s32 arg0, s32 arg1);
s32 func_0000A148(s32 arg0, s32 arg1);
s32 func_000165A0(s32 arg0);
s32 func_000165CC(u16 *arg0, u16 *arg1);
u32 func_00007F0C(void);
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
    return (u8) D_00028E9C & 3;
}

/* func_00007F0C — 5 words. MATCH 100% (shape: m2c). */
u32 func_00007F0C(void) {
    return (u32) ((u8) D_00028E9C << 0x1C) >> 0x1E;
}

/* func_00007F34 — 8 words. MATCH 100% (shape: m2c). */
s32 func_00007F34(void) {
    return func_00007F0C() != 0;
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

/* func_0001CB68 — 2 words. MATCH 100% (shape: thunk, arg0<<6). */
int func_0001CB68(int arg0) {
    return ehsys_5F00A362(arg0 << 6);
}

/* func_0001D7AC — 22 words. MATCH 100% (shape: m2c). */
void func_0001D7AC(void) {
    func_0001E8E4(func_0001E76C(func_0001DC98(func_0001D978(func_0001DA94(func_0001D8E4(func_0001D804()), (u8) D_00029540 & 0xF)))));
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

/* func_000218A4 — 9 words. MATCH 100% (shape: m2c). */
void func_000218A4(void) {
    ehsys_06380DFA();
    ehsys_AB962AE7(0);
}

