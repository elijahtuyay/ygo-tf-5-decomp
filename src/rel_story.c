/*
 * rel_story.prx — reconstructed code (matching decompilation)
 *
 * Compiler:     Metrowerks CodeWarrior for PSP — MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,s -sdatathreshold 0
 * Verification: scripts/mwcc_build.sh src/rel_story.c
 *               scripts/mwcc_diff.py asm/rel_story/text.s build/mwcc/rel_story.o
 *
 * Every function below is byte-identical to the shipped module — each was
 * accepted only on a MATCH verdict from scripts/mwcc_diff.py, and the whole
 * file is re-verified after assembly (scripts/assemble_module.py).
 * Functions are in ADDRESS ORDER, which is what the linker needs.
 *
 * Import names are resolved from the module's NID tables and are identical
 * across all 28 modules — see docs/nids/README.md.
 *
 * STATUS: 86 functions matched here. The rest of the module is not
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
extern char D_000200F4;
extern char D_00020108;
extern char D_0002011C;
extern char D_00020134;
extern char D_0002A5C0;
extern char D_00033A98;
extern char D_00034580;
extern int cardalbum_EE554159();
extern int conv_machine_0BB25540();
extern int deck_tutorial_4E16F5A6();
extern int duelrecord_6ADB95DB();
extern int ehsys_008B4553();
extern int ehsys_088F768A();
extern int ehsys_0A60B08B();
extern int ehsys_13A4081A();
extern int ehsys_2AE3C0AD();
extern int ehsys_81857D14();
extern int ehsys_9090346C();
extern int ehsys_92675210();
extern int ehsys_A84EDF3B();
extern int ehsys_B27BC15D();
extern int ehsys_B4471B5E();
extern int ehsys_C5D3B70C();
extern int ehsys_C859D5FE();
extern int ehsys_CCDAED90();
extern int ehsys_D9E726DC();
extern int ehsys_frame_sync();
extern int ehsys_memset();
extern int field_74B014A2();
extern int field_79E5F8B7();
extern int field_86220A06();
extern int field_E92DC2F2();
extern int field_FABFD3C6();
extern int func_00000038();
extern int func_00000248();
extern int func_0000025C();
extern int func_000002F8();
extern int func_00000384();
extern int func_00000398();
extern int func_00000AF8();
extern int func_00000B0C();
extern int func_00000DC8();
extern int func_00000DF4();
extern int func_00000E54();
extern int func_00001CE0();
extern int func_00002184();
extern int func_00002198();
extern int func_00002A3C();
extern int func_00003488();
extern int func_00003518();
extern int func_0000352C();
extern int func_00003C44();
extern int func_00003C58();
extern int func_00005954();
extern int func_00009B70();
extern int func_00009E94();
extern int func_00009FA0();
extern int func_00009FB4();
extern int func_0000A068();
extern int func_0000A6E8();
extern int func_0000A840();
extern int func_0000A930();
extern int func_0000AA80();
extern int func_0000AF78();
extern int func_0000B2DC();
extern int func_0000B2F0();
extern int func_0000B56C();
extern int func_0000B580();
extern int func_0000B5F8();
extern int func_0000B60C();
extern int func_0000B860();
extern int func_0000B874();
extern int func_0000B8A8();
extern int func_0000BA94();
extern int func_0000BABC();
extern int func_0000BAE4();
extern int func_0000BBD8();
extern int func_0000BD18();
extern int func_0000BD4C();
extern int func_0000BDE0();
extern int func_0000DDA8();
extern int func_0000EBA8();
extern int func_0000FFB8();
extern int func_00011634();
extern int func_0001167C();
extern int func_00011690();
extern int func_00011874();
extern int func_000118E0();
extern int func_00011998();
extern int func_00011C24();
extern int func_00011C38();
extern int func_00011D00();
extern int func_00011D20();
extern int func_00011F04();
extern int func_00012104();
extern int func_0001222C();
extern int func_00012238();
extern int func_00012358();
extern int func_00012368();
extern int func_000123A4();
extern int func_000123C4();
extern int func_00012408();
extern int func_00013B2C();
extern int func_00013CEC();
extern int func_00013D00();
extern int func_00014124();
extern int func_0001422C();
extern int func_0001432C();
extern int func_00014360();
extern int func_00015778();
extern int func_00015814();
extern int func_00015854();
extern int func_000159CC();
extern int limitlist_E69A45D2();
extern int password_932AE9C8();
extern int recipe_viewer_98E7E882();
extern int select_card_BF2B46D7();
extern int tutoriallist_41015B0F();

/* ---- forward declarations ---- */
s32 func_00000000(s32 arg0);
s32 func_0000261C(void);
s32 func_00003418(void);
s32 func_000068A4(void);
s32 func_000068E8(void);
s32 func_00009E1C(void);
void func_000000E8(void);
void func_0000018C(void);
void func_00000230(void);
void func_00000238(void);
void func_00000240(void);
void func_00001400(void);
void func_0000195C(void);
void func_00001E9C(void);
void func_00001EC0(void);
void func_000023EC(s32 arg0);
void func_00002844(void);
void func_0000284C(void);
void func_000068C8(void);
void func_00008CB4(void);
void func_00008CE0(void);
void func_00008EB4(void);
void func_00008F54(void);
void func_00008FE4(void);
void func_00009080(void);
void func_00009110(void);
void func_000092D8(void);
void func_0000939C(void);
void func_00009598(void);
void func_00009644(void);
void func_00009A30(void);
void func_00009B84(void);
void func_0000B0D0(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3);
void func_0000B5F0(void);
void func_0000B8C8(void);
void func_0000B8D0(void);
void func_0000BCE8(void);
void func_0000D438(void);
void func_0000D518(void);
void func_0000D544(void);
void func_0000DE2C(void);
void func_0000E150(void);
void func_0000E20C(void);
void func_0000E214(void);
void func_0000E284(void);
void func_0000E4E4(void);
void func_0000E6F4(void);
void func_0000E998(void);
void func_0000E9D4(void);
void func_0000EBA0(void);
void func_0000EC0C(void);
void func_0000EC14(void);
void func_0000EC1C(void);
void func_0000EC24(void);
void func_0000EC60(void);
void func_0000ED98(void);
void func_0000EF18(void);
void func_0000EF30(void);
void func_0000EF38(void);
void func_0000F6BC(void);
void func_0000F714(void);
void func_0000FA28(void);
void func_0000FA30(void);
void func_0000FBC0(void);
void func_0000FBC8(void);
void func_0000FBD0(void);
void func_0000FCC0(void);
void func_0000FCC8(void);
void func_0000FEA8(void);
void func_0000FEB0(void);
void func_00010028(void);
void func_0001005C(void);
void func_00010090(void);
void func_00010288(void);
void func_00010290(void);
void func_00010298(void);
void func_000116F0(void);
void func_00011714(void);
void func_00011774(void);
void func_00011C1C(void);
void func_000124C8(void);
void func_00013B94(s32 arg0, int arg1);
void func_0001411C(void);
void func_0001439C(void);
void func_00015804(void);
void func_0001580C(void);

