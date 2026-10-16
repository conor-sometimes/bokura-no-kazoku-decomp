#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMemTex.h"
typedef __builtin_va_list va_list;
extern "C" void *memcpy(void *d, const void *s, unsigned int n);
extern "C" void *memset(void *d, int c, unsigned int n);
extern "C" int vsprintf(char *buf, const char *fmt, va_list ap);
s32 Func235DE0(const char *fmt, ...);
extern void *(*D_002B91A4)(u32 n);
extern void (*D_002B91B0)(void *p);
void Func23B1D0(s32 fd);

class IDebOut {
public:
    virtual void Release();                                  // [0] inline
};
class CDebOut : public IDebOut {
public:
    virtual s32 Open(const char *name);                      // [1] 0x251CC8
    virtual void Close();                                    // [2] 0x251D80
    virtual void SetUnk10(s32 a, s32 b);                     // [3] inline
    virtual void SetUnk18(s32 a, s32 b);                     // [4] inline
    virtual void SetColor(f32 r, f32 g, f32 b, f32 a);       // [5] 0x252238
    virtual void SetCursor(s32 x, s32 y);                    // [6] 0x252220
    virtual void SetPos(f32 x, f32 y);                       // [7] 0x252208
    virtual void SetUnk28(s32 v);                            // [8] 0x252230
    virtual void Measure(const char *s, s32 *w, s32 *h);     // [9] 0x2522F8
    virtual void Begin();                                    // [10] 0x251DC0
    virtual void Printf(const char *fmt, ...);               // [11] 0x252250
    virtual s32 End();                                       // [12] 0x2520C8
    virtual void PrintfAt(const char *fmt, ...);             // [13] 0x252A80
    virtual ~CDebOut();                                      // [14] 0x251C60
    void Func2522B0(const char *fmt, va_list ap);
    void Func2523F8(const char *s, s32 *x0, s32 *x1, s32 *y0, s32 *y1, s32 draw);

    s32 m_fd;        // 0x4
    f32 m_x;         // 0x8
    f32 m_y;         // 0xC
    s32 m_unk10;     // 0x10
    s32 m_unk14;     // 0x14
    s32 m_unk18;     // 0x18
    s32 m_unk1C;     // 0x1C
    s32 m_cx;        // 0x20
    s32 m_cy;        // 0x24
    s32 m_unk28;     // 0x28
    f32 m_r;         // 0x2C
    f32 m_g;         // 0x30
    f32 m_b;         // 0x34
    f32 m_a;         // 0x38
};
s32 Func252398(const char **pp);

// Bone remap table (CBoneDupMap's base): pairs of bone indices between two XMD models.
struct CBonePair { s16 m_a; s16 m_b; };
class CVec4;
void Func270C50(CVec4 *d, const CVec4 *s);
struct CBoneXf { u8 a[0x10]; u8 b[0x10]; u8 c[0x10]; };
struct CBoneSet { u8 pad[0x10]; CBoneXf m_bones[1]; };
class CCharaObjSub48 {
public:
    void Func252BB8();
    s32 Func252E18(s32 a, s32 b);
    void Func252EC8(CBoneSet *dst, CBoneSet *src, u32 flags);
    CBonePair *m_unk0;
    s32 m_unk4;
    s32 m_unk8;
    s32 m_unkC;
};
class CBoneDupMap : public CCharaObjSub48 {
public:
    CBoneDupMap();
    virtual void KeyStub();   // never defined: the retail key method is the destructor, this keeps the vtable out of the object
    virtual ~CBoneDupMap();
};
s32 Func252C08(s32 id, const char *name);
s32 Func252CC0(CBonePair *out, s32 a, s32 b);
extern const char D_002E6B48[];
struct CTexFmt { s32 m0; s32 m4; u32 m8; s32 mC; };
extern CTexFmt D_002BA0B8[];
struct CTim2Pic { u32 m_total; u32 m_clutSize; u32 m_imgSize; u16 m_hdrSize; u16 m_clutColors; u8 m_fmt; u8 m_mip; u8 m_clutType; u8 m_imgType; u16 m_w; u16 m_h; };

// Byte stream helpers (BMP loader): read/write through a cursor.
void Func253188(u8 **pp, void *dst, s32 n);
void Func2531D0(u8 **pp, void *dst);
void Func2531E8(u8 **pp, void *dst);
void Func253200(u8 **pp, void *dst);
s32 Func253218(u8 **pp, const void *src, s32 n);
s32 Func253268(u8 **pp, u32 v);
s32 Func253290(u8 **pp, u16 v);
s32 Func2532B8(u8 **pp, u8 v);
s32 Func2532E0(u8 **pp, u8 *h);
s32 Func2539A0(s32 fmt);
s32 Func253A18(s32 fmt);

