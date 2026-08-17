/*
 * rel_duel_eng.prx — reconstructed code (matching decompilation)
 *
 * Compiler:     Metrowerks CodeWarrior for PSP — MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,s -sdatathreshold 0
 * Verification: scripts/mwcc_build.sh src/rel_duel_eng.c
 *               scripts/mwcc_diff.py asm/rel_duel_eng/text.s build/mwcc/rel_duel_eng.o
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
 * STATUS: 44 functions matched. build/auto/rel_duel_eng.json has the
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


/* func_00002600 — 2 words. MATCH 100% (shape: m2c). */
void func_00002600(void) {
    extern int ehsys_639AE71F();
    extern int func_00002600();
    ehsys_639AE71F();
}

/* func_000046E8 — 2 words. MATCH 100% (shape: m2c). */
s32 func_000046E8(void) {
    extern int func_000046E8();
    return 0;
}

/* func_000047A4 — 2 words. MATCH 100% (shape: m2c). */
void func_000047A4(void) {
    extern int func_00000664();
    extern int func_000047A4();
    func_00000664();
}

/* func_00004A9C — 2 words. MATCH 100% (shape: m2c). */
void func_00004A9C(void) {
    extern int ehsys_1460C6FD();
    extern int func_00004A9C();
    ehsys_1460C6FD();
}

/* func_00004D40 — 2 words. MATCH 100% (shape: m2c). */
void func_00004D40(void) {
    extern int func_00004C74();
    extern int func_00004D40();
    func_00004C74();
}

/* func_0000F9C4 — 2 words. MATCH 100% (shape: m2c). */
void func_0000F9C4(void) {
    extern int func_0000F9C4();

}

/* func_000197DC — 2 words. MATCH 100% (shape: m2c). */
s32 func_000197DC(void) {
    extern int func_000197DC();
    return 1;
}

/* func_0001D97C — 2 words. MATCH 100% (shape: m2c). */
s32 func_0001D97C(void) {
    extern int func_0001D97C();
    return 0;
}

/* func_00031424 — 2 words. MATCH 100% (shape: m2c). */
s32 func_00031424(void) {
    extern int func_00031424();
    return 1;
}

/* func_00035D08 — 8 words. MATCH 100% (shape: m2c). */
s32 func_00035D08(void) {
    extern int func_00035C38();
    extern int func_00035D08();
    func_00035C38();
    return 0;
}

/* func_00035F78 — 14 words. MATCH 100% (shape: m2c). */
void *func_00035F78(s32 arg0) {
    extern char D_0034C6C8;
    extern char D_0034C6F8;
    extern int func_00035F78();
    return &D_0034C6C8 + ((arg0 == (s32) &D_0034C6F8) * 0x4C) + 0x30;
}

/* func_0003E0A0 — 10 words. MATCH 100% (shape: m2c). */
s32 func_0003E0A0(void) {
    extern int func_0003DD30();
    extern int func_0003DE44();
    extern int func_0003E0A0();
    func_0003DD30();
    func_0003DE44();
    return 1;
}

/* func_0003FBD4 — 6 words. MATCH 100% (shape: m2c). */
void *func_0003FBD4(s32 arg0) {
    extern char D_0034DF44;
    extern int func_0003FBD4();
    return &D_0034DF44 + (arg0 * 4) + 0x14;
}

/* func_0004461C — 17 words. MATCH 100% (shape: m2c). */
s32 func_0004461C(s32 arg0) {
    extern int func_0004461C();
    if ((arg0 != 0x1D9A) && (arg0 != 0x1CDA) && (arg0 != 0x1A92) && (arg0 != 0x1578)) {
        return 0;
    }
    return 1;
}

/* func_000602C4 — 19 words. MATCH 100% (shape: m2c). */
void func_000602C4(s32 arg0, s32 arg1) {
    extern int func_000135F0();
    extern int func_000602C4();
    extern int func_0015CCE0();
    s32 temp_a0;

    temp_a0 = arg0 & 1;
    func_000135F0(0x3E, (((arg1 & 0x3FF) << 6) | (temp_a0 | 0x1E)) & 0xFFFF, (temp_a0 | 0x5C) & 0xFFFF, 0);
    func_0015CCE0(0x26, 0);
}

