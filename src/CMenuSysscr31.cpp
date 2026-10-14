#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" void func_001A8E28(void *p);
class CMenuSysscr27 {
public:
    static CMenuSysscr27 *Create();
};

class CChrBodyWin {
public:
    void Func188BA8();
};
extern CChrBodyWin *D_002A4308;
extern "C" int func_00245818(void *p, s32 v);
extern "C" void func_00189270(void *p, s32 v);
class CMenuSysscr31 {
public:
    void Release1A8DC0();
    u8 pad0[0x58];
    u8 m_unk58[0xC];          // 0x58
    void *m_unk64;            // 0x64
    void *m_unk68;            // 0x68
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr31", Init1A7B68__13CMenuSysscr32);

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr31", func_001A7BB8);

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr31", func_001A7C30);

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr31", func_001A8AD8);

CMenuSysscr27 *CMenuSysscr27::Create() {
    CMenuSysscr27 *p = (CMenuSysscr27 *)operator new(0x78);
    func_001A8E28(p);
    return p;
}

void CMenuSysscr31::Release1A8DC0() {
    func_00245818(m_unk58, 1);
    D_002A4308->Func188BA8();
    if (m_unk68) {
        operator delete(m_unk68);
        m_unk68 = 0;
    }
    if (m_unk64) {
        func_00189270(m_unk64, 3);
        m_unk64 = 0;
    }
}
