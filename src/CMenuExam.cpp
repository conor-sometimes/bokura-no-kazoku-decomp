#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuExam.
class CMenuExam : public CMenuProcess {
public:
    CMenuExam();
    virtual ~CMenuExam();
    virtual s32 Update();
    virtual s32 Draw();

    s32 m_unk58;              // 0x58
};

#include "CFlagWork.h"
extern CFlagWork *D_002A5358;
extern "C" void func_00185648(s32 i);
extern "C" void func_00185868(s32 i, s32 a, s32 b);
s32 Func145738(s32 a, s32 b);
// Text table reader (0x10BF88 constructor, 0x256260 lookup; library code).
struct CTextBuf {
    s32 m0;
    u8 pad4[0x8C];
};
extern "C" CTextBuf *func_0010BF88(CTextBuf *p);
extern "C" const char *func_00256260(CTextBuf *p, s32 id);
extern "C" char *strcpy(char *dst, const char *src);

extern char D_002DAEE0[], D_002DAF08[], D_002DAF30[], D_002DADA0[], D_002DADC0[], D_002DADE0[];
extern s32 D_002A4268[][5];
extern s32 D_002A41A0[][10];
struct CExamFlagDef {
    s32 m_dst;
    s32 m_src;
};
extern CExamFlagDef D_002A3CC8[];
extern CExamFlagDef D_002A3DB0[];
extern CFlagWork *D_002A4638[];
extern "C" char *func_0024BA08(char *buf, s32 v);
extern "C" int sprintf(char *buf, const char *fmt, ...);

void *Func248E48(const char *name);
extern char D_002DAF58[], D_002DAF70[];
extern "C" int func_00253048(void *p, s32 *a, s32 *b, s32 *c, s32 *d, s32 *e, s32 *f, s32 *g, s32 *h);
extern "C" void func_0023C048(s32 a, s32 b, s32 c);
struct CExamTex {
    void *m_data;             // 0x0
    s32 m_unk4;               // 0x4
    s32 m_unk8;               // 0x8
    s32 m_unkC;               // 0xC
    s32 m_unk10;              // 0x10
    s32 m_unk14;              // 0x14
    s32 m_unk18;              // 0x18
    s32 m_unk1C;              // 0x1C
    s32 m_unk20;              // 0x20
};

struct CExamNames { s32 n; char *s[1]; };
extern char D_002DAE00[], D_002DAE58[], D_002DAE60[];
class CExamDB {
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual s32 Find(s32 a);
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void V34();
    virtual void V35();
    virtual void V36();
    virtual void V37();
    virtual void V38();
    virtual void V39();
    virtual void V40();
    virtual void V41();
    virtual void V42();
    virtual void V43();
    virtual void V44();
    virtual void V45();
    virtual CExamNames *GetNames(s32 b);
    virtual struct CExamNames *GetNamesA(s32 b, s32 i);
    virtual struct CExamNames *GetNamesB(s32 b, s32 i);
};
extern CExamDB *D_002A2988;

class CUnk1A4298 {
public:
    int Func1A4298();
    u8 pad0[0x34];
    f32 m_unk34;              // 0x34
};
class CMenuRecordWin {
public:
    void Func1A39A8(f32 *v, s32 *n, s32 k);
};
class CUnk237E90 {
public:
    int Func237E90(int v);
};
u8 *Func237570(int n);
void Func237A88(void *p, int v);
void *Func237C30(void *p);
int Func238158(void *p, int v);
void Func225240(int v);
class CMenuMgrSub1B4768 {
public:
    void Reset1B4D28();
};
extern CMenuMgrSub1B4768 *D_002A5530;
class CMenuLoadMemorialSub17B3A0 {
public:
    void CallFunc17B3E8();
    int Func17B4A0();
    void SetUnk40(f32 x, f32 y, s32 v);
    void SetUnk20(f32 x, f32 y);
    void SetUnk10(f32 x, f32 y);
    void SetUnk30(f32 x, f32 y, f32 z, f32 w);
    s32 Draw17B4D8(s32 k);
};
extern CMenuLoadMemorialSub17B3A0 *D_002A3AF8;

extern char D_002DAEB8[];

struct CGsRect { s32 x0, y0, x1, y1; };
// @decl-end

CMenuExam::CMenuExam() {
    m_unk58 = 0;
}

CMenuExam::~CMenuExam() {
}

INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DAB38);
INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DAB40);
INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DAB60);
INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DAB88);
INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DABB8);
INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DABC0);
INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DABC8);
INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DABD0);
INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DAC00);
INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DAC10);
INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DAC20);
INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DAC30);
INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DAC50);
INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DAC90);
INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DACB8);
INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DACE0);
INCLUDE_ASM("asm/nonmatchings/CMenuExam", Update__9CMenuExam);
INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DAD28);
INCLUDE_RODATA("asm/nonmatchings/CMenuExam", D_002DAD48);

s32 CMenuExam::Draw() {
    f32 v[2];
    if (m_unk58 == 0) {
        Func225088();
        Func2250C0();
    } else {
        u8 *p = Func237570(0x40);
        Func237A88(p, 4);
        CUnk237E90 *q = (CUnk237E90 *)(p + 0x20);
        Func238158(Func237C30(p + 0x30), 1);
        CUnk1A4298 *w = (CUnk1A4298 *)m_unk58;
        ((CUnk237E90 *)(p + 0x10))->Func237E90(w->Func1A4298());
        D_002A5530->Reset1B4D28();
        D_002A3AF8->CallFunc17B3E8();
        q->Func237E90(D_002A3AF8->Func17B4A0());
        D_002A3AF8->SetUnk40(3.0f, 1.0f, 1);
        D_002A3AF8->SetUnk20(0.65f, 0.65f);
        ((CMenuRecordWin *)m_unk58)->Func1A39A8(&v[0], (s32 *)&v[1], 8);
        D_002A3AF8->SetUnk10(v[0], v[1]);
        D_002A3AF8->SetUnk30(1.0f, 1.0f, 1.0f, ((CUnk1A4298 *)m_unk58)->m_unk34);
        q->Func237E90(D_002A3AF8->Draw17B4D8(D_002A5358->Func1091B0(4)));
        Func225088();
        Func225240((s32)p);
        Func2250C0();
    }
}

s32 Func1855B0(s32 *out) {
    s32 i;
    for (i = 5; i >= 0; i--) {
        out[i] = -1;
    }
    for (i = 0; i < 6; i++) {
        s32 v = D_002A5358->Func1091B0(i + 4);
        if (v < 0) {
            break;
        }
        out[i] = v;
    }
    return i;
}

INCLUDE_ASM("asm/nonmatchings/CMenuExam", func_00185648);

void Func185810() {
    s32 i;
    for (i = 0; i < D_002A26E4->Func1091B0(0x27); i++) {
        func_00185648(i);
    }
}

INCLUDE_ASM("asm/nonmatchings/CMenuExam", func_00185868);

void Func185A28(s32 a, s32 b) {
    s32 i;
    for (i = 0; i < D_002A26E4->Func1091B0(0x27); i++) {
        func_00185868(i, a, b);
    }
}

void Func185AA0(char *dst, s32 k, s32 a, s32 b, s32 c, s32 d, s32 e) {
    if (!dst) return;
    if (a >= 0 && b >= 0 && c >= 0 && d >= 0 && e >= 0) {
        s32 v = D_002A26E4->Get1458F0(k, a, b, c, d, e);
        sprintf(dst, D_002DAE00, v, D_002A26E4->GetStr(k + 0x2E));
    } else {
        s32 v = D_002A26E4->Get1458F0(k, -1, -1, -1, -1, -1);
        sprintf(dst, D_002DAE00, v, D_002A26E4->GetStr(k + 0x2E));
    }
}

INCLUDE_ASM("asm/nonmatchings/CMenuExam", func_00185BD0);

void Func185E80(char *dst, s32 k) {
    CTextBuf buf;
    s32 a;
    func_0010BF88(&buf);
    buf.m0 = 0;
    D_002A26E4->Func1091B0(0x27);
    a = D_002A26E4->Func1091B0(k + 0x3A);
    strcpy(dst, func_00256260(&buf, a * 4 + D_002A26E4->Func1091B0(k + 0x40) + 0xB4));
}

void Func185F18(char *dst, s32 k, s32 flag) {
    CTextBuf buf;
    char num[0x100];
    s32 n;
    func_0010BF88(&buf);
    buf.m0 = 0;
    n = D_002A26E4->Func1091B0(0x27);
    if (flag && k == n - 1 && n != 1) {
        strcpy(dst, func_00256260(&buf, 0xBD));
    } else {
        const char *fmt = func_00256260(&buf, 0xBC);
        sprintf(dst, fmt, func_0024BA08(num, k + 1));
    }
}

