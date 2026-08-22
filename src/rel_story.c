/*
 * rel_story.prx — reconstructed code (matching decompilation)
 *
 * Compiler:     Metrowerks CodeWarrior for PSP — MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,s -sdatathreshold 0
 * Verification: scripts/mwcc_build.sh src/rel_story.c
 *               scripts/mwcc_diff.py asm/rel_story/text.s build/mwcc/rel_story.o
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
 * STATUS: 240 functions matched. build/auto/rel_story.json has the
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


/* func_00000000 — 14 words. MATCH 100% (shape: m2c). */
s32 func_00000000(s32 arg0) {
    extern char D_0002A5C0;
    extern int ehsys_B4471B5E();
    extern int func_00000000();
    extern int func_00000038();
    extern int func_00000230();
    if (arg0 == 0) {
        ehsys_B4471B5E(func_00000038, func_00000230, &D_0002A5C0);
    }
    return 0;
}
/* func_00000038 — 44 words. MATCH 100% (shape: bool-fold). */
void func_00000038(void) {
    extern int ehsys_13A4081A();
    extern int ehsys_C2E59A21();
    extern int ehsys_frame_sync();
    extern int ehsys_sceKernelChangeCurrentThreadAttr();
    extern int func_00000038();
    extern int func_000000E8();
    extern int func_0000018C();
    extern int func_00000238();
    extern int func_00000240();
    extern int func_00003C6C();
    extern int func_000053AC();
    extern int func_00005478();
    extern int func_00005948();
    ehsys_sceKernelChangeCurrentThreadAttr(0, 0x4000);
    func_000000E8();
    ehsys_frame_sync();
    ehsys_C2E59A21(2, func_00000238, func_00000240);
    if (func_00003C6C()) {
        do {
            func_00005478();
            ehsys_frame_sync();
        } while (!func_00005948());
    }
    ehsys_C2E59A21(0, NULL, NULL);
    ehsys_13A4081A(1);
    ehsys_frame_sync();
    func_0000018C();
    func_000053AC();
}

/* func_000000E8 — 41 words. MATCH 100% (shape: m2c). */
void func_000000E8(void) {
    extern int func_000000E8();
    extern int func_00000248();
    extern int func_00000384();
    extern int func_00000AF8();
    extern int func_00002184();
    extern int func_00003518();
    extern int func_00003C44();
    extern int func_00009B70();
    extern int func_00009FA0();
    extern int func_0000B2DC();
    extern int func_0000B56C();
    extern int func_0000B5F8();
    extern int func_0000B860();
    extern int func_0000B8C8();
    extern int func_0000BCE8();
    extern int func_0001167C();
    extern int func_00011C24();
    extern int func_00013CEC();
    extern int func_00015814();
    func_00015814();
    func_00009B70();
    func_00003C44();
    func_00000AF8();
    func_0000B8C8();
    func_00002184();
    func_00011C24();
    func_0000BCE8();
    func_0000B2DC();
    func_0000B56C();
    func_00000384();
    func_00013CEC();
    func_00009FA0();
    func_0000B860();
    func_00003518();
    func_0000B5F8();
    func_00000248();
    func_0001167C();
}

/* func_0000018C — 41 words. MATCH 100% (shape: m2c). */
void func_0000018C(void) {
    extern int func_0000018C();
    extern int func_0000025C();
    extern int func_00000398();
    extern int func_00000B0C();
    extern int func_00002198();
    extern int func_0000352C();
    extern int func_00003C58();
    extern int func_00009B84();
    extern int func_00009FB4();
    extern int func_0000B2F0();
    extern int func_0000B580();
    extern int func_0000B60C();
    extern int func_0000B874();
    extern int func_0000B8D0();
    extern int func_0000BD18();
    extern int func_00011690();
    extern int func_00011C38();
    extern int func_00013D00();
    extern int func_00015854();
    func_0000B2F0();
    func_0000BD18();
    func_00011C38();
    func_00002198();
    func_0000B8D0();
    func_0000B580();
    func_00000398();
    func_00013D00();
    func_00009FB4();
    func_00003C58();
    func_00000B0C();
    func_0000B874();
    func_0000352C();
    func_0000B60C();
    func_0000025C();
    func_00011690();
    func_00009B84();
    func_00015854();
}

/* func_00000230 — 2 words. MATCH 100% (shape: m2c). */
void func_00000230(void) {
    extern int func_00000230();

}

/* func_00000238 — 2 words. MATCH 100% (shape: m2c). */
void func_00000238(void) {
    extern int func_00000238();
    extern int func_00005954();
    func_00005954();
}

/* func_00000240 — 2 words. MATCH 100% (shape: m2c). */
void func_00000240(void) {
    extern int func_00000240();

}

/* func_00000248 — 5 words. MATCH 100% (shape: manual). */
void func_00000248(void) {
    extern char D_0002A5CC;
    extern int ehsys_memset();
    ehsys_memset(&D_0002A5CC, 0, 0x4);
}

/* func_0000025C — 5 words. MATCH 100% (shape: manual). */
void func_0000025C(void) {
    extern char D_0002A5CC;
    extern int ehsys_memset();
    ehsys_memset(&D_0002A5CC, 0, 0x4);
}

/* func_00000384 — 5 words. MATCH 100% (shape: manual). */
void func_00000384(void) {
    extern char D_0002A5D0;
    extern int ehsys_memset();
    ehsys_memset(&D_0002A5D0, 0, 0x84);
}

/* func_00000398 — 5 words. MATCH 100% (shape: manual). */
void func_00000398(void) {
    extern char D_0002A5D0;
    extern int ehsys_memset();
    ehsys_memset(&D_0002A5D0, 0, 0x84);
}

/* func_000003AC — 3 words. MATCH 100% (shape: manual). */
void func_000003AC(s32 arg0) {
    extern s32 D_0002A654;
    D_0002A654 = arg0;
}

/* func_000003B8 — 5 words. MATCH 100% (shape: manual). */
void func_000003B8(void) {
    extern void *D_0002A654;
    extern int ehsys_memset();
    ehsys_memset(D_0002A654, 0, 0x200);
}

/* func_000003CC — 3 words. MATCH 100% (shape: manual). */
void func_000003CC(s32 arg0) {
    extern s32 D_0002A5D0;
    D_0002A5D0 = arg0;
}

/* func_00000AF8 — 5 words. MATCH 100% (shape: manual). */
void func_00000AF8(void) {
    extern char D_0002A658;
    extern int ehsys_memset();
    ehsys_memset(&D_0002A658, 0, 0x8);
}

/* func_00000B0C — 5 words. MATCH 100% (shape: manual). */
void func_00000B0C(void) {
    extern char D_0002A658;
    extern int ehsys_memset();
    ehsys_memset(&D_0002A658, 0, 0x8);
}

/* func_00000B20 — 3 words. MATCH 100% (shape: manual). */
void func_00000B20(s32 arg0) {
    extern s32 D_0002A660;
    D_0002A660 = arg0;
}

/* func_00000B2C — 5 words. MATCH 100% (shape: manual). */
void func_00000B2C(void) {
    extern void *D_0002A660;
    extern int ehsys_memset();
    ehsys_memset(D_0002A660, 0, 0x1C);
}

/* func_00000B40 — 17 words. MATCH 100% (shape: manual, lever: dispatcher
 * forwards arg0 as an unused passthrough to callees that don't touch it). */
extern u16 func_000025DC();
extern u16 func_000025FC();
extern int func_0000B498();
void func_00000B40(s32 arg0) {
    if (func_0000B498(arg0) != 0) {
        func_000025FC(arg0);
    } else {
        func_000025DC(arg0);
    }
}

/* func_00000B84 — 17 words. MATCH 100% (shape: manual). */
extern s32 func_00002C3C();
extern s32 func_00002C7C();
void func_00000B84(s32 arg0) {
    if (func_0000B498(arg0) != 0) {
        func_00002C7C(arg0);
    } else {
        func_00002C3C(arg0);
    }
}

/* func_00000BC8 — 17 words. MATCH 100% (shape: manual). */
extern s32 func_00002CBC();
extern s32 func_00002CFC();
void func_00000BC8(s32 arg0) {
    if (func_0000B498(arg0) != 0) {
        func_00002CFC(arg0);
    } else {
        func_00002CBC(arg0);
    }
}

/* func_00000C0C — 17 words. MATCH 100% (shape: manual). */
extern s32 func_00002C1C();
extern s32 func_00002C5C();
void func_00000C0C(s32 arg0) {
    if (func_0000B498(arg0) != 0) {
        func_00002C5C(arg0);
    } else {
        func_00002C1C(arg0);
    }
}

/* func_00000C50 — 17 words. MATCH 100% (shape: manual). */
extern s32 func_00002C9C();
extern s32 func_00002CDC();
void func_00000C50(s32 arg0) {
    if (func_0000B498(arg0) != 0) {
        func_00002CDC(arg0);
    } else {
        func_00002C9C(arg0);
    }
}

/* func_00000C94 — 17 words. MATCH 100% (shape: manual). */
extern u8 func_00002D3C();
extern u8 func_00002D7C();
void func_00000C94(s32 arg0) {
    if (func_0000B498(arg0) != 0) {
        func_00002D7C(arg0);
    } else {
        func_00002D3C(arg0);
    }
}

/* func_00000CD8 — 17 words. MATCH 100% (shape: manual). */
extern u8 func_00002D1C();
extern u8 func_00002D5C();
void func_00000CD8(s32 arg0) {
    if (func_0000B498(arg0) != 0) {
        func_00002D5C(arg0);
    } else {
        func_00002D1C(arg0);
    }
}

/* func_00000D1C — 17 words. MATCH 100% (shape: manual). */
extern u8 func_00002D9C();
extern u8 func_00002E98();
void func_00000D1C(s32 arg0) {
    if (func_0000B498(arg0) != 0) {
        func_00002E98(arg0);
    } else {
        func_00002D9C(arg0);
    }
}

/* func_00000D60 — 17 words. MATCH 100% (shape: manual). */
extern u8 func_00002E78();
extern u8 func_00002EB8();
void func_00000D60(s32 arg0) {
    if (func_0000B498(arg0) != 0) {
        func_00002EB8(arg0);
    } else {
        func_00002E78(arg0);
    }
}

/* func_00000DA4 — 9 words. MATCH 100% (shape: manual). */
void func_00000DA4(s32 arg0) {
    extern s32 D_0002A660;
    s32 *p = (s32 *)D_0002A660;
    if ((arg0 >= 0) || (arg0 < 0x26)) {
        *p = arg0;
    }
}

/* func_00000DC8 — 4 words. MATCH 100% (shape: manual). */
s32 func_00000DC8(void) {
    extern void *D_0002A660;
    return *(s32 *)((char *)D_0002A660);
}

/* func_00000DD8 — 3 words. MATCH 100% (shape: manual). */
void func_00000DD8(s32 arg0) {
    extern s32 D_0002A658;
    D_0002A658 = arg0;
}

/* func_00000DE4 — 4 words. MATCH 100% (shape: manual). */
s32 func_00000DE4(void) {
    extern s32 D_0002A658;
    return D_0002A658 != 0;
}

/* func_00000DF4 — 4 words. MATCH 100% (shape: manual). */
void func_00000DF4(s32 arg0) {
    extern void *D_0002A660;
    *(s32 *)((char *)D_0002A660 + 0x4) = (s32)arg0;
}

/* func_00000E04 — 4 words. MATCH 100% (shape: manual). */
s32 func_00000E04(void) {
    extern void *D_0002A660;
    return *(s32 *)((char *)D_0002A660 + 0x4);
}

