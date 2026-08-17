/*
 * rel_tutorial.prx — reconstructed code (matching decompilation)
 *
 * Compiler:     Metrowerks CodeWarrior for PSP — MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,s -sdatathreshold 0
 * Verification: scripts/mwcc_build.sh src/rel_tutorial.c
 *               scripts/mwcc_diff.py asm/rel_tutorial/text.s build/mwcc/rel_tutorial.o
 *
 * Every function below is byte-identical to the shipped module — each was
 * accepted only on a MATCH verdict from scripts/mwcc_diff.py, and the whole
 * file is re-verified after assembly (scripts/assemble_module.py).
 * Functions are in ADDRESS ORDER, which is what the linker needs.
 *
 * Import names are resolved from the module's NID tables and are identical
 * across all 28 modules — see docs/nids/README.md.
 *
 * STATUS: 63 functions matched here. The rest of the module is not
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
extern char D_0000CAF0;
extern s32 D_00010048;
extern char D_000101A4;
extern s32 D_000101D4;
extern char D_15A14;
extern char D_15A2C;
extern char D_15A30;
extern char D_15A34;
extern char D_15A38;
extern char D_15A3C;
extern char D_15A40;
extern char D_15A50;
extern int duel_draw_048AF0E1();
extern int duel_draw_4CDAED11();
extern int duel_draw_6214421F();
extern int duel_draw_6D200A3F();
extern int duel_draw_C04933FF();
extern int duel_draw_C7776D2B();
extern int duel_draw_D755977D();
extern int duel_draw_DB788046();
extern int duel_eng_3865EBDA();
extern int ehsys_06380DFA();
extern int ehsys_1EC5342B();
extern int ehsys_20E340D9();
extern int ehsys_3BB2BAC6();
extern int ehsys_4175E3DB();
extern int ehsys_41AABF28();
extern int ehsys_450CD6C5();
extern int ehsys_878EE1D3();
extern int ehsys_97BB99A5();
extern int ehsys_AB962AE7();
extern int ehsys_BC8E65D7();
extern int ehsys_DFCA450B();
extern int ehsys_memset();
extern int ehsys_strncpy();
extern int func_00000F4C();
extern int func_000014D8();
extern int func_000017D4();
extern int func_00002310();
extern int func_00005170();
extern int func_00005544();
extern int func_00005BB4();
extern int func_00005E98();

/* ---- forward declarations ---- */
s32 func_00001B0C(void);
s32 func_00001B14(void);
s32 func_000026A0(void);
s32 func_00002EBC(void);
s32 func_00003054(void);
s32 func_00003E6C(s32 *arg0);
void *func_00003E74(void);
void *func_00004BB0(void);
void *func_00004BBC(void);
void *func_00004BC8(void);
void *func_00004BD4(void);
void *func_00004BE0(void);
void *func_00004BEC(void);
void *func_00004E28(void);
s32 func_00005250(s32 *arg0);
s32 func_000052F0(s32 arg0, s32 arg1);
void func_00005BA0(void);
void func_000062DC(void);
s32 func_00004764(void);
s32 func_00005444(void);
s32 func_00005844(void);
s32 func_0000584C(void);
s32 func_00005854(void);
s32 func_00005A4C(void *arg0, void *arg1);
s32 func_00005A6C(void);
s32 func_00005B18(void);
s32 func_00005BD4(void);
s32 func_0000602C(void);
s32 func_000067B0(void);
u16 func_00002378(void);
u8 func_00002358(s32 arg0);
void * func_000003EC(s32 arg0);
void func_000005F4(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_00000608(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void func_00000B24(void);
void func_00001B00(s32 arg0, s32 arg1);
void func_00001B20(s32 arg0);
void func_00001B2C(void);
void func_00001B68(void);
void func_00001C30(s32 arg0);
void func_00002048(s32 arg0);
void func_00002384(void);
void func_0000238C(void);
void func_00002394(void);
void func_00002650(void);
void func_00002674(void);
void func_00002680(s32 arg0);
void func_00002690();
void func_00002EA0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void func_00002EC8(s32 arg0);
void func_00002EE8(s32 arg0);
void func_00002F7C(void);
void func_00002F8C(void);
void func_00003688(void);
void func_00004680(void);
void func_00004F28(void);
void func_000051E4(s32 *arg0);
void func_00005224(s32 *arg0, s32 arg1);
void func_0000522C(void);
void func_0000531C(s32 *arg0, s32 arg1);
void func_000054E8(void);
void func_00005834(void);
void func_0000583C(void);
void func_0000585C(s32 arg0, s32 arg1);
void func_00005970(void);
void func_00005A34(void);
void func_00005A40(void *arg0);
void func_00005BA8(void *arg0, s32 arg1);
void func_00005BF8(void);
void func_00005E24(void);
void func_00005F7C(void);
void func_00005FE8(void);
void func_000062B4(s32 arg0);
void func_00006308(void);
void func_00006310(void);

/* func_000003EC — 9 words. MATCH 100% (shape: m2c). */
void *func_000003EC(s32 arg0) {
    return &D_0000CAF0 + (arg0 * 0x428);
}

/* func_000005F4 — 5 words. MATCH 100% (shape: hand). */
void func_000005F4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    ehsys_BC8E65D7(arg0 << 6, arg1 << 6, arg2 << 6, arg3, -1);
}

/* func_00000608 — 7 words. MATCH 100% (shape: hand). */
void func_00000608(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    ehsys_3BB2BAC6(arg0 << 6, arg1 << 6, arg2 << 6, arg3 << 6, arg4, -1, 0);
}

/* func_00000B24 — 2 words. MATCH 100% (shape: m2c). */
void func_00000B24(void) {

}

/* func_00001B00 — 3 words. MATCH 100% (shape: hand). */
void func_00001B00(s32 arg0, s32 arg1) {
    ehsys_97BB99A5(arg0, arg1, 0, 0);
}

/* func_00001B0C — 2 words. MATCH 100% (shape: m2c). */
s32 func_00001B0C(void) {
    return 0;
}

/* func_00001B14 — 3 words. MATCH 100% (shape: m2c). */
s32 func_00001B14(void) {
    return D_00010048;
}

/* func_00001B20 — 3 words. MATCH 100% (shape: m2c). */
void func_00001B20(s32 arg0) {
    D_00010048 = arg0;
}

/* func_00001B2C — 15 words. MATCH 100% (shape: m2c). */
void func_00001B2C(void) {
    ehsys_memset(&D_000101D4, 0, 0x604);
    ehsys_memset(&D_000101A4, 0, 0xC);
}

/* func_00001B68 — 2 words. MATCH 100% (shape: m2c). */
void func_00001B68(void) {

}

/* func_00001C30 — 9 words. MATCH 100% (shape: m2c). */
void func_00001C30(s32 arg0) {
    ehsys_1EC5342B();
    D_000101D4 = 0;
}

/* func_00002048 — 18 words. MATCH 100% (shape: m2c). */
void func_00002048(s32 arg0) {
    if ((arg0 >= 0) && (arg0 < 3)) {
        ehsys_memset(&D_000101A4 + (arg0 * 0xC), 0, 0xC);
    }
}

/* func_00002358 — 8 words. MATCH 100% (shape: m2c). */
u8 func_00002358(s32 arg0) {
    return *(&D_000101A4 + (arg0 * 0xC));
}

/* func_00002378 — 3 words. MATCH 100% (shape: m2c). */
u16 func_00002378(void) {
    return *(u16 *)0x15046;
}

/* func_00002384 — 2 words. MATCH 100% (shape: m2c). */
void func_00002384(void) {
    duel_eng_3865EBDA();
}

/* func_0000238C — 2 words. MATCH 100% (shape: m2c). */
void func_0000238C(void) {
    func_00002650();
}

/* func_00002394 — 2 words. MATCH 100% (shape: m2c). */
void func_00002394(void) {
    func_00002674();
}

/* func_00002650 — 9 words. MATCH 100% (shape: m2c). */
void func_00002650(void) {
    *(s32 *)0x1504C = duel_draw_6D200A3F();
}

/* func_00002674 — 3 words. MATCH 100% (shape: m2c). */
void func_00002674(void) {
    *(s32 *)0x1504C = 0;
}

/* func_00002680 — 4 words. MATCH 100% (shape: hand). */
void func_00002680(s32 arg0) {
    ehsys_41AABF28(*(s32 *)0x1504C, arg0);
}

/* func_00002690 — 4 words. MATCH 100% (shape: hand). K&R-style definition
 * so func_00005BA0's argument-less call below stays legal C: the target's
 * jal there has no $a0 setup at all. */
void func_00002690(arg0)
s32 arg0;
{
    ehsys_20E340D9(*(s32 *)0x1504C, arg0);
}

/* func_000026A0 — 3 words. MATCH 100% (shape: m2c). */
s32 func_000026A0(void) {
    return *(s32 *)0x1504C;
}

/* func_00002EA0 — 7 words. MATCH 100% (shape: hand). */
void func_00002EA0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    ehsys_3BB2BAC6(arg0 << 6, arg1 << 6, arg2 << 6, arg3 << 6, arg4, -1, 0);
}

