/*
 * rel_soundtest.prx — reconstructed code (matching decompilation)
 *
 * Compiler:     Metrowerks CodeWarrior for PSP — MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,s -sdatathreshold 0
 * Verification: scripts/mwcc_build.sh src/rel_soundtest.c
 *               scripts/mwcc_diff.py asm/rel_soundtest/text.s build/mwcc/rel_soundtest.o
 *
 * Every function below is byte-identical to the shipped module — each was
 * accepted only on a MATCH verdict from scripts/mwcc_diff.py, and the whole
 * file is re-verified after assembly (scripts/assemble_module.py).
 * Functions are in ADDRESS ORDER, which is what the linker needs.
 *
 * Import names are resolved from the module's NID tables and are identical
 * across all 28 modules — see docs/nids/README.md.
 *
 * STATUS: 5 functions matched here. The rest of the module is not
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
extern char D_00006A2C;
extern char D_00006A48;
extern char D_00006A4C;
extern char D_00006A50;
extern int ehsys_20E340D9();
extern int ehsys_6E42DDCD();
extern int ehsys_BC8E65D7();
extern int ehsys_ED1410E0();
extern int ehsys_F6414A71();
extern int func_00000908();

/* ---- forward declarations ---- */
s32 func_00000000(void);
void func_00000234(void);
void func_0000023C(void);
s32 func_000013FC(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_000015B8(void);

/* func_00000000 — 2 words. MATCH 100% (shape: m2c). */
s32 func_00000000(void) {
    return 0;
}

/* func_00000234 — 2 words. MATCH 100% (shape: m2c). */
void func_00000234(void) {
    func_00000908();
}

/* func_0000023C — 17 words. MATCH 100% (shape: hand). */
void func_0000023C(void) {
    func_000015B8();
    if (*(int *) &D_00006A4C > 0) {
        ehsys_F6414A71(*(int *) &D_00006A4C, *(int *) &D_00006A50);
        ehsys_ED1410E0(*(int *) &D_00006A4C);
    }
}

/* func_000013FC — 5 words. MATCH 100% (shape: hand). */
s32 func_000013FC(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return ehsys_BC8E65D7(arg0 << 6, arg1 << 6, arg2 << 6, arg3, -1);
}

/* func_000015B8 — 12 words. MATCH 100% (shape: hand). */
void func_000015B8(void) {
    ehsys_6E42DDCD();
    ehsys_20E340D9(*(int *) &D_00006A48, *(int *) &D_00006A2C);
}
