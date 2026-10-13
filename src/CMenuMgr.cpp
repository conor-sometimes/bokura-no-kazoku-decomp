#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern void *D_002A5530;
extern void *D_002A5534;

class CUnk2320F8 {
public:
    int Func2320F8();
};

class CUnk2A55B0 {
public:
    int Func1B76D0(void *p);
    int Func1B7910();
};
extern CUnk2A55B0 *D_002A55B0;

class CSndWork {
public:
    void Func25C648(s32 a, s32 b = 0);
    void Func25C840(s32 a, s32 b = 0, s32 c = 0);
    int Func25C990(s32 a);
};

class CMenuMgr {
public:
    void SetUnk70(s32 v);
    int GetMenuId();
    void SndFunc25C648(s32 a);
    void SndFunc25C840(s32 a);
    int SndFunc25C990(s32 a);

    u8 pad0[0x70];
    s32 m_unk70;              // 0x70
    CSndWork m_snd;           // 0x74
};

// Placeholder for the class of 0x1B4768-0x1B4E28 (name unknown).
class CMenuMgrSub1B4768 {
public:
    void Init();
    u64 SwapUnk0(u64 v);
    u64 SwapUnk8(u64 v);
    void SetUnk20(f32 x, f32 y, f32 z);
    void SetUnk30(f32 x, f32 y, f32 z, f32 w);
    void SetUnk40(f32 x, f32 y, f32 z, f32 w);
    void SetUnk4C(f32 v);
    void SetUnk50(s32 v);

    u64 m_unk0;               // 0x0
    u64 m_unk8;               // 0x8
    s32 m_unk10;              // 0x10
    s32 m_unk14;              // 0x14
    u8 pad18[0x8];
    f32 m_unk20;              // 0x20
    f32 m_unk24;              // 0x24
    f32 m_unk28;              // 0x28
    u8 pad2C[0x4];
    f32 m_unk30;              // 0x30
    f32 m_unk34;              // 0x34
    f32 m_unk38;              // 0x38
    f32 m_unk3C;              // 0x3C
    f32 m_unk40;              // 0x40
    f32 m_unk44;              // 0x44
    f32 m_unk48;              // 0x48
    f32 m_unk4C;              // 0x4C
    s32 m_unk50;              // 0x50
    s32 m_unk54;              // 0x54
    s32 m_unk58;              // 0x58
};
// Placeholder for the class of 0x1B5BF8-0x1B5E08 (name unknown).
class CMenuMgrSub1B5BF8 {
public:
    void Init();
    void CallReset();
    u64 SwapUnk20(u64 v);
    u64 SwapUnk28(u64 v);
    void Reset();
    void SetUnk0(f32 x, f32 y);
    void SetUnk10(f32 x, f32 y, f32 z);
    void SetUnk1C(f32 v);
    void SetUnk30(s32 v);
    void SetUnk34(s32 v);
    void SetUnk5C(s32 v);

    f32 m_unk0;               // 0x0
    f32 m_unk4;               // 0x4
    u8 pad8[0x8];
    f32 m_unk10;              // 0x10
    f32 m_unk14;              // 0x14
    f32 m_unk18;              // 0x18
    f32 m_unk1C;              // 0x1C
    u64 m_unk20;              // 0x20
    u64 m_unk28;              // 0x28
    s32 m_unk30;              // 0x30
    s32 m_unk34;              // 0x34
    s32 m_unk38;              // 0x38
    u8 pad3C[0x20];
    s32 m_unk5C;              // 0x5C
};

// Placeholder for the class of 0x1B6418-0x1B6558 (name unknown).
class CMenuMgrSub1B6418 {
public:
    u64 SwapUnk60(u64 v);
    u64 SwapUnk68(u64 v);
    void SetUnkE0(s32 v);
    void SetUnk0And20(f32 x, f32 y);
    void SetUnk40(f32 x, f32 y, f32 z, f32 w);
    void SetUnk4C(f32 v);
    void GetDefaultSize(f32 *w, f32 *h);

    f32 m_unk0;               // 0x0
    f32 m_unk4;               // 0x4
    u8 pad8[0x18];
    f32 m_unk20;              // 0x20
    f32 m_unk24;              // 0x24
    u8 pad28[0x18];
    f32 m_unk40;              // 0x40
    f32 m_unk44;              // 0x44
    f32 m_unk48;              // 0x48
    f32 m_unk4C;              // 0x4C
    u8 pad50[0x10];
    u64 m_unk60;              // 0x60
    u64 m_unk68;              // 0x68
    u8 pad70[0x70];
    s32 m_unkE0;              // 0xE0
};

class CMenuMgrSub1B74F8 {
public:
    int CallFunc2320F8();

    u8 pad0[0x5C];
    CUnk2320F8 m_unk5C;       // 0x5C
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B3C68);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B3DD0);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B3FC8);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B4050);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B41B8);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B4230);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B42A0);

void CMenuMgr::SetUnk70(s32 v) {
    m_unk70 = v;
}

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B4318);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B4418);

int CMenuMgr::GetMenuId() {
    return 0x2B;
}

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B44C0);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B44F8);

void CMenuMgr::SndFunc25C648(s32 a) {
    m_snd.Func25C648(a);
}

void CMenuMgr::SndFunc25C840(s32 a) {
    m_snd.Func25C840(a);
}

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B4578);

int CMenuMgr::SndFunc25C990(s32 a) {
    return m_snd.Func25C990(a);
}

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B45E8);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B46C8);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B4730);

void CMenuMgrSub1B4768::Init() {
    D_002A5530 = this;
    m_unk10 = 0;
    m_unk14 = 0;
    m_unk54 = 0;
    m_unk58 = 0;
}

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B4788);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B47E8);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B4820);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B4BF8);

