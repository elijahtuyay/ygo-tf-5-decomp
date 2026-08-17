/*
 * rel_story.prx — reconstructed code (matching decompilation)
 *
 * Compiler:     Metrowerks CodeWarrior for PSP — MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,s -sdatathreshold 0
 * Verification: scripts/mwcc_build.sh src/rel_story.c
 *               scripts/mwcc_diff.py asm/rel_story/text.s build/mwcc/rel_story.o
 *
 * Every function below is byte-identical to the shipped module: each was
 * accepted only on a MATCH verdict, and the whole file is re-verified after
 * assembly. Functions are in ADDRESS ORDER, which is what the linker needs.
 *
 * Import names come from the module's NID tables and are identical across
 * all 28 modules — see docs/nids/README.md.
 *
 * Externs are declared inside each function on purpose: the same global is
 * accessed at different widths by different functions, and a single
 * file-scope declaration would change the load/store width and break the
 * match. See scripts/assemble_module.py.
 *
 * STATUS: 87 functions matched. build/auto/rel_story.json has the
 * status of every attempt, including what the rest of the module still needs.
 *
 * Assembled by scripts/assemble_module.py from scripts/auto_decomp.py drafts,
 * so local names are still m2c's (temp_v0, var_s1). Renaming them and adding
 * commentary is safe as long as every edit is re-verified.
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


/* func_00000000 — 14 words. MATCH 100% (shape: m2c). */
s32 func_00000000(s32 arg0) {
    extern char D_0002A5C0;
    extern int ehsys_B4471B5E();
    extern int func_00000000();
    extern int func_00000038();
    extern int func_00000230();
    if (arg0 == 0) {
        ehsys_B4471B5E(func_00000038, func_00000230, &D_0002A5C0);
    }
    return 0;
}

/* func_000000E8 — 41 words. MATCH 100% (shape: m2c). */
void func_000000E8(void) {
    extern int func_000000E8();
    extern int func_00000248();
    extern int func_00000384();
    extern int func_00000AF8();
    extern int func_00002184();
    extern int func_00003518();
    extern int func_00003C44();
    extern int func_00009B70();
    extern int func_00009FA0();
    extern int func_0000B2DC();
    extern int func_0000B56C();
    extern int func_0000B5F8();
    extern int func_0000B860();
    extern int func_0000B8C8();
    extern int func_0000BCE8();
    extern int func_0001167C();
    extern int func_00011C24();
    extern int func_00013CEC();
    extern int func_00015814();
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
    extern int func_0000018C();
    extern int func_0000025C();
    extern int func_00000398();
    extern int func_00000B0C();
    extern int func_00002198();
    extern int func_0000352C();
    extern int func_00003C58();
    extern int func_00009B84();
    extern int func_00009FB4();
    extern int func_0000B2F0();
    extern int func_0000B580();
    extern int func_0000B60C();
    extern int func_0000B874();
    extern int func_0000B8D0();
    extern int func_0000BD18();
    extern int func_00011690();
    extern int func_00011C38();
    extern int func_00013D00();
    extern int func_00015854();
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
    extern int func_00000230();

}

/* func_00000238 — 2 words. MATCH 100% (shape: m2c). */
void func_00000238(void) {
    extern int func_00000238();
    extern int func_00005954();
    func_00005954();
}

/* func_00000240 — 2 words. MATCH 100% (shape: m2c). */
void func_00000240(void) {
    extern int func_00000240();

}

/* func_000003AC — 3 words. MATCH 100% (shape: manual). */
void func_000003AC(s32 arg0) {
    extern s32 D_0002A654;
    D_0002A654 = arg0;
}

/* func_000003CC — 3 words. MATCH 100% (shape: manual). */
void func_000003CC(s32 arg0) {
    extern s32 D_0002A5D0;
    D_0002A5D0 = arg0;
}

/* func_00000B20 — 3 words. MATCH 100% (shape: manual). */
void func_00000B20(s32 arg0) {
    extern s32 D_0002A660;
    D_0002A660 = arg0;
}

/* func_00000DC8 — 4 words. MATCH 100% (shape: manual). */
s32 func_00000DC8(void) {
    extern void *D_0002A660;
    return *(s32 *)((char *)D_0002A660);
}

/* func_00000DD8 — 3 words. MATCH 100% (shape: manual). */
void func_00000DD8(s32 arg0) {
    extern s32 D_0002A658;
    D_0002A658 = arg0;
}

/* func_00000DE4 — 4 words. MATCH 100% (shape: manual). */
s32 func_00000DE4(void) {
    extern s32 D_0002A658;
    return D_0002A658 != 0;
}

/* func_00000DF4 — 4 words. MATCH 100% (shape: manual). */
void func_00000DF4(s32 arg0) {
    extern void *D_0002A660;
    *(s32 *)((char *)D_0002A660 + 0x4) = (s32)arg0;
}

/* func_00000E04 — 4 words. MATCH 100% (shape: manual). */
s32 func_00000E04(void) {
    extern void *D_0002A660;
    return *(s32 *)((char *)D_0002A660 + 0x4);
}

/* func_00000E14 — 4 words. MATCH 100% (shape: manual). */
void func_00000E14(s32 arg0) {
    extern void *D_0002A660;
    *(s16 *)((char *)D_0002A660 + 0xC) = (s16)arg0;
}

