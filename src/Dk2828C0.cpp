#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" s32 D_424418;
extern "C" void func_00283760(void);

typedef void (*W2Fp)(void);
extern "C" W2Fp *D_002BF224;
extern "C" s32 D_002BF228;
extern "C" u8 D_002C2C98[];
extern "C" void *func_00285DD0(void *);

extern "C" double func_00284E38(double, double);

typedef void (*W2Ctor)(void);
extern "C" W2Ctor D_0029F230[];
extern "C" u8 D_424400[];
extern "C" void func_00285CA0(void *, void *);
extern "C" s32 func_00289048(void (*)(void));
extern "C" void func_002836D0(void);
// @decl-end

INCLUDE_ASM("asm/nonmatchings/Dk2828C0", func_002828C0);

INCLUDE_ASM("asm/nonmatchings/Dk2828C0", func_00282E40);

extern "C" float __floatdisf(s64 u) { double f; if (!(-((s64)1 << 53) < u && u < ((s64)1 << 53))) { if ((u64)u & (0x800 - 1)) u |= 0x800; } f = (s32)(u >> 32); f *= 65536.0; f *= 65536.0; f += (u32)(u & 0xFFFFFFFF); return (float)f; }

INCLUDE_ASM("asm/nonmatchings/Dk2828C0", func_00283490);

INCLUDE_ASM("asm/nonmatchings/Dk2828C0", __fixunssfdi);

extern "C" void func_002836D0(void) { while (*D_002BF224) { D_002BF224++; (*(D_002BF224 - 1))(); } if (!D_002BF228) { D_002BF228 = 1; func_00285DD0(D_002C2C98); return; } }

extern "C" void func_00283760(void) { unsigned long nptrs; u32 i; func_00285CA0(D_002C2C98, D_424400); nptrs = (unsigned long)(s32)D_0029F230[0]; if (nptrs == (unsigned long)-1) for (nptrs = 0; D_0029F230[nptrs + 1] != 0; nptrs++); for (i = nptrs; i >= 1; i--) D_0029F230[i](); func_00289048(func_002836D0); return; }

extern "C" void func_00283820(void) { if (!D_424418) { D_424418 = 1; func_00283760(); return; } }