/* func_00000000 — 14 words. MATCH 100% (shape: m2c). */
s32 func_00000000(s32 arg0) {
    if (arg0 == 0) {
        ehsys_B4471B5E(func_00000038, func_00000230, &D_0002A5C0);
    }
    return 0;
}

/* func_000000E8 — 41 words. MATCH 100% (shape: m2c). */
void func_000000E8(void) {
    func_00015814();
    func_00009B70();
    func_00003C44();
    func_00000AF8();
    func_0000B8C8();
    func_00002184();
    func_00011C24();
    func_0000BCE8();
    func_0000B2DC();
    func_0000B56C();
    func_00000384();
    func_00013CEC();
    func_00009FA0();
    func_0000B860();
    func_00003518();
    func_0000B5F8();
    func_00000248();
    func_0001167C();
}

/* func_0000018C — 41 words. MATCH 100% (shape: m2c). */
void func_0000018C(void) {
    func_0000B2F0();
    func_0000BD18();
    func_00011C38();
    func_00002198();
    func_0000B8D0();
    func_0000B580();
    func_00000398();
    func_00013D00();
    func_00009FB4();
    func_00003C58();
    func_00000B0C();
    func_0000B874();
    func_0000352C();
    func_0000B60C();
    func_0000025C();
    func_00011690();
    func_00009B84();
    func_00015854();
}

/* func_00000230 — 2 words. MATCH 100% (shape: m2c). */
void func_00000230(void) {

}

/* func_00000238 — 2 words. MATCH 100% (shape: m2c). */
void func_00000238(void) {
    func_00005954();
}

/* func_00000240 — 2 words. MATCH 100% (shape: m2c). */
void func_00000240(void) {

}

/* func_00001400 — 2 words. MATCH 100% (shape: m2c). */
void func_00001400(void) {

}

/* func_0000195C — 23 words. MATCH 100% (shape: m2c). */
void func_0000195C(void) {
    int sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;

    if (func_0000BBD8() != -1) {
        func_00001CE0(&sp1C, &sp18, &sp14, &sp10);
        func_00012408();
        func_0000BDE0(sp18, sp14, sp10);
        func_000123C4();
    }
}