/* func_00000E14 — 4 words. MATCH 100% (shape: manual). */
void func_00000E14(s32 arg0) {
    extern void *D_0002A660;
    *(s16 *)((char *)D_0002A660 + 0xC) = (s16)arg0;
}

/* func_00000E24 — 4 words. MATCH 100% (shape: manual). */
s32 func_00000E24(void) {
    extern void *D_0002A660;
    return *(u16 *)((char *)D_0002A660 + 0xC);
}

/* func_00000E34 — 4 words. MATCH 100% (shape: manual). */
void func_00000E34(s32 arg0) {
    extern void *D_0002A660;
    *(s32 *)((char *)D_0002A660 + 0x8) = (s32)arg0;
}

/* func_00000E44 — 4 words. MATCH 100% (shape: manual). */
s32 func_00000E44(void) {
    extern void *D_0002A660;
    return *(s32 *)((char *)D_0002A660 + 0x8);
}

/* func_00000F4C — 3 words. MATCH 100% (shape: manual). */
void func_00000F4C(s32 arg0) {
    extern s32 D_0002A65C;
    D_0002A65C = arg0;
}

/* func_00001400 — 2 words. MATCH 100% (shape: m2c). */
void func_00001400(void) {
    extern int func_00001400();

}

/* func_0000195C — 23 words. MATCH 100% (shape: m2c). */
void func_0000195C(void) {
    extern int func_0000195C();
    extern int func_00001CE0();
    extern int func_0000BBD8();
    extern int func_0000BDE0();
    extern int func_000123C4();
    extern int func_00012408();
    int sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;

    if (func_0000BBD8() != -1) {
        func_00001CE0(&sp1C, &sp18, &sp14, &sp10);
        func_00012408();
        func_0000BDE0(sp18, sp14, sp10);
        func_000123C4();
    }
}

/* func_00001E9C — 9 words. MATCH 100% (shape: m2c). */
void func_00001E9C(void) {
    extern int func_00001E9C();
    extern int func_0000B8A8();
    extern int func_00011D00();
    func_0000B8A8(0);
    func_00011D00();
}

/* func_00001EC0 — 2 words. MATCH 100% (shape: m2c). */
void func_00001EC0(void) {
    extern int func_00001EC0();

}

/* func_00002184 — 5 words. MATCH 100% (shape: manual). */
void func_00002184(void) {
    extern char D_0002A664;
    extern int ehsys_memset();
    ehsys_memset(&D_0002A664, 0, 0x4AC4);
}

/* func_00002198 — 5 words. MATCH 100% (shape: manual). */
void func_00002198(void) {
    extern char D_0002A664;
    extern int ehsys_memset();
    ehsys_memset(&D_0002A664, 0, 0x4AC4);
}

/* func_000023EC — 13 words. MATCH 100% (shape: m2c). */
void func_000023EC(s32 arg0) {
    extern int ehsys_C5D3B70C();
    extern int func_000023EC();
    extern int func_00002A3C();
    ehsys_C5D3B70C(0, arg0, func_00002A3C());
}

/* func_00002420 — 27 words. MATCH 100% (shape: manual, lever: don't hoist
 * the shared assignment out of the if/else -- write it in each branch as
 * m2c did, or MWCC materializes an address register that the target
 * doesn't). */
extern int func_00002358();
void func_00002420(s32 unused0, s32 arg1, s32 arg2) {
    void *p = (void *)func_00002358();
    if (arg2 != 0) {
        *(int *)((char *)p + 0x54) = (*(int *)((char *)p + 0x54)) | (1 << (arg1 - 1));
    } else {
        *(int *)((char *)p + 0x54) = (*(int *)((char *)p + 0x54)) & ~(1 << (arg1 - 1));
    }
}

/* func_000024C8 — 10 words. MATCH 100% (shape: manual, lever: func_00002358
 * field-setter family). */
extern int func_00002358();
void func_000024C8(s32 unused0, s16 arg1) {
    *(s16 *)((char *)func_00002358() + 0x18) = arg1;
}

/* func_000024F0 — 8 words. MATCH 100% (shape: manual). */
u16 func_000024F0(void) {
    return *(u16 *)((char *)func_00002358() + 0x18);
}

/* func_000025DC — 8 words. MATCH 100% (shape: manual). */
u16 func_000025DC(void) {
    return *(u16 *)((char *)func_00002358() + 0x0);
}

/* func_000025FC — 8 words. MATCH 100% (shape: manual). */
u16 func_000025FC(void) {
    return *(u16 *)((char *)func_00002358() + 0x28);
}

/* func_0000263C — 23 words. MATCH 100% (shape: manual, lever: pointer-global
 * array — D_0002F128 is an array of 0x5C-byte structs; index*0x5C+base
 * addressing works fine here despite resembling the D_00034580/84
 * commutative-addu family). */
extern s32 D_0002F128;
extern int ehsys_783340AE();
void func_0000263C(void) {
    s32 i;
    for (i = 0; i < 0x91; i++) {
        ehsys_783340AE(*(int *)((char *)D_0002F128 + i * 0x5C + 0x1C), 0);
    }
}

/* func_00002698 — 28 words. MATCH 100% (shape: manual). */
extern int ehsys_92675210();
extern int ehsys_64320906();
void func_00002698(void) {
    s32 i;
    for (i = 0; i < 0x91; i++) {
        char *e = (char *)D_0002F128 + i * 0x5C;
        ehsys_92675210(*(int *)(e + 0x1C), 1);
        ehsys_64320906(*(int *)(e + 0x1C), 0);
    }
}

/* func_00002854 — 32 words. MATCH 100% (shape: manual, lever: a float
 * argument needs an explicit prototype -- `extern int f(int, float);` --
 * or K&R default-argument-promotion widens the literal to double and the
 * whole call shape changes). */
extern int ehsys_8CFD5EC1(int, float);
extern int ehsys_9F4359AB();
extern int ehsys_0EB054A9();
void func_00002854(void) {
    s32 i;
    for (i = 0; i < 0x91; i++) {
        char *e = (char *)D_0002F128 + i * 0x5C;
        ehsys_8CFD5EC1(*(int *)(e + 0x1C), 2.5f);
        ehsys_9F4359AB(*(int *)(e + 0x1C), 0);
        ehsys_0EB054A9(*(int *)(e + 0x1C), 0);
    }
}

/* func_000028D4 — 37 words. MATCH 100% (shape: manual, lever: re-read the
 * field at each call site inside the loop rather than caching it in a
 * local -- caching forces an extra callee-unsaved register + move per
 * call that the target does not have). */
extern int ehsys_481242AF();
void func_000028D4(void) {
    s32 i, j;
    for (i = 0; i < 0x91; i++) {
        char *e = (char *)D_0002F128 + i * 0x5C;
        for (j = 0; j < 3; j++) {
            ehsys_481242AF(*(int *)(e + 0x1C), j, 5);
        }
        ehsys_481242AF(*(int *)(e + 0x1C), 3, 1);
    }
}

/* func_00002968 — 43 words. MATCH 100% (shape: manual). */
extern int ehsys_2D976EA8();
extern int ehsys_C78C87F4();
extern int ehsys_E7FAA144();
extern int ehsys_B75B23D0();
extern int ehsys_F358A88E();
extern int ehsys_DDAAA4FF();
extern int ehsys_074A3951();
void func_00002968(void) {
    s32 i;
    for (i = 0; i < 0x91; i++) {
        char *e = (char *)D_0002F128 + i * 0x5C;
        ehsys_2D976EA8(*(int *)(e + 0x1C), 0);
        ehsys_C78C87F4(*(int *)(e + 0x1C), 0xFFFF);
        ehsys_E7FAA144(*(int *)(e + 0x1C), 0);
        ehsys_B75B23D0(*(int *)(e + 0x1C), 0);
        ehsys_F358A88E(*(int *)(e + 0x1C), 0);
        ehsys_DDAAA4FF(*(int *)(e + 0x1C), 0);
        ehsys_074A3951(*(int *)(e + 0x1C), 0);
    }
}

/* func_00002A14 — 10 words. MATCH 100% (shape: manual). */
void func_00002A14(s32 unused0, s32 arg1) {
    *(s32 *)((char *)func_00002358() + 0x20) = arg1;
}

/* func_00002B74 — 18 words. MATCH 100% (shape: manual). */
void func_00002B74(s32 unused0, s32 arg1, s32 arg2, s32 arg3) {
    void *p = (void *)func_00002358();
    *(int *)((char *)p + 0x4) = arg1;
    *(int *)((char *)p + 0x8) = arg2;
    *(unsigned char *)((char *)p + 0x14) = arg3;
}

/* func_00002BBC — 14 words. MATCH 100% (shape: manual). */
void func_00002BBC(s32 unused0, s32 arg1, s32 arg2) {
    void *p = (void *)func_00002358();
    *(int *)((char *)p + 0x2C) = arg1;
    *(int *)((char *)p + 0x30) = arg2;
}

/* func_00002BF4 — 10 words. MATCH 100% (shape: manual). */
void func_00002BF4(s32 unused0, s8 arg1) {
    *(s8 *)((char *)func_00002358() + 0x3C) = arg1;
}

/* func_00002C1C — 8 words. MATCH 100% (shape: manual). */
s32 func_00002C1C(void) {
    return *(s32 *)((char *)func_00002358() + 0x4);
}

/* func_00002C3C — 8 words. MATCH 100% (shape: manual). */
s32 func_00002C3C(void) {
    return *(s32 *)((char *)func_00002358() + 0xC);
}

/* func_00002C5C — 8 words. MATCH 100% (shape: manual). */
s32 func_00002C5C(void) {
    return *(s32 *)((char *)func_00002358() + 0x2C);
}

/* func_00002C7C — 8 words. MATCH 100% (shape: manual). */
s32 func_00002C7C(void) {
    return *(s32 *)((char *)func_00002358() + 0x34);
}

/* func_00002C9C — 8 words. MATCH 100% (shape: manual). */
s32 func_00002C9C(void) {
    return *(s32 *)((char *)func_00002358() + 0x8);
}

/* func_00002CBC — 8 words. MATCH 100% (shape: manual). */
s32 func_00002CBC(void) {
    return *(s32 *)((char *)func_00002358() + 0x10);
}

/* func_00002CDC — 8 words. MATCH 100% (shape: manual). */
s32 func_00002CDC(void) {
    return *(s32 *)((char *)func_00002358() + 0x30);
}

/* func_00002CFC — 8 words. MATCH 100% (shape: manual). */
s32 func_00002CFC(void) {
    return *(s32 *)((char *)func_00002358() + 0x38);
}

/* func_00002D1C — 8 words. MATCH 100% (shape: manual). */
u8 func_00002D1C(void) {
    return *(u8 *)((char *)func_00002358() + 0x14);
}

/* func_00002D3C — 8 words. MATCH 100% (shape: manual). */
u8 func_00002D3C(void) {
    return *(u8 *)((char *)func_00002358() + 0x15);
}

/* func_00002D5C — 8 words. MATCH 100% (shape: manual). */
u8 func_00002D5C(void) {
    return *(u8 *)((char *)func_00002358() + 0x3C);
}

/* func_00002D7C — 8 words. MATCH 100% (shape: manual). */
u8 func_00002D7C(void) {
    return *(u8 *)((char *)func_00002358() + 0x3D);
}

