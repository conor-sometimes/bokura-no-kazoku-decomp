#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
struct CResortDBEntry20 {
    u8 data[0x14];
};
#include "CPushBuf.h"
struct CResortDBEntry;
struct CResortSub10 {
    const char *m0;           // 0x0
    const char *m4;           // 0x4
    s32 m8;                   // 0x8
    s32 mC;                   // 0xC
};
struct CResortRec30 {
    s32 m_id;                 // 0x0
    s32 m4;                   // 0x4
    s32 m8;                   // 0x8
    s32 mC;                   // 0xC
    const char *m10;          // 0x10
    s32 m14;                  // 0x14
    s32 m18;                  // 0x18
    s32 m1C;                  // 0x1C
    s32 m20;                  // 0x20
    s32 m24;                  // 0x24
    CResortSub10 *m28;        // 0x28
    s32 m2C;                  // 0x2C
};
struct CResortRecC {
    s32 m_id;                 // 0x0
    s32 *m_values;            // 0x4
    s32 m_count;              // 0x8
};
// "GET" rows: id (index + 0x10), then m_count pairs of values.
struct CResortNameRec {
    s32 m_id;                 // 0x0
    s32 *m_values;            // 0x4
    s32 m_count;              // 0x8
};
int Func1456A8(int v);
class CVec4 {
public:
    f32 x, y, z, w;
};
struct CResortColorRec {
    const char *m_name;       // 0x0
    CVec4 *m_vals;            // 0x4
    s32 m_count;              // 0x8
};
const char *Func24ADE0(const char *p, char *buf, int n);
// Interface without fields (its RTTI name only): the vptr is at 0.
class IResortDBMgr {
public:
    virtual void Release() = 0;
    virtual int Func171DE8(const char *path) = 0;
    virtual void Init() = 0;
    virtual struct CResortRec30 *Func172920(s32 id) = 0;
    virtual int Func172968(const char *name, s32 idx, CVec4 *out) = 0;
    virtual int Func29A3F0() = 0;
    virtual int Func29A430() = 0;
    virtual int Func172A60(const char *name, s32 a, s32 b) = 0;
    virtual int Func172B28(s32 id) = 0;
    virtual struct CResortRecC *Func172B68(s32 id) = 0;
    virtual CResortDBEntry *GetEntryA(s32 i) = 0;
    virtual CResortDBEntry20 *GetEntryC(s32 i) = 0;
    virtual CResortDBEntry *GetEntryB(s32 i) = 0;
};
// Vtable 0x2C1570: slot 0 is an inline `delete this` (0x29A3B8, emitted elsewhere), the
// destructor is slot 13; slots 5 and 6 are inline too. Release is declared, not defined, so it is
// the key method and the vtable stays asm while Func171DE8 is C++.
class CResortDBMgr : public IResortDBMgr {
public:
    CResortDBMgr();
    virtual void Release();
    virtual int Func171DE8(const char *path);
    virtual void Init();
    virtual CResortRec30 *Func172920(s32 id);
    virtual int Func172968(const char *name, s32 idx, CVec4 *out);
    virtual int Func29A3F0();
    virtual int Func29A430();
    virtual int Func172A60(const char *name, s32 a, s32 b);
    virtual int Func172B28(s32 id);
    virtual CResortRecC *Func172B68(s32 id);
    virtual CResortDBEntry *GetEntryA(s32 i);
    virtual CResortDBEntry20 *GetEntryC(s32 i);
    virtual CResortDBEntry *GetEntryB(s32 i);
    virtual ~CResortDBMgr();
    void Clear();

    CPushBuf m_buf;           // 0x4
    CResortRec30 *m_unk10;    // 0x10
    s32 m_unk14;              // 0x14
    CResortNameRec *m_names;  // 0x18
    s32 m_numNames;           // 0x1C
    CResortRecC *m_recsC;     // 0x20
    s32 m_numC;               // 0x24
    CResortColorRec *m_colors; // 0x28
    s32 m_numColors;          // 0x2C
    s32 Load171EC0();
    s32 Func171F68(void *data);
    s32 Func1722D8(void *data);
    s32 Func172498(void *data);
    s32 Func172690();
};

