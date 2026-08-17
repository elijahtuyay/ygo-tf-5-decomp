/*
 * rel_labo.prx — reconstructed code (matching decompilation)
 *
 * Compiler:     Metrowerks CodeWarrior for PSP — MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,s -sdatathreshold 0
 * Verification: scripts/mwcc_build.sh src/rel_labo.c
 *               scripts/mwcc_diff.py asm/rel_labo/text.s build/mwcc/rel_labo.o
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
extern char D_00006850;
extern char D_00006B8C;
extern char D_00006B9C;
extern char D_00006BA0;
extern char D_00006BE4;
extern char D_00006BE8;
extern char D_00006BEC;
extern char D_0000688C;
extern char D_0000A868;
extern char D_0000ADB0;
extern char D_0000ADB4;
extern char D_0000ADF0;
extern char D_0000ADF8;
extern char D_0000AE0C;
extern char D_0000AE18;
extern char D_0000AE1C;
extern char D_0000AE20;
extern char D_0000AE24;
extern char D_0000AE30;
extern char D_0000AE40;
extern int ehsys_1D98951B();
extern int ehsys_1EC5342B();
extern int ehsys_399AC68A();
extern int ehsys_3BB2BAC6();
extern int ehsys_42110BF9();
extern int ehsys_4878E980();
extern int ehsys_60B55A50();
extern int ehsys_7DAC692D();
extern int ehsys_82B715FD();
extern int ehsys_878EE1D3();
extern int ehsys_942B03D0();
extern int ehsys_99FF9D51();
extern int ehsys_B2B9FEFA();
extern int ehsys_B4471B5E();
extern int ehsys_B89D38DC();
extern int ehsys_BF3E9066();
extern int ehsys_C62F9EAC();
extern int ehsys_C87BAB32();
extern int ehsys_D2A768F4();
extern int ehsys_DF62D899();
extern int ehsys_DFCA450B();
extern int ehsys_memset();
extern int ehsys_sprintf();
extern int func_00000034();
extern int func_00000F58();

/* ---- forward declarations ---- */
s32 func_00000000(void);
void func_0000097C(void);
void func_00000984(void);
void func_00000A0C(void);
void func_00000A14(void);
void func_00000B58(void);
void func_00000EC0(void);
int func_00000F38(s32 arg0, s32 arg1, int arg2);
int func_00001164(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
void func_00001180(void);
s32 func_000012A4(void);

/* func_00000000 — 13 words. MATCH 100% (shape: m2c). */
s32 func_00000000(void) {
    ehsys_B4471B5E(func_00000034, func_0000097C, &D_0000AE0C);
    return 0;
}

/* func_0000097C — 2 words. MATCH 100% (shape: m2c). */
void func_0000097C(void) {

}

/* func_00000984 — 34 words. MATCH 100% (shape: hand). */
void func_00000984(void) {
    s32 fn = ((int *) &D_00006850)[*(int *) &D_0000ADF0];
    if (fn != 0) {
        ((void (*)(void)) fn)();
        return;
    }
    ehsys_1EC5342B(ehsys_C62F9EAC(ehsys_399AC68A(ehsys_42110BF9(ehsys_1D98951B(ehsys_DFCA450B(0, 0), 0xFF000000), 0), 0), 0x17));
}

/* func_00000A0C — 2 words. MATCH 100% (shape: m2c). */
void func_00000A0C(void) {

}

/* func_00000A14 — 81 words. MATCH 100% (shape: hand). */
void func_00000A14(void) {
    s32 sp1C;
    s32 temp_v0;
    s32 var_s0;

    sp1C = ehsys_DFCA450B(0, 0);
    sp1C = ehsys_1D98951B(sp1C, 0xFF404000);
    sp1C = ehsys_42110BF9(sp1C, 0);
    sp1C = ehsys_399AC68A(sp1C, 0);
    sp1C = ehsys_C62F9EAC(sp1C, 0x17);
    ehsys_1EC5342B(sp1C);
    ehsys_4878E980(4);
    ehsys_942B03D0(0xA, 0xA);
    ehsys_60B55A50(-1);
    ehsys_C87BAB32(0xC, 2, &D_00006B8C);
    temp_v0 = ehsys_B2B9FEFA();
    if ((*(int *) temp_v0 >> 3) & 1) {
        ehsys_C87BAB32(0, ((*(int *) &D_0000ADF8) * 0xC) + 0x18, &D_00006B9C);
    }
    var_s0 = 0;
    do {
        ehsys_C87BAB32(0xC, (var_s0 * 0xC) + 0x18, (char *) &D_0000688C + (var_s0 << 6));
        var_s0 += 1;
    } while (var_s0 < 0xC);
    sp1C = ehsys_DFCA450B(4, 0);
    ehsys_878EE1D3(&sp1C);
    ehsys_1EC5342B(sp1C);
}

/* func_00000B58 — 28 words. MATCH 100% (shape: hand). */
void func_00000B58(void) {
    ehsys_memset(&D_0000AE18, 0, 0x1C);
    *(int *) &D_0000AE1C = 2;
    *(void **) &D_0000AE30 = &D_0000AE40;
    ehsys_BF3E9066(3, &D_00006BA0, *(void **) &D_0000AE30, ehsys_D2A768F4(3, &D_00006BA0));
}

/* func_00000EC0 — 30 words. MATCH 100% (shape: hand). */
void func_00000EC0(void) {
    u16 temp_s1 = *(u16 *) &D_0000AE1C;
    u16 temp_a0 = *(u16 *) &D_0000AE20;

    if ((s32) temp_s1 >= 2) {
        u16 temp_s0 = temp_a0 & 0xFFFF;
        if (ehsys_99FF9D51(temp_s1, temp_s0) != 0) {
            func_00000F38(0x7F, 0xA, ehsys_7DAC692D(temp_s1, temp_s0, 0));
        }
    }
}

/* func_00000F38 — 8 words. MATCH 100% (shape: hand). */
int func_00000F38(s32 arg0, s32 arg1, int arg2) {
    return ehsys_B89D38DC(arg0 << 6, arg1 << 6, (0x1E0 - arg0) << 6, arg2);
}

/* func_00001164 — 7 words. MATCH 100% (shape: hand). */
int func_00001164(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    return ehsys_3BB2BAC6(arg0 << 6, arg1 << 6, arg2 << 6, arg3 << 6, arg4, -1, 0);
}

/* func_00001180 — 73 words. MATCH 100% (shape: hand). */
void func_00001180(void) {
    char sp10[1024];

    ehsys_60B55A50(-1);
    ehsys_942B03D0(0xE, 0xE);
    ehsys_C87BAB32(0xA, ((*(int *) &D_0000AE18) * 0x14) + 0xA, &D_0000ADB0);
    ehsys_sprintf(sp10, (*(int *) &D_00006BE4), (*(int *) &D_0000AE1C));
    ehsys_C87BAB32(0x1E, 0xA, sp10);
    ehsys_sprintf(sp10, (*(int *) &D_00006BE8), (*(int *) &D_0000AE20));
    ehsys_C87BAB32(0x1E, 0x1E, sp10);
    ehsys_sprintf(sp10, (*(int *) &D_00006BEC), (*(int *) &D_0000AE24), ((int *) &D_0000A868)[(*(int *) &D_0000AE24)]);
    ehsys_942B03D0(0xC, 0xC);
    ehsys_C87BAB32(0x1E, 0x32, sp10);
    ehsys_942B03D0(0xE, 0xE);
    func_00000EC0();
    func_00000F58();
    ehsys_942B03D0(0xE, 0xE);
    ehsys_C87BAB32(0xA, 0xFA, &D_0000ADB4);
}

/* func_000012A4 — 17 words. MATCH 100% (shape: hand). */
s32 func_000012A4(void) {
    s32 temp_v0 = ehsys_DF62D899(*(int *) &D_0000AE1C, *(int *) &D_0000AE20);
    s32 temp_s0 = *(int *) &D_0000AE24;
    return ehsys_82B715FD(temp_v0) + temp_s0;
}
