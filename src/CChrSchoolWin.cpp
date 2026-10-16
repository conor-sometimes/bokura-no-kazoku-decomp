#pragma interface
#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CChrSchoolWinSub186E80 {
public:
    void SetUnk60(f32 x, f32 y);

    u8 pad0[0x60];
    f32 m_unk60;              // 0x60
    f32 m_unk64;              // 0x64
};

class CUnk1A4298 {
public:
    int Func1A4298();
    u8 pad0[0x34];
    f32 m_unk34;              // 0x34
};
class CUnk237E90 {
public:
    int Func237E90(int v);
};
extern "C" u8 *func_00237570(s32 v);
extern "C" void func_00237A88(void *p, s32 v);
extern "C" void *func_00237C30(void *p);
extern "C" int func_00238158(void *p, s32 v);
void Func225088();
int Func2250C0();
void Func225240(s32 v);
class CChrSchoolWinObj {
public:
    void Func186FA8();
    u8 pad0[0x48];
    CUnk1A4298 *m_unk48;      // 0x48
    u8 pad4C[0x10];
    s32 m_unk5C;              // 0x5C
};
#include "CFlagWork.h"
int Func235DE0(const char *fmt, ...) throw();
extern "C" int sprintf(char *buf, const char *fmt, ...);
extern "C" const char *func_001A36B0(void *w, s32 v);
class CStatusItem {
public:
    void Func1A3378();
};
#include "CMenuRecordWin.h"
#include "CStatusWinSub1A40B8.h"
#include "CStatusWin.h"
extern CStatusWin *D_002A5408;
extern CFlagWork *D_002A5358;
extern char D_002DAF80[], D_002DAF88[], D_002DAF90[];
struct CSchoolRec {
    u8 pad0[0x8];
    const char *m_name;       // 0x8
};
class CSchoolDB {
public:
    virtual void Vf0();
    virtual void Vf1();
    virtual void Vf2();
    virtual void Vf3();
    virtual void Vf4();
    virtual void Vf5();
    virtual void Vf6();
    virtual void Vf7();
    virtual void Vf8();
    virtual void Vf9();
    virtual void Vf10();
    virtual void Vf11();
    virtual void Vf12();
    virtual void Vf13();
    virtual void Vf14();
    virtual void Vf15();
    virtual void Vf16();
    virtual void Vf17();
    virtual void Vf18();
    virtual void Vf19();
    virtual void Vf20();
    virtual void Vf21();
    virtual void Vf22();
    virtual void Vf23();
    virtual void Vf24();
    virtual void Vf25();
    virtual void Vf26();
    virtual void Vf27();
    virtual void Vf28();
    virtual void Vf29();
    virtual void Vf30();
    virtual void Vf31();
    virtual void Vf32();
    virtual void Vf33();
    virtual void Vf34();
    virtual void Vf35();
    virtual void Vf36();
    virtual void Vf37();
    virtual void Vf38();
    virtual void Vf39();
    virtual CSchoolRec *Find(s32 id);
};
extern CSchoolDB *D_002A2988;
// Status window base (CStatusBase unit; constructor through config/aliases.ld). All seven
// virtuals are pure; the first is declared non-pure here so this unit emits no vtable for it.
class CStatusBase {
public:
    CStatusBase();
    virtual void Vf0();
    virtual void Vf1() = 0;
    virtual void Vf2() = 0;
    virtual void Vf3() = 0;
    virtual void Vf4() = 0;
    virtual void Vf5() = 0;
    virtual void Vf6() = 0;

    s16 m_unk0;               // 0x00
    s16 m_unk2;               // 0x02
    s32 m_unk4;               // 0x04
    u8 pad8[0x40];
    CStatusItem *m_item;      // 0x48
    s32 m_state;              // 0x4C
    u32 m_unk50;              // 0x50
    s32 m_unk54;              // 0x54
    // vptr 0x58
};
// Vtable _vt$13CChrSchoolWin (asm); slot 0 (0x186E90) is the key method.
class CChrSchoolWin : public CStatusBase {
public:
    CChrSchoolWin(s32 load);
    virtual void Vf0();
    virtual void Vf1();
    virtual void Vf2();
    virtual void Vf3();
    virtual void Vf4();
    virtual void Vf5();
    virtual void Vf6();

