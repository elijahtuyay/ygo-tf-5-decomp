/*
 * rel_field.prx — reconstructed code (matching decompilation)
 *
 * Compiler:     Metrowerks CodeWarrior for PSP — MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,s -sdatathreshold 0
 * Verification: scripts/mwcc_build.sh src/rel_field.c
 *               scripts/mwcc_diff.py asm/rel_field/text.s build/mwcc/rel_field.o
 *
 * Every function below is byte-identical to the shipped module — each was
 * accepted only on a MATCH verdict from scripts/mwcc_diff.py, and the whole
 * file is re-verified after assembly (scripts/assemble_module.py).
 * Functions are in ADDRESS ORDER, which is what the linker needs.
 *
 * Import names are resolved from the module's NID tables and are identical
 * across all 28 modules — see docs/nids/README.md.
 *
 * STATUS: 104 functions matched here. The rest of the module is not
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
extern char D_0003DAE8;
extern char D_00048F18;
extern char D_00052040;
extern char D_000528BC;
extern char D_000528D0;
extern char D_000536F8;
extern char D_00053720;
extern char D_00053858;
extern char D_0005505C;
extern char D_B74450;
extern char D_B75940;
extern char D_B75948;
extern char D_B75AF0;
extern char D_B7AB00;
extern char D_B7AB44;
extern char D_B7AD44;
extern char D_B7AF5C;
extern char D_B7AF6C;
extern char D_B7B17C;
extern char D_B7B188;
extern char D_B7B38C;
extern int ehsys_025FE238();
extern int ehsys_04E1CB0F();
extern int ehsys_06380DFA();
extern int ehsys_1EC5342B();
extern int ehsys_4175E3DB();
extern int ehsys_4AA58320();
extern int ehsys_4F22C9AA();
extern int ehsys_5DF04F49();
extern int ehsys_60B55A50();
extern int ehsys_878EE1D3();
extern int ehsys_942B03D0();
extern int ehsys_9EFDC9B9();
extern int ehsys_AB962AE7();
extern int ehsys_B4471B5E();
extern int ehsys_BF3E9066();
extern int ehsys_C5BDA06E();
extern int ehsys_C792FA38();
extern int ehsys_C9D9E989();
extern int ehsys_D2A768F4();
extern int ehsys_D853F15C();
extern int ehsys_DFCA450B();
extern int ehsys_E58C0FDC();
extern int ehsys_F5E3080C();
extern int ehsys_frame_sync();
extern int ehsys_memset();
extern int func_00000038();
extern int func_00000DBC();
extern int func_00003384();
extern int func_00003F00();
extern int func_00004D4C();
extern int func_000051F0();
extern int func_00005CD8();
extern int func_00005CEC();
extern int func_00005E74();
extern int func_00006080();
extern int func_0000629C();
extern int func_000063DC();
extern int func_000064A4();
extern int func_0000747C();
extern int func_00009F70();
extern int func_0000A0B4();
extern int func_0000A958();
extern int func_0000A9C4();
extern int func_0000BB4C();
extern int func_0000BBA4();
extern int func_0000DAF8();
extern int func_0000DC1C();
extern int func_000101AC();
extern int func_00012BBC();
extern int func_00013028();
extern int func_00013234();
extern int func_000132C8();
extern int func_000139C0();
extern int func_00013ACC();
extern int func_00013BD0();
extern int func_00013C64();
extern int func_00013CFC();
extern int func_00013D90();
extern int func_00013E24();
extern int func_00014430();
extern int func_000144F8();
extern int func_000147B8();
extern int func_000147F0();
extern int func_00014B30();
extern int func_00014B68();
extern int func_00016BAC();
extern int func_00016BE4();
extern int func_0001A190();
extern int func_0001A5B8();
extern int func_0001B374();
extern int func_000225A0();
extern int func_00024754();
extern int func_00024C54();
extern int func_0002D07C();
extern int func_0002F5F0();
extern int func_0002F60C();
extern int func_0002F614();
extern int func_00030138();

/* ---- forward declarations ---- */
s32 func_00000000(s32 arg0);
s32 func_000003B8(void);
s32 func_00004970(s32 arg0);
s32 func_0000B06C(s32 *arg0, s32 *arg1);
s32 func_0000BAFC(void);
s32 func_000140DC(void);
s32 func_00016BA0(void);
s32 func_00018604(void);
s32 func_0001A12C(void);
s32 func_0001B35C(void);
s32 func_0001B460(void);
s32 func_0001B528(void);
s32 func_0002EBA8(void);
s32 func_0002F02C(s32 arg0);
s32 func_0002F03C(s32 arg0);
void * func_00014928(s32 arg0);
void func_00000138(void);
void func_00000388(void);
void func_00000390(void);
void func_000003C0(void);
void func_000003F0(void);
void func_00000414(void);
void func_00001214(void);
void func_00002C20(void);
void func_00003788(void);
void func_000037B8(void);
void func_00003944(void);
void func_00003F14(void);
void func_00003F38(void);
void func_00004D60(void);
void func_00004D84(void);
void func_00005204(void);
void func_00005228(void);
void func_00005E88(void);
void func_00005E90(void);
void func_00005E98(void);
void func_00005EBC(void);
void func_00005F0C(void);
void func_00006BC0(void);
void func_00007C7C(void);
void func_00007C94(void);
void func_000087A8(void);
void func_000088B0(void);
void func_000095D8(void);
void func_00009BAC(void);
void func_0000A714(void);
void func_0000A798(void);
void func_0000A9A0(void);
void func_0000B9C0(void);
void func_0000BA40(void);
void func_0000BAEC(void);
void func_0000BB80(void);
void func_0000D1FC(void);
void func_0000DBF8(void);
void func_0000F4D8(void);
void func_00011730(void);
void func_00012FD4(void);
void func_00013EB8(s32 arg0);
void func_00013EEC(s32 arg0);
void func_00013F20(s32 arg0);
void func_00014490(s32 arg0, int arg1, int arg2);
void func_000147CC(void);
void func_00014804(void);
void func_00014B44(void);
void func_00015534(void);
void func_00016BC0(void);
void func_00019C54(void);
void func_00019C78(void);
void func_0001A004(s32 arg0);
void func_0001A5B0(void);
void func_0001A87C(void);
void func_0001AD1C(void);
void func_0001B368(s32 arg0);
void func_0001B38C(s32 arg0);
void func_0001B3AC(s32 arg0);
void func_0001B440(void);
void func_0001B450(void);
void func_0001BB1C(void);
void func_000225B4(void);
void func_000225D8(void);
void func_000226AC(void);
void func_00024864(void);
void func_00024BB8(void);
void func_00024C30(void);
void func_00025F24(void);
void func_0002D058(s32 arg0);
void func_0002D1A4(s32 arg0, s32 arg1);
void func_0002D95C(void);
void func_0002DAEC(void);
void func_0002DC9C(void);
void func_0002EF10(void);
void func_0002F3F4(void);
void func_0002F428(void);
void func_0002F5E8(void);
void func_0002FB70(void);
void func_00030078(void);
void func_000300AC(void);
void func_000300DC(void);
void func_000304D4(void);
void func_000304DC(void);
void func_000304E4(void);
void func_000304EC(void);
void func_000306FC(void);
void func_00030CA0(void);