/* func_00002D9C — 8 words. MATCH 100% (shape: manual). */
u8 func_00002D9C(void) {
    return *(u8 *)((char *)func_00002358() + 0x16);
}
/* func_00002DBC — 47 words. MATCH 100% (shape: m2c asm-fields). */
void func_00002DBC(void) {
    extern int D_0001FF24;
    extern int D_0002F128;
    extern int ehsys_D4DE5DD8();
    extern int func_000018F8();
    extern int func_00002DBC();
    s32 var_s1;
    s32 var_v1;
    int temp_s0;
    var_s1 = 0;
    do {
        temp_s0 = D_0002F128 + (var_s1 * 0x5C);
        if (func_000018F8((*(int *)((char *)temp_s0 + 0x1C))) != 0) {
            var_v1 = 0;
        } else if ((ehsys_D4DE5DD8() % 3) != 0) {
            var_v1 = 0;
        } else {
            var_v1 = ehsys_D4DE5DD8() % 10;
        }
        var_s1 += 1;
        (*(unsigned char *)((char *)temp_s0 + 0x17)) = (s8) (&D_0001FF24)[var_v1];
    } while (var_s1 < 0x91);
}

/* func_00002E78 — 8 words. MATCH 100% (shape: manual). */
u8 func_00002E78(void) {
    return *(u8 *)((char *)func_00002358() + 0x17);
}

/* func_00002E98 — 8 words. MATCH 100% (shape: manual). */
u8 func_00002E98(void) {
    return *(u8 *)((char *)func_00002358() + 0x3E);
}

/* func_00002EB8 — 8 words. MATCH 100% (shape: manual). */
u8 func_00002EB8(void) {
    return *(u8 *)((char *)func_00002358() + 0x3F);
}

/* func_00002ED8 — 32 words. MATCH 100% (shape: manual). */
void func_00002ED8(void) {
    s32 i;
    for (i = 0; i < 0x91; i++) {
        char *e = (char *)D_0002F128 + i * 0x5C;
        *(u16 *)(e + 0x40) = 0xFDE8;
        *(u16 *)(e + 0x42) = 0xFDE8;
        *(u16 *)(e + 0x46) = 0xFDE8;
        *(u16 *)(e + 0x48) = 0xFDE8;
        *(u16 *)(e + 0x4A) = 0xFDE8;
        *(u16 *)(e + 0x28) = 0;
        *(int *)(e + 0x2C) = 0;
        *(int *)(e + 0x30) = 0;
        *(int *)(e + 0x34) = 0;
        *(int *)(e + 0x38) = 0;
        *(unsigned char *)(e + 0x3C) = 0;
        *(unsigned char *)(e + 0x3D) = 0;
        *(unsigned char *)(e + 0x3E) = 0;
        *(unsigned char *)(e + 0x3F) = 0;
        *(u16 *)(e + 0x4C) = 0;
        *(u16 *)(e + 0x4E) = 0;
        *(u16 *)(e + 0x50) = 0;
    }
}

/* func_00002F58 — 10 words. MATCH 100% (shape: manual). */
void func_00002F58(s32 unused0, s16 arg1) {
    *(s16 *)((char *)func_00002358() + 0x40) = arg1;
}

/* func_00002F80 — 10 words. MATCH 100% (shape: manual). */
void func_00002F80(s32 unused0, s16 arg1) {
    *(s16 *)((char *)func_00002358() + 0x42) = arg1;
}

/* func_00002FA8 — 10 words. MATCH 100% (shape: manual). */
void func_00002FA8(s32 unused0, s16 arg1) {
    *(s16 *)((char *)func_00002358() + 0x44) = arg1;
}

/* func_00002FD0 — 20 words. MATCH 100% (shape: manual). */
void func_00002FD0(s32 unused0, s32 arg1, s32 arg2) {
    void *p = (void *)func_00002358();
    *(s16 *)((char *)p + 0x46) = arg1;
    *(s16 *)((char *)p + 0x48) = arg2 / 100;
    *(s16 *)((char *)p + 0x4A) = arg2 % 100;
}

/* func_00003020 — 18 words. MATCH 100% (shape: manual). */
void func_00003020(s32 unused0, s32 arg1, s32 arg2, s32 arg3) {
    void *p = (void *)func_00002358();
    *(s16 *)((char *)p + 0x28) = arg3;
    *(int *)((char *)p + 0x34) = arg1;
    *(int *)((char *)p + 0x38) = arg2;
}

/* func_00003068 — 17 words. MATCH 100% (shape: manual). */
extern int func_00003834();
void func_00003068(s32 unused0, s32 arg1, s32 arg2) {
    void *p = (void *)func_00002358();
    s32 v = func_00003834(arg1);
    *(unsigned char *)((char *)p + 0x3D) = v;
    *(unsigned char *)((char *)p + 0x3E) = arg2;
}

/* func_000030AC — 10 words. MATCH 100% (shape: manual). */
void func_000030AC(s32 unused0, s8 arg1) {
    *(s8 *)((char *)func_00002358() + 0x3F) = arg1;
}

/* func_000030D4 — 20 words. MATCH 100% (shape: manual). */
void func_000030D4(s32 unused0, s32 arg1, s32 arg2) {
    void *p = (void *)func_00002358();
    *(s16 *)((char *)p + 0x4C) = arg1;
    *(s16 *)((char *)p + 0x4E) = arg2 / 100;
    *(s16 *)((char *)p + 0x50) = arg2 % 100;
}

/* func_00003124 — 21 words. MATCH 100% (shape: manual). */
void func_00003124(s32 unused0, s32 *arg1, s32 *arg2, s32 *arg3) {
    void *p = (void *)func_00002358();
    *arg1 = *(u16 *)((char *)p + 0x4C);
    *arg2 = *(u16 *)((char *)p + 0x4E);
    *arg3 = *(u16 *)((char *)p + 0x50);
}

/* func_00003178 — 21 words. MATCH 100% (shape: manual). */
void func_00003178(s32 unused0, s32 *arg1, s32 *arg2, s32 *arg3) {
    void *p = (void *)func_00002358();
    *arg1 = *(u16 *)((char *)p + 0x46);
    *arg2 = *(u16 *)((char *)p + 0x48);
    *arg3 = *(u16 *)((char *)p + 0x4A);
}

/* func_0000261C — 8 words. MATCH 100% (shape: m2c). */
s32 func_0000261C(void) {
    extern int ehsys_B27BC15D();
    extern int func_0000261C();
    return ehsys_B27BC15D() & 0xFFFF;
}

/* func_00002818 — 11 words. MATCH 100% (shape: m2c). */
s32 func_00002818(s32 arg0) {
    extern int func_00002818();
    extern int func_00002844();
    return arg0 == func_00002844();
}

/* func_00002844 — 2 words. MATCH 100% (shape: m2c). */
void func_00002844(void) {
    extern int ehsys_CCDAED90();
    extern int func_00002844();
    ehsys_CCDAED90();
}

/* func_0000284C — 2 words. MATCH 100% (shape: m2c). */
void func_0000284C(void) {
    extern int ehsys_81857D14();
    extern int func_0000284C();
    ehsys_81857D14();
}
/* func_00002AD4 — 17 words. MATCH 100% (shape: m2c). */
s32 func_00002AD4(s32 arg0) {
    extern int func_00002358();
    extern int func_00002A3C();
    extern int func_00002AD4();
    extern int func_00013B2C();
    s32 sp1C;
    s32 temp_s0;

    temp_s0 = func_00002358();
    func_00013B2C((*(int *)((char *)temp_s0 + 0x1C)), func_00002A3C(arg0), &sp1C);
    return sp1C;
}
/* func_0000335C — 22 words. MATCH 100% (shape: bool-fold). */
s32 func_0000335C(s32 arg0) {
    extern int ehsys_5D9E6261();
    extern int ehsys_7DFFA500();
    extern int func_00002358();
    extern int func_00002A88();
    extern int func_0000335C();
    extern int func_000033B4();
    s32 temp_v0;

    func_00002358();
    temp_v0 = ehsys_7DFFA500(arg0, func_00002A88(arg0));
    if (!func_000033B4(arg0, temp_v0)) {
        return 0;
    }
    return ehsys_5D9E6261(temp_v0);
}

/* func_00003418 — 8 words. MATCH 100% (shape: m2c). */
s32 func_00003418(void) {
    extern int func_00003418();
    extern int func_00003488();
    return func_00003488() + 4;
}

/* func_00003438 — 10 words. MATCH 100% (shape: manual). */
extern s32 D_0002F128;
s32 func_00003438(s32 arg0) {
    return *(int *)((char *)D_0002F128 + arg0 * 0x5C + 0x1C);
}

/* func_00003460 — 10 words. MATCH 100% (shape: manual). */
s32 func_00003460(s32 arg0) {
    return *(int *)((char *)D_0002F128 + arg0 * 0x5C + 0x20);
}

/* func_00003518 — 5 words. MATCH 100% (shape: manual). */
void func_00003518(void) {
    extern char D_0002F130;
    extern int ehsys_memset();
    ehsys_memset(&D_0002F130, 0, 0x2);
}

/* func_0000352C — 5 words. MATCH 100% (shape: manual). */
void func_0000352C(void) {
    extern char D_0002F130;
    extern int ehsys_memset();
    ehsys_memset(&D_0002F130, 0, 0x2);
}

/* func_00003C44 — 5 words. MATCH 100% (shape: manual). */
void func_00003C44(void) {
    extern char D_0002F134;
    extern int ehsys_memset();
    ehsys_memset(&D_0002F134, 0, 0x4964);
}

/* func_00003C58 — 5 words. MATCH 100% (shape: manual). */
void func_00003C58(void) {
    extern char D_0002F134;
    extern int ehsys_memset();
    ehsys_memset(&D_0002F134, 0, 0x4964);
}

/* func_00005394 — 6 words. MATCH 100% (shape: manual). */
void *func_00005394(u16 *arg0, u16 *arg1) {
    arg0[0] = arg1[0];
    arg0[1] = arg1[1];
    return arg0;
}

/* func_00005948 — 3 words. MATCH 100% (shape: manual). */
s32 func_00005948(void) {
    extern s32 D_0002F134;
    return D_0002F134;
}

/* func_000068A4 — 9 words. MATCH 100% (shape: m2c). */
s32 func_000068A4(void) {
    extern int field_79E5F8B7();
    extern int func_000068A4();
    int sp1C;

    return field_79E5F8B7(0x20, &sp1C) != 0;
}

/* func_000068C8 — 8 words. MATCH 100% (shape: m2c). */
void func_000068C8(void) {
    extern int field_86220A06();
    extern int func_000068C8();
    int sp1C;

    field_86220A06(0x21, &sp1C);
}

/* func_000068E8 — 9 words. MATCH 100% (shape: m2c). */
s32 func_000068E8(void) {
    extern int field_79E5F8B7();
    extern int func_000068E8();
    int sp1C;

    return field_79E5F8B7(0x21, &sp1C) != 0;
}

/* func_00006E60 — 11 words. MATCH 100% (shape: manual). */
extern void *D_0002F13C;
extern int field_86220A06();
void func_00006E60(void) {
    int sp1C;
    field_86220A06(0x10, &sp1C);
    D_0002F13C = (void *)6;
}

/* func_00008CB4 — 11 words. MATCH 100% (shape: m2c). */
void func_00008CB4(void) {
    extern int ehsys_13A4081A();
    extern int ehsys_frame_sync();
    extern int field_E92DC2F2();
    extern int func_00008CB4();
    field_E92DC2F2();
    ehsys_frame_sync();
    ehsys_13A4081A(1);
}

/* func_00008CE0 — 9 words. MATCH 100% (shape: m2c). */
void func_00008CE0(void) {
    extern int field_74B014A2();
    extern int field_FABFD3C6();
    extern int func_00008CE0();
    field_FABFD3C6();
    field_74B014A2();
}

/* func_00008EB4 — 12 words. MATCH 100% (shape: m2c). */
void func_00008EB4(void) {
    extern int ehsys_13A4081A();
    extern int func_00008EB4();
    extern int recipe_viewer_98E7E882();
    recipe_viewer_98E7E882(0, 0, 1, 1);
    ehsys_13A4081A(0);
}

