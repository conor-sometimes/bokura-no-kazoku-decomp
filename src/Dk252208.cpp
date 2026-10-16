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
struct Y1BmpCore { u32 size; u16 w, h, planes, bits; };
struct Y1BmpInfo { u32 m_size; s32 m_w; s32 m_h; u16 m_planes; u16 m_bits; u32 m_comp; u32 m_imgsize; s32 m18, m1C; u32 m_clrUsed; u32 m24; };
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
INCLUDE_RODATA("asm/nonmatchings/Dk252208", D_002E6B48);
INCLUDE_RODATA("asm/nonmatchings/Dk252208", D_002E6B50);
INCLUDE_RODATA("asm/nonmatchings/Dk252208", D_002E6B60);
INCLUDE_RODATA("asm/nonmatchings/Dk252208", D_002E6B68);
INCLUDE_RODATA("asm/nonmatchings/Dk252208", D_002E6B70);
INCLUDE_RODATA("asm/nonmatchings/Dk252208", D_002E6B78);
INCLUDE_RODATA("asm/nonmatchings/Dk252208", D_002E6B80);
INCLUDE_RODATA("asm/nonmatchings/Dk252208", D_002E6B88);

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
