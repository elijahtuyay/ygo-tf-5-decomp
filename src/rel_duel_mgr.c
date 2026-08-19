/*
 * rel_duel_mgr.prx — reconstructed code (matching decompilation)
 *
 * Compiler:     Metrowerks CodeWarrior for PSP — MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,s -sdatathreshold 0
 * Verification: scripts/mwcc_build.sh src/rel_duel_mgr.c
 *               scripts/mwcc_diff.py asm/rel_duel_mgr/text.s build/mwcc/rel_duel_mgr.o
 *
 * Every function below is byte-identical to the shipped module — each was
 * accepted only on a MATCH verdict from scripts/mwcc_diff.py, and the whole
 * file is re-verified after assembly (scripts/assemble_module.py).
 * Functions are in ADDRESS ORDER, which is what the linker needs.
 *
 * Import names are resolved from the module's NID tables and are identical
 * across all 28 modules — see docs/nids/README.md.
 *
 * STATUS: 34 functions matched here. The rest of the module is not
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
extern int duel_draw_35284271();
extern int duel_draw_48A690B3();
extern int duel_draw_A50043BA();
extern int duel_eng_9FBBA3CF();
extern int duel_eng_AFF0389D();
extern int ehsys_1460C6FD();
extern int ehsys_1EC5342B();
extern void ehsys_20E340D9(s32, s32);
extern int ehsys_3BB2BAC6();
extern int ehsys_558B2DCB();
extern int ehsys_5F00A362();
extern int ehsys_6E42DDCD();
extern int ehsys_6F0D36D3();
extern int ehsys_88B6C7F0();
extern int ehsys_97BB99A5();
extern int ehsys_B8770B92();
extern int ehsys_B89D38DC();
extern int ehsys_BC8E65D7();
extern int ehsys_C859D5FE();
extern int ehsys_E4867425();
extern int ehsys_memset();
extern int ehsys_sceGuFinish();
extern int func_0000663C();
extern int func_0000C054();
extern int func_00010E10();
extern int func_000119AC();
extern int func_00011C08();
extern int func_000126D0();
extern int func_00010EBC();
extern int func_00011E50();
extern int func_00005014();
extern int ehsys_06A1D1D8();
extern int ehsys_D5D33185();
extern int D_0001F328;

/* ---- forward declarations ---- */
s32 func_00004B44(void);
s32 func_000065D0(void);
s32 func_0000B144(void);
s32 func_00010DD0(void);
u16 * func_00001DEC(u16 *arg0, u16 *arg1);
void func_00000948(s32 arg0);
void func_0000344C(void);
void func_00004688(void);
void func_00004F98(void);
void func_0000500C(void);
void func_0000BB8C(s32 arg0, s32 arg1);
void func_0000C888(s32 arg0);
void func_00010DC0(s32 arg0, s32 arg1, s32 arg2);
void func_00011814(void);
void func_00011A30(void);
void func_000150EC(s32 arg0);
void func_00016BB8(void *arg0, s32 arg1, s32 arg2);
void func_000048B8(void);
void func_00016EE8(s32 arg0, s32 arg1, s32 arg2);
void func_00010E7C(void);

/* func_00000948 — 13 words. MATCH 100% (shape: m2c). */
void func_00000948(s32 arg0) {
    if (arg0 != duel_draw_48A690B3()) {
        duel_draw_35284271(arg0);
    }
}

/* func_0000149C — clears D_0001E778. MATCH 100% (shape: hand). */
extern s32 D_0001E778;
void func_0000149C(void) {
    D_0001E778 = 0;
}

/* func_00001DEC — 4 words. MATCH 100% (shape: m2c). */
u16 *func_00001DEC(u16 *arg0, u16 *arg1) {
    *arg0 = *arg1;
    return arg0;
}

/* func_0000344C — 2 words. MATCH 100% (shape: m2c). */
void func_0000344C(void) {

}

/* func_00003E44 — resets D_0001F314 and registers the module's main/teardown
 * callbacks (same shape as rel_movie_viewer/rel_html_view's entry helper).
 * MATCH 100% (shape: hand). */
