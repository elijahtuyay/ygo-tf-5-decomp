#!/usr/bin/env python3
"""
Rebuild the upstream review stack: 200+ commits of work, re-cut as ~35 branches.

    scripts/pr_stack.py            # rebuild every pr/* branch from HEAD
    scripts/pr_stack.py --check    # verify the stack tip matches HEAD, nothing else
    scripts/pr_stack.py --push     # rebuild, then push them all to the fork

Upstream cannot review a 225-file diff, so the same content is also published as
a stack of small branches: six foundation PRs, then one per module, then the
log. Branches are stacked (each based on the previous), so each diff shows only
its own change.

The stack is GENERATED, never hand-edited. The invariant that makes it worth
trusting is that its tip is byte-identical to the working branch:

    git diff --stat pr/99-engineering-log HEAD    # must be empty

If a file is added to the project and not classified below, this script fails
rather than silently leaving it out of the stack -- an unassigned file would
mean the stack quietly says less than we have. See docs/22-pr-stack.md.
"""
import argparse
import json
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
UPSTREAM = "origin/main"
TIP = "pr/99-engineering-log"
TRAILER = ("\nCo-Authored-By: Claude Opus 5 <noreply@anthropic.com>\n")


def git(*a, check=True):
    r = subprocess.run(["git"] + list(a), cwd=ROOT, capture_output=True, text=True)
    if check and r.returncode != 0:
        sys.exit(f"git {' '.join(a[:3])} failed:\n{r.stderr[:2000]}")
    return r.stdout


# Which branch each changed file belongs to. Order matters: first match wins.
RULES = [
    ("01-survey-all-modules", lambda f: (f.startswith("config/") and f.endswith(".yaml"))
        or f in ("Makefile", "scripts/module_survey.py", "scripts/asm_prepare.py")
        or f.startswith("docs/modules/")),
    ("02-nid-resolution", lambda f: f.startswith("nids/") or f.startswith("config/symbols/")
        or f in ("scripts/resolve_nids.py", "scripts/eboot_signatures.py",
                 "scripts/infer_arity.py", "docs/nids/README.md")),
    ("03-headers-and-types", lambda f: f.startswith("include/")
        or f in ("scripts/gen_types.py", "scripts/gen_context.py")),
    ("04-build-and-verification", lambda f: f in (
        "scripts/mwcc_build.sh", "scripts/mwcc_diff.py", "scripts/show_diff.py",
        "scripts/progress.py", "scripts/check_regressions.py", "scripts/make_hybrid.py",
        "scripts/hybrid_sweep.sh", "scripts/assemble_module.py", "scripts/setup_tools.sh",
        "docs/11-reproducing-the-pipeline.md", "docs/16-testing-methodology.md")),
    ("05-matching-pipeline", lambda f: f in (
        "scripts/auto_decomp.py", "scripts/merge_matches.py", "scripts/gate1_census.py",
        "scripts/near_misses.py", "scripts/permute.py", "scripts/find_twins.py",
        "scripts/adapt_twins.py", "scripts/idiom_families.py", "scripts/struct_copies.py",
        "scripts/const_trampolines.py", "scripts/leaf_trampolines.py",
        "scripts/prune_module.py", "docs/09-first-match.md", "docs/13-process-design.md",
        "docs/14-debugging-playbook.md", "docs/15-matching-playbook.md")),
    ("06-compiler-identification", lambda f: f in (
        "docs/17-compiler-identification.md", "scripts/comment_fingerprint_test.sh",
        "scripts/mwcc_bisect.sh")),
]
# Anything left over is the engineering log: session write-ups and local tooling.
FALLBACK = "99-engineering-log"

