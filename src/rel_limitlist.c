/*
 * rel_limitlist.prx — reconstructed code (matching decompilation)
 *
 * Compiler:     Metrowerks CodeWarrior for PSP — MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,s -sdatathreshold 0
 * Verification: scripts/mwcc_build.sh src/rel_limitlist.c
 *               scripts/mwcc_diff.py asm/rel_limitlist/text.s build/mwcc/rel_limitlist.o
 *
 * Every function below is byte-identical to the shipped module — each was
 * accepted only on a MATCH verdict from scripts/mwcc_diff.py, and the whole
 * file is re-verified after assembly (scripts/assemble_module.py).
 * Functions are in ADDRESS ORDER, which is what the linker needs.
 *
 * Import names are resolved from the module's NID tables and are identical
 * across all 28 modules — see docs/nids/README.md.
 *
 * STATUS: 11 functions matched here. The rest of the module is not
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
extern char D_0000B0D5;
extern char D_0000B134;
extern char D_0000B540;
extern u16 D_0000AB00[];
extern int ehsys_60B55A50();
extern int ehsys_831C5769();
extern int ehsys_942B03D0();
extern int ehsys_A4AFF8E6();
extern int ehsys_B8AD96EA();
extern int ehsys_B89D38DC();
extern int ehsys_E58C0FDC();
extern int ehsys_EF9B5D06();
extern int ehsys_F843E20A();
extern int func_00000B94();
extern int func_00000CA8();
extern int func_000037F8();
extern int func_000039D4();

/* ---- forward declarations ---- */
s32 func_00000000(void);
s32 func_00001CC8(s32 arg0);
s32 func_000034C8(u16 *arg0, u16 *arg1);
void func_00000B30(s32 arg0, s32 arg1, int arg2);
void func_00000B50(void);
void func_00001484(s32 arg0, s32 arg1, s32 arg2);
void func_00001D14(s32 arg0, s32 arg1, int arg2, s32 arg3);
void func_00001DB4(s32 arg0, s32 arg1, int arg2);
void func_00002BC8(s32 arg0);
void func_000037F0(void);
void func_00003DC0(s32 arg0, s32 arg1, int arg2);

/* func_00000000 — 2 words. MATCH 100% (shape: m2c). */
s32 func_00000000(void) {
    return 0;
}

/* func_00000B30 — 8 words. Draws a 0x1E0-flipped rect: scales coords by 64
 * and forwards to the draw primitive. MATCH 100% (shape: tail-call). */
void func_00000B30(s32 arg0, s32 arg1, int arg2) {
    ehsys_B89D38DC(arg0 << 6, arg1 << 6, (0x1E0 - arg0) << 6, arg2);
}

/* func_00000B50 — 17 words. MATCH 100% (shape: m2c). */
void func_00000B50(void) {
    if (((u32) ((u8) D_0000B0D5 << 0x1D) >> 0x1F) == 0) {
        func_00000B94();
        return;
    }
    func_00000CA8();
}

/* func_00001484 — 4 words. Scales 3 coords by 64, tail-calls the draw
 * primitive. MATCH 100%. */
void func_00001484(s32 arg0, s32 arg1, s32 arg2) {
    ehsys_B89D38DC(arg0 << 6, arg1 << 6, arg2 << 6);
}

/* func_00001CC8 — 19 words. MATCH 100% (shape: m2c). */
s32 func_00001CC8(s32 arg0) {
    s32 sp1C;

    sp1C = arg0;
    if ((u8) D_0000B134 & 1) {
        sp1C = ehsys_F843E20A();
    } else {
        ehsys_EF9B5D06(&sp1C, &D_0000B540);
    }
    return sp1C;
}

/* func_00001D14 — 40 words. Sets up a full-screen clear then draws via
 * func_00001DB4, looking up a per-value u16 from D_0000AB00[]. MATCH 100%. */
void func_00001D14(s32 arg0, s32 arg1, int arg2, s32 arg3) {
    ehsys_942B03D0(0xC, 0xC);
    ehsys_60B55A50(0xFF000000);
    ehsys_B8AD96EA(arg0);
    func_00001DB4(arg2, arg3 + 2,
                  ehsys_E58C0FDC(func_000039D4(0x1020), D_0000AB00[arg1 & 0xFFFF]));
    ehsys_A4AFF8E6();
}

/* func_00001DB4 — 8 words. Same shape as func_00000B30/func_00003DC0. MATCH 100%. */
void func_00001DB4(s32 arg0, s32 arg1, int arg2) {
    ehsys_B89D38DC(arg0 << 6, arg1 << 6, (0x1E0 - arg0) << 6, arg2);
}

/* func_00002BC8 — 16 words. MATCH 100% (shape: m2c). */
void func_00002BC8(s32 arg0) {
    s32 temp_v0;

    temp_v0 = func_000039D4(0x1010);
    if (temp_v0 != 0) {
        ehsys_831C5769(temp_v0, arg0, arg0 + 1);
    }
}

/* func_000034C8 — 4 words. MATCH 100% (shape: m2c). */
s32 func_000034C8(u16 *arg0, u16 *arg1) {
    return *arg0 - *arg1;
}

/* func_000037F0 — 2 words. MATCH 100% (shape: m2c). */
void func_000037F0(void) {
    func_000037F8();
}

/* func_00003DC0 — 8 words. Same shape as func_00000B30/func_00001DB4. MATCH 100%. */
void func_00003DC0(s32 arg0, s32 arg1, int arg2) {
    ehsys_B89D38DC(arg0 << 6, arg1 << 6, (0x1E0 - arg0) << 6, arg2);
}

