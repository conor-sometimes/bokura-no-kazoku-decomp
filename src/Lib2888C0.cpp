#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern "C" int func_0028ADE8(int);
extern "C" void func_00100248(int) __attribute__((noreturn));
extern "C" int func_002883B0(void *, void *, void *, s32 *);
extern "C" double func_0028C888(const char *, char **);
extern "C" float func_0028C8B0(const char *, char **);
extern "C" long func_0028CB10(const char *, char **, int);
extern "C" void *D_002BF5D0;
extern "C" int func_0028AC78(void *, int);
extern "C" int func_0028AB88(void *);

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern "C" void *D_002BF5D0;
extern "C" int func_0028ABF8(void *, void *, void *);

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern "C" int func_002892F0(void *, const char *, ...);
extern "C" const char D_002EAE48[];
extern "C" void func_00288FF8(void);

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern "C" void func_0028A070(void *);
extern "C" void func_00290D48(void *, void *);
extern "C" void func_0028A0F0(void *);
struct W2VtEnt { s16 delta; s16 index; void *pfn; };
extern "C" s32 func_00288A88(void *, void *, s32, void *, void *, void *);
extern "C" u8 __tf19__pointer_type_info[];
extern "C" u8 __tf9type_info[];
extern "C" s32 D_002BFA34;
extern "C" s32 D_002BFA30;
extern "C" s32 D_002BE1C0;
extern "C" s32 func_002731C0(s32);
// @decl-end

extern "C" s32 func_002888C0(void *a, void *b, void *c) { s32 x; if (func_002883B0(a, b, c, &x)) return x; return 0; }

extern "C" s32 func_002888E8(void *p) { s32 r = 0; if (p) { W2VtEnt *v = FLD(W2VtEnt *, p, 4); r = func_00288A88(v->pfn, __tf19__pointer_type_info, 0, (u8 *)p + v->delta, __tf9type_info, p); } return r != 0; }

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", func_00288938);

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", func_00288958);

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", func_00288980);

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", func_002889A0);

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", func_002889C0);

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", func_002889E0);

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", func_00288A00);

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", func_00288A88);

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", func_00288B18);

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", func_00288B50);

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", func_00288B88);

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", func_00288BC0);

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", func_00288BF8);

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", func_00288C30);

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", func_00288C68);

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", func_00288CA0);

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", func_00288CD8);

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", func_00288D10);

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", func_00288D48);

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", func_00288D80);

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", func_00288DB8);

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", func_00288DF0);

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", func_00288E28);

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", func_00288E60);

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", func_00288E98);

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", func_00288ED0);

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", func_00288F08);

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", func_00288F40);

extern "C" void func_00288FF8(void) { func_0028ADE8(6); func_00100248(1); }

extern "C" void func_00289010(const char *file, s32 line, const char *expr) { func_002892F0(FLD(void *, D_002BF5D0, 0xC), D_002EAE48, expr, file, line); func_00288FF8(); return; }

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", func_00289048);

extern "C" double func_002890E8(const char *s) { return func_0028C888(s, 0); }

extern "C" float atoff(const char *s) { return func_0028C8B0(s, 0); }

extern "C" int atoi(const char *s) { return func_0028CB10(s, 0, 10); }

extern "C" long atol(const char *s) { return func_0028CB10(s, 0, 10); }

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", bsearch);

extern "C" void *func_00289230(void) { return D_002BF5D0; }

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", func_00289240);

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", func_002892F0);

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", func_00289348);

extern "C" void func_002893A0(void *p) { func_0028A070(D_002BF5D0); func_00290D48(D_002BF5D0, p); func_0028A0F0(D_002BF5D0); return; }

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", func_002893E8);

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", func_00289640);

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", strncmp);

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", memcpy);

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", func_00289EAC);

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", memset);

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", func_0028A070);

extern "C" void func_0028A0F0(void *r) { if (--D_002BFA34 == 0) { D_002BFA30 = -1; func_002731C0(D_002BE1C0); return; } }

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", func_0028A140);

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", func_0028AB30);

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", func_0028AB88);

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", func_0028ABF8);

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", func_0028AC78);

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", func_0028AD50);

extern "C" int func_0028ADE8(int s) { return func_0028AC78(D_002BF5D0, s); }

extern "C" int func_0028AE08(void *a, void *b) { return func_0028ABF8(D_002BF5D0, a, b); }

extern "C" int func_0028AE30(void) { return func_0028AB88(D_002BF5D0); }
