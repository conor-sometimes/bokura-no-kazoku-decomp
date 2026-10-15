#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

class CUnk1A4298 {
public:
    int Func1A4298();
};

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuNews.
class CMenuNews : public CMenuProcess {
public:
    CMenuNews();
    virtual ~CMenuNews();
    virtual s32 Update();
    virtual s32 Draw();

    CUnk1A4298 *m_unk58;      // 0x58
};

class CMenuExGetMoney {
public:
    CMenuExGetMoney() throw();

    u8 pad0[0x78];
};

#include "CFlagWork.h"
extern CFlagWork *D_002A5358;
inline f32 Clamp01(f32 v) { return (v < 1.0f ? v : 1.0f) < 0.0f ? 0.0f : (v < 1.0f ? v : 1.0f); }
// CMenuExGetMoney's unit starts here (its text starts before its first vtable function).
class CMenuExGetMoneyPart {
public:
    void SetRate(f32 v);
    void SetScale(f32 v);

    u8 pad0[0x64];
    s32 m_unk64;              // 0x64
    u8 pad68[0x4];
    s32 m_unk6C;              // 0x6C
    s32 m_unk70;              // 0x70
    f32 m_unk74;              // 0x74
};
// @decl-end

CMenuNews::CMenuNews() {
    m_unk58 = 0;
}

CMenuNews::~CMenuNews() {
}

INCLUDE_ASM("asm/nonmatchings/CMenuNews", Update__9CMenuNews);
INCLUDE_RODATA("asm/nonmatchings/CMenuNews", D_002DA3D0);
INCLUDE_RODATA("asm/nonmatchings/CMenuNews", D_002DA3F0);

s32 CMenuNews::Draw() {
    return m_unk58->Func1A4298();
}

CMenuExGetMoney *CreateCMenuExGetMoney() {
    return new CMenuExGetMoney;
}

void CMenuExGetMoneyPart::SetRate(f32 v) {
    f32 r = Clamp01(v);
    m_unk6C = (s32)(m_unk64 * r);
    m_unk70 = (s32)(f32)m_unk6C + D_002A5358->Func1091B0(0x24D);
}

void CMenuExGetMoneyPart::SetScale(f32 v) {
    m_unk74 = 2.0f - Clamp01(v);
}
