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
# as -g only for the C++ units: the C-style units from CAppMain on (scripts/text_units.py) match
# only without it, so they were built differently (docs/compiler.md).
ASG      := -Wa,-g
build/src/CAppMain.cpp.o build/src/Unit%.cpp.o: ASG :=
# Two groups of dklib units were built with the SDK compiler ee-gcc 2.9-991111, not the game's 2.96
# (docs/compiler.md):
# - SDK_OBJS (lane d3): dklib's units from 0x262D28 (IPU, MPEG stream, ...), C++ through 2.9 and its
#   own as replaced by the 2.96 GNU as (-B), no as -g (frameless sibcalls, its varargs frame,
#   strict aliasing at -O2);
# - SDKC_OBJS (lane d4): the Sony SDK libraries (libmpeg, libipu, libgraph, libdma, libvu0,
#   libkernel, ...), C through 2.9-991111-01's cc1 -O2 -G0, assembled by the game compiler's GNU as 2.10 (-B:
#   2.9's own as fills fewer delay slots and adds COP2 hazard nops). Their .cpp files compile as C.
SDKCC    := tools/compilers/ee-gcc2.9-991111/bin/ee-gcc
SDKAS    := tools/compilers/ee-gcc2.96/ee/bin/
SDK_OBJS := $(patsubst %,build/src/%.cpp.o,Dk262D28 Dk2631E0 Dk265918 Dk268138 Dk26A870)
$(SDK_OBJS): EECC := $(SDKCC)
$(SDK_OBJS): CXXFLAGS = -O2 -G0 -fno-exceptions -B$(SDKAS) -Iinclude -Wa,-Iinclude
SDKC_UNITS := Dk26CFB0 Dk26FC10 Dk271AF8 Dk272E50 Dk273210 Dk2735D0 Dk2752B8 Dk2779D8 Dk27A100 Dk27C020 Dk27DBB8
SDKC_OBJS := $(SDKC_UNITS:%=build/src/%.cpp.o)
SDKC01CC := tools/compilers/ee-gcc2.9-991111-01/bin/ee-gcc
$(SDKC_OBJS): EECC := $(SDKC01CC)
$(SDKC_OBJS): CXXFLAGS = -x c -O2 -G0 -B$(SDKAS) -Iinclude -Wa,-Iinclude
# - LIBC_OBJS (lane w2): libgcc and newlib (0x283858-0x292E20: __pure_virtual, eh, frame.c, fp-bit,
#   tinfo, libc) are the game compiler's 2.96 but without -fno-strict-aliasing (__register_frame_info
#   0x285CA0 loads the mutex before the list stores, _init_signal_r 0x28AB88 hoists the table pointer
#   out of its clear loop, only with strict aliasing). Written as C++ (`return;` after a final void call
#   gives the C sibcall).
LIBC_OBJS := $(patsubst %,build/src/%.cpp.o,Lib283858 Lib285F80 Lib2888C0 Lib28AE50 Lib28D8B0 Lib290990)
$(LIBC_OBJS): CXXFLAGS = -O2 -G0 -fno-exceptions -Iinclude -Wa,-Iinclude $(ASG)
CXXFLAGS  = -O2 -G0 -fno-strict-aliasing -fno-exceptions -Iinclude -Wa,-Iinclude $(ASG)
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
$(SDK_OBJS): $(SDKCC)
$(SDKC_OBJS): $(SDKC01CC)
$(SDKC01CC):
	scripts/fetch_compilers.sh ee-gcc2.9-991111-01
$(SDKCC):
	scripts/fetch_compilers.sh ee-gcc2.9-991111

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