extern u32 *D_002B94E4;
inline u32 *PktAlloc(s32 n) { u32 *p = D_002B94E4; D_002B94E4 = p + n; return p; }
extern "C" void func_00237350(s32 x);
extern "C" void func_00237408(s32 x);
extern "C" void func_00237460(void);
extern "C" void func_002374B0(void);
extern "C" void func_00227BF0(u64 tex0, s32 a, s32 b, s32 c, s32 d, u8 *p);
extern "C" void func_001EFF48(u64 tex0, s32 a, s32 b, s32 c, s32 d, u8 *p, s32 e);
class IShareTex {
public:
    virtual void Release();                                  // [0] inline
};
class CShareTex : public IShareTex {
public:
    CShareTex();
    virtual s32 Func253BE0(s32 a, s32 b, s32 c, s32 d);      // [1] key method
    virtual void Func253E30();                               // [2]
    virtual s32 GetUnk4();                                   // [3] inline
    virtual u64 GetUnk8();                                   // [4] inline
    virtual u64 GetUnk10();                                  // [5] inline
    virtual s32 Func253E78(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i); // [6]
    virtual void Func254090(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i); // [7]
    virtual ~CShareTex();                                    // [8]
    s32 m_unk4;
    u64 m_unk8;
    u64 m_unk10;
};
extern CShareTex *D_002BA128;
CShareTex *Func253A38();
struct CTexFmtEnt { s32 m0; s32 m4; };
extern CTexFmtEnt D_002BA130[];
s32 Func253B00(s32 fmt);
s32 Func253B70(s32 fmt);
s32 Func253BA8(s32 fmt);
s32 Func254730(s32 psm);
void Func254788(u64 tex0, s32 a, s32 b, s32 c, s32 d, s32 e, u8 *p);
void Func254838(u64 tex0, s32 a, s32 b, s32 c, s32 d, s32 e, u8 *p);

extern "C" u64 func_0023AA40(s32 c);
extern "C" u64 func_0023BD80(s32 c);
void Func225088();
int Func2250C0();
void Func2251E8();
void Func227DC8(long t, s32 n, s32 p);
extern "C" void func_00227A20();
extern "C" void func_00227AA8();
extern "C" void func_00226DF8(s32 reg, u64 v);
// @decl-end

void CDebOut::SetPos(f32 x, f32 y) {
    m_x = x;
    m_y = y;
    m_cx = 0;
    m_cy = 0;
}

void CDebOut::SetCursor(s32 x, s32 y) {
    m_cx = x;
    m_cy = y;
}

void CDebOut::SetUnk28(s32 v) { m_unk28 = v; }

void CDebOut::SetColor(f32 r, f32 g, f32 b, f32 a) {
    m_r = r;
    m_g = g;
    m_b = b;
    m_a = a;
}

void CDebOut::Printf(const char *fmt, ...) {
    va_list ap;
    __builtin_stdarg_start(ap, fmt);
    Func2522B0(fmt, ap);
    __builtin_va_end(ap);
}

void CDebOut::Func2522B0(const char *fmt, va_list ap) {
    char buf[0x1000];
    vsprintf(buf, fmt, ap);
    Func2523F8(buf, 0, 0, 0, 0, 1);
}

void CDebOut::Measure(const char *s, s32 *w, s32 *h) {
    s32 r[4];
    s32 x = m_cx;
    s32 y = m_cy;
    m_cx = 0;
    m_cy = 0;
    Func2523F8(s, &r[0], &r[1], &r[2], &r[3], 0);
    if (w) *w = r[1] - r[0];
    if (h) *h = r[3] - r[2];
    m_cx = x;
    m_cy = y;
}

s32 Func252398(const char **pp) {
    s32 n = 0;
    while ((u32)((u8)**pp - '0') < 10) n = n * 10 + *(*pp)++ - '0';
    return n;
}

INCLUDE_ASM("asm/nonmatchings/Dk252208", Func2523F8__7CDebOutPCcPiN32i);

void CDebOut::PrintfAt(const char *fmt, ...) {
    va_list ap;
    Begin();
    __builtin_stdarg_start(ap, fmt);
    Func2522B0(fmt, ap);
    End();
    __builtin_va_end(ap);
}

CBoneDupMap::CBoneDupMap() {
    m_unk0 = 0;
    m_unk4 = 0;
    m_unkC = -1;
    m_unk8 = -1;
}

