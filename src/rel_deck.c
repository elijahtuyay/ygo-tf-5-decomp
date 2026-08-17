/*
 * rel_deck.prx — reconstructed code (matching decompilation)
 *
 * Compiler:     Metrowerks CodeWarrior for PSP — MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,s -sdatathreshold 0
 * Verification: scripts/mwcc_build.sh src/rel_deck.c
 *               scripts/mwcc_diff.py asm/rel_deck/text.s build/mwcc/rel_deck.o
 *
 * Every function below is byte-identical to the shipped module — each was
 * accepted only on a MATCH verdict from scripts/mwcc_diff.py, and the whole
 * file is re-verified after assembly (scripts/assemble_module.py).
 * Functions are in ADDRESS ORDER, which is what the linker needs.
 *
 * Import names are resolved from the module's NID tables and are identical
 * across all 28 modules — see docs/nids/README.md.
 *
 * STATUS: 38 functions matched here. The rest of the module is not
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
extern char D_0002CFE8;
extern char D_0002DA7C;
extern char D_0002E120;
extern char D_F768A0;
extern char D_F76A70;
extern char D_F76A80;
extern char D_F76C90;
extern char D_F76C9C;
extern char D_F76EA0;
extern int ehsys_4AA58320();
extern int ehsys_56D1651D();
extern int ehsys_5DF04F49();
extern int ehsys_60B55A50();
extern int ehsys_942B03D0();
extern int ehsys_5F00A362();
extern int ehsys_97BB99A5();
extern int ehsys_98E07D26();
extern int ehsys_A4AFF8E6();
extern int ehsys_B4471B5E();
extern int ehsys_B89D38DC();
extern int ehsys_B8AD96EA();
extern int ehsys_BC8E65D7();
extern int ehsys_C792FA38();
extern int ehsys_C9D9E989();
extern int ehsys_D853F15C();
extern int ehsys_E5738C32();
extern int ehsys_E58C0FDC();
extern int ehsys_E62CCE79();
extern int ehsys_EF9B5D06();
extern int ehsys_memset();
extern int func_0000EE34();
extern int func_0000EF68();
extern int func_00015D28();
extern int func_00015E5C();
extern int func_0001708C();
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

/* ---- forward declarations ---- */
s32 func_0000B440(s32 arg0);
s32 func_0000C858(s32 arg0, s32 arg1, s32 arg2, int arg3);
s32 func_0000D6D0(s32 arg0, s32 arg1);
s32 func_0000D734(s32 arg0, s32 arg1);
s32 func_0000DA6C(s32 arg0, s32 arg1);
s32 func_0000EB20(void);
s32 func_0001187C(s32 arg0, s32 arg1, s32 arg2, int arg3);
s32 func_00012DC4(u16 *arg0);
s32 func_00013060(void);
s32 func_00013098(void);
s32 func_00014E50(s32 arg0, s32 arg1, s32 arg2, int arg3);
s32 func_00015AEC(s32 *arg0, s32 arg1);
s32 func_00015B04(u16 *arg0, u16 *arg1);
s32 func_000186D4(s32 arg0, s32 arg1, s32 arg2, int arg3);
s32 func_00018C44(s32 arg0, s32 arg1, s32 arg2);
s32 func_0001AE20(s32 arg0, s32 arg1, s32 arg2, int arg3);
s32 func_0001C134(s32 arg0);
s32 func_0001D4CC(s32 arg0, s32 arg1, s32 arg2, int arg3);
s32 func_0001D7B4(s32 arg0, s32 arg1, s32 arg2, int arg3);
s32 func_0001F328(s32 arg0, s32 arg1, s32 arg2);
s32 func_0001F890(s32 arg0, s32 arg1, s32 arg2, int arg3);
s32 func_0001FC98(s32 arg0, s32 arg1, s32 arg2, int arg3);
s32 func_00020B10(s32 arg0, s32 arg1);
s32 func_00022134(s32 arg0, s32 arg1, s32 arg2, int arg3);
s32 func_00022188(void);
s32 func_00022264(s32 arg0);
s32 func_00022274(s32 arg0);
s32 func_00022960(s32 arg0, s32 arg1, s32 arg2, int arg3);
s32 func_00023078(s32 arg0, s32 arg1, s32 arg2, int arg3);
s32 func_000235EC(s32 arg0, s32 arg1);
s32 func_00024214(s32 arg0, s32 arg1);
u32 func_00013070(void);
void func_00015D20(void);
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
void func_00022974(void);
void func_000229A8(void);
void func_00022B68(void);
void func_000230F0(void);
void func_000235F8(void);
void func_0002362C(void);
void func_0002365C(void);
void func_00023A54(void);
void func_00023A5C(void);
void func_00023A64(void);
void func_00023A6C(void);
void func_00023C7C(void);
void func_00024220(void);

