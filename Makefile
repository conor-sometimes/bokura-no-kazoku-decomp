# Round-trip build of SCPS_150.88 from assembly.
#   ./setup.sh path/to/bokura.iso   (once; inside bokura-env)
#   make                            (split if needed, assemble, link, rebuild ELF, check SHA-1)
# Run inside bokura-env: .bokura-env/bin/bokura-env -c make

TARGET   := SCPS_150.88
CONFIG   := config/$(TARGET).yaml
BASEROM  := disc/$(TARGET)
EXPECTED := 621ffd58de52794eaa3d33885ba1288f36e19365

CROSS    := mips-ps2-decompals-
AS       := $(CROSS)as
LD       := $(CROSS)ld
OBJCOPY  := $(CROSS)objcopy
PYTHON   := .venv/bin/python

ASFLAGS  := -EL -march=r5900 -mabi=eabi -no-pad-sections -G 0 -Iinclude

# Game C++: Sony EE-GCC 2.96 (2.96-ee-001003-1), -O2 -G0 -fno-strict-aliasing -fno-exceptions, as -g (docs/compiler.md). The driver runs
# cc1plus and its own GNU as 2.10-ee, which also assembles the INCLUDE_ASM'd functions.
EECC     := tools/compilers/ee-gcc2.96/bin/ee-gcc
CXXFLAGS := -O2 -G0 -fno-strict-aliasing -fno-exceptions -Iinclude -Wa,-Iinclude -Wa,-g
LDSCRIPT := build/$(TARGET).ld
SPLIT    := build/.split

.PHONY: all split check clean distclean
all: check

# splat writes asm/, assets/ and the linker script; re-run it when the yaml or symbols change.
# splat doesn't delete files of pieces that no longer exist, so start from an empty asm/.
$(SPLIT): $(CONFIG) config/symbol_addrs.txt config/vtables.txt config/rodata_syms.txt $(BASEROM)
	@mkdir -p build
	rm -rf asm
	$(PYTHON) -m splat split $(CONFIG)
	python3 -I scripts/data_syms.py $(CONFIG) asm > build/data_syms_auto.txt
	python3 -I scripts/rodata_align.py asm
	@touch $@
split: $(SPLIT)

# The object list is only known after splitting, so the link runs in a sub-make.
check: $(SPLIT)
	@$(MAKE) --no-print-directory build/$(TARGET)
	@sum=$$(sha1sum build/$(TARGET) | cut -d' ' -f1); \
	if [ "$$sum" = "$(EXPECTED)" ]; then echo "OK: build/$(TARGET) matches ($$sum)"; \
	else echo "FAIL: build/$(TARGET) is $$sum, expected $(EXPECTED)"; exit 1; fi

# asm/nonmatchings/ holds the INCLUDE_ASM'd functions of the C++ units: not objects of their own.
ASM_SRCS := $(shell find asm -name '*.s' -not -path 'asm/nonmatchings/*' 2>/dev/null)
BIN_SRCS := $(shell find assets -name '*.bin' 2>/dev/null)
CPP_SRCS := $(shell find src -name '*.cpp' 2>/dev/null)
OBJS     := $(ASM_SRCS:%=build/%.o) $(BIN_SRCS:%=build/%.o) $(CPP_SRCS:%=build/%.o)

build/asm/%.s.o: asm/%.s include/macro.inc
	@mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) -o $@ $<

# C++ units; each rebuilds when one of its INCLUDE_ASM files changes.
.SECONDEXPANSION:
build/src/%.cpp.o: src/%.cpp $(wildcard include/*.h) $$(wildcard asm/nonmatchings/$$*/*.s) $(EECC)
	@mkdir -p $(dir $@)
	$(EECC) $(CXXFLAGS) -c -o $@ $<

$(EECC):
	scripts/fetch_compilers.sh

# Raw blobs (VU microcode): .incbin through the same assembler so the ELF flags agree.
build/assets/%.bin.o: assets/%.bin
	@mkdir -p $(dir $@)
	printf '.section .data, "wa"\n.incbin "%s"\n' $< | $(AS) $(ASFLAGS) -o $@ -

build/$(TARGET).elf: $(OBJS) $(LDSCRIPT)
	$(LD) -EL --no-warn-rwx-segments -T build/undefined_syms_auto.txt -T build/undefined_funcs_auto.txt -T build/data_syms_auto.txt -T config/aliases.ld \
	    -Map build/$(TARGET).map -T $(LDSCRIPT) -o $@

# Loaded image (.text through .gcc_except_table) as one flat blob, then the ELF container around it.
build/$(TARGET).img: build/$(TARGET).elf
	$(OBJCOPY) -O binary $< $@

build/$(TARGET): build/$(TARGET).img scripts/mkelf.py
	python3 -I scripts/mkelf.py $< $@

clean:
	rm -rf build
distclean: clean
	rm -rf asm assets
