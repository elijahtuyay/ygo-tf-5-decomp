/*
 * rel_password.prx — reconstructed code (matching decompilation)
 *
 * Compiler:     Metrowerks CodeWarrior for PSP — MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,s -sdatathreshold 0
 * Verification: scripts/mwcc_build.sh src/rel_password.c
 *               scripts/mwcc_diff.py asm/rel_password/text.s build/mwcc/rel_password.o
 *
 * Every function below is byte-identical to the shipped module — each was
 * accepted only on a MATCH verdict from scripts/mwcc_diff.py, and the whole
 * file is re-verified after assembly (scripts/assemble_module.py).
 * Functions are in ADDRESS ORDER, which is what the linker needs.
 *
 * Import names are resolved from the module's NID tables and are identical
 * across all 28 modules — see docs/nids/README.md.
 *
 * STATUS: 8 functions matched here. The rest of the module is not
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
extern char D_00008C08;
extern int ehsys_3BB2BAC6();
extern int ehsys_558B2DCB();
extern int ehsys_5F00A362();
extern int ehsys_B8770B92();
extern int ehsys_B89D38DC();
extern int ehsys_memset();
extern int ehsys_qsort();
extern u8 D_00008ADC;
extern int func_00001358();

/* ---- forward declarations ---- */
s32 func_0000152C(u16 *arg0, u16 *arg1);
s32 func_0000159C(void);
s32 func_0000337C(s32 arg0);
s32 func_000034D8(void);
void func_00000A24(s32 arg0, s32 arg1, s32 arg2);
void func_00000A34(s32 arg0);
void func_00000A58(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_00000D6C(s32 arg0, s32 arg1, int arg2);
void func_000010C4(void);

/* func_00000A24 — 4 words. MATCH 100% (shape: hand). */
void func_00000A24(s32 arg0, s32 arg1, s32 arg2) {
    ehsys_B89D38DC(arg0 << 6, arg1 << 6, arg2 << 6);
}

/* func_00000A34 — 2 words. MATCH 100% (shape: hand). */
void func_00000A34(s32 arg0) {
    ehsys_5F00A362(arg0 << 6);
}

/* func_00000A58 — 5 words. MATCH 100% (shape: hand). */
void func_00000A58(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    ehsys_3BB2BAC6(arg0 << 6, arg1 << 6, arg2 << 6, arg3 << 6);
}

/* func_00000D6C — 8 words. MATCH 100% (shape: hand). */
void func_00000D6C(s32 arg0, s32 arg1, int arg2) {
    ehsys_B89D38DC(arg0 << 6, arg1 << 6, (0x1E0 - arg0) << 6, arg2);
}

/* func_000010C4 — 25 words. MATCH 100% (shape: m2c, bitfield lever). */
void func_000010C4(void) {
    struct bf1 { unsigned bit0 : 1; };
    extern struct bf1 D_00008C40;
    ehsys_memset(&D_00008C40, 0, 2);
    D_00008C40.bit0 = 1;
    ehsys_qsort(&D_00008ADC, 0x11, 0x10, func_0000152C);
}

/* func_0000152C — 4 words. MATCH 100% (shape: m2c). */
s32 func_0000152C(u16 *arg0, u16 *arg1) {
    return *arg0 - *arg1;
}

/* func_0000159C — 2 words. MATCH 100% (shape: m2c). */
s32 func_0000159C(void) {
    return 0;
}

/* func_0000337C — 17 words. MATCH 100% (shape: hand). */
s32 func_0000337C(s32 arg0) {
    s32 i;
    u16 key = arg0 & 0xFFFF;
    for (i = 0; i < 0x12; i++) {
        if (key == ((u16 *) &D_00008C08)[i]) {
            return 1;
        }
    }
    return 0;
}

/* func_000034D8 — 29 words. MATCH 100% (shape: m2c). */
s32 func_000034D8(void) {
    int sp1C;
    s32 sp18;
    s32 temp_s0;
    s32 temp_v0;

    temp_v0 = func_00001358(0x1010);
    if (temp_v0 != 0) {
        temp_s0 = ehsys_558B2DCB(temp_v0);
        ehsys_B8770B92(temp_v0, &sp1C, &sp18);
        if (temp_s0 < (sp18 - 1)) {
            return 0;
        }
    }
    return 1;
}