/* func_00000E24 — 4 words. MATCH 100% (shape: manual). */
s32 func_00000E24(void) {
    extern void *D_0002A660;
    return *(u16 *)((char *)D_0002A660 + 0xC);
}

/* func_00000E34 — 4 words. MATCH 100% (shape: manual). */
void func_00000E34(s32 arg0) {
    extern void *D_0002A660;
    *(s32 *)((char *)D_0002A660 + 0x8) = (s32)arg0;
}

/* func_00000E44 — 4 words. MATCH 100% (shape: manual). */
s32 func_00000E44(void) {
    extern void *D_0002A660;
    return *(s32 *)((char *)D_0002A660 + 0x8);
}

/* func_00000F4C — 3 words. MATCH 100% (shape: manual). */
void func_00000F4C(s32 arg0) {
    extern s32 D_0002A65C;
    D_0002A65C = arg0;
}

/* func_00001400 — 2 words. MATCH 100% (shape: m2c). */
void func_00001400(void) {
    extern int func_00001400();

}

/* func_0000195C — 23 words. MATCH 100% (shape: m2c). */
void func_0000195C(void) {
    extern int func_0000195C();
    extern int func_00001CE0();
    extern int func_0000BBD8();
    extern int func_0000BDE0();
    extern int func_000123C4();
    extern int func_00012408();
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
    extern int func_00001E9C();
    extern int func_0000B8A8();
    extern int func_00011D00();
    func_0000B8A8(0);
    func_00011D00();
}

/* func_00001EC0 — 2 words. MATCH 100% (shape: m2c). */
void func_00001EC0(void) {
    extern int func_00001EC0();

}

/* func_000023EC — 13 words. MATCH 100% (shape: m2c). */
void func_000023EC(s32 arg0) {
    extern int ehsys_C5D3B70C();
    extern int func_000023EC();
    extern int func_00002A3C();
    ehsys_C5D3B70C(0, arg0, func_00002A3C());
}

/* func_0000261C — 8 words. MATCH 100% (shape: m2c). */
s32 func_0000261C(void) {
    extern int ehsys_B27BC15D();
    extern int func_0000261C();
    return ehsys_B27BC15D() & 0xFFFF;
}

/* func_00002818 — 11 words. MATCH 100% (shape: m2c). */
s32 func_00002818(s32 arg0) {
    extern int func_00002818();
    extern int func_00002844();
    return arg0 == func_00002844();
}

/* func_00002844 — 2 words. MATCH 100% (shape: m2c). */
void func_00002844(void) {
    extern int ehsys_CCDAED90();
    extern int func_00002844();
    ehsys_CCDAED90();
}

/* func_0000284C — 2 words. MATCH 100% (shape: m2c). */
void func_0000284C(void) {
    extern int ehsys_81857D14();
    extern int func_0000284C();
    ehsys_81857D14();
}

/* func_00003418 — 8 words. MATCH 100% (shape: m2c). */
s32 func_00003418(void) {
    extern int func_00003418();
    extern int func_00003488();
    return func_00003488() + 4;
}

/* func_00005948 — 3 words. MATCH 100% (shape: manual). */
s32 func_00005948(void) {
    extern s32 D_0002F134;
    return D_0002F134;
}

/* func_000068A4 — 9 words. MATCH 100% (shape: m2c). */
s32 func_000068A4(void) {
    extern int field_79E5F8B7();
    extern int func_000068A4();
    int sp1C;

    return field_79E5F8B7(0x20, &sp1C) != 0;
}

/* func_000068C8 — 8 words. MATCH 100% (shape: m2c). */
void func_000068C8(void) {
    extern int field_86220A06();
    extern int func_000068C8();
    int sp1C;

    field_86220A06(0x21, &sp1C);
}

/* func_000068E8 — 9 words. MATCH 100% (shape: m2c). */
s32 func_000068E8(void) {
    extern int field_79E5F8B7();
    extern int func_000068E8();
    int sp1C;

    return field_79E5F8B7(0x21, &sp1C) != 0;
}

/* func_00008CB4 — 11 words. MATCH 100% (shape: m2c). */
void func_00008CB4(void) {
    extern int ehsys_13A4081A();
    extern int ehsys_frame_sync();
    extern int field_E92DC2F2();
    extern int func_00008CB4();
    field_E92DC2F2();
    ehsys_frame_sync();
    ehsys_13A4081A(1);
}

/* func_00008CE0 — 9 words. MATCH 100% (shape: m2c). */
void func_00008CE0(void) {
    extern int field_74B014A2();
    extern int field_FABFD3C6();
    extern int func_00008CE0();
    field_FABFD3C6();
    field_74B014A2();
}

/* func_00008EB4 — 12 words. MATCH 100% (shape: m2c). */
void func_00008EB4(void) {
    extern int ehsys_13A4081A();
    extern int func_00008EB4();
    extern int recipe_viewer_98E7E882();
    recipe_viewer_98E7E882(0, 0, 1, 1);
    ehsys_13A4081A(0);
}

/* func_00008F54 — 9 words. MATCH 100% (shape: m2c). */
void func_00008F54(void) {
    extern int ehsys_13A4081A();
    extern int func_00008F54();
    extern int password_932AE9C8();
    password_932AE9C8();
    ehsys_13A4081A(0);
}

/* func_00008FE4 — 12 words. MATCH 100% (shape: m2c). */
void func_00008FE4(void) {
    extern int ehsys_13A4081A();
    extern int func_00008FE4();
    extern int select_card_BF2B46D7();
    select_card_BF2B46D7(0, 0, 0, 0);
    ehsys_13A4081A(0);
}

