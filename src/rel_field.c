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
 * STATUS: 233 functions matched here. The rest of the module is not
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
extern int D_0005FE44;
extern void * D_0005F688;
extern void * D_B75994;
extern void * D_B75AAC;
extern void * D_B7AB2C;
extern char D_0003DAE8;
extern char D_00048F18;
extern char D_00052040;
extern int D_00052868;
extern char D_000528BC;
extern int D_000528D0;
extern int D_000528D4;
extern int D_000528D8;
extern int D_000528DC;
extern int D_000528E0;
extern int D_000536F8;
extern int D_00053720;
extern int D_00053728;
extern int D_00053858;
extern int D_0005385C;
extern int D_00053860;
extern u16 D_00053948;
extern int D_000539B0;
extern int D_000539CC;
extern int D_000539D0;
extern int D_000539D4;
extern int D_000539EC;
extern int D_000539F0;
extern int D_000539F4;
extern int D_000539F8;
extern int D_000539FC;
extern int D_00053A40;
extern int D_00053A50;
extern int D_00054650;
extern int D_00054654;
extern int D_000546CC;
extern int D_000546D0;
extern int D_0005496C;
extern int D_00054A1C;
extern int D_00054A2C;
extern int D_00054A60;
extern int D_00054BC0;
extern int D_00054BD0;
extern int D_00054BD4;
extern int D_00054BD8;
extern int D_00054BDC;
extern int D_00054BE0;
extern int D_00054BE4;
extern int D_00054BE8;
extern int D_00054BEC;
extern int D_00054BF0;
extern int D_00054C20;
extern int D_00054C24;
extern int D_00054C2C;
extern int D_0005505C;
extern f32 D_0005507C;
extern int D_00055084;
extern f32 D_00055088;
extern int D_00055098;
extern int D_000550A0;
extern int D_000550A4;
extern int D_0005F4C8;
extern int D_0005F5D0;
extern int D_0005F650;
extern int D_0005F654;
extern int D_0005F658;
extern int D_0005F664;
extern int D_0005F668;
extern int D_0005F670;
extern int D_0005F6E8;
extern int D_0005F758;
extern int D_0005F75C;
extern int D_0005F760;
extern int D_0005F890;
extern int D_0005F8E4;
extern int D_0005F8E8;
extern int D_B71070;
extern int D_B71E00;
extern int D_B74450;
extern int D_B74730;
extern char D_B75940;
extern char D_B75948;
extern int D_B75AE4;
extern char D_B75AF0;
extern char D_B7AB00;
extern char D_B7AB44;
extern char D_B7AD44;
extern char D_B7AF5C;
extern char D_B7AF6C;
extern char D_B7B17C;
extern char D_B7B188;
extern char D_B7B250;
extern char D_B7B268;
extern char D_B7B29C;
extern char D_B7B374;
extern char D_B7B38C;
extern char D_B7B3C0;
extern int ehsys_025FE238();
extern int ehsys_04E1CB0F();
extern int ehsys_06380DFA();
extern int ehsys_1EC5342B();
extern int ehsys_31D0BD26();
extern int ehsys_4175E3DB();
extern int ehsys_42110BF9();
extern int ehsys_4AA58320();
extern int ehsys_4F22C9AA();
extern int ehsys_578BC0A3();
extern int ehsys_5DF04F49();
extern int ehsys_60B55A50();
extern int ehsys_8174A2CB();
extern int ehsys_878EE1D3();
extern int ehsys_942B03D0();
extern int ehsys_942E589C();
extern int ehsys_9EFDC9B9();
extern int ehsys_A84EDF3B();
extern int ehsys_AB962AE7();
extern int ehsys_B4471B5E();
extern int ehsys_BC8E65D7();
extern int ehsys_BF3E9066();
extern int ehsys_C0AB60EF();
extern int ehsys_C5BDA06E();
extern int ehsys_C62F9EAC();
extern int ehsys_C792FA38();
extern int ehsys_C9D9E989();
extern int ehsys_D2A768F4();
extern int ehsys_D4DE5DD8();
extern int ehsys_D853F15C();
extern int ehsys_DFCA450B();
extern int ehsys_E11E4575();
extern int ehsys_E58C0FDC();
extern int ehsys_F462EE6E();
extern int ehsys_F5E3080C();
extern int ehsys_frame_sync();
extern int ehsys_memset();
extern int func_00000038();
extern int func_00000DBC();
extern int func_00006080();
extern int func_0000629C();
extern int func_000063DC();
extern int func_000064A4();
extern int func_0000747C();
extern int func_00007A98();
extern int func_00009F70();
extern int func_0000A0B4();
extern int func_0000A9C4();
extern int func_0000BB4C();
extern int func_0000BBA4();
extern int func_0000DAF8();
extern int func_0000DC1C();
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
extern int func_00014B68();
extern int func_00016BE4();
extern int func_0001A190();
extern int func_0001A5B8();
extern int func_00024754();
extern int func_00024C54();
extern int func_0002D07C();
extern int func_0002F5F0();
extern int func_0002F614();
extern int func_00030138();
extern int ehsys_20E340D9();
extern int func_00013420();
extern int ehsys_3BB2BAC6();
extern int ehsys_B89D38DC();
extern int ehsys_97BB99A5();
extern int func_0002D520();
extern int func_0003027C();

