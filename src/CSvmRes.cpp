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
// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CSvmRes. The vptr
// follows its own fields.
class CSvmRes {
public:
    CSvmRes();
    virtual ~CSvmRes();
    void Release();

    s32 m_unk0;               // 0x00
    s32 m_unk4;               // 0x04
    s32 m_unk8;               // 0x08
    s32 m_unkC;               // 0x0C
    s32 m_unk10;              // 0x10
    s32 m_unk14;              // 0x14
    s32 m_unk18;              // 0x18
    s32 m_unk1C;              // 0x1C
    // vptr 0x20
};
// @decl-end

CSvmRes::CSvmRes() {
    m_unk0 = 0;
    m_unk4 = 0;
    m_unk8 = 0;
    m_unkC = 0;
    m_unk10 = 0;
    m_unk14 = 0;
    m_unk18 = 0;
    m_unk1C = 0;
}

CSvmRes::~CSvmRes() {
    Release();
}

int CSvmHeader::IsValid() {
    if (m_magic == 0x44435347) {
        if (m_version == 0x100) {
            return 1;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/CSvmRes", func_0012DE40);

INCLUDE_RODATA("asm/nonmatchings/CSvmRes", D_002D5160);
INCLUDE_ASM("asm/nonmatchings/CSvmRes", func_0012DEC0);

INCLUDE_ASM("asm/nonmatchings/CSvmRes", func_0012DFB0);

INCLUDE_ASM("asm/nonmatchings/CSvmRes", Release__7CSvmRes);

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
