#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern "C" int func_00283888(void);
extern "C" int func_00288FF8(void);
extern "C" void func_00283C98(void);
extern "C" void (*D_002BF230)(void);
extern "C" void *func_00285DD0(void);
extern "C" int func_002893A0(void *);

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
struct W2FpNum { s32 cls; u32 sign; s32 exp; u32 pad; u64 frac; };
struct W2FpNumS { s32 cls; u32 sign; s32 exp; u32 frac; };
extern "C" double func_002880D0(W2FpNum *);
extern "C" void *func_00289348(u32);
extern "C" int func_00285CA0(void *, void *);
extern "C" int func_00285D38(void *, void *);

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
struct W2Fde { u32 length; s32 cie; s32 pc; };

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
struct W2FpNum2 { s32 cls; u32 sign; s32 exp; u32 pad; u64 frac; };
extern "C" void func_002881A8(void *, W2FpNum2 *);
extern "C" s32 func_00288268(W2FpNum2 *, W2FpNum2 *);
// @decl-end

extern "C" void __pure_virtual(void) { func_00283888(); return; }

extern "C" void func_00283870(void) { func_00288FF8(); return; }

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_00283888);

extern "C" void func_002838D0(void) {
}

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_002838D8);

extern "C" void func_00283930(void *p) { if (p) { func_002893A0(p); return; } }

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_00283958);

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_00283980);

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_002839A8);

extern "C" void func_00283BB0(void) { D_002BF230 = func_00283C98; }

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_00283BC8);

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_00283C30);

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_00283C98);

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_00283D20);

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_00283E00);

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_00283E90);

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_00283EB8);

extern "C" s16 func_00284188(void *p) { return FLD(s16, p, 6); }

extern "C" s16 func_00284190(void *p) { return FLD(s16, p, 4); }

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_00284198);

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_00284268);

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_002843A8);

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_00284438);

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_002844A0);

extern "C" void func_00284550(void) {
}

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_00284558);

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_002848E8);

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_00284A38);

INCLUDE_ASM("asm/nonmatchings/Lib283858", fptodp);

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_00284BD8);

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_00284E38);

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_00284E90);

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_00284EF8);

INCLUDE_ASM("asm/nonmatchings/Lib283858", dpdiv);

extern "C" s32 dpcmp(double a, double b) { W2FpNum2 x, y; union { double d; u64 l; } au, bu; au.d = a; bu.d = b; func_002881A8(&au, &x); func_002881A8(&bu, &y); return func_00288268(&x, &y); }

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_00285310);

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_002853C8);

extern "C" double func_00285468(s32 c, u32 s, s32 e, u64 f) { W2FpNum n; n.cls = c; n.sign = s; n.exp = e; n.frac = f; return func_002880D0(&n); }

INCLUDE_ASM("asm/nonmatchings/Lib283858", dptofp);

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_002854F0);

extern "C" u8 *func_00285590(u8 *buf, u32 *r) { u32 shift = 0; u32 result = 0; while (1) { u32 byte = *buf++; result |= (byte & 0x7f) << shift; if ((byte & 0x80) == 0) break; shift += 7; } *r = result; return buf; }

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_002855D8);

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_00285630);

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_00285728);

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_00285CA0);

extern "C" int func_00285D08(void *p) { return func_00285CA0(p, func_00289348(0x18)); }

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_00285D38);

extern "C" int func_00285DA0(void *p) { return func_00285D38(p, func_00289348(0x18)); }

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_00285DD0);

extern "C" void func_00285E90(void) { func_002893A0(func_00285DD0()); return; }

extern "C" u32 func_00285EB0(W2Fde *f) { u32 n; for (n = 0; f->length != 0; f = (W2Fde *)((u8 *)f + f->length + 4)) { if (f->cie == 0 || f->pc == 0) continue; ++n; } return n; }

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_00285EF0);
