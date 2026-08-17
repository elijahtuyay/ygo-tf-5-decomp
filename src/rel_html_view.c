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
 * Data layout. Names come from config/symbols/rel_html_view.extra.txt, which
 * scripts/resolve_nids.py merges into the generated symbol file, so the
 * disassembly and this source use the SAME names. Everything at or after vram
 * 0x5EA0 is past the end of .data, i.e. .bss:
 *
 *   vram      symbol           where   what
 *   0x5E34    jtbl_00005E34    .data   func_0000039C's jump table (6 entries)
 *   0x5E4C    s_download_url   .data   the URL literal above
 *   0x5E80    s_savedata_dir   .data   "/PSP/SAVEDATA/"
 *   0x5EA0    g_module_reg     .bss    0xC, 3rd arg of the registration call
 *   0x5EAC    g_state          .bss    state word 1..4, see func_00000670
 *   0x5EB0    g_html_param     .bss    0xA8, the SceUtilityHtmlViewerParam
 *   0x5F68    g_url_buf        .bss    0x200, initialurl/homeurl text
 *   0x6168    g_dl_dir_buf     .bss    0x84, dldirname text
 *   0x61EC    g_heap_ptr       .bss    points at g_heap
 *   0x61F0    g_heap           .bss    the 6 MB block passed as param.memaddr
 *
 * HOW THIS MODULE IS ENTERED — it exports NOTHING. Its `libhtml_view_rel`
 * entry table has 0 functions and 0 variables, and its syslib entry exports
 * only the two standard variables `module_info` (NID 0xF01D73A7) and
 * `module_sdk_version` (0x11B97506). No other module imports it, either: it is
 * absent from every other module's .lib.stub, unlike e.g. rel_cardalbum, which
 * rel_labo and rel_title both import.
 *
 * So nothing calls into this module by name. The PRX's ELF entry point is
 * 0x0 — func_00000000 — which the engine's module loader calls, and that
 * function's whole job is to hand the engine two callbacks (func_00000034 to
 * run, func_00000084 to tear down) plus g_module_reg. Everything after that is
 * driven by the engine calling those callbacks. rel_movie_viewer has the same
 * shape (entry 0x0, same registration call ehsys_B4471B5E), so this is the
 * convention for a leaf module rather than anything specific to the browser.
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
 * Three engine functions this module uses were identified by reading the EBOOT
 * (evidence in nids/ehsys.names.csv): ehsys_get_language (334 call sites
 * project-wide), ehsys_get_button_code (288) and ehsys_frame_sync (172). The
 * first two explain func_0000039C and the buttonSwap test below; unlike the
 * sce* names they are inferences, not hash-proven symbols.
 *
 * Resolution confirmed the whole reading of this module and named the thing it
 * is really doing: `sceUtilityHtmlViewerInitStart` takes a
 * **`pspUtilityHtmlViewerParam`**, a documented SDK struct that is exactly the
 * 0xA8 bytes func_00000470 fills in, and func_000005A0 is the standard utility
 * dialog pump (`GetStatus()` -> 2 = `Update()`, 3 = `ShutdownStart()`).
 * Re-typing func_00000470's 30 stores against the real field layout is the
 * obvious next step.
 *
 * STATUS — 15 of the module's 16 functions are byte-identical to the target
 * (mwccpsp_3.0.1_219, -O4,s -sdatathreshold 0), verified with mwcc_diff.py.
 * Only func_00000470 is outstanding, and only by a 4-word instruction
 * SCHEDULING permutation — every word is otherwise identical. See its comment.
 *
 * func_0000039C's jump table is verified by CONTENTS, not by name: splat calls
 * the shipped module's table jtbl_00005E34 (it sits in .data — the module has
 * no general .rodata), while an unlinked .o has an anonymous local in .rodata
 * whose entries are relocation addends off the function. mwcc_diff.py now
 * checks that every target entry equals func_vram + the candidate's addend;
 * all six do. That is a link-time placement difference, not a source one, and
 * no compiler flag controls it (-strings readonly/noreadonly and
 * -sdatathreshold make no difference). Every module with a switch will hit
 * this, which is why the check lives in the differ.
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
extern char s_download_url;   /* "http://www.konami.jp/gs/game/yugioh_tf5/dl/eu.php" */
extern char s_savedata_dir;   /* "/PSP/SAVEDATA/" */
extern char g_module_reg;
extern volatile int g_state;
extern char g_html_param;
extern char g_url_buf;
extern char g_dl_dir_buf;
extern char g_heap;
extern void *g_heap_ptr;

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
    ehsys_B4471B5E(func_00000034, func_00000084, (void *) &g_module_reg);
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
    ehsys_strcat(dst, &s_download_url);
}