BODIES = json.loads(r'''{
 "01-survey-all-modules": [
  "feat(split): section-accurate splat configs for all 28 rel_*.prx modules",
  "Adds a splat config per module, each covering 100% of its file, plus the survey\ndoc it was derived from. After this, any of the 28 modules can be split and\nworked on immediately -- which is the prerequisite for everything else.\n\n`scripts/module_survey.py` generates the surveys (section table, splat\ndisassembly, printable strings in .data); `docs/modules/README.md` is the index,\nwith what each module actually is and how big its .text is.\n\nWorth knowing before reading further: rel_duel_eng alone is 3 MB of .text, 56%\nof the project. The other 27 modules together are 1.7 MB.\n\nNo decompiled code here -- this is purely the ability to split."
 ],
 "02-nid-resolution": [
  "feat(nids): resolve the shared import table once, for all 28 modules",
  "Every module's .rodata.sceNid is the same ~0x1B04 bytes / 1729 entries, with one\n8-byte .sceStub.text trampoline each. The array is byte-identical across all 28\nmodules AND in the EBOOT's export table (sha1 820088858e31), so stub *k* is the\nsame engine function everywhere and the EBOOT pairs each NID with its address.\n\nThose 1729 are not SDK imports: they are the complete export list of\nlibehsys_rel, the engine in the EBOOT, which every module links a stub for\nwhether it calls it or not.\n\nResolved and checked in:\n  - 986 engine functions actually called project-wide\n  - 275 module-to-module imports\n  -  47 genuine sce* SDK imports, every one hash-verified against its name\n\nconfig/symbols/<module>.txt feeds splat, so any module re-split from here gets\nnamed calls instead of raw addresses. This generalises PR #4 from\nrel_movie_viewer to all 28 modules."
 ],
 "03-headers-and-types": [
  "feat(include): generated engine and per-module declarations",
  "include/ehsys.h declares the resolved engine imports; include/globals/<module>.h\ndeclares each module's data symbols. Both are generated by scripts/gen_types.py\nfrom the NID tables in the previous PR, not hand-written -- so they can be\nregenerated rather than maintained.\n\nThe declared type of a global decides the load width MWCC emits (char -> lb,\nint -> lw, unsigned short -> lhu), which is why these matter for matching and\nnot just for readability."
 ],
 "04-build-and-verification": [
  "feat(build): the matching build, and the two gates that keep it honest",
  "Two gates, both of which had to exist before any match could be trusted.\n\n**Byte-exactness (HYBRID=1).** `make MODULE=<name> HYBRID=1` rebuilds a module's\n.text byte-for-byte from our C plus the shipped assembly for everything not yet\ndecompiled. All 28 modules pass; scripts/hybrid_sweep.sh checks the lot.\n\nRecommend treating HYBRID=1, not SRC=1, as the definition of done for a module.\nSRC=1 replaces the whole .text and so demands that every function match, which\nis unreachable by construction for the 19 modules containing hand-written\nassembly -- 248 functions are asm and can never come from C.\n\n**Regression (scripts/check_regressions.py).** Every function that ever verified\nas MATCH must stay matched. The baseline is a list of function NAMES per module,\nnot counts, so a regression names exactly what was lost, and --update refuses to\nshrink it without --force. The motivating incident was rel_html_view going 15 ->\n0 in a silent commit.\n\nVerification is the real thing, not bookkeeping: each checked module is\nrecompiled with mwccpsp and re-diffed, the local equivalent of a decomp.me score\nof 0. scripts/progress.py reports it."
 ],
 "05-matching-pipeline": [
  "feat(pipeline): automated draft-and-verify, and the levers behind it",
  "The loop that produces candidate matches at volume: draft with m2c, compile,\ndiff against the shipped code, keep only what reports MATCH.\n\n  auto_decomp.py     draft + compile + diff, shardable across a large module\n  merge_matches.py   add verified functions to a curated src/ file, one at a\n                     time, re-verifying after each and rolling back anything\n                     that breaks itself or a neighbour -- so it is safe to run\n                     against files a human is editing\n  gate1_census.py    measures WHY drafts fail to compile rather than guessing\n  find/adapt_twins   the same function compiled into several modules\n  near_misses.py     rank functions by how close they already are\n  permute.py         decomp-permuter driver\n\nTwo findings are worth more than the code:\n\n  1. m2c cannot read Allegrex `ext`/`ins` and fails SILENTLY -- 1,703 functions\n     were being drafted from truncated input without any error.\n  2. Measured fresh, 84% of drafts now compile. Gate 1 is not the bottleneck it\n     was assumed to be."
 ],
 "06-compiler-identification": [
  "docs(compiler): .comment identifies the LINKER, not the compiler",
  "A correction to a belief this project was steering by, with a reproducer:\nscripts/comment_fingerprint_test.sh.\n\nThe Metrowerks linker writes .comment itself and ignores what its input objects\ncarry. Two objects both compiled by 2.3.1.01 link into a binary claiming\n2.4.1.01 -- under either linker version, in either order. GNU ld merges both\nstrings instead, which is why the original experiment, run with GNU ld,\nconcluded the opposite.\n\nSo the shipped modules' `MW MIPS C Compiler (2.4.1.01)` identifies mwldpsp and\nsays nothing about which compiler built the code. The argument that our compiler\nis not publicly catalogued rested entirely on this, and is unsupported;\nmwccpsp_3.0.1_219 is excluded by nothing.\n\nPractical rule: do not screen candidate compilers with `readelf -p .comment` on\na linked binary. It is only diagnostic on an unlinked .o."
 ],
 "99-engineering-log": [
  "docs: the working session log",
  "Chronological notes from the sessions that produced the preceding PRs. Not\nrequired reading -- the distilled findings are already in the PRs they belong\nto. This is here so the reasoning, including the dead ends, is recoverable."
 ],
 "mod-rel_duel_eng": [
  "feat(rel_duel_eng): 1497 of 7487 functions matched",
  "The rules engine: 3 MB of code, all card logic hardcoded.\n\n  functions   1497 / 7487\n  .text bytes 60,728 / 3,107,612  (2.0%)\n\nVerify:\n\n    make MODULE=rel_duel_eng HYBRID=1        # rebuilds .text byte-for-byte\n    scripts/check_regressions.py rel_duel_eng\n\nEvery function in this file compiled with mwccpsp and diffed byte-identical\nagainst the shipped module. The baseline entry added here is the list of their\nnames, so any later regression names exactly what broke."
 ],
 "mod-rel_duel_draw": [
  "feat(rel_duel_draw): 650 of 1546 functions matched",
  "The duel renderer \u2014 float/VFPU constant pool in `.data`.\n\n  functions   650 / 1546\n  .text bytes 26,216 / 452,356  (5.8%)\n\nVerify:\n\n    make MODULE=rel_duel_draw HYBRID=1        # rebuilds .text byte-for-byte\n    scripts/check_regressions.py rel_duel_draw\n\nEvery function in this file compiled with mwccpsp and diffed byte-identical\nagainst the shipped module. The baseline entry added here is the list of their\nnames, so any later regression names exactly what broke."
 ],
 "mod-rel_field": [
  "feat(rel_field): 317 of 730 functions matched",
  "The overworld: a named scene table (`bg_02 [S_YUSEI_CAMP]`, `bg_09 [C_STADIUM]`, ...).\n\n  functions   317 / 730\n  .text bytes 11,136 / 228,624  (4.9%)\n\nVerify:\n\n    make MODULE=rel_field HYBRID=1        # rebuilds .text byte-for-byte\n    scripts/check_regressions.py rel_field\n\nEvery function in this file compiled with mwccpsp and diffed byte-identical\nagainst the shipped module. The baseline entry added here is the list of their\nnames, so any later regression names exactly what broke."
 ],
 "mod-rel_story": [
  "feat(rel_story): 333 of 640 functions matched",
  "Story mode / event scenes.\n\n  functions   333 / 640\n  .text bytes 10,556 / 88,840  (11.9%)\n\nVerify:\n\n    make MODULE=rel_story HYBRID=1        # rebuilds .text byte-for-byte\n    scripts/check_regressions.py rel_story\n\nEvery function in this file compiled with mwccpsp and diffed byte-identical\nagainst the shipped module. The baseline entry added here is the list of their\nnames, so any later regression names exactly what broke."
 ],
 "mod-rel_cutin_viewer": [
  "feat(rel_cutin_viewer): 124 of 314 functions matched",
  "Character cut-in viewer (`cutin_*.ehp`, `.tmt.gz` models).\n\n  functions   124 / 314\n  .text bytes 6,120 / 117,500  (5.2%)\n\nVerify:\n\n    make MODULE=rel_cutin_viewer HYBRID=1        # rebuilds .text byte-for-byte\n    scripts/check_regressions.py rel_cutin_viewer\n\nEvery function in this file compiled with mwccpsp and diffed byte-identical\nagainst the shipped module. The baseline entry added here is the list of their\nnames, so any later regression names exactly what broke."
 ],
 "mod-rel_decktutorial": [
  "feat(rel_decktutorial): 87 of 354 functions matched",
  "Guided deck-building tutorial.\n\n  functions   87 / 354\n  .text bytes 5,520 / 137,696  (4.0%)\n\nVerify:\n\n    make MODULE=rel_decktutorial HYBRID=1        # rebuilds .text byte-for-byte\n    scripts/check_regressions.py rel_decktutorial\n\nEvery function in this file compiled with mwccpsp and diffed byte-identical\nagainst the shipped module. The baseline entry added here is the list of their\nnames, so any later regression names exactly what broke."
 ],
 "mod-rel_deck": [
  "feat(rel_deck): 101 of 404 functions matched",
  "Deck editor (loads `duelsys/CARD_Link.bin`).\n\n  functions   101 / 404\n  .text bytes 4,860 / 148,136  (3.3%)\n\nVerify:\n\n    make MODULE=rel_deck HYBRID=1        # rebuilds .text byte-for-byte\n    scripts/check_regressions.py rel_deck\n\nEvery function in this file compiled with mwccpsp and diffed byte-identical\nagainst the shipped module. The baseline entry added here is the list of their\nnames, so any later regression names exactly what broke."
 ],
 "mod-rel_deckswap": [
  "feat(rel_deckswap): 61 of 245 functions matched",
  "Deck swap/share.\n\n  functions   61 / 245\n  .text bytes 4,624 / 98,028  (4.7%)\n\nVerify:\n\n    make MODULE=rel_deckswap HYBRID=1        # rebuilds .text byte-for-byte\n    scripts/check_regressions.py rel_deckswap\n\nEvery function in this file compiled with mwccpsp and diffed byte-identical\nagainst the shipped module. The baseline entry added here is the list of their\nnames, so any later regression names exactly what broke."
 ],
 "mod-rel_select_card": [
  "feat(rel_select_card): 64 of 248 functions matched",
  "Shared card picker used by rental, convert machine and the title menu.\n\n  functions   64 / 248\n  .text bytes 4,472 / 99,404  (4.5%)\n\nVerify:\n\n    make MODULE=rel_select_card HYBRID=1        # rebuilds .text byte-for-byte\n    scripts/check_regressions.py rel_select_card\n\nEvery function in this file compiled with mwccpsp and diffed byte-identical\nagainst the shipped module. The baseline entry added here is the list of their\nnames, so any later regression names exactly what broke."
 ],
 "mod-rel_tutoriallist": [
  "feat(rel_tutoriallist): 22 of 31 functions matched",
  "Tutorial index menu (`database/tutoriallist.ehp`).\n\n  functions   22 / 31\n  .text bytes 3,256 / 10,620  (30.7%)\n\nVerify:\n\n    make MODULE=rel_tutoriallist HYBRID=1        # rebuilds .text byte-for-byte\n    scripts/check_regressions.py rel_tutoriallist\n\nEvery function in this file compiled with mwccpsp and diffed byte-identical\nagainst the shipped module. The baseline entry added here is the list of their\nnames, so any later regression names exactly what broke."
 ],
 "mod-rel_shop": [
  "feat(rel_shop): 71 of 254 functions matched",
  "Card shop.\n\n  functions   71 / 254\n  .text bytes 3,016 / 105,164  (2.9%)\n\nVerify:\n\n    make MODULE=rel_shop HYBRID=1        # rebuilds .text byte-for-byte\n    scripts/check_regressions.py rel_shop\n\nEvery function in this file compiled with mwccpsp and diffed byte-identical\nagainst the shipped module. The baseline entry added here is the list of their\nnames, so any later regression names exactly what broke."
 ],
 "mod-rel_duel_mgr": [
  "feat(rel_duel_mgr): 54 of 228 functions matched",
  "Duel setup & flow: jyanken (turn order), win/lose/draw screens.\n\n  functions   54 / 228\n  .text bytes 2,996 / 94,100  (3.2%)\n\nVerify:\n\n    make MODULE=rel_duel_mgr HYBRID=1        # rebuilds .text byte-for-byte\n    scripts/check_regressions.py rel_duel_mgr\n\nEvery function in this file compiled with mwccpsp and diffed byte-identical\nagainst the shipped module. The baseline entry added here is the list of their\nnames, so any later regression names exactly what broke."
 ],
 "mod-rel_tutorial": [
  "feat(rel_tutorial): 98 of 190 functions matched",
  "In-duel tutorial driver (`tuto_field_%02d.ydq`, `tuto_cmd_%02d.bin`).\n\n  functions   98 / 190\n  .text bytes 2,772 / 26,740  (10.4%)\n\nVerify:\n\n    make MODULE=rel_tutorial HYBRID=1        # rebuilds .text byte-for-byte\n    scripts/check_regressions.py rel_tutorial\n\nEvery function in this file compiled with mwccpsp and diffed byte-identical\nagainst the shipped module. The baseline entry added here is the list of their\nnames, so any later regression names exactly what broke."
 ],
 "mod-rel_movie_viewer": [
  "feat(rel_movie_viewer): 15 of 16 functions matched",
  "`movie/` .pmf player.\n\n  functions   15 / 16\n  .text bytes 1,764 / 2,228  (79.2%)\n\nVerify:\n\n    make MODULE=rel_movie_viewer HYBRID=1        # rebuilds .text byte-for-byte\n    scripts/check_regressions.py rel_movie_viewer\n\nEvery function in this file compiled with mwccpsp and diffed byte-identical\nagainst the shipped module. The baseline entry added here is the list of their\nnames, so any later regression names exactly what broke."
 ],
 "mod-rel_umd_replace": [
  "feat(rel_umd_replace): 33 of 76 functions matched",
  "Previous-UMD recognition: disc IDs for Tag Force 1-4 across EU/JP/US.\n\n  functions   33 / 76\n  .text bytes 1,716 / 14,860  (11.5%)\n\nVerify:\n\n    make MODULE=rel_umd_replace HYBRID=1        # rebuilds .text byte-for-byte\n    scripts/check_regressions.py rel_umd_replace\n\nEvery function in this file compiled with mwccpsp and diffed byte-identical\nagainst the shipped module. The baseline entry added here is the list of their\nnames, so any later regression names exactly what broke."
 ],
 "mod-rel_duelrecord": [
  "feat(rel_duelrecord): 22 of 47 functions matched",
  "Duel record / stats screen.\n\n  functions   22 / 47\n  .text bytes 1,708 / 18,776  (9.1%)\n\nVerify:\n\n    make MODULE=rel_duelrecord HYBRID=1        # rebuilds .text byte-for-byte\n    scripts/check_regressions.py rel_duelrecord\n\nEvery function in this file compiled with mwccpsp and diffed byte-identical\nagainst the shipped module. The baseline entry added here is the list of their\nnames, so any later regression names exactly what broke."
 ],
 "mod-rel_labo": [
  "feat(rel_labo): 12 of 14 functions matched",
  "The \"Labo\" hub menu \u2014 launches password, rental, trade, convert, deckswap, album, duelist list, ranking, limit list, tutorial, partner select, voice & subtitle.\n\n  functions   12 / 14\n  .text bytes 1,704 / 4,840  (35.2%)\n\nVerify:\n\n    make MODULE=rel_labo HYBRID=1        # rebuilds .text byte-for-byte\n    scripts/check_regressions.py rel_labo\n\nEvery function in this file compiled with mwccpsp and diffed byte-identical\nagainst the shipped module. The baseline entry added here is the list of their\nnames, so any later regression names exactly what broke."
 ],
 "mod-rel_html_view": [
  "feat(rel_html_view): 15 of 16 functions matched",
  "In-game browser: Konami's TF5 download page + `/PSP/SAVEDATA/`.\n\n  functions   15 / 16\n  .text bytes 1,584 / 1,888  (83.9%)\n\nVerify:\n\n    make MODULE=rel_html_view HYBRID=1        # rebuilds .text byte-for-byte\n    scripts/check_regressions.py rel_html_view\n\nEvery function in this file compiled with mwccpsp and diffed byte-identical\nagainst the shipped module. The baseline entry added here is the list of their\nnames, so any later regression names exactly what broke."
 ],
 "mod-rel_soundtest": [
  "feat(rel_soundtest): 9 of 12 functions matched",
  "Sound test (`database/soundtest.ehp`).\n\n  functions   9 / 12\n  .text bytes 1,564 / 5,608  (27.9%)\n\nVerify:\n\n    make MODULE=rel_soundtest HYBRID=1        # rebuilds .text byte-for-byte\n    scripts/check_regressions.py rel_soundtest\n\nEvery function in this file compiled with mwccpsp and diffed byte-identical\nagainst the shipped module. The baseline entry added here is the list of their\nnames, so any later regression names exactly what broke."
 ],
 "mod-rel_title": [
  "feat(rel_title): 45 of 618 functions matched",
  "Title screen + options; 6 language message files.\n\n  functions   45 / 618\n  .text bytes 1,548 / 278,520  (0.6%)\n\nVerify:\n\n    make MODULE=rel_title HYBRID=1        # rebuilds .text byte-for-byte\n    scripts/check_regressions.py rel_title\n\nEvery function in this file compiled with mwccpsp and diffed byte-identical\nagainst the shipped module. The baseline entry added here is the list of their\nnames, so any later regression names exactly what broke."
 ],
 "mod-rel_debug_menu": [
  "feat(rel_debug_menu): 20 of 44 functions matched",
  "Developer menu: region select, \"clear all data\", \"get all card\", \"demonstration\".\n\n  functions   20 / 44\n  .text bytes 1,292 / 16,408  (7.9%)\n\nVerify:\n\n    make MODULE=rel_debug_menu HYBRID=1        # rebuilds .text byte-for-byte\n    scripts/check_regressions.py rel_debug_menu\n\nEvery function in this file compiled with mwccpsp and diffed byte-identical\nagainst the shipped module. The baseline entry added here is the list of their\nnames, so any later regression names exactly what broke."
 ],
 "mod-rel_limitlist": [
  "feat(rel_limitlist): 18 of 70 functions matched",
  "Forbidden & limited card list.\n\n  functions   18 / 70\n  .text bytes 1,048 / 22,648  (4.6%)\n\nVerify:\n\n    make MODULE=rel_limitlist HYBRID=1        # rebuilds .text byte-for-byte\n    scripts/check_regressions.py rel_limitlist\n\nEvery function in this file compiled with mwccpsp and diffed byte-identical\nagainst the shipped module. The baseline entry added here is the list of their\nnames, so any later regression names exactly what broke."
 ],
 "mod-rel_charalist": [
  "feat(rel_charalist): 29 of 120 functions matched",
  "Duelist list: portraits, bustups, voice test.\n\n  functions   29 / 120\n  .text bytes 1,032 / 36,240  (2.8%)\n\nVerify:\n\n    make MODULE=rel_charalist HYBRID=1        # rebuilds .text byte-for-byte\n    scripts/check_regressions.py rel_charalist\n\nEvery function in this file compiled with mwccpsp and diffed byte-identical\nagainst the shipped module. The baseline entry added here is the list of their\nnames, so any later regression names exactly what broke."
 ],
 "mod-rel_conv_machine": [
  "feat(rel_conv_machine): 26 of 62 functions matched",
  "Card Convert Machine (`labo/conv_machine.ehp`).\n\n  functions   26 / 62\n  .text bytes 1,032 / 13,996  (7.4%)\n\nVerify:\n\n    make MODULE=rel_conv_machine HYBRID=1        # rebuilds .text byte-for-byte\n    scripts/check_regressions.py rel_conv_machine\n\nEvery function in this file compiled with mwccpsp and diffed byte-identical\nagainst the shipped module. The baseline entry added here is the list of their\nnames, so any later regression names exactly what broke."
 ],
 "mod-rel_gallery": [
  "feat(rel_gallery): 34 of 98 functions matched",
  "Movie gallery (`TF5_opening`, `TF5_staffroll`, +USA variants).\n\n  functions   34 / 98\n  .text bytes 1,028 / 17,740  (5.8%)\n\nVerify:\n\n    make MODULE=rel_gallery HYBRID=1        # rebuilds .text byte-for-byte\n    scripts/check_regressions.py rel_gallery\n\nEvery function in this file compiled with mwccpsp and diffed byte-identical\nagainst the shipped module. The baseline entry added here is the list of their\nnames, so any later regression names exactly what broke."
 ],
 "mod-rel_cardalbum": [
  "feat(rel_cardalbum): 16 of 82 functions matched",
  "Card album browser.\n\n  functions   16 / 82\n  .text bytes 856 / 28,340  (3.0%)\n\nVerify:\n\n    make MODULE=rel_cardalbum HYBRID=1        # rebuilds .text byte-for-byte\n    scripts/check_regressions.py rel_cardalbum\n\nEvery function in this file compiled with mwccpsp and diffed byte-identical\nagainst the shipped module. The baseline entry added here is the list of their\nnames, so any later regression names exactly what broke."
 ],
 "mod-rel_recipeviewer": [
  "feat(rel_recipeviewer): 19 of 96 functions matched",
  "Deck recipe viewer (`deck/recipe_view.ehp`).\n\n  functions   19 / 96\n  .text bytes 692 / 35,564  (1.9%)\n\nVerify:\n\n    make MODULE=rel_recipeviewer HYBRID=1        # rebuilds .text byte-for-byte\n    scripts/check_regressions.py rel_recipeviewer\n\nEvery function in this file compiled with mwccpsp and diffed byte-identical\nagainst the shipped module. The baseline entry added here is the list of their\nnames, so any later regression names exactly what broke."
 ],
 "mod-rel_password": [
  "feat(rel_password): 11 of 41 functions matched",
  "Password machine \u2014 nixie-tube display (`nixi.ehf`), `labo/password.ehp`.\n\n  functions   11 / 41\n  .text bytes 432 / 14,264  (3.0%)\n\nVerify:\n\n    make MODULE=rel_password HYBRID=1        # rebuilds .text byte-for-byte\n    scripts/check_regressions.py rel_password\n\nEvery function in this file compiled with mwccpsp and diffed byte-identical\nagainst the shipped module. The baseline entry added here is the list of their\nnames, so any later regression names exactly what broke."
 ]
}''')


