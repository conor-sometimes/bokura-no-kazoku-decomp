#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CPushBuf.h"

//@sym strcmp 0x28B190
#include "libc.h"
void *operator new(unsigned int n);
#include "CFlagWork.h"
struct CResNameEnt { s32 id; s32 v[2]; };
// Interface without fields (its RTTI name only): the vptr is at 0. Slot 0 is an inline
// `delete this` (emitted elsewhere); CResNameMgr declares it without a body so that it, not
// Func145D18, is the key method and the vtable stays asm.
class IResNameMgr {
public:
    virtual void Release() = 0;
    virtual int Func145D18(const char *path) = 0;
    virtual void Init() = 0;
    virtual int Load(int k, char *buf, int key) = 0;
    virtual int GetValue(u32 kind, int id) = 0;
};
class CResNameMgr : public IResNameMgr {
public:
    CResNameMgr();
    virtual void Release();
    virtual int Func145D18(const char *path);
    virtual void Init();
    virtual int Load(int k, char *buf, int key);
    virtual int GetValue(u32 kind, int id);
    virtual ~CResNameMgr();
    void Clear();
    void Init146F60();
    int Func146658(int k, char *buf, int key);
    int Func146DE8(int k, char *buf, int key);
    int Func1467E0(char *buf, int key, int a, int b);
    int Func146B58(char *buf, int key, int b);
    int Func146C08(char *buf, int key, int season);
    int Func145E18();
    int Func146238();
    int Func146410();

    CPushBuf m_buf;           // 0x4
    s32 m_unk10;              // 0x10
    s32 m_unk14;              // 0x14
    s32 m_unk18;              // 0x18
    s32 m_unk1C;              // 0x1C
    CResNameEnt *m20;         // 0x20
    s32 m24;                  // 0x24
};
extern CResNameMgr *D_002A28D8;
CResNameMgr *NewResNameMgr();
int Season146608(int v);
int FindString145CA8(const char **p, const char *s);

//@sym Func145E18__11CResNameMgr 0x145E18
extern s32 D_002A2964, D_002A2968, D_002A296C;
extern const char *D_002A2974, *D_002A2978, *D_002A297C, *D_002A2980;
extern const char D_002D7C78[], D_002D7C80[];
extern "C" void func_00248C30(CPushBuf *p);
extern "C" void func_00248C70(CPushBuf *p);
extern "C" char *func_00248DA8(CPushBuf *p);
extern "C" s32 func_00248DC0(CPushBuf *p);
extern "C" const char *func_0024A710(const char *p, s32 *v, s32 k, const char *s1, const char *s2);
extern "C" s32 func_0024B040(const char *s, s32 k);
const char *Func24A570(const char *s, char *buf, const char *a, const char *b);
const char *Func24AF10(void *p, const char *key);
const char *Func24AFE8(const char *p, char *buf, s32 a, s32 n);
void *Func24A4C0(const char *name);
extern void (*D_002B91B0)(void *p);
void Func2491A8(void *buf, const char *path, s32 a, s32 b, s32 c);
s32 Func249248(void *buf);
void Func249348();
int Func235DE0(const char *fmt, ...);

//@sym Func1467E0__11CResNameMgrPciii 0x1467E0
//@sym Func146B58__11CResNameMgrPcii 0x146B58
extern const char D_002D7C78[], D_002D7C80[];
extern "C" const char *func_0024A710(const char *p, s32 *v, s32 k, const char *s1, const char *s2);
const char *Func24A570(const char *s, char *buf, const char *a, const char *b);
extern "C" int func_00289118(const char *s);
extern "C" void func_0028B520(char *s);
extern "C" int sprintf(char *buf, const char *fmt, ...);
extern "C" unsigned int strlen(const char *s);
int Func1456A8(int v);
extern s32 D_002A2910[];
extern const char *D_002A28E0[];
inline char *StrCat(char *d, const char *s) { strcpy(d + strlen(d), s); return d; }
struct CResSchoolRec {
    s32 m_id;                 // 0x0
    const char *m_names[2];   // 0x4
};

int Func1456A8(int v);
// @decl-end

CResNameMgr::CResNameMgr() {
    D_002A28D8 = this;
    Clear();
    return;
}

CResNameMgr::~CResNameMgr() {
    Init();
    D_002A28D8 = 0;
}

void CResNameMgr::Clear() {
    m_unk10 = 0;
    m_unk14 = 0;
    m_unk18 = 0;
    m_unk1C = 0;
    m20 = 0;
    m24 = 0;
}

