#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

// The window items (CStatusItem, CStatusWin.cpp; named after Func1A4298 there).
class CUnk1A4298 {
public:
    int Func1A4298();
    f32 GetUnk34() { return m_unk34; }

    u8 pad0[0x34];
    f32 m_unk34;              // 0x34
};
class CUnk237E90 {
public:
    int Func237E90(int v);
};
class CMenuMgrSub1B6418 {
public:
    void SetUnk4C(f32 v);
};
extern CMenuMgrSub1B6418 *D_002A5538;
extern "C" int func_001B66E8(void *p);
void *Func237570(int size);
void Func237A88(void *p, int n);
void *Func237C30(void *p);
void Func238158(void *p, int v);
void Func225088();
int Func2250C0();
void Func225240(int v);

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuReviewStart.
class CMenuReviewStart : public CMenuProcess {
public:
    CMenuReviewStart();
    virtual ~CMenuReviewStart();
    virtual s32 Update();
    virtual s32 Draw();

    CUnk1A4298 *m_unk58;      // 0x58
    CUnk1A4298 *m_unk5C;      // 0x5C
};

//@sym __builtin_new 0x245648
class CMenuContinue {
public:
    CMenuContinue() throw();

    u8 pad0[0x60];
};
// @decl-end

CMenuReviewStart::CMenuReviewStart() {
    m_unk58 = 0;
    m_unk5C = 0;
}

CMenuReviewStart::~CMenuReviewStart() {
}

INCLUDE_ASM("asm/nonmatchings/CMenuReviewStart", Update__16CMenuReviewStart);
INCLUDE_RODATA("asm/nonmatchings/CMenuReviewStart", D_002DBCC0);
INCLUDE_RODATA("asm/nonmatchings/CMenuReviewStart", D_002DBCE0);

s32 CMenuReviewStart::Draw() {
    u8 *p = (u8 *)Func237570(0x40);
    Func237A88(p, 4);
    Func238158(Func237C30(p + 0x30), 1);
    ((CUnk237E90 *)(p + 0x10))->Func237E90(m_unk58->Func1A4298());
    ((CUnk237E90 *)(p + 0x10))->Func237E90(m_unk5C->Func1A4298());
    D_002A5538->SetUnk4C(m_unk5C->GetUnk34());
    ((CUnk237E90 *)(p + 0x20))->Func237E90(func_001B66E8(D_002A5538));
    Func225088();
    Func225240((int)p);
    return Func2250C0();
}

CMenuContinue *CreateCMenuContinue() {
    return new CMenuContinue;
}
