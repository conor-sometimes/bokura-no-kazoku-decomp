#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
struct CTexCacheEnt { u8 pad0[0x10]; s32 m10; s32 m14; u8 pad18[4]; s32 m1C; };
class CTexCacheMgr {
public:
    void Clear();
    void Age();
    u8 pad0[0x18];
    s32 m18;                  // 0x18
    CTexCacheEnt *m1C;        // 0x1C
};
void BlitFlip8(u8 *dst, u8 *src, int stride, int x, int y, int w, int h);
void BlitFlip32(u32 *dst, u32 *src, int stride, int x, int y, int w, int h);
void BlitFlip16(u16 *dst, u16 *src, int stride, int x, int y, int w, int h);
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CList", func_0010CF40);

INCLUDE_ASM("asm/nonmatchings/CList", func_0010D028);

INCLUDE_ASM("asm/nonmatchings/CList", func_0010D200);

void CTexCacheMgr::Clear() {
    int i;
    for (i = 0; i < m18; i++) {
        m1C[i].m10 = -1;
        m1C[i].m14 = 0;
        m1C[i].m1C = 0;
    }
}

void CTexCacheMgr::Age() {
    int i;
    for (i = 0; i < m18; i++) {
        m1C[i].m1C--;
        m1C[i].m1C = m1C[i].m1C < 0 ? 0 : m1C[i].m1C;
    }
}

INCLUDE_ASM("asm/nonmatchings/CList", func_0010D360);

INCLUDE_ASM("asm/nonmatchings/CList", func_0010D4F0);

INCLUDE_ASM("asm/nonmatchings/CList", func_0010D6C0);

INCLUDE_ASM("asm/nonmatchings/CList", func_0010D728);

void BlitFlip8(u8 *dst, u8 *src, int stride, int x, int y, int w, int h) {
    u8 *s = src + w + (y * stride + x) - 1;
    int i;
    for (; h > 0; h--) {
        for (i = w; i > 0; i--) *dst++ = *s--;
        s += stride + w;
    }
}
