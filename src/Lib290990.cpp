#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern "C" int func_00291590(void *, void *);
extern "C" int func_00290990(void);
extern "C" int func_00290C78(void *);
extern "C" void *func_002916B8(void *);
extern "C" int func_00292CA8(s32, s32);
extern "C" int func_00292E20(u32, u32);
extern "C" int func_00292F60(u32, u32);
extern "C" void *D_002BF5D0;
extern "C" u8 D_002EB4B8[];

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
struct W2Big { W2Big *next; s32 k; };
struct W2Re { u8 pad[0x4C]; W2Big **fl; };
extern "C" void *D_002BF5D0;
extern "C" int func_00291628(void *, void *, void *);

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern "C" void *func_00291980(void *, s32);
union W2Dbl { double d; struct { u32 lo; s32 hi; } w; };
// @decl-end

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00290990);

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00290AA8);

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00290B08);

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00290B80);

extern "C" int func_00290C78(void *p) { return func_00291590(p, (void *)func_00290990); }

extern "C" int func_00290C98(void) { return func_00290C78(D_002BF5D0); }

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00290CB8);

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00290D48);

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00291040);

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_002911B0);

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00291590);

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00291628);

extern "C" void *func_002916B8(void *) { return D_002EB4B8; }

extern "C" int func_002916C8(void *a, void *b) { return func_00291628(D_002BF5D0, a, b); }

extern "C" void *func_002916F0(void) { return func_002916B8(D_002BF5D0); }

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00291710);

extern "C" int func_00291868(void *r, u32 *pwc, const u8 *s, u32 n) { u32 dummy; if (pwc == 0) pwc = &dummy; if (s == 0) return 0; if (n == 0) return -1; *pwc = *s; return *s != 0; }

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_0029189C);

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00291980);

extern "C" void func_00291A28(W2Re *r, W2Big *v) { if (v) { s32 k = v->k; W2Big **fl = r->fl; v->next = fl[k]; fl[k] = v; } }

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00291A58);

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00291B60);

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00291C90);

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00291D10);

extern "C" void *func_00291DD0(void *r, s32 i) { void *b = func_00291980(r, 1); FLD(s32, b, 0x14) = i; FLD(s32, b, 0x10) = 1; return b; }

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00291E08);

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00292018);

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00292118);

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00292270);

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_002922D8);

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00292468);

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00292538);

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_002926D0);

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00292858);

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00292928);

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00292998);

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_002929E0);

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00292A20);

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00292A88);

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00292B08);

extern "C" int func_00292B70(void *p) { return func_00292CA8(FLD(s32, p, 0x54), FLD(s16, p, 0xE)); }

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00292B90);

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00292BF0);

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00292CA8);

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00292D00);

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00292D60);

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00292DC0);

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00292E20);

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00292EC8);

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00292F48);

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00292F60);

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00293008);

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00293088);
