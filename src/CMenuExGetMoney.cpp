#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

class CVec4 {
public:
    f32 x, y, z, w;
};
// The window item (CStatusWin.cpp); Func1A4298 is named under another class there.
class CStatusItem {
public:
    void Func1A40C8();
    void Start();
    int Select(s32 i);
    void Func1A3628();
    void Func1A3378();
    int GetColor(CVec4 *out, s32 i);
    int GetPos(f32 *x, f32 *y, s32 i);

    u8 pad0[0x34];
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
#include "CFlagWork.h"
extern CFlagWork *D_002A5358;
extern "C" int sprintf(char *buf, const char *fmt, ...);
extern char D_002DA470[];
void *Func237570(int size);
void Func237A88(void *p, int n);
void *Func237C30(void *p);
void Func238158(void *p, int v);
void Func225240(int v);

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuExGetMoney.
class CMenuExGetMoney : public CMenuProcess {
public:
    CMenuExGetMoney();
    virtual ~CMenuExGetMoney();
    virtual s32 Update();
    virtual s32 Draw();

    CStatusItem *m_unk58;     // 0x58
    s32 m_unk5C;              // 0x5C
    u8 pad60[0x4];
    s32 m_unk64;              // 0x64
    s32 m_unk68;              // 0x68
    s32 m_unk6C;              // 0x6C
    s32 m_unk70;              // 0x70
    f32 m_unk74;              // 0x74
};

class CMenuConfig {
public:
    CMenuConfig() throw();

    u8 pad0[0x7C];
};

struct CStatusItemX {
    u8 pad0[0x20];
    s32 m_state;              // 0x20
};
class CStatusWinSub1A0A10 {
public:
    CStatusItem *Find(const char *name);
};
extern CStatusWinSub1A0A10 *D_002A5408;
#include "CMenuMgrSub1B6418.h"
extern CMenuMgrSub1B6418 *D_002A5538;
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
    virtual void Play(s32 v);
    virtual void Stop(s32 v);
};
extern CSndIf *D_002A5468;
extern CFlagWork *D_002A4B60;
class CMenuExGetMoneyPart {
public:
    void SetRate(f32 t);
    void SetScale(f32 t);
};
// @decl-end

CMenuExGetMoney::CMenuExGetMoney() {
    m_unk58 = 0;
    m_unk64 = 0;
    m_unk68 = 0;
    m_unk6C = 0;
    m_unk70 = 0;
    m_unk74 = 1.0f;
    m_unk5C = 0;
}

CMenuExGetMoney::~CMenuExGetMoney() {
}

s32 CMenuExGetMoney::Update() {
    s32 a, b, c;
    char buf[0x200];
    s32 done;
    CStatusItem *w;
    D_002A5468->V7(&a, &b, &c);
    if (m_state == 6) {
        m_state = 5;
        goto end;
    }
    done = 0;
loop:
    if (done) goto out;
    {
        u32 fl = (u16)m_unk0;
        if ((fl >> 7) & 1) goto out;
    }
    switch (m_unk4) {
    case -1:
        w = D_002A5408->Find("exgetmoney");
        m_unk58 = w;
        if (!w) return Func235DE0("*** Can't Get %s Window\n", "exgetmoney");
        w->Func1A3378();
        D_002A5538->SetUnkE0(0);
        m_unk58->Select(-1);
        m_unk64 = D_002A5358->Func1091B0(0x25E);
        m_unk6C = 0;
        m_unk70 = D_002A5358->Func1091B0(0x24D);
        m_unk68 = m_unk70 + m_unk64;
        m_unk74 = 1.0f;
        m_unk5C = 0;
        m_unk58->Func1A3628();
        do {
    case -0xE0:
        if (((CStatusItemX *)m_unk58)->m_state != 2) {
            m_unk4 = -0xE0; done = 1; goto loop;
        }
        } while (0);
        m_unk4 = -0xE5; done = 1; goto loop;
    case -0xE5:
        *(s32 *)&pad60 = 0;
        m_unk5C = 1;
        D_002A5468->Play(0x4C);
        while (*(s32 *)&pad60 < D_002A4B60->Func1091B0(0x29)) {
            if (a & 0x60) goto cA;
            (*(s32 *)&pad60)++;
            ((CMenuExGetMoneyPart *)this)->SetRate((f32)*(s32 *)&pad60 / (f32)D_002A4B60->Func1091B0(0x29));
            m_unk4 = -0xFA; done = 1; goto loop;
    case -0xFA:;
        }
        m_unk4 = -0xFF; done = 1; goto loop;
        if (0) {
    cA:
            D_002A5468->Play(0x4D);
            D_002A5468->Stop(0x4C);
            m_unk4C = -1;
            goto y11c;
        }
    case -0xFF:
        *(s32 *)&pad60 = 0;
        D_002A5468->Play(0x4D);
        while (*(s32 *)&pad60 < D_002A4B60->Func1091B0(0x2A)) {
            if (*(s32 *)&pad60 == D_002A4B60->Func1091B0(0x2F)) D_002A5468->Stop(0x4C);
            if (a & 0x60) {
                D_002A5468->Stop(0x4C);
                m_unk4C = -1;
                goto y11c;
            }
            (*(s32 *)&pad60)++;
            ((CMenuExGetMoneyPart *)this)->SetScale((f32)*(s32 *)&pad60 / (f32)D_002A4B60->Func1091B0(0x2A));
            m_unk4 = -0x117; done = 1; goto loop;
    case -0x117:;
        }
    y11c:
        m_unk4 = -0x11C; done = 1; goto loop;
        if (0) {
    c3:
            D_002A5468->Play(3);
            m_unk4C = -1;
            goto s4;
        }
    case -0x11C:
        m_unk70 = m_unk68;
        m_unk6C = m_unk64;
        m_unk5C = 0;
        *(s32 *)&pad60 = 0;
        for (;;) {
    case -0x133:
            if (a & 0x60) goto c3;
            (*(s32 *)&pad60)++;
            if (D_002A4B60->Func1091B0(0x2B) < *(s32 *)&pad60) {
                m_unk4C = 0;
                goto s4;
            }
            m_unk4 = -0x133; done = 1; goto loop;
        }
    s4:
        m_state = 4;
        m_unk58->Start();
    case -0x144:
        if (((CStatusItemX *)m_unk58)->m_state != 0) {
            m_unk4 = -0x144; done = 1; goto loop;
        }
        m_state = 5;
        m_unk4 = -0x148;
    case -0x148:
        done = 1; goto loop;
    }
out:
    m_unk58->Func1A40C8();
end:;
}

