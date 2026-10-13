#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CValue {
public:
    void Reset();

    s32 m_type;               // 0x0
    s32 m_value;              // 0x4
};

class CSvmHeader {
public:
    int IsValid();

    u32 m_magic;              // 0x0
    u8 pad4[0x4];
    s32 m_version;            // 0x8
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CSvmRes", func_0012DD80);

INCLUDE_ASM("asm/nonmatchings/CSvmRes", func_0012DDB0);

int CSvmHeader::IsValid() {
    if (m_magic == 0x44435347) {
        if (m_version == 0x100) {
            return 1;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/CSvmRes", func_0012DE40);

INCLUDE_ASM("asm/nonmatchings/CSvmRes", func_0012DEC0);

INCLUDE_ASM("asm/nonmatchings/CSvmRes", func_0012DFB0);

INCLUDE_ASM("asm/nonmatchings/CSvmRes", func_0012E058);

void CValue::Reset() {
    m_type = -1;
    m_value = 0;
}

INCLUDE_ASM("asm/nonmatchings/CSvmRes", SetInt__6CValuei);

INCLUDE_ASM("asm/nonmatchings/CSvmRes", SetFloat__6CValuef);

INCLUDE_ASM("asm/nonmatchings/CSvmRes", Set12E1D8__6CValuei);

INCLUDE_ASM("asm/nonmatchings/CSvmRes", AsInt__6CValue);

INCLUDE_ASM("asm/nonmatchings/CSvmRes", AsFloat__6CValue);

INCLUDE_ASM("asm/nonmatchings/CSvmRes", Get12E350__6CValue);

INCLUDE_ASM("asm/nonmatchings/CSvmRes", func_0012E410);

INCLUDE_ASM("asm/nonmatchings/CSvmRes", func_0012E558);
