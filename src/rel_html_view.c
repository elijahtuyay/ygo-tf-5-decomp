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
 *   D_00005EA0  .bss   module-registration blob passed to ehsys_B4471B5E
 *   D_00005EAC  .bss   the module's state/mode word (1..4), see func_00000670
 *   D_00005EB0  .bss   0xA8-byte browser config struct built by func_00000470
 *   D_00005F68  .bss   0x200-byte URL buffer  (filled by func_00000414)
 *   D_00006168  .bss   0x84-byte  path buffer (filled by func_00000420)
 *   D_000061EC  .bss   pointer, initialised to &D_000061F0 by func_00000650
 *   D_000061F0  .bss   the buffer that pointer points at
 *
 * Functions at vram >= 0x760 (sceNetInetInit and up) are .sceStub.text import
 * trampolines, i.e. calls out to the engine/SDK; they are NOT part of this
 * translation unit and are declared extern below. Their signatures are
 * best-effort guesses from call sites; the NAMES are now resolved and proven —
 * see docs/nids/README.md. Every import below is either a real SDK function
 * (its NID re-hashes to that exact name) or an engine export named
 * `ehsys_<NID>` / `ehsys_<name>`, and those names are identical in all 28
 * modules, so anything learned here transfers.
 *
 * Resolution confirmed the whole reading of this module and named the thing it
 * is really doing: `sceUtilityHtmlViewerInitStart` takes a
 * **`pspUtilityHtmlViewerParam`**, a documented SDK struct that is exactly the
 * 0xA8 bytes func_00000470 fills in, and func_000005A0 is the standard utility
 * dialog pump (`GetStatus()` -> 2 = `Update()`, 3 = `ShutdownStart()`).
 * Re-typing func_00000470's 30 stores against the real field layout is the
 * obvious next step.
 *
 * STATUS — the module has 16 functions (an earlier version of this header said
 * 17, which was a miscount). 14 are byte-identical to the target
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
 *     case uses $v1 — because the case-2 body calls
 *     sceUtilityHtmlViewerUpdate(2) and MWCC hoisted the argument load above
 *     the compare and reused it. An import
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
extern int  sceNetInetInit(void);
extern int  sceNetInetTerm(void);
extern int  sceNetApctlTerm(void);
extern int  sceNetApctlInit(int, int);
extern int  sceNetResolverTerm(void);
extern int  sceNetResolverInit(void);
extern int  sceSslEnd(void);
extern int  sceSslInit(int);
extern int  sceHttpSaveSystemCookie(void);
extern int  sceHttpsLoadDefaultCert(int, int);
extern int  sceHttpInit(int);
extern int  sceHttpEnd(void);
extern int  sceHttpsInit(int, int, int, int);
extern int  sceHttpLoadSystemCookie(void);
extern int  sceHttpsEnd(void);
extern int  sceNetTerm(void);
extern int  sceNetInit(int, int, int, int, int);
extern int  sceUtilityHtmlViewerUpdate(int);
extern int  sceUtilityLoadModule(int);
extern int  sceUtilityHtmlViewerGetStatus(void);
extern int  sceUtilityHtmlViewerInitStart(void *);
extern int  sceUtilityUnloadModule(int);
extern int  sceUtilityHtmlViewerShutdownStart(void);
extern void ehsys_B4471B5E(void (*)(void), void (*)(void), void *);
extern int  ehsys_8171F765(int);
extern void ehsys_08813E19(int, int);
extern void ehsys_57018B7C(void *);
extern void ehsys_memset(void *, int, int);
extern void ehsys_strcpy(void *, void *);
extern void ehsys_strcat(void *, void *);
extern void ehsys_sceKernelChangeCurrentThreadAttr(int, int);
extern void ehsys_sceGuSync(int, int);
extern void ehsys_F1BC43DB(void);
extern int  ehsys_31454993(void);

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

