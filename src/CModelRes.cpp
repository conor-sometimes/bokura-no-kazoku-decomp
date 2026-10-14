#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
//@sym memset 0x289FB0
#include "libc.h"

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CModelRes.
class CModelRes {
public:
    CModelRes();
    virtual ~CModelRes();
    void Release();
    s32 Load(s32 a, s32 b);

    s32 m_unk0;               // 0x00
    s32 m_unk4;               // 0x04
    s32 m_unk8;               // 0x08
    s32 m_unkC;               // 0x0C
    s32 m_unk10;              // 0x10
    u8 m_unk14[0x8];          // 0x14
    // vptr 0x1C
};

struct CModelRec {
    s32 m_id;                 // 0x0
    u8 pad4[0x30];
};
extern "C" s32 func_00110560(CModelRec *recs, s32 a, s32 b, s32 c, s32 d, s32 *e, s32 *f);
extern "C" void *func_00245678(u32 size);
// @decl-end

CModelRes::CModelRes() {
    m_unkC = -1;
    m_unk4 = 0;
    m_unk0 = 0;
    m_unk8 = 0;
    m_unk10 = 0;
    memset(m_unk14, 0, 8);
}

CModelRes::~CModelRes() {
    Release();
}

INCLUDE_ASM("asm/nonmatchings/CModelRes", func_0010FFE8);
INCLUDE_RODATA("asm/nonmatchings/CModelRes", D_002D3130);

INCLUDE_ASM("asm/nonmatchings/CModelRes", func_00110178);

INCLUDE_ASM("asm/nonmatchings/CModelRes", func_001102C8);
INCLUDE_RODATA("asm/nonmatchings/CModelRes", D_002D31B8);
INCLUDE_RODATA("asm/nonmatchings/CModelRes", D_002D31C0);
INCLUDE_RODATA("asm/nonmatchings/CModelRes", D_002D31C8);

INCLUDE_ASM("asm/nonmatchings/CModelRes", func_00110560);
INCLUDE_RODATA("asm/nonmatchings/CModelRes", D_002D31D8);
INCLUDE_RODATA("asm/nonmatchings/CModelRes", D_002D31E0);
INCLUDE_RODATA("asm/nonmatchings/CModelRes", D_002D31E8);
INCLUDE_RODATA("asm/nonmatchings/CModelRes", D_002D31F0);
INCLUDE_RODATA("asm/nonmatchings/CModelRes", D_002D31F8);

s32 CModelRes::Load(s32 a, s32 b) {
    s32 i;
    Release();
    m_unk0 = func_00110560(0, a, b, m_unkC, m_unk10, 0, 0);
    m_unk4 = (s32)func_00245678(m_unk0 * sizeof(CModelRec));
    memset((void *)m_unk4, 0, m_unk0 * sizeof(CModelRec));
    func_00110560((CModelRec *)m_unk4, a, b, m_unkC, m_unk10, (s32 *)&m_unk14[0], (s32 *)&m_unk14[4]);
    m_unk8 = 0;
    for (i = 0; i < m_unk0; i++) {
        s32 v = ((CModelRec *)m_unk4)[i].m_id + 1;
        if (v < m_unk8) {
            v = m_unk8;
        }
        m_unk8 = v;
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/CModelRes", func_00110868);

INCLUDE_ASM("asm/nonmatchings/CModelRes", Release__9CModelRes);
