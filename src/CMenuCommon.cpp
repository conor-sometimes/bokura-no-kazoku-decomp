#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

class CStatusItem {
public:
    const char *GetUnkE4(s32 i);
    void GetPos(f32 *x, f32 *y, s32 i);
    void SetText(s32 i, const char *s);
    void Func1A3378();
    void Func1A3628();
    void Start();
    void Func1A40C8();

    u8 pad0[0x20];
    s32 m_state;              // 0x20
    u8 pad24[0x10];
    f32 m_unk34;              // 0x34
};
class CMenuCommonSub18C110 {
public:
    int Init18BB10();
    void Update18CE28();
    void Start18C0B0();
    void Func18C050();
    s32 GetUnk14();
    s32 GetItemState();

    CStatusItem *m_item;  // 0x0
    void *m_unk4;             // 0x4
    void *m_unk8;             // 0x8
    CStatusItem *m_item2; // 0xC
    u8 pad10[0x4];
    s32 m_unk14;              // 0x14
    u8 pad18[0x28];
    f32 m_unk40;              // 0x40
    f32 m_unk44;              // 0x44
};
class CMenuCommonSub18E0E0 {
public:
    void Update18D8B8();
    void Next();
    void Prev();
    void SetIndex(s32 i);
    void Start18DFC8();
    void Func18DF88();
    s32 GetUnk8();
    s32 GetItemState();
    void Update18E100();

    CStatusItem *m_item;  // 0x0
    u8 pad4[0x4];
    s32 m_unk8;               // 0x8
    s32 m_index;              // 0xC
    s32 m_count;              // 0x10
    u8 pad14[0x8];
    s32 m_unk1C;              // 0x1C
    u8 pad20[0x8];
    f32 m_unk28;              // 0x28
};

//@sym Update18D8B8__20CMenuCommonSub18E0E0 0x18D8B8
#include "CFlagWork.h"
#include "CMenuMgrSub1B6418.h"
extern CMenuMgrSub1B6418 *D_002A5538;
extern char D_002DB9D0[];
extern char D_002DB8F8[];
extern "C" void func_001A3840(CStatusItem *p, s32 i);
extern "C" void func_001A3CF8(CStatusItem *p, f32 *x, f32 *y, s32 i);
extern "C" void *func_0010BF88(void *p);
extern "C" s32 func_001A4060(void *p, s32 v);
extern "C" void func_00256260(void *p, s32 v);
// CMenuCommonSub18E638 is this class (its unit's text starts before 0x18E638).
class CMenuPTJobMoney {
public:
    CMenuPTJobMoney() throw();

    u8 pad0[0x80];
};
class CMenuCommonSub18E638 {
public:
    static CMenuCommonSub18E638 *Create();
    void SetRate(f32 v);
    void SetScale(f32 v);

    u8 pad0[0x6C];
    s32 m_unk6C;              // 0x6C
    u8 pad70[0x4];
    s32 m_unk74;              // 0x74
    s32 m_unk78;              // 0x78
    f32 m_unk7C;              // 0x7C
};
class CMenuCommonSub18D838 {
public:
    void Func18D768(s32 v);
    void Func18D838(s32 v);
    void Clear18D918();

    s32 m_unk0;               // 0x0
    void *m_unk4;             // 0x4
    s32 m_unk8;               // 0x8
    s32 m_unkC;               // 0xC
    s32 m_unk10;              // 0x10
    s32 m_unk14;              // 0x14
    s32 m_unk18;              // 0x18
    s32 m_unk1C;              // 0x1C
    s32 m_unk20;              // 0x20
    s32 m_unk24;              // 0x24
    s32 m_unk28;              // 0x28
    s32 m_unk2C;              // 0x2C
    s32 m_unk30;              // 0x30
    s32 m_unk34;              // 0x34
    s32 m_unk38;              // 0x38
};
class CMenuCommonTmp {
public:
    s32 m0;
    u8 pad4[0x8C];
};

class CMenuCommonSub18B990 {
public:
    void Clear();
    s32 m_unk0;
    s32 m_unk4;
    s32 m_unk8;
    s32 m_unkC;
    s32 m_unk10;
    s32 m_unk14;
    s32 m_unk18;
    s32 m_unk1C;
    s32 m_unk20;
    s32 m_unk24;
    s32 m_unk28;
    s32 m_unk2C;
    s32 m_unk30;
    s32 m_unk34;
    s32 m_unk38;
    u8 pad3C[0x4];
    f32 m_unk40;
    f32 m_unk44;
};