/* func_00008F54 — 9 words. MATCH 100% (shape: m2c). */
void func_00008F54(void) {
    extern int ehsys_13A4081A();
    extern int func_00008F54();
    extern int password_932AE9C8();
    password_932AE9C8();
    ehsys_13A4081A(0);
}

/* func_00008FE4 — 12 words. MATCH 100% (shape: m2c). */
void func_00008FE4(void) {
    extern int ehsys_13A4081A();
    extern int func_00008FE4();
    extern int select_card_BF2B46D7();
    select_card_BF2B46D7(0, 0, 0, 0);
    ehsys_13A4081A(0);
}

/* func_00009080 — 9 words. MATCH 100% (shape: m2c). */
void func_00009080(void) {
    extern int conv_machine_0BB25540();
    extern int ehsys_13A4081A();
    extern int func_00009080();
    conv_machine_0BB25540();
    ehsys_13A4081A(0);
}

/* func_00009110 — 10 words. MATCH 100% (shape: m2c). */
void func_00009110(void) {
    extern int cardalbum_EE554159();
    extern int ehsys_13A4081A();
    extern int func_00009110();
    cardalbum_EE554159(1, 0);
    ehsys_13A4081A(0);
}

/* func_000092D8 — 10 words. MATCH 100% (shape: m2c). */
void func_000092D8(void) {
    extern int ehsys_13A4081A();
    extern int func_000092D8();
    extern int limitlist_E69A45D2();
    limitlist_E69A45D2(1, 0);
    ehsys_13A4081A(0);
}

/* func_0000939C — 12 words. MATCH 100% (shape: m2c). */
void func_0000939C(void) {
    extern int ehsys_13A4081A();
    extern int func_00000DC8();
    extern int func_0000939C();
    extern int tutoriallist_41015B0F();
    tutoriallist_41015B0F(func_00000DC8(), 0);
    ehsys_13A4081A(0);
}

/* func_00009598 — 12 words. MATCH 100% (shape: m2c). */
void func_00009598(void) {
    extern int deck_tutorial_4E16F5A6();
    extern int ehsys_13A4081A();
    extern int func_00000DC8();
    extern int func_00009598();
    deck_tutorial_4E16F5A6(func_00000DC8(), 0);
    ehsys_13A4081A(0);
}

/* func_00009644 — 9 words. MATCH 100% (shape: m2c). */
void func_00009644(void) {
    extern int duelrecord_6ADB95DB();
    extern int ehsys_13A4081A();
    extern int func_00009644();
    duelrecord_6ADB95DB(0);
    ehsys_13A4081A(0);
}

/* func_0000986C — 19 words. MATCH 100% (shape: m2c). */
void func_0000986C(void) {
    extern void *D_0002F13C;
    extern void *D_0002F150;
    extern int ehsys_13A4081A();
    extern int func_00000E54();
    extern int func_0000986C();
    extern int func_000098B8();
    func_00000E54(1, 1, 0, 0);
    ehsys_13A4081A(0);
    D_0002F13C = (void *)0x31;
    D_0002F150 = func_000098B8;
}

/* func_00009A30 — 16 words. MATCH 100% (shape: m2c). */
void func_00009A30(void) {
    extern int ehsys_13A4081A();
    extern int func_00000DF4();
    extern int func_00000E54();
    extern int func_00009A30();
    extern int func_00011874();
    func_00011874();
    func_00000E54(0, 1, 0, 0);
    ehsys_13A4081A(1);
    func_00000DF4(1);
}

/* func_00009B70 — 5 words. MATCH 100% (shape: manual). */
void func_00009B70(void) {
    extern char D_00033A98;
    extern int ehsys_memset();
    ehsys_memset(&D_00033A98, 0, 0x14);
}

/* func_00009B84 — 12 words. MATCH 100% (shape: m2c). */
void func_00009B84(void) {
    extern char D_00033A98;
    extern int ehsys_memset();
    extern int func_00009B84();
    extern int func_00009E94();
    func_00009E94();
    ehsys_memset(&D_00033A98, 0, 0x14);
}

/* func_00009E1C — 30 words. MATCH 100% (shape: m2c). */
s32 func_00009E1C(void) {
    extern char D_000200F4;
    extern char D_00020108;
    extern char D_0002011C;
    extern char D_00020134;
    extern int func_00009E1C();
    extern int func_00012104();
    extern int func_0001222C();
    extern int func_00012238();
    extern int func_00015778();
    extern int func_000159CC();
    func_00012104(func_000159CC(2, &D_000200F4));
    func_0001222C(func_000159CC(2, &D_00020108));
    func_00012238(func_000159CC(2, &D_0002011C));
    func_00015778(func_000159CC(3, &D_00020134));
    return 1;
}

/* func_00009FA0 — 5 words. MATCH 100% (shape: manual). */
void func_00009FA0(void) {
    extern char D_00034470;
    extern int ehsys_memset();
    ehsys_memset(&D_00034470, 0, 0x14);
}

/* func_00009FB4 — 5 words. MATCH 100% (shape: manual). */
void func_00009FB4(void) {
    extern char D_00034470;
    extern int ehsys_memset();
    ehsys_memset(&D_00034470, 0, 0x14);
}

/* func_00009FC8 — 3 words. MATCH 100% (shape: manual). */
void func_00009FC8(s32 arg0) {
    extern s32 D_00034484;
    D_00034484 = arg0;
}

/* func_00009FD4 — 5 words. MATCH 100% (shape: manual). */
void func_00009FD4(void) {
    extern void *D_00034484;
    extern int ehsys_memset();
    ehsys_memset(D_00034484, 0, 0x54);
}

/* func_00009FE8 — 32 words. MATCH 100% (shape: m2c). */
void func_00009FE8(void) {
    extern void *D_00033DA8;
    extern void *D_00033FA0;
    extern char D_00033ACC;
    extern void *D_00034198;
    extern char D_00034470;
    extern void *D_00034390;
    extern void *D_00034484;
    extern int ehsys_memset();
    extern int func_00009FE8();
    void *temp_s0;

    temp_s0 = D_00034484;
    ehsys_memset(&D_00033ACC, 0, 0x9A4);
    ehsys_memset(&D_00034470, 0, 0x14);
    ehsys_memset((void **) temp_s0, 0, 0x54);
    D_00033DA8 = (void *)1;
    D_00033FA0 = (void *)1;
    D_00034198 = (void *)1;
    D_00034390 = (void *)1;
}

/* func_0000AA80 — 6 words. MATCH 100% (shape: manual). */
void func_0000AA80(s32 arg0, s32 arg1, s32 arg2) {
    extern void *D_00034484;
    char *p = (char *)D_00034484;
    *(s32 *)(p + 0x38) = arg0;
    *(s32 *)(p + 0x3C) = arg1;
    *(s32 *)(p + 0x40) = arg2;
}

/* func_0000AA98 — 3 words. MATCH 100% (shape: manual). */
void func_0000AA98(s32 arg0) {
    extern s32 D_00034470;
    D_00034470 = arg0;
}

/* func_0000AB00 — 9 words. MATCH 100% (shape: manual). */
void func_0000AB00(s32 *arg0, s32 *arg1, s32 *arg2) {
    extern s32 D_00034484;
    char *p = (char *)D_00034484;
    *arg0 = *(int *)(p + 0x14);
    *arg1 = *(int *)(p + 0x18);
    *arg2 = *(int *)(p + 0x1C);
}

/* func_0000AB24 — 9 words. MATCH 100% (shape: manual). */
void func_0000AB24(s32 *arg0, s32 *arg1, s32 *arg2) {
    extern s32 D_00034484;
    char *p = (char *)D_00034484;
    *arg0 = *(int *)(p + 0x20);
    *arg1 = *(int *)(p + 0x24);
    *arg2 = *(int *)(p + 0x28);
}

/* func_0000AB48 — 9 words. MATCH 100% (shape: manual). */
void func_0000AB48(s32 *arg0, s32 *arg1, s32 *arg2) {
    extern s32 D_00034484;
    char *p = (char *)D_00034484;
    *arg0 = *(int *)(p + 0x2C);
    *arg1 = *(int *)(p + 0x30);
    *arg2 = *(int *)(p + 0x34);
}

/* func_0000AB6C — 4 words. MATCH 100% (shape: manual). */
s32 func_0000AB6C(void) {
    extern void *D_00034484;
    return *(s32 *)((char *)D_00034484 + 0x38);
}

/* func_0000AB7C — 4 words. MATCH 100% (shape: manual). */
s32 func_0000AB7C(void) {
    extern void *D_00034484;
    return *(s32 *)((char *)D_00034484 + 0x3C);
}

/* func_0000AB8C — 4 words. MATCH 100% (shape: manual). */
s32 func_0000AB8C(void) {
    extern void *D_00034484;
    return *(s32 *)((char *)D_00034484 + 0x40);
}

/* func_0000AE90 — 7 words. MATCH 100% (shape: manual). */
s32 func_0000AE90(s32 *arg0) {
    extern s32 D_00034484;
    char *p = (char *)D_00034484;
    if (arg0 != 0) {
        *arg0 = *(int *)(p + 0x4);
    }
    return *(int *)(p + 0x0);
}

/* func_0000AEAC — 7 words. MATCH 100% (shape: manual). */
s32 func_0000AEAC(s32 *arg0) {
    extern s32 D_00034484;
    char *p = (char *)D_00034484;
    if (arg0 != 0) {
        *arg0 = *(int *)(p + 0xC);
    }
    return *(int *)(p + 0x8);
}

/* func_0000AEC8 — 5 words. MATCH 100% (shape: manual). */
s32 func_0000AEC8(void) {
    extern void *D_00034484;
    return *(u8 *)((char *)D_00034484 + 0x44) & 1;
}

/* func_0000AEDC — 6 words. MATCH 100% (shape: manual). */
s32 func_0000AEDC(void) {
    extern void *D_00034484;
    u32 v = *(u8 *)((char *)D_00034484 + 0x44);
    return (v << 30) >> 31;
}

/* func_0000AEF4 — 5 words. MATCH 100% (shape: manual). */
void func_0000AEF4(s32 arg0, s32 arg1) {
    extern void *D_00034484;
    char *p = (char *)D_00034484;
    *(s32 *)(p + 0x48) = arg0;
    *(s32 *)(p + 0x4C) = arg1;
}

/* func_0000AF08 — 6 words. MATCH 100% (shape: manual). */
s32 func_0000AF08(s32 *arg0) {
    extern void *D_00034484;
    char *p = (char *)D_00034484;
    *arg0 = *(s32 *)(p + 0x4C);
    return *(s32 *)(p + 0x48);
}

/* func_0000AF20 — 4 words. MATCH 100% (shape: manual). */
void func_0000AF20(s32 arg0) {
    extern void *D_00034484;
    *(s32 *)((char *)D_00034484 + 0x50) = (s32)arg0;
}

/* func_0000AF30 — 4 words. MATCH 100% (shape: manual). */
s32 func_0000AF30(void) {
    extern void *D_00034484;
    return *(s32 *)((char *)D_00034484 + 0x50);
}

/* func_0000AF40 — 10 words. MATCH 100% (shape: manual). */
void func_0000AF40(s32 arg0) {
    extern s32 D_00034484;
    char *p = (char *)D_00034484;
    *(unsigned char *)(p + 0x44) = (*(unsigned char *)(p + 0x44) & ~4) | ((arg0 & 1) << 2);
}

