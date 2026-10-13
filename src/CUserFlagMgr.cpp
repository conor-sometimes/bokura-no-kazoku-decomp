#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
//@sym strcmp 0x28B190
#include "libc.h"
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_0013F2E8);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_0013F390);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_0013F488);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_0013F648);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_0013F740);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_0013F7B0);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_0013F820);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_0013F890);

int CompareUserFlagNames(const char **a, const char **b) {
    return strcmp(*a, *b);
}

int CompareUserFlagNames2(const char **a, const char **b) {
    return strcmp(*a, *b);
}

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_0013F948);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_0013FD00);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_0013FF08);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_00140040);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_00140088);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_001400B0);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_001400F0);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_00140160);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_001401B8);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_00140250);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_001402B0);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_00140358);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_00140440);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_001408C8);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_00140900);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_00140938);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_001409A8);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_00140D40);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_00140EA0);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_00140EE0);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_00140FB0);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_00141030);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_001410E8);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_001411B8);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_00141280);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_001412D0);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_00141560);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_00141768);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_00141F68);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_00142318);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_001425D8);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_00142A70);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_00142B38);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_00142BD8);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_00142C90);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_00142CE8);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_001432E0);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_00143328);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_00143478);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_001436E0);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_00143808);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_00143848);

int InRange(int v, int lo, int hi) {
    return v >= lo && v <= hi;
}

int OutOfRange(int v, int lo, int hi) {
    return v < lo || v > hi;
}

int Clamp(int v, int lo, int hi) {
    int r = (v < hi) ? v : hi;
    return (r < lo) ? lo : r;
}

int Min(int a, int b) {
    return (a < b) ? a : b;
}

int Max(int a, int b) {
    return (b < a) ? a : b;
}

int Abs(int x) {
    return x < 0 ? -x : x;
}

int InRangeF(f32 v, f32 lo, f32 hi) {
    return v >= lo && v <= hi;
}

int OutOfRangeF(f32 v, f32 lo, f32 hi) {
    return v < lo || hi < v;
}

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_00143970);

f32 MinF(f32 a, f32 b) {
    return (a < b) ? a : b;
}

f32 MaxF(f32 a, f32 b) {
    return (b < a) ? a : b;
}

f32 AbsF(f32 x) {
    return x >= 0.0f ? x : -x;
}

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_001439F8);