struct CResortDBEntry {
    u8 data[0x10];
};
extern CResortDBEntry D_002A36F0[];
extern CResortDBEntry D_002A3850[];
extern CResortDBMgr *D_002A36E8;

extern CResortDBEntry20 D_002A3760[];

//@sym Func171F68__12CResortDBMgrPv 0x171F68
//@sym Func1722D8__12CResortDBMgrPv 0x1722D8
//@sym Func172498__12CResortDBMgrPv 0x172498
//@sym Func172690__12CResortDBMgr 0x172690
#include "libc.h"
extern "C" void func_00248C30(CPushBuf *p);
extern "C" void func_00248C70(CPushBuf *p);
void *Func24A4C0(const char *name);
extern void (*D_002B91B0)(void *p);
void Func2491A8(void *buf, const char *path, s32 a, s32 b, s32 c);
s32 Func249248(void *buf);
void Func249348();
int Func235DE0(const char *fmt, ...) throw();
void Func270C50(CVec4 *dst, const CVec4 *src);

extern "C" const char *func_0024A710(const char *p, s32 *v, s32 k, const char *s1, const char *s2);
extern "C" s32 func_0024A7D8(const char *s, const char *a, const char *b);
extern "C" s32 func_0024B040(const char *s, s32 k);
const char *Func24A570(const char *s, char *buf, const char *a, const char *b);
const char *Func24AF10(void *p, const char *key);
const char *Func24AFE8(const char *p, char *buf, s32 a, s32 n);
extern const char D_002DA0D8[], D_002DA0E0[];

int CountLines172640(const char *p);
extern "C" char *func_0024A778(char *p, f32 *v, f32 def, const char *s1, const char *s2);
extern "C" char *func_00248DA8(void *buf);
extern "C" char *func_00248DC0(void *buf);
// @decl-end

CResortDBMgr::CResortDBMgr() {
    D_002A36E8 = this;
    Clear();
}

CResortDBMgr::~CResortDBMgr() {
    Init();
    D_002A36E8 = 0;
}

void CResortDBMgr::Clear() {
    m_unk10 = 0;
    m_unk14 = 0;
    m_colors = 0;
    m_numColors = 0;
}

int CResortDBMgr::Func171DE8(const char *path) {
    u8 buf[0x100];
    CPushBuf *pb = &m_buf;
    Init();
    Func2491A8(buf, path, (s32)"FILE", (s32)"resortdb", (s32)"data/resortdb.xap");
    if (!Func249248(buf)) return 0;
    Func235DE0("resort database ...\n");
    func_00248C30(pb);
    if (Load171EC0()) Func172690();
    func_00248C70(pb);
    Func249348();
    Func235DE0("size=%d\n", pb->m_unk4);
    return 1;
}

s32 CResortDBMgr::Load171EC0() {
    s32 ok = 0;
    void *data = Func24A4C0("resort.txt");
    if (data) {
        if (Func171F68(data) && Func1722D8(data)) ok = Func172498(data) != 0;
        if (data) D_002B91B0(data);
    }
    Func235DE0(" resort (%d)\n", ok);
    return ok;
}

