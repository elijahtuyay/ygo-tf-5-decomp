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
# Definition of done for a module: `make MODULE=<name> SRC=1` prints OK.

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
build/$(MODULE).srcsyms.ld: $(MWOBJ)
	@$(CROSS)nm -u $< | grep -oE '\b(jtbl|D)_[0-9A-F]{4,8}\b' | sort -u | awk -F_ \
		'{ printf "PROVIDE(%s = 0x%s);\n", $$0, $$2 }' > $@

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
	code=$$(readelf -SW $(PRX) | awk '$$2==".text"{print strtonum("0x" $$6)}'); \
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


build/hybrid/$(MODULE).o: src/$(MODULE).c scripts/make_hybrid.py
	scripts/make_hybrid.py $(MODULE)
	python3 tools/mwccgap/mwccgap.py build/hybrid/$(MODULE).c $@ \
		--mwcc-path tools/mwccpsp_3.0.1_219/mwccpsp.exe \
		--use-wibo --wibo-path tools/wibo-bin/wibo \
		--as-path $(CROSS)as --as-march mips32r2 --as-mabi 32 \
		--macro-inc-path include/macro.inc \
		-Iinclude -O4,s -sdatathreshold 0
# NOTE: --macro-inc-path is required (the per-function .s files open with
# .include "macro.inc"), and --as-flags must NOT be used: mwccgap sets its
# option prefix to "~", so --as-flags' nargs="*" swallows every following
# -flag and leaves the compiler with none.
