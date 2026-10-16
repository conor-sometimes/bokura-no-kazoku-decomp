#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"
#include "IFlags.h"

class CMenuSysscr01 {
public:
    CMenuSysscr01() throw();
    static CMenuSysscr01 *Create();

    u8 pad0[0x60];
};

class CUnk1A4298 {
public:
    int Func1A4298();
};
class CUnk237E90 {
public:
    int Func237E90(int v);
};
extern "C" u8 *func_00237570(s32 v);
extern "C" void func_00237A88(void *p, s32 v);
extern "C" void *func_00237C30(void *p);
extern "C" int func_00238158(void *p, s32 v);
extern "C" int func_001B66E8(void *p);
extern void *D_002A5538;
void Func225240(s32 v);
extern ISysFlag *D_002A26E0;

// Background work (0x2456F8, library code).
extern "C" void func_00245818(void *p, s32 v);
class CBgWork {
public:
    CBgWork();
    ~CBgWork();

    u8 pad0[0xC];
};

// Same layout as the state block at the start of CMenuProcess.
class CMenuTimer {
public:
    CMenuTimer() {
        m_unk4 = -1;
        m_unk2 = 0;
        m_unk0 = 0;
    }

    s16 m_unk0;               // 0x0
    s16 m_unk2;               // 0x2
    s32 m_unk4;               // 0x4
};

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuSysscr02.
class CMenuSysscr02 : public CMenuProcess {
public:
    CMenuSysscr02();
    virtual ~CMenuSysscr02();
    virtual s32 Update();
    virtual s32 Draw();
    void LoadFlags();