/* func_0007F9B0 — 38 words. MATCH 100% (shape: m2c). */
s32 func_0007F9B0(s32 arg0) {
    extern int func_0007F9B0();
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_a0_4;

    temp_a0_2 = ((u32) (arg0 & 0xAAAAAAAA) >> 1) + (arg0 & 0x55555555);
    temp_a0_3 = ((u32) (temp_a0_2 & 0xCCCCCCCC) >> 2) + (temp_a0_2 & 0x33333333);
    temp_a0_4 = ((u32) (temp_a0_3 & 0xF0F0F0F0) >> 4) + (temp_a0_3 & 0x0F0F0F0F);
    temp_a0 = ((u32) (temp_a0_4 & 0xFF00FF00) >> 8) + (temp_a0_4 & 0xFF00FF);
    return ((u32) (temp_a0 & 0xFFFF0000) >> 0x10) + (temp_a0 & 0xFFFF);
}

/* func_000804E4 — 3 words. MATCH 100% (shape: m2c). */
void func_000804E4(f32 *arg0, f32 *arg1) {
    extern int func_000804E4();
    *arg0 = *arg1;
}

/* func_000804F0 — 5 words. MATCH 100% (shape: m2c). */
void func_000804F0(f32 *arg0, f32 *arg1) {
    extern int func_000804F0();
    f32 temp_f1;

    temp_f1 = *arg0;
    *arg0 = *arg1;
    *arg1 = temp_f1;
}

/* func_00080504 — 5 words. MATCH 100% (shape: m2c). */
s32 func_00080504(s32 *arg0, s32 *arg1) {
    extern int func_00080504();
    return *arg0 == *arg1;
}

/* func_00089398 — 45 words. MATCH 100% (shape: m2c). */
s32 func_00089398(u16 *arg0) {
    extern int func_00089398();
    u16 temp_v1;

    temp_v1 = *arg0;
    if ((temp_v1 != 0x1926) && (temp_v1 != 0x18D9) && (temp_v1 != 0x1739) && (temp_v1 != 0x12D0) && (temp_v1 != 0x12CF) && (temp_v1 != 0xE05) && (temp_v1 != 0x1EC2) && (temp_v1 != 0x1ADF) && (temp_v1 != 0x1737) && (temp_v1 != 0x1696) && (temp_v1 != 0x15DF) && (temp_v1 != 0x1530) && (temp_v1 != 0x14F6)) {
        return 0;
    }
    return 1;
}

/* func_00089810 — 15 words. MATCH 100% (shape: m2c). */
s32 func_00089810(u16 *arg0) {
    extern int func_00089810();
    u16 temp_v1;

    temp_v1 = *arg0;
    if ((temp_v1 != 0x232A) && (temp_v1 != 0x21EB) && (temp_v1 != 0x213A)) {
        return 3;
    }
    return 1;
}

/* func_0008AC80 — 18 words. MATCH 100% (shape: m2c). */
s32 func_0008AC80(s32 arg0) {
    extern int func_0008AB14();
    extern int func_0008AC80();
    s32 temp_s0;

    temp_s0 = func_0008AB14(0, arg0, -1);
    return temp_s0 + func_0008AB14(1, arg0, -1);
}

/* func_0008F4A4 — 16 words. MATCH 100% (shape: m2c). */
void func_0008F4A4(s32 arg0, int arg1) {
    extern int func_000827C4();
    extern int func_0008F2E4();
    extern int func_0008F4A4();
    func_0008F2E4(arg0, arg1, func_000827C4());
}

/* func_0008F4E4 — 16 words. MATCH 100% (shape: m2c). */
void func_0008F4E4(s32 arg0, int arg1) {
    extern int func_00083084();
    extern int func_0008F2E4();
    extern int func_0008F4E4();
    func_0008F2E4(arg0, arg1, func_00083084());
}

