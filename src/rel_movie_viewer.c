/*
 * rel_movie_viewer.prx — reconstructed code (matching decompilation)
 *
 * Compiler:     Metrowerks CodeWarrior for PSP — MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,p -sdatathreshold 0
 * Verification: local build with wibo + mwccpsp_3.0.1_219 (see docs/03-tools.md
 *               "local matching" section) — compare with
 *               `mips-linux-gnu-objdump -dr` against asm/rel_movie_viewer/text.s,
 *               treating any word with a matching relocation (HI16/LO16/26,
 *               same symbol) on both sides as equal regardless of its baked
 *               immediate. Only functions marked "MATCH 100%" below have been
 *               confirmed this way; 9/16 functions in this file currently are.
 *
 * Conventions (see docs/09-first-match.md):
 *  - global game-state variables are `volatile` and are accessed via a local
 *    pointer to reproduce the original codegen (value reload, use of $s0);
 *  - names `func_XXXXXXXX` / `D_XXXXXXXX` = placeholders (address), to be renamed
 *    as their purpose becomes clear.
 *  - whether a state-blob field is a fresh named extern (`D_0009DB04`, ...) or
 *    `offset(basePointer)` off a `volatile T *p = &D_0009DB00;` depends on
 *    whether the ORIGINAL reuses one register across multiple fields of the
 *    blob (offset form) or recomputes a fresh %hi/%lo per field (separate
 *    extern form) — this must be checked per function against the target asm,
 *    it is not a blanket rule (func_00000138 does NOT share a register between
 *    D_0009DB00 and D_0009DB04; func_00000034/func_000001C8/func_00000470/
 *    func_00000540 DO share one across several fields).
 *
 * Functions below `func_00000184` without a "MATCH 100%" tag are DRAFTS: they
 * compile and their instruction COUNT/logic is right, but a handful of
 * instructions differ from the target — usually MWCC's choice of branch
 * polarity (`beq`-to-handler vs `bne`-skip) or whether it folds a
 * `(x < 0) ? 0 : x` clamp into the Allegrex `max` pseudo-op, which plain
 * portable C does not appear to control reliably. Treat as very-close
 * NONMATCHING, not as verified.
 *
 * Layout notes discovered while drafting (see asm/rel_movie_viewer/text.s):
 *  - D_0009DB00 is the start of a much larger state blob. func_00000138
 *    zero-fills it with size 0x653C via func_00001D7C(&D_0009DB00, 0, 0x653C),
 *    which is exactly (last known field 0x6538) + 4 — i.e. 0x653C is very
 *    likely the blob's real size.
 *  - D_000A3F0C (referenced directly elsewhere via its own %hi/%lo symbol)
 *    is exactly D_0009DB00 + 0x640C: the two names denote adjacent globals
 *    in the SAME data blob, not unrelated objects.
 *  - Fields at D_0009DB00+0x6408 and +0x6530 are read both via a register
 *    holding &D_0009DB00 (spimdisasm resolves these to D_0009DB00 in the
 *    asm) and via raw absolute immediates (0xA3F08 / 0xA4030, left
 *    unresolved by spimdisasm because no relocation entry pointed at the
 *    middle of the blob) — same memory, two addressing idioms.
 *  - D_0009DB00+0x0008 up to +0x6408 looks like an array of 0x100-byte
 *    records (100 of them: 100*0x100+8 = 0x6408), indexed via
 *    `(index << 8) + 8`; +0x6408 itself is used as a slot counter/index
 *    compared against 0x64 (100).
 */

extern volatile int D_0009DB00;
extern void func_00000CEC(int);

/* func_00000184 — "release-and-clear" cleanup of a global handle.
 * MATCH 100% (mwccpsp_3.0.1_219, -O4,p -sdatathreshold 0). */
void func_00000184(void) {
    volatile int *p = &D_0009DB00;
    if (*p != 0) {
        func_00000CEC(*p);
        *p = 0;
    }
}

/* ============================================================
 * Remaining functions of the module. Each is individually tagged
 * "MATCH 100%" if verified, otherwise treat as a close NONMATCHING draft
 * (see the file header for how these were checked and what's usually left).
 * ============================================================ */