/* func_00000420 — build the savedata path into dst: copy "/PSP/SAVEDATA/",
 * then append the game's own id (ehsys_57018B7C fills the 0x20-byte buffer). */
void func_00000420(void *dst) {
    char buf[0x20];

    ehsys_strcpy(dst, &s_savedata_dir);
    ehsys_memset(buf, 0, 0x20);
    ehsys_57018B7C(buf);
    ehsys_strcat(dst, buf);
}

/* func_00000470 — build the 0xA8-byte browser config at g_html_param and hand
 * it to sceUtilityHtmlViewerInitStart (the "start browser" import).
 *
 * NONMATCHING, but only just: 76/76 words, every word identical except WHERE
 * the call's argument setup sits. The target emits `addu $a0, $s0, $zero`
 * BEFORE the three trailing `sw $zero` stores; MWCC puts it immediately before
 * the jal. The stores themselves are already in the target's exact order.
 *
 * Source shapes tried, none of which moves it: shared vs duplicated return
 * variable; a separate pointer variable for the call argument; passing
 * `&cfg->base`; `(char *)0` instead of `0` for the three pointer fields;
 * chained assignment; an inner block; hoisting the argument into a local
 * declared early; reordering the four trailing stores (putting
 * `disconnectmode` first gets 3 diffs instead of 4, but only by moving the
 * stores AWAY from the target's order, so it is not closer); and accessing the
 * global directly instead of through a pointer — that last one is worth
 * recording as a NEGATIVE result: it re-materialises &g_param at every access
 * and explodes to 100 words, which is the func_00000294 trap from
 * rel_movie_viewer reproducing here. The pointer-variable form is what keeps
 * the base in $s0, and it is not negotiable.
 *
 * Next thing to try: decomp-permuter (the scaffold from func_00000294 is
 * reusable, and unlike that case there is no compile-time constant blocking
 * it — this is a pure scheduling tie-break, which is what the permuter is
 * actually good at).
 *
 * The base register does NOT re-materialise here (unlike func_00000294 in
 * rel_movie_viewer) — see the file header for the int[]-indexing +
 * pointer-typed-store combination that made $s0 stick. */
int func_00000470(void *arg0) {
    SceUtilityHtmlViewerParam *cfg = (SceUtilityHtmlViewerParam *) &g_html_param;

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

    func_00000414(&g_url_buf);
    cfg->initialurl = &g_url_buf;
    cfg->numtabs = 3;
    cfg->interfacemode = 2;
    cfg->options = 0x2BA;

    func_00000420(&g_dl_dir_buf);
    cfg->dldirname = &g_dl_dir_buf;
    cfg->cookiemode = 3;
    cfg->unknown3 = 0x200;
    cfg->textsize = 1;
    cfg->displaymode = 1;
    cfg->connectmode = 1;
    cfg->unknown4[9] = 1;
    cfg->homeurl = &g_url_buf;
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
    char *cfg = &g_html_param;
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
    g_state = 1;
    g_heap_ptr = &g_heap;
}

/* func_00000670 — the state machine, pumped once per frame by func_00000034.
 * Returns nonzero once state 4 (done) is reached. */
int func_00000670(void) {
    switch (g_state) {
    case 1:
        if (func_00000278() < 0) {
            g_state = 3;
        } else if (func_00000470(g_heap_ptr) < 0) {
            g_state = 3;
        } else {
            g_state = g_state + 1;
        }
        break;
    case 2:
        if (func_000005A0() != 0) {
            g_state = g_state + 1;
        }
        break;
    case 3:
        func_00000358();
        g_state = g_state + 1;
        break;
    case 4:
        return 1;
    }
    return 0;
}
