/*
 * rel_gallery.prx — reconstructed code (matching decompilation)
 *
 * Compiler:     Metrowerks CodeWarrior for PSP — MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,s -sdatathreshold 0
 * Verification: scripts/mwcc_build.sh src/rel_gallery.c
 *               scripts/mwcc_diff.py asm/rel_gallery/text.s build/mwcc/rel_gallery.o
 *
 * Every function below is byte-identical to the shipped module — each was
 * accepted only on a MATCH verdict from scripts/mwcc_diff.py, and the whole
 * file is re-verified after assembly (scripts/assemble_module.py).
 * Functions are in ADDRESS ORDER, which is what the linker needs.
 *
 * Import names are resolved from the module's NID tables and are identical
 * across all 28 modules — see docs/nids/README.md.
 *
 * STATUS: 9 functions matched here. The rest of the module is not
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
extern char D_0000A840;
extern int ehsys_B4471B5E();
extern int func_00000188();
extern int func_00003F30();

/* ---- forward declarations ---- */
s32 func_00000150(s32 arg0);
void func_00000228(void);
void func_00001818(void);
void func_00003204(void);
void func_00003F94(void);
void func_000042B8(void);
void func_00004314(void);
void func_00004394(void);
void func_000044A4(void);

/* func_00000150 — 14 words. MATCH 100% (shape: m2c). */
s32 func_00000150(s32 arg0) {
    if (arg0 == 0) {
        ehsys_B4471B5E(func_00000188, func_00000228, &D_0000A840);
    }
    return 0;
}

/* func_00000228 — 2 words. MATCH 100% (shape: m2c). */
void func_00000228(void) {

}

/* func_00001818 — 2 words. MATCH 100% (shape: m2c). */
void func_00001818(void) {

}

/* func_00003204 — 2 words. MATCH 100% (shape: m2c). */
void func_00003204(void) {

}

/* func_00003F94 — 2 words. MATCH 100% (shape: m2c). */
void func_00003F94(void) {
    func_00003F30();
}

/* func_000042B8 — 2 words. MATCH 100% (shape: m2c). */
void func_000042B8(void) {

}

/* func_00004314 — 2 words. MATCH 100% (shape: m2c). */
void func_00004314(void) {

}

/* func_00004394 — 2 words. MATCH 100% (shape: m2c). */
void func_00004394(void) {

}

/* func_000044A4 — 2 words. MATCH 100% (shape: m2c). */
void func_000044A4(void) {

}