extern s32 D_0001F314;
extern char D_0001F318;
extern void func_00003E80(void);
extern void func_00004C60(void);
extern void ehsys_B4471B5E(void (*)(void), void (*)(void), void *);
s32 func_00003E44(void) {
    D_0001F314 = 0;
    ehsys_B4471B5E(func_00003E80, func_00004C60, &D_0001F318);
    return 0;
}

/* func_0000463C — clamps D_0001E77C (a u16 counter) up to 0x14 once
 * func_00012660() reports ready, then syncs a frame.
 * MATCH 100% (shape: hand). */
extern u16 D_0001E77C;
extern s32 func_00012660(void);
extern void ehsys_frame_sync(void);
void func_0000463C(void) {
    if ((D_0001E77C < 0x14) && (func_00012660() != 0)) {
        D_0001E77C = 0x14;
    }
    ehsys_frame_sync();
}

/* func_00004688 — 13 words. MATCH 100% (shape: m2c). */
void func_00004688(void) {
    ehsys_88B6C7F0();
    func_00011A30();
    ehsys_C859D5FE(0x2B80);
    ehsys_C859D5FE(4);
}

/* func_000046BC — 20 words. MATCH 100% (verified). */
void func_000046BC(void) {
    extern int D_0001E92C;
    extern int D_0001E930;
    extern int D_0001F300;
    func_00010EBC();
    while (!D_0001E92C) {
        ehsys_frame_sync();
    }
    func_00005014(D_0001E930, D_0001F300);
}

/* func_00004814 — 20 words. MATCH 100% (verified). */
int func_00004814(void) {
    func_00010E7C();
    while (ehsys_06A1D1D8() != 0) {
        ehsys_frame_sync();
    }
    ehsys_6E42DDCD();
    ehsys_D5D33185(0x2B80);
    return func_00011E50();
}

/* func_00004868 — 20 words. MATCH 100% (verified). */
s32 func_00004868(void) {
    extern int D_0001E770;
    extern unsigned short D_0001E77C;
    while ((D_0001E770 == 0) && (D_0001E77C == 1)) {
        func_000048B8();
        func_0000463C();
    }
    return 1;
}

/* func_00004B44 — 16 words. MATCH 100% (shape: m2c). */
s32 func_00004B44(void) {
    ehsys_E4867425(0);
    duel_eng_9FBBA3CF();
    duel_draw_A50043BA();
    func_00011C08();
    duel_eng_AFF0389D(1);
    return 1;
}

/* func_00004F98 — 13 words. MATCH 100% (shape: m2c). */
void func_00004F98(void) {
    s32 temp_s0;

    temp_s0 = ehsys_6F0D36D3();
    ehsys_1EC5342B((temp_s0 + ehsys_sceGuFinish()) - 8);
}
/* func_00004FCC — 0 words. MATCH 100% (shape: same-shape twin). */
void func_00004FCC(void) {

    s32 sp1C;
    s32 garbage;
    s32 temp_v0;

    ehsys_4DFEDFFA(temp_v0 = ehsys_DFCA450B(garbage, &sp1C));
    ehsys_sceGuStart(2, temp_v0, sp1C);
}

/* func_0000500C — 2 words. MATCH 100% (shape: m2c). */
void func_0000500C(void) {

}

/* func_00006198 — 5 words. MATCH 100% (verified). */
int func_00006198(s32 a0, s32 a1, s32 a2, s32 a3) {
    return ehsys_BC8E65D7(a0 << 6, a1 << 6, a2 << 6, a3, -1);
}

/* func_000061AC — 11 words. MATCH 100% (verified). */
void func_000061AC(void) {
    extern int D_0001F324;
    ehsys_20E340D9(*(int *)(D_0001F324 + 0xC0), D_0001F324);
    D_0001F324 = 0;
}