/* func_00000000 — 14 words. MATCH 100% (shape: m2c). */
s32 func_00000000(s32 arg0) {
    if (arg0 == 0) {
        ehsys_B4471B5E(func_00000038, func_00000138, &D_000528BC);
    }
    return 0;
}

/* func_00000138 — 15 words. MATCH 100% (shape: m2c). */
void func_00000138(void) {
    ehsys_5DF04F49(&D_00052040);
loop_1:
    if (func_0000A0B4() == 0) {
        ehsys_frame_sync();
        goto loop_1;
    }
}

/* func_00000388 — 2 words. MATCH 100% (shape: m2c). */
void func_00000388(void) {
    func_00009F70();
}

/* func_00000390 — 2 words. MATCH 100% (shape: m2c). */
void func_00000390(void) {

}

/* func_000003B8 — 2 words. MATCH 100% (shape: m2c). */
s32 func_000003B8(void) {
    return 0;
}

/* func_000003C0 — 12 words. MATCH 100% (shape: m2c). */
void func_000003C0(void) {
    ehsys_memset(&D_000528D0, 0, 0xB90);
    func_00000DBC();
}

/* func_000003F0 — 9 words. MATCH 100% (shape: m2c). */
void func_000003F0(void) {
    func_00000414();
    func_000003C0();
}

