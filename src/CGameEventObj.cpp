#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CFlagWork.h"
#include "CGameDBMgr.h"
#include "IUserFlagMgr.h"
extern CFlagWork *D_002A5358;
extern char D_002D9820[];
int Func235DE0(const char *fmt, ...) throw();
extern "C" void func_00108EA0(CFlagWork *w, s32 id, const char *s);
#include "CProcess.h"
// The event-script base (CEventObj unit): fields up to 0xFEC4, then its vptr (one slot, the
// destructor).
class CEventObj {
public:
    virtual ~CEventObj();

    u8 pad0[0xFEC4];
};
// A resource object (vptr at 0xC: destructor, Load, Release) owned at 0x10134.
class CGameEventRes {
public:
    virtual ~CGameEventRes();
    virtual s32 Load(const char *name);
    virtual void Release();

    u8 pad0[0xC];
    // vptr 0xC
};
// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CGameEventObj.
class CGameEventObj : public CEventObj {
public:
    void Func1640E0(s32 k);
    virtual ~CGameEventObj();
    void Func165380(s32 k);
    void Func164878(s32 k);
    void Func164D38(s32 k);
    void Func163908();
    void Func164EF0();
    void Func165FF0();
    void Func1650E8();
    void Func163DD0();
    void Func1656B8();
    void Func165B18();
    void Func164A08();
    s32 Func165410(s32 a, s32 b, s32 c, s32 lo, s32 hi);
    s32 Func165A70(s32 k);
    s32 Func165ED0(s32 k);
    s32 Func166208(s32 k);
    s32 Func166348(s32 k);
    s32 Func166548(s32 k);

    s32 m_unkFEC8;            // 0xFEC8
    CStateMachine m_sm;       // 0xFECC
    CBgWork m_bg;             // 0xFF14
    s32 m_unkFF20;            // 0xFF20
    u8 padFF24[0x8];
    s32 m_count;              // 0xFF2C
    s32 m_ids[0x80];          // 0xFF30
    s32 m_unk10130;           // 0x10130
    CGameEventRes *m_res;     // 0x10134
    s32 m_unk10138;           // 0x10138
};
// &m_ids[k], computed as this + (k * 4 + 0xFF30) as retail does. A free function: an inline
// member would be emitted out of line now that the key method (~CGameEventObj) is here.
inline s32 *IdPtr(CGameEventObj *obj, s32 k) {
    u32 o = k * 4 + 0xFF30;
    return (s32 *)((u8 *)obj + o);
}

extern char D_002D9648[], D_002D97B0[], D_002D97D0[], D_002D97E0[], D_002D97F0[];
s32 Func163880(s32 v);
s32 Func165F78(s32 v);

// Text resource manager at D_002BA1D0 (library side); slot 3 looks up a string by id.
class CTextMgr2BA1D0 {
public:
    virtual void Vf0();
    virtual void Vf1();
    virtual void Vf2();
    virtual const char *GetText(s32 id);
};
extern CTextMgr2BA1D0 *D_002BA1D0;

extern s32 D_002A34A0[];
extern s32 D_002A34B8[];

extern char D_002D97F8[], D_002D98C0[], D_002D98D0[];

extern char D_002D98B0[];