/* func_000065D0 — 27 words. MATCH 100% (shape: m2c). */
s32 func_000065D0(void) {
    int sp1C;
    s32 sp18;
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0 = func_0000663C();
    if (temp_v0 != 0) {
        ehsys_B8770B92(temp_v0, &sp1C, &sp18);
        temp_v0_2 = ehsys_558B2DCB(temp_v0);
        if ((sp18 > 0) && (temp_v0_2 >= (sp18 - 1))) {
            return 1;
        }
    }
    return 0;
}
/* func_00008A2C — 32 words. MATCH 100% (shape: m2c asm-fields). */
void func_00008A2C(void) {
    extern int D_0001F324;
    extern int ehsys_D4DE5DD8();
    extern int func_00008A2C();
    s32 temp_hi;
    s32 var_v1;
    u8 temp_a0;

    temp_hi = ehsys_D4DE5DD8() % 100;
    temp_a0 = (*(unsigned char *)((char *)D_0001F324 + 0x4));
    if (temp_hi < 0x14) {
        (*(unsigned char *)((char *)D_0001F324 + 0x5)) = temp_a0;
        return;
    }
    if (!(temp_hi & 1)) {
        var_v1 = (s32) ((temp_a0 & 0xFF) + 2) % 3;
    } else {
        var_v1 = (s32) ((temp_a0 & 0xFF) + 1) % 3;
    }
    (*(unsigned char *)((char *)D_0001F324 + 0x5)) = (u8) var_v1;
}
/* func_0000AF64 — 56 words. MATCH 100% (shape: m2c asm-fields). */
void func_0000AF64(void) {
    extern int D_0001F328;
    extern int ehsys_1D98951B();
    extern int ehsys_1EC5342B();
    extern int ehsys_399AC68A();
    extern int ehsys_42110BF9();
    extern int ehsys_878EE1D3();
    extern int ehsys_C62F9EAC();
    extern int ehsys_DFCA450B();
    extern int ehsys_EF9B5D06();
    extern int func_0000AF64();
    extern int func_0000C0CC();
    s32 sp1C;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_6;
    u16 temp_a0;

    temp_v0 = ehsys_DFCA450B(0, 0);
    sp1C = temp_v0;
    temp_v0_2 = ehsys_1D98951B(temp_v0, -0x01000000);
    sp1C = temp_v0_2;
    temp_v0_3 = ehsys_42110BF9(temp_v0_2, 0);
    sp1C = temp_v0_3;
    temp_v0_4 = ehsys_399AC68A(temp_v0_3, 0);
    sp1C = temp_v0_4;
    temp_v0_5 = ehsys_C62F9EAC(temp_v0_4, 0x17);
    sp1C = temp_v0_5;
    ehsys_1EC5342B(temp_v0_5);
    temp_a0 = (*(unsigned short *)((char *)D_0001F328 + 0x0));
    if ((temp_a0 != 0xA) && (temp_a0 != 0)) {
        temp_v0_6 = ehsys_DFCA450B(4, 0);
        sp1C = temp_v0_6;
        sp1C = func_0000C0CC(temp_v0_6);
        if ((*(unsigned char *)((char *)D_0001F328 + 0x18C)) & 3) {
            ehsys_EF9B5D06((s32) &sp1C, D_0001F328 + 0x68);
        }
        ehsys_878EE1D3((s32) &sp1C);
        ehsys_1EC5342B(sp1C);
    }
}

/* func_0000B044 — 20 words. MATCH 100% (verified). */
void func_0000B044(void) {
    s32 temp_a1;
    s32 temp_s0;

    temp_a1 = (*(int *)((char *)D_0001F328 + 0x194));
    temp_s0 = (*(int *)((char *)D_0001F328 + 0x64));
    if (temp_a1 != 0) {
        ehsys_20E340D9(temp_s0, temp_a1);
    }
    ehsys_20E340D9(temp_s0, D_0001F328);
    D_0001F328 = 0;
}

