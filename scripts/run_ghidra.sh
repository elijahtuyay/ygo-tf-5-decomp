#!/usr/bin/env bash
# Launches Ghidra for analyzing the Tag Force 5 binaries.
#
# Usage:
#   scripts/run_ghidra.sh                 # opens Ghidra (in the background)
#   scripts/run_ghidra.sh <project.gpr>   # opens a specific Ghidra project
#   GHIDRA_HOME=/path/to/ghidra scripts/run_ghidra.sh   # forces the Ghidra path
#
# Requirements: Ghidra 12.0.x + JDK 21 + ghidra-allegrex extension
# (installation: docs/03-tools.md §4).
set -euo pipefail

# --- 1) Locate the Ghidra installation -------------------------------------
find_ghidra() {
  # a) explicit environment variable
  if [ -n "${GHIDRA_HOME:-}" ] && [ -x "$GHIDRA_HOME/ghidraRun" ]; then
    echo "$GHIDRA_HOME"; return 0
  fi
  # b) ghidra_*_PUBLIC folders in the home dir (picks the most recent)
  local cand
  cand=$(ls -d "$HOME"/ghidra_*_PUBLIC 2>/dev/null | sort -V | tail -n1 || true)
  if [ -n "$cand" ] && [ -x "$cand/ghidraRun" ]; then
    echo "$cand"; return 0
  fi
  # c) search common locations
  cand=$(find "$HOME" /opt -maxdepth 4 -name ghidraRun -type f 2>/dev/null | head -n1 || true)
  if [ -n "$cand" ]; then dirname "$cand"; return 0; fi
  return 1
}

GHIDRA_DIR="$(find_ghidra || true)"
if [ -z "$GHIDRA_DIR" ]; then
  echo "ERROR: Ghidra not found." >&2
  echo "  Install it (Ghidra 12.0) as described in docs/03-tools.md §4," >&2
  echo "  or specify the path:  GHIDRA_HOME=/path/to/ghidra $0" >&2
  exit 1
fi
echo "==> Ghidra: $GHIDRA_DIR"

# --- 2) Ensure a JDK 21 -------------------------------------------------------
pick_jdk21() {
  # if JAVA_HOME is already a JDK 21, keep it
  if [ -n "${JAVA_HOME:-}" ] && "$JAVA_HOME/bin/java" -version 2>&1 | grep -q '"21'; then
    echo "$JAVA_HOME"; return 0
  fi
  local c
  for c in /usr/lib/jvm/java-21-openjdk-amd64 /usr/lib/jvm/openjdk-21 "$HOME/android-studio/jbr"; do
    if [ -x "$c/bin/java" ] && "$c/bin/java" -version 2>&1 | grep -q '"21'; then
      echo "$c"; return 0
    fi
  done
  # fallback: the system java, if it's version 21
  if command -v java >/dev/null 2>&1 && java -version 2>&1 | grep -q '"21'; then
    echo ""; return 0   # empty string = use the java on PATH
  fi
  return 1
}

if JDK="$(pick_jdk21)"; then
  if [ -n "$JDK" ]; then export JAVA_HOME="$JDK"; echo "==> JAVA_HOME: $JAVA_HOME"; else
    echo "==> Java 21 from PATH ($(command -v java))"; fi
else
  echo "WARNING: no JDK 21 detected. Ghidra 12 requires it." >&2
  echo "        Install it with:  sudo apt install openjdk-21-jdk" >&2
fi

# --- 3) Check for the ghidra-allegrex extension (warning only) ----------------------
GHIDRA_VER="$(basename "$GHIDRA_DIR")"
if ! find "$HOME/.config/ghidra/$GHIDRA_VER/Extensions" "$GHIDRA_DIR/Ghidra/Extensions" \
        -maxdepth 2 -iname '*allegrex*' 2>/dev/null | grep -q .; then
  echo "WARNING: ghidra-allegrex extension not detected." >&2
  echo "        Without it there's no Allegrex/VFPU support or PSP relocations." >&2
  echo "        In Ghidra: File > Install Extensions > (+) > select the zip" >&2
  echo "        ghidra_${GHIDRA_VER#ghidra_}_ghidra-allegrex.zip (see docs/03 §4)." >&2
fi

# --- 4) Launch (in the background, terminal stays free) ----------------------------------
LOG="${TMPDIR:-/tmp}/ghidra_run.log"
echo "==> Starting Ghidra (log: $LOG)"
# nohup + & : Ghidra survives the terminal closing, which stays free for other use.
nohup "$GHIDRA_DIR/ghidraRun" "$@" >"$LOG" 2>&1 &
GHIDRA_PID=$!
echo "==> Ghidra started (PID $GHIDRA_PID). The first launch may take a few seconds."
