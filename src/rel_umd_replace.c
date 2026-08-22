/*
 * rel_umd_replace.prx — reconstructed code (matching decompilation)
 *
 * Compiler:     Metrowerks CodeWarrior for PSP — MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,s -sdatathreshold 0
 * Verification: scripts/mwcc_build.sh src/rel_umd_replace.c
 *               scripts/mwcc_diff.py asm/rel_umd_replace/text.s build/mwcc/rel_umd_replace.o
 *
 * Every function below is byte-identical to the shipped module — each was
 * accepted only on a MATCH verdict from scripts/mwcc_diff.py, and the whole
 * file is re-verified after assembly (scripts/assemble_module.py).
 * Functions are in ADDRESS ORDER, which is what the linker needs.
 *
 * Import names are resolved from the module's NID tables and are identical
 * across all 28 modules — see docs/nids/README.md.
 *
 * STATUS: 16 functions matched here. The rest of the module is not
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
extern char D_00009350;
extern char D_00009354;
extern char D_000096E0;
extern char D_000096F0;
extern char D_0000B108;
extern char D_B910;
extern char D_BAC0;
extern char D_BAD0;
extern char D_BBF4;
extern int ehsys_03E45FFF();
extern int ehsys_14BFFB01();
extern int ehsys_1EC5342B();
extern int ehsys_2717C28C();
extern int ehsys_30FECAEF();
extern int ehsys_39ADDA9F();
extern int ehsys_4AA58320();
extern int ehsys_5DF04F49();
extern int ehsys_B4471B5E();
extern int ehsys_DFCA450B();
extern int ehsys_E1139F1A();
extern int ehsys_EBD1986B();
extern int ehsys_memset();
extern int func_00000038();
extern int func_00000250();
extern int func_000029BC();
extern int func_000036D4();
extern s32 ehsys_D3448D59(s32 arg0);
extern s32 ehsys_1D821C84(void);
extern s32 ehsys_33ED567B(s32 arg0);
extern s32 ehsys_D853F15C(s32 arg0);
extern s32 ehsys_EF9B5D06(s32 *arg0, s32 arg1);
extern s32 ehsys_get_language(void);
extern int sceImposeSetUMDPopup();
extern int sceKernelCreateCallback();
extern int sceUmdActivate();
extern int sceUmdRegisterUMDCallBack();

/* ---- forward declarations ---- */
s32 func_00000000(s32 arg0);
s32 func_00000FD0(s32 arg0);
s32 func_00001018(s32 arg0, s32 arg1);
s32 func_00002EC8(void);
s32 func_0000327C(void);
s32 func_000036B0(void);
s32 func_000038B8(void);
s32 func_000038C4(void);
void func_000000DC(void);
void func_0000017C(void);
void func_00000184(void);
void func_00001164(void);
void func_0000293C(void);
void func_00002A58(void);
void func_00002E78(void);
void func_00003714(void);

/* func_00000000 — 14 words. MATCH 100% (shape: m2c). */
s32 func_00000000(s32 arg0) {
    if (arg0 == 0) {
        ehsys_B4471B5E(func_00000038, func_000000DC, &D_000096E0);
    }
    return 0;
}

/* func_000000DC — 2 words. MATCH 100% (shape: m2c). */
void func_000000DC(void) {

}

/* func_000000E4 — 13 words. Sets the current thread's attribute mask,
 * starts func_000010A0, then marks D_000096EC true and returns 1 (the
 * return value is unused by its caller but the store and the return share
 * the literal 1, which is what pins the value into $v0 rather than a dead
 * register). MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_000000E4(void) {
    extern int D_000096EC;
    extern void func_000010A0(void);
    extern int sceKernelChangeCurrentThreadAttr();
    sceKernelChangeCurrentThreadAttr(0, 0x4000);
    func_000010A0();
    D_000096EC = 1;
    return 1;
}

/* func_0000017C — 2 words. MATCH 100% (shape: m2c). */
void func_0000017C(void) {
    func_00001164();
}

/* func_00000184 — 16 words. MATCH 100% (shape: m2c). */
void func_00000184(void) {
    ehsys_memset(&D_000096F0, 0, 0x1CE0);
    ehsys_30FECAEF(&D_0000B108, func_000038B8());
}

