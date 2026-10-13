#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CMenuRecord {
public:
    int GetMenuId();


};

extern const char D_002DD7F8[];
class CMenuRecordWin {
public:
    void Func1A3740(s32 v, const char *s);
    void Func1A39A8(f32 *v, s32 *n, s32 k);
    void Func1A3B58(f32 *v, s32 *n, s32 k);
};
class CMenuRecordSub196E68 {
public:
    void CallFunc1A3740(s32 v);
    f32 GetWinValueA();
    f32 GetWinValueB();

    u8 pad0[0x48];
    CMenuRecordWin* m_win;    // 0x48
};

class CMenuRecordSub196FC8 {
public:
    int IsUnk4D4InWindow();

    u8 pad0[0x4D0];
    s32 m_unk4D0;             // 0x4D0
    s32 m_unk4D4;             // 0x4D4
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CMenuRecord", func_00194490);

INCLUDE_ASM("asm/nonmatchings/CMenuRecord", func_00194528);

INCLUDE_ASM("asm/nonmatchings/CMenuRecord", func_001945C0);

INCLUDE_ASM("asm/nonmatchings/CMenuRecord", func_00196388);

INCLUDE_ASM("asm/nonmatchings/CMenuRecord", func_00196938);

INCLUDE_ASM("asm/nonmatchings/CMenuRecord", func_00196B50);

INCLUDE_ASM("asm/nonmatchings/CMenuRecord", func_00196C70);

INCLUDE_ASM("asm/nonmatchings/CMenuRecord", func_00196D78);

void CMenuRecordSub196E68::CallFunc1A3740(s32 v) {
    m_win->Func1A3740(v + 0x24, D_002DD7F8);
}

INCLUDE_ASM("asm/nonmatchings/CMenuRecord", func_00196E90);

int CMenuRecordSub196FC8::IsUnk4D4InWindow() {
    s32 v = m_unk4D4;
    if (v >= 3) {
        if (v < m_unk4D0 + 3) {
            return 1;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/CMenuRecord", func_00196FF8);

INCLUDE_ASM("asm/nonmatchings/CMenuRecord", func_00197078);

INCLUDE_ASM("asm/nonmatchings/CMenuRecord", func_001970C8);

int CMenuRecord::GetMenuId() {
    return 0x31;
}

INCLUDE_ASM("asm/nonmatchings/CMenuRecord", func_00197108);

f32 CMenuRecordSub196E68::GetWinValueA() {
    f32 v;
    s32 n;
    m_win->Func1A39A8(&v, &n, 1);
    return v;
}

f32 CMenuRecordSub196E68::GetWinValueB() {
    f32 v;
    s32 n;
    m_win->Func1A3B58(&v, &n, 1);
    return v;
}

INCLUDE_ASM("asm/nonmatchings/CMenuRecord", func_001971A0);

INCLUDE_ASM("asm/nonmatchings/CMenuRecord", func_001971E0);

INCLUDE_ASM("asm/nonmatchings/CMenuRecord", func_00197260);

INCLUDE_ASM("asm/nonmatchings/CMenuRecord", func_001972E8);

INCLUDE_ASM("asm/nonmatchings/CMenuRecord", func_001974F8);

INCLUDE_ASM("asm/nonmatchings/CMenuRecord", func_001976A0);

INCLUDE_ASM("asm/nonmatchings/CMenuRecord", func_00197950);

INCLUDE_ASM("asm/nonmatchings/CMenuRecord", func_00197AE0);

INCLUDE_ASM("asm/nonmatchings/CMenuRecord", func_00197FA8);
