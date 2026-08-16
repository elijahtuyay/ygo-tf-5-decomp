#!/usr/bin/env bash
# Compiles one src/*.c against EVERY mwccpsp build installed under tools/ and
# reports, per function, which builds match the target asm.
#
# Purpose: the project's compiler build is not actually pinned. The PRX
# .comment says "MW MIPS C Compiler (2.4.1.01)", which is a different numbering
# scheme from Metrowerks' internal 3.0.1_NNN builds; 219 was confirmed
# SUFFICIENT for 9 functions but never proven UNIQUE (docs/09-first-match.md).
# This harness answers that empirically.
#
# Usage:
#   scripts/mwcc_bisect.sh src/rel_movie_viewer.c asm/rel_movie_viewer/text.s
#   scripts/mwcc_bisect.sh src/rel_movie_viewer.c asm/rel_movie_viewer/text.s -O4,s -sdatathreshold 0
#
# Extra args after the target asm are passed through to mwccpsp as flags.
# Cells: OK = matches | sN = size mismatch, N words off | dN = N differing words
#        x  = failed to compile
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
SRC="${1:?usage: $0 <src/file.c> <asm/<module>/text.s> [mwccpsp flags...]}"
TARGET="${2:?usage: $0 <src/file.c> <asm/<module>/text.s> [mwccpsp flags...]}"
shift 2
FLAGS=("$@")

BUILDS=()
for d in "$ROOT"/tools/mwccpsp_3.0.1_*; do
  [ -f "$d/mwccpsp.exe" ] || continue
  BUILDS+=("$(basename "$d" | sed 's/.*_//')")
done
if [ "${#BUILDS[@]}" -eq 0 ]; then
  echo "ERROR: no mwccpsp builds under tools/. Run scripts/setup_tools.sh." >&2
  exit 1
fi

WORK="$ROOT/build/bisect"
mkdir -p "$WORK"
BASENAME="$(basename "${SRC%.c}")"

echo "source:   $SRC"
echo "target:   $TARGET"
echo "flags:    ${FLAGS[*]:--O4,s -sdatathreshold 0 (default)}"
echo "builds:   ${BUILDS[*]}"
echo

# Per build: compile, diff, and reduce each function's verdict to one token.
for b in "${BUILDS[@]}"; do
  out="$WORK/$b"
  mkdir -p "$out"
  if ! MWCCPSP_BUILD="$b" MWCC_OUT_DIR="$out" \
       "$ROOT/scripts/mwcc_build.sh" "$SRC" "${FLAGS[@]}" >"$out/build.log" 2>&1; then
    echo "build $b: COMPILE FAILED (see $out/build.log)" >&2
    continue
  fi
  "$ROOT/scripts/mwcc_diff.py" "$TARGET" "$out/$BASENAME.o" >"$out/diff.txt" 2>&1 || true
  awk -v b="$b" '
    /^func_[0-9A-F]+: MATCH/         { split($1,f,":"); print f[1], b, "OK";   next }
    /^func_[0-9A-F]+: SIZE MISMATCH/ { split($1,f,":");
                                       t=$4; c=$6; sub(/[^0-9]*/,"",t); sub(/[^0-9]*/,"",c);
                                       d=c-t;
                                       print f[1], b, (d>0 ? "+" d : d);       next }
    /^func_[0-9A-F]+: [0-9]+ diff/   { split($1,f,":"); print f[1], b, "d" $2; next }
    /^func_[0-9A-F]+: NOT COMPILED/  { split($1,f,":"); print f[1], b, "x";    next }
  ' "$out/diff.txt"
done > "$WORK/matrix.raw"

# Pivot into a function x build table.
python3 - "$WORK/matrix.raw" "${BUILDS[@]}" <<'PY'
import sys, collections
raw, builds = sys.argv[1], sys.argv[2:]
cells = collections.defaultdict(dict)
for line in open(raw):
    fn, b, v = line.split()
    cells[fn][b] = v
w = max((len(f) for f in cells), default=8)
print("function".ljust(w), " ".join(b.rjust(5) for b in builds))
print("-" * (w + 6 * len(builds)))
for fn in sorted(cells):
    row = cells[fn]
    print(fn.ljust(w), " ".join(row.get(b, "-").rjust(5) for b in builds))
print()
for b in builds:
    n = sum(1 for fn in cells if cells[fn].get(b) == "OK")
    print(f"build {b}: {n}/{len(cells)} match")
PY
