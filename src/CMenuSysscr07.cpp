#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" void func_001AC820(void *p);
class CMenuSysscr06 {
public:
    static CMenuSysscr06 *Create();
};

extern char D_002DF658[];
extern "C" int func_001A7658(void *p);
#include "CMenuProcess.h"
// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuSysscr07.
class CMenuSysscr07 : public CMenuProcess {
public:
    CMenuSysscr07();
    virtual ~CMenuSysscr07();
    virtual s32 Update();
    virtual s32 Draw();

    u8 *m_unk58;              // 0x58
};
// @decl-end

CMenuSysscr07::CMenuSysscr07() {
    m_unk58 = 0;
}

CMenuSysscr07::~CMenuSysscr07() {
    if (m_unk58) {
        delete m_unk58;
        m_unk58 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr07", Update__13CMenuSysscr07);
INCLUDE_RODATA("asm/nonmatchings/CMenuSysscr07", D_002DF658);

s32 CMenuSysscr07::Draw() {
    if (m_unk58 == 0) {
        Func235DE0(D_002DF658);
        Func225088();
        return Func2250C0();
    }
    return func_001A7658(m_unk58);
}

CMenuSysscr06 *CMenuSysscr06::Create() {
    CMenuSysscr06 *p = (CMenuSysscr06 *)operator new(0x7C);
    func_001AC820(p);
    return p;
}
