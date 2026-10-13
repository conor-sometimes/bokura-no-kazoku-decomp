#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CResCache {
public:
    void Init250208(void (*f)(), s32 a, s32 b, s32 c);
    void *Find250B08(s32 id);
    void Func250368();
};
class CEnvResMgr : public CResCache {
public:
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

INCLUDE_ASM("asm/nonmatchings/IEnvResMgr", func_0012DC48);

s32 CEnvResMgr::GetItemUnk14(s32 id) {
    CEnvResItem *p = (CEnvResItem *)Find250B08(id);
    if (p) {
        return p->m_unk14;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/IEnvResMgr", func_0012DCE8);

void CEnvResMgr::InitCache() {
    Init250208(func_0012D8B0, 4, 0x100, 1);
}

void CEnvResMgr::CallFunc250368() {
    Func250368();
}
