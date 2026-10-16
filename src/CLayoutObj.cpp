#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
struct CLayoutEntry {
    const char *m_name;       // 0x0
    u8 pad4[0x9C];
};
class CLayoutObjPart {
public:


    u8 pad0[0x4];
    CLayoutEntry *m_entries;  // 0x4
    s32 m_unk8;               // 0x8
};
class CLayoutObjSub1B9E60 {
public:
    s32 GetPartUnk8();

    u8 pad0[0x4];
    CLayoutObjPart* m_part;   // 0x4
};
class CLayoutObjSub1BA0A0 {
public:
    void Reset();

    u8 pad0[0x50];
    s32 m_unk50;              // 0x50
    s32 m_unk54;              // 0x54
    f32 m_unk58;              // 0x58
    f32 m_unk5C;              // 0x5C
    s32 m_unk60;              // 0x60
};
class CLayoutRes {
public:
    CLayoutObjPart *Func1B9B80(int v);
    u8 pad0[0xC];
    void *m_text;             // 0xC
};
class CLayoutHourglass;
// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CLayoutObj, its
// only virtual. The vptr follows its fields at 0x164.
class CLayoutObj {
public:
    CLayoutObj();
    virtual ~CLayoutObj();
    void Func1B9E28();
    void CallFunc1B9E28();
    void SetUnk30(f32 x, f32 y);
    void SetUnk1DC(s32 v);
    void CopyUnk1DC();
    void ResetUnk1E0();
    int Func1BA0C0();
    void Func1B9FF0();
    void Func1BA0F0();
    int Func1BA1A0();
    void Func1B9F60();
    int Set(CLayoutRes *res, int v);
    void Func1B9D40();
    void Init1BD188();
    void Func1BA210(CLayoutEntry *e, int a, f32 x, f32 y, f32 z, f32 w);
    void Draw1BA1D0(CLayoutEntry *e, int a, f32 x, f32 y, f32 z, f32 w, f32 sx, f32 sy);
    void Func1BA440(int a, f32 x, f32 y, f32 z, f32 w);
    int Func1BA520(CLayoutEntry *e, int a, f32 x, f32 y, f32 z, f32 w, f32 sx, f32 sy);
    int Draw1BA5D0(int a, f32 x, f32 y, f32 z, f32 w);
    void Printf(const char *fmt, ...);
    CLayoutEntry *FindEntry(const char *name);
    CLayoutEntry *GetEntry(int i);
    void Text1BC6A8(class CLayoutObjSub1BC320 *st, const char *s, s32 flags, f32 x, f32 y);
    const char *Text1BC900(class CLayoutObjSub1BC320 *st, const char *s, s32 flags, f32 x, f32 y);
    // The 0x1BD188 object (CLayoutHourglass) starts with a CLayoutObj; some of its methods are
    // still declared here.
    CLayoutHourglass *Hg() { return (CLayoutHourglass *)this; }

    s32 m_unk0;               // 0x0
    CLayoutObjPart *m_part;   // 0x4
    s32 m_unk8;               // 0x8
    u8 padC[0x14];
    f32 m_unk20;              // 0x20
    f32 m_unk24;              // 0x24
    f32 m_unk28;              // 0x28
    f32 m_unk2C;              // 0x2C
    f32 m_unk30;              // 0x30
    f32 m_unk34;              // 0x34
    u8 pad38[0x8];
    f32 m_unk40;              // 0x40
    f32 m_unk44;              // 0x44
    s32 m_unk48;              // 0x48
    s32 m_unk4C;              // 0x4C
    f32 m_unk50;              // 0x50
    f32 m_unk54;              // 0x54
    u8 pad58[0xC];
    char m_text[0x100];       // 0x64
    // vptr 0x164; 16-byte aligned (size 0x170)
} __attribute__((aligned(16)));
// Sound object (library, 0x25C230 constructor, 0x25C2C0 destructor), 0x6C bytes.
class CSndWork {
public:
    void Func25C648(s32 a, s32 b);
    u8 pad0[0x6C];
};
extern "C" void func_0025C230(void *p);
class CLayoutHourglass {
public:
    CLayoutHourglass();
    int Load(CLayoutRes *res, const char *name);
    void Update();
    int Draw1BD420();