/* func_00000414 — 2 words. MATCH 100% (shape: m2c). */
void func_00000414(void) {
    func_00000DBC();
}

/* func_00001214 — 2 words. MATCH 100% (shape: m2c). */
void func_00001214(void) {

}

/* func_00002C20 — 15 words. MATCH 100% (shape: m2c). */
void func_00002C20(void) {
    ehsys_memset(&D_000536F8, 0, 0x28);
    ehsys_memset(&D_00053720, 0, 0x10);
}

/* func_00003788 — 12 words. MATCH 100% (shape: m2c). */
void func_00003788(void) {
    ehsys_memset(&D_00053858, 0, 4);
    func_00005CD8();
}

/* func_000037B8 — 9 words. MATCH 100% (shape: m2c). */
void func_000037B8(void) {
    func_00003944();
    func_00003788();
}

/* func_00003944 — 2 words. MATCH 100% (shape: m2c). */
void func_00003944(void) {
    func_00005CEC();
}

/* func_00003F14 — 9 words. MATCH 100% (shape: m2c). */
void func_00003F14(void) {
    func_00003F38();
    func_00003F00();
}

/* func_00003F38 — 2 words. MATCH 100% (shape: m2c). */
void func_00003F38(void) {

}

/* func_00004970 — 2 words. MATCH 100% (shape: m2c). */
s32 func_00004970(s32 arg0) {
    return arg0;
}

/* func_00004D60 — 9 words. MATCH 100% (shape: m2c). */
void func_00004D60(void) {
    func_00004D84();
    func_00004D4C();
}

/* func_00004D84 — 2 words. MATCH 100% (shape: m2c). */
void func_00004D84(void) {

}

/* func_00005204 — 9 words. MATCH 100% (shape: m2c). */
void func_00005204(void) {
    func_00005228();
    func_000051F0();
}

/* func_00005228 — 2 words. MATCH 100% (shape: m2c). */
void func_00005228(void) {

}

/* func_00005E88 — 2 words. MATCH 100% (shape: m2c). */
void func_00005E88(void) {

}

/* func_00005E90 — 2 words. MATCH 100% (shape: m2c). */
void func_00005E90(void) {

}

/* func_00005E98 — 9 words. MATCH 100% (shape: m2c). */
void func_00005E98(void) {
    ehsys_F5E3080C();
    func_000064A4();
}

/* func_00005EBC — 20 words. MATCH 100% (shape: m2c). */
void func_00005EBC(void) {
    ehsys_1EC5342B(func_000063DC(func_0000629C(func_00006080(ehsys_DFCA450B(0, 0)))));
    ehsys_4F22C9AA(2);
    ehsys_9EFDC9B9();
}

/* func_00005F0C — 11 words. MATCH 100% (shape: m2c). */
void func_00005F0C(void) {
    func_000063DC(func_0000629C(func_00006080()));
}

/* func_00006BC0 — 11 words. MATCH 100% (shape: m2c). */
void func_00006BC0(void) {
    func_0001B374();
    func_000132C8(0);
    func_000132C8(2);
}

/* func_00007C7C — 2 words. MATCH 100% (shape: m2c). */
void func_00007C7C(void) {

}

