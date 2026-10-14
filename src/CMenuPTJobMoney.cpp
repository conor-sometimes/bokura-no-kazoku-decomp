#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

class CMenuGetMoney {
public:
    CMenuGetMoney() throw();
    static CMenuGetMoney *Create();

    u8 pad0[0x7C];
};

class CFlagWork {
public:
    int Func1091B0(int id);
};
extern CFlagWork *D_002A5358;
extern char D_002DBA30[];

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuPTJobMoney.
class CMenuPTJobMoney : public CMenuProcess {
public:
    CMenuPTJobMoney();
    virtual ~CMenuPTJobMoney();
    virtual s32 Update();
    virtual s32 Draw();

    s32 m_unk58;              // 0x58
    s32 m_unk5C;              // 0x5C
    s32 m_unk60;              // 0x60
    u8 pad64[0x4];
    s32 m_childNum;           // 0x68
    s32 m_unk6C;              // 0x6C
    s32 m_unk70;              // 0x70
    s32 m_unk74;              // 0x74
    s32 m_unk78;              // 0x78
    f32 m_unk7C;              // 0x7C
};

inline f32 Clamp01(f32 v) { return (v < 1.0f ? v : 1.0f) < 0.0f ? 0.0f : (v < 1.0f ? v : 1.0f); }
// CMenuGetMoney's unit starts here (its text starts before its first vtable function).
class CMenuGetMoneyPart {
public:
    void SetRate(f32 v);
    void SetScale(f32 v);

    u8 pad0[0x68];
    s32 m_unk68;              // 0x68
    u8 pad6C[0x4];
    s32 m_unk70;              // 0x70
    s32 m_unk74;              // 0x74
    f32 m_unk78;              // 0x78
};
// @decl-end

CMenuPTJobMoney::CMenuPTJobMoney() {
    m_unk58 = 0;
    m_unk5C = 0;
    m_childNum = D_002A5358->Func1091B0(0x251);
    if ((u32)m_childNum >= 7) {
        Func235DE0(D_002DBA30, m_childNum);
        m_childNum = 1;
    }
    m_unk60 = 0;
    m_unk6C = 0;
    m_unk70 = 0;
    m_unk74 = 0;
    m_unk78 = 0;
    m_unk7C = 1.0f;
}

CMenuPTJobMoney::~CMenuPTJobMoney() {
}

INCLUDE_RODATA("asm/nonmatchings/CMenuPTJobMoney", D_002DB5E0);
INCLUDE_RODATA("asm/nonmatchings/CMenuPTJobMoney", D_002DB5E8);
INCLUDE_RODATA("asm/nonmatchings/CMenuPTJobMoney", D_002DB5F0);
INCLUDE_RODATA("asm/nonmatchings/CMenuPTJobMoney", D_002DB600);
INCLUDE_RODATA("asm/nonmatchings/CMenuPTJobMoney", D_002DB608);
INCLUDE_RODATA("asm/nonmatchings/CMenuPTJobMoney", D_002DB610);
INCLUDE_RODATA("asm/nonmatchings/CMenuPTJobMoney", D_002DB618);
INCLUDE_RODATA("asm/nonmatchings/CMenuPTJobMoney", D_002DB640);
INCLUDE_RODATA("asm/nonmatchings/CMenuPTJobMoney", D_002DB668);
INCLUDE_RODATA("asm/nonmatchings/CMenuPTJobMoney", D_002DB678);
INCLUDE_RODATA("asm/nonmatchings/CMenuPTJobMoney", D_002DB690);
INCLUDE_RODATA("asm/nonmatchings/CMenuPTJobMoney", D_002DB6B8);
INCLUDE_RODATA("asm/nonmatchings/CMenuPTJobMoney", jtbl_002DB6E0);
INCLUDE_RODATA("asm/nonmatchings/CMenuPTJobMoney", D_002DB700);
INCLUDE_RODATA("asm/nonmatchings/CMenuPTJobMoney", jtbl_002DB710);
INCLUDE_RODATA("asm/nonmatchings/CMenuPTJobMoney", D_002DB730);
INCLUDE_RODATA("asm/nonmatchings/CMenuPTJobMoney", D_002DB810);
INCLUDE_RODATA("asm/nonmatchings/CMenuPTJobMoney", D_002DB8F0);
INCLUDE_RODATA("asm/nonmatchings/CMenuPTJobMoney", D_002DB8F8);
INCLUDE_RODATA("asm/nonmatchings/CMenuPTJobMoney", D_002DB920);
INCLUDE_RODATA("asm/nonmatchings/CMenuPTJobMoney", D_002DB958);
INCLUDE_RODATA("asm/nonmatchings/CMenuPTJobMoney", D_002DB980);
INCLUDE_RODATA("asm/nonmatchings/CMenuPTJobMoney", D_002DB988);
INCLUDE_RODATA("asm/nonmatchings/CMenuPTJobMoney", D_002DB990);
INCLUDE_RODATA("asm/nonmatchings/CMenuPTJobMoney", jtbl_002DB9B0);
INCLUDE_RODATA("asm/nonmatchings/CMenuPTJobMoney", D_002DB9D0);
INCLUDE_RODATA("asm/nonmatchings/CMenuPTJobMoney", D_002DBA08);
INCLUDE_RODATA("asm/nonmatchings/CMenuPTJobMoney", D_002DBA18);
INCLUDE_RODATA("asm/nonmatchings/CMenuPTJobMoney", D_002DBA30);
INCLUDE_ASM("asm/nonmatchings/CMenuPTJobMoney", Update__15CMenuPTJobMoney);

INCLUDE_ASM("asm/nonmatchings/CMenuPTJobMoney", Draw__15CMenuPTJobMoney);

CMenuGetMoney *CMenuGetMoney::Create() {
    return new CMenuGetMoney;
}

void CMenuGetMoneyPart::SetRate(f32 v) {
    f32 r = Clamp01(v);
    m_unk70 = (s32)(m_unk68 * r);
    m_unk74 = (s32)(f32)m_unk70 + D_002A5358->Func1091B0(0x24D);
}

void CMenuGetMoneyPart::SetScale(f32 v) {
    m_unk78 = 2.0f - Clamp01(v);
}