/* func_0000B440 — 11 words. MATCH 100% (shape: m2c). */
s32 func_0000B440(s32 arg0) {
    s32 sp1C;

    sp1C = arg0;
    ehsys_EF9B5D06(&sp1C, &D_0002CFE8);
    return sp1C;
}

/* func_0000C858 — 5 words. MATCH 100% (shape: thunk, tail call w/ shifted args). */
s32 func_0000C858(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    return ehsys_BC8E65D7(arg0 << 6, arg1 << 6, arg2 << 6, arg3, -1);
}

/* func_0000D6D0 — 25 words. MATCH 100% (shape: m2c). */
s32 func_0000D6D0(s32 arg0, s32 arg1) {
    s32 temp_s0;

    temp_s0 = arg0 & 0xFFFF;
    if ((ehsys_E5738C32(temp_s0) != 0) && (arg1 & (1 << ehsys_98E07D26(temp_s0)))) {
        return 1;
    }
    return 0;
}

/* func_0000D734 — 25 words. MATCH 100% (shape: m2c). */
s32 func_0000D734(s32 arg0, s32 arg1) {
    s32 temp_s0;

    temp_s0 = arg0 & 0xFFFF;
    if ((ehsys_E5738C32(temp_s0) != 0) && (arg1 & (1 << ehsys_E62CCE79(temp_s0)))) {
        return 1;
    }
    return 0;
}

/* func_0000DA6C — 19 words. MATCH 100% (shape: m2c). */
s32 func_0000DA6C(s32 arg0, s32 arg1) {
    return (arg1 & (1 << ehsys_56D1651D(func_00013098(), arg0 & 0xFFFF))) != 0;
}

/* func_0000EB20 — 13 words. MATCH 100% (shape: m2c). */
s32 func_0000EB20(void) {
    ehsys_B4471B5E(func_0000EE34, func_0000EF68, &D_F768A0);
    return 0;
}

/* func_0001187C — 5 words. MATCH 100% (shape: thunk, tail call w/ shifted args). */
s32 func_0001187C(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    return ehsys_BC8E65D7(arg0 << 6, arg1 << 6, arg2 << 6, arg3, -1);
}

/* func_00012DC4 — 14 words. MATCH 100% (shape: m2c). */
s32 func_00012DC4(u16 *arg0) {
    u16 temp_v1;

    temp_v1 = *arg0;
    if ((temp_v1 != 4) && (temp_v1 != 2) && (temp_v1 != 0)) {
        return 0;
    }
    return 1;
}

/* func_00013060 — 4 words. MATCH 100% (shape: m2c). */
s32 func_00013060(void) {
    return (u8) D_0002DA7C & 3;
}

/* func_00013070 — 5 words. MATCH 100% (shape: m2c). */
u32 func_00013070(void) {
    return (u32) ((u8) D_0002DA7C << 0x1C) >> 0x1E;
}