/* func_00009080 — 9 words. MATCH 100% (shape: m2c). */
void func_00009080(void) {
    extern int conv_machine_0BB25540();
    extern int ehsys_13A4081A();
    extern int func_00009080();
    conv_machine_0BB25540();
    ehsys_13A4081A(0);
}

/* func_00009110 — 10 words. MATCH 100% (shape: m2c). */
void func_00009110(void) {
    extern int cardalbum_EE554159();
    extern int ehsys_13A4081A();
    extern int func_00009110();
    cardalbum_EE554159(1, 0);
    ehsys_13A4081A(0);
}

/* func_000092D8 — 10 words. MATCH 100% (shape: m2c). */
void func_000092D8(void) {
    extern int ehsys_13A4081A();
    extern int func_000092D8();
    extern int limitlist_E69A45D2();
    limitlist_E69A45D2(1, 0);
    ehsys_13A4081A(0);
}

/* func_0000939C — 12 words. MATCH 100% (shape: m2c). */
void func_0000939C(void) {
    extern int ehsys_13A4081A();
    extern int func_00000DC8();
    extern int func_0000939C();
    extern int tutoriallist_41015B0F();
    tutoriallist_41015B0F(func_00000DC8(), 0);
    ehsys_13A4081A(0);
}

/* func_00009598 — 12 words. MATCH 100% (shape: m2c). */
void func_00009598(void) {
    extern int deck_tutorial_4E16F5A6();
    extern int ehsys_13A4081A();
    extern int func_00000DC8();
    extern int func_00009598();
    deck_tutorial_4E16F5A6(func_00000DC8(), 0);
    ehsys_13A4081A(0);
}

/* func_00009644 — 9 words. MATCH 100% (shape: m2c). */
void func_00009644(void) {
    extern int duelrecord_6ADB95DB();
    extern int ehsys_13A4081A();
    extern int func_00009644();
    duelrecord_6ADB95DB(0);
    ehsys_13A4081A(0);
}

/* func_00009A30 — 16 words. MATCH 100% (shape: m2c). */
void func_00009A30(void) {
    extern int ehsys_13A4081A();
    extern int func_00000DF4();
    extern int func_00000E54();
    extern int func_00009A30();
    extern int func_00011874();
    func_00011874();
    func_00000E54(0, 1, 0, 0);
    ehsys_13A4081A(1);
    func_00000DF4(1);
}

/* func_00009B84 — 12 words. MATCH 100% (shape: m2c). */
void func_00009B84(void) {
    extern char D_00033A98;
    extern int ehsys_memset();
    extern int func_00009B84();
    extern int func_00009E94();
    func_00009E94();
    ehsys_memset(&D_00033A98, 0, 0x14);
}

/* func_00009E1C — 30 words. MATCH 100% (shape: m2c). */
s32 func_00009E1C(void) {
    extern char D_000200F4;
    extern char D_00020108;
    extern char D_0002011C;
    extern char D_00020134;
    extern int func_00009E1C();
    extern int func_00012104();
    extern int func_0001222C();
    extern int func_00012238();
    extern int func_00015778();
    extern int func_000159CC();
    func_00012104(func_000159CC(2, &D_000200F4));
    func_0001222C(func_000159CC(2, &D_00020108));
    func_00012238(func_000159CC(2, &D_0002011C));
    func_00015778(func_000159CC(3, &D_00020134));
    return 1;
}

/* func_00009FC8 — 3 words. MATCH 100% (shape: manual). */
void func_00009FC8(s32 arg0) {
    extern s32 D_00034484;
    D_00034484 = arg0;
}

/* func_0000AA98 — 3 words. MATCH 100% (shape: manual). */
void func_0000AA98(s32 arg0) {
    extern s32 D_00034470;
    D_00034470 = arg0;
}

/* func_0000AB6C — 4 words. MATCH 100% (shape: manual). */
s32 func_0000AB6C(void) {
    extern void *D_00034484;
    return *(s32 *)((char *)D_00034484 + 0x38);
}

/* func_0000AB7C — 4 words. MATCH 100% (shape: manual). */
s32 func_0000AB7C(void) {
    extern void *D_00034484;
    return *(s32 *)((char *)D_00034484 + 0x3C);
}

/* func_0000AB8C — 4 words. MATCH 100% (shape: manual). */
s32 func_0000AB8C(void) {
    extern void *D_00034484;
    return *(s32 *)((char *)D_00034484 + 0x40);
}

/* func_0000AF20 — 4 words. MATCH 100% (shape: manual). */
void func_0000AF20(s32 arg0) {
    extern void *D_00034484;
    *(s32 *)((char *)D_00034484 + 0x50) = (s32)arg0;
}

/* func_0000AF30 — 4 words. MATCH 100% (shape: manual). */
s32 func_0000AF30(void) {
    extern void *D_00034484;
    return *(s32 *)((char *)D_00034484 + 0x50);
}

/* func_0000AF68 — 4 words. MATCH 100% (shape: manual). */
void func_0000AF68(s32 arg0) {
    extern void *D_00034484;
    *(s32 *)((char *)D_00034484 + 0x10) = (s32)arg0;
}

/* func_0000AF78 — 4 words. MATCH 100% (shape: manual). */
s32 func_0000AF78(void) {
    extern void *D_00034484;
    return *(s32 *)((char *)D_00034484 + 0x10);
}

