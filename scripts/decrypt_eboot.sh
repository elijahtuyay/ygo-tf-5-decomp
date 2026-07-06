#!/usr/bin/env bash
# Decifra PSP_GAME/SYSDIR/EBOOT.BIN (header ~PSP) producendo l'ELF in chiaro
# in build/EBOOT.elf, e ne stampa lo sha1 (target della build matching).
#
# Richiede pspdecrypt compilato: vedi scripts/setup_tools.sh + libssl-dev.
# In alternativa si può ottenere l'EBOOT decifrato da PPSSPP: vedi
# docs/04-estrazione-e-decrypt.md.
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$ROOT"

EBOOT="iso_extracted/PSP_GAME/SYSDIR/EBOOT.BIN"
DEC="tools/pspdecrypt/pspdecrypt"
OUT="build"

[ -f "$EBOOT" ] || { echo "ERRORE: $EBOOT non trovato. Lancia prima scripts/extract_iso.sh" >&2; exit 1; }
mkdir -p "$OUT"

if [ ! -x "$DEC" ]; then
  echo "ERRORE: pspdecrypt non compilato ($DEC)." >&2
  echo "  Compilalo con:  sudo apt install libssl-dev  &&  make -C tools/pspdecrypt" >&2
  echo "  Oppure dumpa l'EBOOT decifrato con PPSSPP (docs/04-estrazione-e-decrypt.md)." >&2
  exit 1
fi

echo "==> Decifro $EBOOT"
# pspdecrypt scrive l'output accanto all'input o su path indicato; -e = decripta eboot
"$DEC" "$EBOOT" -o "$OUT/EBOOT.elf"

echo "==> ELF in chiaro: $OUT/EBOOT.elf"
file "$OUT/EBOOT.elf" 2>/dev/null || true
echo "==> sha1 (target di verifica del match):"
sha1sum "$OUT/EBOOT.elf"
