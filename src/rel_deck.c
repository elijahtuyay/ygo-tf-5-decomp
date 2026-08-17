/*
 * rel_deck.prx — reconstructed code (matching decompilation)
 *
 * Compiler:     Metrowerks CodeWarrior for PSP — MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,s -sdatathreshold 0
 * Verification: scripts/mwcc_build.sh src/rel_deck.c && 
 *               scripts/mwcc_diff.py asm/rel_deck/text.s build/mwcc/rel_deck.o
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
 * STATUS: 48 function(s) matched via the automated pass so far.
 *   func_0000B440 (11 words)
 *   func_0000D6D0 (25 words)
 *   func_0000D734 (25 words)
 *   func_0000DA6C (19 words)
 *   func_0000EB20 (13 words)
 *   func_0000F0D0 (14 words)
 *   func_00012DC4 (14 words)
 *   func_00013060 (4 words)
 *   func_00013070 (5 words)
 *   func_00013084 (5 words)
 *   func_00013098 (8 words)
 *   func_00015B04 (4 words)
 *   func_00015D20 (2 words)
 *   func_00015D28 (23 words)
 *   func_00017290 (2 words)
 *   func_00018638 (39 words)
 *   func_0001D4E0 (22 words)
 *   func_0001FCA0 (27 words)
 *   func_0001FD0C (27 words)
 *   func_0001FD78 (27 words)
 *   func_0001FDE4 (27 words)
 *   func_0001FE50 (27 words)
 *   func_00020B1C (2 words)
 *   func_00020CAC (13 words)
 *   func_00020E5C (18 words)
 *   func_00022148 (16 words)
 *   func_00022264 (4 words)
 *   func_00022274 (4 words)
 *   func_00022974 (13 words)
 *   func_000229A8 (18 words)
 *   func_00022B68 (2 words)
 *   func_0002308C (16 words)
 *   func_000230F0 (4 words)
 *   func_00023100 (3 words)
 *   func_000235F8 (13 words)
 *   func_0002362C (12 words)
 *   func_0002365C (12 words)
 *   func_00023A54 (2 words)
 *   func_00023A5C (2 words)
 *   func_00023A64 (2 words)
 *   func_00023A6C (2 words)
 *   func_00023C7C (3 words)
 *   func_00023C88 (3 words)
 *   func_00023C94 (16 words)
 *   func_00023CD4 (4 words)
 *   func_00023CE4 (3 words)
 *   func_00023CF0 (4 words)
 *   func_00024220 (18 words)
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
extern int ehsys_20E340D9();
extern int ehsys_4AA58320();
extern int ehsys_56D1651D();
extern int ehsys_5DF04F49();
extern int ehsys_60B55A50();
extern int ehsys_942B03D0();
extern int ehsys_98E07D26();
extern int ehsys_A4AFF8E6();
extern int ehsys_B4471B5E();
extern int ehsys_B8AD96EA();
extern int ehsys_C792FA38();
extern int ehsys_C9D9E989();
extern int ehsys_D5D33185();
extern int ehsys_D853F15C();
extern int ehsys_E5738C32();
extern int ehsys_E58C0FDC();
extern int ehsys_E62CCE79();
extern int ehsys_EF9B5D06();
extern int func_0000EE34();
extern int func_0000EF68();
extern int func_00015E5C();
extern int func_0001708C();
extern int func_000186D4();
extern int func_000196A8();
extern int func_00019770();
extern int func_000197EC();
extern int func_000198AC();
extern int func_0001995C();
extern int func_0001D538();
extern int func_0001D618();
extern int func_0001D6AC();
extern int func_0001D7C8();
extern int func_0001D9CC();
extern int func_0001E4CC();
extern int func_0001E644();
extern int func_00022B70();
extern int func_00022B8C();
extern int func_00022B94();
extern int func_000236B8();
extern int func_000237FC();
extern int D_0002CFE8;
extern int D_0002DA7C;
extern int D_0002E0FC;
extern int D_0002E104;
extern int D_0002E110;
extern int D_0002E114;
extern int D_0002E120;
extern int D_F768A0;
extern int D_F76A70;
extern int D_F76A80;
extern int D_F76C90;
extern int D_F76C9C;
extern int D_F76D64;
extern int D_F76D7C;
extern int D_F76DB0;
extern int D_F76E88;
extern int D_F76EA0;
extern int D_F76ED4;

/* forward declarations for functions defined later in this file (address order). */
s32 func_0000B440(s32 arg0);
s32 func_0000D6D0(s32 arg0, s32 arg1);
s32 func_0000D734(s32 arg0, s32 arg1);
s32 func_0000DA6C(s32 arg0, s32 arg1);
s32 func_0000EB20(void);
void func_0000F0D0(void);
s32 func_00012DC4(u16 *arg0);
s32 func_00013060(void);
u32 func_00013070(void);
u32 func_00013084(void);
s32 func_00013098(void);
s32 func_00015B04(u16 *arg0, u16 *arg1);
void func_00015D20(void);
void func_00015D28(void);
void func_00017290(void);
void func_00018638(s32 arg0, int arg1, int arg2, int arg3);
void func_0001D4E0(void);
void func_0001FCA0(s32 arg0, s32 arg1, s32 arg2, int arg3);
void func_0001FD0C(s32 arg0, s32 arg1, s32 arg2, int arg3);
void func_0001FD78(s32 arg0, s32 arg1, s32 arg2, int arg3);
void func_0001FDE4(s32 arg0, s32 arg1, s32 arg2, int arg3);
void func_0001FE50(s32 arg0, s32 arg1, s32 arg2, int arg3);
void func_00020B1C(void);
void func_00020CAC(void);
void func_00020E5C(void);
void func_00022148(void);
s32 func_00022264(s32 arg0);
s32 func_00022274(s32 arg0);
void func_00022974(void);
void func_000229A8(void);
void func_00022B68(void);
void func_0002308C(void);
void func_000230F0(void);
void func_00023100(void);
void func_000235F8(void);
void func_0002362C(void);
void func_0002365C(void);
void func_00023A54(void *unused);
void func_00023A5C(void *unused, s32 unused2);
void func_00023A64(void *unused);
void func_00023A6C(void *unused, s32 unused2);
void func_00023C7C(void);
void func_00023C88(void);
void func_00023C94(void);
void func_00023CD4(s32 arg0);
void func_00023CE4(void);
void func_00023CF0(s32 arg0);
void func_00024220(void);

