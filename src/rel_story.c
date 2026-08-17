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
 * STATUS: 126 functions matched here. The rest of the module is not
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
extern char D_0002A5C0;
extern char D_0002A5D0;
extern char D_0002A654;
extern char D_0002A658;
extern char D_0002A65C;
extern char D_0002A660;
extern char D_0002F134;
extern char D_0002F13C;
extern char D_00033A98;
extern char D_00033ACC;
extern char D_00033BA0;
extern char D_00033BA3;
extern char D_00034398;
extern char D_0003439C;
extern char D_00034470;
extern char D_00034484;
extern char D_00034488;
extern char D_00034490;
extern char D_00034494;
extern char D_000344A4;
extern char D_00034560;
extern char D_00034574;
extern char D_00034578;
extern char D_0003457C;
extern char D_00034580;
extern char D_00034584;
extern char D_0003458C;
extern char D_00034590;
extern char D_00034594;
extern char D_00034F98;
extern char D_00034F9C;
extern char D_00034FA4;
extern char D_00034FA8;
extern char D_00034FAC;
extern char D_00034FC0;
extern char D_00034FC4;
extern char D_00034FC8;
extern char D_00034FCC;
extern char D_00034FD0;
extern char D_00034FD4;
extern char D_000351FC;
extern char D_00035200;
extern char D_00035204;
extern char D_00035230;
extern int cardalbum_EE554159();
extern int conv_machine_0BB25540();
extern int deck_tutorial_4E16F5A6();
extern int duelrecord_6ADB95DB();
extern int ehsys_008B4553();
extern int ehsys_088F768A();
extern int ehsys_0A60B08B();
extern int ehsys_13A4081A();
extern int ehsys_1856E536();
extern int ehsys_2AE3C0AD();
extern int ehsys_81857D14();
extern int ehsys_92675210();
extern int ehsys_A84EDF3B();
extern int ehsys_B27BC15D();
extern int ehsys_B4471B5E();
extern int ehsys_C5D3B70C();
extern int ehsys_C859D5FE();
extern int ehsys_CCDAED90();
extern int ehsys_D9E726DC();
extern int ehsys_F11F0D9A();
extern int ehsys_frame_sync();
extern int ehsys_memset();
extern int field_74B014A2();
extern int field_79E5F8B7();
extern int field_86220A06();
extern int field_E92DC2F2();
extern int field_FABFD3C6();
extern int func_00000038();
extern int func_000002F8();
extern int func_00000DC8();
extern int func_00000DF4();
extern int func_00000E54();
extern int func_00001CE0();
extern int func_00002A3C();
extern int func_00003488();
extern int func_00005954();
extern int func_0000690C();
extern int func_00009E94();
extern int func_0000A068();
extern int func_0000AA80();
extern int func_0000AF78();
extern int func_0000B498();
extern int func_0000B8A8();
extern int func_0000BA94();
extern int func_0000BABC();
extern int func_0000BAE4();
extern int func_0000BBD8();
extern int func_0000BDE0();
extern int func_0000DDA8();
extern int func_0000EBA8();
extern int func_0000FFB8();
extern int func_00011874();
extern int func_000118E0();
extern int func_00011998();
extern int func_00011D00();
extern int func_00011D20();
extern int func_00012358();
extern int func_00012368();
extern int func_000123A4();
extern int func_000123C4();
extern int func_00012408();
extern int func_00013B2C();
extern int func_00014124();
extern int func_0001422C();
extern int func_0001432C();
extern int func_00014360();
extern int func_00015A38();
extern int func_00015AE4();
extern int limitlist_E69A45D2();
extern int password_932AE9C8();
extern int recipe_viewer_98E7E882();
extern int select_card_BF2B46D7();
extern int tutoriallist_41015B0F();

