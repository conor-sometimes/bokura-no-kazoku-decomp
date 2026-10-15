#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CPushBuf {
public:
    CPushBuf();
    ~CPushBuf();
    void Func248E00();
    int Func248EB0();
    void *Func248CC8(s32 size, s32 a, s32 b);
    void Func248EE0(void *p);

    u8 m_data[0xC];
};

// A link from a layout element to another element of its entry (by name).
struct CLayoutLink {
    CLayoutLink *m_next;      // 0x0
    u8 pad4[0x8];
    const char *m_name;       // 0xC
    struct CLayoutElem *m_target; // 0x10
};
// Layout element (0xA0 bytes).
struct CLayoutElem {
    const char *m_name;       // 0x0
    u32 m_flags;              // 0x4
    const char *m_ref;        // 0x8
    void *m_part;             // 0xC
    class CLayoutEntry *m_entry; // 0x10
    CLayoutLink *m_links;     // 0x14
    u8 pad18[0x88];
};
class CLayoutEntry {
public:
    const char *m_name;       // 0x0
    CLayoutElem *m_elems;     // 0x4
    s32 m_numElems;           // 0x8
};

class CLayoutPart {
public:
    u8 pad0[0x28];
};

class CLayoutResSub1B8748 : public CPushBuf {
public:
    s32 Parse1B8890(s32 data);
    s32 LoadClut(class CLayoutTex *t, CPushBuf *b);
    s32 LoadTex(class CLayoutTex *t, CPushBuf *b);
    s32 Load(const char *dir);
    void Clear();
    s32 Init();
    s32 Func1B96F0(void *p);
    void *CopyFrom(CPushBuf *b);
    void Release();
    CLayoutEntry *Find(const char *name);
    CLayoutPart *GetPart(s32 i);
    s32 ReadInts(const char *key, s32 *out, s32 n);

    s32 m_unkC;               // 0xC
    CLayoutEntry *m_entries;  // 0x10
    s32 m_count;              // 0x14
    CLayoutPart *m_parts;     // 0x18
    s32 m_numParts;           // 0x1C
};
// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CLayoutRes.
// CLayoutResSub1B8748 is this class's non-virtual part: the destructor destroys the CPushBuf
// as a member (in_chrg 2), so CPushBuf is a member here, not a base.
class CLayoutRes {
public:
    CLayoutRes();
    virtual ~CLayoutRes();
    CLayoutResSub1B8748 *Sub() { return (CLayoutResSub1B8748 *)this; }

    CPushBuf m_buf;           // 0x00
    u8 padC[0x14];
    // vptr 0x20
};
extern "C" int strcmp(const char *a, const char *b);
extern void (*D_002B91B0)(void *p);
const char *Func24ADE0(const char *p, char *buf, s32 n);
void Func226DF8(s32 a, u64 b);
const char *Func24AF10(void *p, const char *key);
const char *Func24AFE8(const char *p, char *buf, s32 a, s32 n);
long Func289140(const char *s);

//@sym strcmp 0x28B190

extern "C" char *strstr(const char *s, const char *t);
extern "C" int strncmp(const char *a, const char *b, unsigned int n);

int Func249248(void *p);
void Func249348();
extern void *D_002A5988;
extern "C" s32 func_0024A4A0(void *p);
extern "C" void func_00248C30(void *p);
extern "C" void func_00248C70(void *p);

#include "libc.h"
class CLayoutTex {
public:
    s32 m_unk0;               // 0x0
    void *m_data;             // 0x4
    s32 m_unk8;               // 0x8
    s32 m_unkC;               // 0xC
    s32 m_unk10;              // 0x10
    s32 m_unk14;              // 0x14
    s32 m_unk18;              // 0x18
    s32 m_unk1C;              // 0x1C
    s32 m_unk20;              // 0x20
    s32 m_unk24;              // 0x24
};
extern "C" char *func_00248DA8(void *p);
extern "C" s32 func_00248DC0(void *p);
extern "C" int func_00253048(void *p, s32 *a, s32 *b, s32 *c, s32 *d, s32 *e, s32 *f, s32 *g, s32 *h);
extern "C" void func_0023C048(s32 a, s32 b, s32 c);
s32 Func235DE0(const char *fmt, ...);

extern char *D_002A598C;
extern "C" s32 func_0024B040(const char *p, s32 k);
extern "C" s32 func_001B8CB0(void *p, s32 data, const char *name, CLayoutEntry *e);
// @decl-end

CLayoutRes::CLayoutRes() {
    Sub()->Clear();
}

CLayoutRes::~CLayoutRes() {
    Sub()->Release();
}

void CLayoutResSub1B8748::Clear() {
    m_entries = 0;
    m_count = 0;
    m_parts = 0;
    m_numParts = 0;
    m_unkC = 0;
}

