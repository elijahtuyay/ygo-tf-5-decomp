# Rebuild a gmodule PRX and verify it against checksums.sha1.
#
#   make MODULE=rel_html_view            # build from asm, verify the sha1
#   make MODULE=rel_html_view SRC=1      # build with src/<module>.c instead of
#                                        # asm/<module>/text.s, verify the sha1
#   make MODULE=rel_html_view clean
#
# WHAT "VERIFIED" MEANS HERE. The splat config covers 100% of the file, split
# into code (asm/) and non-code blobs (assets/: ELF header, import/export
# tables, the NID table, .data, and the ELF metadata trailer). This build
# assembles/compiles the CODE, links it with those blobs at their real file
# offsets, flattens the result and compares the sha1 of the whole file against
# checksums.sha1. So a PASS proves the code we produce is byte-identical and
# that the config's layout is exact; the non-code blobs are carried over
# verbatim, as the config declares them, and are not reconstructed.
#
# SRC=1 is the one that proves the decompilation: it swaps our compiled C in for
# the disassembly, so it only passes when EVERY function in the module matches.
# Until then it fails at the first differing byte, which is exactly the signal
# you want. For rel_html_view today it builds to the correct 26900 bytes and
# differs at byte 1481 (vram 0x574) — the one instruction func_00000470
# schedules differently. Every other byte of the module, all 15 other functions
# and the jump table included, is identical.
#
# HYBRID=1 is what a module is actually finished against. It compiles every
# function we have matched and assembles the rest, splicing them into one object
# with tools/mwccgap. SRC=1 cannot be the bar: 248 functions across 19 modules
# are hand-written assembly and can never come from C, so for those modules
# SRC=1 is unreachable by construction.
#
# Definition of done for a module: `make MODULE=<name> HYBRID=1` prints OK.
# All 28 do, as of 2026-08-20 — see scripts/hybrid_sweep.sh and docs/21. That
# proves the layout, symbols and relocations are right and that the .text is
# reconstructed byte-for-byte. It does NOT mean a module is decompiled: only a
# few percent of .text currently comes from C, and the rest is carried assembly.
#
# Use SRC=1 to test how much of a module genuinely compiles from C.

MODULE  ?= rel_html_view
SRC     ?=

ROOT    := $(CURDIR)
PRX     := iso_extracted/PSP_GAME/USRDIR/gmodule/$(MODULE).prx
LD      := build/$(MODULE).ld
# SRC and non-SRC builds MUST NOT share output paths: they have different
# prerequisites, so sharing lets a mode switch verify a stale binary from the
# other mode (both a false FAIL and a false PASS are possible — seen 2026-08-18).

# HYBRID=1: build the module from our C for the functions we have matched, and
# from ASSEMBLY for everything else, spliced into one object by tools/mwccgap.
# This is what lets a module be COMPLETED at all: plain SRC=1 replaces the whole
# .text, so a module only passes once every function matches — impossible for
# the 19 modules containing hand-written assembly, which can never come from C.
ifeq ($(HYBRID),1)
  SRC := 1
  MWOBJ := build/hybrid/$(MODULE).o
else
  MWOBJ := build/mwcc/$(MODULE).o
endif

ifeq ($(SRC),1)
  OUT   := build/$(MODULE).src.elf
  BIN   := build/$(MODULE).src.prx
else
  OUT   := build/$(MODULE).elf
  BIN   := build/$(MODULE).prx
endif

CROSS   := mips-linux-gnu-
AS      := $(CROSS)as
LDD     := $(CROSS)ld
OBJCOPY := $(CROSS)objcopy
# --no-pad-sections + explicit section alignments. gas otherwise rounds .text up
# to 16 and marks it 2**4 (padding before the stub section, shifting every jal
# target), and emits EMPTY .data/.bss sections aligned to 16 — which the linker
# script pulls in before the data blobs, so the location counter gets aligned and
# everything after .text shifts. rel_html_view hid both because its .text happens
# to be a multiple of 16.
ASFLAGS := -march=mips32r2 -mabi=32 -EL --no-pad-sections -I include -I asm/$(MODULE)

