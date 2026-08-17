/*
 * rel_duelrecord.prx — reconstructed code (matching decompilation)
 *
 * Compiler:     Metrowerks CodeWarrior for PSP — MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,s -sdatathreshold 0
 * Verification: scripts/mwcc_build.sh src/rel_duelrecord.c
 *               scripts/mwcc_diff.py asm/rel_duelrecord/text.s build/mwcc/rel_duelrecord.o
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
extern char D_00009F70;
extern char D_0000A166;
extern char D_0000A168;
extern char D_0000A188;
extern char D_0000A2F0;
extern char D_0000A2F4;
extern int ehsys_20E340D9();
extern int ehsys_memset();
extern int ehsys_qsort();

/* ---- forward declarations ---- */
s16 func_000042A0(void);
s32 func_00000000(void);
s32 func_0000453C(void);
s32 func_00004694(u16 *arg0, u16 *arg1);
void func_000042AC(s16 arg0);
void func_00004354(void);
void func_000044FC(void);
void func_00004504(void);

/* func_00000000 — 2 words. MATCH 100% (shape: m2c). */
s32 func_00000000(void) {
    return 0;
}

/* func_000042A0 — 3 words. MATCH 100% (shape: m2c). */
s16 func_000042A0(void) {
    return D_0000A168;
}

/* func_000042AC — 3 words. MATCH 100% (shape: m2c). */
void func_000042AC(s16 arg0) {
    D_0000A166 = arg0;
}

/* func_00004354 — 17 words. MATCH 100% (shape: m2c). */
void func_00004354(void) {
    ehsys_memset(&D_0000A2F0, 0, 2);
    ehsys_qsort(&D_00009F70, 3, 0xC, func_00004694);
}

/* func_000044FC — 2 words. MATCH 100% (shape: m2c). */
void func_000044FC(void) {
    func_00004504();
}

/* func_00004504 — 14 words. MATCH 100% (shape: m2c). */
void func_00004504(void) {
    if (D_0000A2F4 != 0) {
        ehsys_20E340D9(D_0000A188, D_0000A2F4);
        D_0000A2F4 = 0;
    }
}

/* func_0000453C — 3 words. MATCH 100% (shape: m2c). */
s32 func_0000453C(void) {
    return D_0000A2F4;
}

/* func_00004694 — 4 words. MATCH 100% (shape: m2c). */
s32 func_00004694(u16 *arg0, u16 *arg1) {
    return *arg0 - *arg1;
}