#include "CProcess.h"
class CGameResort : public CProcess {
public:
    CGameResort(s32 a, s32 b, s32 c, s32 d);
    virtual ~CGameResort();
    u8 pad18[0x6D0 - 0x18];
};
class CTaskList24F5C0 {
public:
    s32 Func24F5C0(void *task, s32 pri);
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CGameEventObj", __13CGameEventObji);

CGameEventObj::~CGameEventObj() {
    CGameEventRes *r;
    func_00245818(&m_bg, 1);
    r = m_res;
    if (r) {
        r->Release();
        delete r;
    }
}

INCLUDE_RODATA("asm/nonmatchings/CGameEventObj", D_002D9590);
INCLUDE_RODATA("asm/nonmatchings/CGameEventObj", D_002D9598);
INCLUDE_RODATA("asm/nonmatchings/CGameEventObj", D_002D95A0);
INCLUDE_RODATA("asm/nonmatchings/CGameEventObj", D_002D95A8);
INCLUDE_RODATA("asm/nonmatchings/CGameEventObj", D_002D95B0);
INCLUDE_RODATA("asm/nonmatchings/CGameEventObj", D_002D95B8);
INCLUDE_RODATA("asm/nonmatchings/CGameEventObj", D_002D95D8);
INCLUDE_ASM("asm/nonmatchings/CGameEventObj", func_001602F8);
INCLUDE_RODATA("asm/nonmatchings/CGameEventObj", D_002D9648);
INCLUDE_RODATA("asm/nonmatchings/CGameEventObj", D_002D9650);
INCLUDE_RODATA("asm/nonmatchings/CGameEventObj", D_002D9658);
INCLUDE_RODATA("asm/nonmatchings/CGameEventObj", D_002D9660);
INCLUDE_RODATA("asm/nonmatchings/CGameEventObj", D_002D9678);
INCLUDE_RODATA("asm/nonmatchings/CGameEventObj", D_002D9690);
INCLUDE_RODATA("asm/nonmatchings/CGameEventObj", D_002D96A8);
INCLUDE_RODATA("asm/nonmatchings/CGameEventObj", D_002D96C0);
INCLUDE_RODATA("asm/nonmatchings/CGameEventObj", D_002D96D8);
INCLUDE_RODATA("asm/nonmatchings/CGameEventObj", D_002D96F8);
INCLUDE_RODATA("asm/nonmatchings/CGameEventObj", D_002D9718);
INCLUDE_RODATA("asm/nonmatchings/CGameEventObj", D_002D9730);
INCLUDE_RODATA("asm/nonmatchings/CGameEventObj", D_002D9748);
INCLUDE_RODATA("asm/nonmatchings/CGameEventObj", D_002D9760);
INCLUDE_RODATA("asm/nonmatchings/CGameEventObj", D_002D9778);
INCLUDE_RODATA("asm/nonmatchings/CGameEventObj", D_002D9790);
INCLUDE_RODATA("asm/nonmatchings/CGameEventObj", D_002D97B0);
INCLUDE_RODATA("asm/nonmatchings/CGameEventObj", D_002D97D0);
INCLUDE_RODATA("asm/nonmatchings/CGameEventObj", D_002D97E0);
INCLUDE_RODATA("asm/nonmatchings/CGameEventObj", D_002D97F0);

s32 Func163880(s32 v) {
    s32 i, n = 0;
    for (i = 0; i < D_002A26E4->Func1091B0(0x27); i++) {
        if (D_002A26E4->Func1091B0(i + 0x3A) == v) n++;
    }
    return n;
}

void CGameEventObj::Func163908() {
    s32 ids[0x100];
    s32 i, n;
    n = D_002A2988->Collect14BC20(ids, 0x100);
    for (i = 0; i < n; i++) {
        CGameDBRec *r = D_002A2988->GetUnk20(ids[i]);
        s32 k, v;
        if (!r) continue;
        k = D_002A26E4->Func1091B0(0x27);
        v = r->m_unk4;
        D_002A26E4->Func108FF0(k + 0x28, v);
        D_002A26E4->Func108FF0(k + 0x34, 0);
        D_002A26E4->Func108FF0(k + 0x46, 1);
        D_002A26E4->Func108FF0(k + 0xD6, 1);
        D_002A26E4->Func108FF0(k + 0x3A, v >= 0x14);
        D_002A26E4->Func108FF0(k + 0x40, Func163880(v >= 0x14));
        D_002A26E4->Func108FF0(k + 0x9A, 4);
        D_002A26E4->Func108FF0(k + 0xA0, 4);
        D_002A26E4->Func108FF0(k + 0xA6, 4);
        D_002A26E4->Func108FF0(k + 0xAC, 4);
        D_002A26E4->Func108FF0(k + 0xB2, 4);
        func_00108EA0(D_002A26E4, k + 0x2E, D_002D9648);
        D_002A26E4->Set144C60(0x496, k, D_002A26E4->Func1091B0(k + 0x46), 1);
        D_002A26E4->Set144C60(0x736, k, D_002A26E4->Func1091B0(k + 0xD6), 1);
        D_002A26E4->Set144C60(0x6D6, k, D_002A26E4->Func1091B0(k + 0xB8), 1);
        D_002A26E4->Func109108(0x27, 1);
    }
}

s32 CheckFlags163B98(s32 a, s32 b) {
    s32 v[4];
    s32 w[4];
    s32 i;
    v[0] = D_002A26E4->Get144B68(0x316, a, b);
    v[1] = D_002A26E4->Get144B68(0x376, a, b);
    v[2] = D_002A26E4->Get144B68(0x3D6, a, b);
    v[3] = D_002A26E4->Get144B68(0x436, a, b);
    w[0] = D_002A26E4->Vf299248(a);
    w[1] = D_002A26E4->Vf2992C8(a);
    w[2] = D_002A26E4->Vf299348(a);
    w[3] = D_002A26E4->Vf2993C8(a);
    Func235DE0(D_002D97B0, a, b);
    for (i = 0; i < 4; i++) {
        Func235DE0(D_002D97D0, i, v[i], w[i]);
    }
    for (i = 0; i < 4; i++) {
        if (v[i] > 0 && w[i] < v[i]) {
            Func235DE0(D_002D97E0);
            return 0;
        }
    }
    Func235DE0(D_002D97F0);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/CGameEventObj", func_00163DD0);
INCLUDE_RODATA("asm/nonmatchings/CGameEventObj", D_002D9820);

// GNU as 2.10 assembles a lui here as lw unless the function starts on a fresh .p2align (docs/lessons.md).
asm(".p2align 3");
void CGameEventObj::Func1640E0(s32 k) {
    s32 v;
    if (m_ids[k] == 0x401) {
        D_002A26E4->Func108FF0(0x15, 0);
        D_002A26E4->Func108FF0(m_unkFF20 + 0x58, 9);
        D_002A26E4->Func108FF0(m_unkFF20 + 0x5E, 0);
    } else {
    D_002A26E4->Func108FF0(0x15, m_ids[k]);
    switch (D_002A26E4->Func1091B0(m_unkFF20 + 0x46)) {
    case 2:
        v = 3;
        break;
    case 3:
        v = 4;
        break;
    case 4:
        v = 5;
        break;
    case 5:
    case 7:
    case 8:
        v = 6;
        break;
    default:
        Func235DE0(D_002D9820, D_002A26E4->Func1091B0(m_unkFF20 + 0x46));
        return;
    }
    D_002A26E4->Func108FF0(m_unkFF20 + 0x58, v);
    D_002A26E4->Func108FF0(m_unkFF20 + 0x5E, m_ids[k]);
    }
}

INCLUDE_ASM("asm/nonmatchings/CGameEventObj", func_00164290);

void CGameEventObj::Func164878(s32 k) {
    s32 v;
    s32 *p;
    D_002A26E4->Func108FF0(0x15, m_ids[k]);
    switch (D_002A26E4->Func1091B0(m_unkFF20 + 0x46)) {
    case 2:
        v = 3;
        break;
    case 3:
        v = 4;
        break;
    case 4:
        v = 5;
        break;
    case 5:
    case 7:
    case 8:
        v = 6;
        break;
    default:
        Func235DE0(D_002D9820, D_002A26E4->Func1091B0(m_unkFF20 + 0x46));
        return;
    }
    p = IdPtr(this, k);
    D_002A26E4->Func108FF0(m_unkFF20 + 0x64, v);
    D_002A26E4->Func108FF0(m_unkFF20 + 0x6A, *p);
    D_002A26E4->MoveMoney(D_002A2988->Find1E8(*p)->m_unk18);
}

INCLUDE_RODATA("asm/nonmatchings/CGameEventObj", D_002D98B0);
void CGameEventObj::Func164A08() {
    s32 t;
    D_002A5358->Func108700();
    D_002A5358->Func108FF0(0x260, 1);
    D_002A5358->Func108FF0(0x261, m_unkFF20);
    m_count = 0;
    t = D_002A2988->Vf14F380(m_unkFF20, D_002A2988->FindType8());
    Func235DE0(D_002D98B0, D_002A2988->Vf14F2A0(m_unkFF20), t);
    func_00108EA0(D_002A5358, m_count + 0x263, D_002BA1D0->GetText(0x3ED));
    D_002A5358->Func108FF0(m_count + 0x26E, D_002A2988->FindType8());
    D_002A5358->Func108FF0(m_count + 0x279, D_002A2988->Vf14F2A0(m_unkFF20));
    m_ids[m_count++] = D_002A2988->FindType8();
    func_00108EA0(D_002A5358, m_count + 0x263, D_002BA1D0->GetText(0x3EE));
    D_002A5358->Func108FF0(m_count + 0x279, 1);
    m_ids[m_count++] = 0x400;
    func_00108EA0(D_002A5358, m_count + 0x263, D_002BA1D0->GetText(0x3EF));
    D_002A5358->Func108FF0(m_count + 0x279, 1);
    m_ids[m_count++] = 0;
    D_002A5358->Func108FF0(0x262, m_count);
    D_002A5358->Func108FF0(0x28F, -1);
}
INCLUDE_RODATA("asm/nonmatchings/CGameEventObj", D_002D98C0);
INCLUDE_RODATA("asm/nonmatchings/CGameEventObj", D_002D98D0);

void CGameEventObj::Func164D38(s32 k) {
    s32 *p = IdPtr(this, k);
    if (*p == 0x400) {
        D_002A26E4->Func108FF0(0x15, 0);
        D_002A26E4->Func108FF0(m_unkFF20 + 0x64, 7);
        D_002A26E4->Func108FF0(m_unkFF20 + 0x6A, 0);
        return;
    }
    D_002A26E4->Func108FF0(0x15, *p);
    D_002A26E4->Func108FF0(m_unkFF20 + 0x64, 8);
    D_002A26E4->Func108FF0(m_unkFF20 + 0x6A, *p);
    if (D_002A2988->Vf14F380(m_unkFF20, D_002A2988->FindType8())) return;
    D_002A26E4->MoveMoney(D_002A2988->Find1E8(D_002A2988->FindType8())->m_unk18);
}

void CGameEventObj::Func164EF0() {
    s32 ids[0x80];
    s32 vals[0x100];
    s32 i, n;
    D_002A5358->Func108700();
    D_002A5358->Func108FF0(0x260, 6);
    D_002A5358->Func108FF0(0x261, m_unkFF20);
    m_count = 0;
    n = D_002A2988->Vf14C2B0(ids, vals, m_unkFF20);
    for (i = 0; i < n; i++) {
        CGameDBRec *r = D_002A2988->Find200(ids[i]);
        if (r) {
            func_00108EA0(D_002A5358, m_count + 0x263, r->m_unk8);
            D_002A5358->Func108FF0(m_count + 0x26E, r->m_unk0);
            D_002A5358->Func108FF0(m_count + 0x279, vals[i]);
            m_ids[m_count++] = ids[i];
        }
    }
    D_002A5358->Func108FF0(0x262, m_count);
    D_002A5358->Func108FF0(0x28F, -1);
}

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_001650E0() {
}

void CGameEventObj::Func1650E8() {
    s32 ids[0x80];
    s32 vals[0x80];
    s32 i, n;
    D_002A5358->Func108700();
    D_002A5358->Func108FF0(0x260, 4);
    D_002A5358->Func108FF0(0x261, m_unkFF20);
    m_count = 0;
    n = D_002A2988->Vf14C2B0(ids, vals, m_unkFF20);
    for (i = 0; i < n; i++) {
        CGameDBRec *r = D_002A2988->Find200(ids[i]);
        if (r) {
            func_00108EA0(D_002A5358, m_count + 0x263, r->m_unk8);
            D_002A5358->Func108FF0(m_count + 0x26E, r->m_unk0);
            D_002A5358->Func108FF0(m_count + 0x279, vals[i]);
            m_ids[m_count++] = ids[i];
        }
    }
    if (D_002A26E4->Func1091B0(m_unkFF20 + 0x46) != 6) {
        func_00108EA0(D_002A5358, m_count + 0x263, D_002BA1D0->GetText(0x3F0));
        D_002A5358->Func108FF0(m_count + 0x279, 1);
        m_ids[m_count++] = 0;
    }
    D_002A5358->Func108FF0(0x262, m_count);
    D_002A5358->Func108FF0(0x28F, -1);
}

void CGameEventObj::Func165380(s32 k) {
    s32 *p = IdPtr(this, k);
    D_002A26E4->Func108FF0(0x15, *p);
    D_002A26E4->Func108FF0(m_unkFF20 + 0x64, 9);
    D_002A26E4->Func108FF0(m_unkFF20 + 0x6A, *p);
}

s32 CGameEventObj::Func165410(s32 a, s32 b, s32 c, s32 lo, s32 hi) {
    s32 v[5];
    s32 i, j, k;
    s32 sum1, sum2;
    for (i = 0; i < 5; i++) {
        v[i] = D_002A26E4->GetNamed(D_002A34A0[i], c);
    }
    sum1 = 0;
    for (i = 0; i < 5; i++) {
        sum1 += D_002A2988->Vf14F550(c, D_002A34A0[i], v[i]);
    }
    for (k = lo; k <= hi; k++) {
        s32 r = D_002A2988->Get150590(a, b, c, k);
        for (j = 0; D_002A34B8[j] >= 0; j++) {
            if (D_002A34B8[j] == r) break;
        }
        if (D_002A34B8[j] < 0) continue;
        v[j] += D_002A2988->Get150630(a, b, c, k);
        v[j] = v[j] < 0 ? 0 : (v[j] < 10 ? v[j] : 9);
    }
    sum2 = 0;
    for (i = 0; i < 5; i++) {
        sum2 += D_002A2988->Vf14F550(m_unkFF20, D_002A34A0[i], v[i]);
    }
    return sum1 - sum2;
}

void CGameEventObj::Func1656B8() {
    s32 ids[0x100];
    s32 i, n;
    s32 best = -1;
    s32 bestv = 0;
    s32 first = -1;
    s32 sel;
    D_002A5358->Func108700();
    D_002A5358->Func108FF0(0x260, 2);
    D_002A5358->Func108FF0(0x261, m_unkFF20);
    m_count = 0;
    n = D_002A2988->Vf14C800(ids, m_unkFF20);
    for (i = 0; i < n; i++) {
        CGameDBRec *r = D_002A2988->Find220(ids[i]);
        s32 d;
        if (!r) continue;
        func_00108EA0(D_002A5358, m_count + 0x263, r->m_unk8);
        D_002A5358->Func108FF0(m_count + 0x26E, r->m_unk0);
        D_002A5358->Func108FF0(m_count + 0x279, 1);
        m_ids[m_count] = ids[i];
        if (first < 0 && !D_002A26E0->Get144378(0x23F8, m_unkFF20, ids[i])) {
            first = m_count;
        }
        d = Func165410(4, ids[i], m_unkFF20, 0, 1);
        if (d > 0 && (best < 0 || bestv < d)) {
            best = m_count;
            bestv = d;
        }
        m_count++;
    }
    func_00108EA0(D_002A5358, m_count + 0x263, D_002BA1D0->GetText(0x3EA));
    D_002A5358->Func108FF0(m_count + 0x279, 1);
    D_002A5358->Func108FF0(m_count + 0x290, 1);
    m_ids[m_count++] = 0;
    D_002A5358->Func108FF0(0x262, m_count);
    sel = -1;
    if (D_002A2988->TestBits14F478(m_unkFF20)) {
        sel = best;
        Func235DE0(D_002D98C0, sel);
    } else {
        if (D_002A26E0->SumFlags() >= 11) sel = first;
        Func235DE0(D_002D98D0, sel);
    }
    D_002A5358->Func108FF0(0x28F, sel);
}

s32 CGameEventObj::Func165A70(s32 k) {
    s32 *p = IdPtr(this, k);
    D_002A26E4->Func108FF0(0x15, *p);
    if (!D_002A2988->Find220(*p)) return 0;
    D_002A26E4->Func108FF0(m_unkFF20 + 0xDC, *p);
    return 1;
}

void CGameEventObj::Func165B18() {
    s32 ids[0x80];
    s32 i, n;
    s32 best = -1;
    s32 bestv = 0;
    s32 first = -1;
    s32 sel;
    D_002A5358->Func108700();
    D_002A5358->Func108FF0(0x260, 3);
    D_002A5358->Func108FF0(0x261, m_unkFF20);
    m_count = 0;
    n = D_002A2988->Vf14C648(ids, m_unkFF20);
    for (i = 0; i < n; i++) {
        CGameDBRec *r = D_002A2988->Find20C(ids[i]);
        s32 d;
        if (!r) continue;
        func_00108EA0(D_002A5358, m_count + 0x263, r->m_unk8);
        D_002A5358->Func108FF0(m_count + 0x26E, r->m_unk0);
        D_002A5358->Func108FF0(m_count + 0x279, 1);
        m_ids[m_count] = ids[i];
        if (first < 0 && !D_002A26E0->Get144378(0x23F8, m_unkFF20, ids[i])) {
            first = m_count;
        }
        d = Func165410(4, ids[i], m_unkFF20, 0, 1);
        if (d > 0 && (best < 0 || bestv < d)) {
            best = m_count;
            bestv = d;
        }
        m_count++;
    }
    func_00108EA0(D_002A5358, m_count + 0x263, D_002BA1D0->GetText(0x3EB));
    D_002A5358->Func108FF0(m_count + 0x279, 1);
    D_002A5358->Func108FF0(m_count + 0x290, 1);
    m_ids[m_count++] = 0;
    D_002A5358->Func108FF0(0x262, m_count);
    sel = -1;
    if (D_002A2988->TestBits14F478(m_unkFF20)) {
        sel = best;
        Func235DE0(D_002D98C0, sel);
    } else {
        if (D_002A26E0->SumFlags() >= 11) sel = first;
        Func235DE0(D_002D98D0, sel);
    }
    D_002A5358->Func108FF0(0x28F, sel);
}

s32 CGameEventObj::Func165ED0(s32 k) {
    s32 *p = IdPtr(this, k);
    D_002A26E4->Func108FF0(0x15, *p);
    if (!D_002A2988->Find20C(*p)) return 0;
    D_002A26E4->Func108FF0(m_unkFF20 + 0xE2, *p);
    return 1;
}

s32 Func165F78(s32 v) {
    s32 i;
    for (i = 0; i < D_002A26E4->Func1091B0(0x27); i++) {
        if (D_002A26E4->Func1091B0(i + 0x28) == v) return i;
    }
    return i;
}

void CGameEventObj::Func165FF0() {
    s32 ids[0x80];
    s32 vals[0x80];
    s32 i, n;
    D_002A5358->Func108700();
    D_002A5358->Func108FF0(0x260, 0);
    D_002A5358->Func108FF0(0x261, m_unkFF20);
    m_count = 0;
    n = D_002A2988->Vf14C490(ids, vals, m_unkFF20);
    for (i = 0; i < n; i++) {
        CGameDBRec *r = D_002A2988->Find234(ids[i]);
        if (r) {
            s32 v = D_002A26E4->Func1091B0(ids[i] + 0x1006);
            func_00108EA0(D_002A5358, m_count + 0x263, r->m_unk8);
            D_002A5358->Func108FF0(m_count + 0x26E, r->m_unk0);
            D_002A5358->Func108FF0(m_count + 0x279, v == 0);
            D_002A5358->Func108FF0(m_count + 0x284, v ? Func165F78(v) : -1);
            m_ids[m_count++] = ids[i];
        }
    }
    D_002A5358->Func108FF0(0x262, m_count);
    D_002A5358->Func108FF0(0x28F, -1);
}

s32 CGameEventObj::Func166208(s32 k) {
    s32 *p = IdPtr(this, k);
    CGameDBRec *r;
    D_002A26E4->Func108FF0(0x15, *p);
    r = D_002A2988->Find234(*p);
    if (!r) return 0;
    D_002A26E4->Func108FF0(m_unkFF20 + 0x166, *p);
    D_002A26E4->Func108FF0(*p + 0x1006, D_002A26E4->Func1091B0(m_unkFF20 + 0x28));
    D_002A0D38->RunScript(r->m_unk10, 1);
    D_002A26E4->Func108FF0(m_unkFF20 + 0xCA, D_002A0D38->GetUnk590C());
    return 1;
}

s32 CGameEventObj::Func166348(s32 k) {
    s32 v = D_002A26E4->Func1091B0(m_unkFF20 + 0xDC);
    if (v == 0 || D_002A2988->Find220(v) == 0) return 0;
    switch (k) {
    case 0:
        D_002A0D38->RunScript(D_002A2988->Func14ECD0(m_unkFF20, 0), 1);
        D_002A0D38->RunScript(D_002A2988->Func14ECD0(m_unkFF20, 1), 1);
        break;
    case 1:
        D_002A0D38->RunScript(D_002A2988->Func14ECD0(m_unkFF20, 2), 1);
        D_002A0D38->RunScript(D_002A2988->Func14ECD0(m_unkFF20, 3), 1);
        break;
    }
    return 1;
}

s32 CGameEventObj::Func166548(s32 k) {
    s32 v = D_002A26E4->Func1091B0(m_unkFF20 + 0xE2);
    if (v == 0 || D_002A2988->Find20C(v) == 0) return 0;
    switch (k) {
    case 0:
        D_002A0D38->RunScript(D_002A2988->Func14EC50(m_unkFF20, 0), 1);
        D_002A0D38->RunScript(D_002A2988->Func14EC50(m_unkFF20, 1), 1);
        break;
    case 1:
        D_002A0D38->RunScript(D_002A2988->Func14EC50(m_unkFF20, 2), 1);
        D_002A0D38->RunScript(D_002A2988->Func14EC50(m_unkFF20, 3), 1);
        break;
    }
    return 1;
}

void CreateGameResort(CTaskList24F5C0 *list, s32 a, s32 b, s32 c, s32 d) {
    CGameResort *t = new CGameResort(a, b, c, d);
    list->Func24F5C0(t, 0);
}
