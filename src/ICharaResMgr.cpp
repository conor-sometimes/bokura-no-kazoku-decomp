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
class CCharaResMgr : public CResCache {
public:
    void InitCache(s32 size, s32 n);
    s32 *FindRes(s32 id);
    void CallFunc250368();
};

extern "C" void func_0012D1C8();
// @decl-end

INCLUDE_ASM("asm/nonmatchings/ICharaResMgr", func_0012D440);

INCLUDE_ASM("asm/nonmatchings/ICharaResMgr", func_0012D4B8);

void CCharaResMgr::InitCache(s32 size, s32 n) {
    if (size < 0) size = 0x64000;
    if (n < 0) n = 0x18;
    Init250208(func_0012D1C8, n, size, 0x80);
}

void CCharaResMgr::CallFunc250368() {
    Func250368();
}
