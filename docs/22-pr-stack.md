# The PR stack: 209 commits, reshaped for piecemeal review

Upstream (`angelof-exe/ygo-tf-5-decomp`) is at PR #2 merged and has not moved.
Our working branch is 209 commits / 225 files / +124,881 lines ahead of it. That
is unreviewable as one pull request, and reviewing it is the only thing standing
between this work and upstream.

So the same content is also published as a stack of **35 branches**, each one
small enough to read in a sitting and each making a single claim that can be
checked. The tip of the stack is byte-identical to the working branch — the
stack is a *view* of the work, not a fork of it.

## How it is arranged

Branches are **stacked**: each is based on the one above it, so each diff shows
only its own change. Layers 01-06 are the foundation a reviewer reads once.
Everything after is one module per PR, smallest first, forever.

| branch | files | subject |
|---|---:|---|
| `pr/01-survey-all-modules` | 61 | feat(split): section-accurate splat configs for all 28 rel_*.prx modules |
| `pr/02-nid-resolution` | 67 | feat(nids): resolve the shared import table once, for all 28 modules |
| `pr/03-headers-and-types` | 32 | feat(include): generated engine and per-module declarations |
| `pr/04-build-and-verification` | 11 | feat(build): the matching build, and the two gates that keep it honest |
| `pr/05-matching-pipeline` | 16 | feat(pipeline): automated draft-and-verify, and the levers behind it |
| `pr/06-compiler-identification` | 3 | docs(compiler): .comment identifies the LINKER, not the compiler |
| `pr/mod-rel_password` | 1 | feat(rel_password): 11 of 41 functions matched |
| `pr/mod-rel_movie_viewer` | 1 | feat(rel_movie_viewer): 15 of 16 functions matched |
| `pr/mod-rel_recipeviewer` | 1 | feat(rel_recipeviewer): 19 of 96 functions matched |
| `pr/mod-rel_cardalbum` | 1 | feat(rel_cardalbum): 16 of 82 functions matched |
| `pr/mod-rel_limitlist` | 1 | feat(rel_limitlist): 18 of 70 functions matched |
| `pr/mod-rel_labo` | 1 | feat(rel_labo): 12 of 14 functions matched |
| `pr/mod-rel_soundtest` | 1 | feat(rel_soundtest): 9 of 12 functions matched |
| `pr/mod-rel_gallery` | 1 | feat(rel_gallery): 34 of 98 functions matched |
| `pr/mod-rel_charalist` | 1 | feat(rel_charalist): 29 of 120 functions matched |
| `pr/mod-rel_debug_menu` | 1 | feat(rel_debug_menu): 20 of 44 functions matched |
| `pr/mod-rel_conv_machine` | 1 | feat(rel_conv_machine): 26 of 62 functions matched |
| `pr/mod-rel_umd_replace` | 1 | feat(rel_umd_replace): 33 of 76 functions matched |
| `pr/mod-rel_duelrecord` | 1 | feat(rel_duelrecord): 22 of 47 functions matched |
| `pr/mod-rel_title` | 1 | feat(rel_title): 45 of 618 functions matched |
| `pr/mod-rel_html_view` | 1 | feat(rel_html_view): 15 of 16 functions matched |
| `pr/mod-rel_tutoriallist` | 1 | feat(rel_tutoriallist): 22 of 31 functions matched |
| `pr/mod-rel_duel_mgr` | 1 | feat(rel_duel_mgr): 54 of 228 functions matched |
| `pr/mod-rel_shop` | 1 | feat(rel_shop): 71 of 254 functions matched |
| `pr/mod-rel_select_card` | 1 | feat(rel_select_card): 64 of 248 functions matched |
| `pr/mod-rel_tutorial` | 1 | feat(rel_tutorial): 98 of 190 functions matched |
| `pr/mod-rel_deckswap` | 1 | feat(rel_deckswap): 61 of 245 functions matched |
| `pr/mod-rel_deck` | 1 | feat(rel_deck): 101 of 404 functions matched |
| `pr/mod-rel_decktutorial` | 1 | feat(rel_decktutorial): 87 of 354 functions matched |
| `pr/mod-rel_cutin_viewer` | 1 | feat(rel_cutin_viewer): 124 of 314 functions matched |
| `pr/mod-rel_field` | 1 | feat(rel_field): 317 of 730 functions matched |
| `pr/mod-rel_story` | 1 | feat(rel_story): 333 of 640 functions matched |
| `pr/mod-rel_duel_draw` | 1 | feat(rel_duel_draw): 650 of 1546 functions matched |
| `pr/mod-rel_duel_eng` | 1 | feat(rel_duel_eng): 1497 of 7487 functions matched |
| `pr/99-engineering-log` | 7 | docs: the working session log |

## Opening them

Nothing is open upstream yet, deliberately — dropping 35 pull requests on a
dormant repository reads as pressure, not contribution. All 35 branches are
pushed to the fork and ready, so opening one is a single command:

    gh pr create --repo angelof-exe/ygo-tf-5-decomp \
        --base main --head elijahtuyay:pr/01-survey-all-modules

Open them **in order**, and only as fast as they are being reviewed. Each PR
after the first should be retargeted to `main` once its parent merges; until
then GitHub will show the parent's commits in the diff, which is why the order
matters.

PR #4 (`rel_movie_viewer`: name all imports from resolved NIDs) is already open
and is a subset of `pr/02-nid-resolution`. Close it in favour of 02, or let it
merge first — either works, but do not review both.

## Keeping it fresh

The stack is regenerated, never edited by hand. Work continues on
`eboot/engine-survey`; when the stack needs to catch up, rebuild it from the
current tip. The invariant that makes it trustworthy is one command:

    git diff --stat pr/99-engineering-log eboot/engine-survey   # must be empty

If that is not empty, the stack is lying about what we have.

## What a reviewer is being asked to trust

Each module PR carries its own entry in `config/progress-baseline.json` — the
list of matched function *names*, not a count — so every claim in the stack is
checkable from that branch alone:

    make MODULE=<name> HYBRID=1          # .text rebuilt byte-for-byte
    scripts/check_regressions.py <name>  # recompiles and re-diffs every function

Current state: **3,803 of 14,083 functions matched, 3.16% of `.text` by bytes**,
and all 28 modules rebuild byte-exactly.