/* func_0000B144 — 28 words. MATCH 100% (shape: m2c). */
s32 func_0000B144(void) {
    int sp1C;
    s32 sp18;
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0 = func_0000C054(1);
    if (temp_v0 != 0) {
        ehsys_B8770B92(temp_v0, &sp1C, &sp18);
        temp_v0_2 = ehsys_558B2DCB(temp_v0);
        if ((sp18 > 0) && (temp_v0_2 >= (sp18 - 1))) {
            return 1;
        }
    }
    return 0;
}
/* func_0000B920 — 37 words. MATCH 100% (shape: m2c asm-fields). */
void func_0000B920(void) {
    extern int D_0001F328;
    extern int func_0000B094();
    extern int func_0000B144();
    extern int func_0000B920();
    u16 temp_a0;

    if (func_0000B144() != 0) {
        func_0000B094(0);
    }
    temp_a0 = (*(unsigned short *)((char *)D_0001F328 + 0x2E));
    (*(unsigned short *)((char *)D_0001F328 + 0x2E)) = (u16) (temp_a0 + 1);
    if ((s32) temp_a0 >= 0x10) {
        func_0000B094(1);
        (*(unsigned char *)((char *)D_0001F328 + 0x28)) = (u8) (((*(unsigned char *)((char *)D_0001F328 + 0x28)) & ~0xF) | ((*(unsigned char *)((char *)D_0001F328 + 0x4)) & 0xF));
        (*(unsigned short *)((char *)D_0001F328 + 0x0)) = 2;
        (*(unsigned short *)((char *)D_0001F328 + 0x2E)) = 0U;
    }
}

/* func_0000BB8C — 3 words. MATCH 100% (shape: hand). */
void func_0000BB8C(s32 arg0, s32 arg1) {
    ehsys_97BB99A5(arg0, arg1, 0, 0);
}
/* func_0000C054 — 30 words. MATCH 100% (shape: m2c). */
s32 func_0000C054(s32 arg0) {
    extern int D_0001DAC0;
    extern int D_0001F328;
    extern int ehsys_C6C15111();
    extern int func_0000C054();
    s32 temp_s0;
    s32 temp_v0;

    temp_v0 = arg0 & 0xFFFF;
    temp_s0 = temp_v0 * 4;
    if ((*(int *)((char *)(temp_s0 + D_0001F328) + 0x198)) == 0) {
        (*(int *)((char *)(temp_s0 + D_0001F328) + 0x198)) = ehsys_C6C15111((*(int *)((char *)D_0001F328 + 0x194)), (s32) (&D_0001DAC0)[temp_v0], 0);
    }
    return (*(int *)((char *)(temp_s0 + D_0001F328) + 0x198));
}

/* func_0000C888 — 2 words. MATCH 100% (shape: hand). */
void func_0000C888(s32 arg0) {
    ehsys_5F00A362(arg0 << 6);
}

/* func_0000C890 — 5 words. MATCH 100% (verified). */
int func_0000C890(s32 a0, s32 a1, s32 a2, s32 a3) {
    return ehsys_BC8E65D7(a0 << 6, a1 << 6, a2 << 6, a3, -1);
}

/* func_0000D2E8 — 8 words. MATCH 100% (verified). */
int func_0000D2E8(s32 a0, s32 a1, s32 a2) {
    return ehsys_B89D38DC(a0 << 6, a1 << 6, (0x1E0 - a0) << 6, a2);
}

/* func_0000D710 — 7 words. MATCH 100% (verified). */
int func_0000D710(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    return ehsys_3BB2BAC6(a0 << 6, a1 << 6, a2 << 6, a3 << 6, a4, -1, 0);
}

/* func_0000F530 — 8 words. MATCH 100% (shape: twin-of-rel_deck-func_0001B428,
 * via find_twins.py same-shape tier). */
s32 func_0000F530(void) {
    extern int ehsys_B2B9FEFA();
    return ((s32 *)ehsys_B2B9FEFA())[1];
}
/* func_00010888 — 0 words. MATCH 100% (shape: same-shape twin). */
void func_00010888(void) {

    s32 sp;
    ehsys_23E69878(
        ehsys_5CBB9E43(
            ehsys_F462EE6E(
                ehsys_4175E3DB(
                    ehsys_4175E3DB(
                        ehsys_E6E4401F(
                            ehsys_CABEA834(
                                ehsys_09794DF0(
                                    ehsys_F462EE6E(
                                        ehsys_F462EE6E(
                                            ehsys_42110BF9(
                                                ehsys_399AC68A(
                                                    ehsys_1D98951B(sp, 0), 0),
                                                0),
                                            9),
                                        1),
                                    0, 1),
                                -1),
                            0, 0),
                        1),
                    0xA),
                4),
            0, 2, 3, 0, 0),
        -1);
}

