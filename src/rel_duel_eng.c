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
/* func_0000EBFC — 2 words. MATCH 100% (shape: hand). */
extern int func_0000EB18();
int func_0000EBFC(int a0, int a1, int a2, int a3) {
    extern int func_0000EB18();
    extern int func_0000EBFC(); return func_0000EB18(0, a1, a2, a3); }
/* func_0000EC0C — 2 words. MATCH 100% (shape: hand). */
extern int func_0000EB18();
/* func_0000EC04 — 2 words. MATCH 100% (shape: hand). */
extern int func_0000EB18();
int func_0000EC04(int a0, int a1, int a2, int a3) {
    extern int func_0000EB18();
    extern int func_0000EC04(); return func_0000EB18(0x1, a1, a2, a3); }

int func_0000EC0C(int a0, int a1, int a2, int a3) {
    extern int func_0000EB18();
    extern int func_0000EC0C(); return func_0000EB18(0x2, a1, a2, a3); }
/* func_0000EC24 — 2 words. MATCH 100% (shape: hand). */
extern int func_0000EB18();
/* func_0000EC14 — 2 words. MATCH 100% (shape: hand). */
extern int func_0000EB18();
int func_0000EC14(int a0, int a1, int a2, int a3) {
    extern int func_0000EB18();
    extern int func_0000EC14(); return func_0000EB18(0x3, a1, a2, a3); }
/* func_0000EC1C — 2 words. MATCH 100% (shape: hand). */
extern int func_0000EB18();
int func_0000EC1C(int a0, int a1, int a2, int a3) {
    extern int func_0000EB18();
    extern int func_0000EC1C(); return func_0000EB18(0x4, a1, a2, a3); }


int func_0000EC24(int a0, int a1, int a2, int a3) {
    extern int func_0000EB18();
    extern int func_0000EC24(); return func_0000EB18(0x5, a1, a2, a3); }




/* func_0000F9C4 — 2 words. MATCH 100% (shape: m2c). */
void func_0000F9C4(void) {
    extern int func_0000F9C4();

}
/* func_0001336C — 2 words. MATCH 100% (shape: hand). */
extern int func_00012D28();
int func_0001336C(int a0, int a1, int a2, int a3, int t0) {
    extern int func_00012D28();
    extern int func_0001336C(); return func_00012D28(0x1, a1, a2, a3, t0); }
/* func_00013374 — 2 words. MATCH 100% (shape: hand). */
extern int func_00012D28();
int func_00013374(int a0, int a1, int a2, int a3, int t0) {
    extern int func_00012D28();
    extern int func_00013374(); return func_00012D28(0, a1, a2, a3, t0); }



/* func_000197DC — 2 words. MATCH 100% (shape: m2c). */
s32 func_000197DC(void) {
    extern int func_000197DC();
    return 1;
}
/* func_0001A350 — 3 words. MATCH 100% (shape: hand). */
extern int func_0001A1A0();
/* func_0001A344 — 3 words. MATCH 100% (shape: hand). */
extern int func_0001A1A0();
int func_0001A344(int a0, int a1, int a2) {
    extern int func_0001A1A0();
    extern int func_0001A344(); return func_0001A1A0(a0, 0x1, 0); }

int func_0001A350(int a0, int a1, int a2) {
    extern int func_0001A1A0();
    extern int func_0001A350(); return func_0001A1A0(a0, 0, 0x1); }
/* func_0001A35C — 3 words. MATCH 100% (shape: hand). */
extern int func_0001A1A0();
int func_0001A35C(int a0, int a1, int a2) {
    extern int func_0001A1A0();
    extern int func_0001A35C(); return func_0001A1A0(a0, 0, 0x2); }



/* func_0001D97C — 2 words. MATCH 100% (shape: m2c). */
s32 func_0001D97C(void) {
    extern int func_0001D97C();
    return 0;
}
/* func_0002C2E8 — 2 words. MATCH 100% (shape: hand). */
extern int func_0002C14C();
/* func_0002C0F0 — 3 words. MATCH 100% (shape: hand). */
extern int func_0002BFC4();
int func_0002C0F0(int a0, int a1, int a2, int a3) {
    extern int func_0002BFC4();
    extern int func_0002C0F0(); return func_0002BFC4((0x1 - a0), a1, a2, a3); }

int func_0002C2E8(int a0, int a1, int a2, int a3) {
    extern int func_0002C14C();
    extern int func_0002C2E8(); return func_0002C14C(a0, a1, 0, a3); }
/* func_0002C5A4 — 2 words. MATCH 100% (shape: hand). */
extern int func_0002C3AC();
/* func_0002C2F0 — 4 words. MATCH 100% (shape: hand). */
extern int func_0002C14C();
int func_0002C2F0(int a0, int a1, int a2, int a3) {
    extern int func_0002C14C();
    extern int func_0002C2F0();
    return func_0002C14C((0x1 - a0), a1, 0, a3);
}

int func_0002C5A4(int a0, int a1, int a2, int a3) {
    extern int func_0002C3AC();
    extern int func_0002C5A4(); return func_0002C3AC(a0, a1, 0xE, a3); }
/* func_0002C76C — 2 words. MATCH 100% (shape: hand). */
extern int func_0002C3AC();
int func_0002C76C(int a0, int a1, int a2, int a3) {
    extern int func_0002C3AC();
    extern int func_0002C76C(); return func_0002C3AC(a0, a1, 0xF, a3); }
/* func_0002C950 — 2 words. MATCH 100% (shape: hand). */
extern int func_0002C77C();
/* func_0002C938 — 2 words. MATCH 100% (shape: hand). */
extern int func_0002C77C();
/* func_0002C774 — 2 words. MATCH 100% (shape: hand). */
extern int func_0002C3AC();
int func_0002C774(int a0, int a1, int a2, int a3) {
    extern int func_0002C3AC();
    extern int func_0002C774(); return func_0002C3AC(a0, a1, 0x10, a3); }

int func_0002C938(int a0, int a1, int a2) {
    extern int func_0002C77C();
    extern int func_0002C938(); return func_0002C77C(a0, a1, 0xE); }
/* func_0002C940 — 4 words. MATCH 100% (shape: hand). */
extern int func_0002C77C();
int func_0002C940(int a0, int a1, int a2) {
    extern int func_0002C77C();
    extern int func_0002C940();
    return func_0002C77C((0x1 - a0), a1, 0xE);
}


int func_0002C950(int a0, int a1, int a2) {
    extern int func_0002C77C();
    extern int func_0002C950(); return func_0002C77C(a0, a1, 0xF); }
/* func_0002E6B4 — 3 words. MATCH 100% (shape: hand). */
extern int func_0002E52C();
/* func_0002E364 — 6 words. MATCH 100% (shape: hand). */
extern int func_0002E1E0();
/* func_0002C958 — 4 words. MATCH 100% (shape: hand). */
extern int func_0002C77C();
int func_0002C958(int a0, int a1, int a2) {
    extern int func_0002C77C();
    extern int func_0002C958();
    return func_0002C77C((0x1 - a0), a1, 0xF);
}