/* func_00007C94 — 2 words. MATCH 100% (shape: m2c). */
void func_00007C94(void) {

}

/* func_000087A8 — 2 words. MATCH 100% (shape: m2c). */
void func_000087A8(void) {

}

/* func_000088B0 — 2 words. MATCH 100% (shape: m2c). */
void func_000088B0(void) {

}

/* func_000095D8 — 2 words. MATCH 100% (shape: m2c). */
void func_000095D8(void) {

}

/* func_00009BAC — 2 words. MATCH 100% (shape: m2c). */
void func_00009BAC(void) {

}

/* func_0000A714 — 33 words. MATCH 100% (shape: m2c). */
void func_0000A714(void) {
    func_00005E74();
    func_00014B30();
    func_00016BAC();
    func_0000A958();
    func_000147B8();
    func_00003788();
    func_0000BB4C();
    func_0000DAF8();
    func_000003C0();
    func_00003F00();
    func_000051F0();
    func_00004D4C();
    func_000225A0();
    func_00024BB8();
}

/* func_0000A798 — 33 words. MATCH 100% (shape: m2c). */
void func_0000A798(void) {
    func_00016BE4();
    func_0000A9C4();
    func_0000BBA4();
    func_0000DC1C();
    func_00003944();
    func_000147F0();
    func_00003F38();
    func_00000414();
    func_00014B68();
    func_00005E90();
    func_00005228();
    func_00004D84();
    func_000225D8();
    func_00024C54();
}

/* func_0000A9A0 — 9 words. MATCH 100% (shape: m2c). */
void func_0000A9A0(void) {
    func_0000A9C4();
    func_0000A958();
}

/* func_0000B06C — 4 words. MATCH 100% (shape: m2c). */
s32 func_0000B06C(s32 *arg0, s32 *arg1) {
    return *arg1 - *arg0;
}

/* func_0000B9C0 — 3 words. MATCH 100% (shape: m2c). */
void func_0000B9C0(void) {
    func_00003384(&D_0005505C);
}

/* func_0000BA40 — 2 words. MATCH 100% (shape: m2c). */
void func_0000BA40(void) {

}

/* func_0000BAEC — 2 words. MATCH 100% (shape: m2c). */
void func_0000BAEC(void) {
    func_000101AC();
}

/* func_0000BAFC — 9 words. MATCH 100% (shape: m2c). */
s32 func_0000BAFC(void) {
    return ehsys_04E1CB0F() == 0;
}

/* func_0000BB80 — 9 words. MATCH 100% (shape: m2c). */
void func_0000BB80(void) {
    func_0000BBA4();
    func_0000BB4C();
}

/* func_0000D1FC — 2 words. MATCH 100% (shape: m2c). */
void func_0000D1FC(void) {

}

/* func_0000DBF8 — 9 words. MATCH 100% (shape: m2c). */
void func_0000DBF8(void) {
    func_0000DC1C();
    func_0000DAF8();
}

/* func_0000F4D8 — 2 words. MATCH 100% (shape: m2c). */
void func_0000F4D8(void) {
    func_0000747C();
}

/* func_00011730 — 2 words. MATCH 100% (shape: m2c). */
void func_00011730(void) {

}

/* func_00012FD4 — 21 words. MATCH 100% (shape: m2c). */
void func_00012FD4(void) {
    func_00013234();
    func_000139C0();
    func_00013ACC();
    func_00013BD0();
    func_00013C64();
    func_00013CFC();
    func_00013D90();
    func_00013E24();
}

/* func_00013EB8 — 13 words. MATCH 100% (shape: m2c). */
void func_00013EB8(s32 arg0) {
    ehsys_E58C0FDC(func_000132C8(7), arg0);
}

/* func_00013EEC — 13 words. MATCH 100% (shape: m2c). */
void func_00013EEC(s32 arg0) {
    ehsys_E58C0FDC(func_000132C8(5), arg0 + 0x32);
}

