/*
 * rel_soundtest.prx — reconstructed code (matching decompilation)
 *
 * Compiler:     Metrowerks CodeWarrior for PSP — MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,s -sdatathreshold 0
 * Verification: scripts/mwcc_build.sh src/rel_soundtest.c
 *               scripts/mwcc_diff.py asm/rel_soundtest/text.s build/mwcc/rel_soundtest.o
 *
 * Every function below is byte-identical to the shipped module — each was
 * accepted only on a MATCH verdict from scripts/mwcc_diff.py, and the whole
 * file is re-verified after assembly (scripts/assemble_module.py).
 * Functions are in ADDRESS ORDER, which is what the linker needs.
 *
 * Import names are resolved from the module's NID tables and are identical
 * across all 28 modules — see docs/nids/README.md.
 *
 * STATUS: 8 functions matched here. The rest of the module is not
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
extern char D_000067D0;
extern char D_000067D4;
extern char D_00006820;
extern char D_000068C4;
extern char D_000068DC;
extern char D_000068E8;
extern char D_000068F0;
extern char D_000068F8;
extern char D_00006908;
extern char D_00006918;
extern char D_00006920;
extern char D_00006928;
extern char D_00006960;
extern char D_00006964;
extern char D_0000696C;
extern char D_00006970;
extern char D_00006974;
extern char D_00006978;
extern char D_0000697C;
extern char D_00006980;
extern char D_00006A2C;
extern char D_00006A30;
extern char D_00006A34;
extern char D_00006A38;
extern char D_00006A3C;
extern char D_00006A40;
extern char D_00006A44;
extern char D_00006A48;
extern char D_00006A4C;
extern char D_00006A50;
extern int ehsys_06A1D1D8();
extern int ehsys_13A4081A();
extern int ehsys_1856E536();
extern int ehsys_20E340D9();
extern int ehsys_251128FD();
extern int ehsys_33ED567B();
extern int ehsys_41AABF28();
extern int ehsys_450CD6C5();
extern int ehsys_4AA58320();
extern int ehsys_4B0DABFA();
extern int ehsys_5998BFD7();
extern int ehsys_6367AE39();
extern int ehsys_6E42DDCD();
extern int ehsys_BC8E65D7();
extern int ehsys_BF3E9066();
extern int ehsys_C07BB470();
extern int ehsys_C6C15111();
extern int ehsys_C9D9E989();
extern int ehsys_D2A768F4();
extern int ehsys_D470D0B2();
extern int ehsys_D853F15C();
extern int ehsys_D979E9BF();
extern int ehsys_ED1410E0();
extern int ehsys_F6414A71();
extern int ehsys_FDAFCF3A();
extern int ehsys_get_language();
extern int ehsys_memset();
extern int ehsys_sceKernelChangeCurrentThreadAttr();
extern int ehsys_sprintf();
extern int func_000004AC();
extern int func_00000908();

/* ---- forward declarations ---- */
s32 func_00000000(void);
void func_00000008(s32 arg0);
s32 func_000000FC(void);
void func_00000234(void);
void func_0000023C(void);
void func_00000280(void);
s32 func_000013FC(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_000015B8(void);

/* func_00000000 — 2 words. MATCH 100% (shape: m2c). */
s32 func_00000000(void) {
    return 0;
}

/* func_00000008 — 61 words. MATCH 100% (shape: hand). */
void func_00000008(s32 arg0) {
    s32 temp;

    ehsys_memset(&D_00006960, 0, 0xF4);
    if (arg0 == 0) {
        temp = ehsys_C07BB470(&D_000067D0, 2, 0, 0x300000, 1, 0);
        *(int *) &D_00006A4C = temp;
        ehsys_D979E9BF(temp, &D_00006A50, 0);
        *(int *) &D_00006A48 = ehsys_1856E536(*(int *) &D_00006A50, 0x300000);
    } else {
        *(int *) &D_00006A48 = arg0;
    }
    ehsys_sceKernelChangeCurrentThreadAttr(0, 0x4000);
    ehsys_6E42DDCD();
    ehsys_C9D9E989(1);
    ehsys_4AA58320(1);
    if (ehsys_get_language() == 0) {
        ehsys_33ED567B(1);
        ehsys_D853F15C(0);
    } else {
        ehsys_33ED567B(0);
        ehsys_D853F15C(1);
    }
}

/* func_000000FC — 78 words. MATCH 100% (shape: hand). */
s32 func_000000FC(void) {
    switch (*(int *) &D_00006960) {
        case 0:
            func_00000280();
            ehsys_13A4081A(0);
            ehsys_5998BFD7(1, 0xFF000000, 0);
            ehsys_D470D0B2(1, 0xFF000000, 0x10);
            *(int *) &D_00006960 = 1;
            break;
        case 1:
            if (ehsys_450CD6C5() == 0) {
                break;
            }
            *(int *) &D_00006960 = 2;
            break;
        case 2:
            if (func_000004AC() != 0) {
                break;
            }
            ehsys_6367AE39(0x258);
            ehsys_5998BFD7(1, 0xFF000000, 0x1E);
            *(int *) &D_00006960 = 3;
            break;
        case 3:
            if (ehsys_450CD6C5() == 0) {
                break;
            }
            if (ehsys_06A1D1D8() != 0) {
                break;
            }
            *(int *) &D_00006960 = 4;
            break;
        case 4:
            func_0000023C();
            return 0;
        default:
            break;
    }
    return 1;
}

/* func_00000234 — 2 words. MATCH 100% (shape: m2c). */
void func_00000234(void) {
    func_00000908();
}

/* func_0000023C — 17 words. MATCH 100% (shape: hand). */
void func_0000023C(void) {
    func_000015B8();
    if (*(int *) &D_00006A4C > 0) {
        ehsys_F6414A71(*(int *) &D_00006A4C, *(int *) &D_00006A50);
        ehsys_ED1410E0(*(int *) &D_00006A4C);
    }
}

/* func_00000280 — 139 words. MATCH 100% (shape: hand). */
void func_00000280(void) {
    char sp10[64];
    s32 temp_a;
    s32 temp_b;
    s32 var_s0;
    s32 var_s0_2;

    temp_a = ehsys_D2A768F4(3, &D_000068C4);
    temp_b = ehsys_41AABF28(*(int *) &D_00006A48, temp_a);
    *(int *) &D_00006A2C = temp_b;
    ehsys_BF3E9066(3, &D_000068C4, temp_b, temp_a);
    ehsys_4B0DABFA(0, *(int *) &D_00006A2C);
    var_s0 = ehsys_get_language();
    if (var_s0 < 0 || var_s0 >= 6) {
        var_s0 = 0;
    }
    *(int *) &D_00006A30 = ehsys_C6C15111(*(int *) &D_00006A2C, &D_000068DC, 0);
    *(int *) &D_00006A38 = ehsys_C6C15111(*(int *) &D_00006A2C, &D_000068E8, 0);
    *(int *) &D_00006A3C = ehsys_C6C15111(*(int *) &D_00006A2C, &D_000068F0, 0);
    *(int *) &D_00006A40 = ehsys_C6C15111(*(int *) &D_00006A2C, &D_000068F8, 0);
    *(int *) &D_00006A44 = ehsys_C6C15111(*(int *) &D_00006A2C, &D_00006908, 0);
    ehsys_sprintf(sp10, &D_00006918, &D_00006920, (char *) &D_000067D4 + var_s0 * 2, &D_00006928);
    *(int *) &D_00006A34 = ehsys_C6C15111(*(int *) &D_00006A2C, sp10, 0);
    ehsys_FDAFCF3A(*(int *) &D_00006A38, *(int *) &D_00006A3C);
    ehsys_FDAFCF3A(*(int *) &D_00006A40, *(int *) &D_00006A44);
    *(int *) &D_00006964 = 1;
    *(int *) &D_00006974 = -1;
    *(int *) &D_00006978 = 0;
    *(int *) &D_0000696C = 0;
    *(int *) &D_00006970 = 0;
    *(int *) &D_0000697C = 0;
    *(int *) &D_00006980 = 0;
    var_s0_2 = 0;
    do {
        *(int *) ((char *) &D_00006960 + 0x24 + var_s0_2 * 4) =
            ehsys_251128FD(*(int *) ((char *) &D_00006820 + var_s0_2 * 4));
        var_s0_2 += 1;
    } while (var_s0_2 < 0x29);
}

/* func_000013FC — 5 words. MATCH 100% (shape: hand). */
s32 func_000013FC(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return ehsys_BC8E65D7(arg0 << 6, arg1 << 6, arg2 << 6, arg3, -1);
}

/* func_000015B8 — 12 words. MATCH 100% (shape: hand). */
void func_000015B8(void) {
    ehsys_6E42DDCD();
    ehsys_20E340D9(*(int *) &D_00006A48, *(int *) &D_00006A2C);
}
