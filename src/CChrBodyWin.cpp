#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CStatusBase {
public:
    f32 GetItemUnk34();
};
class CFlagWork {
public:
    int Func1091B0(s32 id);
};
extern CFlagWork *D_002A464C;

class CStatusBaseSub19AE68 {
public:
    void Set(s32 v);
};

class CChrBodyWin {
public:
    int CallFunc1091B0(s32 id);
    void CallFunc188BA8();
    void Func188BA8();
    void SetUnk6C(s32 v);
    void SetMode1();
    void SetMode2();
    void SetMode6();
    void CallSetMode2();
    void Check2To3();
    void Check3To4();
    void SetMode5();
    f32 GetStatusUnk34();

    u8 pad0[0x48];
    s32 m_unk48;              // 0x48
    s32 m_mode;               // 0x4C
    u8 pad50[0x4];
    s32 m_unk54;              // 0x54
    u8 pad58[0xC];
    CStatusBase* m_status;    // 0x64
    u8 pad68[0x4];
    CStatusBaseSub19AE68* m_unk6C; // 0x6C
};

class CChrBodyWinSub188748 {
public:
    u64 SwapUnk188(u64 v);
    u64 SwapUnk190(u64 v);
    void SetUnk388(s32 v);
    void SetUnk380(s32 v);
    void SetUnk374(f32 v);
    void SetUnk378(f32 v);

    u8 pad0[0x188];
    u64 m_unk188;             // 0x188
    u64 m_unk190;             // 0x190
    u8 pad198[0x1DC];
    f32 m_unk374;             // 0x374
    f32 m_unk378;             // 0x378
    u8 pad37C[0x4];
    s32 m_unk380;             // 0x380
    u8 pad384[0x4];
    s32 m_unk388;             // 0x388
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_00187038);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_00187088);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_001870B8);

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_001871C0() {
}

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_001871C8() {
}

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_001871D0);

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_001872D8() {
}

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_001872E0);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_001875D8);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_00187610);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_00187680);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_00187758);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_001878F8);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_00187A00);

int CChrBodyWin::CallFunc1091B0(s32 id) {
    return D_002A464C->Func1091B0(id + 0xAE);
}

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_00187A68);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_00187D68);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_00187ED0);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_00188098);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_001883D0);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_00188450);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_001884B0);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_001884F0);

void CChrBodyWin::CallFunc188BA8() {
    Func188BA8();
}

u64 CChrBodyWinSub188748::SwapUnk188(u64 v) {
    u64 old = m_unk188;
    m_unk188 = v;
    return old;
}

u64 CChrBodyWinSub188748::SwapUnk190(u64 v) {
    u64 old = m_unk190;
    m_unk190 = v;
    return old;
}

void CChrBodyWinSub188748::SetUnk388(s32 v) {
    if (v) {
        m_unk388 = v;
    }
}

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_00188778);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_001888B8);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_00188910);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_00188948);

void CChrBodyWinSub188748::SetUnk380(s32 v) {
    m_unk380 = v;
}

void CChrBodyWinSub188748::SetUnk374(f32 v) {
    m_unk374 = v;
}

void CChrBodyWinSub188748::SetUnk378(f32 v) {
    m_unk378 = v;
}

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_001889F8);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", Func188BA8__11CChrBodyWin);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_00188C30);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_00188C98);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_00188CD8);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_00188F30);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_00189018);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_00189270);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_00189348);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_001893A0);

void CChrBodyWin::SetUnk6C(s32 v) {
    if (m_unk6C) {
        m_unk6C->Set(v);
    }
}

void CChrBodyWin::SetMode1() {
    m_mode = 1;
}

void CChrBodyWin::SetMode2() {
    m_mode = 2;
}

void CChrBodyWin::SetMode6() {
    m_mode = 6;
}

void CChrBodyWin::CallSetMode2() {
    SetMode2();
}

void CChrBodyWin::Check2To3() {
    if (m_unk48 == 2 && m_unk54) {
        m_mode = 3;
    }
}

void CChrBodyWin::Check3To4() {
    if (m_unk48 == 3) {
        m_mode = 4;
    }
}

void CChrBodyWin::SetMode5() {
    m_mode = 5;
}

f32 CChrBodyWin::GetStatusUnk34() {
    if (m_status) {
        return m_status->GetItemUnk34();
    }
    return 0.0f;
}

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_001895F8);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_0018A1F0);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_0018A3D8);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_0018A410);
