#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
//@sym memset 0x289FB0
#include "libc.h"

// Members created by the constructor; only their virtual destructors are called here.
class CMapAttr {
public:
    virtual ~CMapAttr();
    void CallFunc1182B8();

    u8 pad0[0x154];
    // vptr 0x154
};
class CMapEffRes {
public:
    virtual ~CMapEffRes();

    u8 pad0[0x18];
    // vptr 0x18
};
class CMapSndRes {
public:
    CMapSndRes();
    virtual ~CMapSndRes();
    void CallFunc127928();

    u64 pad0[0x2F];           // 8-aligned: sizeof is 0x180
    // vptr 0x178
};
extern "C" void func_00118210(void *p);
extern "C" void func_0011BD00(void *p);

struct CMapItem {
    CMapItem *m_next0;        // 0x0
    CMapItem *m_next4;        // 0x4
    char m_name[0x20];        // 0x8
    s32 m28;                  // 0x28
    s32 m2C;                  // 0x2C
    s32 m30;                  // 0x30
    void *m34;                // 0x34
    s32 m38;                  // 0x38
    s32 m3C;                  // 0x3C
    s32 m40;                  // 0x40
    void *m44;                // 0x44
    s32 m48;                  // 0x48
    s32 m4C;                  // 0x4C
    s32 m50;                  // 0x50
    s32 m54;                  // 0x54
    s32 m58;                  // 0x58
    s32 m5C;                  // 0x5C
    s32 m60;                  // 0x60
};
struct CMapPair {
    s32 a;                    // 0x0
    s32 b;                    // 0x4
};
struct CMapAttrSet {
    s32 m_flags;              // 0x0
    s32 m_num;                // 0x4
    CMapPair *m_pairs;        // 0x8
};
extern "C" char *strstr(const char *a, const char *b);
extern "C" void *func_0024A3D8(s32 n);
extern "C" s32 func_002301B0(const char *name, char *buf, s32 n);
extern "C" void *func_00245DD0(s32 n);
extern "C" const char *func_0024A710(const char *p, s32 *v, s32 def, const char *s1, const char *s2);
const char *Func24A570(const char *s, char *out, const char *sep, const char *ws);
const char *Func24AF10(void *p, const char *key);
const char *Func24AFE8(const char *s, char *buf, s32 k, s32 size);
extern void (*D_002B91B0)(void *p);
void Func235DE0(const char *fmt, ...);
extern char D_002D3C30[], D_002D3C80[], D_002D3C90[], D_002D3CB8[];
extern const char *D_002A0620, *D_002A0628, *D_002A062C, *D_002A0630;
s32 ParseMapAttr(CMapAttrSet *s, CMapPair *out, const char *p);
s32 LoadMapAttrSets(CMapAttrSet *sets, void *text);
s32 LoadMapItems(CMapItem *items, void *text);
extern "C" int func_00119230(CMapAttr *a, void *text);
extern "C" int func_0011C428(CMapEffRes *e, void *text);
// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMapRes.
class CMapRes {
public:
    CMapRes();
    virtual ~CMapRes();
    void Func11AC70();
    int Save11A1E8(const char *path);
    s32 Func119F48(char *buf);
    int Load11A8F8(void *text);
    void Sort119E08();
    int LoadFile(const char *path);

    s32 m_unk0;               // 0x00
    CMapItem *m_unk4;         // 0x04
    CMapItem *m_unk8;         // 0x08
    CMapItem *m_unkC;         // 0x0C
    s32 m_unk10;              // 0x10
    CMapAttrSet *m_unk14;     // 0x14
    CMapAttr *m_attr;         // 0x18
    CMapEffRes *m_eff;        // 0x1C
    CMapSndRes *m_snd;        // 0x20
    s32 m_unk24[2];           // 0x24
    // vptr 0x2C
};
void Func11CA30(void *p);
extern "C" void func_0022DCE0();
extern "C" void func_0022DD00();
extern "C" void func_0022DC90(const char *dir);
extern "C" int func_0022FF58(const char *name);
int Func249248(void *f);
void Func249348();
extern "C" void func_0024B650(const char *p, s32 a, char *buf, s32 b);
extern "C" void func_0024B7B8(const char *p, char *dir, char *name);
extern "C" unsigned int strlen(const char *s);
char *Func24A4C0(const char *name);
extern "C" void func_00247110();
extern "C" s32 func_00247140();
extern "C" void func_00127E98(CMapSndRes *s, const char *name);
extern const char *D_002A0634, *D_002A0638, *D_002A063C, *D_002A0644;
extern char D_002D3D10[];

