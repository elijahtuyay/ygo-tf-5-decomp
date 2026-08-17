/*
 * rel_duel_mgr.prx — reconstructed code (matching decompilation)
 *
 * Compiler:     Metrowerks CodeWarrior for PSP — MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,s -sdatathreshold 0
 * Verification: scripts/mwcc_build.sh src/rel_duel_mgr.c
 *               scripts/mwcc_diff.py asm/rel_duel_mgr/text.s build/mwcc/rel_duel_mgr.o
 *
 * Every function below is byte-identical to the shipped module — each was
 * accepted only on a MATCH verdict from scripts/mwcc_diff.py, and the whole
 * file is re-verified after assembly (scripts/assemble_module.py).
 * Functions are in ADDRESS ORDER, which is what the linker needs.
 *
 * Import names are resolved from the module's NID tables and are identical
 * across all 28 modules — see docs/nids/README.md.
 *
 * STATUS: 17 functions matched here. The rest of the module is not
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
extern int duel_draw_35284271();
extern int duel_draw_48A690B3();
extern int duel_draw_A50043BA();
extern int duel_eng_9FBBA3CF();
extern int duel_eng_AFF0389D();
extern int ehsys_1460C6FD();
extern int ehsys_1EC5342B();
extern int ehsys_558B2DCB();
extern int ehsys_5F00A362();
extern int ehsys_6E42DDCD();
extern int ehsys_6F0D36D3();
extern int ehsys_88B6C7F0();
extern int ehsys_97BB99A5();
extern int ehsys_B8770B92();
extern int ehsys_B89D38DC();
extern int ehsys_C859D5FE();
extern int ehsys_E4867425();
extern int ehsys_sceGuFinish();
extern int func_0000663C();
extern int func_0000C054();
extern int func_00010E10();
extern int func_000119AC();
extern int func_00011C08();
extern int func_000126D0();

/* ---- forward declarations ---- */
s32 func_00004B44(void);
s32 func_000065D0(void);
s32 func_0000B144(void);
s32 func_00010DD0(void);
u16 * func_00001DEC(u16 *arg0, u16 *arg1);
void func_00000948(s32 arg0);
void func_0000344C(void);
void func_00004688(void);
void func_00004F98(void);
void func_0000500C(void);
void func_0000BB8C(s32 arg0, s32 arg1);
void func_0000C888(s32 arg0);
void func_00010DC0(s32 arg0, s32 arg1, s32 arg2);
void func_00011814(void);
void func_00011A30(void);
void func_000150EC(s32 arg0);
void func_00016EE8(s32 arg0, s32 arg1, s32 arg2);

/* func_00000948 — 13 words. MATCH 100% (shape: m2c). */
void func_00000948(s32 arg0) {
    if (arg0 != duel_draw_48A690B3()) {
        duel_draw_35284271(arg0);
    }
}

/* func_00001DEC — 4 words. MATCH 100% (shape: m2c). */
u16 *func_00001DEC(u16 *arg0, u16 *arg1) {
    *arg0 = *arg1;
    return arg0;
}

/* func_0000344C — 2 words. MATCH 100% (shape: m2c). */
void func_0000344C(void) {

}

/* func_00004688 — 13 words. MATCH 100% (shape: m2c). */
void func_00004688(void) {
    ehsys_88B6C7F0();
    func_00011A30();
    ehsys_C859D5FE(0x2B80);
    ehsys_C859D5FE(4);
}

/* func_00004B44 — 16 words. MATCH 100% (shape: m2c). */
s32 func_00004B44(void) {
    ehsys_E4867425(0);
    duel_eng_9FBBA3CF();
    duel_draw_A50043BA();
    func_00011C08();
    duel_eng_AFF0389D(1);
    return 1;
}

/* func_00004F98 — 13 words. MATCH 100% (shape: m2c). */
void func_00004F98(void) {
    s32 temp_s0;

    temp_s0 = ehsys_6F0D36D3();
    ehsys_1EC5342B((temp_s0 + ehsys_sceGuFinish()) - 8);
}

/* func_0000500C — 2 words. MATCH 100% (shape: m2c). */
void func_0000500C(void) {

}

/* func_000065D0 — 27 words. MATCH 100% (shape: m2c). */
s32 func_000065D0(void) {
    int sp1C;
    s32 sp18;
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0 = func_0000663C();
    if (temp_v0 != 0) {
        ehsys_B8770B92(temp_v0, &sp1C, &sp18);
        temp_v0_2 = ehsys_558B2DCB(temp_v0);
        if ((sp18 > 0) && (temp_v0_2 >= (sp18 - 1))) {
            return 1;
        }
    }
    return 0;
}

/* func_0000B144 — 28 words. MATCH 100% (shape: m2c). */
s32 func_0000B144(void) {
    int sp1C;
    s32 sp18;
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0 = func_0000C054(1);
    if (temp_v0 != 0) {
        ehsys_B8770B92(temp_v0, &sp1C, &sp18);
        temp_v0_2 = ehsys_558B2DCB(temp_v0);
        if ((sp18 > 0) && (temp_v0_2 >= (sp18 - 1))) {
            return 1;
        }
    }
    return 0;
}

/* func_0000BB8C — 3 words. MATCH 100% (shape: hand). */
void func_0000BB8C(s32 arg0, s32 arg1) {
    ehsys_97BB99A5(arg0, arg1, 0, 0);
}

/* func_0000C888 — 2 words. MATCH 100% (shape: hand). */
void func_0000C888(s32 arg0) {
    ehsys_5F00A362(arg0 << 6);
}

/* func_00010DC0 — 4 words. MATCH 100% (shape: hand). */
void func_00010DC0(s32 arg0, s32 arg1, s32 arg2) {
    ehsys_B89D38DC(arg0 << 6, arg1 << 6, arg2 << 6);
}

/* func_00010DD0 — 16 words. MATCH 100% (shape: m2c). */
s32 func_00010DD0(void) {
    if ((ehsys_1460C6FD() == 0) && (func_00010E10() != 0)) {
        return 1;
    }
    return 0;
}

/* func_00011814 — 9 words. MATCH 100% (shape: m2c). */
void func_00011814(void) {
    func_000126D0();
    func_000119AC();
}

/* func_00011A30 — 9 words. MATCH 100% (shape: m2c). */
void func_00011A30(void) {
    ehsys_6E42DDCD();
    func_00011C08();
}

/* func_000150EC — 2 words. MATCH 100% (shape: hand). */
void func_000150EC(s32 arg0) {
    ehsys_5F00A362(arg0 << 6);
}

/* func_00016EE8 — 4 words. MATCH 100% (shape: hand). */
void func_00016EE8(s32 arg0, s32 arg1, s32 arg2) {
    ehsys_B89D38DC(arg0 << 6, arg1 << 6, arg2 << 6);
}