int FindString145CA8(const char **p, const char *s) {
    int i;
    for (i = 0; p[i]; i++) {
        if (!strcmp(p[i], s)) return i;
    }
    return -1;
}

INCLUDE_RODATA("asm/nonmatchings/CResNameMgr", D_002D7B90);
INCLUDE_RODATA("asm/nonmatchings/CResNameMgr", D_002D7B98);
INCLUDE_RODATA("asm/nonmatchings/CResNameMgr", D_002D7BA0);
INCLUDE_RODATA("asm/nonmatchings/CResNameMgr", D_002D7BA8);
INCLUDE_RODATA("asm/nonmatchings/CResNameMgr", D_002D7BB0);
INCLUDE_RODATA("asm/nonmatchings/CResNameMgr", D_002D7BB8);
INCLUDE_RODATA("asm/nonmatchings/CResNameMgr", D_002D7BC0);
INCLUDE_RODATA("asm/nonmatchings/CResNameMgr", D_002D7BC8);
INCLUDE_RODATA("asm/nonmatchings/CResNameMgr", D_002D7BD0);
INCLUDE_RODATA("asm/nonmatchings/CResNameMgr", D_002D7BD8);
INCLUDE_RODATA("asm/nonmatchings/CResNameMgr", D_002D7BE0);
INCLUDE_RODATA("asm/nonmatchings/CResNameMgr", D_002D7BE8);
INCLUDE_RODATA("asm/nonmatchings/CResNameMgr", D_002D7BF0);
INCLUDE_RODATA("asm/nonmatchings/CResNameMgr", D_002D7BF8);
INCLUDE_RODATA("asm/nonmatchings/CResNameMgr", D_002D7C00);
INCLUDE_RODATA("asm/nonmatchings/CResNameMgr", D_002D7C08);
INCLUDE_RODATA("asm/nonmatchings/CResNameMgr", D_002D7C10);
INCLUDE_RODATA("asm/nonmatchings/CResNameMgr", D_002D7C18);
INCLUDE_RODATA("asm/nonmatchings/CResNameMgr", D_002D7C20);
INCLUDE_RODATA("asm/nonmatchings/CResNameMgr", D_002D7C28);
int CResNameMgr::Func145D18(const char *path) {
    u8 buf[0x100];
    s32 opened = 0;
    s32 pushed = 0;
    s32 ok = 0;
    CPushBuf *pb;
    Func2491A8(buf, path, D_002A2964, D_002A2968, D_002A296C);
    if (Func249248(buf)) {
        pb = &m_buf;
        opened = 1;
        Func235DE0("resource name ...\n");
        pushed = 1;
        func_00248C30(pb);
        if (Func145E18() && Func146238()) ok = Func146410() != 0;
    } else {
        pb = &m_buf;
    }
    if (pushed) func_00248C70(pb);
    if (opened) Func249348();
    Func235DE0("size=%d\n", pb->m_unk4);
    return ok;
}
INCLUDE_RODATA("asm/nonmatchings/CResNameMgr", D_002D7C68);
INCLUDE_RODATA("asm/nonmatchings/CResNameMgr", D_002D7C78);
INCLUDE_RODATA("asm/nonmatchings/CResNameMgr", D_002D7C80);

INCLUDE_ASM("asm/nonmatchings/CResNameMgr", Func145E18__11CResNameMgr);
INCLUDE_RODATA("asm/nonmatchings/CResNameMgr", D_002D7CA8);
INCLUDE_RODATA("asm/nonmatchings/CResNameMgr", D_002D7CB8);

int CResNameMgr::Func146238() {
    char buf[0x100];
    s32 ok = 0;
    s32 i;
    void *data = Func24A4C0(D_002A2974);
    if (data) {
        const char *p = Func24AF10(data, D_002A2978);
        m_unk1C = func_0024B040(p, 1);
        m_unk18 = (s32)m_buf.Func248CC8(m_unk1C * 12, 1, 1);
        for (i = 0; i < m_unk1C; i++) {
            CResNameEnt *e = &((CResNameEnt *)m_unk18)[i];
            const char *q;
            p = Func24AFE8(p, buf, 1, 0x100);
            q = func_0024A710(buf, &e->id, 0, D_002D7C78, D_002D7C80);
            q = Func24A570(q, 0, D_002D7C78, D_002D7C80);
            q = Func24A570(q, func_00248DA8(&m_buf), D_002D7C78, D_002D7C80);
            e->v[0] = func_00248DC0(&m_buf);
            Func24A570(q, func_00248DA8(&m_buf), D_002D7C78, D_002D7C80);
            e->v[1] = func_00248DC0(&m_buf);
        }
        ok = 1;
        if (data) D_002B91B0(data);
    }
    Func235DE0(" school (%d)\n", ok);
    return ok;
}
INCLUDE_RODATA("asm/nonmatchings/CResNameMgr", D_002D7CD0);
INCLUDE_RODATA("asm/nonmatchings/CResNameMgr", D_002D7CE0);

