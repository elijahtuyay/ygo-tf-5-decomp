/*
 * rel_recipeviewer.prx -- reconstructed code (matching decompilation)
 *
 * What it is:  Deck recipe viewer: browses saved/shared deck recipes (deck/all_%c.ehp, deck/recipe_view.ehp) and renders their card-icon/panel UI (cis_all.gim, ciss.gim, panel.gim, icon0N.gim).
 *
 * Compiler:     Metrowerks CodeWarrior for PSP -- MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,s -sdatathreshold 0   (SIZE, not ,p)
 * Verification: scripts/mwcc_build.sh src/rel_recipeviewer.c && \
 *               scripts/mwcc_diff.py asm/rel_recipeviewer/text.s build/mwcc/rel_recipeviewer.o
 *               Every function below must report MATCH; if one regresses it
 *               must be fixed or pulled from this file (see docs/09-first-match.md
 *               and the src/rel_movie_viewer.c header for the accumulated list of
 *               MWCC -O4,s codegen levers this project has found so far).
 *
 * Status:       8/96 functions in this module are matched and present
 *               below (each tagged "MATCH 100%"). The rest are tracked in
 *               build/auto/rel_recipeviewer.json (status + closest-verdict per function,
 *               written by scripts/auto_decomp.py) and build/auto/rel_recipeviewer/*.c
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
 * Matched functions (8): func_00000000, func_00000958, func_00002958, func_0000296C, func_00003BD4, func_00003ED0, func_0000695C, func_00006D64
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

extern char D_0000E5BD;
extern char D_0000E5BE;
extern char D_00010358;
extern char D_0001047C;
extern char D_00010484;

extern int func_00006D6C();

/* func_00000000 -- MATCH 100% (2 words). */
s32 func_00000000(void) {
    return 0;
}

/* func_00000958 -- MATCH 100% (7 words). */
s32 func_00000958(s32 arg0) {
    s32 var_a0;

    var_a0 = arg0;
    if (var_a0 >= 0x5A) {
        var_a0 -= 4;
    }
    return var_a0;
}

/* func_00002958 -- MATCH 100% (5 words). */
u32 func_00002958(void) {
    return (u32) ((u8) D_0000E5BD << 0x1E) >> 0x1F;
}

/* func_0000296C -- MATCH 100% (3 words). */
u16 func_0000296C(void) {
    return D_0000E5BE;
}

/* func_00003BD4 -- MATCH 100% (15 words). */
s32 func_00003BD4(s32 arg0) {
    s32 sp1C;

    sp1C = arg0;
    ehsys_EF9B5D06(&sp1C, &D_00010358);
    ehsys_EF9B5D06(&sp1C, &D_00010484);
    return sp1C;
}

/* func_00003ED0 -- MATCH 100% (12 words). */
void func_00003ED0(void) {
    ehsys_memset(&D_0001047C, 0, 0x12C);
    D_0001047C = 0;
}

/* func_0000695C -- MATCH 100% (4 words). */
s32 func_0000695C(u16 *arg0, u16 *arg1) {
    return *arg0 - *arg1;
}

/* func_00006D64 -- MATCH 100% (2 words). */
void func_00006D64(void) {
    func_00006D6C();
}