/* externs used by the drafts (types are best-effort guesses from usage,
 * to be corrected once matched or once the modules they live in are
 * decompiled) */
extern void func_000008B4(void (*)(void), void (*)(void), void *);
extern void func_000008CC(int, void (*)(void), void (*)(void));
extern int func_00000924(int);
extern int func_00000CE4(void *, int);
extern void *func_00000D74(void);
extern int func_00000DA4(int, int);
extern void func_00000DAC(int);
extern int func_00000EB4(int);
extern int func_00000EFC(int, int, int);
extern void func_00001694(void *, int, int);
extern void func_0000169C(void *, void *);
extern int func_000016A4(void *);
extern void func_000016C4(void *);
extern void func_0000175C(int);
extern void func_0000180C(void);
extern void func_00001A2C(int, int);
extern void func_00001A5C(void *, int);
extern void func_00001B8C(int, int);
extern void func_00001D7C(void *, int, int);
extern void func_00001DBC(void *, void *);
extern void func_00001DCC(void *, void *);
extern int func_00001DE4(void *);
extern int func_00002224(void);
extern void func_0000222C(int);
extern int func_00002234(int, void *);
extern void func_00002DEC(int, int);
extern int func_00002DF4(void);
extern void func_00002DFC(void *, int);
extern void func_00002E0C(void);
extern void func_00002E94(int, int, void *);
extern void func_00002EB4(int, int);
extern void func_00002EC4(int);
extern void func_00002EE4(int, int, int, void *);
extern void func_00002F94(int);
extern void func_00002F9C(void);
extern void func_00002FD4(void);

extern char D_00005A74;
extern char D_00005A7C;
extern char D_00005A88;
extern char D_00005AA4;
extern char D_00005AC0;
extern char D_00005AD0;
extern char D_00085B00;
extern char D_000A3F0C;

/* other fields of the D_0009DB00 state blob (see file header) — declared as
 * their OWN extern symbols, not as `D_0009DB00 + offset` pointer arithmetic:
 * the target reloads a fresh %hi/%lo pair per distinct global instead of
 * reusing one base register across unrelated fields (confirmed by matching
 * func_00000138, which recomputes `lui $v1,0xA0000>>16` twice back-to-back
 * for D_0009DB00 and D_0009DB04 instead of reusing the register). */
extern volatile int D_0009DB04;           /* +0x4: current mode (1..4) */
extern volatile int D_000A3F08;           /* +0x6408: slot cursor/count (<0x64) */
extern volatile int D_000A4030;           /* +0x6530: last-picked slot index */
extern volatile int D_000A4034;           /* +0x6534: fade-pending flag */
extern volatile int D_000A4038;           /* +0x6538: load counter */
extern volatile unsigned char D_000A3FF9; /* +0x64F9: substate byte */

/* forward declarations: call graph is not in address order */
void func_00000034(void);
void func_00000138(void);
void func_000001C0(void);
void func_000001C8(int mode);
void func_000006B4(void);
void func_0000024C(void);
void func_00000294(void);
void func_00000464(void);
void func_00000470(void);
void func_00000540(void);
void func_000005C8(void);
void func_000006BC(void *arg0);
void func_000007C8(int arg1, int arg2, int arg3);
void func_00000894(int arg0, int arg1, void *arg2);

/* func_00000000 — module entry point: registers the viewer's main loop
 * (func_00000034) and teardown (func_000001C0) callbacks.
 * MATCH 100% (mwccpsp_3.0.1_219, -O4,p -sdatathreshold 0). */
int func_00000000(void) {
    func_000008B4(func_00000034, func_000001C0, (void *) &D_00005AC0);
    return 0;
}

/* func_00000034 — viewer main loop: dispatches on the current mode
 * (D_0009DB00+0x4) each frame until told to exit (mode 4). DRAFT. */