int func_0002E364(int a0, int a1, int a2, int a3, int t0) {
    extern int func_0002E1E0();
    extern int func_0002E364();
    return func_0002E1E0(a1, 0xE, 0x1, 0, 0x1);
}
/* func_0002E3AC — 6 words. MATCH 100% (shape: hand). */
extern int func_0002E1E0();
/* func_0002E37C — 6 words. MATCH 100% (shape: hand). */
extern int func_0002E1E0();
int func_0002E37C(int a0, int a1, int a2, int a3, int t0) {
    extern int func_0002E1E0();
    extern int func_0002E37C();
    return func_0002E1E0(a1, 0xE, 0x1, 0x1, 0x1);
}
/* func_0002E394 — 6 words. MATCH 100% (shape: hand). */
extern int func_0002E1E0();
int func_0002E394(int a0, int a1, int a2, int a3, int t0) {
    extern int func_0002E1E0();
    extern int func_0002E394();
    return func_0002E1E0(a1, 0xF, 0, 0x1, 0x1);
}


int func_0002E3AC(int a0, int a1, int a2, int a3, int t0) {
    extern int func_0002E1E0();
    extern int func_0002E3AC();
    return func_0002E1E0(a1, 0xE, 0x1, 0x1, 0);
}
/* func_0002E3C4 — 6 words. MATCH 100% (shape: hand). */
extern int func_0002E1E0();
int func_0002E3C4(int a0, int a1, int a2, int a3, int t0) {
    extern int func_0002E1E0();
    extern int func_0002E3C4();
    return func_0002E1E0(a1, 0xE, 0x1, 0, 0);
}
/* func_0002E3DC — 6 words. MATCH 100% (shape: hand). */
extern int func_0002E1E0();
int func_0002E3DC(int a0, int a1, int a2, int a3, int t0) {
    extern int func_0002E1E0();
    extern int func_0002E3DC();
    return func_0002E1E0(a1, 0xF, 0, 0x1, 0);
}
/* func_0002E3F4 — 6 words. MATCH 100% (shape: hand). */
extern int func_0002E1E0();
int func_0002E3F4(int a0, int a1, int a2, int a3, int t0) {
    extern int func_0002E1E0();
    extern int func_0002E3F4();
    return func_0002E1E0(a1, 0xB, 0, 0, 0);
}





int func_0002E6B4(int a0, int a1, int a2, int a3) {
    extern int func_0002E52C();
    extern int func_0002E6B4(); return func_0002E52C(a0, a1, 0xF, 0); }
/* func_0002E6C0 — 4 words. MATCH 100% (shape: hand). */
extern int func_0002E52C();
int func_0002E6C0(int a0, int a1, int a2, int a3) {
    extern int func_0002E52C();
    extern int func_0002E6C0();
    return func_0002E52C(a0, a1, 0xE, 0x10002);
}







/* func_00031424 — 2 words. MATCH 100% (shape: m2c). */
s32 func_00031424(void) {
    extern int func_00031424();
    return 1;
}
/* func_0003349C — 3 words. MATCH 100% (shape: hand). */
extern int func_00033320();
int func_0003349C(int a0, int a1, int a2, int a3) {
    extern int func_00033320();
    extern int func_0003349C(); return func_00033320((0x1 - a0), a1, a2, a3); }


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
/* func_0003CB10 — 2 words. MATCH 100% (shape: hand). */
extern int func_0003B4A0();
/* func_00038FAC — 2 words. MATCH 100% (shape: hand). */
extern int func_00035FB0();
int func_00038FAC(int a0, int a1, int a2, int a3, int t0, int t1, int t2, int t3) {
    extern int func_00035FB0();
    extern int func_00038FAC(); return func_00035FB0(a0, 0, a2, a3, t0, t1, t2, t3); }

int func_0003CB10(int a0, int a1, int a2, int a3, int t0) {
    extern int func_0003B4A0();
    extern int func_0003CB10(); return func_0003B4A0(a0, 0, a2, a3, t0); }


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
/* func_0005F33C — 2 words. MATCH 100% (shape: hand). */
extern int func_0005F344();
/* func_0005BF28 — 2 words. MATCH 100% (shape: hand). */
extern int func_0005BF30();
/* func_000452BC — 3 words. MATCH 100% (shape: hand). */
extern int func_00045388();
int func_000452BC(int a0, int a1, int a2, int a3) {
    extern int func_000452BC();
    extern int func_00045388(); return func_00045388(a0, a1, 0x1, 0); }
/* func_0005AA80 — 3 words. MATCH 100% (shape: hand). */
extern int func_0005A860();
int func_0005AA80(int a0, int a1, int a2, int a3, int t0) {
    extern int func_0005A860();
    extern int func_0005AA80(); return func_0005A860(a0, a1, a2, 0x2, a3); }


int func_0005BF28(int a0, int a1, int a2, int a3) {
    extern int func_0005BF28();
    extern int func_0005BF30(); return func_0005BF30(a0, a1, a2, 0xA); }

int func_0005F33C(int a0, int a1, int a2, int a3) {
    extern int func_0005F33C();
    extern int func_0005F344(); return func_0005F344(*(unsigned short *)((char *)a0 + 0x2), a1, a2, a3); }
/* func_00060078 — 3 words. MATCH 100% (shape: hand). */
extern int func_00060084();
/* func_0005FAD4 — 4 words. MATCH 100% (shape: hand). */
extern int func_0005F51C();
int func_0005FAD4(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_0005F51C();
    extern int func_0005FAD4();
    return func_0005F51C(a0, a1, a2, 0xF, 0, 0);
}

int func_00060078(int a0, int a1, int a2, int a3) {
    extern int func_00060078();
    extern int func_00060084(); return func_00060084(a0, a1, (a2 != 0), a2); }



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
/* func_000603B4 — 2 words. MATCH 100% (shape: hand). */
extern int func_000603BC();
int func_000603B4(int a0, int a1, int a2, int a3) {
    extern int func_000603B4();
    extern int func_000603BC(); return func_000603BC(a0, a1, 0x1, a3); }
/* func_0007A0B0 — 2 words. MATCH 100% (shape: hand). */
extern int func_0007A0B8();
/* func_00074C4C — 2 words. MATCH 100% (shape: hand). */
extern int func_00074ADC();
/* func_00072420 — 3 words. MATCH 100% (shape: hand). */
extern int func_000715A8();
int func_00072420(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000715A8();
    extern int func_00072420(); return func_000715A8(a0, a1, 0x1, 0, t0); }
/* func_00073B90 — 6 words. MATCH 100% (shape: hand). */
extern int func_00073548();
/* func_00073B78 — 6 words. MATCH 100% (shape: hand). */
extern int func_00073548();
int func_00073B78(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_00073548();
    extern int func_00073B78();
    return func_00073548(a0, a1, 0, a2, a3, t0);
}

