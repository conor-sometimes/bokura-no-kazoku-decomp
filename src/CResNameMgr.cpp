#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CPushBuf {
public:
    void Func248E00();
    int Func248EB0();

    u8 m_data[0xC];
};
class CResNameMgrSub145C88 {
public:
    void Init();
    void Clear();

    u8 pad0[0x4];
    CPushBuf m_buf;           // 0x4
    s32 m_unk10;              // 0x10
    s32 m_unk14;              // 0x14
    s32 m_unk18;              // 0x18
    s32 m_unk1C;              // 0x1C
    s32 m_unk20;              // 0x20
    s32 m_unk24;              // 0x24
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CResNameMgr", func_00145BD0);

INCLUDE_ASM("asm/nonmatchings/CResNameMgr", func_00145C10);

void CResNameMgrSub145C88::Clear() {
    m_unk10 = 0;
    m_unk14 = 0;
    m_unk18 = 0;
    m_unk1C = 0;
    m_unk20 = 0;
    m_unk24 = 0;
}

INCLUDE_ASM("asm/nonmatchings/CResNameMgr", func_00145CA8);

INCLUDE_ASM("asm/nonmatchings/CResNameMgr", func_00145D18);

INCLUDE_ASM("asm/nonmatchings/CResNameMgr", func_00145E18);

INCLUDE_ASM("asm/nonmatchings/CResNameMgr", func_00146238);

INCLUDE_ASM("asm/nonmatchings/CResNameMgr", func_00146410);

void CResNameMgrSub145C88::Init() {
    m_buf.Func248E00();
    Clear();
}

INCLUDE_ASM("asm/nonmatchings/CResNameMgr", func_001465C0);

INCLUDE_ASM("asm/nonmatchings/CResNameMgr", func_00146608);

INCLUDE_ASM("asm/nonmatchings/CResNameMgr", func_00146658);

INCLUDE_ASM("asm/nonmatchings/CResNameMgr", func_001467E0);

INCLUDE_ASM("asm/nonmatchings/CResNameMgr", func_00146B58);

INCLUDE_ASM("asm/nonmatchings/CResNameMgr", func_00146C08);

INCLUDE_ASM("asm/nonmatchings/CResNameMgr", func_00146DE8);

INCLUDE_ASM("asm/nonmatchings/CResNameMgr", func_00146EB8);

INCLUDE_ASM("asm/nonmatchings/CResNameMgr", func_00146F28);
