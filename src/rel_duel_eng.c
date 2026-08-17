/*
 * rel_duel_eng.prx — reconstructed code (matching decompilation)
 *
 * Compiler:     Metrowerks CodeWarrior for PSP — MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,s -sdatathreshold 0
 * Verification: scripts/mwcc_build.sh src/rel_duel_eng.c
 *               scripts/mwcc_diff.py asm/rel_duel_eng/text.s build/mwcc/rel_duel_eng.o
 *
 * Every function below is byte-identical to the shipped module — each was
 * accepted only on a MATCH verdict from scripts/mwcc_diff.py, and the whole
 * file is re-verified after assembly (scripts/assemble_module.py).
 * Functions are in ADDRESS ORDER, which is what the linker needs.
 *
 * Import names are resolved from the module's NID tables and are identical
 * across all 28 modules — see docs/nids/README.md.
 *
 * STATUS: 45 functions matched here. The rest of the module is not
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
extern char D_0034C6C8;
extern char D_0034C6F8;
extern char D_0034DF44;
extern int ehsys_1460C6FD();
extern int ehsys_3C9CB549();
extern int ehsys_639AE71F();
extern int ehsys_BD86E5F9();
extern int ehsys_CEA78CA6();
extern int ehsys_E62CCE79();
extern int func_00000664();
extern int func_00004C74();
extern int func_000135F0();
extern int func_00035C38();
extern int func_0003DD30();
extern int func_0003DE44();
extern int func_0006D308();
extern int func_0006E5F4();
extern int func_0006E8A0();
extern int func_0006F5B0();
extern int func_000744E4();
extern int func_00078AAC();
extern int func_00078C8C();
extern int func_00078EC0();
extern int func_000827C4();
extern int func_00083084();
extern int func_00089E9C();
extern int func_0008A0D0();
extern int func_0008A830();
extern int func_0008A8B0();
extern int func_0008AB14();
extern int func_0008B27C();
extern int func_0008C4A4();
extern int func_0008F280();
extern int func_0008F2E4();
extern int func_000A41B4();
extern int func_000A4934();
extern int func_000A49E8();
extern int func_000A59E0();
extern int func_000A5CB0();
extern int func_000C2A88();
extern int func_000D6EAC();
extern int func_0015CCE0();
extern int func_0017B640();
extern int func_0017B760();
extern void * D_00326E80;

/* ---- forward declarations ---- */
s32 func_000046E8();
s32 func_000197DC();
s32 func_0001D97C();
s32 func_00031424();
s32 func_00035D08();
s32 func_0003E0A0();
s32 func_0004461C();
s32 func_0007F9B0();
s32 func_00080504();
s32 func_00089398();
s32 func_00089810();
s32 func_0008AC80();
s32 func_00095C28();
s32 func_000A17A0();
s32 func_000A2944();
s32 func_000A294C();
s32 func_000A42C4();
s32 func_000C2C68();
s32 func_000CD188();
s32 func_000DC190();
s32 func_000DE6B4();
s32 func_000E2258();
s32 func_000ECFE4();
s32 func_000ED2FC();
s32 func_000F5398();
s32 func_000FC658();
s32 func_000FC800();
s32 func_000FC8C4();
s32 func_00108EE4();
s32 func_001172D8();
void * func_00035F78();
void * func_0003FBD4();
void func_00002600();
void func_000047A4();
void func_00004A9C();
void func_00004D40();
void func_0000F9C4();
void func_00041EE0();
void func_000602C4();
void func_000804E4();
void func_000804F0();
void func_0008F4A4();
void func_0008F4E4();
void func_000A5C50();
void func_000A5DCC();

/* func_00002600 — 2 words. MATCH 100% (shape: m2c). */
void func_00002600(void) {
    ehsys_639AE71F();
}

/* func_000046E8 — 2 words. MATCH 100% (shape: m2c). */
s32 func_000046E8(void) {
    return 0;
}

/* func_000047A4 — 2 words. MATCH 100% (shape: m2c). */
void func_000047A4(void) {
    func_00000664();
}

/* func_00004A9C — 2 words. MATCH 100% (shape: m2c). */
void func_00004A9C(void) {
    ehsys_1460C6FD();
}

/* func_00004D40 — 2 words. MATCH 100% (shape: m2c). */
void func_00004D40(void) {
    func_00004C74();
}