    CLayoutObj m_obj;         // 0x000
    CSndWork m_snd;           // 0x170
    s32 m_unk1DC;             // 0x1DC
    s32 m_unk1E0;             // 0x1E0
    s32 m_unk1E4;             // 0x1E4
    s32 m_unk1E8;             // 0x1E8
    s32 m_unk1EC;             // 0x1EC
    s32 m_unk1F0;             // 0x1F0
    s32 m_unk1F4;             // 0x1F4
    s32 m_unk1F8;             // 0x1F8
    s32 m_unk1FC;             // 0x1FC
    s32 m_unk200;             // 0x200
};

void Func225088();
int Func2250C0();
void Func225240(s32 v);

typedef __builtin_va_list va_list;
#define va_start(ap, last) __builtin_stdarg_start(ap, last)
#define va_end(ap) __builtin_va_end(ap)
//@sym strcmp 0x28B190
#include "libc.h"
//@sym vsprintf 0x28F338
extern "C" int vsprintf(char *buf, const char *fmt, va_list ap);
class CUnk237E90 {
public:
    void Func237E90(int v);
};
struct CLayoutDrawObj { u8 pad0[0x10]; CUnk237E90 m10; };
struct CLayoutImage { u8 pad0[0x18]; s32 m18; u8 pad1C[4]; s32 m20; s32 m24; };
struct CLayoutImageRef { u8 pad0[0xC]; CLayoutImage *m_image; };
void Func227DC8(s64 a, int size, int b);
class CLayoutDraw {
public:
    void Upload(CLayoutImageRef *r);
    u8 pad0[8];
    CLayoutDrawObj *m8;       // 0x8
    u8 padC[0xC];
    s64 m18;                  // 0x18
};
class CLayoutObjSub1BC320 {
public:
    void Init();
    s32 m0; f32 m4, m8; s32 mC; f32 m10; u8 pad14[0xC]; f32 m20, m24, m28, m2C, m30, m34; s32 m38, m3C;
} __attribute__((aligned(8)));
int LayoutFlagX(int v);
int LayoutFlagY(int v);
const char *ParseUInt(const char *s, int *out);
const char *ParseSjis(const char *s, s16 *out);
void Func2251E8();
extern "C" void func_00227A20();
extern "C" void func_00227AA8();
extern "C" void func_00226DF8(s32 reg, u64 v);
extern "C" s32 func_0023A0E8();
extern "C" s32 func_0023A2F0(s32 a);
extern "C" u64 func_0023C650(s32 a);
extern "C" u64 func_0023C658(s32 a);
void *Func237570(s32 size);
void Func237A88(void *p, s32 n);
void *Func237C30(void *p);
void Func238158(void *p, s32 v);
class CDisp2BA128 {
public:
    virtual void Vf0();
    virtual void Vf1();
    virtual void Vf2();
    virtual void Vf3();
    virtual u64 GetFrame();
    virtual u64 GetZBuf();
};
extern CDisp2BA128 *D_002BA128;
extern "C" CLayoutEntry *func_001B9E78(CLayoutObj *o, s32 i);
const char *Func24AF10(void *p, const char *key);
extern "C" const char *func_0024AD10(const char *p, char *buf, s32 k, s32 n);
extern "C" long atol(const char *s);
extern char D_002E0D50[];

//@sym Text1BC900__10CLayoutObjP19CLayoutObjSub1BC320PCciff 0x1BC900

struct CLayoutGlyph {
    s16 m0;
    u8 pad2[0x1FE];
};
extern "C" const char *func_001BC870(const char *s, CLayoutGlyph *g);
extern "C" void func_001BCAF8(CLayoutObj *o, CLayoutObjSub1BC320 *st, CLayoutGlyph *g, s32 flags, f32 x, f32 y);
extern "C" int func_001BCFB0(CLayoutObj *o, CLayoutObjSub1BC320 *st, const char **pp, f32 *w);
// Float view of the s32 fields of CLayoutObjSub1BC320.
#define LF(v) (*(f32 *)&(v))

extern char D_002E0D60[];
// Reset() is defined earlier in this file; called through this alias (config/aliases.ld) the
// delay slots of Draw1BD420 come out like retail's (GCC fills differently around calls to
// functions it has already compiled).
extern "C" void func_001BA0A0(CLayoutObjSub1BA0A0 *p);

