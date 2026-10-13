#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CResCacheUnit {
public:
    u8 pad0[0x10];
    s32 m_res;                // 0x10
};
class CResCache {
public:
    void *Find250B08(s32 id);
    void Func250368();
};
class CMapResMgr : public CResCache {
public:
    s32 *FindRes(s32 id);
    void CallFunc250368();
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/IMapResMgr", func_0012D7A0);

INCLUDE_ASM("asm/nonmatchings/IMapResMgr", func_0012D818);

INCLUDE_ASM("asm/nonmatchings/IMapResMgr", func_0012D848);

void CMapResMgr::CallFunc250368() {
    Func250368();
}

INCLUDE_ASM("asm/nonmatchings/IMapResMgr", func_0012D8B0);