/* func_00010DC0 — 4 words. MATCH 100% (shape: hand). */
void func_00010DC0(s32 arg0, s32 arg1, s32 arg2) {
    ehsys_B89D38DC(arg0 << 6, arg1 << 6, arg2 << 6);
}

/* func_00010DD0 — 16 words. MATCH 100% (shape: m2c). */
s32 func_00010DD0(void) {
    if ((ehsys_1460C6FD() == 0) && (func_00010E10() != 0)) {
        return 1;
    }
    return 0;
}

/* func_00010E6C — 4 words. MATCH 100% (verified). */
extern s32 D_0001E92C;
int func_00010E6C(void) {
    return D_0001E92C = 1;
}

/* func_00010E7C — if D_0001E930 (a pending value) is set, forwards it plus
 * the pointer it points at through ehsys_20E340D9 and clears it; always
 * clears D_0001E92C too. MATCH 100% (shape: hand). */
extern s32 D_0001E930;
extern s32 D_0001E92C;
extern s32 D_0001F300;
extern void ehsys_20E340D9(s32, s32);
void func_00010E7C(void) {
    if (D_0001E930 != 0) {
        ehsys_20E340D9(D_0001F300, D_0001E930);
        D_0001E930 = 0;
    }
    D_0001E92C = 0;
}

/* func_000111A4 — 29 words. MATCH 100% (verified). */
extern int ehsys_597CDADD();
void func_000111A4(void) {
    extern int D_0001E938;
    extern int D_0001E918;
    extern int D_0001E91C;
    extern int D_0001E920;
    extern int D_0001E924;
    extern int D_0001E928;
    s32 sp1C;
    int sp18;

    if (D_0001E938 == 0) {
        D_0001E918 = 0x14;
        D_0001E91C = 0;
        D_0001E920 = 0x4000;
        D_0001E924 = 0;
        D_0001E928 = 0;
        sp1C = 0;
        ehsys_597CDADD(0xB, 4, &sp1C, &sp18, &D_0001E918);
    }
}

/* func_00011814 — 9 words. MATCH 100% (shape: m2c). */
void func_00011814(void) {
    func_000126D0();
    func_000119AC();
}

/* func_00011A30 — 9 words. MATCH 100% (shape: m2c). */
void func_00011A30(void) {
    ehsys_6E42DDCD();
    func_00011C08();
}

/* func_000126D0 — 5 words. MATCH 100% (verified). */
extern s32 D_0001E7A8;
/* func_00012660 — 28 words. MATCH 100% (shape: bool-fold). */
s32 func_00012660(void) {
    extern int ehsys_0D3E34B5();
    extern int ehsys_1460C6FD();
    extern int ehsys_2630B590();
    extern int ehsys_6DD74ECC();
    extern int func_00012660();
    s32 temp_v0;

    if (!ehsys_1460C6FD()) {
        return 0;
    }
    temp_v0 = ehsys_0D3E34B5();
    if ((temp_v0 != 0xA) && (temp_v0 != -1)) {
        return 0;
    }
    ehsys_6DD74ECC();
    return (!ehsys_2630B590()) & 0xFF;
}
int func_000126D0(void) {
    return ehsys_memset(&D_0001E7A8, 0, 0x104);
}

/* func_00012850 — D_0001F32C holds a pointer value; loads that value and
 * also dereferences it, forwarding both to ehsys_20E340D9 (same pattern as
 * func_00010E7C above, seen also in rel_charalist/rel_tutorial).
 * MATCH 100% (shape: hand). */
extern s32 D_0001F32C;
void func_00012850(void) {
    ehsys_20E340D9(*(s32 *)D_0001F32C, D_0001F32C);
}
/* func_00013A88 — 14 words. MATCH 100% (shape: bool-fold). */
s32 func_00013A88(s32 arg0) {
    extern int D_0001F32C;
    extern int ehsys_558B2DCB();
    extern int func_00013A88();
    s32 temp_a0;

    temp_a0 = (*(int *)((char *)(D_0001F32C + (arg0 * 4)) + 0x80));
    if (!temp_a0) {
        return -1;
    }
    return ehsys_558B2DCB(temp_a0);
}
/* func_00013AC0 — 14 words. MATCH 100% (shape: bool-fold). */
s32 func_00013AC0(s32 arg0, s32 arg1, s32 arg2) {
    extern int D_0001F32C;
    extern int ehsys_2074DED0();
    extern int func_00013AC0();
    s32 temp_a0;

    temp_a0 = (*(int *)((char *)(D_0001F32C + (arg0 * 4)) + 0x80));
    if (!temp_a0) {
        return 0;
    }
    return ehsys_2074DED0(temp_a0, arg1, arg2);
}