class CUnk237E90 {
public:
    int Func237E90(int v);
};
extern "C" u8 *func_00237570(s32 v);
extern "C" void func_00237A88(void *p, s32 v);
extern "C" void *func_00237C30(void *p);
extern "C" int func_00238158(void *p, s32 v);
extern "C" int func_0018CEF0(void *p);
extern "C" int func_0019B1F8(void *p);
extern "C" int func_0018E1E0(void *p);
void Func225240(s32 v);
extern "C" void func_00245818(void *p, s32 v);
class CBgWork {
public:
    CBgWork();
    ~CBgWork();

    u8 pad0[0xC];
};

// 0x18AF18 (CMenuChildStatus.cpp's name for it) works on this class.
class CMenuChildStatusObj {
public:
    void Release18AF18();
};

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuCommon.
class CMenuCommon : public CMenuProcess {
public:
    CMenuCommon();
    virtual ~CMenuCommon();
    virtual void Update();
    virtual s32 Draw();

    CBgWork m_bg;             // 0x58
    void *m_unk64;            // 0x64
    void *m_unk68;            // 0x68
    void *m_unk6C;            // 0x6C
    s32 m_unk70;              // 0x70
};

extern void *D_002A5408;
extern char D_002DB8F0[];
extern "C" void *func_001A0CF0(void *p, const char *s);
extern "C" void func_001A3378(void *p);
extern "C" void func_001A3DC8(void *p, s32 i, s32 v);
extern "C" void func_001A40C8(void *p);
extern "C" void func_001795F8(void *p);
extern "C" void func_00179578(void *p, f32 v);
extern "C" void func_001789B8(void *p);
extern "C" void func_00178938(void *p, f32 v);
class CMenuCommonSub18D678 {
public:
    void Init(s32 v);
    void *m_unk0;             // 0x0
    u8 pad4[0x10];
    s32 m_unk14;              // 0x14
    s32 m_unk18;              // 0x18
    s32 m_unk1C;              // 0x1C
};

extern void (*D_002B91B0)(void *p);
extern char *D_002A439C;
extern char *D_002A43A0;
extern char *D_002A43A4;
extern char D_002DB810[][32];
extern char D_002DB678[];
extern "C" void func_002491A8(char *buf, const char *name, const char *a, const char *b, const char *c);
extern "C" int func_00249248(const char *path);
extern "C" void func_00249348();
extern "C" void *func_0024A4C0(const char *name);
extern CFlagWork *D_002A5358;
class CMenuCommonRes {
public:
    int Load18BDF0();
    u8 pad0[0x10];
    void *m_data;             // 0x10
};

class CMenuLoadMemorialSub178690 {
public:
    ~CMenuLoadMemorialSub178690();
};
class CMenuLoadMemorialSub1792B0 {
public:
    ~CMenuLoadMemorialSub1792B0();
};
struct CMenuChildStatusRec {
    void *m_data;
    u8 pad4[0x20];
};
extern void (*D_002B91B0)(void *p);
class CMenuChildStatusSub18B9E0 {
public:
    int Func18B880(char *out, s32 id, s32 n);
    int Load18BEE8();
    ~CMenuChildStatusSub18B9E0();
    u8 pad0[0x4];
    CMenuLoadMemorialSub1792B0 *m_unk4; // 0x4
    CMenuLoadMemorialSub178690 *m_unk8; // 0x8
    u8 padC[0x4];
    void *m_unk10;            // 0x10
    u8 pad14[0x24];
    CMenuChildStatusRec *m_recs; // 0x38
};

//@sym memset 0x289FB0
#include "libc.h"
void *Func245D00(s32 size);
extern "C" void func_0018B880(void *p, char *buf, s32 v, s32 k);
extern "C" int func_001869C8(CMenuChildStatusRec *r, char *buf);

inline f32 Clamp01(f32 v) { return (v < 1.0f ? v : 1.0f) < 0.0f ? 0.0f : (v < 1.0f ? v : 1.0f); }

extern char D_002DB600[], D_002DB608[], D_002DB610[], D_002DB618[];
extern "C" const char *func_0024AD10(const char *p, char *buf, s32 a, s32 n);
extern "C" const char *func_0024A710(const char *p, s32 *v, s32 k, const char *s1, const char *s2);
extern "C" const char *func_0024A6B0(const char *p, char *out, const char *a, const char *s1, const char *s2);

