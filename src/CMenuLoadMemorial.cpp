#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern void *D_002A3AF8;

class CMenuLoadMemorialSub178778 {
public:
    void SetUnk4(s32 v);
    void SetUnk50(f32 x, f32 y);
    void SetUnkAC(s32 v);
    void SetUnkB0(f32 x, f32 y);

    u8 pad0[0x4];
    s32 m_unk4;               // 0x4
    u8 pad8[0x48];
    f32 m_unk50;              // 0x50
    f32 m_unk54;              // 0x54
    u8 pad58[0x54];
    s32 m_unkAC;              // 0xAC
    f32 m_unkB0;              // 0xB0
    f32 m_unkB4;              // 0xB4
};

class CMenuLoadMemorialSub179568 {
public:
    void SetUnk50(f32 x, f32 y);

    u8 pad0[0x50];
    f32 m_unk50;              // 0x50
    f32 m_unk54;              // 0x54
};

class CMenuLoadMemorialSub17B3A0 {
public:
    int Init();
    void Func17B3E8();
    void CallFunc17B3E8();
    void SetUnk40(f32 x, f32 y, s32 v);
    void SetUnk10(f32 x, f32 y);
    void SetUnk20(f32 x, f32 y);
    void SetUnk30(f32 x, f32 y, f32 z, f32 w);
    void SetUnk3C(f32 v);

    s32 m_unk0;               // 0x0
    u8 pad4[0xC];
    f32 m_unk10;              // 0x10
    f32 m_unk14;              // 0x14
    u8 pad18[0x8];
    f32 m_unk20;              // 0x20
    f32 m_unk24;              // 0x24
    u8 pad28[0x8];
    f32 m_unk30;              // 0x30
    f32 m_unk34;              // 0x34
    f32 m_unk38;              // 0x38
    f32 m_unk3C;              // 0x3C
    f32 m_unk40;              // 0x40
    f32 m_unk44;              // 0x44
};

//@sym __builtin_delete 0x2456A8
// Empty destructors (GCC 2.96 deleting-destructor shape: delete when (in_chrg & 1)).
class CMenuLoadMemorialSub178690 { public: ~CMenuLoadMemorialSub178690(); };
class CMenuLoadMemorialSub1792B0 { public: ~CMenuLoadMemorialSub1792B0(); };
class CMenuLoadMemorialSub17A8D8 { public: ~CMenuLoadMemorialSub17A8D8(); };
class CMenuLoadMemorialSub17CAB8 { public: ~CMenuLoadMemorialSub17CAB8(); };
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_00176B98);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_00176BE0);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_00176D30);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_001785A0);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_00178650);

CMenuLoadMemorialSub178690::~CMenuLoadMemorialSub178690() {
}

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_001786C0);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_00178738);

void CMenuLoadMemorialSub178778::SetUnk4(s32 v) {
    m_unk4 = v;
}

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_00178780);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_001787E8);

void CMenuLoadMemorialSub178778::SetUnk50(f32 x, f32 y) {
    m_unk50 = x;
    m_unk54 = y;
}

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_00178938);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_00178978);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_001789B8);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_00178B30);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_00179198);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_00179270);

CMenuLoadMemorialSub1792B0::~CMenuLoadMemorialSub1792B0() {
}

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_001792E0);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_00179378);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_001793B8);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_001793F8);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_00179438);

void CMenuLoadMemorialSub178778::SetUnkAC(s32 v) {
    m_unkAC = v;
}

void CMenuLoadMemorialSub178778::SetUnkB0(f32 x, f32 y) {
    m_unkB0 = x;
    m_unkB4 = y;
}

void CMenuLoadMemorialSub179568::SetUnk50(f32 x, f32 y) {
    m_unk50 = x;
    m_unk54 = y;
}

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_00179578);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_001795B8);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_001795F8);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_00179790);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_0017A370);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_0017A828);

CMenuLoadMemorialSub17A8D8::~CMenuLoadMemorialSub17A8D8() {
}

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_0017A908);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_0017A968);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_0017AFC8);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_0017B030);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_0017B098);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_0017B1A8);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_0017B368);

// Returns int but has no return statement (keeps $v0 free, as in retail).
int CMenuLoadMemorialSub17B3A0::Init() {
    D_002A3AF8 = this;
}

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_0017B3B0);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", Func17B3E8__26CMenuLoadMemorialSub17B3A0);

void CMenuLoadMemorialSub17B3A0::CallFunc17B3E8() {
    Func17B3E8();
}

void CMenuLoadMemorialSub17B3A0::SetUnk40(f32 x, f32 y, s32 v) {
    m_unk0 = v;
    m_unk40 = x;
    m_unk44 = y;
}

void CMenuLoadMemorialSub17B3A0::SetUnk10(f32 x, f32 y) {
    m_unk10 = x;
    m_unk14 = y;
}

void CMenuLoadMemorialSub17B3A0::SetUnk20(f32 x, f32 y) {
    m_unk20 = x;
    m_unk24 = y;
}

void CMenuLoadMemorialSub17B3A0::SetUnk30(f32 x, f32 y, f32 z, f32 w) {
    m_unk30 = x;
    m_unk34 = y;
    m_unk38 = z;
    m_unk3C = w;
}

void CMenuLoadMemorialSub17B3A0::SetUnk3C(f32 v) {
    m_unk3C = v;
}

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_0017B4A0);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_0017B4D8);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_0017B680);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_0017B758);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_0017B850);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_0017BDF0);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_0017BFA0);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_0017C2C0);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_0017CA48);

CMenuLoadMemorialSub17CAB8::~CMenuLoadMemorialSub17CAB8() {
}

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_0017CAE8);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_0017CC00);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_0017CC38);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_0017CC70);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_0017D160);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_0017D1E8);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_0017D240);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_0017D3B0);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_0017DC50);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_0017DC88);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_0017DD28);

INCLUDE_ASM("asm/nonmatchings/CMenuLoadMemorial", func_0017DE18);
