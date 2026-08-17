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
 * STATUS: 88 functions matched here. The rest of the module is not
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
extern char D_0002E120;
extern char D_F768A0;
extern char D_F76A70;
extern char D_F76A80;
extern char D_F76C90;
extern char D_F76C9C;
extern char D_F76D7C;
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
extern int ehsys_CC7A2A21();
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
extern int func_0001907C();
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
extern int func_000206E0();
extern int func_000236B8();
extern int func_000237FC();
extern int ehsys_3BB2BAC6();

/* ---- forward declarations ---- */
s32 func_0001C118(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
s32 func_00020C90(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
s32 func_000232D8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
s32 func_00023EAC(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
s32 func_0000B440(s32 arg0);
s32 func_0000C858(s32 arg0, s32 arg1, s32 arg2, int arg3);
s32 func_0000D670(s32 arg0, s32 arg1);
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
s32 func_0002151C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7);
s32 func_00021530(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7);
s32 func_00022134(s32 arg0, s32 arg1, s32 arg2, int arg3);
s32 func_00022188(void);
s32 func_00022264(s32 arg0);
s32 func_00022274(s32 arg0);
s32 func_00022960(s32 arg0, s32 arg1, s32 arg2, int arg3);
s32 func_00023078(s32 arg0, s32 arg1, s32 arg2, int arg3);
s32 func_000235EC(s32 arg0, s32 arg1);
s32 func_00024214(s32 arg0, s32 arg1);
u32 func_00013070(void);
u32 func_00013084(void);
void func_00015D20(void);
void func_00017290(void);
void func_00018638(s32 arg0, int arg1, int arg2, int arg3);
void func_0001C630(u16 *arg0, u16 *arg1, s32 arg2);
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
void func_000229F0(void *arg0);
void func_00022B68(void);
void func_00023100(void);
void func_00023C7C(void);
void func_00023C88(int arg0);
void func_00023CD4(void *arg0);
void func_00023CE4(void);
void func_00023CF0(void *arg0);
void func_000230F0(void);
void func_000235F8(void);
void func_0002362C(void);
void func_0002365C(void);
void func_00023A54(void);
void func_00023A5C();
void func_00023A64();
void func_00023A6C();
void func_00024220(void);
/* func_000068B4 — 31 words. MATCH 100% (shape: m2c). */
void func_000068B4(void) {
    extern int D_0002CFE0;
    extern int D_0002E0B0;
    extern int D_0002E0FC;
    extern int ehsys_20E340D9();
    extern int ehsys_834A6E13();
    extern int func_000068B4();
    s32 temp_a1;

    ehsys_834A6E13(&D_0002E0B0, (*(int *)((char *)D_0002CFE0 + 0x24C)));
    temp_a1 = (*(int *)((char *)D_0002CFE0 + 0x24C));
    if (temp_a1 != 0) {
        ehsys_20E340D9(D_0002E0FC, temp_a1);
        (*(int *)((char *)D_0002CFE0 + 0x24C)) = 0;
    }
    if (D_0002CFE0 != 0) {
        ehsys_20E340D9(D_0002E0FC, D_0002CFE0);
    }
    D_0002CFE0 = 0;
}

/* func_00006D3C — 11 words. MATCH 100% (shape: m2c; (x<<27)>>29 field extract
 * via unsigned intermediate to get srl not sra). */
s32 func_00006D3C(void) {
    extern int D_0002CFE0;
    extern int D_0002D930;
    extern int func_00000F98();
    u8 byte6;
    u16 half2;
    u32 v1;

    byte6 = *(u8 *)((char *)D_0002CFE0 + 0x6);
    half2 = *(u16 *)((char *)D_0002CFE0 + 0x2);
    v1 = ((u32) byte6 << 27) >> 29;
    v1 = v1 << 5;
    return func_00000F98((char *)&D_0002D930 + v1, half2);
}

/* func_0000B440 — 11 words. MATCH 100% (shape: m2c). */
s32 func_0000B440(s32 arg0) {
    s32 sp1C;

    sp1C = arg0;
    ehsys_EF9B5D06(&sp1C, &D_0002CFE8);
    return sp1C;
}
/* func_0000BF78 — 35 words. MATCH 100% (shape: m2c). */
void func_0000BF78(void) {
    extern int D_0002D910;
    extern int D_0002E0FC;
    extern int ehsys_20E340D9();
    extern int ehsys_E1139F1A();
    extern int func_0000BF78();
    s32 temp_a0;

    temp_a0 = (*(int *)((char *)D_0002D910 + 0x14));
    if (temp_a0 != 0) {
        ehsys_E1139F1A(temp_a0);
        ehsys_20E340D9(D_0002E0FC, (*(int *)((char *)D_0002D910 + 0x14)));
    }
    ehsys_E1139F1A((*(int *)((char *)D_0002D910 + 0x10)));
    ehsys_20E340D9(D_0002E0FC, (*(int *)((char *)D_0002D910 + 0x10)));
    ehsys_20E340D9(D_0002E0FC, D_0002D910);
    D_0002D910 = 0;
}

/* func_0000C0A8 — 12 words. MATCH 100% (shape: thunk; forwards $a0/$a2). */
void func_0000C0A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    extern char D_00029DA0;
    extern int func_0001FEBC();

    func_0001FEBC(arg0, (char *)&D_00029DA0 + ((arg1 & 0xFFFF) + 1) * 6, arg2, arg3 + 1, 0xA4, 0);
}

/* func_0000C838 — 8 words. MATCH 100% (shape: thunk, tail call w/ shifted args). */
int func_0000C838(s32 arg0, s32 arg1, int arg2) {
    extern int ehsys_B89D38DC();

    return ehsys_B89D38DC(arg0 << 6, arg1 << 6, (0x1E0 - arg0) << 6, arg2);
}

/* func_0000C858 — 5 words. MATCH 100% (shape: thunk, tail call w/ shifted args). */
s32 func_0000C858(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    return ehsys_BC8E65D7(arg0 << 6, arg1 << 6, arg2 << 6, arg3, -1);
}

/* func_0000D198 — 41 words. MATCH 100% (shape: m2c; volatile reload of
 * D_0002D916 reproduces the target's separate reload before the branch and
 * the multiply — order of the two leading stores also matters). */
void func_0000D198(void *arg0, s32 arg1) {
    extern char D_0002D914;
    extern short D_0002D916;
    extern int D_0002D91C;
    extern int D_0002D920;
    extern int D_0002D924;
    extern int D_0002E0FC;
    extern int ehsys_41AABF28();
    extern int ehsys_memset();
    s32 temp_v0;
    u16 v0;

    ehsys_memset(&D_0002D914, 0, 0x14);
    D_0002D916 = *(u16 *)((char *)arg0 + 0x14);
    D_0002D920 = arg1;
    v0 = *(volatile u16 *)&D_0002D916;
    if (v0 > 0) {
        D_0002D91C = ehsys_41AABF28(D_0002E0FC, v0 * 2);
    }
    temp_v0 = ehsys_41AABF28(D_0002E0FC, 0x10000);
    D_0002D924 = temp_v0;
    ehsys_memset((void *)temp_v0, 0xFF, 0x10000);
}

/* func_0000D670 — 24 words. MATCH 100% (shape: m2c). */
s32 func_0000D670(s32 arg0, s32 arg1) {
    s32 temp_a0;
    s32 var_v0;

    temp_a0 = arg0 & 0xFFFF;
    if ((u32) (temp_a0 - 0x1386) < 3U) {
        var_v0 = 1;
    } else {
        var_v0 = func_0001907C(ehsys_CC7A2A21(temp_a0) & 0xFFFF);
    }
    if (arg1 & (1 << var_v0)) {
        return 1;
    }
    return 0;
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
/* func_0000DDFC — 0 words. MATCH 100% (shape: twin of func_00007EEC). */
void func_0000DDFC(u16 *a0, s32 a1, u8 *a2) {

    s32 t0;
    for (t0 = 0; t0 < a1 - 1; t0++) {
        a2[a0[t0]] = 0xFF;
    }
}

/* func_0000EB20 — 13 words. MATCH 100% (shape: m2c). */
s32 func_0000EB20(void) {
    ehsys_B4471B5E(func_0000EE34, func_0000EF68, &D_F768A0);
    return 0;
}

/* func_0000F0D0 — 14 words. MATCH 100% (shape: m2c). */
void func_0000F0D0(void) {
    extern int D_0002E0FC;
    extern int D_0002E114;
    extern int ehsys_20E340D9();
    extern int ehsys_D5D33185();

    func_00015D20();
    ehsys_20E340D9(D_0002E0FC, D_0002E114);
    ehsys_D5D33185(0x2B7E);
}

/* func_0001187C — 5 words. MATCH 100% (shape: thunk, tail call w/ shifted args). */
s32 func_0001187C(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    return ehsys_BC8E65D7(arg0 << 6, arg1 << 6, arg2 << 6, arg3, -1);
}

/* func_00011F6C — 31 words. MATCH 100% (shape: manual, via find_twins.py
 * same-shape tier). */
void func_00011F6C(void) {
    extern int ehsys_memset();
    extern int func_00015E5C();
    extern s32 D_0002E100;
    extern int ehsys_1CC5878C();
    extern int func_000120DC();
    char buf[0x24];

    ehsys_memset(buf, 0, 0x24);
    *(s32 *)(buf + 0x0) = func_00015E5C(0x8007);
    *(s32 *)(buf + 0x4) = func_00015E5C(0x8009);
    *(s32 *)(buf + 0x8) = func_00015E5C(0x8024);
    *(s32 *)(buf + 0xC) = func_00015E5C(0x8011);
    *(s32 *)(buf + 0x10) = func_00015E5C(0x8010);
    *(s32 *)(buf + 0x1C) = D_0002E100;
    ehsys_1CC5878C(buf);
    func_000120DC();
}

/* func_00012A08 — 24 words. MATCH 100% (shape: manual, via find_twins.py
 * same-shape tier). */
s32 func_00012A08(void *arg0) {
    extern unsigned short D_0002DF50;
    extern int D_0002D930;
    extern int ehsys_memcpy();

    if (D_0002DF50 == 0) {
        return 0;
    }
    D_0002DF50 = D_0002DF50 - 1;
    ehsys_memcpy(arg0, (char *)&D_0002D930 + D_0002DF50 * 0xA + 0x622, 0xA);
    return 1;
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
    extern char D_0002DA7C;
    return (u8) D_0002DA7C & 3;
}

/* func_00013070 — 5 words. MATCH 100% (shape: m2c). */
u32 func_00013070(void) {
    extern char D_0002DA7C;
    return (u32) ((u8) D_0002DA7C << 0x1C) >> 0x1E;
}

/* func_00013084 — 5 words. MATCH 100% (shape: m2c; local extern re-declares
 * D_0002DA7C at u16 width so this site loads lhu instead of lb). */
u32 func_00013084(void) {
    extern u16 D_0002DA7C;
    return (u32) (D_0002DA7C << 20) >> 24;
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

/* func_00016ACC — 12 words. MATCH 100% (shape: thunk; forwards $a0/$a2). */
void func_00016ACC(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    extern char D_0002A914;
    extern int func_0001FEBC();

    func_0001FEBC(arg0, (char *)&D_0002A914 + ((arg1 & 0xFFFF) + 1) * 6, arg2, arg3 + 1, 0x88, 0);
}

/* func_00016AFC — 14 words. MATCH 100% (shape: manual). */
s32 func_00016AFC(s32 arg0, u16 arg1, s32 arg2, s32 arg3) {
    extern char D_0002A958;
    extern int func_0001FEBC();
    char *p = *(char **)((*(int *)0xF768B4) + 0x14);
    u16 val = *(u16 *)(p + 0xF4);
    return func_0001FEBC(arg0, &D_0002A958 + arg1 * 6, arg2, arg3 + 1, val, 0);
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

/* func_000186E8 — 45 words. MATCH 100% (shape: twin-of-rel_deckswap-
 * func_0000EE6C, via find_twins.py same-shape tier). */
void func_000186E8(s32 arg0, int arg1, s32 arg2, int arg3) {
    extern unsigned short D_0002DA7A;
    s32 var_s4;
    s32 temp_s4;

    if (D_0002DA7A == 0) {
        var_s4 = 0x99;
    } else {
        var_s4 = 0x98;
    }
    temp_s4 = ehsys_E58C0FDC(func_00015E5C(0x8033), var_s4);
    ehsys_B8AD96EA(arg0);
    ehsys_942B03D0(0xC, 0xC);
    ehsys_60B55A50(0xFF000000);
    func_000186D4(arg1, arg2 - 2, arg3, temp_s4);
    ehsys_A4AFF8E6();
}

/* func_00018C24 — 8 words. MATCH 100% (shape: thunk, tail call w/ shifted args). */
int func_00018C24(s32 arg0, s32 arg1, int arg2) {
    extern int ehsys_B89D38DC();

    return ehsys_B89D38DC(arg0 << 6, arg1 << 6, (0x1E0 - arg0) << 6, arg2);
}

/* func_00018C44 — 4 words. MATCH 100% (shape: thunk, tail call w/ shifted args). */
s32 func_00018C44(s32 arg0, s32 arg1, s32 arg2) {
    return ehsys_B89D38DC(arg0 << 6, arg1 << 6, arg2 << 6);
}

/* func_00019374 — 8 words. MATCH 100% (shape: thunk, tail call w/ shifted args). */
int func_00019374(s32 arg0, s32 arg1, int arg2) {
    extern int ehsys_B89D38DC();

    return ehsys_B89D38DC(arg0 << 6, arg1 << 6, (0x1E0 - arg0) << 6, arg2);
}

/* func_0001AE20 — 5 words. MATCH 100% (shape: thunk, tail call w/ shifted args). */
s32 func_0001AE20(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    return ehsys_BC8E65D7(arg0 << 6, arg1 << 6, arg2 << 6, arg3, -1);
}

/* func_0001B428 — 8 words. MATCH 100% (shape: twin-of-rel_deckswap-
 * func_00016FAC, via find_twins.py same-shape tier). */
s32 func_0001B428(void) {
    extern int ehsys_B2B9FEFA();
    return ((s32 *)ehsys_B2B9FEFA())[1];
}

/* func_0001C118 — bulk-matched thunk into ehsys_3BB2BAC6. */
s32 func_0001C118(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return ehsys_3BB2BAC6(arg0 << 6, arg1 << 6, arg2 << 6, arg3 << 6, arg4, -1, 0);
}

/* func_0001C134 — 2 words. MATCH 100% (shape: thunk, tail call w/ shifted arg). */
s32 func_0001C134(s32 arg0) {
    return ehsys_5F00A362(arg0 << 6);
}

/* func_0001C630 — 19 words. MATCH 100% (shape: m2c; goto-based loop, test-at-bottom). */
void func_0001C630(u16 *arg0, u16 *arg1, s32 arg2) {
    s32 t1;
    u16 t0;

    t1 = 0;
    goto test;
loop:
    t0 = *arg0;
    if (t0 == 0) {
        *arg1 = 0;
        return;
    }
    if (t0 == 0xA) {
        *arg1 = 0x20;
    } else {
        *arg1 = t0;
    }
    t1 += 1;
    arg0 += 1;
    arg1 += 1;
test:
    if (t1 < arg2) {
        goto loop;
    }
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
/* func_0001D96C — 0 words. MATCH 100% (shape: twin of func_00010290). */
void func_0001D96C(void *arg0, s16 arg1, s16 arg2, s16 arg3) {

    unsigned short temp_a3;
    unsigned short temp_a2;
    char *p = (char *)arg0;

    *(s16 *)(p + 0x4) = arg1;
    *(s16 *)(p + 0x6) = arg2;
    *(s16 *)(p + 0x8) = 0;
    *(s32 *)(p + 0x0) = 0x33000000;
    temp_a3 = (unsigned short)arg1 + (unsigned short)arg3;
    *(s16 *)(p + 0x10) = temp_a3;
    *(s16 *)(p + 0x12) = arg2;
    *(s16 *)(p + 0x14) = 0;
    *(s32 *)(p + 0xC) = 0x33000000;
    temp_a2 = (unsigned short)arg2 + 1;
    *(s16 *)(p + 0x1C) = arg1;
    *(s16 *)(p + 0x1E) = temp_a2;
    *(s16 *)(p + 0x20) = 0;
    *(s32 *)(p + 0x18) = 0x19000000;
    *(s16 *)(p + 0x28) = temp_a3;
    *(s16 *)(p + 0x2A) = temp_a2;
    *(s16 *)(p + 0x2C) = 0;
    *(s32 *)(p + 0x24) = 0x19000000;
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

/* func_00020C90 — bulk-matched thunk into ehsys_3BB2BAC6. */
s32 func_00020C90(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return ehsys_3BB2BAC6(arg0 << 6, arg1 << 6, arg2 << 6, arg3 << 6, arg4, -1, 0);
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

/* func_0002151C — 5 words. MATCH 100% (shape: thunk, tail call w/ fixed args
 * in the $t0-$t3 8-register slots; arg0-arg2 and arg7 forwarded untouched). */
s32 func_0002151C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    return func_000206E0(arg0, arg1, arg2, 0, 0, 7, 6, arg7);
}

/* func_00021530 — 5 words. MATCH 100% (shape: thunk, same target as
 * func_0002151C with a different arg4). */
s32 func_00021530(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    return func_000206E0(arg0, arg1, arg2, 0, 6, 7, 6, arg7);
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

/* func_000229F0 — 2 words. MATCH 100% (shape: m2c). */
void func_000229F0(void *arg0) {
    *(s32 *)((char *)arg0 + 8) = 0;
}

/* func_00022B68 — 2 words. MATCH 100% (shape: m2c). */
void func_00022B68(void) {

}

/* func_00022B8C — 2 words. MATCH 100% (shape: K&R definition — old-style
 * unprototyped signature so func_00023A64 can also call it with 0 args). */
u16 func_00022B8C(arg0)
void *arg0;
{
    return *(u16 *)((char *)arg0 + 2);
}

/* func_00022B94 — 2 words. MATCH 100% (shape: K&R definition — old-style
 * unprototyped signature so func_00023A6C can also call it with 0 args). */
void func_00022B94(arg0, arg1)
void *arg0;
u16 arg1;
{
    *(u16 *)((char *)arg0 + 2) = arg1;
}
/* func_0002308C — 16 words. MATCH 100% (shape: m2c). */
void func_0002308C(void) {
    extern char D_F76D64;
    extern char D_F76D7C;
    extern char D_F76DB0;
    extern int ehsys_5DF04F49();
    extern int ehsys_memset();
    extern int func_0002308C();
    extern int func_00023A54();
    func_00023A54(&D_F76D7C);
    ehsys_5DF04F49(&D_F76DB0);
    ehsys_memset(&D_F76D64, 0, 0x124);
}

/* func_000230F0 — 4 words. MATCH 100% (shape: m2c). */
void func_000230F0(void) {
    *(s32 *)0xF76D64 = 1;
}

/* func_00023078 — 5 words. MATCH 100% (shape: thunk, tail call w/ shifted args). */
s32 func_00023078(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    return ehsys_BC8E65D7(arg0 << 6, arg1 << 6, arg2 << 6, arg3, -1);
}

/* func_00023100 — 3 words. MATCH 100% (shape: thunk; sets $a0 = &D_F76D7C then
 * tail-calls func_00023A64, whose own K&R signature is unprototyped). */
void func_00023100(void) {
    func_00023A64(&D_F76D7C);
}

/* func_000232D8 — bulk-matched thunk into ehsys_3BB2BAC6. */
s32 func_000232D8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return ehsys_3BB2BAC6(arg0 << 6, arg1 << 6, arg2 << 6, arg3 << 6, arg4, -1, 0);
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

/* func_0002368C — 11 words. MATCH 100% (shape: manual). */
void func_0002368C(void *arg0) {
    extern int func_000229F0();
    func_000229F0();
    *(s16 *)((char *)arg0 + 0x30) = 0;
    *(s16 *)((char *)arg0 + 0x32) = 0;
}

/* func_00023A54 — 2 words. MATCH 100% (shape: m2c). */
void func_00023A54(void) {
    func_00022B68();
}

/* func_00023A5C — 2 words. MATCH 100% (shape: m2c; unprototyped so
 * func_00023CD4 can tail-call it with 2 args). */
void func_00023A5C() {
    func_00022B70();
}

/* func_00023A64 — 2 words. MATCH 100% (shape: m2c; unprototyped so
 * func_00023100/func_00023CE4 can tail-call it with 1 arg). */
void func_00023A64() {
    func_00022B8C();
}

/* func_00023A6C — 2 words. MATCH 100% (shape: m2c; unprototyped so
 * func_00023CF0 can tail-call it with 2 args). */
void func_00023A6C() {
    func_00022B94();
}

/* func_00023C7C — 3 words. MATCH 100% (shape: m2c). */
void func_00023C7C(void) {
    func_000236B8(&D_F76EA0);
}

/* func_00023C88 — 3 words. MATCH 100% (shape: thunk; unused leading arg0
 * forwarded into $a0 so the target only has to set $a1 = &D_F76EA0). */
void func_00023C88(int arg0) {
    func_000237FC(arg0, &D_F76EA0);
}
/* func_00023C94 — 16 words. MATCH 100% (shape: m2c). */
void func_00023C94(void) {
    extern char D_F76E88;
    extern char D_F76EA0;
    extern char D_F76ED4;
    extern int ehsys_5DF04F49();
    extern int ehsys_memset();
    extern int func_00023A54();
    extern int func_00023C94();
    func_00023A54(&D_F76EA0);
    ehsys_5DF04F49(&D_F76ED4);
    ehsys_memset(&D_F76E88, 0, 0x11C);
}

/* func_00023CD4 — 4 words. MATCH 100% (shape: thunk; forwards arg0 into
 * $a1 and tail-calls the unprototyped func_00023A5C with &D_F76EA0 in $a0). */
void func_00023CD4(void *arg0) {
    func_00023A5C(&D_F76EA0, arg0);
}

/* func_00023CE4 — 3 words. MATCH 100% (shape: thunk; sets $a0 = &D_F76EA0
 * then tail-calls the unprototyped func_00023A64). */
void func_00023CE4(void) {
    func_00023A64(&D_F76EA0);
}

/* func_00023CF0 — 4 words. MATCH 100% (shape: thunk; forwards arg0 into
 * $a1 and tail-calls the unprototyped func_00023A6C with &D_F76EA0 in $a0). */
void func_00023CF0(void *arg0) {
    func_00023A6C(&D_F76EA0, arg0);
}

/* func_00023EAC — bulk-matched thunk into ehsys_3BB2BAC6. */
s32 func_00023EAC(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return ehsys_3BB2BAC6(arg0 << 6, arg1 << 6, arg2 << 6, arg3 << 6, arg4, -1, 0);
}

/* func_00023EC8 — 8 words. MATCH 100% (shape: thunk, tail call w/ shifted args). */
int func_00023EC8(s32 arg0, s32 arg1, int arg2) {
    extern int ehsys_B89D38DC();

    return ehsys_B89D38DC(arg0 << 6, arg1 << 6, (0x1E0 - arg0) << 6, arg2);
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

