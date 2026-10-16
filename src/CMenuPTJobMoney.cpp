#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

class CMenuGetMoney {
public:
    CMenuGetMoney() throw();
    static CMenuGetMoney *Create();

    u8 pad0[0x7C];
};

#include "CFlagWork.h"
extern CFlagWork *D_002A5358;
extern char D_002DBA30[];

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuPTJobMoney.
class CMenuPTJobMoney : public CMenuProcess {
public:
    CMenuPTJobMoney();
    virtual ~CMenuPTJobMoney();
    virtual s32 Update();
    virtual s32 Draw();

    s32 m_unk58;              // 0x58
    s32 m_unk5C;              // 0x5C
    s32 m_unk60;              // 0x60
    u8 pad64[0x4];
    s32 m_childNum;           // 0x68
    s32 m_unk6C;              // 0x6C
    s32 m_unk70;              // 0x70
    s32 m_unk74;              // 0x74
    s32 m_unk78;              // 0x78
    f32 m_unk7C;              // 0x7C
};

inline f32 Clamp01(f32 v) { return (v < 1.0f ? v : 1.0f) < 0.0f ? 0.0f : (v < 1.0f ? v : 1.0f); }
// CMenuGetMoney's unit starts here (its text starts before its first vtable function).
class CMenuGetMoneyPart {
public:
    void SetRate(f32 v);
    void SetScale(f32 v);

    u8 pad0[0x68];
    s32 m_unk68;              // 0x68
    u8 pad6C[0x4];
    s32 m_unk70;              // 0x70
    s32 m_unk74;              // 0x74
    f32 m_unk78;              // 0x78
};