/* func_0000B0D0 — 26 words. MATCH 100% (shape: m2c). */
void func_0000B0D0(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3) {
    extern int ehsys_9090346C();
    extern int func_00002A3C();
    extern int func_0000B0D0();
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

/* func_0000B2A0 — 3 words. MATCH 100% (shape: manual). */
void func_0000B2A0(s32 arg0) {
    extern s32 D_00034398;
    D_00034398 = arg0;
}

/* func_0000B304 — 3 words. MATCH 100% (shape: manual). */
void func_0000B304(s32 arg0) {
    extern s32 D_000344A4;
    D_000344A4 = arg0;
}

/* func_0000B324 — 3 words. MATCH 100% (shape: manual). */
void func_0000B324(s32 arg0) {
    extern s32 D_00034488;
    D_00034488 = arg0;
}

/* func_0000B3CC — 3 words. MATCH 100% (shape: manual). */
void func_0000B3CC(s32 arg0) {
    extern s32 D_00034490;
    D_00034490 = arg0;
}

/* func_0000B454 — 3 words. MATCH 100% (shape: manual). */
void func_0000B454(s32 arg0) {
    extern s32 D_00034494;
    D_00034494 = arg0;
}

/* func_0000B488 — 4 words. MATCH 100% (shape: manual). */
void func_0000B488(s32 arg0) {
    extern void *D_000344A4;
    *(s32 *)((char *)D_000344A4 + 0xC) = (s32)arg0;
}

/* func_0000B498 — 4 words. MATCH 100% (shape: manual). */
s32 func_0000B498(void) {
    extern void *D_000344A4;
    return *(s32 *)((char *)D_000344A4 + 0xC);
}

/* func_0000B4A8 — 4 words. MATCH 100% (shape: manual). */
void func_0000B4A8(s32 arg0) {
    extern void *D_000344A4;
    *(s32 *)((char *)D_000344A4 + 0x10) = (s32)arg0;
}

/* func_0000B4B8 — 4 words. MATCH 100% (shape: manual). */
s32 func_0000B4B8(void) {
    extern void *D_000344A4;
    return *(s32 *)((char *)D_000344A4 + 0x10);
}

/* func_0000B4DC — 3 words. MATCH 100% (shape: manual). */
void *func_0000B4DC(void) {
    extern s32 D_0003449C;
    return &D_0003449C;
}

/* func_0000B4E8 — 4 words. MATCH 100% (shape: manual). */
void func_0000B4E8(s32 arg0) {
    extern void *D_000344A4;
    *(s32 *)((char *)D_000344A4 + 0x14) = (s32)arg0;
}

/* func_0000B4F8 — 4 words. MATCH 100% (shape: manual). */
void func_0000B4F8(s32 arg0) {
    extern void *D_000344A4;
    *(s16 *)((char *)D_000344A4 + 0x18) = (s16)arg0;
}

/* func_0000B508 — 4 words. MATCH 100% (shape: manual). */
s32 func_0000B508(void) {
    extern void *D_000344A4;
    return *(s32 *)((char *)D_000344A4 + 0x14);
}

/* func_0000B518 — 4 words. MATCH 100% (shape: manual). */
s32 func_0000B518(void) {
    extern void *D_000344A4;
    return *(u16 *)((char *)D_000344A4 + 0x18);
}

/* func_0000B528 — 4 words. MATCH 100% (shape: manual). */
void func_0000B528(s32 arg0) {
    extern void *D_000344A4;
    *(s32 *)((char *)D_000344A4 + 0x1C) = (s32)arg0;
}

/* func_0000B538 — 4 words. MATCH 100% (shape: manual). */
s32 func_0000B538(void) {
    extern void *D_000344A4;
    return *(s32 *)((char *)D_000344A4 + 0x1C);
}

/* func_0000B560 — 3 words. MATCH 100% (shape: manual). */
s32 func_0000B560(void) {
    extern s32 D_000344A4;
    return D_000344A4;
}

/* func_0000B5F0 — 2 words. MATCH 100% (shape: m2c). */
void func_0000B5F0(void) {
    extern int func_0000B5F0();

}

/* func_0000B77C — 3 words. MATCH 100% (shape: manual). */
void func_0000B77C(s32 arg0) {
    extern s32 D_00034560;
    D_00034560 = 0;
}

/* func_0000B888 — 3 words. MATCH 100% (shape: manual). */
void func_0000B888(s32 arg0) {
    extern s32 D_00034574;
    D_00034574 = arg0;
}

/* func_0000B8A8 — 4 words. MATCH 100% (shape: manual). */
void func_0000B8A8(s32 arg0) {
    extern void *D_00034574;
    *(s32 *)((char *)D_00034574 + 0x4) = (s32)arg0;
}

/* func_0000B8B8 — 4 words. MATCH 100% (shape: manual). */
s32 func_0000B8B8(void) {
    extern void *D_00034574;
    return *(s32 *)((char *)D_00034574 + 0x4);
}

/* func_0000B8C8 — 2 words. MATCH 100% (shape: m2c). */
void func_0000B8C8(void) {
    extern int func_0000B8C8();

}

/* func_0000B8D0 — 2 words. MATCH 100% (shape: m2c). */
void func_0000B8D0(void) {
    extern int func_0000B8D0();

}

/* func_0000B95C — 4 words. MATCH 100% (shape: manual). */
void func_0000B95C(s32 arg0) {
    extern void *D_0003457C;
    *(s32 *)((char *)D_0003457C + 0x4) = (s32)arg0;
}

/* func_0000B984 — 4 words. MATCH 100% (shape: manual). */
f32 func_0000B984(void) {
    extern void *D_0003457C;
    return *(f32 *)((char *)D_0003457C + 0x8);
}

/* func_0000B994 — 4 words. MATCH 100% (shape: manual). */
f32 func_0000B994(void) {
    extern void *D_0003457C;
    return *(f32 *)((char *)D_0003457C + 0xC);
}

/* func_0000B9A4 — 4 words. MATCH 100% (shape: manual). */
s32 func_0000B9A4(void) {
    extern void *D_0003457C;
    return *(s32 *)((char *)D_0003457C + 0x10);
}

/* func_0000BA5C — 4 words. MATCH 100% (shape: manual). */
void func_0000BA5C(s32 arg0) {
    extern void *D_0003457C;
    *(s32 *)((char *)D_0003457C + 0x30) = (s32)arg0;
}

/* func_0000BA6C — 4 words. MATCH 100% (shape: manual). */
s32 func_0000BA6C(void) {
    extern void *D_0003457C;
    return *(s32 *)((char *)D_0003457C + 0x30);
}

/* func_0000BA94 — 4 words. MATCH 100% (shape: manual). */
s32 func_0000BA94(void) {
    extern void *D_0003457C;
    return *(s32 *)((char *)D_0003457C + 0x38);
}

/* func_0000BABC — 4 words. MATCH 100% (shape: manual). */
s32 func_0000BABC(void) {
    extern void *D_0003457C;
    return *(s32 *)((char *)D_0003457C + 0x3C);
}

/* func_0000BBD8 — 4 words. MATCH 100% (shape: manual). */
s32 func_0000BBD8(void) {
    extern void *D_0003457C;
    return *(s32 *)((char *)D_0003457C + 0x14);
}

/* func_0000BBE8 — 4 words. MATCH 100% (shape: manual). */
s32 func_0000BBE8(void) {
    extern void *D_0003457C;
    return *(s32 *)((char *)D_0003457C + 0x18);
}

/* func_0000BBF8 — 4 words. MATCH 100% (shape: manual). */
s32 func_0000BBF8(void) {
    extern void *D_0003457C;
    return *(s32 *)((char *)D_0003457C + 0x1C);
}

/* func_0000BC68 — 4 words. MATCH 100% (shape: manual). */
void func_0000BC68(s32 arg0) {
    extern void *D_0003457C;
    *(s16 *)((char *)D_0003457C + 0x160) = (s16)arg0;
}

/* func_0000BC78 — 4 words. MATCH 100% (shape: manual). */
void func_0000BC78(s32 arg0) {
    extern void *D_0003457C;
    *(s16 *)((char *)D_0003457C + 0x162) = (s16)arg0;
}

/* func_0000BC88 — 4 words. MATCH 100% (shape: manual). */
void func_0000BC88(s32 arg0) {
    extern void *D_0003457C;
    *(s32 *)((char *)D_0003457C + 0x164) = (s32)arg0;
}

/* func_0000BC98 — 4 words. MATCH 100% (shape: manual). */
s32 func_0000BC98(void) {
    extern void *D_0003457C;
    return *(u16 *)((char *)D_0003457C + 0x160);
}

/* func_0000BCA8 — 4 words. MATCH 100% (shape: manual). */
s32 func_0000BCA8(void) {
    extern void *D_0003457C;
    return *(u16 *)((char *)D_0003457C + 0x162);
}

/* func_0000BCB8 — 4 words. MATCH 100% (shape: manual). */
s32 func_0000BCB8(void) {
    extern void *D_0003457C;
    return *(s32 *)((char *)D_0003457C + 0x164);
}

/* func_0000BCC8 — 4 words. MATCH 100% (shape: manual). */
void func_0000BCC8(s32 arg0) {
    extern void *D_0003457C;
    *(s32 *)((char *)D_0003457C + 0x168) = (s32)arg0;
}

/* func_0000BCD8 — 4 words. MATCH 100% (shape: manual). */
s32 func_0000BCD8(void) {
    extern void *D_0003457C;
    return *(s32 *)((char *)D_0003457C + 0x168);
}

/* func_0000BCE8 — 12 words. MATCH 100% (shape: m2c). */
void func_0000BCE8(void) {
    extern char D_00034580;
    extern int ehsys_memset();
    extern int func_0000BCE8();
    extern int func_0000BD4C();
    ehsys_memset(&D_00034580, 0, 0xA1C);
    func_0000BD4C();
}

/* func_0000BD2C — 3 words. MATCH 100% (shape: manual). */
void func_0000BD2C(s32 arg0) {
    extern s32 D_00034F9C;
    D_00034F9C = arg0;
}

/* func_0000C544 — 3 words. MATCH 100% (shape: manual). */
void func_0000C544(s32 arg0) {
    extern s32 D_00034590;
    D_00034590 = arg0;
}

/* func_0000C550 — 3 words. MATCH 100% (shape: manual). */
s32 func_0000C550(void) {
    extern s32 D_00034594;
    return D_00034594;
}

/* func_0000D438 — 9 words. MATCH 100% (shape: m2c). */
void func_0000D438(void) {
    extern int func_0000D438();
    extern int func_00014124();
    extern int func_0001422C();
    func_00014124();
    func_0001422C();
}

/* func_0000D518 — 11 words. MATCH 100% (shape: m2c). */
void func_0000D518(void) {
    extern int func_0000D518();
    extern int func_0001432C();
    extern int func_00014360();
    if (func_0001432C() != 0) {
        func_00014360();
    }
}

/* func_0000D544 — 2 words. MATCH 100% (shape: m2c). */
void func_0000D544(void) {
    extern int func_0000D544();

}

/* func_0000DE2C — 2 words. MATCH 100% (shape: m2c). */
void func_0000DE2C(void) {
    extern int func_0000DDA8();
    extern int func_0000DE2C();
    func_0000DDA8();
}

/* func_0000E150 — 2 words. MATCH 100% (shape: m2c). */
void func_0000E150(void) {
    extern int func_0000E150();

}

/* func_0000E20C — 2 words. MATCH 100% (shape: m2c). */
void func_0000E20C(void) {
    extern int func_0000E20C();

}

/* func_0000E214 — 2 words. MATCH 100% (shape: m2c). */
void func_0000E214(void) {
    extern int func_0000E214();

}

/* func_0000E284 — 2 words. MATCH 100% (shape: m2c). */
void func_0000E284(void) {
    extern int func_0000E284();

}

/* func_0000E4E4 — 2 words. MATCH 100% (shape: m2c). */
void func_0000E4E4(void) {
    extern int func_0000E4E4();

}

/* func_0000E6F4 — 2 words. MATCH 100% (shape: m2c). */
void func_0000E6F4(void) {
    extern int func_0000E6F4();

}

/* func_0000E998 — 15 words. MATCH 100% (shape: m2c). */
void func_0000E998(void) {
    extern int func_0000BA94();
    extern int func_0000BAE4();
    extern int func_0000E998();
    s32 temp_v0;

    temp_v0 = func_0000BA94();
    if ((temp_v0 > 0) && (temp_v0 < 0x33)) {
        func_0000BAE4(temp_v0);
    }
}

/* func_0000E9D4 — 15 words. MATCH 100% (shape: m2c). */
void func_0000E9D4(void) {
    extern int func_0000BABC();
    extern int func_0000BAE4();
    extern int func_0000E9D4();
    s32 temp_v0;

    temp_v0 = func_0000BABC();
    if ((temp_v0 > 0) && (temp_v0 < 0x33)) {
        func_0000BAE4(temp_v0);
    }
}

/* func_0000EBA0 — 2 words. MATCH 100% (shape: m2c). */
void func_0000EBA0(void) {
    extern int func_0000EBA0();

}

/* func_0000EC0C — 2 words. MATCH 100% (shape: m2c). */
void func_0000EC0C(void) {
    extern int func_0000EBA8();
    extern int func_0000EC0C();
    func_0000EBA8();
}

/* func_0000EC14 — 2 words. MATCH 100% (shape: m2c). */
void func_0000EC14(void) {
    extern int func_0000EC14();

}

/* func_0000EC1C — 2 words. MATCH 100% (shape: m2c). */
void func_0000EC1C(void) {
    extern int func_0000EC1C();

}

/* func_0000EC24 — 15 words. MATCH 100% (shape: m2c). */
void func_0000EC24(void) {
    extern int ehsys_92675210();
    extern int func_0000BBD8();
    extern int func_0000EC24();
    extern int func_00012368();
    extern int func_000123A4();
    s32 temp_s0;

    func_00012368();
    temp_s0 = func_0000BBD8();
    ehsys_92675210(temp_s0, func_000123A4() & 0xFFFF);
}

/* func_0000EC60 — 2 words. MATCH 100% (shape: m2c). */
void func_0000EC60(void) {
    extern int func_0000EC60();

}

/* func_0000ECFC — 2 words. MATCH 100% (shape: manual). */
s32 func_0000ECFC(void) {
    extern int func_000111D8();
    return func_000111D8(1);
}

/* func_0000ED04 — 2 words. MATCH 100% (shape: manual). */
s32 func_0000ED04(void) {
    extern int func_000111D8();
    return func_000111D8(5);
}

/* func_0000ED98 — 2 words. MATCH 100% (shape: m2c). */
void func_0000ED98(void) {
    extern int func_0000ED98();

}

/* func_0000EF0C — 3 words. MATCH 100% (shape: manual). */
s32 func_0000EF0C(void) {
    extern int func_00005998();
    return func_00005998(5, 0);
}

/* func_0000EF18 — 2 words. MATCH 100% (shape: m2c). */
void func_0000EF18(void) {
    extern int func_0000EF18();

}

/* func_0000EF20 — 4 words. MATCH 100% (shape: manual). */
void func_0000EF20(void) {
    extern s32 D_00034590;
    D_00034590 = 0x76;
}

/* func_0000EF30 — 2 words. MATCH 100% (shape: m2c). */
void func_0000EF30(void) {
    extern int func_0000EF30();

}

/* func_0000EF38 — 2 words. MATCH 100% (shape: m2c). */
void func_0000EF38(void) {
    extern int func_0000EF38();

}

/* func_0000F6BC — 22 words. MATCH 100% (shape: m2c). */
void func_0000F6BC(void) {
    extern int func_00002A3C();
    extern int func_0000A068();
    extern int func_0000AA80();
    extern int func_0000AF78();
    extern int func_0000F6BC();
    extern int func_00013B2C();
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = func_0000AF78();
    func_00013B2C(temp_v0, func_00002A3C(temp_v0), &sp1C);
    func_0000A068(temp_v0, sp1C);
    func_0000AA80(-1, -1, -1);
}

/* func_0000F714 — 31 words. MATCH 100% (shape: m2c). */
void func_0000F714(void) {
    extern int func_00002A3C();
    extern int func_0000A6E8();
    extern int func_0000A840();
    extern int func_0000A930();
    extern int func_0000AA80();
    extern int func_0000AF78();
    extern int func_0000F714();
    extern int func_00011F04();
    extern int func_00013B2C();
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
    extern int func_0000FA28();

}

/* func_0000FA30 — 2 words. MATCH 100% (shape: m2c). */
void func_0000FA30(void) {
    extern int func_0000FA30();

}

/* func_0000FA38 — 4 words. MATCH 100% (shape: manual). */
void func_0000FA38(void) {
    extern s32 D_0003458C;
    D_0003458C = 0x1;
}

/* func_0000FBC0 — 2 words. MATCH 100% (shape: m2c). */
void func_0000FBC0(void) {
    extern int func_0000FBC0();

}

/* func_0000FBC8 — 2 words. MATCH 100% (shape: m2c). */
void func_0000FBC8(void) {
    extern int func_0000FBC8();

}

/* func_0000FBD0 — 2 words. MATCH 100% (shape: m2c). */
void func_0000FBD0(void) {
    extern int func_0000FBD0();

}

/* func_0000FCC0 — 2 words. MATCH 100% (shape: m2c). */
void func_0000FCC0(void) {
    extern int func_0000FCC0();

}

/* func_0000FCC8 — 2 words. MATCH 100% (shape: m2c). */
void func_0000FCC8(void) {
    extern int func_0000FCC8();

}

/* func_0000FD14 — 3 words. MATCH 100% (shape: manual). */
s32 func_0000FD14(void) {
    extern int func_00011F04();
    return func_00011F04(25, 1);
}

/* func_0000FDCC — 4 words. MATCH 100% (shape: manual). */
void func_0000FDCC(void) {
    extern s32 D_00034590;
    D_00034590 = 0x67;
}

/* func_0000FEA8 — 2 words. MATCH 100% (shape: m2c). */
void func_0000FEA8(void) {
    extern int func_0000FEA8();
    extern int func_000118E0();
    func_000118E0();
}

/* func_0000FEB0 — 2 words. MATCH 100% (shape: m2c). */
void func_0000FEB0(void) {
    extern int func_0000FEB0();
    extern int func_00011998();
    func_00011998();
}

/* func_00010028 — 2 words. MATCH 100% (shape: m2c). */
void func_00010028(void) {
    extern int func_0000FFB8();
    extern int func_00010028();
    func_0000FFB8();
}

/* func_0001005C — 2 words. MATCH 100% (shape: m2c). */
void func_0001005C(void) {
    extern int func_0001005C();

}

/* func_00010090 — 2 words. MATCH 100% (shape: m2c). */
void func_00010090(void) {
    extern int func_00010090();

}

/* func_00010288 — 2 words. MATCH 100% (shape: m2c). */
void func_00010288(void) {
    extern int func_00010288();

}

/* func_00010290 — 2 words. MATCH 100% (shape: m2c). */
void func_00010290(void) {
    extern int func_00010290();

}

/* func_00010298 — 2 words. MATCH 100% (shape: m2c). */
void func_00010298(void) {
    extern int func_00010298();

}

/* func_000102A0 — 2 words. MATCH 100% (shape: manual). */
s32 func_000102A0(void) {
    extern int func_0000B4A8();
    return func_0000B4A8(2);
}

/* func_000105AC — 4 words. MATCH 100% (shape: manual). */
void func_000105AC(void) {
    extern s32 D_00034590;
    D_00034590 = 0x78;
}

/* func_00010D1C — 4 words. MATCH 100% (shape: manual). */
void func_00010D1C(void) {
    extern s32 D_00034590;
    D_00034590 = 0x79;
}

/* func_000116A4 — 3 words. MATCH 100% (shape: manual). */
void func_000116A4(s32 arg0) {
    extern s32 D_00034FA4;
    D_00034FA4 = arg0;
}

/* func_000116F0 — 9 words. MATCH 100% (shape: m2c). */
void func_000116F0(void) {
    extern int ehsys_C859D5FE();
    extern int func_000116F0();
    ehsys_C859D5FE(0x2B7E);
    ehsys_C859D5FE(0x2B81);
}

/* func_00011714 — 2 words. MATCH 100% (shape: m2c). */
void func_00011714(void) {
    extern int ehsys_2AE3C0AD();
    extern int func_00011714();
    ehsys_2AE3C0AD();
}

/* func_00011774 — 2 words. MATCH 100% (shape: m2c). */
void func_00011774(void) {
    extern int ehsys_088F768A();
    extern int func_00011774();
    ehsys_088F768A();
}

/* func_000119A0 — 2 words. MATCH 100% (shape: manual). */
s32 func_000119A0(void) {
    extern int func_000117CC();
    return func_000117CC(8);
}

/* func_00011C1C — 2 words. MATCH 100% (shape: m2c). */
void func_00011C1C(void) {
    extern int ehsys_A84EDF3B();
    extern int func_00011C1C();
    ehsys_A84EDF3B();
}

/* func_00011D00 — 4 words. MATCH 100% (shape: manual). */
s32 func_00011D00(void) {
    extern void *D_00034FD0;
    return *(s32 *)((char *)D_00034FD0 + 0x10);
}

/* func_00011D10 — 4 words. MATCH 100% (shape: manual). */
s32 func_00011D10(void) {
    extern void *D_00034FD0;
    return *(s32 *)((char *)D_00034FD0 + 0x4);
}

/* func_00011D20 — 4 words. MATCH 100% (shape: manual). */
s32 func_00011D20(void) {
    extern void *D_00034FD0;
    return *(s32 *)((char *)D_00034FD0 + 0x8);
}

/* func_00011D30 — 4 words. MATCH 100% (shape: manual). */
s32 func_00011D30(void) {
    extern void *D_00034FD0;
    return *(s32 *)((char *)D_00034FD0 + 0xC);
}

/* func_00012358 — 4 words. MATCH 100% (shape: manual). */
s32 func_00012358(void) {
    extern void *D_00034FD0;
    return *(s32 *)((char *)D_00034FD0 + 0x1C);
}

/* func_000123A4 — 4 words. MATCH 100% (shape: manual). */
s32 func_000123A4(void) {
    extern void *D_00034FCC;
    return *(u8 *)((char *)D_00034FCC);
}

/* func_000123B4 — 4 words. MATCH 100% (shape: manual). */
void func_000123B4(s32 arg0) {
    extern void *D_00034FCC;
    *(s8 *)((char *)D_00034FCC) = (s8)arg0;
}

/* func_000123F8 — 4 words. MATCH 100% (shape: manual). */
void func_000123F8(s32 arg0) {
    extern void *D_00034FCC;
    *(s8 *)((char *)D_00034FCC + 0x1) = (s8)arg0;
}

/* func_00012408 — 4 words. MATCH 100% (shape: manual). */
s32 func_00012408(void) {
    extern void *D_00034FCC;
    return *(u8 *)((char *)D_00034FCC + 0x1);
}

/* func_000124C8 — 2 words. MATCH 100% (shape: m2c). */
void func_000124C8(void) {
    extern int func_000124C8();

}

/* func_00013970 — 4 words. MATCH 100% (shape: manual). */
s32 func_00013970(void) {
    extern void *D_00034FCC;
    return *(s32 *)((char *)D_00034FCC + 0xB4);
}

/* func_00013B94 — 20 words. MATCH 100% (shape: m2c). */
void func_00013B94(s32 arg0, int arg1) {
    extern int ehsys_008B4553();
    extern int ehsys_0A60B08B();
    extern int ehsys_D9E726DC();
    extern int func_00013B94();
    if (ehsys_0A60B08B() != 0) {
        ehsys_008B4553(arg0, arg1);
        ehsys_D9E726DC(arg0, arg1);
    }
}

/* func_00013CD4 — 3 words. MATCH 100% (shape: manual). */
void func_00013CD4(s32 arg0) {
    extern s32 D_00034FC8;
    D_00034FC8 = arg0;
}

/* func_00013CE0 — 3 words. MATCH 100% (shape: manual). */
s32 func_00013CE0(void) {
    extern s32 D_00034FC8;
    return D_00034FC8;
}

/* func_0001411C — 2 words. MATCH 100% (shape: m2c). */
void func_0001411C(void) {
    extern int func_0001411C();
    extern int func_00014124();
    func_00014124();
}

/* func_0001439C — 19 words. MATCH 100% (shape: m2c). */
void func_0001439C(void) {
    extern int func_000002F8();
    extern int func_00011634();
    extern int func_0001422C();
    extern int func_0001432C();
    extern int func_00014360();
    extern int func_0001439C();
    if (func_0001432C() != 0) {
        func_00014360();
    }
    if (func_00011634() == 0) {
        func_0001422C();
        func_000002F8();
    }
}

/* func_00015784 — 3 words. MATCH 100% (shape: manual). */
void func_00015784(s32 arg0) {
    extern s32 D_00035200;
    D_00035200 = arg0;
}

/* func_00015804 — 2 words. MATCH 100% (shape: m2c). */
void func_00015804(void) {
    extern int func_00012358();
    extern int func_00015804();
    func_00012358();
}

/* func_0001580C — 2 words. MATCH 100% (shape: m2c). */
void func_0001580C(void) {
    extern int func_00011D20();
    extern int func_0001580C();
    func_00011D20();
}

/* func_00015890 — 3 words. MATCH 100% (shape: manual). */
s32 func_00015890(void) {
    extern s32 D_00035204;
    return D_00035204;
}

/* func_00015ABC — 4 words. MATCH 100% (shape: manual). */
s32 func_00015ABC(s32 arg0) {
    extern s32 D_00035204;
    extern int ehsys_41AABF28();
    return ehsys_41AABF28(D_00035204, arg0);
}

/* func_00015ACC — 4 words. MATCH 100% (shape: manual). */
s32 func_00015ACC(s32 arg0) {
    extern s32 D_00035204;
    extern int ehsys_20E340D9();
    return ehsys_20E340D9(D_00035204, arg0);
}

/* func_00015ADC — 2 words. MATCH 100% (shape: manual). */
s32 func_00015ADC(void *arg0) {
    return *(s32 *)((char *)arg0 + 0xC);
}