/* func_0000F9C4 — 2 words. MATCH 100% (shape: m2c). */
void func_0000F9C4(void) {

}

/* func_000197DC — 2 words. MATCH 100% (shape: m2c). */
s32 func_000197DC(void) {
    return 1;
}

/* func_0001D97C — 2 words. MATCH 100% (shape: m2c). */
s32 func_0001D97C(void) {
    return 0;
}

/* func_00031424 — 2 words. MATCH 100% (shape: m2c). */
s32 func_00031424(void) {
    return 1;
}

/* func_00035D08 — 8 words. MATCH 100% (shape: m2c). */
s32 func_00035D08(void) {
    func_00035C38();
    return 0;
}

/* func_00035F78 — 14 words. MATCH 100% (shape: m2c). */
void *func_00035F78(s32 arg0) {
    return &D_0034C6C8 + ((arg0 == (s32) &D_0034C6F8) * 0x4C) + 0x30;
}

/* func_0003E0A0 — 10 words. MATCH 100% (shape: m2c). */
s32 func_0003E0A0(void) {
    func_0003DD30();
    func_0003DE44();
    return 1;
}

/* func_0003FBD4 — 6 words. MATCH 100% (shape: m2c). */
void *func_0003FBD4(s32 arg0) {
    return &D_0034DF44 + (arg0 * 4) + 0x14;
}

/* func_00041EE0 — 11 words. MATCH 100% (shape: m2c). */
void func_00041EE0(void) {
    if (D_00326E80 != NULL) {
        ((int (*)()) D_00326E80)();
    }
}

/* func_0004461C — 17 words. MATCH 100% (shape: m2c). */
s32 func_0004461C(s32 arg0) {
    if ((arg0 != 0x1D9A) && (arg0 != 0x1CDA) && (arg0 != 0x1A92) && (arg0 != 0x1578)) {
        return 0;
    }
    return 1;
}

/* func_000602C4 — 19 words. MATCH 100% (shape: m2c). */
void func_000602C4(s32 arg0, s32 arg1) {
    s32 temp_a0;

    temp_a0 = arg0 & 1;
    func_000135F0(0x3E, (((arg1 & 0x3FF) << 6) | (temp_a0 | 0x1E)) & 0xFFFF, (temp_a0 | 0x5C) & 0xFFFF, 0);
    func_0015CCE0(0x26, 0);
}

/* func_0007F9B0 — 38 words. MATCH 100% (shape: m2c). */
s32 func_0007F9B0(s32 arg0) {
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
    *arg0 = *arg1;
}

/* func_000804F0 — 5 words. MATCH 100% (shape: m2c). */
void func_000804F0(f32 *arg0, f32 *arg1) {
    f32 temp_f1;

    temp_f1 = *arg0;
    *arg0 = *arg1;
    *arg1 = temp_f1;
}

/* func_00080504 — 5 words. MATCH 100% (shape: m2c). */
s32 func_00080504(s32 *arg0, s32 *arg1) {
    return *arg0 == *arg1;
}

/* func_00089398 — 45 words. MATCH 100% (shape: m2c). */
s32 func_00089398(u16 *arg0) {
    u16 temp_v1;

    temp_v1 = *arg0;
    if ((temp_v1 != 0x1926) && (temp_v1 != 0x18D9) && (temp_v1 != 0x1739) && (temp_v1 != 0x12D0) && (temp_v1 != 0x12CF) && (temp_v1 != 0xE05) && (temp_v1 != 0x1EC2) && (temp_v1 != 0x1ADF) && (temp_v1 != 0x1737) && (temp_v1 != 0x1696) && (temp_v1 != 0x15DF) && (temp_v1 != 0x1530) && (temp_v1 != 0x14F6)) {
        return 0;
    }
    return 1;
}

/* func_00089810 — 15 words. MATCH 100% (shape: m2c). */
s32 func_00089810(u16 *arg0) {
    u16 temp_v1;

    temp_v1 = *arg0;
    if ((temp_v1 != 0x232A) && (temp_v1 != 0x21EB) && (temp_v1 != 0x213A)) {
        return 3;
    }
    return 1;
}

/* func_0008AC80 — 18 words. MATCH 100% (shape: m2c). */
s32 func_0008AC80(s32 arg0) {
    s32 temp_s0;

    temp_s0 = func_0008AB14(0, arg0, -1);
    return temp_s0 + func_0008AB14(1, arg0, -1);
}

