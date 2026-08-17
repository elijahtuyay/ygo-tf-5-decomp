/*
 * rel_html_view.prx — reconstructed code (matching decompilation)
 *
 * Compiler:     Metrowerks CodeWarrior for PSP — MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,s -sdatathreshold 0   (same config confirmed on rel_movie_viewer)
 * Verification: scripts/mwcc_build.sh src/rel_html_view.c
 *               scripts/mwcc_diff.py asm/rel_html_view/text.s build/mwcc/rel_html_view.o
 *
 * Read src/rel_movie_viewer.c's file header first: every convention and every
 * MWCC lever documented there (volatile-global-via-local-pointer, switch vs if
 * branch shapes, int[] indexing of a state blob, the __builtin_allegrex_*
 * intrinsics, and the -O2+ address re-materialisation trap) applies here too.
 *
 * WHAT THIS MODULE IS. The in-game HTML/browser front end. Its .data holds the
 * two strings it needs:
 *   vram 0x5E4C  "http://www.konami.jp/gs/game/yugioh_tf5/dl/eu.php"
 *   vram 0x5E80  "/PSP/SAVEDATA/"
 * i.e. it configures and runs the PSP's browser/HTTP stack against Konami's
 * TF5 download page, with a savedata directory for downloads.
 *
 * Data layout (everything at/after vram 0x5EA0 is past the end of .data, i.e.
 * .bss — uninitialised globals):
 *   D_00005E4C  .data  the URL literal above
 *   D_00005E80  .data  the "/PSP/SAVEDATA/" literal
 *   D_00005EA0  .bss   module-registration blob passed to func_00000818
 *   D_00005EAC  .bss   the module's state/mode word (1..4), see func_00000670
 *   D_00005EB0  .bss   0xA8-byte browser config struct built by func_00000470
 *   D_00005F68  .bss   0x200-byte URL buffer  (filled by func_00000414)
 *   D_00006168  .bss   0x84-byte  path buffer (filled by func_00000420)
 *   D_000061EC  .bss   pointer, initialised to &D_000061F0 by func_00000650
 *   D_000061F0  .bss   the buffer that pointer points at
 *
 * Functions at vram >= 0x760 (func_00000760 and up) are .sceStub.text import
 * trampolines, i.e. calls out to the engine/SDK; they are NOT part of this
 * translation unit and are declared extern below. Their signatures are
 * best-effort guesses from call sites until the NID table is resolved.
 *
 * STATUS — 15 of 17 functions are byte-identical to the target
 * (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0), verified with mwcc_diff.py:
 *
 *   MATCH 100%  func_00000000 func_00000034 func_00000084 func_0000008C
 *               func_00000134 func_00000178 func_00000244 func_00000278
 *               func_00000358 func_00000414 func_00000420 func_000005A0
 *               func_00000650 func_00000670
 *   MATCH,      func_0000039C  — every instruction and both relocation kinds
 *   modulo                       are identical; only the jump table's SECTION
 *   section                      differs (ours lands in .rodata, the shipped
 *                                module has no .rodata and keeps it in .data
 *                                as jtbl_00005E34). Not a source problem.
 *   NONMATCHING func_00000470  — 76/76 words, all identical except a 4-word
 *                                scheduling permutation; see its comment.
 *
 * THREE LEVERS THIS MODULE ADDED (all reusable, all cost real time to find):
 *  1. A dead argument register can double as a switch's comparison constant.
 *     func_000005A0's target tests `beq $v0, $a0` against 2 where every other
 *     case uses $v1 — because the case-2 body calls func_000007E8(2) and MWCC
 *     hoisted the argument load above the compare and reused it. An import
 *     whose call site sets up NO argument register is not necessarily a
 *     no-argument function: check whether an earlier constant load already
 *     put the value there.
 *  2. MWCC emits switch case TESTS in reverse source order while laying the
 *     case BODIES out in source order. To reproduce the target's 3, 2, 4, 1
 *     test order the cases are written 1, 4, 2, 3. (rel_movie_viewer's
 *     func_00000034 recorded "tests descending"; that was a special case of
 *     this — its source happened to be in ascending order.)
 *  3. A duplicated `return r;` — once inside the failure branch and once
 *     after it — is not redundant to MWCC. Written as a single shared return
 *     (`if (r < 0) { cleanup(); } return r;`, or the equivalent goto) it
 *     picks the branch-LIKELY form and schedules the return-value move into
 *     the delay slot; duplicating the return gives the target's plain
 *     `bgez` + `nop`. This matched the tails of func_00000178/func_00000278.
 *
 * ALSO WORTH RECORDING: the -O2+ address re-materialisation trap that stalled
 * rel_movie_viewer's func_00000294 did NOT recur here. func_00000470 builds a
 * 0xA8-byte global struct through 30 stores and MWCC kept the base in $s0 for
 * all of them — but ONLY once the struct was indexed as int[] and the pointer
 * fields were stored through `*(void **)&cfg[n]` rather than `(int)&sym`. The
 * int-cast form made the address an integer temp that got CSE'd into a saved
 * register across calls (2 words short, and it swapped $s0/$s1). So the
 * pointer/int distinction, not just the indexing form, drives whether MWCC
 * caches or re-materialises a global's address. That is a concrete new lead
 * for func_00000294, which currently re-materialises where the target caches.
 */