/* func_00001E9C — 9 words. MATCH 100% (shape: m2c). */
void func_00001E9C(void) {
    func_0000B8A8(0);
    func_00011D00();
}

/* func_00001EC0 — 2 words. MATCH 100% (shape: m2c). */
void func_00001EC0(void) {

}

/* func_000023EC — 13 words. MATCH 100% (shape: m2c). */
void func_000023EC(s32 arg0) {
    ehsys_C5D3B70C(0, arg0, func_00002A3C());
}

/* func_0000261C — 8 words. MATCH 100% (shape: m2c). */
s32 func_0000261C(void) {
    return ehsys_B27BC15D() & 0xFFFF;
}

/* func_00002844 — 2 words. MATCH 100% (shape: m2c). */
void func_00002844(void) {
    ehsys_CCDAED90();
}

/* func_0000284C — 2 words. MATCH 100% (shape: m2c). */
void func_0000284C(void) {
    ehsys_81857D14();
}

/* func_00003418 — 8 words. MATCH 100% (shape: m2c). */
s32 func_00003418(void) {
    return func_00003488() + 4;
}

/* func_000068A4 — 9 words. MATCH 100% (shape: m2c). */
s32 func_000068A4(void) {
    int sp1C;

    return field_79E5F8B7(0x20, &sp1C) != 0;
}

/* func_000068C8 — 8 words. MATCH 100% (shape: m2c). */
void func_000068C8(void) {
    int sp1C;

    field_86220A06(0x21, &sp1C);
}

/* func_000068E8 — 9 words. MATCH 100% (shape: m2c). */
s32 func_000068E8(void) {
    int sp1C;

    return field_79E5F8B7(0x21, &sp1C) != 0;
}

/* func_00008CB4 — 11 words. MATCH 100% (shape: m2c). */
void func_00008CB4(void) {
    field_E92DC2F2();
    ehsys_frame_sync();
    ehsys_13A4081A(1);
}

/* func_00008CE0 — 9 words. MATCH 100% (shape: m2c). */
void func_00008CE0(void) {
    field_FABFD3C6();
    field_74B014A2();
}

/* func_00008EB4 — 12 words. MATCH 100% (shape: m2c). */
void func_00008EB4(void) {
    recipe_viewer_98E7E882(0, 0, 1, 1);
    ehsys_13A4081A(0);
}

/* func_00008F54 — 9 words. MATCH 100% (shape: m2c). */
void func_00008F54(void) {
    password_932AE9C8();
    ehsys_13A4081A(0);
}

/* func_00008FE4 — 12 words. MATCH 100% (shape: m2c). */
void func_00008FE4(void) {
    select_card_BF2B46D7(0, 0, 0, 0);
    ehsys_13A4081A(0);
}

/* func_00009080 — 9 words. MATCH 100% (shape: m2c). */
void func_00009080(void) {
    conv_machine_0BB25540();
    ehsys_13A4081A(0);
}

/* func_00009110 — 10 words. MATCH 100% (shape: m2c). */
void func_00009110(void) {
    cardalbum_EE554159(1, 0);
    ehsys_13A4081A(0);
}

/* func_000092D8 — 10 words. MATCH 100% (shape: m2c). */
void func_000092D8(void) {
    limitlist_E69A45D2(1, 0);
    ehsys_13A4081A(0);
}

/* func_0000939C — 12 words. MATCH 100% (shape: m2c). */
void func_0000939C(void) {
    tutoriallist_41015B0F(func_00000DC8(), 0);
    ehsys_13A4081A(0);
}

/* func_00009598 — 12 words. MATCH 100% (shape: m2c). */
void func_00009598(void) {
    deck_tutorial_4E16F5A6(func_00000DC8(), 0);
    ehsys_13A4081A(0);
}

/* func_00009644 — 9 words. MATCH 100% (shape: m2c). */
void func_00009644(void) {
    duelrecord_6ADB95DB(0);
    ehsys_13A4081A(0);
}

/* func_00009A30 — 16 words. MATCH 100% (shape: m2c). */
void func_00009A30(void) {
    func_00011874();
    func_00000E54(0, 1, 0, 0);
    ehsys_13A4081A(1);
    func_00000DF4(1);
}

/* func_00009B84 — 12 words. MATCH 100% (shape: m2c). */
void func_00009B84(void) {
    func_00009E94();
    ehsys_memset(&D_00033A98, 0, 0x14);
}

