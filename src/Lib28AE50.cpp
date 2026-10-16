#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern "C" int func_0028AD50(void *, int);
extern "C" int func_00273970(void);
extern "C" void *D_002BF5D0;

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern "C" void *D_002BF5D0;
extern "C" double func_0028B970(void *, const char *, char **);
extern "C" double func_0028C888(const char *, char **);
extern "C" long func_0028C8D8(void *, const char *, char **, int);

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern "C" s32 func_002911B0(void *, void *);
extern "C" const char _ctype_[];
// @decl-end

extern "C" int func_0028AE50(int s) { return func_0028AD50(D_002BF5D0, s); }

INCLUDE_ASM("asm/nonmatchings/Lib28AE50", func_0028AE70);

extern "C" int func_0028AED0(void) { return func_00273970(); }

INCLUDE_ASM("asm/nonmatchings/Lib28AE50", func_0028AEE8);

INCLUDE_ASM("asm/nonmatchings/Lib28AE50", sprintf);

INCLUDE_ASM("asm/nonmatchings/Lib28AE50", func_0028B000);

INCLUDE_ASM("asm/nonmatchings/Lib28AE50", strcmp);

INCLUDE_ASM("asm/nonmatchings/Lib28AE50", strcpy);

INCLUDE_ASM("asm/nonmatchings/Lib28AE50", strlen);

extern "C" char *func_0028B520(char *a) { char *ret = a; while (*a != 0) { int c = *a; if ((_ctype_ + 1)[c] & 1) *a = c - 0x41 + 0x61; ++a; } return ret; }

INCLUDE_ASM("asm/nonmatchings/Lib28AE50", func_0028B570);

INCLUDE_ASM("asm/nonmatchings/Lib28AE50", func_0028B728);

INCLUDE_ASM("asm/nonmatchings/Lib28AE50", strstr);

INCLUDE_ASM("asm/nonmatchings/Lib28AE50", func_0028B970);

extern "C" double func_0028C888(const char *s, char **e) { return func_0028B970(D_002BF5D0, s, e); }

extern "C" float func_0028C8B0(const char *s, char **e) { return func_0028C888(s, e); }

INCLUDE_ASM("asm/nonmatchings/Lib28AE50", func_0028C8D8);

extern "C" long func_0028CB10(const char *s, char **e, int b) { return func_0028C8D8(D_002BF5D0, s, e, b); }

extern "C" s32 func_0028CB40(void *fp, void *uio) { s32 err; if (FLD(s32, uio, 8) == 0) { FLD(s32, uio, 4) = 0; return 0; } err = func_002911B0(fp, uio); FLD(s32, uio, 8) = 0; FLD(s32, uio, 4) = 0; return err; }

INCLUDE_ASM("asm/nonmatchings/Lib28AE50", func_0028CB88);

INCLUDE_ASM("asm/nonmatchings/Lib28AE50", func_0028CC40);

INCLUDE_ASM("asm/nonmatchings/Lib28AE50", func_0028CCB8);
