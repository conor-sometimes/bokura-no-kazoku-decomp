#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern s32 D_002A0394;
extern s32 D_002A0398;

class CEFontWork {
public:
    void CopyUnk84(const CEFontWork *src);

    u8 pad0[0x80];
    s32 m_unk80;              // 0x80
    s32 m_unk84;              // 0x84
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CEFontWork", func_0010BF88);

void CEFontWork::CopyUnk84(const CEFontWork *src) {
    m_unk80 = src->m_unk84;
}

INCLUDE_ASM("asm/nonmatchings/CEFontWork", func_0010BFD0);

int GetEFontUnkC() {
    return 0xC;
}

INCLUDE_ASM("asm/nonmatchings/CEFontWork", func_0010C710);

INCLUDE_ASM("asm/nonmatchings/CEFontWork", func_0010C798);

INCLUDE_ASM("asm/nonmatchings/CEFontWork", func_0010CA28);

INCLUDE_ASM("asm/nonmatchings/CEFontWork", func_0010CA90);

INCLUDE_ASM("asm/nonmatchings/CEFontWork", func_0010CBC0);

INCLUDE_ASM("asm/nonmatchings/CEFontWork", func_0010CC00);

INCLUDE_ASM("asm/nonmatchings/CEFontWork", func_0010CC48);

INCLUDE_ASM("asm/nonmatchings/CEFontWork", func_0010CCC8);

INCLUDE_ASM("asm/nonmatchings/CEFontWork", func_0010CD48);

s32 GetEFontUnk2A0398() {
    return D_002A0398;
}

s32 GetEFontUnk2A0394() {
    return D_002A0394 < 0 ? 0 : 0x8090000;
}

INCLUDE_ASM("asm/nonmatchings/CEFontWork", func_0010CDD0);

INCLUDE_ASM("asm/nonmatchings/CEFontWork", func_0010CE40);

INCLUDE_ASM("asm/nonmatchings/CEFontWork", func_0010CEB0);
