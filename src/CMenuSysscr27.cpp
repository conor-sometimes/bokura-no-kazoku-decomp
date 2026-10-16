#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"
#include "CBgWork.h"
class CMenuRecordWin;
extern "C" void func_001AA118(void *p);
class CMenuSysscr26 {
public:
    static CMenuSysscr26 *Create();
};

#include "CMenuRecordWin.h"
extern "C" const char *func_001A36B0(CMenuRecordWin *w, s32 v);
extern "C" s32 func_0024BA08(char *buf, s32 v);
extern "C" int sprintf(char *buf, const char *fmt, ...);
//@sym sprintf 0x28AF70
class CMenuSysscr27Win {
public:
    void Func1A98F8();
    void Func1A9BF8();
    void Func1A9D30();
    void Func1A9ED8(s32 k);
    void Func1A9E60();
    void Func1AA0B0(f32 t);
    void Func1A9FA0(f32 t, s32 a, s32 b);
    void Func1A9FA0_8_9(f32 t);
    void Func1A9FA0_10_11(f32 t);
    void Func1A9FA0_6_7(f32 t);
    u8 pad0[0x58];
    CMenuRecordWin *m_unk58;  // 0x58
    s32 m_unk5C;              // 0x5C
    s32 m_unk60;              // 0x60
};

extern char D_002DF258[];

class CUnk237E90 {
public:
    int Func237E90(int v);
};
extern "C" u8 *func_00237570(s32 v);
extern "C" void func_00237A88(void *p, s32 v);
extern "C" void *func_00237C30(void *p);
extern "C" int func_00238158(void *p, s32 v);
extern "C" int func_001A0510(void *p);
extern "C" int func_0018A1F0(void *p);
void Func225240(s32 v);
class CMenuSysscr31 {
public:
    void Release1A8DC0();
};
// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuSysscr27.
class CMenuSysscr27 : public CMenuProcess {
public:
    CMenuSysscr27();
    virtual ~CMenuSysscr27();
    virtual void Update();
    virtual s32 Draw();

    CBgWork m_bg;             // 0x58
    void *m_unk64;            // 0x64
    void *m_unk68;            // 0x68
    s32 m_unk6C;              // 0x6C
    s32 m_unk70;              // 0x70
    s32 m_unk74;              // 0x74
};

extern "C" void func_001A3AF8(CMenuRecordWin *w, s32 k, f32 x, f32 y);

extern char D_002DF230[];

#include "state.h"
#include "CChrBodyWin.h"
#include "CFlagWork.h"
#include "CMenuMgrSub1B6418.h"
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
class CStatusWin {
public:
    CStatusWin();
    void Select1A01C8(s32 k);
    void SetUnk4C(u32 v);
    void ItemFunc1A3628();
    s32 GetItemState2();
    void ItemStart();
    void Update1A03E8();
    u8 pad0[0x84];
};
class CChildStatusObj {
public:
    void SetChild1893A0(s32 v);
};
class CChrBodyWinSub188748 {
public:
    void SetUnk380(int v);
};
class CMenuSysscr31V {
public:
    void Release1A8DC0() throw() asm("Release1A8DC0__13CMenuSysscr31");
};
class CChrBodyWinV {
public:
    void Check2To3V() asm("Check2To3__11CChrBodyWin");
    void Check3To4V() asm("Check3To4__11CChrBodyWin");
    void Init189018(int k) asm("Init189018__11CChrBodyWini");
    u8 pad0[0x48];
    s32 m48;
};
extern CChrBodyWin *D_002A4308;
extern CFlagWork *D_002A4B60;
extern CFlagWork *D_002A4638[6];
extern CMenuMgrSub1B6418 *D_002A5538;
void Func185A28(int a, int b);
extern "C" void func_001895F8(void *p);
class CBgTarget;
typedef int (CBgTarget::*BgFn)();
extern "C" void func_002457A0(CBgWork *bg, void *obj, BgFn f, s32 x);
extern "C" int BgBusy(void *p, s32 v) asm("func_00245818");
inline void SetVar(CStateMachine *sm, s32 k, s32 v) { sm->Var(k) = v; }
inline void Inc(CStateMachine *sm) { SetVar(sm, 0, sm->Get(0) + 1); }
#define BODY ((CChrBodyWin *)m_unk64)
#define BODYV ((CChrBodyWinV *)m_unk64)
#define WIN ((CStatusWin *)m_unk68)
// @decl-end

CMenuSysscr27::CMenuSysscr27() {
    m_unk68 = 0;
    m_unk64 = 0;
    m_unk6C = 0;
    m_unk74 = 0;
}

CMenuSysscr27::~CMenuSysscr27() {
    ((CMenuSysscr31 *)this)->Release1A8DC0();
}

