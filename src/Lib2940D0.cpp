#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CTask.h"
extern "C" void CTask_dtor(CTask *, s32) asm("_$_5CTask");
extern "C" void func_00286BC0(void *, const char *, void *);
extern "C" void func_00286BE0(void *, const char *);
extern "C" char D_002D3768[];
extern "C" char D_002D37F0[];
extern "C" char D_002D3808[];
extern "C" u8 D_2EB708[];
extern "C" u8 D_2EB758[];
extern "C" u8 D_4246B0[];
extern "C" u8 D_4246D0[];
extern "C" void *__tf8CListTag(void);
extern "C" void *func_002942A0(void);
// @decl-end

extern "C" s32 func_002940D0(u8 *p) { return *(s32 *)(p + 0x74); }

extern "C" s32 func_002940D8(u8 *p) { return *(s32 *)(p + 0x78); }

extern "C" void func_002940E0(u8 *p, f32 v) { *(f32 *)(p + 0x7C) = v; }

extern "C" void func_002940E8(u8 *p, f32 v) { *(f32 *)(p + 0x80) = v; }

extern "C" f32 func_002940F0(u8 *p) { return *(f32 *)(p + 0x7C); }

extern "C" f32 func_002940F8(u8 *p) { return *(f32 *)(p + 0x80); }

extern "C" s32 func_00294100(u8 *p) { return *(s32 *)(p + 0x94); }

extern "C" s32 func_00294108(u8 *p) { return *(s32 *)(p + 0x90); }

extern "C" s32 func_00294110(u8 *p) { return *(s32 *)(p + 0x138) > 0; }

extern "C" void func_00294120(u8 *p, s32 v) { *(s32 *)(p + 0x6C) = v; }

extern "C" s32 func_00294128(u8 *p) { return *(s32 *)(p + 0x6C); }

extern "C" void func_00294130(u8 *p, s32 v) { *(s32 *)(p + 0x64) = v; }

extern "C" s32 func_00294138(u8 *p) { return *(s32 *)(p + 0x64); }

extern "C" void func_00294140(u8 *p, f32 v) { *(f32 *)(p + 0x168) = v; }

extern "C" f32 func_00294148(u8 *p) { return *(f32 *)(p + 0x168); }

extern "C" u8 *func_00294150(u8 *p) { return p + 0x1A8; }

extern "C" u8 *func_00294158(u8 *p) { return p + 0x1B8; }

extern "C" void func_00294160(u8 *p, s32 v) { *(s32 *)(p + 0x16C) = v; }

extern "C" s32 func_00294168(u8 *p) { return *(s32 *)(p + 0x16C); }

extern "C" void func_00294170(u8 *p, s32 v) { *(s32 *)(p + 0x178) = v; }

extern "C" s32 func_00294178(u8 *p) { return *(s32 *)(p + 0x178); }

extern "C" s32 func_00294180(u8 *p) { return *(s32 *)(p + 0x188); }

extern "C" void func_00294188(u8 *p, s32 v) { *(s32 *)(p + 0x1C8) = v; }

extern "C" s32 func_00294190(u8 *p) { return *(s32 *)(p + 0x1C8); }

extern "C" s32 func_00294198(u8 *p) { return *(s32 *)(p + 0x3C); }

extern "C" s32 func_002941A0(u8 *p) { return *(s32 *)(p + 0x44); }

extern "C" s32 func_002941A8(u8 *p) { return *(s32 *)(p + 0x40); }

extern "C" void *func_002941B0(void) {
    if (*(s32 *)D_4246B0 == 0) {
        __tf8CListTag();
        func_00286BC0(D_4246B0, D_002D3768, D_2EB708);
    }
    return D_4246B0;
}

extern "C" void *__tf15CModelAccResMgr(void) {
    if (*(s32 *)D_4246D0 == 0) {
        func_002942A0();
        func_00286BC0(D_4246D0, D_002D37F0, D_2EB758);
    }
    return D_4246D0;
}

INCLUDE_ASM("asm/nonmatchings/Lib2940D0", func_00294250);

// CModelAccResMgr[3]
extern "C" u8 *func_00294288(u8 *p) { return p + 0x4; }

// CModelAccResMgr[4]
extern "C" u8 *func_00294290(u8 *p) { return p + 0x24; }

// CModelAccResMgr[5]
extern "C" u8 *func_00294298(u8 *p) { return p + 0x34; }

extern "C" void *func_002942A0(void) {
    if (*(s32 *)D_2EB758 == 0) {
        func_00286BE0(D_2EB758, D_002D3808);
    }
    return D_2EB758;
}

INCLUDE_ASM("asm/nonmatchings/Lib2940D0", func_002942E0);

INCLUDE_ASM("asm/nonmatchings/Lib2940D0", func_00294308);

INCLUDE_ASM("asm/nonmatchings/Lib2940D0", func_00294330);

INCLUDE_ASM("asm/nonmatchings/Lib2940D0", func_00294388);

extern "C" s32 func_002943A8(u8 *p) { return *(s32 *)(p + 0xC); }

INCLUDE_ASM("asm/nonmatchings/Lib2940D0", func_002943B0);

extern "C" s32 func_002943C8(u8 *p) { return *(s32 *)(p + 0xC); }

INCLUDE_ASM("asm/nonmatchings/Lib2940D0", func_002943D0);

INCLUDE_ASM("asm/nonmatchings/Lib2940D0", func_002943E8);

INCLUDE_ASM("asm/nonmatchings/Lib2940D0", func_00294408);

INCLUDE_ASM("asm/nonmatchings/Lib2940D0", func_00294420);

INCLUDE_ASM("asm/nonmatchings/Lib2940D0", func_00294438);

INCLUDE_ASM("asm/nonmatchings/Lib2940D0", func_002945F8);

INCLUDE_ASM("asm/nonmatchings/Lib2940D0", func_00294610);

INCLUDE_ASM("asm/nonmatchings/Lib2940D0", func_00294620);

INCLUDE_ASM("asm/nonmatchings/Lib2940D0", func_002947C0);

INCLUDE_ASM("asm/nonmatchings/Lib2940D0", func_002947D0);

INCLUDE_ASM("asm/nonmatchings/Lib2940D0", func_002947E8);

INCLUDE_ASM("asm/nonmatchings/Lib2940D0", func_00294818);

INCLUDE_ASM("asm/nonmatchings/Lib2940D0", func_00294848);

INCLUDE_ASM("asm/nonmatchings/Lib2940D0", func_002948B0);

INCLUDE_ASM("asm/nonmatchings/Lib2940D0", func_00294908);

INCLUDE_ASM("asm/nonmatchings/Lib2940D0", func_00294948);

INCLUDE_ASM("asm/nonmatchings/Lib2940D0", func_00294970);

INCLUDE_ASM("asm/nonmatchings/Lib2940D0", func_002949A0);

INCLUDE_ASM("asm/nonmatchings/Lib2940D0", func_00294A08);