void func_00000034(void) {
    volatile int *state = &D_0009DB00;
    int done = 0;
    int mode;

    func_00000138();
    func_0000175C(0);
    func_000008CC(0, func_000005C8, func_000006B4);

    while (!done) {
        func_00002FD4();
        mode = state[1]; /* +0x4 */
        if (mode == 4) {
            done = 1;
            continue;
        }
        if (mode == 3) {
            func_00000540();
            continue;
        }
        if (mode == 2) {
            func_00000470();
            continue;
        }
        if (mode == 1) {
            func_0000024C();
            func_000001C8(2);
        }
    }

    func_00000184();
    func_0000180C();
    func_00002FD4();
    func_00001A2C(9, 0);
}

/* func_00000138 — viewer init: zero the whole state blob, open the movie
 * resource, and set the initial mode.
 * MATCH 100% (mwccpsp_3.0.1_219, -O4,p -sdatathreshold 0). */
void func_00000138(void) {
    func_00001D7C((void *) &D_0009DB00, 0, 0x653C);
    D_0009DB00 = func_00000CE4((void *) &D_00005AD0, 0x80000);
    D_0009DB04 = 1;
}

/* func_000001C0 — empty callback (teardown hook registered by
 * func_00000000; nothing to release here).
 * MATCH 100% (mwccpsp_3.0.1_219, -O4,p -sdatathreshold 0). */
void func_000001C0(void) {
}

/* func_000001C8 — state-transition: runs exit logic for the current mode,
 * then sets the new mode and runs its entry logic. DRAFT. */
void func_000001C8(int mode) {
    volatile int *s1 = &D_0009DB00;
    int old_mode = s1[1]; /* +0x4 */

    if (old_mode == 2) {
        func_00000464();
    }

    s1[1] = mode; /* +0x4 */

    switch (mode) {
    case 2:
        func_00000294();
        return;
    case 3:
        *(volatile int *) ((volatile char *) s1 + 0x6534) = 0;
        return;
    }
}

/* func_0000024C — one-shot: format a string into a stack buffer and hand
 * it to func_000006BC (a size-measurement/wrap routine, going by its own
 * body); buffer size confirmed by the match (0x110 frame - 0x10 = 0x100).
 * MATCH 100% (mwccpsp_3.0.1_219, -O4,p -sdatathreshold 0). */
void func_0000024C(void) {
    char buf[0x100];

    func_00001DBC(buf, (void *) (long) func_00000924(3));
    func_00001DCC(buf, &D_00005A74);
    D_000A3F08 = 0;
    func_000006BC(buf);
}

/* func_00000294 — init the "viewer config" blob at D_000A3F0C (font/frame
 * geometry, flags, the func_000007C8 render callback). DRAFT: field names
 * are placeholder byte offsets (`cfg[OFF]`), not yet a real struct. */
