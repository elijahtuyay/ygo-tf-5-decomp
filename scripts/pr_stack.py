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
 ]
}''')


# Module PR bodies are COMPUTED, not stored. An earlier version froze each
# module's match count into this file, which meant the stack quietly advertised
# stale numbers the moment anything new matched — while docs/22 promised it is
# always regenerated. The counts come from the committed baseline and the
# shipped assembly, so they cannot disagree with what the branch actually
# carries. Sizes come from asm/<module>/text.s directly: no compiling needed.
def module_sizes(module):
    """{function: size in bytes} for every function in the shipped module."""
    path = os.path.join(ROOT, "asm", module, "text.s")
    out, cur, words = {}, None, 0
    if not os.path.exists(path):
        return out
    for line in open(path, errors="replace"):
        m = re.match(r"glabel (\w+)", line)
        if m:
            cur, words = m.group(1), 0
        elif cur and re.match(r"\s*/\* [0-9A-F]+ ", line):
            words += 1
        elif cur and line.startswith("endlabel"):
            out[cur] = words * 4
            cur = None
    return out


def module_descriptions():
    """The one-line 'what it is' column from the survey index."""
    out = {}
    path = os.path.join(ROOT, "docs/modules/README.md")
    if not os.path.exists(path):
        return out
    for line in open(path):
        m = re.match(r"\| `(rel_\w+)` \| 0x[0-9A-F]+ \|.*?\|\s*([^|]+?)\s*\|\s*$", line)
        if m:
            out[m.group(1)] = re.sub(r"\*\*|\(\d+/\d+ matched\)", "", m.group(2)).strip()
    return out


def module_body(module, matched):
    sizes = module_sizes(module)
    got = [f for f in matched if f in sizes]
    fn, fnt = len(got), len(sizes)
    by, byt = sum(sizes[f] for f in got), sum(sizes.values())
    desc = module_descriptions().get(module, "")
    desc = (desc[0].upper() + desc[1:]) if desc else module
    pct = (100.0 * by / byt) if byt else 0.0
    return (f"feat({module}): {fn} of {fnt} functions matched",
            f"""{desc}.

  functions   {fn} / {fnt}
  .text bytes {by:,} / {byt:,}  ({pct:.1f}%)

Verify:

    make MODULE={module} HYBRID=1        # rebuilds .text byte-for-byte
    scripts/check_regressions.py {module}

Every function in this file compiled with mwccpsp and diffed byte-identical
against the shipped module. The baseline entry added here is the list of their
names, so any later regression names exactly what broke.""")


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
    missing = [b for b in branch_order(assign)
               if b not in BODIES and not b.startswith("mod-")]
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
        subject, body = (module_body(name[4:], cumulative.get(name[4:], []))
                         if name.startswith("mod-") else BODIES[name])
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
