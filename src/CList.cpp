#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CList.h"
// Texture cache entry (vtable _vt$10CCacheInfo), on the cache's list.
class CTexCacheEnt : public CListTag {
public:
    virtual ~CTexCacheEnt();
    s32 m10;                  // 0x10
    s32 m14;                  // 0x14
    u8 pad18[4];
    s32 m1C;                  // 0x1C
};
// The node list at 0x20 (TList<CCacheInfo>: CListTag fields, vptr at 0xC).
struct CTexCacheList { s32 m_isHead; CTexCacheList *m_prev; CTexCacheList *m_next; void *m_vt; };
// Vtable _vt$12CTexCacheMgr (in asm): slot 0 is an inline library function, slot 1
// (func_0010D028) the key method; the destructor is the last slot.
class ITexCacheMgr {
public:
    virtual void V0() = 0;
    virtual void V1() = 0;
    virtual void Release10D200() = 0;
    virtual void Clear() = 0;
    virtual void Age() = 0;
    virtual void V5() = 0;
};
class CTexCacheMgr : public ITexCacheMgr {
public:
    virtual void V0();
    virtual void V1();
    virtual void Release10D200();
    virtual void Clear();
    virtual void Age();
    virtual void V5();
    virtual ~CTexCacheMgr();
    // vptr 0x0
    void *m4;                 // 0x4
    s32 m8;                   // 0x8
    s32 mC;                   // 0xC
    s32 m10;                  // 0x10
    s32 m14;                  // 0x14
    s32 m18;                  // 0x18
    CTexCacheEnt *m1C;        // 0x1C
    CTexCacheList m20;        // 0x20
};
extern void (*D_002B91B0)(void *p);
void BlitFlip8(u8 *dst, u8 *src, int stride, int x, int y, int w, int h);
void BlitFlip32(u32 *dst, u32 *src, int stride, int x, int y, int w, int h);
void BlitFlip16(u16 *dst, u16 *src, int stride, int x, int y, int w, int h);
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CList", func_0010CF40);

INCLUDE_ASM("asm/nonmatchings/CList", func_0010D028);

void CTexCacheMgr::Release10D200() {
    if (m4) {
        D_002B91B0(m4);
        m4 = 0;
    }
    if (m1C) {
        delete[] m1C;
        m18 = 0;
    }
    m8 = 0;
    mC = 0;
    m10 = 0;
    m14 = 0;
}

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

void BlitFlip32(u32 *dst, u32 *src, int stride, int x, int y, int w, int h) {
    u32 *s = src + (y * stride + x) + w - 1;
    int i;
    for (; h > 0; h--) {
        for (i = w; i > 0; i--) *dst++ = *s--;
        s += stride + w;
    }
}

void BlitFlip16(u16 *dst, u16 *src, int stride, int x, int y, int w, int h) {
    u16 *s = src + (y * stride + x) + w - 1;
    int i;
    for (; h > 0; h--) {
        for (i = w; i > 0; i--) *dst++ = *s--;
        s += stride + w;
    }
}

void BlitFlip8(u8 *dst, u8 *src, int stride, int x, int y, int w, int h) {
    u8 *s = src + w + (y * stride + x) - 1;
    int i;
    for (; h > 0; h--) {
        for (i = w; i > 0; i--) *dst++ = *s--;
        s += stride + w;
    }
}
