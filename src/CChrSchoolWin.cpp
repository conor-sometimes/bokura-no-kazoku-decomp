#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CChrSchoolWinSub186E80 {
public:
    void SetUnk60(f32 x, f32 y);

    u8 pad0[0x60];
    f32 m_unk60;              // 0x60
    f32 m_unk64;              // 0x64
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CChrSchoolWin", func_00186DF0);

void CChrSchoolWinSub186E80::SetUnk60(f32 x, f32 y) {
    m_unk60 = x;
    m_unk64 = y;
}

INCLUDE_ASM("asm/nonmatchings/CChrSchoolWin", func_00186E90);

INCLUDE_ASM("asm/nonmatchings/CChrSchoolWin", func_00186EC0);

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_00186F88() {
}

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_00186F90() {
}

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_00186F98() {
}

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_00186FA0() {
}

INCLUDE_ASM("asm/nonmatchings/CChrSchoolWin", func_00186FA8);
