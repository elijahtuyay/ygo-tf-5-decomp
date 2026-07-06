#!/usr/bin/env bash
# Sets up the local toolchain for the Tag Force 5 decompilation.
# Idempotent: safe to re-run without breaking anything.
#
# Does NOT require root for the Python part. System dependencies (7z, libssl-dev,
# etc.) must be installed separately — see docs/03-tools.md.
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$ROOT"

echo "==> Project: $ROOT"

# 1) Python virtualenv with splat/spimdisasm/rabbitizer
if [ ! -d .venv ]; then
  echo "==> Creating virtualenv .venv"
  python3 -m venv .venv
fi
# shellcheck disable=SC1091
. .venv/bin/activate
python -m pip install --quiet --upgrade pip
echo "==> Installing requirements.txt"
pip install --quiet -r requirements.txt

# 2) External git-based tools (not on PyPI) inside tools/
mkdir -p tools
clone_or_pull() {  # $1 = url, $2 = dir
  if [ -d "tools/$2/.git" ]; then
    echo "==> Updating tools/$2"
    git -C "tools/$2" pull --ff-only --quiet || true
  else
    echo "==> Cloning tools/$2"
    git clone --depth 1 "$1" "tools/$2"
  fi
}
clone_or_pull https://github.com/simonlindholm/asm-differ       asm-differ
clone_or_pull https://github.com/matt-kempster/m2c              m2c
clone_or_pull https://github.com/simonlindholm/decomp-permuter  decomp-permuter
# pspdecrypt: to decrypt the EBOOT from the CLI (requires libssl-dev to build)
clone_or_pull https://github.com/John-K/pspdecrypt              pspdecrypt

# Python dependencies of the cloned tools
pip install --quiet -r tools/asm-differ/requirements.txt 2>/dev/null || true
pip install --quiet -r tools/m2c/requirements.txt        2>/dev/null || true

echo
echo "==> Done. Installed versions:"
python - <<'PY'
import importlib.metadata as m
for p in ("splat64","spimdisasm","rabbitizer"):
    try: print(f"   {p}: {m.version(p)}")
    except Exception: print(f"   {p}: NOT installed")
PY
echo "   tools/: $(ls tools 2>/dev/null | tr '\n' ' ')"
echo
echo "Remember: run 'source .venv/bin/activate' before using the tools."
echo "To build pspdecrypt:  (sudo apt install libssl-dev)  &&  make -C tools/pspdecrypt"
