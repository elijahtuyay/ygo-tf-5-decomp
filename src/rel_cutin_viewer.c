/*
 * rel_cutin_viewer.prx — reconstructed code (matching decompilation)
 *
 * Compiler:     Metrowerks CodeWarrior for PSP — MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,s -sdatathreshold 0
 * Verification: scripts/mwcc_build.sh src/rel_cutin_viewer.c && 
 *               scripts/mwcc_diff.py asm/rel_cutin_viewer/text.s build/mwcc/rel_cutin_viewer.o
 *               Every function below is tagged "MATCH 100%" only if it has
 *               been confirmed this way as part of this file (matches can
 *               regress when combined with neighbors; re-verify after edits).
 *
 * Produced by scripts/auto_decomp.py's per-function search (m2c draft, then a
 * series of known MWCC-codegen source shapes, keeping only byte-identical
 * matches) — see src/rel_movie_viewer.c's header for the shape catalogue and
 * codegen levers (switch-vs-if, goto-rotated loops, min/max intrinsics,
 * address rematerialization, etc.) this search draws on.
 *
 * STATUS: 55 function(s) matched via the automated pass so far.
 *   func_00000000 (13 words)
 *   func_00000034 (2 words)
 *   func_000002E0 (2 words)
 *   func_0000066C (3 words)
 *   func_000007EC (26 words)
 *   func_00000A98 (11 words)
 *   func_00000B44 (2 words)
 *   func_00000CC0 (15 words)
 *   func_00000D04 (16 words)
 *   func_00000E78 (9 words)
 *   func_0000130C (2 words)
 *   func_00001830 (2 words)
 *   func_000019E4 (16 words)
 *   func_00001C0C (9 words)
 *   func_00001E7C (4 words)
 *   func_00001E8C (4 words)
 *   func_00001E9C (4 words)
 *   func_00001EAC (3 words)
 *   func_00001EC8 (3 words)
 *   func_00002544 (3 words)
 *   func_00002550 (16 words)
 *   func_00003920 (2 words)
 *   func_000039E8 (22 words)
 *   func_00003E8C (2 words)
 *   func_00003E94 (2 words)
 *   func_0000450C (3 words)
 *   func_00004C50 (4 words)
 *   func_00005D64 (5 words)
 *   func_00005EEC (14 words)
 *   func_0000647C (17 words)
 *   func_00006778 (13 words)
 *   func_00006DB8 (12 words)
 *   func_000070D0 (21 words)
 *   func_000071A0 (33 words)
 *   func_00007224 (33 words)
 *   func_000072A8 (13 words)
 *   func_00007BCC (2 words)
 *   func_00007BD4 (2 words)
 *   func_00007BDC (2 words)
 *   func_0000C578 (2 words)
 *   func_0000C580 (2 words)
 *   func_00015AB0 (3 words)
 *   func_00016E64 (3 words)
 *   func_0001AF78 (33 words)
 *   func_0001B490 (3 words)
 *   func_0001BF10 (25 words)
 *   func_0001C5AC (3 words)
 *   func_0001C5B8 (3 words)
 *   func_0001C7E4 (4 words)
 *   func_0001C7F4 (2 words)
 *   func_0001C8CC (20 words)
 *   func_0001C91C (24 words)
 *   func_0001CAE4 (2 words)
 *   func_0001CAEC (2 words)
 *   func_0001CAF4 (2 words)
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

/* externs: imports and sibling functions referenced by matched bodies. */
extern int ehsys_13A4081A();
extern int ehsys_291D6262();
extern int ehsys_47719795();
extern int ehsys_4F22C9AA();
extern int ehsys_60BA0722();
extern int ehsys_53D7C1EE();
extern int ehsys_65DA0419();
extern int ehsys_9EA6989A();
extern int ehsys_9EFDC9B9();
extern int ehsys_B4471B5E();
extern int ehsys_BFFBA174();
extern int ehsys_E1139F1A();
extern int ehsys_E47E40E4();
extern int ehsys_EF9740B0();
extern int ehsys_F292E199();
extern int ehsys_F2BD0694();
extern int ehsys_F8CDBCAB();
extern int ehsys_strcat();
extern int ehsys_strcpy();
extern int func_0000003C();
extern int func_000002E8();
extern int func_00001778();
extern int func_00001A24();
extern int func_0000260C();
extern int func_00002EC8();
extern int func_00002F3C();
extern int func_00003A40();
extern int func_00003B94();
extern int func_00003C40();
extern int func_000044D0();
extern int func_00005B18();
extern int func_00005DEC();
extern int func_000062BC();
extern int func_00006668();
extern int func_00006D78();
extern int func_0000766C();
extern int func_000077DC();
extern int func_0000789C();
extern int func_00007BE4();
extern int func_0001AFFC();
extern int func_0001B384();
extern int func_0001B760();
extern int func_0001B964();
extern int func_0001BAF8();
extern int func_0001BD1C();
extern int func_0001C5D4();
extern int func_0001C7FC();
extern int D_00024D00;
extern int D_000250FC;
extern int D_00025458;
extern int D_000257C8;
extern int D_00025A80;
extern int D_00025A90;
extern int D_0002BEAC;
extern int D_0002BFE0;
extern int D_0002C1C0;
extern int D_0002C1C4;
extern int D_0002D1C4;
extern int D_0002E1D0;
extern int D_0002E1D4;
extern int D_000258B8;
extern int D_000259EC;
extern int D_B2E6E0;
extern int D_B2F4A0;
extern int D_B31480;
extern int D_B314C0;
extern int D_B31500;
extern int D_B31540;
extern int D_B31780;
extern int D_B32B90;
extern int D_C82B90;

