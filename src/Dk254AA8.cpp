#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CPushBuf.h"
extern "C" void *memset(void *d, int c, unsigned int n);
s32 Func235DE0(const char *fmt, ...);
extern void (*D_002B91B0)(void *p);
class CVec4 { public: f32 x, y, z, w; };
void Func270C50(CVec4 *d, const CVec4 *s);
extern "C" void func_002709A8(CVec4 *out, const CVec4 *a, const CVec4 *b, f32 t);
struct CVec4x4 { s32 m0, m4, m8, mC; };
extern s32 D_002BA188;
extern s32 D_002BA184;
extern s32 D_002BA190;
extern CVec4x4 D_393950;
extern const char D_002E70D0[];
extern const char D_002E71B8[];

class IFontTextRes {
public:
    virtual void Release();                                  // [0] inline
};
class CFontTextRes : public IFontTextRes {
public:
    virtual void Release();                                  // [0] override, never defined: keeps the vtable out of this object
    CFontTextRes();
    virtual s32 Load(const char *name, s32 page);            // [1] 0x2556A8 key
    virtual void Clear(s32 page);                            // [2] 0x255978
    virtual const char *Get(u32 id);                         // [3] 0x255678
    virtual ~CFontTextRes();                                 // [4] 0x2555B0
    CPushBuf m_bufs[8];       // 0x4
    char *m_tbl[0x4000];      // 0x64
    s8 m_page[0x4000];        // 0x10064
};
extern CFontTextRes *D_002BA1D0;
CFontTextRes *Func2554E0();

class IFontBankRes {
public:
    virtual void Release();                                  // [0] inline
    virtual s32 GetUnk4();                                   // [1] inline
};
class CFontBankRes : public IFontBankRes {
public:
    virtual s32 GetUnk4();                                   // [1] override, never defined: keeps the vtable out of this object
    CFontBankRes();
    virtual s32 Regist(u32 id, void *a, void *b);            // [2] 0x255B20 key
    virtual s32 Load(s32 id, const char *a, const char *b);  // [3] 0x255C10
    virtual void Unregist(u32 id);                           // [4] 0x255D08
    virtual void UnregistAll();                              // [5] 0x255D58
    virtual s32 FindUsed();                                  // [6] 0x255DB8
    virtual s32 GetBank(u32 id);                             // [7] 0x255DF8
    virtual ~CFontBankRes();                                 // [8] 0x255AB8
    s32 m_unk4;
    s32 m_banks[8];
};
extern CFontBankRes *D_002BA1D4;
CFontBankRes *Func255A30();
extern "C" void *func_002303E0(const char *name);
extern "C" void func_00240AA8(s32 id);

struct CVCode { u16 m_from; u16 m_to; };
class IFontVCodeRes {
public:
    virtual void Release();                                  // [0] inline
};
class CFontVCodeRes : public IFontVCodeRes {
public:
    virtual void Release();                                  // [0] override, never defined: keeps the vtable out of this object
    CFontVCodeRes();
    virtual s32 Load(const char *name);                      // [1] 0x255EE8 key
    virtual void Free();                                     // [2] 0x2560C8
    virtual void Replace(u8 *s);                             // [3] 0x256118
    virtual ~CFontVCodeRes();                                // [4] 0x255E80
    CVCode *m_codes;          // 0x4
    s32 m_num;                // 0x8
    s32 m_min;                // 0xC
    s32 m_max;                // 0x10
};
extern CFontVCodeRes *D_002BA1D8;
CFontVCodeRes *Func255E18();
extern "C" void func_00241FC8(void);
extern "C" void func_00242468(s32 x);
extern "C" void func_00242170(void);
extern "C" s32 func_00242340(void);
extern "C" void func_00242408(s32 a, s32 b);
// Library font object (vtable _vt$9CFontWork: [0] 0x257030 (empty, key method), [1] 0x257038); the
// vptr follows its fields at 0x7C.
class CFontWork {
public:
    void Func257B70(f32 x0, f32 y0, f32 *x, f32 *y, const char **s, void *ctx, s32 f);
    void Func2574B8(f32 x0, f32 y0, f32 *x, f32 *y, const char **s, void *ctx, s32 f);
    void Func256988(const char *fmt, ...);
    void Func256930(const char *s);
    void Func2566A0(const char *s, s32 shadow);
    void Func2565B0(f32 *w, f32 *h, const char *fmt, ...);
    void Func2564B8(f32 *w, f32 *h, const char *s);
    void Func2562B0(void *ctx, char *buf, s32 n, s32 mode);
    CFontWork();
    virtual void Func0();
    virtual void Func1(s32 x);
    s32 m_unk0;
    s32 m_unk4;
    s32 m_unk8;
    s32 m_unkC;
    s32 m_unk10;
    s32 m_unk14;
    s32 m_unk18;
    s32 m_unk1C;
    f32 m_unk20;
    f32 m_unk24;
    s32 m_unk28;
    s32 m_unk2C;
    f32 m_unk30;
    f32 m_unk34;
    f32 m_unk38;
    f32 m_unk3C;
    s32 m_unk40;
    s32 m_unk44;
    s32 m_unk48;
    s32 m_unk4C;
    s32 m_unk50;
    s32 m_unk54;
    s32 m_unk58;
    s32 m_unk5C;
    s32 m_unk60;
    s32 m_unk64;
    s32 m_unk68;
    f32 m_unk6C;
    s32 m_unk70;
    s32 m_unk74;
    s32 m_unk78;
};
class CFontMgr {
public:
    const char *GetText(s32 id);
    void Func256648();
    s32 Func256668();
    void Func256680(s32 a, s32 b);
};

