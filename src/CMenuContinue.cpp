#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

class CMenuSub1A7658 {
public:
    int Func1A7658();
    void Func1A7308(s32 n);

    u8 pad0[0x54];
    s32 m_unk54;              // 0x54
    s32 m_unk58;              // 0x58
};
// The kana/selection window object (CMenuInputKanji.cpp); same object as CMenuSub1A7658.
class CMenuInputKanji {
public:
    void SetUnk4C(s32 v);
};
// The window item (CStatusWin.cpp).
class CStatusItem {
public:
    void Func1A3378();
    void SetUnkF0(s32 i, s32 v);
};
class CStatusWinSub1A0A10 {
public:
    CStatusItem *Find(const char *name);
};
extern CStatusWinSub1A0A10 *D_002A5408;
extern "C" void func_001A72D8(void *p, CStatusItem *item);
extern "C" void func_001A73B0(void *p);
void *operator new(unsigned int n);

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuContinue.
class CMenuContinue : public CMenuProcess {
public:
    CMenuContinue();
    virtual ~CMenuContinue();
    virtual s32 Update();
    virtual s32 Draw();

    CMenuSub1A7658 *m_unk58;  // 0x58
    CStatusItem *m_unk5C;     // 0x5C
};

//@sym __builtin_new 0x245648
//@sym __12CMenuAsksave 0x1929C8
class CMenuAsksave {
public:
    CMenuAsksave() throw();

    u8 pad0[0x60];
};
// @decl-end

CMenuContinue::CMenuContinue() {
    m_unk58 = 0;
}

CMenuContinue::~CMenuContinue() {
    if (m_unk58) {
        delete m_unk58;
        m_unk58 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/CMenuContinue", Update__13CMenuContinue);

s32 CMenuContinue::Draw() {
    if (!m_unk58) {
        Func235DE0("*** SelectMenu is NULL!\n");
        Func225088();
        return Func2250C0();
    }
    return m_unk58->Func1A7658();
}

CMenuAsksave *CreateCMenuAsksave() {
    return new CMenuAsksave;
}
