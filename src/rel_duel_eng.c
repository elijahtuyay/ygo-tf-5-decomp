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
/* func_00000254 — 3 words. MATCH 100% (shape: hand). */
void func_00000254(int a0) {
    extern int D_00325D30;
    D_00325D30 = a0;
}
/* func_00000458 — 3 words. MATCH 100% (shape: hand). */
void func_00000458(void) {
    extern int D_00325D3C;
    D_00325D3C = 0;
}
/* func_00000578 — 3 words. MATCH 100% (shape: hand). */
int func_00000578(void) {
    extern int D_00325D48;
    return D_00325D48;
}
/* func_000005E8 — 3 words. MATCH 100% (shape: hand). */
void func_000005E8(int a0) {
    extern int D_00325D4C;
    D_00325D4C = a0;
}
/* func_000005F4 — 3 words. MATCH 100% (shape: hand). */
int func_000005F4(void) {
    extern int D_00325D4C;
    return D_00325D4C;
}
/* func_00000600 — 3 words. MATCH 100% (shape: hand). */
void func_00000600(int a0) {
    extern int D_00325D50;
    D_00325D50 = a0;
}
/* func_0000060C — 3 words. MATCH 100% (shape: hand). */
int func_0000060C(void) {
    extern int D_00325D50;
    return D_00325D50;
}
/* func_00000618 — 6 words. MATCH 100% (shape: hand). */
void func_00000618(int a0) {

    extern int D_00325D54;
    D_00325D54 = D_00325D54 | a0;
}
/* func_00000630 — 7 words. MATCH 100% (shape: hand). */
void func_00000630(int a0) {

    extern int D_00325D54;
    D_00325D54 = D_00325D54 & ~a0;
}
/* func_0000064C — 3 words. MATCH 100% (shape: hand). */
int func_0000064C(void) {
    extern int D_00325D54;
    return D_00325D54;
}
/* func_00000658 — 3 words. MATCH 100% (shape: hand). */
void func_00000658(int a0) {
    extern int D_00325D58;
    D_00325D58 = a0;
}



