/*
 * rel_shop.prx — reconstructed code (matching decompilation)
 *
 * Compiler:     Metrowerks CodeWarrior for PSP — MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,s -sdatathreshold 0
 * Verification: scripts/mwcc_build.sh src/rel_shop.c
 *               scripts/mwcc_diff.py asm/rel_shop/text.s build/mwcc/rel_shop.o
 *
 * Every function below is byte-identical to the shipped module — each was
 * accepted only on a MATCH verdict from scripts/mwcc_diff.py, and the whole
 * file is re-verified after assembly (scripts/assemble_module.py).
 * Functions are in ADDRESS ORDER, which is what the linker needs.
 *
 * Import names are resolved from the module's NID tables and are identical
 * across all 28 modules — see docs/nids/README.md.
 *
 * STATUS: 24 functions matched here. The rest of the module is not
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
extern char D_0002305D;
extern char D_000240A4;
extern char D_0002E017;
extern char D_0002F1C8;
extern char D_76F1F0;
extern char D_76F260;
extern char D_8E73B8;
extern char D_8E73C0;
extern int ehsys_03E45FFF();
extern int ehsys_06380DFA();
extern int ehsys_291D6262();
extern int ehsys_4F22C9AA();
extern int ehsys_5DF04F49();
extern int ehsys_9EA6989A();
extern int ehsys_AB962AE7();
extern int ehsys_B4471B5E();
extern int ehsys_EBD1986B();
extern int ehsys_EF9B5D06();
extern int ehsys_memset();
extern int func_00000000();
extern int func_00000DF8();
extern int func_0000A2A8();
extern int func_0000A36C();
extern int func_0000A6BC();
extern int func_0000B1D0();
extern int func_0000F998();
extern int func_0000FB88();
extern int func_0001161C();
extern int func_00012FB4();
extern int func_000130AC();
extern int func_00015228();
extern int func_00015650();

/* ---- forward declarations ---- */
f32 func_0000694C(s32 arg0, s32 arg1);
s32 func_000063D4(s32 arg0);
s32 func_0000A1A8(s32 arg0);
s32 func_000163F4(void);
s32 func_00016580(void);
u8 func_0000B444(s32 arg0);
void func_00006754(s32 arg0, s32 arg1);
void func_0000A030(void);
void func_0000A054(void);
void func_0000A3FC(void);
void func_0000A404(void);
void func_0000F8F4(void);
void func_0000F928(void);
void func_00012F68(void);
void func_00014D20(void);
void func_00014D44(void);
void func_000150D0(s32 arg0);
void func_00015648(void);
void func_00015914(void);
void func_00015DB4(void);
void func_00016414(s32 arg0);
void func_000164A8(void);
void func_000164B8(void);
void func_00016B74(void);

/* func_000063D4 — 11 words. MATCH 100% (shape: m2c). */
s32 func_000063D4(s32 arg0) {
    s32 sp1C;

    sp1C = arg0;
    ehsys_EF9B5D06(&sp1C, &D_000240A4);
    return sp1C;
}

/* func_00006754 — 13 words. MATCH 100% (shape: m2c). */
void func_00006754(s32 arg0, s32 arg1) {
    ehsys_9EA6989A(arg0, func_0000FB88(arg1 & 0xFFFF));
}

/* func_0000694C — 13 words. MATCH 100% (shape: m2c). */
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

/* func_0000A030 — 9 words. MATCH 100% (shape: m2c). */
void func_0000A030(void) {
    func_00000000();
    func_00000DF8();
}

/* func_0000A054 — 2 words. MATCH 100% (shape: m2c). */
void func_0000A054(void) {
    func_0001161C();
}

/* func_0000A1A8 — 14 words. MATCH 100% (shape: m2c). */
s32 func_0000A1A8(s32 arg0) {
    if (arg0 == 0) {
        ehsys_B4471B5E(func_0000A2A8, func_0000A36C, &D_76F1F0);
    }
    return 0;
}

/* func_0000A3FC — 2 words. MATCH 100% (shape: m2c). */
void func_0000A3FC(void) {
    func_0001161C();
}

/* func_0000A404 — 12 words. MATCH 100% (shape: m2c). */
void func_0000A404(void) {
    func_0000F928();
    ehsys_03E45FFF();
    ehsys_EBD1986B(0, 0);
}

/* func_0000B444 — 9 words. MATCH 100% (shape: m2c). */
u8 func_0000B444(s32 arg0) {
    return *(&D_0002305D + ((arg0 & 0xFFFF) * 0xC));
}

/* func_0000F8F4 — 13 words. MATCH 100% (shape: m2c). */
void func_0000F8F4(void) {
    D_0002F1C8 = ehsys_291D6262(&D_76F260, 0x178000, 0);
}

/* func_0000F928 — 2 words. MATCH 100% (shape: m2c). */
void func_0000F928(void) {
    func_0000F998();
}

/* func_00012F68 — 19 words. MATCH 100% (shape: m2c). */
void func_00012F68(void) {
    func_0000A6BC();
    ehsys_4F22C9AA(2);
    if (func_0000B1D0((u8) D_0002E017) & 0xFFFF) {
        func_00012FB4();
    }
    func_000130AC();
}

/* func_00014D20 — 9 words. MATCH 100% (shape: m2c). */
void func_00014D20(void) {
    func_00015648();
    func_00015914();
}

/* func_00014D44 — 9 words. MATCH 100% (shape: m2c). */
void func_00014D44(void) {
    func_00015228();
    func_00015650();
}

/* func_000150D0 — 3 words. MATCH 100% (shape: m2c). */
void func_000150D0(s32 arg0) {
    *(s32 *)0x8E7394 = arg0;
}

/* func_00015648 — 2 words. MATCH 100% (shape: m2c). */
void func_00015648(void) {

}

/* func_00015914 — 2 words. MATCH 100% (shape: m2c). */
void func_00015914(void) {

}

/* func_00015DB4 — 15 words. MATCH 100% (shape: m2c). */
void func_00015DB4(void) {
    *(s32 *)0x8E7518 = 0;
    ehsys_5DF04F49(&D_8E73C0);
    ehsys_memset(&D_8E73B8, 0, 0x184);
}

/* func_000163F4 — 3 words. MATCH 100% (shape: m2c). */
s32 func_000163F4(void) {
    return *(s32 *)0x8E7508;
}

/* func_00016414 — 3 words. MATCH 100% (shape: m2c). */
void func_00016414(s32 arg0) {
    *(s32 *)0x8E74A8 = arg0;
}

/* func_000164A8 — 4 words. MATCH 100% (shape: m2c). */
void func_000164A8(void) {
    *(s32 *)0x8E73B8 = 1;
}

/* func_000164B8 — 4 words. MATCH 100% (shape: m2c). */
void func_000164B8(void) {
    *(s32 *)0x8E73B8 = 3;
}

/* func_00016580 — 13 words. MATCH 100% (shape: m2c). */
s32 func_00016580(void) {
    s32 temp_v1;

    temp_v1 = *(s32 *)0x8E73B8;
    if ((temp_v1 != 3) && (temp_v1 != 1)) {
        return 0;
    }
    return 1;
}

/* func_00016B74 — 9 words. MATCH 100% (shape: m2c). */
void func_00016B74(void) {
    ehsys_06380DFA();
    ehsys_AB962AE7(0);
}

