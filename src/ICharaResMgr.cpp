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
class CCharaResMgr : public CResCache {
public:
    s32 *FindRes(s32 id);
    void CallFunc250368();
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/ICharaResMgr", func_0012D440);

INCLUDE_ASM("asm/nonmatchings/ICharaResMgr", func_0012D4B8);

INCLUDE_ASM("asm/nonmatchings/ICharaResMgr", func_0012D4E8);

void CCharaResMgr::CallFunc250368() {
    Func250368();
}