/* ---- forward declarations ---- */
s32 func_00000000(s32 arg0);
s32 func_00000DE4(void);
s32 func_0000261C(void);
s32 func_00003418(void);
s32 func_00005948(void);
s32 func_000068A4(void);
s32 func_000068E8(void);
s32 func_0000B560(void);
s32 func_0000C550(void);
s32 func_00011634(void);
s32 func_00013A38(s32 arg0, int arg1);
s32 func_00013CE0(void);
s32 func_00015890(void);
void func_00000230(void);
void func_00000238(void);
void func_00000240(void);
void func_000003AC(s32 arg0);
void func_000003CC(s32 arg0);
void func_00000B20(s32 arg0);
void func_00000DD8(s32 arg0);
void func_00000F4C(s32 arg0);
void func_00001400(void);
void func_0000195C(void);
void func_00001E9C(void);
void func_00001EC0(void);
void func_000023EC(s32 arg0);
void func_00002844(void);
void func_0000284C(void);
void func_000068C8(void);
void func_00006B80(void);
void func_00006E60(void);
void func_00008B10(void);
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
void func_00009FC8(s32 arg0);
void func_0000AA98(s32 arg0);
void func_0000AE34(void);
void func_0000B2A0(s32 arg0);
void func_0000B304(s32 arg0);
void func_0000B324(s32 arg0);
void func_0000B3CC(s32 arg0);
void func_0000B454(s32 arg0);
void func_0000B5F0(void);
void func_0000B77C(void);
void func_0000B888(s32 arg0);
void func_0000B8C8(void);
void func_0000B8D0(void);
void func_0000B8D8(s32 arg0, s32 arg1);
void func_0000BCE8(void);
void func_0000BD2C(s32 arg0);
void func_0000BD4C(void);
void func_0000C544(s32 arg0);
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
void func_0000EF20(void);
void func_0000EF30(void);
void func_0000EF38(void);
void func_0000F6BC(void);
void func_0000FA28(void);
void func_0000FA30(void);
void func_0000FA38(void);
void func_0000FBC0(void);
void func_0000FBC8(void);
void func_0000FBD0(void);
void func_0000FCC0(void);
void func_0000FCC8(void);
void func_0000FDCC(void);
void func_0000FEA8(void);
void func_0000FEB0(void);
void func_00010028(void);
void func_0001005C(void);
void func_00010090(void);
void func_00010288(void);
void func_00010290(void);
void func_00010298(void);
void func_000105AC(void);
void func_00010D1C(void);
void func_000116A4(s32 arg0);
void func_000116F0(void);
void func_00011714(void);
void func_00011774(void);
void func_00011C1C(void);
void func_00011C4C(s32 arg0, s32 arg1, s32 arg2);
void func_00011C68(void);
void func_0001222C(s32 arg0);
void func_00012238(s32 arg0);
void func_00012244(s32 arg0, s32 arg1);
void func_000124C8(void);
void func_00013B94(s32 arg0, int arg1);
void func_00013CD4(s32 arg0);
void func_0001411C(void);
void func_0001439C(void);
void func_00015778(s32 arg0);
void func_00015784(s32 arg0);
void func_00015804(void);
void func_0001580C(void);
void func_00015814(void);