/* ---- forward declarations ---- */
s32 func_00013038(s32 arg0);
s32 func_00013908(s32 arg0, s32 arg1, s32 arg2);
s32 func_00013924(s32 arg0, s32 arg1, s32 arg2);
s32 func_00015504(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
s32 func_00015520(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_00017DF8(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_0001B340(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
s32 func_0001C1A4(s32 arg0, s32 arg1, s32 arg2);
s32 func_0001C33C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
s32 func_0001DB88(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_00024850(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_00029F60(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_0002D044(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_0002D950(s32 arg0, s32 arg1);
s32 func_0002DAD0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
s32 func_0002E35C(s32 arg0, s32 arg1, s32 arg2);
s32 func_0002E370(s32 arg0, s32 arg1, s32 arg2);
s32 func_0002EEFC(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_0002EF50(void);
s32 func_0002F3E0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_0002FAF8(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_0002FD58(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
s32 func_0003006C(s32 arg0, s32 arg1);
s32 func_00030708(s32 arg0);
s32 func_0003092C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
s32 func_00030C94(s32 arg0, s32 arg1);
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
void func_000304D4();
void func_000304DC();
void func_000304E4(u16 *arg0);
void func_000304EC();
void func_000306FC(void);
void func_00030CA0(void);

void func_00000398(s32 arg0, s32 arg1, s32 arg2);
u8 func_000008A8(void);
u8 func_000008F4(void);
u8 func_00000AA8(void);
u8 func_00000B54(void);
u8 func_00000BDC(void);
int *func_00002C5C(void);
void func_00003384(s32 *arg0);
int *func_00003478(void);
int *func_00003484(void);
u8 func_00003DD4(void);
int func_00003F00(void);
u8 func_00004288(void);
u8 func_0000494C(int *a0);
void func_00004D28(int a0);
int func_00004D34(int *a0);
int func_00004D4C(void);
u8 func_000050F4(void);
int func_000051F0(void);
void func_00005684(void);
int func_000056BC(void);
void func_000058C8(int a0);
void func_000058D4(int a0);
int func_00005CD8(void);
int func_00005CEC(void);
int func_00005E20(void *a0);
int func_00005E74(void);
void func_00005FC8(int a0);
u8 func_0000603C(void);
void func_00006054(void);
u8 func_00006068(void);
int func_00006658(void);
int func_00007864(int a0);
void func_00007C84(void);
void *func_00007DA0(f32 *a0, f32 *a1);
int func_00008794(s32 a0, s32 a1, s32 a2, s32 a3);
void func_000088B8(void);
void func_000095E0(void);
int func_00009D90(void);
u8 func_0000A2D0(void);
u8 func_0000A330(void);
u8 func_0000A400(void);
u8 func_0000A4B0(void);
u8 func_0000A570(void);
u8 func_0000A5B8(void);
u8 func_0000A6BC(void);
int func_0000A6D4(s32 *a0);
u8 func_0000A6DC(void);
int func_0000A6F4(s32 *a0);
u8 func_0000A6FC(void);
int func_0000A958(void);
u8 func_0000AFB8(void);
u8 func_0000AFFC(void);
void func_0000B014(f32 *a0, f32 a1, f32 a2);
int func_0000B060(void);
f32 func_0000B288(void);
int func_0000B294(void);
void func_0000B2A0(int a0);
void func_0000BA48(f32 *a0, f32 a1);
int func_0000BAF4(void);
u8 func_0000C5B0(void);
u8 func_0000C718(void);
int func_0000D634(void);
void func_0000D644(void);
void **func_000101AC(void);
u8 func_00010324(void);
u8 func_00010358(void);
u8 func_0001041C(void);
u8 func_00010DD0(void);
u8 func_00010DE8(void);
int *func_00010E00(void);
int func_00010E0C(void);
int func_000116CC(void);
int func_000116DC(void);
int func_000116EC(void);
void func_0001181C(void);
int func_00011980(void);
u8 func_00011A48(void);
int func_000147B8(void);
int func_000147F0(void);
u8 func_00014A7C(void);
int func_00014B30(void);
int func_00015564(void);
int func_00016BAC(void);
void **func_0001B374(void);
void **func_0001B380(void);
int func_000225A0(void);
void **func_0002D198(void);
void func_0002D1E4(void ***arg0, void ***arg1);
void func_0002FB0C(void);
void func_0002FB80(void);
void func_00030714(void);
void func_00030754(s32 arg0);
void func_00030764(void);
void func_00030770(s32 arg0);
void func_00035F50(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

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

/* func_00000398 — 8 words. MATCH 100% (verified). */
void func_00000398(s32 arg0, s32 arg1, s32 arg2) {
    (&D_00052868)[arg1] += arg2;
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

/* func_000008A8 — 6 words. MATCH 100% (verified). */
u8 func_000008A8(void) {
    return !D_000528D0;
}

/* func_000008C0 — 13 words. MATCH 100% (verified). */
void func_000008C0(void) {
    extern int func_00013C64();
    extern int func_00000DBC();
    extern s32 D_000528D4;
    D_000528D4 = 1;
    func_00013C64();
    func_00000DBC();
    D_000528D4 = 0;
}

/* func_000008F4 — 6 words. MATCH 100% (verified). */
u8 func_000008F4(void) {
    return !D_000528D4;
}

/* func_00000AA8 — 6 words. MATCH 100% (verified). */
u8 func_00000AA8(void) {
    return !D_000528D8;
}

/* func_00000B54 — 6 words. MATCH 100% (verified). */
u8 func_00000B54(void) {
    return !D_000528DC;
}

/* func_00000BDC — 6 words. MATCH 100% (verified). */
u8 func_00000BDC(void) {
    return !D_000528E0;
}

/* func_00000DBC — 20 words. MATCH 100% (verified). */
extern void func_00000E0C(void *arg0);
int func_00000DBC(void) {
    extern s32 D_000528D0;
    s32 i;
    char *s0 = (char *)&D_000528D0;
    for (i = 0; i < 0xB; i++) {
        func_00000E0C(s0 + (i << 8) + 0x70);
    }
}

/* func_00001214 — 2 words. MATCH 100% (shape: m2c). */
void func_00001214(void) {

}

/* func_00002C20 — 15 words. MATCH 100% (shape: m2c). */
void func_00002C20(void) {
    ehsys_memset(&D_000536F8, 0, 0x28);
    ehsys_memset(&D_00053720, 0, 0x10);
}

/* func_00002C5C — 3 words. MATCH 100% (verified). */
int *func_00002C5C(void) {
    return &D_000536F8;
}

/* func_00002CB0 — 16 words. MATCH 100% (verified). */
extern f32 ehsys_8D0CE141(f32);
extern f32 ehsys_317716E5(f32);
f32 func_00002CB0(f32 *arg0) {
    f32 sum = arg0[0] * arg0[0] + arg0[1] * arg0[1] + arg0[2] * arg0[2];
    return ehsys_317716E5(ehsys_8D0CE141(sum));
}

/* func_00002D50 — 40 words. MATCH 100% (verified). */
extern int ehsys_23E69878();
extern int ehsys_8EA6B1E7();
extern int ehsys_FDD168CA();

int func_00002D50(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 temp_v0;

    temp_v0 = ehsys_4175E3DB(arg0, 9);
    temp_v0 = ehsys_23E69878(temp_v0, arg5);
    temp_v0 = ehsys_8EA6B1E7(temp_v0, 1, 1, arg3, arg4);
    return ehsys_FDD168CA(temp_v0, arg1, arg2, 0, 0, 0, 0, 0);
}

/* func_00002DF0 — 8 words. MATCH 100% (verified). */
extern void func_00002E10(s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_00002DF0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    func_00002E10(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg5, arg6);
}

/* func_00002E10 — 31 words. MATCH 100% (verified). */
void func_00002E10(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    s32 v0 = ehsys_8EA6B1E7(arg0, arg5, arg6, arg7, arg8);
    ehsys_FDD168CA(v0, arg1, arg2, 0, arg3, arg4, 0, 0);
}

/* func_00003384 — 20 words. MATCH 100% (verified). */
void func_00003384(s32 *arg0) {
    while (!*arg0) {
        ehsys_E11E4575(4);
        ehsys_8174A2CB();
    }
    ehsys_E11E4575(4);
}

/* func_00003478 — 3 words. MATCH 100% (verified). */
int *func_00003478(void) {
    return &D_00053720;
}

/* func_00003484 — 3 words. MATCH 100% (verified). */
int *func_00003484(void) {
    return &D_00053728;
}

/* func_000036F0 — 22 words. MATCH 100% (verified). */
extern s32 ehsys_39ADDA9F(void *);
extern void ehsys_E1139F1A(void *);
s32 func_000036F0(void) {
    extern s32 D_00053730;
    extern s32 D_00053854;
    void *s1 = &D_00053730;
    s32 s0 = ehsys_39ADDA9F(s1);
    if (s0 != -1) {
        ehsys_E1139F1A(s1);
        D_00053854 = 0;
    }
    return s0;
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

/* func_00003B00 — 8 words. MATCH 100% (verified). */
typedef struct { f32 a, b, c; } V3_3B00;
void *func_00003B00(V3_3B00 *arg0, V3_3B00 *arg1) {
    arg0->a = arg1->a;
    arg0->b = arg1->b;
    arg0->c = arg1->c;
    return arg0;
}

/* func_00003DA8 — 11 words. MATCH 100% (verified). */
void func_00003DA8(void) {
    extern int func_000139C0();
    extern s32 D_00053858;
    D_00053858 = 1;
    func_000139C0();
    D_00053858 = 0;
}

/* func_00003DD4 — 6 words. MATCH 100% (verified). */
u8 func_00003DD4(void) {
    return !D_00053858;
}

/* func_00003EE0 — 8 words. MATCH 100% (verified). */
s32 func_00003EE0(s32 arg0, s32 arg1, s32 arg2) {
    return ehsys_B89D38DC(arg0 << 6, arg1 << 6, (0x1E0 - arg0) << 6, arg2);
}

/* func_00003F00 — 5 words. MATCH 100% (verified). */
int func_00003F00(void) {
    return ehsys_memset(&D_0005385C, 0, 0x178);
}

/* func_00003F14 — 9 words. MATCH 100% (shape: m2c). */
void func_00003F14(void) {
    func_00003F38();
    func_00003F00();
}

/* func_00003F38 — 2 words. MATCH 100% (shape: m2c). */
void func_00003F38(void) {

}

/* func_00004288 — 6 words. MATCH 100% (verified). */
u8 func_00004288(void) {
    return !D_0005385C;
}

/* func_0000494C — 9 words. MATCH 100% (verified). */
u8 func_0000494C(int *a0) {
    *a0 = D_000539B0;
    return !D_00053860;
}

/* func_00004970 — 2 words. MATCH 100% (shape: m2c). */
s32 func_00004970(s32 arg0) {
    return arg0;
}

/* func_00004D28 — 3 words. MATCH 100% (verified). */
void func_00004D28(int a0) {
    D_000539D0 = a0;
}

/* func_00004D34 — 6 words. MATCH 100% (verified). */
int func_00004D34(int *a0) {
    *a0 = D_00053948;
    return D_000539CC;
}

/* func_00004D4C — 5 words. MATCH 100% (verified). */
int func_00004D4C(void) {
    return ehsys_memset(&D_000539D4, 0, 0x18);
}

/* func_00004D60 — 9 words. MATCH 100% (shape: m2c). */
void func_00004D60(void) {
    func_00004D84();
    func_00004D4C();
}

/* func_00004D84 — 2 words. MATCH 100% (shape: m2c). */
void func_00004D84(void) {

}

/* func_000050F4 — 6 words. MATCH 100% (verified). */
u8 func_000050F4(void) {
    return !D_000539D4;
}

/* func_0000510C — 10 words. MATCH 100% (verified). */
void func_0000510C(s32 *arg0) {
    extern s32 D_000539DC;
    char *a1 = (char *)&D_000539D4;
    s32 v = *arg0;
    D_000539DC = v;
    if (v != 0) {
        *(s32 *)(a1 + 4) = 1;
    }
}

/* func_000051F0 — 5 words. MATCH 100% (verified). */
int func_000051F0(void) {
    return ehsys_memset(&D_000539EC, 0, 0x14);
}

/* func_00005204 — 9 words. MATCH 100% (shape: m2c). */
void func_00005204(void) {
    func_00005228();
    func_000051F0();
}

/* func_00005228 — 2 words. MATCH 100% (shape: m2c). */
void func_00005228(void) {

}

/* func_00005684 — 14 words. MATCH 100% (verified). */
void func_00005684(void) {
    D_000539EC = 1;
    D_000539F0 = 0xFF000000;
    D_000539F4 = 0xFF000000;
    D_000539F8 = -1;
    D_000539FC = 0;
}

/* func_000056BC — 5 words. MATCH 100% (verified). */
int func_000056BC(void) {
    return D_000539EC == 0;
}

/* func_000057A0 — 8 words. MATCH 100% (verified). */
s32 func_000057A0(s32 arg0, s32 arg1, s32 arg2) {
    return ehsys_B89D38DC(arg0 << 6, arg1 << 6, (0x1E0 - arg0) << 6, arg2);
}

/* func_000058A0 — 10 words. MATCH 100% (verified). */
typedef struct { f32 a, b, c, d; } V4_58A0;
void *func_000058A0(V4_58A0 *arg0, V4_58A0 *arg1) {
    arg0->a = arg1->a;
    arg0->b = arg1->b;
    arg0->c = arg1->c;
    arg0->d = arg1->d;
    return arg0;
}

/* func_000058C8 — 3 words. MATCH 100% (verified). */
void func_000058C8(int a0) {
    D_00053A40 = a0;
}

/* func_000058D4 — 31 words. MATCH 100% (verified). */
void func_000058D4(int a0) {
    ehsys_942E589C(ehsys_F462EE6E(ehsys_578BC0A3(ehsys_F462EE6E(ehsys_C0AB60EF(ehsys_4175E3DB(ehsys_C62F9EAC(ehsys_42110BF9(a0, 0), 2), 9), 1), 3), 1, 0, 0xFF), 5), 0xFFFFFF);
}

/* func_00005CD8 — 5 words. MATCH 100% (verified). */
int func_00005CD8(void) {
    return ehsys_memset(&D_00053A50, 0, 0xC00);
}

/* func_00005CEC — 5 words. MATCH 100% (verified). */
int func_00005CEC(void) {
    return ehsys_memset(&D_00053A50, 0, 0xC00);
}

/* func_00005E20 — 3 words. MATCH 100% (verified). */
int func_00005E20(void *a0) {
    return ehsys_memset(a0, 0, 0x60);
}

/* func_00005E74 — 5 words. MATCH 100% (verified). */
int func_00005E74(void) {
    return ehsys_memset(&D_00054650, 0, 0x80);
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

/* func_00005FC8 — 3 words. MATCH 100% (verified). */
void func_00005FC8(int a0) {
    D_000546CC = a0;
}

/* func_0000603C — 6 words. MATCH 100% (verified). */
u8 func_0000603C(void) {
    return !D_00054650;
}

/* func_00006054 — 5 words. MATCH 100% (verified). */
void func_00006054(void) {
    D_00054650 = 0;
    D_00054654 = 0;
}

/* func_00006068 — 6 words. MATCH 100% (verified). */
u8 func_00006068(void) {
    return !D_00054654;
}

/* func_00006658 — 5 words. MATCH 100% (verified). */
int func_00006658(void) {
    return ehsys_memset(&D_000546D0, 0, 0x1A0);
}

/* func_0000666C — 15 words. MATCH 100% (verified). */
extern void ehsys_60BA0722(s32);
extern void ehsys_BFFBA174(void);
void func_0000666C(void) {
    extern s32 D_000547E0;
    extern s32 D_000546D0;
    ehsys_60BA0722(D_000547E0);
    ehsys_BFFBA174();
    ehsys_memset(&D_000546D0, 0, 0x1A0);
}

/* func_000066A8 — 21 words. MATCH 100% (verified). */
extern void func_00006B74(void);
extern void func_00006BEC(void);
void func_000066A8(void) {
    extern s32 D_000547DC;
    switch (D_000547DC) {
        case 1:
            func_00006B74();
            break;
        case 2:
            func_00006BEC();
            break;
    }
}

/* func_00006918 — 21 words. MATCH 100% (verified). */
extern s32 func_0001B528(void);
void func_00006918(s32 *arg0) {
    extern s32 D_000546D4;
    extern s32 D_000546D0;
    char *s0 = (char *)&D_000546D0;
    if (D_000546D4 != 0) {
        if (func_0001B528() == 0) {
            *(s32 *)(s0 + 0x10C) = 0;
            *arg0 = 0;
        }
    }
}

/* func_00006B74 — 19 words. MATCH 100% (verified). */
extern s32 func_0001B35C(void);
extern void func_0001B450(void);
void func_00006B74(void) {
    extern s32 D_000546D0;
    char *s0 = (char *)&D_000546D0;
    if (func_0001B35C() != 0) {
        if (*(s32 *)(s0 + 0x194) != 0) {
            func_0001B450();
        }
        *(s32 *)(s0 + 4) = 1;
    }
}

/* func_00006BC0 — 11 words. MATCH 100% (shape: m2c). */
void func_00006BC0(void) {
    func_0001B374();
    func_000132C8(0);
    func_000132C8(2);
}

/* func_000071F0 — 13 words. MATCH 100% (verified). */
void func_000071F0(void) {
    extern s32 D_00054870;
    extern s32 D_00054A60;
    ehsys_memset(&D_00054870, 0, 0x360);
    D_00054A60 = 1;
}

/* func_00007864 — 3 words. MATCH 100% (verified). */
int func_00007864(int a0) {
    D_00054A60 = a0;
}

/* func_00007C7C — 2 words. MATCH 100% (shape: m2c). */
void func_00007C7C(void) {

}

/* func_00007C84 — 4 words. MATCH 100% (verified). */
void func_00007C84(void) {
    D_0005496C = 1;
}

/* func_00007C94 — 2 words. MATCH 100% (shape: m2c). */
void func_00007C94(void) {

}

/* func_00007DA0 — 6 words. MATCH 100% (verified). */
void *func_00007DA0(f32 *a0, f32 *a1) {
    a0[0] = a1[0];
    a0[1] = a1[1];
    return a0;
}

/* func_00008794 — 5 words. MATCH 100% (verified). */
int func_00008794(s32 a0, s32 a1, s32 a2, s32 a3) {
    return ehsys_BC8E65D7(a0 << 6, a1 << 6, a2 << 6, a3, -1);
}

/* func_000087A8 — 2 words. MATCH 100% (shape: m2c). */
void func_000087A8(void) {

}

/* func_000088B0 — 2 words. MATCH 100% (shape: m2c). */
void func_000088B0(void) {

}

/* func_000088B8 — 4 words. MATCH 100% (verified). */
void func_000088B8(void) {
    D_00054A1C = 1;
}

/* func_000095D8 — 2 words. MATCH 100% (shape: m2c). */
void func_000095D8(void) {

}

/* func_000095E0 — 4 words. MATCH 100% (verified). */
void func_000095E0(void) {
    D_00054A2C = 1;
}

/* func_00009BAC — 2 words. MATCH 100% (shape: m2c). */
void func_00009BAC(void) {

}

/* func_00009D90 — 4 words. MATCH 100% (verified). */
int func_00009D90(void) {
    D_00054BC0 = 1;
    return 1;
}

/* func_0000A2D0 — 6 words. MATCH 100% (verified). */
u8 func_0000A2D0(void) {
    return !D_00054BD0;
}

/* func_0000A330 — 6 words. MATCH 100% (verified). */
u8 func_0000A330(void) {
    return !D_00054BD4;
}

/* func_0000A400 — 6 words. MATCH 100% (verified). */
u8 func_0000A400(void) {
    return !D_00054BD8;
}

/* func_0000A4B0 — 6 words. MATCH 100% (verified). */
u8 func_0000A4B0(void) {
    return !D_00054BDC;
}

/* func_0000A570 — 6 words. MATCH 100% (verified). */
u8 func_0000A570(void) {
    return !D_00054BE0;
}

/* func_0000A588 — 12 words. MATCH 100% (verified). */
void func_0000A588(void **arg0) {
    extern int func_0001A010();
    extern s32 D_00054BE4;
    func_0001A010(*arg0, 0xC8, 0x64);
    D_00054BE4 = 1;
}

/* func_0000A5B8 — 6 words. MATCH 100% (verified). */
u8 func_0000A5B8(void) {
    return !D_00054BE4;
}

/* func_0000A6BC — 6 words. MATCH 100% (verified). */
u8 func_0000A6BC(void) {
    return !D_00054BE8;
}

/* func_0000A6D4 — 2 words. MATCH 100% (verified). */
int func_0000A6D4(s32 *a0) {
    return func_00007864(*a0);
}

/* func_0000A6DC — 6 words. MATCH 100% (verified). */
u8 func_0000A6DC(void) {
    return !D_00054BEC;
}

/* func_0000A6F4 — 2 words. MATCH 100% (verified). */
int func_0000A6F4(s32 *a0) {
    return func_00007A98(*a0);
}

/* func_0000A6FC — 6 words. MATCH 100% (verified). */
u8 func_0000A6FC(void) {
    return !D_00054BF0;
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

/* func_0000A958 — 18 words. MATCH 100% (verified). */
int func_0000A958(void) {
    ehsys_memset(&D_00054C20, 0, 0x480);
    D_0005505C = 1;
    func_0000BA48(&D_00055088, 0.0f);
    return 1;
}

/* func_0000A9A0 — 9 words. MATCH 100% (shape: m2c). */
void func_0000A9A0(void) {
    func_0000A9C4();
    func_0000A958();
}

/* func_0000AE44 — 24 words. MATCH 100% (verified). */
extern s32 ehsys_85F89FE8(s32);
extern s32 func_0000B9CC(s32, void *);
extern s32 ehsys_89812D8A(s32);
void func_0000AE44(void) {
    extern s32 D_00055044;
    char *s0 = (char *)&D_00054C20;
    if (D_00055044 != 0) {
        s32 v0 = ehsys_DFCA450B(1, 0);
        v0 = ehsys_85F89FE8(v0);
        v0 = func_0000B9CC(v0, s0 + 0x448);
        v0 = ehsys_89812D8A(v0);
        ehsys_1EC5342B(v0);
    }
}

/* func_0000AEA4 — 24 words. MATCH 100% (verified). */
void func_0000AEA4(void) {
    extern s32 ehsys_85F89FE8(s32);
    extern s32 func_0000B9CC(s32, void *);
    extern s32 ehsys_89812D8A(s32);
    extern s32 D_00055044;
    char *s0 = (char *)&D_00054C20;
    if (D_00055044 != 0) {
        s32 v0 = ehsys_DFCA450B(1, 0);
        v0 = ehsys_85F89FE8(v0);
        v0 = func_0000B9CC(v0, s0 + 0x440);
        v0 = ehsys_89812D8A(v0);
        ehsys_1EC5342B(v0);
    }
}

/* func_0000AFB8 — 6 words. MATCH 100% (verified). */
u8 func_0000AFB8(void) {
    return !D_00054C20;
}

/* func_0000AFD0 — 11 words. MATCH 100% (verified). */
void func_0000AFD0(void) {
    extern int func_00013BD0();
    extern s32 D_00054C24;
    D_00054C24 = 1;
    func_00013BD0();
    D_00054C24 = 0;
}

/* func_0000AFFC — 6 words. MATCH 100% (verified). */
u8 func_0000AFFC(void) {
    return !D_00054C24;
}

/* func_0000B014 — 3 words. MATCH 100% (verified). */
void func_0000B014(f32 *a0, f32 a1, f32 a2) {
    a0[0] = a1;
    a0[2] = a2;
}

/* func_0000B020 — 9 words. MATCH 100% (verified). */
void func_0000B020(f32 *arg0, s32 arg1, s32 arg2) {
    arg0[0] = (f32)arg1;
    arg0[2] = (f32)arg2;
    func_0000B014(arg0, arg0[0], arg0[2]);
}

/* func_0000B044 — 7 words. MATCH 100% (verified). */
void func_0000B044(s32 *arg0, s32 *arg1, f32 arg2, f32 arg3) {
    *arg0 = (s32)arg2;
    *arg1 = (s32)arg3;
}

/* func_0000B060 — 3 words. MATCH 100% (verified). */
int func_0000B060(void) {
    return D_00054C2C;
}

/* func_0000B06C — 4 words. MATCH 100% (shape: m2c). */
s32 func_0000B06C(s32 *arg0, s32 *arg1) {
    return *arg1 - *arg0;
}

/* func_0000B07C — 18 words. MATCH 100% (verified). */
extern s32 func_00030D64(void *, s32, s32);
s32 func_0000B07C(s32 arg0, s32 arg1) {
    extern s32 D_0005504C;
    char *v1 = (char *)&D_00054C20;
    if (D_0005504C != 0) {
        return func_00030D64(*(void **)(v1 + 0x42C), arg0, arg1);
    }
    return -2;
}

/* func_0000B0C4 — 18 words. MATCH 100% (verified). */
s32 func_0000B0C4(s32 arg0, s32 arg1) {
    extern s32 D_00055050;
    char *v1 = (char *)&D_00054C20;
    if (D_00055050 != 0) {
        return func_00030D64(*(void **)(v1 + 0x430), arg0, arg1);
    }
    return -2;
}

/* func_0000B10C — 15 words. MATCH 100% (verified). */
extern s32 func_00030D54(s32 *);
s32 func_0000B10C(void) {
    extern s32 D_0005504C;
    char *v1 = (char *)&D_00054C20;
    if (D_0005504C != 0) {
        return func_00030D54(*(s32 **)(v1 + 0x42C));
    }
    return 0;
}

/* func_0000B148 — 15 words. MATCH 100% (verified). */
extern s32 func_00030D5C(s32 *);
s32 func_0000B148(void) {
    extern s32 D_0005504C;
    char *v1 = (char *)&D_00054C20;
    if (D_0005504C != 0) {
        return func_00030D5C(*(s32 **)(v1 + 0x42C));
    }
    return 0;
}

/* func_0000B288 — 3 words. MATCH 100% (verified). */
f32 func_0000B288(void) {
    return D_0005507C;
}

/* func_0000B294 — 3 words. MATCH 100% (verified). */
int func_0000B294(void) {
    return D_00055084;
}

/* func_0000B2A0 — 3 words. MATCH 100% (verified). */
void func_0000B2A0(int a0) {
    D_00055098 = a0;
}

/* func_0000B9C0 — 3 words. MATCH 100% (shape: m2c). */
void func_0000B9C0(void) {
    func_00003384(&D_0005505C);
}

/* func_0000BA40 — 2 words. MATCH 100% (shape: m2c). */
void func_0000BA40(void) {

}

/* func_0000BA48 — 16 words. MATCH 100% (verified). */
void func_0000BA48(f32 *a0, f32 a1) {
    ehsys_memset(a0, 0, 0xC);
    a0[0] = a1;
    a0[1] = a1;
}

/* func_0000BAEC — 2 words. MATCH 100% (shape: m2c). */
void func_0000BAEC(void) {
    func_000101AC();
}

/* func_0000BAF4 — 2 words. MATCH 100% (verified). */
int func_0000BAF4(void) {
    return ehsys_A84EDF3B(0x1F4);
}

/* func_0000BAFC — 9 words. MATCH 100% (shape: m2c). */
s32 func_0000BAFC(void) {
    return ehsys_04E1CB0F() == 0;
}

/* func_0000BB20 — 11 words. MATCH 100% (verified). */
extern void func_000119B8(void *);
void func_0000BB20(void) {
    s32 buf[3];
    ehsys_memset(buf, 0, 0xC);
    func_000119B8(buf);
}

/* func_0000BB4C — 13 words. MATCH 100% (verified). */
int func_0000BB4C(void) {
    extern s32 D_000550A0;
    extern s32 D_0005F4B8;
    ehsys_memset(&D_000550A0, 0, 0xA420);
    D_0005F4B8 = -1;
}

/* func_0000BB80 — 9 words. MATCH 100% (shape: m2c). */
void func_0000BB80(void) {
    func_0000BBA4();
    func_0000BB4C();
}

/* func_0000C5B0 — 6 words. MATCH 100% (verified). */
u8 func_0000C5B0(void) {
    return !D_000550A0;
}

/* func_0000C718 — 6 words. MATCH 100% (verified). */
u8 func_0000C718(void) {
    return !D_000550A4;
}

/* func_0000D0C8 — 6 words. MATCH 100% (verified). */
void func_0000D0C8(s32 *arg0, s32 arg1, void *arg2) {
    *(s32 *)((char *)arg2 + 0x154) = (s32)arg0;
    if (arg0 != 0) {
        *(s32 *)((char *)arg2 + 0x4) = *arg0;
    }
}

/* func_0000D0E0 — 6 words. MATCH 100% (verified). */
void func_0000D0E0(s32 *arg0, s32 arg1, void *arg2) {
    if (arg0 != 0) {
        *(s32 *)((char *)arg2 + 0x8) = *arg0;
    }
}

/* func_0000D1B4 — 18 words. MATCH 100% (verified). */
extern void func_0000DA54(f32 arg0, void *arg1);
void func_0000D1B4(void) {
    extern s32 D_0005F4C0;
    extern s32 D_0005F630;
    extern s32 D_0005F63C;
    ehsys_memset(&D_0005F4C0, 0, 0x190);
    func_0000DA54(0.0f, &D_0005F630);
    func_0000DA54(0.0f, &D_0005F63C);
}

/* func_0000D1FC — 2 words. MATCH 100% (shape: m2c). */
void func_0000D1FC(void) {

}

/* func_0000D634 — 4 words. MATCH 100% (verified). */
int func_0000D634(void) {
    return D_0005F5D0 != 0;
}

/* func_0000D644 — 3 words. MATCH 100% (verified). */
void func_0000D644(void) {
    D_0005F4C8 = 0;
}

/* func_0000D650 — 7 words. MATCH 100% (verified). */
void func_0000D650(s32 *arg0, s32 arg1, void *arg2) {
    extern s32 D_0005F4C0;
    D_0005F4C0 = (s32)arg0;
    if (arg0 != 0) {
        *(s32 *)((char *)arg2 + 0x4) = *arg0;
    }
}

/* func_0000D66C — 7 words. MATCH 100% (verified). */
void func_0000D66C(s32 *arg0, s32 arg1, void *arg2) {
    extern s32 D_0005F4C4;
    D_0005F4C4 = (s32)arg0;
    if (arg0 != 0) {
        *(s32 *)((char *)arg2 + 0x8) = *arg0;
    }
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

/* func_000101AC — 3 words. MATCH 100% (verified). */
void **func_000101AC(void) {
    return &D_0005F688;
}

/* func_00010324 — 6 words. MATCH 100% (verified). */
u8 func_00010324(void) {
    return !D_0005F650;
}

/* func_0001033C — 7 words. MATCH 100% (verified). */
extern s32 func_00011840(f32, f32, s32);
s32 func_0001033C(void *arg0) {
    extern s32 D_0005F654;
    D_0005F654 = 1;
    return func_00011840(*(f32 *)((char *)arg0 + 0), *(f32 *)((char *)arg0 + 4), *(s32 *)((char *)arg0 + 8));
}

/* func_00010358 — 6 words. MATCH 100% (verified). */
u8 func_00010358(void) {
    return !D_0005F654;
}

/* func_0001041C — 6 words. MATCH 100% (verified). */
u8 func_0001041C(void) {
    return !D_0005F658;
}

/* func_00010D48 — 10 words. MATCH 100% (verified). */
void func_00010D48(s32 *arg0) {
    extern s32 D_0005F660;
    extern s32 D_0005F678;
    extern s32 D_0005F6AC;
    D_0005F660 = 1;
    D_0005F678 = *arg0;
    D_0005F6AC = 0x11;
}

/* func_00010D70 — 9 words. MATCH 100% (verified). */
u8 func_00010D70(s32 *arg0) {
    extern s32 D_0005F680;
    extern s32 D_0005F660;
    *arg0 = D_0005F680;
    return !D_0005F660;
}

/* func_00010D94 — 8 words. MATCH 100% (verified). */
extern s32 func_000069A4(s32, s32, s32, s32);
s32 func_00010D94(void *arg0) {
    extern s32 D_0005F664;
    D_0005F664 = 1;
    return func_000069A4(*(s32 *)arg0, 0, 0, *(s32 *)((char *)arg0 + 4));
}

/* func_00010DB4 — 7 words. MATCH 100% (verified). */
extern void func_000067EC();
void func_00010DB4(s32 *arg0) {
    extern s32 D_0005F668;
    D_0005F668 = 1;
    func_000067EC(*arg0, 0, 0);
}

/* func_00010DD0 — 6 words. MATCH 100% (verified). */
u8 func_00010DD0(void) {
    return !D_0005F664;
}

/* func_00010DE8 — 6 words. MATCH 100% (verified). */
u8 func_00010DE8(void) {
    return !D_0005F668;
}

/* func_00010E00 — 3 words. MATCH 100% (verified). */
int *func_00010E00(void) {
    return &D_0005F6E8;
}

/* func_00010E0C — 3 words. MATCH 100% (verified). */
int func_00010E0C(void) {
    return D_0005F670;
}

/* func_000116CC — 4 words. MATCH 100% (verified). */
int func_000116CC(void) {
    return D_0005F758 = 1;
}

/* func_000116DC — 4 words. MATCH 100% (verified). */
int func_000116DC(void) {
    return D_0005F75C = 1;
}

/* func_000116EC — 4 words. MATCH 100% (verified). */
int func_000116EC(void) {
    return D_0005F760 = 1;
}

/* func_000116FC — 13 words. MATCH 100% (verified). */
void func_000116FC(void) {
    extern s32 D_0005F780;
    extern s32 D_0005F8A4;
    ehsys_memset(&D_0005F780, 0, 0x190);
    D_0005F8A4 = 6;
}

/* func_00011730 — 2 words. MATCH 100% (shape: m2c). */
void func_00011730(void) {

}

/* func_0001181C — 4 words. MATCH 100% (verified). */
void func_0001181C(void) {
    D_0005F8E4 = 1;
}

/* func_0001182C — 5 words. MATCH 100% (verified). */
void func_0001182C(void) {
    extern s32 D_0005F790;
    char *p = (char *)&D_0005F790;
    *(s32 *)(p + 0x24) = 0;
    *(s32 *)(p + 0x1C) = 0;
}

/* func_00011980 — 4 words. MATCH 100% (verified). */
int func_00011980(void) {
    return D_0005F890 != 0;
}

/* func_00011990 — 10 words. MATCH 100% (verified). */
s32 func_00011990(void) {
    extern s32 D_0005F8E0;
    extern s32 D_0005F780;
    char *v1 = (char *)&D_0005F780;
    if (D_0005F8E0 != 0) {
        return (s32)(v1 + 0x10);
    }
    return 0;
}

/* func_000119B8 — 12 words. MATCH 100% (verified). */
void func_000119B8(void *arg0) {
    extern int func_00003AC8();
    extern s32 D_0005F8E0;
    extern s32 D_0005F780;
    char *a1 = (char *)&D_0005F780;
    if (D_0005F8E0 != 0) {
        func_00003AC8(arg0, a1 + 0x10);
    }
}

/* func_00011A3C — 3 words. MATCH 100% (verified). */
void func_00011A3C(s32 arg0) {
    D_0005F8E4 = arg0;
}

/* func_00011A48 — 6 words. MATCH 100% (verified). */
u8 func_00011A48(void) {
    return !D_0005F8E8;
}

/* func_00011A98 — 7 words. MATCH 100% (verified). */
void func_00011A98(s32 *arg0, s32 arg1, void *arg2) {
    extern s32 D_0005F780;
    D_0005F780 = (s32)arg0;
    if (arg0 != 0) {
        *(s32 *)((char *)arg2 + 0x4) = *arg0;
    }
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

/* func_00013028 — 4 words. MATCH 100% (verified). */
extern s32 ehsys_41AABF28();
s32 func_00013028(s32 arg0) {
    extern s32 D_0005FE44;
    return ehsys_41AABF28(D_0005FE44, arg0);
}

/* func_00013038 — bulk-matched thunk into ehsys_20E340D9. */
s32 func_00013038(s32 arg0) {
    return ehsys_20E340D9(*(int*)&D_0005FE44, (arg0));
}

/* func_00013048 — 3 words. MATCH 100% (verified). */
s32 func_00013048(void) {
    extern s32 D_0005FE44;
    return D_0005FE44;
}

/* func_00013054 — 19 words. MATCH 100% (verified). */
extern s32 ehsys_291D6262(void *, u32, s32);
extern char D_B5FE60;
s32 func_00013054(void) {
    extern s32 D_0005FE48;
    extern s32 D_0005FE44;
    char *s0 = (char *)&D_0005FE44;
    if (D_0005FE48 == 0) {
        s32 v0 = ehsys_291D6262(&D_B5FE60, 0x11200, 0);
        *(s32 *)(s0 + 4) = v0;
    }
}

/* func_000130A0 — 3 words. MATCH 100% (verified). */
s32 func_000130A0(void) {
    extern s32 D_0005FE48;
    return D_0005FE48;
}

/* func_000132C8 — 10 words. MATCH 100% (verified). */
extern s32 *func_000132F0(s32 arg0);
s32 func_000132C8(s32 arg0) {
    s32 *p = func_000132F0(arg0);
    return p != 0 ? *p : 0;
}

/* func_000138E8 — 8 words. MATCH 100% (verified). */
extern s32 func_00013420(s32, s32, s32, s32, s32);
s32 func_000138E8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 sel;
    if (arg1 != 1) {
        sel = 6;
    } else {
        sel = 5;
    }
    return func_00013420(sel, arg0, arg2, arg3, arg4);
}

/* func_00013908 — bulk-matched thunk into func_00013420. */
s32 func_00013908(s32 arg0, s32 arg1, s32 arg2) {
    return func_00013420(0x7, (arg0), (arg1), (arg2), 0x1);
}

/* func_00013924 — bulk-matched thunk into func_00013420. */
s32 func_00013924(s32 arg0, s32 arg1, s32 arg2) {
    return func_00013420(0x8, (arg0), (arg1), (arg2), 0x1);
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

/* func_000147B8 — 5 words. MATCH 100% (verified). */
int func_000147B8(void) {
    return ehsys_memset(&D_B71070, 0, 0xD90);
}

/* func_000147CC — 9 words. MATCH 100% (shape: m2c). */
void func_000147CC(void) {
    func_000147F0();
    func_000147B8();
}

/* func_000147F0 — 5 words. MATCH 100% (verified). */
int func_000147F0(void) {
    return ehsys_memset(&D_B71070, 0, 0xD90);
}

/* func_00014804 — 2 words. MATCH 100% (shape: m2c). */
void func_00014804(void) {

}

/* func_00014928 — 5 words. MATCH 100% (shape: m2c). */
void *func_00014928(s32 arg0) {
    return &D_0003DAE8 + (arg0 * 8);
}

/* func_00014A7C — 6 words. MATCH 100% (verified). */
u8 func_00014A7C(void) {
    return !(*(int *)0xB71070);
}

/* func_00014B30 — 5 words. MATCH 100% (verified). */
int func_00014B30(void) {
    return ehsys_memset(&D_B71E00, 0, 0x2640);
}

/* func_00014B44 — 9 words. MATCH 100% (shape: m2c). */
void func_00014B44(void) {
    func_00014B68();
    func_00014B30();
}

/* func_000154E4 — 8 words. MATCH 100% (verified). */
s32 func_000154E4(s32 arg0, s32 arg1, s32 arg2) {
    return ehsys_B89D38DC(arg0 << 6, arg1 << 6, (0x1E0 - arg0) << 6, arg2);
}

/* func_00015504 — bulk-matched thunk into ehsys_3BB2BAC6. */
s32 func_00015504(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return ehsys_3BB2BAC6(arg0 << 6, arg1 << 6, arg2 << 6, arg3 << 6, arg4, -1, 0);
}

/* func_00015520 — bulk-matched thunk into ehsys_BC8E65D7. */
s32 func_00015520(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return ehsys_BC8E65D7(arg0 << 6, arg1 << 6, arg2 << 6, arg3, 0xFFFFFFFF);
}

/* func_00015534 — 12 words. MATCH 100% (shape: m2c). */
void func_00015534(void) {
    ehsys_memset(&D_B74450, 0, 0x2E0);
    func_0002D07C();
}

/* func_00015564 — 5 words. MATCH 100% (verified). */
int func_00015564(void) {
    return ehsys_memset(&D_B74450, 0, 0x2E0);
}

/* func_00016B84 — 7 words. MATCH 100% (verified). */
void func_00016B84(s32 arg0) {
    extern s32 D_B74450;
    char *p = (char *)&D_B74450;
    if (arg0 != 0) {
        *(s32 *)(p + 0x2BC) = 1;
    }
    *(s32 *)(p + 0x2B0) = arg0;
}

/* func_00016BA0 — 3 words. MATCH 100% (shape: m2c). */
s32 func_00016BA0(void) {
    return *(s32 *)0xB74720;
}

/* func_00016BAC — 5 words. MATCH 100% (verified). */
int func_00016BAC(void) {
    return ehsys_memset(&D_B74730, 0, 0x11B0);
}

/* func_00016BC0 — 9 words. MATCH 100% (shape: m2c). */
void func_00016BC0(void) {
    func_00016BE4();
    func_00016BAC();
}

/* func_00017DF8 — bulk-matched thunk into ehsys_BC8E65D7. */
s32 func_00017DF8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return ehsys_BC8E65D7(arg0 << 6, arg1 << 6, arg2 << 6, arg3, 0xFFFFFFFF);
}

/* func_00018604 — 4 words. MATCH 100% (shape: m2c). */
s32 func_00018604(void) {
    return *(s32 *)0xB7473C != 0;
}

/* func_00018DF8 — 6 words. MATCH 100% (verified). */
typedef struct { s32 i; f32 f; } Vec2_18DF8;
void *func_00018DF8(Vec2_18DF8 *arg0, Vec2_18DF8 *arg1) {
    arg0->i = arg1->i;
    arg0->f = arg1->f;
    return arg0;
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

/* func_0001B340 — bulk-matched thunk into ehsys_3BB2BAC6. */
s32 func_0001B340(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return ehsys_3BB2BAC6(arg0 << 6, arg1 << 6, arg2 << 6, arg3 << 6, arg4, -1, 0);
}

/* func_0001B35C — 3 words. MATCH 100% (shape: m2c). */
s32 func_0001B35C(void) {
    return *(s32 *)0xB75A90;
}

/* func_0001B368 — 3 words. MATCH 100% (shape: m2c). */
void func_0001B368(s32 arg0) {
    *(s32 *)0xB75AA0 = arg0;
}

/* func_0001B374 — 3 words. MATCH 100% (verified). */
void **func_0001B374(void) {
    return &D_B75994;
}

/* func_0001B380 — 3 words. MATCH 100% (verified). */
void **func_0001B380(void) {
    return &D_B75AAC;
}

/* func_0001B38C — 3 words. MATCH 100% (shape: m2c). */
void func_0001B38C(s32 arg0) {
    *(s32 *)0xB75AA8 = arg0;
}

/* func_0001B398 — 5 words. MATCH 100% (verified). */
void func_0001B398(u8 arg0) {
    char *p = (char *)&D_B75994;
    p[0x50] = arg0;
    p[0x5C] = arg0;
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

/* func_0001B670 — 15 words. MATCH 100% (verified). */
extern s32 func_0001B470(void);
void func_0001B670(void) {
    char *s0 = (char *)&D_B75940;
    if (func_0001B470() == 0) {
        *(s32 *)(s0 + 0x164) += 1;
    }
}

/* func_0001BB1C — 9 words. MATCH 100% (shape: m2c). */
void func_0001BB1C(void) {
    ehsys_06380DFA();
    ehsys_AB962AE7(0);
}

/* func_0001BC58 — 17 words. MATCH 100% (verified). */
extern void *func_000224C4(s32 arg0);
extern s32 ehsys_1C99A7A5(void *arg0);
void func_0001BC58(void) {
    void *s0 = func_000224C4(0);
    if (s0 != 0) {
        s32 v0 = ehsys_1C99A7A5(s0);
        *(f32 *)((char *)s0 + 0x20) = (f32)v0;
    }
}

/* func_0001C1A4 — bulk-matched thunk into ehsys_B89D38DC. */
s32 func_0001C1A4(s32 arg0, s32 arg1, s32 arg2) {
    return ehsys_B89D38DC(arg0 << 6, arg1 << 6, arg2 << 6);
}

/* func_0001C33C — bulk-matched thunk into ehsys_3BB2BAC6. */
s32 func_0001C33C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return ehsys_3BB2BAC6(arg0 << 6, arg1 << 6, arg2 << 6, arg3 << 6, arg4, -1, 0);
}

/* func_0001DB88 — bulk-matched thunk into ehsys_BC8E65D7. */
s32 func_0001DB88(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return ehsys_BC8E65D7(arg0 << 6, arg1 << 6, arg2 << 6, arg3, 0xFFFFFFFF);
}

/* func_00022494 — 12 words. MATCH 100% (verified). */
extern s32 ehsys_C6C15111(s32, void *, s32);
s32 func_00022494(s32 arg0) {
    extern s32 D_00048CF0;
    if (arg0 == 0) {
        return 0;
    }
    return ehsys_C6C15111(arg0, &D_00048CF0, 0);
}

/* func_000225A0 — 5 words. MATCH 100% (verified). */
int func_000225A0(void) {
    return ehsys_memset(&D_B75AE4, 0, 0x8);
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

/* func_00022720 — 8 words. MATCH 100% (verified). */
s32 func_00022720(s32 *arg0) {
    if (*(s32 *)0xB75AE4 == 0) {
        *arg0 = 0;
        return 1;
    }
    return 0;
}

/* func_00024850 — bulk-matched thunk into ehsys_BC8E65D7. */
s32 func_00024850(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return ehsys_BC8E65D7(arg0 << 6, arg1 << 6, arg2 << 6, arg3, 0xFFFFFFFF);
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

/* func_00025EAC — 14 words. MATCH 100% (verified). */
s32 func_00025EAC(s32 **arg0, s32 **arg1) {
    f32 k = 100000.0f;
    s32 *p0 = *arg0;
    s32 *p1 = *arg1;
    return (s32)(k * *(f32 *)((char *)p0 + 0x18) - k * *(f32 *)((char *)p1 + 0x18));
}

/* func_00025F24 — 3 words. MATCH 100% (shape: m2c). */
void func_00025F24(void) {
    func_00003384((s32 *)&D_B7AB00);
}

/* func_00029F60 — bulk-matched thunk into ehsys_BC8E65D7. */
s32 func_00029F60(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return ehsys_BC8E65D7(arg0 << 6, arg1 << 6, arg2 << 6, arg3, 0xFFFFFFFF);
}

/* func_00029F74 — 50 words. MATCH 100% (shape: m2c). */
void func_00029F74(s32 *arg0) {
    s32 temp_s0;

    *(s32 *)0xB7AB1C = ehsys_D4DE5DD8() % 5;
    temp_s0 = ehsys_D4DE5DD8() % 3;
    *(s32 *)0xB7AB20 = ehsys_D4DE5DD8() % 6;
    *(s32 *)0xB7AB24 = ehsys_31D0BD26(func_00010E0C(), 2);
    arg0[0] = func_00010E0C();
    arg0[1] = 4;
    arg0[2] = temp_s0 + ((*(s32 *)0xB7AB1C * 3) + 1);
    arg0[3] = arg0[0];
    arg0[4] = arg0[1];
    arg0[5] = arg0[2];
}

/* func_0002D044 — bulk-matched thunk into ehsys_BC8E65D7. */
s32 func_0002D044(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return ehsys_BC8E65D7(arg0 << 6, arg1 << 6, arg2 << 6, arg3, 0xFFFFFFFF);
}

/* func_0002D058 — 3 words. MATCH 100% (shape: m2c). */
void func_0002D058(s32 arg0) {
    *(s32 *)0xB7AB28 = arg0;
}

/* func_0002D198 — 3 words. MATCH 100% (verified). */
void **func_0002D198(void) {
    return &D_B7AB2C;
}

/* func_0002D1A4 — 16 words. MATCH 100% (shape: m2c). */
void func_0002D1A4(s32 arg0, s32 arg1) {
    ehsys_025FE238(&D_B7AB44, arg0);
    ehsys_025FE238(&D_B7AD44, arg1);
}

/* func_0002D1E4 — 7 words. MATCH 100% (verified). */
void func_0002D1E4(void ***arg0, void ***arg1) {
    *arg0 = (void **)&D_B7AB44;
    *arg1 = (void **)&D_B7AD44;
}

/* func_0002D254 — 11 words. MATCH 100% (verified). */
extern s32 *func_0002D200(void);
s32 func_0002D254(void) {
    s32 *p = func_0002D200();
    return *p / 5;
}

/* func_0002D480 — 40 words. MATCH 100% (verified). */
int func_0002D480(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 temp_v0;

    temp_v0 = ehsys_4175E3DB(arg0, 9);
    temp_v0 = ehsys_23E69878(temp_v0, arg5);
    temp_v0 = ehsys_8EA6B1E7(temp_v0, 1, 1, arg3, arg4);
    return ehsys_FDD168CA(temp_v0, arg1, arg2, 0, 0, 0, 0, 0);
}

/* func_0002D520 — 8 words. MATCH 100% (verified). */
extern void func_0002D540(s32, s32, s32, s32, s32, s32, s32, s32, s32);
int func_0002D520(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    func_0002D540(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg5, arg6);
}

/* func_0002D540 — 31 words. MATCH 100% (verified). */
void func_0002D540(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    s32 v0 = ehsys_8EA6B1E7(arg0, arg5, arg6, arg7, arg8);
    ehsys_FDD168CA(v0, arg1, arg2, 0, arg3, arg4, 0, 0);
}

/* func_0002D950 — bulk-matched thunk into ehsys_97BB99A5. */
s32 func_0002D950(s32 arg0, s32 arg1) {
    return ehsys_97BB99A5(arg0, arg1, 0, 0);
}

/* func_0002D95C — 2 words. MATCH 100% (shape: m2c). */
void func_0002D95C(void) {

}

/* func_0002DAD0 — bulk-matched thunk into ehsys_3BB2BAC6. */
s32 func_0002DAD0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return ehsys_3BB2BAC6(arg0 << 6, arg1 << 6, arg2 << 6, arg3 << 6, arg4, -1, 0);
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

/* func_0002E35C — bulk-matched thunk into func_0002D520. */
s32 func_0002E35C(s32 arg0, s32 arg1, s32 arg2) {
    return func_0002D520(arg0, arg1, arg2, 0, 0, 0x7, 0x6);
}

/* func_0002E370 — bulk-matched thunk into func_0002D520. */
s32 func_0002E370(s32 arg0, s32 arg1, s32 arg2) {
    return func_0002D520(arg0, arg1, arg2, 0, 0x6, 0x7, 6);
}

/* func_0002EBA8 — 5 words. MATCH 100% (shape: m2c). */
s32 func_0002EBA8(void) {
    return *(s32 *)0xB7B064 != 3;
}

/* func_0002EEFC — bulk-matched thunk into ehsys_BC8E65D7. */
s32 func_0002EEFC(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return ehsys_BC8E65D7(arg0 << 6, arg1 << 6, arg2 << 6, arg3, 0xFFFFFFFF);
}

/* func_0002EF10 — 16 words. MATCH 100% (shape: m2c). */
void func_0002EF10(void) {
    ehsys_D853F15C(1);
    ehsys_C792FA38(0);
    ehsys_C9D9E989(1);
    ehsys_942B03D0(0xF, 0xF);
    ehsys_60B55A50(0xFF000000);
}

/* func_0002EF50 — bulk-matched thunk into ehsys_C792FA38. */
s32 func_0002EF50(void) {
    return ehsys_C792FA38(0);
}

/* func_0002F02C — 4 words. MATCH 100% (shape: m2c). */
s32 func_0002F02C(s32 arg0) {
    return *(s32 *)0xB7B0A4 + arg0;
}

/* func_0002F03C — 4 words. MATCH 100% (shape: m2c). */
s32 func_0002F03C(s32 arg0) {
    return arg0 - *(s32 *)0xB7B0A4;
}

/* func_0002F3E0 — bulk-matched thunk into ehsys_BC8E65D7. */
s32 func_0002F3E0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return ehsys_BC8E65D7(arg0 << 6, arg1 << 6, arg2 << 6, arg3, 0xFFFFFFFF);
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

/* func_0002F470 — 2 words. MATCH 100% (shape: m2c). */
void func_0002F470(s32 *arg0) {
    arg0[2] = 0;
}

/* func_0002F5E8 — 2 words. MATCH 100% (shape: m2c). */
void func_0002F5E8(void) {

}

/* func_0002F60C — 2 words. MATCH 100% (shape: m2c). */
u16 func_0002F60C(u16 *arg0) {
    return arg0[1];
}

/* func_0002F614 — 2 words. MATCH 100% (verified). */
int func_0002F614(arg0, arg1)
void *arg0;
u16 arg1;
{
    *(u16 *)((char *)arg0 + 2) = arg1;
}

/* func_0002FAF8 — bulk-matched thunk into ehsys_BC8E65D7. */
s32 func_0002FAF8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return ehsys_BC8E65D7(arg0 << 6, arg1 << 6, arg2 << 6, arg3, 0xFFFFFFFF);
}

/* func_0002FB0C — 16 words. MATCH 100% (verified). */
void func_0002FB0C(void) {
    func_000304D4(&D_B7B268);
    ehsys_5DF04F49(&D_B7B29C);
    ehsys_memset(&D_B7B250, 0, 0x124);
}

/* func_0002FB70 — 4 words. MATCH 100% (shape: m2c). */
void func_0002FB70(void) {
    *(s32 *)0xB7B250 = 1;
}

/* func_0002FB80 — 3 words. MATCH 100% (verified). */
void func_0002FB80(void) {
    func_000304E4((u16 *)&D_B7B268);
}

/* func_0002FD58 — bulk-matched thunk into ehsys_3BB2BAC6. */
s32 func_0002FD58(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return ehsys_3BB2BAC6(arg0 << 6, arg1 << 6, arg2 << 6, arg3 << 6, arg4, -1, 0);
}

/* func_0003006C — bulk-matched thunk into ehsys_97BB99A5. */
s32 func_0003006C(s32 arg0, s32 arg1) {
    return ehsys_97BB99A5(arg0, arg1, 0, 0);
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

/* func_0003010C — 11 words. MATCH 100% (verified). */
void func_0003010C(s32 *arg0) {
    func_0002F470(arg0);
    *(s16 *)((char *)arg0 + 0x30) = 0;
    *(s16 *)((char *)arg0 + 0x32) = 0;
}

/* func_000304D4 — 2 words. MATCH 100% (shape: m2c). */
void func_000304D4() {
    func_0002F5E8();
}

/* func_000304DC — 2 words. MATCH 100% (shape: m2c). */
void func_000304DC() {
    func_0002F5F0();
}

/* func_000304E4 — 2 words. MATCH 100% (shape: m2c). */
void func_000304E4(u16 *arg0) {
    func_0002F60C(arg0);
}

/* func_000304EC — 2 words. MATCH 100% (shape: m2c). */
void func_000304EC() {
    func_0002F614();
}

/* func_000306FC — 3 words. MATCH 100% (shape: m2c). */
void func_000306FC(void) {
    func_00030138(&D_B7B38C);
}

/* func_00030708 — bulk-matched thunk into func_0003027C. */
s32 func_00030708(s32 arg0) {
    return func_0003027C(arg0, &D_B7B38C);
}

/* func_00030714 — 16 words. MATCH 100% (verified). */
void func_00030714(void) {
    func_000304D4(&D_B7B38C);
    ehsys_5DF04F49(&D_B7B3C0);
    ehsys_memset(&D_B7B374, 0, 0x11C);
}

/* func_00030754 — 4 words. MATCH 100% (verified). */
void func_00030754(s32 arg0) {
    func_000304DC(&D_B7B38C, arg0);
}

/* func_00030764 — 3 words. MATCH 100% (verified). */
void func_00030764(void) {
    func_000304E4((u16 *)&D_B7B38C);
}

/* func_00030770 — 4 words. MATCH 100% (verified). */
void func_00030770(s32 arg0) {
    func_000304EC(&D_B7B38C, arg0);
}

/* func_0003092C — bulk-matched thunk into ehsys_3BB2BAC6. */
s32 func_0003092C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return ehsys_3BB2BAC6(arg0 << 6, arg1 << 6, arg2 << 6, arg3 << 6, arg4, -1, 0);
}

/* func_00030948 — 8 words. MATCH 100% (verified). */
s32 func_00030948(s32 arg0, s32 arg1, s32 arg2) {
    return ehsys_B89D38DC(arg0 << 6, arg1 << 6, (0x1E0 - arg0) << 6, arg2);
}

/* func_00030C94 — bulk-matched thunk into ehsys_97BB99A5. */
s32 func_00030C94(s32 arg0, s32 arg1) {
    return ehsys_97BB99A5(arg0, arg1, 0, 0);
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

/* func_00030D28 — 2 words. MATCH 100% (shape: m2c). */
s32 func_00030D28(s32 *arg0) {
    return arg0[3];
}

/* func_00030D30 — 9 words. MATCH 100% (verified). */
void *func_00030D30(s32 a0, s32 a1, s32 a2) {
    s32 off1 = *(s32 *)((a1 << 3) + a0 + 0x14);
    s32 p = off1 + a0;
    s32 off2 = *(s32 *)(p + a2 * 8 + 4);
    return (void *)(off2 + a0);
}

/* func_00030D54 — 2 words. MATCH 100% (shape: m2c). */
s32 func_00030D54(s32 *arg0) {
    return arg0[2];
}

/* func_00030D5C — 2 words. MATCH 100% (shape: m2c). */
s32 func_00030D5C(s32 *arg0) {
    return arg0[3];
}

/* func_00030DF8 — 35 words. MATCH 100% (shape: m2c). */
void func_00030DF8(s32 *arg0) {
    *(s32 *)0xB7B498 = ehsys_31D0BD26(func_00010E0C(), 1);
    *(s32 *)0xB7B494 = ehsys_D4DE5DD8() % 5;
    arg0[0] = func_00010E0C();
    arg0[1] = 0x12;
    arg0[2] = (*(s32 *)0xB7B494 * 4) + 1;
    arg0[3] = arg0[0];
    arg0[4] = arg0[1];
    arg0[5] = arg0[2];
}

/* func_00035F50 — 5 words. MATCH 100% (verified). */
void func_00035F50(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    ehsys_BC8E65D7(arg0 << 6, arg1 << 6, arg2 << 6, arg3, -1);
}