void CMenuSysscr27::Update() {
    CStateMachine *sm = (CStateMachine *)this;
    s32 a, b, c;
    s32 done;
    s32 i;
    if (m_state == 6) {
        ((CMenuSysscr31V *)this)->Release1A8DC0();
        m_state = 5;
        m_unk4C = -1;
        goto end;
    }
    D_002A5468->V7(&a, &b, &c);
    done = 0;
loop:
    if (done) goto out;
    {
        u32 fl = sm->m_flags;
        if ((fl >> 7) & 1) goto out;
    }
    switch (sm->m_state) {
    case -1:
        m_state = 0;
        Func185A28(0, 5);
        D_002A4308->Clear1884B0();
        ((CChrBodyWinSub188748 *)D_002A4308)->SetUnk380(1);
        for (i = 0; i < D_002A26E4->Func1091B0(0x27); i++) D_002A4308->Open(i);
        func_002457A0(&m_bg, D_002A4308, (BgFn)&CChrBodyWin::Func1889F8, 0);
        m_state = 1;
        while (BgBusy(&m_bg, 0)) {
            sm->m_state = -0xC5; done = 1; goto loop;
    case -0xC5:;
        }
        m_unk68 = new CStatusWin;
        {
            void *p = operator new(0x84);
            ((CChrBodyWinV *)p)->Init189018(0);
            m_unk64 = p;
        }
        BODY->Set189348(1, 1);
        ((CChildStatusObj *)m_unk64)->SetChild1893A0(m_unk6C);
        WIN->SetUnk4C(0);
        WIN->Select1A01C8(m_unk6C);
        m_state = 3;
        D_002A5538->SetUnkE0(0);
        WIN->ItemFunc1A3628();
        sm->Push(4);
        SetVar(sm, 1, 6);
        SetVar(sm, 0, 0);
        {
            f32 z = 0.0f;
            SetVar(sm, 2, *(s32 *)&z);
        }
        {
            f32 o = 1.0f;
            SetVar(sm, 3, *(s32 *)&o);
        }
        for (; sm->Get(0) < sm->Get(1); Inc(sm)) {
            sm->m_state = -0xDD; done = 1; goto loop;
    case -0xDD:;
        }
        sm->Pop(4);
        do { } while (0);
        BODY->SetMode1();
        do {
    case -0xEA: {
            s32 k = WIN->GetItemState2();
            if (k != 2) {
                sm->m_state = -0xEA; done = 1; goto loop;
            }
            if (BODYV->m48 == k) {
                sm->m_state = -0x109; done = 1; goto loop;
            }
            sm->m_state = -0xEA; done = 1; goto loop;
        }
        } while (0);
    advance:
        WIN->Select1A01C8(++m_unk6C);
        ((CChildStatusObj *)m_unk64)->SetChild1893A0(m_unk6C);
        sm->m_state = -0xEE; done = 1; goto loop;
    case -0xEE:
        m_unk70 = 0;
        do {
    case -0x104:
            if (a & 0x20) {
                D_002A5468->V14(3);
                BODY->SetMode5();
                goto y124;
            }
            if (a & 0x40) {
                D_002A5468->V14(3);
                goto s4;
            }
            m_unk70++;
            if (D_002A4B60->Func1091B0(0x21) < m_unk70) {
                sm->m_state = -0x109; done = 1; goto loop;
            }
            sm->m_state = -0x104; done = 1; goto loop;
        } while (0);
    case -0x109:
        m_state = 2;
        BODYV->Check2To3V();
        sm->m_state = -0x10F; done = 1; goto loop;
        for (;;) {
    case -0x10F:
    case -0x11F:
            if (BODYV->m48 != 3) break;
            if (a & 0x20) {
                D_002A5468->V14(3);
                BODY->Check3To4();
            }
            if (a & 0x40) {
                D_002A5468->V14(3);
                goto s4;
            }
            sm->m_state = -0x11F; done = 1; goto loop;
        }
    y124:
        sm->m_state = -0x124; done = 1; goto loop;
    case -0x124:
        m_unk70 = 0;
        do {
    case -0x13B:
            if (a & 0x20) {
                D_002A5468->V14(3);
                goto y13F;
            }
            if (a & 0x40) {
                D_002A5468->V14(3);
                goto s4;
            }
            m_unk70++;
            if (D_002A4B60->Func1091B0(0x23) < m_unk70) goto y13F;
            sm->m_state = -0x13B; done = 1; goto loop;
        } while (0);
    y13F:
        sm->m_state = -0x13F; done = 1; goto loop;
    case -0x13F:
        if (m_unk6C == D_002A26E4->Func1091B0(0x27) - 1) {
            m_unk70 = 0;
            goto s176;
        }
        if (D_002A4638[0]->Func1091B0(m_unk6C + 0xAE) == D_002A4638[5]->Func1091B0(m_unk6C + 0xAE)) goto advance;
        m_unk70 = 0;
        do {
    case -0x161:
            if (a & 0x20) {
                D_002A5468->V14(3);
                goto advance;
            }
            if (a & 0x40) {
                D_002A5468->V14(3);
                goto s4;
            }
            m_unk70++;
            if (D_002A4B60->Func1091B0(0x24) < m_unk70) goto advance;
            sm->m_state = -0x161; done = 1; goto loop;
        } while (0);
        for (;;) {
    case -0x176:
    s176:
            if (!(m_unk70++ < D_002A4B60->Func1091B0(0x25))) break;
            if (a & 0x60) {
                D_002A5468->V14(3);
                goto s4;
            }
            sm->m_state = -0x176; done = 1; goto loop;
        }
    s4:
        m_state = 4;
        WIN->ItemStart();
        BODY->SetMode2();
    case -0x188:
        if (WIN->GetItemState2() != 0) {
            sm->m_state = -0x188; done = 1; goto loop;
        }
        if (BODYV->m48 == 0) goto e5;
        sm->m_state = -0x188; done = 1; goto loop;
    e5:
        m_state = 5;
        sm->m_state = -0x18C;
    case -0x18C:
        done = 1; goto loop;
    }
out:
    if (m_unk68 && m_unk64) {
        WIN->Update1A03E8();
        func_001895F8(m_unk64);
    }
end:;
}

s32 CMenuSysscr27::Draw() {
    if (m_unk64 == 0 || m_unk68 == 0) {
        Func225088();
        return Func2250C0();
    }
    u8 *p = func_00237570(0x40);
    CUnk237E90 *q = (CUnk237E90 *)(p + 0x10);
    func_00237A88(p, 4);
    func_00238158(func_00237C30(p + 0x30), 1);
    q->Func237E90(func_001A0510(m_unk68));
    q->Func237E90(func_0018A1F0(m_unk64));
    Func225088();
    Func225240((s32)p);
    return Func2250C0();
}