/* func_00002EBC — 3 words. MATCH 100% (shape: m2c). */
s32 func_00002EBC(void) {
    return *(s32 *)0x151A8;
}

/* func_00002EC8 — 3 words. MATCH 100% (shape: m2c). */
void func_00002EC8(s32 arg0) {
    *(s32 *)0x151B8 = arg0;
}

/* func_00002EE8 — 3 words. MATCH 100% (shape: m2c). */
void func_00002EE8(s32 arg0) {
    *(s32 *)0x15148 = arg0;
}

/* func_00002F7C — 4 words. MATCH 100% (shape: m2c). */
void func_00002F7C(void) {
    *(s32 *)0x15058 = 1;
}

/* func_00002F8C — 4 words. MATCH 100% (shape: m2c). */
void func_00002F8C(void) {
    *(s32 *)0x15058 = 3;
}

/* func_00003054 — 13 words. MATCH 100% (shape: m2c). */
s32 func_00003054(void) {
    s32 temp_v1;

    temp_v1 = *(s32 *)0x15058;
    if ((temp_v1 != 3) && (temp_v1 != 1)) {
        return 0;
    }
    return 1;
}

/* func_00003688 — 9 words. MATCH 100% (shape: m2c). */
void func_00003688(void) {
    ehsys_06380DFA();
    ehsys_AB962AE7(0);
}

