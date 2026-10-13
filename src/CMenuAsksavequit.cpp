#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CMenuAsksavequitSub193E18 {
public:
    void ClearUnk10();

    u8 pad0[0x10];
    s32 m_unk10;              // 0x10
};
class CMenuAsksavequitSub193FC0 {
public:
    u64 SwapUnk0(u64 v);
    u64 SwapUnk8(u64 v);

    u64 m_unk0;               // 0x0
    u64 m_unk8;               // 0x8
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CMenuAsksavequit", func_00192D38);

INCLUDE_ASM("asm/nonmatchings/CMenuAsksavequit", func_00192D70);

INCLUDE_ASM("asm/nonmatchings/CMenuAsksavequit", func_00192DD8);

INCLUDE_ASM("asm/nonmatchings/CMenuAsksavequit", func_00193180);

INCLUDE_ASM("asm/nonmatchings/CMenuAsksavequit", func_001932B8);

INCLUDE_ASM("asm/nonmatchings/CMenuAsksavequit", func_00193358);

INCLUDE_ASM("asm/nonmatchings/CMenuAsksavequit", func_00193D68);

void CMenuAsksavequitSub193E18::ClearUnk10() {
    m_unk10 = 0;
}

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_00193E20() {
}

INCLUDE_ASM("asm/nonmatchings/CMenuAsksavequit", func_00193E28);

INCLUDE_ASM("asm/nonmatchings/CMenuAsksavequit", func_00193F80);

u64 CMenuAsksavequitSub193FC0::SwapUnk0(u64 v) {
    u64 old = m_unk0;
    m_unk0 = v;
    return old;
}

u64 CMenuAsksavequitSub193FC0::SwapUnk8(u64 v) {
    u64 old = m_unk8;
    m_unk8 = v;
    return old;
}

INCLUDE_ASM("asm/nonmatchings/CMenuAsksavequit", func_00193FE0);

INCLUDE_ASM("asm/nonmatchings/CMenuAsksavequit", func_00194140);

INCLUDE_ASM("asm/nonmatchings/CMenuAsksavequit", func_001942C8);

INCLUDE_ASM("asm/nonmatchings/CMenuAsksavequit", func_00194300);

INCLUDE_ASM("asm/nonmatchings/CMenuAsksavequit", func_00194390);

INCLUDE_ASM("asm/nonmatchings/CMenuAsksavequit", func_00194410);
