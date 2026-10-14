#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" void func_001AAB60(void *p);
class CMenuSysscr24 {
public:
    static CMenuSysscr24 *Create();
};

#include "CMenuProcess.h"

extern "C" int func_001A7658(void *p);
// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuSysscr25.
class CMenuSysscr25 : public CMenuProcess {
public:
    CMenuSysscr25();
    virtual ~CMenuSysscr25();
    virtual s32 Update();
    virtual s32 Draw();

    void *m_unk58;            // 0x58
};
// @decl-end

CMenuSysscr25::CMenuSysscr25() {
    m_unk58 = 0;
}

CMenuSysscr25::~CMenuSysscr25() {
    if (m_unk58) {
        delete m_unk58;
        m_unk58 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr25", Update__13CMenuSysscr25);

s32 CMenuSysscr25::Draw() {
    if (m_unk58 == 0) {
        Func235DE0("*** SelectMenu is NULL!\n");
        Func225088();
        return Func2250C0();
    }
    return func_001A7658(m_unk58);
}

CMenuSysscr24 *CMenuSysscr24::Create() {
    CMenuSysscr24 *p = (CMenuSysscr24 *)operator new(0x7C);
    func_001AAB60(p);
    return p;
}