/* func_00095C28 — 20 words. MATCH 100% (shape: m2c). */
s32 func_00095C28(s32 arg0) {
    extern int ehsys_CEA78CA6();
    extern int ehsys_E62CCE79();
    extern int func_0008A0D0();
    extern int func_00095C28();
    if ((ehsys_CEA78CA6() != 0) && (func_0008A0D0(0xEAD) != 0)) {
        return 2;
    }
    return ehsys_E62CCE79(arg0);
}

/* func_000A17A0 — 55 words. MATCH 100% (shape: m2c). */
s32 func_000A17A0(s32 arg0, s32 arg1) {
    extern int ehsys_3C9CB549();
    extern int ehsys_BD86E5F9();
    extern int func_00078AAC();
    extern int func_00078C8C();
    extern int func_00089E9C();
    extern int func_000A17A0();
    if (((arg1 == 0) || (ehsys_3C9CB549(arg1) != 0)) && (func_00089E9C(arg0, 0x20D6, -1) != 0) && (func_00078AAC(arg0, 0xB, 0x20D6) == 0)) {
        return 0x20D6;
    }
    if (((arg1 == 0) || ((ehsys_BD86E5F9(arg1) != 0) && (arg1 != 0x2115))) && (func_00078AAC(arg0, 0xB, 0x2115) != 0) && (func_00078C8C(arg0, 0xB, 0x2115, 2) == 0)) {
        return 0x2115;
    }
    return 0;
}

/* func_000A2944 — 2 words. MATCH 100% (shape: m2c). */
s32 func_000A2944(void) {
    extern int func_000A2944();
    return 1;
}

/* func_000A294C — 104 words. MATCH 100% (shape: m2c). */
s32 func_000A294C(s32 arg0, s32 arg1) {
    extern int func_0008A0D0();
    extern int func_0008B27C();
    extern int func_000A294C();
    if ((arg1 != 2) && (func_0008A0D0(0x1AE2) != 0)) {
        return 0;
    }
    if ((arg1 != 3) && (func_0008A0D0(0x1AE3) != 0)) {
        return 0;
    }
    if ((arg1 != 4) && (func_0008A0D0(0x1AE4) != 0)) {
        return 0;
    }
    if ((arg1 != 6) && (func_0008A0D0(0x1AE5) != 0)) {
        return 0;
    }
    if ((arg1 != 5) && (func_0008A0D0(0x1AE6) != 0)) {
        return 0;
    }
    if ((arg1 != 1) && (func_0008A0D0(0x1AE7) != 0)) {
        return 0;
    }
    if (((u32) (arg1 - 1) < 2U) && (func_0008A0D0(0x1FF0) != 0)) {
        return 0;
    }
    if ((arg1 == 1) && (func_0008A0D0(0x20D8) != 0)) {
        return 0;
    }
    if ((arg1 == 2) && (func_0008A0D0(0x21C4) != 0)) {
        return 0;
    }
    if ((arg1 != 0) && (func_0008B27C(1 - arg0, 0x197D, arg1) != 0)) {
        return 0;
    }
    return 1;
}

/* func_000A42C4 — 45 words. MATCH 100% (shape: m2c). */
s32 func_000A42C4(s32 arg0) {
    extern int func_00078EC0();
    extern int func_0008A830();
    extern int func_0008A8B0();
    extern int func_000A42C4();
    s32 temp_s0;
    s32 temp_s1;
    s32 temp_v0;
    s32 var_s2;

    var_s2 = 6;
    temp_s1 = func_0008A8B0(0x1401);
    temp_s0 = func_0008A830(1 - arg0, 0x1800);
    temp_v0 = func_00078EC0(arg0, 0xB, 0x159F);
    if ((temp_s1 != 0) && (temp_s0 < temp_s1)) {
        var_s2 = 0xFFFF;
    } else {
        if ((temp_s0 > 0) && (temp_v0 < temp_s0)) {
            var_s2 = 5;
        }
        if ((temp_v0 > 0) && (temp_s0 < temp_v0)) {
            var_s2 = 7;
        }
    }
    return var_s2;
}