/* func_00000000 — 14 words. MATCH 100% (shape: m2c). */
s32 func_00000000(s32 arg0) {
    if (arg0 == 0) {
        ehsys_B4471B5E(func_00000038, func_00000230, &D_0002A5C0);
    }
    return 0;
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

/* func_000003AC — 3 words. MATCH 100% (shape: m2c). */
void func_000003AC(s32 arg0) {
    D_0002A654 = arg0;
}

/* func_000003CC — 3 words. MATCH 100% (shape: m2c). */
void func_000003CC(s32 arg0) {
    D_0002A5D0 = arg0;
}

/* func_00000B20 — 3 words. MATCH 100% (shape: m2c). */
void func_00000B20(s32 arg0) {
    D_0002A660 = arg0;
}

/* func_00000DD8 — 3 words. MATCH 100% (shape: m2c). */
void func_00000DD8(s32 arg0) {
    D_0002A658 = arg0;
}

/* func_00000DE4 — 4 words. MATCH 100% (shape: m2c). */
s32 func_00000DE4(void) {
    return D_0002A658 != 0;
}

/* func_00000F4C — 3 words. MATCH 100% (shape: m2c). */
void func_00000F4C(s32 arg0) {
    D_0002A65C = arg0;
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

/* func_00005948 — 3 words. MATCH 100% (shape: m2c). */
s32 func_00005948(void) {
    return D_0002F134;
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

/* func_00006B80 — 18 words. MATCH 100% (shape: m2c). */
void func_00006B80(void) {
    func_0000690C();
    D_0002F13C = 4;
    ehsys_13A4081A(1);
    if (func_0000B498() == 0) {
        func_000118E0();
    }
}

/* func_00006E60 — 11 words. MATCH 100% (shape: m2c). */
void func_00006E60(void) {
    int sp1C;

    field_86220A06(0x10, &sp1C);
    D_0002F13C = 6;
}

/* func_00008B10 — 15 words. MATCH 100% (shape: m2c). */
void func_00008B10(void) {
    func_00000E54(0, 1, 0, 0);
    ehsys_13A4081A(1);
    D_0002F13C = 7;
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

/* func_00009FC8 — 3 words. MATCH 100% (shape: m2c). */
void func_00009FC8(s32 arg0) {
    D_00034484 = arg0;
}

/* func_0000AA98 — 3 words. MATCH 100% (shape: m2c). */
void func_0000AA98(s32 arg0) {
    D_00034470 = arg0;
}

/* func_0000AE34 — 23 words. MATCH 100% (shape: m2c). */
void func_0000AE34(void) {
    ehsys_memset(&D_00033ACC, 0, 0x9A4);
    D_00033BA0 = 2;
    D_00033BA3 = (s8) D_00034470;
    D_0003439C = 1;
    ehsys_F11F0D9A(&D_00033ACC);
}

/* func_0000B2A0 — 3 words. MATCH 100% (shape: m2c). */
void func_0000B2A0(s32 arg0) {
    D_00034398 = arg0;
}

/* func_0000B304 — 3 words. MATCH 100% (shape: m2c). */
void func_0000B304(s32 arg0) {
    D_000344A4 = arg0;
}

/* func_0000B324 — 3 words. MATCH 100% (shape: m2c). */
void func_0000B324(s32 arg0) {
    D_00034488 = arg0;
}

/* func_0000B3CC — 3 words. MATCH 100% (shape: m2c). */
void func_0000B3CC(s32 arg0) {
    D_00034490 = arg0;
}

/* func_0000B454 — 3 words. MATCH 100% (shape: m2c). */
void func_0000B454(s32 arg0) {
    D_00034494 = arg0;
}

/* func_0000B560 — 3 words. MATCH 100% (shape: m2c). */
s32 func_0000B560(void) {
    return D_000344A4;
}

/* func_0000B5F0 — 2 words. MATCH 100% (shape: m2c). */
void func_0000B5F0(void) {

}

/* func_0000B77C — 3 words. MATCH 100% (shape: m2c). */
void func_0000B77C(void) {
    D_00034560 = 0;
}

/* func_0000B888 — 3 words. MATCH 100% (shape: m2c). */
void func_0000B888(s32 arg0) {
    D_00034574 = arg0;
}

/* func_0000B8C8 — 2 words. MATCH 100% (shape: m2c). */
void func_0000B8C8(void) {

}

/* func_0000B8D0 — 2 words. MATCH 100% (shape: m2c). */
void func_0000B8D0(void) {

}

/* func_0000B8D8 — 5 words. MATCH 100% (shape: m2c). */
void func_0000B8D8(s32 arg0, s32 arg1) {
    D_0003457C = arg0;
    D_00034578 = arg1;
}

/* func_0000BCE8 — 12 words. MATCH 100% (shape: m2c). */
void func_0000BCE8(void) {
    ehsys_memset(&D_00034580, 0, 0xA1C);
    func_0000BD4C();
}

/* func_0000BD2C — 3 words. MATCH 100% (shape: m2c). */
void func_0000BD2C(s32 arg0) {
    D_00034F9C = arg0;
}

/* func_0000BD4C — 11 words. MATCH 100% (shape: m2c). */
void func_0000BD4C(void) {
    D_00034580 = 0;
    D_00034584 = 1;
    D_00034590 = 0x74;
    D_00034594 = 0;
}

/* func_0000C544 — 3 words. MATCH 100% (shape: m2c). */
void func_0000C544(s32 arg0) {
    D_00034590 = arg0;
}

/* func_0000C550 — 3 words. MATCH 100% (shape: m2c). */
s32 func_0000C550(void) {
    return D_00034594;
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

/* func_0000EF20 — 4 words. MATCH 100% (shape: m2c). */
void func_0000EF20(void) {
    D_00034590 = 0x76;
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

/* func_0000FA28 — 2 words. MATCH 100% (shape: m2c). */
void func_0000FA28(void) {

}

/* func_0000FA30 — 2 words. MATCH 100% (shape: m2c). */
void func_0000FA30(void) {

}

/* func_0000FA38 — 4 words. MATCH 100% (shape: m2c). */
void func_0000FA38(void) {
    D_0003458C = 1;
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

/* func_0000FDCC — 4 words. MATCH 100% (shape: m2c). */
void func_0000FDCC(void) {
    D_00034590 = 0x67;
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

/* func_000105AC — 4 words. MATCH 100% (shape: m2c). */
void func_000105AC(void) {
    D_00034590 = 0x78;
}

/* func_00010D1C — 4 words. MATCH 100% (shape: m2c). */
void func_00010D1C(void) {
    D_00034590 = 0x79;
}

/* func_00011634 — 3 words. MATCH 100% (shape: m2c). */
s32 func_00011634(void) {
    return D_00034F98;
}

/* func_000116A4 — 3 words. MATCH 100% (shape: m2c). */
void func_000116A4(s32 arg0) {
    D_00034FA4 = arg0;
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

/* func_00011C4C — 7 words. MATCH 100% (shape: m2c). */
void func_00011C4C(s32 arg0, s32 arg1, s32 arg2) {
    D_00034FD0 = arg0;
    D_00034FCC = arg1;
    D_00034FD4 = arg2;
}

/* func_00011C68 — 18 words. MATCH 100% (shape: m2c). */
void func_00011C68(void) {
    s32 temp_s0;

    temp_s0 = D_00034FD0;
    ehsys_memset(D_00034FCC, 0, 0xB8);
    ehsys_memset(temp_s0, 0, 0x24);
}

/* func_0001222C — 3 words. MATCH 100% (shape: m2c). */
void func_0001222C(s32 arg0) {
    D_00034FC0 = arg0;
}

/* func_00012238 — 3 words. MATCH 100% (shape: m2c). */
void func_00012238(s32 arg0) {
    D_00034FC4 = arg0;
}

/* func_00012244 — 5 words. MATCH 100% (shape: m2c). */
void func_00012244(s32 arg0, s32 arg1) {
    D_00034FA8 = arg0;
    D_00034FAC = arg1;
}

/* func_000124C8 — 2 words. MATCH 100% (shape: m2c). */
void func_000124C8(void) {

}

/* func_00013A38 — 14 words. MATCH 100% (shape: m2c). */
s32 func_00013A38(s32 arg0, int arg1) {
    s32 sp1C;

    func_00015A38(func_00015AE4(D_00034FC0, arg0, arg1), &sp1C);
    return sp1C;
}

/* func_00013B94 — 20 words. MATCH 100% (shape: m2c). */
void func_00013B94(s32 arg0, int arg1) {
    if (ehsys_0A60B08B() != 0) {
        ehsys_008B4553(arg0, arg1);
        ehsys_D9E726DC(arg0, arg1);
    }
}

/* func_00013CD4 — 3 words. MATCH 100% (shape: m2c). */
void func_00013CD4(s32 arg0) {
    D_00034FC8 = arg0;
}

/* func_00013CE0 — 3 words. MATCH 100% (shape: m2c). */
s32 func_00013CE0(void) {
    return D_00034FC8;
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

/* func_00015778 — 3 words. MATCH 100% (shape: m2c). */
void func_00015778(s32 arg0) {
    D_000351FC = arg0;
}

/* func_00015784 — 3 words. MATCH 100% (shape: m2c). */
void func_00015784(s32 arg0) {
    D_00035200 = arg0;
}

/* func_00015804 — 2 words. MATCH 100% (shape: m2c). */
void func_00015804(void) {
    func_00012358();
}

/* func_0001580C — 2 words. MATCH 100% (shape: m2c). */
void func_0001580C(void) {
    func_00011D20();
}

/* func_00015814 — 16 words. MATCH 100% (shape: m2c). */
void func_00015814(void) {
    ehsys_memset(&D_00035204, 0, 0x24);
    D_00035204 = ehsys_1856E536(&D_00035230, 0x500000);
}

/* func_00015890 — 3 words. MATCH 100% (shape: m2c). */
s32 func_00015890(void) {
    return D_00035204;
}