void func_00000294(void) {
    char *cfg = &D_000A3F0C;
    char *rec = cfg + 0x4C; /* record cleared/initialized below */
    int flag = 0 & 1;       /* always 0 here; mirrors the asm's `andi $a2,$zero,1` */
    unsigned char b;
    int val_408, val_530, t0, t1;

    func_00001D7C(cfg, 0, 0x124);

    *(int *) (cfg + 0x4C) = 1;
    *(int *) (rec + 0x14) = 1;
    *(int *) (rec + 0x3C) = 1;
    *(int *) (rec + 0x2C) = 1;
    *(int *) (rec + 0x30) = 1;
    *(int *) (rec + 0x24) = -1;
    *(int *) (rec + 0x54) = -1;
    *(int *) (rec + 0x60) = -1;
    *(short *) (rec + 0x48) = 0xC;
    *(short *) (rec + 0x4C) = 0xC;
    *(short *) (rec + 0x4A) = 0xC;
    *(short *) (rec + 0x4E) = 0xC;
    *(signed char *) (rec + 0x50) = 0xC;
    *(signed char *) (rec + 0x5C) = 0xC;
    *(signed char *) (rec + 0x9) = 2;
    *(int *) (rec + 0x64) = 2;
    *(int *) (rec + 0x68) = 2;

    *(int *) (cfg + 0xC8) = D_0009DB00;
    b = *(unsigned char *) (cfg + 0xCC);
    *(unsigned char *) (cfg + 0xCC) = (b & ~1) | flag;
    b = *(unsigned char *) (cfg + 0xCC);
    *(unsigned char *) (cfg + 0xCC) = (b & ~2) | 2;
    b = *(unsigned char *) (cfg + 0xCC);
    *(unsigned char *) (cfg + 0xCC) = (b & ~4) | (flag << 2);
    b = *(unsigned char *) (cfg + 0xCC);
    *(unsigned char *) (cfg + 0xCC) = (b & ~8) | (flag << 3);
    b = *(unsigned char *) (cfg + 0xCC);
    *(unsigned char *) (cfg + 0xCC) = (b & ~0x10) | (flag << 4);
    b = *(unsigned char *) (cfg + 0xCC);
    *(unsigned char *) (cfg + 0xCC) = (b & ~0x20) | (flag << 5);
    b = *(unsigned char *) (cfg + 0xCD);
    *(unsigned char *) (cfg + 0xCD) = (b & ~0x78) | 0x10;

    *(short *) (cfg + 0xD0) = 0xA;
    *(signed char *) (cfg + 0xD2) = 0xA;
    *(short *) (cfg + 0xF4) = 0xF0;
    *(short *) (cfg + 0xF6) = 0x10;
    *(void (**)(int, int, int)) (cfg + 0x100) = func_000007C8;

    *(signed char *) (rec + 0x8) = 0;
    *(short *) (rec + 0xC) = 0;
    *(short *) (rec + 0xE) = 0;
    *(int *) (rec + 0x38) = 0;
    *(int *) (rec + 0x58) = 0;

    func_00001694(cfg, b, flag);

    /* geometry clamp: pull the two counters at D_0009DB00+0x6408/+0x6530
     * (aka D_000A3F08 / D_000A4030 via the "middle of the blob" raw
     * addressing spimdisasm couldn't name, see file header) and derive
     * the config's D0/D4/D6 fields from them. */
    val_408 = D_000A3F08;
    val_530 = D_000A4030;
    t0 = val_408 - 0xA;
    *(short *) (cfg + 0xD0) = (short) val_408;
    t0 = (val_530 < t0) ? val_530 : t0;
    t1 = (val_530 - val_408) + 0xA;
    *(short *) (cfg + 0xD4) = (short) t0;
    t1 = (t1 < 0) ? 0 : t1;
    b = *(unsigned char *) (cfg + 0xD6);
    *(unsigned char *) (cfg + 0xD6) = (b & ~0x1F) | (t1 & 0x1F);
}

/* func_00000464 — tail-calls into func_000016C4 with the config blob.
 * MATCH 100% (mwccpsp_3.0.1_219, -O4,p -sdatathreshold 0). */
void func_00000464(void) {
    func_000016C4(&D_000A3F0C);
}

/* func_00000470 — per-frame update for mode 2: tracks a load counter and,
 * once a completion flag is set, transitions to mode 3 or 4. DRAFT. */
void func_00000470(void) {
    volatile int *s1 = &D_0009DB00;
    void *obj = func_00000D74();
    int result = func_000016A4(&D_000A3F0C);
    int flags = *(int *) ((char *) obj + 0xC);
    int changed = 0;
    int counter;
    volatile int *counter_p = (volatile int *) ((volatile char *) s1 + 0x6538);

    if (flags & 0x100) {
        changed = 1;
        counter = *counter_p - 1;
        counter = (counter < 0) ? 0 : counter;
        *counter_p = counter;
    } else if (flags & 0x200) {
        changed = 1;
        counter = *counter_p + 1;
        *counter_p = counter;
    }

    if (changed) {
        func_00001B8C(*counter_p, changed);
    }

    if (*(volatile unsigned char *) ((volatile char *) s1 + 0x64F9) == 6) {
        if (result != -2) {
            *(volatile int *) ((volatile char *) s1 + 0x6530) = result;
            func_000001C8(3);
            return;
        }
        func_000001C8(4);
    }
}

/* func_00000540 — per-frame update for mode 3: waits for the fade to
 * finish, sets up the fade-to-black overlay, then hands off to mode 2.
 * MATCH 100% (mwccpsp_3.0.1_219, -O4,p -sdatathreshold 0). */
