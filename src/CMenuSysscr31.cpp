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
#include "CMenuProcess.h"
#include "CBgWork.h"
#include "CCommandBase.h"

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuSysscr31.
// Release1A7AF8 and the factory sit at the end of CMenuSysscr32.cpp (unit text starts late).
class CMenuSysscr31 : public CMenuProcess {
public:
    CMenuSysscr31();
    virtual ~CMenuSysscr31();
    virtual s32 Update();
    virtual s32 Draw();
    void Release1A7AF8();
    void Release1A8DC0();

    CBgWork m_bg;             // 0x58
    void *m_unk64;            // 0x64
    CCommandBase *m_cmd;      // 0x68
    void *m_unk6C;            // 0x6C
    u8 pad70[0x8];
    s32 m_unk78;              // 0x78
    s32 m_unk7C;              // 0x7C
    s32 m_unk80;              // 0x80
};
// @decl-end

CMenuSysscr31::CMenuSysscr31() {
    m_unk64 = 0;
    m_cmd = 0;
    m_unk78 = 0;
    m_unk7C = 0;
    m_unk80 = 0;
}

CMenuSysscr31::~CMenuSysscr31() {
    Release1A7AF8();
}



INCLUDE_RODATA("asm/nonmatchings/CMenuSysscr31", D_002DF0F8);
INCLUDE_ASM("asm/nonmatchings/CMenuSysscr31", Update__13CMenuSysscr31);
INCLUDE_RODATA("asm/nonmatchings/CMenuSysscr31", D_002DF110);
INCLUDE_RODATA("asm/nonmatchings/CMenuSysscr31", D_002DF118);
INCLUDE_RODATA("asm/nonmatchings/CMenuSysscr31", D_002DF138);

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr31", Draw__13CMenuSysscr31);

CMenuSysscr27 *CMenuSysscr27::Create() {
    CMenuSysscr27 *p = (CMenuSysscr27 *)operator new(0x78);
    func_001A8E28(p);
    return p;
}

void CMenuSysscr31::Release1A8DC0() {
    func_00245818(&m_bg, 1);
    D_002A4308->Func188BA8();
    if (m_cmd) {
        operator delete(m_cmd);
        m_cmd = 0;
    }
    if (m_unk64) {
        func_00189270(m_unk64, 3);
        m_unk64 = 0;
    }
}
