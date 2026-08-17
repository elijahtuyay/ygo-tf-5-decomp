/*
 * rel_gallery.prx — reconstructed code (matching decompilation)
 *
 * Compiler:     Metrowerks CodeWarrior for PSP — MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,s -sdatathreshold 0
 * Verification: scripts/mwcc_build.sh src/rel_gallery.c
 *               scripts/mwcc_diff.py asm/rel_gallery/text.s build/mwcc/rel_gallery.o
 *
 * Every function below is byte-identical to the shipped module — each was
 * accepted only on a MATCH verdict from scripts/mwcc_diff.py, and the whole
 * file is re-verified after assembly (scripts/assemble_module.py).
 * Functions are in ADDRESS ORDER, which is what the linker needs.
 *
 * Import names are resolved from the module's NID tables and are identical
 * across all 28 modules — see docs/nids/README.md.
 *
 * STATUS: 31 functions matched here. The rest of the module is not
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
extern char D_0000A840;
extern s16 D_0000A318[];
extern s16 D_000098A0[];
extern int ehsys_B4471B5E();
extern int func_00000188();
extern int func_00003F30();
extern s32 ehsys_C6C15111(s32 arg0, s16 *arg1, s32 arg2);
extern void ehsys_E58C0FDC(s32 arg0, s32 arg1);
extern s32 func_00003D94(s32 *arg0, s32 arg1);

/* ---- forward declarations ---- */
s32 func_00000150(s32 arg0);
void func_00000228(void);
s32 func_000002D4(void);
void func_00000314(void);
s32 func_00000720(s32 arg0, s32 arg1);
s32 func_00001144(void *arg0);
s32 func_00001158(void *arg0);
f32 func_00001328(void *arg0, s32 arg1);
void func_00001818(void);
s32 func_00001D00(s32 *arg0);
void func_000024E0(void *arg0, s8 arg1);
void func_000025D8(void *arg0);
void func_0000320C(void *arg0);
void func_00003204(void);
void func_00003510(s32 *arg0, s32 arg1);
void func_00003D24(void *arg0);
void func_00003D7C(s32 arg0, s32 *arg1, s32 arg2);
s32 func_00003D84(s32 *arg0, s32 arg1);
void func_00003F94(void);
s32 func_00003F9C(s32 *arg0, s32 arg1);
s32 func_000041DC(s32 *arg0, s32 arg1);
void func_00004220(void);
void func_000042B8(void);
void func_00004314(void);
void func_00004394(void);
void func_000044A4(void);

/* func_00000150 — 14 words. MATCH 100% (shape: m2c). */
s32 func_00000150(s32 arg0) {
    if (arg0 == 0) {
        ehsys_B4471B5E(func_00000188, func_00000228, &D_0000A840);
    }
    return 0;
}

/* func_00000228 — 2 words. MATCH 100% (shape: m2c). */
void func_00000228(void) {

}

/* func_000002D4 — 16 words. MATCH 100% (shape: m2c, extern-symbol lever). */
s32 func_000002D4(void) {
    extern int func_00002124();
    extern s32 D_0000A84C;
    s32 *p = &D_0000A84C;

    if (func_00002124(*(s32 *)0x30A854) != 0) {
        *p = 0;
        return 1;
    }
    return 0;
}

/* func_00000314 — 12 words. MATCH 100% (shape: m2c, extern-symbol lever). */
void func_00000314(void) {
    extern s32 D_0000A84C;
    extern int func_00003BCC();

    if (D_0000A84C != 0) {
        func_00003BCC(*(s32 *)0x30A854);
    }
}

/* func_00000720 — 2 words. MATCH 100% (shape: m2c). */
s32 func_00000720(s32 arg0, s32 arg1) {
    return arg1;
}

/* func_00001144 — 5 words. MATCH 100% (shape: m2c, s16 field cmp). */
s32 func_00001144(void *arg0) {
    return (*(s16 *)((char *)arg0 + 0x28)) != (*(s16 *)((char *)arg0 + 0x2A));
}

/* func_00001158 — 4 words. MATCH 100% (shape: m2c, lh + xori/sltiu equality). */
s32 func_00001158(void *arg0) {
    return *(s16 *)((char *)arg0 + 0x24FC) == 8;
}