s32 Func185FD8(s32 k) {
    s32 v = D_002A5358->Func1091B0(k + 0x2E);
    s32 a = D_002A5358->Func1091B0(k + 0x34);
    s32 b = D_002A26E4->Func1091B0(k + 0xE8);
    s32 c = D_002A26E4->Func1091B0(k + 0xF4);
    if ((u32)v < 4) return 0;
    if ((u32)(v - 4) < 3) return 1;
    if ((u32)(v - 7) < 6) return 2;
    if ((u32)(v - 13) < 3) return 3;
    if ((u32)(v - 16) < 3) return 4;
    if (a == 9 && b == 1 && c > 0) return 8;
    if (a == 9 && b == 1 && c == 0) return 7;
    if (a == 9 && b == 0 && c == 0) return 6;
    if (a != 9 && b == 0 && c == 0) return 5;
    if (a != 9 && b == 0 && c > 0) return 9;
    if (a != 9 && b == 1 && c > 0) return 10;
    if (a == 9 && b == 0 && c > 0) return 11;
    Func235DE0(D_002DAEB8, v, a, b, c);
    return 0;
}

void Func186198(char *dst, s32 a, s32 b) {
    CTextBuf buf;
    func_0010BF88(&buf);
    buf.m0 = 0;
    s32 i = D_002A2988->Find(a);
    CExamNames *t = D_002A2988->GetNames(b);
    if (t && t->s[i][0]) {
        strcpy(dst, t->s[i]);
    } else {
        CExamNames *ta = D_002A2988->GetNamesA(b, i);
        CExamNames *tb = D_002A2988->GetNamesB(b, i);
        sprintf(dst, D_002DAE60, ta->s[i], func_00256260(&buf, 0xF3), tb->s[i]);
    }
}

void Func1862F8(char *dst, s32 k) {
    CTextBuf buf;
    func_0010BF88(&buf);
    buf.m0 = 0;
    strcpy(dst, func_00256260(&buf, Func145738(k, 1) + 0xAE));
}

void Func186358(char *dst, s32 a, s32 b) {
    CTextBuf buf;
    func_0010BF88(&buf);
    buf.m0 = 0;
    if (a) {
        if (b == 1) {
            strcpy(dst, func_00256260(&buf, 0xDC));
        } else {
            strcpy(dst, func_00256260(&buf, 0xDD));
        }
    } else {
        strcpy(dst, func_00256260(&buf, 0xDE));
    }
}

INCLUDE_ASM("asm/nonmatchings/CMenuExam", func_001863F0);

void Func1864A8(char *dst) {
    CTextBuf buf;
    char num[0x100];
    func_0010BF88(&buf);
    buf.m0 = 0;
    if (!dst) return;
    if (D_002A26E4->Vf2991E8() == 0) {
        sprintf(dst, D_002DAE58, func_00256260(&buf, 0xAA));
    } else if (D_002A26E4->Vf2991E8() == 0x23) {
        sprintf(dst, D_002DAE58, func_00256260(&buf, 0xAB));
    } else {
        const char *s = func_0024BA08(num, D_002A26E4->Vf2991E8() + 1);
        sprintf(dst, D_002DAE00, s, func_00256260(&buf, 0xB1));
    }
}

INCLUDE_ASM("asm/nonmatchings/CMenuExam", func_001865B8);

void Func186690(s32 *out, f32 *in) {
    out[0] = (s32)(in[0] * 16.0f) + 0x6C00;
    out[1] = (s32)(in[1] * 16.0f) + 0x7200;
}

void Func1866D0(CGsRect *r, f32 x, f32 y, f32 w, f32 h) {
    r->x0 = (s32)(x * 16.0f) + 0x6C00;
    r->y0 = (s32)(y * 16.0f) + 0x7200;
    r->x1 = r->x0 + (s32)(w * 16.0f);
    r->y1 = r->y0 + (s32)(h * 16.0f);
}

INCLUDE_ASM("asm/nonmatchings/CMenuExam", func_00186730);

s32 LoadExamTex(CExamTex *t, const char *name) {
    if (!t) return 0;
    void *d = Func248E48(name);
    if (!d) {
        Func235DE0(D_002DAF58, name);
        return 0;
    }
    t->m_data = d;
    func_00253048(d, &t->m_unk4, &t->m_unk8, &t->m_unkC, &t->m_unk10, &t->m_unk14, &t->m_unk18, &t->m_unk1C, &t->m_unk20);
    if (t->m_unk1C > 0x10) func_0023C048(t->m_unk1C * t->m_unk20, t->m_unk14, t->m_unk14);
    Func235DE0(D_002DAF70, name, t->m_unkC, t->m_unk10);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/CMenuExam", func_00186AC8);
