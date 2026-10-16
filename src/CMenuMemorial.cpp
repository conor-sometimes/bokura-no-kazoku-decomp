#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

class CUnk1A4298 {
public:
    int Func1A4298();
};

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuMemorial.
class CMenuMemorial : public CMenuProcess {
public:
    CMenuMemorial();
    virtual ~CMenuMemorial();
    virtual s32 Update();
    virtual s32 Draw();

    CUnk1A4298 *m_unk58;      // 0x58
};

//@sym __builtin_new 0x245648
//@sym __17CMenuLoadMemorial 0x176B98
class CMenuLoadMemorial {
public:
    CMenuLoadMemorial() throw();

    u8 pad0[0x7DC0];
};

#include "CMenuMgrSub1B6BA8.h"
extern CMenuMgrSub1B6BA8 *D_002A55AC;
class CMenuTutorSelectedSub182108 {
public:
    void GetCursorPos(f32 *x, f32 *y);
};
#include "CMenuMgrSub1B6418.h"
extern CMenuMgrSub1B6418 *D_002A5538;
extern "C" void func_001829E8(void *p, s32 v);
// CMenuLoadMemorial's unit starts here (its text starts before its first vtable function).
class CMenuLoadMemorialPart {
public:
    void Func176AE0();

    u8 pad0[0x64];
    s32 m_unk64;              // 0x64
    u8 pad68[0x58];
    CMenuTutorSelectedSub182108 m_unkC0; // 0xC0
};
// @decl-end

CMenuMemorial::CMenuMemorial() {
    m_unk58 = 0;
}

CMenuMemorial::~CMenuMemorial() {
}

INCLUDE_ASM("asm/nonmatchings/CMenuMemorial", Update__13CMenuMemorial);
INCLUDE_RODATA("asm/nonmatchings/CMenuMemorial", D_002DA5D8);
INCLUDE_RODATA("asm/nonmatchings/CMenuMemorial", D_002DA5F8);

s32 CMenuMemorial::Draw() {
    return m_unk58->Func1A4298();
}

CMenuLoadMemorial *CreateCMenuLoadMemorial() {
    return new CMenuLoadMemorial;
}

void CMenuLoadMemorialPart::Func176AE0() {
    f32 x, y;
    func_001829E8(&m_unkC0, m_unk64);
    m_unkC0.GetCursorPos(&x, &y);
    D_002A5538->Move1B6488(x, y);
}

int HasMemorialSave() {
    s32 i;
    for (i = 0; i < 30; i++) {
        if (D_002A55AC->Check1B7428(i) == 1) {
            return 1;
        }
    }
    return 0;
}
