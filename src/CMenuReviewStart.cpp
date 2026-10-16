#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

// The window items (CStatusItem, CStatusWin.cpp; named after Func1A4298 there).
class CUnk1A4298 {
public:
    int Func1A4298();
    f32 GetUnk34() { return m_unk34; }

    u8 pad0[0x34];
    f32 m_unk34;              // 0x34
};
class CUnk237E90 {
public:
    int Func237E90(int v);
};
#include "CMenuMgrSub1B6418.h"
extern CMenuMgrSub1B6418 *D_002A5538;
extern "C" int func_001B66E8(void *p);
void *Func237570(int size);
void Func237A88(void *p, int n);
void *Func237C30(void *p);
void Func238158(void *p, int v);
void Func225088();
int Func2250C0();
void Func225240(int v);

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuReviewStart.
class CMenuReviewStart : public CMenuProcess {
public:
    CMenuReviewStart();
    virtual ~CMenuReviewStart();
    virtual s32 Update();
    virtual s32 Draw();

    CUnk1A4298 *m_unk58;      // 0x58
    CUnk1A4298 *m_unk5C;      // 0x5C
    s32 m_unk60;              // 0x60
    s32 m_unk64;              // 0x64
};

//@sym __builtin_new 0x245648
class CMenuContinue {
public:
    CMenuContinue() throw();

    u8 pad0[0x60];
};

#include "state.h"
class CVec4 {
public:
    f32 x, y, z, w;
};
class CStatusItem {
public:
    void Func1A3378();
    void Func1A3628();
    void Start();
    void Func1A40C8();
    int Select(s32 i);
    const char *GetUnkE4(s32 i);
    void SetText(s32 i, const char *s);
    int GetMappedUnkC0(f32 *x, f32 *y, s32 n);
    void SetMappedColor(s32 n, const CVec4 *v);
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
#include "CFlagWork.h"
extern CFlagWork *D_002A5358;
extern CFlagWork *D_002A4B60;
extern "C" int sprintf(char *buf, const char *fmt, ...);
inline void SetVar(CStateMachine *sm, s32 k, s32 v) { sm->Var(k) = v; }
#define W(p) ((CStatusItem *)(p))
// @decl-end

CMenuReviewStart::CMenuReviewStart() {
    m_unk58 = 0;
    m_unk5C = 0;
}

CMenuReviewStart::~CMenuReviewStart() {
}

s32 CMenuReviewStart::Update() {
    CStateMachine *sm = (CStateMachine *)this;
    s32 a, b, c;
    char buf[0x200];
    f32 x, y;
    CVec4 col0, col1;
    f32 *c0 = &col0.x;
    f32 *c1 = &col1.x;
    s32 i;
    s32 done;
    for (i = 0; i < 4; i++) {
        s32 o = i * 4;
        *(f32 *)((u8 *)c0 + o) = D_002A4B60->Func1091B0(i + 0xB);
        *(f32 *)((u8 *)c1 + o) = D_002A4B60->Func1091B0(i + 0xF);
    }
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
    case -1: {
        m_unk58 = (CUnk1A4298 *)D_002A5408->Find("reviewstart");
        if (!m_unk58) return Func235DE0("*** Can't Get %s Window\n", "reviewstart");
        W(m_unk58)->Func1A3378();
        m_unk5C = (CUnk1A4298 *)D_002A5408->Find("reviewask");
        if (!m_unk58) return Func235DE0("*** Can't Get %s Window\n", "reviewask");
        W(m_unk5C)->Func1A3378();
        D_002A5538->SetUnkE0(1);
        sprintf(buf, W(m_unk58)->GetUnkE4(6), D_002A5358->GetStr(0x242));
        W(m_unk58)->SetText(6, buf);
        W(m_unk58)->Func1A3628();
        W(m_unk58)->Select(-1);
    }
        while (W(m_unk58)->m_state != 2) {
            sm->m_state = -0xAF; done = 1; goto loop;
    case -0xAF:;
        }
        W(m_unk5C)->Func1A3628();
        m_unk64 = m_unk50 < 0 ? 0 : m_unk50;
        W(m_unk5C)->Select(m_unk64);
        sm->Push();
        SetVar(sm, 0, -0xBC);
        goto sub;
    case -0xBC:
    case -0xC0:
        if (W(m_unk5C)->m_state == 2) {
            sm->m_state = -0xC5; done = 1; goto loop;
        }
        sm->m_state = -0xC0; done = 1; goto loop;
    case -0xC5:
        m_unk60 = 0;
        do {
    case -0xE3:
            if ((c & 0x2000) && m_unk64 == 0) {
                D_002A5468->V14(0);
                m_unk64 = 1;
                sm->Push();
                SetVar(sm, 0, -0xCE);
                goto sub;
            }
            if ((c & 0x8000) && m_unk64 == 1) {
                D_002A5468->V14(0);
                m_unk64 = 0;
                sm->Push();
                SetVar(sm, 0, -0xD4);
                goto sub;
            }
            if (a & 0x20) {
                D_002A5468->V14(1);
                m_unk4C = m_unk64;
                goto s4;
            }
            if (a & 0x40) {
                D_002A5468->V14(2);
                m_unk4C = 1;
                goto s4;
            }
    case -0xCE:
    case -0xD4:
            sm->m_state = -0xE3; done = 1; goto loop;
        } while (0);
    s4:
        m_state = 4;
        W(m_unk58)->Start();
        W(m_unk5C)->Start();
        do {
    case -0xF6:
            if (W(m_unk58)->m_state != 0) {
                sm->m_state = -0xF6; done = 1; goto loop;
            }
            if (W(m_unk5C)->m_state == 0) {
                m_state = 5;
                sm->m_state = -0x104;
                goto e104;
            }
            sm->m_state = -0xF6; done = 1; goto loop;
        } while (0);
    sub:
        W(m_unk5C)->Select(m_unk64);
        W(m_unk5C)->SetMappedColor(m_unk64, (CVec4 *)c0);
        W(m_unk5C)->SetMappedColor(1 - m_unk64, (CVec4 *)c1);
        W(m_unk5C)->GetMappedUnkC0(&x, &y, m_unk64);
        D_002A5538->Move1B6488(x, y);
        sm->m_state = sm->Get();
        sm->Pop();
        goto loop;
    case -0x104:
    e104:
        done = 1; goto loop;
    }
out:
    W(m_unk58)->Func1A40C8();
    W(m_unk5C)->Func1A40C8();
    D_002A5538->Update1B6570();
end:;
}

s32 CMenuReviewStart::Draw() {
    u8 *p = (u8 *)Func237570(0x40);
    Func237A88(p, 4);
    Func238158(Func237C30(p + 0x30), 1);
    ((CUnk237E90 *)(p + 0x10))->Func237E90(m_unk58->Func1A4298());
    ((CUnk237E90 *)(p + 0x10))->Func237E90(m_unk5C->Func1A4298());
    D_002A5538->SetUnk4C(m_unk5C->GetUnk34());
    ((CUnk237E90 *)(p + 0x20))->Func237E90(func_001B66E8(D_002A5538));
    Func225088();
    Func225240((int)p);
    return Func2250C0();
}

CMenuContinue *CreateCMenuContinue() {
    return new CMenuContinue;
}
