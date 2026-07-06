#!/usr/bin/env bash
# Estrae la ISO UMD in iso_extracted/.
# Uso:  scripts/extract_iso.sh [percorso/della.iso]
# Se il percorso è omesso, cerca la prima .iso sotto la cartella del progetto.
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$ROOT"

ISO="${1:-}"
if [ -z "$ISO" ]; then
  ISO="$(find . -maxdepth 3 -iname '*.iso' | head -n1 || true)"
fi
if [ -z "$ISO" ] || [ ! -f "$ISO" ]; then
  echo "ERRORE: ISO non trovata. Passala come argomento: scripts/extract_iso.sh gioco.iso" >&2
  exit 1
fi

OUT="iso_extracted"
echo "==> ISO:    $ISO"
echo "==> Output: $OUT/"
mkdir -p "$OUT"

if command -v 7z >/dev/null 2>&1; then
  7z x -y -o"$OUT" "$ISO" >/dev/null
else
  echo "ERRORE: serve 7z (sudo apt install p7zip-full)." >&2
  exit 1
fi

echo "==> Estrazione completata. Contenuto principale:"
find "$OUT/PSP_GAME/SYSDIR" "$OUT/PSP_GAME/USRDIR/gmodule" -maxdepth 1 -type f 2>/dev/null | sort | sed 's/^/   /'

echo
echo "Prossimo passo: decifrare l'EBOOT ->  scripts/decrypt_eboot.sh"
