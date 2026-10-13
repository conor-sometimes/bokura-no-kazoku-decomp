#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CPushBuf {
public:
    void Func248E00();
    int Func248EB0();

    u8 m_data[0xC];
};
class CGameDBMgr {
public:
    void Func147020();
    void Init();
    s32 GetUnk24();
    int Func14EB20(s32 a, s32 b, s32 c);
    int CallFunc14EB20Minus(s32 a, s32 b);
    int CallFunc14EB20Plus(s32 a, s32 b);

    u8 pad0[0x4];
    CPushBuf m_buf;           // 0x4
    u8 pad10[0x14];
    s32 m_unk24;              // 0x24
};

class CGameDBEntry {
public:


    s32 m_id;                 // 0x0
    u8 pad4[0x34];
    s32 m_order;              // 0x38
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_00146F60);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_00146FA8);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", Func147020__10CGameDBMgr);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_00147130);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_00147340);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_001473B0);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_00147500);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_001478E8);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_00148110);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_00148238);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_00148400);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_00148450);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_00148510);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_001485E8);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_00148C50);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_00148D70);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_00148EC8);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_001490F8);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_00149618);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_00149670);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_00149DC8);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014A0F8);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014A370);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014A620);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014A8C0);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014AAD0);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014AD78);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014AE30);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014B4C8);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014B890);

void CGameDBMgr::Init() {
    m_buf.Func248E00();
    Func147020();
}

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014BB28);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014BB90);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014BBD8);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014BC20);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014BD00);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014C048);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014C2B0);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014C490);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014C648);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014C800);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014C998);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014C9F8);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014CA38);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014CAF0);

int CompareGameDBIds(const s32 *a, const s32 *b) {
    return *a - *b;
}

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014CC00);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014CF78);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014D378);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014D430);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014D5F8);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014D7C8);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014DB70);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014DCE0);

s32 CGameDBMgr::GetUnk24() {
    return m_unk24;
}

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014E448);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014E480);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014E4B8);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014E508);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014E550);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014E5D0);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014E618);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014E660);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014E7C0);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014E808);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014E850);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014E898);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014E8E0);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014E928);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014E970);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014E9B8);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014EA00);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014EA48);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014EA90);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014EAD8);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", Func14EB20__10CGameDBMgriii);

int CGameDBMgr::CallFunc14EB20Minus(s32 a, s32 b) {
    return Func14EB20(a, b, -1);
}

int CGameDBMgr::CallFunc14EB20Plus(s32 a, s32 b) {
    return Func14EB20(a, b, 1);
}

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014EBF0);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014EC50);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014ECD0);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014ED50);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014EDE0);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014EE18);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014F2A0);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014F380);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014F478);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014F550);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014F638);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014F760);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014F830);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014F918);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014FA08);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014FAD0);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014FB08);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014FB48);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014FBB0);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014FC70);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014FCC8);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014FE60);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014FF30);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_00150348);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_00150550);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_00150590);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_001505E0);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_00150630);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_00150680);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_00150980);

int CompareGameDBEntries(const CGameDBEntry *a, const CGameDBEntry *b) {
    int d = a->m_order - b->m_order;
    if (d != 0) {
        return d;
    }
    return a->m_id - b->m_id;
}

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_00150A10);
