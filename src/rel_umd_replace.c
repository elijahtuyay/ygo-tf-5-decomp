/*
 * rel_umd_replace.prx -- reconstructed code (matching decompilation)
 *
 * What it is:  UMD-swap prompt module: detects disc removal/insertion, checks disc region/serial against a whitelist, and streams the alternate localization .ehp/.gim/.tms assets from the replacement UMD (basic_lang_*.ehp, card.tms, card_icon*.gim, ...).
 *
 * Compiler:     Metrowerks CodeWarrior for PSP -- MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,s -sdatathreshold 0   (SIZE, not ,p)
 * Verification: scripts/mwcc_build.sh src/rel_umd_replace.c && \
 *               scripts/mwcc_diff.py asm/rel_umd_replace/text.s build/mwcc/rel_umd_replace.o
 *               Every function below must report MATCH; if one regresses it
 *               must be fixed or pulled from this file (see docs/09-first-match.md
 *               and the src/rel_movie_viewer.c header for the accumulated list of
 *               MWCC -O4,s codegen levers this project has found so far).
 *
 * Status:       26/76 functions in this module are matched and present
 *               below (each tagged "MATCH 100%"). The rest are tracked in
 *               build/auto/rel_umd_replace.json (status + closest-verdict per function,
 *               written by scripts/auto_decomp.py) and build/auto/rel_umd_replace/*.c
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
 * Matched functions (26): func_00000000, func_000000DC, func_00000150, func_0000017C, func_00000184, func_00000250, func_00000614, func_00000FD0, func_000010A0, func_00001164, func_00001A54, func_00001B58, func_00001C7C, func_00002450, func_0000293C, func_00002A58, func_00002E78, func_00002EC8, func_00002ED4, func_0000327C, func_000036B0, func_00003714, func_00003898, func_000038A8, func_000038B8, func_000038C4
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

extern char D_00009350;
extern char D_00009354;
extern char D_000096E0;
extern char D_000096EC;
extern char D_000096F0;
extern char D_000096F4;
extern char D_0000B108;
extern char D_0000B3D0;
extern char D_0000B7E0;
extern char D_0000B7E4;
extern char D_0000B7E8;
extern char D_B910;
extern char D_BAC0;
extern char D_BAD0;
extern char D_BBF4;
extern void * D_BCC0;

extern int func_00000038();
extern void func_000000DC(void);
extern void func_00000184(void);
extern void func_00000250(void);
extern int func_0000042C();
extern int func_00001018();
extern void func_00001164(void);
extern int func_00001330();
extern int func_00001748();
extern int func_00001A88();
extern void func_0000293C(void);
extern int func_000029BC();
extern int func_00002A38();
extern s32 func_0000327C(void);
extern int func_0000364C();
extern int func_000036D4();
extern int func_0000371C();
extern int func_000037E4();
extern void func_00003898(s32 arg0);
extern void func_000038A8(s32 arg0);
extern s32 func_000038B8(void);

/* func_00000000 -- MATCH 100% (14 words). */
s32 func_00000000(s32 arg0) {
    if (arg0 == 0) {
        ehsys_B4471B5E(func_00000038, func_000000DC, &D_000096E0);
    }
    return 0;
}

/* func_000000DC -- MATCH 100% (2 words). */
void func_000000DC(void) {

}

/* func_00000150 -- MATCH 100% (11 words). */
void func_00000150(void) {
    if (D_000096EC != 0) {
        func_00001330();
    }
}

/* func_0000017C -- MATCH 100% (2 words). */
void func_0000017C(void) {
    func_00001164();
}

/* func_00000184 -- MATCH 100% (16 words). */
void func_00000184(void) {
    ehsys_memset(&D_000096F0, 0, 0x1CE0);
    ehsys_30FECAEF(&D_0000B108, func_000038B8());
}

/* func_00000250 -- MATCH 100% (15 words). */
void func_00000250(void) {
    ehsys_5DF04F49(&D_0000B108);
    ehsys_9490E557(D_000096F4, 0, 0);
    ehsys_BFFBA174();
}

/* func_00000614 -- MATCH 100% (4 words). */
s32 func_00000614(void) {
    return D_000096F0 != 0;
}

/* func_00000FD0 -- MATCH 100% (18 words). */
s32 func_00000FD0(s32 arg0) {
    s32 temp_v0;

    temp_v0 = ehsys_39ADDA9F();
    if (temp_v0 != -1) {
        ehsys_E1139F1A(arg0);
    }
    return temp_v0;
}

