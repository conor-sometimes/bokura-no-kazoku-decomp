#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "IGameDBMgr.h"
#include "CUserFlagMgr.h"
#include "IFlags.h"
#include "ISnapMgr.h"

class CFlagWork {
public:
    void Func108700();
    void Func108FF0(s32 id, s32 v);
    int Func1091B0(s32 id);
    void SetStr(s32 id, const char *s);
    void Func109108(s32 id, s32 delta);
};
extern CFlagWork *D_002A26E4;
extern CFlagWork *D_002A5358;

class CGameDBRec20 {
public:
    s32 m_id;                 // 0x0
    s32 m4;                   // 0x4
    const char *m8;           // 0x8
    const char *mC;           // 0xC
    s32 m10;                  // 0x10
    s32 m14;                  // 0x14
    s32 m18;                  // 0x18
    s32 m1C;                  // 0x1C
};
class CGameDBRec24 {
public:
    s32 m_id;                 // 0x0
    u8 pad4[0xC];
    const char *m10;          // 0x10
    u8 pad14[0x10];
};
struct CSeasonFlagDef {
    s32 m_id;                 // 0x0
    s32 m_kind;               // 0x4
    s32 m_base;               // 0x8
};
extern CSeasonFlagDef D_002A32A0[];
struct CSeasonScriptDef {
    s32 m_id;                 // 0x0
    s32 m_kind;               // 0x4
};
extern CSeasonScriptDef D_002A33D8[];
s32 Func157AE8();
class CUnk16E280 {
public:
    void Func16E280();
    void Func16E518();
};
class CGameSeasonPrevPart {
public:


    u8 pad0[0x140];
    s32 m_unk140;             // 0x140
    u8 pad144[0xEC];
    CUnk16E280 m_unk230;      // 0x230
};
class CNameDBMgr {
public:
    static CNameDBMgr *Create(void *p);
    virtual ~CNameDBMgr();

    u8 pad0[0xFEC4];
    // vptr 0xFEC4
};
// Object at 0x1F0 (vptr at 0xC); only its virtual calls are needed here.
class CGameSeasonPrevObj {
public:
    virtual ~CGameSeasonPrevObj();
    virtual void Func1();
    virtual void Func2();

    u8 pad0[0xC];
    // vptr 0xC
};
// Same layout as the state block at the start of CMenuProcess.
class CSeasonTimer {
public:
    CSeasonTimer() {
        m_unk4 = -1;
        m_unk2 = 0;
        m_unk0 = 0;
    }
    void SetState(s32 v) {
        m_unk4 = v;
    }

    s16 m_unk0;               // 0x0
    s16 m_unk2;               // 0x2
    s32 m_unk4;               // 0x4
};
class CSeasonDate {
public:
    CSeasonDate() {
        m_unk0 = 1;
    }

    s32 m_unk0;               // 0x0
};
int Func251B88();
extern "C" int func_00245818(void *p, s32 v);

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CGameSeasonPrev.
class CGameSeasonPrev : public CProcess {
public:
    CGameSeasonPrev(s32 a);
    virtual ~CGameSeasonPrev();
    virtual void Update();
    virtual void Draw();
    void CallFunc16E280();
    void CallFunc16E518();
    s32 Func156C50();
    void DrawFrame();
    void Func156D28();
    s32 Func156D60(s32 b);
    s32 Func156DD0(s32 b);
    s32 Func156E80(s32 i);
    s32 Func157568(s32 i);
    s32 Func157498(s32 b);
    s32 Func157860(s32 k);
    s32 Func157B68();
    s32 Func157BF0();
    s32 Func157C98();
    s32 Func157738(s32 k);
    s32 Func157DB0();
    s32 Func157978(s32 k);
    s32 Func157EE8();
    s32 Func158088();
    s32 Func156858();