    s32 m_unk5C;              // 0x5C
    f32 m_unk60;              // 0x60
    f32 m_unk64;              // 0x64
};

// From CMenuExam.cpp (functions 0x185648-0x186DF0 moved here: their literals follow 9CMenuExam)
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
struct CExamRec { s32 m0; const char *m_name; };
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
    virtual struct CExamRec *Get40(s32 id);
    virtual struct CExamRec *Get41(s32 id);
    virtual void V42();
    virtual void V43();
    virtual void V44();
    virtual void V45();
    virtual CExamNames *GetNames(s32 b);
    virtual struct CExamNames *GetNamesA(s32 b, s32 i);
    virtual struct CExamNames *GetNamesB(s32 b, s32 i);
};
extern CExamDB *D_002A2988_exam asm("D_002A2988");   // the same table as CSchoolDB, as the exam code sees it

#include "CMenuRecordWin.h"
u8 *Func237570(int n);
void Func237A88(void *p, int v);
void *Func237C30(void *p);
int Func238158(void *p, int v);
void Func225240(int v);
#include "CMenuMgrSub1B4768.h"
extern CMenuMgrSub1B4768 *D_002A5530;
#include "CMenuLoadMemorialSub17B3A0.h"
extern CMenuLoadMemorialSub17B3A0 *D_002A3AF8;

extern char D_002DAEB8[];

struct CGsRect { s32 x0, y0, x1, y1; };
// @decl-end
INCLUDE_RODATA("asm/nonmatchings/CChrSchoolWin", D_002DAD98);
INCLUDE_RODATA("asm/nonmatchings/CChrSchoolWin", D_002DADA0);
INCLUDE_RODATA("asm/nonmatchings/CChrSchoolWin", D_002DADC0);
INCLUDE_RODATA("asm/nonmatchings/CChrSchoolWin", D_002DADE0);
INCLUDE_RODATA("asm/nonmatchings/CChrSchoolWin", D_002DAE00);
INCLUDE_RODATA("asm/nonmatchings/CChrSchoolWin", D_002DAE08);
INCLUDE_RODATA("asm/nonmatchings/CChrSchoolWin", D_002DAE28);
INCLUDE_RODATA("asm/nonmatchings/CChrSchoolWin", D_002DAE30);
INCLUDE_RODATA("asm/nonmatchings/CChrSchoolWin", D_002DAE58);
INCLUDE_RODATA("asm/nonmatchings/CChrSchoolWin", D_002DAE60);
INCLUDE_RODATA("asm/nonmatchings/CChrSchoolWin", D_002DAE68);
INCLUDE_RODATA("asm/nonmatchings/CChrSchoolWin", jtbl_002DAE90);
INCLUDE_RODATA("asm/nonmatchings/CChrSchoolWin", D_002DAEB8);
INCLUDE_RODATA("asm/nonmatchings/CChrSchoolWin", D_002DAEE0);
INCLUDE_RODATA("asm/nonmatchings/CChrSchoolWin", D_002DAF08);
INCLUDE_RODATA("asm/nonmatchings/CChrSchoolWin", D_002DAF30);
INCLUDE_RODATA("asm/nonmatchings/CChrSchoolWin", D_002DAF58);
INCLUDE_RODATA("asm/nonmatchings/CChrSchoolWin", D_002DAF70);

INCLUDE_ASM("asm/nonmatchings/CChrSchoolWin", func_00185648);

void Func185810() {
    s32 i;
    for (i = 0; i < D_002A26E4->Func1091B0(0x27); i++) {
        func_00185648(i);
    }
}

extern "C" void func_00185868(s32 i, s32 a, s32 b) {
    s32 j;
    if (i < 0 || D_002A26E4->Func1091B0(0x27) - 1 < i) return (void)Func235DE0(D_002DADA0, i);
    if ((u32)a >= 6) return (void)Func235DE0(D_002DADC0, a);
    if ((u32)b >= 6) return (void)Func235DE0(D_002DADE0, b);
    for (j = 0; D_002A3CC8[j].m_dst >= 0; j++) {
        D_002A5358->Func108FF0(D_002A3CC8[j].m_dst + i, D_002A4638[a]->Func1091B0(D_002A3CC8[j].m_src + i));
    }
    for (j = 0; D_002A3DB0[j].m_dst >= 0; j++) {
        D_002A5358->Func108FF0(D_002A3DB0[j].m_dst + i, D_002A4638[b]->Func1091B0(D_002A3DB0[j].m_src + i));
    }
}

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