/* ---- pspUtilityHtmlViewerParam (the SDK struct func_00000470 fills) ----
 * sceUtilityHtmlViewerInitStart's parameter, identified via the resolved NID
 * (docs/nids/README.md). sizeof is exactly 0xA8 — the size func_00000470
 * memsets and then stores into `base.size`, which is what confirms the layout.
 * Field names follow the public SDK headers; `unknownN` are unnamed there too. */
typedef struct {
    int size;           /* 0x00 */
    int language;       /* 0x04 */
    int buttonSwap;     /* 0x08 */
    int graphicsThread; /* 0x0C */
    int accessThread;   /* 0x10 */
    int fontThread;     /* 0x14 */
    int soundThread;    /* 0x18 */
    int result;         /* 0x1C — read by func_000005A0 */
    int reserved[4];    /* 0x20 */
} SceUtilityDialogCommon;

typedef struct {
    SceUtilityDialogCommon base; /* 0x00 */
    void *memaddr;               /* 0x30 */
    unsigned int memsize;        /* 0x34 */
    int unknown1;                /* 0x38 */
    int unknown2;                /* 0x3C */
    char *initialurl;            /* 0x40 */
    unsigned int numtabs;        /* 0x44 */
    unsigned int interfacemode;  /* 0x48 */
    unsigned int options;        /* 0x4C */
    char *dldirname;             /* 0x50 */
    char *dlfilename;            /* 0x54 */
    char *uldirname;             /* 0x58 */
    char *ulfilename;            /* 0x5C */
    unsigned int cookiemode;     /* 0x60 */
    unsigned int unknown3;       /* 0x64 */
    char *homeurl;               /* 0x68 */
    unsigned int textsize;       /* 0x6C */
    unsigned int displaymode;    /* 0x70 */
    unsigned int connectmode;    /* 0x74 */
    unsigned int disconnectmode; /* 0x78 */
    unsigned int memused;        /* 0x7C */
    int unknown4[10];            /* 0x80..0xA8 */
} SceUtilityHtmlViewerParam;

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
    ehsys_B4471B5E(func_00000034, func_00000084, (void *) &D_00005EA0);
    return 0;
}

/* func_00000034 — the module's main routine: init, then pump func_00000670
 * (the state machine) once per frame until it reports "done". */
void func_00000034(void) {
    ehsys_sceKernelChangeCurrentThreadAttr(0, 0x4000);
    func_00000650();
loop:
    if (func_00000670() != 0) {
        goto done;
    }
    ehsys_F1BC43DB();
    goto loop;
done:
    ehsys_08813E19(0xD, 0);
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

    r = sceUtilityLoadModule(0x100);
    if (r < 0) {
        goto fail;
    }
    r = sceUtilityLoadModule(0x102);
    if (r < 0) {
        goto fail;
    }
    r = sceUtilityLoadModule(0x103);
    if (r < 0) {
        goto fail;
    }
    r = sceUtilityLoadModule(0x104);
    if (r < 0) {
        goto fail;
    }
    r = sceUtilityLoadModule(0x105);
    if (r < 0) {
        goto fail;
    }
    r = sceUtilityLoadModule(0x106);
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
    sceUtilityUnloadModule(0x106);
    sceUtilityUnloadModule(0x105);
    sceUtilityUnloadModule(0x104);
    sceUtilityUnloadModule(0x103);
    sceUtilityUnloadModule(0x102);
    sceUtilityUnloadModule(0x100);
}

/* func_00000178 — bring up the network/browser stack (0x28000 = 160 KB of
 * working memory). Every step after the first unwinds via func_00000244. */
int func_00000178(void) {
    int r;

    r = sceSslInit(0x28000);
    if (r < 0) {
        return r;
    }
    r = sceHttpInit(0x28000);
    if (r < 0) {
        func_00000244();
        return r;
    }
    r = sceHttpsInit(0, 0, 0, 0);
    if (r < 0) {
        func_00000244();
        return r;
    }
    r = sceHttpsLoadDefaultCert(0, 0);
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
    r = sceHttpLoadSystemCookie();
    if (r < 0) {
        func_00000244();
        return r;
    }
    return r;
}

