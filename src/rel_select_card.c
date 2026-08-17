/*
 * rel_select_card.prx — reconstructed code (matching decompilation)
 *
 * Compiler:     Metrowerks CodeWarrior for PSP — MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,s -sdatathreshold 0
 * Verification: scripts/mwcc_build.sh src/rel_select_card.c
 *               scripts/mwcc_diff.py asm/rel_select_card/text.s build/mwcc/rel_select_card.o
 *
 * Every function below is byte-identical to the shipped module — each was
 * accepted only on a MATCH verdict from scripts/mwcc_diff.py, and the whole
 * file is re-verified after assembly (scripts/assemble_module.py).
 * Functions are in ADDRESS ORDER, which is what the linker needs.
 *
 * Import names are resolved from the module's NID tables and are identical
 * across all 28 modules — see docs/nids/README.md.
 *
 * STATUS: 17 functions matched here. The rest of the module is not
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
extern char D_0001E5E4;
extern char D_0001EB58;
extern char D_0001EB7C;
extern char D_0001EB90;
extern char D_0001F310;
extern char D_0001FC50;
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
extern int func_000012A8();
extern int func_0000FDBC();
extern int func_00010FD4();
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

/* ---- forward declarations ---- */
s32 func_00001B3C(void);
s32 func_00001F54(void);
s32 func_00006B30(s32 arg0);
s32 func_00008DBC(s32 arg0, s32 arg1);
s32 func_00008E20(s32 arg0, s32 arg1);
s32 func_0000910C(s32 arg0, s32 arg1);
s32 func_0000F7A8(u16 *arg0, u16 *arg1);
void func_0000120C(s32 arg0, int arg1, int arg2, int arg3);
void func_0000F040(void);
void func_0000FBA0(void);
void func_000111A0(void);
void func_0001174C(s32 arg0, s32 arg1, s32 arg2, int arg3);
void func_000117B8(s32 arg0, s32 arg1, s32 arg2, int arg3);
void func_00011824(s32 arg0, s32 arg1, s32 arg2, int arg3);
void func_00011890(s32 arg0, s32 arg1, s32 arg2, int arg3);
void func_000118FC(s32 arg0, s32 arg1, s32 arg2, int arg3);
void func_00012BB4(void);

/* func_0000120C — 39 words. MATCH 100% (shape: m2c). */
void func_0000120C(s32 arg0, int arg1, int arg2, int arg3) {
    s32 temp_s0;

    temp_s0 = ehsys_E58C0FDC(func_0000FDBC(0x8033), 0x9A);
    ehsys_B8AD96EA(arg0);
    ehsys_942B03D0(0xC, 0xC);
    ehsys_60B55A50(-1);
    func_000012A8(arg1, arg2, arg3, temp_s0);
    ehsys_A4AFF8E6();
}

/* func_00001B3C — 2 words. MATCH 100% (shape: m2c). */
s32 func_00001B3C(void) {
    return 0;
}

/* func_00001F54 — 12 words. MATCH 100% (shape: single-switch). */
s32 func_00001F54(void) {
    D_0001EB58 = 1;

    switch (D_0001E5E4) {
    case 0:
        return 0;
        break;
    }
    D_0001E5E4 = 0xB;
    return 1;
}

/* func_00006B30 — 11 words. MATCH 100% (shape: m2c). */
s32 func_00006B30(s32 arg0) {
    s32 sp1C;

    sp1C = arg0;
    ehsys_EF9B5D06(&sp1C, &D_0001F310);
    return sp1C;
}

/* func_00008DBC — 25 words. MATCH 100% (shape: m2c). */
s32 func_00008DBC(s32 arg0, s32 arg1) {
    s32 temp_s0;

    temp_s0 = arg0 & 0xFFFF;
    if ((ehsys_E5738C32(temp_s0) != 0) && (arg1 & (1 << ehsys_98E07D26(temp_s0)))) {
        return 1;
    }
    return 0;
}

/* func_00008E20 — 25 words. MATCH 100% (shape: m2c). */
s32 func_00008E20(s32 arg0, s32 arg1) {
    s32 temp_s0;

    temp_s0 = arg0 & 0xFFFF;
    if ((ehsys_E5738C32(temp_s0) != 0) && (arg1 & (1 << ehsys_E62CCE79(temp_s0)))) {
        return 1;
    }
    return 0;
}

/* func_0000910C — 14 words. MATCH 100% (shape: m2c). */
s32 func_0000910C(s32 arg0, s32 arg1) {
    return (arg1 & (1 << ehsys_FE91A2EC(arg0 & 0xFFFF))) != 0;
}

/* func_0000F040 — 14 words. MATCH 100% (shape: m2c). */
void func_0000F040(void) {
    if (D_0001FC50 != 0) {
        ehsys_20E340D9(D_0001EB7C, D_0001FC50);
        D_0001FC50 = 0;
    }
}

/* func_0000F7A8 — 4 words. MATCH 100% (shape: m2c). */
s32 func_0000F7A8(u16 *arg0, u16 *arg1) {
    return *arg0 - *arg1;
}

/* func_0000FBA0 — 2 words. MATCH 100% (shape: m2c). */
void func_0000FBA0(void) {

}

/* func_000111A0 — 2 words. MATCH 100% (shape: m2c). */
void func_000111A0(void) {
    func_00010FD4();
}

/* func_0001174C — 27 words. MATCH 100% (shape: m2c). */
void func_0001174C(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    func_000153A8(arg0, (arg1 & 0xFFFF) | ((arg2 & 0xFFFF) << 0x10), arg3, func_0000FDBC(0x8007));
}

/* func_000117B8 — 27 words. MATCH 100% (shape: m2c). */
void func_000117B8(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    func_00015470(arg0, (arg1 & 0xFFFF) | ((arg2 & 0xFFFF) << 0x10), arg3, func_0000FDBC(0x8007));
}

/* func_00011824 — 27 words. MATCH 100% (shape: m2c). */
void func_00011824(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    func_000154EC(arg0, (arg1 & 0xFFFF) | ((arg2 & 0xFFFF) << 0x10), arg3, func_0000FDBC(0x8007));
}

/* func_00011890 — 27 words. MATCH 100% (shape: m2c). */
void func_00011890(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    func_000155AC(arg0, (arg1 & 0xFFFF) | ((arg2 & 0xFFFF) << 0x10), arg3, func_0000FDBC(0x800A));
}

/* func_000118FC — 27 words. MATCH 100% (shape: m2c). */
void func_000118FC(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    func_0001565C(arg0, (arg1 & 0xFFFF) | ((arg2 & 0xFFFF) << 0x10), arg3, func_0000FDBC(0x800A));
}

/* func_00012BB4 — 18 words. MATCH 100% (shape: m2c). */
void func_00012BB4(void) {
    func_000130B8(func_00012F90(func_00012D8C(func_00012CB8(func_00012BFC()), (u8) D_0001EB90 & 0xF)));
}