/* func_00013F20 — 13 words. MATCH 100% (shape: m2c). */
void func_00013F20(s32 arg0) {
    ehsys_E58C0FDC(func_000132C8(4), arg0);
}

/* func_000140DC — 16 words. MATCH 100% (shape: m2c). */
s32 func_000140DC(void) {
    if (func_000144F8() == 0) {
        func_00012BBC();
        return 0;
    }
    func_00012FD4();
    return 1;
}

/* func_00014490 — 26 words. MATCH 100% (shape: m2c). */
void func_00014490(s32 arg0, int arg1, int arg2) {
    int (*sp1C)(int, int, s32);
    s32 sp18;

loop_1:
    func_00014430(arg0, &sp1C, &sp18);
    if (sp1C != NULL) {
        sp1C(arg1, arg2, sp18);
        goto loop_1;
    }
}

/* func_000147CC — 9 words. MATCH 100% (shape: m2c). */
void func_000147CC(void) {
    func_000147F0();
    func_000147B8();
}

/* func_00014804 — 2 words. MATCH 100% (shape: m2c). */
void func_00014804(void) {

}

/* func_00014928 — 5 words. MATCH 100% (shape: m2c). */
void *func_00014928(s32 arg0) {
    return &D_0003DAE8 + (arg0 * 8);
}

/* func_00014B44 — 9 words. MATCH 100% (shape: m2c). */
void func_00014B44(void) {
    func_00014B68();
    func_00014B30();
}

/* func_00015534 — 12 words. MATCH 100% (shape: m2c). */
void func_00015534(void) {
    ehsys_memset(&D_B74450, 0, 0x2E0);
    func_0002D07C();
}

/* func_00016BA0 — 3 words. MATCH 100% (shape: m2c). */
s32 func_00016BA0(void) {
    return *(s32 *)0xB74720;
}

/* func_00016BC0 — 9 words. MATCH 100% (shape: m2c). */
void func_00016BC0(void) {
    func_00016BE4();
    func_00016BAC();
}

/* func_00018604 — 4 words. MATCH 100% (shape: m2c). */
s32 func_00018604(void) {
    return *(s32 *)0xB7473C != 0;
}

/* func_00019C54 — 9 words. MATCH 100% (shape: m2c). */
void func_00019C54(void) {
    func_0001A5B0();
    func_0001A87C();
}

/* func_00019C78 — 9 words. MATCH 100% (shape: m2c). */
void func_00019C78(void) {
    func_0001A190();
    func_0001A5B8();
}

/* func_0001A004 — 3 words. MATCH 100% (shape: m2c). */
void func_0001A004(s32 arg0) {
    *(s32 *)0xB7591C = arg0;
}

/* func_0001A12C — 5 words. MATCH 100% (shape: m2c). */
s32 func_0001A12C(void) {
    return *(s32 *)0xB758E4 == 2;
}

/* func_0001A5B0 — 2 words. MATCH 100% (shape: m2c). */
void func_0001A5B0(void) {

}

/* func_0001A87C — 2 words. MATCH 100% (shape: m2c). */
void func_0001A87C(void) {

}

/* func_0001AD1C — 15 words. MATCH 100% (shape: m2c). */
void func_0001AD1C(void) {
    *(s32 *)0xB75AA0 = 0;
    ehsys_5DF04F49(&D_B75948);
    ehsys_memset(&D_B75940, 0, 0x184);
}

/* func_0001B35C — 3 words. MATCH 100% (shape: m2c). */
s32 func_0001B35C(void) {
    return *(s32 *)0xB75A90;
}

/* func_0001B368 — 3 words. MATCH 100% (shape: m2c). */
void func_0001B368(s32 arg0) {
    *(s32 *)0xB75AA0 = arg0;
}

/* func_0001B38C — 3 words. MATCH 100% (shape: m2c). */
void func_0001B38C(s32 arg0) {
    *(s32 *)0xB75AA8 = arg0;
}