/* func_0000B440 — 11 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_0000B440(s32 arg0) {
    s32 sp1C;

    sp1C = arg0;
    ehsys_EF9B5D06(&sp1C, &D_0002CFE8);
    return sp1C;
}

/* func_0000D6D0 — 25 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_0000D6D0(s32 arg0, s32 arg1) {
    s32 temp_s0;

    temp_s0 = arg0 & 0xFFFF;
    if ((ehsys_E5738C32(temp_s0) != 0) && (arg1 & (1 << ehsys_98E07D26(temp_s0)))) {
        return 1;
    }
    return 0;
}

/* func_0000D734 — 25 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_0000D734(s32 arg0, s32 arg1) {
    s32 temp_s0;

    temp_s0 = arg0 & 0xFFFF;
    if ((ehsys_E5738C32(temp_s0) != 0) && (arg1 & (1 << ehsys_E62CCE79(temp_s0)))) {
        return 1;
    }
    return 0;
}

/* func_0000DA6C — 19 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_0000DA6C(s32 arg0, s32 arg1) {
    return (arg1 & (1 << ehsys_56D1651D(func_00013098(), arg0 & 0xFFFF))) != 0;
}

/* func_0000EB20 — 13 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_0000EB20(void) {
    ehsys_B4471B5E(func_0000EE34, func_0000EF68, &D_F768A0);
    return 0;
}

/* func_0000F0D0 — 14 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_0000F0D0(void) {
    func_00015D20();
    ehsys_20E340D9(D_0002E0FC, D_0002E114);
    ehsys_D5D33185(0x2B7E);
}

/* func_00012DC4 — 14 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_00012DC4(u16 *arg0) {
    u16 temp_v1;

    temp_v1 = *arg0;
    if ((temp_v1 != 4) && (temp_v1 != 2) && (temp_v1 != 0)) {
        return 0;
    }
    return 1;
}

/* func_00013060 — 4 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_00013060(void) {
    return (u8) D_0002DA7C & 3;
}

/* func_00013070 — 5 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
u32 func_00013070(void) {
    return (u32) ((u8) D_0002DA7C << 0x1C) >> 0x1E;
}

/* func_00013084 — 5 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
u32 func_00013084(void) {
    return (u32) (D_0002DA7C << 0x14) >> 0x18;
}

/* func_00013098 — 8 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_00013098(void) {
    return func_00013070() != 0;
}

/* func_00015B04 — 4 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_00015B04(u16 *arg0, u16 *arg1) {
    return *arg0 - *arg1;
}

/* func_00015D20 — 2 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00015D20(void) {
    func_00015D28();
}

/* func_00015D28 — 23 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00015D28(void) {
    if (D_0002E104 != 0) {
        ehsys_20E340D9(D_0002E0FC, D_0002E104);
        D_0002E104 = 0;
    }
    if (D_0002E110 != 0) {
        ehsys_20E340D9(D_0002E0FC, D_0002E110);
        D_0002E110 = 0;
    }
}

/* func_00017290 — 2 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00017290(void) {
    func_0001708C();
}

/* func_00018638 — 39 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00018638(s32 arg0, int arg1, int arg2, int arg3) {
    s32 temp_s0;

    temp_s0 = ehsys_E58C0FDC(func_00015E5C(0x8033), 0x9A);
    ehsys_B8AD96EA(arg0);
    ehsys_942B03D0(0xC, 0xC);
    ehsys_60B55A50(-1);
    func_000186D4(arg1, arg2, arg3, temp_s0);
    ehsys_A4AFF8E6();
}

/* func_0001D4E0 — 22 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_0001D4E0(void) {
    func_0001E644(func_0001E4CC(func_0001D9CC(func_0001D6AC(func_0001D7C8(func_0001D618(func_0001D538()), (u8) D_0002E120 & 0xF)))));
}

/* func_0001FCA0 — 27 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_0001FCA0(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    func_000196A8(arg0, (arg1 & 0xFFFF) | ((arg2 & 0xFFFF) << 0x10), arg3, func_00015E5C(0x8007));
}

/* func_0001FD0C — 27 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_0001FD0C(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    func_00019770(arg0, (arg1 & 0xFFFF) | ((arg2 & 0xFFFF) << 0x10), arg3, func_00015E5C(0x8007));
}

/* func_0001FD78 — 27 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_0001FD78(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    func_000197EC(arg0, (arg1 & 0xFFFF) | ((arg2 & 0xFFFF) << 0x10), arg3, func_00015E5C(0x8007));
}

/* func_0001FDE4 — 27 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_0001FDE4(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    func_000198AC(arg0, (arg1 & 0xFFFF) | ((arg2 & 0xFFFF) << 0x10), arg3, func_00015E5C(0x800A));
}

/* func_0001FE50 — 27 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_0001FE50(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    func_0001995C(arg0, (arg1 & 0xFFFF) | ((arg2 & 0xFFFF) << 0x10), arg3, func_00015E5C(0x800A));
}

/* func_00020B1C — 2 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00020B1C(void) {

}

/* func_00020CAC — 13 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00020CAC(void) {
    ehsys_5DF04F49(&D_F76A80);
    ehsys_memset(&D_F76A70, 0, 0xF0);
}

/* func_00020E5C — 18 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00020E5C(void) {
    ehsys_D853F15C(1);
    ehsys_C792FA38(0);
    ehsys_C9D9E989(1);
    ehsys_4AA58320(1);
    ehsys_942B03D0(0xE, 0xE);
    ehsys_60B55A50(0xFF000000);
}

/* func_00022148 — 16 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00022148(void) {
    ehsys_D853F15C(1);
    ehsys_C792FA38(0);
    ehsys_C9D9E989(1);
    ehsys_942B03D0(0xF, 0xF);
    ehsys_60B55A50(0xFF000000);
}

/* func_00022264 — 4 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_00022264(s32 arg0) {
    return *(s32 *)0xF76BB8 + arg0;
}

/* func_00022274 — 4 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_00022274(s32 arg0) {
    return arg0 - *(s32 *)0xF76BB8;
}

/* func_00022974 — 13 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00022974(void) {
    ehsys_5DF04F49(&D_F76C9C);
    ehsys_memset(&D_F76C90, 0, 0xD4);
}

/* func_000229A8 — 18 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_000229A8(void) {
    ehsys_D853F15C(1);
    ehsys_C792FA38(0);
    ehsys_C9D9E989(1);
    ehsys_4AA58320(1);
    ehsys_942B03D0(0xE, 0xE);
    ehsys_60B55A50(0xFF000000);
}

/* func_00022B68 — 2 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00022B68(void) {

}

/* func_0002308C — 16 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_0002308C(void) {
    func_00023A54(&D_F76D7C);
    ehsys_5DF04F49(&D_F76DB0);
    ehsys_memset(&D_F76D64, 0, 0x124);
}

/* func_000230F0 — 4 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_000230F0(void) {
    *(s32 *)0xF76D64 = 1;
}

/* func_00023100 — 3 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00023100(void) {
    func_00023A64(&D_F76D7C);
}

/* func_000235F8 — 13 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_000235F8(void) {
    ehsys_D853F15C(1);
    ehsys_C792FA38(0);
    ehsys_C9D9E989(1);
    ehsys_4AA58320(1);
}

/* func_0002362C — 12 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_0002362C(void) {
    func_000235F8();
    ehsys_942B03D0(0xE, 0xE);
    ehsys_60B55A50(-1);
}

/* func_0002365C — 12 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_0002365C(void) {
    func_000235F8();
    ehsys_942B03D0(0xE, 0xE);
    ehsys_60B55A50(0xFF000000);
}

/* func_00023A54 — 2 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00023A54(void *unused) {
    func_00022B68();
}

/* func_00023A5C — 2 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00023A5C(void *unused, s32 unused2) {
    func_00022B70();
}

/* func_00023A64 — 2 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00023A64(void *unused) {
    func_00022B8C();
}

/* func_00023A6C — 2 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00023A6C(void *unused, s32 unused2) {
    func_00022B94();
}

/* func_00023C7C — 3 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00023C7C(void) {
    func_000236B8(&D_F76EA0);
}

/* func_00023C88 — 3 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00023C88(void) {
    func_000237FC(&D_F76EA0);
}

/* func_00023C94 — 16 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00023C94(void) {
    func_00023A54(&D_F76EA0);
    ehsys_5DF04F49(&D_F76ED4);
    ehsys_memset(&D_F76E88, 0, 0x11C);
}

/* func_00023CD4 — 4 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00023CD4(s32 arg0) {
    func_00023A5C(&D_F76EA0, arg0);
}

/* func_00023CE4 — 3 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00023CE4(void) {
    func_00023A64(&D_F76EA0);
}

/* func_00023CF0 — 4 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00023CF0(s32 arg0) {
    func_00023A6C(&D_F76EA0, arg0);
}

/* func_00024220 — 18 words. MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00024220(void) {
    ehsys_D853F15C(1);
    ehsys_C792FA38(0);
    ehsys_C9D9E989(1);
    ehsys_4AA58320(1);
    ehsys_942B03D0(0xE, 0xE);
    ehsys_60B55A50(0xFF000000);
}

