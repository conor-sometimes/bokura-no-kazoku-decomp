#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

class CUnk1A4298 {
public:
    int Func1A4298();
};

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuNews.
class CMenuNews : public CMenuProcess {
public:
    CMenuNews();
    virtual ~CMenuNews();
    virtual s32 Update();
    virtual s32 Draw();

    CUnk1A4298 *m_unk58;      // 0x58
};

class CMenuExGetMoney {
public:
    CMenuExGetMoney() throw();

    u8 pad0[0x78];
};

#include "CFlagWork.h"
extern CFlagWork *D_002A5358;
inline f32 Clamp01(f32 v) { return (v < 1.0f ? v : 1.0f) < 0.0f ? 0.0f : (v < 1.0f ? v : 1.0f); }
// CMenuExGetMoney's unit starts here (its text starts before its first vtable function).
class CMenuExGetMoneyPart {
public:
    void SetRate(f32 v);
    void SetScale(f32 v);

    u8 pad0[0x64];
    s32 m_unk64;              // 0x64
    u8 pad68[0x4];
    s32 m_unk6C;              // 0x6C
    s32 m_unk70;              // 0x70
    f32 m_unk74;              // 0x74
};

#include "state.h"
class CStatusItem {
public:
    void Func1A3378();
    void Func1A3628();
    void Start();
    void Func1A40C8();
    const char *GetUnkE4(s32 i);
    void SetText(s32 i, const char *s);
    void GetPos(f32 *x, f32 *y, s32 i);
    u8 pad0[0x20];
    s32 m_state;              // 0x20
};
class CStatusWinSub1A40B8 {
public:
    void SetUnk80(f32 x, f32 y);
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
extern "C" int sprintf(char *buf, const char *fmt, ...);
inline void SetVar(CStateMachine *sm, s32 k, s32 v) { sm->Var(k) = v; }
inline void Inc(CStateMachine *sm) { SetVar(sm, 0, sm->Get(0) + 1); }
// @decl-end

CMenuNews::CMenuNews() {
    m_unk58 = 0;
}

CMenuNews::~CMenuNews() {
}

s32 CMenuNews::Update() {
    CStateMachine *sm = (CStateMachine *)this;
    s32 a, b, c;
    char buf[0x100];
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
    case -1: {
        CStatusItem *item;
        s32 n, k;
        m_unk58 = (CUnk1A4298 *)D_002A5408->Find("news");
        if (!m_unk58) return Func235DE0("*** Can't Get %s Window\n", "news");
        ((CStatusItem *)m_unk58)->Func1A3378();
        n = D_002A5358->Func1091B0(0x2C8) - 1;
        if (!((u32)n < 3)) {
            Func235DE0("News Lines Error.(%d)\n", n);
            n = 0;
        }
        k = n + 5;
        sprintf(buf, ((CStatusItem *)m_unk58)->GetUnkE4(k), D_002A5358->GetStr(0x2C7));
        ((CStatusItem *)m_unk58)->SetText(k, buf);
        if (D_002A5358->Func1091B0(0x2C9)) {
            f32 x, y;
            ((CStatusItem *)m_unk58)->GetPos(&x, &y, 8);
            ((CStatusWinSub1A40B8 *)m_unk58)->SetUnk80(x, y);
        }
        ((CStatusItem *)m_unk58)->Func1A3628();
    }
    case -0x9C:
        if (((CStatusItem *)m_unk58)->m_state != 2) {
            sm->m_state = -0x9C; done = 1; goto loop;
        }
        sm->m_state = -0xA1; done = 1; goto loop;
    case -0xA1:
        sm->Push(4);
        SetVar(sm, 1, D_002A5358->Func1091B0(0x2CA));
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
                sm->m_state = -0xAB; done = 1; goto loop;
            }
            D_002A5468->V14(3);
            sm->Pop(4);
            goto s4;
    case -0xAB:;
        }
        sm->Pop(4);
    s4:
        m_state = 4;
        ((CStatusItem *)m_unk58)->Start();
        do {
    case -0xBC:
        if (((CStatusItem *)m_unk58)->m_state != 0) {
            sm->m_state = -0xBC; done = 1; goto loop;
        }
        } while (0);
        m_state = 5;
        sm->m_state = -0xC0;
    case -0xC0:
        done = 1; goto loop;
    }
out:
    ((CStatusItem *)m_unk58)->Func1A40C8();
end:;
}

s32 CMenuNews::Draw() {
    return m_unk58->Func1A4298();
}

CMenuExGetMoney *CreateCMenuExGetMoney() {
    return new CMenuExGetMoney;
}

void CMenuExGetMoneyPart::SetRate(f32 v) {
    f32 r = Clamp01(v);
    m_unk6C = (s32)(m_unk64 * r);
    m_unk70 = (s32)(f32)m_unk6C + D_002A5358->Func1091B0(0x24D);
}

void CMenuExGetMoneyPart::SetScale(f32 v) {
    m_unk74 = 2.0f - Clamp01(v);
}
