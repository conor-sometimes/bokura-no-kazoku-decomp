#include "common.h"

// tinfo2/exception C++ after the fp-bit helpers (0x288388-0x2888C0)

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" int strcmp(const char *, const char *);
// @decl-end

extern "C" s32 func_00288388(const char **a, const char **b) { return strcmp(*a, *b) < 0; }

INCLUDE_ASM("asm/nonmatchings/Lib288388", func_002883B0);