void func_00000540(void) {
    volatile int *s0 = &D_0009DB00;
    func_00002DEC(0, 1);
    goto test;
loop:
    func_00002FD4();
test:
    if (!func_00002DF4()) {
        goto loop;
    }
    func_00002DFC(&D_00085B00, 0x18000);
    *(volatile int *) ((volatile char *) s0 + 0x6534) = 1;
    func_00002FD4();
    func_00002E0C();
    func_000001C8(2);
}

/* func_000005C8 — per-frame update for mode... dispatches on the current
 * mode value again (0009DB04) to run small per-mode housekeeping. DRAFT. */
void func_000005C8(void) {
    int mode = D_0009DB04;
    int handle;

    switch (mode) {
    case 2:
        handle = func_00000DA4(1, 0);
        func_0000169C(&handle, &D_000A3F0C);
        func_00000DAC(handle);
        return;
    case 1:
        func_00002EB4(0x10, 0x10);
        func_00002E94(0, 0, &D_00005A88);
        return;
    case 3:
        if (D_000A4034 != 0) {
            int slot = D_000A4030;
            func_00001A5C((void *) ((volatile char *) &D_0009DB00 + (slot << 8) + 8), 0xF3F9);
            D_000A4034 = 0;
        }
        return;
    default:
        func_00002EB4(0x10, 0x10);
        func_00002E94(0, 0, &D_00005A7C);
        return;
    }
}

/* func_000006B4 — empty callback (registered alongside func_000005C8 in
 * func_00000034).
 * MATCH 100% (mwccpsp_3.0.1_219, -O4,p -sdatathreshold 0). */
void func_000006B4(void) {
}

/* func_000006BC — walks a linked list of directory/file entries (via
 * func_00002224/func_00002234/func_0000222C), recursing into
 * subdirectories and appending matched entries into the 0x100-byte-record
 * table at D_0009DB00+0x8. DRAFT. */
void func_000006BC(void *arg0) {
    char entry[0x100];
    int flags;
    int handle = func_00002224();

    while (func_00002234(handle, &flags) > 0) {
        if (D_000A3F08 >= 0x64) {
            break;
        }
        if (!(flags & 0x1000)) {
            if (flags & 0x2000) {
                int index = D_000A3F08;
                char *slot = (char *) &D_0009DB00 + (index << 8) + 8;
                func_00001DBC(slot, arg0);
                func_00001DCC(slot, entry);
                D_000A3F08 = index + 1;
            }
        } else if (*(signed char *) entry != 0x2E) {
            int len = func_00001DE4(arg0);
            func_00001DCC(arg0, entry);
            func_00001DCC(arg0, &D_00005AA4);
            func_000006BC(arg0);
            ((char *) arg0)[len] = 0;
        }
    }

    func_0000222C(handle);
}

/* func_000007C8 — render callback set into the viewer config
 * (D_000A3F0C+0x100): builds a wide-char label from a table entry's name
 * and draws it. DRAFT. */
void func_000007C8(int arg1, int arg2, int arg3) {
    short label[0x104];
    signed char *src = (signed char *) &D_0009DB00 + ((arg1 & 0xFFFF) << 8) + 8;
    short *dst = label;

    while (*src != 0) {
        *dst = (short) *src;
        dst++;
        src++;
    }
    *dst = 0;

    func_00002F94(func_00000EFC(func_00000EB4(-1), 0, 1));
    func_00002EB4(0xC, 0xC);
    func_00002EC4(0xFF000000);
    func_00000894(arg2 + 2, arg3 + 2,
                   (void *) (label + (func_00001DE4(
                                           (void *) (long) func_00000924(3))
                                       * 2)
                             + 0x10));
    func_00002F9C();
}

/* func_00000894 — tail-calls the real draw routine with geometry derived
 * from arg0 (a "used width" the caller subtracts from a fixed 0x1E0
 * total).
 * MATCH 100% (mwccpsp_3.0.1_219, -O4,p -sdatathreshold 0). */
void func_00000894(int arg0, int arg1, void *arg2) {
    func_00002EE4(arg0 << 6, arg1 << 6, (0x1E0 - arg0) << 6, arg2);
}
