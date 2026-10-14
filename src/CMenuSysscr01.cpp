#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

extern "C" void func_001AE488(void *p);
class CMenuSysscr00 {
public:
    static CMenuSysscr00 *Create();
};

extern "C" int func_001A7658(void *p);
class CMenuSub1A7658 {
public:
    u8 pad0[0x5C];
};

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuSysscr01.
class CMenuSysscr01 : public CMenuProcess {
public:
    CMenuSysscr01();
    virtual ~CMenuSysscr01();
    virtual s32 Update();
    virtual s32 Draw();

    CMenuSub1A7658 *m_unk58;  // 0x58
};
// @decl-end

CMenuSysscr01::CMenuSysscr01() {
    m_unk58 = 0;
}

CMenuSysscr01::~CMenuSysscr01() {
    if (m_unk58) {
        delete m_unk58;
        m_unk58 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr01", Update__13CMenuSysscr01);

s32 CMenuSysscr01::Draw() {
    if (m_unk58 == 0) {
        Func235DE0("*** SelectMenu is NULL!\n");
        Func225088();
        return Func2250C0();
    }
    return func_001A7658(m_unk58);
}

CMenuSysscr00 *CMenuSysscr00::Create() {
    CMenuSysscr00 *p = (CMenuSysscr00 *)operator new(0x60);
    func_001AE488(p);
    return p;
}

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr01", func_001AE3F8);
