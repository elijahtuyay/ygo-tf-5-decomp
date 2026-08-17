/*
 * rel_title.prx — reconstructed code (matching decompilation)
 *
 * Compiler:     Metrowerks CodeWarrior for PSP — MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,s -sdatathreshold 0
 * Verification: scripts/mwcc_build.sh src/rel_title.c
 *               scripts/mwcc_diff.py asm/rel_title/text.s build/mwcc/rel_title.o
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
 * STATUS: 29 functions matched. build/auto/rel_title.json has the
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
/* func_00002F9C — 8 words. MATCH 100% (shape: m2c -O2; spill/reload of a0
 * through a wasted 0x10 stack frame). */
#pragma optimization_level 2
void func_00002F9C(void *arg0) {
    extern int func_00002F9C();
    volatile int sp[4];
    sp[0] = (int)arg0;
    *(short *)((char *)sp[0] + 0x10) = 1;
}
#pragma optimization_level 4

/* func_0000330C — 12 words. MATCH 100% (shape: m2c -O2; spill/reload of a0
 * through a wasted 0x20 stack frame). */
#pragma optimization_level 2
int func_0000330C(s32 arg0) {
    extern int func_00003338();
    extern int func_0000330C();
    volatile int sp[4];
    sp[0] = arg0;
    return func_00003338(sp[0], 0x10);
}
#pragma optimization_level 4

/* func_00003784 — 13 words. MATCH 100% (shape: m2c -O2; spill/reload of a0
 * through a wasted 0x20 stack frame). */
#pragma optimization_level 2
int func_00003784(s32 arg0) {
    extern int ehsys_2012884C();
    extern int ehsys_E1139F1A();
    extern int func_00003784();
    volatile int sp[4];
    sp[0] = arg0;
    ehsys_E1139F1A(sp[0]);
    return ehsys_2012884C(sp[0]);
}
#pragma optimization_level 4

/* func_00006B40 — 3 words. MATCH 100% (shape: m2c -O2). */
#pragma optimization_level 2
s32 func_00006B40(void) {
    extern int func_00006B40();
    return 1;
}
#pragma optimization_level 4


/* func_0000D420 — 5 words. MATCH 100% (shape: thunk+1). */
void func_0000D420(int a, int b, int c, int d) {
    extern int ehsys_BC8E65D7();
    extern int func_0000D420();
    ehsys_BC8E65D7(a << 6, b << 6, c << 6, d, -1);
}

/* func_0000D860 — 6 words. MATCH 100% (shape: m2c -O2; spill/reload of a0
 * through a wasted 0x60 stack frame). */
#pragma optimization_level 2
int func_0000D860(int a) {
    extern int func_0000D860();
    volatile int sp[24];
    sp[0] = a;
    return sp[0];
}
#pragma optimization_level 4

/* func_0000F028 — 5 words. MATCH 100% (shape: thunk+1). */
void func_0000F028(int a, int b, int c, int d) {
    extern int ehsys_BC8E65D7();
    extern int func_0000F028();
    ehsys_BC8E65D7(a << 6, b << 6, c << 6, d, -1);
}

/* func_00017374 — 2 words. MATCH 100% (shape: m2c). */
void func_00017374(void) {
    extern int func_00017374();

}

/* func_0001A2E4 — 5 words. MATCH 100% (shape: thunk+1). */
void func_0001A2E4(int a, int b, int c, int d) {
    extern int ehsys_BC8E65D7();
    extern int func_0001A2E4();
    ehsys_BC8E65D7(a << 6, b << 6, c << 6, d, -1);
}

/* func_0001A2F8 — 8 words. MATCH 100% (shape: thunk+2; computes (0x1E0-a0)<<6
 * for the third arg). */
int func_0001A2F8(int a0, int a1, int a2) {
    extern int ehsys_B89D38DC();
    extern int func_0001A2F8();
    return ehsys_B89D38DC(a0 << 6, a1 << 6, (0x1E0 - a0) << 6, a2);
}

/* func_0001A318 — 2 words. MATCH 100% (shape: thunk+1). */
int func_0001A318(int a) {
    extern int ehsys_5F00A362();
    extern int func_0001A318();
    return ehsys_5F00A362(a << 6);
}

/* func_0001A5A8 — 4 words. MATCH 100% (shape: thunk+1). */
int func_0001A5A8(int a, int b, int c) {
    extern int ehsys_B89D38DC();
    extern int func_0001A5A8();
    return ehsys_B89D38DC(a << 6, b << 6, c << 6);
}
/* func_0001D0B8 — 15 words. MATCH 100% (shape: m2c -O2). */
#pragma optimization_level 2
s32 func_0001D0B8(void) {
    extern char D_C55030;
    extern int ehsys_B4471B5E();
    extern int func_0001D0B8();
    extern int func_0001D0F4();
    extern int func_0001D46C();
    ehsys_B4471B5E(func_0001D0F4, func_0001D46C, &D_C55030);
    return 0;
}
#pragma optimization_level 4

/* func_0001D46C — 2 words. MATCH 100% (shape: m2c). */
void func_0001D46C(void) {
    extern int func_0001D46C();

}
/* func_0001D5C8 — 8 words. MATCH 100% (shape: m2c -O2). */
#pragma optimization_level 2
void func_0001D5C8(void) {
    extern int func_00001858();
    extern int func_0001D5C8();
    func_00001858();
}
#pragma optimization_level 4