/* func_00000150 — MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00000150(void) {
    extern int D_000096EC;
    extern void func_00001330(void);
    if (D_000096EC != 0) {
        func_00001330();
    }
}

/* func_00000614 — MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_00000614(void) {
    return *(int *)&D_000096F0 != 0;
}

/* func_00000FD0 — 18 words. MATCH 100% (shape: m2c). */
s32 func_00000FD0(s32 arg0) {
    s32 temp_v0;

    temp_v0 = ehsys_39ADDA9F();
    if (temp_v0 != -1) {
        ehsys_E1139F1A(arg0);
    }
    return temp_v0;
}

/* func_00001018 — 34 words. MATCH 100% (shape: m2c). */
s32 func_00001018(s32 arg0, s32 arg1) {
    s32 sp1C;
    s32 v0;
    s32 s1;
    s32 s0;

    sp1C = arg1;
    v0 = ehsys_D3448D59(arg0);
    s1 = v0;
    v0 = ehsys_1D821C84();
    s0 = v0;
    v0 = ehsys_get_language();
    if (v0 == 0) {
        ehsys_33ED567B(1);
    } else {
        ehsys_D853F15C(1);
    }
    ehsys_EF9B5D06(&sp1C, arg0);
    ehsys_33ED567B(s1);
    ehsys_D853F15C(s0);
    return sp1C;
}

/* func_00001164 — 22 words. MATCH 100% (shape: m2c). */
void func_00001164(void) {
    ehsys_4AA58320(*(s32 *)0xB9D8);
    func_000029BC();
    func_00000250();
    ehsys_5DF04F49(&D_B910);
    func_000036D4();
    ehsys_03E45FFF();
    ehsys_EBD1986B(0, 0);
}

/* func_00001A1C — MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00001A1C(void) {
    extern int func_000036B0(void);
    extern int D_0000B3D0;
    int *p = &D_0000B3D0;
    if (func_000036B0() != 0) {
        *p = 1;
    }
}

/* func_00001A54 — MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00001A54(void) {
    extern int D_0000B3D0;
    extern void func_00001A88(void);
    extern void func_0000371C(int, void (*)(void), int);

    func_0000371C(0, func_00001A88, 0);
    D_0000B3D0 = 2;
}
/* func_00001A88 — 52 words. MATCH 100% (shape: m2c). */
void func_00001A88(void) {
    extern int D_0000B3D0;
    extern int D_B9E0;
    extern int D_BA50;
    extern int ehsys_42144DB8();
    extern int ehsys_D470D0B2();
    extern int ehsys_FDAFCF3A();
    extern int ehsys_memset();
    extern int func_000001C4();
    extern int func_00001A88();
    extern int func_000037E4();
    D_0000B3D0 = 3;
    *(s32 *)0xB9DC = func_000037E4(7);
    ehsys_FDAFCF3A(*(int *)0xB9DC, func_000037E4(8));
    ehsys_42144DB8(*(int *)0xB9DC, 0);
    ehsys_memset(&D_B9E0, 0, 0x60);
    *(s32 *)0xBA40 = func_000037E4(9);
    ehsys_FDAFCF3A(*(int *)0xBA40, func_000037E4(0xA));
    ehsys_42144DB8(*(int *)0xBA40, 0);
    ehsys_memset(&D_BA50, 0, 0x60);
    func_000001C4();
    ehsys_D470D0B2(1, -0x01000000, 0x10);
}