/* func_0000AF68 — 4 words. MATCH 100% (shape: manual). */
void func_0000AF68(s32 arg0) {
    extern void *D_00034484;
    *(s32 *)((char *)D_00034484 + 0x10) = (s32)arg0;
}

/* func_0000AF78 — 4 words. MATCH 100% (shape: manual). */
s32 func_0000AF78(void) {
    extern void *D_00034484;
    return *(s32 *)((char *)D_00034484 + 0x10);
}

/* func_0000B0D0 — 26 words. MATCH 100% (shape: m2c). */
void func_0000B0D0(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3) {
    extern int ehsys_9090346C();
    extern int func_00002A3C();
    extern int func_0000B0D0();
    s32 sp1C;

    sp1C = arg0;
    if (arg1 <= 0) {
        *arg2 = arg0;
        *arg3 = func_00002A3C(sp1C);
        return;
    }
    if (ehsys_9090346C(arg1, &sp1C, arg3) != 0) {
        *arg2 = sp1C;
    }
}

/* func_0000B2A0 — 3 words. MATCH 100% (shape: manual). */
void func_0000B2A0(s32 arg0) {
    extern s32 D_00034398;
    D_00034398 = arg0;
}

/* func_0000B2DC — 5 words. MATCH 100% (shape: manual). */
void func_0000B2DC(void) {
    extern char D_00034488;
    extern int ehsys_memset();
    ehsys_memset(&D_00034488, 0, 0x1C);
}

/* func_0000B2F0 — 5 words. MATCH 100% (shape: manual). */
void func_0000B2F0(void) {
    extern char D_00034488;
    extern int ehsys_memset();
    ehsys_memset(&D_00034488, 0, 0x1C);
}

/* func_0000B304 — 3 words. MATCH 100% (shape: manual). */
void func_0000B304(s32 arg0) {
    extern s32 D_000344A4;
    D_000344A4 = arg0;
}

/* func_0000B310 — 5 words. MATCH 100% (shape: manual). */
void func_0000B310(void) {
    extern void *D_000344A4;
    extern int ehsys_memset();
    ehsys_memset(D_000344A4, 0, 0x20);
}

/* func_0000B324 — 3 words. MATCH 100% (shape: manual). */
void func_0000B324(s32 arg0) {
    extern s32 D_00034488;
    D_00034488 = arg0;
}

/* func_0000B3CC — 3 words. MATCH 100% (shape: manual). */
void func_0000B3CC(s32 arg0) {
    extern s32 D_00034490;
    D_00034490 = arg0;
}

/* func_0000B3D8 — 6 words. MATCH 100% (shape: manual). */
void func_0000B3D8(s32 arg0) {
    extern char D_00034488;
    char *p = (char *)&D_00034488;
    if (arg0) {
        *(s32 *)(p + 0x10) = arg0;
    }
}

/* func_0000B3F0 — 10 words. MATCH 100% (shape: manual). */
extern s32 D_00034498;
extern char D_00034488;
s32 func_0000B3F0(void) {
    char *p = &D_00034488;
    if (D_00034498 == 0) {
        return 0;
    }
    return *(int *)(p + 0x10);
}

/* func_0000B454 — 3 words. MATCH 100% (shape: manual). */
void func_0000B454(s32 arg0) {
    extern s32 D_00034494;
    D_00034494 = arg0;
}

/* func_0000B460 — 10 words. MATCH 100% (shape: manual). */
extern s32 D_00034494;
s32 func_0000B460(void) {
    char *p = &D_00034488;
    if (D_00034494 == 0) {
        return 0;
    }
    return *(int *)(p + 0xC);
}

/* func_0000B488 — 4 words. MATCH 100% (shape: manual). */
void func_0000B488(s32 arg0) {
    extern void *D_000344A4;
    *(s32 *)((char *)D_000344A4 + 0xC) = (s32)arg0;
}

/* func_0000B498 — 4 words. MATCH 100% (shape: manual). */
s32 func_0000B498(void) {
    extern void *D_000344A4;
    return *(s32 *)((char *)D_000344A4 + 0xC);
}

/* func_0000B4A8 — 4 words. MATCH 100% (shape: manual). */
void func_0000B4A8(s32 arg0) {
    extern void *D_000344A4;
    *(s32 *)((char *)D_000344A4 + 0x10) = (s32)arg0;
}

/* func_0000B4B8 — 4 words. MATCH 100% (shape: manual). */
s32 func_0000B4B8(void) {
    extern void *D_000344A4;
    return *(s32 *)((char *)D_000344A4 + 0x10);
}

/* func_0000B4C8 — 5 words. MATCH 100% (shape: manual). */
void func_0000B4C8(void *arg0) {
    extern char D_0003449C;
    extern int ehsys_memcpy();
    ehsys_memcpy(&D_0003449C, arg0, 0x8);
}

/* func_0000B4DC — 3 words. MATCH 100% (shape: manual). */
void *func_0000B4DC(void) {
    extern s32 D_0003449C;
    return &D_0003449C;
}

/* func_0000B4E8 — 4 words. MATCH 100% (shape: manual). */
void func_0000B4E8(s32 arg0) {
    extern void *D_000344A4;
    *(s32 *)((char *)D_000344A4 + 0x14) = (s32)arg0;
}

/* func_0000B4F8 — 4 words. MATCH 100% (shape: manual). */
void func_0000B4F8(s32 arg0) {
    extern void *D_000344A4;
    *(s16 *)((char *)D_000344A4 + 0x18) = (s16)arg0;
}

/* func_0000B508 — 4 words. MATCH 100% (shape: manual). */
s32 func_0000B508(void) {
    extern void *D_000344A4;
    return *(s32 *)((char *)D_000344A4 + 0x14);
}

/* func_0000B518 — 4 words. MATCH 100% (shape: manual). */
s32 func_0000B518(void) {
    extern void *D_000344A4;
    return *(u16 *)((char *)D_000344A4 + 0x18);
}

/* func_0000B528 — 4 words. MATCH 100% (shape: manual). */
void func_0000B528(s32 arg0) {
    extern void *D_000344A4;
    *(s32 *)((char *)D_000344A4 + 0x1C) = (s32)arg0;
}

/* func_0000B538 — 4 words. MATCH 100% (shape: manual). */
s32 func_0000B538(void) {
    extern void *D_000344A4;
    return *(s32 *)((char *)D_000344A4 + 0x1C);
}

/* func_0000B548 — 6 words. MATCH 100% (shape: manual). */
void func_0000B548(s32 arg0, s32 arg1, s32 arg2) {
    extern void *D_000344A4;
    char *p = (char *)D_000344A4;
    *(s32 *)(p + 0x0) = arg0;
    *(s32 *)(p + 0x4) = arg1;
    *(s32 *)(p + 0x8) = arg2;
}

/* func_0000B560 — 3 words. MATCH 100% (shape: manual). */
s32 func_0000B560(void) {
    extern s32 D_000344A4;
    return D_000344A4;
}

/* func_0000B56C — 5 words. MATCH 100% (shape: manual). */
void func_0000B56C(void) {
    extern char D_000344A8;
    extern int ehsys_memset();
    ehsys_memset(&D_000344A8, 0, 0x84);
}

/* func_0000B580 — 5 words. MATCH 100% (shape: manual). */
void func_0000B580(void) {
    extern char D_000344A8;
    extern int ehsys_memset();
    ehsys_memset(&D_000344A8, 0, 0x84);
}

/* func_0000B5F0 — 2 words. MATCH 100% (shape: m2c). */
void func_0000B5F0(void) {
    extern int func_0000B5F0();

}

/* func_0000B5F8 — 5 words. MATCH 100% (shape: manual). */
void func_0000B5F8(void) {
    extern char D_0003452C;
    extern int ehsys_memset();
    ehsys_memset(&D_0003452C, 0, 0x38);
}

/* func_0000B60C — 5 words. MATCH 100% (shape: manual). */
void func_0000B60C(void) {
    extern char D_0003452C;
    extern int ehsys_memset();
    ehsys_memset(&D_0003452C, 0, 0x38);
}

/* func_0000B748 — 13 words. MATCH 100% (shape: manual, lever: virtual-call
 * thunk through a struct's function-pointer field; materialize the base
 * pointer once via a local `char *p`, don't rematerialize per-use). */
extern s32 D_00034560;
extern char D_0003452C;
void func_0000B748(void) {
    char *p = &D_0003452C;
    if (D_00034560 != 0) {
        void (*fn)(void *) = *(void (**)(void *))(p + 0x34);
        fn(p);
    }
}

/* func_0000B77C — 3 words. MATCH 100% (shape: manual). */
void func_0000B77C(s32 arg0) {
    extern s32 D_00034560;
    D_00034560 = 0;
}

/* func_0000B860 — 5 words. MATCH 100% (shape: manual). */
void func_0000B860(void) {
    extern char D_00034564;
    extern int ehsys_memset();
    ehsys_memset(&D_00034564, 0, 0x10);
}

/* func_0000B874 — 5 words. MATCH 100% (shape: manual). */
void func_0000B874(void) {
    extern char D_00034564;
    extern int ehsys_memset();
    ehsys_memset(&D_00034564, 0, 0x10);
}

/* func_0000B888 — 3 words. MATCH 100% (shape: manual). */
void func_0000B888(s32 arg0) {
    extern s32 D_00034574;
    D_00034574 = arg0;
}

/* func_0000B894 — 5 words. MATCH 100% (shape: manual). */
void func_0000B894(void) {
    extern void *D_00034574;
    extern int ehsys_memset();
    ehsys_memset(D_00034574, 0, 0x8);
}

/* func_0000B8A8 — 4 words. MATCH 100% (shape: manual). */
void func_0000B8A8(s32 arg0) {
    extern void *D_00034574;
    *(s32 *)((char *)D_00034574 + 0x4) = (s32)arg0;
}

/* func_0000B8B8 — 4 words. MATCH 100% (shape: manual). */
s32 func_0000B8B8(void) {
    extern void *D_00034574;
    return *(s32 *)((char *)D_00034574 + 0x4);
}

/* func_0000B8C8 — 2 words. MATCH 100% (shape: m2c). */
void func_0000B8C8(void) {
    extern int func_0000B8C8();

}

/* func_0000B8D0 — 2 words. MATCH 100% (shape: m2c). */
void func_0000B8D0(void) {
    extern int func_0000B8D0();

}

/* func_0000B8D8 — 5 words. MATCH 100% (shape: manual). */
void func_0000B8D8(s32 arg0, s32 arg1) {
    extern s32 D_0003457C;
    extern s32 D_00034578;
    D_0003457C = arg0;
    if (arg1) {
    }
    D_00034578 = arg1;
}

/* func_0000B8EC — 5 words. MATCH 100% (shape: manual). */
void func_0000B8EC(void) {
    extern s32 D_0003457C;
    extern int ehsys_memset();
    ehsys_memset(D_0003457C, 0, 0x16C);
}

/* func_0000B900 — 15 words. MATCH 100% (shape: manual). */
void func_0000B900(s32 arg0) {
    extern s32 D_0003457C;
    extern int func_0000B95C();
    s32 *p = (s32 *)D_0003457C;
    func_0000B95C(*p);
    *p = arg0;
}

/* func_0000B95C — 4 words. MATCH 100% (shape: manual). */
void func_0000B95C(s32 arg0) {
    extern void *D_0003457C;
    *(s32 *)((char *)D_0003457C + 0x4) = (s32)arg0;
}

/* func_0000B96C — 6 words. MATCH 100% (shape: manual). */
void func_0000B96C(f32 arg0, f32 arg1, s32 arg2) {
    extern void *D_0003457C;
    char *p = (char *)D_0003457C;
    *(f32 *)(p + 0x8) = arg0;
    *(f32 *)(p + 0xC) = arg1;
    *(s32 *)(p + 0x10) = arg2;
}