/* func_0001B3AC — 3 words. MATCH 100% (shape: m2c). */
void func_0001B3AC(s32 arg0) {
    *(s32 *)0xB75A30 = arg0;
}

/* func_0001B440 — 4 words. MATCH 100% (shape: m2c). */
void func_0001B440(void) {
    *(s32 *)0xB75940 = 1;
}

/* func_0001B450 — 4 words. MATCH 100% (shape: m2c). */
void func_0001B450(void) {
    *(s32 *)0xB75940 = 3;
}

/* func_0001B460 — 4 words. MATCH 100% (shape: m2c). */
s32 func_0001B460(void) {
    return *(s32 *)0xB75940 != 0;
}

/* func_0001B528 — 13 words. MATCH 100% (shape: m2c). */
s32 func_0001B528(void) {
    s32 temp_v1;

    temp_v1 = *(s32 *)0xB75940;
    if ((temp_v1 != 3) && (temp_v1 != 1)) {
        return 0;
    }
    return 1;
}

/* func_0001BB1C — 9 words. MATCH 100% (shape: m2c). */
void func_0001BB1C(void) {
    ehsys_06380DFA();
    ehsys_AB962AE7(0);
}

/* func_000225B4 — 9 words. MATCH 100% (shape: m2c). */
void func_000225B4(void) {
    func_000225D8();
    func_000225A0();
}

/* func_000225D8 — 2 words. MATCH 100% (shape: m2c). */
void func_000225D8(void) {

}

/* func_000226AC — 23 words. MATCH 100% (shape: m2c). */
void func_000226AC(void) {
    s32 sp1C;
    s32 temp_v0;

    if (*(s32 *)0xB75AE8 != 0) {
        temp_v0 = ehsys_DFCA450B(4, 0);
        sp1C = temp_v0;
        sp1C = ehsys_4175E3DB(temp_v0, 1);
        ehsys_878EE1D3(&sp1C);
        ehsys_1EC5342B(sp1C);
        ehsys_C5BDA06E();
    }
}

/* func_00024864 — 2 words. MATCH 100% (shape: m2c). */
void func_00024864(void) {
    func_00024754();
}

/* func_00024BB8 — 30 words. MATCH 100% (shape: m2c). */
void func_00024BB8(void) {
    s32 temp_v0;
    s32 temp_v0_2;

    ehsys_memset(&D_B75AF0, 0, 0x501C);
    *(s32 *)0xB7AB00 = 1;
    temp_v0 = ehsys_D2A768F4(3, &D_00048F18);
    temp_v0_2 = func_00013028(temp_v0);
    *(s32 *)0xB7AB04 = temp_v0_2;
    ehsys_BF3E9066(3, &D_00048F18, temp_v0_2, temp_v0);
}

/* func_00024C30 — 9 words. MATCH 100% (shape: m2c). */
void func_00024C30(void) {
    func_00024C54();
    func_00024BB8();
}

/* func_00025F24 — 3 words. MATCH 100% (shape: m2c). */
void func_00025F24(void) {
    func_00003384(&D_B7AB00);
}

/* func_0002D058 — 3 words. MATCH 100% (shape: m2c). */
void func_0002D058(s32 arg0) {
    *(s32 *)0xB7AB28 = arg0;
}

/* func_0002D1A4 — 16 words. MATCH 100% (shape: m2c). */
void func_0002D1A4(s32 arg0, s32 arg1) {
    ehsys_025FE238(&D_B7AB44, arg0);
    ehsys_025FE238(&D_B7AD44, arg1);
}

/* func_0002D95C — 2 words. MATCH 100% (shape: m2c). */
void func_0002D95C(void) {

}

/* func_0002DAEC — 13 words. MATCH 100% (shape: m2c). */
void func_0002DAEC(void) {
    ehsys_5DF04F49(&D_B7AF6C);
    ehsys_memset(&D_B7AF5C, 0, 0xF0);
}

