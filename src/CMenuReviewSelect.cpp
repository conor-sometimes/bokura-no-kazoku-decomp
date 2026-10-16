#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" void func_00191E28(void *p);
class CMenuReviewStart {
public:
    static CMenuReviewStart *Create();
};
#include "CMenuProcess.h"
class CVec4 {
public:
    f32 x, y, z, w;
};
// The window item (CStatusWin.cpp); Func1A4298 is named under another class there.
class CStatusItem {
public:
    int GetColor(CVec4 *out, s32 i);
    void GetPos(f32 *x, f32 *y, s32 i);
    void Func1A3378();
    void Func1A3628();
    void Start();
    void Func1A40C8();
    int Select(s32 i);
    const char *GetUnkE4(s32 i);
    void SetText(s32 i, const char *s);
    int GetMappedUnkC0(f32 *x, f32 *y, s32 n);

    u8 pad0[0x20];
    s32 m_state;              // 0x20
    u8 pad24[0x10];
    f32 m_unk34;              // 0x34
};
class CUnk1A4298 {
public:
    int Func1A4298();
};
class CUnk237E90 {
public:
    int Func237E90(int v);
};
#include "CMenuMgrSub1B5BF8.h"
extern CMenuMgrSub1B5BF8 *D_002A5534;
extern "C" int func_001B5E18(CMenuMgrSub1B5BF8 *p);
extern "C" int func_001B5FE0(CMenuMgrSub1B5BF8 *p, f32 x, f32 y, const char *s);
#include "CMenuMgrSub1B4768.h"
class CMenuMgr {
public:
    int Func1B4ED0(int v);
};
extern CMenuMgrSub1B4768 *D_002A5530;
extern "C" int func_001B50B0(CMenuMgrSub1B4768 *p, int k);
#include "CMenuMgrSub1B6418.h"
extern CMenuMgrSub1B6418 *D_002A5538;
extern "C" int func_001B66E8(CMenuMgrSub1B6418 *p);
extern "C" int sprintf(char *buf, const char *fmt, ...);
void *Func237570(int size);
void Func237A88(void *p, int n);
void *Func237C30(void *p);
void Func238158(void *p, int v);
void Func225240(int v);
// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuReviewSelect.
class CMenuReviewSelect : public CMenuProcess {
public:
    CMenuReviewSelect();
    virtual ~CMenuReviewSelect();
    virtual void Update();
    virtual s32 Draw();

    CStatusItem *m_unk58;     // 0x58
    CStatusItem *m_unk5C;     // 0x5C
    u8 pad60[0x4];
    s32 m_unk64;              // 0x64
    s32 m_unk68[5];           // 0x68
};

#include "state.h"
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
inline void SetVar(CStateMachine *sm, s32 k, s32 v) { sm->Var(k) = v; }
#define W(p) ((CStatusItem *)(p))
// @decl-end

CMenuReviewSelect::CMenuReviewSelect() {
    s32 i;
    m_unk58 = 0;
    m_unk5C = 0;
    for (i = 4; i >= 0; i--) {
        m_unk68[i] = 0;
    }
}

CMenuReviewSelect::~CMenuReviewSelect() {
}

void CMenuReviewSelect::Update() {
    CStateMachine *sm = (CStateMachine *)this;
    s32 a, b, c;
    char buf[0x200];
    f32 x, y;
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
        const char *name = "reviewselect1";
        m_unk58 = (CStatusItem *)D_002A5408->Find(name);
        if (!m_unk58) { Func235DE0("*** Can't Get %s Window\n", name); return; }
        W(m_unk58)->Func1A3378();
        name = "reviewselect2";
        m_unk5C = (CStatusItem *)D_002A5408->Find(name);
        if (!m_unk5C) { Func235DE0("*** Can't Get %s Window\n", name); return; }
        W(m_unk5C)->Func1A3378();
        D_002A5538->SetUnkE0(1);
        m_unk64 = m_unk50 < 0 ? 0 : m_unk50;
        W(m_unk58)->GetMappedUnkC0(&x, &y, m_unk64);
        D_002A5538->SetUnk0And20(x, y);
        W(m_unk58)->Select(m_unk64);
        sm->Push();
        SetVar(sm, 0, -0xBD);
        goto sub;
    }
    case -0xBD:
        W(m_unk5C)->Select(-1);
        sprintf(buf, W(m_unk58)->GetUnkE4(7), D_002A5358->GetStr(0x243));
        W(m_unk58)->SetText(7, buf);
        W(m_unk58)->Func1A3628();
        W(m_unk5C)->Func1A3628();
        do {
    case -0xD3:
            if (W(m_unk58)->m_state != 2) {
                sm->m_state = -0xD3; done = 1; goto loop;
            }
            if (W(m_unk5C)->m_state != 2) {
                sm->m_state = -0xD3; done = 1; goto loop;
            }
        } while (0);
        sm->m_state = -0xD8; done = 1; goto loop;
    case -0xD8:
    case -0xF4:
        if (!(a & 0x20)) {
            if ((a & 0x1000) && m_unk64 == 1) {
                D_002A5468->V14(0);
                m_unk64 = 0;
                sm->Push();
                SetVar(sm, 0, -0xE9);
                goto sub;
            }
            if ((a & 0x4000) && m_unk64 == 0) {
                D_002A5468->V14(0);
                m_unk64 = 1;
                sm->Push();
                SetVar(sm, 0, -0xF1);
                goto sub;
            }
            sm->m_state = -0xF4; done = 1; goto loop;
    case -0xE9:
    case -0xF1:
            sm->m_state = -0xF4; done = 1; goto loop;
        }
        D_002A5468->V14(1);
        m_unk4C = m_unk64;
        m_state = 4;
        W(m_unk58)->Start();
        W(m_unk5C)->Start();
        do {
    case -0x107:
            if (W(m_unk58)->m_state != 0 || W(m_unk5C)->m_state != 0) {
                sm->m_state = -0x107; done = 1; goto loop;
            }
            m_state = 5;
            sm->m_state = -0x118;
            goto e118;
        } while (0);
    sub:
        m_unk68[0] = D_002A5358->Func1091B0(0x244);
        m_unk68[1] = D_002A5358->Func1091B0(0x245 + m_unk64);
        m_unk68[2] = D_002A5358->Func1091B0(0x247);
        m_unk68[3] = D_002A5358->Func1091B0(0x248);
        m_unk68[4] = m_unk68[0] + m_unk68[1] + m_unk68[2] + m_unk68[3];
        W(m_unk58)->GetMappedUnkC0(&x, &y, m_unk64);
        D_002A5538->Move1B6488(x, y);
        W(m_unk58)->Select(m_unk64);
        sm->m_state = sm->Get();
        sm->Pop();
        goto loop;
    case -0x118:
    e118:
        done = 1; goto loop;
    }