// Text writer: func_0024B818 is its printf (returns the length; writes only when m_p is set).
struct CTextOut {
    char *m_p;
    s32 m4;
    s32 m8;
    s32 mC;
};
extern "C" s32 func_0024B818(CTextOut *w, const char *fmt, ...);
extern "C" s32 func_00118448(CMapAttr *a, char *p);
extern "C" s32 func_0011BD90(CMapEffRes *e, char *p);
extern const char *D_002A0624;
extern char D_002D3C70[], D_002D3C78[], D_002D3C88[];

extern const char *D_002A0624;
extern char D_002D3D10[], D_002D3D30[];
void *Func248E48(const char *name);
void Func24B600(char *dst, const char *src, s32 n);
extern "C" int strcmp(const char *a, const char *b);
extern "C" void func_00253048(void *tex, void **a, s32 *b, s32 *c, s32 *d, s32 *e, s32 *f, s32 *g, s32 *h);
extern "C" void func_0023C048(s32 a, s32 b, s32 c);
extern "C" void *func_00248E60(const char *name);
struct CIpuHeader {
    u8 pad0[0x8];
    u16 m_width;              // 0x8
    u16 m_height;             // 0xA
};
extern "C" void *func_001EF728(void *data, s32 size);
extern "C" s32 func_001EF890(void *ipu, s32 mode);
extern "C" void func_001EFC20(void *ipu, void *buf, s32 mode, s32 a, s32 b);
extern "C" CIpuHeader *func_001EF878(void *ipu);
extern "C" void func_001EF810(void *ipu);
void *Func245D00(int size);
// @decl-end

CMapRes::CMapRes() {
    CMapAttr *attr;
    CMapEffRes *eff;
    m_unk0 = 0;
    m_unk4 = 0;
    m_unk8 = 0;
    m_unkC = 0;
    m_unk10 = 0;
    m_unk14 = 0;
    attr = (CMapAttr *)operator new(0x160);
    func_00118210(attr);
    m_attr = attr;
    eff = (CMapEffRes *)operator new(0x1C);
    func_0011BD00(eff);
    m_eff = eff;
    m_snd = new CMapSndRes;
    memset(m_unk24, 0, 8);
}

CMapRes::~CMapRes() {
    Func11AC70();
    delete m_snd;
    delete m_eff;
    delete m_attr;
}

INCLUDE_ASM("asm/nonmatchings/CMapRes", Sort119E08__7CMapRes);

INCLUDE_RODATA("asm/nonmatchings/CMapRes", D_002D3C28);
INCLUDE_RODATA("asm/nonmatchings/CMapRes", D_002D3C30);
INCLUDE_RODATA("asm/nonmatchings/CMapRes", D_002D3C38);
INCLUDE_RODATA("asm/nonmatchings/CMapRes", D_002D3C40);
INCLUDE_RODATA("asm/nonmatchings/CMapRes", D_002D3C48);
s32 CMapRes::Func119F48(char *buf) {
    CTextOut w;
    s32 i, j, n, r;
    w.m_p = buf;
    n = func_0024B818(&w, "[%s]\n", D_002A0620);
    for (i = 0; i < m_unk0; i++) {
        CMapItem *it = &m_unk4[i];
        n += func_0024B818(&w, "\t%s %d %d %d\n", it->m_name, it->m38, it->m3C, it->m40);
    }
    for (i = 0; i < m_unk10; i++) {
        n += func_0024B818(&w, "\t%s ", D_002A0624);
        if (m_unk14[i].m_flags & 1) n += func_0024B818(&w, D_002D3C70, D_002A0628);
        if (m_unk14[i].m_flags & 2) n += func_0024B818(&w, D_002D3C70, D_002A062C);
        if (m_unk14[i].m_flags & 4) n += func_0024B818(&w, D_002D3C70, D_002A0630);
        for (j = 0; j < m_unk14[i].m_num; j++) {
            n += func_0024B818(&w, D_002D3C78, m_unk14[i].m_pairs[j].a, m_unk14[i].m_pairs[j].b);
            if (j < m_unk14[i].m_num - 1) n += func_0024B818(&w, D_002D3C80);
            else n += func_0024B818(&w, D_002D3C88);
        }
    }
    n += func_0024B818(&w, D_002D3C88);
    r = func_00118448(m_attr, w.m_p);
    if (r < 0) return -1;
    if (w.m_p) w.m_p += r;
    n += r;
    r = func_0011BD90(m_eff, w.m_p);
    if (r < 0) return -1;
    if (w.m_p) w.m_p += r;
    return n + r;
}
INCLUDE_RODATA("asm/nonmatchings/CMapRes", D_002D3C70);
INCLUDE_RODATA("asm/nonmatchings/CMapRes", D_002D3C78);
INCLUDE_RODATA("asm/nonmatchings/CMapRes", D_002D3C80);
INCLUDE_RODATA("asm/nonmatchings/CMapRes", D_002D3C88);
INCLUDE_RODATA("asm/nonmatchings/CMapRes", D_002D3C90);

