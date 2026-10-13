#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern void *D_002A53D4;
extern f32 D_002A53D8;
extern f32 D_002A53DC;
extern f32 D_002A53E0;
extern f32 D_002A53E4;

// The object a status window points to at 0x48 (methods at 0x1A3480 on, in CStatusWin.cpp).
class CStatusItem {
public:
    void Start();
    void Func1A3628();


    u8 pad0[0x20];
    s32 m_state;              // 0x20
    u8 pad24[0xC];
    s32 m_unk30;              // 0x30
    f32 m_unk34;              // 0x34
};

class CStatusBase {
public:
    f32 GetItemUnk34();
    s32 GetItemState();
    void Advance2To3();

    u8 pad0[0x48];
    CStatusItem* m_item;      // 0x48
    s32 m_state;              // 0x4C
    u8 pad50[0x4];
    s32 m_unk54;              // 0x54
};

class CStatusBaseSub19AE68 {
public:
    void Set(s32 v);
    s32 GetUnk18();

    s32 m_unk0;               // 0x0
    u8 pad4[0x4];
    s32 m_unk8;               // 0x8
    s32 m_unkC;               // 0xC
    s32 m_unk10;              // 0x10
    u8 pad14[0x4];
    s32 m_unk18;              // 0x18
};

class CStatusBaseSub19AF50 {
public:
    f32 GetItemUnk34();

    CStatusItem* m_item;      // 0x0
};

class CStatusBaseSub19B8C8 {
public:
    void Init();

    u8 pad0[0x4];
    s32 m_unk4;               // 0x4
};

class CStatusBaseSub19C400 {
public:
    void Init();

    u8 pad0[0x1C];
    s32 m_unk1C;              // 0x1C
    u8 pad20[0xA4];
    f32 m_unkC4;              // 0xC4
    s32 m_unkC8;              // 0xC8
    s32 m_unkCC;              // 0xCC
};

//@sym __builtin_delete 0x2456A8
class CStatusBaseSub19AD40 { public: ~CStatusBaseSub19AD40(); };
class CStatusBaseSub19AD70 {
public:
    void ItemFunc1A3628();
    void ItemStart();

    CStatusItem* m_item;      // 0x0
    u8 pad4[0x14];
    s32 m_unk18;              // 0x18
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CStatusBase", func_0019A830);

INCLUDE_ASM("asm/nonmatchings/CStatusBase", func_0019A858);

INCLUDE_ASM("asm/nonmatchings/CStatusBase", func_0019A8C0);

INCLUDE_ASM("asm/nonmatchings/CStatusBase", func_0019A900);

f32 CStatusBase::GetItemUnk34() {
    return m_item ? m_item->m_unk34 : 0.0f;
}

s32 CStatusBase::GetItemState() {
    return m_item ? m_item->m_state : -1;
}

void CStatusBase::Advance2To3() {
    if (m_state == 2) {
        m_unk54 = 0;
        m_state = 3;
    }
}

INCLUDE_ASM("asm/nonmatchings/CStatusBase", func_0019A990);

INCLUDE_ASM("asm/nonmatchings/CStatusBase", func_0019A9D8);

INCLUDE_ASM("asm/nonmatchings/CStatusBase", func_0019AC20);

CStatusBaseSub19AD40::~CStatusBaseSub19AD40() {
}

void CStatusBaseSub19AD70::ItemFunc1A3628() {
    m_item->Func1A3628();
    m_unk18 = 1;
}

void CStatusBaseSub19AD70::ItemStart() {
    m_item->Start();
    m_unk18 = 4;
}

INCLUDE_ASM("asm/nonmatchings/CStatusBase", func_0019ADD0);

void CStatusBaseSub19AE68::Set(s32 v) {
    m_unk8 = v;
    m_unk10 = 0;
    m_unkC = 0;
}

INCLUDE_ASM("asm/nonmatchings/CStatusBase", func_0019AE78);

INCLUDE_ASM("asm/nonmatchings/CStatusBase", func_0019AEC0);

s32 CStatusBaseSub19AE68::GetUnk18() {
    if (m_unk0 == 0) {
        return 0;
    }
    return m_unk18;
}

f32 CStatusBaseSub19AF50::GetItemUnk34() {
    return m_item->m_unk34;
}

INCLUDE_ASM("asm/nonmatchings/CStatusBase", func_0019AF60);

INCLUDE_ASM("asm/nonmatchings/CStatusBase", func_0019AFA8);

INCLUDE_ASM("asm/nonmatchings/CStatusBase", func_0019B1F8);

INCLUDE_ASM("asm/nonmatchings/CStatusBase", func_0019B858);

INCLUDE_ASM("asm/nonmatchings/CStatusBase", func_0019B890);

void CStatusBaseSub19B8C8::Init() {
    D_002A53D4 = this;
    m_unk4 = 0;
}

INCLUDE_ASM("asm/nonmatchings/CStatusBase", func_0019B8D8);

INCLUDE_ASM("asm/nonmatchings/CStatusBase", func_0019B938);

INCLUDE_ASM("asm/nonmatchings/CStatusBase", func_0019BA00);

INCLUDE_ASM("asm/nonmatchings/CStatusBase", func_0019C0F0);

INCLUDE_ASM("asm/nonmatchings/CStatusBase", func_0019C130);

INCLUDE_ASM("asm/nonmatchings/CStatusBase", func_0019C170);

void SetStatusColor(f32 r, f32 g, f32 b, f32 a) {
    D_002A53D8 = r;
    D_002A53DC = g;
    D_002A53E0 = b;
    D_002A53E4 = a;
}

INCLUDE_ASM("asm/nonmatchings/CStatusBase", func_0019C1E0);

INCLUDE_ASM("asm/nonmatchings/CStatusBase", func_0019C278);

void CStatusBaseSub19C400::Init() {
    m_unk1C = 3;
    m_unkC4 = D_002A53DC;
    m_unkC8 = 0;
    m_unkCC = 2;
}

INCLUDE_ASM("asm/nonmatchings/CStatusBase", func_0019C428);

INCLUDE_ASM("asm/nonmatchings/CStatusBase", func_0019C730);

INCLUDE_ASM("asm/nonmatchings/CStatusBase", func_0019CC90);

INCLUDE_ASM("asm/nonmatchings/CStatusBase", func_0019CCF8);
