/*
 * rel_decktutorial.prx — reconstructed code (matching decompilation)
 *
 * Compiler:     Metrowerks CodeWarrior for PSP — MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,s -sdatathreshold 0
 * Verification: scripts/mwcc_build.sh src/rel_decktutorial.c && 
 *               scripts/mwcc_diff.py asm/rel_decktutorial/text.s build/mwcc/rel_decktutorial.o
 *               Every function below is tagged "MATCH 100%" only if it has
 *               been confirmed this way as part of this file (matches can
 *               regress when combined with neighbors; re-verify after edits).
 *
 * Produced by scripts/auto_decomp.py's per-function search (m2c draft, then a
 * series of known MWCC-codegen source shapes, keeping only byte-identical
 * matches) — see src/rel_movie_viewer.c's header for the shape catalogue and
 * codegen levers (switch-vs-if, goto-rotated loops, min/max intrinsics,
 * address rematerialization, etc.) this search draws on.
 *
 * STATUS: 36 function(s) matched via the automated pass so far.
 *   func_00001CCC (13 words)
 *   func_00001F98 (6 words)
 *   func_000020D4 (17 words)
 *   func_00002488 (17 words)
 *   func_000026B0 (13 words)
 *   func_00002808 (16 words)
 *   func_000032C4 (2 words)
 *   func_000032CC (14 words)
 *   func_0000353C (4 words)
 *   func_000035C4 (2 words)
 *   func_00007C58 (2 words)
 *   func_00007C60 (14 words)
 *   func_00007EFC (4 words)
 *   func_00007F0C (5 words)
 *   func_00007F20 (5 words)
 *   func_00007F34 (8 words)
 *   func_00009DAC (25 words)
 *   func_00009E10 (25 words)
 *   func_0000A148 (19 words)
 *   func_000165A0 (11 words)
 *   func_000165CC (4 words)
 *   func_00017D20 (2 words)
 *   func_00019088 (39 words)
 *   func_00019974 (11 words)
 *   func_0001D7AC (22 words)
 *   func_0001FF08 (27 words)
 *   func_0001FF74 (27 words)
 *   func_0001FFE0 (27 words)
 *   func_0002004C (27 words)
 *   func_000200B8 (27 words)
 *   func_00020AB4 (15 words)
 *   func_000210F4 (3 words)
 *   func_00021100 (3 words)
 *   func_000211A8 (4 words)
 *   func_00021270 (13 words)
 *   func_000218A4 (9 words)
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

/* externs: imports and sibling functions referenced by matched bodies. */
extern int ehsys_025FE238();
extern int ehsys_06380DFA();
extern int ehsys_20E340D9();
extern int ehsys_56D1651D();
extern int ehsys_5998BFD7();
extern int ehsys_5DF04F49();
extern int ehsys_60B55A50();
extern int ehsys_6367AE39();
extern int ehsys_942B03D0();
extern int ehsys_98E07D26();
extern int ehsys_A4AFF8E6();
extern int ehsys_AB962AE7();
extern int ehsys_B8AD96EA();
extern int ehsys_E1139F1A();
extern int ehsys_E5738C32();
extern int ehsys_E58C0FDC();
extern int ehsys_E62CCE79();
extern int ehsys_EF9B5D06();
extern int func_000168C0();
extern int func_00017B1C();
extern int func_00019124();
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
extern int D_00028D44;
extern int D_00028E92;
extern int D_00028E9C;
extern int D_0002951C;
extern int D_00029540;
extern int D_00029CC2;
extern int D_00029CCE;
extern int D_00029CD8;
extern int D_00029D14;
extern int D_00029D18;
extern int D_00029D24;
extern int D_00029F6C;
extern int D_0002B7D8;
extern int D_0002C108;
extern int D_0002C10C;
extern int D_0002C114;
extern void *D_0002C160;
extern int D_0002C26C;