int CMapRes::Save11A1E8(const char *path) {
    int ok = 0;
    char *buf = 0;
    if (strstr(path, D_002D3C90)) return 0;
    s32 n = Func119F48(0);
    if (n <= 0 || !(buf = (char *)func_0024A3D8(n)) || Func119F48(buf) <= 0 || func_002301B0(path, buf, n) != n) {
        Func235DE0("*** failed to write map '%s'\n", path);
    } else {
        ok = 1;
    }
    if (buf) D_002B91B0(buf);
    return ok;
}
INCLUDE_RODATA("asm/nonmatchings/CMapRes", D_002D3CB8);

s32 LoadMapItems(CMapItem *items, void *text) {
    char line[0x100];
    char tok[0x100];
    const char *p;
    s32 n;
    CMapItem *it;
    if (text) {
        const char *s;
        n = 0;
        it = items;
        s = Func24AF10(text, D_002A0620);
        if (*s) {
            p = s;
            goto start;
        }
    }
    return 0;
start:
    while ((p = Func24AFE8(p, line, 1, 0x100), *p) || line[0]) {
        const char *q = Func24A570(line, tok, D_002D3C80, D_002D3CB8);
        if (!strcmp(tok, D_002A0624)) continue;
        if (items) {
            it->m28 = n;
            it->m30 = -1;
            Func24B600(it->m_name, tok, 0x20);
            q = func_0024A710(q, &it->m38, 0, D_002D3C80, D_002D3CB8);
            q = func_0024A710(q, &it->m3C, 0, D_002D3C80, D_002D3CB8);
            func_0024A710(q, &it->m40, 0, D_002D3C80, D_002D3CB8);
            if (strstr(tok, ".tm2")) {
                it->m34 = Func248E48(tok);
                if (!it->m34) {
                    Func235DE0("*** failed to load %s\n", tok);
                } else {
                    func_00253048(it->m34, &it->m44, &it->m48, &it->m4C, &it->m50, &it->m54, &it->m58, &it->m5C, &it->m60);
                    if (it->m4C & 7) Func235DE0("!!! invalid width (fname=%s, width=%d)\n", tok, it->m4C);
                    if (it->m5C > 16) func_0023C048(it->m5C, it->m54, it->m54);
                    it->m2C = 0;
                }
            } else if (strstr(tok, ".ipu")) {
                void *f = 0;
                void *ipu = 0;
                void *buf = 0;
                s32 size = func_0022FF58(tok);
                if (size <= 0 || (f = func_00248E60(tok)) == 0 || (ipu = func_001EF728(f, size)) == 0 ||
                    (buf = Func245D00(func_001EF890(ipu, 2))) == 0) {
                    Func235DE0(D_002D3D10, tok);
                } else {
                    func_001EFC20(ipu, buf, 2, 0, 0);
                    CIpuHeader *h = func_001EF878(ipu);
                    it->m34 = buf;
                    it->m44 = buf;
                    it->m48 = 2;
                    it->m4C = h->m_width;
                    it->m50 = h->m_height;
                    it->m2C = 1;
                    it->m54 = 0;
                    it->m58 = 0;
                    it->m5C = 0;
                    it->m60 = 0;
                    buf = 0;
                }
                if (buf) D_002B91B0(buf);
                if (ipu) func_001EF810(ipu);
                if (f) D_002B91B0(f);
            } else {
                Func235DE0(D_002D3D30, tok);
            }
        }
        it++;
        n++;
    }
    return n;
}
INCLUDE_RODATA("asm/nonmatchings/CMapRes", D_002D3D10);
INCLUDE_RODATA("asm/nonmatchings/CMapRes", D_002D3D30);