/* func_000A5C50 — 24 words. MATCH 100% (shape: m2c). */
void func_000A5C50(s32 arg0, int arg1, int arg2) {
    extern int func_000A59E0();
    extern int func_000A5C50();
    func_000A59E0(0, arg0, arg1, arg2);
    func_000A59E0(1, arg0, arg1, arg2);
}

/* func_000A5DCC — 24 words. MATCH 100% (shape: m2c). */
void func_000A5DCC(s32 arg0, int arg1, int arg2) {
    extern int func_000A5CB0();
    extern int func_000A5DCC();
    func_000A5CB0(0, arg0, arg1, arg2);
    func_000A5CB0(1, arg0, arg1, arg2);
}

/* func_000C2C68 — 14 words. MATCH 100% (shape: m2c). */
s32 func_000C2C68(void) {
    extern int func_000C2A88();
    extern int func_000C2C68();
    if (func_000C2A88 == func_000C2C68) {
        return 1;
    }
    return func_000C2A88();
}

/* func_000CD188 — 17 words. MATCH 100% (shape: m2c). */
s32 func_000CD188(s32 arg0) {
    extern int func_0006F5B0();
    extern int func_000A4934();
    extern int func_000CD188();
    extern int func_0017B640();
    if (func_000A4934() == 0) {
        func_0006F5B0(arg0, func_0017B640(arg0));
    }
    return 1;
}

/* func_000DC190 — 23 words. MATCH 100% (shape: m2c). */
s32 func_000DC190(u16 *arg0, int arg1) {
    extern int func_0008A0D0();
    extern int func_000D6EAC();
    extern int func_000DC190();
    if ((*arg0 == 0x12EA) && (func_0008A0D0(0x12FB) > 0)) {
        return 0;
    }
    return func_000D6EAC(arg0, arg1);
}

/* func_000DE6B4 — 18 words. MATCH 100% (shape: m2c). */
s32 func_000DE6B4(void) {
    extern int func_0008C4A4();
    extern int func_000DE6B4();
    s32 temp_s0;

    temp_s0 = func_0008C4A4(0, 1, 0);
    return (temp_s0 + func_0008C4A4(1, 1, 0)) != 0;
}

/* func_000E2258 — 8 words. MATCH 100% (shape: m2c). */
s32 func_000E2258(void) {
    extern int func_0008F280();
    extern int func_000E2258();
    return func_0008F280(0x159D) != 0;
}

/* func_000ECFE4 — 15 words. MATCH 100% (shape: m2c). */
s32 func_000ECFE4(void) {
    extern int func_000A41B4();
    extern int func_000ECFE4();
    s32 var_v0;

    var_v0 = func_000A41B4(0, 1) != 0;
    if (var_v0 != 0) {
        var_v0 = func_000A41B4(1, 1) != 0;
    }
    return var_v0;
}

/* func_000ED2FC — 8 words. MATCH 100% (shape: m2c). */
s32 func_000ED2FC(void) {
    extern int func_0008A0D0();
    extern int func_000ED2FC();
    return func_0008A0D0(0x175E) != 0;
}

/* func_000F5398 — 8 words. MATCH 100% (shape: m2c). */
s32 func_000F5398(void) {
    extern int func_000A49E8();
    extern int func_000F5398();
    return func_000A49E8() != 0;
}

/* func_000FC658 — 13 words. MATCH 100% (shape: m2c). */
s32 func_000FC658(s32 arg0) {
    extern int func_0006D308();
    extern int func_000FC658();
    extern int func_0017B760();
    func_0006D308(arg0, func_0017B760());
    return 0;
}

/* func_000FC800 — 13 words. MATCH 100% (shape: m2c). */
s32 func_000FC800(s32 arg0) {
    extern int func_0006E5F4();
    extern int func_000FC800();
    extern int func_0017B760();
    func_0006E5F4(arg0, func_0017B760());
    return 0;
}

