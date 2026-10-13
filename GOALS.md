# Goals

Phases from the decomp skill; each has a clear done signal.

- [x] **0. Recon**: boot ELF `SCPS_150.88`, SDK 2.8, C++ with Sony EE-GCC 2.9x (see README).
- [ ] **0b. Symbols**: ccc `stdump` on the ELF and IRX modules; Redump hash check of the ISO.
- [ ] **1. Repo + environment**: `bokura-env` from decomp-nix; pinned tools (splat, spimdisasm,
      R5900 binutils, objdiff); `make` checks the disc image hash before extracting.
- [x] **2. Round-trip the ELF as pure assembly** with splat (`platform: ps2`). Done: the rebuilt
      `SCPS_150.88` matches the original SHA-1.
      Matched 2026-10-13: one `asm` subsegment for .text (spimdisasm finds 7228 functions,
      Ghidra 5911), data/rodata as asm, .vudata as bin, ELF container from `scripts/mkelf.py`.
- [x] **3. Confirm the compiler** on 5-6 tiny leaf functions (EE-GCC 2.96 first, then 2.95 /
      3.x if not). Done: all match.
      Confirmed 2026-10-13: **EE-GCC 2.96 (2.96-ee-001003-1), `-O2 -G0`**, 8/8 functions
      (0x1300E8, 0x145698, 0x178928, 0x10CDA8, 0x1438D8, 0x1300F0, 0x143910, 0x1439E0).
      Best other candidates: SN 2.95.x 6/8, EE 2.9-991111 5/8, EE 3.2 2/8. -O3 also 8/8
      (inlining only), -G8 7/8, -O1 4/8. Details in docs/compiler.md.
- [ ] **4. Name and split the libraries**: Sony SDK 2.8 libraries are one block; match them with
      signatures, never decompile them.
- [ ] **5. C++ pipeline**: game code to C++ units, `INCLUDE_ASM` per function, class layouts
      from the mangled names (`CSceneCharaSet`, `TArray`, `TAllocator`, ...).
- [ ] **6. The batch loop**: fan-in order, permuter for near-misses, HARD.md for the stuck.
- [ ] **7. Mod build**: every pointer a symbol, then shiftable.
