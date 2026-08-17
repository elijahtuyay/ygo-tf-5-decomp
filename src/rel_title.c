/*
 * rel_title.prx — reconstructed code (matching decompilation)
 *
 * Compiler:     Metrowerks CodeWarrior for PSP — MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,s -sdatathreshold 0
 * Verification: scripts/mwcc_build.sh src/rel_title.c
 *               scripts/mwcc_diff.py asm/rel_title/text.s build/mwcc/rel_title.o
 *
 * Every function below is byte-identical to the shipped module: each was
 * accepted only on a MATCH verdict, and the whole file is re-verified after
 * assembly. Functions are in ADDRESS ORDER, which is what the linker needs.
 *
 * Import names come from the module's NID tables and are identical across
 * all 28 modules — see docs/nids/README.md.
 *
 * Externs are declared inside each function on purpose: the same global is
 * accessed at different widths by different functions, and a single
 * file-scope declaration would change the load/store width and break the
 * match. See scripts/assemble_module.py.
 *
 * STATUS: 16 functions matched. build/auto/rel_title.json has the
 * status of every attempt, including what the rest of the module still needs.
 *
 * Assembled by scripts/assemble_module.py from scripts/auto_decomp.py drafts,
 * so local names are still m2c's (temp_v0, var_s1). Renaming them and adding
 * commentary is safe as long as every edit is re-verified.
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


/* func_0000D420 — 5 words. MATCH 100% (shape: thunk+1). */
void func_0000D420(int a, int b, int c, int d) {
    extern int ehsys_BC8E65D7();
    extern int func_0000D420();
    ehsys_BC8E65D7(a << 6, b << 6, c << 6, d, -1);
}

/* func_0000F028 — 5 words. MATCH 100% (shape: thunk+1). */
void func_0000F028(int a, int b, int c, int d) {
    extern int ehsys_BC8E65D7();
    extern int func_0000F028();
    ehsys_BC8E65D7(a << 6, b << 6, c << 6, d, -1);
}

/* func_00017374 — 2 words. MATCH 100% (shape: m2c). */
void func_00017374(void) {
    extern int func_00017374();

}

/* func_0001A2E4 — 5 words. MATCH 100% (shape: thunk+1). */
void func_0001A2E4(int a, int b, int c, int d) {
    extern int ehsys_BC8E65D7();
    extern int func_0001A2E4();
    ehsys_BC8E65D7(a << 6, b << 6, c << 6, d, -1);
}

/* func_0001A318 — 2 words. MATCH 100% (shape: thunk+1). */
int func_0001A318(int a) {
    extern int ehsys_5F00A362();
    extern int func_0001A318();
    return ehsys_5F00A362(a << 6);
}

/* func_0001A5A8 — 4 words. MATCH 100% (shape: thunk+1). */
int func_0001A5A8(int a, int b, int c) {
    extern int ehsys_B89D38DC();
    extern int func_0001A5A8();
    return ehsys_B89D38DC(a << 6, b << 6, c << 6);
}

/* func_0001D46C — 2 words. MATCH 100% (shape: m2c). */
void func_0001D46C(void) {
    extern int func_0001D46C();

}

/* func_0001D650 — 2 words. MATCH 100% (shape: m2c). */
void func_0001D650(void) {
    extern int func_0001D650();

}

/* func_000268A0 — 2 words. MATCH 100% (shape: thunk+1). */
int func_000268A0(int a) {
    extern int ehsys_5F00A362();
    extern int func_000268A0();
    return ehsys_5F00A362(a << 6);
}

/* func_00029470 — 5 words. MATCH 100% (shape: thunk+1). */
void func_00029470(int a, int b, int c, int d) {
    extern int ehsys_BC8E65D7();
    extern int func_00029470();
    ehsys_BC8E65D7(a << 6, b << 6, c << 6, d, -1);
}

/* func_00029574 — 4 words. MATCH 100% (shape: thunk+1). */
int func_00029574(int a, int b, int c) {
    extern int ehsys_B89D38DC();
    extern int func_00029574();
    return ehsys_B89D38DC(a << 6, b << 6, c << 6);
}

/* func_0002B944 — 5 words. MATCH 100% (shape: thunk+1). */
void func_0002B944(int a, int b, int c, int d) {
    extern int ehsys_BC8E65D7();
    extern int func_0002B944();
    ehsys_BC8E65D7(a << 6, b << 6, c << 6, d, -1);
}

/* func_00040C30 — 2 words. MATCH 100% (shape: m2c). */
void func_00040C30(void) {
    extern int func_00040C30();

}

/* func_00040C38 — 2 words. MATCH 100% (shape: m2c). */
void func_00040C38(void) {
    extern int func_00040C38();

}

/* func_00040C40 — 2 words. MATCH 100% (shape: m2c). */
void func_00040C40(void) {
    extern int func_00040C40();

}

/* func_00040C48 — 2 words. MATCH 100% (shape: m2c). */
void func_00040C48(void) {
    extern int func_00040C48();

}

