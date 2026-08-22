#!/usr/bin/env bash
# Compiles a src/*.c file with the real target compiler (mwccpsp, via wibo)
# and produces a relocatable .o next to it in build/mwcc/, ready to be
# objdumped and compared against the target asm (see docs/06 "local matching").
#
# Usage:
#   scripts/mwcc_build.sh src/rel_movie_viewer.c
#   scripts/mwcc_build.sh src/rel_movie_viewer.c -O4,p -sdatathreshold 0   # override flags
#
# Requirements: tools/wibo-bin/wibo + tools/mwccpsp_3.0.1_219/mwccpsp.exe
# (both fetched by scripts/setup_tools.sh).
#
# Environment overrides (used by scripts/mwcc_bisect.sh):
#   MWCCPSP_BUILD  compiler build number to use     (default: 219)
#   MWCC_OUT_DIR   directory to write the .o into   (default: build/mwcc)
# Without these the bisect harness silently compiles every build with 219 and
# re-diffs whatever .o files are already lying in its output dirs.
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
WIBO="$ROOT/tools/wibo-bin/wibo"
MWCC="$ROOT/tools/mwccpsp_3.0.1_${MWCCPSP_BUILD:-219}/mwccpsp.exe"

if [ ! -x "$WIBO" ] || [ ! -f "$MWCC" ]; then
  echo "ERROR: wibo/mwccpsp not found ($MWCC). Run scripts/setup_tools.sh first." >&2
  exit 1
fi

SRC="${1:?usage: $0 <src/file.c> [mwccpsp flags...]}"
shift || true
FLAGS=("$@")
if [ "${#FLAGS[@]}" -eq 0 ]; then
  FLAGS=(-O4,s -sdatathreshold 0)
fi

BASENAME="$(basename "${SRC%.c}")"
OUT_DIR="${MWCC_OUT_DIR:-$ROOT/build/mwcc}"
mkdir -p "$OUT_DIR"
cp "$SRC" "$OUT_DIR/$BASENAME.c"

( cd "$OUT_DIR" && "$WIBO" "$MWCC" -c "${FLAGS[@]}" -o "$BASENAME.o" "$BASENAME.c" )

echo "==> Built $OUT_DIR/$BASENAME.o"
echo "    Inspect with:  mips-linux-gnu-objdump -dr $OUT_DIR/$BASENAME.o"
echo "    Or compare a function: scripts/mwcc_diff.py asm/<module>/text.s $OUT_DIR/$BASENAME.o func_XXXXXXXX"