/* func_00001B58 — MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00001B58(void) {
    extern int D_0000B3D0;
    extern void func_00002A38(int);
    extern int func_000037E4(int);
    extern int ehsys_E58C0FDC(int, int);
    extern void func_00001748(int);

    func_00002A38(0);
    D_0000B3D0 = 4;
    func_00001748(ehsys_E58C0FDC(func_000037E4(0), 8));
}

/* func_00001C7C — MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00001C7C(void) {
    extern int D_0000B3D0;
    extern void func_00002A38(int);
    extern int func_000037E4(int);
    extern int ehsys_E58C0FDC(int, int);
    extern void func_00001748(int);

    func_00001748(ehsys_E58C0FDC(func_000037E4(0), 7));
    func_00002A38(1);
    D_0000B3D0 = 6;
}

/* func_00002450 — MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00002450(void) {
    extern void func_0000042C(int);
    extern int D_0000B7E8;
    extern int D_0000B3D0;
    func_0000042C(D_0000B7E8);
    D_0000B7E8 = 0;
    D_0000B3D0 = 9;
}

/* func_00002484 — MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00002484(void) {
    extern void func_0000028C(void);
    extern s32 func_00000614(void);
    extern int D_0000B3D0;
    int *p = &D_0000B3D0;
    func_0000028C();
    if (func_00000614() == 0) {
        *p = 3;
    }
}

/* func_000024C4 — MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_000024C4(void) {
    extern int ehsys_E58C0FDC(int, int);
    extern int D_0000B3D0;
    extern int D_0000B7EC;
    extern void func_00000DF0(int *, int, int, int, int);
    extern s32 func_000037E4(int);
    func_00000DF0(&D_0000B7EC, ehsys_E58C0FDC(func_000037E4(0), 1), 1, 1, 1);
    D_0000B3D0 = 0xB;
}

/* func_00002754 — MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
void func_00002754(void) {
    extern int ehsys_E58C0FDC(int, int);
    extern int D_0000B3D0;
    extern int D_0000B7EC;
    extern void func_00000DF0(int *, int, int, int, int);
    extern s32 func_000037E4(int);
    func_00000DF0(&D_0000B7EC, ehsys_E58C0FDC(func_000037E4(0), 2), 3, 2, 0);
    D_0000B3D0 = 0xF;
}

/* func_0000293C — 32 words. MATCH 100% (shape: m2c). */
void func_0000293C(void) {
    s32 temp_v0;

    ehsys_memset(&D_BAC0, 0, 0x1FC);
    temp_v0 = sceKernelCreateCallback(&D_00009350, func_0000327C, 0);
    *(s32 *)0xBACC = temp_v0;
    sceUmdRegisterUMDCallBack(temp_v0);
    sceUmdActivate(1, &D_00009354);
    sceImposeSetUMDPopup(0);
    ehsys_30FECAEF(&D_BBF4, func_000038B8());
}

/* func_00002A58 — 2 words. MATCH 100% (shape: m2c). */
void func_00002A58(void) {

}

/* func_00002E78 — 20 words. MATCH 100% (shape: m2c). */
void func_00002E78(void) {
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = ehsys_DFCA450B(4, 0);
    sp1C = temp_v0;
    sp1C = func_00001018((s32) &D_BAD0, temp_v0);
    ehsys_14BFFB01(&sp1C, &D_BBF4);
    ehsys_1EC5342B(sp1C);
}

/* func_00002EC8 — 3 words. MATCH 100% (shape: m2c). */
s32 func_00002EC8(void) {
    return *(s32 *)0xBAC4;
}
/* func_00002ED4 — 3 words. MATCH 100% (shape: m2c). */
void **func_00002ED4(void) {
    extern void * D_BCC0;
    extern int func_00002ED4();
    return &D_BCC0;
}

/* func_0000327C — 2 words. MATCH 100% (shape: m2c). */
s32 func_0000327C(void) {
    return 0;
}

/* func_000036B0 — 9 words. MATCH 100% (shape: m2c). */
s32 func_000036B0(void) {
    return ehsys_2717C28C(*(s32 *)0x290CE8) != 0;
}

/* func_000036D4 — MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_000036D4(void) {
    extern void ehsys_1078C73B(int);
    extern int D_290CE4;
    int *p = &D_290CE4;
    if (*(int *)0x290CE4 != 0) {
        ehsys_1078C73B(*p);
        *p = 0;
    }
    return 1;
}

/* func_000037E4 — 8 words. Indexes a 0x24-byte record array at D_000094B4
 * by arg0 and tail-calls func_00003804 with the record pointer and its
 * field at offset 0x20. MATCH 100% (mwccpsp_3.0.1_219, -O4,s
 * -sdatathreshold 0). */
void func_000037E4(s32 arg0) {
    extern char D_000094B4[];
    extern void func_00003804(void *arg0, s32 arg1);
    char *p = D_000094B4 + arg0 * 0x24;
    func_00003804(p, *(s32 *) (p + 0x20));
}

/* func_00003714 — 2 words. MATCH 100% (shape: m2c). */
void func_00003714(void) {

}

/* func_00003898 — MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_00003898(s32 arg0) {
    extern int ehsys_41AABF28(int, int);
    return ehsys_41AABF28(*(int *)0x290CE4, arg0);
}

/* func_000038A8 — MATCH 100% (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0). */
s32 func_000038A8(s32 arg0) {
    extern int ehsys_20E340D9(int, int);
    return ehsys_20E340D9(*(int *)0x290CE4, arg0);
}

/* func_000038B8 — 3 words. MATCH 100% (shape: m2c). */
s32 func_000038B8(void) {
    return *(s32 *)0x290CE4;
}

/* func_000038C4 — 3 words. MATCH 100% (shape: m2c). */
s32 func_000038C4(void) {
    return *(s32 *)0x290CE8;
}