/* func_0008F4A4 — 16 words. MATCH 100% (shape: m2c). */
void func_0008F4A4(s32 arg0, int arg1) {
    func_0008F2E4(arg0, arg1, func_000827C4());
}

/* func_0008F4E4 — 16 words. MATCH 100% (shape: m2c). */
void func_0008F4E4(s32 arg0, int arg1) {
    func_0008F2E4(arg0, arg1, func_00083084());
}

/* func_00095C28 — 20 words. MATCH 100% (shape: m2c). */
s32 func_00095C28(s32 arg0) {
    if ((ehsys_CEA78CA6() != 0) && (func_0008A0D0(0xEAD) != 0)) {
        return 2;
    }
    return ehsys_E62CCE79(arg0);
}

/* func_000A17A0 — 55 words. MATCH 100% (shape: m2c). */
s32 func_000A17A0(s32 arg0, s32 arg1) {
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
    return 1;
}

/* func_000A294C — 104 words. MATCH 100% (shape: m2c). */
s32 func_000A294C(s32 arg0, s32 arg1) {
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
    func_000A59E0(0, arg0, arg1, arg2);
    func_000A59E0(1, arg0, arg1, arg2);
}

/* func_000A5DCC — 24 words. MATCH 100% (shape: m2c). */
void func_000A5DCC(s32 arg0, int arg1, int arg2) {
    func_000A5CB0(0, arg0, arg1, arg2);
    func_000A5CB0(1, arg0, arg1, arg2);
}

/* func_000C2C68 — 14 words. MATCH 100% (shape: m2c). */
s32 func_000C2C68(void) {
    if (func_000C2A88 == func_000C2C68) {
        return 1;
    }
    return func_000C2A88();
}

/* func_000CD188 — 17 words. MATCH 100% (shape: m2c). */
s32 func_000CD188(s32 arg0) {
    if (func_000A4934() == 0) {
        func_0006F5B0(arg0, func_0017B640(arg0));
    }
    return 1;
}

/* func_000DC190 — 23 words. MATCH 100% (shape: m2c). */
s32 func_000DC190(u16 *arg0, int arg1) {
    if ((*arg0 == 0x12EA) && (func_0008A0D0(0x12FB) > 0)) {
        return 0;
    }
    return func_000D6EAC(arg0, arg1);
}

/* func_000DE6B4 — 18 words. MATCH 100% (shape: m2c). */
s32 func_000DE6B4(void) {
    s32 temp_s0;

    temp_s0 = func_0008C4A4(0, 1, 0);
    return (temp_s0 + func_0008C4A4(1, 1, 0)) != 0;
}

/* func_000E2258 — 8 words. MATCH 100% (shape: m2c). */
s32 func_000E2258(void) {
    return func_0008F280(0x159D) != 0;
}

/* func_000ECFE4 — 15 words. MATCH 100% (shape: m2c). */
s32 func_000ECFE4(void) {
    s32 var_v0;

    var_v0 = func_000A41B4(0, 1) != 0;
    if (var_v0 != 0) {
        var_v0 = func_000A41B4(1, 1) != 0;
    }
    return var_v0;
}

/* func_000ED2FC — 8 words. MATCH 100% (shape: m2c). */
s32 func_000ED2FC(void) {
    return func_0008A0D0(0x175E) != 0;
}

/* func_000F5398 — 8 words. MATCH 100% (shape: m2c). */
s32 func_000F5398(void) {
    return func_000A49E8() != 0;
}

/* func_000FC658 — 13 words. MATCH 100% (shape: m2c). */
s32 func_000FC658(s32 arg0) {
    func_0006D308(arg0, func_0017B760());
    return 0;
}

/* func_000FC800 — 13 words. MATCH 100% (shape: m2c). */
s32 func_000FC800(s32 arg0) {
    func_0006E5F4(arg0, func_0017B760());
    return 0;
}

/* func_000FC8C4 — 13 words. MATCH 100% (shape: m2c). */
s32 func_000FC8C4(s32 arg0) {
    func_0006E8A0(arg0, func_0017B760());
    return 0;
}

/* func_00108EE4 — 2 words. MATCH 100% (shape: m2c). */
s32 func_00108EE4(void) {
    return 0;
}

/* func_001172D8 — 8 words. MATCH 100% (shape: m2c). */
s32 func_001172D8(void) {
    func_000744E4();
    return 0;
}

