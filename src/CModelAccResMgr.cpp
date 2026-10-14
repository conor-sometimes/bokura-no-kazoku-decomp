#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
// Members built here; their units belong to other lanes, so the constructor and destructor
// names reach them through config/aliases.ld.
class CModelTbl {
public:
    CModelTbl();
    virtual ~CModelTbl();
    u8 pad0[0x1C];
};
class CMotionTbl {
public:
    CMotionTbl();
    virtual ~CMotionTbl();
    void Release();
    u8 pad0[0xC];
};
class CSwingBoneRes2 {
public:
    CSwingBoneRes2();
    virtual ~CSwingBoneRes2();
    void Func111CF8();
    u8 pad0[0xC];
};
extern "C" void func_001109D8(CModelTbl *p);

// Interface without fields (its RTTI name only): the vptr is at 0.
class IModelAccResMgr {
public:
    virtual void Release() = 0;
    virtual int Func118078() = 0;
    virtual void Func118130() = 0;
    virtual int Func294288() = 0;
    virtual int Func294290() = 0;
    virtual int Func294298() = 0;
};
// Vtable 0x2C00B0: slot 0 is an inline `delete this` (emitted elsewhere), so the key method is
// Func118078, not the destructor (slot 6). The factory is CreateSub117F98 in CCharaObj.cpp.
class CModelAccResMgr : public IModelAccResMgr {
public:
    CModelAccResMgr();
    virtual void Release() { delete this; }
    virtual int Func118078();
    virtual void Func118130();
    virtual int Func294288();
    virtual int Func294290();
    virtual int Func294298();
    virtual ~CModelAccResMgr();

    CModelTbl m_models;       // 0x04
    CMotionTbl m_motions;     // 0x24
    CSwingBoneRes2 m_swing;   // 0x34
};
extern CModelAccResMgr *D_002A05D0;
// @decl-end

CModelAccResMgr::CModelAccResMgr() {
    D_002A05D0 = this;
}

CModelAccResMgr::~CModelAccResMgr() {
    Func118130();
    D_002A05D0 = 0;
}

INCLUDE_RODATA("asm/nonmatchings/CModelAccResMgr", D_002D3780);
INCLUDE_RODATA("asm/nonmatchings/CModelAccResMgr", D_002D3788);
INCLUDE_RODATA("asm/nonmatchings/CModelAccResMgr", D_002D3790);
INCLUDE_RODATA("asm/nonmatchings/CModelAccResMgr", D_002D37A0);
INCLUDE_RODATA("asm/nonmatchings/CModelAccResMgr", D_002D37B0);
INCLUDE_RODATA("asm/nonmatchings/CModelAccResMgr", D_002D37C0);
INCLUDE_ASM("asm/nonmatchings/CModelAccResMgr", func_00118078);
INCLUDE_RODATA("asm/nonmatchings/CModelAccResMgr", D_002D37F0);
INCLUDE_RODATA("asm/nonmatchings/CModelAccResMgr", D_002D3808);

void CModelAccResMgr::Func118130() {
    m_swing.Func111CF8();
    m_motions.Release();
    func_001109D8(&m_models);
}

INCLUDE_ASM("asm/nonmatchings/CModelAccResMgr", func_00118168);