/* func_00013098 — 8 words. MATCH 100% (shape: m2c). */
s32 func_00013098(void) {
    return func_00013070() != 0;
}

/* func_00014E50 — 5 words. MATCH 100% (shape: thunk, tail call w/ shifted args). */
s32 func_00014E50(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    return ehsys_BC8E65D7(arg0 << 6, arg1 << 6, arg2 << 6, arg3, -1);
}

/* func_00015AEC — 6 words. MATCH 100% (shape: m2c; return value forces slt instead of blez). */
s32 func_00015AEC(s32 *arg0, s32 arg1) {
    s32 temp = 0 < arg1;
    if (temp) {
        *arg0 = arg1;
    }
    return temp;
}

/* func_00015B04 — 4 words. MATCH 100% (shape: m2c). */
s32 func_00015B04(u16 *arg0, u16 *arg1) {
    return *arg0 - *arg1;
}

/* func_00015D20 — 2 words. MATCH 100% (shape: m2c). */
void func_00015D20(void) {
    func_00015D28();
}

/* func_00017290 — 2 words. MATCH 100% (shape: m2c). */
void func_00017290(void) {
    func_0001708C();
}

/* func_00018638 — 39 words. MATCH 100% (shape: m2c). */
void func_00018638(s32 arg0, int arg1, int arg2, int arg3) {
    s32 temp_s0;

    temp_s0 = ehsys_E58C0FDC(func_00015E5C(0x8033), 0x9A);
    ehsys_B8AD96EA(arg0);
    ehsys_942B03D0(0xC, 0xC);
    ehsys_60B55A50(-1);
    func_000186D4(arg1, arg2, arg3, temp_s0);
    ehsys_A4AFF8E6();
}

/* func_000186D4 — 5 words. MATCH 100% (shape: thunk, tail call w/ shifted args). */
s32 func_000186D4(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    return ehsys_BC8E65D7(arg0 << 6, arg1 << 6, arg2 << 6, arg3, -1);
}

/* func_00018C44 — 4 words. MATCH 100% (shape: thunk, tail call w/ shifted args). */
s32 func_00018C44(s32 arg0, s32 arg1, s32 arg2) {
    return ehsys_B89D38DC(arg0 << 6, arg1 << 6, arg2 << 6);
}

/* func_0001AE20 — 5 words. MATCH 100% (shape: thunk, tail call w/ shifted args). */
s32 func_0001AE20(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    return ehsys_BC8E65D7(arg0 << 6, arg1 << 6, arg2 << 6, arg3, -1);
}

/* func_0001C134 — 2 words. MATCH 100% (shape: thunk, tail call w/ shifted arg). */
s32 func_0001C134(s32 arg0) {
    return ehsys_5F00A362(arg0 << 6);
}

/* func_0001D4CC — 5 words. MATCH 100% (shape: thunk, tail call w/ shifted args). */
s32 func_0001D4CC(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    return ehsys_BC8E65D7(arg0 << 6, arg1 << 6, arg2 << 6, arg3, -1);
}

/* func_0001D4E0 — 22 words. MATCH 100% (shape: m2c). */
void func_0001D4E0(void) {
    func_0001E644(func_0001E4CC(func_0001D9CC(func_0001D6AC(func_0001D7C8(func_0001D618(func_0001D538()), (u8) D_0002E120 & 0xF)))));
}

/* func_0001D7B4 — 5 words. MATCH 100% (shape: thunk, tail call w/ shifted args). */
s32 func_0001D7B4(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    return ehsys_BC8E65D7(arg0 << 6, arg1 << 6, arg2 << 6, arg3, -1);
}

/* func_0001F328 — 4 words. MATCH 100% (shape: thunk, tail call w/ shifted args). */
s32 func_0001F328(s32 arg0, s32 arg1, s32 arg2) {
    return ehsys_B89D38DC(arg0 << 6, arg1 << 6, arg2 << 6);
}