/* func_00003E6C — 2 words. MATCH 100% (shape: m2c). */
s32 func_00003E6C(s32 *arg0) {
    return *arg0;
}

/* func_00003E74 — address-of D_15A14. MATCH 100% (shape: hand). */
void *func_00003E74(void) {
    return &D_15A14;
}

/* func_00004680 — 11 words. MATCH 100% (shape: m2c). */
void func_00004680(void) {
    s16 temp_v1;

    temp_v1 = *(s16 *)0x151F8;
    if (temp_v1 >= 0) {
        func_00005170(temp_v1 & 0xFFFF);
    }
}

/* func_00004764 — 18 words. MATCH 100% (shape: m2c). */
s32 func_00004764(void) {
    if ((*(s32 *)0x15A10 == 1) && (ehsys_450CD6C5() == 1)) {
        return 1;
    }
    return 0;
}

/* func_00004BB0 — address-of D_15A40. MATCH 100% (shape: hand). */
void *func_00004BB0(void) {
    return &D_15A40;
}

/* func_00004BBC — address-of D_15A3C. MATCH 100% (shape: hand). */
void *func_00004BBC(void) {
    return &D_15A3C;
}

/* func_00004BC8 — address-of D_15A38. MATCH 100% (shape: hand). */
void *func_00004BC8(void) {
    return &D_15A38;
}

