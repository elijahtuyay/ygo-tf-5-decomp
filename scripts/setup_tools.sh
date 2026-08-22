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

# psplibdoc: the pspdev community's Sony NID database (~6300 NID -> name pairs,
# CSV: lib,fun|var,NID,name,status). scripts/eboot_signatures.py uses it to name
# the engine's SDK imports — it resolves 314 of modehsys's 339 imports (93%),
# where PPSSPP's HLE tables alone managed 39. Large clone (~226 MB), shallow.
clone_or_pull https://github.com/pspdev/psplibdoc                psplibdoc

# Python dependencies of the cloned tools
pip install --quiet -r tools/asm-differ/requirements.txt 2>/dev/null || true
pip install --quiet -r tools/m2c/requirements.txt        2>/dev/null || true

# 3) wibo (runs the Windows mwccpsp.exe on Linux) + mwccpsp_3.0.1_219 itself.
# Both come from decompals/wibo and decompme/compilers releases: real binaries,
# not built from anything in this repo, so they live under tools/ (gitignored)
# like everything else in this section.
WIBO_VERSION=1.1.0
if [ ! -x tools/wibo-bin/wibo ]; then
  echo "==> Downloading wibo $WIBO_VERSION"
  mkdir -p tools/wibo-bin
  curl -sL -o tools/wibo-bin/wibo \
    "https://github.com/decompals/wibo/releases/download/${WIBO_VERSION}/wibo-x86_64"
  chmod +x tools/wibo-bin/wibo
fi
if [ ! -f tools/mwccpsp_3.0.1_219/mwccpsp.exe ]; then
  echo "==> Downloading mwccpsp_3.0.1_219 (from decompme/compilers releases)"
  mkdir -p tools/mwccpsp_3.0.1_219
  curl -sL -o /tmp/mwccpsp_3.0.1_219.tar.gz \
    "https://github.com/decompme/compilers/releases/download/compilers/mwccpsp_3.0.1_219.tar.gz"
  tar xzf /tmp/mwccpsp_3.0.1_219.tar.gz -C tools/mwccpsp_3.0.1_219
  rm /tmp/mwccpsp_3.0.1_219.tar.gz
  chmod +x tools/mwccpsp_3.0.1_219/mwccpsp.exe
fi

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
