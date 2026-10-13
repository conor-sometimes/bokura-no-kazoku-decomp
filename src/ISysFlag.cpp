#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern s32 D_002A2814;
extern s32 D_002A2818;

class CFlagWork {
public:
    void Func108FF0(s32 id);
    int Func1091B0(s32 id);
};

class CCurFlag : public CFlagWork {
public:
    void Func108FF0Cur2(u32 id);
    void Func108FF0Cur(s32 id);
    int Func1091B0Cur(s32 id);
    int Func1091B0Cur2(s32 id);
    s32 Select(s32 v);


};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00143A90);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00143B08);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00143B80);

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_00143BD0() {
}

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00143BD8);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00143CD0);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00143F20);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00143FA8);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00144070);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_001440F8);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_001441B8);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00144210);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00144270);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00144378);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00144440);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_001446D8);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00144770);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_001447A8);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00144808);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00144880);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00144A58);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00144AE8);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00144B68);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00144C60);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00144D68);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00144E28);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00145008);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00145090);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00145118);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00145160);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_001451E8);

void CCurFlag::Func108FF0Cur(s32 id) {
    Func108FF0(id + 0x1462);
}

int CCurFlag::Func1091B0Cur(s32 id) {
    return Func1091B0(id + 0x1462);
}

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00145280);

void CCurFlag::Func108FF0Cur2(u32 id) {
    if (id < 0xD00) {
        Func108FF0(id + 0x226A);
    }
}

int CCurFlag::Func1091B0Cur2(s32 id) {
    return Func1091B0(id + 0x226A);
}

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00145330);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00145398);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_001454F0);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00145558);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_001455D0);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00145610);

int IsFlagKind(int v) {
    return (v >= 2 && v <= 6) || v == 8;
}

int IsNine(int v) {
    return v == 9;
}

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_001456A8);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", Func145738__Fii);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00145808);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00145848);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00145888);

s32 CCurFlag::Select(s32 v) {
    return v ? D_002A2814 : D_002A2818;
}

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_001458F0);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00145A28);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00145AD0);

INCLUDE_ASM("asm/nonmatchings/ISysFlag", func_00145B98);
