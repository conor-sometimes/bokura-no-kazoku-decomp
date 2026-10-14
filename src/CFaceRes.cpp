#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
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

INCLUDE_ASM("asm/nonmatchings/CFaceRes", func_0010E4F0);

INCLUDE_ASM("asm/nonmatchings/CFaceRes", func_0010E580);

INCLUDE_ASM("asm/nonmatchings/CFaceRes", func_0010E5E0);

INCLUDE_ASM("asm/nonmatchings/CFaceRes", func_0010E7A8);

INCLUDE_ASM("asm/nonmatchings/CFaceRes", func_0010E8D0);

INCLUDE_ASM("asm/nonmatchings/CFaceRes", func_0010E970);

INCLUDE_ASM("asm/nonmatchings/CFaceRes", func_0010EC18);

INCLUDE_ASM("asm/nonmatchings/CFaceRes", func_0010ED30);

INCLUDE_ASM("asm/nonmatchings/CFaceRes", func_0010EF78);

INCLUDE_ASM("asm/nonmatchings/CFaceRes", func_0010F068);

INCLUDE_ASM("asm/nonmatchings/CFaceRes", func_0010F348);

INCLUDE_ASM("asm/nonmatchings/CFaceRes", func_0010F580);

INCLUDE_ASM("asm/nonmatchings/CFaceRes", func_0010F6F8);

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