/* forward declarations for functions defined later in this file (address order). */
s32 func_00000000(void);
s32 func_00000034(void);
void func_000002E0(void);
void func_0000066C(void);
void func_000007EC(void);
void func_00000A98(void);
void func_00000B44(void);
void func_00000CC0(void);
void func_00000D04(void);
void func_00000E78(void);
void func_0000130C(void);
void func_00001830(void);
void func_000019E4(void);
s32 func_00001C0C(void);
s32 func_00001E7C(void);
s32 func_00001E8C(void);
s32 func_00001E9C(void);
s32 func_00001EAC(void);
s32 (*func_00001EC8(void))();
void func_00002544(s32 arg0);
void func_00002550(s32 arg0, int arg1);
s32 func_00003920(void);
s32 func_000039E8(s32 arg0, int arg1, int arg2);
s32 func_00003E8C(void);
s32 func_00003E94(void);
void func_0000450C(s32 arg0);
s32 func_00004C50(void);
void func_000056F0(int arg0, int arg1);
void func_00005A60(int arg0, int arg1);
s32 func_00005D64(void);
void func_00005EEC(void);
void func_0000647C(void);
void func_00006778(s32 arg0, int arg1);
s32 func_00006D50(s32 arg0);
void func_00006DB8(s32 arg0);
void func_000070D0(void);
void func_000071A0(void);
void func_00007224(void);
f32 func_000072A8(s32 arg0, s32 arg1);
void func_00007BCC(void);
void func_00007BD4(void);
void func_00007BDC(void);
void func_0000C578(void);
void func_0000C580(void);
s32 func_00013C00(int arg0);
void func_00015AB0(s32 arg0);
void func_00016E64(s32 arg0);
void func_0001AF78(void);
s32 func_0001B490(void);
void func_0001BF10(void);
s32 func_0001C54C(int arg0, int arg1, int arg2);
void func_0001C5AC(s32 arg0);
void func_0001C5B8(void);
s32 func_0001C7E4(s32 *arg0, s32 *arg1);
s32 func_0001C7F4(void);
s32 func_0001C8CC(s32 arg0, int arg1, int arg2);
s32 func_0001C91C(s32 arg0, int arg1, int arg2, int arg3);
void func_0001CAE4(void);
void func_0001CAEC(void);
s32 func_0001CAF4(void);

