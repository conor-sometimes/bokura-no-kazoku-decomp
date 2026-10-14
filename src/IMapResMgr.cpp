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
};
class CMapResMgr : public CResCache {
public:
    void Func12D848(s32 size, s32 n);
    s32 *FindRes(s32 id);
    void CallFunc250368();
};

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

INCLUDE_ASM("asm/nonmatchings/IMapResMgr", func_0012D7A0);

INCLUDE_ASM("asm/nonmatchings/IMapResMgr", func_0012D818);

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
