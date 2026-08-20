#!/usr/bin/env bash
# Build every module with HYBRID=1 and report which ones come out byte-exact.
#
# HYBRID=1 compiles the functions we have matched from C and assembles the rest,
# splicing them into one object with tools/mwccgap. It is the only path that can
# ever COMPLETE the 19 modules containing hand-written assembly, because plain
# SRC=1 replaces the whole .text and so requires every function to match.
#
# Runs modules ONE AT A TIME, deliberately. tools/mwccgap hangs under concurrency
# (see the MWCCGAP_TIMEOUT note in the Makefile); the Makefile now serialises the
# mwccgap step with flock anyway, so parallelism here would buy nothing but would
# make a hang harder to attribute.
#
# Usage:
#   scripts/hybrid_sweep.sh                  # all 28 modules
#   scripts/hybrid_sweep.sh rel_labo rel_shop
#
# Environment:
#   MWCCGAP_TIMEOUT   seconds per mwccgap invocation (default 900, from Makefile)
set -uo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$ROOT"

if [ "$#" -gt 0 ]; then
  MODULES=("$@")
else
  mapfile -t MODULES < <(ls iso_extracted/PSP_GAME/USRDIR/gmodule/rel_*.prx \
    | xargs -n1 basename | sed 's/\.prx$//' | sort)
fi

# Refuse to run two sweeps at once. They share build/hybrid/logs and every
# module's object, so a second sweep silently overwrites the first's results
# while the Makefile's flock makes them merely SLOW rather than obviously wrong
# — which is exactly how you end up reading a summary assembled from two runs.
mkdir -p build/hybrid
exec 9>build/hybrid/.sweep.lock
if ! flock -n 9; then
  echo "ERROR: another hybrid sweep is already running (build/hybrid/.sweep.lock)." >&2
  echo "       Wait for it, or kill it, before starting another." >&2
  exit 1
fi

LOG_DIR="build/hybrid/logs"
mkdir -p "$LOG_DIR"

pass=(); fail=(); hung=()

for m in "${MODULES[@]}"; do
  printf '%-22s ' "$m"
  log="$LOG_DIR/$m.log"
  start=$SECONDS
  if make MODULE="$m" HYBRID=1 >"$log" 2>&1; then
    printf 'OK      (%ds)\n' "$((SECONDS - start))"
    pass+=("$m")
  else
    rc=$?
    if grep -q "mwccgap timed out" "$log"; then
      printf 'TIMEOUT (%ds)  %s\n' "$((SECONDS - start))" "$log"
      hung+=("$m")
    else
      printf 'FAIL    (%ds)  %s\n' "$((SECONDS - start))" "$log"
      fail+=("$m")
    fi
  fi
done

echo
echo "byte-exact : ${#pass[@]} / ${#MODULES[@]}"
[ "${#pass[@]}" -gt 0 ] && printf '  OK      %s\n' "${pass[*]}"
[ "${#fail[@]}" -gt 0 ] && printf '  FAIL    %s\n' "${fail[*]}"
[ "${#hung[@]}" -gt 0 ] && printf '  TIMEOUT %s   (retry individually)\n' "${hung[*]}"
exit 0
