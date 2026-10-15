#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CTask.h"
extern "C" void CTask_dtor(CTask *, s32) asm("_$_5CTask");
extern "C" void func_00286BC0(void *, const char *, void *);
extern "C" void func_00286BE0(void *, const char *);
extern "C" char D_002D3088[];
extern "C" char D_002D3240[];
extern "C" char D_002D3338[];
extern "C" char D_002D3390[];
extern "C" char D_002D33F0[];
extern "C" char D_002D3578[];
extern "C" char D_002D3758[];
extern "C" u8 D_2EB728[];
extern "C" u8 D_2EB730[];
extern "C" u8 D_2EB738[];
extern "C" u8 D_2EB740[];
extern "C" u8 D_2EB748[];
extern "C" u8 D_2EB750[];
extern "C" u8 D_4246B0[];
extern "C" u8 D_4246C0[];
extern "C" void *func_002941B0(void);

class CVec4;
void Func270C50(CVec4 *dst, const CVec4 *src);
void Func270CA0(CVec4 *dst, void *src);
// @decl-end

extern "C" void *__tf14CDiffMotionObj(void) {
    if (*(s32 *)D_2EB728 == 0) {
        func_00286BE0(D_2EB728, D_002D3088);
    }
    return D_2EB728;
}

extern "C" void func_00293CF0(u8 *p, f32 v) { *(f32 *)(p + 0x18) = v; }

extern "C" f32 func_00293CF8(u8 *p) { return *(f32 *)(p + 0x18); }

extern "C" void func_00293D00(u8 *p, f32 v) { *(f32 *)(p + 0x20) = v; }

extern "C" f32 func_00293D08(u8 *p) { return *(f32 *)(p + 0x20); }

extern "C" void func_00293D10(u8 *p, f32 v) { *(f32 *)(p + 0x1C) = v; }

extern "C" f32 func_00293D18(u8 *p) { return *(f32 *)(p + 0x1C); }

extern "C" void *__tf9CModelRes(void) {
    if (*(s32 *)D_2EB730 == 0) {
        func_00286BE0(D_2EB730, D_002D3240);
    }
    return D_2EB730;
}

extern "C" void func_00293D60(u8 *p, s32 v) { *(s32 *)(p + 0xC) = v; }

extern "C" s32 func_00293D68(u8 *p) { return *(s32 *)(p + 0xC); }

extern "C" void func_00293D70(u8 *p, s32 v) { *(s32 *)(p + 0x10) = v; }

extern "C" s32 func_00293D78(u8 *p) { return *(s32 *)(p + 0x10); }

extern "C" s32 func_00293D80(u8 *p, s32 i) { return ((s32 *)(p + 0x14))[i]; }

extern "C" void *__tf10CMotionRes(void) {
    if (*(s32 *)D_2EB738 == 0) {
        func_00286BE0(D_2EB738, D_002D3338);
    }
    return D_2EB738;
}

extern "C" void *__tf13CSwingBoneObj(void) {
    if (*(s32 *)D_2EB740 == 0) {
        func_00286BE0(D_2EB740, D_002D3390);
    }
    return D_2EB740;
}

extern "C" void func_00293E10(u8 *p, f32 v) { *(f32 *)(p + 0x2C) = v; }

extern "C" f32 func_00293E18(u8 *p) { return *(f32 *)(p + 0x2C); }

extern "C" f32 func_00293E20(u8 *p) { return 1.0f; }

extern "C" void func_00293E30(u8 *p, f32 v) { *(f32 *)(p + 0x28) = v; }

extern "C" f32 func_00293E38(u8 *p) { return *(f32 *)(p + 0x28); }

extern "C" void *__tf13CSwingBoneRes(void) {
    if (*(s32 *)D_2EB748 == 0) {
        func_00286BE0(D_2EB748, D_002D33F0);
    }
    return D_2EB748;
}

extern "C" void *__tf9CCharaRes(void) {
    if (*(s32 *)D_2EB750 == 0) {
        func_00286BE0(D_2EB750, D_002D3578);
    }
    return D_2EB750;
}