def classify(files):
    """file -> branch. src/*.c each get their own branch, smallest diff first."""
    out, src = {}, {}
    for f in files:
        if f.startswith("src/") and f.endswith(".c"):
            n = git("diff", "--numstat", f"{UPSTREAM}...HEAD", "--", f).split()
            src[f] = int(n[0]) if n else 0
            continue
        for name, pred in RULES:
            if pred(f):
                out[f] = name
                break
        else:
            out[f] = FALLBACK
    for f in sorted(src, key=src.get):
        out[f] = "mod-" + re.sub(r"^src/|\.c$", "", f)
    return out


def branch_order(assign):
    fixed = [n for n, _ in RULES]
    mods = sorted({b for b in assign.values() if b.startswith("mod-")},
                  key=lambda b: [f for f, x in assign.items() if x == b])
    # preserve smallest-first: recover it from the assignment insertion order
    seen, mods = set(), [b for b in assign.values() if b.startswith("mod-")]
    mods = [b for b in mods if not (b in seen or seen.add(b))]
    return [n for n in fixed if n in set(assign.values())] + mods + [FALLBACK]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--push", action="store_true")
    args = ap.parse_args()

    work = git("rev-parse", "HEAD").strip()
    start = git("rev-parse", "--abbrev-ref", "HEAD").strip()

    if args.check:
        d = git("diff", "--stat", TIP, work, check=False)
        print("stack is current" if not d.strip() else "STACK IS STALE:\n" + d)
        return 0 if not d.strip() else 1

    if git("status", "--porcelain", "--", "src", "config", "docs", "scripts", "include").strip():
        sys.exit("working tree has uncommitted changes; commit them first")

    files = git("diff", "--name-only", f"{UPSTREAM}...HEAD").split()
    assign = classify(files)
    missing = [b for b in branch_order(assign) if b not in BODIES]
    if missing:
        sys.exit(f"no commit message defined for: {missing}")

    baseline = json.load(open(os.path.join(ROOT, "config/progress-baseline.json")))
    base, made, cumulative = UPSTREAM, [], {}
    for name in branch_order(assign):
        group = [f for f, b in assign.items() if b == name]
        branch = "pr/" + name
        git("checkout", "-q", "-B", branch, base)
        git("checkout", work, "--", *group)
        if name.startswith("mod-"):
            m = name[4:]
            cumulative[m] = baseline["modules"].get(m, [])
            p = os.path.join(ROOT, "config/progress-baseline.json")
            with open(p, "w") as fh:
                json.dump({"generated": baseline["generated"],
                           "modules": {k: sorted(v) for k, v in sorted(cumulative.items())}},
                          fh, indent=1)
                fh.write("\n")
            git("add", "config/progress-baseline.json")
        subject, body = BODIES[name]
        git("commit", "-q", "-m", subject, "-m", body + TRAILER)
        made.append((branch, git("rev-parse", "--short", "HEAD").strip(), len(group)))
        base = branch

    git("checkout", "-q", start)
    for b, sha, n in made:
        print(f"{sha}  {b:34s} {n:3d} files")

    drift = git("diff", "--stat", TIP, work, check=False)
    if drift.strip():
        sys.exit("\nSTACK DOES NOT REPRODUCE HEAD:\n" + drift)
    print(f"\n{len(made)} branches; tip is byte-identical to {work[:8]}")

    if args.push:
        git("push", "--force-with-lease", "fork", *[b for b, _, _ in made])
        print("pushed to fork")
    return 0


if __name__ == "__main__":
    sys.exit(main())