/* func_00001328 — 12 words. MATCH 100% (shape: m2c, duplicated-return branch). */
f32 func_00001328(void *arg0, s32 arg1) {
    f32 v;
    if (arg1 != 0) {
        v = *(f32 *)((char *)arg0 + 0x15D4);
        return v - 40.0f;
    }
    v = *(f32 *)((char *)arg0 + 8);
    return v - 40.0f;
}

/* func_00001818 — 2 words. MATCH 100% (shape: m2c). */
void func_00001818(void) {

}
/* func_00001930 — 2 words. MATCH 100% (shape: m2c). */
s32 func_00001930(void *arg0) {
    extern int func_00001930();
    return (*(int *)((char *)arg0 + 0x180));
}

/* func_00001D00 — 2 words. MATCH 100% (shape: m2c). */
s32 func_00001D00(s32 *arg0) {
    return func_00003D84(arg0, *(int *)((char *)arg0 + 0x188));
}
/* func_000024D8 — 2 words. MATCH 100% (shape: m2c). */
s32 func_000024D8(void *arg0) {
    extern int func_000024D8();
    return (*(int *)((char *)arg0 + 0x17C));
}

/* func_000024E0 — 2 words. MATCH 100% (shape: m2c, sb field store). */
void func_000024E0(void *arg0, s8 arg1) {
    *(s8 *)((char *)arg0 + 0x10) = arg1;
}

/* func_000025D8 — 5 words. MATCH 100% (shape: m2c, s16/s8 field stores). */
void func_000025D8(void *arg0) {
    *(s16 *)((char *)arg0 + 0x1A) = 0xFF;
    *(s8 *)((char *)arg0 + 0x1C) = -0xA;
}

/* func_00003204 — 2 words. MATCH 100% (shape: m2c). */
void func_00003204(void) {

}

/* func_0000320C — 57 words. MATCH 100% (shape: m2c, extern-symbol lever). */
void func_0000320C(void *arg0) {
    extern int ehsys_06380DFA();
    extern int ehsys_0D961646();
    extern int ehsys_1EC5342B();
    extern int ehsys_60B55A50();
    extern int ehsys_942B03D0();
    extern int ehsys_A4AFF8E6();
    extern int ehsys_B8AD96EA();
    extern int ehsys_C9D9E989();
    extern int ehsys_DFCA450B();
    extern s32 ehsys_E58C0FDC(s32 arg0, s32 arg1);
    extern int func_000032F0();
    s32 temp_s1;
    s32 temp_s0;

    if ((func_00003D84((s32 *)(*(int *)((char *)arg0 + 0x0)), 0) != 0) && (func_00001158((void *)(*(int *)((char *)arg0 + 0x8))) != 0)) {
        temp_s1 = ehsys_DFCA450B(4, 0);
        temp_s0 = ehsys_0D961646() & 0xFFFF;
        ehsys_B8AD96EA(temp_s1);
        ehsys_C9D9E989(1);
        ehsys_942B03D0(0xE, 0xE);
        ehsys_60B55A50(-1);
        func_000032F0(0x28, 0x10, ehsys_E58C0FDC(ehsys_C6C15111(func_00003D84((s32 *)(*(int *)((char *)arg0 + 0x0)), 0x5E), D_0000A318, 0), 0xB3));
        ehsys_06380DFA(temp_s0);
        ehsys_1EC5342B(ehsys_A4AFF8E6());
    }
}

/* func_000032F0 — 8 words. MATCH 100% (shape: twin-of-rel_select_card-
 * func_00017094-family, via find_twins.py same-shape tier). */
extern int ehsys_B89D38DC();
s32 func_000032F0(s32 arg0, s32 arg1, s32 arg2) {
    return ehsys_B89D38DC(arg0 << 6, arg1 << 6, (0x1E0 - arg0) << 6, arg2);
}

/* func_00003510 — 23 words. MATCH 100% (shape: m2c). */
void func_00003510(s32 *arg0, s32 arg1) {
    s32 v0 = func_00003D84((s32 *)arg0[0], 0x5E);
    v0 = ehsys_C6C15111(v0, D_0000A318, 0);
    ehsys_E58C0FDC(v0, D_000098A0[arg1]);
}

