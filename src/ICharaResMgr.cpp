#pragma interface
#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CResCacheUnit {
public:
    u8 pad0[0x10];
    s32 m_res;                // 0x10
};
class CResCache {
public:
    void Init250208(void (*f)(), s32 a, s32 b, s32 c);
    void *Find250B08(s32 id);
    void Func250368();
    ~CResCache();

    u8 pad0[0x13C];
};
// #pragma interface (top) keeps this unit from emitting the vtables (asm data), so the key method
// ~CCharaResMgr can be C++; ~ICharaResMgr is inline in retail. vptr at 0x13C, after CResCache.
class ICharaResMgr : public CResCache {
public:
    virtual ~ICharaResMgr() {}
};
extern void *D_002A0BE4;
class CCharaResMgr : public ICharaResMgr {
public:
    virtual ~CCharaResMgr();
    void InitCache(s32 size, s32 n);
    s32 *FindRes(s32 id);
    void CallFunc250368();
};

extern "C" void func_0012D1C8();
// @decl-end

CCharaResMgr::~CCharaResMgr() {
    D_002A0BE4 = 0;
}

s32 *CCharaResMgr::FindRes(s32 id) { CResCacheUnit *u = (CResCacheUnit *)Find250B08(id); if (u) return &u->m_res; return 0; }

void CCharaResMgr::InitCache(s32 size, s32 n) {
    if (size < 0) size = 0x64000;
    if (n < 0) n = 0x18;
    Init250208(func_0012D1C8, n, size, 0x80);
}

void CCharaResMgr::CallFunc250368() {
    Func250368();
}
