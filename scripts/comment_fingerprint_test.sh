#!/usr/bin/env bash
# Is a Metrowerks binary's .comment string evidence of which COMPILER built it?
#
# No. This reproduces the experiment recorded in docs/17: the Metrowerks linker
# writes .comment itself and ignores what its input objects carry, so the
# shipped TF5 modules' "MW MIPS C Compiler (2.4.1.01)" identifies the LINKER,
# not the compiler — and cannot be used to reject a candidate compiler.
#
# The clinching case is the last one: BOTH objects are compiled by 2.3.1.01 and
# the linked output still claims 2.4.1.01.
#
# Caveat, repeated from docs/17: this uses mwldps2, because no mwldpsp exists in
# this repo. See the caveats section there.
set -uo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$ROOT"
W="$ROOT/tools/wibo-bin/wibo"
OLD=tools/mwcps2-2.3.3-000906     # stamps 2.3.1.01
NEW=tools/mwcps2-2.4-001213       # stamps 2.4.1.01

for d in "$W" "$OLD/mwccps2.exe" "$NEW/mwccps2.exe"; do
  [ -e "$d" ] || { echo "ERROR: missing $d (run scripts/setup_tools.sh)" >&2; exit 1; }
done

T=$(mktemp -d); trap 'rm -rf "$T"' EXIT
printf 'int a_fn(int x){return x+1;}\n'                        > "$T/a.c"
printf 'extern int a_fn(int);\nint __start(void){return a_fn(2);}\n' > "$T/b.c"

compile() { # <compiler-dir> <src> <out>
  (cd "$1" && "$W" ./mwccps2.exe -c -o "$T/$3" "$T/$2") >/dev/null 2>&1
}
stamp() { readelf -p .comment "$1" 2>/dev/null | sed -n 's/^  \[ *[0-9a-f]*\]  //p' | paste -sd' + '; }

compile "$OLD" a.c a_old.o; compile "$NEW" a.c a_new.o
compile "$OLD" b.c b_old.o; compile "$NEW" b.c b_new.o

echo "OBJECTS (what the compiler itself stamps — this part IS diagnostic)"
printf '  a_old.o  %s\n  a_new.o  %s\n' "$(stamp "$T/a_old.o")" "$(stamp "$T/a_new.o")"

link() { # <label> <linker-dir> <obj> <obj>
  (cd "$2" && "$W" ./mwldps2.exe -o "$T/out.elf" "$T/$3" "$T/$4") >/dev/null 2>&1
  printf '  %-46s %s\n' "$1" "$(stamp "$T/out.elf")"
}

echo
echo "LINKED (what the linker writes — this part is NOT diagnostic)"
link "linker 2.4  <- 2.3.1.01 + 2.4.1.01"   "$NEW" a_old.o b_new.o
link "linker 2.3.3 <- 2.3.1.01 + 2.4.1.01"  "$OLD" a_old.o b_new.o
link "linker 2.4  <- reversed order"        "$NEW" a_new.o b_old.o
link "linker 2.4  <- 2.3.1.01 + 2.3.1.01 *" "$NEW" a_old.o b_old.o
link "linker 2.3.3 <- 2.3.1.01 + 2.3.1.01 *" "$OLD" a_old.o b_old.o
echo "  * every input object is 2.3.1.01, yet the output claims 2.4.1.01"

echo
echo "CONTRAST: GNU ld on the same mixed pair merges BOTH strings"
mips-linux-gnu-ld -EL -r -o "$T/gnu.o" "$T/a_old.o" "$T/b_new.o" 2>/dev/null
printf '  %-46s %s\n' "GNU ld -r" "$(stamp "$T/gnu.o")"

echo
echo "SHIPPED TF5 MODULE (a linker stamp, therefore says nothing about mwccpsp)"
printf '  %-46s %s\n' "rel_movie_viewer.prx" \
  "$(stamp iso_extracted/PSP_GAME/USRDIR/gmodule/rel_movie_viewer.prx)"
