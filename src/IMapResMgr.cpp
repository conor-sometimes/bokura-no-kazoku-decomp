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
    ~CResCache();
    void Init250208(void (*f)(), s32 a, s32 b, s32 c);
    void *Find250B08(s32 id);
    void Func250368();

    u8 pad0[0x13C];
};
// The vtables live in the CMapResObj data (asm); #pragma interface at the top keeps this
// unit from emitting them.
class IMapResMgr : public CResCache {
public:
    virtual ~IMapResMgr() {}
};
class CMapResMgr : public IMapResMgr {
public:
    virtual ~CMapResMgr();
    void Func12D848(s32 size, s32 n);
    s32 *FindRes(s32 id);
    void CallFunc250368();
};
extern CMapResMgr *D_002A0BE8;

//@sym __10CEnvResObj 0x12D8E8
//@sym __nw__8CHeapObjUi 0x245D20
class CHeapObj {
public:
    static void *operator new(unsigned int n);

    u8 m_base[4];             // 0x0 (layout unknown)
};
class CEnvResObj : public CHeapObj {
public:
    CEnvResObj() throw();

    u8 pad4[0x14];
};
void Func12D550();
// @decl-end

CMapResMgr::~CMapResMgr() {
    D_002A0BE8 = 0;
}

s32 *CMapResMgr::FindRes(s32 id) { CResCacheUnit *u = (CResCacheUnit *)Find250B08(id); if (u) return &u->m_res; return 0; }

void CMapResMgr::Func12D848(s32 size, s32 n) {
    if (size < 0) size = 0x100000;
    if (n < 0) n = 3;
    Init250208(Func12D550, n, size, 0x80);
}

void CMapResMgr::CallFunc250368() {
    Func250368();
}

// Factory callback for the env resource cache (IEnvResMgr refers to it by this name).
extern "C" CEnvResObj *func_0012D8B0() {
    return new CEnvResObj;
}