out:
    W(m_unk58)->Func1A40C8();
    W(m_unk5C)->Func1A40C8();
    D_002A5538->Update1B6570();
end:;
}

s32 CMenuReviewSelect::Draw() {
    f32 x, y;
    char buf[0x100];
    CVec4 col;
    u8 *p;
    s32 i;
    if (!m_unk58 || !m_unk5C) {
        Func225088();
        Func2250C0();
    } else {
        p = (u8 *)Func237570(0x60);
        Func237A88(p, 6);
        Func238158(Func237C30(p + 0x50), 1);
        ((CUnk237E90 *)(p + 0x10))->Func237E90(((CUnk1A4298 *)m_unk58)->Func1A4298());
        ((CUnk237E90 *)(p + 0x10))->Func237E90(((CUnk1A4298 *)m_unk5C)->Func1A4298());
        ((CUnk237E90 *)(p + 0x20))->Func237E90(func_001B5E18(D_002A5534));
        D_002A5534->Reset();
        D_002A5534->SetUnk30(1);
        D_002A5534->SetUnk1C(m_unk5C->m_unk34);
        D_002A5534->SetUnk0(1.0f, 1.0f);
        for (i = 0; i < 5; i++) {
            sprintf(buf, "%d", m_unk68[i]);
            m_unk5C->GetPos(&x, &y, i + 0xC);
            switch (i) {
            case 0:
                D_002A5534->SetUnk10(0.78f, 0.78f, 0.78f);
                D_002A5534->SetUnk34(2);
                break;
            case 1:
                m_unk5C->GetColor(&col, 0x11);
                D_002A5534->SetUnk10(col.x * 0.0078125f, col.y * 0.0078125f, col.z * 0.0078125f);
                D_002A5534->SetUnk34(0);
                break;
            case 4:
                m_unk5C->GetColor(&col, 0x11);
                D_002A5534->SetUnk10(col.x * 0.0078125f, col.y * 0.0078125f, col.z * 0.0078125f);
                D_002A5534->SetUnk34(1);
                break;
            default:
                D_002A5534->SetUnk10(0.78f, 0.78f, 0.78f);
                D_002A5534->SetUnk34(1);
                break;
            }
            ((CUnk237E90 *)(p + 0x20))->Func237E90(func_001B5FE0(D_002A5534, x, y, buf));
        }
        D_002A5534->SetUnk34(0);
        ((CUnk237E90 *)(p + 0x30))->Func237E90(((CMenuMgr *)D_002A5530)->Func1B4ED0(D_002A5530->GetEntry0(0x18)));
        D_002A5530->Reset1B4D28();
        D_002A5530->SetUnk4C(m_unk5C->m_unk34);
        for (i = 0; i < 4; i++) {
            m_unk5C->GetPos(&x, &y, i + 8);
            D_002A5530->SetUnk20(x, y, 0.0f);
            ((CUnk237E90 *)(p + 0x30))->Func237E90(func_001B50B0(D_002A5530, 0x18));
        }
        D_002A5538->SetUnk4C(m_unk58->m_unk34);
        ((CUnk237E90 *)(p + 0x40))->Func237E90(func_001B66E8(D_002A5538));
        Func225088();
        Func225240((int)p);
        Func2250C0();
    }
}

CMenuReviewStart *CMenuReviewStart::Create() {
    CMenuReviewStart *p = (CMenuReviewStart *)operator new(0x68);
    func_00191E28(p);
    return p;
}