#include "IGameDBMgr.h"
extern "C" void func_00185AA0(void *p, s32 k, s32 a, s32 b, s32 c, s32 d, s32 e);
void Func185E80(char *buf, s32 a);
void Func185F18(char *buf, s32 a, s32 b);
extern "C" char *func_0024BA08(char *buf, s32 v);
extern "C" int sprintf(char *buf, const char *fmt, ...);
extern char D_002DB640[];
extern char D_002DB668[];
extern char D_002DB730[][32];
class CMenuLoadMemorialSub179568 {
public:
    int Create();
    void SetUnk44(u32 v);
    u8 pad[0xC0];
};
class CMenuLoadMemorialSub178778 {
public:
    int Create();
    void SetUnk44(u32 v);
    u8 pad[0xB0];
};
#include "CStatusWinSub1A40B8.h"

extern CFlagWork *D_002A4B60;
extern "C" void func_001B6570(CMenuMgrSub1B6418 *p);
inline f32 FracVu0(f32 x) {
    f32 r;
    asm volatile(
        ".set noreorder\n"
        "mfc1 $2, %1\n"
        "qmtc2.ni $2, $vf2\n"
        "vftoi0.x $vf3, $vf2\n"
        "vmulaw.x ACC, $vf2, $vf0w\n"
        "vaddw.x $vf2, $vf0, $vf0w\n"
        "vitof0.x $vf3, $vf3\n"
        "bgez $2, 1f\n"
        "nop\n"
        "vmadda.x ACC, $vf2, $vf2\n"
        "1:\n"
        "vmsubw.x $vf2, $vf3, $vf0w\n"
        "qmfc2.ni $8, $vf2\n"
        "mtc1 $8, %0\n"
        ".set reorder\n"
        : "=f"(r) : "f"(x) : "$2", "$8");
    return r;
}

#include "state.h"
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
class CChrBodyWin {
public:
    void Clear1884B0();
    void Open(int c);
    int Func1889F8();
};
class CChrBodyWinSub188748 {
public:
    void SetUnk380(int v);
};
extern CChrBodyWin *D_002A4308;
class CStatusBaseSub19AE68 {
public:
    void Func19ADD0(s32 c);
    s32 GetUnk18();
};
class CStatusBaseSub19AD70 {
public:
    void ItemFunc1A3628();
    void ItemStart();
};
class CBgTarget;
typedef int (CBgTarget::*BgFn)();
extern "C" void func_002457A0(CBgWork *bg, void *obj, BgFn f, s32 x);
extern "C" int BgBusy(void *p, s32 v) asm("func_00245818");
extern "C" void func_00185648(s32 v);
extern "C" void func_0018D958(void *p);
extern "C" void func_0018C130(void *p, s32 v);
extern "C" void func_0019AC20(void *p, s32 v) asm("Init19AC20__20CStatusBaseSub19AE68i");
extern "C" void func_0019AFA8(void *p);
inline void SetVar(CStateMachine *sm, s32 k, s32 v) { sm->Var(k) = v; }
#define M64 ((CMenuCommonSub18E0E0 *)m_unk64)
#define M68 ((CMenuCommonSub18C110 *)m_unk68)
#define M6C1 ((CStatusBaseSub19AE68 *)m_unk6C)
#define M6C2 ((CStatusBaseSub19AD70 *)m_unk6C)
// @decl-end

CMenuCommon::CMenuCommon() {
    m_unk64 = 0;
    m_unk70 = 0;
    m_unk68 = 0;
    m_unk6C = 0;
    m_unk4C = -1;
}

CMenuCommon::~CMenuCommon() {
    func_00245818(&m_bg, 1);
    ((CMenuChildStatusObj *)this)->Release18AF18();
}