class CStatusItem;
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
class CMenuCommonSub18E638 {
public:
    void SetRate(f32 t);
    void SetScale(f32 t);
};
class CStatusItem {
public:
    void Func1A3378();
    void Func1A3628();
    int Select(s32 i);
    void Start();
    void Func1A40C8();
    const char *GetUnkE4(s32 k);
    void SetText(s32 k, const char *s);
};
void Func185AA0(char *buf, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern "C" int sprintf(char *buf, const char *fmt, ...);
// @decl-end

CMenuPTJobMoney::CMenuPTJobMoney() {
    m_unk58 = 0;
    m_unk5C = 0;
    m_childNum = D_002A5358->Func1091B0(0x251);
    if ((u32)m_childNum >= 7) {
        Func235DE0(D_002DBA30, m_childNum);
        m_childNum = 1;
    }
    m_unk60 = 0;
    m_unk6C = 0;
    m_unk70 = 0;
    m_unk74 = 0;
    m_unk78 = 0;
    m_unk7C = 1.0f;
}

CMenuPTJobMoney::~CMenuPTJobMoney() {
}

INCLUDE_RODATA("asm/nonmatchings/CMenuPTJobMoney", D_002DBA30);
s32 CMenuPTJobMoney::Update() {
    s32 a, b, c;
    char name[0x200];
    char buf[0x100];
    s32 done;
    s32 i;
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
        sprintf(name, "ptjob%da", m_childNum);
        m_unk58 = (s32)D_002A5408->Find(name);
        if (!m_unk58) return Func235DE0("*** Can't Get %s Window\n", name);
        ((CStatusItem *)m_unk58)->Func1A3378();
        sprintf(name, "ptjob%db", m_childNum);
        m_unk5C = (s32)D_002A5408->Find(name);
        if (!m_unk5C) return Func235DE0("*** Can't Get %s Window\n", name);
        ((CStatusItem *)m_unk5C)->Func1A3378();
        for (i = 0; i < m_childNum; i++) {
            Func185AA0(buf, D_002A5358->Func1091B0(0x252 + i), -1, -1, -1, -1, -1);
            sprintf(name, ((CStatusItem *)m_unk58)->GetUnkE4(i + 8), buf);
            ((CStatusItem *)m_unk58)->SetText(i + 8, name);
        }
        D_002A5538->SetUnkE0(0);
        ((CStatusItem *)m_unk58)->Select(-1);
        ((CStatusItem *)m_unk5C)->Select(-1);
        m_unk6C = 0;
        for (s32 j = 0; j < m_childNum; j++) m_unk6C += D_002A5358->Func1091B0(0x258 + j);
        m_unk74 = 0;
        m_unk78 = D_002A5358->Func1091B0(0x24D);
        m_unk70 = m_unk78 + m_unk6C;
        m_unk60 = 0;
        ((CStatusItem *)m_unk58)->Func1A3628();
        do {
    case -0x10B:
        if (((CStatusItemX *)m_unk58)->m_state != 2) {
            m_unk4 = -0x10B; done = 1; goto loop;
        }
        } while (0);
        ((CStatusItem *)m_unk5C)->Func1A3628();
    case -0x119:
        if (((CStatusItemX *)m_unk5C)->m_state != 2) {
            m_unk4 = -0x119; done = 1; goto loop;
        }
        m_unk4 = -0x11E; done = 1; goto loop;
    case -0x11E:
        *(s32 *)&pad64 = 0;
        m_unk60 = 1;
        D_002A5468->Play(0x4C);
        while (*(s32 *)&pad64 < D_002A4B60->Func1091B0(0x2C)) {
            if (a & 0x60) goto cA;
            (*(s32 *)&pad64)++;
            ((CMenuCommonSub18E638 *)this)->SetRate((f32)*(s32 *)&pad64 / (f32)D_002A4B60->Func1091B0(0x2C));
            m_unk4 = -0x133; done = 1; goto loop;
    case -0x133:;
        }
        m_unk4 = -0x138; done = 1; goto loop;
        if (0) {
    cA:
            D_002A5468->Play(0x4D);
            D_002A5468->Stop(0x4C);
            m_unk4C = -1;
            goto y155;
        }
    case -0x138:
        *(s32 *)&pad64 = 0;
        D_002A5468->Play(0x4D);
        while (*(s32 *)&pad64 < D_002A4B60->Func1091B0(0x2D)) {
            if (*(s32 *)&pad64 == D_002A4B60->Func1091B0(0x2F)) D_002A5468->Stop(0x4C);
            if (a & 0x60) {
                D_002A5468->Stop(0x4C);
                m_unk4C = -1;
                goto y155;
            }
            (*(s32 *)&pad64)++;
            ((CMenuCommonSub18E638 *)this)->SetScale((f32)*(s32 *)&pad64 / (f32)D_002A4B60->Func1091B0(0x2D));
            m_unk4 = -0x150; done = 1; goto loop;
    case -0x150:;
        }
    y155:
        m_unk4 = -0x155; done = 1; goto loop;
        if (0) {
    c3:
            D_002A5468->Play(3);
            m_unk4C = -1;
            goto s4;
        }
    case -0x155:
        m_unk78 = m_unk70;
        m_unk74 = m_unk6C;
        m_unk60 = 0;
        *(s32 *)&pad64 = 0;
        for (;;) {
    case -0x16B:
            if (a & 0x60) goto c3;
            (*(s32 *)&pad64)++;
            if (D_002A4B60->Func1091B0(0x2E) < *(s32 *)&pad64) {
                m_unk4C = 0;
                goto s4;
            }
            m_unk4 = -0x16B; done = 1; goto loop;
        }
    s4:
        m_state = 4;
        ((CStatusItem *)m_unk58)->Start();
        ((CStatusItem *)m_unk5C)->Start();
        do {
    case -0x17E:
        if (((CStatusItemX *)m_unk58)->m_state != 0 || ((CStatusItemX *)m_unk5C)->m_state != 0) {
            m_unk4 = -0x17E; done = 1; goto loop;
        }
        } while (0);
        m_state = 5;
        m_unk4 = -0x182;
    case -0x182:
        done = 1; goto loop;
    }
out:
    ((CStatusItem *)m_unk58)->Func1A40C8();
    ((CStatusItem *)m_unk5C)->Func1A40C8();
end:;
}

INCLUDE_ASM("asm/nonmatchings/CMenuPTJobMoney", Draw__15CMenuPTJobMoney);

CMenuGetMoney *CMenuGetMoney::Create() {
    return new CMenuGetMoney;
}

void CMenuGetMoneyPart::SetRate(f32 v) {
    f32 r = Clamp01(v);
    m_unk70 = (s32)(m_unk68 * r);
    m_unk74 = (s32)(f32)m_unk70 + D_002A5358->Func1091B0(0x24D);
}

void CMenuGetMoneyPart::SetScale(f32 v) {
    m_unk78 = 2.0f - Clamp01(v);
}
