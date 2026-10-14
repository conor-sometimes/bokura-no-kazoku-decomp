#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CChrSchoolWinSub186E80 {
public:
    void SetUnk60(f32 x, f32 y);

    u8 pad0[0x60];
    f32 m_unk60;              // 0x60
    f32 m_unk64;              // 0x64
};

class CUnk1A4298 {
public:
    int Func1A4298();
};
class CUnk237E90 {
public:
    int Func237E90(int v);
};
extern "C" u8 *func_00237570(s32 v);
extern "C" void func_00237A88(void *p, s32 v);
extern "C" void *func_00237C30(void *p);
extern "C" int func_00238158(void *p, s32 v);
void Func225088();
int Func2250C0();
void Func225240(s32 v);
class CChrSchoolWinObj {
public:
    void Func186FA8();
    u8 pad0[0x48];
    CUnk1A4298 *m_unk48;      // 0x48
    u8 pad4C[0x10];
    s32 m_unk5C;              // 0x5C
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

void CChrSchoolWinObj::Func186FA8() {
    char buf[256];
    u8 *p = func_00237570(0x60);
    func_00237A88(p, 6);
    func_00238158(func_00237C30(p + 0x50), 1);
    if (m_unk5C) {
        ((CUnk237E90 *)(p + 0x10))->Func237E90(m_unk48->Func1A4298());
    }
    Func225088();
    Func225240((s32)p);
    Func2250C0();
}