/* func_0000B984 — 4 words. MATCH 100% (shape: manual). */
f32 func_0000B984(void) {
    extern void *D_0003457C;
    return *(f32 *)((char *)D_0003457C + 0x8);
}

/* func_0000B994 — 4 words. MATCH 100% (shape: manual). */
f32 func_0000B994(void) {
    extern void *D_0003457C;
    return *(f32 *)((char *)D_0003457C + 0xC);
}

/* func_0000B9A4 — 4 words. MATCH 100% (shape: manual). */
s32 func_0000B9A4(void) {
    extern void *D_0003457C;
    return *(s32 *)((char *)D_0003457C + 0x10);
}

/* func_0000BA5C — 4 words. MATCH 100% (shape: manual). */
void func_0000BA5C(s32 arg0) {
    extern void *D_0003457C;
    *(s32 *)((char *)D_0003457C + 0x30) = (s32)arg0;
}

/* func_0000BA6C — 4 words. MATCH 100% (shape: manual). */
s32 func_0000BA6C(void) {
    extern void *D_0003457C;
    return *(s32 *)((char *)D_0003457C + 0x30);
}

/* func_0000BA7C — 6 words. MATCH 100% (shape: manual). */
s32 func_0000BA7C(s32 arg0) {
    extern void *D_0003457C;
    return *(s32 *)((char *)D_0003457C + 0x34) == arg0;
}

/* func_0000BA94 — 4 words. MATCH 100% (shape: manual). */
s32 func_0000BA94(void) {
    extern void *D_0003457C;
    return *(s32 *)((char *)D_0003457C + 0x38);
}

/* func_0000BAA4 — 6 words. MATCH 100% (shape: manual). */
s32 func_0000BAA4(s32 arg0) {
    extern void *D_0003457C;
    return *(s32 *)((char *)D_0003457C + 0x38) == arg0;
}

/* func_0000BABC — 4 words. MATCH 100% (shape: manual). */
s32 func_0000BABC(void) {
    extern void *D_0003457C;
    return *(s32 *)((char *)D_0003457C + 0x3C);
}

/* func_0000BACC — 6 words. MATCH 100% (shape: manual). */
s32 func_0000BACC(s32 arg0) {
    extern void *D_0003457C;
    return *(s32 *)((char *)D_0003457C + 0x3C) == arg0;
}

/* func_0000BBD8 — 4 words. MATCH 100% (shape: manual). */
s32 func_0000BBD8(void) {
    extern void *D_0003457C;
    return *(s32 *)((char *)D_0003457C + 0x14);
}

/* func_0000BBE8 — 4 words. MATCH 100% (shape: manual). */
s32 func_0000BBE8(void) {
    extern void *D_0003457C;
    return *(s32 *)((char *)D_0003457C + 0x18);
}

/* func_0000BBF8 — 4 words. MATCH 100% (shape: manual). */
s32 func_0000BBF8(void) {
    extern void *D_0003457C;
    return *(s32 *)((char *)D_0003457C + 0x1C);
}

/* func_0000BC08 — 6 words. MATCH 100% (shape: manual). */
s32 func_0000BC08(s32 arg0) {
    extern void *D_0003457C;
    return *(s32 *)((char *)D_0003457C + 0x14) == arg0;
}

/* func_0000BC20 — 7 words. MATCH 100% (shape: manual). */
void func_0000BC20(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    extern s32 D_0003457C;
    char *p = (char *)D_0003457C;
    *(int *)(p + 0x20) = arg0;
    *(int *)(p + 0x24) = arg1;
    *(int *)(p + 0x28) = arg2;
    *(int *)(p + 0x2C) = arg3;
}

/* func_0000BC3C — 11 words. MATCH 100% (shape: manual). */
void func_0000BC3C(s32 *arg0, s32 *arg1, s32 *arg2, s32 *arg3) {
    extern s32 D_0003457C;
    char *p = (char *)D_0003457C;
    *arg0 = *(int *)(p + 0x20);
    *arg1 = *(int *)(p + 0x24);
    *arg2 = *(int *)(p + 0x28);
    *arg3 = *(int *)(p + 0x2C);
}

/* func_0000BC68 — 4 words. MATCH 100% (shape: manual). */
void func_0000BC68(s32 arg0) {
    extern void *D_0003457C;
    *(s16 *)((char *)D_0003457C + 0x160) = (s16)arg0;
}

/* func_0000BC78 — 4 words. MATCH 100% (shape: manual). */
void func_0000BC78(s32 arg0) {
    extern void *D_0003457C;
    *(s16 *)((char *)D_0003457C + 0x162) = (s16)arg0;
}

/* func_0000BC88 — 4 words. MATCH 100% (shape: manual). */
void func_0000BC88(s32 arg0) {
    extern void *D_0003457C;
    *(s32 *)((char *)D_0003457C + 0x164) = (s32)arg0;
}

/* func_0000BC98 — 4 words. MATCH 100% (shape: manual). */
s32 func_0000BC98(void) {
    extern void *D_0003457C;
    return *(u16 *)((char *)D_0003457C + 0x160);
}

/* func_0000BCA8 — 4 words. MATCH 100% (shape: manual). */
s32 func_0000BCA8(void) {
    extern void *D_0003457C;
    return *(u16 *)((char *)D_0003457C + 0x162);
}

/* func_0000BCB8 — 4 words. MATCH 100% (shape: manual). */
s32 func_0000BCB8(void) {
    extern void *D_0003457C;
    return *(s32 *)((char *)D_0003457C + 0x164);
}

/* func_0000BCC8 — 4 words. MATCH 100% (shape: manual). */
void func_0000BCC8(s32 arg0) {
    extern void *D_0003457C;
    *(s32 *)((char *)D_0003457C + 0x168) = (s32)arg0;
}

/* func_0000BCD8 — 4 words. MATCH 100% (shape: manual). */
s32 func_0000BCD8(void) {
    extern void *D_0003457C;
    return *(s32 *)((char *)D_0003457C + 0x168);
}

/* func_0000BCE8 — 12 words. MATCH 100% (shape: m2c). */
void func_0000BCE8(void) {
    extern char D_00034580;
    extern int ehsys_memset();
    extern int func_0000BCE8();
    extern int func_0000BD4C();
    ehsys_memset(&D_00034580, 0, 0xA1C);
    func_0000BD4C();
}

/* func_0000BD18 — 5 words. MATCH 100% (shape: manual). */
void func_0000BD18(void) {
    extern char D_00034580;
    extern int ehsys_memset();
    ehsys_memset(&D_00034580, 0, 0xA1C);
}

/* func_0000BD2C — 3 words. MATCH 100% (shape: manual). */
void func_0000BD2C(s32 arg0) {
    extern s32 D_00034F9C;
    D_00034F9C = arg0;
}

/* func_0000BD38 — 5 words. MATCH 100% (shape: manual). */
void func_0000BD38(void) {
    extern void *D_00034F9C;
    extern int ehsys_memset();
    ehsys_memset(D_00034F9C, 0, 0x68);
}
/* func_0000BD4C — 11 words. MATCH 100% (shape: m2c). */
void func_0000BD4C(void) {
    extern int D_00034580;
    extern int D_00034584;
    extern int D_00034590;
    extern int D_00034594;
    extern int func_0000BD4C();
    D_00034580 = 0;
    D_00034584 = 1;
    D_00034590 = 0x74;
    D_00034594 = 0;
}

/* func_0000BD78 — 26 words. MATCH 100% (shape: manual, lever: a store can
 * land in a jal's delay slot -- it executes BEFORE the callee runs, so
 * "sb 0,0x65(s0)" ahead of "jal func_00011F04" in the disassembly means
 * the store happens first in the C source, not last). */
void func_0000BD78(void) {
    extern s32 D_00034F9C;
    extern int func_00002ED8();
    extern int func_0000B528();
    extern int func_0000B488();
    extern int func_0000B4E8();
    extern int func_0000B4F8();
    extern int func_0000B548();
    extern int func_00011F04();
    void *p = (void *)D_00034F9C;
    func_00002ED8();
    func_0000B528(-1);
    func_0000B488(0);
    func_0000B4E8(0);
    func_0000B4F8(0);
    func_0000B548(0, 0, 0);
    *(unsigned char *)((char *)p + 0x65) = 0;
    func_00011F04(0x1E, 0);
}

/* func_0000C52C — 6 words. MATCH 100% (shape: manual). */
s32 func_0000C52C(s32 arg0) {
    extern s32 D_00034588[];
    return D_00034588[arg0];
}

/* func_0000C544 — 3 words. MATCH 100% (shape: manual). */
void func_0000C544(s32 arg0) {
    extern s32 D_00034590;
    D_00034590 = arg0;
}

/* func_0000C550 — 3 words. MATCH 100% (shape: manual). */
s32 func_0000C550(void) {
    extern s32 D_00034594;
    return D_00034594;
}

/* func_0000D438 — 9 words. MATCH 100% (shape: m2c). */
void func_0000D438(void) {
    extern int func_0000D438();
    extern int func_00014124();
    extern int func_0001422C();
    func_00014124();
    func_0001422C();
}

/* func_0000D518 — 11 words. MATCH 100% (shape: m2c). */
void func_0000D518(void) {
    extern int func_0000D518();
    extern int func_0001432C();
    extern int func_00014360();
    if (func_0001432C() != 0) {
        func_00014360();
    }
}

/* func_0000D544 — 2 words. MATCH 100% (shape: m2c). */
void func_0000D544(void) {
    extern int func_0000D544();

}

/* func_0000DE2C — 2 words. MATCH 100% (shape: m2c). */
void func_0000DE2C(void) {
    extern int func_0000DDA8();
    extern int func_0000DE2C();
    func_0000DDA8();
}

/* func_0000E150 — 2 words. MATCH 100% (shape: m2c). */
void func_0000E150(void) {
    extern int func_0000E150();

}

/* func_0000E20C — 2 words. MATCH 100% (shape: m2c). */
void func_0000E20C(void) {
    extern int func_0000E20C();

}

/* func_0000E214 — 2 words. MATCH 100% (shape: m2c). */
void func_0000E214(void) {
    extern int func_0000E214();

}

/* func_0000E284 — 2 words. MATCH 100% (shape: m2c). */
void func_0000E284(void) {
    extern int func_0000E284();

}

/* func_0000E4E4 — 2 words. MATCH 100% (shape: m2c). */
void func_0000E4E4(void) {
    extern int func_0000E4E4();

}

/* func_0000E6F4 — 2 words. MATCH 100% (shape: m2c). */
void func_0000E6F4(void) {
    extern int func_0000E6F4();

}

/* func_0000E998 — 15 words. MATCH 100% (shape: m2c). */
void func_0000E998(void) {
    extern int func_0000BA94();
    extern int func_0000BAE4();
    extern int func_0000E998();
    s32 temp_v0;

    temp_v0 = func_0000BA94();
    if ((temp_v0 > 0) && (temp_v0 < 0x33)) {
        func_0000BAE4(temp_v0);
    }
}

/* func_0000E9D4 — 15 words. MATCH 100% (shape: m2c). */
void func_0000E9D4(void) {
    extern int func_0000BABC();
    extern int func_0000BAE4();
    extern int func_0000E9D4();
    s32 temp_v0;

    temp_v0 = func_0000BABC();
    if ((temp_v0 > 0) && (temp_v0 < 0x33)) {
        func_0000BAE4(temp_v0);
    }
}

/* func_0000EBA0 — 2 words. MATCH 100% (shape: m2c). */
void func_0000EBA0(void) {
    extern int func_0000EBA0();

}