s32 CLayoutResSub1B8748::Load(const char *dir) {
    s32 ok = 0;
    s32 pushed = 0;
    s32 opened = 0;
    Release();
    if (dir && dir[0]) {
        if (!Func249248((void *)dir)) goto end;
        opened = 1;
    }
    m_unkC = func_0024A4A0(D_002A5988);
    if (m_unkC) {
        func_00248C30(this);
        pushed = 1;
        if (Parse1B8890(m_unkC)) {
            ok = Init() != 0;
        }
    }
end:
    if (pushed) func_00248C70(this);
    if (opened) Func249348();
    return ok;
}

s32 CountTokens(const char *p) {
    char buf[0x100];
    s32 n = 0;
    for (;;) {
        p = Func24ADE0(p, buf, 0x100);
        if (*p == 0 && buf[0] == 0) {
            break;
        }
        n++;
    }
    return n;
}

s32 CLayoutResSub1B8748::Parse1B8890(s32 data) {
    s32 i;
    const char *p = Func24AF10((void *)data, D_002A598C);
    if (*p) {
        m_count = func_0024B040(p, 1);
        m_entries = (CLayoutEntry *)Func248CC8(m_count * 12, 1, 1);
        for (i = 0; i < m_count; i++) {
            CLayoutEntry *e = &m_entries[i];
            p = Func24AFE8(p, func_00248DA8(this), 1, 0x100);
            e->m_name = (const char *)func_00248DC0(this);
            if (!func_001B8CB0(this, data, e->m_name, e)) return 0;
        }
    }
    for (i = 0; i < m_count; i++) {
        CLayoutEntry *e = &m_entries[i];
        for (s32 j = 0; j < e->m_numElems; j++) {
            CLayoutElem *x = &e->m_elems[j];
            if (x->m_flags & 0xF) continue;
            for (s32 k = 0; k < m_count; k++) {
                if (k == i) continue;
                if (strcmp(m_entries[k].m_name, x->m_ref) == 0) {
                    x->m_flags = (x->m_flags & ~0xF) | 7;
                    x->m_entry = &m_entries[k];
                    break;
                }
            }
        }
    }
    for (i = 0; i < m_count; i++) {
        CLayoutEntry *e = &m_entries[i];
        for (s32 j = 0; j < e->m_numElems; j++) {
            CLayoutElem *x = &e->m_elems[j];
            CLayoutLink *l;
            for (l = x->m_links; l; l = l->m_next) {
                for (s32 k = 0; k < e->m_numElems; k++) {
                    if (strcmp(e->m_elems[k].m_name, l->m_name) == 0) {
                        l->m_target = &e->m_elems[k];
                        break;
                    }
                }
            }
        }
    }
    return 1;
}

s32 FindLayoutName(const char **tbl, const char *name, s32 def) {
    s32 i;
    for (i = 0; tbl[i]; i++) {
        if (strcmp(tbl[i], name) == 0) {
            return i;
        }
    }
    return def;
}

INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002DFF50);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002DFF68);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002DFF70);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002DFF78);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002DFF98);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002DFFA0);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002DFFA8);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002DFFB0);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002DFFD8);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0008);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0030);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0060);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0090);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E00B8);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E00E8);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0120);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", jtbl_002E0140);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0270);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0298);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E02B8);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E02D0);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E02F0);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0318);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0338);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0350);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0380);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E03A8);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E03C8);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E03E8);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E03F8);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0408);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0428);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0448);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0470);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0498);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E04C0);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E04E8);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0508);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0530);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0560);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0590);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E05B8);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E05C0);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E05D0);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E05D8);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E05E0);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E05F8);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0610);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0618);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0630);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0640);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0658);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0668);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0678);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0690);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E06B0);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E06C8);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E06E0);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E06E8);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0700);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0718);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0730);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0738);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0740);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0760);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0778);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0788);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E07A8);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E07D8);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0800);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0820);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0840);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0860);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0888);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E08A0);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E08B0);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E08D0);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E08E0);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0900);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0910);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0928);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0950);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0980);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", jtbl_002E09A0);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E09C0);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0A10);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0A20);
s32 GetLayoutPartType(const char *s) {
    if (strstr(s, ".tm2")) return 3;
    if (strstr(s, ".cl2")) return 4;
    if (strcmp(s, "box") == 0) return 1;
    if (strcmp(s, "line") == 0) return 2;
    if (strncmp(s, "text:", 4) == 0) return 5;
    if (strncmp(s, "form:", 4) == 0) return 6;
    return 0;
}
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0A58);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0A60);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0A68);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0A70);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0A78);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0A80);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0A88);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0A90);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0A98);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0AA0);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0AA8);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0AB0);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0AB8);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0AC0);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0AC8);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0AD0);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0AD8);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0AE0);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0AE8);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0AF0);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0AF8);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0B00);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0B08);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0B10);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0B18);

INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0B20);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0B28);
INCLUDE_RODATA("asm/nonmatchings/CLayoutRes", D_002E0B30);
INCLUDE_ASM("asm/nonmatchings/CLayoutRes", func_001B8CB0);

s32 CLayoutResSub1B8748::Init() {
    m_numParts = Func1B96F0(0);
    m_parts = (CLayoutPart *)Func248CC8(m_numParts * sizeof(CLayoutPart), 1, 1);
    Func1B96F0(m_parts);
    return 1;
}

s32 CLayoutResSub1B8748::Func1B96F0(void *p) {
    CLayoutPart *parts = (CLayoutPart *)p;
    s32 n = 0;
    s32 i, j, k;
    for (i = 0; i < m_count; i++) {
        CLayoutEntry *e = &m_entries[i];
        for (j = 0; j < e->m_numElems; j++) {
            CLayoutElem *x = &e->m_elems[j];
            for (k = 0; k < j; k++) {
                if (strcmp(e->m_elems[k].m_ref, x->m_ref) == 0) {
                    x->m_part = e->m_elems[k].m_part;
                    break;
                }
            }
            if (k < j) continue;
            switch (x->m_flags & 0xF) {
            case 3:
                x->m_part = &parts[n];
                if (parts) LoadTex((CLayoutTex *)&parts[n], (CPushBuf *)x->m_ref);
                n++;
                break;
            case 4:
                x->m_part = &parts[n];
                if (parts) LoadClut((CLayoutTex *)&parts[n], (CPushBuf *)x->m_ref);
                n++;
                break;
            }
        }
    }
    return n;
}

void *CLayoutResSub1B8748::CopyFrom(CPushBuf *b) {
    s32 n = b->Func248EB0();
    if (n <= 0) {
        return 0;
    }
    void *p = Func248CC8(n, 0, 1);
    b->Func248EE0(p);
    return p;
}

s32 CLayoutResSub1B8748::LoadTex(CLayoutTex *t, CPushBuf *b) {
    t->m_data = CopyFrom(b);
    if (!t->m_data) return 0;
    strcpy(func_00248DA8(this), (const char *)b);
    t->m_unk0 = func_00248DC0(this);
    if (!func_00253048(t->m_data, &t->m_unk8, &t->m_unkC, &t->m_unk10, &t->m_unk14, &t->m_unk18, &t->m_unk1C, &t->m_unk20, &t->m_unk24)) {
        Func235DE0("*** invalid texture %s\n", b);
        return 0;
    }
    if (t->m_unk20 > 0x10) func_0023C048(t->m_unk20, t->m_unk18, t->m_unk18);
    return 1;
}

s32 CLayoutResSub1B8748::LoadClut(CLayoutTex *t, CPushBuf *b) {
    t->m_data = CopyFrom(b);
    if (!t->m_data) return 0;
    strcpy(func_00248DA8(this), (const char *)b);
    t->m_unk0 = func_00248DC0(this);
    if (!func_00253048(t->m_data, &t->m_unk8, &t->m_unkC, &t->m_unk10, &t->m_unk14, &t->m_unk18, &t->m_unk1C, &t->m_unk20, &t->m_unk24)) {
        Func235DE0("*** invalid CLUT %s\n", b);
        return 0;
    }
    if (t->m_unk20 > 0x10) func_0023C048(t->m_unk20, t->m_unk18, t->m_unk18);
    return 1;
}

void CLayoutResSub1B8748::Release() {
    Func248E00();
    if (m_unkC) {
        D_002B91B0((void *)m_unkC);
        m_unkC = 0;
    }
    Clear();
}

CLayoutEntry *CLayoutResSub1B8748::Find(const char *name) {
    s32 i;
    for (i = 0; i < m_count; i++) {
        if (strcmp(m_entries[i].m_name, name) == 0) {
            return &m_entries[i];
        }
    }
    return 0;
}

CLayoutPart *CLayoutResSub1B8748::GetPart(s32 i) {
    if (i < 0 || i > m_numParts - 1) {
        return 0;
    }
    return &m_parts[i];
}

s32 CLayoutResSub1B8748::ReadInts(const char *key, s32 *out, s32 n) {
    char buf[0x100];
    if (!m_unkC) {
        return 0;
    }
    const char *p = Func24AF10((void *)m_unkC, key);
    if (*p == 0) {
        return 0;
    }
    s32 i;
    for (i = 0; i < n; i++) {
        p = Func24AFE8(p, buf, 1, 0x100);
        out[i] = Func289140(buf);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/CLayoutRes", func_001B9CE8);