/* func_0001F890 — 5 words. MATCH 100% (shape: thunk, tail call w/ shifted args). */
s32 func_0001F890(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    return ehsys_BC8E65D7(arg0 << 6, arg1 << 6, arg2 << 6, arg3, -1);
}

/* func_0001FC98 — 2 words. MATCH 100% (shape: thunk, tail call w/ fixed arg). */
s32 func_0001FC98(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    return ehsys_BC8E65D7(arg0, arg1, arg2, arg3, -1);
}

/* func_0001FCA0 — 27 words. MATCH 100% (shape: m2c). */
void func_0001FCA0(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    func_000196A8(arg0, (arg1 & 0xFFFF) | ((arg2 & 0xFFFF) << 0x10), arg3, func_00015E5C(0x8007));
}

/* func_0001FD0C — 27 words. MATCH 100% (shape: m2c). */
void func_0001FD0C(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    func_00019770(arg0, (arg1 & 0xFFFF) | ((arg2 & 0xFFFF) << 0x10), arg3, func_00015E5C(0x8007));
}

/* func_0001FD78 — 27 words. MATCH 100% (shape: m2c). */
void func_0001FD78(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    func_000197EC(arg0, (arg1 & 0xFFFF) | ((arg2 & 0xFFFF) << 0x10), arg3, func_00015E5C(0x8007));
}

/* func_0001FDE4 — 27 words. MATCH 100% (shape: m2c). */
void func_0001FDE4(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    func_000198AC(arg0, (arg1 & 0xFFFF) | ((arg2 & 0xFFFF) << 0x10), arg3, func_00015E5C(0x800A));
}

/* func_0001FE50 — 27 words. MATCH 100% (shape: m2c). */
void func_0001FE50(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    func_0001995C(arg0, (arg1 & 0xFFFF) | ((arg2 & 0xFFFF) << 0x10), arg3, func_00015E5C(0x800A));
}

/* func_00020B10 — 3 words. MATCH 100% (shape: thunk, tail call w/ fixed args). */
s32 func_00020B10(s32 arg0, s32 arg1) {
    return ehsys_97BB99A5(arg0, arg1, 0, 0);
}

/* func_00020B1C — 2 words. MATCH 100% (shape: m2c). */
void func_00020B1C(void) {

}

/* func_00020CAC — 13 words. MATCH 100% (shape: m2c). */
void func_00020CAC(void) {
    ehsys_5DF04F49(&D_F76A80);
    ehsys_memset(&D_F76A70, 0, 0xF0);
}

/* func_00020E5C — 18 words. MATCH 100% (shape: m2c). */
void func_00020E5C(void) {
    ehsys_D853F15C(1);
    ehsys_C792FA38(0);
    ehsys_C9D9E989(1);
    ehsys_4AA58320(1);
    ehsys_942B03D0(0xE, 0xE);
    ehsys_60B55A50(0xFF000000);
}

/* func_00022134 — 5 words. MATCH 100% (shape: thunk, tail call w/ shifted args). */
s32 func_00022134(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    return ehsys_BC8E65D7(arg0 << 6, arg1 << 6, arg2 << 6, arg3, -1);
}

/* func_00022148 — 16 words. MATCH 100% (shape: m2c). */
void func_00022148(void) {
    ehsys_D853F15C(1);
    ehsys_C792FA38(0);
    ehsys_C9D9E989(1);
    ehsys_942B03D0(0xF, 0xF);
    ehsys_60B55A50(0xFF000000);
}

/* func_00022188 — 2 words. MATCH 100% (shape: thunk, tail call w/ fixed arg). */
s32 func_00022188(void) {
    return ehsys_C792FA38(0);
}

/* func_00022264 — 4 words. MATCH 100% (shape: m2c). */
s32 func_00022264(s32 arg0) {
    return *(s32 *)0xF76BB8 + arg0;
}