/* forward declarations for functions defined later in this file (address order). */
void func_00001CCC(void);
void func_00001F98(void);
void func_000020D4(void);
void func_00002488(void);
void func_000026B0(void);
void func_00002808(void);
void func_000032C4(void);
void func_000032CC(void);
s32 func_0000353C(u16 *arg0, u16 *arg1);
s32 func_000035C4(void);
void func_00007C58(void);
s32 func_00007C60(u16 *arg0);
s32 func_00007EFC(void);
u32 func_00007F0C(void);
u32 func_00007F20(void);
s32 func_00007F34(void);
s32 func_00009DAC(s32 arg0, s32 arg1);
s32 func_00009E10(s32 arg0, s32 arg1);
s32 func_0000A148(s32 arg0, s32 arg1);
s32 func_000165A0(s32 arg0);
s32 func_000165CC(u16 *arg0, u16 *arg1);
void func_00017D20(void);
void func_00019088(s32 arg0, int arg1, int arg2, int arg3);
void func_00019974(s32 arg0);
void func_0001D7AC(void);
void func_0001FF08(s32 arg0, s32 arg1, s32 arg2, int arg3);
void func_0001FF74(s32 arg0, s32 arg1, s32 arg2, int arg3);
void func_0001FFE0(s32 arg0, s32 arg1, s32 arg2, int arg3);
void func_0002004C(s32 arg0, s32 arg1, s32 arg2, int arg3);
void func_000200B8(s32 arg0, s32 arg1, s32 arg2, int arg3);
void func_00020AB4(void);
void func_000210F4(s32 arg0);
void **func_00021100(void);
void func_000211A8(void);
s32 func_00021270(void);
void func_000218A4(void);