ASM_SRCS   := $(wildcard asm/$(MODULE)/*.s)
ASM_OBJS   := $(patsubst asm/$(MODULE)/%.s,build/asm/$(MODULE)/%.s.o,$(ASM_SRCS))
ASSET_SRCS := $(wildcard assets/$(MODULE)/*.bin)
ASSET_OBJS := $(patsubst assets/$(MODULE)/%.bin,build/assets/$(MODULE)/%.bin.o,$(ASSET_SRCS))

.DEFAULT_GOAL := all

# Symbols our object references that nothing defines: D_XXXXXXXX / jtbl_XXXXXXXX
# globals the ORIGINAL bakes as absolute constants with no relocation, so splat
# never emitted a name for them (see KNOWN_ADDR in scripts/mwcc_diff.py). Their
# address is encoded in the name, which is what makes this safe to automate.
#
# .LXXXXXXXX joins them under HYBRID=1. Splitting .text into one .s per function
# leaves any reference that crosses a function boundary dangling, since gas keeps
# `.L` names out of the symbol table — in rel_cutin_viewer, absolute references
# like `lui %hi(.L00010B48)` / `sw %lo(.L00010B48)($v0)` reaching into another
# function. Same reasoning applies: the name encodes the address.
build/$(MODULE).srcsyms.ld: $(MWOBJ)
	@$(CROSS)nm -u $< | grep -oE '\b(jtbl|D)_[0-9A-F]{4,8}\b' | sort -u | awk -F_ \
		'{ printf "PROVIDE(%s = 0x%s);\n", $$0, $$2 }' > $@
	@# .L names never appear in `nm -u` — they are local, so nm filters them out
	@# even though the relocations reference them. Read the relocation table.
	@$(CROSS)readelf -r $< | grep -oE '\.L[0-9A-F]{8}' | sort -u \
		| sed -E 's/^\.L(.*)$$/PROVIDE(.L\1 = 0x\1);/' >> $@

ifeq ($(SRC),1)
  # our compiled C replaces the disassembled .text. The linker script names that
  # object by path, so it needs a variant with the substitution applied.
  CODE_OBJS := $(MWOBJ) $(filter-out build/asm/$(MODULE)/text.s.o,$(ASM_OBJS))
  LINK_LD   := build/$(MODULE).src.ld
  EXTRA_LD  := build/$(MODULE).srcsyms.ld
else
  CODE_OBJS := $(ASM_OBJS)
  LINK_LD   := $(LD)
endif

.PRECIOUS: build/asm/$(MODULE)/%.s
.DELETE_ON_ERROR:
.PHONY: all verify clean
all: verify

# gas cannot assemble Allegrex's custom opcodes (min/max and the VFPU block),
# which 20 of the 28 modules use. asm_prepare.py rewrites exactly the lines the
# assembler rejects into .word with the identical encoding.
build/asm/$(MODULE)/%.s: asm/$(MODULE)/%.s scripts/asm_prepare.py
	@mkdir -p $(dir $@)
	@python3 scripts/asm_prepare.py $< $@ -- $(AS) $(ASFLAGS)

build/asm/$(MODULE)/%.s.o: build/asm/$(MODULE)/%.s
	@mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) $< -o $@
	@$(OBJCOPY) --set-section-alignment .text=4 --set-section-alignment .data=1 \
		--set-section-alignment .bss=1 $@

build/assets/$(MODULE)/%.bin.o: assets/$(MODULE)/%.bin
	@mkdir -p $(dir $@)
	$(OBJCOPY) -I binary -O elf32-tradlittlemips -B mips \
		--rename-section .data=.data,alloc,load,readonly,data,contents \
		--set-section-alignment .data=1 $< $@

# Absolute addresses for every import stub and named global, so the linker can
# resolve the references our object makes. Generated from the symbol file that
# scripts/resolve_nids.py produces, so it never drifts from the disassembly.
# Absolute addresses come from two places: the named symbols in the symbol file,
# and splat's auto-generated jtbl_XXXXXXXX / D_XXXXXXXX references, whose names
# literally encode the vram they live at (they point into blobs we link verbatim,
# so nothing else defines them).
build/$(MODULE).symbols.ld: config/symbols/$(MODULE).txt $(ASM_SRCS)
	@mkdir -p $(dir $@)
	@sed -n 's/^\([A-Za-z_][A-Za-z0-9_]*\) *= *\(0x[0-9A-Fa-f]*\);.*/PROVIDE(\1 = \2);/p' \
		config/symbols/$(MODULE).txt > $@
	@grep -ohE '\b(jtbl|D)_[0-9A-F]{4,8}\b' $(ASM_SRCS) | sort -u | awk -F_ \
		'{ printf "PROVIDE(%s = 0x%s);\n", $$0, $$2; \
		   p = sprintf("%s_%08X", $$1, strtonum("0x" $$2)); \
		   if (p != $$0) printf "PROVIDE(%s = 0x%s);\n", p, $$2 }' >> $@

build/mwcc/$(MODULE).o: src/$(MODULE).c
	scripts/mwcc_build.sh $<

# Our compiled object also carries any compiler-generated jump tables, in its own
# .rodata. The shipped module keeps them in .data (it has no .rodata at all), and
# those bytes are already inside the data blob we link verbatim — verified
# identical by scripts/mwcc_diff.py. So the table is placed at its real address
# as NOLOAD: the symbol resolves correctly and no bytes are emitted twice.
build/$(MODULE).src.ld: $(LD) $(ASM_SRCS)
	@sed 's|build/asm/$(MODULE)/text\.s\.o|$(MWOBJ)|' $< \
		| grep -v '$(MWOBJ)(\.rodata)' > $@.tmp
	@jt=$$(grep -ohE '\bjtbl_[0-9A-F]{8}\b' $(ASM_SRCS) | sort -u | head -1 | sed 's/jtbl_/0x/'); \
	if [ -n "$$jt" ]; then \
		awk -v addr="$$jt" -v obj="$(MWOBJ)" \
			'/\/DISCARD\//{printf "    .jtbl %s (NOLOAD) : { %s(.rodata) }\n\n", addr, obj} {print}' \
			$@.tmp > $@; \
	else mv $@.tmp $@; fi
	@rm -f $@.tmp

$(OUT): $(CODE_OBJS) $(ASSET_OBJS) $(LINK_LD) build/$(MODULE).symbols.ld $(EXTRA_LD)
	$(LDD) -EL $(if $(EXTRA_LD),-T $(EXTRA_LD),) -T build/$(MODULE).symbols.ld \
		-T $(LINK_LD) -o $@ --no-check-sections

$(BIN): $(OUT)
	$(OBJCOPY) -O binary $< $@

verify: $(BIN)
	@expected=$$(grep -F "$(MODULE).prx" checksums.sha1 | cut -d' ' -f1); \
	actual=$$(sha1sum $(BIN) | cut -d' ' -f1); \
	total=$$(wc -c < $(PRX)); \
	code=$$(readelf -SW $(PRX) | sed 's/\[ *[0-9]*\]//' \
		| awk '$$1==".text"{print strtonum("0x" $$5)}'); \
	if [ "$$expected" != "$$actual" ]; then \
		echo "FAIL $(MODULE).prx"; \
		echo "  expected $$expected"; \
		echo "  actual   $$actual"; \
		echo "  original $$total bytes, built $$(wc -c < $(BIN)) bytes"; \
		cmp $(PRX) $(BIN) | head -3; \
		exit 1; \
	elif [ "$(SRC)" = "1" ]; then \
		echo "OK  $(MODULE).prx matches checksums.sha1 ($$actual)"; \
		echo "    $$code of $$total bytes ($$((100 * code / total))%) rebuilt from src/$(MODULE).c;"; \
		echo "    the rest — import stubs, module tables, .data, ELF metadata — is still"; \
		echo "    carried over from the shipped module, NOT reconstructed. See README."; \
	else \
		echo "OK  $(MODULE).prx matches checksums.sha1 ($$actual)"; \
		echo "    rebuilt from the DISASSEMBLY: this verifies the splat config's layout,"; \
		echo "    not the decompilation. Use SRC=1 to test src/$(MODULE).c."; \
	fi

clean:
	rm -rf build/asm/$(MODULE) build/assets/$(MODULE) \
		build/$(MODULE).elf build/$(MODULE).prx \
		build/$(MODULE).src.elf build/$(MODULE).src.prx \
		build/$(MODULE).symbols.ld build/$(MODULE).src.ld build/$(MODULE).srcsyms.ld


# THE mwccgap HANG, SOLVED. Module builds were observed sitting at 0.0% CPU for
# one to four hours (docs/19), blamed first on concurrency and then on wibo.
# It is neither. tools/mwccgap/mwccgap.py opens with:
#
#     read_from_file = sys.stdin.isatty()
#     if not read_from_file:
#         in_lines = sys.stdin.readlines()
#
# So whenever stdin is not a terminal it reads stdin to EOF. Under a terminal
# that is fine; run it from a script, a CI job, or any harness that hands it an
# open socket, and it blocks forever on a read that will never return. A hung
# process shows exactly that: no children, no compiler running, blocked in
# unix_stream_read_gen on fd 0. It looked concurrency-related only because the
# runs without a controlling terminal were the background ones.
#
# `< /dev/null` is the fix: readlines() returns immediately.
#
#   timeout  still bounds every invocation — cheap insurance, and it turns any
#            future stall into a clear failure instead of a silent CPU squat;
#   flock    still serialises them, so two builds cannot race the same output.
#
# This discipline used to live in a throwaway /tmp script, which meant the
# "19 of 28 modules build byte-exactly" result could not be reproduced at all.
MWCCGAP_TIMEOUT ?= 900

build/hybrid/$(MODULE).o: src/$(MODULE).c scripts/make_hybrid.py
	scripts/make_hybrid.py $(MODULE)
	@mkdir -p build/hybrid
	@flock build/hybrid/.mwccgap.lock \
	 timeout $(MWCCGAP_TIMEOUT) python3 tools/mwccgap/mwccgap.py build/hybrid/$(MODULE).c $@ \
		--mwcc-path tools/mwccpsp_3.0.1_219/mwccpsp.exe \
		--use-wibo --wibo-path tools/wibo-bin/wibo \
		--as-path $(CROSS)as --as-march mips32r2 --as-mabi 32 \
		--macro-inc-path include/macro.inc \
		-Iinclude -O4,s -sdatathreshold 0 < /dev/null \
	 || { rc=$$?; \
	      if [ $$rc -eq 124 ]; then \
	        echo "FAIL $(MODULE): mwccgap timed out after $(MWCCGAP_TIMEOUT)s."; \
	        echo "     stdin is redirected from /dev/null, so this is NOT the old"; \
	        echo "     readlines() hang. Retry it; raise MWCCGAP_TIMEOUT if large."; \
	      fi; exit $$rc; }
# NOTE: --macro-inc-path is required (the per-function .s files open with
# .include "macro.inc"), and --as-flags must NOT be used: mwccgap sets its
# option prefix to "~", so --as-flags' nargs="*" swallows every following
# -flag and leaves the compiler with none.
