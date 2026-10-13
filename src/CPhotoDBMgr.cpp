#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CPushBuf {
public:
    void Func248E00();
    int Func248EB0();

    u8 m_data[0xC];
};
class CPhotoDBMgrSub1705B0 {
public:
    void Init();
    void Clear();

    u8 pad0[0x4];
    CPushBuf m_buf;           // 0x4
    u8 pad10[0x8];
    s32 m_unk18;              // 0x18
    s32 m_unk1C;              // 0x1C
    s32 m_unk20;              // 0x20
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CPhotoDBMgr", func_001704F8);

INCLUDE_ASM("asm/nonmatchings/CPhotoDBMgr", func_00170538);

void CPhotoDBMgrSub1705B0::Clear() {
    m_unk18 = 0;
    m_unk1C = 0;
    m_unk20 = 0;
}

INCLUDE_ASM("asm/nonmatchings/CPhotoDBMgr", func_001705C0);

INCLUDE_ASM("asm/nonmatchings/CPhotoDBMgr", func_00170758);

INCLUDE_ASM("asm/nonmatchings/CPhotoDBMgr", func_00170900);

INCLUDE_ASM("asm/nonmatchings/CPhotoDBMgr", func_001709A0);

INCLUDE_ASM("asm/nonmatchings/CPhotoDBMgr", func_00170B18);

INCLUDE_ASM("asm/nonmatchings/CPhotoDBMgr", func_00170CD8);

INCLUDE_ASM("asm/nonmatchings/CPhotoDBMgr", func_00170E18);

INCLUDE_ASM("asm/nonmatchings/CPhotoDBMgr", func_001711A0);

INCLUDE_ASM("asm/nonmatchings/CPhotoDBMgr", func_00171378);

void CPhotoDBMgrSub1705B0::Init() {
    m_buf.Func248E00();
    Clear();
}

INCLUDE_ASM("asm/nonmatchings/CPhotoDBMgr", func_00171448);

INCLUDE_ASM("asm/nonmatchings/CPhotoDBMgr", func_001714C8);

INCLUDE_ASM("asm/nonmatchings/CPhotoDBMgr", func_00171510);

INCLUDE_ASM("asm/nonmatchings/CPhotoDBMgr", func_00171838);

INCLUDE_ASM("asm/nonmatchings/CPhotoDBMgr", func_00171980);

INCLUDE_ASM("asm/nonmatchings/CPhotoDBMgr", func_00171A58);

INCLUDE_ASM("asm/nonmatchings/CPhotoDBMgr", func_00171B30);

INCLUDE_ASM("asm/nonmatchings/CPhotoDBMgr", func_00171C08);

INCLUDE_ASM("asm/nonmatchings/CPhotoDBMgr", func_00171CE0);