/* func_0002DC9C — 18 words. MATCH 100% (shape: m2c). */
void func_0002DC9C(void) {
    ehsys_D853F15C(1);
    ehsys_C792FA38(0);
    ehsys_C9D9E989(1);
    ehsys_4AA58320(1);
    ehsys_942B03D0(0xE, 0xE);
    ehsys_60B55A50(0xFF000000);
}

/* func_0002EBA8 — 5 words. MATCH 100% (shape: m2c). */
s32 func_0002EBA8(void) {
    return *(s32 *)0xB7B064 != 3;
}

/* func_0002EF10 — 16 words. MATCH 100% (shape: m2c). */
void func_0002EF10(void) {
    ehsys_D853F15C(1);
    ehsys_C792FA38(0);
    ehsys_C9D9E989(1);
    ehsys_942B03D0(0xF, 0xF);
    ehsys_60B55A50(0xFF000000);
}

/* func_0002F02C — 4 words. MATCH 100% (shape: m2c). */
s32 func_0002F02C(s32 arg0) {
    return *(s32 *)0xB7B0A4 + arg0;
}

/* func_0002F03C — 4 words. MATCH 100% (shape: m2c). */
s32 func_0002F03C(s32 arg0) {
    return arg0 - *(s32 *)0xB7B0A4;
}

/* func_0002F3F4 — 13 words. MATCH 100% (shape: m2c). */
void func_0002F3F4(void) {
    ehsys_5DF04F49(&D_B7B188);
    ehsys_memset(&D_B7B17C, 0, 0xD4);
}

/* func_0002F428 — 18 words. MATCH 100% (shape: m2c). */
void func_0002F428(void) {
    ehsys_D853F15C(1);
    ehsys_C792FA38(0);
    ehsys_C9D9E989(1);
    ehsys_4AA58320(1);
    ehsys_942B03D0(0xE, 0xE);
    ehsys_60B55A50(0xFF000000);
}

/* func_0002F5E8 — 2 words. MATCH 100% (shape: m2c). */
void func_0002F5E8(void) {

}

/* func_0002FB70 — 4 words. MATCH 100% (shape: m2c). */
void func_0002FB70(void) {
    *(s32 *)0xB7B250 = 1;
}

/* func_00030078 — 13 words. MATCH 100% (shape: m2c). */
void func_00030078(void) {
    ehsys_D853F15C(1);
    ehsys_C792FA38(0);
    ehsys_C9D9E989(1);
    ehsys_4AA58320(1);
}

/* func_000300AC — 12 words. MATCH 100% (shape: m2c). */
void func_000300AC(void) {
    func_00030078();
    ehsys_942B03D0(0xE, 0xE);
    ehsys_60B55A50(-1);
}

/* func_000300DC — 12 words. MATCH 100% (shape: m2c). */
void func_000300DC(void) {
    func_00030078();
    ehsys_942B03D0(0xE, 0xE);
    ehsys_60B55A50(0xFF000000);
}

/* func_000304D4 — 2 words. MATCH 100% (shape: m2c). */
void func_000304D4(void) {
    func_0002F5E8();
}

/* func_000304DC — 2 words. MATCH 100% (shape: m2c). */
void func_000304DC(void) {
    func_0002F5F0();
}

/* func_000304E4 — 2 words. MATCH 100% (shape: m2c). */
void func_000304E4(void) {
    func_0002F60C();
}

/* func_000304EC — 2 words. MATCH 100% (shape: m2c). */
void func_000304EC(void) {
    func_0002F614();
}

/* func_000306FC — 3 words. MATCH 100% (shape: m2c). */
void func_000306FC(void) {
    func_00030138(&D_B7B38C);
}

/* func_00030CA0 — 18 words. MATCH 100% (shape: m2c). */
void func_00030CA0(void) {
    ehsys_D853F15C(1);
    ehsys_C792FA38(0);
    ehsys_C9D9E989(1);
    ehsys_4AA58320(1);
    ehsys_942B03D0(0xE, 0xE);
    ehsys_60B55A50(0xFF000000);
}

