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
 * STATUS: 4 functions matched here. The rest of the module is not
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

/* ---- forward declarations ---- */
s32 func_000063E4(u16 *arg0, u16 *arg1);
s32 func_00006A84(void);
void func_000052C4(void);
void func_00005EFC(void);

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

/* func_00005EFC — 2 words. MATCH 100% (shape: m2c). */
void func_00005EFC(void) {
    func_00005F04();
}

/* func_000063E4 — 4 words. MATCH 100% (shape: m2c). */
s32 func_000063E4(u16 *arg0, u16 *arg1) {
    return *arg0 - *arg1;
}

/* func_00006A84 — 2 words. MATCH 100% (shape: m2c). */
s32 func_00006A84(void) {
    return 0;
}