s32 CMenuExGetMoney::Draw() {
    f32 x, y;
    char buf[0x100];
    CVec4 col;
    u8 *p;
    if (!m_unk58) {
        Func225088();
        Func2250C0();
    } else {
        p = (u8 *)Func237570(0x60);
        Func237A88(p, 6);
        Func238158(Func237C30(p + 0x50), 1);
        ((CUnk237E90 *)(p + 0x10))->Func237E90(((CUnk1A4298 *)m_unk58)->Func1A4298());
        ((CUnk237E90 *)(p + 0x20))->Func237E90(func_001B5E18(D_002A5534));
        D_002A5534->Reset();
        D_002A5534->SetUnk30(1);
        D_002A5534->SetUnk0(1.0f, 1.0f);
        D_002A5534->SetUnk34(0);
        D_002A5534->SetUnk1C(m_unk58->m_unk34);
        m_unk58->GetColor(&col, 9);
        D_002A5534->SetUnk10(col.x * 0.0078125f, col.y * 0.0078125f, col.z * 0.0078125f);
        sprintf(buf, D_002DA470, D_002A5358->Func1091B0(0x25E));
        m_unk58->GetPos(&x, &y, 9);
        ((CUnk237E90 *)(p + 0x20))->Func237E90(func_001B5FE0(D_002A5534, x, y, buf));
        if (m_unk5C == 1) D_002A5534->SetUnk1C(m_unk74);
        else D_002A5534->SetUnk1C(m_unk58->m_unk34);
        m_unk58->GetColor(&col, 10);
        D_002A5534->SetUnk10(col.x * 0.0078125f, col.y * 0.0078125f, col.z * 0.0078125f);
        sprintf(buf, D_002DA470, m_unk70);
        m_unk58->GetPos(&x, &y, 10);
        ((CUnk237E90 *)(p + 0x20))->Func237E90(func_001B5FE0(D_002A5534, x, y, buf));
        ((CUnk237E90 *)(p + 0x30))->Func237E90(((CMenuMgr *)D_002A5530)->Func1B4ED0(D_002A5530->GetEntry0(0x18)));
        D_002A5530->Reset1B4D28();
        D_002A5530->SetUnk4C(m_unk58->m_unk34);
        m_unk58->GetPos(&x, &y, 8);
        D_002A5530->SetUnk20(x, y, 0.0f);
        ((CUnk237E90 *)(p + 0x30))->Func237E90(func_001B50B0(D_002A5530, 0x18));
        Func225088();
        Func225240((int)p);
        Func2250C0();
    }
}
INCLUDE_RODATA("asm/nonmatchings/CMenuExGetMoney", D_002DA470);

CMenuConfig *CreateCMenuConfig() {
    return new CMenuConfig;
}