struct CLayoutGroup {
    s32 m0;                   // 0x0
    CLayoutEntry *m_items;    // 0x4
    s32 m_num;                // 0x8
};
struct CLayoutEntryHdr {
    const char *m_name;       // 0x0
    u32 m_flags;              // 0x4
    u8 pad8[0x8];
    CLayoutGroup *m_group;    // 0x10
};
extern "C" void func_001BA7E8(CLayoutObj *o, CLayoutEntry *e, int a, f32 x, f32 y, f32 z, f32 w);
extern "C" void func_001BADB0(CLayoutObj *o, CLayoutEntry *e, int a, f32 x, f32 y, f32 z, f32 w);
extern "C" void func_001BB438(CLayoutObj *o, CLayoutEntry *e, int a, f32 x, f32 y, f32 z, f32 w);
extern "C" void func_001BBDE8(CLayoutObj *o, CLayoutEntry *e, int a, f32 x, f32 y, f32 z, f32 w);
extern "C" void func_001BC360(CLayoutObj *o, CLayoutEntry *e, int a, f32 x, f32 y, f32 z, f32 w);
extern "C" void func_001BBD08(CLayoutObj *o, CLayoutEntry *e, int a);

struct CLayoutTbl { u32 m0; CLayoutEntry *m_entries; s32 m_count; };
// @decl-end

CLayoutObj::CLayoutObj() {
    m_unk0 = 0;
    m_part = 0;
    Func1B9F60();
    return;
}

CLayoutObj::~CLayoutObj() {
    Func1B9E28();
}

int CLayoutObj::Set(CLayoutRes *res, int v) {
    Func1B9E28();
    m_unk0 = (s32)res;
    m_part = res->Func1B9B80(v);
    return 1;
}

void CLayoutObj::Func1B9E28() {
    if (m_unk0) {
        m_part = 0;
        Func1B9F60();
        m_unk0 = 0;
    }
}

s32 CLayoutObjSub1B9E60::GetPartUnk8() {
    return m_part ? m_part->m_unk8 : 0;
}

extern "C" CLayoutEntry *func_001B9E78(CLayoutObj *o, s32 i) { CLayoutTbl *t = *(CLayoutTbl **)((u8 *)o + 4); if (!t || i < 0 || t->m_count - 1 < i) return 0; return &t->m_entries[i]; }

CLayoutEntry *CLayoutObj::FindEntry(const char *name) {
    int i;
    if (!m_part) return 0;
    for (i = 0; i < m_part->m_unk8; i++) {
        if (!strcmp(m_part->m_entries[i].m_name, name)) return &m_part->m_entries[i];
    }
    return 0;
}

void CLayoutObj::Func1B9F60() {
    m_text[0] = 0;
    m_unk20 = 1.0f;
    m_unk24 = 1.0f;
    m_unk28 = 1.0f;
    m_unk2C = 1.0f;
    m_unk40 = 1.0f;
    m_unk48 = 0;
    m_unk4C = 0;
    m_unk44 = 1.0f;
}

void CLayoutObj::Printf(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    vsprintf(m_text, fmt, ap);
    va_end(ap);
}

void CLayoutObj::Func1B9FF0() {
    CLayoutDraw *d = (CLayoutDraw *)this;
    d->m8 = (CLayoutDrawObj *)Func237570(0x30);
    Func237A88(d->m8, 3);
    Func238158(Func237C30((u8 *)d->m8 + 0x20), 1);
    *(u64 *)((u8 *)this + 0x10) = D_002BA128->GetFrame();
    d->m18 = D_002BA128->GetZBuf();
    m_text[0] = 0;
    ((CLayoutObjSub1BA0A0 *)this)->Reset();
}

void CLayoutObjSub1BA0A0::Reset() {
    m_unk50 = 0;
    m_unk54 = 0;
    m_unk5C = 1.0f;
    m_unk58 = 1.0f;
    m_unk60 = 0;
}

int CLayoutObj::Func1BA0C0() {
    Func225088();
    Func225240(m_unk8);
    return Func2250C0();
}

