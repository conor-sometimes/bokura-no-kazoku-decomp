#pragma interface
#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CMapRes {
public:
    CMapRes();
    void Func11AC70();
    s32 LoadFile(const char *path);

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
    virtual s32 Func12D5A0(const char *name) = 0;
    virtual void ResFunc11AC70() = 0;

    CResObj *m_next;          // 0x4
    CResObj *m_prev;          // 0x8
};
// Vtable 0x2C05A0: slot 0 is an inline destructor (0x2972F8), so the key method is Func12D5A0.
class CMapResObj : public CResObj {
public:
    CMapResObj() {}
    virtual ~CMapResObj() {}
    virtual s32 Func12D5A0(const char *name);
    virtual void ResFunc11AC70();

    CMapRes m_res;            // 0x10
};

void *operator new(unsigned int n);

// CMapResMgr (IMapResMgr.cpp merged in by lane lb: one object; #pragma interface keeps the vtables in asm). CResCache is the library base (0x24FFE0); IMapResMgr introduces the
// virtuals after its 0x13C bytes and has an inline destructor (0x297240).
class CResCacheUnit {
public:
    u8 pad0[0x10];
    s32 m_res;                // 0x10
};
class CResCache {
public:
    CResCache();
    ~CResCache();
    void Init250208(void (*f)(), s32 a, s32 b, s32 c);
    void *Find250B08(s32 id);
    void Func250368();

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
//@sym __10CEnvResObj 0x12D8E8
class CEnvResObj : public CHeapObj {
public:
    CEnvResObj() throw();

    u8 pad4[0x14];
};
CMapResObj *Func12D550();
extern "C" f32 func_002471D8();
extern "C" void func_00247178(f32 v);
extern "C" s32 func_002462B0();
extern "C" s32 func_00248E90(const char *path);
extern "C" int sprintf(char *buf, const char *fmt, ...);
void Func2491A8(void *buf, const char *path, s32 a, s32 b, s32 c);
s32 Func249248(void *buf);
void Func249348();
int Func235DE0(const char *fmt, ...) throw();
// @decl-end

CMapResObj *Func12D550() {
    return new CMapResObj;
}

INCLUDE_RODATA("asm/nonmatchings/CMapResObj", D_002D4F70);
s32 CMapResObj::Func12D5A0(const char *name) {
    u8 buf[0x100];
    char path[0x100];
    s32 opened = 0;
    f32 saved = func_002471D8();
    ResFunc11AC70();
    Func2491A8(buf, (const char *)((u8 *)D_002A0BE8 + 0x3C), (s32)"FILE", (s32)"mapdir", (s32)"data/map.xap");
    if (!Func249248(buf)) {
        Func235DE0("*** not found %s\n", buf);
    } else {
        opened = 1;
        sprintf(path, "%s.xap", name);
        if (func_00248E90(path) || (sprintf(path, "%s/%s.txt", name, name), func_00248E90(path))) {
            func_00247178(0.95f);
            if (m_res.LoadFile(path)) {
                Func235DE0("map(%s,left=%d)\n", path, func_002462B0());
            }
        }
    }
    if (opened) Func249348();
    func_00247178(saved);
    return 1;
}

void CMapResObj::ResFunc11AC70() {
    m_res.Func11AC70();
}

CMapResMgr *NewCMapResObj() {
    return new CMapResMgr;
}

CMapResMgr::CMapResMgr() {
    D_002A0BE8 = this;
}

CMapResMgr::~CMapResMgr() {
    D_002A0BE8 = 0;
}

s32 *CMapResMgr::FindRes(s32 id) { CResCacheUnit *u = (CResCacheUnit *)Find250B08(id); if (u) return &u->m_res; return 0; }

void CMapResMgr::Func12D848(s32 size, s32 n) {
    if (size < 0) size = 0x100000;
    if (n < 0) n = 3;
    Init250208((void (*)())Func12D550, n, size, 0x80);
}

void CMapResMgr::CallFunc250368() {
    Func250368();
}

// Factory callback for the env resource cache (IEnvResMgr refers to it by this name).
extern "C" CEnvResObj *func_0012D8B0() {
    return new CEnvResObj;
}
INCLUDE_RODATA("asm/nonmatchings/CMapResObj", D_002D5010);
INCLUDE_RODATA("asm/nonmatchings/CMapResObj", D_002D5020);
INCLUDE_RODATA("asm/nonmatchings/CMapResObj", D_002D5030);