CBoneDupMap::~CBoneDupMap() { Func252BB8(); }

void CCharaObjSub48::Func252BB8() {
    if (m_unk0) D_002B91B0(m_unk0);
    m_unk0 = 0;
    m_unk4 = 0;
    m_unk8 = -1;
    m_unkC = -1;
}

INCLUDE_ASM("asm/nonmatchings/Dk252208", Func252C08__FiPCc);

INCLUDE_ASM("asm/nonmatchings/Dk252208", Func252CC0__FP9CBonePairii);

s32 CCharaObjSub48::Func252E18(s32 a, s32 b) {
    Func252BB8();
    m_unk4 = Func252CC0(0, a, b);
    m_unk0 = (CBonePair *)D_002B91A4(m_unk4 * 4);
    Func252CC0(m_unk0, a, b);
    m_unk8 = Func252C08(a, D_002E6B48);
    m_unkC = Func252C08(b, D_002E6B48);
    return 1;
}

void CCharaObjSub48::Func252EC8(CBoneSet *dst, CBoneSet *src, u32 flags) {
    for (s32 i = 0; i < m_unk4; i++) {
        s32 d = m_unk0[i].m_a;
        s32 s = m_unk0[i].m_b;
        if (flags & 2) Func270C50((CVec4 *)dst->m_bones[d].b, (CVec4 *)src->m_bones[s].b);
        if (flags & 1) Func270C50((CVec4 *)dst->m_bones[d].c, (CVec4 *)src->m_bones[s].c);
        if (flags & 4) Func270C50((CVec4 *)dst->m_bones[d].a, (CVec4 *)src->m_bones[s].a);
    }
    if (m_unk8 >= 0 && m_unkC >= 0) Func270C50((CVec4 *)dst->m_bones[m_unk8].c, (CVec4 *)src->m_bones[m_unkC].c);
}

s32 Func253048(u32 *data, u8 **pix, s32 *psm, s32 *w, s32 *h, u8 **clut, s32 *cpsm, u32 *k, s32 *n) {
    if (*data != 0x324D4954 && *data != 0x32544C43) return 0;
    CTim2Pic *t = (CTim2Pic *)(data + 4);
    u8 *p = 0;
    s32 fmt = 0;
    s32 ww = 0;
    s32 hh = 0;
    u32 isz = t->m_imgSize;
    if (isz) {
        fmt = D_002BA0B8[t->m_imgType].m0;
        p = (u8 *)t + t->m_hdrSize;
        ww = t->m_w;
        hh = t->m_h;
    }
    u8 *c = 0;
    s32 cf = 0;
    u32 kk = 0;
    s32 cnt = 0;
    if (t->m_clutSize) {
        c = (u8 *)t + t->m_hdrSize + isz;
        cf = D_002BA0B8[t->m_clutType & 0x7F].m0;
        kk = D_002BA0B8[t->m_imgType].m8;
        if (kk) cnt = t->m_clutColors / kk;
    }
    if (pix) *pix = p;
    if (psm) *psm = fmt;
    if (w) *w = ww;
    if (h) *h = hh;
    if (clut) *clut = c;
    if (cpsm) *cpsm = cf;
    if (k) *k = kk;
    if (n) *n = cnt;
    return 1;
}

void Func253188(u8 **pp, void *dst, s32 n) {
    if (dst) memcpy(dst, *pp, n);
    *pp += n;
}

void Func2531D0(u8 **pp, void *dst) { return Func253188(pp, dst, 4); }

void Func2531E8(u8 **pp, void *dst) { return Func253188(pp, dst, 2); }

void Func253200(u8 **pp, void *dst) { return Func253188(pp, dst, 1); }

s32 Func253218(u8 **pp, const void *src, s32 n) {
    if (*pp) {
        memcpy(*pp, src, n);
        *pp += n;
    }
    return n;
}

s32 Func253268(u8 **pp, u32 v) { return Func253218(pp, &v, 4); }

s32 Func253290(u8 **pp, u16 v) { return Func253218(pp, &v, 2); }

s32 Func2532B8(u8 **pp, u8 v) { return Func253218(pp, &v, 1); }