/* func_00004BD4 — address-of D_15A34. MATCH 100% (shape: hand). */
void *func_00004BD4(void) {
    return &D_15A34;
}

/* func_00004BE0 — address-of D_15A30. MATCH 100% (shape: hand). */
void *func_00004BE0(void) {
    return &D_15A30;
}

/* func_00004BEC — address-of D_15A2C. MATCH 100% (shape: hand). */
void *func_00004BEC(void) {
    return &D_15A2C;
}

/* func_00004E28 — address-of D_15A50. MATCH 100% (shape: hand). */
void *func_00004E28(void) {
    return &D_15A50;
}

/* func_00004F28 — 12 words. MATCH 100% (shape: m2c). */
void func_00004F28(void) {
    func_00005544(func_00004BE0());
    *(s16 *)0x151F8 = -1;
}

/* func_000051E4 — 2 words. MATCH 100% (shape: hand). */
void func_000051E4(s32 *arg0) {
    duel_draw_DB788046(*arg0);
}

/* func_00005224 — 2 words. MATCH 100% (shape: m2c). */
void func_00005224(s32 *arg0, s32 arg1) {
    *arg0 = arg1;
}

/* func_0000522C — 9 words. MATCH 100% (shape: m2c). */
void func_0000522C(void) {
    duel_draw_C7776D2B(0);
    duel_draw_4CDAED11(1);
}

/* func_00005250 — forwards duel_draw_239DFC05()'s result through
 * func_00005224 into *arg0, then returns arg0 unchanged.
 * MATCH 100% (shape: hand). */
extern s32 duel_draw_239DFC05(void);
s32 func_00005250(s32 *arg0) {
    func_00005224(arg0, duel_draw_239DFC05());
    return (s32)arg0;
}

/* func_000052F0 — stores arg1 through func_0000531C at arg0+0x10, returns
 * arg0+0x10. MATCH 100% (shape: hand). */
s32 func_000052F0(s32 arg0, s32 arg1) {
    func_0000531C((s32 *)(arg0 + 0x10), arg1);
    return arg0 + 0x10;
}

/* func_0000531C — 2 words. MATCH 100% (shape: m2c). */
void func_0000531C(s32 *arg0, s32 arg1) {
    *arg0 = arg1;
}

/* func_00005444 — 16 words. MATCH 100% (shape: m2c). */
s32 func_00005444(void) {
    if ((func_000014D8(8) == 0) && (func_000014D8(6) == 0)) {
        return 0;
    }
    return 1;
}

/* func_000054E8 — 2 words. MATCH 100% (shape: m2c). */
void func_000054E8(void) {

}

/* func_00005834 — 2 words. MATCH 100% (shape: hand). */
void func_00005834(void) {
    func_00002310(0);
}

/* func_0000583C — 2 words. MATCH 100% (shape: hand). */
void func_0000583C(void) {
    func_00002358(0);
}

/* func_00005844 — 2 words. MATCH 100% (shape: m2c). */
s32 func_00005844(void) {
    return 1;
}

/* func_0000584C — 2 words. MATCH 100% (shape: m2c). */
s32 func_0000584C(void) {
    return 1;
}

/* func_00005854 — 2 words. MATCH 100% (shape: m2c). */
s32 func_00005854(void) {
    return 0;
}

/* func_0000585C — 2 words. MATCH 100% (shape: hand). */
void func_0000585C(s32 arg0, s32 arg1) {
    duel_draw_D755977D(arg1);
}

/* func_00005970 — 2 words. MATCH 100% (shape: m2c). */
void func_00005970(void) {

}

