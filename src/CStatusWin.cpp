#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern void *D_002A5408;

class CStatusItem {
public:
    void Func1A3628();
    void SetUnk34(f32 v);
    void Start();

    u8 pad0[0x20];
    s32 m_state;              // 0x20
    u8 pad24[0xC];
    s32 m_unk30;              // 0x30
    f32 m_unk34;              // 0x34
};

class CStatusWin {
public:
    void CallFunc19F400();
    void Func19F400();
    f32 GetItemUnk34();
    s32 GetItemState();
    void Advance2To3();
    void Advance2To4();
    void ItemFunc1A3628();
    void ItemStart();
    void SetUnk5C(s32 v);
    s32 GetItemState2();
    f32 GetItemUnk34_2();

    u8 pad0[0x48];
    CStatusItem* m_item;      // 0x48
    s32 m_state;              // 0x4C
    u8 pad50[0x4];
    s32 m_unk54;              // 0x54
    u8 pad58[0x4];
    s32 m_unk5C;              // 0x5C
};

class CStatusWinSub1A0A10 {
public:
    int Init();
    void Clear();
    u64 SwapUnk0(u64 v);
    u64 SwapUnk8(u64 v);

    u64 m_unk0;               // 0x0
    u64 m_unk8;               // 0x8
    s32 m_unk10;              // 0x10
    s32 m_unk14;              // 0x14
};

class CStatusWinSub1A40B8 {
public:
    void SetUnk80(f32 x, f32 y);

    u8 pad0[0x80];
    f32 m_unk80;              // 0x80
    f32 m_unk84;              // 0x84
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019CD98);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019D0A8);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019D138);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019D570);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019D5A0);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019DBA0);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019DD48);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019DDC0);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019DE80);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019E008);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019E0B8);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019E148);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019E300);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019E5C8);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019E6A0);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019E780);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019E8B0);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019ECB0);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019F200);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019F328);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019F390);

void CStatusWin::CallFunc19F400() {
    Func19F400();
}

INCLUDE_ASM("asm/nonmatchings/CStatusWin", Func19F400__10CStatusWin);

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_0019F498() {
}

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_0019F4A0() {
}

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019F4A8);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019F578);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019F5B8);

f32 CStatusWin::GetItemUnk34() {
    return m_item ? m_item->m_unk34 : 0.0f;
}

s32 CStatusWin::GetItemState() {
    return m_item ? m_item->m_state : -1;
}

void CStatusWin::Advance2To3() {
    if (m_state == 2) {
        m_unk54 = 0;
        m_state = 3;
    }
}

void CStatusWin::Advance2To4() {
    if (m_state == 2) {
        m_unk54 = 0;
        m_state = 4;
    }
}

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019F668);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019F6C0);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019FA50);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019FC30);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019FE18);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A00B0);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A0140);

void CStatusWin::ItemFunc1A3628() {
    if (m_item) {
        m_item->Func1A3628();
    }
}

void CStatusWin::ItemStart() {
    if (m_item) {
        m_item->Start();
    }
}

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A01C8);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A0280);

void CStatusWin::SetUnk5C(s32 v) {
    m_unk5C = v;
}

s32 CStatusWin::GetItemState2() {
    return m_item ? m_item->m_state : -1;
}

f32 CStatusWin::GetItemUnk34_2() {
    return m_item ? m_item->m_unk34 : 0.0f;
}

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A03E8);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A0510);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A09D8);

// Returns int but has no return statement (that is why $v1 holds the address).
int CStatusWinSub1A0A10::Init() {
    D_002A5408 = this;
}

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A0A20);

void CStatusWinSub1A0A10::Clear() {
    m_unk0 = 0;
    m_unk8 = 0;
    m_unk10 = 0;
    m_unk14 = 0;
}

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A0A98);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A0C58);

u64 CStatusWinSub1A0A10::SwapUnk0(u64 v) {
    u64 old = m_unk0;
    m_unk0 = v;
    return old;
}

u64 CStatusWinSub1A0A10::SwapUnk8(u64 v) {
    u64 old = m_unk8;
    m_unk8 = v;
    return old;
}

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A0CF0);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A0D98);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A1040);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A1418);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A18B0);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A1AA0);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A1B38);

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_001A1BE8() {
}

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A1BF0);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A1CF0);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A3378);

void CStatusItem::SetUnk34(f32 v) {
    m_unk34 = v;
}

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A3488);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A3590);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", Func1A3628__11CStatusItem);

void CStatusItem::Start() {
    m_state = 4;
    m_unk30 = 0;
}

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A36B0);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", Func1A3740__14CMenuRecordWiniPCc);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A3840);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A38D0);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A3930);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", Func1A39A8__14CMenuRecordWinPfPii);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A3A18);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A3A78);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A3AF8);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", Func1A3B58__14CMenuRecordWinPfPii);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A3BC8);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A3C28);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A3C98);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A3CF8);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A3D68);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A3DC8);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A3E28);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A3EA8);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A3F20);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A3FA8);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A4008);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A4060);

void CStatusWinSub1A40B8::SetUnk80(f32 x, f32 y) {
    m_unk80 = x;
    m_unk84 = y;
}

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A40C8);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", Func1A4298__10CUnk1A4298);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A49E0);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A4A40);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A4AE0);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A4BA8);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A4D28);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A4E88);