int func_00073B90(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_00073548();
    extern int func_00073B90();
    return func_00073548(a0, a1, 0x1, a2, a3, t0);
}
/* func_00073BA8 — 5 words. MATCH 100% (shape: hand). */
extern int func_00073254();
int func_00073BA8(int a0, int a1, int a2, int a3, int t0) {
    extern int func_00073254();
    extern int func_00073BA8();
    return func_00073254(a0, 0, a1, (a3 != 0), a2);
}
/* func_00073BBC — 5 words. MATCH 100% (shape: hand). */
extern int func_00073254();
int func_00073BBC(int a0, int a1, int a2, int a3, int t0) {
    extern int func_00073254();
    extern int func_00073BBC();
    return func_00073254(a0, 0, a1, 0, 0);
}
/* func_00073BD0 — 4 words. MATCH 100% (shape: hand). */
extern int func_00073254();
int func_00073BD0(int a0, int a1, int a2, int a3, int t0) {
    extern int func_00073254();
    extern int func_00073BD0();
    return func_00073254(a0, 0x1, a1, a3, a2);
}
/* func_00074230 — 6 words. MATCH 100% (shape: hand). */
extern int func_0005BA60();
/* func_00074000 — 8 words. MATCH 100% (shape: hand). */
extern int func_00073D98();
int func_00074000(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_00073D98();
    extern int func_00074000();
    return func_00073D98(a0, 0xB, a1, a2, a3, t0);
}

int func_00074230(int a0, int a1, int a2, int a3, int t0) {
    extern int func_0005BA60();
    extern int func_00074230();
    return func_0005BA60(a0, 0xB, a1, a2, a3);
}






int func_00074C4C(int a0, int a1, int a2, int a3, int t0) {
    extern int func_00074ADC();
    extern int func_00074C4C(); return func_00074ADC(a0, 0x1, a2, a3, t0); }
/* func_00079C18 — 2 words. MATCH 100% (shape: hand). */
extern int func_00079C20();
int func_00079C18(int a0, int a1, int a2, int a3) {
    extern int func_00079C18();
    extern int func_00079C20(); return func_00079C20(a0, a1, 0, a3); }


int func_0007A0B0(int a0, int a1, int a2, int a3) {
    extern int func_0007A0B0();
    extern int func_0007A0B8(); return func_0007A0B8(a0, a1, 0, a3); }



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
/* func_00089A94 — 2 words. MATCH 100% (shape: hand). */
extern int func_00089A9C();
int func_00089A94(int a0, int a1, int a2) {
    extern int func_00089A94();
    extern int func_00089A9C(); return func_00089A9C(a0, a1, -0x1); }
/* func_0008A8A8 — 2 words. MATCH 100% (shape: hand). */
extern int func_0008A650();
int func_0008A8A8(int a0, int a1, int a2) {
    extern int func_0008A650();
    extern int func_0008A8A8(); return func_0008A650(a0, a1, 0x1); }
/* func_0008AC78 — 2 words. MATCH 100% (shape: hand). */
extern int func_0008AB14();
int func_0008AC78(int a0, int a1, int a2) {
    extern int func_0008AB14();
    extern int func_0008AC78(); return func_0008AB14(a0, a1, -0x1); }




/* func_0008AC80 — 18 words. MATCH 100% (shape: m2c). */
s32 func_0008AC80(s32 arg0) {
    extern int func_0008AB14();
    extern int func_0008AC80();
    s32 temp_s0;

    temp_s0 = func_0008AB14(0, arg0, -1);
    return temp_s0 + func_0008AB14(1, arg0, -1);
}
/* func_0008C79C — 2 words. MATCH 100% (shape: hand). */
extern int func_0008C7A4();
/* func_0008BE60 — 3 words. MATCH 100% (shape: hand). */
extern int func_0008BEBC();
int func_0008BE60(int a0, int a1, int a2, int a3) {
    extern int func_0008BE60();
    extern int func_0008BEBC(); return func_0008BEBC(a0, a1, -0x1, 0x1); }

int func_0008C79C(int a0, int a1, int a2) {
    extern int func_0008C79C();
    extern int func_0008C7A4(); return func_0008C7A4(a0, a1, 0x1); }
/* func_0008CFC4 — 2 words. MATCH 100% (shape: hand). */
extern int func_0008CCB0();
int func_0008CFC4(int a0, int a1, int a2) {
    extern int func_0008CCB0();
    extern int func_0008CFC4(); return func_0008CCB0(a0, 0, a2); }
/* func_0008CFCC — 2 words. MATCH 100% (shape: hand). */
extern int func_0008CCB0();
int func_0008CFCC(int a0, int a1, int a2) {
    extern int func_0008CCB0();
    extern int func_0008CFCC(); return func_0008CCB0(a0, 0x20000, a2); }
/* func_0008DEEC — 2 words. MATCH 100% (shape: hand). */
extern int func_0008D184();
int func_0008DEEC(int a0, int a1, int a2, int a3) {
    extern int func_0008D184();
    extern int func_0008DEEC(); return func_0008D184(a0, a1, a2, 0x1); }
/* func_0008DEFC — 2 words. MATCH 100% (shape: hand). */
extern int func_0008D184();
/* func_0008DEF4 — 2 words. MATCH 100% (shape: hand). */
extern int func_0008D184();
int func_0008DEF4(int a0, int a1, int a2, int a3) {
    extern int func_0008D184();
    extern int func_0008DEF4(); return func_0008D184(a0, a1, a2, 0); }

int func_0008DEFC(int a0, int a1, int a2, int a3) {
    extern int func_0008D184();
    extern int func_0008DEFC(); return func_0008D184(a0, a1, a2, 0x2); }