s32 ParseMapAttr(CMapAttrSet *s, CMapPair *out, const char *p) {
    char tok[0x100];
    s32 n = 0;
    while ((p = Func24A570(p, tok, D_002D3C80, D_002D3CB8), *p) || tok[0]) {
        if (tok[0] == '/') {
            if (!strcmp(tok, D_002A0630)) {
                s->m_flags |= 4;
            } else if (!strcmp(tok, D_002A0628)) {
                s->m_flags |= 1;
            } else if (!strcmp(tok, D_002A062C)) {
                s->m_flags |= 2;
            }
        } else {
            if (out) {
                const char *q = func_0024A710(tok, &out[n].a, 1, ",", "<> \t");
                func_0024A710(q, &out[n].b, 0, ",", "<> \t");
            }
            n++;
        }
    }
    return n;
}
INCLUDE_RODATA("asm/nonmatchings/CMapRes", D_002D3D58);
INCLUDE_RODATA("asm/nonmatchings/CMapRes", D_002D3D60);
INCLUDE_RODATA("asm/nonmatchings/CMapRes", D_002D3D68);
INCLUDE_RODATA("asm/nonmatchings/CMapRes", D_002D3D70);

INCLUDE_ASM("asm/nonmatchings/CMapRes", LoadMapAttrSets__FP11CMapAttrSetPv);

int CMapRes::Load11A8F8(void *text) {
    m_unk0 = LoadMapItems(0, text);
    m_unk4 = (CMapItem *)func_00245DD0(m_unk0 * sizeof(CMapItem));
    LoadMapItems(m_unk4, text);
    m_unk10 = LoadMapAttrSets(0, text);
    m_unk14 = (CMapAttrSet *)func_00245DD0(m_unk10 * sizeof(CMapAttrSet));
    LoadMapAttrSets(m_unk14, text);
    for (s32 i = 0; i < m_unk10; i++) {
        for (s32 j = 0; j < m_unk14[i].m_num; j++) {
            s32 k = m_unk14[i].m_pairs[j].b;
            if (k >= 0 && k <= m_unk0 - 1) m_unk4[k].m30 = i;
        }
    }
    Sort119E08();
    if (!func_00119230(m_attr, text)) return 0;
    return func_0011C428(m_eff, text) != 0;
}

int CMapRes::LoadFile(const char *path) {
    char buf[0x100];
    char name[0x100];
    char *text = 0;
    int ok = 0;
    func_0022DCE0();
    if (strstr(path, D_002A0634) || strstr(path, D_002A0638)) {
        if (!Func249248((void *)path)) goto fail;
        func_0024B650(path, 0, buf, 0);
        const char *ext = D_002A063C;
        strcpy(buf + strlen(buf), ext);
        ok = LoadFile(buf);
        Func249348();
    } else if (strstr(path, D_002A063C)) {
        Func11AC70();
        func_0024B7B8(path, buf, name);
        func_0022DC90(buf);
        text = Func24A4C0(name);
        if (!text) {
        fail:
            Func235DE0(D_002D3D10, path);
        } else {
            func_00247110();
            ok = Load11A8F8(text);
            if (ok) {
                m_unk24[0] = func_00247140();
                D_002B91B0(text);
                text = 0;
                func_0024B650(path, 0, name, 0);
                const char *e2 = D_002A0644;
                strcpy(name + strlen(name), e2);
                if (func_0022FF58(name) > 0) {
                    func_00247110();
                    func_00127E98(m_snd, name);
                    m_unk24[1] = func_00247140();
                }
            }
        }
    }
    if (text) D_002B91B0(text);
    func_0022DD00();
    return ok;
}

void CMapRes::Func11AC70() {
    s32 i;
    m_snd->CallFunc127928();
    Func11CA30(m_eff);
    m_attr->CallFunc1182B8();
    if (m_unk4) {
        for (i = 0; i < m_unk0; i++) {
            if (m_unk4[i].m34) D_002B91B0(m_unk4[i].m34);
        }
        D_002B91B0(m_unk4);
        m_unk4 = 0;
        m_unk0 = 0;
    }
    m_unkC = 0;
    m_unk8 = 0;
    if (m_unk14) {
        for (i = 0; i < m_unk10; i++) {
            if (m_unk14[i].m_pairs) D_002B91B0(m_unk14[i].m_pairs);
        }
        D_002B91B0(m_unk14);
        m_unk14 = 0;
        m_unk10 = 0;
    }
    memset(m_unk24, 0, 8);
}