    u8 pad18[0x14];
    CGameSeasonPrevPart* m_part; // 0x2C
    CSeasonTimer m_timer;     // 0x30
    u8 pad38[0x40];
    CBgWork m_bg78;           // 0x78
    CSeasonDate m_date;       // 0x84
    u8 pad88[0x100];
    CNameDBMgr *m_nameDB;     // 0x188
    u32 *m_screen;            // 0x18C
    u8 pad190[0x20];
    s32 m_unk1B0[6];          // 0x1B0
    s32 m_unk1C8[6];          // 0x1C8
    s32 m_unk1E0;             // 0x1E0
    s32 m_unk1E4;             // 0x1E4
    s32 m_unk1E8;             // 0x1E8
    s32 m_unk1EC;             // 0x1EC
    CGameSeasonPrevObj *m_unk1F0; // 0x1F0
    u8 pad1F4[0x8];
    s32 m_unk1FC;             // 0x1FC
};

class CTaskList24F5C0 {
public:
    s32 Func24F5C0(void *task, s32 pri);
};
class CGameSeasonPost : public CProcess {
public:
    CGameSeasonPost(s32 a);

    u8 pad18[0x74];
};

extern "C" void func_00227BF0(u64 tex, s32 a, s32 b, s32 w, s32 h, u8 *src);
extern "C" void *func_00251488();
extern "C" void func_00227CB8(void *ctx, s32 x, s32 y, s32 w, s32 h, void *src);
void FillBorder16E830(u32 *buf, s32 w, s32 h, s32 t, u32 val);
void ClearBorder16E8E0(u32 *buf, s32 w, s32 h);
extern "C" void func_0016E688(u32 *buf, s32 w, s32 h, f32 v);

class CGameDBRec28 {
public:
    u8 pad0[0x14];
    const char *m14;          // 0x14
};
int IsNine(int v);

class CGameDBRec24b {
public:
    u8 pad0[0x14];
    s32 m14;                  // 0x14
    s32 m18;                  // 0x18
    s32 m1C;                  // 0x1C
};
extern char D_002D8DC0[];
s32 Func157AE8();

class CGameDBRecB0 {
public:
    u8 pad0[0x1C];
    s32 m1C[1];               // 0x1C
};
struct CSeasonScript2 {
    s32 m_script;             // 0x0
    s32 m_idx;                // 0x4
    s32 m_check;              // 0x8
};
extern CSeasonScript2 D_002A33F8[];
int IsFlagKind(int v);

class CGameMain {
public:
    void Func151120(s32 a, s32 b, s32 c, s32 d, s32 e);
};
extern CFlagWork *D_002A4638[6];
extern "C" void ResetAllFlags__Fv(void *p);
int IsNine(int v);
int IsFlagKind(int v);

extern u64 *D_2EC0AC;
// @decl-end

CGameSeasonPrev::CGameSeasonPrev(s32 a) {
    m_part = (CGameSeasonPrevPart *)a;
    m_screen = (u32 *)D_0029F398->Func10();
    m_timer.SetState(((ICurFlag *)D_002A26E4)->V5());
    m_nameDB = CNameDBMgr::Create(0);
    m_date.m_unk0 = Func251B88() + 0x3089;
    if (((ICurFlag *)D_002A26E4)->V6() == 0x23 && ((ICurFlag *)D_002A26E4)->V5() == 0 &&
        D_002A26E4->Func1091B0(0x3B64)) {
        m_unk1FC = 1;
    }
}

CGameSeasonPrev::~CGameSeasonPrev() {
    CGameSeasonPrevObj *obj;
    func_00245818(&m_bg78, 1);
    obj = m_unk1F0;
    if (obj) {
        obj->Func2();
        delete obj;
    }
    if (m_nameDB) {
        delete m_nameDB;
        m_nameDB = 0;
    }
    m_part->m_unk140 = 0;
}

void CGameSeasonPrev::DrawFrame() {
    FillBorder16E830(m_screen, 0x280, 0x1C0, 0xC, 0x80D4D4D4);
    func_0016E688(m_screen, 0x280, 0x1C0, 1.0f);
    ClearBorder16E8E0(m_screen, 0x280, 0x1C0);
}

