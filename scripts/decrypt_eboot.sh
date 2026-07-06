#!/usr/bin/env bash
# Decrypts PSP_GAME/SYSDIR/EBOOT.BIN (header ~PSP), producing the plain ELF
# at build/EBOOT.elf, and prints its sha1 (the target of the matching build).
#
# Requires a compiled pspdecrypt: see scripts/setup_tools.sh + libssl-dev.
# Alternatively, the decrypted EBOOT can be obtained from PPSSPP: see
# docs/04-extraction-and-decryption.md.
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$ROOT"

EBOOT="iso_extracted/PSP_GAME/SYSDIR/EBOOT.BIN"
DEC="tools/pspdecrypt/pspdecrypt"
OUT="build"

[ -f "$EBOOT" ] || { echo "ERROR: $EBOOT not found. Run scripts/extract_iso.sh first" >&2; exit 1; }
mkdir -p "$OUT"

if [ ! -x "$DEC" ]; then
  echo "ERROR: pspdecrypt not built ($DEC)." >&2
  echo "  Build it with:  sudo apt install libssl-dev  &&  make -C tools/pspdecrypt" >&2
  echo "  Or dump the decrypted EBOOT with PPSSPP (docs/04-extraction-and-decryption.md)." >&2
  exit 1
fi

echo "==> Decrypting $EBOOT"
# pspdecrypt writes the output next to the input or to the given path; -e = decrypt eboot
"$DEC" "$EBOOT" -o "$OUT/EBOOT.elf"

echo "==> Plain ELF: $OUT/EBOOT.elf"
file "$OUT/EBOOT.elf" 2>/dev/null || true
echo "==> sha1 (match verification target):"
sha1sum "$OUT/EBOOT.elf"
