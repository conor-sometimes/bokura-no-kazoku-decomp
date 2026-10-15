#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" s32 func_002731B0(s32);
extern "C" void func_002731D0(s32);
extern s32 D_002BD790;
extern "C" s32 func_00263330(s32, s32, s32);
struct S41C080 { s32 m0; u8 pad4[0x38]; s32 m3C; };
extern S41C080 D_41C080;
extern s32 D_002BD788;
extern s32 D_002BD78C;
extern s32 D_41AAC0;
extern u32 *D_41AAE8;
extern u32 *D_41AAEC;
extern u32 *D_41AAF0;
extern "C" s32 func_00264E90(s32, s32, s32, s32);
struct Rx { s32 m0; u32 m4; u8 pad8[0x90 - 8]; u32 m90; };
extern void (*D_41A808)(s32);
extern u32 D_41A80C;
extern s32 D_41A810;
extern s32 D_002BBBE4;

extern "C" s32 func_00274F10(const char *, ...);
extern s32 D_002BBBD0;
extern const char D_002E9130[];
extern "C" s32 func_00273F80(s32);
extern "C" s32 func_002762A8(void *);
extern u8 D_002BD740[];
extern u8 D_41AB40[];
extern const char D_002E92F8[];
extern "C" s32 func_002760B0(void *, s32, s32, void *, s32, void *, s32, void *, void *);
extern "C" s32 func_0027BD20(void);
extern "C" s32 func_0027BD78(void);
extern "C" s32 func_002752D0(u32, void *, s32);
extern s32 D_002BBC00;
extern "C" void func_00263260(void);
extern "C" void func_00264CF8(void);
// @decl-end

INCLUDE_ASM("asm/nonmatchings/Dk2631E0", func_002631E0);

INCLUDE_ASM("asm/nonmatchings/Dk2631E0", func_00263260);

extern "C" s32 func_002632B8(void) { s32 r; D_002BBBE4 = 1; r = func_0027BD20(); func_002752D0(0x80000012, (void *)func_00263260, 0); if (r) func_0027BD78(); D_002BBBE4 = 0; D_002BBC00 = 1; return 1; }

INCLUDE_ASM("asm/nonmatchings/Dk2631E0", func_00263330);

extern "C" s32 func_00263648(s32 a, s32 b) { return func_00263330(a, b, 0); }

INCLUDE_ASM("asm/nonmatchings/Dk2631E0", func_00263668);

INCLUDE_ASM("asm/nonmatchings/Dk2631E0", func_002637D8);

INCLUDE_ASM("asm/nonmatchings/Dk2631E0", func_00263870);

extern "C" s32 func_00263910(s32 mode) {
    if (mode == 0) {
        if (D_002BBBD0 > 0) func_00274F10(D_002E9130);
        while (func_002762A8(D_002BD740)) func_00273F80(4000);
        return 0;
    }
    return func_002762A8(D_002BD740);
}

INCLUDE_ASM("asm/nonmatchings/Dk2631E0", func_00263980);

INCLUDE_ASM("asm/nonmatchings/Dk2631E0", func_00263AF0);

INCLUDE_ASM("asm/nonmatchings/Dk2631E0", func_00263BA0);

INCLUDE_ASM("asm/nonmatchings/Dk2631E0", func_00263E80);

INCLUDE_ASM("asm/nonmatchings/Dk2631E0", func_00264078);

INCLUDE_ASM("asm/nonmatchings/Dk2631E0", func_00264280);

INCLUDE_ASM("asm/nonmatchings/Dk2631E0", func_00264460);

INCLUDE_ASM("asm/nonmatchings/Dk2631E0", func_002644F8);

INCLUDE_ASM("asm/nonmatchings/Dk2631E0", func_00264590);

INCLUDE_ASM("asm/nonmatchings/Dk2631E0", func_00264648);

INCLUDE_ASM("asm/nonmatchings/Dk2631E0", func_00264720);

INCLUDE_ASM("asm/nonmatchings/Dk2631E0", func_002647F0);

INCLUDE_ASM("asm/nonmatchings/Dk2631E0", func_002648C0);

INCLUDE_ASM("asm/nonmatchings/Dk2631E0", func_002649B8);

INCLUDE_ASM("asm/nonmatchings/Dk2631E0", func_00264AA8);

extern "C" s32 func_00264C78(void) { if (D_002BD78C >= 0) { func_002731B0(D_002BD78C); D_002BD78C = -1; func_002731B0(D_002BD790); } return 1; }

extern "C" void *func_00264CC8(void **a, void **b) { *a = &D_41C080; *b = &D_002BD788; D_41C080.m3C = D_002BD78C; return &D_41AAC0; }

extern "C" void func_00264CF8(void) { func_002731D0(D_002BD790); }

INCLUDE_ASM("asm/nonmatchings/Dk2631E0", func_00264D08);

INCLUDE_ASM("asm/nonmatchings/Dk2631E0", func_00264DC8);

INCLUDE_ASM("asm/nonmatchings/Dk2631E0", func_00264E90);

extern "C" s32 func_00264FB8(s32 a, s32 b, s32 c) { s32 r = func_00264E90(a, b, c, 0x40); if (r == 0) D_002BD788 = 11; return r; }

INCLUDE_ASM("asm/nonmatchings/Dk2631E0", func_00264FF0);

INCLUDE_ASM("asm/nonmatchings/Dk2631E0", func_002650B0);

INCLUDE_ASM("asm/nonmatchings/Dk2631E0", func_00265190);

INCLUDE_ASM("asm/nonmatchings/Dk2631E0", func_00265228);

INCLUDE_ASM("asm/nonmatchings/Dk2631E0", func_00265340);

INCLUDE_ASM("asm/nonmatchings/Dk2631E0", func_002654B8);

extern "C" void func_00265580(Rx *r) { r = (Rx *)((u32)r | 0x20000000); if (D_41AAE8) *D_41AAE8 = r->m0; if (D_41AAEC) *D_41AAEC = r->m4; if (D_41AAF0) *D_41AAF0 = r->m90; func_002731D0(D_002BD790); }

INCLUDE_ASM("asm/nonmatchings/Dk2631E0", func_002655D8);

extern "C" s32 func_00265758(void) {
    if (func_002760B0(&D_41AAC0, 0x35, 0, D_41AB40, 0x30, &D_41C080, 4, (void *)func_00264CF8, 0)) { func_00274F10(D_002E92F8); return -1; }
    return D_41C080.m0;
}

INCLUDE_ASM("asm/nonmatchings/Dk2631E0", func_002657C8);