INCLUDE_ASM("asm/nonmatchings/CChrSchoolWin", func_00185BD0);

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
    s32 i = D_002A2988_exam->Find(a);
    CExamNames *t = D_002A2988_exam->GetNames(b);
    if (t && t->s[i][0]) {
        strcpy(dst, t->s[i]);
    } else {
        CExamNames *ta = D_002A2988_exam->GetNamesA(b, i);
        CExamNames *tb = D_002A2988_exam->GetNamesB(b, i);
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

extern "C" s32 func_001863F0(s32 a, s32 b, s32 c) {
    s32 i = a - 16;
    if ((u32)i >= 9) {
        Func235DE0(D_002DAEE0, a);
        return 0;
    }
    if ((u32)b >= 5) {
        Func235DE0(D_002DAF08, b);
        return 0;
    }
    if ((u32)c >= 10) {
        Func235DE0(D_002DAF30, c);
        return 0;
    }
    return D_002A41A0[D_002A4268[i][b]][c];
}

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

INCLUDE_ASM("asm/nonmatchings/CChrSchoolWin", func_001865B8);

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

INCLUDE_ASM("asm/nonmatchings/CChrSchoolWin", func_00186730);

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

INCLUDE_ASM("asm/nonmatchings/CChrSchoolWin", func_00186AC8);

INCLUDE_RODATA("asm/nonmatchings/CChrSchoolWin", D_002DAF80);
INCLUDE_RODATA("asm/nonmatchings/CChrSchoolWin", D_002DAF88);
INCLUDE_RODATA("asm/nonmatchings/CChrSchoolWin", D_002DAF90);

CChrSchoolWin::CChrSchoolWin(s32 load) {
    m_item = D_002A5408->Func1A0CF0(D_002DAF80);
    m_item->Func1A3378();
    m_unk5C = 0;
    m_unk60 = m_unk64 = 0.0f;
    if (load) ((CMenuRecordWin *)m_item)->Func1A39A8(&m_unk60, (s32 *)&m_unk64, 4);
    ((CStatusWinSub1A40B8 *)m_item)->SetUnk80(m_unk60, m_unk64);
    return;
}

void CChrSchoolWinSub186E80::SetUnk60(f32 x, f32 y) {
    m_unk60 = x;
    m_unk64 = y;
}

// Key method: #pragma interface (top) keeps this unit from emitting the vtables (asm data).
void CChrSchoolWin::Vf0() {
    Vf1();
}

void CChrSchoolWin::Vf1() {
    char buf[0x100];
    s32 v = D_002A5358->Func1091B0(m_unk50 + 0xD6);
    buf[0] = D_002DAF88[0];
    m_unk5C = v;
    if (v) {
        CSchoolRec *r = D_002A2988->Find(m_unk5C);
        if (!r) {
            Func235DE0(D_002DAF90, m_unk5C);
            m_unk5C = 0;
        } else {
            sprintf(buf, func_001A36B0(m_item, 3), r->m_name);
        }
    }
    ((CMenuRecordWin *)m_item)->Func1A3740(3, buf);
}

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_00186F88() {
}

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_00186F90() {
}

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_00186F98() {
}

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_00186FA0() {
}

void CChrSchoolWinObj::Func186FA8() {
    char buf[256];
    u8 *p = func_00237570(0x60);
    func_00237A88(p, 6);
    func_00238158(func_00237C30(p + 0x50), 1);
    if (m_unk5C) {
        ((CUnk237E90 *)(p + 0x10))->Func237E90(m_unk48->Func1A4298());
    }
    Func225088();
    Func225240((s32)p);
    Func2250C0();
}
INCLUDE_RODATA("asm/nonmatchings/CChrSchoolWin", D_002DAFC0);
