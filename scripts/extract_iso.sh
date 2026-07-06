#!/usr/bin/env bash
# Extracts the UMD ISO into iso_extracted/.
# Usage:  scripts/extract_iso.sh [path/to.iso]
# If the path is omitted, looks for the first .iso under the project folder.
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$ROOT"

ISO="${1:-}"
if [ -z "$ISO" ]; then
  ISO="$(find . -maxdepth 3 -iname '*.iso' | head -n1 || true)"
fi
if [ -z "$ISO" ] || [ ! -f "$ISO" ]; then
  echo "ERROR: ISO not found. Pass it as an argument: scripts/extract_iso.sh game.iso" >&2
  exit 1
fi

OUT="iso_extracted"
echo "==> ISO:    $ISO"
echo "==> Output: $OUT/"
mkdir -p "$OUT"

if command -v 7z >/dev/null 2>&1; then
  7z x -y -o"$OUT" "$ISO" >/dev/null
else
  echo "ERROR: 7z is required (sudo apt install p7zip-full)." >&2
  exit 1
fi

echo "==> Extraction complete. Main contents:"
find "$OUT/PSP_GAME/SYSDIR" "$OUT/PSP_GAME/USRDIR/gmodule" -maxdepth 1 -type f 2>/dev/null | sort | sed 's/^/   /'

echo
echo "Next step: decrypt the EBOOT ->  scripts/decrypt_eboot.sh"