/* func_000FC8C4 — 13 words. MATCH 100% (shape: m2c). */
s32 func_000FC8C4(s32 arg0) {
    extern int func_0006E8A0();
    extern int func_000FC8C4();
    extern int func_0017B760();
    func_0006E8A0(arg0, func_0017B760());
    return 0;
}

/* func_00108EE4 — 2 words. MATCH 100% (shape: m2c). */
s32 func_00108EE4(void) {
    extern int func_00108EE4();
    return 0;
}

/* func_001172D8 — 8 words. MATCH 100% (shape: m2c). */
s32 func_001172D8(void) {
    extern int func_000744E4();
    extern int func_001172D8();
    func_000744E4();
    return 0;
}

/* func_00118150 — 14 words. MATCH 100% (shape: hand). */
extern int func_0017B760();
extern int func_0006E20C();

int func_00118150(int a0) {
    extern int func_0006E20C();
    extern int func_00118150();
    extern int func_0017B760();
    int v0 = func_0017B760(a0);
    func_0006E20C(a0, v0, 2);
    return 0;
}

/* func_00121D58 — 14 words. MATCH 100% (shape: hand). */
extern int func_0017B760();
extern int func_0006E20C();

int func_00121D58(int a0) {
    extern int func_0006E20C();
    extern int func_00121D58();
    extern int func_0017B760();
    int v0 = func_0017B760(a0);
    func_0006E20C(a0, v0, 0);
    return 0;
}

/* func_0012FCAC — 13 words. MATCH 100% (shape: hand). */
extern int func_0017B760();
extern int func_0006F4D8();
/* func_00126EAC — 13 words. MATCH 100% (shape: hand). */
void func_00126EAC(short *a0, unsigned short *a1) {
    extern int func_00126EAC();
    extern int func_0017C328();
    extern int func_0017C328();
    *a0 = *a1;
    func_0017C328(a0, a1);
    *a0 = 0x183E;
}


int func_0012FCAC(int a0) {
    extern int func_0006F4D8();
    extern int func_0012FCAC();
    extern int func_0017B760();
    int v0 = func_0017B760(a0);
    func_0006F4D8(a0, v0);
    return 0;
}

/* func_00138790 — 18 words. MATCH 100% (shape: hand). */
extern int func_0017B444();
extern int func_001029B4();

int func_00138790(int a0, int a1) {
    extern int func_001029B4();
    extern int func_00138790();
    extern int func_0017B444();
    int v0 = func_0017B444(a0, a1);
    if (v0 != 0) {
        func_001029B4(a0, a1);
    }
    return 0;
}

/* func_001422E8 — 16 words. MATCH 100% (shape: hand). */
extern int func_0011228C();
extern int func_00115704();

int func_001422E8(int a0, int a1) {
    extern int func_0011228C();
    extern int func_00115704();
    extern int func_001422E8();
    func_0011228C(a0, a1);
    func_00115704(a0, a1);
    return 0;
}

/* func_00152608 — 2 words. MATCH 100% (shape: hand). */
int func_00152608(void *a0, int a1) {
    extern int func_00152464();
    extern int func_00152608();
    extern int func_00152464();
    return func_00152464(a0, a1, 0);
}

/* func_00152610 — 2 words. MATCH 100% (shape: hand). */
int func_00152610(void *a0, int a1) {
    extern int func_00152464();
    extern int func_00152610();
    extern int func_00152464();
    return func_00152464(a0, a1, 0x6F);
}

/* func_00152618 — 2 words. MATCH 100% (shape: hand). */
int func_00152618(void *a0, int a1) {
    extern int func_00152464();
    extern int func_00152618();
    extern int func_00152464();
    return func_00152464(a0, a1, 0x7C);
}

/* func_00152620 — 2 words. MATCH 100% (shape: hand). */
int func_00152620(void *a0, int a1) {
    extern int func_00152464();
    extern int func_00152620();
    extern int func_00152464();
    return func_00152464(a0, a1, 0x64);
}