/* func_00009E1C — 30 words. MATCH 100% (shape: m2c). */
s32 func_00009E1C(void) {
    func_00012104(func_000159CC(2, &D_000200F4));
    func_0001222C(func_000159CC(2, &D_00020108));
    func_00012238(func_000159CC(2, &D_0002011C));
    func_00015778(func_000159CC(3, &D_00020134));
    return 1;
}

/* func_0000B0D0 — 26 words. MATCH 100% (shape: m2c). */
void func_0000B0D0(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3) {
    s32 sp1C;

    sp1C = arg0;
    if (arg1 <= 0) {
        *arg2 = arg0;
        *arg3 = func_00002A3C(sp1C);
        return;
    }
    if (ehsys_9090346C(arg1, &sp1C, arg3) != 0) {
        *arg2 = sp1C;
    }
}

/* func_0000B5F0 — 2 words. MATCH 100% (shape: m2c). */
void func_0000B5F0(void) {

}

/* func_0000B8C8 — 2 words. MATCH 100% (shape: m2c). */
void func_0000B8C8(void) {

}

/* func_0000B8D0 — 2 words. MATCH 100% (shape: m2c). */
void func_0000B8D0(void) {

}

/* func_0000BCE8 — 12 words. MATCH 100% (shape: m2c). */
void func_0000BCE8(void) {
    ehsys_memset(&D_00034580, 0, 0xA1C);
    func_0000BD4C();
}

/* func_0000D438 — 9 words. MATCH 100% (shape: m2c). */
void func_0000D438(void) {
    func_00014124();
    func_0001422C();
}

/* func_0000D518 — 11 words. MATCH 100% (shape: m2c). */
void func_0000D518(void) {
    if (func_0001432C() != 0) {
        func_00014360();
    }
}

/* func_0000D544 — 2 words. MATCH 100% (shape: m2c). */
void func_0000D544(void) {

}

/* func_0000DE2C — 2 words. MATCH 100% (shape: m2c). */
void func_0000DE2C(void) {
    func_0000DDA8();
}

/* func_0000E150 — 2 words. MATCH 100% (shape: m2c). */
void func_0000E150(void) {

}

/* func_0000E20C — 2 words. MATCH 100% (shape: m2c). */
void func_0000E20C(void) {

}

/* func_0000E214 — 2 words. MATCH 100% (shape: m2c). */
void func_0000E214(void) {

}

/* func_0000E284 — 2 words. MATCH 100% (shape: m2c). */
void func_0000E284(void) {

}

/* func_0000E4E4 — 2 words. MATCH 100% (shape: m2c). */
void func_0000E4E4(void) {

}

/* func_0000E6F4 — 2 words. MATCH 100% (shape: m2c). */
void func_0000E6F4(void) {

}

/* func_0000E998 — 15 words. MATCH 100% (shape: m2c). */
void func_0000E998(void) {
    s32 temp_v0;

    temp_v0 = func_0000BA94();
    if ((temp_v0 > 0) && (temp_v0 < 0x33)) {
        func_0000BAE4(temp_v0);
    }
}

/* func_0000E9D4 — 15 words. MATCH 100% (shape: m2c). */
void func_0000E9D4(void) {
    s32 temp_v0;

    temp_v0 = func_0000BABC();
    if ((temp_v0 > 0) && (temp_v0 < 0x33)) {
        func_0000BAE4(temp_v0);
    }
}

/* func_0000EBA0 — 2 words. MATCH 100% (shape: m2c). */
void func_0000EBA0(void) {

}

/* func_0000EC0C — 2 words. MATCH 100% (shape: m2c). */
void func_0000EC0C(void) {
    func_0000EBA8();
}

/* func_0000EC14 — 2 words. MATCH 100% (shape: m2c). */
void func_0000EC14(void) {

}

/* func_0000EC1C — 2 words. MATCH 100% (shape: m2c). */
void func_0000EC1C(void) {

}

/* func_0000EC24 — 15 words. MATCH 100% (shape: m2c). */
void func_0000EC24(void) {
    s32 temp_s0;

    func_00012368();
    temp_s0 = func_0000BBD8();
    ehsys_92675210(temp_s0, func_000123A4() & 0xFFFF);
}

/* func_0000EC60 — 2 words. MATCH 100% (shape: m2c). */
void func_0000EC60(void) {

}

/* func_0000ED98 — 2 words. MATCH 100% (shape: m2c). */
void func_0000ED98(void) {

}

/* func_0000EF18 — 2 words. MATCH 100% (shape: m2c). */
void func_0000EF18(void) {

}