/* func_00000244 — tear down what func_00000178 brought up. */
void func_00000244(void) {
    sceHttpSaveSystemCookie();
    sceHttpsEnd();
    sceHttpEnd();
    sceSslEnd();
}

/* func_00000278 — full startup sequence: resources, then a 0x20000-byte
 * subsystem, then the network stack. Any failure unwinds via func_00000358. */
int func_00000278(void) {
    int r;

    r = func_0000008C();
    if (r < 0) {
        return r;
    }
    r = sceNetInit(0x20000, 0x2A, 0, 0x2A, 0);
    if (r < 0) {
        return r;
    }
    r = sceNetInetInit();
    if (r < 0) {
        func_00000358();
        return r;
    }
    r = sceNetResolverInit();
    if (r < 0) {
        func_00000358();
        return r;
    }
    r = sceNetApctlInit(0x5400, 0x30);
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
    sceNetApctlTerm();
    sceNetResolverTerm();
    sceNetInetTerm();
    sceNetTerm();
    func_00000134();
}

/* func_0000039C — maps the system language (ehsys_31454993) onto the browser's
 * own language id. Compiled with a jump table (jtbl_00005E34, in .data). */
int func_0000039C(void) {
    switch (ehsys_31454993()) {
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
    ehsys_strcat(dst, &D_00005E4C);
}

/* func_00000420 — build the savedata path into dst: copy "/PSP/SAVEDATA/",
 * then append the game's own id (ehsys_57018B7C fills the 0x20-byte buffer). */
void func_00000420(void *dst) {
    char buf[0x20];

    ehsys_strcpy(dst, &D_00005E80);
    ehsys_memset(buf, 0, 0x20);
    ehsys_57018B7C(buf);
    ehsys_strcat(dst, buf);
}

/* func_00000470 — build the 0xA8-byte browser config at D_00005EB0 and hand
 * it to sceUtilityHtmlViewerInitStart (the "start browser" import).
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
    SceUtilityHtmlViewerParam *cfg = (SceUtilityHtmlViewerParam *) &D_00005EB0;

    ehsys_memset(cfg, 0, sizeof(*cfg));

    cfg->base.size = sizeof(*cfg);
    cfg->base.language = func_0000039C();
    if ((ehsys_8171F765(0) & 0xFFFF) == 0x2000) {
        cfg->base.buttonSwap = 0;
    } else {
        cfg->base.buttonSwap = 1;
    }
    cfg->base.soundThread = 0x10;
    cfg->base.graphicsThread = 0x11;
    cfg->base.fontThread = 0x12;
    cfg->base.accessThread = 0x13;
    cfg->memsize = 0x600000;   /* 6 MB browser heap */
    cfg->memaddr = arg0;

    func_00000414(&D_00005F68);
    cfg->initialurl = &D_00005F68;
    cfg->numtabs = 3;
    cfg->interfacemode = 2;
    cfg->options = 0x2BA;

    func_00000420(&D_00006168);
    cfg->dldirname = &D_00006168;
    cfg->cookiemode = 3;
    cfg->unknown3 = 0x200;
    cfg->textsize = 1;
    cfg->displaymode = 1;
    cfg->connectmode = 1;
    cfg->unknown4[9] = 1;
    cfg->homeurl = &D_00005F68;
    cfg->dlfilename = 0;
    cfg->ulfilename = 0;
    cfg->uldirname = 0;
    cfg->disconnectmode = 0;

    return sceUtilityHtmlViewerInitStart(cfg);
}

/* func_000005A0 — per-frame poll while the browser runs. sceUtilityHtmlViewerGetStatus
 * reports the browser's exit reason: 0 = still running (in which case the
 * config's +0x1C field selects the return code), otherwise dispatch the
 * reason and report 0. */
int func_000005A0(void) {
    char *cfg = &D_00005EB0;
    int reason;

    ehsys_sceGuSync(0, 0);
    reason = sceUtilityHtmlViewerGetStatus();
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
            sceUtilityHtmlViewerUpdate(2);
            break;
        case 3:
            sceUtilityHtmlViewerShutdownStart();
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
