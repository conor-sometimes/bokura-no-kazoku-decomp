#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern "C" s32 func_002911B0(void *, void *);
// @decl-end

extern "C" s32 func_0028D8B0(void *fp, void *uio) { s32 err; if (FLD(s32, uio, 8) == 0) { FLD(s32, uio, 4) = 0; return 0; } err = func_002911B0(fp, uio); FLD(s32, uio, 8) = 0; FLD(s32, uio, 4) = 0; return err; }

INCLUDE_ASM("asm/nonmatchings/Lib28D8B0", func_0028D8F8);

INCLUDE_ASM("asm/nonmatchings/Lib28D8B0", func_0028D9B0);

INCLUDE_ASM("asm/nonmatchings/Lib28D8B0", func_0028DA28);

INCLUDE_ASM("asm/nonmatchings/Lib28D8B0", func_0028F098);

INCLUDE_ASM("asm/nonmatchings/Lib28D8B0", func_0028F258);

INCLUDE_ASM("asm/nonmatchings/Lib28D8B0", vsprintf);

INCLUDE_ASM("asm/nonmatchings/Lib28D8B0", func_0028F390);

INCLUDE_ASM("asm/nonmatchings/Lib28D8B0", func_0028F3E8);

INCLUDE_ASM("asm/nonmatchings/Lib28D8B0", func_0028F4F8);

INCLUDE_ASM("asm/nonmatchings/Lib28D8B0", func_0028F728);