/* func_00001CCC — 13 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00001CCC(void) {
    ehsys_E1139F1A(&D_00029D24);
    D_00029CCE &= 0xFFFE;
}

/* func_00001F98 — 6 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00001F98(void) {
    D_00029CCE &= 0xFFFD;
}

/* func_000020D4 — 17 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_000020D4(void) {
    ehsys_memset(&D_00029CD8, 0, 0x28);
    D_00029D14 = 0;
    D_00029CCE &= 0xFFFB;
}

/* func_00002488 — 17 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00002488(void) {
    ehsys_memset(&D_00029CD8, 0, 0x28);
    D_00029D18 = 0;
    D_00029CCE &= 0xFFEF;
}

/* func_000026B0 — 13 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_000026B0(void) {
    ehsys_E1139F1A(&D_00029F6C);
    D_00029CCE &= 0xFFBF;
}

/* func_00002808 — 16 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00002808(void) {
    D_00028E92 = 0;
    D_00029CC2 = 3;
    ehsys_5998BFD7(1, 0xFF000000, 0x10);
    ehsys_6367AE39(0x258);
}

/* func_000032C4 — 2 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_000032C4(void) {
    func_000032CC();
}

/* func_000032CC — 14 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_000032CC(void) {
    if (D_00028D44 != 0) {
        ehsys_20E340D9(D_0002951C, D_00028D44);
        D_00028D44 = 0;
    }
}

/* func_0000353C — 4 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_0000353C(u16 *arg0, u16 *arg1) {
    return *arg0 - *arg1;
}

/* func_000035C4 — 2 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_000035C4(void) {
    return 0;
}

/* func_00007C58 — 2 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00007C58(void) {

}

/* func_00007C60 — 14 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_00007C60(u16 *arg0) {
    u16 temp_v1;

    temp_v1 = *arg0;
    if ((temp_v1 != 4) && (temp_v1 != 2) && (temp_v1 != 0)) {
        return 0;
    }
    return 1;
}

/* func_00007EFC — 4 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_00007EFC(void) {
    return (u8) D_00028E9C & 3;
}

/* func_00007F0C — 5 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
u32 func_00007F0C(void) {
    return (u32) ((u8) D_00028E9C << 0x1C) >> 0x1E;
}

/* func_00007F20 — 5 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
u32 func_00007F20(void) {
    return (u32) (D_00028E9C << 0x14) >> 0x18;
}

/* func_00007F34 — 8 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_00007F34(void) {
    return func_00007F0C() != 0;
}

/* func_00009DAC — 25 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_00009DAC(s32 arg0, s32 arg1) {
    s32 temp_s0;

    temp_s0 = arg0 & 0xFFFF;
    if ((ehsys_E5738C32(temp_s0) != 0) && (arg1 & (1 << ehsys_98E07D26(temp_s0)))) {
        return 1;
    }
    return 0;
}

/* func_00009E10 — 25 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_00009E10(s32 arg0, s32 arg1) {
    s32 temp_s0;

    temp_s0 = arg0 & 0xFFFF;
    if ((ehsys_E5738C32(temp_s0) != 0) && (arg1 & (1 << ehsys_E62CCE79(temp_s0)))) {
        return 1;
    }
    return 0;
}

/* func_0000A148 — 19 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_0000A148(s32 arg0, s32 arg1) {
    return (arg1 & (1 << ehsys_56D1651D(func_00007F34(), arg0 & 0xFFFF))) != 0;
}

/* func_000165A0 — 11 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_000165A0(s32 arg0) {
    s32 sp1C;

    sp1C = arg0;
    ehsys_EF9B5D06(&sp1C, &D_0002B7D8);
    return sp1C;
}

/* func_000165CC — 4 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_000165CC(u16 *arg0, u16 *arg1) {
    return *arg0 - *arg1;
}

/* func_00017D20 — 2 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00017D20(void) {
    func_00017B1C();
}

/* func_00019088 — 39 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00019088(s32 arg0, int arg1, int arg2, int arg3) {
    s32 temp_s0;

    temp_s0 = ehsys_E58C0FDC(func_000168C0(0x8033), 0x9A);
    ehsys_B8AD96EA(arg0);
    ehsys_942B03D0(0xC, 0xC);
    ehsys_60B55A50(-1);
    func_00019124(arg1, arg2, arg3, temp_s0);
    ehsys_A4AFF8E6();
}

/* func_00019974 — 11 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00019974(s32 arg0) {
    if (D_0002C108 != 0) {
        ehsys_025FE238(D_0002C108 + 6, arg0);
    }
}

/* func_0001D7AC — 22 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_0001D7AC(void) {
    func_0001E8E4(func_0001E76C(func_0001DC98(func_0001D978(func_0001DA94(func_0001D8E4(func_0001D804()), (u8) D_00029540 & 0xF)))));
}

/* func_0001FF08 — 27 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_0001FF08(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    func_0001A0DC(arg0, (arg1 & 0xFFFF) | ((arg2 & 0xFFFF) << 0x10), arg3, func_000168C0(0x8007));
}

/* func_0001FF74 — 27 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_0001FF74(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    func_0001A1A4(arg0, (arg1 & 0xFFFF) | ((arg2 & 0xFFFF) << 0x10), arg3, func_000168C0(0x8007));
}

/* func_0001FFE0 — 27 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_0001FFE0(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    func_0001A220(arg0, (arg1 & 0xFFFF) | ((arg2 & 0xFFFF) << 0x10), arg3, func_000168C0(0x8007));
}

/* func_0002004C — 27 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_0002004C(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    func_0001A2E0(arg0, (arg1 & 0xFFFF) | ((arg2 & 0xFFFF) << 0x10), arg3, func_000168C0(0x800A));
}

/* func_000200B8 — 27 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_000200B8(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    func_0001A390(arg0, (arg1 & 0xFFFF) | ((arg2 & 0xFFFF) << 0x10), arg3, func_000168C0(0x800A));
}

/* func_00020AB4 — 15 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00020AB4(void) {
    D_0002C26C = 0;
    ehsys_5DF04F49(&D_0002C114);
    ehsys_memset(&D_0002C10C, 0, 0x184);
}

/* func_000210F4 — 3 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_000210F4(s32 arg0) {
    D_0002C26C = arg0;
}

/* func_00021100 — 3 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void **func_00021100(void) {
    return &D_0002C160;
}

/* func_000211A8 — 4 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_000211A8(void) {
    D_0002C10C = 1;
}

/* func_00021270 — 13 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_00021270(void) {
    if ((D_0002C10C != 3) && (D_0002C10C != 1)) {
        return 0;
    }
    return 1;
}

/* func_000218A4 — 9 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_000218A4(void) {
    ehsys_06380DFA();
    ehsys_AB962AE7(0);
}

