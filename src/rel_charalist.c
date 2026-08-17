/*
 * rel_charalist.prx — reconstructed code (matching decompilation)
 *
 * Compiler:     Metrowerks CodeWarrior for PSP — MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,s -sdatathreshold 0
 * Verification: scripts/mwcc_build.sh src/rel_charalist.c
 *               scripts/mwcc_diff.py asm/rel_charalist/text.s build/mwcc/rel_charalist.o
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
extern int ehsys_2630B590();
extern int func_00000580();
extern int func_00005C90();

/* ---- forward declarations ---- */
s32 func_0000006C(void);
s32 func_00000B6C(void);
s32 func_00005C58(void);
s32 func_000062DC(u16 *arg0, u16 *arg1);
s32 func_00008D70(s32 arg0);
void func_00000B18(void);

/* func_0000006C — 2 words. MATCH 100% (shape: m2c). */
s32 func_0000006C(void) {
    return 0;
}

/* func_00000B18 — 2 words. MATCH 100% (shape: m2c). */
void func_00000B18(void) {
    func_00000580();
}

/* func_00000B6C — 2 words. MATCH 100% (shape: m2c). */
s32 func_00000B6C(void) {
    return 0;
}

/* func_00005C58 — 14 words. MATCH 100% (shape: m2c). */
s32 func_00005C58(void) {
    if (ehsys_2630B590() != 0) {
        return 0;
    }
    func_00005C90();
    return 1;
}

/* func_000062DC — 4 words. MATCH 100% (shape: m2c). */
s32 func_000062DC(u16 *arg0, u16 *arg1) {
    return *arg0 - *arg1;
}

/* func_00008D70 — 2 words. MATCH 100% (shape: m2c). */
s32 func_00008D70(s32 arg0) {
    return arg0;
}

