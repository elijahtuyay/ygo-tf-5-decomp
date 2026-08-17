/*
 * rel_tutoriallist.prx — reconstructed code (matching decompilation)
 *
 * Compiler:     Metrowerks CodeWarrior for PSP — MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,s -sdatathreshold 0
 * Verification: scripts/mwcc_build.sh src/rel_tutoriallist.c
 *               scripts/mwcc_diff.py asm/rel_tutoriallist/text.s build/mwcc/rel_tutoriallist.o
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
extern char D_00007C04;
extern char D_00007D0C;
extern char D_00007D10;
extern char D_00007D14;
extern int ehsys_20E340D9();
extern int ehsys_97BB99A5();
extern int ehsys_B89D38DC();
extern int ehsys_ED1410E0();
extern int ehsys_F6414A71();

/* ---- forward declarations ---- */
s32 func_00002630(u16 *arg0, u16 *arg1);
s32 func_000026B8(void);
s32 func_00002908(void);
void func_00000658(s32 arg0, s32 arg1, int arg2);
void func_00000B8C(s32 arg0, s32 arg1, s32 arg2);
void func_00001C5C(s32 arg0, s32 arg1);
void func_000023C4(void);
void func_000023CC(void);

/* func_00000658 — 8 words. MATCH 100% (shape: hand). */
void func_00000658(s32 arg0, s32 arg1, int arg2) {
    ehsys_B89D38DC(arg0 << 6, arg1 << 6, (0x1E0 - arg0) << 6, arg2);
}

/* func_00000B8C — 4 words. MATCH 100% (shape: hand). */
void func_00000B8C(s32 arg0, s32 arg1, s32 arg2) {
    ehsys_B89D38DC(arg0 << 6, arg1 << 6, arg2 << 6);
}

/* func_00001C5C — 3 words. MATCH 100% (shape: hand). */
void func_00001C5C(s32 arg0, s32 arg1) {
    ehsys_97BB99A5(arg0, arg1, 0, 0);
}

/* func_000023C4 — 2 words. MATCH 100% (shape: m2c). */
void func_000023C4(void) {
    func_000023CC();
}

/* func_000023CC — 14 words. MATCH 100% (shape: hand). */
void func_000023CC(void) {
    if (*(int *) &D_00007C04 != 0) {
        ehsys_20E340D9(*(int *) &D_00007D0C, *(int *) &D_00007C04);
        *(int *) &D_00007C04 = 0;
    }
}

/* func_00002630 — 4 words. MATCH 100% (shape: m2c). */
s32 func_00002630(u16 *arg0, u16 *arg1) {
    return *arg0 - *arg1;
}

/* func_000026B8 — 2 words. MATCH 100% (shape: m2c). */
s32 func_000026B8(void) {
    return 0;
}

/* func_00002908 — 18 words. MATCH 100% (shape: hand). */
s32 func_00002908(void) {
    func_000023C4();
    if (*(int *) &D_00007D10 > 0) {
        ehsys_F6414A71(*(int *) &D_00007D10, *(int *) &D_00007D14);
        ehsys_ED1410E0(*(int *) &D_00007D10);
    }
    return 1;
}