void CLayoutObj::Func1BA0F0() {
    Func225088();
    func_00227A20();
    func_00226DF8(0x42, 0x44);
    func_00226DF8(8, 0xA);
    func_00226DF8(0x4A, 0);
    func_00226DF8(0x49, 0);
    func_00226DF8(0x14, 0x60);
    func_00226DF8(0x3B, 0x80);
    func_00226DF8(0x47, 0x39001);
    func_00227AA8();
    Func2251E8();
    ((CLayoutDraw *)this)->m8->m10.Func237E90(Func2250C0());
}

int CLayoutObj::Func1BA1A0() {
    Func1B9FF0();
    Func1BA0F0();
    return Func1BA0C0();
}

void CLayoutObj::Draw1BA1D0(CLayoutEntry *e, int a, f32 x, f32 y, f32 z, f32 w, f32 sx, f32 sy) {
    Func1BA210(e, a, x, y, z + m_unk30 + m_unk50, w + m_unk34 + m_unk54);
}

void CLayoutObj::Func1BA210(CLayoutEntry *e, int a, f32 x, f32 y, f32 z, f32 w) {
    if (!e) return;
    if (y == 0.0f) return;
    if (((CLayoutObjSub1BA0A0 *)this)->m_unk5C == 0.0f) return;
    switch (((CLayoutEntryHdr *)e)->m_flags & 0xF) {
    case 2:
        func_001BA7E8(this, e, a, x, y, z, w);
        break;
    case 1:
        func_001BADB0(this, e, a, x, y, z, w);
        break;
    case 3:
        func_001BB438(this, e, a, x, y, z, w);
        break;
    case 4:
        func_001BBD08(this, e, a);
        break;
    case 5:
        func_001BBDE8(this, e, a, x, y, z, w);
        break;
    case 6:
        func_001BC360(this, e, a, x, y, z, w);
        break;
    case 7: {
        CLayoutGroup *g = ((CLayoutEntryHdr *)e)->m_group;
        if (!g) break;
        for (s32 i = 0; i < g->m_num; i++) {
            CLayoutEntry *it = &g->m_items[i];
            func_001BA0A0((CLayoutObjSub1BA0A0 *)this);
            Draw1BA1D0(it, a, x, y, z, w, 1.0f, 1.0f);
        }
        break;
    }
    }
}

void CLayoutObj::Func1BA440(int a, f32 x, f32 y, f32 z, f32 w) {
    s32 n = ((CLayoutObjSub1B9E60 *)this)->GetPartUnk8();
    for (s32 i = 0; i < n; i++) {
        ((CLayoutObjSub1BA0A0 *)this)->Reset();
        Draw1BA1D0(func_001B9E78(this, i), a, y, x, z, w, 1.0f, 1.0f);
    }
}

int CLayoutObj::Func1BA520(CLayoutEntry *e, int a, f32 x, f32 y, f32 z, f32 w, f32 sx, f32 sy) {
    Func1B9FF0();
    Draw1BA1D0(e, a, x, y, z, w, sx, sy);
    return Func1BA0C0();
}

int CLayoutObj::Draw1BA5D0(int a, f32 x, f32 y, f32 z, f32 w) {
    Func1B9FF0();
    Func1BA440(a, x, y, z, w);
    return Func1BA0C0();
}

void SetFrameZMask(u32 flags) {
    if (flags & 0x40000000) {
        u64 fr = func_0023C650(func_0023A2F0(func_0023A0E8()));
        u64 zb = func_0023C658(func_0023A2F0(func_0023A0E8()));
        func_00226DF8(0x4E, ((zb & 0x3FFF) >> 5) | (((zb >> 32) & 0x3F) << 24) | ((u64)0x8000 << 17));
        func_00226DF8(0x4C, ((fr & 0x3FFF) >> 5) | (((fr >> 14) & 0x3F) << 16) | (((fr >> 32) & 0x3F) << 24) | ((u64)0xFFFFFF << 32));
    }
}

void SetFrameZ(u32 flags) {
    if (flags & 0x40000000) {
        u64 fr = func_0023C650(func_0023A2F0(func_0023A0E8()));
        u64 zb = func_0023C658(func_0023A2F0(func_0023A0E8()));
        func_00226DF8(0x4E, ((zb & 0x3FFF) >> 5) | (((zb >> 32) & 0x3F) << 24));
        func_00226DF8(0x4C, ((fr & 0x3FFF) >> 5) | (((fr >> 14) & 0x3F) << 16) | (((fr >> 32) & 0x3F) << 24));
    }
}

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001BA7E8);

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001BADB0);

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001BB438);

