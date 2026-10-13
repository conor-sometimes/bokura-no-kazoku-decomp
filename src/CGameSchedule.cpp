#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CGameScheduleNode {
public:


    s32 m_unk0;               // 0x0
    u8 pad4[0x4];
    CGameScheduleNode* m_next; // 0x8
};
class CGameScheduleSub159F58 {
public:
    void Advance();

    u8 pad0[0xCC];
    CGameScheduleNode* m_cur; // 0xCC
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_00159850);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_00159A10);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_00159C50);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_00159CF0);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_00159E18);

void CGameScheduleSub159F58::Advance() {
    if (m_cur) {
        CGameScheduleNode *n = m_cur->m_next;
        m_cur = n->m_unk0 ? 0 : n;
    }
}

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_00159F80);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015A090);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015A120);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015A158);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015D3E0);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015D468);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015D620);

int CompareScheduleIds(const s32 *a, const s32 *b) {
    return *a - *b;
}

int CheckScheduleId(int v) {
    if (v == 0x3FFF) {
        return -1;
    }
    if (v < 0) {
        return -1;
    }
    return v;
}

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015D820);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015DAB0);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015DD38);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015DE20);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015DEA0);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015E048);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015E2A8);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015E2F8);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015E450);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015E5A8);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015E638);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015E6E8);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015E860);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015E908);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015EAE0);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015EB68);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015EEF8);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015F030);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015F080);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015F0D8);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015F1B0);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015F2C8);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015F780);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015F958);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015F9E0);

INCLUDE_ASM("asm/nonmatchings/CGameSchedule", func_0015FDE0);