/* ---- imports (.sceStub.text trampolines) ---- */
extern int  func_00000760(void);
extern int  func_00000768(void);
extern int  func_00000770(void);
extern int  func_00000778(int, int);
extern int  func_00000780(void);
extern int  func_00000788(void);
extern int  func_00000790(void);
extern int  func_00000798(int);
extern int  func_000007A0(void);
extern int  func_000007A8(int, int);
extern int  func_000007B0(int);
extern int  func_000007B8(void);
extern int  func_000007C0(int, int, int, int);
extern int  func_000007C8(void);
extern int  func_000007D0(void);
extern int  func_000007D8(void);
extern int  func_000007E0(int, int, int, int, int);
extern int  func_000007E8(int);
extern int  func_000007F0(int);
extern int  func_000007F8(void);
extern int  func_00000800(void *);
extern int  func_00000808(int);
extern int  func_00000810(void);
extern void func_00000818(void (*)(void), void (*)(void), void *);
extern int  func_00001778(int);
extern void func_00001990(int, int);
extern void func_000019C8(void *);
extern void func_00001CE0(void *, int, int);
extern void func_00001D20(void *, void *);
extern void func_00001D30(void *, void *);
extern void func_00001E38(int, int);
extern void func_00002210(int, int);
extern void func_00002F38(void);
extern int  func_000038B8(void);

/* ---- module data ---- */
extern char D_00005E4C;   /* "http://www.konami.jp/gs/game/yugioh_tf5/dl/eu.php" */
extern char D_00005E80;   /* "/PSP/SAVEDATA/" */
extern char D_00005EA0;
extern volatile int D_00005EAC;
extern char D_00005EB0;
extern char D_00005F68;
extern char D_00006168;
extern char D_000061F0;
extern void *D_000061EC;

/* forward declarations: the call graph is not in address order */
void func_00000034(void);
void func_00000084(void);
int  func_0000008C(void);
void func_00000134(void);
int  func_00000178(void);
void func_00000244(void);
int  func_00000278(void);
void func_00000358(void);
int  func_0000039C(void);
void func_00000414(void *dst);
void func_00000420(void *dst);
int  func_00000470(void *arg0);
int  func_000005A0(void);
void func_00000650(void);
int  func_00000670(void);

/* func_00000000 — module entry point: registers the browser's main routine
 * (func_00000034) and its (empty) teardown hook (func_00000084).
 * Same shape as rel_movie_viewer's func_00000000. */
int func_00000000(void) {
    func_00000818(func_00000034, func_00000084, (void *) &D_00005EA0);
    return 0;
}

/* func_00000034 — the module's main routine: init, then pump func_00000670
 * (the state machine) once per frame until it reports "done". */
void func_00000034(void) {
    func_00001E38(0, 0x4000);
    func_00000650();
loop:
    if (func_00000670() != 0) {
        goto done;
    }
    func_00002F38();
    goto loop;
done:
    func_00001990(0xD, 0);
}

/* func_00000084 — empty teardown callback registered by func_00000000. */
void func_00000084(void) {
}

/* func_0000008C — acquire six resources/handles (ids 0x100, 0x102..0x106);
 * on the first failure release everything already taken (func_00000134) and
 * return that negative result. The success path returns the LAST acquire's
 * value, which is why one variable carries both. */