/* func_00152628 — 2 words. MATCH 100% (shape: hand). */
int func_00152628(void *a0, int a1) {
    extern int func_00152464();
    extern int func_00152628();
    extern int func_00152464();
    return func_00152464(a0, a1, 0x119);
}

/* func_00152630 — 2 words. MATCH 100% (shape: hand). */
int func_00152630(void *a0, int a1) {
    extern int func_00152464();
    extern int func_00152630();
    extern int func_00152464();
    return func_00152464(a0, a1, 0x77);
}

/* func_00152638 — 2 words. MATCH 100% (shape: hand). */
int func_00152638(void *a0, int a1) {
    extern int func_00152464();
    extern int func_00152638();
    extern int func_00152464();
    return func_00152464(a0, a1, 0x85);
}

/* func_00152640 — 2 words. MATCH 100% (shape: hand). */
int func_00152640(void *a0, int a1) {
    extern int func_00152464();
    extern int func_00152640();
    extern int func_00152464();
    return func_00152464(a0, a1, 0x15C);
}

/* func_00152648 — 2 words. MATCH 100% (shape: hand). */
int func_00152648(void *a0, int a1) {
    extern int func_00152464();
    extern int func_00152648();
    extern int func_00152464();
    return func_00152464(a0, a1, 0x4E);
}

/* func_00152650 — 2 words. MATCH 100% (shape: hand). */
int func_00152650(void *a0, int a1) {
    extern int func_00152464();
    extern int func_00152650();
    extern int func_00152464();
    return func_00152464(a0, a1, 0x4F);
}

/* func_00152658 — 2 words. MATCH 100% (shape: hand). */
int func_00152658(void *a0, int a1) {
    extern int func_00152464();
    extern int func_00152658();
    extern int func_00152464();
    return func_00152464(a0, a1, 0x156);
}

/* func_00152660 — 2 words. MATCH 100% (shape: hand). */
int func_00152660(void *a0, int a1) {
    extern int func_00152464();
    extern int func_00152660();
    extern int func_00152464();
    return func_00152464(a0, a1, 0x165);
}

/* func_00152668 — 2 words. MATCH 100% (shape: hand). */
int func_00152668(void *a0, int a1) {
    extern int func_00152464();
    extern int func_00152668();
    extern int func_00152464();
    return func_00152464(a0, a1, 0x125);
}

/* func_00152670 — 2 words. MATCH 100% (shape: hand). */
int func_00152670(void *a0, int a1) {
    extern int func_00152464();
    extern int func_00152670();
    extern int func_00152464();
    return func_00152464(a0, a1, 0x3A);
}

/* func_00152678 — 2 words. MATCH 100% (shape: hand). */
int func_00152678(void *a0, int a1) {
    extern int func_00152464();
    extern int func_00152678();
    extern int func_00152464();
    return func_00152464(a0, a1, 0x11A);
}

/* func_00167700 — 3 words. MATCH 100% (shape: hand). */
int func_00167700(void *unused, void *p) {
    extern int func_00167700();
    extern int func_00170D08();
    extern int func_00170D08();
    return func_00170D08(p, 0xB);
}
/* func_0016F9A0 — 3 words. MATCH 100% (shape: hand). */
int func_0016F9A0(int a0, int a1, int a2, int a3, void *t0) {
    extern int ehsys_1738DF69();
    extern int func_0016F9A0();
    extern int ehsys_1738DF69();
    unsigned short v0 = *(unsigned short *)t0;
    return ehsys_1738DF69(v0 & 0x3FFF);
}
/* func_00170778 — 3 words. MATCH 100% (shape: hand). */
int func_00170778(void *unused, void *p, int a2) {
    extern int func_0001E84C();
    extern int func_00170778();
    extern int func_0001E84C();
    return func_0001E84C(p, 0, a2);
}



/* func_00176738 — 3 words. MATCH 100% (shape: hand). */
int func_00176738(void *a0) {
    extern int func_001765EC();
    extern int func_00176738();
    extern int func_001765EC();
    return func_001765EC(a0, 0x1, 0x2);
}

