#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern "C" int func_00283980(void);
extern "C" int strcmp(const char *, const char *);
extern "C" void *D_002BF244;

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
struct W2FpNumS { s32 cls; u32 sign; s32 exp; u32 frac; };
extern "C" float func_00288F40(W2FpNumS *);

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern "C" s32 strcmp(const char *, const char *);
// @decl-end

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_00285F80);

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_00285FD8);

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_00286140);

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_002862E8);

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_002863F8);

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_00286518);

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_00286968);

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_00286B20);

extern "C" s32 func_00286B58(const char **a, const char **b) { return b == a || strcmp(*a, *b) == 0; }

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_00286B98);

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_00286BC0);

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_00286BE0);

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_00286C00);

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_00286C78);

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_00286DC0);

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_00286E20);

extern "C" s32 func_00286EB8(void *a, void *b, void *c, s32 x, s32 y) { return y == x ? 6 : 1; }

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_00286ED0);

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_00286F80);

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_002870A0);

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_00287138);

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_00287378);

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_002877B8);

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_00287920);

extern "C" void *func_00287960(void *p) { void *o = D_002BF244; D_002BF244 = p; return o; }

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_00287978);

extern "C" s32 func_002879B8(void) { return *(s32 *)func_00283980(); }

extern "C" void *func_002879D8(void) { u8 *p = *(u8 **)func_00283980(); FLD(s32, p, 0x14) = 1; FLD(s64, p, 0x20) = FLD(s64, p, 0x20) + 1; return p; }

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_00287A10);

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_00287A70);

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_00287B00);

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_00287C28);

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_00287C88);

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_00287E50);

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_00287EB8);

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_00287F58);

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_00287F98);

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_00288040);

extern "C" float func_002880A0(s32 c, u32 s, s32 e, u32 f) { W2FpNumS n; n.cls = c; n.sign = s; n.exp = e; n.frac = f; return func_00288F40(&n); }

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_002880D0);

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_002881A8);

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_00288268);

extern "C" s32 func_00288388(const char **a, const char **b) { return strcmp(*a, *b) < 0; }

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_002883B0);