u64 CMenuMgrSub1B4768::SwapUnk0(u64 v) {
    u64 old = m_unk0;
    m_unk0 = v;
    return old;
}

u64 CMenuMgrSub1B4768::SwapUnk8(u64 v) {
    u64 old = m_unk8;
    m_unk8 = v;
    return old;
}

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B4CD0);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B4D28);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B4DA8);

void CMenuMgrSub1B4768::SetUnk20(f32 x, f32 y, f32 z) {
    m_unk20 = x;
    m_unk24 = y;
    m_unk28 = z;
}

void CMenuMgrSub1B4768::SetUnk30(f32 x, f32 y, f32 z, f32 w) {
    m_unk30 = x;
    m_unk34 = y;
    m_unk38 = z;
    m_unk3C = w;
}

void CMenuMgrSub1B4768::SetUnk40(f32 x, f32 y, f32 z, f32 w) {
    m_unk40 = x;
    m_unk44 = y;
    m_unk48 = z;
    m_unk4C = w;
}

void CMenuMgrSub1B4768::SetUnk4C(f32 v) {
    m_unk4C = v;
}

void CMenuMgrSub1B4768::SetUnk50(s32 v) {
    m_unk50 = v;
}

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B4E30);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B4E70);

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_001B4EC8() {
}

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B4ED0);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B50B0);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B5568);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B55A0);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B5788);

void CMenuMgrSub1B5BF8::Init() {
    D_002A5534 = this;
    m_unk38 = 0;
}

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B5C08);

void CMenuMgrSub1B5BF8::CallReset() {
    Reset();
}

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B5C88);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B5D40);

u64 CMenuMgrSub1B5BF8::SwapUnk20(u64 v) {
    u64 old = m_unk20;
    m_unk20 = v;
    return old;
}

u64 CMenuMgrSub1B5BF8::SwapUnk28(u64 v) {
    u64 old = m_unk28;
    m_unk28 = v;
    return old;
}

void CMenuMgrSub1B5BF8::Reset() {
    m_unk0 = 1.0f;
    m_unk4 = 1.0f;
    m_unk10 = 1.0f;
    m_unk14 = 1.0f;
    m_unk18 = 1.0f;
    m_unk1C = 1.0f;
    m_unk30 = 0;
    m_unk34 = 0;
    m_unk5C = 0;
}

void CMenuMgrSub1B5BF8::SetUnk0(f32 x, f32 y) {
    m_unk0 = x;
    m_unk4 = y;
}

void CMenuMgrSub1B5BF8::SetUnk10(f32 x, f32 y, f32 z) {
    m_unk10 = x;
    m_unk14 = y;
    m_unk18 = z;
}

void CMenuMgrSub1B5BF8::SetUnk1C(f32 v) {
    m_unk1C = v;
}

void CMenuMgrSub1B5BF8::SetUnk30(s32 v) {
    m_unk30 = v;
}

void CMenuMgrSub1B5BF8::SetUnk34(s32 v) {
    m_unk34 = v;
}

void CMenuMgrSub1B5BF8::SetUnk5C(s32 v) {
    m_unk5C = v;
}

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_001B5E10() {
}

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B5E18);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B5F78);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B5FE0);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B6120);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B6158);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B6268);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B62A0);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B6300);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B6350);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B63A8);

u64 CMenuMgrSub1B6418::SwapUnk60(u64 v) {
    u64 old = m_unk60;
    m_unk60 = v;
    return old;
}

u64 CMenuMgrSub1B6418::SwapUnk68(u64 v) {
    u64 old = m_unk68;
    m_unk68 = v;
    return old;
}

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B6438);

void CMenuMgrSub1B6418::SetUnkE0(s32 v) {
    if (v != 1) {
        v = 0;
    }
    m_unkE0 = v;
}

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B6488);

void CMenuMgrSub1B6418::SetUnk0And20(f32 x, f32 y) {
    m_unk0 = x;
    m_unk4 = y;
    m_unk20 = x;
    m_unk24 = y;
}

void CMenuMgrSub1B6418::SetUnk40(f32 x, f32 y, f32 z, f32 w) {
    m_unk40 = x;
    m_unk44 = y;
    m_unk48 = z;
    m_unk4C = w;
}

void CMenuMgrSub1B6418::SetUnk4C(f32 v) {
    m_unk4C = v;
}

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B6518);

void CMenuMgrSub1B6418::GetDefaultSize(f32 *w, f32 *h) {
    *w = 24.0f;
    *h = 24.0f;
}

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B6570);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B66E8);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B6B48);

// Two BCD digits to an int (0x42 -> 42).
int BcdToInt(int bcd) {
    return ((bcd & 0xF0) >> 4) * 10 + (bcd & 0xF);
}

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B6BA8);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B6C38);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B6CA8);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B6DA8);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B6F00);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B6FA8);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B7008);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B70D8);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B7118);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B7188);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B72E0);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B7368);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B73A8);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B73E8);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B7428);

int CMenuMgrSub1B74F8::CallFunc2320F8() {
    return m_unk5C.Func2320F8();
}

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B7510);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B7658);

int CallFunc1B76D0(void *p) {
    return D_002A55B0->Func1B76D0(p);
}

int CallFunc1B7910() {
    return D_002A55B0->Func1B7910();
}

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", Func1B76D0__10CUnk2A55B0Pv);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", Func1B7910__10CUnk2A55B0);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B7C10);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B7CD8);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B7D78);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B7E28);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B7E70);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B7EF8);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B8500);

INCLUDE_ASM("asm/nonmatchings/CMenuMgr", func_001B85D8);