void CLayoutDraw::Upload(CLayoutImageRef *r) {
    CLayoutImage *img = r->m_image;
    if (img) {
        Func225088();
        Func227DC8(m18, img->m20 * img->m24, img->m18);
        m8->m10.Func237E90(Func2250C0());
    }
}

int LayoutFlagX(int v) {
    switch (v & 0xF0) {
    case 0x00:
    default:
        return 0;
    case 0x10:
        return 1;
    case 0x20:
        return 2;
    }
}

int LayoutFlagY(int v) {
    switch (v & 0xF00) {
    case 0x000:
    default:
        return 0;
    case 0x100:
        return 1;
    case 0x200:
        return 2;
    }
}

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001BBDE8);

void CLayoutObjSub1BC320::Init() {
    m0 = 0;
    m4 = 1.0f;
    m8 = 1.0f;
    mC = 0;
    m10 = 0;
    m20 = 1.0f;
    m24 = 1.0f;
    m28 = 1.0f;
    m2C = 1.0f;
    m30 = 1.0f;
    m34 = 1.0f;
    m38 = 0;
    m3C = 0;
}

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001BC360);

void CLayoutObj::Text1BC6A8(CLayoutObjSub1BC320 *st, const char *s, s32 flags, f32 x, f32 y) {
    f32 h = 0.0f;
    while (*s) {
        CLayoutObjSub1BC320 tmp;
        tmp.Init();
        tmp = *st;
        tmp.m38 = 0;
        tmp.m3C = 0;
        const char *next = Text1BC900(&tmp, s, flags | 0x8000000, 0.0f, 0.0f);
        if (!(flags & 0x8000000)) {
            f32 dx;
            switch (flags & 0xF0) {
            case 0x00:
            default:
                dx = 0.0f;
                break;
            case 0x10:
                dx = LF(st->m38) * 0.5f - LF(tmp.m38) * 0.5f;
                break;
            case 0x20:
                dx = LF(st->m38) - LF(tmp.m38);
                break;
            }
            Text1BC900(st, s, flags, x + dx, y + h);
        }
        s = next;
        LF(st->m38) = LF(tmp.m38) < LF(st->m38) ? LF(st->m38) : LF(tmp.m38);
        h += LF(tmp.m3C);
        if (*s) h += st->m10;
    }
    LF(st->m3C) = h;
}

extern "C" const char *func_001BC870(const char *s, CLayoutGlyph *g) { s16 *d = (s16 *)g; while (*s && *s != '@' && *s != '\n') { if (*s >= 0) *d++ = *s++; else { *d++ = *s++; *d++ = *s++; } } *d = 0; return s; }

const char *CLayoutObj::Text1BC900(CLayoutObjSub1BC320 *st, const char *s, s32 flags, f32 x, f32 y) {
    const char *p;
    f32 w;
    w = 0.0f;
    p = s;
    while (*p) {
        CLayoutObjSub1BC320 tmp;
        CLayoutGlyph g;
        tmp.Init();
        p = func_001BC870(p, &g);
        if (g.m0) {
            tmp = *st;
            tmp.m38 = 0;
            tmp.m3C = 0;
            func_001BCAF8(this, &tmp, &g, flags | 0x8000000, 0.0f, 0.0f);
            if (!(flags & 0x8000000)) func_001BCAF8(this, st, &g, flags, x + w, y);
            LF(st->m3C) = LF(tmp.m3C) < LF(st->m3C) ? LF(st->m3C) : LF(tmp.m3C);
            w += LF(tmp.m38);
        }
        if (*p == '@') {
            if (func_001BCFB0(this, st, &p, &w)) break;
        } else if (*p == '\n') {
            p++;
            break;
        }
        if (g.m0) LF(st->m38) += LF(st->mC);
    }
    LF(st->m38) = w;
    return p;
}

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001BCAF8);

const char *ParseUInt(const char *s, int *out) {
    *out = 0;
    while (*s >= '0' && *s <= '9') {
        *out = *out * 10 + (*s++ - '0');
    }
    return s;
}

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001BCFB0);

