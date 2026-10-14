#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CMapRes {
public:
    CMapRes();
    void Func11AC70();

    u8 pad0[0x30];
};
//@sym __nw__8CHeapObjUi 0x245D20
class CHeapObj {
public:
    static void *operator new(unsigned int n);

    s32 m_unk0;               // 0x0
    CHeapObj() { m_unk0 = 0; }
};
// Resource cache entry: a self-linked list node, then the vptr at 0xC.
class CResObj : public CHeapObj {
public:
    CResObj() { m_prev = this; m_next = this; }
    virtual ~CResObj() {}
    virtual void Func12D5A0() = 0;
    virtual void ResFunc11AC70() = 0;

    CResObj *m_next;          // 0x4
    CResObj *m_prev;          // 0x8
};
// Vtable 0x2C05A0: slot 0 is an inline destructor (0x2972F8), so the key method is Func12D5A0.
class CMapResObj : public CResObj {
public:
    CMapResObj() {}
    virtual ~CMapResObj() {}
    virtual void Func12D5A0();
    virtual void ResFunc11AC70();

    CMapRes m_res;            // 0x10
};

void *operator new(unsigned int n);

// CMapResMgr (IMapResMgr.cpp): its factory and constructor sit at the end of this file (unit
// text starts late). CResCache is the library base (0x24FFE0); IMapResMgr introduces the
// virtuals after its 0x13C bytes and has an inline destructor (0x297240).
class CResCache {
public:
    CResCache();
    ~CResCache();

    u8 pad0[0x13C];
};
class IMapResMgr : public CResCache {
public:
    virtual ~IMapResMgr() {}
    virtual void V1() = 0;
    virtual s32 *FindRes(s32 id) = 0;
    virtual void Func12D848(s32 size, s32 n) = 0;
    virtual void CallFunc250368() = 0;
};
class CMapResMgr : public IMapResMgr {
public:
    CMapResMgr();
    virtual ~CMapResMgr();
    virtual void V1();
    virtual s32 *FindRes(s32 id);
    virtual void Func12D848(s32 size, s32 n);
    virtual void CallFunc250368();
};
extern CMapResMgr *D_002A0BE8;
CMapResMgr *NewCMapResObj();
// @decl-end

CMapResObj *Func12D550() {
    return new CMapResObj;
}

INCLUDE_ASM("asm/nonmatchings/CMapResObj", func_0012D5A0);

void CMapResObj::ResFunc11AC70() {
    m_res.Func11AC70();
}

CMapResMgr *NewCMapResObj() {
    return new CMapResMgr;
}

CMapResMgr::CMapResMgr() {
    D_002A0BE8 = this;
}
