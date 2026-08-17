/*
 * rel_cardalbum.prx -- reconstructed code (matching decompilation)
 *
 * What it is:  Card album viewer: renders the collected-card grid/list (icon, frame, spell/trap overlays) using bg.gim/hand.gim/icon*.gim/frame.gim assets.
 *
 * Compiler:     Metrowerks CodeWarrior for PSP -- MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,s -sdatathreshold 0   (SIZE, not ,p)
 * Verification: scripts/mwcc_build.sh src/rel_cardalbum.c && \
 *               scripts/mwcc_diff.py asm/rel_cardalbum/text.s build/mwcc/rel_cardalbum.o
 *               Every function below must report MATCH; if one regresses it
 *               must be fixed or pulled from this file (see docs/09-first-match.md
 *               and the src/rel_movie_viewer.c header for the accumulated list of
 *               MWCC -O4,s codegen levers this project has found so far).
 *
 * Status:       7/82 functions in this module are matched and present
 *               below (each tagged "MATCH 100%"). The rest are tracked in
 *               build/auto/rel_cardalbum.json (status + closest-verdict per function,
 *               written by scripts/auto_decomp.py) and build/auto/rel_cardalbum/*.c
 *               (per-function trial sources) for hand-iteration.
 *
 * Conventions:  names func_XXXXXXXX / D_XXXXXXXX are placeholders (by address);
 *               extern declarations for globals/functions not defined in this
 *               file use whatever type ("char", "int", "void *", ...) the
 *               verified compile actually required -- these are NOT meant to
 *               convey the true C type, only to reproduce the exact codegen
 *               (see docs/09-first-match.md and scripts/auto_decomp.py's
 *               DATA_FLAVOURS). Absolute addresses baked directly into the
 *               original binary with no relocation (e.g. *(s32 *)0x290CE4)
 *               are written as raw pointer casts rather than named externs --
 *               see mwcc_diff.py's "raw word" vs "reloc" comparison.
 *
 * Matched functions (7): func_00001708, func_00001C48, func_00002FD0, func_000052C4, func_00005EFC, func_000063E4, func_00006A84
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

extern char D_0000CA74;
extern char D_0000CA84;
extern int D_0000F03C;
extern int D_0000F040;
extern int D_0000F044;
extern char D_0000F074;

extern int func_00004488();
extern int func_00005238();
extern int func_00005F04();
extern int func_0000608C();

/* func_00001708 -- MATCH 100% (27 words). */
void func_00001708(void) {
    if (D_0000CA74 != 0) {
        ehsys_20E340D9(D_0000F074, D_0000CA74);
        D_0000CA74 = 0;
    }
    if (D_0000CA84 != 0) {
        ehsys_E1139F1A(D_0000CA84);
        ehsys_20E340D9(D_0000F074, D_0000CA84);
        D_0000CA84 = 0;
    }
}

/* func_00001C48 -- MATCH 100% (11 words). */
s32 func_00001C48(s32 arg0) {
    s32 sp1C;

    sp1C = arg0;
    ehsys_EF9B5D06(&sp1C, D_0000CA84);
    return sp1C;
}

/* func_00002FD0 -- MATCH 100% (16 words). */
void func_00002FD0(void) {
    func_00004488();
    func_00005238(8);
    D_0000F03C = 0;
    D_0000F040 = 0x3F800000;
    D_0000F044 = 0x3F800000;
}

/* func_000052C4 -- MATCH 100% (27 words). */
void func_000052C4(void) {
    int sp1C;
    s32 sp18;
    s32 temp_a1;
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0 = func_0000608C(0x1010);
    if (temp_v0 != 0) {
        ehsys_B8770B92(temp_v0, &sp1C, &sp18);
        temp_v0_2 = ehsys_558B2DCB(temp_v0);
        if (sp18 > 0) {
            temp_a1 = sp18 - 1;
            if (temp_v0_2 >= temp_a1) {
                ehsys_831C5769(temp_v0, temp_a1, sp18);
            }
        }
    }
}

/* func_00005EFC -- MATCH 100% (2 words). */
void func_00005EFC(void) {
    func_00005F04();
}

/* func_000063E4 -- MATCH 100% (4 words). */
s32 func_000063E4(u16 *arg0, u16 *arg1) {
    return *arg0 - *arg1;
}

/* func_00006A84 -- MATCH 100% (2 words). */
s32 func_00006A84(void) {
    return 0;
}