void CMenuCommon::Update() {
    CStateMachine *sm = (CStateMachine *)this;
    s32 a, b, c;
    s32 done;
    if (m_state == 6) {
        BgBusy(&m_bg, 1);
        m_state = 5;
        m_unk4C = -1;
        goto end;
    }
    done = 0;
    D_002A5468->V7(&a, &b, &c);
loop:
    if (done) goto out;
    {
        u32 fl = sm->m_flags;
        if ((fl >> 7) & 1) goto out;
    }
    switch (sm->m_state) {
    case -1:
        func_00185648(D_002A5358->Func1091B0(0x261));
        D_002A4308->Clear1884B0();
        ((CChrBodyWinSub188748 *)D_002A4308)->SetUnk380(0);
        D_002A4308->Open(D_002A5358->Func1091B0(0x261));
        func_002457A0(&m_bg, D_002A4308, (BgFn)&CChrBodyWin::Func1889F8, 0);
        m_state = 1;
        while (BgBusy(&m_bg, 0)) {
            sm->m_state = -0xB7; done = 1; goto loop;
    case -0xB7:;
        }
        {
            CMenuCommonSub18D838 *p = (CMenuCommonSub18D838 *)operator new(0x3C);
            p->Clear18D918();
            m_unk64 = p;
            func_0018D958(p);
        }
        {
            CMenuCommonSub18B990 *p = (CMenuCommonSub18B990 *)operator new(0x50);
            p->Clear();
            m_unk68 = p;
            ((CMenuCommonSub18C110 *)p)->Init18BB10();
        }
        m_state = 1;
        func_002457A0(&m_bg, m_unk68, (BgFn)&CMenuCommonRes::Load18BDF0, 0);
        while (BgBusy(&m_bg, 0)) {
            sm->m_state = -0xC4; done = 1; goto loop;
    case -0xC4:;
        }
        func_002457A0(&m_bg, m_unk68, (BgFn)&CMenuChildStatusSub18B9E0::Load18BEE8, 0);
        while (BgBusy(&m_bg, 0)) {
            sm->m_state = -0xC9; done = 1; goto loop;
    case -0xC9:;
        }
        if (m_unk50 < 0) func_0018C130(m_unk68, 0);
        else func_0018C130(m_unk68, m_unk50);
        {
            void *p = operator new(0x20);
            func_0019AC20(p, 2);
            m_unk6C = p;
        }
        M6C1->Func19ADD0(D_002A5358->Func1091B0(0x261));
        m_state = 2;
        M64->Func18DF88();
        do {
    case -0xE6:
            if (M64->GetItemState() != 2) {
                sm->m_state = -0xE6; done = 1; goto loop;
            }
        } while (0);
        M68->Func18C050();
        M6C2->ItemFunc1A3628();
        do {
    case -0xF5: {
            s32 k = M68->GetItemState();
            if (k != 2) goto yF5;
            if (M6C1->GetUnk18() != k) {
                yF5: sm->m_state = -0xF5; done = 1; goto loop;
            }
        }
        } while (0);
        m_state = 3;
        m_unk70 = 1;
        do {
    case -0x125:
            if (c & 0x1000) {
                D_002A5468->V14(0);
                M64->Prev();
                func_0018C130(m_unk68, M64->m_index);
                sm->Push();
                SetVar(sm, 0, -0x105);
                goto sub;
            } else if (c & 0x4000) {
                D_002A5468->V14(0);
                M64->Next();
                func_0018C130(m_unk68, M64->m_index);
                sm->Push();
                SetVar(sm, 0, -0x10E);
                goto sub;
            } else if (a & 0x20) {
                m_unk4C = M64->m_index;
                if (D_002A5358->Func1091B0(m_unk4C + 0x279)) {
                    D_002A5468->V14(1);
                    goto s4;
                }
                D_002A5468->V14(4);
                m_unk4C = -1;
            } else if (a & 0x40) {
                if (D_002A5358->Func1091B0(0x25F)) {
                    m_unk4C = -1;
                    goto s4;
                }
            }
    case -0x105:
    case -0x10E:
            sm->m_state = -0x125; done = 1; goto loop;
        } while (0);
    s4:
        m_state = 4;
        M64->Start18DFC8();
        if (m_unk70) {
            M68->Start18C0B0();
            M6C2->ItemStart();
        }
        do {
    case -0x13C:
            if (M64->GetItemState() != 0) goto y13C;
            if (M68->GetItemState() != 0) goto y13C;
            if (M6C1->GetUnk18() == 0) {
                m_state = 5;
                sm->m_state = -0x158; done = 1; goto loop;
            }
            y13C: sm->m_state = -0x13C; done = 1; goto loop;
        } while (0);
    sub:
        if (D_002A5358->Func1091B0(M64->m_index + 0x26E) > 0) {
            if (!m_unk70) {
                M68->Func18C050();
                M6C2->ItemFunc1A3628();
                m_unk70 = 1;
            }
        } else if (m_unk70) {
            M68->Start18C0B0();
            M6C2->ItemStart();
            m_unk70 = 0;
        }
        sm->m_state = sm->Get();
        sm->Pop();
        goto loop;
    case -0x158:
        goto out;
    }
out:
    if (m_unk64 && m_unk68 && m_unk6C) {
        M64->Update18E100();
        M68->Update18CE28();
        func_0019AFA8(m_unk6C);
    }
end:;
}

s32 CMenuCommon::Draw() {
    u8 *p = func_00237570(0x40);
    func_00237A88(p, 4);
    func_00238158(func_00237C30(p + 0x30), 1);
    if (m_unk64 && m_unk68 && m_unk6C) {
        CUnk237E90 *q = (CUnk237E90 *)(p + 0x10);
        q->Func237E90(func_0018CEF0(m_unk68));
        q->Func237E90(func_0019B1F8(m_unk6C));
        q->Func237E90(func_0018E1E0(m_unk64));
    }
    Func225088();
    Func225240((s32)p);
    return Func2250C0();
}