void CGameSeasonPrev::CallFunc16E280() {
    m_part->m_unk230.Func16E280();
}

void CGameSeasonPrev::CallFunc16E518() {
    m_part->m_unk230.Func16E518();
}

INCLUDE_RODATA("asm/nonmatchings/CGameSeasonPrev", D_002D8CA8);
INCLUDE_ASM("asm/nonmatchings/CGameSeasonPrev", Update__15CGameSeasonPrev);
INCLUDE_RODATA("asm/nonmatchings/CGameSeasonPrev", D_002D8CF0);
INCLUDE_RODATA("asm/nonmatchings/CGameSeasonPrev", D_002D8D10);
INCLUDE_RODATA("asm/nonmatchings/CGameSeasonPrev", D_002D8D50);
INCLUDE_RODATA("asm/nonmatchings/CGameSeasonPrev", D_002D8D60);
INCLUDE_RODATA("asm/nonmatchings/CGameSeasonPrev", D_002D8D68);
INCLUDE_RODATA("asm/nonmatchings/CGameSeasonPrev", D_002D8D70);
INCLUDE_RODATA("asm/nonmatchings/CGameSeasonPrev", D_002D8D78);
INCLUDE_RODATA("asm/nonmatchings/CGameSeasonPrev", D_002D8D80);
INCLUDE_RODATA("asm/nonmatchings/CGameSeasonPrev", D_002D8D90);
INCLUDE_RODATA("asm/nonmatchings/CGameSeasonPrev", D_002D8DA0);
INCLUDE_RODATA("asm/nonmatchings/CGameSeasonPrev", D_002D8DB0);
INCLUDE_RODATA("asm/nonmatchings/CGameSeasonPrev", D_002D8DC0);
INCLUDE_RODATA("asm/nonmatchings/CGameSeasonPrev", D_002D8DD0);
INCLUDE_RODATA("asm/nonmatchings/CGameSeasonPrev", D_002D8DE0);
INCLUDE_RODATA("asm/nonmatchings/CGameSeasonPrev", D_002D8DF0);
INCLUDE_RODATA("asm/nonmatchings/CGameSeasonPrev", D_002D8E00);
INCLUDE_RODATA("asm/nonmatchings/CGameSeasonPrev", D_002D8E10);

INCLUDE_ASM("asm/nonmatchings/CGameSeasonPrev", func_00156120);

s32 CGameSeasonPrev::Func156858() {
    s32 i;
    ResetAllFlags__Fv(m_part);
    for (i = 0; i < D_002A26E4->Func1091B0(0x27); i++) {
        s32 f;
        s32 j;
        s32 changed;
        D_002A0D38->V9();
        D_002A0D38->V7(i);
        if (!D_002A26E4->Func1091B0(i + 0x34)) Func156DD0(i);
        ((CGameMain *)m_part)->Func151120(0, i, 0, 0, D_002A26E4->Func1091B0(i + 0x34) == 0);
        if (!D_002A26E4->Func1091B0(i + 0x34)) {
            ((CGameMain *)m_part)->Func151120(1, i, 0, 0, 1);
        } else if (Func156E80(i)) {
            ((CGameMain *)m_part)->Func151120(1, i, 0, 0, 0);
        }
        f = D_002A26E4->Func1091B0(i + 0x46);
        if (IsFlagKind(f)) {
            if (Func157568(i)) {
                if (!((ICurFlag *)D_002A26E4)->GetNamed(0x4C, i)) {
                    ((CGameMain *)m_part)->Func151120(2, i, 0, 0, 0);
                } else {
                    ((CGameMain *)m_part)->Func151120(1, i, 0, 0, 0);
                }
            }
        } else if (IsNine(f)) {
            if (!((ICurFlag *)D_002A26E4)->GetNamed(0x4C, i) && Func157738(i)) {
                ((CGameMain *)m_part)->Func151120(2, i, 0, 0, 0);
            }
        }
        if (Func157978(i)) {
            ((CGameMain *)m_part)->Func151120(3, i, 0, 0, 0);
        }
        changed = 0;
        for (j = 0; j < 6; j++) {
            if (D_002A4638[j]->Func1091B0(i)) {
                if (D_002A4638[0]->Func1091B0(i + 0x60) != D_002A4638[j]->Func1091B0(i + 0x60)) {
                    changed = 1;
                    D_002A4638[j]->Func108FF0(i + 0x3C, D_002A4638[0]->Func1091B0(i + 0x3C));
                    D_002A4638[j]->Func108FF0(i + 0x60, D_002A4638[0]->Func1091B0(i + 0x60));
                }
            }
        }
        if (D_002A0D38->V32(i) || changed) {
            ((CGameMain *)m_part)->Func151120(4, i, 0, 0, 0);
        }
        D_002A0D38->V31(i);
        ((CGameMain *)m_part)->Func151120(5, i, 0, 0, 0);
        D_002A0D38->V10();
    }
    return 1;
}

