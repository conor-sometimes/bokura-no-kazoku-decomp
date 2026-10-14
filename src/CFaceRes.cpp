#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
//@sym memset 0x289FB0
#include "libc.h"

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CFaceRes.
class CFaceRes {
public:
    CFaceRes();
    virtual ~CFaceRes();
    void Release();

    s32 m_unk0;               // 0x00
    s32 m_unk4;               // 0x04
    s32 m_unk8;               // 0x08
    s32 m_unkC;               // 0x0C
    s32 m_unk10;              // 0x10
    s32 m_unk14;              // 0x14
    u8 m_unk18[0xC];          // 0x18
    u8 m_unk24[0xC];          // 0x24
    s32 m_unk30;              // 0x30
    s32 m_unk34;              // 0x34
    s32 m_unk38;              // 0x38
    s32 m_unk3C;              // 0x3C
    s32 m_unk40;              // 0x40
    s32 m_unk44;              // 0x44
    s32 m_unk48;              // 0x48
    s32 m_unk4C;              // 0x4C
    s32 m_unk50;              // 0x50
    // vptr 0x54
};

class CFaceResSub10F938 {
public:
    s32 GetFirst();

    u8 pad0[0x10];
    s32* m_list;              // 0x10
    s32 m_count;              // 0x14
};

class CFaceResRec {
public:
    s32 m_id;                 // 0x0
    u8 pad4[0x18];
};
class CFaceResSub10F8F0 {
public:
    CFaceResRec *Find(s32 id);

    u8 pad0[0x10];
    CFaceResRec *m_recs;      // 0x10
    s32 m_num;                // 0x14
};
// @decl-end

CFaceRes::CFaceRes() {
    m_unk8 = 0;
    m_unkC = 0;
    m_unk0 = 0;
    m_unk4 = 0;
    m_unk10 = 0;
    m_unk14 = 0;
    memset(m_unk18, 0, 0xC);
    memset(m_unk24, 0, 0xC);
    m_unk34 = 0;
    m_unk30 = -1;
    m_unk38 = 0;
    m_unk3C = 0;
    m_unk40 = 0;
    m_unk44 = 0;
    m_unk48 = 0;
    m_unk4C = 0x50;
    m_unk50 = 0x50;
}

CFaceRes::~CFaceRes() {
    Release();
}

INCLUDE_ASM("asm/nonmatchings/CFaceRes", func_0010E5E0);

INCLUDE_ASM("asm/nonmatchings/CFaceRes", func_0010E7A8);

INCLUDE_RODATA("asm/nonmatchings/CFaceRes", D_002D2DC0);
INCLUDE_RODATA("asm/nonmatchings/CFaceRes", D_002D2DC8);
INCLUDE_RODATA("asm/nonmatchings/CFaceRes", D_002D2DD0);
INCLUDE_RODATA("asm/nonmatchings/CFaceRes", D_002D2DD8);
INCLUDE_RODATA("asm/nonmatchings/CFaceRes", D_002D2DE0);
INCLUDE_ASM("asm/nonmatchings/CFaceRes", func_0010E8D0);

INCLUDE_ASM("asm/nonmatchings/CFaceRes", func_0010E970);
INCLUDE_RODATA("asm/nonmatchings/CFaceRes", D_002D2EE0);
INCLUDE_RODATA("asm/nonmatchings/CFaceRes", jtbl_002D2F00);
INCLUDE_RODATA("asm/nonmatchings/CFaceRes", D_002D2FB8);

INCLUDE_ASM("asm/nonmatchings/CFaceRes", func_0010EC18);

INCLUDE_ASM("asm/nonmatchings/CFaceRes", func_0010ED30);

INCLUDE_ASM("asm/nonmatchings/CFaceRes", func_0010EF78);

INCLUDE_ASM("asm/nonmatchings/CFaceRes", func_0010F068);
INCLUDE_RODATA("asm/nonmatchings/CFaceRes", D_002D2FD8);
INCLUDE_RODATA("asm/nonmatchings/CFaceRes", D_002D2FE0);

INCLUDE_RODATA("asm/nonmatchings/CFaceRes", D_002D2FE8);
INCLUDE_RODATA("asm/nonmatchings/CFaceRes", D_002D2FF0);
INCLUDE_RODATA("asm/nonmatchings/CFaceRes", D_002D2FF8);
INCLUDE_ASM("asm/nonmatchings/CFaceRes", func_0010F348);

INCLUDE_ASM("asm/nonmatchings/CFaceRes", func_0010F580);

INCLUDE_ASM("asm/nonmatchings/CFaceRes", Release__8CFaceRes);

CFaceResRec *CFaceResSub10F8F0::Find(s32 id) {
    for (s32 i = 0; i < m_num; i++) {
        if (m_recs[i].m_id == id) {
            return &m_recs[i];
        }
    }
    return 0;
}

s32 CFaceResSub10F938::GetFirst() {
    return m_count > 0 ? m_list[0] : -1;
}

void Blit32(u32 *dst, u32 *src, s32 stride, s32 x, s32 y, s32 w, s32 h) {
    u32 *p = src + y * stride + x;
    for (; h > 0; h--) {
        for (s32 i = w; i > 0; i--) {
            *dst++ = *p++;
        }
        p += stride - w;
    }
}

void Blit8(u8 *dst, u8 *src, s32 stride, s32 x, s32 y, s32 w, s32 h) {
    src = src + y * stride + x;
    for (; h > 0; h--) {
        for (s32 i = w; i > 0; i--) {
            *dst++ = *src++;
        }
        src += stride - w;
    }
}

void Blit16(u16 *dst, u16 *src, s32 stride, s32 x, s32 y, s32 w, s32 h) {
    u16 *p = src + y * stride + x;
    for (; h > 0; h--) {
        for (s32 i = w; i > 0; i--) {
            *dst++ = *p++;
        }
        p += stride - w;
    }
}