/* func_0000EC0C — 2 words. MATCH 100% (shape: m2c). */
void func_0000EC0C(void) {
    extern int func_0000EBA8();
    extern int func_0000EC0C();
    func_0000EBA8();
}

/* func_0000EC14 — 2 words. MATCH 100% (shape: m2c). */
void func_0000EC14(void) {
    extern int func_0000EC14();

}

/* func_0000EC1C — 2 words. MATCH 100% (shape: m2c). */
void func_0000EC1C(void) {
    extern int func_0000EC1C();

}

/* func_0000EC24 — 15 words. MATCH 100% (shape: m2c). */
void func_0000EC24(void) {
    extern int ehsys_92675210();
    extern int func_0000BBD8();
    extern int func_0000EC24();
    extern int func_00012368();
    extern int func_000123A4();
    s32 temp_s0;

    func_00012368();
    temp_s0 = func_0000BBD8();
    ehsys_92675210(temp_s0, func_000123A4() & 0xFFFF);
}

/* func_0000EC60 — 2 words. MATCH 100% (shape: m2c). */
void func_0000EC60(void) {
    extern int func_0000EC60();

}

/* func_0000ECFC — 2 words. MATCH 100% (shape: manual). */
s32 func_0000ECFC(void) {
    extern int func_000111D8();
    return func_000111D8(1);
}

/* func_0000ED04 — 2 words. MATCH 100% (shape: manual). */
s32 func_0000ED04(void) {
    extern int func_000111D8();
    return func_000111D8(5);
}

/* func_0000ED98 — 2 words. MATCH 100% (shape: m2c). */
void func_0000ED98(void) {
    extern int func_0000ED98();

}

/* func_0000EF0C — 3 words. MATCH 100% (shape: manual). */
s32 func_0000EF0C(void) {
    extern int func_00005998();
    return func_00005998(5, 0);
}

/* func_0000EF18 — 2 words. MATCH 100% (shape: m2c). */
void func_0000EF18(void) {
    extern int func_0000EF18();

}

/* func_0000EF20 — 4 words. MATCH 100% (shape: manual). */
void func_0000EF20(void) {
    extern s32 D_00034590;
    D_00034590 = 0x76;
}

/* func_0000EF30 — 2 words. MATCH 100% (shape: m2c). */
void func_0000EF30(void) {
    extern int func_0000EF30();

}

/* func_0000EF38 — 2 words. MATCH 100% (shape: m2c). */
void func_0000EF38(void) {
    extern int func_0000EF38();

}

/* func_0000F6BC — 22 words. MATCH 100% (shape: m2c). */
void func_0000F6BC(void) {
    extern int func_00002A3C();
    extern int func_0000A068();
    extern int func_0000AA80();
    extern int func_0000AF78();
    extern int func_0000F6BC();
    extern int func_00013B2C();
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = func_0000AF78();
    func_00013B2C(temp_v0, func_00002A3C(temp_v0), &sp1C);
    func_0000A068(temp_v0, sp1C);
    func_0000AA80(-1, -1, -1);
}

/* func_0000F714 — 31 words. MATCH 100% (shape: m2c). */
void func_0000F714(void) {
    extern int func_00002A3C();
    extern int func_0000A6E8();
    extern int func_0000A840();
    extern int func_0000A930();
    extern int func_0000AA80();
    extern int func_0000AF78();
    extern int func_0000F714();
    extern int func_00011F04();
    extern int func_00013B2C();
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = func_0000AF78();
    func_00013B2C(temp_v0, func_00002A3C(temp_v0), &sp1C);
    func_00011F04(0x1B, 1);
    func_0000A6E8(0, 0);
    func_0000A840(temp_v0, sp1C);
    func_0000A930(0, 0);
    func_0000AA80(-1, -1, -1);
}

/* func_0000FA28 — 2 words. MATCH 100% (shape: m2c). */
void func_0000FA28(void) {
    extern int func_0000FA28();

}

/* func_0000FA30 — 2 words. MATCH 100% (shape: m2c). */
void func_0000FA30(void) {
    extern int func_0000FA30();

}

/* func_0000FA38 — 4 words. MATCH 100% (shape: manual). */
void func_0000FA38(void) {
    extern s32 D_0003458C;
    D_0003458C = 0x1;
}

/* func_0000FBC0 — 2 words. MATCH 100% (shape: m2c). */
void func_0000FBC0(void) {
    extern int func_0000FBC0();

}

/* func_0000FBC8 — 2 words. MATCH 100% (shape: m2c). */
void func_0000FBC8(void) {
    extern int func_0000FBC8();

}

/* func_0000FBD0 — 2 words. MATCH 100% (shape: m2c). */
void func_0000FBD0(void) {
    extern int func_0000FBD0();

}

/* func_0000FCC0 — 2 words. MATCH 100% (shape: m2c). */
void func_0000FCC0(void) {
    extern int func_0000FCC0();

}

/* func_0000FCC8 — 2 words. MATCH 100% (shape: m2c). */
void func_0000FCC8(void) {
    extern int func_0000FCC8();

}

/* func_0000FCD0 — 17 words. MATCH 100% (shape: manual). */
void func_0000FCD0(void) {
    extern s32 D_00034F9C;
    extern int func_00011F04();
    char *p = (char *)D_00034F9C;
    (*(unsigned char *)(p + 0x65))++;
    if ((*(unsigned char *)(p + 0x65)) >= 5) {
        func_00011F04(0x18, 1);
    }
}

/* func_0000FD14 — 3 words. MATCH 100% (shape: manual). */
s32 func_0000FD14(void) {
    extern int func_00011F04();
    return func_00011F04(25, 1);
}

/* func_0000FDCC — 4 words. MATCH 100% (shape: manual). */
void func_0000FDCC(void) {
    extern s32 D_00034590;
    D_00034590 = 0x67;
}

/* func_0000FEA8 — 2 words. MATCH 100% (shape: m2c). */
void func_0000FEA8(void) {
    extern int func_0000FEA8();
    extern int func_000118E0();
    func_000118E0();
}

/* func_0000FEB0 — 2 words. MATCH 100% (shape: m2c). */
void func_0000FEB0(void) {
    extern int func_0000FEB0();
    extern int func_00011998();
    func_00011998();
}

/* func_00010028 — 2 words. MATCH 100% (shape: m2c). */
void func_00010028(void) {
    extern int func_0000FFB8();
    extern int func_00010028();
    func_0000FFB8();
}

/* func_0001005C — 2 words. MATCH 100% (shape: m2c). */
void func_0001005C(void) {
    extern int func_0001005C();

}

/* func_00010090 — 2 words. MATCH 100% (shape: m2c). */
void func_00010090(void) {
    extern int func_00010090();

}

/* func_00010288 — 2 words. MATCH 100% (shape: m2c). */
void func_00010288(void) {
    extern int func_00010288();

}

/* func_00010290 — 2 words. MATCH 100% (shape: m2c). */
void func_00010290(void) {
    extern int func_00010290();

}

/* func_00010298 — 2 words. MATCH 100% (shape: m2c). */
void func_00010298(void) {
    extern int func_00010298();

}

/* func_000102A0 — 2 words. MATCH 100% (shape: manual). */
s32 func_000102A0(void) {
    extern int func_0000B4A8();
    return func_0000B4A8(2);
}

/* func_000105AC — 4 words. MATCH 100% (shape: manual). */
void func_000105AC(void) {
    extern s32 D_00034590;
    D_00034590 = 0x78;
}

/* func_00010D1C — 4 words. MATCH 100% (shape: manual). */
void func_00010D1C(void) {
    extern s32 D_00034590;
    D_00034590 = 0x79;
}

/* func_00011634 — 3 words. MATCH 100% (shape: twin-of-func_000116A4, via
 * find_twins.py same-shape tier). */
s32 func_00011634(void) {
    extern s32 D_00034F98;
    return D_00034F98;
}
/* func_00011640 — 15 words. MATCH 100% (shape: m2c unsigned short-fields). */
void func_00011640(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    extern int func_0000B330();
    extern int func_0000B418();
    extern int func_00011640();
    func_0000B418((s32) (*(unsigned short *)((char *)((arg3 * 0xA) + func_0000B330(arg0, arg1, arg2)) + 0x8)));
}

/* func_0001167C — 5 words. MATCH 100% (shape: manual). */
void func_0001167C(void) {
    extern char D_00034FA0;
    extern int ehsys_memset();
    ehsys_memset(&D_00034FA0, 0, 0x4);
}

/* func_00011690 — 5 words. MATCH 100% (shape: manual). */
void func_00011690(void) {
    extern char D_00034FA0;
    extern int ehsys_memset();
    ehsys_memset(&D_00034FA0, 0, 0x4);
}

/* func_000116A4 — 3 words. MATCH 100% (shape: manual). */
void func_000116A4(s32 arg0) {
    extern s32 D_00034FA4;
    D_00034FA4 = arg0;
}

/* func_000116B0 — 16 words. MATCH 100% (shape: m2c). */
void func_000116B0(void) {
    extern void *D_00034FA4;
    extern int ehsys_memset();
    extern int func_000116B0();
    void *temp_s0;

    temp_s0 = D_00034FA4;
    ehsys_memset(temp_s0, 0, 0xC);
    (*(int *)((char *)temp_s0 + 0x0)) = -1;
    (*(int *)((char *)temp_s0 + 0x4)) = -1;
}

/* func_000116F0 — 9 words. MATCH 100% (shape: m2c). */
void func_000116F0(void) {
    extern int ehsys_C859D5FE();
    extern int func_000116F0();
    ehsys_C859D5FE(0x2B7E);
    ehsys_C859D5FE(0x2B81);
}

/* func_00011714 — 2 words. MATCH 100% (shape: m2c). */
void func_00011714(void) {
    extern int ehsys_2AE3C0AD();
    extern int func_00011714();
    ehsys_2AE3C0AD();
}

/* func_00011774 — 2 words. MATCH 100% (shape: m2c). */
void func_00011774(void) {
    extern int ehsys_088F768A();
    extern int func_00011774();
    ehsys_088F768A();
}

/* func_0001177C — 8 words. MATCH 100% (shape: manual). */
void func_0001177C(s32 arg0, s32 arg1) {
    extern s32 D_00034FA4;
    char *p = (char *)D_00034FA4;
    if (arg0 != 1) {
        *(int *)(p + 0x0) = arg1;
    } else {
        *(int *)(p + 0x4) = arg1;
    }
}

/* func_0001179C — 12 words. MATCH 100% (shape: manual). */
void func_0001179C(s32 arg0) {
    extern s32 D_00034FA4;
    extern int func_000117CC();
    if ((*(int *)((char *)D_00034FA4 + 0x4)) != arg0) {
        func_000117CC(arg0);
    }
}

/* func_00011998 — 2 words. MATCH 100% (shape: twin-of-func_000119A0). */
s32 func_00011998(void) {
    extern int ehsys_DF5CB459();
    return ehsys_DF5CB459(0x5DC);
}

/* func_000119A0 — 2 words. MATCH 100% (shape: manual). */
s32 func_000119A0(void) {
    extern int func_000117CC();
    return func_000117CC(8);
}

/* func_00011BA4 — 24 words. MATCH 100% (shape: m2c). */
void func_00011BA4(void) {
    extern void *D_00034FA4;
    extern int func_00003AF4();
    extern int func_0000B93C();
    extern int func_000117CC();
    extern int func_00011BA4();
    extern int func_00011C04();
    s32 temp_s1;
    void *temp_s0;

    temp_s0 = D_00034FA4;
    temp_s1 = func_00003AF4(func_0000B93C());
    func_0000B93C();
    if ((*(int *)((char *)temp_s0 + 0x4)) != temp_s1) {
        func_000117CC(temp_s1);
    }
    func_00011C04(0x80);
}

