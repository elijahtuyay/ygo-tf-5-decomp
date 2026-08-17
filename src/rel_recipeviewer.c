/*
 * rel_recipeviewer.prx — reconstructed code (matching decompilation)
 *
 * Compiler:     Metrowerks CodeWarrior for PSP — MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,s -sdatathreshold 0
 * Verification: scripts/mwcc_build.sh src/rel_recipeviewer.c
 *               scripts/mwcc_diff.py asm/rel_recipeviewer/text.s build/mwcc/rel_recipeviewer.o
 *
 * Every function below is byte-identical to the shipped module — each was
 * accepted only on a MATCH verdict from scripts/mwcc_diff.py, and the whole
 * file is re-verified after assembly (scripts/assemble_module.py).
 * Functions are in ADDRESS ORDER, which is what the linker needs.
 *
 * Import names are resolved from the module's NID tables and are identical
 * across all 28 modules — see docs/nids/README.md.
 *
 * STATUS: 6 functions matched here. The rest of the module is not
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
extern char D_0000E5BD;
extern char D_00010358;
extern char D_00010484;
extern int ehsys_EF9B5D06();
extern int func_00006D6C();

/* ---- forward declarations ---- */
s32 func_00000000(void);
s32 func_00000958(s32 arg0);
s32 func_00003BD4(s32 arg0);
s32 func_0000695C(u16 *arg0, u16 *arg1);
u32 func_00002958(void);
void func_00006D64(void);

/* func_00000000 — 2 words. MATCH 100% (shape: m2c). */
s32 func_00000000(void) {
    return 0;
}

/* func_00000958 — 7 words. MATCH 100% (shape: m2c). */
s32 func_00000958(s32 arg0) {
    s32 var_a0;

    var_a0 = arg0;
    if (var_a0 >= 0x5A) {
        var_a0 -= 4;
    }
    return var_a0;
}

/* func_00002958 — 5 words. MATCH 100% (shape: m2c). */
u32 func_00002958(void) {
    return (u32) ((u8) D_0000E5BD << 0x1E) >> 0x1F;
}

/* func_00003BD4 — 15 words. MATCH 100% (shape: m2c). */
s32 func_00003BD4(s32 arg0) {
    s32 sp1C;

    sp1C = arg0;
    ehsys_EF9B5D06(&sp1C, &D_00010358);
    ehsys_EF9B5D06(&sp1C, &D_00010484);
    return sp1C;
}

/* func_0000695C — 4 words. MATCH 100% (shape: m2c). */
s32 func_0000695C(u16 *arg0, u16 *arg1) {
    return *arg0 - *arg1;
}

/* func_00006D64 — 2 words. MATCH 100% (shape: m2c). */
void func_00006D64(void) {
    func_00006D6C();
}