typedef __builtin_va_list va_list;
extern "C" int vsprintf(char *buf, const char *fmt, va_list ap);
void Func254FD0(CVec4 *out, CVec4 *k, f32 t);
void Func255010(f32 *d, f32 *s);

extern void *(*D_002B91A4)(u32 n);
extern const char D_002E71E0[];
extern const char D_002E7200[];
extern const char D_002E7100[];
void *Func24A4C0(const char *name);
extern "C" s32 func_0024AD80(char *d, s32 c);
extern "C" char *func_0024AD10(char *p, char *buf, s32 a, s32 n);
char *Func24A570(const char *s, char *tok, const char *a, const char *b);

extern "C" s32 func_00240C60(s32 i);
extern "C" s32 func_00240CB8(s32 i);
struct Y1FontCtx {
    s32 m0, m4, m8, mC;
    f32 m10, m14, m18, m1C;
    f32 m20, m24, m28, m2C;
    s32 m30, m34, m38, m3C;
    f32 m40, m44, m48, m4C;
    f32 m50, m54; s32 m58, m5C;
    f32 m60, m64, m68, m6C;
    s32 m70, m74, m78, m7C;
    s32 m80, m84, m88, m8C;
    char *m90; s32 m94; s32 m98;
};

struct Y1FontCtx2 { s32 w[0xA0 / 4]; } __attribute__((aligned(8)));
#define Y1F(m) (*(f32 *)&(m))

struct W2FontCh2 { u8 p0[0xA]; s8 mA; u8 pB[5]; s8 m10; };
struct W2FontLay2 { u8 p0[0x10]; f32 m10; f32 m14; u8 p18[8]; f32 m20; u8 p24[0x2C]; f32 m50; u8 p54[0x28]; s32 m7C; };
extern "C" void func_00256DC8(void *ctx, W2FontCh2 *c, f32 x, f32 y, W2FontLay2 *l);
// @decl-end

INCLUDE_ASM("asm/nonmatchings/Dk254AA8", func_00254AA8);

extern "C" void func_00254F28(s32 init, s32 prio) {
    if (prio == 0xFFFF && init == 1) {
        D_393950.m0 = D_002BA188;
        D_393950.m4 = D_002BA184;
        D_393950.m8 = D_002BA190;
        D_393950.mC = 0;
    }
}

extern "C" void func_00254F70(void) { func_00254F28(1, 0xFFFF); }

void Func254F90(CVec4 *out, CVec4 *k, f32 t) {
    func_002709A8(out, &k[1], k, (t - k[0].z) / (k[1].z - k[0].z));
}

void Func254FD0(CVec4 *out, CVec4 *k, f32 t) {
    f32 f = (t - k[0].x) / (k[1].x - k[0].x);
    func_002709A8(out, &k[1], k, f);
}

void Func255010(f32 *d, f32 *s) {
    f32 b = s[0];
    f32 a = s[1];
    d[0] = a;
    d[1] = b;
}