/* func_000037C0 — 5 words. MATCH 100% (shape: twin-of-rel_select_card-
 * func_000012A8-family, via find_twins.py same-shape tier). */
extern int ehsys_BC8E65D7();
s32 func_000037C0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return ehsys_BC8E65D7(arg0 << 6, arg1 << 6, arg2 << 6, arg3, -1);
}

/* func_00003D24 — 18 words. MATCH 100% (shape: m2c). */
void func_00003D24(void *arg0) {
    extern int ehsys_memset();

    ehsys_memset(arg0, 0, 0x17C);
    (*(int *)((char *)arg0 + 0x17C)) = 0;
    (*(int *)((char *)arg0 + 0x18C)) = 0;
    (*(int *)((char *)arg0 + 0x198)) = 0;
    (*(int *)((char *)arg0 + 0x194)) = 0;
    (*(int *)((char *)arg0 + 0x19C)) = 0;
    (*(int *)((char *)arg0 + 0x1A0)) = 1;
}

/* func_00003D6C — 4 words. MATCH 100% (shape: m2c). */
void func_00003D6C(void *arg0) {
    extern int func_00003D6C();
    (*(int *)((char *)arg0 + 0x17C)) = (s32) ((*(int *)((char *)arg0 + 0x17C)) - 1);
}

/* func_00003D7C — 2 words. MATCH 100% (shape: m2c). */
void func_00003D7C(s32 arg0, s32 *arg1, s32 arg2) {
    *arg1 = arg2;
}

/* func_00003D84 — 4 words. MATCH 100% (shape: m2c). */
s32 func_00003D84(s32 *arg0, s32 arg1) {
    return arg0[arg1];
}
/* func_00003F20 — 4 words. MATCH 100% (shape: m2c). */
void func_00003F20(void *arg0) {
    extern int func_00003F20();
    (*(int *)((char *)arg0 + 0x0)) = 0;
    (*(int *)((char *)arg0 + 0x4)) = 0;
    (*(int *)((char *)arg0 + 0x8)) = 0;
}

/* func_00003F94 — 2 words. MATCH 100% (shape: m2c). */
void func_00003F94(void) {
    func_00003F30();
}

/* func_00003F9C — 2 words. MATCH 100% (shape: m2c). */
s32 func_00003F9C(s32 *arg0, s32 arg1) {
    *(int *)((char *)arg0 + 0x188) = arg1;
    return func_00003D94(arg0, arg1);
}

/* func_000041DC — 3 words. MATCH 100% (shape: m2c). */
s32 func_000041DC(s32 *arg0, s32 arg1) {
    s32 v0 = 0 < arg1;
    *arg0 = v0;
    return v0;
}

/* func_00004220 — 17 words. MATCH 100% (shape: m2c, ternary avoids branch-likely). */
void func_00004220(void) {
    extern int ehsys_57345021();
    extern int func_000044AC();
    s32 var_a0;
    s32 t = *(s32 *)0x30A850;

    var_a0 = ehsys_57345021(0x20, t);
    var_a0 = var_a0 ? func_000044AC(var_a0) : var_a0;
    *(s32 *)0x755884 = var_a0;
}

/* func_000042B8 — 2 words. MATCH 100% (shape: m2c). */
void func_000042B8(void) {

}

/* func_00004314 — 2 words. MATCH 100% (shape: m2c). */
void func_00004314(void) {

}

/* func_00004394 — 2 words. MATCH 100% (shape: m2c). */
void func_00004394(void) {

}

/* func_000044A4 — 2 words. MATCH 100% (shape: m2c). */
void func_000044A4(void) {

}

/* func_000044F4 — 4 words. MATCH 100% (shape: m2c). */
void func_000044F4(void *arg0) {
    extern int func_000044F4();
    (*(int *)((char *)arg0 + 0x0)) = 0;
    (*(int *)((char *)arg0 + 0x4)) = 0;
    (*(int *)((char *)arg0 + 0x8)) = 0;
}
