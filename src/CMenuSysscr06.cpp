#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" void func_001ACCE8(void *p);
class CMenuSysscr05 {
public:
    static CMenuSysscr05 *Create();
};

#include "CMenuProcess.h"

// Vptr at 0; only the calls are needed here.
class CMenuInputKanji {
public:
    virtual s32 Func1A4FE0();
    virtual s32 Func29B570();
    virtual s32 Func29B578();
    virtual s32 Func1A5048();
    virtual s32 Func1A50C8();
    virtual s32 Func1A64D0();
    virtual s32 Func1A4F78();
};

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuSysscr06.
class CMenuSysscr06 : public CMenuProcess {
public:
    CMenuSysscr06();
    virtual ~CMenuSysscr06();
    virtual s32 Update();
    virtual s32 Draw();

    CMenuInputKanji *m_win;   // 0x58
    u8 m_name[0x12];          // 0x5C
};
// @decl-end

CMenuSysscr06::CMenuSysscr06() {
    s32 i;
    for (i = 0; i < 8; i++) {
        m_name[i * 2] = 0x81;
        m_name[i * 2 + 1] = 0x40;
    }
}

CMenuSysscr06::~CMenuSysscr06() {
}

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr06", Update__13CMenuSysscr06);
INCLUDE_RODATA("asm/nonmatchings/CMenuSysscr06", D_002DF6A8);

s32 CMenuSysscr06::Draw() {
    if (m_win) {
        return m_win->Func1A64D0();
    }
    Func225088();
    return Func2250C0();
}

CMenuSysscr05 *CMenuSysscr05::Create() {
    CMenuSysscr05 *p = (CMenuSysscr05 *)operator new(0x5C);
    func_001ACCE8(p);
    return p;
}