extern "C" void func_00293EC0(u8 *p, s32 v) { *(s32 *)(p + 0x8C) = v; }

extern "C" u8 *func_00293EC8(u8 *p) { return p + 0x20; }

extern "C" s32 func_00293ED0(u8 *p) { return *(s32 *)(p + 0x50); }

extern "C" s32 func_00293ED8(u8 *p) { return *(s32 *)(p + 0x14); }

extern "C" s32 func_00293EE0(u8 *p) { return *(s32 *)(p + 0x18); }

extern "C" u8 *func_00293EE8(u8 *p) { return p + 0x60; }

extern "C" u8 *func_00293EF0(u8 *p) { return p + 0x70; }

extern "C" s32 func_00293EF8(u8 *p) { return *(s32 *)(p + 0x80); }

extern "C" s32 func_00293F00(u8 *p, s32 i) { return ((s32 *)(p + 0xA8))[i]; }

extern "C" void func_00293F10(u8 *p, s32 v) { *(s32 *)(p + 0xB4) = v; }

extern "C" s32 func_00293F18(u8 *p) { return *(s32 *)(p + 0xB4); }

extern "C" void *__tf9CCharaObj(void) {
    if (*(s32 *)D_4246C0 == 0) {
        func_002941B0();
        func_00286BC0(D_4246C0, D_002D3758, D_4246B0);
    }
    return D_4246C0;
}

extern "C" s32 func_00293F70(u8 *p) { return *(s32 *)(p + 0x14); }

extern "C" void func_00293F78(u8 *p, const CVec4 *v) { Func270C50((CVec4 *)(p + 0xA0), v); }

extern "C" void func_00293F98(u8 *p, const CVec4 *v) { Func270C50((CVec4 *)(p + 0xB0), v); }

extern "C" void func_00293FB8(u8 *p, const CVec4 *v) { Func270C50((CVec4 *)(p + 0xC0), v); }

extern "C" void func_00293FD8(u8 *p, const CVec4 *v) { Func270C50((CVec4 *)(p + 0xD0), v); }

extern "C" void func_00293FF8(u8 *p, void *v) { Func270CA0((CVec4 *)(p + 0xE0), v); }

extern "C" u8 *func_00294018(u8 *p) { return p + 0xA0; }

extern "C" u8 *func_00294020(u8 *p) { return p + 0xB0; }

extern "C" u8 *func_00294028(u8 *p) { return p + 0xC0; }

extern "C" u8 *func_00294030(u8 *p) { return p + 0xD0; }

extern "C" u8 *func_00294038(u8 *p) { return p + 0xE0; }

extern "C" s32 func_00294040(u8 *p) { return *(s32 *)(p + 0x28); }

extern "C" s32 func_00294048(u8 *p) { return *(s32 *)(p + 0x2C); }

extern "C" s32 func_00294050(u8 *p) { return *(s32 *)(p + 0x30); }

extern "C" void func_00294058(u8 *p, const CVec4 *v) { Func270C50((CVec4 *)(p + 0x120), v); }

extern "C" u8 *func_00294078(u8 *p) { return p + 0x120; }

extern "C" void func_00294080(u8 *p, f32 v) { *(f32 *)(p + 0x130) = v; }

extern "C" f32 func_00294088(u8 *p) { return *(f32 *)(p + 0x13C); }

extern "C" void func_00294090(u8 *p, s32 v) { *(s32 *)(p + 0x1A4) = v; }

extern "C" s32 func_00294098(u8 *p) { return *(s32 *)(p + 0x1A4); }

extern "C" void func_002940A0(u8 *p, s32 v) { *(s32 *)(p + 0x140) = v; }

extern "C" s32 func_002940A8(u8 *p) { return *(s32 *)(p + 0x140); }

extern "C" void func_002940B0(u8 *p, s32 v) { *(s32 *)(p + 0x144) = v; }

extern "C" s32 func_002940B8(u8 *p) { return *(s32 *)(p + 0x144); }

extern "C" void func_002940C0(u8 *p, s32 v) { *(s32 *)(p + 0x148) = v; }

extern "C" s32 func_002940C8(u8 *p) { return *(s32 *)(p + 0x148); }
