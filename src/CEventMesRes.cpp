#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
//@sym strcmp 0x28B190
#include "libc.h"

class CEventMesItem {
public:


    u8 pad0[0x4];
    s32 m_unk4;               // 0x4
};
class CEventMesMgr {
public:
    CEventMesItem *Find(s32 id);
    s32 GetItemUnk4(s32 id);


};
//@sym Find__12CEventMesMgri 0x13E070

class CPushBuf {
public:
    void Func248E00();
    int Func248EB0();

    u8 m_data[0xC];
};
class CEventMesResSub13DD98 {
public:
    void Init();

    u8 pad0[0x10];
    CPushBuf m_buf;           // 0x10
    s32 m_unk1C;              // 0x1C
    s32 m_unk20;              // 0x20
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CEventMesRes", func_0013D910);

INCLUDE_ASM("asm/nonmatchings/CEventMesRes", func_0013D958);

int CompareEventMesNames(const char **a, const char **b) {
    return strcmp(*a, *b);
}

INCLUDE_ASM("asm/nonmatchings/CEventMesRes", func_0013DA10);

INCLUDE_ASM("asm/nonmatchings/CEventMesRes", func_0013DBF8);

void CEventMesResSub13DD98::Init() {
    m_buf.Func248E00();
    m_unk1C = 0;
    m_unk20 = 0;
}

INCLUDE_ASM("asm/nonmatchings/CEventMesRes", func_0013DDC8);

INCLUDE_ASM("asm/nonmatchings/CEventMesRes", func_0013DE00);

INCLUDE_ASM("asm/nonmatchings/CEventMesRes", func_0013DE38);

INCLUDE_ASM("asm/nonmatchings/CEventMesRes", func_0013DE70);

INCLUDE_ASM("asm/nonmatchings/CEventMesRes", func_0013DEB0);

INCLUDE_ASM("asm/nonmatchings/CEventMesRes", func_0013DFB8);

INCLUDE_ASM("asm/nonmatchings/CEventMesRes", func_0013DFF8);

INCLUDE_ASM("asm/nonmatchings/CEventMesRes", Find__12CEventMesMgri);

s32 CEventMesMgr::GetItemUnk4(s32 id) {
    CEventMesItem *p = Find(id);
    if (p) {
        return p->m_unk4;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/CEventMesRes", func_0013E0F8);

INCLUDE_ASM("asm/nonmatchings/CEventMesRes", func_0013E178);

INCLUDE_ASM("asm/nonmatchings/CEventMesRes", func_0013E3D0);
