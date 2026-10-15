#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" void func_0011CAE0(void *p);
class CMapEffObjRes {
public:
    static CMapEffObjRes *Create();
};

extern "C" s32 func_00295110(void *p);
extern "C" void **func_00295170(void *p, s32 i);
extern "C" void func_00295188(void *p, s32 v);

extern "C" void *func_00295090(void *list);
class CMapEffRes {
public:
    CMapEffRes();
    virtual ~CMapEffRes();
    u8 m_list[0x18];
};
// @decl-end

CMapEffRes::CMapEffRes() {
    func_00295090(m_list);
}

INCLUDE_ASM("asm/nonmatchings/CMapEffRes", func_0011BD20);

INCLUDE_ASM("asm/nonmatchings/CMapEffRes", func_0011BD90);

INCLUDE_ASM("asm/nonmatchings/CMapEffRes", func_0011C428);

void Func11CA30(void *list) {
    s32 n = func_00295110(list);
    for (s32 i = 0; i < n; i++) {
        operator delete(*func_00295170(list, i));
    }
    func_00295188(list, 0);
}

CMapEffObjRes *CMapEffObjRes::Create() {
    CMapEffObjRes *p = (CMapEffObjRes *)operator new(0x114);
    func_0011CAE0(p);
    return p;
}