/* func_00002600 — 2 words. MATCH 100% (shape: m2c). */
void func_00002600(void) {
    extern int ehsys_639AE71F();
    extern int func_00002600();
    ehsys_639AE71F();
}
/* func_00004340 — 3 words. MATCH 100% (shape: hand). */
int func_00004340(void) {
    extern int D_00325DE0;
    return D_00325DE0;
}
/* func_0000434C — 6 words. MATCH 100% (shape: hand). */
int func_0000434C(int a0) {

    extern int D_00325DF0[];
    return D_00325DF0[a0];
}
/* func_00004364 — 3 words. MATCH 100% (shape: hand). */
int func_00004364(void) {
    extern int D_00325DE4;
    return D_00325DE4;
}
/* func_00004370 — 3 words. MATCH 100% (shape: hand). */
int func_00004370(void) {
    extern int D_00325DEC;
    return D_00325DEC;
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
/* func_0000E1D4 — 3 words. MATCH 100% (shape: m2c). */
void func_0000E1D4(void) {
    extern int D_0034DF34;
    extern int func_0000E1D4();
    D_0034DF34 = 0;
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
/* func_0000F7F4 — 3 words. MATCH 100% (shape: m2c). */
void func_0000F7F4(void) {
    extern int D_0034DF34;
    extern int func_0000F7F4();
    D_0034DF34 = 0;
}
/* func_0000F800 — 3 words. MATCH 100% (shape: m2c). */
void func_0000F800(void) {
    extern int D_0034DF34;
    extern int func_0000F800();
    D_0034DF34 = 0;
}
/* func_0000F80C — 3 words. MATCH 100% (shape: m2c). */
void func_0000F80C(void) {
    extern int D_0034DF34;
    extern int func_0000F80C();
    D_0034DF34 = 0;
}




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

/* func_00016600 — 3 words. MATCH 100% (shape: hand). */
u16 func_00016600(void) {
    extern u16 D_0035186C;
    return D_0035186C;
}

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
/* func_00031A28 — 5 words. MATCH 100% (shape: m2c). */
s32 func_00031A28(void) {
    extern char D_00351768;
    extern int func_00031A28();
    return D_00351768 == 6;
}
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

/* func_0003FBA8 — 3 words. MATCH 100% (shape: hand). */
void func_0003FBA8(int a0) {
    extern int D_0034DF4C;
    extern int func_0003FBA8();
    D_0034DF4C = a0;
}
/* func_0003FBD4 — 6 words. MATCH 100% (shape: m2c). */
void *func_0003FBD4(s32 arg0) {
    extern char D_0034DF44;
    extern int func_0003FBD4();
    return &D_0034DF44 + (arg0 * 4) + 0x14;
}
/* func_0003FBEC — 3 words. MATCH 100% (shape: hand). */
int func_0003FBEC(void) {
    extern int D_0034DF4C;
    extern int func_0003FEEC();
    extern int func_0003FBEC();
    return func_0003FEEC(D_0034DF4C);
}
/* func_0003FBF8 — 3 words. MATCH 100% (shape: hand). */
int func_0003FBF8(void) {
    extern int D_0034DF50;
    extern int func_0003FBF8();
    return D_0034DF50;
}
/* func_0004458C — 3 words. MATCH 100% (shape: hand). */
int func_0004458C(void) {
    extern int D_00351740;
    extern int func_0004458C();
    return D_00351740;
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
/* func_00050600 — 14 words. MATCH 100% (shape: bool-fold). */
s32 func_00050600(s32 arg0, int arg1, int arg2) {
    extern int func_00050600();
    extern int func_0014BF14();
    if (!func_0014BF14(4, arg0, arg1, arg2)) {
        return 0;
    }
    return 0x800;
}
int func_0005AA80(int a0, int a1, int a2, int a3, int t0) {
    extern int func_0005A860();
    extern int func_0005AA80(); return func_0005A860(a0, a1, a2, 0x2, a3); }
/* func_0005BA60 — 12 words. MATCH 100% (shape: hand). */
int func_0005BA60(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000135F0();
    extern int func_0005BA60();
    extern int func_000135F0();
    int t;
    int hi;
    int lo;
    int v;
    if (a0 != 0) {
        t = 0x8000;
    } else {
        t = 0;
    }
    t |= 0x35;
    hi = a3 & 0xFF;
    lo = a1 & 0xFF;
    hi = hi << 8;
    v = lo | hi;
    return func_000135F0((unsigned short)t, (unsigned short)v, a2, t0);
}

/* func_0005BDDC — 27 words. MATCH 100% (shape: bool-fold). */
void func_0005BDDC(s32 arg0, s32 arg1) {
    extern int func_000135F0();
    extern int func_0005BDDC();
    extern int func_00078B44();
    s32 temp_v0;
    s32 var_v1;

    temp_v0 = func_00078B44();
    if (temp_v0) {
        if (!arg0) {
            var_v1 = 0;
        } else {
            var_v1 = 0x8000;
        }
        func_000135F0((var_v1 | 0x37) & 0xFFFF, ((arg1 & 0xFF) | ((temp_v0 & 0xFF) << 8)) & 0xFFFF, 0, 0);
    }
}


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
/* func_00060848 — 9 words. MATCH 100% (shape: bulk). */
int func_00060848(int a0, int a1) {
    extern int func_000135F0();
    extern int func_00060848();
    extern int func_000135F0();
    int v0 = a0 ? 0x8000 : 0;
    return func_000135F0((v0 | 0x28) & 0xFFFF, a1 & 0xFFFF, 0, 0);
}
/* func_0006086C — 9 words. MATCH 100% (shape: bulk). */
int func_0006086C(int a0, int a1, int a2) {
    extern int func_000135F0();
    extern int func_0006086C();
    extern int func_000135F0();
    int v0 = a0 ? 0x8000 : 0;
    return func_000135F0((v0 | 0x28) & 0xFFFF, a1 & 0xFFFF, a2 & 0xFFFF, 0);
}
/* func_00060890 — 9 words. MATCH 100% (shape: bulk). */
int func_00060890(int a0, int a1) {
    extern int func_000135F0();
    extern int func_00060890();
    extern int func_000135F0();
    int v0 = a0 ? 0x8000 : 0;
    return func_000135F0((v0 | 0x28) & 0xFFFF, 0xD, a1 & 0xFFFF, 0xFFFE);
}
/* func_000609F4 — 9 words. MATCH 100% (shape: bulk). */
int func_000609F4(int a0, int a1, int a2) {
    extern int func_000135F0();
    extern int func_000609F4();
    extern int func_000135F0();
    int v0 = a0 ? 0x8000 : 0;
    return func_000135F0((v0 | 0x42) & 0xFFFF, a1 & 0xFFFF, a2 & 0xFFFF, 0);
}




/* func_0006F914 — 22 words. MATCH 100% (shape: bool-fold). */
void func_0006F914(s32 arg0, s32 arg1) {
    extern int func_000135F0();
    extern int func_0006F914();
    s32 var_v0;

    if (arg0 < 0) {
        func_000135F0(0x2F, arg1 & 0xFFFF, 1, 0);
        return;
    }
    if (!arg0) {
        var_v0 = 0;
    } else {
        var_v0 = 0x8000;
    }
    func_000135F0((var_v0 | 0x2F) & 0xFFFF, arg1 & 0xFFFF, 0, 0);
}
/* func_0006F96C — 9 words. MATCH 100% (shape: bulk). */
int func_0006F96C(int a0, int a1) {
    extern int func_000135F0();
    extern int func_0006F96C();
    extern int func_000135F0();
    int v0 = a0 ? 0x8000 : 0;
    return func_000135F0((v0 | 0x2E) & 0xFFFF, a1 & 0xFFFF, 1, 0);
}

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
/* func_00074248 — 9 words. MATCH 100% (shape: bulk). */
int func_00074248(int a0, int a1) {
    extern int func_000135F0();
    extern int func_00074248();
    extern int func_000135F0();
    int v0 = a0 ? 0x8000 : 0;
    return func_000135F0((v0 | 0x52) & 0xFFFF, a1 & 0xFFFF, 0, 0);
}
/* func_0007426C — 10 words. MATCH 100% (shape: hand). */
int func_0007426C(int a0, int a1, int a2) {
    extern int func_000135F0();
    extern int func_0007426C();
    extern int func_000135F0();
    int t;
    if (a0 != 0) {
        t = 0x8000;
    } else {
        t = 0;
    }
    t |= 0x53;
    return func_000135F0((unsigned short)t, (unsigned short)a2, (unsigned short)a1, 0);
}

/* func_000744D0 — 5 words. MATCH 100% (shape: bulk). */
int func_000744D0(int a0) {
    extern int func_000135F0();
    extern int func_000744D0();
    extern int func_000135F0();
    return func_000135F0(0x5A, a0 & 0xFFFF, 0, 0);
}
/* func_00074748 — 5 words. MATCH 100% (shape: bulk). */
int func_00074748(int a0) {
    extern int func_000135F0();
    extern int func_00074748();
    extern int func_000135F0();
    return func_000135F0(0x7, a0 & 0xFFFF, 0, 0);
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
/* func_00080424 — 11 words. MATCH 100% (shape: lead-dummy1). */
s32 func_00080424(s32 unused0, s32 arg1) {
    extern int ehsys_E62CCE79();
    extern int func_00080424();
    return arg1 == ehsys_E62CCE79();
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
/* func_00081ED8 — 6 words. MATCH 100% (shape: hand). */
int func_00081ED8(int a0) {

    extern int D_002FF308[];
    return D_002FF308[a0];
}

/* func_00083084 — 2 words. MATCH 100% (shape: hand). */
int func_00083084(int a0, int a1, int a2, int a3) {
    extern int func_00083084();
    extern int func_0008308C();
    extern int func_0008308C();
    return func_0008308C(a0, a1, 0x1, a3);
}

/* func_000832B4 — 12 words. MATCH 100% (shape: lead-dummy2). */
void func_000832B4(s32 unused0, s32 unused1, int arg2) {
    extern int ehsys_6F2C8118();
    extern int func_000827C4();
    extern int func_000832B4();
    ehsys_6F2C8118(func_000827C4(), arg2);
}
/* func_000832E4 — 12 words. MATCH 100% (shape: lead-dummy2). */
void func_000832E4(s32 unused0, s32 unused1, int arg2) {
    extern int ehsys_6F2C8118();
    extern int func_000832E4();
    extern int func_0009412C();
    ehsys_6F2C8118(func_0009412C(), arg2);
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
/* func_0008A830 — 2 words. MATCH 100% (shape: hand). */
int func_0008A830(int a0, int a1, int a2, int a3) {
    extern int func_0008A650();
    extern int func_0008A830();
    extern int func_0008A650();
    return func_0008A650(a0, a1, 0x0, a3);
}

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
/* func_0008C0BC — 9 words. MATCH 100% (shape: hand). */
int func_0008C0BC(int a0) {
    extern int func_0008C0BC();
    int v0;
    if (a0 != 0x1D11) {
        if (a0 != 0x1C06) {
            v0 = 0;
        } else {
            v0 = 1;
        }
    } else {
        v0 = 2;
    }
    return v0;
}


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
/* func_000910F0 — 12 words. MATCH 100% (shape: lead-dummy2). */
s32 func_000910F0(s32 unused0, s32 unused1, s32 arg2) {
    extern int func_00090DB0();
    extern int func_000910F0();
    return ((arg2 + 1) & func_00090DB0()) > 0;
}
/* func_0009135C — 12 words. MATCH 100% (shape: lead-dummy2). */
s32 func_0009135C(s32 unused0, s32 unused1, s32 arg2) {
    extern int func_00091120();
    extern int func_0009135C();
    return ((arg2 + 1) & func_00091120()) > 0;
}
/* func_000914F4 — 12 words. MATCH 100% (shape: lead-dummy2). */
s32 func_000914F4(s32 unused0, s32 unused1, s32 arg2) {
    extern int func_0009138C();
    extern int func_000914F4();
    return ((arg2 + 1) & func_0009138C()) > 0;
}
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
/* func_000A3D84 — 21 words. MATCH 100% (shape: lead-dummy1). */
s32 func_000A3D84(s32 unused0, int arg1) {
    extern int func_00089E9C();
    extern int func_0008A0D0();
    extern int func_000A3D84();
    if ((func_0008A0D0(0x159D) != 0) && (func_00089E9C(arg1, 0x158B, -1) == 0)) {
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
/* func_000AEF18 — 8 words. MATCH 100% (shape: hand). */
int func_000AEF18(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000AEF18();
    extern int func_000ACAC8();
    return func_000ACAC8(a0, a1, a2, 0x45A, t0) != 0;
}

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
/* func_000BEE14 — 8 words. MATCH 100% (shape: hand). */
int func_000BEE14(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BEE14();
    extern int func_000ACAC8();
    return func_000ACAC8(a0, a1, a2, 0x145A, t0) != 0;
}
/* func_000BEE34 — 9 words. MATCH 100% (shape: hand). */
int func_000BEE34(int a0, int a1, int a2, int a3, int t0) {
    extern int func_000ACAC8();
    extern int func_000BEE34();
    extern int func_000ACAC8();
    return func_000ACAC8(a0, a1, a2, 0x40012, t0) != 0;
}


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
/* func_000C2364 — 14 words. MATCH 100% (shape: bool-fold). */
s16 func_000C2364(u16 *arg0) {
    extern char D_003003EC;
    extern int func_000C2364();
    extern int func_002EED78();
    s32 temp_v0;

    temp_v0 = func_002EED78(*arg0, &D_003003EC, 0x12, 4);
    if (!temp_v0) {
        return 0;
    }
    return (*(int *)((char *)temp_v0 + 0x2));
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
/* func_000D1B94 — 2 words. MATCH 100% (shape: hand). */
extern int func_000D1B9C();
/* func_000CED20 — 12 words. MATCH 100% (shape: hand). */
int func_000CED20(unsigned short *a0, int a1, int a2, int a3) {
    extern int func_00074A28();
    extern int func_000CED20();
    extern int func_00074A28();
    func_00074A28(a0[1], a0[2], 0x1B, 0x1);
    return 1;
}

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
/* func_000D7AFC — 10 words. MATCH 100% (shape: bool-fold). */
s32 func_000D7AFC(void) {
    extern int func_000C3644();
    extern int func_000D7AFC();
    if (!func_000C3644()) {
        return 0;
    }
    return 2;
}
/* func_000DAFA8 — 11 words. MATCH 100% (shape: hand). */
int func_000DAFA8(unsigned short *a0) {

    extern char D_0034E678[];
    int idx = a0[1] & 1;
    int *p = (int *)(D_0034E678 + idx * 0xB3C);
    return *p != 0;
}

/* func_000DC104 — 12 words. MATCH 100% (shape: m2c). */
s32 func_000DC104(void *arg0) {
    extern int func_000DC104();
    u16 temp_v1;

    temp_v1 = (*(int *)((char *)arg0 + 0x6));
    if ((temp_v1 != 7) && (temp_v1 != 8)) {
        return 0;
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
/* func_000DE044 — 4 words. MATCH 100% (shape: hand). */
int func_000DE044(unsigned short *a0) {
    extern int func_000DE044();
    return a0[3] == 0x19;
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
/* func_000DEE40 — 15 words. MATCH 100% (shape: m2c). */
s32 func_000DEE40(void *arg0) {
    extern int func_000DEE40();
    u16 temp_v1;

    temp_v1 = (*(int *)((char *)arg0 + 0x6));
    if ((temp_v1 != 0x15) && (temp_v1 != 0x14) && (temp_v1 != 0x13)) {
        return 0;
    }
    return 1;
}

int func_000DEED4(int a0) {
    extern int func_0008F280();
    extern int func_000DEED4(); return func_0008F280(0x10F4); }
/* func_000E04F0 — 5 words. MATCH 100% (shape: hand). */
extern int func_00078D2C();
/* func_000DEEDC — 15 words. MATCH 100% (shape: m2c). */
s32 func_000DEEDC(void *arg0) {
    extern int func_000DEEDC();
    u16 temp_v1;

    temp_v1 = (*(int *)((char *)arg0 + 0x6));
    if ((temp_v1 != 9) && (temp_v1 != 8) && (temp_v1 != 7)) {
        return 0;
    }
    return 1;
}
int func_000E04F0(int a0, int a1, int a2, int a3, int t0) {
    extern int func_00078D2C();
    extern int func_000E04F0(); return func_00078D2C((*(unsigned short *)((char *)a0 + 0x2)), 0xB, (*(unsigned short *)((char *)a0 + 0x0)), a3, t0); }



/* func_000E2258 — 8 words. MATCH 100% (shape: m2c). */
s32 func_000E2258(void) {
    extern int func_0008F280();
    extern int func_000E2258();
    return func_0008F280(0x159D) != 0;
}
/* func_000E2EF8 — 10 words. MATCH 100% (shape: hand). */
int func_000E2EF8(unsigned short *a0, int a1, int a2, int a3) {
    extern int func_0009321C();
    extern int func_000E2EF8();
    extern int func_0009321C();
    return func_0009321C(a0[1], a0[2], a2, a3) != 0;
}

/* func_000E33D8 — 10 words. MATCH 100% (shape: bool-fold). */
s32 func_000E33D8(void) {
    extern int func_000D6A00();
    extern int func_000E33D8();
    if (!func_000D6A00()) {
        return 0;
    }
    return 2;
}
/* func_000E51E8 — 10 words. MATCH 100% (shape: bool-fold). */
s32 func_000E51E8(void) {
    extern int func_000D75E8();
    extern int func_000E51E8();
    if (!func_000D75E8()) {
        return 0;
    }
    return 2;
}
/* func_000E6130 — 11 words. MATCH 100% (shape: hand). */
int func_000E6130(unsigned short *a0, int a1, int a2, int a3) {
    extern int func_00078AAC();
    extern int func_000E6130();
    extern int func_00078AAC();
    return func_00078AAC(a0[1], a0[2], a0[0], a3) != 0;
}

/* func_000E77A0 — 17 words. MATCH 100% (shape: bool-fold). */
s32 func_000E77A0(s32 arg0, int arg1) {
    extern int func_000D72B8();
    extern int func_000D7B24();
    extern int func_000E77A0();
    if (!func_000D7B24()) {
        return 0;
    }
    return func_000D72B8(arg0, arg1);
}
/* func_000E7A8C — 10 words. MATCH 100% (shape: bool-fold). */
s32 func_000E7A8C(void) {
    extern int func_000D7548();
    extern int func_000E7A8C();
    if (!func_000D7548()) {
        return 0;
    }
    return 2;
}
/* func_000E95E0 — 16 words. MATCH 100% (shape: bool-fold). */
s32 func_000E95E0(void *arg0) {
    extern int func_000A3DFC();
    extern int func_000E95E0();
    extern int func_00171104();
    u16 temp_a0;

    temp_a0 = (*(int *)((char *)arg0 + 0x2));
    if (!func_000A3DFC(temp_a0, temp_a0)) {
        return 0;
    }
    return func_00171104(arg0) > 0;
}
/* func_000EAA24 — 15 words. MATCH 100% (shape: single-switch). */
s32 func_000EAA24(void *arg0, s32 arg1) {
    extern int func_000EAA24();
    u16 temp_v1;


    switch (arg1) {
    case 0:
        temp_v1 = (*(int *)((char *)arg0 + 0x6));
        if ((temp_v1 != 0x22) && (temp_v1 != 0x21)) {
            return 0;
        }
        return 1;
        break;
    }
    return 0;
}
/* func_000EAA60 — 10 words. MATCH 100% (shape: bool-fold). */
s32 func_000EAA60(void) {
    extern int func_000D73BC();
    extern int func_000EAA60();
    if (!func_000D73BC()) {
        return 1;
    }
    return 2;
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
/* func_000EEB5C — 15 words. MATCH 100% (shape: bool-fold). */
s32 func_000EEB5C(s32 arg0) {
    extern int func_000D75E8();
    extern int func_000EEB5C();
    extern int func_00171104();
    if (!func_000D75E8()) {
        return 0;
    }
    return func_00171104(arg0) >= 2;
}
/* func_000EEB98 — 14 words. MATCH 100% (shape: bool-fold). */
s32 func_000EEB98(void) {
    extern int func_0008227C();
    extern int func_000A4934();
    extern int func_000EEB98();
    if (!func_000A4934()) {
        return func_0008227C(0x1E) > 0;
    }
    return 0;
}
/* func_000F3164 — 12 words. MATCH 100% (shape: hand). */
int func_000F3164(unsigned short *a0, int a1, int a2, int a3) {
    extern int func_0008110C();
    extern int func_000F3164();
    extern int func_0008110C();
    int r = func_0008110C(a0[1], a0[2], a2, a3);
    return (r + 1) == 2;
}

/* func_000F45A8 — 10 words. MATCH 100% (shape: bool-fold). */
s32 func_000F45A8(void) {
    extern int func_000EAD8C();
    extern int func_000F45A8();
    if (!func_000EAD8C()) {
        return 0;
    }
    return 2;
}
/* func_000F471C — 10 words. MATCH 100% (shape: bool-fold). */
s32 func_000F471C(void) {
    extern int func_000D72B8();
    extern int func_000F471C();
    if (!func_000D72B8()) {
        return 0;
    }
    return 2;
}
/* func_000F4F58 — 10 words. MATCH 100% (shape: bool-fold). */
s32 func_000F4F58(void) {
    extern int func_000D6C00();
    extern int func_000F4F58();
    if (!func_000D6C00()) {
        return 0;
    }
    return 2;
}


/* func_000F5398 — 8 words. MATCH 100% (shape: m2c). */
s32 func_000F5398(void) {
    extern int func_000A49E8();
    extern int func_000F5398();
    return func_000A49E8() != 0;
}
/* func_000FC1FC — 3 words. MATCH 100% (shape: hand). */
extern int func_000FC208();
/* func_000F79AC — 10 words. MATCH 100% (shape: bool-fold). */
s32 func_000F79AC(void) {
    extern int func_000D6970();
    extern int func_000F79AC();
    if (!func_000D6970()) {
        return 0;
    }
    return 2;
}
/* func_000FBE30 — 11 words. MATCH 100% (shape: hand). */
int func_000FBE30(unsigned short *a0, int a1, int a2, int a3) {
    extern int func_000820D8();
    extern int func_000FBE30();
    extern int func_000820D8();
    return func_000820D8(a0[1], a0[2], 0x18, a3) > 0;
}

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
/* func_000FF294 — 8 words. MATCH 100% (shape: hand). */
int func_000FF294(int a0, int a1, int a2, int a3) {
    extern int func_000FF070();
    extern int func_000FF294();
    extern int func_000FF070();
    func_000FF070(a0, a1, 0x1, a3);
    return 0;
}

int func_00101224(int a0, int a1, int a2, int a3, int t0) {
    extern int func_00101224();
    extern int func_0010122C(); return func_0010122C(a0, a1, a2, 0, t0); }


/* func_00108EE4 — 2 words. MATCH 100% (shape: m2c). */
s32 func_00108EE4(void) {
    extern int func_00108EE4();
    return 0;
}
/* func_0010BB64 — 12 words. MATCH 100% (shape: lead-dummy1). */
void func_0010BB64(s32 unused0, s32 arg1) {
    extern int func_000FF294();
    extern int func_0010BB64();
    extern int func_0010BB94();
    if (arg1 != 0) {
        func_000FF294();
        return;
    }
    func_0010BB94();
}
/* func_00114078 — 17 words. MATCH 100% (shape: bool-fold). */
s32 func_00114078(s32 arg0, int arg1) {
    extern int func_000FEF9C();
    extern int func_00114078();
    extern int func_0017C014();
    if (!func_0017C014()) {
        return 0;
    }
    return func_000FEF9C(arg0, arg1);
}
/* func_00116EB4 — 8 words. MATCH 100% (shape: hand). */
int func_00116EB4(int a0, int a1, int a2, int a3) {
    extern int func_000FF070();
    extern int func_00116EB4();
    extern int func_000FF070();
    func_000FF070(a0, a1, 0x0, a3);
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
/* func_0011A668 — 20 words. MATCH 100% (shape: m2c). */
s32 func_0011A668(void *arg0) {
    extern int func_00100E50();
    extern int func_00102E14();
    extern int func_0011A668();
    u16 temp_v1;

    temp_v1 = (*(int *)((char *)arg0 + 0x26));
    switch (temp_v1) {                              /* irregular */
    case 1:
        return func_00100E50();
    case 2:
        return func_00102E14();
    default:
        return 0;
    }
}

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
/* func_001237AC — 12 words. MATCH 100% (shape: m2c). */
s32 func_001237AC(void *arg0) {
    extern int func_000FF294();
    extern int func_001237AC();
    if ((*(int *)((char *)arg0 + 0x30)) != 0) {
        return 0;
    }
    return func_000FF294();
}
/* func_00126EAC — 13 words. MATCH 100% (shape: hand). */
void func_00126EAC(short *a0, unsigned short *a1) {
    extern int func_00126EAC();
    extern int func_0017C328();
    extern int func_0017C328();
    *a0 = *a1;
    func_0017C328(a0, a1);
    *a0 = 0x183E;
}
/* func_00129CBC — 17 words. MATCH 100% (shape: bool-fold). */
s32 func_00129CBC(s32 arg0, int arg1) {
    extern int func_000FC5C0();
    extern int func_00129CBC();
    extern int func_0017C014();
    if (!func_0017C014()) {
        return 0;
    }
    return func_000FC5C0(arg0, arg1);
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
/* func_001306E8 — 18 words. MATCH 100% (shape: bool-fold). */
s32 func_001306E8(s32 arg0, int arg1) {
    extern int func_0008AC80();
    extern int func_00100458();
    extern int func_001306E8();
    if (!func_0008AC80(0x1A77)) {
        return 0;
    }
    return func_00100458(arg0, arg1);
}
/* func_0013813C — 12 words. MATCH 100% (shape: m2c). */
s32 func_0013813C(void *arg0) {
    extern int func_000FF294();
    extern int func_0013813C();
    if ((*(int *)((char *)arg0 + 0x30)) != 0) {
        return 0;
    }
    return func_000FF294();
}

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
/* func_0013DC20 — 17 words. MATCH 100% (shape: bool-fold). */
s32 func_0013DC20(s32 arg0, int arg1) {
    extern int func_000FC44C();
    extern int func_0012B2D4();
    extern int func_0013DC20();
    if (!func_0012B2D4()) {
        return 0;
    }
    return func_000FC44C(arg0, arg1);
}

int func_001422E8(int a0, int a1) {
    extern int func_0011228C();
    extern int func_00115704();
    extern int func_001422E8();
    func_0011228C(a0, a1);
    func_00115704(a0, a1);
    return 0;
}
/* func_00143698 — 17 words. MATCH 100% (shape: bool-fold). */
s32 func_00143698(s32 arg0, int arg1) {
    extern int func_00102194();
    extern int func_00143698();
    extern int func_0017B444();
    if (!func_0017B444()) {
        return 0;
    }
    return func_00102194(arg0, arg1);
}
/* func_001453B4 — 18 words. MATCH 100% (shape: m2c). */
s32 func_001453B4(void *arg0) {
    extern int func_0005FF2C();
    extern int func_00081090();
    extern int func_001453B4();
    s32 temp_s0;

    temp_s0 = (*(int *)((char *)arg0 + 0x30));
    func_0005FF2C(arg0, temp_s0 & 1, func_00081090(temp_s0));
    return 0;
}
/* func_001475A8 — 17 words. MATCH 100% (shape: bool-fold). */
s32 func_001475A8(s32 arg0, int arg1) {
    extern int func_001030E8();
    extern int func_001475A8();
    extern int func_0017B444();
    if (!func_0017B444()) {
        return 0;
    }
    return func_001030E8(arg0, arg1);
}
/* func_0014D260 — 17 words. MATCH 100% (shape: bool-fold). */
s32 func_0014D260(s32 arg0, int arg1) {
    extern int func_000D6A00();
    extern int func_0014D260();
    extern int func_0014D460();
    if (!func_000D6A00()) {
        return 0;
    }
    return func_0014D460(arg0, arg1);
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
/* func_00155014 — 27 words. MATCH 100% (shape: m2c). */
s32 func_00155014(s32 arg0, int arg1, s32 arg2) {
    extern int func_0007FD14();
    extern int func_000DDAB8();
    extern int func_00155014();
    if ((arg2 < 5) && (func_0007FD14(arg1, arg2) == 0)) {
        return 0;
    }
    return func_000DDAB8(arg0, arg1, arg2);
}
/* func_0015915C — 13 words. MATCH 100% (shape: m2c). */
void func_0015915C(u16 *arg0, u16 *arg1) {
    extern int func_0015915C();
    extern int func_0017C2A4();
    *arg0 = *arg1;
    func_0017C2A4();
    *arg0 = 0x183E;
}
/* func_0015F408 — 3 words. MATCH 100% (shape: hand). */
int func_0015F408(void) {

    extern int D_0034D558;
    return D_0034D558;
}
/* func_00162F70 — 7 words. MATCH 100% (shape: bulk). */
int func_00162F70(int a0, int a1, int a2, int a3) {

    extern int D_0034D654;
    extern int func_0014BF14();
    return func_0014BF14(D_0034D654, a0, a1, a2);
}


/* func_00163168 — 8 words. MATCH 100% (shape: bulk). */
int func_00163168(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_001621C4();
    extern int func_00163168();
    extern int func_001621C4();
    return func_001621C4(a1, (*(unsigned short *)((char *)(a0) + 0)), 0, 0, (*(int *)((char *)(a0) + 8)), 8);
}
/* func_001632BC — 8 words. MATCH 100% (shape: bulk). */
int func_001632BC(int a0, int a1, int a2, int a3, int t0, int t1, int t2) {
    extern int func_00161DF0();
    extern int func_001632BC();
    extern int func_00161DF0();
    return func_00161DF0(a1, (*(unsigned short *)((char *)(a0) + 0)), a2, 0, 0, (*(int *)((char *)(a0) + 8)), 2);
}
/* func_001632DC — 8 words. MATCH 100% (shape: bulk). */
int func_001632DC(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_0016164C();
    extern int func_001632DC();
    extern int func_0016164C();
    return func_0016164C(a1, (*(unsigned short *)((char *)(a0) + 0)), 0, 0, (*(int *)((char *)(a0) + 8)), 2);
}
/* func_001632FC — 8 words. MATCH 100% (shape: bulk). */
int func_001632FC(int a0, int a1, int a2, int a3, int t0, int t1, int t2) {
    extern int func_00161DF0();
    extern int func_001632FC();
    extern int func_00161DF0();
    return func_00161DF0(a1, (*(unsigned short *)((char *)(a0) + 0)), a2, 0, 0, (*(int *)((char *)(a0) + 8)), 0);
}
/* func_00163470 — 8 words. MATCH 100% (shape: bulk). */
int func_00163470(int a0, int a1, int a2, int a3, int t0, int t1, int t2) {
    extern int func_00161DF0();
    extern int func_00163470();
    extern int func_00161DF0();
    return func_00161DF0(a1, (*(unsigned short *)((char *)(a0) + 0)), a2, 0, 0, (*(int *)((char *)(a0) + 8)), 17);
}
/* func_001637F4 — 9 words. MATCH 100% (shape: bulk). */
int func_001637F4(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_001621C4();
    extern int func_001637F4();
    extern int func_001621C4();
    return func_001621C4(a1, (*(unsigned short *)((char *)(a0) + 0)), 0, 0, (*(int *)((char *)(a0) + 8)), 0x18000);
}
/* func_00163A4C — 8 words. MATCH 100% (shape: bulk). */
int func_00163A4C(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_001621C4();
    extern int func_00163A4C();
    extern int func_001621C4();
    return func_001621C4(a1, (*(unsigned short *)((char *)(a0) + 0)), 0, 0, (*(int *)((char *)(a0) + 8)), 2048);
}
/* func_00163ABC — 9 words. MATCH 100% (shape: bulk). */
int func_00163ABC(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_0016164C();
    extern int func_00163A6C();
    extern int func_00163ABC();
    extern int func_0016164C();
    extern int func_00163A6C();
    return func_0016164C(a1, (*(unsigned short *)((char *)(a0) + 0)), ((int)&func_00163A6C), 0, (*(int *)((char *)(a0) + 8)), 0);
}
/* func_00163AE0 — 8 words. MATCH 100% (shape: bulk). */
int func_00163AE0(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_00161AE0();
    extern int func_00163AE0();
    extern int func_00161AE0();
    return func_00161AE0(a1, (*(unsigned short *)((char *)(a0) + 0)), 0, 0, (*(int *)((char *)(a0) + 8)), 12);
}
/* func_00163D6C — 8 words. MATCH 100% (shape: bulk). */
int func_00163D6C(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_0016164C();
    extern int func_00163D6C();
    extern int func_0016164C();
    return func_0016164C(a1, (*(unsigned short *)((char *)(a0) + 0)), 0, 0, (*(int *)((char *)(a0) + 8)), 0);
}
/* func_001640C8 — 9 words. MATCH 100% (shape: bulk). */
int func_001640C8(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_00161AE0();
    extern int func_00164058();
    extern int func_001640C8();
    extern int func_00161AE0();
    extern int func_00164058();
    return func_00161AE0(a1, (*(unsigned short *)((char *)(a0) + 0)), ((int)&func_00164058), 0, (*(int *)((char *)(a0) + 8)), 2);
}
/* func_001640EC — 8 words. MATCH 100% (shape: bulk). */
int func_001640EC(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_001621C4();
    extern int func_001640EC();
    extern int func_001621C4();
    return func_001621C4(a1, (*(unsigned short *)((char *)(a0) + 0)), 0, 0, (*(int *)((char *)(a0) + 8)), 1);
}
/* func_0016420C — 8 words. MATCH 100% (shape: bulk). */
int func_0016420C(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_001621C4();
    extern int func_0016420C();
    extern int func_001621C4();
    return func_001621C4(a1, (*(unsigned short *)((char *)(a0) + 0)), 0, 0, (*(int *)((char *)(a0) + 8)), 0);
}
/* func_001642E8 — 9 words. MATCH 100% (shape: bulk). */
int func_001642E8(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_0016164C();
    extern int func_001642E8();
    extern int func_0016164C();
    return func_0016164C(a1, (*(unsigned short *)((char *)(a0) + 0)), 0, 0, (*(int *)((char *)(a0) + 8)), ((*(short *)((char *)(a0) + 2)) << 25));
}
/* func_0016434C — 8 words. MATCH 100% (shape: bulk). */
int func_0016434C(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_00161AE0();
    extern int func_0016434C();
    extern int func_00161AE0();
    return func_00161AE0(a1, (*(unsigned short *)((char *)(a0) + 0)), 0, 0, (*(int *)((char *)(a0) + 8)), 10);
}
/* func_0016436C — 8 words. MATCH 100% (shape: bulk). */
int func_0016436C(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_00161AE0();
    extern int func_0016436C();
    extern int func_00161AE0();
    return func_00161AE0(a1, (*(unsigned short *)((char *)(a0) + 0)), 0, 0, (*(int *)((char *)(a0) + 8)), 0);
}
/* func_00164414 — 8 words. MATCH 100% (shape: bulk). */
int func_00164414(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_00161AE0();
    extern int func_00164414();
    extern int func_00161AE0();
    return func_00161AE0(a1, (*(unsigned short *)((char *)(a0) + 0)), 0, 0, (*(int *)((char *)(a0) + 8)), 16);
}
/* func_001644A4 — 9 words. MATCH 100% (shape: bulk). */
int func_001644A4(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_001621C4();
    extern int func_001644A4();
    extern int func_001621C4();
    return func_001621C4(a1, (*(unsigned short *)((char *)(a0) + 0)), 0, 0, (*(int *)((char *)(a0) + 8)), 0x10001);
}
/* func_00164564 — 8 words. MATCH 100% (shape: bulk). */
int func_00164564(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_0016164C();
    extern int func_00164564();
    extern int func_0016164C();
    return func_0016164C(a1, (*(unsigned short *)((char *)(a0) + 0)), 0, 0, (*(int *)((char *)(a0) + 8)), 10);
}
/* func_00164600 — 8 words. MATCH 100% (shape: bulk). */
int func_00164600(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_001621C4();
    extern int func_00164600();
    extern int func_001621C4();
    return func_001621C4(a1, (*(unsigned short *)((char *)(a0) + 0)), 0, 0, (*(int *)((char *)(a0) + 8)), 16384);
}
/* func_00164620 — 8 words. MATCH 100% (shape: bulk). */
int func_00164620(int a0, int a1, int a2, int a3, int t0, int t1, int t2) {
    extern int func_00161DF0();
    extern int func_00164620();
    extern int func_00161DF0();
    return func_00161DF0(a1, (*(unsigned short *)((char *)(a0) + 0)), a2, 0, 0, (*(int *)((char *)(a0) + 8)), 4);
}
/* func_00164668 — 9 words. MATCH 100% (shape: bulk). */
int func_00164668(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_0016164C();
    extern int func_00164640();
    extern int func_00164668();
    extern int func_0016164C();
    extern int func_00164640();
    return func_0016164C(a1, (*(unsigned short *)((char *)(a0) + 0)), ((int)&func_00164640), 0, (*(int *)((char *)(a0) + 8)), 0);
}
/* func_0016468C — 8 words. MATCH 100% (shape: bulk). */
int func_0016468C(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_001621C4();
    extern int func_0016468C();
    extern int func_001621C4();
    return func_001621C4(a1, (*(unsigned short *)((char *)(a0) + 0)), 0, 0, (*(int *)((char *)(a0) + 8)), 16);
}
/* func_001647D8 — 8 words. MATCH 100% (shape: bulk). */
int func_001647D8(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_001621C4();
    extern int func_001647D8();
    extern int func_001621C4();
    return func_001621C4(a1, (*(unsigned short *)((char *)(a0) + 0)), 0, 0, (*(int *)((char *)(a0) + 8)), 384);
}
/* func_00164984 — 8 words. MATCH 100% (shape: bulk). */
int func_00164984(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_001621C4();
    extern int func_00164984();
    extern int func_001621C4();
    return func_001621C4(a1, (*(unsigned short *)((char *)(a0) + 0)), 0, 0, (*(int *)((char *)(a0) + 8)), 2049);
}
/* func_00164A08 — 8 words. MATCH 100% (shape: bulk). */
int func_00164A08(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_001621C4();
    extern int func_00164A08();
    extern int func_001621C4();
    return func_001621C4(a1, (*(unsigned short *)((char *)(a0) + 0)), 0, 0, (*(int *)((char *)(a0) + 8)), 640);
}
/* func_00164A28 — 8 words. MATCH 100% (shape: bulk). */
int func_00164A28(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_001621C4();
    extern int func_00164A28();
    extern int func_001621C4();
    return func_001621C4(a1, (*(unsigned short *)((char *)(a0) + 0)), 0, 0, (*(int *)((char *)(a0) + 8)), 0x10000);
}
/* func_00164D28 — 8 words. MATCH 100% (shape: bulk). */
int func_00164D28(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_001627D4();
    extern int func_00164D28();
    extern int func_001627D4();
    return func_001627D4(a1, (*(unsigned short *)((char *)(a0) + 0)), 0, 0, (*(int *)((char *)(a0) + 8)), 8);
}
/* func_00164F20 — 9 words. MATCH 100% (shape: bulk). */
int func_00164F20(int a0, int a1, int a2, int a3, int t0, int t1, int t2) {
    extern int func_00161DF0();
    extern int func_00164EB0();
    extern int func_00164F20();
    extern int func_00161DF0();
    extern int func_00164EB0();
    return func_00161DF0(a1, (*(unsigned short *)((char *)(a0) + 0)), a2, ((int)&func_00164EB0), 0, (*(int *)((char *)(a0) + 8)), 2);
}
/* func_00165414 — 8 words. MATCH 100% (shape: bulk). */
int func_00165414(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_001621C4();
    extern int func_00165414();
    extern int func_001621C4();
    return func_001621C4(a1, (*(unsigned short *)((char *)(a0) + 0)), 0, 0, (*(int *)((char *)(a0) + 8)), 4104);
}
/* func_00165930 — 8 words. MATCH 100% (shape: bulk). */
int func_00165930(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_001621C4();
    extern int func_00165930();
    extern int func_001621C4();
    return func_001621C4(a1, (*(unsigned short *)((char *)(a0) + 0)), 0, 0, (*(int *)((char *)(a0) + 8)), 9);
}
/* func_00165C04 — 8 words. MATCH 100% (shape: bulk). */
int func_00165C04(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_0016164C();
    extern int func_00165C04();
    extern int func_0016164C();
    return func_0016164C(a1, (*(unsigned short *)((char *)(a0) + 0)), 0, 0, (*(int *)((char *)(a0) + 8)), 18);
}
/* func_00165C24 — 7 words. MATCH 100% (shape: bulk). */
int func_00165C24(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_001621C4();
    extern int func_00165C24();
    extern int func_001621C4();
    return func_001621C4(a2, (*(unsigned short *)((char *)(a0) + 0)), 0, 0, (*(int *)((char *)(a0) + 8)), 0);
}
/* func_00165E50 — 8 words. MATCH 100% (shape: bulk). */
int func_00165E50(int a0, int a1, int a2, int a3, int t0, int t1, int t2) {
    extern int func_00161DF0();
    extern int func_00165E50();
    extern int func_00161DF0();
    return func_00161DF0(a1, (*(unsigned short *)((char *)(a0) + 0)), a2, 0, 0, (*(int *)((char *)(a0) + 8)), 16);
}
/* func_00166128 — 8 words. MATCH 100% (shape: bulk). */
int func_00166128(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_001627D4();
    extern int func_00166128();
    extern int func_001627D4();
    return func_001627D4(a1, (*(unsigned short *)((char *)(a0) + 0)), 0, 0, (*(int *)((char *)(a0) + 8)), 0);
}
/* func_00166148 — 8 words. MATCH 100% (shape: bulk). */
int func_00166148(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_001627D4();
    extern int func_00166148();
    extern int func_001627D4();
    return func_001627D4(a1, (*(unsigned short *)((char *)(a0) + 0)), 0, 0, (*(int *)((char *)(a0) + 8)), 12);
}
/* func_001661B4 — 9 words. MATCH 100% (shape: bulk). */
int func_001661B4(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_0016164C();
    extern int func_00166168();
    extern int func_001661B4();
    extern int func_0016164C();
    extern int func_00166168();
    return func_0016164C(a1, (*(unsigned short *)((char *)(a0) + 0)), ((int)&func_00166168), 0, (*(int *)((char *)(a0) + 8)), 0);
}
/* func_001664F0 — 8 words. MATCH 100% (shape: bulk). */
int func_001664F0(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_001621C4();
    extern int func_001664F0();
    extern int func_001621C4();
    return func_001621C4(a1, (*(unsigned short *)((char *)(a0) + 0)), 0, 0, (*(int *)((char *)(a0) + 8)), 4104);
}
/* func_00166550 — 8 words. MATCH 100% (shape: bulk). */
int func_00166550(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_001621C4();
    extern int func_00166550();
    extern int func_001621C4();
    return func_001621C4(a1, (*(unsigned short *)((char *)(a0) + 0)), 0, 0, (*(int *)((char *)(a0) + 8)), 4096);
}
/* func_00166D9C — 9 words. MATCH 100% (shape: bulk). */
int func_00166D9C(int a0, int a1, int a2, int a3, int t0, int t1, int t2) {
    extern int func_00161DF0();
    extern int func_00166D30();
    extern int func_00166D9C();
    extern int func_00161DF0();
    extern int func_00166D30();
    return func_00161DF0(a1, (*(unsigned short *)((char *)(a0) + 0)), a2, ((int)&func_00166D30), 0, (*(int *)((char *)(a0) + 8)), 17);
}
/* func_00167080 — 8 words. MATCH 100% (shape: bulk). */
int func_00167080(int a0, int a1, int a2, int a3, int t0, int t1, int t2) {
    extern int func_00161DF0();
    extern int func_00167080();
    extern int func_00161DF0();
    return func_00161DF0(a1, (*(unsigned short *)((char *)(a0) + 0)), a2, 0, 0, (*(int *)((char *)(a0) + 8)), 0);
}
/* func_001670A0 — 8 words. MATCH 100% (shape: bulk). */
int func_001670A0(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_00161AE0();
    extern int func_001670A0();
    extern int func_00161AE0();
    return func_00161AE0(a1, (*(unsigned short *)((char *)(a0) + 0)), 0, 0, (*(int *)((char *)(a0) + 8)), 18);
}












































/* func_00167700 — 3 words. MATCH 100% (shape: hand). */
int func_00167700(void *unused, void *p) {
    extern int func_00167700();
    extern int func_00170D08();
    extern int func_00170D08();
    return func_00170D08(p, 0xB);
}
/* func_00167FEC — 8 words. MATCH 100% (shape: bulk). */
int func_00167FEC(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_001621C4();
    extern int func_00167FEC();
    extern int func_001621C4();
    return func_001621C4(a1, (*(unsigned short *)((char *)(a0) + 0)), 0, 0, (*(int *)((char *)(a0) + 8)), 65);
}
/* func_001681DC — 9 words. MATCH 100% (shape: bulk). */
int func_001681DC(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_0016164C();
    extern int func_00168194();
    extern int func_001681DC();
    extern int func_0016164C();
    extern int func_00168194();
    return func_0016164C(a1, (*(unsigned short *)((char *)(a0) + 0)), ((int)&func_00168194), 0, (*(int *)((char *)(a0) + 8)), 10);
}
/* func_001686A8 — 9 words. MATCH 100% (shape: bulk). */
int func_001686A8(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_00161AE0();
    extern int func_00168664();
    extern int func_001686A8();
    extern int func_00161AE0();
    extern int func_00168664();
    return func_00161AE0(a1, (*(unsigned short *)((char *)(a0) + 0)), ((int)&func_00168664), 0, (*(int *)((char *)(a0) + 8)), 2);
}
/* func_00168B44 — 9 words. MATCH 100% (shape: bulk). */
int func_00168B44(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_001621C4();
    extern int func_00168AA0();
    extern int func_00168B44();
    extern int func_001621C4();
    extern int func_00168AA0();
    return func_001621C4(a1, (*(unsigned short *)((char *)(a0) + 0)), ((int)&func_00168AA0), 0, (*(int *)((char *)(a0) + 8)), 0);
}
/* func_00168BC4 — 9 words. MATCH 100% (shape: bulk). */
int func_00168BC4(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_001621C4();
    extern int func_00168BC4();
    extern int func_001621C4();
    return func_001621C4(a1, (*(unsigned short *)((char *)(a0) + 0)), 0, 0, (*(int *)((char *)(a0) + 8)), 0x11000);
}
/* func_00169D34 — 9 words. MATCH 100% (shape: bulk). */
int func_00169D34(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_00161AE0();
    extern int func_00169CD8();
    extern int func_00169D34();
    extern int func_00161AE0();
    extern int func_00169CD8();
    return func_00161AE0(a1, (*(unsigned short *)((char *)(a0) + 0)), ((int)&func_00169CD8), 0, (*(int *)((char *)(a0) + 8)), 0);
}
/* func_00169FB0 — 9 words. MATCH 100% (shape: bulk). */
int func_00169FB0(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_0016164C();
    extern int func_00169F10();
    extern int func_00169FB0();
    extern int func_0016164C();
    extern int func_00169F10();
    return func_0016164C(a1, (*(unsigned short *)((char *)(a0) + 0)), ((int)&func_00169F10), 0, (*(int *)((char *)(a0) + 8)), 0);
}
/* func_0016A094 — 9 words. MATCH 100% (shape: bulk). */
int func_0016A094(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_001621C4();
    extern int func_0016A094();
    extern int func_001621C4();
    return func_001621C4(a1, (*(unsigned short *)((char *)(a0) + 0)), 0, 0, (*(int *)((char *)(a0) + 8)), 0x12000);
}
/* func_0016A118 — 9 words. MATCH 100% (shape: bulk). */
int func_0016A118(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_00161AE0();
    extern int func_0016A0B8();
    extern int func_0016A118();
    extern int func_00161AE0();
    extern int func_0016A0B8();
    return func_00161AE0(a1, (*(unsigned short *)((char *)(a0) + 0)), ((int)&func_0016A0B8), 0, (*(int *)((char *)(a0) + 8)), 0);
}
/* func_0016A588 — 9 words. MATCH 100% (shape: bulk). */
int func_0016A588(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_001621C4();
    extern int func_0016A520();
    extern int func_0016A588();
    extern int func_001621C4();
    extern int func_0016A520();
    return func_001621C4(a1, (*(unsigned short *)((char *)(a0) + 0)), ((int)&func_0016A520), 0, (*(int *)((char *)(a0) + 8)), 0x10000);
}
/* func_0016BCC4 — 8 words. MATCH 100% (shape: bulk). */
int func_0016BCC4(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_001621C4();
    extern int func_0016BCC4();
    extern int func_001621C4();
    return func_001621C4(a1, (*(unsigned short *)((char *)(a0) + 0)), 0, 0, (*(int *)((char *)(a0) + 8)), 265);
}
/* func_0016BF5C — 8 words. MATCH 100% (shape: bulk). */
int func_0016BF5C(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_00161AE0();
    extern int func_0016BF5C();
    extern int func_00161AE0();
    return func_00161AE0(a1, (*(unsigned short *)((char *)(a0) + 0)), 0, 0, (*(int *)((char *)(a0) + 8)), 36);
}
/* func_0016C048 — 8 words. MATCH 100% (shape: bulk). */
int func_0016C048(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_001621C4();
    extern int func_0016C048();
    extern int func_001621C4();
    return func_001621C4(a1, (*(unsigned short *)((char *)(a0) + 0)), 0, 0, (*(int *)((char *)(a0) + 8)), 64);
}
/* func_0016C150 — 8 words. MATCH 100% (shape: bulk). */
int func_0016C150(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_001627D4();
    extern int func_0016C150();
    extern int func_001627D4();
    return func_001627D4(a1, (*(unsigned short *)((char *)(a0) + 0)), 0, 0, (*(int *)((char *)(a0) + 8)), 9);
}
/* func_0016C464 — 8 words. MATCH 100% (shape: bulk). */
int func_0016C464(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_001621C4();
    extern int func_0016C464();
    extern int func_001621C4();
    return func_001621C4(a1, (*(unsigned short *)((char *)(a0) + 0)), 0, 0, (*(int *)((char *)(a0) + 8)), 0x8008);
}
/* func_0016C610 — 9 words. MATCH 100% (shape: bulk). */
int func_0016C610(int a0, int a1, int a2, int a3, int t0, int t1, int t2) {
    extern int func_00161DF0();
    extern int func_0016C5BC();
    extern int func_0016C610();
    extern int func_00161DF0();
    extern int func_0016C5BC();
    return func_00161DF0(a1, (*(unsigned short *)((char *)(a0) + 0)), a2, ((int)&func_0016C5BC), 0, (*(int *)((char *)(a0) + 8)), 17);
}
/* func_0016CA3C — 8 words. MATCH 100% (shape: bulk). */
int func_0016CA3C(int a0, int a1, int a2, int a3, int t0, int t1, int t2) {
    extern int func_00161DF0();
    extern int func_0016CA3C();
    extern int func_00161DF0();
    return func_00161DF0(a1, (*(unsigned short *)((char *)(a0) + 0)), a2, 0, 0, (*(int *)((char *)(a0) + 8)), 32);
}
/* func_0016CBE0 — 9 words. MATCH 100% (shape: bulk). */
int func_0016CBE0(int a0, int a1, int a2, int a3, int t0, int t1, int t2) {
    extern int func_00161DF0();
    extern int func_0016CACC();
    extern int func_0016CBE0();
    extern int func_00161DF0();
    extern int func_0016CACC();
    return func_00161DF0(a1, (*(unsigned short *)((char *)(a0) + 0)), a2, ((int)&func_0016CACC), 0, (*(int *)((char *)(a0) + 8)), 17);
}
/* func_0016CC78 — 9 words. MATCH 100% (shape: bulk). */
int func_0016CC78(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_001621C4();
    extern int func_0016CC34();
    extern int func_0016CC78();
    extern int func_001621C4();
    extern int func_0016CC34();
    return func_001621C4(a1, (*(unsigned short *)((char *)(a0) + 0)), ((int)&func_0016CC34), 0, (*(int *)((char *)(a0) + 8)), 0);
}
/* func_0016CEF8 — 9 words. MATCH 100% (shape: bulk). */
int func_0016CEF8(int a0, int a1, int a2, int a3, int t0, int t1, int t2) {
    extern int func_00161DF0();
    extern int func_0016CDD4();
    extern int func_0016CEF8();
    extern int func_00161DF0();
    extern int func_0016CDD4();
    return func_00161DF0(a1, (*(unsigned short *)((char *)(a0) + 0)), a2, ((int)&func_0016CDD4), 0, (*(int *)((char *)(a0) + 8)), 17);
}
/* func_0016D700 — 9 words. MATCH 100% (shape: bulk). */
int func_0016D700(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_001621C4();
    extern int func_0016D6E8();
    extern int func_0016D700();
    extern int func_001621C4();
    extern int func_0016D6E8();
    return func_001621C4(a1, (*(unsigned short *)((char *)(a0) + 0)), ((int)&func_0016D6E8), 0, (*(int *)((char *)(a0) + 8)), 1160);
}
/* func_0016D8CC — 9 words. MATCH 100% (shape: bulk). */
int func_0016D8CC(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_001621C4();
    extern int func_0016D7E8();
    extern int func_0016D8CC();
    extern int func_001621C4();
    extern int func_0016D7E8();
    return func_001621C4(a1, (*(unsigned short *)((char *)(a0) + 0)), ((int)&func_0016D7E8), 0, (*(int *)((char *)(a0) + 8)), 8);
}
/* func_0016D9C4 — 9 words. MATCH 100% (shape: bulk). */
int func_0016D9C4(int a0, int a1, int a2, int a3, int t0, int t1, int t2) {
    extern int func_00161DF0();
    extern int func_0016D8F0();
    extern int func_0016D9C4();
    extern int func_00161DF0();
    extern int func_0016D8F0();
    return func_00161DF0(a1, (*(unsigned short *)((char *)(a0) + 0)), a2, ((int)&func_0016D8F0), 0, (*(int *)((char *)(a0) + 8)), 17);
}
/* func_0016D9E8 — 9 words. MATCH 100% (shape: bulk). */
int func_0016D9E8(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_001621C4();
    extern int func_0016C634();
    extern int func_0016D9E8();
    extern int func_001621C4();
    extern int func_0016C634();
    return func_001621C4(a1, (*(unsigned short *)((char *)(a0) + 0)), ((int)&func_0016C634), 0, (*(int *)((char *)(a0) + 8)), 0x10000);
}
/* func_0016DD00 — 8 words. MATCH 100% (shape: bulk). */
int func_0016DD00(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_001621C4();
    extern int func_0016DD00();
    extern int func_001621C4();
    return func_001621C4(a1, (*(unsigned short *)((char *)(a0) + 0)), 0, 0, (*(int *)((char *)(a0) + 8)), 0x20000);
}
/* func_0016DE54 — 6 words. MATCH 100% (shape: bulk). */
int func_0016DE54(int a0, int a1, int a2, int a3) {

    extern int D_0034D434;
    extern int func_0015EA4C();
    return func_0015EA4C(D_0034D434, a0, 14, a2);
}

/* func_0016DE6C — 9 words. MATCH 100% (shape: bulk). */
int func_0016DE6C(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_001621C4();
    extern int func_0016DE54();
    extern int func_0016DE6C();
    extern int func_001621C4();
    extern int func_0016DE54();
    return func_001621C4(a1, (*(unsigned short *)((char *)(a0) + 0)), ((int)&func_0016DE54), 0, (*(int *)((char *)(a0) + 8)), 0x10000);
}
/* func_0016DF10 — 8 words. MATCH 100% (shape: bulk). */
int func_0016DF10(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_001621C4();
    extern int func_0016DF10();
    extern int func_001621C4();
    return func_001621C4(a1, (*(unsigned short *)((char *)(a0) + 0)), 0, 0, (*(int *)((char *)(a0) + 8)), 4);
}
/* func_0016E2AC — 8 words. MATCH 100% (shape: bulk). */
int func_0016E2AC(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_00161AE0();
    extern int func_0016E2AC();
    extern int func_00161AE0();
    return func_00161AE0(a1, (*(unsigned short *)((char *)(a0) + 0)), 0, 0, (*(int *)((char *)(a0) + 8)), 1);
}
/* func_0016E3A0 — 9 words. MATCH 100% (shape: bulk). */
int func_0016E3A0(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_001621C4();
    extern int func_0016E358();
    extern int func_0016E3A0();
    extern int func_001621C4();
    extern int func_0016E358();
    return func_001621C4(a1, (*(unsigned short *)((char *)(a0) + 0)), ((int)&func_0016E358), 0, (*(int *)((char *)(a0) + 8)), 8);
}
/* func_0016E5F8 — 8 words. MATCH 100% (shape: bulk). */
int func_0016E5F8(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_001621C4();
    extern int func_0016E5F8();
    extern int func_001621C4();
    return func_001621C4(a1, (*(unsigned short *)((char *)(a0) + 0)), 0, 0, (*(int *)((char *)(a0) + 8)), 392);
}
/* func_0016E720 — 9 words. MATCH 100% (shape: bulk). */
int func_0016E720(int a0, int a1, int a2, int a3, int t0, int t1, int t2) {
    extern int func_00161DF0();
    extern int func_0016E658();
    extern int func_0016E720();
    extern int func_00161DF0();
    extern int func_0016E658();
    return func_00161DF0(a1, (*(unsigned short *)((char *)(a0) + 0)), a2, ((int)&func_0016E658), 0, (*(int *)((char *)(a0) + 8)), 17);
}
/* func_0016EC64 — 9 words. MATCH 100% (shape: bulk). */
int func_0016EC64(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_001621C4();
    extern int func_00162F48();
    extern int func_0016EC64();
    extern int func_001621C4();
    extern int func_00162F48();
    return func_001621C4(a1, (*(unsigned short *)((char *)(a0) + 0)), ((int)&func_00162F48), 0, (*(int *)((char *)(a0) + 8)), 8);
}
/* func_0016F298 — 9 words. MATCH 100% (shape: bulk). */
int func_0016F298(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_001621C4();
    extern int func_0016F194();
    extern int func_0016F298();
    extern int func_001621C4();
    extern int func_0016F194();
    return func_001621C4(a1, (*(unsigned short *)((char *)(a0) + 0)), ((int)&func_0016F194), 0, (*(int *)((char *)(a0) + 8)), 0x10000);
}
/* func_0016F550 — 9 words. MATCH 100% (shape: bulk). */
int func_0016F550(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_001621C4();
    extern int func_0016F46C();
    extern int func_0016F550();
    extern int func_001621C4();
    extern int func_0016F46C();
    return func_001621C4(a1, (*(unsigned short *)((char *)(a0) + 0)), ((int)&func_0016F46C), 0, (*(int *)((char *)(a0) + 8)), 8);
}
/* func_0016F7D8 — 9 words. MATCH 100% (shape: bulk). */
int func_0016F7D8(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_001627D4();
    extern int func_00162F48();
    extern int func_0016F7D8();
    extern int func_001627D4();
    extern int func_00162F48();
    return func_001627D4(a1, (*(unsigned short *)((char *)(a0) + 0)), ((int)&func_00162F48), 0, (*(int *)((char *)(a0) + 8)), 12);
}



































/* func_0016F9A0 — 3 words. MATCH 100% (shape: hand). */
int func_0016F9A0(int a0, int a1, int a2, int a3, void *t0) {
    extern int ehsys_1738DF69();
    extern int func_0016F9A0();
    extern int ehsys_1738DF69();
    unsigned short v0 = *(unsigned short *)t0;
    return ehsys_1738DF69(v0 & 0x3FFF);
}
/* func_0016FAEC — 9 words. MATCH 100% (shape: bulk). */
int func_0016FAEC(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_001621C4();
    extern int func_0016FAA8();
    extern int func_0016FAEC();
    extern int func_001621C4();
    extern int func_0016FAA8();
    return func_001621C4(a1, (*(unsigned short *)((char *)(a0) + 0)), ((int)&func_0016FAA8), 0, (*(int *)((char *)(a0) + 8)), 8);
}
/* func_0016FC80 — 9 words. MATCH 100% (shape: bulk). */
int func_0016FC80(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_00161AE0();
    extern int func_0016FBAC();
    extern int func_0016FC80();
    extern int func_00161AE0();
    extern int func_0016FBAC();
    return func_00161AE0(a1, (*(unsigned short *)((char *)(a0) + 0)), ((int)&func_0016FBAC), 0, (*(int *)((char *)(a0) + 8)), 18);
}
/* func_0016FCA4 — 9 words. MATCH 100% (shape: bulk). */
int func_0016FCA4(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_0016164C();
    extern int func_0016FCA4();
    extern int func_0016164C();
    return func_0016164C(a1, (*(unsigned short *)((char *)(a0) + 0)), 0, 0, (*(int *)((char *)(a0) + 8)), ((a2 << 25) | 0x2));
}



/* func_00170778 — 3 words. MATCH 100% (shape: hand). */
int func_00170778(void *unused, void *p, int a2) {
    extern int func_0001E84C();
    extern int func_00170778();
    extern int func_0001E84C();
    return func_0001E84C(p, 0, a2);
}
/* func_00171104 — 6 words. MATCH 100% (shape: bulk). */
int func_00171104(int a0, int a1, int a2) {
    extern int func_00171104();
    extern int func_0017111C();
    extern int func_0017111C();
    return func_0017111C((*(unsigned short *)((char *)(a0) + 0)), ((*(unsigned short *)((char *)(a0) + 2)) ^ (*(unsigned short *)((char *)(a0) + 10))), (*(unsigned short *)((char *)(a0) + 0)));
}
/* func_00171740 — 19 words. MATCH 100% (shape: m2c). */
void func_00171740(s32 arg0, int arg1) {
    extern int func_00171678();
    extern int func_00171740();
    func_00171678(0, arg0, arg1);
    func_00171678(1, arg0, arg1);
}
/* func_00171944 — 2 words. MATCH 100% (shape: bulk). */
int func_00171944(int a0, int a1) {
    extern int func_0017178C();
    extern int func_00171944();
    extern int func_0017178C();
    return func_0017178C(a0, 0);
}
/* func_0017194C — 2 words. MATCH 100% (shape: bulk). */
int func_0017194C(int a0, int a1) {
    extern int func_0017178C();
    extern int func_0017194C();
    extern int func_0017178C();
    return func_0017178C(a0, 1);
}
/* func_00171A14 — 14 words. MATCH 100% (shape: m2c). */
void func_00171A14(s32 arg0) {
    extern int func_00171954();
    extern int func_00171A14();
    func_00171954(0, arg0);
    func_00171954(1, arg0);
}
/* func_00174ED0 — 24 words. MATCH 100% (shape: m2c). */
void func_00174ED0(s32 arg0, int arg1, int arg2) {
    extern int func_00174DDC();
    extern int func_00174ED0();
    func_00174DDC(0, arg0, arg1, arg2);
    func_00174DDC(1, arg0, arg1, arg2);
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
/* func_0017810C — 6 words. MATCH 100% (shape: single-switch). */
s32 func_0017810C(s32 arg0) {
    extern int func_0017810C();

    switch (arg0) {
    case 0x239F:
        return 2;
        break;
    }
    return 1;
}
/* func_0017AA58 — 2 words. MATCH 100% (shape: m2c). */
s32 func_0017AA58(void) {
    extern int func_0017AA58();
    return 0;
}
/* func_0017AA60 — 2 words. MATCH 100% (shape: m2c). */
s32 func_0017AA60(void) {
    extern int func_0017AA60();
    return 2;
}
/* func_0017BB0C — 2 words. MATCH 100% (shape: hand). */
int func_0017BB0C(void *a0, int a1) {
    extern int func_0017BB0C();
    extern int func_0017BB14();
    extern int func_0017BB14();
    return func_0017BB14(a0, a1, -1);
}
/* func_0017C27C — 10 words. MATCH 100% (shape: bool-fold). */
s32 func_0017C27C(void) {
    extern int func_0017B1EC();
    extern int func_0017C27C();
    s32 temp_v0;

    temp_v0 = func_0017B1EC();
    if (!temp_v0) {
        return 0;
    }
    return (*(int *)((char *)temp_v0 + 0x10));
}
/* func_0017C300 — 10 words. MATCH 100% (shape: bool-fold). */
s32 func_0017C300(void) {
    extern int func_0017B1EC();
    extern int func_0017C300();
    s32 temp_v0;

    temp_v0 = func_0017B1EC();
    if (!temp_v0) {
        return 0;
    }
    return (*(int *)((char *)temp_v0 + 0x14));
}
/* func_0017CA50 — 16 words. MATCH 100% (shape: m2c). */
void func_0017CA50(s32 arg0, int arg1) {
    extern int func_000827C4();
    extern int func_0017C7BC();
    extern int func_0017CA50();
    func_0017C7BC(arg0, arg1, func_000827C4());
}
/* func_0017CA90 — 16 words. MATCH 100% (shape: m2c). */
void func_0017CA90(s32 arg0, int arg1) {
    extern int func_00083084();
    extern int func_0017C7BC();
    extern int func_0017CA90();
    func_0017C7BC(arg0, arg1, func_00083084());
}
/* func_00183700 — 6 words. MATCH 100% (shape: bulk). */
int func_00183700(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_0017E33C();
    extern int func_00183700();
    extern int func_0017E33C();
    return func_0017E33C(a0, (-1), a1, 1, a2, a3);
}
/* func_00183718 — 6 words. MATCH 100% (shape: bulk). */
int func_00183718(int a0, int a1, int a2, int a3, int t0, int t1) {
    extern int func_0017E33C();
    extern int func_00183718();
    extern int func_0017E33C();
    return func_0017E33C(a0, (-1), a1, 0, a2, a3);
}
/* func_00187B88 — 10 words. MATCH 100% (shape: hand). */
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
#define M2C_UNK int

extern int func_00187BD8();

s32 func_00187B88(s32 arg0, s32 arg1) {
    extern int func_00187B88();
    extern int func_00187BD8();
    s32 sp1C;

    sp1C = 0;
    func_00187BD8(arg0, arg1, &sp1C, 0);
    return sp1C;
}
/* func_00187BB0 — 10 words. MATCH 100% (shape: hand). */
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
#define M2C_UNK int

extern int func_00187BD8();

s32 func_00187BB0(s32 arg0, s32 arg1) {
    extern int func_00187BB0();
    extern int func_00187BD8();
    s32 sp1C;

    sp1C = 0;
    func_00187BD8(arg0, arg1, 0, &sp1C);
    return sp1C;
}


/* func_0018C938 — 9 words. MATCH 100% (shape: bulk). */
int func_0018C938(int a0, int a1, int a2, int a3, int t0, int t1, int t2, int t3) {
    extern int func_0018C938();
    extern int func_0018C95C();
    extern int func_0018C95C();
    return func_0018C95C(a0, (-1), a1, a2, a3, 0, 0, 6);
}
/* func_00197164 — 8 words. MATCH 100% (shape: hand). */
void func_00197164(void *a0, void *a1) {

    extern void func_00197184();
    int local = 0;
    func_00197184(a0, a1, &local);
}

/* func_00199854 — 4 words. MATCH 100% (shape: bulk). */
int func_00199854(int a0, int a1, int a2, int a3) {
    extern int func_00199854();
    extern int func_002A2AD8();
    extern int func_002A2AD8();
    return func_002A2AD8(a0, 0, a1, 0);
}




/* func_0019A408 — 8 words. MATCH 100% (shape: hand). */
int func_0019A408(void *a0, int a1) {
    extern int func_000844B8();
    extern int func_0019A408();
    extern int func_000844B8();
    return func_000844B8(a0, a1 & 0xFFFF) > 0;
}
/* func_0019BE04 — 18 words. MATCH 100% (shape: m2c). */
void func_0019BE04(s32 arg0, int arg1) {
    extern int func_00083084();
    extern int func_0017C7BC();
    extern int func_0019BCC0();
    extern int func_0019BE04();
    func_0019BCC0(func_0017C7BC(arg0, arg1, func_00083084()));
}
/* func_0019BE4C — 22 words. MATCH 100% (shape: bool-fold). */
s32 func_0019BE4C(s32 arg0, int arg1) {
    extern int func_00083084();
    extern int func_0017C7BC();
    extern int func_0019BCC0();
    extern int func_0019BE4C();
    s32 temp_v0;

    temp_v0 = func_0019BCC0(func_0017C7BC(arg0, arg1, func_00083084()));
    if (!temp_v0) {
        return 0;
    }
    return 0x50000 - temp_v0;
}
/* func_0019CAB0 — 9 words. MATCH 100% (shape: hand). */
int func_0019CAB0(void *a0, void *a1) {

    extern void func_0019C938();
    int local = 0;
    func_0019C938(a0, a1, &local);
    return local;
}

/* func_0019F850 — 2 words. MATCH 100% (shape: bulk). */
int func_0019F850(int a0, int a1, int a2) {
    extern int func_0019F850();
    extern int func_0019F858();
    extern int func_0019F858();
    return func_0019F858(a0, a1, (-1));
}
/* func_0019F858 — 9 words. MATCH 100% (shape: m2c). */
s32 func_0019F858(void) {
    extern int func_0019F144();
    extern int func_0019F858();
    return func_0019F144() == 0x64;
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
/* func_001A1270 — 2 words. MATCH 100% (shape: m2c). */
s32 func_001A1270(void) {
    extern int func_001A1270();
    return 1;
}
/* func_001A369C — 21 words. MATCH 100% (shape: m2c). */
s32 func_001A369C(s32 arg0, int arg1) {
    extern int ehsys_EED9C836();
    extern int func_00089E9C();
    extern int func_001A369C();
    if ((ehsys_EED9C836(arg1) != 0) && (func_00089E9C(arg0, 0x17A3, -1) != 0)) {
        return 0;
    }
    return 1;
}
/* func_001CEA8C — 19 words. MATCH 100% (shape: m2c). */
void func_001CEA8C(s32 arg0) {
    extern int func_001A4698();
    extern int func_001A8530();
    extern int func_001CDF58();
    extern int func_001CEA8C();
    func_001A4698(2);
    func_001CDF58(arg0, 0, 0, 0);
    func_001A8530(arg0, 0, 0);
}
/* func_001E308C — 9 words. MATCH 100% (shape: hand). */
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
#define M2C_UNK int

extern int func_0007FD4C();

s32 func_001E308C(void) {
    extern int func_0007FD4C();
    extern int func_001E308C();
    return !(func_0007FD4C() != 0);
}

/* func_001ED714 — 2 words. MATCH 100% (shape: bulk). */
int func_001ED714(int arg1, int arg2) {
    extern int func_00095D40();
    extern int func_001ED714();
    extern int func_00095D40();
    return func_00095D40(arg1, arg2);
}
/* func_001F2C48 — 4 words. MATCH 100% (shape: hand). */
int func_001F2C48(void) {

    extern int func_002F6B08();
    extern char D_0034BEBC;
    return func_002F6B08(&D_0034BEBC, 0x20);
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
/* func_001FB318 — 8 words. MATCH 100% (shape: bulk). */
int func_001FB318(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6) {
    extern int func_001FB1BC();
    extern int func_001FB318();
    extern int func_001FB1BC();
    return func_001FB1BC(arg1, 65535, arg2, arg3, arg4, arg5);
}
/* func_001FB544 — 2 words. MATCH 100% (shape: m2c). */
s16 func_001FB544(void *arg0) {
    extern int func_001FB544();
    return (*(int *)((char *)arg0 + 0x18));
}
/* func_001FBF28 — 18 words. MATCH 100% (shape: m2c). */
s32 func_001FBF28(s16 *arg0) {
    extern int func_00089E9C();
    extern int func_0008E8A4();
    extern int func_001FBF28();
    s16 temp_s0;
    s32 var_v0;

    temp_s0 = *arg0;
    var_v0 = func_00089E9C(temp_s0, 0x1468, -1) != 0;
    if (var_v0 != 0) {
        var_v0 = func_0008E8A4(temp_s0) < 0;
    }
    return var_v0;
}

/* func_001FC194 — 3 words. MATCH 100% (shape: hand). */
int func_001FC194(void *a0) {
    extern int func_001FBF70();
    extern int func_001FC194();
    extern int func_001FBF70();
    return func_001FBF70(a0, 0, 0);
}
/* func_001FC1A0 — 3 words. MATCH 100% (shape: bulk). */
int func_001FC1A0(int arg1, int arg2, int arg3) {
    extern int func_001FBF70();
    extern int func_001FC1A0();
    extern int func_001FBF70();
    return func_001FBF70(arg1, 1, 0);
}
/* func_001FC1AC — 3 words. MATCH 100% (shape: bulk). */
int func_001FC1AC(int arg1, int arg2, int arg3) {
    extern int func_001FBF70();
    extern int func_001FC1AC();
    extern int func_001FBF70();
    return func_001FBF70(arg1, 0, 1);
}
/* func_001FC1B8 — 18 words. MATCH 100% (shape: m2c). */
s32 func_001FC1B8(s16 *arg0) {
    extern int func_00089E9C();
    extern int func_0008E8A4();
    extern int func_001FC1B8();
    s16 temp_s0;
    s32 var_v0;

    temp_s0 = *arg0;
    var_v0 = func_00089E9C(temp_s0, 0x17AF, -1) != 0;
    if (var_v0 != 0) {
        var_v0 = func_0008E8A4(temp_s0) < 0;
    }
    return var_v0;
}
/* func_001FCA04 — 4 words. MATCH 100% (shape: m2c). */
s32 func_001FCA04(void *arg0) {
    extern int func_001FCA04();
    return ((*(int *)((char *)arg0 + 0x14)) & 1) != 0;
}
/* func_001FCA14 — 4 words. MATCH 100% (shape: m2c). */
s32 func_001FCA14(void *arg0) {
    extern int func_001FCA14();
    return ((*(int *)((char *)arg0 + 0x14)) & 2) != 0;
}
/* func_001FCA24 — 4 words. MATCH 100% (shape: m2c). */
s32 func_001FCA24(void *arg0) {
    extern int func_001FCA24();
    return ((*(int *)((char *)arg0 + 0x14)) & 4) != 0;
}
/* func_001FCA34 — 4 words. MATCH 100% (shape: m2c). */
s32 func_001FCA34(void *arg0) {
    extern int func_001FCA34();
    return ((*(int *)((char *)arg0 + 0x14)) & 8) != 0;
}
/* func_001FCA44 — 4 words. MATCH 100% (shape: m2c). */
s32 func_001FCA44(void *arg0) {
    extern int func_001FCA44();
    return ((*(int *)((char *)arg0 + 0x14)) & 0x10) != 0;
}
/* func_001FCA54 — 4 words. MATCH 100% (shape: m2c). */
s32 func_001FCA54(void *arg0) {
    extern int func_001FCA54();
    return ((*(int *)((char *)arg0 + 0x14)) & 0x20) != 0;
}
/* func_001FCA64 — 4 words. MATCH 100% (shape: m2c). */
s32 func_001FCA64(void *arg0) {
    extern int func_001FCA64();
    return ((*(int *)((char *)arg0 + 0x14)) & 0x40) != 0;
}
/* func_001FCA74 — 4 words. MATCH 100% (shape: m2c). */
s32 func_001FCA74(void *arg0) {
    extern int func_001FCA74();
    return ((*(int *)((char *)arg0 + 0x14)) & 0x80) != 0;
}
/* func_001FCA84 — 3 words. MATCH 100% (shape: m2c). */
s32 func_001FCA84(void *arg0) {
    extern int func_001FCA84();
    return (*(int *)((char *)arg0 + 0x1C)) != 0;
}
/* func_001FCA90 — 3 words. MATCH 100% (shape: m2c). */
s32 func_001FCA90(void *arg0) {
    extern int func_001FCA90();
    return (*(int *)((char *)arg0 + 0x20)) != 0;
}
/* func_001FD84C — 2 words. MATCH 100% (shape: m2c). */
s32 func_001FD84C(void) {
    extern int func_001FD84C();
    return 1;
}
/* func_001FD854 — 2 words. MATCH 100% (shape: m2c). */
s32 func_001FD854(void) {
    extern int func_001FD854();
    return 0;
}
/* func_001FD85C — 2 words. MATCH 100% (shape: bulk). */
int func_001FD85C(int arg1, int arg2, int arg3) {
    extern int func_001FD85C();
    extern int func_002E94A4();
    extern int func_002E94A4();
    return func_002E94A4(arg1, (arg3 | 4096));
}
/* func_001FD864 — 14 words. MATCH 100% (shape: m2c). */
s32 func_001FD864(s32 arg0) {
    extern int func_000C3644();
    extern int func_001FD864();
    extern int func_002E94A4();
    return func_002E94A4(arg0, func_000C3644() | 0x1000) >= 0;
}
/* func_001FD89C — 21 words. MATCH 100% (shape: bool-fold). */
s32 func_001FD89C(s32 arg0) {
    extern int func_000C3644();
    extern int func_001FD89C();
    extern int func_002E94A4();
    s32 temp_v0;
    s32 var_s0;

    temp_v0 = func_000C3644();
    var_s0 = 0;
    if ((temp_v0 & 1) && (!func_002E94A4(arg0, temp_v0 | 0x1000))) {
        var_s0 = 1;
    }
    return var_s0;
}
/* func_001FDBAC — 2 words. MATCH 100% (shape: bulk). */
int func_001FDBAC(int arg1, int arg2) {
    extern int func_00186A10();
    extern int func_001FDBAC();
    extern int func_00186A10();
    return func_00186A10(arg1, 0);
}
/* func_001FEB48 — 9 words. MATCH 100% (shape: hand). */
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
#define M2C_UNK int

extern int func_002CEAB4();
/* func_001FEB20 — 10 words. MATCH 100% (shape: hand). */
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
#define M2C_UNK int

extern int func_001FE8E4();

s32 func_001FEB20(s32 arg0) {
    extern int func_001FE8E4();
    extern int func_001FEB20();
    return func_001FE8E4(arg0, 0, 0) == 1;
}


s32 func_001FEB48(void) {
    extern int func_001FEB48();
    extern int func_002CEAB4();
    return !(func_002CEAB4(0x18) != 0);
}

/* func_001FEF90 — 7 words. MATCH 100% (shape: bulk). */
int func_001FEF90(int arg1, int arg2, int arg3, int arg4) {
    extern int func_001FEF90();
    extern int func_0027E710();
    extern int func_0027E710();
    return func_0027E710(((*(unsigned short *)((char *)arg1 + 2)) ^ (*(unsigned short *)((char *)arg1 + 10))), (*(unsigned short *)(arg1)), (*(unsigned short *)((char *)arg1 + 22)), 0);
}
/* func_00200B44 — 4 words. MATCH 100% (shape: bulk). */
int func_00200B44(int arg1, int arg2) {
    extern int func_000A3CB4();
    extern int func_00200B44();
    extern int func_000A3CB4();
    return func_000A3CB4(((*(unsigned short *)((char *)arg1 + 2)) ^ (*(unsigned short *)((char *)arg1 + 10))), (*(unsigned short *)((char *)arg1 + 2)));
}
/* func_00200B54 — 5 words. MATCH 100% (shape: bulk). */
int func_00200B54(int arg1, int arg2) {
    extern int func_000A3730();
    extern int func_00200B54();
    extern int func_000A3730();
    return func_000A3730(((*(unsigned short *)((char *)arg1 + 2)) ^ (*(unsigned short *)((char *)arg1 + 10))), 1);
}
/* func_00200F8C — 5 words. MATCH 100% (shape: bulk). */
int func_00200F8C(int arg1, int arg2) {
    extern int func_00200F8C();
    extern int func_0026B324();
    extern int func_0026B324();
    return func_0026B324(((*(unsigned short *)((char *)arg1 + 2)) ^ (*(unsigned short *)((char *)arg1 + 10))), (*(unsigned short *)(arg1)));
}
/* func_00201D6C — 5 words. MATCH 100% (shape: bulk). */
int func_00201D6C(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6) {
    extern int func_00201AC8();
    extern int func_00201D6C();
    extern int func_00201AC8();
    return func_00201AC8(arg1, arg2, 1, 1, 0, 0);
}
/* func_00201D80 — 5 words. MATCH 100% (shape: bulk). */
int func_00201D80(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6) {
    extern int func_00201AC8();
    extern int func_00201D80();
    extern int func_00201AC8();
    return func_00201AC8(arg1, arg2, 1, 1, 1, 0);
}
/* func_00201D94 — 5 words. MATCH 100% (shape: bulk). */
int func_00201D94(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6) {
    extern int func_00201AC8();
    extern int func_00201D94();
    extern int func_00201AC8();
    return func_00201AC8(arg1, arg2, 1, 1, 0, 1);
}

/* func_00204854 — 11 words. MATCH 100% (shape: hand). */
int func_00204854(void *a0, int a1) {
    extern int func_00204664();
    extern int func_00204854();
    extern int func_00204664();
    unsigned short a2 = *(unsigned short *)a0;
    return !(func_00204664(a0, a1, a2, 0, 1) < 1);
}
/* func_002050E4 — 9 words. MATCH 100% (shape: hand). */
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
#define M2C_UNK int

extern int func_001FE728();

s32 func_002050E4(s32 arg0) {
    extern int func_001FE728();
    extern int func_002050E4();
    return func_001FE728(arg0, 0, 0) != 0;
}
/* func_00205BB8 — 9 words. MATCH 100% (shape: hand). */
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
#define M2C_UNK int

extern int func_00205108();

s32 func_00205BB8(s32 arg0, s32 arg1) {
    extern int func_00205108();
    extern int func_00205BB8();
    return func_00205108(arg0, arg1, 0, 0) != 0;
}


/* func_002061AC — 3 words. MATCH 100% (shape: bulk). */
int func_002061AC(int arg1, int arg2, int arg3, int arg4) {
    extern int func_0020606C();
    extern int func_002061AC();
    extern int func_0020606C();
    return func_0020606C(arg1, arg2, 0, -1);
}

/* func_00206544 — 2 words. MATCH 100% (shape: hand). */
int func_00206544(void *a0, int a1) {
    extern int func_00206270();
    extern int func_00206544();
    extern int func_00206270();
    return func_00206270(a0, a1, -1);
}
/* func_00208E88 — 7 words. MATCH 100% (shape: bulk). */
int func_00208E88(int arg1, int arg2, int arg3) {
    extern int func_00208C88();
    extern int func_00208E88();
    extern int func_00208C88();
    return func_00208C88(arg1, (1 << ((*(unsigned short *)((char *)arg1 + 4)) + ((*(unsigned short *)((char *)arg1 + 2)) << 4))), 1);
}
/* func_0020C2EC — 18 words. MATCH 100% (shape: m2c). */
s32 func_0020C2EC(s32 arg0) {
    extern int func_0008F280();
    extern int func_001FDC38();
    extern int func_0020C2EC();
    s32 var_v0;

    var_v0 = func_0008F280(0x215B) != 0;
    if (var_v0 != 0) {
        var_v0 = func_001FDC38(arg0, 1, 0) != 0;
    }
    return var_v0;
}
/* func_0020D438 — 6 words. MATCH 100% (shape: bulk). */
int func_0020D438(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6) {
    extern int func_00202408();
    extern int func_0020D438();
    extern int func_00202408();
    return func_00202408(arg1, 700, -1, 0, 1, 2);
}
/* func_0020E888 — 2 words. MATCH 100% (shape: bulk). */
int func_0020E888(int arg1, int arg2, int arg3) {
    extern int func_0020E678();
    extern int func_0020E888();
    extern int func_0020E678();
    return func_0020E678(arg1, arg2, 0);
}
/* func_00210BD0 — 21 words. MATCH 100% (shape: bool-fold). */
s32 func_00210BD0(s32 arg0, u16 *arg1) {
    extern int ehsys_133DA48C();
    extern int func_00205108();
    extern int func_00210BD0();
    if (!ehsys_133DA48C(*arg1)) {
        return 0;
    }
    return func_00205108(arg0, arg1, 0, 0) != 0;
}
/* func_002126E8 — 21 words. MATCH 100% (shape: bool-fold). */
s32 func_002126E8(s32 arg0, u16 *arg1) {
    extern int ehsys_EED9C836();
    extern int func_00205108();
    extern int func_002126E8();
    if (!ehsys_EED9C836(*arg1)) {
        return 0;
    }
    return func_00205108(arg0, arg1, 0, 0) != 0;
}
/* func_0021AC5C — 2 words. MATCH 100% (shape: m2c). */
s32 func_0021AC5C(void) {
    extern int func_0021AC5C();
    return 1;
}
/* func_0021DCEC — 7 words. MATCH 100% (shape: bulk). */
int func_0021DCEC(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7) {
    extern int func_00201F7C();
    extern int func_0021DCEC();
    extern int func_00201F7C();
    return func_00201F7C(arg1, 4041, 0, 0, 1, 1, 0);
}
/* func_0021DFF8 — 4 words. MATCH 100% (shape: bulk). */
int func_0021DFF8(int arg1, int arg2, int arg3, int arg4, int arg5) {
    extern int func_0021DE64();
    extern int func_0021DFF8();
    extern int func_0021DE64();
    return func_0021DE64(arg1, arg2, 1, 1, 0);
}

/* func_0021F1B8 — 4 words. MATCH 100% (shape: hand). */
int func_0021F1B8(void *a0, int a1) {
    extern int func_0021DE64();
    extern int func_0021F1B8();
    extern int func_0021DE64();
    return func_0021DE64(a0, a1, 1, 1, 0x18E8);
}
/* func_0021F7A4 — 7 words. MATCH 100% (shape: bulk). */
int func_0021F7A4(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7) {
    extern int func_00201F7C();
    extern int func_0021F7A4();
    extern int func_00201F7C();
    return func_00201F7C(arg1, 5880, 1, 0, 1, 1, 1);
}
/* func_0021F8C0 — 6 words. MATCH 100% (shape: bulk). */
int func_0021F8C0(int arg1, int arg2, int arg3) {
    extern int func_00078AAC();
    extern int func_0021F8C0();
    extern int func_00078AAC();
    return func_00078AAC((1 - (*(unsigned short *)((char *)arg1 + 2))), 11, 4769);
}
/* func_00224400 — 7 words. MATCH 100% (shape: bulk). */
int func_00224400(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7) {
    extern int func_00201F7C();
    extern int func_00224400();
    extern int func_00201F7C();
    return func_00201F7C(arg1, 6251, 1, 0, 1, 1, 0);
}
/* func_00226158 — 9 words. MATCH 100% (shape: hand). */
int func_00226158(void *a0, int a1) {
    extern int func_00226158();
    extern int func_002531FC();
    extern int func_002531FC();
    return func_002531FC(a0, a1, 0) >= 0;
}
/* func_0022648C — 7 words. MATCH 100% (shape: bulk). */
int func_0022648C(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7) {
    extern int func_00201F7C();
    extern int func_0022648C();
    extern int func_00201F7C();
    return func_00201F7C(arg1, 6481, 2, 1, 1, 1, 1);
}


/* func_00226980 — 3 words. MATCH 100% (shape: hand). */
int func_00226980(int unused, unsigned short *a1) {
    extern int func_00226980();
    extern int func_002836D4();
    extern int func_002836D4();
    return func_002836D4(*a1, 1);
}

/* func_002270D0 — 3 words. MATCH 100% (shape: bulk). */
int func_002270D0(int arg1, int arg2) {
    extern int func_002270D0();
    extern int func_0027D058();
    extern int func_0027D058();
    return func_0027D058((*(unsigned short *)((char *)arg1 + 2)), 0);
}
/* func_00229958 — 17 words. MATCH 100% (shape: m2c). */
s32 func_00229958(s32 arg0) {
    extern int ehsys_98E07D26();
    extern int ehsys_CF199BAE();
    extern int func_00229958();
    s32 var_v0;

    var_v0 = ehsys_98E07D26() == 9;
    if (var_v0 != 0) {
        var_v0 = ehsys_CF199BAE(arg0) >= 5;
    }
    return var_v0;
}
/* func_0022999C — 17 words. MATCH 100% (shape: m2c). */
s32 func_0022999C(s32 arg0) {
    extern int ehsys_98E07D26();
    extern int ehsys_CF199BAE();
    extern int func_0022999C();
    s32 var_v0;

    var_v0 = ehsys_98E07D26() == 9;
    if (var_v0 != 0) {
        var_v0 = ehsys_CF199BAE(arg0) >= 7;
    }
    return var_v0;
}

/* func_00229EB0 — 7 words. MATCH 100% (shape: bulk). */
int func_00229EB0(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7) {
    extern int func_00201F7C();
    extern int func_00229EB0();
    extern int func_00201F7C();
    return func_00201F7C(arg1, 6866, 1, 0, 1, 1, 0);
}

/* func_0022A478 — 6 words. MATCH 100% (shape: bulk). */
int func_0022A478(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6) {
    extern int func_00202408();
    extern int func_0022A478();
    extern int func_00202408();
    return func_00202408(arg1, 500, -1, 0, 1, 2);
}
/* func_00230F24 — 29 words. MATCH 100% (shape: hand). */
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
#define M2C_UNK int

extern int func_00200550();
extern int func_00206270();
/* func_0022E150 — 4 words. MATCH 100% (shape: bulk). */
int func_0022E150(int arg1, int arg2) {

    extern int func_0008BE60();
    extern char ehsys_0E47B027;
    return func_0008BE60((*(unsigned short *)((char *)arg1 + 2)), ((int)&ehsys_0E47B027));
}

s32 func_00230F24(s32 arg0, s32 arg1) {
    extern int func_00200550();
    extern int func_00206270();
    extern int func_00230F24();
    s32 var_s0;
    s32 var_v0;

    var_v0 = arg1 != 0;
    var_s0 = 0;
    if (var_v0 != 0) {
        var_v0 = func_00200550(arg0, arg1, 0) != 0;
    }
    if ((var_v0 != 0) && (func_00206270(arg0, arg1, -1) != 0)) {
        var_s0 = 1;
    }
    return var_s0;
}


/* func_002337C8 — 7 words. MATCH 100% (shape: bulk). */
int func_002337C8(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7) {
    extern int func_00201F7C();
    extern int func_002337C8();
    extern int func_00201F7C();
    return func_00201F7C(arg1, 6315, 3, 0, 1, 1, 0);
}
/* func_0023797C — 17 words. MATCH 100% (shape: m2c). */
s32 func_0023797C(s32 arg0) {
    extern int ehsys_98E07D26();
    extern int ehsys_CF199BAE();
    extern int func_0023797C();
    s32 var_v0;

    var_v0 = ehsys_98E07D26() == 0x15;
    if (var_v0 != 0) {
        var_v0 = ehsys_CF199BAE(arg0) >= 5;
    }
    return var_v0;
}
/* func_002379C0 — 16 words. MATCH 100% (shape: m2c). */
s32 func_002379C0(s32 arg0) {
    extern int ehsys_98E07D26();
    extern int ehsys_CF199BAE();
    extern int func_002379C0();
    s32 var_v0;

    var_v0 = ehsys_98E07D26() == 0x15;
    if (var_v0 != 0) {
        var_v0 = ehsys_CF199BAE(arg0) < 5;
    }
    return var_v0;
}

/* func_0023BC88 — 6 words. MATCH 100% (shape: bulk). */
int func_0023BC88(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6) {
    extern int func_00202408();
    extern int func_0023BC88();
    extern int func_00202408();
    return func_00202408(arg1, 500, -1, 0, 1, 3);
}
/* func_00245238 — 8 words. MATCH 100% (shape: m2c). */
s32 func_00245238(void) {
    extern int func_00244F78();
    extern int func_00245238();
    return func_00244F78() != 0;
}
/* func_00253EBC — 4 words. MATCH 100% (shape: bulk). */
int func_00253EBC(int arg1, int arg2) {

    extern int func_002F6B08();
    extern char D_0034C630;
    return func_002F6B08(((int)&D_0034C630), 8);
}

/* func_00256F64 — 8 words. MATCH 100% (shape: bulk). */
int func_00256F64(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6) {
    extern int func_00255F8C();
    extern int func_00256F64();
    extern int func_00255F8C();
    return func_00255F8C(arg1, ((*(unsigned short *)((char *)arg1 + 2)) ^ (*(unsigned short *)((char *)arg1 + 10))), (*(short *)(arg1)), (*(short *)((char *)arg1 + 4)), (*(short *)((char *)arg1 + 8)), arg2);
}
/* func_0025E5F8 — 3 words. MATCH 100% (shape: hand). */
void func_0025E5F8(void) {
    extern u16 D_0034BFA8;
    extern int func_0025E5F8();
    D_0034BFA8 = 0;
}
/* func_00265F44 — 24 words. MATCH 100% (shape: bool-fold). */
s32 func_00265F44(s32 arg0, int arg1, int arg2) {
    extern int func_00265748();
    extern int func_00265F44();
    extern int func_002CEAB4();
    if (!func_002CEAB4(0x19)) {
        return func_00265748(arg0, arg1, arg2) != 0;
    }
    return 1;
}
/* func_00266AF0 — 15 words. MATCH 100% (shape: bool-fold). */
s32 func_00266AF0(s32 arg0) {
    extern int ehsys_67312719();
    extern int ehsys_FE91A2EC();
    extern int func_00266AF0();
    if (!ehsys_67312719()) {
        return ehsys_FE91A2EC(arg0);
    }
    return 3;
}
/* func_0026B544 — 4 words. MATCH 100% (shape: bulk). */
int func_0026B544(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_00322E38;
    return func_002EED24(arg1, ((int)&D_00322E38), 3);
}
/* func_00276E10 — 11 words. MATCH 100% (shape: m2c). */
s32 func_00276E10(s32 arg0, s32 arg1) {
    extern int func_00276E10();
    if ((arg1 != 0) && ((u32) (arg0 + 2) < 2U)) {
        return 0;
    }
    return arg0 < 0;
}
/* func_00276FC4 — 18 words. MATCH 100% (shape: bool-fold). */
s32 func_00276FC4(s32 arg0) {
    extern int func_0008A0D0();
    extern int func_001A0D94();
    extern int func_00276FC4();
    if (!func_0008A0D0(0x1A77)) {
        return func_001A0D94(arg0, 0x1D17, 0) > 0;
    }
    return 1;
}
/* func_002774E4 — 29 words. MATCH 100% (shape: m2c). */
s32 func_002774E4(s32 arg0) {
    extern int func_002774E4();
    extern int func_002EF404();
    if ((func_002EF404() != 0) && (arg0 != 0x2349) && (arg0 != 0x2079) && (arg0 != 0x2078) && (arg0 != 0x2075) && (arg0 != 0x200F)) {
        return 1;
    }
    return 0;
}

/* func_00277558 — 2 words. MATCH 100% (shape: bulk). */
int func_00277558(int arg1) {
    extern int func_0002B388();
    extern int func_00277558();
    extern int func_0002B388();
    return func_0002B388(arg1);
}
/* func_0027C4C4 — 12 words. MATCH 100% (shape: m2c). */
void func_0027C4C4(s32 arg0) {
    extern int func_0017B640();
    extern int func_0027C32C();
    extern int func_0027C4C4();
    func_0027C32C(arg0, func_0017B640());
}
/* func_0027D19C — 9 words. MATCH 100% (shape: m2c). */
s32 func_0027D19C(void) {
    extern int func_0008A0D0();
    extern int func_0027D19C();
    return func_0008A0D0(0x1FFF) <= 0;
}

/* func_0027FBC0 — 2 words. MATCH 100% (shape: bulk). */
int func_0027FBC0(int arg1, int arg2, int arg3) {
    extern int func_0027FBC0();
    extern int func_0027FBC8();
    extern int func_0027FBC8();
    return func_0027FBC8(arg1, arg2, 0);
}

/* func_00280844 — 2 words. MATCH 100% (shape: bulk). */
int func_00280844(int arg1, int arg2, int arg3) {
    extern int func_00280844();
    extern int func_0028084C();
    extern int func_0028084C();
    return func_0028084C(arg1, arg2, 0);
}

/* func_00281260 — 5 words. MATCH 100% (shape: bulk). */
int func_00281260(int arg1, int arg2, int arg3, int arg4, int arg5) {
    extern int func_002810B0();
    extern int func_00281260();
    extern int func_002810B0();
    return func_002810B0(arg1, 100, 1000, 100, -800);
}
/* func_00283E94 — 4 words. MATCH 100% (shape: bulk). */
int func_00283E94(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_00323404;
    return func_002EED24(arg1, ((int)&D_00323404), 13);
}
/* func_00283EA4 — 4 words. MATCH 100% (shape: bulk). */
int func_00283EA4(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_00323420;
    return func_002EED24(arg1, ((int)&D_00323420), 3);
}
/* func_00283EB4 — 4 words. MATCH 100% (shape: bulk). */
int func_00283EB4(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_00323428;
    return func_002EED24(arg1, ((int)&D_00323428), 19);
}
/* func_00283EC4 — 4 words. MATCH 100% (shape: bulk). */
int func_00283EC4(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_00323450;
    return func_002EED24(arg1, ((int)&D_00323450), 4);
}
/* func_00283FFC — 4 words. MATCH 100% (shape: bulk). */
int func_00283FFC(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_00323524;
    return func_002EED24(arg1, ((int)&D_00323524), 11);
}
/* func_0028400C — 4 words. MATCH 100% (shape: bulk). */
int func_0028400C(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_0032353C;
    return func_002EED24(arg1, ((int)&D_0032353C), 30);
}
/* func_002840A0 — 4 words. MATCH 100% (shape: bulk). */
int func_002840A0(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_0032358C;
    return func_002EED24(arg1, ((int)&D_0032358C), 14);
}
/* func_002840B0 — 4 words. MATCH 100% (shape: bulk). */
int func_002840B0(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_003235A8;
    return func_002EED24(arg1, ((int)&D_003235A8), 23);
}
/* func_002840C0 — 16 words. MATCH 100% (shape: bool-fold). */
s32 func_002840C0(s32 arg0) {
    extern int func_002840C0();
    extern int func_00284100();
    extern int func_00284110();
    if (!func_00284100()) {
        return func_00284110(arg0) != 0;
    }
    return 1;
}
/* func_00284100 — 4 words. MATCH 100% (shape: bulk). */
int func_00284100(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_003235D8;
    return func_002EED24(arg1, ((int)&D_003235D8), 37);
}
/* func_002841E0 — 4 words. MATCH 100% (shape: bulk). */
int func_002841E0(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_00323658;
    return func_002EED24(arg1, ((int)&D_00323658), 25);
}
/* func_002841F0 — 4 words. MATCH 100% (shape: bulk). */
int func_002841F0(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_0032368C;
    return func_002EED24(arg1, ((int)&D_0032368C), 12);
}
/* func_00284200 — 4 words. MATCH 100% (shape: bulk). */
int func_00284200(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_003236A4;
    return func_002EED24(arg1, ((int)&D_003236A4), 25);
}
/* func_00284454 — 22 words. MATCH 100% (shape: m2c). */
s32 func_00284454(s32 arg0) {
    extern char D_00323848;
    extern int func_00284454();
    extern int func_00284A54();
    extern int func_00284FCC();
    extern int func_002EED24();
    if ((func_00284FCC() != 0) && (func_00284A54(arg0) == 0)) {
        return 1;
    }
    return func_002EED24(arg0, &D_00323848, 0xA);
}
/* func_002844AC — 4 words. MATCH 100% (shape: bulk). */
int func_002844AC(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_0032385C;
    return func_002EED24(arg1, ((int)&D_0032385C), 3);
}
/* func_002845B4 — 4 words. MATCH 100% (shape: bulk). */
int func_002845B4(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_00323954;
    return func_002EED24(arg1, ((int)&D_00323954), 5);
}
/* func_00284984 — 4 words. MATCH 100% (shape: bulk). */
int func_00284984(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_003239D8;
    return func_002EED24(arg1, ((int)&D_003239D8), 10);
}
/* func_00284A54 — 4 words. MATCH 100% (shape: bulk). */
int func_00284A54(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_003239EC;
    return func_002EED24(arg1, ((int)&D_003239EC), 1);
}
/* func_00284FCC — 4 words. MATCH 100% (shape: bulk). */
int func_00284FCC(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_00323A44;
    return func_002EED24(arg1, ((int)&D_00323A44), 8);
}
/* func_002850A8 — 4 words. MATCH 100% (shape: bulk). */
int func_002850A8(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_00323A54;
    return func_002EED24(arg1, ((int)&D_00323A54), 30);
}
/* func_0028510C — 4 words. MATCH 100% (shape: bulk). */
int func_0028510C(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_00323AC4;
    return func_002EED24(arg1, ((int)&D_00323AC4), 14);
}
/* func_00285150 — 4 words. MATCH 100% (shape: bulk). */
int func_00285150(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_00323B24;
    return func_002EED24(arg1, ((int)&D_00323B24), 10);
}
/* func_00285C4C — 4 words. MATCH 100% (shape: bulk). */
int func_00285C4C(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_003243F0;
    return func_002EED24(arg1, ((int)&D_003243F0), 47);
}
/* func_00285C90 — 4 words. MATCH 100% (shape: bulk). */
int func_00285C90(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_00324468;
    return func_002EED24(arg1, ((int)&D_00324468), 1);
}

/* func_0028AD44 — 2 words. MATCH 100% (shape: bulk). */
int func_0028AD44(int arg1, int arg2, int arg3, int arg4, int arg5) {
    extern int func_0028A9DC();
    extern int func_0028AD44();
    extern int func_0028A9DC();
    return func_0028A9DC(arg1, arg2, arg3, arg4, 0);
}

/* func_0028AD4C — 2 words. MATCH 100% (shape: bulk). */
int func_0028AD4C(int arg1, int arg2, int arg3, int arg4, int arg5) {
    extern int func_0028A9DC();
    extern int func_0028AD4C();
    extern int func_0028A9DC();
    return func_0028A9DC(arg1, arg2, arg3, arg4, 1);
}

/* func_0028BCDC — 4 words. MATCH 100% (shape: bulk). */
int func_0028BCDC(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6) {
    extern int func_0028B888();
    extern int func_0028BCDC();
    extern int func_0028B888();
    return func_0028B888(arg1, arg2, arg3, (*(short *)((char *)arg3 + 2)), 0, arg4);
}
/* func_0028ECE0 — 2 words. MATCH 100% (shape: m2c). */
s32 func_0028ECE0(void) {
    extern int func_0028ECE0();
    return 1;
}
/* func_002905B8 — 23 words. MATCH 100% (shape: m2c). */
s32 func_002905B8(s8 *arg0) {
    extern int func_00078EC0();
    extern int func_00287FC8();
    extern int func_002905B8();
    s32 temp_v0;

    if (func_00078EC0(*arg0, 0xB, 0x169C) < 0) {
        temp_v0 = func_00287FC8(0x169C, arg0, -1);
        if (temp_v0 >= 0) {
            return temp_v0;
        }
    }
    return -1;
}

/* func_0029BD4C — 2 words. MATCH 100% (shape: bulk). */
int func_0029BD4C(int arg1, int arg2, int arg3) {
    extern int func_0029BBE0();
    extern int func_0029BD4C();
    extern int func_0029BBE0();
    return func_0029BBE0(arg1, arg2, 6);
}
/* func_0029C0C8 — 15 words. MATCH 100% (shape: m2c). */
s32 func_0029C0C8(void) {
    extern int func_0003FBD4();
    extern int func_0029C020();
    extern int func_0029C0C8();
    s32 temp_v0;
    s32 var_s0;

    var_s0 = 0;
    temp_v0 = func_0029C020();
    if (temp_v0 >= 0) {
        var_s0 = func_0003FBD4(temp_v0);
    }
    return var_s0;
}

/* func_0029F9E8 — 3 words. MATCH 100% (shape: bulk). */
int func_0029F9E8(int arg1, int arg2, int arg3, int arg4, int arg5) {
    extern int func_0029F854();
    extern int func_0029F9E8();
    extern int func_0029F854();
    return func_0029F854(arg1, arg2, arg3, 0, 10);
}

/* func_0029F9F4 — 3 words. MATCH 100% (shape: bulk). */
int func_0029F9F4(int arg1, int arg2, int arg3, int arg4, int arg5) {
    extern int func_0029F854();
    extern int func_0029F9F4();
    extern int func_0029F854();
    return func_0029F854(arg1, arg2, arg3, 1, 10);
}

/* func_0029FA00 — 3 words. MATCH 100% (shape: bulk). */
int func_0029FA00(int arg1, int arg2, int arg3, int arg4, int arg5) {
    extern int func_0029F854();
    extern int func_0029FA00();
    extern int func_0029F854();
    return func_0029F854(arg1, arg2, arg3, 0, 14);
}

/* func_0029FA0C — 3 words. MATCH 100% (shape: bulk). */
int func_0029FA0C(int arg1, int arg2, int arg3, int arg4, int arg5) {
    extern int func_0029F854();
    extern int func_0029FA0C();
    extern int func_0029F854();
    return func_0029F854(arg1, arg2, arg3, 1, 14);
}

/* func_0029FA18 — 3 words. MATCH 100% (shape: bulk). */
int func_0029FA18(int arg1, int arg2, int arg3, int arg4, int arg5) {
    extern int func_0029F854();
    extern int func_0029FA18();
    extern int func_0029F854();
    return func_0029F854(arg1, arg2, arg3, 0, 15);
}

/* func_0029FA24 — 3 words. MATCH 100% (shape: bulk). */
int func_0029FA24(int arg1, int arg2, int arg3, int arg4, int arg5) {
    extern int func_0029F854();
    extern int func_0029FA24();
    extern int func_0029F854();
    return func_0029F854(arg1, arg2, arg3, 1, 15);
}

/* func_0029FA30 — 3 words. MATCH 100% (shape: bulk). */
int func_0029FA30(int arg1, int arg2, int arg3, int arg4, int arg5) {
    extern int func_0029F854();
    extern int func_0029FA30();
    extern int func_0029F854();
    return func_0029F854(arg1, arg2, arg3, 0, 11);
}

/* func_0029FA3C — 3 words. MATCH 100% (shape: bulk). */
int func_0029FA3C(int arg1, int arg2, int arg3, int arg4, int arg5) {
    extern int func_0029F854();
    extern int func_0029FA3C();
    extern int func_0029F854();
    return func_0029F854(arg1, arg2, arg3, 1, 11);
}

/* func_0029FA48 — 3 words. MATCH 100% (shape: bulk). */
int func_0029FA48(int arg1, int arg2, int arg3, int arg4, int arg5) {
    extern int func_0029F854();
    extern int func_0029FA48();
    extern int func_0029F854();
    return func_0029F854(arg1, arg2, arg3, 0, 13);
}

/* func_0029FA54 — 3 words. MATCH 100% (shape: bulk). */
int func_0029FA54(int arg1, int arg2, int arg3, int arg4, int arg5) {
    extern int func_0029F854();
    extern int func_0029FA54();
    extern int func_0029F854();
    return func_0029F854(arg1, arg2, arg3, 1, 13);
}

/* func_002A0D40 — 2 words. MATCH 100% (shape: bulk). */
int func_002A0D40(int arg1, int arg2, int arg3) {
    extern int func_002A0BAC();
    extern int func_002A0D40();
    extern int func_002A0BAC();
    return func_002A0BAC(arg1, arg2, 0);
}
/* func_002A5F98 — 20 words. MATCH 100% (shape: m2c). */
s32 func_002A5F98(s32 arg0, int arg1) {
    extern int func_002630D0();
    extern int func_0027F808();
    extern int func_002A5F98();
    s32 var_v0;

    var_v0 = func_0027F808() != 0;
    if (var_v0 != 0) {
        var_v0 = func_002630D0(arg0, arg1, 0) != 0;
    }
    return var_v0;
}

/* func_002A60A0 — 2 words. MATCH 100% (shape: bulk). */
int func_002A60A0(int arg1) {
    extern int func_00187B88();
    extern int func_002A60A0();
    extern int func_00187B88();
    return func_00187B88(arg1);
}
/* func_002A60A8 — 8 words. MATCH 100% (shape: m2c). */
s32 func_002A60A8(void) {
    extern int func_00187B88();
    extern int func_002A60A8();
    return func_00187B88() + 1;
}

/* func_002A60C8 — 2 words. MATCH 100% (shape: bulk). */
int func_002A60C8(int arg1) {
    extern int func_0009F680();
    extern int func_002A60C8();
    extern int func_0009F680();
    return func_0009F680(arg1);
}
/* func_002A6124 — 17 words. MATCH 100% (shape: bool-fold). */
s32 func_002A6124(s32 arg0, int arg1) {
    extern int func_00187B88();
    extern int func_001A35C4();
    extern int func_002A6124();
    if (!func_001A35C4()) {
        return 0;
    }
    return func_00187B88(arg0, arg1);
}

/* func_002A6610 — 2 words. MATCH 100% (shape: bulk). */
int func_002A6610(int arg1) {
    extern int func_0009F6F8();
    extern int func_002A6610();
    extern int func_0009F6F8();
    return func_0009F6F8(arg1);
}
/* func_002A8C78 — 22 words. MATCH 100% (shape: m2c). */
s32 func_002A8C78(s32 arg0) {
    extern int func_0009F6F8();
    extern int func_0029BD54();
    extern int func_002A8C78();
    s32 temp_v0;
    s32 var_v1;

    temp_v0 = func_0009F6F8();
    var_v1 = temp_v0 >= 2;
    if (var_v1 != 0) {
        var_v1 = temp_v0 < 0xE;
    }
    if (var_v1 != 0) {
        var_v1 = func_0029BD54(arg0, 0xE2B, temp_v0) != 0;
    }
    return var_v1;
}
/* func_002A8CD0 — 22 words. MATCH 100% (shape: bool-fold). */
s32 func_002A8CD0(s32 arg0) {
    extern int func_0017CA50();
    extern int func_00183758();
    extern int func_0029BD54();
    extern int func_002A8CD0();
    s32 temp_v0;

    temp_v0 = func_0017CA50();
    if (!func_0029BD54(arg0, 0xE2E, temp_v0)) {
        return 0;
    }
    return func_00183758(arg0, temp_v0) + 1;
}

/* func_002ADC78 — 7 words. MATCH 100% (shape: bulk). */
int func_002ADC78(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7) {
    extern int func_00279030();
    extern int func_002ADC78();
    extern int func_00279030();
    return func_00279030(arg1, arg1, arg2, 1, 1, 0, 0);
}
/* func_002AF86C — 13 words. MATCH 100% (shape: m2c). */
void func_002AF86C(s32 arg0) {
    extern int func_0017CA50();
    extern int func_0029BD54();
    extern int func_002AF86C();
    func_0029BD54(arg0, 0x198E, func_0017CA50());
}

/* func_002B2C1C — 2 words. MATCH 100% (shape: bulk). */
int func_002B2C1C(int arg1) {
    extern int func_00040510();
    extern int func_002B2C1C();
    extern int func_00040510();
    return func_00040510(100);
}
/* func_002B64FC — 10 words. MATCH 100% (shape: m2c). */
s32 func_002B64FC(void) {
    extern int func_00187B88();
    extern int func_002B64FC();
    return 0x186A0 - func_00187B88();
}

/* func_002B7454 — 3 words. MATCH 100% (shape: bulk). */
int func_002B7454(int arg1, int arg2, int arg3, int arg4) {
    extern int func_002B7354();
    extern int func_002B7454();
    extern int func_002B7354();
    return func_002B7354(arg1, arg2, 1, 1);
}
/* func_002CDC30 — 3 words. MATCH 100% (shape: hand). */
void func_002CDC30(void) {
    extern int D_0034BFAC;
    extern int func_002CDC30();
    D_0034BFAC = 0;
}

/* func_002D4EE4 — 4 words. MATCH 100% (shape: bulk). */
int func_002D4EE4(int arg1, int arg2, int arg3, int arg4, int arg5) {
    extern int func_002D49B0();
    extern int func_002D4EE4();
    extern int func_002D49B0();
    return func_002D49B0(arg1, arg2, 0, arg3, 14);
}

/* func_002D4EF4 — 4 words. MATCH 100% (shape: bulk). */
int func_002D4EF4(int arg1, int arg2, int arg3, int arg4, int arg5) {
    extern int func_002D49B0();
    extern int func_002D4EF4();
    extern int func_002D49B0();
    return func_002D49B0(arg1, arg2, 0, arg3, 15);
}

/* func_002D4F04 — 5 words. MATCH 100% (shape: bulk). */
int func_002D4F04(int arg1, int arg2, int arg3, int arg4, int arg5) {
    extern int func_002D49B0();
    extern int func_002D4F04();
    extern int func_002D49B0();
    return func_002D49B0(arg1, 0, arg2, arg3, 14);
}

/* func_002D4F18 — 5 words. MATCH 100% (shape: bulk). */
int func_002D4F18(int arg1, int arg2, int arg3, int arg4, int arg5) {
    extern int func_002D49B0();
    extern int func_002D4F18();
    extern int func_002D49B0();
    return func_002D49B0(arg1, 0, arg2, arg3, 15);
}

/* func_002D7B48 — 2 words. MATCH 100% (shape: bulk). */
int func_002D7B48(int arg1, int arg2, int arg3) {
    extern int func_000A126C();
    extern int func_002D7B48();
    extern int func_000A126C();
    return func_000A126C(arg1, arg2, 4);
}
/* func_002D7B50 — 9 words. MATCH 100% (shape: m2c). */
void func_002D7B50(void) {
    extern int ehsys_D2361003();
    extern int func_0017CA50();
    extern int func_002D7B50();
    ehsys_D2361003(func_0017CA50());
}

/* func_002D7B74 — 2 words. MATCH 100% (shape: bulk). */
int func_002D7B74(int arg1, int arg2, int arg3) {
    extern int func_000A126C();
    extern int func_002D7B74();
    extern int func_000A126C();
    return func_000A126C(arg1, arg2, 1);
}

/* func_002D7B7C — 2 words. MATCH 100% (shape: bulk). */
int func_002D7B7C(int arg1, int arg2, int arg3) {
    extern int func_000A126C();
    extern int func_002D7B7C();
    extern int func_000A126C();
    return func_000A126C(arg1, arg2, 3);
}
/* func_002D7C74 — 9 words. MATCH 100% (shape: m2c). */
void func_002D7C74(void) {
    extern int func_0017CA50();
    extern int func_002D7C74();
    extern int func_002EF364();
    func_002EF364(func_0017CA50());
}

/* func_002D7C98 — 2 words. MATCH 100% (shape: bulk). */
int func_002D7C98(int arg1, int arg2, int arg3) {
    extern int func_000A094C();
    extern int func_002D7C98();
    extern int func_000A094C();
    return func_000A094C(arg1, arg2, 21);
}
/* func_002E6B6C — 9 words. MATCH 100% (shape: m2c). */
void func_002E6B6C(void) {
    extern int ehsys_51B8DDE5();
    extern int func_0017CA50();
    extern int func_002E6B6C();
    ehsys_51B8DDE5(func_0017CA50());
}
/* func_002E6C30 — 9 words. MATCH 100% (shape: m2c). */
void func_002E6C30(void) {
    extern int ehsys_68D242C5();
    extern int func_0017CA50();
    extern int func_002E6C30();
    ehsys_68D242C5(func_0017CA50());
}
/* func_002E6C54 — 9 words. MATCH 100% (shape: m2c). */
void func_002E6C54(void) {
    extern int func_0017CA50();
    extern int func_002E6C54();
    extern int func_002EF404();
    func_002EF404(func_0017CA50());
}
/* func_002E6C78 — 9 words. MATCH 100% (shape: m2c). */
void func_002E6C78(void) {
    extern int ehsys_AB8CF7CC();
    extern int func_0017CA50();
    extern int func_002E6C78();
    ehsys_AB8CF7CC(func_0017CA50());
}
/* func_002E6C9C — 9 words. MATCH 100% (shape: m2c). */
void func_002E6C9C(void) {
    extern int func_0017CA50();
    extern int func_002E6C9C();
    extern int func_002EF384();
    func_002EF384(func_0017CA50());
}
/* func_002E6CC0 — 9 words. MATCH 100% (shape: m2c). */
void func_002E6CC0(void) {
    extern int func_0017CA50();
    extern int func_002E6CC0();
    extern int func_002EF604();
    func_002EF604(func_0017CA50());
}

/* func_002E949C — 2 words. MATCH 100% (shape: bulk). */
int func_002E949C(int arg1) {
    extern int func_00040510();
    extern int func_002E949C();
    extern int func_00040510();
    return func_00040510(2);
}
/* func_002EE70C — 8 words. MATCH 100% (shape: m2c). */
s32 func_002EE70C(s32 arg0) {
    extern int func_002CEAB4();
    extern int func_002EE70C();
    return func_002CEAB4(arg0 > 0) != 0;
}
/* func_002EECF8 — 9 words. MATCH 100% (shape: m2c). */
void func_002EECF8(void) {
    extern int func_002CDC30();
    extern int func_002CEA6C();
    extern int func_002EECF8();
    func_002CEA6C(0xC);
    func_002CDC30();
}

/* func_002EED1C — 2 words. MATCH 100% (shape: bulk). */
int func_002EED1C(int arg1) {
    extern int func_002CEA6C();
    extern int func_002EED1C();
    extern int func_002CEA6C();
    return func_002CEA6C(4);
}
/* func_002EEE80 — 9 words. MATCH 100% (shape: m2c). */
s32 func_002EEE80(void) {
    extern int ehsys_A72D71BF();
    extern int func_002EEE80();
    return ehsys_A72D71BF() == 2;
}
/* func_002EF044 — 14 words. MATCH 100% (shape: m2c). */
s32 func_002EF044(s32 arg0) {
    extern int func_002EF044();
    if ((arg0 != 0x219E) && (arg0 != 0x201E) && (arg0 != 0x1935)) {
        return 0;
    }
    return 1;
}
/* func_002EF364 — 4 words. MATCH 100% (shape: bulk). */
int func_002EF364(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_00325128;
    return func_002EED24(arg1, ((int)&D_00325128), 25);
}
/* func_002EF374 — 4 words. MATCH 100% (shape: bulk). */
int func_002EF374(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_0032515C;
    return func_002EED24(arg1, ((int)&D_0032515C), 6);
}
/* func_002EF384 — 4 words. MATCH 100% (shape: bulk). */
int func_002EF384(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_00325168;
    return func_002EED24(arg1, ((int)&D_00325168), 27);
}
/* func_002EF394 — 4 words. MATCH 100% (shape: bulk). */
int func_002EF394(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_003251A0;
    return func_002EED24(arg1, ((int)&D_003251A0), 19);
}
/* func_002EF3A4 — 20 words. MATCH 100% (shape: m2c). */
s32 func_002EF3A4(s32 arg0) {
    extern int ehsys_EED9C836();
    extern int func_002EF3A4();
    if ((arg0 >= 0xD49) && (arg0 < 0xE10) && (arg0 != 0xDAC) && (ehsys_EED9C836() != 0)) {
        return 1;
    }
    return 0;
}
/* func_002EF3F4 — 4 words. MATCH 100% (shape: bulk). */
int func_002EF3F4(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_003251C8;
    return func_002EED24(arg1, ((int)&D_003251C8), 9);
}
/* func_002EF404 — 4 words. MATCH 100% (shape: bulk). */
int func_002EF404(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_003251DC;
    return func_002EED24(arg1, ((int)&D_003251DC), 26);
}
/* func_002EF414 — 4 words. MATCH 100% (shape: bulk). */
int func_002EF414(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_00325210;
    return func_002EED24(arg1, ((int)&D_00325210), 19);
}
/* func_002EF480 — 4 words. MATCH 100% (shape: bulk). */
int func_002EF480(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_00325238;
    return func_002EED24(arg1, ((int)&D_00325238), 19);
}
/* func_002EF490 — 4 words. MATCH 100% (shape: bulk). */
int func_002EF490(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_00325260;
    return func_002EED24(arg1, ((int)&D_00325260), 6);
}
/* func_002EF4A0 — 4 words. MATCH 100% (shape: bulk). */
int func_002EF4A0(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_0032526C;
    return func_002EED24(arg1, ((int)&D_0032526C), 21);
}
/* func_002EF4B0 — 4 words. MATCH 100% (shape: bulk). */
int func_002EF4B0(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_00325298;
    return func_002EED24(arg1, ((int)&D_00325298), 6);
}
/* func_002EF4C0 — 4 words. MATCH 100% (shape: bulk). */
int func_002EF4C0(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_003252A4;
    return func_002EED24(arg1, ((int)&D_003252A4), 13);
}
/* func_002EF4D0 — 4 words. MATCH 100% (shape: bulk). */
int func_002EF4D0(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_003252C0;
    return func_002EED24(arg1, ((int)&D_003252C0), 3);
}
/* func_002EF4E0 — 4 words. MATCH 100% (shape: bulk). */
int func_002EF4E0(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_003252C8;
    return func_002EED24(arg1, ((int)&D_003252C8), 13);
}
/* func_002EF4F0 — 4 words. MATCH 100% (shape: bulk). */
int func_002EF4F0(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_003252E4;
    return func_002EED24(arg1, ((int)&D_003252E4), 6);
}
/* func_002EF500 — 4 words. MATCH 100% (shape: bulk). */
int func_002EF500(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_003252F0;
    return func_002EED24(arg1, ((int)&D_003252F0), 4);
}
/* func_002EF510 — 17 words. MATCH 100% (shape: bool-fold). */
s32 func_002EF510(s32 arg0) {
    extern char D_003252F8;
    extern int func_002EED24();
    extern int func_002EF510();
    extern int func_002EF554();
    if (!func_002EF554()) {
        return func_002EED24(arg0, &D_003252F8, 5);
    }
    return 1;
}
/* func_002EF554 — 4 words. MATCH 100% (shape: bulk). */
int func_002EF554(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_00325304;
    return func_002EED24(arg1, ((int)&D_00325304), 9);
}
/* func_002EF564 — 4 words. MATCH 100% (shape: bulk). */
int func_002EF564(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_00325318;
    return func_002EED24(arg1, ((int)&D_00325318), 9);
}
/* func_002EF574 — 4 words. MATCH 100% (shape: bulk). */
int func_002EF574(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_0032532C;
    return func_002EED24(arg1, ((int)&D_0032532C), 9);
}
/* func_002EF584 — 4 words. MATCH 100% (shape: bulk). */
int func_002EF584(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_00325340;
    return func_002EED24(arg1, ((int)&D_00325340), 17);
}
/* func_002EF594 — 4 words. MATCH 100% (shape: bulk). */
int func_002EF594(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_00325364;
    return func_002EED24(arg1, ((int)&D_00325364), 18);
}
/* func_002EF5A4 — 4 words. MATCH 100% (shape: bulk). */
int func_002EF5A4(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_00325388;
    return func_002EED24(arg1, ((int)&D_00325388), 3);
}
/* func_002EF5B4 — 4 words. MATCH 100% (shape: bulk). */
int func_002EF5B4(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_00325390;
    return func_002EED24(arg1, ((int)&D_00325390), 22);
}
/* func_002EF5C4 — 4 words. MATCH 100% (shape: bulk). */
int func_002EF5C4(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_003253BC;
    return func_002EED24(arg1, ((int)&D_003253BC), 7);
}
/* func_002EF5D4 — 4 words. MATCH 100% (shape: bulk). */
int func_002EF5D4(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_003253CC;
    return func_002EED24(arg1, ((int)&D_003253CC), 11);
}
/* func_002EF5E4 — 4 words. MATCH 100% (shape: bulk). */
int func_002EF5E4(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_003253E4;
    return func_002EED24(arg1, ((int)&D_003253E4), 9);
}
/* func_002EF5F4 — 4 words. MATCH 100% (shape: bulk). */
int func_002EF5F4(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_003253F8;
    return func_002EED24(arg1, ((int)&D_003253F8), 10);
}
/* func_002EF604 — 4 words. MATCH 100% (shape: bulk). */
int func_002EF604(int arg1, int arg2, int arg3) {

    extern int func_002EED24();
    extern char D_0032540C;
    return func_002EED24(arg1, ((int)&D_0032540C), 8);
}
/* func_002EF790 — 3 words. MATCH 100% (shape: hand). */
int func_002EF790(void) {
    extern int D_00351894;
    extern int func_002EF790();
    return D_00351894;
}
/* func_002EF79C — 3 words. MATCH 100% (shape: hand). */
int func_002EF79C(void) {
    extern int D_0035187C;
    extern int func_002EF79C();
    return D_0035187C;
}
/* func_002EF7A8 — 3 words. MATCH 100% (shape: hand). */
int func_002EF7A8(void) {
    extern int D_00351880;
    extern int func_002EF7A8();
    return D_00351880;
}
/* func_002EF7B4 — 3 words. MATCH 100% (shape: hand). */
int func_002EF7B4(void) {
    extern int D_00351884;
    extern int func_002EF7B4();
    return D_00351884;
}
/* func_002EFA64 — 5 words. MATCH 100% (shape: bulk). */
int func_002EFA64(int arg1, int arg2) {

    extern int func_002EFA78();
    extern char D_003518AC;
    extern char D_003518B0;
    return func_002EFA78(((int)&D_003518AC), ((int)&D_003518B0));
}
/* func_002EFA78 — 4 words. MATCH 100% (shape: m2c). */
s32 *func_002EFA78(s32 *arg0, s32 *arg1) {
    extern int func_002EFA78();
    *arg0 = *arg1;
    return arg0;
}
/* func_002EFB08 — 5 words. MATCH 100% (shape: bulk). */
int func_002EFB08(int arg1, int arg2) {

    extern int func_002EFB1C();
    extern char D_003518B4;
    extern char D_003518BC;
    return func_002EFB1C(((int)&D_003518B4), ((int)&D_003518BC));
}
/* func_002EFBD0 — 5 words. MATCH 100% (shape: bulk). */
int func_002EFBD0(int arg1, int arg2) {

    extern int func_002EFBE4();
    extern char D_003518C4;
    extern char D_003518CC;
    return func_002EFBE4(((int)&D_003518C4), ((int)&D_003518CC));
}
/* func_002EFC9C — 5 words. MATCH 100% (shape: bulk). */
int func_002EFC9C(int arg1, int arg2) {

    extern int func_002EFCB0();
    extern char D_003518D4;
    extern char D_003518DC;
    return func_002EFCB0(((int)&D_003518D4), ((int)&D_003518DC));
}
/* func_002EFD6C — 5 words. MATCH 100% (shape: bulk). */
int func_002EFD6C(int arg1, int arg2) {

    extern int func_002EFD80();
    extern char D_003518E4;
    extern char D_003518EC;
    return func_002EFD80(((int)&D_003518E4), ((int)&D_003518EC));
}
/* func_002EFE3C — 5 words. MATCH 100% (shape: bulk). */
int func_002EFE3C(int arg1, int arg2) {

    extern int func_002EFE50();
    extern char D_003518F4;
    extern char D_003518FC;
    return func_002EFE50(((int)&D_003518F4), ((int)&D_003518FC));
}
/* func_002EFEE0 — 5 words. MATCH 100% (shape: bulk). */
int func_002EFEE0(int arg1, int arg2) {

    extern int func_002EFEF4();
    extern char D_00351904;
    extern char D_00351908;
    return func_002EFEF4(((int)&D_00351904), ((int)&D_00351908));
}
/* func_002EFEF4 — 4 words. MATCH 100% (shape: m2c). */
s32 *func_002EFEF4(s32 *arg0, s32 *arg1) {
    extern int func_002EFEF4();
    *arg0 = *arg1;
    return arg0;
}
/* func_002EFF54 — 5 words. MATCH 100% (shape: bulk). */
int func_002EFF54(int arg1, int arg2) {

    extern int func_002EFF68();
    extern char D_0035190C;
    extern char D_00351910;
    return func_002EFF68(((int)&D_0035190C), ((int)&D_00351910));
}
/* func_002EFF68 — 4 words. MATCH 100% (shape: m2c). */
s32 *func_002EFF68(s32 *arg0, s32 *arg1) {
    extern int func_002EFF68();
    *arg0 = *arg1;
    return arg0;
}
/* func_002EFFC0 — 5 words. MATCH 100% (shape: bulk). */
int func_002EFFC0(int arg1, int arg2) {

    extern int func_002EFFD4();
    extern char D_00351914;
    extern char D_00351918;
    return func_002EFFD4(((int)&D_00351914), ((int)&D_00351918));
}
/* func_002EFFD4 — 4 words. MATCH 100% (shape: m2c). */
s32 *func_002EFFD4(s32 *arg0, s32 *arg1) {
    extern int func_002EFFD4();
    *arg0 = *arg1;
    return arg0;
}
/* func_002F002C — 5 words. MATCH 100% (shape: bulk). */
int func_002F002C(int arg1, int arg2) {

    extern int func_002F0040();
    extern char D_0035191C;
    extern char D_00351920;
    return func_002F0040(((int)&D_0035191C), ((int)&D_00351920));
}
/* func_002F0040 — 4 words. MATCH 100% (shape: m2c). */
s32 *func_002F0040(s32 *arg0, s32 *arg1) {
    extern int func_002F0040();
    *arg0 = *arg1;
    return arg0;
}
/* func_002F0098 — 5 words. MATCH 100% (shape: bulk). */
int func_002F0098(int arg1, int arg2) {

    extern int func_002F00AC();
    extern char D_00351924;
    extern char D_00351928;
    return func_002F00AC(((int)&D_00351924), ((int)&D_00351928));
}
/* func_002F00AC — 4 words. MATCH 100% (shape: m2c). */
s32 *func_002F00AC(s32 *arg0, s32 *arg1) {
    extern int func_002F00AC();
    *arg0 = *arg1;
    return arg0;
}
/* func_002F013C — 5 words. MATCH 100% (shape: bulk). */
int func_002F013C(int arg1, int arg2) {

    extern int func_002F0150();
    extern char D_0035192C;
    extern char D_00351934;
    return func_002F0150(((int)&D_0035192C), ((int)&D_00351934));
}
/* func_002F0264 — 5 words. MATCH 100% (shape: bulk). */
int func_002F0264(int arg1, int arg2) {

    extern int func_002F0278();
    extern char D_0035193C;
    extern char D_00351944;
    return func_002F0278(((int)&D_0035193C), ((int)&D_00351944));
}
/* func_002F0370 — 5 words. MATCH 100% (shape: bulk). */
int func_002F0370(int arg1, int arg2) {

    extern int func_002F0384();
    extern char D_0035194C;
    extern char D_00351954;
    return func_002F0384(((int)&D_0035194C), ((int)&D_00351954));
}
/* func_002F04C0 — 5 words. MATCH 100% (shape: bulk). */
int func_002F04C0(int arg1, int arg2) {

    extern int func_002F04D4();
    extern char D_0035195C;
    extern char D_00351988;
    return func_002F04D4(((int)&D_0035195C), ((int)&D_00351988));
}
/* func_002F0628 — 5 words. MATCH 100% (shape: bulk). */
int func_002F0628(int arg1, int arg2) {

    extern int func_002F063C();
    extern char D_003519B4;
    extern char D_003519E0;
    return func_002F063C(((int)&D_003519B4), ((int)&D_003519E0));
}
/* func_002F076C — 5 words. MATCH 100% (shape: bulk). */
int func_002F076C(int arg1, int arg2) {

    extern int func_002F0780();
    extern char D_00351A0C;
    extern char D_00351A38;
    return func_002F0780(((int)&D_00351A0C), ((int)&D_00351A38));
}
/* func_002F08CC — 5 words. MATCH 100% (shape: bulk). */
int func_002F08CC(int arg1, int arg2) {

    extern int func_002F08E0();
    extern char D_00351A64;
    extern char D_00351A90;
    return func_002F08E0(((int)&D_00351A64), ((int)&D_00351A90));
}
/* func_002F0A50 — 5 words. MATCH 100% (shape: bulk). */
int func_002F0A50(int arg1, int arg2) {

    extern int func_002F0A64();
    extern char D_00351ABC;
    extern char D_00351AC4;
    return func_002F0A64(((int)&D_00351ABC), ((int)&D_00351AC4));
}
/* func_002F0B98 — 5 words. MATCH 100% (shape: bulk). */
int func_002F0B98(int arg1, int arg2) {

    extern int func_002F0BAC();
    extern char D_00351ACC;
    extern char D_00351AD4;
    return func_002F0BAC(((int)&D_00351ACC), ((int)&D_00351AD4));
}
/* func_002F0CE4 — 5 words. MATCH 100% (shape: bulk). */
int func_002F0CE4(int arg1, int arg2) {

    extern int func_002F0CF8();
    extern char D_00351ADC;
    extern char D_00351AE4;
    return func_002F0CF8(((int)&D_00351ADC), ((int)&D_00351AE4));
}
/* func_002F0E34 — 5 words. MATCH 100% (shape: bulk). */
int func_002F0E34(int arg1, int arg2) {

    extern int func_002F0E48();
    extern char D_00351AEC;
    extern char D_00351AF4;
    return func_002F0E48(((int)&D_00351AEC), ((int)&D_00351AF4));
}
/* func_002F10D8 — 5 words. MATCH 100% (shape: bulk). */
int func_002F10D8(int arg1, int arg2) {

    extern int func_002F10EC();
    extern char D_00351F74;
    extern char D_0035233C;
    return func_002F10EC(((int)&D_00351F74), ((int)&D_0035233C));
}
/* func_002F1278 — 5 words. MATCH 100% (shape: bulk). */
int func_002F1278(int arg1, int arg2) {

    extern int func_002F128C();
    extern char D_00352704;
    extern char D_00352714;
    return func_002F128C(((int)&D_00352704), ((int)&D_00352714));
}
/* func_002F13C0 — 5 words. MATCH 100% (shape: bulk). */
int func_002F13C0(int arg1, int arg2) {

    extern int func_002F13D4();
    extern char D_00352724;
    extern char D_0035277C;
    return func_002F13D4(((int)&D_00352724), ((int)&D_0035277C));
}
/* func_002F1524 — 5 words. MATCH 100% (shape: bulk). */
int func_002F1524(int arg1, int arg2) {

    extern int func_002F1538();
    extern char D_003527D4;
    extern char D_00352800;
    return func_002F1538(((int)&D_003527D4), ((int)&D_00352800));
}
/* func_002F1668 — 5 words. MATCH 100% (shape: bulk). */
int func_002F1668(int arg1, int arg2) {

    extern int func_002F167C();
    extern char D_0035282C;
    extern char D_00352858;
    return func_002F167C(((int)&D_0035282C), ((int)&D_00352858));
}
/* func_002F17AC — 5 words. MATCH 100% (shape: bulk). */
int func_002F17AC(int arg1, int arg2) {

    extern int func_002F17C0();
    extern char D_00352884;
    extern char D_003528B0;
    return func_002F17C0(((int)&D_00352884), ((int)&D_003528B0));
}
/* func_002F18F0 — 5 words. MATCH 100% (shape: bulk). */
int func_002F18F0(int arg1, int arg2) {

    extern int func_002F1904();
    extern char D_003528DC;
    extern char D_00352934;
    return func_002F1904(((int)&D_003528DC), ((int)&D_00352934));
}
/* func_002F1A60 — 5 words. MATCH 100% (shape: bulk). */
int func_002F1A60(int arg1, int arg2) {

    extern int func_002F1A74();
    extern char D_0035298C;
    extern char D_00352C78;
    return func_002F1A74(((int)&D_0035298C), ((int)&D_00352C78));
}
/* func_002F1BBC — 5 words. MATCH 100% (shape: bulk). */
int func_002F1BBC(int arg1, int arg2) {

    extern int func_002F1BD0();
    extern char D_00352F64;
    extern char D_00352F6C;
    return func_002F1BD0(((int)&D_00352F64), ((int)&D_00352F6C));
}
/* func_002F1CE4 — 5 words. MATCH 100% (shape: bulk). */
int func_002F1CE4(int arg1, int arg2) {

    extern int func_002F1CF8();
    extern char D_00352F74;
    extern char D_00352F7C;
    return func_002F1CF8(((int)&D_00352F74), ((int)&D_00352F7C));
}
/* func_002F1E0C — 5 words. MATCH 100% (shape: bulk). */
int func_002F1E0C(int arg1, int arg2) {

    extern int func_002F1E20();
    extern char D_00352F84;
    extern char D_00352F8C;
    return func_002F1E20(((int)&D_00352F84), ((int)&D_00352F8C));
}
/* func_002F1EA4 — 19 words. MATCH 100% (shape: m2c). */
void func_002F1EA4(s32 arg0, int arg1, int arg2) {
    extern int func_00078AAC();
    extern int func_002EF7C0();
    extern int func_002F1EA4();
    func_002EF7C0();
    func_00078AAC(arg0, arg1, arg2);
}
/* func_002F1F74 — 5 words. MATCH 100% (shape: bulk). */
int func_002F1F74(int arg1, int arg2) {

    extern int func_002F1F88();
    extern char D_00352F94;
    extern char D_00352FA8;
    return func_002F1F88(((int)&D_00352F94), ((int)&D_00352FA8));
}
/* func_002F2070 — 5 words. MATCH 100% (shape: bulk). */
int func_002F2070(int arg1, int arg2) {

    extern int func_002F2084();
    extern char D_00352FBC;
    extern char D_00352FC0;
    return func_002F2084(((int)&D_00352FBC), ((int)&D_00352FC0));
}
/* func_002F2148 — 5 words. MATCH 100% (shape: bulk). */
int func_002F2148(int arg1, int arg2) {

    extern int func_002F215C();
    extern char D_00352FC4;
    extern char D_00352FC8;
    return func_002F215C(((int)&D_00352FC4), ((int)&D_00352FC8));
}
/* func_002F2220 — 5 words. MATCH 100% (shape: bulk). */
int func_002F2220(int arg1, int arg2) {

    extern int func_002F2234();
    extern char D_00352FCC;
    extern char D_00352FD0;
    return func_002F2234(((int)&D_00352FCC), ((int)&D_00352FD0));
}
/* func_002F22F8 — 5 words. MATCH 100% (shape: bulk). */
int func_002F22F8(int arg1, int arg2) {

    extern int func_002F230C();
    extern char D_00352FD4;
    extern char D_00352FD8;
    return func_002F230C(((int)&D_00352FD4), ((int)&D_00352FD8));
}
/* func_002F23D0 — 5 words. MATCH 100% (shape: bulk). */
int func_002F23D0(int arg1, int arg2) {

    extern int func_002F23E4();
    extern char D_00352FDC;
    extern char D_00352FE0;
    return func_002F23E4(((int)&D_00352FDC), ((int)&D_00352FE0));
}
/* func_002F24E0 — 5 words. MATCH 100% (shape: bulk). */
int func_002F24E0(int arg1, int arg2) {

    extern int func_002F24F4();
    extern char D_00352FE4;
    extern char D_003531D4;
    return func_002F24F4(((int)&D_00352FE4), ((int)&D_003531D4));
}
/* func_002F2630 — 5 words. MATCH 100% (shape: bulk). */
int func_002F2630(int arg1, int arg2) {

    extern int func_002F2644();
    extern char D_003533C4;
    extern char D_003535B4;
    return func_002F2644(((int)&D_003533C4), ((int)&D_003535B4));
}
/* func_002F2780 — 5 words. MATCH 100% (shape: bulk). */
int func_002F2780(int arg1, int arg2) {

    extern int func_002F2794();
    extern char D_003537A4;
    extern char D_00353820;
    return func_002F2794(((int)&D_003537A4), ((int)&D_00353820));
}
/* func_002F28D0 — 5 words. MATCH 100% (shape: bulk). */
int func_002F28D0(int arg1, int arg2) {

    extern int func_002F28E4();
    extern char D_0035389C;
    extern char D_00353AC8;
    return func_002F28E4(((int)&D_0035389C), ((int)&D_00353AC8));
}
/* func_002F2A20 — 5 words. MATCH 100% (shape: bulk). */
int func_002F2A20(int arg1, int arg2) {

    extern int func_002F2A34();
    extern char D_00353CF4;
    extern char D_00353F20;
    return func_002F2A34(((int)&D_00353CF4), ((int)&D_00353F20));
}
/* func_002F2B88 — 5 words. MATCH 100% (shape: bulk). */
int func_002F2B88(int arg1, int arg2) {

    extern int func_002F2B9C();
    extern char D_0035414C;
    extern char D_0035433C;
    return func_002F2B9C(((int)&D_0035414C), ((int)&D_0035433C));
}
/* func_002F2D08 — 5 words. MATCH 100% (shape: bulk). */
int func_002F2D08(int arg1, int arg2) {

    extern int func_002F2D1C();
    extern char D_0035452C;
    extern char D_0035471C;
    return func_002F2D1C(((int)&D_0035452C), ((int)&D_0035471C));
}
/* func_002F2E88 — 5 words. MATCH 100% (shape: bulk). */
int func_002F2E88(int arg1, int arg2) {

    extern int func_002F2E9C();
    extern char D_0035490C;
    extern char D_00354988;
    return func_002F2E9C(((int)&D_0035490C), ((int)&D_00354988));
}
/* func_002F3008 — 5 words. MATCH 100% (shape: bulk). */
int func_002F3008(int arg1, int arg2) {

    extern int func_002F301C();
    extern char D_00354A04;
    extern char D_00354C30;
    return func_002F301C(((int)&D_00354A04), ((int)&D_00354C30));
}
/* func_002F3188 — 5 words. MATCH 100% (shape: bulk). */
int func_002F3188(int arg1, int arg2) {

    extern int func_002F319C();
    extern char D_00354E5C;
    extern char D_00355088;
    return func_002F319C(((int)&D_00354E5C), ((int)&D_00355088));
}
/* func_002F3740 — 5 words. MATCH 100% (shape: bulk). */
int func_002F3740(int arg1, int arg2) {

    extern int func_002F3754();
    extern char D_003552B4;
    extern char D_003554A4;
    return func_002F3754(((int)&D_003552B4), ((int)&D_003554A4));
}
/* func_002F38BC — 4 words. MATCH 100% (shape: m2c). */
s32 *func_002F38BC(s32 *arg0, s32 *arg1) {
    extern int func_002F38BC();
    *arg0 = *arg1;
    return arg0;
}
/* func_002F38CC — 5 words. MATCH 100% (shape: bulk). */
int func_002F38CC(int arg1, int arg2) {

    extern int func_002F38E0();
    extern char D_00355694;
    extern char D_00355E94;
    return func_002F38E0(((int)&D_00355694), ((int)&D_00355E94));
}
/* func_002F3B58 — 5 words. MATCH 100% (shape: bulk). */
int func_002F3B58(int arg1, int arg2) {

    extern int func_002F3B6C();
    extern char D_00356694;
    extern char D_00356724;
    return func_002F3B6C(((int)&D_00356694), ((int)&D_00356724));
}
/* func_002F4114 — 5 words. MATCH 100% (shape: bulk). */
int func_002F4114(int arg1, int arg2) {

    extern int func_002F4128();
    extern char D_003567B4;
    extern char D_00356844;
    return func_002F4128(((int)&D_003567B4), ((int)&D_00356844));
}
/* func_002F4470 — 5 words. MATCH 100% (shape: bulk). */
int func_002F4470(int arg1, int arg2) {

    extern int func_002F4484();
    extern char D_003568D4;
    extern char D_003570D4;
    return func_002F4484(((int)&D_003568D4), ((int)&D_003570D4));
}
/* func_002F4548 — 5 words. MATCH 100% (shape: bulk). */
int func_002F4548(int arg1, int arg2) {

    extern int func_002F455C();
    extern char D_003578D4;
    extern char D_00357CD4;
    return func_002F455C(((int)&D_003578D4), ((int)&D_00357CD4));
}
/* func_002F4664 — 5 words. MATCH 100% (shape: bulk). */
int func_002F4664(int arg1, int arg2) {

    extern int func_002F4678();
    extern char D_003580D4;
    extern char D_00358114;
    return func_002F4678(((int)&D_003580D4), ((int)&D_00358114));
}
/* func_002F47F4 — 5 words. MATCH 100% (shape: bulk). */
int func_002F47F4(int arg1, int arg2) {

    extern int func_002F4808();
    extern char D_00358154;
    extern char D_00358158;
    return func_002F4808(((int)&D_00358154), ((int)&D_00358158));
}
/* func_002F4808 — 4 words. MATCH 100% (shape: m2c). */
s32 *func_002F4808(s32 *arg0, s32 *arg1) {
    extern int func_002F4808();
    *arg0 = *arg1;
    return arg0;
}
/* func_002F4860 — 5 words. MATCH 100% (shape: bulk). */
int func_002F4860(int arg1, int arg2) {

    extern int func_002F4874();
    extern char D_0035815C;
    extern char D_00358160;
    return func_002F4874(((int)&D_0035815C), ((int)&D_00358160));
}
/* func_002F4874 — 4 words. MATCH 100% (shape: m2c). */
s32 *func_002F4874(s32 *arg0, s32 *arg1) {
    extern int func_002F4874();
    *arg0 = *arg1;
    return arg0;
}
/* func_002F48CC — 5 words. MATCH 100% (shape: bulk). */
int func_002F48CC(int arg1, int arg2) {

    extern int func_002F48E0();
    extern char D_00358164;
    extern char D_00358168;
    return func_002F48E0(((int)&D_00358164), ((int)&D_00358168));
}
/* func_002F48E0 — 4 words. MATCH 100% (shape: m2c). */
s32 *func_002F48E0(s32 *arg0, s32 *arg1) {
    extern int func_002F48E0();
    *arg0 = *arg1;
    return arg0;
}
/* func_002F4970 — 5 words. MATCH 100% (shape: bulk). */
int func_002F4970(int arg1, int arg2) {

    extern int func_002F4984();
    extern char D_0035816C;
    extern char D_00358174;
    return func_002F4984(((int)&D_0035816C), ((int)&D_00358174));
}
/* func_002F4AD4 — 5 words. MATCH 100% (shape: bulk). */
int func_002F4AD4(int arg1, int arg2) {

    extern int func_002F4AE8();
    extern char D_0035817C;
    extern char D_003583A8;
    return func_002F4AE8(((int)&D_0035817C), ((int)&D_003583A8));
}
/* func_002F4CA0 — 5 words. MATCH 100% (shape: bulk). */
int func_002F4CA0(int arg1, int arg2) {

    extern int func_002F4CB4();
    extern char D_003585D4;
    extern char D_00358800;
    return func_002F4CB4(((int)&D_003585D4), ((int)&D_00358800));
}
/* func_002F4E5C — 5 words. MATCH 100% (shape: bulk). */
int func_002F4E5C(int arg1, int arg2) {

    extern int func_002F4E70();
    extern char D_00358A2C;
    extern char D_00358C58;
    return func_002F4E70(((int)&D_00358A2C), ((int)&D_00358C58));
}
/* func_002F4FF4 — 5 words. MATCH 100% (shape: bulk). */
int func_002F4FF4(int arg1, int arg2) {

    extern int func_002F5008();
    extern char D_00358E84;
    extern char D_00358EA4;
    return func_002F5008(((int)&D_00358E84), ((int)&D_00358EA4));
}
/* func_002F5150 — 5 words. MATCH 100% (shape: bulk). */
int func_002F5150(int arg1, int arg2) {

    extern int func_002F5164();
    extern char D_00358EC4;
    extern char D_00358F1C;
    return func_002F5164(((int)&D_00358EC4), ((int)&D_00358F1C));
}
/* func_002F5208 — 22 words. MATCH 100% (shape: m2c). */
void *func_002F5208(s32 arg0, s32 arg1) {
    extern char D_0034E660;
    extern int func_002EF7C0();
    extern int func_002F5208();
    func_002EF7C0();
    return (arg1 * 4) + (&D_0034E660 + ((arg0 & 1) * 0xB3C)) + 0x304;
}
/* func_002F5260 — 27 words. MATCH 100% (shape: m2c). */
void func_002F5260(s32 arg0, s32 arg1, int arg2) {
    extern char D_0034E660;
    extern int func_002EF7C0();
    extern int func_002F38BC();
    extern int func_002F5260();
    func_002EF7C0();
    func_002F38BC((arg1 * 4) + (&D_0034E660 + ((arg0 & 1) * 0xB3C)) + 0x304, arg2);
}
/* func_002F52CC — 16 words. MATCH 100% (shape: m2c). */
void func_002F52CC(s32 arg0, int arg1) {
    extern int func_00078AAC();
    extern int func_002EF7C0();
    extern int func_002F52CC();
    func_002EF7C0();
    func_00078AAC(arg0, 0xB, arg1);
}
/* func_002F530C — 16 words. MATCH 100% (shape: m2c). */
void func_002F530C(s32 arg0, int arg1) {
    extern int func_00078AAC();
    extern int func_002EF7C0();
    extern int func_002F530C();
    func_002EF7C0();
    func_00078AAC(arg0, 0xB, arg1);
}
/* func_002F534C — 23 words. MATCH 100% (shape: m2c). */
void func_002F534C(s32 arg0, int arg1, int arg2, int arg3) {
    extern int func_000135F0();
    extern int func_002EF7C0();
    extern int func_002F534C();
    func_002EF7C0();
    func_000135F0(arg0, arg1, arg2, arg3);
}
/* func_002F53A8 — 23 words. MATCH 100% (shape: m2c). */
void func_002F53A8(s32 arg0, int arg1, int arg2, int arg3) {
    extern int func_0001369C();
    extern int func_002EF7C0();
    extern int func_002F53A8();
    func_002EF7C0();
    func_0001369C(arg0, arg1, arg2, arg3);
}
/* func_002F5404 — 9 words. MATCH 100% (shape: m2c). */
void func_002F5404(void) {
    extern int func_0003E0A0();
    extern int func_002EF614();
    extern int func_002F5404();
    func_002EF614(1);
    func_0003E0A0();
}
/* func_002F5428 — 9 words. MATCH 100% (shape: m2c). */
void func_002F5428(void) {
    extern int func_0003E0C8();
    extern int func_002EF614();
    extern int func_002F5428();
    func_002EF614(1);
    func_0003E0C8();
}
/* func_002F544C — 12 words. MATCH 100% (shape: m2c). */
void func_002F544C(s32 arg0) {
    extern int func_0003E15C();
    extern int func_002EF614();
    extern int func_002F544C();
    func_002EF614(0);
    func_0003E15C(arg0);
}
/* func_002F55A0 — 11 words. MATCH 100% (shape: m2c). */
void func_002F55A0(s32 arg0) {
    extern int func_00040F20();
    extern int func_002EF7C0();
    extern int func_002F55A0();
    func_002EF7C0();
    func_00040F20(arg0);
}
/* func_002F55CC — 11 words. MATCH 100% (shape: m2c). */
void func_002F55CC(s32 arg0) {
    extern int func_0003E21C();
    extern int func_002EF7C0();
    extern int func_002F55CC();
    func_002EF7C0();
    func_0003E21C(arg0);
}

/* func_002F55F8 — 2 words. MATCH 100% (shape: bulk). */
int func_002F55F8(int arg1) {
    extern int func_002F55F8();
    extern int func_002F6A4C();
    extern int func_002F6A4C();
    return func_002F6A4C(arg1);
}
/* func_002F56A0 — 23 words. MATCH 100% (shape: m2c). */
void func_002F56A0(s32 arg0, int arg1, int arg2, int arg3) {
    extern int func_00042A70();
    extern int func_002EF7C0();
    extern int func_002F56A0();
    func_002EF7C0();
    func_00042A70(arg0, arg1, arg2, arg3);
}
/* func_002F5778 — 9 words. MATCH 100% (shape: m2c). */
void func_002F5778(void) {
    extern int func_0001E3A0();
    extern int func_002EF7C0();
    extern int func_002F5778();
    func_002EF7C0();
    func_0001E3A0();
}
/* func_002F59EC — 23 words. MATCH 100% (shape: m2c). */
void func_002F59EC(s32 arg0, int arg1, int arg2, int arg3) {
    extern int func_0001E1A8();
    extern int func_002EF7C0();
    extern int func_002F59EC();
    func_002EF7C0();
    func_0001E1A8(arg0, arg1, arg2, arg3);
}
/* func_002F5A48 — 9 words. MATCH 100% (shape: m2c). */
void func_002F5A48(void) {
    extern int func_0001E35C();
    extern int func_002EF7C0();
    extern int func_002F5A48();
    func_002EF7C0();
    func_0001E35C();
}
/* func_002F5A90 — 5 words. MATCH 100% (shape: bulk). */
int func_002F5A90(int arg1, int arg2) {

    extern int func_002F5AA4();
    extern char D_003593CC;
    extern char D_003593D0;
    return func_002F5AA4(((int)&D_003593CC), ((int)&D_003593D0));
}
/* func_002F5AA4 — 4 words. MATCH 100% (shape: m2c). */
s32 *func_002F5AA4(s32 *arg0, s32 *arg1) {
    extern int func_002F5AA4();
    *arg0 = *arg1;
    return arg0;
}
/* func_002F5B10 — 5 words. MATCH 100% (shape: bulk). */
int func_002F5B10(int arg1, int arg2) {

    extern int func_002F5B24();
    extern char D_003593D4;
    extern char D_003593D8;
    return func_002F5B24(((int)&D_003593D4), ((int)&D_003593D8));
}
/* func_002F5B24 — 4 words. MATCH 100% (shape: m2c). */
s32 *func_002F5B24(s32 *arg0, s32 *arg1) {
    extern int func_002F5B24();
    *arg0 = *arg1;
    return arg0;
}
/* func_002F5B90 — 11 words. MATCH 100% (shape: m2c). */
void func_002F5B90(s32 arg0) {
    extern int func_002EB9FC();
    extern int func_002EF7C0();
    extern int func_002F5B90();
    func_002EF7C0();
    func_002EB9FC(arg0);
}
/* func_002F5BBC — 23 words. MATCH 100% (shape: m2c). */
void func_002F5BBC(s32 arg0, int arg1, int arg2, int arg3) {
    extern int func_002EBB18();
    extern int func_002EF7C0();
    extern int func_002F5BBC();
    func_002EF7C0();
    func_002EBB18(arg0, arg1, arg2, arg3);
}
/* func_002F5C18 — 19 words. MATCH 100% (shape: m2c). */
void func_002F5C18(s32 arg0, int arg1, int arg2) {
    extern int func_00170F10();
    extern int func_002EF7C0();
    extern int func_002F5C18();
    func_002EF7C0();
    func_00170F10(arg0, arg1, arg2);
}
/* func_002F5C64 — 23 words. MATCH 100% (shape: m2c). */
void func_002F5C64(s32 arg0, int arg1, int arg2, int arg3) {
    extern int func_000D0E0C();
    extern int func_002EF7C0();
    extern int func_002F5C64();
    func_002EF7C0();
    func_000D0E0C(arg0, arg1, arg2, arg3);
}
/* func_002F5CC0 — 19 words. MATCH 100% (shape: m2c). */
void func_002F5CC0(s32 arg0, int arg1, int arg2) {
    extern int func_000D0F24();
    extern int func_002EF7C0();
    extern int func_002F5CC0();
    func_002EF7C0();
    func_000D0F24(arg0, arg1, arg2);
}
/* func_002F5D38 — 5 words. MATCH 100% (shape: bulk). */
int func_002F5D38(int arg1, int arg2) {

    extern int func_002F5D4C();
    extern char D_003593DC;
    extern char D_003593E0;
    return func_002F5D4C(((int)&D_003593DC), ((int)&D_003593E0));
}
/* func_002F5D4C — 4 words. MATCH 100% (shape: m2c). */
s16 *func_002F5D4C(s16 *arg0, s16 *arg1) {
    extern int func_002F5D4C();
    *arg0 = *arg1;
    return arg0;
}
/* func_002F5DB4 — 5 words. MATCH 100% (shape: bulk). */
int func_002F5DB4(int arg1, int arg2) {

    extern int func_002F5DC8();
    extern char D_003593E4;
    extern char D_003593E8;
    return func_002F5DC8(((int)&D_003593E4), ((int)&D_003593E8));
}
/* func_002F5DC8 — 4 words. MATCH 100% (shape: m2c). */
s32 *func_002F5DC8(s32 *arg0, s32 *arg1) {
    extern int func_002F5DC8();
    *arg0 = *arg1;
    return arg0;
}
/* func_002F5E5C — 5 words. MATCH 100% (shape: bulk). */
int func_002F5E5C(int arg1, int arg2) {

    extern int func_002F5E70();
    extern char D_003593EC;
    extern char D_003593F0;
    return func_002F5E70(((int)&D_003593EC), ((int)&D_003593F0));
}
/* func_002F5E70 — 4 words. MATCH 100% (shape: m2c). */
s32 *func_002F5E70(s32 *arg0, s32 *arg1) {
    extern int func_002F5E70();
    *arg0 = *arg1;
    return arg0;
}
/* func_002F5EDC — 5 words. MATCH 100% (shape: bulk). */
int func_002F5EDC(int arg1, int arg2) {

    extern int func_002F5EF0();
    extern char D_003593F4;
    extern char D_003593F8;
    return func_002F5EF0(((int)&D_003593F4), ((int)&D_003593F8));
}
/* func_002F5EF0 — 4 words. MATCH 100% (shape: m2c). */
s32 *func_002F5EF0(s32 *arg0, s32 *arg1) {
    extern int func_002F5EF0();
    *arg0 = *arg1;
    return arg0;
}
/* func_002F6020 — 15 words. MATCH 100% (shape: m2c). */
void func_002F6020(s32 arg0, int arg1) {
    extern int func_0006F990();
    extern int func_002EF7C0();
    extern int func_002F6020();
    func_002EF7C0();
    func_0006F990(arg0, arg1);
}
/* func_002F605C — 11 words. MATCH 100% (shape: m2c). */
void func_002F605C(s32 arg0) {
    extern int func_0017810C();
    extern int func_002EF7C0();
    extern int func_002F605C();
    func_002EF7C0();
    func_0017810C(arg0);
}
/* func_002F6088 — 15 words. MATCH 100% (shape: m2c). */
void func_002F6088(s32 arg0, int arg1) {
    extern int func_0017A608();
    extern int func_002EF7C0();
    extern int func_002F6088();
    func_002EF7C0();
    func_0017A608(arg0, arg1);
}
/* func_002F60C4 — 9 words. MATCH 100% (shape: m2c). */
void func_002F60C4(void) {
    extern int func_0003FAF4();
    extern int func_002EF7C0();
    extern int func_002F60C4();
    func_002EF7C0();
    func_0003FAF4();
}
/* func_002F60E8 — 11 words. MATCH 100% (shape: m2c). */
void func_002F60E8(s32 arg0) {
    extern int func_0003FBA8();
    extern int func_002EF7C0();
    extern int func_002F60E8();
    func_002EF7C0();
    func_0003FBA8(arg0);
}
/* func_002F6114 — 9 words. MATCH 100% (shape: m2c). */
void func_002F6114(void) {
    extern int func_0003FBB4();
    extern int func_002EF7C0();
    extern int func_002F6114();
    func_002EF7C0();
    func_0003FBB4();
}
/* func_002F6138 — 9 words. MATCH 100% (shape: m2c). */
void func_002F6138(void) {
    extern int func_0003FBF8();
    extern int func_002EF7C0();
    extern int func_002F6138();
    func_002EF7C0();
    func_0003FBF8();
}
/* func_002F615C — 11 words. MATCH 100% (shape: m2c). */
void func_002F615C(s32 arg0) {
    extern int func_0003FC04();
    extern int func_002EF7C0();
    extern int func_002F615C();
    func_002EF7C0();
    func_0003FC04(arg0);
}
/* func_002F6188 — 11 words. MATCH 100% (shape: m2c). */
void func_002F6188(s32 arg0) {
    extern int func_0003FCAC();
    extern int func_002EF7C0();
    extern int func_002F6188();
    func_002EF7C0();
    func_0003FCAC(arg0);
}
/* func_002F61B4 — 11 words. MATCH 100% (shape: m2c). */
void func_002F61B4(s32 arg0) {
    extern int func_0003FEEC();
    extern int func_002EF7C0();
    extern int func_002F61B4();
    func_002EF7C0();
    func_0003FEEC(arg0);
}
/* func_002F61E0 — 11 words. MATCH 100% (shape: m2c). */
void func_002F61E0(s32 arg0) {
    extern int func_0003FBD4();
    extern int func_002EF7C0();
    extern int func_002F61E0();
    func_002EF7C0();
    func_0003FBD4(arg0);
}
/* func_002F620C — 11 words. MATCH 100% (shape: m2c). */
void func_002F620C(s32 arg0) {
    extern int func_0003FF78();
    extern int func_002EF7C0();
    extern int func_002F620C();
    func_002EF7C0();
    func_0003FF78(arg0);
}
/* func_002F6238 — 15 words. MATCH 100% (shape: m2c). */
void func_002F6238(s32 arg0, int arg1) {
    extern int func_00040318();
    extern int func_002EF7C0();
    extern int func_002F6238();
    func_002EF7C0();
    func_00040318(arg0, arg1);
}
/* func_002F6274 — 11 words. MATCH 100% (shape: m2c). */
void func_002F6274(s32 arg0) {
    extern int func_00040358();
    extern int func_002EF7C0();
    extern int func_002F6274();
    func_002EF7C0();
    func_00040358(arg0);
}
/* func_002F62A0 — 11 words. MATCH 100% (shape: m2c). */
void func_002F62A0(s32 arg0) {
    extern int func_00040378();
    extern int func_002EF7C0();
    extern int func_002F62A0();
    func_002EF7C0();
    func_00040378(arg0);
}
/* func_002F62CC — 11 words. MATCH 100% (shape: m2c). */
void func_002F62CC(s32 arg0) {
    extern int func_00040418();
    extern int func_002EF7C0();
    extern int func_002F62CC();
    func_002EF7C0();
    func_00040418(arg0);
}
/* func_002F62F8 — 11 words. MATCH 100% (shape: m2c). */
void func_002F62F8(s32 arg0) {
    extern int func_00040470();
    extern int func_002EF7C0();
    extern int func_002F62F8();
    func_002EF7C0();
    func_00040470(arg0);
}
/* func_002F6324 — 9 words. MATCH 100% (shape: m2c). */
void func_002F6324(void) {
    extern int func_0003FBEC();
    extern int func_002EF7C0();
    extern int func_002F6324();
    func_002EF7C0();
    func_0003FBEC();
}
/* func_002F6348 — 11 words. MATCH 100% (shape: m2c). */
void func_002F6348(s32 arg0) {
    extern int func_0003FD74();
    extern int func_002EF7C0();
    extern int func_002F6348();
    func_002EF7C0();
    func_0003FD74(arg0);
}
/* func_002F6374 — 22 words. MATCH 100% (shape: m2c). */
void func_002F6374(s32 arg0, int arg1) {
    extern char D_003268E0;
    extern int ehsys_memcpy();
    extern int func_002EF7C0();
    extern int func_002F6374();
    func_002EF7C0();
    ehsys_memcpy(&D_003268E0 + (arg0 * 0xC0) + 0x2C, arg1, 0xC0);
}
/* func_002F6A4C — 13 words. MATCH 100% (shape: m2c). */
s32 func_002F6A4C(s32 arg0) {
    extern int ehsys_6595A5B3();
    extern int func_002F6A4C();
    if ((arg0 < 0) || (arg0 >= 0x51)) {
        return 0;
    }
    return ehsys_6595A5B3();
}
/* func_002F6A80 — 3 words. MATCH 100% (shape: hand). */
void func_002F6A80(int a0) {
    extern int D_003593FC;
    extern int func_002F6A80();
    D_003593FC = a0;
}

/* func_002F6AC0 — 2 words. MATCH 100% (shape: bulk). */
int func_002F6AC0(int arg1) {
    extern int func_002F547C();
    extern int func_002F6AC0();
    extern int func_002F547C();
    return func_002F547C(arg1);
}
/* func_002F6AFC — 3 words. MATCH 100% (shape: hand). */
void func_002F6AFC(int a0) {
    extern int D_00359410;
    extern int func_002F6AFC();
    D_00359410 = a0;
}

/* func_002F6B08 — 3 words. MATCH 100% (shape: bulk). */
int func_002F6B08(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8) {
    extern int ehsys_memset();
    extern int func_002F6B08();
    extern int ehsys_memset();
    return ehsys_memset(arg1, 0, arg2, arg4, arg5, arg6, arg7, arg8);
}

/* func_002F6B14 — 2 words. MATCH 100% (shape: bulk). */
int func_002F6B14(int arg1, int arg2, int arg3, int arg4) {
    extern int ehsys_memcpy();
    extern int func_002F6B14();
    extern int ehsys_memcpy();
    return ehsys_memcpy(arg1, arg2, arg3, arg4);
}