int CResNameMgr::Func146410() {
    char buf[0x100];
    s32 ok = 0;
    s32 i;
    void *data = Func24A4C0(D_002A297C);
    if (data) {
        const char *p = Func24AF10(data, D_002A2980);
        m24 = func_0024B040(p, 1);
        m20 = (CResNameEnt *)m_buf.Func248CC8(m24 * 12, 1, 1);
        for (i = 0; i < m24; i++) {
            CResNameEnt *e = &m20[i];
            const char *q;
            p = Func24AFE8(p, buf, 1, 0x100);
            q = func_0024A710(buf, &e->id, 0, D_002D7C78, D_002D7C80);
            q = func_0024A710(q, &e->v[0], 0, D_002D7C78, D_002D7C80);
            func_0024A710(q, &e->v[1], 0, D_002D7C78, D_002D7C80);
        }
        ok = 1;
        if (data) D_002B91B0(data);
    }
    Func235DE0(" ctype motion (%d)\n", ok);
    return ok;
}

void CResNameMgr::Init() {
    m_buf.Func248E00();
    Clear();
}

int CResNameMgr::Load(int k, char *buf, int key) {
    switch (k) {
    case 1: return Func146658(k, buf, key);
    case 2: return Func146DE8(k, buf, key);
    }
    return 1;
}

int Season146608(int v) {
    if (v < 0) v = D_002A26E4->Func1091B0(0x17) % 4;
    return v / 2;
}

int CResNameMgr::Func146658(int k, char *buf, int key) {
    char tok[0x100];
    s32 a, b;
    const char *p = Func24A570(buf, tok, D_002D7C78, D_002D7C80);
    if (!strcmp(tok, "AG")) {
        p = func_0024A710(p, &a, 0, D_002D7C78, D_002D7C80);
        func_0024A710(p, &b, 0, D_002D7C78, D_002D7C80);
        return Func1467E0(buf, key, a, b);
    }
    if (!strcmp(tok, "AC")) {
        func_0024A710(p, &b, 0, D_002D7C78, D_002D7C80);
        return Func146B58(buf, key, b);
    }
    if (!strcmp(tok, "SC")) {
        func_0024A710(p, &b, 0, D_002D7C78, D_002D7C80);
        return Func146C08(buf, key, b);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/CResNameMgr", Func1467E0__11CResNameMgrPciii);

int CResNameMgr::Func146B58(char *buf, int key, int b) {
    s32 idx = Func1456A8(key);
    s32 v;
    if (idx < 0) return 0;
    s32 t;
    v = D_002A26E4->Func1091B0(idx + 0xD6);
    if (v == 13) t = 2;
    else t = v == 14;
    return Func1467E0(buf, key, t, b);
}

INCLUDE_ASM("asm/nonmatchings/CResNameMgr", Func146C08__11CResNameMgrPcii);

int CResNameMgr::Func146DE8(int k, char *buf, int key) {
    s32 idx = Func1456A8(key);
    s32 kind, r, v;
    if (idx < 0) return 1;
    v = func_00289118(buf);
    if (v == -100) kind = 0;
    else {
        kind = 1;
        if (v != -200) return 1;
    }
    r = GetValue(kind, D_002A26E4->Func1091B0(idx + 0xD6));
    if (r < 0) return 1;
    sprintf(buf, "%d", r);
    return 1;
}
INCLUDE_RODATA("asm/nonmatchings/CResNameMgr", D_002D7D60);
INCLUDE_RODATA("asm/nonmatchings/CResNameMgr", D_002D7D70);

int CResNameMgr::GetValue(u32 kind, int id) {
    int i;
    if (kind >= 2) return -1;
    for (i = 0; i < m24; i++) {
        if (m20[i].id == id) return m20[i].v[kind];
    }
    return -1;
}

CResNameMgr *NewResNameMgr() {
    CResNameMgr *p = (CResNameMgr *)operator new(0x258);
    p->Init146F60();
    return p;
}