s32 CGameSeasonPrev::Func156C50() {
    s32 i = 0;
    while (i < D_002A26E4->Func1091B0(0x27)) {
        D_002A0D38->V9();
        D_002A0D38->V7(i);
        Func156E80(i);
        Func157568(i);
        i++;
        D_002A0D38->V10();
    }
    return 1;
}

void CGameSeasonPrev::Func156D28() {
    D_002A0D38->V23();
}

s32 CGameSeasonPrev::Func156D60(s32 b) {
    s32 r = D_002A0D38->GetBit(b);
    D_002A0D38->V24();
    return r;
}

s32 CGameSeasonPrev::Func156DD0(s32 b) {
    s32 i;
    for (i = 0; D_002A32A0[i].m_id >= 0; i++) {
        D_002A26E4->Func108FF0(D_002A32A0[i].m_id + b, D_002A2988->Func14E660(b, D_002A32A0[i].m_kind, -1) - D_002A32A0[i].m_base);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/CGameSeasonPrev", Func156E80__15CGameSeasonPrevi);

s32 CGameSeasonPrev::Func157498(s32 b) {
    s32 i;
    Func156D28();
    for (i = 0; D_002A33D8[i].m_id; i++) {
        D_002A0D38->V18(D_002A33D8[i].m_id, 1, b, D_002A2988->Func14E660(b, D_002A33D8[i].m_kind, -1));
    }
    return Func156D60(b);
}

s32 CGameSeasonPrev::Func157568(s32 k) {
    CGameDBRecB0 *r;
    s32 i;
    if (!IsFlagKind(D_002A26E4->Func1091B0(k + 0x46))) return 0;
    r = D_002A2988->Find1E8(D_002A26E4->Func1091B0(k + 0x52));
    if (!r) return 0;
    Func156D28();
    for (i = 0; D_002A33F8[i].m_script; i++) {
        if (D_002A33F8[i].m_check && (((ICurFlag *)D_002A26E4)->V5() || ((ICurFlag *)D_002A26E4)->GetNamed(0x4C, k))) continue;
        D_002A0D38->V18(D_002A33F8[i].m_script, 1, k, r->m1C[D_002A33F8[i].m_idx]);
    }
    return Func156D60(k);
}

s32 CGameSeasonPrev::Func157738(s32 k) {
    CGameDBRec28 *r;
    if (!IsNine(D_002A26E4->Func1091B0(k + 0x46))) return 0;
    r = D_002A2988->Find200(D_002A26E4->Func1091B0(k + 0x52));
    if (!r) return 0;
    Func156D28();
    D_002A0D38->RunScript(r->m14, 1);
    D_002A26E4->Func108FF0(k + 0xD0, D_002A0D38->V14());
    return Func156D60(k);
}

s32 CGameSeasonPrev::Func157860(s32 k) {
    s32 v = D_002A26E4->Func1091B0(k + 0x166);
    CGameDBRec24 *r;
    if (v == 0 || (r = D_002A2988->Find234(v)) == 0) {
        return 0;
    }
    Func156D28();
    D_002A0D38->RunScript(r->m10, 1);
    D_002A26E4->Func108FF0(k + 0xCA, D_002A0D38->V14());
    return Func156D60(k);
}

s32 CGameSeasonPrev::Func157978(s32 k) {
    s32 c = D_002A26E4->Func1091B0(0x1046);
    CGameDBRec24b *r;
    if (c != k) return 0;
    r = D_002A2988->Get240(D_002A26E4->Func1091B0(c + 0x46), D_002A26E4->Func1091B0(0x1047));
    if (!r) return 0;
    Func156D28();
    D_002A0D38->V18((s32)D_002D8DC0, 1, c, r->m14);
    D_002A0D38->V18((s32)"hum1(%d)+=%d", 1, c, r->m18);
    D_002A0D38->V18((s32)"sci1(%d)+=%d", 1, c, r->m1C);
    return Func156D60(c);
}

s32 Func157AE8() {
    s32 n = 0;
    s32 i;
    for (i = 0; i < D_002A26E4->Func1091B0(0x27); i++) {
        if (D_002A26E4->Func1091B0(i + 0x46) != 9) {
            n += 9;
        }
    }
    return n;
}

s32 CGameSeasonPrev::Func157B68() {
    CGameDBRec20 *r = D_002A2988->GetTbl250(D_002A2988->Func14FA08(-1, 1));
    if (r) {
        m_unk1E0 = r->m10;
        return 1;
    }
    return 0;
}

s32 CGameSeasonPrev::Func157BF0() {
    CGameDBRec20 *r;
    D_002A5358->Func108700();
    r = D_002A2988->GetTbl250(D_002A2988->Func14FA08(-1, 1));
    if (r) {
        D_002A5358->Func108700();
        D_002A5358->SetStr(0x242, r->m8);
        return 1;
    }
    return 0;
}

s32 CGameSeasonPrev::Func157C98() {
    CGameDBRec20 *r;
    D_002A5358->Func108700();
    r = D_002A2988->GetTbl250(D_002A2988->Func14FA08(-1, 1));
    if (r) {
        D_002A5358->SetStr(0x243, r->mC);
        D_002A5358->Func108FF0(0x244, D_002A26E4->Func1091B0(0x22));
        D_002A5358->Func108FF0(0x245, r->m18);
        D_002A5358->Func108FF0(0x246, r->m1C);
        D_002A5358->Func108FF0(0x247, r->m4);
        D_002A5358->Func108FF0(0x248, Func157AE8());
        m_unk1E4 = r->m14;
        return 1;
    }
    return 0;
}

s32 CGameSeasonPrev::Func157DB0() {
    CGameDBRec20 *r;
    s32 x;
    D_002A5358->Func108700();
    r = D_002A2988->GetTbl250(D_002A2988->Func14FA08(-1, 1));
    if (!r) return 0;
    x = (&r->m18)[m_unk1E8] * m_unk1EC / 100;
    D_002A5358->SetStr(0x243, r->mC);
    D_002A5358->Func108FF0(0x249, m_unk1E8);
    D_002A5358->Func108FF0(0x24A, m_unk1EC);
    D_002A5358->Func108FF0(0x24B, D_002A26E4->Func1091B0(0x22));
    D_002A5358->Func108FF0(0x24C, x);
    D_002A26E4->Func109108(0x22, x);
    return 1;
}

s32 CGameSeasonPrev::Func157EE8() {
    CGameDBRec20 *r;
    D_002A5358->Func108700();
    r = D_002A2988->GetTbl250(D_002A2988->Func14FA08(-1, 0));
    D_002A5358->Func108FF0(0x24D, D_002A26E4->Func1091B0(0x1C));
    D_002A5358->Func108FF0(0x24E, D_002A26E4->Func1091B0(0x22));
    D_002A5358->Func108FF0(0x24F, r->m4);
    D_002A5358->Func108FF0(0x250, Func157AE8());
    D_002A26E4->Func108FF0(0x1D, D_002A26E4->Func1091B0(0x1C));
    D_002A26E4->Func108FF0(0x1F, 0);
    D_002A26E4->Func108FF0(0x20, 0);
    D_002A26E4->Func108FF0(0x21, 0);
    D_002A26E4->Func108FF0(0x1E, 0);
    s32 a = D_002A26E4->Func1091B0(0x22);
    ((ICurFlag *)D_002A26E4)->Add145160(0x1F, a + r->m4 + Func157AE8());
    return 1;
}
class CGameDBRec1C {
public:
    u8 pad0[0x10];
    s32 m10;                  // 0x10
    s32 m14;                  // 0x14
    s32 m18;                  // 0x18
};

s32 CGameSeasonPrev::Func158088() {
    s32 n = 0;
    s32 i;
    D_002A5358->Func108700();
    D_002A5358->Func108FF0(0x24D, D_002A26E4->Func1091B0(0x1C));
    for (i = 0; i < D_002A26E4->Func1091B0(0x27); i++) {
        CGameDBRec1C *r;
        s32 v;
        if (!m_unk1B0[i]) continue;
        r = D_002A2988->Find20C(m_unk1B0[i]);
        if (!r) continue;
        switch (m_unk1C8[i]) {
        case 4:
            v = r->m10;
            break;
        case 5:
            v = r->m14;
            break;
        default:
            v = r->m18;
            break;
        }
        D_002A5358->Func108FF0(n + 0x252, i);
        D_002A5358->Func108FF0(n + 0x258, v);
        n++;
        ((ICurFlag *)D_002A26E4)->Add145160(0x20, v);
    }
    D_002A5358->Func108FF0(0x251, n);
    return n > 0;
}

void UploadSeasonScreen(u8 *p) {
    u8 *q = p + 0x8C000;
    if (p) {
        func_00227CB8(func_00251488(), 0, 0, 0x280, 0xE0, p);
        func_00227CB8(func_00251488(), 0, 0xE0, 0x280, 0xE0, q);
    }
}

void UploadSeasonImage(u64 tex, s32 a, s32 b, s32 w, s32 y, s32 h, u8 *base) {
    func_00227BF0(tex, a, b, w, h, base + (y << 5) * w / 8);
}

INCLUDE_ASM("asm/nonmatchings/CGameSeasonPrev", func_001582C8);

void DrawSeasonRect(u32 c, f32 x0, f32 y0, f32 x1, f32 y1) {
    s32 xy[4];
    xy[0] = (s32)(x0 * 16.0f) + 0x6C00;
    xy[1] = (s32)(y0 * 16.0f) + 0x7200;
    xy[2] = (s32)(x1 * 16.0f) + 0x6C00;
    xy[3] = (s32)(y1 * 16.0f) + 0x7200;
    *D_2EC0AC++ = 0x1000000000000004;
    *D_2EC0AC++ = 0xE;
    *D_2EC0AC++ = 0x46;
    *D_2EC0AC++ = 0;
    *D_2EC0AC++ = (u64)((c >> 24) & 0xFF) | ((u64)((c >> 16) & 0xFF) << 8) | ((u64)((c >> 8) & 0xFF) << 16) | ((u64)(c & 0xFF) << 24);
    *D_2EC0AC++ = 1;
    *D_2EC0AC++ = (u64)xy[0] | ((u64)xy[1] << 16);
    *D_2EC0AC++ = 5;
    *D_2EC0AC++ = (u64)xy[2] | ((u64)xy[3] << 16);
    *D_2EC0AC++ = 5;
}

INCLUDE_ASM("asm/nonmatchings/CGameSeasonPrev", Draw__15CGameSeasonPrev);

void CreateGameSeasonPost(CTaskList24F5C0 *list, s32 a) {
    CGameSeasonPost *p = new CGameSeasonPost(a);
    list->Func24F5C0(p, 0);
}
