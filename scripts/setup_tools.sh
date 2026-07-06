#!/usr/bin/env bash
# Configura la toolchain locale per la decomp di Tag Force 5.
# Idempotente: si può rilanciare senza rompere nulla.
#
# NON richiede root per la parte Python. Le dipendenze di sistema (7z, libssl-dev,
# ecc.) vanno installate a parte — vedi docs/03-strumenti.md.
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$ROOT"

echo "==> Progetto: $ROOT"

# 1) virtualenv Python con splat/spimdisasm/rabbitizer
if [ ! -d .venv ]; then
  echo "==> Creo virtualenv .venv"
  python3 -m venv .venv
fi
# shellcheck disable=SC1091
. .venv/bin/activate
python -m pip install --quiet --upgrade pip
echo "==> Installo requirements.txt"
pip install --quiet -r requirements.txt

# 2) tool esterni basati su git (non su PyPI) dentro tools/
mkdir -p tools
clone_or_pull() {  # $1 = url, $2 = dir
  if [ -d "tools/$2/.git" ]; then
    echo "==> Aggiorno tools/$2"
    git -C "tools/$2" pull --ff-only --quiet || true
  else
    echo "==> Clono tools/$2"
    git clone --depth 1 "$1" "tools/$2"
  fi
}
clone_or_pull https://github.com/simonlindholm/asm-differ       asm-differ
clone_or_pull https://github.com/matt-kempster/m2c              m2c
clone_or_pull https://github.com/simonlindholm/decomp-permuter  decomp-permuter
# pspdecrypt: per decifrare l'EBOOT da CLI (serve libssl-dev per compilarlo)
clone_or_pull https://github.com/John-K/pspdecrypt              pspdecrypt

# dipendenze python dei tool clonati
pip install --quiet -r tools/asm-differ/requirements.txt 2>/dev/null || true
pip install --quiet -r tools/m2c/requirements.txt        2>/dev/null || true

echo
echo "==> Fatto. Versioni installate:"
python - <<'PY'
import importlib.metadata as m
for p in ("splat64","spimdisasm","rabbitizer"):
    try: print(f"   {p}: {m.version(p)}")
    except Exception: print(f"   {p}: NON installato")
PY
echo "   tools/: $(ls tools 2>/dev/null | tr '\n' ' ')"
echo
echo "Ricorda: 'source .venv/bin/activate' prima di usare i tool."
echo "Per compilare pspdecrypt:  (sudo apt install libssl-dev)  &&  make -C tools/pspdecrypt"
