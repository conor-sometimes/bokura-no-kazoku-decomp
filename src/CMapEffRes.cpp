#pragma interface
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

void Func11CA30(void *list);
extern "C" void func_002950B8(void *arr, s32 flags);   // TArray<> destructor (linkonce)
// Key method: #pragma interface (top) keeps this unit from emitting the vtables (asm data).
CMapEffRes::~CMapEffRes() {
    Func11CA30(m_list);
    func_002950B8(m_list, 2);
}

INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", D_002D3E58);
INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", D_002D3E60);
INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", D_002D3E70);
INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", D_002D3E80);
INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", D_002D3E88);
INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", D_002D3E98);
INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", D_002D3EA8);
INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", D_002D3EB8);
INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", D_002D3EC8);
INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", D_002D3ED8);
INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", D_002D3EE8);
INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", D_002D3EF0);
INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", D_002D3EF8);
INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", D_002D3F00);
INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", D_002D3F08);
INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", D_002D3F10);
INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", D_002D3F18);
INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", D_002D3F20);
INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", D_002D3F28);
INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", D_002D3F30);
INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", D_002D3F38);
INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", D_002D3F40);
INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", D_002D3F48);
INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", D_002D3F50);
INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", D_002D3F58);
INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", D_002D3F60);
INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", D_002D3F68);
INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", D_002D3F70);
INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", D_002D3F78);
INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", D_002D3F80);
INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", D_002D3F88);
INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", D_002D3F90);
INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", D_002D3F98);
INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", D_002D3FA0);
INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", D_002D3FA8);
INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", D_002D3FB0);
INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", D_002D3FB8);
INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", D_002D3FC0);
INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", D_002D3FC8);
INCLUDE_ASM("asm/nonmatchings/CMapEffRes", func_0011BD90);
INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", D_002D4078);
INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", D_002D4080);
INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", D_002D40B0);
INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", D_002D40E8);
INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", D_002D4108);
INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", D_002D4120);
INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", jtbl_002D4130);

INCLUDE_ASM("asm/nonmatchings/CMapEffRes", func_0011C428);
INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", D_002D4188);
INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", D_002D41C0);

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
INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", D_002D41F0);
INCLUDE_RODATA("asm/nonmatchings/CMapEffRes", D_002D4230);
