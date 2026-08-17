/*
 * rel_labo.prx — reconstructed code (matching decompilation)
 *
 * Compiler:     Metrowerks CodeWarrior for PSP — MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,s -sdatathreshold 0
 * Verification: scripts/mwcc_build.sh src/rel_labo.c
 *               scripts/mwcc_diff.py asm/rel_labo/text.s build/mwcc/rel_labo.o
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
extern char D_00006850;
extern char D_00006BA0;
extern char D_0000ADF0;
extern char D_0000AE0C;
extern char D_0000AE18;
extern char D_0000AE1C;
extern char D_0000AE20;
extern char D_0000AE24;
extern char D_0000AE30;
extern char D_0000AE40;
extern int ehsys_1D98951B();
extern int ehsys_1EC5342B();
extern int ehsys_399AC68A();
extern int ehsys_42110BF9();
extern int ehsys_82B715FD();
extern int ehsys_B4471B5E();
extern int ehsys_BF3E9066();
extern int ehsys_C62F9EAC();
extern int ehsys_D2A768F4();
extern int ehsys_DF62D899();
extern int ehsys_DFCA450B();
extern int ehsys_memset();
extern int func_00000034();

/* ---- forward declarations ---- */
s32 func_00000000(void);
s32 func_000012A4(void);
void func_0000097C(void);
void func_00000984(void);
void func_00000A0C(void);
void func_00000B58(void);

/* func_00000000 — 13 words. MATCH 100% (shape: m2c). */
s32 func_00000000(void) {
    ehsys_B4471B5E(func_00000034, func_0000097C, &D_0000AE0C);
    return 0;
}

/* func_0000097C — 2 words. MATCH 100% (shape: m2c). */
void func_0000097C(void) {

}

/* func_00000984 — 34 words. MATCH 100% (shape: hand). */
void func_00000984(void) {
    s32 fn = ((int *) &D_00006850)[*(int *) &D_0000ADF0];
    if (fn != 0) {
        ((void (*)(void)) fn)();
        return;
    }
    ehsys_1EC5342B(ehsys_C62F9EAC(ehsys_399AC68A(ehsys_42110BF9(ehsys_1D98951B(ehsys_DFCA450B(0, 0), 0xFF000000), 0), 0), 0x17));
}

/* func_00000A0C — 2 words. MATCH 100% (shape: m2c). */
void func_00000A0C(void) {

}

/* func_00000B58 — 28 words. MATCH 100% (shape: hand). */
void func_00000B58(void) {
    ehsys_memset(&D_0000AE18, 0, 0x1C);
    *(int *) &D_0000AE1C = 2;
    *(void **) &D_0000AE30 = &D_0000AE40;
    ehsys_BF3E9066(3, &D_00006BA0, *(void **) &D_0000AE30, ehsys_D2A768F4(3, &D_00006BA0));
}

/* func_000012A4 — 17 words. MATCH 100% (shape: hand). */
s32 func_000012A4(void) {
    s32 temp_v0 = ehsys_DF62D899(*(int *) &D_0000AE1C, *(int *) &D_0000AE20);
    s32 temp_s0 = *(int *) &D_0000AE24;
    return ehsys_82B715FD(temp_v0) + temp_s0;
}