/* func_00176744 — 3 words. MATCH 100% (shape: hand). */
int func_00176744(void *a0) {
    extern int func_001765EC();
    extern int func_00176744();
    extern int func_001765EC();
    return func_001765EC(a0, 0x1B, 0x1);
}

/* func_00176750 — 3 words. MATCH 100% (shape: hand). */
int func_00176750(void *a0) {
    extern int func_001765EC();
    extern int func_00176750();
    extern int func_001765EC();
    return func_001765EC(a0, 0x6, 0x1);
}

/* func_0017675C — 3 words. MATCH 100% (shape: hand). */
int func_0017675C(void *a0) {
    extern int func_001765EC();
    extern int func_0017675C();
    extern int func_001765EC();
    return func_001765EC(a0, 0x6, 0x2);
}

/* func_00176768 — 3 words. MATCH 100% (shape: hand). */
int func_00176768(void *a0) {
    extern int func_001765EC();
    extern int func_00176768();
    extern int func_001765EC();
    return func_001765EC(a0, 0x8, 0x1);
}

/* func_00176774 — 3 words. MATCH 100% (shape: hand). */
int func_00176774(void *a0) {
    extern int func_001765EC();
    extern int func_00176774();
    extern int func_001765EC();
    return func_001765EC(a0, 0xA, 0x1);
}

/* func_00176780 — 3 words. MATCH 100% (shape: hand). */
int func_00176780(void *a0) {
    extern int func_001765EC();
    extern int func_00176780();
    extern int func_001765EC();
    return func_001765EC(a0, 0xC, 0x1);
}

/* func_0017678C — 3 words. MATCH 100% (shape: hand). */
int func_0017678C(void *a0) {
    extern int func_001765EC();
    extern int func_0017678C();
    extern int func_001765EC();
    return func_001765EC(a0, 0xB, 0x1);
}

/* func_00176798 — 3 words. MATCH 100% (shape: hand). */
int func_00176798(void *a0) {
    extern int func_001765EC();
    extern int func_00176798();
    extern int func_001765EC();
    return func_001765EC(a0, 0xD, 0x1);
}

/* func_001767A4 — 3 words. MATCH 100% (shape: hand). */
int func_001767A4(void *a0) {
    extern int func_001765EC();
    extern int func_001767A4();
    extern int func_001765EC();
    return func_001765EC(a0, 0x0, 0x1);
}

/* func_001767B0 — 3 words. MATCH 100% (shape: hand). */
int func_001767B0(void *a0) {
    extern int func_001765EC();
    extern int func_001767B0();
    extern int func_001765EC();
    return func_001765EC(a0, 0x11, 0x2);
}

/* func_001767BC — 3 words. MATCH 100% (shape: hand). */
int func_001767BC(void *a0) {
    extern int func_001765EC();
    extern int func_001767BC();
    extern int func_001765EC();
    return func_001765EC(a0, 0x17, 0x1);
}

/* func_001F2D40 — 2 words. MATCH 100% (shape: hand). */
int func_001F2D40(int a0, int a1) {
    extern int func_00078AAC();
    extern int func_001F2D40();
    extern int func_00078AAC();
    return func_00078AAC(a0, a1, 0xFF);
}

/* func_001F2D48 — 3 words. MATCH 100% (shape: hand). */
int func_001F2D48(void *a0) {
    extern int func_00078AAC();
    extern int func_001F2D48();
    extern int func_00078AAC();
    return func_00078AAC(a0, 0xB, 0xFF);
}

/* func_001FC194 — 3 words. MATCH 100% (shape: hand). */
int func_001FC194(void *a0) {
    extern int func_001FBF70();
    extern int func_001FC194();
    extern int func_001FBF70();
    return func_001FBF70(a0, 0, 0);
}

/* func_00204854 — 11 words. MATCH 100% (shape: hand). */
int func_00204854(void *a0, int a1) {
    extern int func_00204664();
    extern int func_00204854();
    extern int func_00204664();
    unsigned short a2 = *(unsigned short *)a0;
    return !(func_00204664(a0, a1, a2, 0, 1) < 1);
}