/* func_00011C04 — 6 words. MATCH 100% (shape: manual). */
s32 func_00011C04(s32 arg0) {
    extern void *D_00034FA4;
    extern int ehsys_F6905EFA();
    *(s32 *)((char *)D_00034FA4 + 0x8) = arg0;
    return ehsys_F6905EFA(arg0 - 1, 0x5DC);
}

/* func_00011C1C — 2 words. MATCH 100% (shape: m2c). */
void func_00011C1C(void) {
    extern int ehsys_A84EDF3B();
    extern int func_00011C1C();
    ehsys_A84EDF3B();
}

/* func_00011C24 — 5 words. MATCH 100% (shape: manual). */
void func_00011C24(void) {
    extern char D_00034FA8;
    extern int ehsys_memset();
    ehsys_memset(&D_00034FA8, 0, 0x24);
}

/* func_00011C38 — 5 words. MATCH 100% (shape: manual). */
void func_00011C38(void) {
    extern char D_00034FA8;
    extern int ehsys_memset();
    ehsys_memset(&D_00034FA8, 0, 0x24);
}

/* func_00011C4C — 7 words. MATCH 100% (shape: manual). */
void func_00011C4C(s32 arg0, s32 arg1, s32 arg2) {
    extern s32 D_00034FD0;
    extern s32 D_00034FCC;
    extern s32 D_00034FD4;
    D_00034FD0 = arg0;
    D_00034FCC = arg1;
    D_00034FD4 = arg2;
}

/* func_00011C68 — 18 words. MATCH 100% (shape: manual). */
void func_00011C68(void) {
    extern s32 D_00034FD0;
    extern s32 D_00034FCC;
    extern int ehsys_memset();
    void *p = (void *)D_00034FD0;
    ehsys_memset((void *)D_00034FCC, 0, 0xB8);
    ehsys_memset(p, 0, 0x24);
}

/* func_00011D00 — 4 words. MATCH 100% (shape: manual). */
s32 func_00011D00(void) {
    extern void *D_00034FD0;
    return *(s32 *)((char *)D_00034FD0 + 0x10);
}

/* func_00011D10 — 4 words. MATCH 100% (shape: manual). */
s32 func_00011D10(void) {
    extern void *D_00034FD0;
    return *(s32 *)((char *)D_00034FD0 + 0x4);
}

/* func_00011D20 — 4 words. MATCH 100% (shape: manual). */
s32 func_00011D20(void) {
    extern void *D_00034FD0;
    return *(s32 *)((char *)D_00034FD0 + 0x8);
}

/* func_00011D30 — 4 words. MATCH 100% (shape: manual). */
s32 func_00011D30(void) {
    extern void *D_00034FD0;
    return *(s32 *)((char *)D_00034FD0 + 0xC);
}

/* func_00011D40 — 6 words. MATCH 100% (shape: manual). */
s32 func_00011D40(void) {
    extern void *D_00034FD0;
    extern int func_00013BE4();
    s32 *p = (s32 *)D_00034FD0;
    *p = *p + 1;
    return func_00013BE4();
}

/* func_00011D58 — 6 words. MATCH 100% (shape: manual). */
s32 func_00011D58(s32 arg0) {
    extern void *D_00034FD0;
    extern int func_00013BE4();
    s32 *p = (s32 *)D_00034FD0;
    *p = *p + arg0;
    return func_00013BE4();
}

/* func_000120D8 — 11 words. MATCH 100% (shape: manual). */
s32 func_000120D8(void) {
    extern s32 D_00034FD0;
    extern int func_00013BE4();
    int *p = (int *)D_00034FD0;
    int v = *p;
    int rem = (v - 1) % 0x13;
    *p = v + (0x13 - rem);
    return func_00013BE4(v);
}

/* func_0001222C — 3 words. MATCH 100% (shape: twin-of-func_000116A4). */
void func_0001222C(s32 arg0) {
    extern s32 D_00034FC0;
    D_00034FC0 = arg0;
}

/* func_00012238 — 3 words. MATCH 100% (shape: twin-of-func_000116A4). */
void func_00012238(s32 arg0) {
    extern s32 D_00034FC4;
    D_00034FC4 = arg0;
}

/* func_00012244 — 5 words. MATCH 100% (shape: manual). */
void func_00012244(s32 arg0, s32 arg1) {
    extern s32 D_00034FA8;
    extern s32 D_00034FAC;
    D_00034FA8 = arg0;
    D_00034FAC = arg1;
}

/* func_00012280 — 9 words. MATCH 100% (shape: manual). */
void func_00012280(void *arg0) {
    extern s32 D_00034FD0;
    char *p = (char *)D_00034FD0;
    *(int *)((char *)arg0 + 0x0) = (int)(p + 0xC);
    *(int *)((char *)arg0 + 0x4) = (int)(p + 0x1C);
    *(int *)((char *)arg0 + 0x8) = *(int *)(p + 0x14);
}

/* func_00012358 — 4 words. MATCH 100% (shape: manual). */
s32 func_00012358(void) {
    extern void *D_00034FD0;
    return *(s32 *)((char *)D_00034FD0 + 0x1C);
}

/* func_000123A4 — 4 words. MATCH 100% (shape: manual). */
s32 func_000123A4(void) {
    extern void *D_00034FCC;
    return *(u8 *)((char *)D_00034FCC);
}

/* func_000123B4 — 4 words. MATCH 100% (shape: manual). */
void func_000123B4(s32 arg0) {
    extern void *D_00034FCC;
    *(s8 *)((char *)D_00034FCC) = (s8)arg0;
}

/* func_000123F8 — 4 words. MATCH 100% (shape: manual). */
void func_000123F8(s32 arg0) {
    extern void *D_00034FCC;
    *(s8 *)((char *)D_00034FCC + 0x1) = (s8)arg0;
}

/* func_00012408 — 4 words. MATCH 100% (shape: manual). */
s32 func_00012408(void) {
    extern void *D_00034FCC;
    return *(u8 *)((char *)D_00034FCC + 0x1);
}

/* func_00012418 — 9 words. MATCH 100% (shape: manual). */
s32 func_00012418(void) {
    extern void *D_00034FCC;
    extern int D_0002A530;
    return *(int *)((char *)&D_0002A530 + (*(u8 *)D_00034FCC) * 4);
}

/* func_000124C8 — 2 words. MATCH 100% (shape: m2c). */
void func_000124C8(void) {
    extern int func_000124C8();

}

/* func_00013970 — 4 words. MATCH 100% (shape: manual). */
s32 func_00013970(void) {
    extern void *D_00034FCC;
    return *(s32 *)((char *)D_00034FCC + 0xB4);
}

/* func_00013B94 — 20 words. MATCH 100% (shape: m2c). */
void func_00013B94(s32 arg0, int arg1) {
    extern int ehsys_008B4553();
    extern int ehsys_0A60B08B();
    extern int ehsys_D9E726DC();
    extern int func_00013B94();
    if (ehsys_0A60B08B() != 0) {
        ehsys_008B4553(arg0, arg1);
        ehsys_D9E726DC(arg0, arg1);
    }
}

/* func_00013CD4 — 3 words. MATCH 100% (shape: manual). */
void func_00013CD4(s32 arg0) {
    extern s32 D_00034FC8;
    D_00034FC8 = arg0;
}

/* func_00013CE0 — 3 words. MATCH 100% (shape: manual). */
s32 func_00013CE0(void) {
    extern s32 D_00034FC8;
    return D_00034FC8;
}

/* func_00013CEC — 5 words. MATCH 100% (shape: manual). */
void func_00013CEC(void) {
    extern char D_00034FD8;
    extern int ehsys_memset();
    ehsys_memset(&D_00034FD8, 0, 0x22C);
}

/* func_00013D00 — 5 words. MATCH 100% (shape: manual). */
void func_00013D00(void) {
    extern char D_00034FD8;
    extern int ehsys_memset();
    ehsys_memset(&D_00034FD8, 0, 0x22C);
}

/* func_0001411C — 2 words. MATCH 100% (shape: m2c). */
void func_0001411C(void) {
    extern int func_0001411C();
    extern int func_00014124();
    func_00014124();
}

/* func_0001439C — 19 words. MATCH 100% (shape: m2c). */
void func_0001439C(void) {
    extern int func_000002F8();
    extern int func_00011634();
    extern int func_0001422C();
    extern int func_0001432C();
    extern int func_00014360();
    extern int func_0001439C();
    if (func_0001432C() != 0) {
        func_00014360();
    }
    if (func_00011634() == 0) {
        func_0001422C();
        func_000002F8();
    }
}

/* func_00015760 — 6 words. MATCH 100% (shape: manual). */
s32 func_00015760(s32 arg0) {
    extern s32 D_0002A55C[];
    extern int field_F560DE58();
    return field_F560DE58(D_0002A55C[arg0]);
}

/* func_00015778 — 3 words. MATCH 100% (shape: twin-of-func_000116A4). */
void func_00015778(s32 arg0) {
    extern s32 D_000351FC;
    D_000351FC = arg0;
}

/* func_00015784 — 3 words. MATCH 100% (shape: manual). */
void func_00015784(s32 arg0) {
    extern s32 D_00035200;
    D_00035200 = arg0;
}

/* func_00015804 — 2 words. MATCH 100% (shape: m2c). */
void func_00015804(void) {
    extern int func_00012358();
    extern int func_00015804();
    func_00012358();
}

/* func_0001580C — 2 words. MATCH 100% (shape: m2c). */
void func_0001580C(void) {
    extern int func_00011D20();
    extern int func_0001580C();
    func_00011D20();
}
/* func_00015814 — 16 words. MATCH 100% (shape: m2c). */
void func_00015814(void) {
    extern int D_00035204;
    extern int D_00035230;
    extern int ehsys_1856E536();
    extern int ehsys_memset();
    extern int func_00015814();
    ehsys_memset(&D_00035204, 0, 0x24);
    D_00035204 = ehsys_1856E536((s32) &D_00035230, 0x500000);
}
/* func_00015854 — 0 words. MATCH 100% (shape: same-shape twin). */
void func_00015854(void) {

    extern int ehsys_1078C73B();
    extern s32 D_00035204;
    s32 *s0 = &D_00035204;
    if (*s0 != 0) {
        ehsys_1078C73B(*s0);
        *s0 = 0;
    }
}

/* func_00015890 — 3 words. MATCH 100% (shape: manual). */
s32 func_00015890(void) {
    extern s32 D_00035204;
    return D_00035204;
}

/* func_00015ABC — 4 words. MATCH 100% (shape: manual). */
s32 func_00015ABC(s32 arg0) {
    extern s32 D_00035204;
    extern int ehsys_41AABF28();
    return ehsys_41AABF28(D_00035204, arg0);
}

/* func_00015ACC — 4 words. MATCH 100% (shape: manual). */
s32 func_00015ACC(s32 arg0) {
    extern s32 D_00035204;
    extern int ehsys_20E340D9();
    return ehsys_20E340D9(D_00035204, arg0);
}

/* func_00015ADC — 2 words. MATCH 100% (shape: manual). */
s32 func_00015ADC(void *arg0) {
    return *(s32 *)((char *)arg0 + 0xC);
}

/* func_00015AE4 — 0 words. MATCH 100% (shape: twin of func_00030D30). */
void *func_00015AE4(s32 a0, s32 a1, s32 a2) {

    s32 off1 = *(s32 *)((a1 << 3) + a0 + 0x14);
    s32 p = off1 + a0;
    s32 off2 = *(s32 *)(p + a2 * 8 + 4);
    return (void *)(off2 + a0);
}