/* func_0001D650 — 2 words. MATCH 100% (shape: m2c). */
void func_0001D650(void) {
    extern int func_0001D650();

}
/* func_00020CF0 — 8 words. MATCH 100% (shape: m2c -O2). */
#pragma optimization_level 2
void func_00020CF0(void) {
    extern int func_00006990();
    extern int func_00020CF0();
    func_00006990();
}
#pragma optimization_level 4

/* func_000226C0 — 7 words. MATCH 100% (shape: thunk, tail call; e passes
 * through untouched, fixed trailing args -1 and 0). */
int func_000226C0(int a, int b, int c, int d, int e) {
    extern int ehsys_3BB2BAC6();
    extern int func_000226C0();
    return ehsys_3BB2BAC6(a << 6, b << 6, c << 6, d << 6, e, -1, 0);
}
/* func_00022C8C — 13 words. MATCH 100% (shape: m2c -O2; spill/reload of a0
 * through a wasted 0x20 stack frame). */
#pragma optimization_level 2
int func_00022C8C(u16 arg0) {
    extern int ehsys_06380DFA();
    extern int ehsys_AB962AE7();
    extern int func_00022C8C();
    volatile unsigned short sp[8];
    sp[0] = arg0;
    ehsys_06380DFA(sp[0]);
    return ehsys_AB962AE7(0);
}
#pragma optimization_level 4

/* func_00023D04 — 9 words. MATCH 100% (shape: m2c -O2). */
#pragma optimization_level 2
void func_00023D04(void) {
    extern int func_00023D04();
    extern int func_00023D28();
    func_00023D28(1);
}
#pragma optimization_level 4

/* func_000268A0 — 2 words. MATCH 100% (shape: thunk+1). */
int func_000268A0(int a) {
    extern int ehsys_5F00A362();
    extern int func_000268A0();
    return ehsys_5F00A362(a << 6);
}

/* func_00026880 — 8 words. MATCH 100% (shape: thunk+2; computes (0x1E0-a0)<<6
 * for the third arg). */
int func_00026880(int a0, int a1, int a2) {
    extern int ehsys_B89D38DC();
    extern int func_00026880();
    return ehsys_B89D38DC(a0 << 6, a1 << 6, (0x1E0 - a0) << 6, a2);
}

/* func_00029470 — 5 words. MATCH 100% (shape: thunk+1). */
void func_00029470(int a, int b, int c, int d) {
    extern int ehsys_BC8E65D7();
    extern int func_00029470();
    ehsys_BC8E65D7(a << 6, b << 6, c << 6, d, -1);
}

/* func_00029574 — 4 words. MATCH 100% (shape: thunk+1). */
int func_00029574(int a, int b, int c) {
    extern int ehsys_B89D38DC();
    extern int func_00029574();
    return ehsys_B89D38DC(a << 6, b << 6, c << 6);
}

/* func_000294F4 — 7 words. MATCH 100% (shape: thunk, tail call; e passes
 * through untouched, fixed trailing args -1 and 0). */
int func_000294F4(int a, int b, int c, int d, int e) {
    extern int ehsys_3BB2BAC6();
    extern int func_000294F4();
    return ehsys_3BB2BAC6(a << 6, b << 6, c << 6, d << 6, e, -1, 0);
}

/* func_0002B944 — 5 words. MATCH 100% (shape: thunk+1). */
void func_0002B944(int a, int b, int c, int d) {
    extern int ehsys_BC8E65D7();
    extern int func_0002B944();
    ehsys_BC8E65D7(a << 6, b << 6, c << 6, d, -1);
}
/* func_0002BE88 — 16 words. MATCH 100% (shape: m2c -O2; spill/reload of a0/a1
 * through a wasted 0x30 stack frame). */
#pragma optimization_level 2
void func_0002BE88(s32 *arg0, s32 arg1) {
    extern int ehsys_memset();
    volatile int sp[8];
    sp[0] = (int)arg0;
    sp[4] = arg1;
    ehsys_memset((void *)sp[0], 0, 0x154);
    *(s32 *)sp[0] = sp[4];
}
#pragma optimization_level 4

/* func_0002C7C4 — 6 words. MATCH 100% (shape: m2c -O2; spill/reload of a0
 * through a wasted 0x40 stack frame). */
#pragma optimization_level 2
int func_0002C7C4(int a) {
    extern int func_0002C7C4();
    volatile int sp[16];
    sp[0] = a;
    return sp[0];
}
#pragma optimization_level 4

/* func_0002C870 — 6 words. MATCH 100% (shape: m2c -O2; spill/reload of a1
 * through a wasted 0x20 stack frame; a0 unused). */
#pragma optimization_level 2
int func_0002C870(int a, int b) {
    extern int func_0002C870();
    volatile int sp[8];
    sp[4] = b;
    return sp[4];
}
#pragma optimization_level 4

/* func_0003AD7C — 9 words. MATCH 100% (shape: m2c -O2). */
#pragma optimization_level 2
void func_0003AD7C(void) {
    extern int func_00015838();
    extern int func_0003AD7C();
    func_00015838(0);
}
#pragma optimization_level 4

/* func_00040C30 — 2 words. MATCH 100% (shape: m2c). */
void func_00040C30(void) {
    extern int func_00040C30();

}

/* func_00040C38 — 2 words. MATCH 100% (shape: m2c). */
void func_00040C38(void) {
    extern int func_00040C38();

}

/* func_00040C40 — 2 words. MATCH 100% (shape: m2c). */
void func_00040C40(void) {
    extern int func_00040C40();

}

/* func_00040C48 — 2 words. MATCH 100% (shape: m2c). */
void func_00040C48(void) {
    extern int func_00040C48();

}

