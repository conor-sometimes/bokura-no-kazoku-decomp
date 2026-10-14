#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "IFadeMgr.h"

class CVec4 {
public:
    f32 x, y, z, w;
};
void Func270C50(CVec4 *dst, const CVec4 *src);

// Vtable 0x2BFD10 (still asm); the methods are in IFadeMgr.cpp (one object with this unit).
class CFadeMgr : public IFadeMgr {
public:
    CFadeMgr(void *owner, s32 n);
    virtual ~CFadeMgr();

    CFadeMgr **m_owner;       // 0x8
    s32 m_unkC;               // 0xC
    CVec4 m_unk10;            // 0x10
    CVec4 m_unk20;            // 0x20
    CVec4 m_zero;             // 0x30
    s32 m_unk40;              // 0x40
    s32 m_unk44;              // 0x44
    s32 m_unk48;              // 0x48
    s32 m_unk4C;              // 0x4C
    s32 m_unk50;              // 0x50
    u8 pad54[0xC];
};
// @decl-end

CFadeMgr::CFadeMgr(void *owner, s32 n) {
    m_owner = (CFadeMgr **)owner;
    *(CFadeMgr **)owner = this;
    m_unkC = n;
    m_zero.x = 0.0f;
    m_zero.y = 0.0f;
    m_zero.z = 0.0f;
    m_zero.w = 0.0f;
    Func270C50(&m_unk10, &m_zero);
    Func270C50(&m_unk20, &m_zero);
    m_unk48 = 0;
    m_unk40 = 0;
    m_unk44 = 0;
    m_unk4C = 0;
    m_unk50 = 0;
}
