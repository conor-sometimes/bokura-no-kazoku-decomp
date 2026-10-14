#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" void func_001AC488(void *p);
class CMenuSysscr07 {
public:
    static CMenuSysscr07 *Create();
};

#include "CMenuProcess.h"

extern "C" int func_001A7658(void *p);
// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuSysscr08.
class CMenuSysscr08 : public CMenuProcess {
public:
    CMenuSysscr08();
    virtual ~CMenuSysscr08();
    virtual s32 Update();
    virtual s32 Draw();

    void *m_unk58;            // 0x58
};
// @decl-end

CMenuSysscr08::CMenuSysscr08() {
    m_unk58 = 0;
}

CMenuSysscr08::~CMenuSysscr08() {
    if (m_unk58) {
        delete m_unk58;
        m_unk58 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr08", Update__13CMenuSysscr08);

s32 CMenuSysscr08::Draw() {
    if (m_unk58 == 0) {
        Func235DE0("*** SelectMenu is NULL!\n");
        Func225088();
        return Func2250C0();
    }
    return func_001A7658(m_unk58);
}

CMenuSysscr07 *CMenuSysscr07::Create() {
    CMenuSysscr07 *p = (CMenuSysscr07 *)operator new(0x60);
    func_001AC488(p);
    return p;
}
