#pragma interface
#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CResCache {
public:
    void Init250208(void (*f)(), s32 a, s32 b, s32 c);
    void *Find250B08(s32 id);
    void Func250368();
    ~CResCache();

    u8 pad0[0x13C];
};
// Vtable _vt$10CEnvResMgr (vptr at 0x13C, after CResCache); slots as IResMgr in CGameMain.cpp.
// #pragma interface (top) keeps this unit from emitting the vtables (asm data), so the key method
// ~CEnvResMgr can be C++; ~IEnvResMgr is inline in retail.
class IEnvResMgr : public CResCache {
public:
    virtual ~IEnvResMgr() {}
};
extern void *D_002A0BEC;
class CEnvResMgr : public IEnvResMgr {
public:
    virtual ~CEnvResMgr();
    virtual void V1();
    virtual s32 FindRes(s32 id);
    s32 GetKey12DCE8(s32 id);
    void InitCache();
    s32 GetItemUnk14(s32 id);
    void CallFunc250368();
};

class CEnvResItem {
public:


    u8 pad0[0x14];
    s32 m_unk14;              // 0x14
};
//@sym Find250B08__9CResCachei 0x250B08

extern "C" void func_0012D8B0();
// @decl-end

CEnvResMgr::~CEnvResMgr() {
    D_002A0BEC = 0;
}

s32 CEnvResMgr::GetItemUnk14(s32 id) {
    CEnvResItem *p = (CEnvResItem *)Find250B08(id);
    if (p) {
        return p->m_unk14;
    }
    return 0;
}

s32 CEnvResMgr::GetKey12DCE8(s32 id) {
    s32 v = FindRes(id);
    if (v < 0) return 0;
    return (v << 16) | 0x8000000;
}

void CEnvResMgr::InitCache() {
    Init250208(func_0012D8B0, 4, 0x100, 1);
}

void CEnvResMgr::CallFunc250368() {
    Func250368();
}