s32 Func2532E0(u8 **pp, u8 *h) {
    Func2531E8(pp, h);
    if (*(u16 *)h != 0x4D42) return 0;
    Func2531D0(pp, h + 4);
    Func2531E8(pp, h + 8);
    Func2531E8(pp, h + 0xA);
    Func2531D0(pp, h + 0xC);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/Dk252208", func_00253358);

INCLUDE_ASM("asm/nonmatchings/Dk252208", func_00253530);

INCLUDE_ASM("asm/nonmatchings/Dk252208", func_002536C8);

INCLUDE_ASM("asm/nonmatchings/Dk252208", func_002537E8);

INCLUDE_ASM("asm/nonmatchings/Dk252208", func_002538A0);

INCLUDE_ASM("asm/nonmatchings/Dk252208", Func2539A0__Fi);

s32 Func253A18(s32 fmt) { return Func2539A0(fmt) >> 3; }

CShareTex *Func253A38() {
    CShareTex *p = new CShareTex;
    return p;
}

CShareTex::CShareTex() {
    D_002BA128 = this;
    m_unk4 = -1;
    m_unk8 = 0;
    m_unk10 = 0;
}

CShareTex::~CShareTex() {
    Func253E30();
    D_002BA128 = 0;
}

INCLUDE_ASM("asm/nonmatchings/Dk252208", Func253B00__Fi);

s32 Func253B70(s32 fmt) { return D_002BA130[Func253B00(fmt)].m4; }

s32 Func253BA8(s32 fmt) { return D_002BA130[Func253B00(fmt)].m0; }

INCLUDE_ASM("asm/nonmatchings/Dk252208", func_00253BE0);

void CShareTex::Func253E30() {
    if (m_unk4 >= 0) {
        Func23B1D0(m_unk4);
        m_unk4 = -1;
        m_unk8 = 0;
        m_unk10 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/Dk252208", func_00253E78);

void CShareTex::Func254090(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i) {
    if (m_unk4 < 0) return;
    func_00237350(8);
    func_00237408(8);
    s32 n = Func253E78(a, b, c, d, e, f, g, h, i);
    func_00237460();
    *PktAlloc(1) = 0x11000000;
    *PktAlloc(1) = n | 0x50000000;
    func_002374B0();
}

CMemTex::CMemTex() {
    m_unk4 = -1;
    m_unk0 = 0;
    m_unk8 = 0;
    m_unkC = 0;
    m_unk10 = 0;
    m_unk14 = 0;
    m_unk18 = 0;
    m_unk1C = 0;
    m_unk20 = 0;
    m_unk24 = 0;
}

INCLUDE_ASM("asm/nonmatchings/Dk252208", _$_7CMemTex);

INCLUDE_ASM("asm/nonmatchings/Dk252208", func_00254248);

void CMemTex::Func2546F0() {
    if (m_unk0) {
        D_002B91B0(m_unk0);
        m_unk0 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/Dk252208", Func254730__Fi);

void Func254788(u64 tex0, s32 a, s32 b, s32 c, s32 d, s32 e, u8 *p) {
    s32 bpp = Func254730((s32)((tex0 >> 32) & 0x3F));
    func_00227BF0(tex0, a, b, c, e, p + d * bpp * c / 8);
}

void Func254838(u64 tex0, s32 a, s32 b, s32 c, s32 d, s32 e, u8 *p) {
    s32 bpp = Func254730((s32)((tex0 >> 32) & 0x3F));
    func_001EFF48(tex0, a, b, c, e, p + d * bpp * c / 8, 0);
}

extern "C" void func_002548F0(CMemTex *t, s32 id, s32 idx) {
    u64 a = func_0023AA40(id);
    u64 b = func_0023BD80(id);
    Func225088();
    if (t->m_unk20 > 0) {
        idx = idx < t->m_unk24 - 1 ? idx : t->m_unk24 - 1;
        idx = idx < 0 ? 0 : idx;
        Func227DC8(b, t->m_unk20, t->m_unk18 + t->m_unk20 * idx * 4);
    }
    switch (t->m_unk4) {
    case 0:
        Func254788(a, 0, 0, t->m_unk10, 0, t->m_unk14, (u8 *)t->m_unk8);
        break;
    case 1:
        Func254838(a, 0, 0, t->m_unk10, 0, t->m_unk14, (u8 *)t->m_unk8);
        break;
    }
    func_00227A20();
    func_00226DF8(6, (a & 0x3FFF) | (((a >> 14) & 0x3F) << 14) | (((a >> 32) & 0x3F) << 20) | ((u64)10 << 26) | ((u64)10 << 30)
                     | ((u64)1 << 34) | ((b & 0x3FFF) << 37) | (((b >> 32) & 0x3F) << 51) | ((u64)1 << 61));
    func_00226DF8(8, 2 | (2 << 2) | ((u64)(t->m_unk10 - 1) << 14) | ((u64)(t->m_unk14 - 1) << 34));
    func_00227AA8();
    Func2251E8();
    return (void)Func2250C0();
}