int func_0000008C(void) {
    int r;

    r = func_000007F0(0x100);
    if (r < 0) {
        goto fail;
    }
    r = func_000007F0(0x102);
    if (r < 0) {
        goto fail;
    }
    r = func_000007F0(0x103);
    if (r < 0) {
        goto fail;
    }
    r = func_000007F0(0x104);
    if (r < 0) {
        goto fail;
    }
    r = func_000007F0(0x105);
    if (r < 0) {
        goto fail;
    }
    r = func_000007F0(0x106);
    if (r < 0) {
        goto fail;
    }
    return r;
fail:
    func_00000134();
    return r;
}

/* func_00000134 — release the six resources acquired by func_0000008C, in
 * reverse order. */
void func_00000134(void) {
    func_00000808(0x106);
    func_00000808(0x105);
    func_00000808(0x104);
    func_00000808(0x103);
    func_00000808(0x102);
    func_00000808(0x100);
}

/* func_00000178 — bring up the network/browser stack (0x28000 = 160 KB of
 * working memory). Every step after the first unwinds via func_00000244. */
int func_00000178(void) {
    int r;

    r = func_00000798(0x28000);
    if (r < 0) {
        return r;
    }
    r = func_000007B0(0x28000);
    if (r < 0) {
        func_00000244();
        return r;
    }
    r = func_000007C0(0, 0, 0, 0);
    if (r < 0) {
        func_00000244();
        return r;
    }
    r = func_000007A8(0, 0);
    if (r < 0) {
        func_00000244();
        return r;
    }
    /* the LAST check must carry its own `return r;` INSIDE the if-body, with a
     * second `return r;` after it. Phrased as one shared return (either
     * `if (r < 0) { cleanup(); } return r;` or a `goto` past the cleanup) MWCC
     * emits the branch-LIKELY form and schedules the return-value move into
     * the delay slot; the duplicated return gives the target's plain `bgez` +
     * `nop`. The earlier checks are unaffected — they already return inside
     * their bodies. */
    r = func_000007C8();
    if (r < 0) {
        func_00000244();
        return r;
    }
    return r;
}

/* func_00000244 — tear down what func_00000178 brought up. */
void func_00000244(void) {
    func_000007A0();
    func_000007D0();
    func_000007B8();
    func_00000790();
}

/* func_00000278 — full startup sequence: resources, then a 0x20000-byte
 * subsystem, then the network stack. Any failure unwinds via func_00000358. */
int func_00000278(void) {
    int r;

    r = func_0000008C();
    if (r < 0) {
        return r;
    }
    r = func_000007E0(0x20000, 0x2A, 0, 0x2A, 0);
    if (r < 0) {
        return r;
    }
    r = func_00000760();
    if (r < 0) {
        func_00000358();
        return r;
    }
    r = func_00000788();
    if (r < 0) {
        func_00000358();
        return r;
    }
    r = func_00000778(0x5400, 0x30);
    if (r < 0) {
        func_00000358();
        return r;
    }
    /* same duplicated-return shape as func_00000178's last check. */
    r = func_00000178();
    if (r < 0) {
        func_00000358();
        return r;
    }
    return r;
}

/* func_00000358 — the module's full teardown path. */
void func_00000358(void) {
    func_00000244();
    func_00000770();
    func_00000780();
    func_00000768();
    func_000007D8();
    func_00000134();
}

/* func_0000039C — maps the system language (func_000038B8) onto the browser's
 * own language id. Compiled with a jump table (jtbl_00005E34, in .data). */
int func_0000039C(void) {
    switch (func_000038B8()) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 6;
    case 3:
        return 2;
    case 4:
        return 5;
    case 5:
        return 3;
    default:
        return 1;
    }
}

/* func_00000414 — append the Konami TF5 download URL to dst. */
void func_00000414(void *dst) {
    func_00001D30(dst, &D_00005E4C);
}

/* func_00000420 — build the savedata path into dst: copy "/PSP/SAVEDATA/",
 * then append the game's own id (func_000019C8 fills the 0x20-byte buffer). */
void func_00000420(void *dst) {
    char buf[0x20];

    func_00001D20(dst, &D_00005E80);
    func_00001CE0(buf, 0, 0x20);
    func_000019C8(buf);
    func_00001D30(dst, buf);
}