    CBgWork m_bg;             // 0x58
    CMenuTimer m_timer;       // 0x64
    u8 pad6C[0x40];
    s32 m_unkAC;              // 0xAC
    CUnk1A4298 *m_unkB0;      // 0xB0
    s32 m_unkB4[3];           // 0xB4
    s32 m_unkC0[3];           // 0xC0
    s32 m_unkCC[3];           // 0xCC
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
    void Select(s32 i);
    const char *GetUnkE4(s32 i);
    void SetText(s32 i, const char *s);
    void GetMappedUnkC0(f32 *x, f32 *y, s32 n);
    void SetMappedColor(s32 n, const CVec4 *v);
    u8 pad0[0x20];
    s32 m_state;              // 0x20
    u8 pad24[0x10];
    f32 m_unk34;              // 0x34
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
class CFlagWork {
public:
    int Func1091B0(s32 id);
};
extern CFlagWork *D_002A5358;
extern CFlagWork *D_002A4B60;
#include "CMenuMgrSub1B6418.h"
#define MGR ((CMenuMgrSub1B6418 *)D_002A5538)
extern "C" int BgBusy(void *p, s32 v) asm("func_00245818");
extern "C" int sprintf(char *buf, const char *fmt, ...);
extern "C" char *strcpy(char *d, const char *s);
extern "C" char *func_0024BA08(char *buf, s32 v);
extern "C" void func_002457A0(CBgWork *bg, void *obj, void (CMenuSysscr02::*f)(), s32 x);
inline void SetVar(CStateMachine *sm, s32 k, s32 v) { sm->Var(k) = v; }
#define W ((CStatusItem *)m_unkB0)
// @decl-end

CMenuSysscr02::CMenuSysscr02() {
}

CMenuSysscr02::~CMenuSysscr02() {
    func_00245818(&m_bg, 1);
}

void CMenuSysscr02::LoadFlags() {
    s32 i;
    for (i = 0; i < 3; i++) {
        m_unkC0[i] = D_002A26E0->V10(i);
        m_unkCC[i] = D_002A26E0->V7(i);
    }
}

s32 CMenuSysscr02::Update() {
    CStateMachine *sm;
    s32 a, b, c;
    char buf[0x100];
    char tmp[0x100];
    f32 x, y;
    f32 c0[4], c1[4], c2[4];
    s32 i;
    s32 k;
    s32 done;
    for (i = 0; i < 4; i++) {
        c0[i] = D_002A4B60->Func1091B0(i + 0xB);
        c1[i] = D_002A4B60->Func1091B0(i + 0xF);
        c2[i] = D_002A4B60->Func1091B0(i + 0x13);
    }
    D_002A5468->V7(&a, &b, &c);
    if (m_state == 6) {
        BgBusy(&m_bg, 1);
        m_state = 5;
        m_unk4C = -1;
        goto end;
    }
    sm = (CStateMachine *)&m_timer;
    done = 0;
loop:
    if (done) goto out;
    {
        u32 fl = sm->m_flags;
        if ((fl >> 7) & 1) goto out;
    }
    switch (sm->m_state) {
    case -1:
        m_unkB0 = (CUnk1A4298 *)D_002A5408->Find("sysscr02");
        if (!m_unkB0) return Func235DE0("*** Can't Get %s Window.\n", "sysscr02");
        W->Func1A3378();
        func_002457A0(&m_bg, this, &CMenuSysscr02::LoadFlags, 0);
        while (BgBusy(&m_bg, 0)) {
            sm->m_state = -0xB5; done = 1; goto loop;
    case -0xB5:;
        }
        for (i = 0; i < 3; i++) m_unkB4[i] = D_002A5358->Func1091B0(i + 0xC) != 0;
        m_unkAC = 0;
        sm->Push();
        SetVar(sm, 0, -0xBE);
        goto sub;
    case -0xBE:
        W->GetMappedUnkC0(&x, &y, m_unkAC);
        MGR->SetUnkE0(1);
        MGR->SetUnk0And20(x, y);
        W->Func1A3628();
        do {
    case -0xCC:
            if (W->m_state == 2) {
                m_state = 3;
                sm->m_state = -0xD3; done = 1; goto loop;
            }
            sm->m_state = -0xCC; done = 1; goto loop;
        } while (0);
        do {
    case -0xD3:
    case -0x10C:
            if (c & 0x1000) {
                k = m_unkAC;
                if (--m_unkAC < 0) m_unkAC = 2;
                if (k != m_unkAC) {
                    sm->Push();
                    SetVar(sm, 0, -0xE3);
                    goto sub;
    case -0xE3:
                    D_002A5468->V14(0);
                    goto y10C;
                }
            } else if (c & 0x4000) {
                k = m_unkAC;
                if (++m_unkAC >= 3) m_unkAC = 0;
                if (k != m_unkAC) {
                    D_002A5468->V14(0);
                    sm->Push();
                    SetVar(sm, 0, -0xF4);
                    goto sub;
    case -0xF4:
                    goto y10C;
                }
            } else if (a & 0x20) {
                if (m_unkB4[m_unkAC]) {
                    D_002A5468->V14(1);
                    m_unk4C = m_unkAC;
                    goto s4;
                }
                D_002A5468->V14(4);
                goto y10C;
            } else if (a & 0x40) {
                D_002A5468->V14(2);
                m_unk4C = -1;
                goto s4;
            }
        y10C:
            sm->m_state = -0x10C; done = 1; goto loop;
        } while (0);
    s4:
        m_state = 4;
        W->Start();
        do {
    case -0x11D:
            if (W->m_state == 0) {
                m_state = 5;
                sm->m_state = -0x147; done = 1; goto loop;
            }
            sm->m_state = -0x11D; done = 1; goto loop;
        } while (0);
    sub:
        W->Select(m_unkAC);
        {
            s32 j;
            for (j = 0; j < 3; j++) {
                if (m_unkAC == j) {
                    if (m_unkB4[j]) {
                        W->SetMappedColor(j, (CVec4 *)c0);
                        continue;
                    }
                } else {
                    if (m_unkB4[j]) {
                        W->SetMappedColor(j, (CVec4 *)c1);
                        continue;
                    }
                }
                W->SetMappedColor(j, (CVec4 *)c2);
            }
        }
        W->GetMappedUnkC0(&x, &y, m_unkAC);
        MGR->Move1B6488(x, y);
        sprintf(buf, W->GetUnkE4(8), func_0024BA08(tmp, m_unkCC[m_unkAC]));
        W->SetText(8, buf);
        if (m_unkCC[m_unkAC] == 0 && m_unkB4[m_unkAC] == 0) strcpy(buf, "");
        else sprintf(buf, W->GetUnkE4(7), func_0024BA08(tmp, m_unkC0[m_unkAC]));
        W->SetText(7, buf);
        sm->m_state = sm->Get();
        sm->Pop();
        goto loop;
    case -0x147:
    default:
        goto out;
    }
out:
    W->Func1A40C8();
    MGR->SetUnk4C(W->m_unk34);
    MGR->Update1B6570();
end:;
}

s32 CMenuSysscr02::Draw() {
    u8 *p = func_00237570(0x60);
    func_00237A88(p, 4);
    func_00238158(func_00237C30(p + 0x30), 1);
    ((CUnk237E90 *)(p + 0x10))->Func237E90(m_unkB0->Func1A4298());
    ((CUnk237E90 *)(p + 0x20))->Func237E90(func_001B66E8(D_002A5538));
    Func225088();
    Func225240((s32)p);
    return Func2250C0();
}

CMenuSysscr01 *CMenuSysscr01::Create() {
    return new CMenuSysscr01;
}
