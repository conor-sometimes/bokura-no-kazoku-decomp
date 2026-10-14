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
};
class CUnk25C230 {
public:
    void Func25C230();
};
class CLayoutObj {
public:
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
    void Func1BA210(int a, f32 x, f32 y, f32 z, f32 w);
    void Draw1BA1D0(int a, f32 x, f32 y, f32 z, f32 w);
    void Func1BA440(int a, f32 x, f32 y, f32 z, f32 w);
    int Draw1BA5D0(int a, f32 x, f32 y, f32 z, f32 w);
    void Printf(const char *fmt, ...);
    CLayoutEntry *FindEntry(const char *name);
    CLayoutEntry *GetEntry(int i);

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
    char m_text[0x10C];       // 0x64
    CUnk25C230 m_unk170;      // 0x170
    u8 pad171[0x6B];
    s32 m_unk1DC;             // 0x1DC
    s32 m_unk1E0;             // 0x1E0
    s32 m_unk1E4;             // 0x1E4
    s32 m_unk1E8;             // 0x1E8
    s32 m_unk1EC;             // 0x1EC
    s32 m_unk1F0;             // 0x1F0
    s32 m_unk1F4;             // 0x1F4
    u8 pad1F8[0x4];
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
    s32 m0; f32 m4, m8; s32 mC, m10; u8 pad14[0xC]; f32 m20, m24, m28, m2C, m30, m34; s32 m38, m3C;
};
int LayoutFlagX(int v);
int LayoutFlagY(int v);
const char *ParseUInt(const char *s, int *out);
const char *ParseSjis(const char *s, s16 *out);
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001B9D40);

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001B9D70);

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

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001B9E78);

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

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", Func1B9FF0__10CLayoutObj);

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

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", Func1BA0F0__10CLayoutObj);

int CLayoutObj::Func1BA1A0() {
    Func1B9FF0();
    Func1BA0F0();
    return Func1BA0C0();
}

void CLayoutObj::Draw1BA1D0(int a, f32 x, f32 y, f32 z, f32 w) {
    Func1BA210(a, x, y, z + m_unk30 + m_unk50, w + m_unk34 + m_unk54);
}

INCLUDE_RODATA("asm/nonmatchings/CLayoutObj", D_002E0BE8);
INCLUDE_ASM("asm/nonmatchings/CLayoutObj", Func1BA210__10CLayoutObjiffff);

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", Func1BA440__10CLayoutObjiffff);

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001BA520);

int CLayoutObj::Draw1BA5D0(int a, f32 x, f32 y, f32 z, f32 w) {
    Func1B9FF0();
    Func1BA440(a, x, y, z, w);
    return Func1BA0C0();
}

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001BA650);

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001BA728);

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

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001BBD78);

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001BBDB0);

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

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001BC6A8);

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001BC870);

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001BC900);

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001BCAF8);

const char *ParseUInt(const char *s, int *out) {
    *out = 0;
    while (*s >= '0' && *s <= '9') {
        *out = *out * 10 + (*s++ - '0');
    }
    return s;
}

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001BCFB0);
INCLUDE_RODATA("asm/nonmatchings/CLayoutObj", D_002E0D40);

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001BD188);

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001BD1E0);

void CLayoutObj::CallFunc1B9E28() {
    Func1B9E28();
}

void CLayoutObj::SetUnk30(f32 x, f32 y) {
    if (m_unk0) {
        m_unk30 = x;
        m_unk34 = y;
    }
}

void CLayoutObj::SetUnk1DC(s32 v) {
    m_unk1DC = v;
}

void CLayoutObj::CopyUnk1DC() {
    m_unk1E0 = m_unk1DC;
}

void CLayoutObj::ResetUnk1E0() {
    m_unk1E4 = 0;
    m_unk1E8 = 0;
    m_unk1E0 = 0;
    m_unk1F4 = -1;
}

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001BD320);

INCLUDE_ASM("asm/nonmatchings/CLayoutObj", func_001BD420);
