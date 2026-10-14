#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CPushBuf.h"

//@sym strcmp 0x28B190
#include "libc.h"
void *operator new(unsigned int n);
class CFlagWork {
public:
    int Func1091B0(s32 id);
};
extern CFlagWork *D_002A26E4;
struct CResNameEnt { s32 id; s32 v[2]; };
// Interface without fields (its RTTI name only): the vptr is at 0. Slot 0 is an inline
// `delete this` (emitted elsewhere), so CResNameMgr's key method is Func145D18.
class IResNameMgr {
public:
    virtual void Release() = 0;
    virtual int Func145D18() = 0;
    virtual void Init() = 0;
    virtual int Load(int k) = 0;
    virtual int GetValue(u32 kind, int id) = 0;
};
class CResNameMgr : public IResNameMgr {
public:
    CResNameMgr();
    virtual void Release() { delete this; }
    virtual int Func145D18();
    virtual void Init();
    virtual int Load(int k);
    virtual int GetValue(u32 kind, int id);
    virtual ~CResNameMgr();
    void Clear();
    void Init146F60();
    int Func146658(int k);
    int Func146DE8(int k);

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
INCLUDE_ASM("asm/nonmatchings/CResNameMgr", func_00145D18);
INCLUDE_RODATA("asm/nonmatchings/CResNameMgr", D_002D7C68);
INCLUDE_RODATA("asm/nonmatchings/CResNameMgr", D_002D7C78);
INCLUDE_RODATA("asm/nonmatchings/CResNameMgr", D_002D7C80);

INCLUDE_ASM("asm/nonmatchings/CResNameMgr", func_00145E18);
INCLUDE_RODATA("asm/nonmatchings/CResNameMgr", D_002D7CA8);
INCLUDE_RODATA("asm/nonmatchings/CResNameMgr", D_002D7CB8);

INCLUDE_ASM("asm/nonmatchings/CResNameMgr", func_00146238);
INCLUDE_RODATA("asm/nonmatchings/CResNameMgr", D_002D7CD0);
INCLUDE_RODATA("asm/nonmatchings/CResNameMgr", D_002D7CE0);

INCLUDE_ASM("asm/nonmatchings/CResNameMgr", func_00146410);

void CResNameMgr::Init() {
    m_buf.Func248E00();
    Clear();
}

int CResNameMgr::Load(int k) {
    switch (k) {
    case 1: return Func146658(k);
    case 2: return Func146DE8(k);
    }
    return 1;
}

int Season146608(int v) {
    if (v < 0) v = D_002A26E4->Func1091B0(0x17) % 4;
    return v / 2;
}

INCLUDE_ASM("asm/nonmatchings/CResNameMgr", Func146658__11CResNameMgri);

INCLUDE_ASM("asm/nonmatchings/CResNameMgr", func_001467E0);

INCLUDE_ASM("asm/nonmatchings/CResNameMgr", func_00146B58);

INCLUDE_ASM("asm/nonmatchings/CResNameMgr", func_00146C08);

INCLUDE_ASM("asm/nonmatchings/CResNameMgr", Func146DE8__11CResNameMgri);
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
