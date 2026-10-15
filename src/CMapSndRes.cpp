#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CMapSndResSub1278F8 {
public:
    void Reset();

    s8 m_unk0;                // 0x0
    u8 pad1[0x1F];
    s32 m_unk20;              // 0x20
    s32 m_unk24;              // 0x24
    s32 m_unk28;              // 0x28
    s32 m_unk2C;              // 0x2C
    s32 m_unk30;              // 0x30
    s32 m_unk34;              // 0x34
    s32 m_unk38;              // 0x38
    u8 pad3C[0x104];
    s32 m_unk140;             // 0x140
};

// TArray<tagMapSndStepInfo, 16, TAllocator<tagMapSndStepInfo> > (template code at 0x295Dxx).
extern "C" void func_00295DA0(void *p);
class CUnk295E20 {
public:
    void Func295E20(int v);

    u8 pad0[0x18];
};
// Vtable 0x2C0410 still asm; the destructor (key method) stays INCLUDE_ASM.
class CMapSndRes {
public:
    CMapSndRes();
    virtual ~CMapSndRes();
    void Func127928();
    void CallFunc127928();
    s32 Save(char *buf);
    s32 Load(const char *text);
    int SaveFile(const char *name);
    int LoadFile(const char *name);
    int SaveWith(s32 (CMapSndRes::*fn)(char *), const char *name);
    int LoadWith(s32 (CMapSndRes::*fn)(const char *), const char *name);

    s32 m_unk0;               // 0x0
    u8 pad4[0xC];
    CMapSndResSub1278F8 m_unk10; // 0x10
    u8 pad154[0xC];
    CUnk295E20 m_unk160;      // 0x160
    // vptr 0x178
};

class CMapSndResSub127C10 {
public:
    void Init();
    u8 pad0[0x28];
    s32 m28;                  // 0x28
    f32 m2C;                  // 0x2C
    f32 m30;                  // 0x30
    s32 m34;                  // 0x34
    s32 m38;                  // 0x38
};

struct CTextStream {
    char *m_cur;
};
extern "C" s32 func_0024B818(CTextStream *s, const char *fmt, ...);
extern "C" s32 func_00127968(CTextStream *s, const char *name, void *rec);
extern "C" s32 func_00295E40(CUnk295E20 *a);
extern "C" void *func_00295E48(CUnk295E20 *a, s32 i);
extern const char *D_002A0B38;
extern const char *D_002A0B3C;
extern const char *D_002A0B40;
extern const char *D_002A0B44;
const char *Func24AF10(void *text, const char *key);
extern "C" s32 func_0024B298(const char *text, const char *key, s32 *v, s32 def);
extern "C" const char *func_00127AB0(const char *text, const char *name, void *rec);
extern "C" s32 func_0024AF90(const char *text, const char *name);
extern "C" void *func_0024A3D8(s32 n);
extern "C" s32 func_002301B0(const char *name, void *buf, s32 n);
void *Func24A4C0(const char *name);
extern void (*D_002B91B0)(void *p);
extern const char *D_002A0B4C, *D_002A0B50, *D_002A0B54, *D_002A0B58, *D_002A0B5C, *D_002A0B60, *D_002A0B64, *D_002A0B68, *D_002A0B8C;
extern "C" void func_0024B190(const char *p, const char *key, char *dst, const char *def, s32 n);
extern "C" s32 func_0024B300(const char *p, const char *key, f32 *dst, f32 def);
extern "C" void func_0024B4B8(const char *p, const char *key, void *dst, s32 *n, s32 max);
extern "C" s32 func_0024B8B8(CTextStream *s, const char *key, void *src, s32 n);
extern "C" char *strcpy(char *, const char *);
// A sound record as saved in the map sound text (CMapSndResSub1278F8 / tagMapSndStepInfo).
struct CMapSndRec {
    char m_name[0x20];        // 0x00
    s32 m20;                  // 0x20
    s32 m24;                  // 0x24
    s32 m28;                  // 0x28
    f32 m2C;                  // 0x2C
    f32 m30;                  // 0x30
    s32 m34;                  // 0x34
    s32 m38;                  // 0x38
    u8 pad3C[4];
    u8 m40[0x100];            // 0x40
    s32 m140;                 // 0x140
} __attribute__((aligned(8)));
// @decl-end

CMapSndRes::CMapSndRes() {
    func_00295DA0(&m_unk160);
    Func127928();
}

INCLUDE_ASM("asm/nonmatchings/CMapSndRes", _$_10CMapSndRes);

void CMapSndResSub1278F8::Reset() {
    m_unk0 = 0;
    m_unk20 = 0x80;
    m_unk24 = 0;
    m_unk28 = 0;
    m_unk2C = 0;
    m_unk30 = 0;
    m_unk34 = 0x80;
    m_unk38 = 0;
    m_unk140 = 0;
}

void CMapSndRes::Func127928() {
    m_unk0 = 0x80;
    m_unk10.Reset();
    m_unk160.Func295E20(0);
}

INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4A08);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4A38);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4A48);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4A60);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4A68);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4A70);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4A78);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4A80);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4A88);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4A90);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4A98);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4AA0);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4AA8);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4AB0);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4AB8);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4AC0);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4AC8);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4AD0);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4AD8);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4AE0);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4AE8);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4AF0);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4AF8);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4B00);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4B08);
s32 func_00127968(CTextStream *s, const char *name, void *rec) {
    CMapSndRec *r = (CMapSndRec *)rec;
    s32 n = func_0024B818(s, "[%s]\n\t%s=%s\n\t%s=%d\n\t%s=%d\n\t%s=%d\n\t%s=%f\n\t%s=%f\n\t%s=%d\n\t%s=%d\n",
        name, D_002A0B4C, r->m_name, D_002A0B68, r->m20, D_002A0B50, r->m24, D_002A0B54, r->m28,
        D_002A0B58, r->m2C, D_002A0B5C, r->m30, D_002A0B60, r->m34, D_002A0B64, r->m38);
    n += func_0024B8B8(s, D_002A0B8C, r->m40, r->m140);
    n += func_0024B818(s, "\n");
    return n;
}

const char *func_00127AB0(const char *text, const char *name, void *rec) {
    CMapSndRec *r = (CMapSndRec *)rec;
    const char *p = Func24AF10((void *)text, name);
    if (*p) {
        func_0024B190(p, D_002A0B4C, r->m_name, "", 0x100);
        if (!r->m_name[0]) strcpy(r->m_name, "SE_STEP_CONCRE");
        func_0024B298(p, D_002A0B68, &r->m20, 0x80);
        func_0024B298(p, D_002A0B50, &r->m24, 0);
        func_0024B298(p, D_002A0B54, &r->m28, 0);
        func_0024B300(p, D_002A0B58, &r->m2C, 0.0f);
        func_0024B300(p, D_002A0B5C, &r->m30, 0.0f);
        func_0024B298(p, D_002A0B60, &r->m34, 0x80);
        func_0024B298(p, D_002A0B64, &r->m38, 0);
        func_0024B4B8(p, D_002A0B8C, r->m40, &r->m140, 0x10);
    }
    return p;
}

void CMapSndResSub127C10::Init() {
    m28 = 1;
    m34 = 0x80;
    m38 = 0x30;
    m2C = 20.0f;
    m30 = 80.0f;
}

s32 CMapSndRes::Save(char *buf) {
    CTextStream s;
    s32 n, i;
    s.m_cur = buf;
    n = func_0024B818(&s, "# map sound data\n\n");
    n += func_0024B818(&s, "[%s]\n\t%s=%d\n\n", D_002A0B38, D_002A0B44, m_unk0);
    n += func_00127968(&s, D_002A0B3C, &m_unk10);
    if (func_00295E40(&m_unk160) > 0) {
        for (i = 0; i < func_00295E40(&m_unk160); i++) {
            n += func_00127968(&s, D_002A0B40, func_00295E48(&m_unk160, i));
        }
    }
    return n;
}

s32 CMapSndRes::Load(const char *text) {
    const char *p;
    s32 i;
    if (*Func24AF10((void *)text, D_002A0B38) != 0) {
        func_0024B298(text, D_002A0B44, &m_unk0, 0x80);
    }
    func_00127AB0(text, D_002A0B3C, &m_unk10);
    m_unk160.Func295E20(func_0024AF90(text, D_002A0B40));
    p = text;
    for (i = 0; i < func_00295E40(&m_unk160); i++) {
        p = func_00127AB0(p, D_002A0B40, func_00295E48(&m_unk160, i));
    }
    ((CMapSndResSub127C10 *)&m_unk10)->Init();
    for (i = 0; i < func_00295E40(&m_unk160); i++) {
        ((CMapSndResSub127C10 *)func_00295E48(&m_unk160, i))->Init();
    }
    return 1;
}

int CMapSndRes::SaveFile(const char *name) {
    return SaveWith(&CMapSndRes::Save, name);
}

int CMapSndRes::LoadFile(const char *name) {
    return LoadWith(&CMapSndRes::Load, name);
}

INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4BA8);

void CMapSndRes::CallFunc127928() {
    Func127928();
}

int CMapSndRes::SaveWith(s32 (CMapSndRes::*fn)(char *), const char *name) {
    int ok = 0;
    char *buf = 0;
    s32 n = (this->*fn)(0);
    if (n >= 0) {
        buf = (char *)func_0024A3D8(n);
        if (buf) {
            if ((this->*fn)(buf) == n) ok = func_002301B0(name, buf, n) == n;
        }
    }
    if (buf) D_002B91B0(buf);
    return ok;
}

int CMapSndRes::LoadWith(s32 (CMapSndRes::*fn)(const char *), const char *name) {
    int ok = 0;
    char *buf = (char *)Func24A4C0(name);
    if (buf) {
        ok = (this->*fn)(buf) != 0;
        if (buf) D_002B91B0(buf);
    }
    return ok;
}
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4BE0);
INCLUDE_RODATA("asm/nonmatchings/CMapSndRes", D_002D4C28);
