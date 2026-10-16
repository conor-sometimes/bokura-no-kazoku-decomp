#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
// CSvmRes (CSvmRes.cpp): vptr after its fields at 0x20.
class CSvmRes {
public:
    CSvmRes();
    virtual ~CSvmRes();
    void Release();

    u8 pad0[0x20];
};
// Message resource (CEventMesRes unit, another lane's: its constructor and destructor names
// reach it through config/aliases.ld).
class CEventMesResSub13DD98 {
public:
    CEventMesResSub13DD98();
    virtual ~CEventMesResSub13DD98();
    void Init();

    u8 pad0[0x20];
};
extern "C" void func_0013DA10(CEventMesResSub13DD98 *p, const char *name);
extern "C" int func_0012DFB0(void *svm, const char *name);
extern "C" void func_0024B650(const char *name, char *dir, void *out, s32 k);
extern "C" int sprintf(char *buf, const char *fmt, ...);
// The message manager (CEventMesRes unit): vptr at 0.
class CEventMesMgr {
public:
    virtual void V0();
    virtual void Add(CEventMesResSub13DD98 *res);
    virtual void Remove(CEventMesResSub13DD98 *res);
};
extern CEventMesMgr *D_002A0CE0;

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CEventRes, its
// only virtual. The vptr follows its members at 0x68.
class CEventRes {
public:
    CEventRes();
    virtual ~CEventRes();
    void Release();
    int Load(const char *name);
    int LoadArc(const char *name);

    CSvmRes m_svm;                // 0x00
    CEventMesResSub13DD98 m_mes;  // 0x24
    u8 m_unk48;                   // 0x48
    u8 pad49[0x1F];
};

//@sym strcpy 0x28B2D4
#include "libc.h"
extern "C" unsigned int strlen(const char *s);
extern "C" char *strncpy(char *d, const char *s, unsigned int n);
inline void StrCat(char *d, const char *s) { strcpy(d + strlen(d), s); }
void Func2491A8(void *buf, const char *path, s32 a, s32 b, s32 c);
s32 Func249248(void *buf);
void Func249348();
int Func235DE0(const char *fmt, ...) throw();
// @decl-end

CEventRes::CEventRes() {
    m_unk48 = 0;
}

CEventRes::~CEventRes() {
    Release();
}

int CEventRes::LoadArc(const char *name) {
    u8 arc[0x100];
    char path[0x100];
    int ok = 0;
    int opened = 0;
    Func2491A8(arc, 0, (s32)"FILE", (s32)"eventdir", (s32)"data/event.xap");
    if (!Func249248(arc)) {
        Func235DE0("*** not found %s\n", arc);
    } else {
        strcpy(path, name);
        StrCat(path, ".scb");
        opened = 1;
        if (func_0012DFB0(this, path)) {
            strcpy(path, name);
            StrCat(path, ".mes");
            func_0013DA10(&m_mes, path);
            if (D_002A0CE0) D_002A0CE0->Add(&m_mes);
            strncpy((char *)&m_unk48, name, 0x20);
            ok = 1;
        }
    }
    if (opened) Func249348();
    return ok;
}

int CEventRes::Load(const char *name) {
    char dir[0x100];
    char base[0x100];
    char path[0x100];
    if (!func_0012DFB0(this, name)) {
        return 0;
    }
    func_0024B650(name, dir, base, 0);
    sprintf(path, "%s%s.mes", dir, base);
    func_0013DA10(&m_mes, path);
    if (D_002A0CE0) {
        D_002A0CE0->Add(&m_mes);
    }
    func_0024B650(name, 0, &m_unk48, 0);
    return 1;
}

void CEventRes::Release() {
    if (D_002A0CE0) {
        D_002A0CE0->Remove(&m_mes);
    }
    m_mes.Init();
    m_svm.Release();
    m_unk48 = 0;
}