/* func_00005A34 — 3 words. MATCH 100% (shape: hand). */
void func_00005A34(void) {
    func_00002690(*(s32 *)0x15A58);
}

/* func_00005A40 — 3 words. MATCH 100% (shape: hand). */
void func_00005A40(void *arg0) {
    ehsys_memset(arg0, 0, 0x84);
}

/* func_00005A4C — 8 words. MATCH 100% (shape: hand). */
s32 func_00005A4C(void *arg0, void *arg1) {
    ehsys_strncpy(arg0, arg1, 0x80);
    return 1;
}

/* func_00005A6C — 2 words. MATCH 100% (shape: m2c). */
s32 func_00005A6C(void) {
    return 1;
}

/* func_00005B18 — 2 words. MATCH 100% (shape: m2c). */
s32 func_00005B18(void) {
    return 0;
}

/* func_00005BA0 — tail-calls func_00002690 without setting up $a0 (target's
 * jal has no argument setup at all, relying on the K&R-style declaration of
 * func_00002690 above). MATCH 100% (shape: hand). */
void func_00005BA0(void) {
    func_00002690();
}

/* func_00005BA8 — 3 words. MATCH 100% (shape: hand). */
void func_00005BA8(void *arg0, s32 arg1) {
    ehsys_memset(arg0, 0, arg1);
}

/* func_00005BD4 — 9 words. MATCH 100% (shape: m2c). */
s32 func_00005BD4(void) {
    return duel_draw_048AF0E1() == 1;
}

/* func_00005BF8 — 2 words. MATCH 100% (shape: m2c). */
void func_00005BF8(void) {

}

/* func_00005E24 — 5 words. MATCH 100% (shape: hand). */
void func_00005E24(void) {
    ehsys_memset(&D_15A14, 0, 0x18);
}

/* func_00005F7C — 27 words. MATCH 100% (shape: m2c). */
void func_00005F7C(void) {
    if (duel_draw_C04933FF() == 0) {
        if ((ehsys_450CD6C5() == 1) && (func_00005BB4() & 8)) {
            func_000017D4();
            return;
        }
        func_000062DC();
        func_00000F4C();
    }
}

/* func_00005FE8 — 17 words. MATCH 100% (shape: m2c). */
void func_00005FE8(void) {
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = ehsys_DFCA450B(0xA, 0);
    sp1C = temp_v0;
    sp1C = ehsys_4175E3DB(temp_v0, 1);
    ehsys_878EE1D3(&sp1C);
    ehsys_1EC5342B(sp1C);
}

/* func_0000602C — 24 words. MATCH 100% (shape: m2c). */
s32 func_0000602C(void) {
    s32 var_s0;

    var_s0 = 0;
    if (func_00005E98() == 1) {
        var_s0 = 1;
    } else if (ehsys_450CD6C5() == 1) {
        func_00005F7C();
    }
    func_00005FE8();
    return var_s0;
}

/* func_000062B4 — 10 words. MATCH 100% (shape: m2c). */
void func_000062B4(s32 arg0) {
    s32 temp_a0;

    temp_a0 = arg0 & 0xFFFF;
    if (temp_a0 == 7) {
        duel_draw_6214421F(temp_a0);
    }
}

/* func_000062DC — chains func_00001B70 -> func_0000228C -> func_00001C30,
 * threading each result into the next call as its (unused, by
 * func_00001C30's body) argument. MATCH 100% (shape: hand). */
extern s32 func_00001B70(void);
extern s32 func_0000228C(s32);
void func_000062DC(void) {
    func_00001C30(func_0000228C(func_00001B70()));
}

/* func_00006308 — 2 words. MATCH 100% (shape: m2c). */
void func_00006308(void) {

}

/* func_00006310 — 2 words. MATCH 100% (shape: m2c). */
void func_00006310(void) {

}

/* func_000067B0 — 2 words. MATCH 100% (shape: m2c). */
s32 func_000067B0(void) {
    return 0;
}

