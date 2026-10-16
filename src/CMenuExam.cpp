#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuExam.
class CMenuExam : public CMenuProcess {
public:
    CMenuExam();
    virtual ~CMenuExam();
    virtual void Update();
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
#include "CMenuRecordWin.h"
class CUnk237E90 {
public:
    int Func237E90(int v);
};
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

#include "state.h"
class CStatusItem {
public:
    void Func1A3378();
    void Func1A3628();
    void Start();
    void Func1A40C8();
    void Select(s32 i);
    const char *GetUnkE4(s32 i);
    void SetText(s32 i, const char *s);
    void SetUnkF0(s32 i, s32 v);
    u8 pad0[0x20];
    s32 m_state;              // 0x20
};
class CStatusWinSub1A0A10 {
public:
    CStatusItem *Find(const char *name);
};
extern CStatusWinSub1A0A10 *D_002A5408;
class CSndIf {
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual int V7(s32 *a, s32 *b, s32 *c);
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14(s32 v);
};
extern CSndIf *D_002A5468;
extern CFlagWork *D_002A4B60;
#include "CMenuMgrSub1B6418.h"
extern CMenuMgrSub1B6418 *D_002A5538;
extern "C" int sprintf(char *buf, const char *fmt, ...);
void Func185AA0(char *dst, s32 k, s32 a, s32 b, s32 c, s32 d, s32 e);
inline void SetVar(CStateMachine *sm, s32 k, s32 v) { sm->Var(k) = v; }
inline void Inc(CStateMachine *sm) { SetVar(sm, 0, sm->Get(0) + 1); }
#define W ((CStatusItem *)m_unk58)
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
void CMenuExam::Update() {
    CStateMachine *sm = (CStateMachine *)this;
    s32 a, b, c;
    char buf[0x100];
    char tmp[0x100];
    s32 done;
    D_002A5468->V7(&a, &b, &c);
    if (m_state == 6) {
        m_state = 5;
        goto end;
    }
    done = 0;
loop:
    if (done) goto out;
    {
        u32 fl = sm->m_flags;
        if ((fl >> 7) & 1) goto out;
    }
    switch (sm->m_state) {
    case -1:
        m_unk58 = (s32)D_002A5408->Find("exam");
        if (!m_unk58) { Func235DE0("*** Can't Get %s Window\n", "exam"); return; }
        W->Func1A3378();
        W->Select(-1);
        D_002A5538->SetUnkE0(0);
        switch (D_002A5358->Func1091B0(0x2A6)) {
        case 0:
            W->SetUnkF0(3, 1);
            W->SetUnkF0(4, 0);
            W->SetUnkF0(5, 1);
            W->SetUnkF0(6, 0);
            W->SetUnkF0(7, 0);
            break;
        case 1:
            W->SetUnkF0(3, 0);
            W->SetUnkF0(4, 1);
            W->SetUnkF0(5, 0);
            W->SetUnkF0(6, 1);
            W->SetUnkF0(7, 0);
            Func185AA0(tmp, D_002A5358->Func1091B0(4), -1, -1, -1, -1, -1);
            sprintf(buf, W->GetUnkE4(6), tmp);
            W->SetText(6, buf);
            break;
        case 2:
            W->SetUnkF0(3, 0);
            W->SetUnkF0(4, 1);
            W->SetUnkF0(5, 0);
            W->SetUnkF0(6, 0);
            W->SetUnkF0(7, 1);
            Func185AA0(tmp, D_002A5358->Func1091B0(4), -1, -1, -1, -1, -1);
            sprintf(buf, W->GetUnkE4(7), tmp);
            W->SetText(7, buf);
            break;
        }
        W->Func1A3628();
    case -0xBB:
        if (W->m_state == 2) {
            sm->m_state = -0xC0; done = 1; goto loop;
        }
        sm->m_state = -0xBB; done = 1; goto loop;
    case -0xC0:
        sm->Push(4);
        SetVar(sm, 1, D_002A4B60->Func1091B0(0x57));
        SetVar(sm, 0, 0);
        {
            f32 z = 0.0f;
            SetVar(sm, 2, *(s32 *)&z);
        }
        {
            f32 z = 0.0f;
            SetVar(sm, 3, *(s32 *)&z);
        }
        for (; sm->Get(0) < sm->Get(1); Inc(sm)) {
            if (!(a & 0x60)) {
                sm->m_state = -0xCB; done = 1; goto loop;
            }
            D_002A5468->V14(3);
            sm->Pop(4);
            goto s4;
    case -0xCB:;
        }
        sm->Pop(4);
    s4:
        m_state = 4;
        W->Start();
        while (W->m_state != 0) {
            sm->m_state = -0xD6; done = 1; goto loop;
    case -0xD6:;
        }
        m_state = 5;
        sm->m_state = -0xDC;
    case -0xDC:
        done = 1; goto loop;
    }
out:
    if (m_unk58) W->Func1A40C8();
end:;
}

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