/* func_00000470 — build the 0xA8-byte browser config at D_00005EB0 and hand
 * it to func_00000800 (the "start browser" import).
 *
 * NONMATCHING, but only just: 76/76 words, every word identical except a
 * 4-word permutation at the end. The target schedules the call's argument
 * setup (`addu $a0, $s0, $zero`) BEFORE the three `sw $zero` stores; MWCC puts
 * it immediately before the jal in every phrasing tried — shared return
 * variable, separate pointer variable for the call argument, char* casts on
 * the stores, chained assignment, an inner block, and passing &D_00005EB0
 * directly (that last one costs an extra lui, 77 words). The store ORDER is
 * already correct. Whatever moves that move is not reachable from the
 * statement-level shapes tried so far.
 *
 * The base register does NOT re-materialise here (unlike func_00000294 in
 * rel_movie_viewer) — see the file header for the int[]-indexing +
 * pointer-typed-store combination that made $s0 stick. */
int func_00000470(void *arg0) {
    /* indexed as int[] (offset/4) rather than through recomputed byte
     * offsets: this is the same lever that matched rel_movie_viewer's
     * func_000005C8/func_000006BC — it keeps every offset folded into the
     * store immediate off the single base register the target holds in $s0. */
    int *cfg = (int *) &D_00005EB0;

    func_00001CE0(cfg, 0, 0xA8);

    cfg[0x00 / 4] = 0xA8; /* struct size */
    cfg[0x04 / 4] = func_0000039C();
    if ((func_00001778(0) & 0xFFFF) == 0x2000) {
        cfg[0x08 / 4] = 0;
    } else {
        cfg[0x08 / 4] = 1;
    }
    cfg[0x18 / 4] = 0x10;
    cfg[0x0C / 4] = 0x11;
    cfg[0x14 / 4] = 0x12;
    cfg[0x10 / 4] = 0x13;
    cfg[0x34 / 4] = 0x600000; /* browser heap size */
    *(void **) &cfg[0x30 / 4] = arg0;

    func_00000414(&D_00005F68);
    *(void **) &cfg[0x40 / 4] = &D_00005F68;
    cfg[0x44 / 4] = 3;
    cfg[0x48 / 4] = 2;
    cfg[0x4C / 4] = 0x2BA;

    func_00000420(&D_00006168);
    *(void **) &cfg[0x50 / 4] = &D_00006168;
    cfg[0x60 / 4] = 3;
    cfg[0x64 / 4] = 0x200;
    cfg[0x6C / 4] = 1;
    cfg[0x70 / 4] = 1;
    cfg[0x74 / 4] = 1;
    cfg[0xA4 / 4] = 1;
    *(void **) &cfg[0x68 / 4] = &D_00005F68;
    cfg[0x54 / 4] = 0;
    cfg[0x5C / 4] = 0;
    cfg[0x58 / 4] = 0;
    cfg[0x78 / 4] = 0;

    return func_00000800(cfg);
}

/* func_000005A0 — per-frame poll while the browser runs. func_000007F8
 * reports the browser's exit reason: 0 = still running (in which case the
 * config's +0x1C field selects the return code), otherwise dispatch the
 * reason and report 0. */
int func_000005A0(void) {
    char *cfg = &D_00005EB0;
    int reason;

    func_00002210(0, 0);
    reason = func_000007F8();
    if (reason != 0) {
        /* MWCC emits the case TESTS in reverse source order (the target tests
         * 3, 2, 4, 1), while laying the case BODIES out in source order — so
         * the source order below is 1, 4, 2, 3. */
        switch (reason) {
        case 1:
            break;
        case 4:
            break;
        case 2:
            func_000007E8(2);
            break;
        case 3:
            func_00000810();
            break;
        }
    } else {
        return (*(int *) (cfg + 0x1C) == 0) ? 1 : 2;
    }
    return 0;
}

/* func_00000650 — enter state 1 and point the state machine at its buffer. */
void func_00000650(void) {
    D_00005EAC = 1;
    D_000061EC = &D_000061F0;
}

/* func_00000670 — the state machine, pumped once per frame by func_00000034.
 * Returns nonzero once state 4 (done) is reached. */
int func_00000670(void) {
    switch (D_00005EAC) {
    case 1:
        if (func_00000278() < 0) {
            D_00005EAC = 3;
        } else if (func_00000470(D_000061EC) < 0) {
            D_00005EAC = 3;
        } else {
            D_00005EAC = D_00005EAC + 1;
        }
        break;
    case 2:
        if (func_000005A0() != 0) {
            D_00005EAC = D_00005EAC + 1;
        }
        break;
    case 3:
        func_00000358();
        D_00005EAC = D_00005EAC + 1;
        break;
    case 4:
        return 1;
    }
    return 0;
}
