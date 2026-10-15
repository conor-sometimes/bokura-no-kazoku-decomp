#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

class CStatusItem;
class CUnk1A4298 {
public:
    int Func1A4298();
};

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuSysscr00.
class CMenuSysscr00 : public CMenuProcess {
public:
    CMenuSysscr00();
    virtual ~CMenuSysscr00();
    virtual s32 Update();
    virtual s32 Draw();
    void Init1AE800();
    CStatusItem *Item() { return (CStatusItem *)m_unk58; }        // CMenuSave's constructor (that unit's name for it)

    CUnk1A4298 *m_unk58;    // 0x58
    f32 m_unk5C;              // 0x5C
};

void *operator new(unsigned int n);
CMenuSysscr00 *NewCMenuSysscr00();

class CMenuTutorSelectedSub182108 {
public:
    void Func1829E8(s32 v);
    void GetCursorPos(f32 *x, f32 *y);
};
class CMenuMgrSub1B6418 {
public:
    void Move1B6488(f32 x, f32 y);
};
extern CMenuMgrSub1B6418 *D_002A5538;
// The CMenuSave screen (0x7DC0 bytes, created by NewCMenuSysscr00); its code starts here.
class CMenuSave {
public:
    void Func1AE7A8();
    u8 pad0[0x64];
    s32 m64;                  // 0x64
    u8 pad68[0x58];
    u8 m_tutor[0x7C00];       // 0xC0: CMenuTutorSelectedSub182108
};
//@sym Func1829E8__27CMenuTutorSelectedSub182108i 0x1829E8
// @decl-end

CMenuSysscr00::CMenuSysscr00() {
    m_unk58 = 0;
}

CMenuSysscr00::~CMenuSysscr00() {
}

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr00", Update__13CMenuSysscr00);

s32 CMenuSysscr00::Draw() {
    return m_unk58->Func1A4298();
}

// Creates the CMenuSave screen.
CMenuSysscr00 *NewCMenuSysscr00() {
    CMenuSysscr00 *p = (CMenuSysscr00 *)operator new(0x7DC0);
    p->Init1AE800();
    return p;
}

void CMenuSave::Func1AE7A8() {
    f32 x, y;
    CMenuTutorSelectedSub182108 *t = (CMenuTutorSelectedSub182108 *)m_tutor;
    t->Func1829E8(m64);
    t->GetCursorPos(&x, &y);
    D_002A5538->Move1B6488(x, y);
}