/* func_0008E6B4 — 4 words. MATCH 100% (shape: hand). */
extern int func_0008E6C4();
int func_0008E6B4(int a0, int a1, int a2, int a3) {
    extern int func_0008E6B4();
    extern int func_0008E6C4();
    return func_0008E6C4(a0, 0, 0, 0x1);
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
/* func_00092B10 — 2 words. MATCH 100% (shape: hand). */
extern int func_00091F64();
int func_00092B10(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_00091F64();
    extern int func_00092B10(); return func_00091F64(a0, a1, a2, a3, t0, 0); }
/* func_0009321C — 2 words. MATCH 100% (shape: hand). */
extern int func_00092EAC();
/* func_00092B18 — 3 words. MATCH 100% (shape: hand). */
extern int func_00091F64();
int func_00092B18(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_00091F64();
    extern int func_00092B18(); return func_00091F64(a0, a1, a2, a3, 0, 0); }

int func_0009321C(int a0, int a1, int a2) {
    extern int func_00092EAC();
    extern int func_0009321C(); return func_00092EAC(a0, a1, 0xE); }
/* func_0009322C — 2 words. MATCH 100% (shape: hand). */
extern int func_00092EAC();
/* func_00093224 — 2 words. MATCH 100% (shape: hand). */
extern int func_00092EAC();
int func_00093224(int a0, int a1, int a2) {
    extern int func_00092EAC();
    extern int func_00093224(); return func_00092EAC(a0, a1, 0xB); }

int func_0009322C(int a0, int a1, int a2) {
    extern int func_00092EAC();
    extern int func_0009322C(); return func_00092EAC(a0, a1, 0xD); }
/* func_00094F28 — 2 words. MATCH 100% (shape: hand). */
extern int func_00094F30();
int func_00094F28(int a0, int a1, int a2) {
    extern int func_00094F28();
    extern int func_00094F30(); return func_00094F30(a0, a1, -0x1); }





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
/* func_0009F6F8 — 2 words. MATCH 100% (shape: hand). */
extern int func_0009F700();
/* func_000996F0 — 3 words. MATCH 100% (shape: hand). */
extern int func_000996FC();
/* func_00098B58 — 3 words. MATCH 100% (shape: hand). */
extern int func_00098B64();
int func_00098B58(int a0, int a1, int a2, int a3, int t0) {
    extern int func_00098B58();
    extern int func_00098B64(); return func_00098B64(a0, a1, a2, 0, 0); }

int func_000996F0(int a0, int a1, int a2, int a3, int t0, int t1, int t2, int t3) {
    extern int func_000996F0();
    extern int func_000996FC(); return func_000996FC(a0, a1, a2, 0, 0, t1, t2, t3); }

int func_0009F6F8(int a0, int a1, int a2) {
    extern int func_0009F6F8();
    extern int func_0009F700(); return func_0009F700(a0, a1, 0); }
/* func_000A0820 — 2 words. MATCH 100% (shape: hand). */
extern int func_000A019C();
int func_000A0820(int a0, int a1, int a2, int a3) {
    extern int func_000A019C();
    extern int func_000A0820(); return func_000A019C(a0, a1, -0x1, a3); }
/* func_000A1104 — 2 words. MATCH 100% (shape: hand). */
extern int func_000A0A8C();
int func_000A1104(int a0, int a1, int a2) {
    extern int func_000A0A8C();
    extern int func_000A1104(); return func_000A0A8C(a0, a1, 0); }




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
/* func_000A2464 — 3 words. MATCH 100% (shape: hand). */
extern int func_000A1A78();
int func_000A2464(int a0, int a1, int a2, int a3) {
    extern int func_000A1A78();
    extern int func_000A2464(); return func_000A1A78(a0, 0x2, 0, a3); }
/* func_000A258C — 3 words. MATCH 100% (shape: hand). */
extern int func_000A1A78();
/* func_000A2580 — 3 words. MATCH 100% (shape: hand). */
extern int func_000A1A78();
int func_000A2580(int a0, int a1, int a2, int a3) {
    extern int func_000A1A78();
    extern int func_000A2580(); return func_000A1A78(a0, 0x1, 0, a3); }

int func_000A258C(int a0, int a1, int a2, int a3) {
    extern int func_000A1A78();
    extern int func_000A258C(); return func_000A1A78(a0, 0x4, 0, a3); }
/* func_000A25FC — 3 words. MATCH 100% (shape: hand). */
extern int func_000A1A78();
/* func_000A25F0 — 3 words. MATCH 100% (shape: hand). */
extern int func_000A1A78();
int func_000A25F0(int a0, int a1, int a2, int a3) {
    extern int func_000A1A78();
    extern int func_000A25F0(); return func_000A1A78(a0, 0x8, a1, a3); }

int func_000A25FC(int a0, int a1, int a2, int a3) {
    extern int func_000A1A78();
    extern int func_000A25FC(); return func_000A1A78(a0, 0x8, 0, a3); }
/* func_000A262C — 3 words. MATCH 100% (shape: hand). */
extern int func_000A1A78();
int func_000A262C(int a0, int a1, int a2, int a3) {
    extern int func_000A1A78();
    extern int func_000A262C(); return func_000A1A78(a0, 0x18, 0, a3); }





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
/* func_000A3CB4 — 2 words. MATCH 100% (shape: hand). */
extern int func_000A3CBC();
/* func_000A2F70 — 3 words. MATCH 100% (shape: hand). */
extern int func_000A2F7C();
int func_000A2F70(int a0, int a1, int a2, int a3) {
    extern int func_000A2F70();
    extern int func_000A2F7C(); return func_000A2F7C(a0, a1, 0, 0); }
/* func_000A325C — 7 words. MATCH 100% (shape: hand). */
extern int func_000A3278();
int func_000A325C(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_000A325C();
    extern int func_000A3278();
    return func_000A3278(a0, a0, a1, a2, a3, 0x1);
}


int func_000A3CB4(int a0, int a1, int a2) {
    extern int func_000A3CB4();
    extern int func_000A3CBC(); return func_000A3CBC(a0, a1, 0); }


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
/* func_000A59CC — 5 words. MATCH 100% (shape: hand). */
extern int func_000A50E4();
int func_000A59CC(int a0, int a1, int a2, int a3) {
    extern int func_000A50E4();
    extern int func_000A59CC();
    return func_000A50E4(0, a0, a1, 0);
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
/* func_000AEED8 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000AECC0 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000AECB4 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000AECB4(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000AECB4(); return func_000ACAC8(a0, a1, a2, 0x21050, t0); }

int func_000AECC0(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000AECC0(); return func_000ACAC8(a0, a1, a2, 0x10516, t0); }

int func_000AEED8(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000AEED8(); return func_000ACAC8(a0, a1, a2, 0x4059, t0); }
/* func_000AF00C — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000AF00C(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000AF00C(); return func_000ACAC8(a0, a1, a2, 0x1011, t0); }
/* func_000AF234 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000AF234(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000AF234(); return func_000ACAC8(a0, a1, a2, 0x1430, t0); }
/* func_000AF2A4 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000AF298 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000AF298(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000AF298(); return func_000ACAC8(a0, a1, a2, 0x80412, t0); }

int func_000AF2A4(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000AF2A4(); return func_000ACAC8(a0, a1, a2, 0x1412, t0); }
/* func_000AF2B8 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000AF2AC — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000AF2AC(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000AF2AC(); return func_000ACAC8(a0, a1, a2, 0x40512, t0); }

int func_000AF2B8(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000AF2B8(); return func_000ACAC8(a0, a1, a2, 0x1010, t0); }
/* func_000AF2C0 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000AF2C0(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000AF2C0(); return func_000ACAC8(a0, a1, a2, 0x1810, t0); }
/* func_000AF2C8 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000AF2C8(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000AF2C8(); return func_000ACAC8(a0, a1, a2, 0x1012, t0); }
/* func_000AF2D0 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000AF2D0(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000AF2D0(); return func_000ACAC8(a0, a1, a2, 0x1812, t0); }
/* func_000AF2D8 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000AF2D8(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000AF2D8(); return func_000ACAC8(a0, a1, a2, 0x1A, t0); }
/* func_000AF2E0 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000AF2E0(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000AF2E0(); return func_000ACAC8(a0, a1, a2, 0xC12, t0); }
/* func_000AF8DC — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000AF360 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000AF360(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000AF360(); return func_000ACAC8(a0, a1, a2, 0x21420, t0); }

int func_000AF8DC(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000AF8DC(); return func_000ACAC8(a0, a1, a2, 0x1410, t0); }
/* func_000AF8F0 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000AF8E4 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000AF8E4(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000AF8E4(); return func_000ACAC8(a0, a1, a2, 0x80410, t0); }

int func_000AF8F0(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000AF8F0(); return func_000ACAC8(a0, a1, a2, 0x47A, t0); }
/* func_000AF94C — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000AF94C(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000AF94C(); return func_000ACAC8(a0, a1, a2, 0x1448, t0); }
/* func_000B15C4 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B15C4(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B15C4(); return func_000ACAC8(a0, a1, a2, 0xC16, t0); }
/* func_000B15CC — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B15CC(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B15CC(); return func_000ACAC8(a0, a1, a2, 0x1042, t0); }
/* func_000B15D4 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B15D4(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B15D4(); return func_000ACAC8(a0, a1, a2, 0x1842, t0); }
/* func_000B15DC — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B15DC(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B15DC(); return func_000ACAC8(a0, a1, a2, 0x1518, t0); }
/* func_000B1658 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B1658(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B1658(); return func_000ACAC8(a0, a1, a2, 0xC10, t0); }
/* func_000B2C64 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000B2C24 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000B1744 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B1744(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B1744(); return func_000ACAC8(a0, a1, a2, 0x40414, t0); }
/* func_000B1750 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B1750(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B1750(); return func_000ACAC8(a0, a1, a2, 0x21011, t0); }


int func_000B2C24(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B2C24(); return func_000ACAC8(a0, a1, a2, 0x16, t0); }

int func_000B2C64(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B2C64(); return func_000ACAC8(a0, a1, a2, 0x1112, t0); }
/* func_000B2F34 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B2F34(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B2F34(); return func_000ACAC8(a0, a1, a2, 0x1434, t0); }
/* func_000B2F3C — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B2F3C(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B2F3C(); return func_000ACAC8(a0, a1, a2, 0x414, t0); }
/* func_000B2F5C — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000B2F44 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B2F44(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B2F44(); return func_000ACAC8(a0, a1, a2, 0x10412, t0); }
/* func_000B2F50 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B2F50(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B2F50(); return func_000ACAC8(a0, a1, a2, 0x40496, t0); }


int func_000B2F5C(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B2F5C(); return func_000ACAC8(a0, a1, a2, 0x78, t0); }
/* func_000B2F64 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B2F64(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B2F64(); return func_000ACAC8(a0, a1, a2, 0x1092, t0); }
/* func_000B3344 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000B2F6C — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B2F6C(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B2F6C(); return func_000ACAC8(a0, a1, a2, 0x21040, t0); }
/* func_000B2F78 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B2F78(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B2F78(); return func_000ACAC8(a0, a1, a2, 0x40010, t0); }
/* func_000B2F84 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B2F84(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B2F84(); return func_000ACAC8(a0, a1, a2, 0x21070, t0); }
/* func_000B3228 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B3228(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B3228(); return func_000ACAC8(a0, a1, a2, 0x21440, t0); }
/* func_000B3234 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B3234(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B3234(); return func_000ACAC8(a0, a1, a2, 0xa0040, t0); }
/* func_000B3240 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B3240(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B3240(); return func_000ACAC8(a0, a1, a2, 0x80010, t0); }






int func_000B3344(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B3344(); return func_000ACAC8(a0, a1, a2, 0x3418, t0); }
/* func_000B3358 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000B334C — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B334C(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B334C(); return func_000ACAC8(a0, a1, a2, 0x23448, t0); }

int func_000B3358(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B3358(); return func_000ACAC8(a0, a1, a2, 0x1442, t0); }
/* func_000B33E4 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000B33D8 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B33D8(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B33D8(); return func_000ACAC8(a0, a1, a2, 0x40016, t0); }

int func_000B33E4(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B33E4(); return func_000ACAC8(a0, a1, a2, 0x1414, t0); }
/* func_000B33EC — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B33EC(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B33EC(); return func_000ACAC8(a0, a1, a2, 0xC14, t0); }
/* func_000B4C50 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000B3AE8 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B3AE8(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B3AE8(); return func_000ACAC8(a0, a1, a2, 0x20424, t0); }

int func_000B4C50(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B4C50(); return func_000ACAC8(a0, a1, a2, 0x2411, t0); }
/* func_000B4D48 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B4D48(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B4D48(); return func_000ACAC8(a0, a1, a2, 0x11A, t0); }
/* func_000B5068 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000B4F64 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B4F64(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B4F64(); return func_000ACAC8(a0, a1, a2, 0x10010, t0); }

int func_000B5068(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B5068(); return func_000ACAC8(a0, a1, a2, 0x1016, t0); }
/* func_000B6054 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000B6048 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000B5FCC — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B5FCC(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B5FCC(); return func_000ACAC8(a0, a1, a2, 0x80442, t0); }

int func_000B6048(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B6048(); return func_000ACAC8(a0, a1, a2, 0x40416, t0); }

int func_000B6054(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B6054(); return func_000ACAC8(a0, a1, a2, 0x440, t0); }
/* func_000B61D0 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000B61C4 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B61C4(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B61C4(); return func_000ACAC8(a0, a1, a2, 0x20438, t0); }

int func_000B61D0(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B61D0(); return func_000ACAC8(a0, a1, a2, 0x1026, t0); }
/* func_000B76BC — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000B7630 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B7630(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B7630(); return func_000ACAC8(a0, a1, a2, 0x21410, t0); }
/* func_000B76B0 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B76B0(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B76B0(); return func_000ACAC8(a0, a1, a2, 0x24041, t0); }


int func_000B76BC(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B76BC(); return func_000ACAC8(a0, a1, a2, 0x1096, t0); }
/* func_000B76D0 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000B76C4 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B76C4(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B76C4(); return func_000ACAC8(a0, a1, a2, 0x20425, t0); }

int func_000B76D0(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B76D0(); return func_000ACAC8(a0, a1, a2, 0x1470, t0); }
/* func_000B7934 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B7934(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B7934(); return func_000ACAC8(a0, a1, a2, 0x811, t0); }
/* func_000B7948 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000B793C — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B793C(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B793C(); return func_000ACAC8(a0, a1, a2, 0x21014, t0); }

int func_000B7948(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B7948(); return func_000ACAC8(a0, a1, a2, 0x12, t0); }
/* func_000B7950 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B7950(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B7950(); return func_000ACAC8(a0, a1, a2, 0x4A, t0); }
/* func_000B79B8 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000B7964 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000B7958 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B7958(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B7958(); return func_000ACAC8(a0, a1, a2, 0x40418, t0); }

int func_000B7964(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B7964(); return func_000ACAC8(a0, a1, a2, 0x411, t0); }
/* func_000B79AC — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B79AC(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B79AC(); return func_000ACAC8(a0, a1, a2, 0x21470, t0); }


int func_000B79B8(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B79B8(); return func_000ACAC8(a0, a1, a2, 0x1446, t0); }
/* func_000B79C0 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B79C0(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B79C0(); return func_000ACAC8(a0, a1, a2, 0x1472, t0); }
/* func_000B79D4 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000B79C8 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B79C8(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B79C8(); return func_000ACAC8(a0, a1, a2, 0x22415, t0); }

int func_000B79D4(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B79D4(); return func_000ACAC8(a0, a1, a2, 0x1444, t0); }
/* func_000B7E90 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B7E90(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B7E90(); return func_000ACAC8(a0, a1, a2, 0x144A, t0); }
/* func_000B7E98 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B7E98(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B7E98(); return func_000ACAC8(a0, a1, a2, 0x141A, t0); }
/* func_000B7EA0 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B7EA0(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B7EA0(); return func_000ACAC8(a0, a1, a2, 0x416, t0); }
/* func_000B8294 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000B820C — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B820C(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B820C(); return func_000ACAC8(a0, a1, a2, 0x80470, t0); }

int func_000B8294(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B8294(); return func_000ACAC8(a0, a1, a2, 0x2410, t0); }
/* func_000B8318 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000B8300 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B8300(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B8300(); return func_000ACAC8(a0, a1, a2, 0x100412, t0); }
/* func_000B830C — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B830C(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B830C(); return func_000ACAC8(a0, a1, a2, 0x21010, t0); }


int func_000B8318(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B8318(); return func_000ACAC8(a0, a1, a2, 0x4011, t0); }
/* func_000B83A4 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000B8398 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B8398(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B8398(); return func_000ACAC8(a0, a1, a2, 0x80472, t0); }

int func_000B83A4(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B83A4(); return func_000ACAC8(a0, a1, a2, 0x2414, t0); }
/* func_000B83AC — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B83AC(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B83AC(); return func_000ACAC8(a0, a1, a2, 0x1072, t0); }
/* func_000B83B4 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B83B4(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B83B4(); return func_000ACAC8(a0, a1, a2, 0x1011, t0); }
/* func_000B8640 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000B83BC — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B83BC(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B83BC(); return func_000ACAC8(a0, a1, a2, 0x20801, t0); }

int func_000B8640(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B8640(); return func_000ACAC8(a0, a1, a2, 0x2112, t0); }
/* func_000B8648 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B8648(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B8648(); return func_000ACAC8(a0, a1, a2, 0x415, t0); }
/* func_000B8650 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B8650(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B8650(); return func_000ACAC8(a0, a1, a2, 0x70, t0); }
/* func_000B8BBC — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000B8830 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B8830(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B8830(); return func_000ACAC8(a0, a1, a2, 0x21041, t0); }

int func_000B8BBC(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B8BBC(); return func_000ACAC8(a0, a1, a2, 0x42, t0); }
/* func_000B8C98 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B8C98(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B8C98(); return func_000ACAC8(a0, a1, a2, 0x872, t0); }
/* func_000B8CA0 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B8CA0(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B8CA0(); return func_000ACAC8(a0, a1, a2, 0x1510, t0); }
/* func_000B9F38 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000B9400 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B9400(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B9400(); return func_000ACAC8(a0, a1, a2, 0x23070, t0); }

int func_000B9F38(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B9F38(); return func_000ACAC8(a0, a1, a2, 0x1440, t0); }
/* func_000BA014 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000B9F40 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000B9F40(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000B9F40(); return func_000ACAC8(a0, a1, a2, 0x100410, t0); }
/* func_000BA008 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000BA008(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BA008(); return func_000ACAC8(a0, a1, a2, 0x20448, t0); }


int func_000BA014(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BA014(); return func_000ACAC8(a0, a1, a2, 0x7A, t0); }
/* func_000BA658 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000BA440 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000BA1DC — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000BA1DC(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BA1DC(); return func_000ACAC8(a0, a1, a2, 0x20013, t0); }
/* func_000BA1E8 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000BA1E8(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BA1E8(); return func_000ACAC8(a0, a1, a2, 0x21478, t0); }
/* func_000BA434 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000BA434(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BA434(); return func_000ACAC8(a0, a1, a2, 0x100472, t0); }



int func_000BA440(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BA440(); return func_000ACAC8(a0, a1, a2, 0x1411, t0); }

int func_000BA658(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BA658(); return func_000ACAC8(a0, a1, a2, 0x119, t0); }
/* func_000BA660 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000BA660(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BA660(); return func_000ACAC8(a0, a1, a2, 0xC11, t0); }
/* func_000BACD0 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000BA6E8 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000BA6E8(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BA6E8(); return func_000ACAC8(a0, a1, a2, 0x21040, t0); }
/* func_000BA7DC — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000BA7DC(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BA7DC(); return func_000ACAC8(a0, a1, a2, 0x20070, t0); }


int func_000BACD0(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BACD0(); return func_000ACAC8(a0, a1, a2, 0x3411, t0); }
/* func_000BAF48 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000BAED4 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000BAED4(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BAED4(); return func_000ACAC8(a0, a1, a2, 0x40412, t0); }

int func_000BAF48(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BAF48(); return func_000ACAC8(a0, a1, a2, 0x2402, t0); }
/* func_000BB944 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000BB944(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BB944(); return func_000ACAC8(a0, a1, a2, 0x2416, t0); }
/* func_000BB94C — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000BB94C(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BB94C(); return func_000ACAC8(a0, a1, a2, 0x2412, t0); }
/* func_000BBB5C — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000BBB5C(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BBB5C(); return func_000ACAC8(a0, a1, a2, 0x1496, t0); }
/* func_000BBB64 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000BBB64(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BBB64(); return func_000ACAC8(a0, a1, a2, 0x1024, t0); }
/* func_000BBB6C — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000BBB6C(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BBB6C(); return func_000ACAC8(a0, a1, a2, 0x410, t0); }
/* func_000BBB74 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000BBB74(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BBB74(); return func_000ACAC8(a0, a1, a2, 0x1872, t0); }
/* func_000BC00C — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000BBB7C — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000BBB7C(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BBB7C(); return func_000ACAC8(a0, a1, a2, 0x21044, t0); }
/* func_000BBB88 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000BBB88(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BBB88(); return func_000ACAC8(a0, a1, a2, 0x20001, t0); }
/* func_000BBB94 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000BBB94(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BBB94(); return func_000ACAC8(a0, a1, a2, 0x40090, t0); }



int func_000BC00C(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BC00C(); return func_000ACAC8(a0, a1, a2, 0x1001, t0); }
/* func_000BCDC0 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000BC70C — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000BC70C(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BC70C(); return func_000ACAC8(a0, a1, a2, 0x1052, t0); }

int func_000BCDC0(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BCDC0(); return func_000ACAC8(a0, a1, a2, 0x1406, t0); }
/* func_000BCDC8 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000BCDC8(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BCDC8(); return func_000ACAC8(a0, a1, a2, 0x816, t0); }
/* func_000BCDDC — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000BCDD0 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000BCDD0(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BCDD0(); return func_000ACAC8(a0, a1, a2, 0x21444, t0); }

int func_000BCDDC(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BCDDC(); return func_000ACAC8(a0, a1, a2, 0x1416, t0); }
/* func_000BCDEC — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000BCDE4 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000BCDE4(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BCDE4(); return func_000ACAC8(a0, a1, a2, 0x412, t0); }

int func_000BCDEC(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BCDEC(); return func_000ACAC8(a0, a1, a2, 0x2040, t0); }
/* func_000BD1FC — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000BD1FC(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BD1FC(); return func_000ACAC8(a0, a1, a2, 0x1070, t0); }
/* func_000BD644 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000BD2D0 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000BD2D0(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BD2D0(); return func_000ACAC8(a0, a1, a2, 0x100470, t0); }

int func_000BD644(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BD644(); return func_000ACAC8(a0, a1, a2, 0x1452, t0); }
/* func_000BDC84 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000BD718 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000BD718(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BD718(); return func_000ACAC8(a0, a1, a2, 0x80452, t0); }
/* func_000BD9B8 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000BD9B8(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BD9B8(); return func_000ACAC8(a0, a1, a2, 0x100070, t0); }
/* func_000BD9C4 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000BD9C4(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BD9C4(); return func_000ACAC8(a0, a1, a2, 0x80070, t0); }
/* func_000BDBC8 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000BDBC8(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BDBC8(); return func_000ACAC8(a0, a1, a2, 0x100418, t0); }




int func_000BDC84(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BDC84(); return func_000ACAC8(a0, a1, a2, 0x15, t0); }
/* func_000BDC8C — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000BDC8C(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BDC8C(); return func_000ACAC8(a0, a1, a2, 0x1492, t0); }
/* func_000BDE24 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000BDDB4 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000BDDB4(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BDDB4(); return func_000ACAC8(a0, a1, a2, 0x40112, t0); }

int func_000BDE24(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BDE24(); return func_000ACAC8(a0, a1, a2, 0x814, t0); }
/* func_000BDE8C — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000BDE8C(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BDE8C(); return func_000ACAC8(a0, a1, a2, 0x11, t0); }
/* func_000BDE94 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000BDE94(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BDE94(); return func_000ACAC8(a0, a1, a2, 0x1871, t0); }
/* func_000BDF1C — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000BDF1C(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BDF1C(); return func_000ACAC8(a0, a1, a2, 0x1408, t0); }
/* func_000BE0A8 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000BE0A8(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BE0A8(); return func_000ACAC8(a0, a1, a2, 0x104A, t0); }
/* func_000BE484 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000BE0B0 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000BE0B0(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BE0B0(); return func_000ACAC8(a0, a1, a2, 0x20051, t0); }

int func_000BE484(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BE484(); return func_000ACAC8(a0, a1, a2, 0x1458, t0); }
/* func_000BE604 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000BE508 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000BE508(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BE508(); return func_000ACAC8(a0, a1, a2, 0x2470, t0); }
/* func_000BE51C — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000BE510 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000BE510(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BE510(); return func_000ACAC8(a0, a1, a2, 0x28011, t0); }

int func_000BE51C(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BE51C(); return func_000ACAC8(a0, a1, a2, 0x40510, t0); }


int func_000BE604(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BE604(); return func_000ACAC8(a0, a1, a2, 0x1441, t0); }
/* func_000BE814 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000BE60C — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000BE60C(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BE60C(); return func_000ACAC8(a0, a1, a2, 0x24001, t0); }

int func_000BE814(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BE814(); return func_000ACAC8(a0, a1, a2, 0xC70, t0); }
/* func_000BE81C — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000BE81C(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BE81C(); return func_000ACAC8(a0, a1, a2, 0x101A, t0); }
/* func_000BFB18 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000BF664 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000BF664(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BF664(); return func_000ACAC8(a0, a1, a2, 0x80012, t0); }
/* func_000BF670 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000BF670(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BF670(); return func_000ACAC8(a0, a1, a2, 0x80044, t0); }
/* func_000BF67C — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000BF67C(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BF67C(); return func_000ACAC8(a0, a1, a2, 0x4051a, t0); }
/* func_000BF688 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000BF688(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BF688(); return func_000ACAC8(a0, a1, a2, 0x1051a, t0); }
/* func_000BF694 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000BF694(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BF694(); return func_000ACAC8(a0, a1, a2, 0x80475, t0); }
/* func_000BFB0C — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000BFB0C(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BFB0C(); return func_000ACAC8(a0, a1, a2, 0x80444, t0); }






int func_000BFB18(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BFB18(); return func_000ACAC8(a0, a1, a2, 0x1046, t0); }
/* func_000BFD14 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000BFBB4 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000BFBB4(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BFBB4(); return func_000ACAC8(a0, a1, a2, 0xa0401, t0); }
/* func_000BFBC0 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000BFBC0(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BFBC0(); return func_000ACAC8(a0, a1, a2, 0x80424, t0); }


int func_000BFD14(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BFD14(); return func_000ACAC8(a0, a1, a2, 0x1471, t0); }
/* func_000C0A4C — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000C05E4 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000BFD1C — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000BFD1C(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BFD1C(); return func_000ACAC8(a0, a1, a2, 0x8047a, t0); }
/* func_000BFD9C — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000BFD9C(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BFD9C(); return func_000ACAC8(a0, a1, a2, 0x40492, t0); }
/* func_000C00A8 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000C00A8(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000C00A8(); return func_000ACAC8(a0, a1, a2, 0x21874, t0); }
/* func_000C05D8 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000C05D8(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000C05D8(); return func_000ACAC8(a0, a1, a2, 0x80416, t0); }




int func_000C05E4(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000C05E4(); return func_000ACAC8(a0, a1, a2, 0x147A, t0); }
/* func_000C05EC — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000C05EC(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000C05EC(); return func_000ACAC8(a0, a1, a2, 0x20014, t0); }
/* func_000C0A40 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000C0A40(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000C0A40(); return func_000ACAC8(a0, a1, a2, 0x120401, t0); }



int func_000C0A4C(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000C0A4C(); return func_000ACAC8(a0, a1, a2, 0x8011, t0); }
/* func_000C0E4C — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000C0D90 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
/* func_000C0A54 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000C0A54(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000C0A54(); return func_000ACAC8(a0, a1, a2, 0x20c74, t0); }
/* func_000C0D14 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000C0D14(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000C0D14(); return func_000ACAC8(a0, a1, a2, 0x20475, t0); }
/* func_000C0D84 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000C0D84(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000C0D84(); return func_000ACAC8(a0, a1, a2, 0x80035, t0); }



int func_000C0D90(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000C0D90(); return func_000ACAC8(a0, a1, a2, 0x1474, t0); }

int func_000C0E4C(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000C0E4C(); return func_000ACAC8(a0, a1, a2, 0x4071, t0); }
/* func_000C0E54 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000C0E54(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000C0E54(); return func_000ACAC8(a0, a1, a2, 0x472, t0); }
/* func_000C10A8 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000C10A8(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000C10A8(); return func_000ACAC8(a0, a1, a2, 0x8015, t0); }
/* func_000C10B0 — 2 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000C10B0(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000C10B0(); return func_000ACAC8(a0, a1, a2, 0x2002, t0); }
/* func_000C13D8 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000C13D8(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000C13D8(); return func_000ACAC8(a0, a1, a2, 0x21454, t0); }
/* func_000C1468 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000C1468(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000C1468(); return func_000ACAC8(a0, a1, a2, 0x40410, t0); }
/* func_000C1474 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000C1474(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000C1474(); return func_000ACAC8(a0, a1, a2, 0x22011, t0); }
/* func_000C15F8 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000C15F8(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000C15F8(); return func_000ACAC8(a0, a1, a2, 0x40092, t0); }
/* func_000C1754 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000C1754(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000C1754(); return func_000ACAC8(a0, a1, a2, 0x80052, t0); }
/* func_000C1760 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000C1760(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000C1760(); return func_000ACAC8(a0, a1, a2, 0x8044a, t0); }
/* func_000C1B24 — 3 words. MATCH 100% (shape: hand). */
extern int func_000ACAC8();
int func_000C1B24(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000C1B24(); return func_000ACAC8(a0, a1, a2, 0x100476, t0); }



































































































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
/* func_000D1B94 — 2 words. MATCH 100% (shape: hand). */
extern int func_000D1B9C();
int func_000D1B94(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000D1B94();
    extern int func_000D1B9C(); return func_000D1B9C(a0, a1, 0, a3, t0); }
/* func_000D4D0C — 2 words. MATCH 100% (shape: hand). */
extern int func_000D4D14();
/* func_000D2C5C — 2 words. MATCH 100% (shape: hand). */
extern int func_000D2C64();
int func_000D2C5C(int a0, int a1, int a2, int a3) {
    extern int func_000D2C5C();
    extern int func_000D2C64(); return func_000D2C64(a0, a1, 0, a3); }

int func_000D4D0C(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000D4D0C();
    extern int func_000D4D14(); return func_000D4D14(0, a1, a2, a3, t0); }



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
/* func_000DEED4 — 2 words. MATCH 100% (shape: hand). */
extern int func_0008F280();
/* func_000DEB68 — 5 words. MATCH 100% (shape: hand). */
extern int func_00078D2C();
int func_000DEB68(int a0, int a1, int a2, int a3, int t0) {
    extern int func_00078D2C();
    extern int func_000DEB68(); return func_00078D2C((*(unsigned short *)((char *)a0 + 0x2)), (*(unsigned short *)((char *)a0 + 0x4)), (*(unsigned short *)((char *)a0 + 0x0)), a3, t0); }

int func_000DEED4(int a0) {
    extern int func_0008F280();
    extern int func_000DEED4(); return func_0008F280(0x10F4); }
/* func_000E04F0 — 5 words. MATCH 100% (shape: hand). */
extern int func_00078D2C();
int func_000E04F0(int a0, int a1, int a2, int a3, int t0) {
    extern int func_00078D2C();
    extern int func_000E04F0(); return func_00078D2C((*(unsigned short *)((char *)a0 + 0x2)), 0xB, (*(unsigned short *)((char *)a0 + 0x0)), a3, t0); }



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
/* func_000ED31C — 5 words. MATCH 100% (shape: hand). */
extern int func_00092C34();
int func_000ED31C(int a0, int a1, int a2) {
    extern int func_00092C34();
    extern int func_000ED31C();
    return func_00092C34((*(unsigned short *)((char *)a0 + 0x2)), (*(unsigned short *)((char *)a0 + 0x4)), (*(unsigned short *)((char *)a0 + 0x0)));
}


/* func_000F5398 — 8 words. MATCH 100% (shape: m2c). */
s32 func_000F5398(void) {
    extern int func_000A49E8();
    extern int func_000F5398();
    return func_000A49E8() != 0;
}
/* func_000FC1FC — 3 words. MATCH 100% (shape: hand). */
extern int func_000FC208();
int func_000FC1FC(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000FC1FC();
    extern int func_000FC208(); return func_000FC208(a0, 0x1, 0x2, a3, t0); }


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
/* func_00101224 — 2 words. MATCH 100% (shape: hand). */
extern int func_0010122C();
int func_00101224(int a0, int a1, int a2, int a3, int t0) {
    extern int func_00101224();
    extern int func_0010122C(); return func_0010122C(a0, a1, a2, 0, t0); }


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
/* func_00154EFC — 11 words. MATCH 100% (shape: hand). */
int func_00154EFC(void *a0, void *a1, int a2) {
    extern int func_000DDAB8();
    extern int func_00154EFC();
    extern int func_000DDAB8();
    if (a2 >= 5) {
        return 0;
    }
    return func_000DDAB8(a0, a1, a2);
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
/* func_0017BB0C — 2 words. MATCH 100% (shape: hand). */
int func_0017BB0C(void *a0, int a1) {
    extern int func_0017BB0C();
    extern int func_0017BB14();
    extern int func_0017BB14();
    return func_0017BB14(a0, a1, -1);
}
/* func_0019A408 — 8 words. MATCH 100% (shape: hand). */
int func_0019A408(void *a0, int a1) {
    extern int func_000844B8();
    extern int func_0019A408();
    extern int func_000844B8();
    return func_000844B8(a0, a1 & 0xFFFF) > 0;
}


/* func_001A0F58 — 19 words. MATCH 100% (shape: hand). */
int func_001A0F58(void *a0, int a1) {
    extern int func_0008C29C();
    extern int func_000963A4();
    extern int func_001A0F58();
    extern int func_000963A4();
    extern int func_0008C29C();
    if (func_000963A4(a0, a1) != 0) {
        return 1;
    }
    return func_0008C29C(a0, a1) != 0;
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

/* func_00206544 — 2 words. MATCH 100% (shape: hand). */
int func_00206544(void *a0, int a1) {
    extern int func_00206270();
    extern int func_00206544();
    extern int func_00206270();
    return func_00206270(a0, a1, -1);
}

/* func_0021F1B8 — 4 words. MATCH 100% (shape: hand). */
int func_0021F1B8(void *a0, int a1) {
    extern int func_0021DE64();
    extern int func_0021F1B8();
    extern int func_0021DE64();
    return func_0021DE64(a0, a1, 1, 1, 0x18E8);
}
/* func_00226158 — 9 words. MATCH 100% (shape: hand). */
int func_00226158(void *a0, int a1) {
    extern int func_00226158();
    extern int func_002531FC();
    extern int func_002531FC();
    return func_002531FC(a0, a1, 0) >= 0;
}


/* func_00226980 — 3 words. MATCH 100% (shape: hand). */
int func_00226980(int unused, unsigned short *a1) {
    extern int func_00226980();
    extern int func_002836D4();
    extern int func_002836D4();
    return func_002836D4(*a1, 1);
}