s32 Func255028(CVec4 *out, CVec4 *in, f32 z) {
    if (in[0].z < z) {
        if (in[1].z < z) return 0;
        Func254F90(out, in, z);
        Func270C50(&out[1], &in[1]);
    } else if (in[1].z < z) {
        Func270C50(out, in);
        Func254F90(&out[1], in, z);
    } else {
        Func270C50(out, in);
        Func270C50(&out[1], &in[1]);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/Dk254AA8", func_002550E0);

INCLUDE_ASM("asm/nonmatchings/Dk254AA8", func_00255200);

CFontTextRes *Func2554E0() {
    CFontTextRes *p = new CFontTextRes;
    return p;
}

CFontTextRes::CFontTextRes() {
    D_002BA1D0 = this;
    memset(m_tbl, 0, sizeof(m_tbl));
    memset(m_page, -1, sizeof(m_page));
}

CFontTextRes::~CFontTextRes() {
    Clear(-1);
    D_002BA1D0 = 0;
}

const char *CFontTextRes::Get(u32 id) {
    const char *p;
    if (id >= 0x4000 || (p = m_tbl[id]) == 0) p = D_002E70D0;
    return p;
}

INCLUDE_RODATA("asm/nonmatchings/Dk254AA8", D_002E70D0);
INCLUDE_ASM("asm/nonmatchings/Dk254AA8", func_002556A8);
INCLUDE_RODATA("asm/nonmatchings/Dk254AA8", D_002E7100);
INCLUDE_RODATA("asm/nonmatchings/Dk254AA8", D_002E7108);
INCLUDE_RODATA("asm/nonmatchings/Dk254AA8", D_002E7128);

void CFontTextRes::Clear(s32 page) {
    s32 i;
    if (page < 0) {
        for (i = 0; i < 8; i++) Clear(i);
        return;
    }
    for (i = 0; i < 0x4000; i++) {
        if (m_page[i] == page) {
            m_tbl[i] = 0;
            m_page[i] = -1;
        }
    }
    m_bufs[page].Func248E00();
}

CFontBankRes *Func255A30() {
    CFontBankRes *p = new CFontBankRes;
    return p;
}

CFontBankRes::CFontBankRes() {
    D_002BA1D4 = this;
    m_unk4 = 0;
    for (s32 i = 0; i < 8; i++) m_banks[i] = -1;
}

CFontBankRes::~CFontBankRes() {
    UnregistAll();
    D_002BA1D4 = 0;
}

INCLUDE_ASM("asm/nonmatchings/Dk254AA8", func_00255B20);
INCLUDE_RODATA("asm/nonmatchings/Dk254AA8", D_002E71B8);
INCLUDE_RODATA("asm/nonmatchings/Dk254AA8", D_002E71E0);
INCLUDE_RODATA("asm/nonmatchings/Dk254AA8", D_002E7200);

s32 CFontBankRes::Load(s32 id, const char *a, const char *b) {
    s32 ok = 0;
    void *pb = 0;
    void *pa = func_002303E0(a);
    if (!pa || !(pb = func_002303E0(b)) || !Regist(id, pa, pb)) Func235DE0(D_002E71B8, a, b);
    else ok = 1;
    if (pa) D_002B91B0(pa);
    if (pb) D_002B91B0(pb);
    return ok;
}

void CFontBankRes::Unregist(u32 id) {
    if (id < 8 && m_banks[id] >= 0) {
        func_00240AA8(m_banks[id]);
        m_banks[id] = -1;
    }
}

void CFontBankRes::UnregistAll() {
    for (s32 i = 0; i < 8; i++) Unregist(i);
}

s32 CFontBankRes::FindUsed() {
    for (s32 i = 0; i < 8; i++) {
        if (m_banks[i] >= 0) return i;
    }
    return -1;
}

s32 CFontBankRes::GetBank(u32 id) {
    s32 r = -1;
    if (id < 8) r = m_banks[id];
    return r;
}

CFontVCodeRes *Func255E18() {
    CFontVCodeRes *p = new CFontVCodeRes;
    return p;
}

CFontVCodeRes::CFontVCodeRes() {
    D_002BA1D8 = this;
    m_codes = 0;
    m_num = 0;
    m_min = -1;
    m_max = -1;
}

CFontVCodeRes::~CFontVCodeRes() {
    Free();
    D_002BA1D8 = 0;
}

s32 CFontVCodeRes::Load(const char *name) {
    s32 ok = 0;
    Free();
    char *data = (char *)Func24A4C0(name);
    if (!data) {
        Func235DE0(D_002E71E0, name);
    } else {
        m_num = func_0024AD80(data, 1);
        m_codes = (CVCode *)D_002B91A4(m_num * 4);
        s32 i = 0;
        char *p = data;
        m_min = -1;
        m_max = -1;
        for (; i < m_num; i++) {
            char line[0x100];
            u8 tok[0x100];
            p = func_0024AD10(p, line, 1, 0x100);
            char *q = Func24A570(line, (char *)tok, D_002E7100, D_002E7100);
            s32 from = (tok[0] << 8) | tok[1];
            Func24A570(q, (char *)tok, D_002E7100, D_002E7100);
            s32 to = (tok[0] << 8) | tok[1];
            m_codes[i].m_from = from;
            m_codes[i].m_to = to;
            if (m_min < 0 || from < m_min) m_min = from;
            if (m_max < 0 || m_max < to) m_max = to;
        }
        Func235DE0(D_002E7200, name);
        ok = 1;
    }
    if (data) D_002B91B0(data);
    return ok;
}

void CFontVCodeRes::Free() {
    if (m_codes) {
        D_002B91B0(m_codes);
        m_codes = 0;
        m_num = 0;
    }
    m_min = -1;
    m_max = -1;
}

void CFontVCodeRes::Replace(u8 *s) {
    while (*s) {
        u32 c = *s++;
        if (c >= 0x80) c = *s++ | (c << 8);
        if ((s32)c < m_min || m_max < (s32)c) continue;
        for (s32 i = 0; i < m_num; i++) {
            if (m_codes[i].m_from == c) {
                u16 v = m_codes[i].m_to;
                s -= 2;
                *s++ = v >> 8;
                *s++ = v;
            }
        }
    }
}

CFontWork::CFontWork() {
    m_unk0 = -1;
    m_unk4 = 0;
    m_unk10 = 0;
    m_unk14 = 0;
    m_unk18 = 0;
    m_unk1C = 0;
    m_unk20 = 1.0f;
    m_unk24 = 1.0f;
    m_unk28 = 0;
    m_unk2C = 0;
    m_unk30 = 1.0f;
    m_unk34 = 1.0f;
    m_unk38 = 1.0f;
    m_unk3C = 1.0f;
    m_unk40 = 0;
    m_unk44 = 0;
    m_unk48 = 0;
    m_unk4C = 0;
    m_unk50 = 0;
    m_unk54 = 0;
    m_unk58 = 0;
    m_unk60 = 0;
    m_unk64 = 0;
    m_unk68 = 0;
    m_unk6C = 1.0f;
    m_unk70 = 0;
    m_unk74 = 0;
    m_unk78 = -1;
}

const char *CFontMgr::GetText(s32 id) {
    if (D_002BA1D0) return D_002BA1D0->Get(id);
    return D_002E70D0;
}

void CFontWork::Func2562B0(void *vctx, char *buf, s32 n, s32 mode)
{
    Y1FontCtx *c = (Y1FontCtx *)vctx;
    CVec4 v;
    if (mode == 0) Func270C50(&v, (CVec4 *)&m_unk30);
    else {
        Func270C50(&v, (CVec4 *)&m_unk60);
        v.w *= m_unk3C;
    }
    s32 b;
    if (D_002BA1D4->GetBank(m_unk0) >= 0) b = m_unk0;
    else b = D_002BA1D4->FindUsed();
    c->m0 = b;
    c->m4 = D_002BA1D4->GetBank(b);
    c->m10 = func_00240C60(c->m4) * m_unk20;
    c->m14 = func_00240CB8(c->m4) * m_unk24;
    c->m20 = m_unk20;
    c->m24 = m_unk24;
    c->m30 = (s32)(v.x * 128.0f);
    c->m34 = (s32)(v.y * 128.0f);
    c->m38 = (s32)(v.z * 128.0f);
    c->m3C = (s32)(v.w * 128.0f);
    c->m40 = v.x;
    c->m44 = v.y;
    c->m48 = v.z;
    c->m4C = v.w;
    c->m50 = *(f32 *)&m_unk40;
    c->m54 = *(f32 *)&m_unk44;
    c->m60 = m_unk20;
    c->m64 = m_unk24;
    c->m70 = m_unk50;
    c->m74 = m_unk54;
    c->m78 = mode;
    c->m7C = m_unk70;
    c->m80 = 0;
    c->m84 = 0;
    c->m88 = 0;
    c->m90 = buf;
    c->m94 = n;
    c->m98 = 0;
}

void CFontWork::Func2564B8(f32 *w, f32 *h, const char *s) {
    if (!D_002BA1D4) return;
    char ctx[0xA0];
    char buf[0x1000];
    f32 x, y;
    Func2562B0(ctx, buf, 0x400, m_unk58);
    x = 0;
    y = 0;
    switch (m_unk4) {
    case 0:
        Func2574B8(x, x, &x, &y, &s, ctx, 0);
        break;
    case 1:
        Func257B70(x, x, &x, &y, &s, ctx, 0);
        break;
    }
    if (w) *w = x;
    if (h) *h = y;
}

void CFontWork::Func2565B0(f32 *w, f32 *h, const char *fmt, ...) {
    char buf[0x400];
    va_list ap;
    __builtin_stdarg_start(ap, fmt);
    vsprintf(buf, fmt, ap);
    Func2564B8(w, h, buf);
    __builtin_va_end(ap);
}

void CFontMgr::Func256648() { func_00242170(); }

s32 CFontMgr::Func256668() { return func_00242340(); }

void CFontMgr::Func256680(s32 a, s32 b) { func_00242408(a, b); }

void CFontWork::Func2566A0(const char *s, s32 mode)
{
    const char *p = s;
    Y1FontCtx2 c;
    Y1FontCtx2 c2;
    char buf[0x1000];
    const char *p2;
    f32 w, h, x, y;
    if (!D_002BA1D4) return;
    Func2562B0(&c, buf, 0x400, mode);
    c2 = c;
    p2 = p;
    w = h = x = y = 0.0f;
    if (m_unk4 == 0) {
        Func2574B8(x, y, &w, &h, &p, &c, 0);
        switch (m_unk50) {
        case 1: x = (Y1F(m_unk10) + Y1F(m_unk18)) * 0.5f - w * 0.5f; break;
        case 2: x = Y1F(m_unk18) - w; break;
        case 0: default: x = Y1F(m_unk10); break;
        }
    } else {
        Func257B70(x, y, &w, &h, &p, &c, 0);
        switch (m_unk50) {
        case 0: default: x = Y1F(m_unk10) + w; break;
        case 1: x = (Y1F(m_unk10) + Y1F(m_unk18)) * 0.5f + w * 0.5f; break;
        case 2: x = Y1F(m_unk18); break;
        }
    }
    switch (m_unk54) {
    case 1: y = (Y1F(m_unk14) + Y1F(m_unk1C)) * 0.5f - h * 0.5f; break;
    case 0: default: y = Y1F(m_unk14); break;
    case 2: y = Y1F(m_unk1C) - h; break;
    }
    switch (m_unk4) {
    case 0: Func2574B8(x, y, &w, &h, &p2, &c2, 1); break;
    case 1: Func257B70(x, y, &w, &h, &p2, &c2, 1); break;
    }
}

void CFontWork::Func256930(const char *s) {
    if (m_unk58 < 3) {
        if (m_unk58 > 0) Func2566A0(s, m_unk58);
    }
    Func2566A0(s, 0);
}

void CFontWork::Func256988(const char *fmt, ...) {
    char buf[0x400];
    va_list ap;
    __builtin_stdarg_start(ap, fmt);
    vsprintf(buf, fmt, ap);
    Func256930(buf);
    __builtin_va_end(ap);
}

INCLUDE_ASM("asm/nonmatchings/Dk254AA8", func_00256A00);
INCLUDE_RODATA("asm/nonmatchings/Dk254AA8", D_002E73B0);
INCLUDE_RODATA("asm/nonmatchings/Dk254AA8", D_002E73C0);
INCLUDE_RODATA("asm/nonmatchings/Dk254AA8", D_002E73D0);
INCLUDE_RODATA("asm/nonmatchings/Dk254AA8", D_002E73E0);
INCLUDE_RODATA("asm/nonmatchings/Dk254AA8", D_002E73F0);
INCLUDE_RODATA("asm/nonmatchings/Dk254AA8", D_002E7400);
INCLUDE_RODATA("asm/nonmatchings/Dk254AA8", D_002E7410);

INCLUDE_ASM("asm/nonmatchings/Dk254AA8", func_00256DC8);

extern "C" void func_00257030(void) {
}

void CFontWork::Func1(s32 x) {
    func_00241FC8();
    func_00242468(x);
}

extern "C" void func_00257068(void *ctx, f32 *ow, f32 *oh, W2FontCh2 **items, s32 n, W2FontLay2 *l, s32 flags, f32 x, f32 y)
{
    f32 w = 0.0f;
    s32 i;
    for (i = 0; i < n; i++) {
        f32 adv;
        if (items[i] != 0) {
            if (l->m7C) {
                if (flags & 4) func_00256DC8(ctx, items[i], x + w + (f32)items[i]->m10 * l->m20, y, l);
                adv = l->m10;
            } else {
                if (flags & 4) func_00256DC8(ctx, items[i], x + w, y, l);
                adv = (f32)items[i]->mA * l->m20;
            }
        } else {
            adv = l->m10;
        }
        w += adv;
        w += l->m50;
    }
    w -= l->m50;
    *ow = w;
    *oh = l->m14;
}
