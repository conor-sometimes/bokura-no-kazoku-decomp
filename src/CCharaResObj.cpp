#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CCharaRes {
public:
    CCharaRes();
    void Func112A80();

    u8 pad0[0x8C];
    s32 m_unk8C;              // 0x8C
    u8 pad90[0xC0 - 0x90];
};
class CHeapObj {
public:
    static void *operator new(unsigned int n);

    s32 m_unk0;               // 0x0
    CHeapObj() { m_unk0 = 0; }
};
// Resource cache entry: a self-linked list node, then the vptr at 0xC (as in CMapResObj.cpp).
class CResObj : public CHeapObj {
public:
    CResObj() { m_prev = this; m_next = this; }
    virtual ~CResObj();

    CResObj *m_next;          // 0x4
    CResObj *m_prev;          // 0x8
};
// Vtable _vt$12CCharaResObj: inline destructor (0x2970B8), Load (0x12D218), ResFunc112A80.
class CCharaResObj : public CResObj {
public:
    CCharaResObj() {}
    virtual ~CCharaResObj();
    virtual s32 Load(const char *name);
    virtual void ResFunc112A80();

    CCharaRes m_res;          // 0x10
};

//@sym __builtin_new 0x245648
// CCharaResMgr (ICharaResMgr.cpp): its factory and constructor sit at the end of this file (unit
// text starts late). CResCache is the library base (0x24FFE0); ICharaResMgr introduces the
// virtuals after its 0x13C bytes.
class CResCache {
public:
    CResCache();
    ~CResCache();

    u8 pad0[0x13C];
};
class ICharaResMgr : public CResCache {
public:
    virtual ~ICharaResMgr();
    virtual void V1() = 0;
};
class CCharaResMgr : public ICharaResMgr {
public:
    CCharaResMgr();
    virtual ~CCharaResMgr();
    virtual void V1();
};
extern CCharaResMgr *D_002A0BE4;

class CUnk2BA128 {
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual s32 V3();
};
extern CUnk2BA128 *D_002BA128;
extern "C" f32 func_002471D8();
extern "C" void func_00247178(f32 v);
extern "C" s32 func_002462B0();
extern "C" s32 func_00248E90(const char *path);
extern "C" s32 func_00112710(CCharaRes *p, const char *path);
extern "C" int sprintf(char *buf, const char *fmt, ...);
void Func2491A8(void *buf, const char *path, s32 a, s32 b, s32 c);
s32 Func249248(void *buf);
void Func249348();
int Func235DE0(const char *fmt, ...);
extern const char D_002D4ED8[], D_002D4EE0[], D_002D4EE8[], D_002D4EF8[], D_002D4F10[];
extern const char D_002D4F18[], D_002D4F28[];
// @decl-end

CCharaResObj *NewCharaResObj() {
    return new CCharaResObj;
}

s32 CCharaResObj::Load(const char *name) {
    u8 buf[0x100];
    char path[0x100];
    s32 opened = 0;
    f32 saved = func_002471D8();
    ResFunc112A80();
    if (D_002BA128) {
        CCharaRes *r = &m_res;
        r->m_unk8C = D_002BA128->V3();
    }
    Func2491A8(buf, (const char *)((u8 *)D_002A0BE4 + 0x3C), (s32)D_002D4ED8, (s32)D_002D4EE0, (s32)D_002D4EE8);
    if (!Func249248(buf)) {
        Func235DE0(D_002D4EF8, buf);
    } else {
        opened = 1;
        sprintf(path, D_002D4F10, name);
        if (func_00248E90(path) || (sprintf(path, D_002D4F18, name, name), func_00248E90(path))) {
            func_00247178(0.97f);
            if (func_00112710(&m_res, path)) {
                Func235DE0(D_002D4F28, path, func_002462B0());
            }
        }
    }
    if (opened) Func249348();
    func_00247178(saved);
    return 1;
}

void CCharaResObj::ResFunc112A80() {
    m_res.Func112A80();
}

CCharaResMgr *CreateCCharaResObjSub12D408() {
    return new CCharaResMgr;
}

CCharaResMgr::CCharaResMgr() {
    D_002A0BE4 = this;
}