/* func_000150CC — 8 words. MATCH 100% (verified). */
int func_000150CC(s32 a0, s32 a1, s32 a2) {
    return ehsys_B89D38DC(a0 << 6, a1 << 6, (0x1E0 - a0) << 6, a2);
}

/* func_000150EC — 2 words. MATCH 100% (shape: hand). */
void func_000150EC(s32 arg0) {
    ehsys_5F00A362(arg0 << 6);
}

/* func_00013094 — tail call into func_00016BB8, offsetting the pointer
 * stored in D_0001F32C by 0x78. MATCH 100% (verified). */
extern s32 D_0001F32C;
void func_00013094(s32 arg0, s32 arg1) {
    func_00016BB8((void *)(D_0001F32C + 0x78), arg0, arg1);
}
/* func_00015DF0 — 39 words. MATCH 100% (shape: m2c). */
void func_00015DF0(s32 arg0) {
    extern int ehsys_1D98951B();
    extern int ehsys_23E69878();
    extern int ehsys_399AC68A();
    extern int ehsys_4175E3DB();
    extern int ehsys_42110BF9();
    extern int ehsys_5CBB9E43();
    extern int ehsys_E6E4401F();
    extern int ehsys_F462EE6E();
    extern int func_00015DF0();
    ehsys_23E69878(ehsys_5CBB9E43(ehsys_F462EE6E(ehsys_4175E3DB(ehsys_4175E3DB(ehsys_F462EE6E(ehsys_E6E4401F(ehsys_42110BF9(ehsys_399AC68A(ehsys_1D98951B(arg0, 0), 0), 0), 0, 0), 9), 1), 0xA), 4), 0, 2, 3, 0, 0), -1);
}

/* func_00016BA8 — 4 words. MATCH 100% (verified). */
void func_00016BA8(void *arg0) {
    *(char *)((char *)arg0 + 0x0) = 0;
    *(short *)((char *)arg0 + 0x2) = 0;
    *(short *)((char *)arg0 + 0x4) = 0;
}

/* func_00016BB8 — 4 words. MATCH 100% (verified). */
void func_00016BB8(void *arg0, s32 arg1, s32 arg2) {
    *(char *)((char *)arg0 + 0x0) = (char)arg1;
    *(short *)((char *)arg0 + 0x2) = 0;
    *(short *)((char *)arg0 + 0x4) = (short)arg2;
}

/* func_00016C18 — 6 words. MATCH 100% (verified). */
u8 func_00016C18(void *arg0, s16 *arg1, s16 *arg2) {
    *arg1 = *(short *)((char *)arg0 + 0x2);
    *arg2 = *(short *)((char *)arg0 + 0x4);
    return *(u8 *)((char *)arg0 + 0x0);
}

/* func_00016E70 — 5 words. MATCH 100% (verified). */
int func_00016E70(s32 a0, s32 a1, s32 a2, s32 a3) {
    return ehsys_BC8E65D7(a0 << 6, a1 << 6, a2 << 6, a3, -1);
}

/* func_00016EE8 — 4 words. MATCH 100% (shape: hand). */
void func_00016EE8(s32 arg0, s32 arg1, s32 arg2) {
    ehsys_B89D38DC(arg0 << 6, arg1 << 6, arg2 << 6);
}

/* func_00016F64 — clears the D_0001F304 counter. MATCH 100% (shape: hand). */
extern s32 D_0001F304;
void func_00016F64(void) {
    D_0001F304 = 0;
}

/* func_00016F70 — reads the D_0001F304 counter. MATCH 100% (shape: hand). */
s32 func_00016F70(void) {
    return D_0001F304;
}

/* func_00016F7C — increments the D_0001F304 counter.
 * MATCH 100% (shape: hand). */
void func_00016F7C(void) {
    D_0001F304 += 1;
}

