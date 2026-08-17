/*
 * rel_deckswap.prx — reconstructed code (matching decompilation)
 *
 * Compiler:     Metrowerks CodeWarrior for PSP — MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,s -sdatathreshold 0
 * Verification: scripts/mwcc_build.sh src/rel_deckswap.c
 *               scripts/mwcc_diff.py asm/rel_deckswap/text.s build/mwcc/rel_deckswap.o
 *
 * Every function below is byte-identical to the shipped module — each was
 * accepted only on a MATCH verdict from scripts/mwcc_diff.py, and the whole
 * file is re-verified after assembly (scripts/assemble_module.py).
 * Functions are in ADDRESS ORDER, which is what the linker needs.
 *
 * Import names are resolved from the module's NID tables and are identical
 * across all 28 modules — see docs/nids/README.md.
 *
 * STATUS: 16 functions matched here. The rest of the module is not
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
extern char D_0001E89C;
extern char D_0001E8C0;
extern char D_0001F040;
extern char D_0001F984;
extern int ehsys_1460C6FD();
extern int ehsys_20E340D9();
extern int ehsys_60B55A50();
extern int ehsys_942B03D0();
extern int ehsys_98E07D26();
extern int ehsys_A4AFF8E6();
extern int ehsys_B8AD96EA();
extern int ehsys_E5738C32();
extern int ehsys_E58C0FDC();
extern int ehsys_E62CCE79();
extern int ehsys_EF9B5D06();
extern int ehsys_FE91A2EC();
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
extern int func_000152E0();
extern int func_000153A8();
extern int func_00015424();
extern int func_000154E4();
extern int func_00015594();

/* ---- forward declarations ---- */
s32 func_00000000(void);
s32 func_00005644(s32 arg0);
s32 func_00007820(s32 arg0, s32 arg1);
s32 func_00007884(s32 arg0, s32 arg1);
s32 func_00007B70(s32 arg0, s32 arg1);
s32 func_0000C29C(u16 *arg0, u16 *arg1);
s32 func_0000FF30(void);
void func_0000BB8C(void);
void func_0000C438(void);
void func_0000D9D8(void);
void func_0000EDBC(s32 arg0, int arg1, int arg2, int arg3);
void func_00012620(s32 arg0, s32 arg1, s32 arg2, int arg3);
void func_0001268C(s32 arg0, s32 arg1, s32 arg2, int arg3);
void func_000126F8(s32 arg0, s32 arg1, s32 arg2, int arg3);
void func_00012764(s32 arg0, s32 arg1, s32 arg2, int arg3);
void func_000127D0(s32 arg0, s32 arg1, s32 arg2, int arg3);

/* func_00000000 — 2 words. MATCH 100% (shape: m2c). */
s32 func_00000000(void) {
    return 0;
}

/* func_00005644 — 11 words. MATCH 100% (shape: m2c). */
s32 func_00005644(s32 arg0) {
    s32 sp1C;

    sp1C = arg0;
    ehsys_EF9B5D06(&sp1C, &D_0001F040);
    return sp1C;
}

/* func_00007820 — 25 words. MATCH 100% (shape: m2c). */
s32 func_00007820(s32 arg0, s32 arg1) {
    s32 temp_s0;

    temp_s0 = arg0 & 0xFFFF;
    if ((ehsys_E5738C32(temp_s0) != 0) && (arg1 & (1 << ehsys_98E07D26(temp_s0)))) {
        return 1;
    }
    return 0;
}

/* func_00007884 — 25 words. MATCH 100% (shape: m2c). */
s32 func_00007884(s32 arg0, s32 arg1) {
    s32 temp_s0;

    temp_s0 = arg0 & 0xFFFF;
    if ((ehsys_E5738C32(temp_s0) != 0) && (arg1 & (1 << ehsys_E62CCE79(temp_s0)))) {
        return 1;
    }
    return 0;
}

/* func_00007B70 — 14 words. MATCH 100% (shape: m2c). */
s32 func_00007B70(s32 arg0, s32 arg1) {
    return (arg1 & (1 << ehsys_FE91A2EC(arg0 & 0xFFFF))) != 0;
}

/* func_0000BB8C — 14 words. MATCH 100% (shape: m2c). */
void func_0000BB8C(void) {
    if (D_0001F984 != 0) {
        ehsys_20E340D9(D_0001E89C, D_0001F984);
        D_0001F984 = 0;
    }
}

/* func_0000C29C — 4 words. MATCH 100% (shape: m2c). */
s32 func_0000C29C(u16 *arg0, u16 *arg1) {
    return *arg0 - *arg1;
}

/* func_0000C438 — 2 words. MATCH 100% (shape: m2c). */
void func_0000C438(void) {
    func_0000C440();
}

/* func_0000D9D8 — 2 words. MATCH 100% (shape: m2c). */
void func_0000D9D8(void) {
    func_0000D7DC();
}

/* func_0000EDBC — 39 words. MATCH 100% (shape: m2c). */
void func_0000EDBC(s32 arg0, int arg1, int arg2, int arg3) {
    s32 temp_s0;

    temp_s0 = ehsys_E58C0FDC(func_0000C5E8(0x8033), 0x9A);
    ehsys_B8AD96EA(arg0);
    ehsys_942B03D0(0xC, 0xC);
    ehsys_60B55A50(-1);
    func_0000EE58(arg1, arg2, arg3, temp_s0);
    ehsys_A4AFF8E6();
}

/* func_0000FF30 — 31 words. MATCH 100% (shape: m2c). */
s32 func_0000FF30(void) {
    s32 var_s0;

    var_s0 = func_00010E1C(func_00010CA4(func_000102F0(func_00011278(func_000100EC(func_00010068(func_0000FFAC()), (u8) D_0001E8C0 & 0xF)))));
    if (ehsys_1460C6FD() != 0) {
        var_s0 = func_0001101C(var_s0);
    }
    return var_s0;
}

/* func_00012620 — 27 words. MATCH 100% (shape: m2c). */
void func_00012620(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    func_000152E0(arg0, (arg1 & 0xFFFF) | ((arg2 & 0xFFFF) << 0x10), arg3, func_0000C5E8(0x8007));
}

/* func_0001268C — 27 words. MATCH 100% (shape: m2c). */
void func_0001268C(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    func_000153A8(arg0, (arg1 & 0xFFFF) | ((arg2 & 0xFFFF) << 0x10), arg3, func_0000C5E8(0x8007));
}

/* func_000126F8 — 27 words. MATCH 100% (shape: m2c). */
void func_000126F8(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    func_00015424(arg0, (arg1 & 0xFFFF) | ((arg2 & 0xFFFF) << 0x10), arg3, func_0000C5E8(0x8007));
}

/* func_00012764 — 27 words. MATCH 100% (shape: m2c). */
void func_00012764(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    func_000154E4(arg0, (arg1 & 0xFFFF) | ((arg2 & 0xFFFF) << 0x10), arg3, func_0000C5E8(0x800A));
}

/* func_000127D0 — 27 words. MATCH 100% (shape: m2c). */
void func_000127D0(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    func_00015594(arg0, (arg1 & 0xFFFF) | ((arg2 & 0xFFFF) << 0x10), arg3, func_0000C5E8(0x800A));
}

