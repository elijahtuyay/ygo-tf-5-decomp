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
OUT     := build/$(MODULE).elf
BIN     := build/$(MODULE).prx

CROSS   := mips-linux-gnu-
AS      := $(CROSS)as
LDD     := $(CROSS)ld
OBJCOPY := $(CROSS)objcopy
ASFLAGS := -march=r4000 -mabi=32 -EL -I include -I asm/$(MODULE)

ASM_SRCS   := $(wildcard asm/$(MODULE)/*.s)
ASM_OBJS   := $(patsubst asm/$(MODULE)/%.s,build/asm/$(MODULE)/%.s.o,$(ASM_SRCS))
ASSET_SRCS := $(wildcard assets/$(MODULE)/*.bin)
ASSET_OBJS := $(patsubst assets/$(MODULE)/%.bin,build/assets/$(MODULE)/%.bin.o,$(ASSET_SRCS))

ifeq ($(SRC),1)
  # our compiled C replaces the disassembled .text. The linker script names that
  # object by path, so it needs a variant with the substitution applied.
  CODE_OBJS := build/mwcc/$(MODULE).o $(filter-out build/asm/$(MODULE)/text.s.o,$(ASM_OBJS))
  LINK_LD   := build/$(MODULE).src.ld
else
  CODE_OBJS := $(ASM_OBJS)
  LINK_LD   := $(LD)
endif

.PHONY: all verify clean
all: verify

build/asm/$(MODULE)/%.s.o: asm/$(MODULE)/%.s
	@mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) $< -o $@

build/assets/$(MODULE)/%.bin.o: assets/$(MODULE)/%.bin
	@mkdir -p $(dir $@)
	$(OBJCOPY) -I binary -O elf32-tradlittlemips -B mips \
		--rename-section .data=.data,alloc,load,readonly,data,contents $< $@

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
	@grep -ohE '\b(jtbl|D)_[0-9A-F]{8}\b' $(ASM_SRCS) | sort -u | \
		sed -E 's/^(.*)_([0-9A-F]{8})$$/PROVIDE(\1_\2 = 0x\2);/' >> $@

build/mwcc/$(MODULE).o: src/$(MODULE).c
	scripts/mwcc_build.sh $<

# Our compiled object also carries any compiler-generated jump tables, in its own
# .rodata. The shipped module keeps them in .data (it has no .rodata at all), and
# those bytes are already inside the data blob we link verbatim — verified
# identical by scripts/mwcc_diff.py. So the table is placed at its real address
# as NOLOAD: the symbol resolves correctly and no bytes are emitted twice.
build/$(MODULE).src.ld: $(LD) $(ASM_SRCS)
	@sed 's|build/asm/$(MODULE)/text\.s\.o|build/mwcc/$(MODULE).o|' $< \
		| grep -v 'build/mwcc/$(MODULE)\.o(\.rodata)' > $@.tmp
	@jt=$$(grep -ohE '\bjtbl_[0-9A-F]{8}\b' $(ASM_SRCS) | sort -u | head -1 | sed 's/jtbl_/0x/'); \
	if [ -n "$$jt" ]; then \
		awk -v addr="$$jt" -v obj="build/mwcc/$(MODULE).o" \
			'/\/DISCARD\//{printf "    .jtbl %s (NOLOAD) : { %s(.rodata) }\n\n", addr, obj} {print}' \
			$@.tmp > $@; \
	else mv $@.tmp $@; fi
	@rm -f $@.tmp

$(OUT): $(CODE_OBJS) $(ASSET_OBJS) $(LINK_LD) build/$(MODULE).symbols.ld
	$(LDD) -EL -T build/$(MODULE).symbols.ld -T $(LINK_LD) -o $@ --no-check-sections

$(BIN): $(OUT)
	$(OBJCOPY) -O binary $< $@

verify: $(BIN)
	@expected=$$(grep -F "$(MODULE).prx" checksums.sha1 | cut -d' ' -f1); \
	actual=$$(sha1sum $(BIN) | cut -d' ' -f1); \
	if [ "$$expected" = "$$actual" ]; then \
		echo "OK  $(MODULE).prx matches checksums.sha1 ($$actual)"; \
	else \
		echo "FAIL $(MODULE).prx"; \
		echo "  expected $$expected"; \
		echo "  actual   $$actual"; \
		echo "  original $$(wc -c < $(PRX)) bytes, built $$(wc -c < $(BIN)) bytes"; \
		cmp $(PRX) $(BIN) | head -3; \
		exit 1; \
	fi

clean:
	rm -rf build/asm/$(MODULE) build/assets/$(MODULE) $(OUT) $(BIN) \
		build/$(MODULE).symbols.ld build/$(MODULE).src.ld
