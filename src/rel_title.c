/*
 * rel_title.prx — reconstructed code (matching decompilation)
 *
 * Compiler:     Metrowerks CodeWarrior for PSP — MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,s -sdatathreshold 0
 * Verification: scripts/mwcc_build.sh src/rel_title.c
 *               scripts/mwcc_diff.py asm/rel_title/text.s build/mwcc/rel_title.o
 *
 * Every function below is byte-identical to the shipped module — each was
 * accepted only on a MATCH verdict from scripts/mwcc_diff.py, and the whole
 * file is re-verified after assembly (scripts/assemble_module.py).
 * Functions are in ADDRESS ORDER, which is what the linker needs.
 *
 * Import names are resolved from the module's NID tables and are identical
 * across all 28 modules — see docs/nids/README.md.
 *
 * STATUS: 12 functions matched here. The rest of the module is not
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
extern int ehsys_BC8E65D7();

/* ---- forward declarations ---- */
void func_0000D420(int a, int b, int c, int d);
void func_0000F028(int a, int b, int c, int d);
void func_00017374(void);
void func_0001A2E4(int a, int b, int c, int d);
void func_0001D46C(void);
void func_0001D650(void);
void func_00029470(int a, int b, int c, int d);
void func_0002B944(int a, int b, int c, int d);
void func_00040C30(void);
void func_00040C38(void);
void func_00040C40(void);
void func_00040C48(void);

/* func_0000D420 — 5 words. MATCH 100% (shape: thunk, arg0-2 <<6). */
void func_0000D420(int a, int b, int c, int d) {
    ehsys_BC8E65D7(a << 6, b << 6, c << 6, d, -1);
}

/* func_0000F028 — 5 words. MATCH 100% (shape: thunk, arg0-2 <<6). */
void func_0000F028(int a, int b, int c, int d) {
    ehsys_BC8E65D7(a << 6, b << 6, c << 6, d, -1);
}

/* func_00017374 — 2 words. MATCH 100% (shape: m2c). */
void func_00017374(void) {

}

/* func_0001A2E4 — 5 words. MATCH 100% (shape: thunk, arg0-2 <<6). */
void func_0001A2E4(int a, int b, int c, int d) {
    ehsys_BC8E65D7(a << 6, b << 6, c << 6, d, -1);
}

/* func_0001D46C — 2 words. MATCH 100% (shape: m2c). */
void func_0001D46C(void) {

}

/* func_0001D650 — 2 words. MATCH 100% (shape: m2c). */
void func_0001D650(void) {

}

/* func_00029470 — 5 words. MATCH 100% (shape: thunk, arg0-2 <<6). */
void func_00029470(int a, int b, int c, int d) {
    ehsys_BC8E65D7(a << 6, b << 6, c << 6, d, -1);
}

/* func_0002B944 — 5 words. MATCH 100% (shape: thunk, arg0-2 <<6). */
void func_0002B944(int a, int b, int c, int d) {
    ehsys_BC8E65D7(a << 6, b << 6, c << 6, d, -1);
}

/* func_00040C30 — 2 words. MATCH 100% (shape: m2c). */
void func_00040C30(void) {

}

/* func_00040C38 — 2 words. MATCH 100% (shape: m2c). */
void func_00040C38(void) {

}

/* func_00040C40 — 2 words. MATCH 100% (shape: m2c). */
void func_00040C40(void) {

}

/* func_00040C48 — 2 words. MATCH 100% (shape: m2c). */
void func_00040C48(void) {

}