/* func_000010A0 -- MATCH 100% (49 words). */
void func_000010A0(void) {
    ehsys_1EC5342B(ehsys_459B889D(ehsys_DFCA450B(0, 0)));
    ehsys_EBD1986B(func_00003898, func_000038A8);
    ehsys_memset(&D_0000B3D0, 0, 0x6F0);
    D_0000B7E0 = 0;
    D_0000B7E4 = 0;
    D_0000B7E8 = 0;
    func_0000364C();
    func_00000184();
    ehsys_30FECAEF(&D_B910, func_000038B8());
    func_0000293C();
    *(s32 *)0xB9D8 = ehsys_F96D270D();
    ehsys_4AA58320(1);
    ehsys_5998BFD7(1, 0xFF000000, 1);
}

/* func_00001164 -- MATCH 100% (22 words). */
void func_00001164(void) {
    ehsys_4AA58320(*(s32 *)0xB9D8);
    func_000029BC();
    func_00000250();
    ehsys_5DF04F49(&D_B910);
    func_000036D4();
    ehsys_03E45FFF();
    ehsys_EBD1986B(0, 0);
}

/* func_00001A54 -- MATCH 100% (13 words). */
void func_00001A54(void) {
    func_0000371C(0, func_00001A88, 0);
    D_0000B3D0 = 2;
}

/* func_00001B58 -- MATCH 100% (17 words). */
void func_00001B58(void) {
    func_00002A38(0);
    D_0000B3D0 = 4;
    func_00001748(ehsys_E58C0FDC(func_000037E4(0), 8));
}

/* func_00001C7C -- MATCH 100% (17 words). */
void func_00001C7C(void) {
    func_00001748(ehsys_E58C0FDC(func_000037E4(0), 7));
    func_00002A38(1);
    D_0000B3D0 = 6;
}

/* func_00002450 -- MATCH 100% (13 words). */
void func_00002450(void) {
    func_0000042C(D_0000B7E8);
    D_0000B7E8 = 0;
    D_0000B3D0 = 9;
}

/* func_0000293C -- MATCH 100% (32 words). */
void func_0000293C(void) {
    s32 temp_v0;

    ehsys_memset(&D_BAC0, 0, 0x1FC);
    temp_v0 = sceKernelCreateCallback(&D_00009350, func_0000327C, 0);
    *(s32 *)0xBACC = temp_v0;
    sceUmdRegisterUMDCallBack(temp_v0);
    sceUmdActivate(1, &D_00009354);
    sceImposeSetUMDPopup(0);
    ehsys_30FECAEF(&D_BBF4, func_000038B8());
}

/* func_00002A58 -- MATCH 100% (2 words). */
void func_00002A58(void) {

}

/* func_00002E78 -- MATCH 100% (20 words). */
void func_00002E78(void) {
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = ehsys_DFCA450B(4, 0);
    sp1C = temp_v0;
    sp1C = func_00001018(&D_BAD0, temp_v0);
    ehsys_14BFFB01(&sp1C, &D_BBF4);
    ehsys_1EC5342B(sp1C);
}

/* func_00002EC8 -- MATCH 100% (3 words). */
s32 func_00002EC8(void) {
    return *(s32 *)0xBAC4;
}

/* func_00002ED4 -- MATCH 100% (3 words). */
void **func_00002ED4(void) {
    return &D_BCC0;
}

/* func_0000327C -- MATCH 100% (2 words). */
s32 func_0000327C(void) {
    return 0;
}

/* func_000036B0 -- MATCH 100% (9 words). */
s32 func_000036B0(void) {
    return ehsys_2717C28C(*(s32 *)0x290CE8) != 0;
}

/* func_00003714 -- MATCH 100% (2 words). */
void func_00003714(void) {

}

/* func_00003898 -- MATCH 100% (4 words). */
void func_00003898(s32 arg0) {
    ehsys_41AABF28(*(s32 *)0x290CE4, arg0);
}

/* func_000038A8 -- MATCH 100% (4 words). */
void func_000038A8(s32 arg0) {
    ehsys_20E340D9(*(s32 *)0x290CE4, arg0);
}

/* func_000038B8 -- MATCH 100% (3 words). */
s32 func_000038B8(void) {
    return *(s32 *)0x290CE4;
}

/* func_000038C4 -- MATCH 100% (3 words). */
s32 func_000038C4(void) {
    return *(s32 *)0x290CE8;
}

