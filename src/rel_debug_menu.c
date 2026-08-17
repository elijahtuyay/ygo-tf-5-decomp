/*
 * rel_debug_menu.prx — reconstructed code (matching decompilation)
 *
 * Compiler:     Metrowerks CodeWarrior for PSP — MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,s -sdatathreshold 0
 * Verification: scripts/mwcc_build.sh src/rel_debug_menu.c
 *               scripts/mwcc_diff.py asm/rel_debug_menu/text.s build/mwcc/rel_debug_menu.o
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
extern char D_00009C90;
extern char D_00009CE4;
extern char D_809CF8;
extern char D_809D04;
extern char D_80A498;
extern char D_80A49C;
extern char D_80AB9C;
extern char D_80B330;
extern char D_80BA2C;
extern int ehsys_13A4081A();
extern int ehsys_1EC5342B();
extern int ehsys_3A7E4F65();
extern int ehsys_3C1C1F65();
extern int ehsys_551A8EF2();
extern int ehsys_6F0D36D3();
extern int ehsys_6FFA2A28();
extern int ehsys_B4471B5E();
extern int ehsys_C2E59A21();
extern int ehsys_C644C679();
extern int ehsys_FC53D253();
extern int ehsys_frame_sync();
extern int ehsys_memset();
extern int ehsys_sceGuFinish();
extern int func_00000034();
extern int func_000037D0();

/* ---- forward declarations ---- */
s32 func_00000000(void);
s32 func_00001D84(s32 arg0, s32 arg1);
void func_00000264(void);
void func_00000C04(void);
void func_00000C78(void);
void func_00001B84(void);
void func_0000206C(void);
void func_000028BC(void);
void func_00003B84(void);

/* func_00000000 — 13 words. MATCH 100% (shape: m2c). */
s32 func_00000000(void) {
    ehsys_B4471B5E(func_00000034, func_00000264, &D_809CF8);
    return 0;
}

/* func_00000264 — 2 words. MATCH 100% (shape: m2c). */
void func_00000264(void) {

}

/* func_00000C04 — 13 words. MATCH 100% (shape: m2c). */
void func_00000C04(void) {
    s32 temp_s0;

    temp_s0 = ehsys_6F0D36D3();
    ehsys_1EC5342B((temp_s0 + ehsys_sceGuFinish()) - 8);
}

/* func_00000C78 — 2 words. MATCH 100% (shape: m2c). */
void func_00000C78(void) {

}

/* func_00001B84 — 14 words. MATCH 100% (shape: m2c). */
void func_00001B84(void) {
    ehsys_6FFA2A28(3, D_00009CE4);
    D_00009C90 += 1;
}

/* func_00001D84 — 24 words. MATCH 100% (shape: m2c). */
s32 func_00001D84(s32 arg0, s32 arg1) {
    ehsys_C2E59A21(0, 0, 0);
    ehsys_13A4081A(1);
    ehsys_frame_sync();
    ehsys_551A8EF2(1, arg0 & 0xFFFF, arg1 & 0xFFFF);
    return 1;
}

/* func_0000206C — 24 words. MATCH 100% (shape: m2c). */
void func_0000206C(void) {
    ehsys_memset(&D_809D04, 0, 0xE98);
    ehsys_FC53D253();
    ehsys_memset(&D_80A498, 0, 0x6C);
    ehsys_3A7E4F65(&D_80A49C, ehsys_3C1C1F65(), 0xF);
}

/* func_000028BC — 12 words. MATCH 100% (shape: m2c). */
void func_000028BC(void) {
    ehsys_memset(&D_80AB9C, 0, 0xE90);
    ehsys_FC53D253();
}

/* func_00003B84 — 16 words. MATCH 100% (shape: m2c). */
void func_00003B84(void) {
    ehsys_C644C679(&D_80BA2C);
    func_000037D0(&D_80B330, 5);
    func_000037D0(&D_80B330, 5);
}