/* func_0000EF30 — 2 words. MATCH 100% (shape: m2c). */
void func_0000EF30(void) {

}

/* func_0000EF38 — 2 words. MATCH 100% (shape: m2c). */
void func_0000EF38(void) {

}

/* func_0000F6BC — 22 words. MATCH 100% (shape: m2c). */
void func_0000F6BC(void) {
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = func_0000AF78();
    func_00013B2C(temp_v0, func_00002A3C(temp_v0), &sp1C);
    func_0000A068(temp_v0, sp1C);
    func_0000AA80(-1, -1, -1);
}

/* func_0000F714 — 31 words. MATCH 100% (shape: m2c). */
void func_0000F714(void) {
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = func_0000AF78();
    func_00013B2C(temp_v0, func_00002A3C(temp_v0), &sp1C);
    func_00011F04(0x1B, 1);
    func_0000A6E8(0, 0);
    func_0000A840(temp_v0, sp1C);
    func_0000A930(0, 0);
    func_0000AA80(-1, -1, -1);
}

/* func_0000FA28 — 2 words. MATCH 100% (shape: m2c). */
void func_0000FA28(void) {

}

/* func_0000FA30 — 2 words. MATCH 100% (shape: m2c). */
void func_0000FA30(void) {

}

/* func_0000FBC0 — 2 words. MATCH 100% (shape: m2c). */
void func_0000FBC0(void) {

}

/* func_0000FBC8 — 2 words. MATCH 100% (shape: m2c). */
void func_0000FBC8(void) {

}

/* func_0000FBD0 — 2 words. MATCH 100% (shape: m2c). */
void func_0000FBD0(void) {

}

/* func_0000FCC0 — 2 words. MATCH 100% (shape: m2c). */
void func_0000FCC0(void) {

}

/* func_0000FCC8 — 2 words. MATCH 100% (shape: m2c). */
void func_0000FCC8(void) {

}

/* func_0000FEA8 — 2 words. MATCH 100% (shape: m2c). */
void func_0000FEA8(void) {
    func_000118E0();
}

/* func_0000FEB0 — 2 words. MATCH 100% (shape: m2c). */
void func_0000FEB0(void) {
    func_00011998();
}

/* func_00010028 — 2 words. MATCH 100% (shape: m2c). */
void func_00010028(void) {
    func_0000FFB8();
}

/* func_0001005C — 2 words. MATCH 100% (shape: m2c). */
void func_0001005C(void) {

}

/* func_00010090 — 2 words. MATCH 100% (shape: m2c). */
void func_00010090(void) {

}

/* func_00010288 — 2 words. MATCH 100% (shape: m2c). */
void func_00010288(void) {

}

/* func_00010290 — 2 words. MATCH 100% (shape: m2c). */
void func_00010290(void) {

}

/* func_00010298 — 2 words. MATCH 100% (shape: m2c). */
void func_00010298(void) {

}

/* func_000116F0 — 9 words. MATCH 100% (shape: m2c). */
void func_000116F0(void) {
    ehsys_C859D5FE(0x2B7E);
    ehsys_C859D5FE(0x2B81);
}

/* func_00011714 — 2 words. MATCH 100% (shape: m2c). */
void func_00011714(void) {
    ehsys_2AE3C0AD();
}

/* func_00011774 — 2 words. MATCH 100% (shape: m2c). */
void func_00011774(void) {
    ehsys_088F768A();
}

/* func_00011C1C — 2 words. MATCH 100% (shape: m2c). */
void func_00011C1C(void) {
    ehsys_A84EDF3B();
}

/* func_000124C8 — 2 words. MATCH 100% (shape: m2c). */
void func_000124C8(void) {

}

/* func_00013B94 — 20 words. MATCH 100% (shape: m2c). */
void func_00013B94(s32 arg0, int arg1) {
    if (ehsys_0A60B08B() != 0) {
        ehsys_008B4553(arg0, arg1);
        ehsys_D9E726DC(arg0, arg1);
    }
}

/* func_0001411C — 2 words. MATCH 100% (shape: m2c). */
void func_0001411C(void) {
    func_00014124();
}

/* func_0001439C — 19 words. MATCH 100% (shape: m2c). */
void func_0001439C(void) {
    if (func_0001432C() != 0) {
        func_00014360();
    }
    if (func_00011634() == 0) {
        func_0001422C();
        func_000002F8();
    }
}

/* func_00015804 — 2 words. MATCH 100% (shape: m2c). */
void func_00015804(void) {
    func_00012358();
}

/* func_0001580C — 2 words. MATCH 100% (shape: m2c). */
void func_0001580C(void) {
    func_00011D20();
}