s32 CResortDBMgr::Func171F68(void *data) {
    char line[256];
    char tok[256];
    const char *p;
    s32 i, j;
    const char *q;
    p = Func24AF10(data, "INFO");
    if (!*p) return 0;
    m_unk14 = func_0024B040(p, 1);
    m_unk10 = (CResortRec30 *)m_buf.Func248CC8(m_unk14 * sizeof(CResortRec30), 1, 1);
    for (i = 0; i < m_unk14; i++) {
        CResortRec30 *r = &m_unk10[i];
        p = Func24AFE8(p, line, 1, 0x100);
        q = func_0024A710(line, &r->m_id, 0, D_002DA0D8, D_002DA0E0);
        q = Func24A570(q, func_00248DA8(&m_buf), D_002DA0D8, D_002DA0E0);
        r->m4 = (s32)func_00248DC0(&m_buf);
        q = func_0024A710(q, &r->m8, 0, D_002DA0D8, D_002DA0E0);
        q = func_0024A710(q, &r->mC, 0, D_002DA0D8, D_002DA0E0);
        q = func_0024A710(q, &r->m1C, 0, D_002DA0D8, D_002DA0E0);
        q = func_0024A710(q, &r->m20, 0, D_002DA0D8, D_002DA0E0);
        q = func_0024A710(q, &r->m24, 0, D_002DA0D8, D_002DA0E0);
        q = Func24A570(q, func_00248DA8(&m_buf), D_002DA0D8, D_002DA0E0);
        r->m10 = func_00248DC0(&m_buf);
        q = func_0024A710(q, &r->m14, 0, D_002DA0D8, D_002DA0E0);
        q = func_0024A710(q, &r->m18, 0, D_002DA0D8, D_002DA0E0);
        r->m2C = func_0024A7D8(q, D_002DA0D8, D_002DA0E0) / 4;
        r->m28 = (CResortSub10 *)m_buf.Func248CC8(r->m2C * sizeof(CResortSub10), 1, 1);
        for (j = 0; j < r->m2C; j++) {
            CResortSub10 *e = &r->m28[j];
            q = Func24A570(q, func_00248DA8(&m_buf), D_002DA0D8, D_002DA0E0);
            e->m0 = func_00248DC0(&m_buf);
            q = Func24A570(q, func_00248DA8(&m_buf), D_002DA0D8, D_002DA0E0);
            e->m4 = func_00248DC0(&m_buf);
            q = func_0024A710(q, &e->m8, 0, D_002DA0D8, D_002DA0E0);
            q = func_0024A710(q, &e->mC, 0, D_002DA0D8, D_002DA0E0);
        }
    }
    return 1;
}
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA0D8);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA0E0);

INCLUDE_ASM("asm/nonmatchings/CResortDBMgr", Func1722D8__12CResortDBMgrPv);

s32 CResortDBMgr::Func172498(void *data) {
    char buf[0x100];
    const char *p = Func24AF10(data, "ORDER");
    CPushBuf *pb;
    s32 i, j;
    if (!*p) return 0;
    m_numC = func_0024B040(p, 1);
    pb = &m_buf;
    m_recsC = (CResortRecC *)pb->Func248CC8(m_numC * 12, 1, 1);
    for (i = 0; i < m_numC; i++) {
        CResortRecC *e = &m_recsC[i];
        const char *q;
        p = Func24AFE8(p, buf, 1, 0x100);
        q = func_0024A710(buf, &e->m_id, 0, D_002DA0D8, D_002DA0E0);
        e->m_count = func_0024A7D8(q, D_002DA0D8, D_002DA0E0);
        e->m_values = (s32 *)pb->Func248CC8(e->m_count * 4, 1, 1);
        for (j = 0; j < e->m_count; j++) {
            q = func_0024A710(q, &e->m_values[j], 0, D_002DA0D8, D_002DA0E0);
        }
    }
    return 1;
}

int CountLines172640(const char *p) {
    s32 n = 0;
    char buf[0x100];
    while ((p = Func24ADE0(p, buf, 0x100), *p) || buf[0]) {
        n++;
    }
    return n;
}