/* func_00022274 — 4 words. MATCH 100% (shape: m2c). */
s32 func_00022274(s32 arg0) {
    return arg0 - *(s32 *)0xF76BB8;
}

/* func_00022960 — 5 words. MATCH 100% (shape: thunk, tail call w/ shifted args). */
s32 func_00022960(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    return ehsys_BC8E65D7(arg0 << 6, arg1 << 6, arg2 << 6, arg3, -1);
}

/* func_00022974 — 13 words. MATCH 100% (shape: m2c). */
void func_00022974(void) {
    ehsys_5DF04F49(&D_F76C9C);
    ehsys_memset(&D_F76C90, 0, 0xD4);
}

/* func_000229A8 — 18 words. MATCH 100% (shape: m2c). */
void func_000229A8(void) {
    ehsys_D853F15C(1);
    ehsys_C792FA38(0);
    ehsys_C9D9E989(1);
    ehsys_4AA58320(1);
    ehsys_942B03D0(0xE, 0xE);
    ehsys_60B55A50(0xFF000000);
}

/* func_00022B68 — 2 words. MATCH 100% (shape: m2c). */
void func_00022B68(void) {

}

/* func_000230F0 — 4 words. MATCH 100% (shape: m2c). */
void func_000230F0(void) {
    *(s32 *)0xF76D64 = 1;
}

/* func_00023078 — 5 words. MATCH 100% (shape: thunk, tail call w/ shifted args). */
s32 func_00023078(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    return ehsys_BC8E65D7(arg0 << 6, arg1 << 6, arg2 << 6, arg3, -1);
}

/* func_000235EC — 3 words. MATCH 100% (shape: thunk, tail call w/ fixed args). */
s32 func_000235EC(s32 arg0, s32 arg1) {
    return ehsys_97BB99A5(arg0, arg1, 0, 0);
}

/* func_000235F8 — 13 words. MATCH 100% (shape: m2c). */
void func_000235F8(void) {
    ehsys_D853F15C(1);
    ehsys_C792FA38(0);
    ehsys_C9D9E989(1);
    ehsys_4AA58320(1);
}

/* func_0002362C — 12 words. MATCH 100% (shape: m2c). */
void func_0002362C(void) {
    func_000235F8();
    ehsys_942B03D0(0xE, 0xE);
    ehsys_60B55A50(-1);
}

/* func_0002365C — 12 words. MATCH 100% (shape: m2c). */
void func_0002365C(void) {
    func_000235F8();
    ehsys_942B03D0(0xE, 0xE);
    ehsys_60B55A50(0xFF000000);
}

/* func_00023A54 — 2 words. MATCH 100% (shape: m2c). */
void func_00023A54(void) {
    func_00022B68();
}

/* func_00023A5C — 2 words. MATCH 100% (shape: m2c). */
void func_00023A5C(void) {
    func_00022B70();
}

/* func_00023A64 — 2 words. MATCH 100% (shape: m2c). */
void func_00023A64(void) {
    func_00022B8C();
}

/* func_00023A6C — 2 words. MATCH 100% (shape: m2c). */
void func_00023A6C(void) {
    func_00022B94();
}

/* func_00023C7C — 3 words. MATCH 100% (shape: m2c). */
void func_00023C7C(void) {
    func_000236B8(&D_F76EA0);
}

/* func_00024214 — 3 words. MATCH 100% (shape: thunk, tail call w/ fixed args). */
s32 func_00024214(s32 arg0, s32 arg1) {
    return ehsys_97BB99A5(arg0, arg1, 0, 0);
}

/* func_00024220 — 18 words. MATCH 100% (shape: m2c). */
void func_00024220(void) {
    ehsys_D853F15C(1);
    ehsys_C792FA38(0);
    ehsys_C9D9E989(1);
    ehsys_4AA58320(1);
    ehsys_942B03D0(0xE, 0xE);
    ehsys_60B55A50(0xFF000000);
}

