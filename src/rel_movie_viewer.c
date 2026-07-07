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
 *    func_00000540/func_000005C8/func_000006BC DO share one across several
 *    fields).
 *
 * Functions below `func_00000184` without a "MATCH 100%" tag are DRAFTS: they
 * compile and their instruction COUNT/logic is right (each has been narrowed
 * to the closest word-count achievable and its remaining gap root-caused —
 * see its own comment), but a handful of instructions differ from the
 * target, almost always one of these confirmed-uncontrollable-from-portable-C
 * MWCC codegen choices:
 *   - branch polarity in an if/else-if chain (`beq`-to-handler vs
 *     `bne`-skip), and whether a loop test gets rotated to the bottom
 *     without duplication or WITH a duplicated pre-test — both are
 *     sometimes forceable with an explicit `goto`-based rewrite that
 *     mirrors the target's exact block layout (worked for func_00000540,
 *     func_000007C8's copy loop, and the branch shapes in func_000001C8/
 *     func_000005C8/func_000006BC), sometimes not (func_00000034's loop
 *     test);
 *   - whether it folds a `(x < 0) ? 0 : x` clamp into the Allegrex `max`
 *     pseudo-op (confirmed unreliable even in an isolated standalone test
 *     with statement order matching the target exactly — func_00000470,
 *     func_00000294);
 *   - whether it caches a global's address in a saved register for reuse
 *     across many straight-line statements (target sometimes does; this
 *     compiler was confirmed by isolated experiment to always
 *     re-materialize a fresh `lui/addiu` per access instead, regardless of
 *     pointer/struct form — func_00000294, and the `state + 0x6408/0x6534`
 *     case in func_000006BC/func_000005C8);
 *   - which of two otherwise-equivalent registers it assigns to a dead/free
 *     value (func_000007C8's `$a0` vs `$a1` for the copy-loop pointer).
 * Treat DRAFTs as very-close NONMATCHING, not as verified.
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
void func_000007C8(void *unused, int arg1, int arg2, int arg3);
void func_00000894(int arg0, int arg1, void *arg2);

/* func_00000000 — module entry point: registers the viewer's main loop
 * (func_00000034) and teardown (func_000001C0) callbacks.
 * MATCH 100% (mwccpsp_3.0.1_219, -O4,p -sdatathreshold 0). */
int func_00000000(void) {
    func_000008B4(func_00000034, func_000001C0, (void *) &D_00005AC0);
    return 0;
}

/* func_00000034 — viewer main loop: dispatches on the current mode
 * (D_0009DB00+0x4) each frame until told to exit (mode 4). DRAFT: 60/65
 * target words, logic confirmed correct (tried a goto-based rewrite mirroring
 * the target's block order — no improvement). The gap is two more instances
 * of the same MWCC branch-polarity heuristic as func_000001C8 (beq-to-handler
 * +explicit `b` vs bne-skip, not controllable from portable C per the file
 * header), plus the loop-exit test: target computes `sltu`+`xori`+`bnez`
 * (3 words) where this compile collapses the same boolean check to a single
 * `beqz`/`beq` (tried `volatile int done` to block the optimization — no
 * effect). */
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
 * then sets the new mode and runs its entry logic. DRAFT: 29/33 target words,
 * logic/instruction selection confirmed correct — the remaining gap is MWCC
 * choosing `beq`+duplicated epilogue vs `bnel`+merged epilogue for the
 * mode==2 check, the same branch-polarity heuristic noted in the file header
 * as not reliably controllable from portable C (tried goto-based rewrites of
 * both checks; the old_mode read now correctly matches the target's
 * raw-absolute D_0009DB04 access instead of an offset off D_0009DB00). */
void func_000001C8(int mode) {
    int old_mode = D_0009DB04;
    volatile int *s1 = &D_0009DB00;

    if (old_mode == 2) {
        goto call464;
    }
    goto after464;
call464:
    func_00000464();
after464:
    s1[1] = mode; /* +0x4 */

    if (mode == 3) {
        goto clear;
    }
    if (mode == 2) {
        goto call294;
    }
    goto end;
call294:
    func_00000294();
    goto end;
clear:
    *(volatile int *) ((volatile char *) s1 + 0x6534) = 0;
end:
    ;
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
 * are placeholder byte offsets (`cfg[OFF]`), not yet a real struct.
 * Logic/order/values are all confirmed correct against the target
 * (statement-by-statement, including the read-modify-write bit twiddling on
 * +0xCC/+0xCD and the D0/D4/D6 geometry clamp at the end) but target=116
 * candidate=131 words. Root cause confirmed by isolated experiment (not
 * guessed): the target keeps `&D_000A3F0C` cached in one register ($s0) for
 * the whole function and derives `rec = cfg+0x4C` from it with a single
 * ADDIU, while this compile re-materializes a fresh `lui/addiu` pair for
 * D_000A3F0C at almost every access (~13 extra pairs = the entire gap).
 * Tried, none changed it: a plain `char*` local, `register char*`, an
 * `extern char[]` decl instead of `char`, a real struct with `->field`
 * access, folding away the scratch locals (b/val_408/val_530/t0/t1) into
 * single inline expressions, and reproducing the exact statement order in a
 * standalone test file compiled with the same flags. A minimal repro
 * confirmed MWCC always re-derives a global's address in straight-line code
 * this dense regardless of source shape — same class of MWCC-internal
 * codegen choice as the other DRAFTs in this file, just with a much bigger
 * word-count impact because of how many fields this one function touches.
 * The isolated repro also reconfirmed the `(x<0)?0:x`-to-`max`/min-to-`min`
 * pseudo-op fold is unreliable even with statement order matching the
 * target exactly, consistent with func_00000470's DRAFT note. */
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
    *(void (**)(void *, int, int, int)) (cfg + 0x100) = func_000007C8;

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
 * once a completion flag is set, transitions to mode 3 or 4. DRAFT: logic
 * confirmed correct; target=52 candidate=55 words. Confirmed (via an
 * isolated standalone test of `x = x<0?0:x` and equivalents) that no
 * portable-C form of the decrement-then-clamp-to-zero idiom makes MWCC emit
 * the Allegrex `max` pseudo-op here — it stays a `bgez`+move sequence, same
 * "ternary-to-max fold is unreliable" quirk noted in the file header. */
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

/* func_000005C8 — per-frame update for mode: dispatches on the current
 * mode value (D_0009DB04) to run small per-mode housekeeping. The mode==3
 * handler reads/writes D_0009DB00+0x6530/+0x6534 through the shared state
 * pointer rather than standalone extern symbols (same field-sharing as
 * elsewhere in this file), and D_000A3F0C is similarly state+0x640C here.
 * DRAFT: rewriting the if/else-if chain as an explicit goto chain (matching
 * the target's default-inline-others-as-labeled-blocks layout, and forcing
 * mode==3/2/1 check order — a plain `switch` gets sorted ascending by MWCC
 * regardless of case order in the source, which doesn't match this target)
 * got this from 65/59 to 60/59 target words. The remaining word is the same
 * address-CSE choice as func_000006BC: MWCC caches `state + 0x6534` into its
 * own register for the mode==3 body instead of folding the offset into each
 * load/store immediate. */
void func_000005C8(void) {
    int mode = D_0009DB04;
    volatile int *state = &D_0009DB00;
    int handle;

    if (mode == 3) {
        goto case3;
    }
    if (mode == 2) {
        goto case2;
    }
    if (mode == 1) {
        goto case1;
    }
    func_00002EB4(0x10, 0x10);
    func_00002E94(0, 0, &D_00005A7C);
    return;
case1:
    func_00002EB4(0x10, 0x10);
    func_00002E94(0, 0, &D_00005A88);
    return;
case2:
    handle = func_00000DA4(1, 0);
    func_0000169C(&handle, (void *) ((volatile char *) state + 0x640C));
    func_00000DAC(handle);
    return;
case3:
    if (*(volatile int *) ((volatile char *) state + 0x6534) != 0) {
        int slot = *(volatile int *) ((volatile char *) state + 0x6530);
        func_00001A5C((void *) ((volatile char *) state + (slot << 8) + 8), 0xF3F9);
        *(volatile int *) ((volatile char *) state + 0x6534) = 0;
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
 * table at D_0009DB00+0x8. The func_00002234 out-param is an opaque 0x108-byte
 * directory-entry record: flags live at +0x0, the name string at +0x58
 * (confirmed by the target's local frame layout: the out-param buffer sits
 * at sp+0x20, the name bytes are read/passed at sp+0x78). The running slot
 * count normally named D_000A3F08 is accessed here through the D_0009DB00
 * base register (offset 0x6408) rather than its own extern symbol, same as
 * the state-blob field sharing noted in the file header. DRAFT: rewriting
 * the `while` as an explicit goto-test-first loop (matching func_00000034's
 * technique) fixed a loop-rotated-with-duplication issue and got this from
 * 75/67 to 71/67 target words. The remaining 4 words are MWCC choosing to
 * CSE the repeated `state + 0x6408` computation into its own cached base
 * register (2 extra lui/addiu) instead of folding the offset into each
 * individual load/store's immediate like the target does — tried dropping
 * the `state` local entirely and re-deriving `&D_0009DB00` at each site,
 * and array-indexing instead of char-offset casts; the compiler made the
 * same CSE choice either way, so this is compiler-internal, not
 * source-shape-driven. */
void func_000006BC(void *arg0) {
    volatile int *state = &D_0009DB00;
    char dirent[0x108];
    int handle = func_00002224();
    int flags;

    goto test;
loop:
    flags = *(int *) dirent;
    if (*(volatile int *) ((volatile char *) state + 0x6408) >= 0x64) {
        goto done;
    }
    if (!(flags & 0x1000)) {
        if (flags & 0x2000) {
            int index = *(volatile int *) ((volatile char *) state + 0x6408);
            char *slot = (char *) state + (index << 8) + 8;
            func_00001DBC(slot, arg0);
            func_00001DCC(slot, dirent + 0x58);
            *(volatile int *) ((volatile char *) state + 0x6408) = index + 1;
        }
    } else if (*(signed char *) (dirent + 0x58) != 0x2E) {
        int len = func_00001DE4(arg0);
        func_00001DCC(arg0, dirent + 0x58);
        func_00001DCC(arg0, &D_00005AA4);
        func_000006BC(arg0);
        ((char *) arg0)[len] = 0;
    }
test:
    if (func_00002234(handle, dirent) > 0) {
        goto loop;
    }
done:
    func_0000222C(handle);
}

/* func_000007C8 — render callback set into the viewer config
 * (D_000A3F0C+0x100): builds a wide-char label from a table entry's name
 * and draws it. Real signature takes a leading unused param (target uses
 * $a1/$a2/$a3 for arg1/arg2/arg3, not $a0/$a1/$a2). DRAFT: byte-identical
 * except 4 words where the target keeps the `src` copy pointer in $a1
 * (reusing arg1's register) and this compile allocates it to $a0 instead —
 * tried reordering/retyping the locals and params, register choice didn't
 * budge; same class of MWCC-internal-heuristic quirk as the other DRAFTs in
 * this file. */
void func_000007C8(void *unused, int arg1, int arg2, int arg3) {
    short label[0x100];
    signed char *src = (signed char *) &D_0009DB00 + ((arg1 & 0xFFFF) << 8) + 8;
    short *dst = label;

    goto test;
loop:
    *dst = (short) *src;
    dst++;
    src++;
test:
    if (*src != 0) {
        goto loop;
    }
    *dst = 0;

    func_00002F94(func_00000EFC(func_00000EB4(-1), 0, 1));
    func_00002EB4(0xC, 0xC);
    func_00002EC4(0xFF000000);
    func_00000894(arg2 + 2, arg3 + 2,
                   (void *) (label + func_00001DE4(
                                          (void *) (long) func_00000924(3))));
    func_00002F9C();
}

/* func_00000894 — tail-calls the real draw routine with geometry derived
 * from arg0 (a "used width" the caller subtracts from a fixed 0x1E0
 * total).
 * MATCH 100% (mwccpsp_3.0.1_219, -O4,p -sdatathreshold 0). */
void func_00000894(int arg0, int arg1, void *arg2) {
    func_00002EE4(arg0 << 6, arg1 << 6, (0x1E0 - arg0) << 6, arg2);
}
