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
    void GetPos(f32 *x, f32 *y, s32 i);

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
#include "CMenuMgrSub1B6418.h"
extern CMenuMgrSub1B6418 *D_002A5538;
extern "C" int func_001B66E8(CMenuMgrSub1B6418 *p);
extern "C" int sprintf(char *buf, const char *fmt, ...);
void *Func237570(int size);
void Func237A88(void *p, int n);
void *Func237C30(void *p);
void Func238158(void *p, int v);
void Func225240(int v);
#include "CFlagWork.h"
extern CFlagWork *D_002A5358;
extern char D_002DBB08[];

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuGetMoney.
class CMenuGetMoney : public CMenuProcess {
public:
    CMenuGetMoney();
    virtual ~CMenuGetMoney();
    virtual void Update();
    virtual s32 Draw();

    CStatusItem *m_unk58;     // 0x58
    CStatusItem *m_unk5C;     // 0x5C
    s32 m_unk60;              // 0x60
    u8 pad64[0x4];
    s32 m_unk68;              // 0x68
    s32 m_unk6C;              // 0x6C
    s32 m_unk70;              // 0x70
    s32 m_unk74;              // 0x74
    f32 m_unk78;              // 0x78
};

extern "C" void func_001900B0(void *p);
class CMenuReviewResult {
public:
    static CMenuReviewResult *Create();
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
class CMenuGetMoneyPart {
public:
    void SetRate(f32 t);
    void SetScale(f32 t);
};
// @decl-end

CMenuGetMoney::CMenuGetMoney() {
    m_unk58 = 0;
    m_unk5C = 0;
    m_unk78 = 1.0f;
    m_unk68 = 0;
    m_unk6C = 0;
    m_unk70 = 0;
    m_unk74 = 0;
    m_unk60 = 0;
}

CMenuGetMoney::~CMenuGetMoney() {
}

void CMenuGetMoney::Update() {
    s32 a, b, c;
    char buf[0x200];
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
        u32 fl = (u16)m_unk0;
        if ((fl >> 7) & 1) goto out;
    }
    switch (m_unk4) {
    case -1: {
        m_unk58 = D_002A5408->Find("getmoney1");
        if (!m_unk58) { Func235DE0("*** Can't Get %s Window\n", "getmoney1"); return; }
        m_unk58->Func1A3378();
        m_unk5C = D_002A5408->Find("getmoney2");
        if (!m_unk5C) { Func235DE0("*** Can't Get %s Window\n", "getmoney2"); return; }
        m_unk5C->Func1A3378();
        D_002A5538->SetUnkE0(0);
        m_unk58->Select(-1);
        m_unk5C->Select(-1);
        {
            s32 x = D_002A5358->Func1091B0(0x24E);
            s32 y = D_002A5358->Func1091B0(0x24F);
            s32 z = D_002A5358->Func1091B0(0x250);
            m_unk70 = 0;
            m_unk68 = x + y + z;
        }
        m_unk74 = D_002A5358->Func1091B0(0x24D);
        m_unk6C = m_unk74 + m_unk68;
        m_unk78 = 1.0f;
        m_unk60 = 0;
        m_unk58->Func1A3628();
    }
    case -0xF5:
        if (((CStatusItemX *)m_unk58)->m_state != 2) {
            m_unk4 = -0xF5; done = 1; goto loop;
        }
        m_unk5C->Func1A3628();
    case -0x103:
        if (((CStatusItemX *)m_unk5C)->m_state != 2) {
            m_unk4 = -0x103; done = 1; goto loop;
        }
        m_unk4 = -0x108; done = 1; goto loop;
    case -0x108:
        *(s32 *)&pad64 = 0;
        m_unk60 = 1;
        D_002A5468->Play(0x4C);
        while (*(s32 *)&pad64 < D_002A4B60->Func1091B0(0x29)) {
            if (a & 0x60) goto cA;
            (*(s32 *)&pad64)++;
            ((CMenuGetMoneyPart *)this)->SetRate((f32)*(s32 *)&pad64 / (f32)D_002A4B60->Func1091B0(0x29));
            m_unk4 = -0x11D; done = 1; goto loop;
    case -0x11D:;
        }
        m_unk4 = -0x123; done = 1; goto loop;
        if (0) {
    cA:
            D_002A5468->Play(0x4D);
            D_002A5468->Stop(0x4C);
            m_unk4C = -1;
            goto y140;
        }
    case -0x123:
        *(s32 *)&pad64 = 0;
        D_002A5468->Play(0x4D);
        while (*(s32 *)&pad64 < D_002A4B60->Func1091B0(0x2A)) {
            if (*(s32 *)&pad64 == D_002A4B60->Func1091B0(0x2F)) D_002A5468->Stop(0x4C);
            if (a & 0x60) {
                D_002A5468->Stop(0x4C);
                m_unk4C = -1;
                goto y140;
            }
            (*(s32 *)&pad64)++;
            ((CMenuGetMoneyPart *)this)->SetScale((f32)*(s32 *)&pad64 / (f32)D_002A4B60->Func1091B0(0x2A));
            m_unk4 = -0x13B; done = 1; goto loop;
    case -0x13B:;
        }
    y140:
        m_unk4 = -0x140; done = 1; goto loop;
        if (0) {
    c3:
            D_002A5468->Play(3);
            m_unk4C = -1;
            goto s4;
        }
    case -0x140:
        m_unk74 = m_unk6C;
        m_unk70 = m_unk68;
        m_unk60 = 0;
        *(s32 *)&pad64 = 0;
        for (;;) {
    case -0x157:
            if (a & 0x60) goto c3;
            (*(s32 *)&pad64)++;
            if (D_002A4B60->Func1091B0(0x2B) < *(s32 *)&pad64) {
                m_unk4C = 0;
                goto s4;
            }
            m_unk4 = -0x157; done = 1; goto loop;
        }
    s4:
        m_state = 4;
        m_unk58->Start();
        m_unk5C->Start();
        do {
    case -0x16A:
        if (((CStatusItemX *)m_unk58)->m_state != 0 || ((CStatusItemX *)m_unk5C)->m_state != 0) {
            m_unk4 = -0x16A; done = 1; goto loop;
        }
        } while (0);
        m_state = 5;
        m_unk4 = -0x16E;
    case -0x16E:
        done = 1; goto loop;
    }
out:
    m_unk58->Func1A40C8();
    m_unk5C->Func1A40C8();
end:;
}

INCLUDE_RODATA("asm/nonmatchings/CMenuGetMoney", D_002DBB08);
INCLUDE_ASM("asm/nonmatchings/CMenuGetMoney", Draw__13CMenuGetMoney);

CMenuReviewResult *CMenuReviewResult::Create() {
    CMenuReviewResult *p = (CMenuReviewResult *)operator new(0x78);
    func_001900B0(p);
    return p;
}