s32 CResortDBMgr::Func172690() {
    char line[256];
    void *data;
    s32 i, j;
    int ok = 0;
    data = Func24A4C0("location.txt");
    if (data) {
        m_numColors = CountLines172640((const char *)data);
        m_colors = (CResortColorRec *)m_buf.Func248CC8(m_numColors * sizeof(CResortColorRec), 1, 1);
        const char *p = (const char *)data;
        for (i = 0; i < m_numColors; i++) {
            CResortColorRec *r = &m_colors[i];
            p = Func24ADE0(p, func_00248DA8(&m_buf), 0x100);
            r->m_name = func_00248DC0(&m_buf);
            r->m_count = func_0024B040(p, 1);
            const char *q = p;
            r->m_vals = (CVec4 *)m_buf.Func248CC8(r->m_count * sizeof(CVec4), 1, 1);
            for (j = 0; j < r->m_count; j++) {
                CVec4 *v = &r->m_vals[j];
                q = Func24AFE8(q, line, 1, 0x100);
                char *s = func_0024A778(line, &v->x, 0.0f, D_002DA0D8, D_002DA0E0);
                s = func_0024A778(s, &v->y, 0.0f, D_002DA0D8, D_002DA0E0);
                s = func_0024A778(s, &v->z, 0.0f, D_002DA0D8, D_002DA0E0);
                func_0024A778(s, &v->w, 0.0f, D_002DA0D8, D_002DA0E0);
                v->w /= 360.0f;
            }
        }
        ok = 1;
    }
    if (data) D_002B91B0(data);
    return ok;
}
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA108);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA118);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA128);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA138);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA148);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA158);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA160);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA170);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA180);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA190);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA1A0);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA1B0);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA1C0);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA1D0);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA1E0);
INCLUDE_RODATA("asm/nonmatchings/CResortDBMgr", D_002DA1F0);

void CResortDBMgr::Init() {
    m_buf.Func248E00();
    Clear();
}

CResortRec30 *CResortDBMgr::Func172920(s32 id) {
    s32 i;
    for (i = 0; i < m_unk14; i++) {
        if (m_unk10[i].m_id == id) return &m_unk10[i];
    }
    return 0;
}

int CResortDBMgr::Func172968(const char *name, s32 idx, CVec4 *out) {
    s32 i;
    memset(out, 0, 0x10);
    for (i = 0; i < m_numColors; i++) {
        CResortColorRec *e = &m_colors[i];
        if (!strcmp(e->m_name, name)) {
            if (idx < 0 || idx >= e->m_count) return 0;
            Func270C50(out, &e->m_vals[idx]);
            return 1;
        }
    }
    return 0;
}

// Func172A60: `for (i < m_numNames) if (Func1456A8(name_i) == Func1456A8(name)) { s32 *row =
// e->m_values + a * 2; return row[b]; } return -1;` is DIFF 2: retail adds `a*8 + base` with the
// operands the other way round (tried four commutations).
int CResortDBMgr::Func172A60(const char *name, s32 a, s32 b) { s32 i; for (i = 0; i < m_numNames; i++) { CResortNameRec *e = &m_names[i]; if (Func1456A8((int)e->m_id) == Func1456A8((int)name)) return *(s32 *)((a << 3) + (s32)e->m_values + (b << 2)); } return -1; }

int CResortDBMgr::Func172B28(s32 id) {
    s32 i;
    for (i = 0; i < m_unk14; i++) {
        if (m_unk10[i].m_id == id) return m_unk10[i].m8;
    }
    return -1;
}

CResortRecC *CResortDBMgr::Func172B68(s32 id) {
    s32 i;
    for (i = 0; i < m_numC; i++) {
        if (m_recsC[i].m_id == id) return &m_recsC[i];
    }
    return 0;
}

CResortDBEntry *CResortDBMgr::GetEntryA(s32 i) {
    if (i < 1 || i > 6) {
        return 0;
    }
    return &D_002A36F0[i];
}

CResortDBEntry20 *CResortDBMgr::GetEntryC(s32 i) {
    if (i < 8 || i > 11) {
        return 0;
    }
    return &D_002A3760[i];
}

CResortDBEntry *CResortDBMgr::GetEntryB(s32 i) {
    if (i < 12 || i > 38) {
        return 0;
    }
    return &D_002A3850[i];
}