/* func_00000000 — 13 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_00000000(void) {
    ehsys_B4471B5E(func_0000003C, func_000002E0, &D_00025A80);
    return 0;
}

/* func_00000034 — 2 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_00000034(void) {
    return 0;
}

/* func_000002E0 — 2 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_000002E0(void) {

}

/* func_0000066C — 3 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_0000066C(void) {
    ehsys_E1139F1A(&D_0002BEAC);
}

/* func_000007EC — 26 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_000007EC(void) {
    ehsys_60BA0722(D_0002C1C0);
    D_0002C1C0 = 0;
    ehsys_memset(&D_00025A90, 0, 0xA);
    ehsys_memset(&D_0002BFE0, 0, 0x1E0);
    D_0002D1C4 = 0;
    D_0002C1C4 = 0;
    func_00002544(0);
}

/* func_00000A98 — 11 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00000A98(void) {
    ehsys_BFFBA174();
    func_0001AFFC();
    func_000002E8(5);
}

/* func_00000B44 — 2 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00000B44(void) {
    func_0000066C();
}

/* func_00000CC0 — 15 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00000CC0(void) {
    ehsys_13A4081A(1);
    func_0001B760(&D_0002E1D0, &D_0002E1D4, 1);
    func_0001B964();
}

/* func_00000D04 — 16 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00000D04(void) {
    if ((func_0001B384(0x80001) != 0) && (func_0001BAF8() != 0)) {
        func_000002E8(0xA);
    }
}

/* func_00000E78 — 9 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00000E78(void) {
    func_00005B18();
    func_00001A24();
}

/* func_0000130C — 2 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_0000130C(void) {

}

/* func_00001830 — 2 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00001830(void) {

}

/* func_000019E4 — 16 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_000019E4(void) {
    ehsys_memset(&D_B2E6E0, 0, 0x7B0);
    *(s32 *)0xB2E6EC = -1;
    func_000044D0();
    func_00001778();
}

/* func_00001C0C — 9 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_00001C0C(void) {
    func_0000260C(*(s32 *)0xB2E6E8);
    return 0;
}

/* func_00001E7C — 4 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_00001E7C(void) {
    return *(s32 *)0xB2E6E8 + 0x120;
}

/* func_00001E8C — 4 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_00001E8C(void) {
    return *(s32 *)0xB2E6E8 + 0x160;
}

/* func_00001E9C — 4 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_00001E9C(void) {
    return *(s32 *)0xB2E6E8 + 0x1A0;
}

/* func_00001EAC — 3 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_00001EAC(void) {
    return *(s32 *)0xB2E6F0;
}

/* func_00001EC8 — 3 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 (*func_00001EC8(void))() {
    return func_0001C7FC;
}

/* func_00002544 — 3 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00002544(s32 arg0) {
    *(s32 *)0xB2EEB0 = arg0;
}

/* func_00002550 — 16 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00002550(s32 arg0, int arg1) {
    func_00002EC8(arg1);
    func_00002F3C(arg0, arg1);
}

/* func_00003920 — 2 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_00003920(void) {
    return 1;
}

/* func_000039E8 — 22 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_000039E8(s32 arg0, int arg1, int arg2) {
    func_00007BE4();
    func_0000789C(arg0, arg1, arg2);
    func_0000450C(0);
    return 0;
}

/* func_00003E8C — 2 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_00003E8C(void) {
    return 0;
}

/* func_00003E94 — 2 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_00003E94(void) {
    return 0;
}

/* func_0000450C — 3 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_0000450C(s32 arg0) {
    *(s32 *)0xB2EEBC = arg0;
}

/* func_00004C50 — 4 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_00004C50(void) {
    return *(s32 *)0xB2EEC8 != 0;
}

/* func_000056F0 — 15 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_000056F0(int arg0, int arg1) {
    ehsys_F292E199();
    ehsys_65DA0419(0x94D5);
    func_0001C5D4(arg1);
    *(s32 *)0xB2EEC8 = 0;
}

/* func_00005A60 — 9 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00005A60(int arg0, int arg1) {
    func_0001C5D4(arg1);
    *(s32 *)0xB2EEC8 = 0;
}

/* func_00005D64 — 5 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_00005D64(void) {
    *(s32 *)0xB2EF10 = 1;
    return 0;
}

/* func_00005EEC — 14 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00005EEC(void) {
    ehsys_memset(&D_B2F4A0, 0, 0x20F0);
    func_00005DEC();
    func_000077DC();
}

/* func_0000647C — 17 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_0000647C(void) {
    func_000062BC(1);
    func_000062BC(2);
    func_000062BC(3);
    func_000062BC(5);
    func_000062BC(7);
    func_000062BC(8);
}

/* func_00006778 — 13 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00006778(s32 arg0, int arg1) {
    ehsys_9EA6989A(arg0, func_00006668(arg1));
}

/* func_00006D50 — 10 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_00006D50(s32 arg0) {
    s32 temp_v0;

    temp_v0 = ehsys_E47E40E4();
    return temp_v0 + arg0;
}

/* func_00006DB8 — 12 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00006DB8(s32 arg0) {
    func_00006D78(arg0, func_00001E8C());
}

/* func_000070D0 — 21 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_000070D0(void) {
    ehsys_4F22C9AA(0);
    ehsys_F8CDBCAB();
    ehsys_4F22C9AA(1);
    ehsys_F8CDBCAB();
    ehsys_4F22C9AA(3);
    ehsys_F8CDBCAB();
    ehsys_4F22C9AA(2);
    ehsys_F8CDBCAB();
}

/* func_000071A0 — 33 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_000071A0(void) {
    ehsys_4F22C9AA(0);
    ehsys_F2BD0694();
    ehsys_EF9740B0(&D_B31480);
    ehsys_4F22C9AA(1);
    ehsys_F2BD0694();
    ehsys_EF9740B0(&D_B314C0);
    ehsys_4F22C9AA(3);
    ehsys_F2BD0694();
    ehsys_EF9740B0(&D_B31500);
    ehsys_4F22C9AA(2);
    ehsys_F2BD0694();
    ehsys_EF9740B0(&D_B31540);
}

/* func_00007224 — 33 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00007224(void) {
    ehsys_4F22C9AA(0);
    ehsys_F2BD0694();
    ehsys_EF9740B0(func_00001E7C());
    ehsys_4F22C9AA(1);
    ehsys_F2BD0694();
    ehsys_EF9740B0(func_00001E8C());
    ehsys_4F22C9AA(3);
    ehsys_F2BD0694();
    ehsys_9EFDC9B9();
    ehsys_4F22C9AA(2);
    ehsys_F2BD0694();
    ehsys_9EFDC9B9();
}

/* func_000072A8 — 13 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
f32 func_000072A8(s32 arg0, s32 arg1) {
    s32 var_a0;

    var_a0 = arg0;
    if (var_a0 < 0) {
        var_a0 = 0;
    }
    if (arg1 < var_a0) {
        var_a0 = arg1;
    }
    return (f32) var_a0 / (f32) arg1;
}

/* func_00007BCC — 2 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00007BCC(void) {

}

/* func_00007BD4 — 2 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00007BD4(void) {

}

/* func_00007BDC — 2 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00007BDC(void) {

}

/* func_0000C578 — 2 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_0000C578(void) {

}

/* func_0000C580 — 2 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_0000C580(void) {

}

/* func_00015AB0 — 3 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00015AB0(s32 arg0) {
    *(s32 *)0xB31594 = arg0;
}

/* func_00016E64 — 3 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00016E64(s32 arg0) {
    *(s32 *)0xB31598 = arg0;
}

/* func_0001AF78 — 33 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_0001AF78(void) {
    ehsys_qsort(&D_00024D00, 0x25, 0x18, func_0001BD1C);
    ehsys_qsort(&D_000250FC, 1, 0xCC, func_0001BD1C);
    ehsys_qsort(&D_00025458, 0x24, 0x10, func_0001BD1C);
    ehsys_qsort(&D_000257C8, 0xC, 0x14, func_0001BD1C);
}

/* func_0001B490 — 3 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_0001B490(void) {
    return *(s32 *)0xB32B88;
}

/* func_0001BF10 — 25 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_0001BF10(void) {
    ehsys_memset(&D_B31780, 0, 0x201420);
    *(s32 *)0xB32B88 = ehsys_291D6262(&D_B32B90, 0x150000, 0);
    *(s32 *)0xB32B8C = ehsys_47719795(&D_C82B90, 0xB0000, 0);
}

/* func_0001C5AC — 3 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_0001C5AC(s32 arg0) {
    *(s32 *)0xE32C88 = arg0;
}

/* func_0001C5B8 — 3 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_0001C5B8(void) {
    *(s32 *)0xE32C88 = 0;
}

/* func_0001C7E4 — 4 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_0001C7E4(s32 *arg0, s32 *arg1) {
    return *arg0 - *arg1;
}

/* func_0001C7F4 — 2 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_0001C7F4(void) {
    return 1;
}

/* func_0001C8CC — 20 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_0001C8CC(s32 arg0, int arg1, int arg2) {
    func_00007BCC();
    func_000039E8(arg0, arg1, arg2);
    return 0;
}

/* func_0001C91C — 24 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_0001C91C(s32 arg0, int arg1, int arg2, int arg3) {
    func_00007BD4();
    func_00003A40(arg0, arg1, arg2, arg3);
    return 0;
}

/* func_0001CAE4 — 2 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_0001CAE4(void) {
    func_00003B94();
}

/* func_0001CAEC — 2 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_0001CAEC(void) {
    func_00003C40();
}

/* func_0001CAF4 — 2 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_0001CAF4(void) {
    return 0;
}

