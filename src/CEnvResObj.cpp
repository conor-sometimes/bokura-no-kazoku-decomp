#pragma interface
#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CHeapObj {
public:
    static void *operator new(unsigned int n);

    s32 m_unk0;               // 0x0
    CHeapObj() { m_unk0 = 0; }
};
// Resource cache entry: the CListTag list node (CList.h; m_unk0 = its head flag), then the
// vptr at 0xC. Its destructor is inline here (retail inlines the unlink into ~CEnvResObj);
// #pragma interface at the top keeps this unit from emitting the vtables (they stay in asm).
class CListTag : public CHeapObj {
public:
    CListTag() { m_prev = this; m_next = this; }
    virtual ~CListTag() {
        m_next->m_prev = m_prev;
        m_prev->m_next = m_next;
        m_prev = this;
        m_next = this;
    }

    CListTag *m_next;         // 0x4
    CListTag *m_prev;         // 0x8
};
class CEnvResObj : public CListTag {
public:
    CEnvResObj();
    static CEnvResObj *Create();
    virtual ~CEnvResObj();
    virtual s32 Load(const char *name);
    virtual void Release();

    void *m_unk10;            // 0x10
    s32 m_unk14;              // 0x14
};
class CResCache {
public:
    CResCache();
    ~CResCache();

    u8 pad0[0x13C];
};
class IEnvResMgr : public CResCache {
public:
    virtual ~IEnvResMgr();
    virtual void V1() = 0;
};
class CEnvResMgr : public IEnvResMgr {
public:
    CEnvResMgr();
    virtual ~CEnvResMgr();
    virtual void V1();
};
extern CEnvResMgr *D_002A0BEC;

// Graphics/sound manager at D_002BA248 (as CGsMgr in CTitleMain.cpp).
class CGsMgr {
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual s32 V27(s32 kind, const char *name, void *data);
    virtual void V28();
    virtual void V29();
    virtual void V30();
    virtual void V31();
    virtual void V32(s32 a, s32 b);
};
extern CGsMgr *D_002BA248;
extern "C" void func_00219950(void *p);
extern "C" void *func_00219818(s32 a, s32 size);
extern "C" void func_0028B520(char *s);
extern "C" int sprintf(char *buf, const char *fmt, ...);
// File helpers (library, named CPushBuf methods elsewhere; called on a path buffer here).
class CPushBuf {
public:
    int Func248EB0();
    int Func248EE0(void *p);
};
void Func2491A8(void *buf, const char *path, s32 a, s32 b, s32 c);
s32 Func249248(void *buf);
void Func249348();
int Func235DE0(const char *fmt, ...) throw();
extern const char D_002D5078[], D_002D5080[], D_002D5088[], D_002D5098[], D_002D50B0[];
extern const char D_002D50B8[], D_002D50D0[], D_002D50F0[], D_002D5108[];
// @decl-end

CEnvResObj::CEnvResObj() {
    m_unk10 = 0;
    m_unk14 = -1;
}

CEnvResObj::~CEnvResObj() {
    Release();
}

s32 CEnvResObj::Load(const char *name) {
    u8 buf[0x100];
    char path[0x100];
    s32 opened = 0;
    s32 size;
    Release();
    Func2491A8(buf, (const char *)((u8 *)D_002A0BEC + 0x3C), (s32)D_002D5078, (s32)D_002D5080, (s32)D_002D5088);
    if (!Func249248(buf)) {
        Func235DE0(D_002D5098, buf);
    } else {
        opened = 1;
        sprintf(path, D_002D50B0, name);
        func_0028B520(path);
        size = ((CPushBuf *)path)->Func248EB0();
        if (size < 0) {
            Func235DE0(D_002D5098, path);
        } else if (!(m_unk10 = func_00219818(7, size))) {
            Func235DE0(D_002D50B8, path, size);
        } else if (((CPushBuf *)path)->Func248EE0(m_unk10) != size) {
            Func235DE0(D_002D50D0, path);
        } else if ((m_unk14 = D_002BA248->V27(0xB, name, m_unk10)) < 0) {
            Func235DE0(D_002D50F0, path);
        } else {
            Func235DE0(D_002D5108, path, size);
        }
    }
    if (opened) Func249348();
    return 1;
}

void CEnvResObj::Release() {
    if (m_unk14 >= 0) {
        D_002BA248->V32(m_unk14, 0);
        m_unk14 = -1;
    }
    if (m_unk10) {
        func_00219950(m_unk10);
        m_unk10 = 0;
    }
}

CEnvResObj *CEnvResObj::Create() {
    return (CEnvResObj *)new CEnvResMgr;
}

CEnvResMgr::CEnvResMgr() {
    D_002A0BEC = this;
}
