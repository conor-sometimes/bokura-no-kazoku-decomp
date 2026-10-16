#include "common.h"

// Split off CMenuCommon.cpp by lane cv: these functions' literals sit after CMenuCommon's RTTI names, in
// 0x2DB5E0-0x2DBA30, so they are a unit of their own (docs/units.md).

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
    virtual s32 Update();
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
// @decl-end

INCLUDE_RODATA("asm/nonmatchings/CMenuCommonRes", D_002DB5E0);
INCLUDE_RODATA("asm/nonmatchings/CMenuCommonRes", D_002DB5E8);
INCLUDE_RODATA("asm/nonmatchings/CMenuCommonRes", D_002DB5F0);
INCLUDE_RODATA("asm/nonmatchings/CMenuCommonRes", D_002DB600);
INCLUDE_RODATA("asm/nonmatchings/CMenuCommonRes", D_002DB608);
INCLUDE_RODATA("asm/nonmatchings/CMenuCommonRes", D_002DB610);
INCLUDE_RODATA("asm/nonmatchings/CMenuCommonRes", D_002DB618);
INCLUDE_RODATA("asm/nonmatchings/CMenuCommonRes", D_002DB640);
INCLUDE_RODATA("asm/nonmatchings/CMenuCommonRes", D_002DB668);
INCLUDE_RODATA("asm/nonmatchings/CMenuCommonRes", D_002DB678);
INCLUDE_RODATA("asm/nonmatchings/CMenuCommonRes", D_002DB690);
INCLUDE_RODATA("asm/nonmatchings/CMenuCommonRes", D_002DB6B8);
INCLUDE_RODATA("asm/nonmatchings/CMenuCommonRes", jtbl_002DB6E0);
INCLUDE_RODATA("asm/nonmatchings/CMenuCommonRes", D_002DB700);
INCLUDE_RODATA("asm/nonmatchings/CMenuCommonRes", jtbl_002DB710);
INCLUDE_RODATA("asm/nonmatchings/CMenuCommonRes", D_002DB730);
INCLUDE_RODATA("asm/nonmatchings/CMenuCommonRes", D_002DB810);
INCLUDE_RODATA("asm/nonmatchings/CMenuCommonRes", D_002DB8F0);
INCLUDE_RODATA("asm/nonmatchings/CMenuCommonRes", D_002DB8F8);
INCLUDE_RODATA("asm/nonmatchings/CMenuCommonRes", D_002DB920);
INCLUDE_RODATA("asm/nonmatchings/CMenuCommonRes", D_002DB958);
INCLUDE_RODATA("asm/nonmatchings/CMenuCommonRes", D_002DB980);
INCLUDE_RODATA("asm/nonmatchings/CMenuCommonRes", D_002DB988);
INCLUDE_RODATA("asm/nonmatchings/CMenuCommonRes", D_002DB990);
INCLUDE_RODATA("asm/nonmatchings/CMenuCommonRes", jtbl_002DB9B0);
INCLUDE_RODATA("asm/nonmatchings/CMenuCommonRes", D_002DB9D0);
INCLUDE_RODATA("asm/nonmatchings/CMenuCommonRes", D_002DBA08);
INCLUDE_RODATA("asm/nonmatchings/CMenuCommonRes", D_002DBA18);

int CMenuChildStatusSub18B9E0::Func18B880(char *out, s32 id, s32 n) {
    char line[0x400];
    s32 v;
    const char *p;
    if (!m_unk10) return 0;
    p = (const char *)m_unk10;
    do {
        const char *q;
        p = func_0024AD10(p, line, 1, 0x400);
        q = func_0024A710(line, &v, 0, D_002DB600, D_002DB608);
        if (v == id) {
            s32 i = 0;
            do {
                q = func_0024A6B0(q, out, D_002DB610, D_002DB600, D_002DB608);
                i++;
            } while (i < n);
            return 1;
        }
    } while (*p);
    Func235DE0(D_002DB618, id, n);
    return 0;
}

void CMenuCommonSub18B990::Clear() {
    m_unk0 = 0;
    m_unk4 = 0;
    m_unk8 = 0;
    m_unk10 = 0;
    m_unkC = 0;
    m_unk14 = 0;
    m_unk18 = 0;
    m_unk1C = 0;
    m_unk24 = 0;
    m_unk20 = 0;
    m_unk28 = 0;
    m_unk30 = 0;
    m_unk2C = 0;
    m_unk34 = 0;
    m_unk38 = 0;
    m_unk40 = m_unk44 = 0.0f;
}

CMenuChildStatusSub18B9E0::~CMenuChildStatusSub18B9E0() {
    if (m_recs) {
        for (s32 i = 0; i < D_002A5358->Func1091B0(0x262); i++) {
            if (m_recs[i].m_data) D_002B91B0(m_recs[i].m_data);
        }
        D_002B91B0(m_recs);
        m_recs = 0;
    }
    if (m_unk10) {
        D_002B91B0(m_unk10);
        m_unk10 = 0;
    }
    if (m_unk8) {
        delete m_unk8;
        m_unk8 = 0;
    }
    if (m_unk4) {
        delete m_unk4;
        m_unk4 = 0;
    }
}

int CMenuCommonSub18C110::Init18BB10() {
    char buf[0x400];
    char num[0x100];
    char name[0x100];
    char s1[0x100];
    char s2[0x100];
    s32 k = D_002A5358->Func1091B0(0x260);
    if ((u32)k >= 7) {
        Func235DE0(D_002DB640, k);
        return 0;
    }
    m_item = (CStatusItem *)func_001A0CF0(D_002A5408, D_002DB730[k]);
    if (!m_item) return 0;
    m_item->Func1A3378();
    s32 id = D_002A5358->Func1091B0(0x261);
    func_00185AA0(name, id, -1, -1, -1, -1, -1);
    sprintf(buf, m_item->GetUnkE4(10), name);
    m_item->SetText(10, buf);
    char *cn = D_002A2988->GetCharaName(id);
    sprintf(buf, m_item->GetUnkE4(11), cn);
    m_item->SetText(11, buf);
    Func185E80(s1, id);
    Func185F18(s2, id, 1);
    sprintf(buf, m_item->GetUnkE4(12), s2, s1);
    m_item->SetText(12, buf);
    const char *fmt = m_item->GetUnkE4(13);
    sprintf(buf, fmt, func_0024BA08(num, D_002A26E4->Func1091B0(id + 0x34)));
    m_item->SetText(13, buf);
    CMenuLoadMemorialSub179568 *p4 = new CMenuLoadMemorialSub179568;
    p4->Create();
    m_unk4 = p4;
    p4->SetUnk44(1);
    CMenuLoadMemorialSub178778 *p8 = new CMenuLoadMemorialSub178778;
    p8->Create();
    m_unk8 = p8;
    p8->SetUnk44(1);
    if (k == 1 || k == 5) {
        m_item2 = (CStatusItem *)func_001A0CF0(D_002A5408, D_002DB668);
        if (!m_item2) return 0;
        m_item2->Func1A3378();
        m_item2->GetPos(&m_unk40, &m_unk44, 11);
        m_unk44 *= (f32)(D_002A5358->Func1091B0(0x262) - 2);
        ((CStatusWinSub1A40B8 *)m_item2)->SetUnk80(m_unk40, m_unk44);
    }
    return 1;
}

int CMenuCommonRes::Load18BDF0() {
    char path[256];
    int ok = 0;
    if (m_data) D_002B91B0(m_data);
    func_002491A8(path, 0, D_002A439C, D_002A43A0, D_002A43A4);
    if (func_00249248(path)) {
        m_data = func_0024A4C0(D_002DB810[D_002A5358->Func1091B0(0x260)]);
        if (m_data == 0) {
            Func235DE0(D_002DB678, D_002DB810[D_002A5358->Func1091B0(0x260)]);
        } else {
            ok = 1;
        }
    }
    func_00249348();
    return ok;
}

int CMenuChildStatusSub18B9E0::Load18BEE8() {
    char path[256];
    char buf[256];
    int ok = 0;
    func_002491A8(path, 0, D_002A439C, D_002A43A0, D_002A43A4);
    if (func_00249248(path)) {
        m_recs = (CMenuChildStatusRec *)Func245D00(D_002A5358->Func1091B0(0x262) * sizeof(CMenuChildStatusRec));
        if (m_recs) {
            for (s32 i = 0; i < D_002A5358->Func1091B0(0x262); i++) {
                if (D_002A5358->Func1091B0(i + 0x26E) > 0) {
                    func_0018B880(this, buf, D_002A5358->Func1091B0(i + 0x26E), 1);
                    if (func_001869C8(&m_recs[i], buf) == 0) {
                        memset(&m_recs[i], 0, sizeof(CMenuChildStatusRec));
                    }
                } else {
                    memset(&m_recs[i], 0, sizeof(CMenuChildStatusRec));
                }
            }
            ok = 1;
        }
    }
    func_00249348();
    return ok;
}

void CMenuCommonSub18C110::Func18C050() {
    if (m_item) {
        if (m_unk14 != 1) {
            m_item->Func1A3628();
            if (m_item2) {
                m_item2->Func1A3628();
            }
            m_unk14 = 1;
        }
    }
}

void CMenuCommonSub18C110::Start18C0B0() {
    if (m_item) {
        if (m_unk14 != 4) {
            m_item->Start();
            if (m_item2) {
                m_item2->Start();
            }
            m_unk14 = 4;
        }
    }
}

s32 CMenuCommonSub18C110::GetUnk14() {
    return m_unk14;
}

s32 CMenuCommonSub18C110::GetItemState() {
    return m_item ? m_item->m_state : -1;
}

INCLUDE_ASM("asm/nonmatchings/CMenuCommonRes", func_0018C130);

void CMenuCommonSub18C110::Update18CE28() {
    if (m_item) {
        func_001A40C8(m_item);
        switch (m_item->m_state) {
        case 0:
            m_unk14 = 0;
            break;
        case 2:
            m_unk14 = 2;
            break;
        }
    }
    if (m_item2) func_001A40C8(m_item2);
    if (m_unk4) {
        func_001795F8(m_unk4);
        if (m_item) func_00179578(m_unk4, m_item->m_unk34);
    }
    if (m_unk8) {
        func_001789B8(m_unk8);
        if (m_item) func_00178938(m_unk8, m_item->m_unk34);
    }
}

INCLUDE_ASM("asm/nonmatchings/CMenuCommonRes", func_0018CEF0);

void CMenuCommonSub18D678::Init(s32 v) {
    s32 i;
    m_unk0 = func_001A0CF0(D_002A5408, D_002DB8F0);
    func_001A3378(m_unk0);
    for (i = 0; i < 40; i++) func_001A3DC8(m_unk0, i, 0);
    for (s32 k = 0; k < 4; k++) func_001A3DC8(m_unk0, v * 4 - 8 + k, 1);
    for (i = v + 42; i < 53; i++) func_001A3DC8(m_unk0, i, 0);
    m_unk14 = 53;
    m_unk18 = 54;
    m_unk1C = 55;
}

void CMenuCommonSub18D838::Func18D768(s32 v) {
    CMenuCommonTmp tmp;
    func_0010BF88(&tmp);
    tmp.m0 = 0;
    if (D_002A26E4->Func1091B0(v + 0x34) == 1) {
        func_00256260(&tmp, func_001A4060(m_unk4, 10) - 1);
        return;
    }
    s32 k = D_002A26E4->Func1091B0(v + 0x46);
    if (k == 6) {
        if ((u32)(D_002A26E4->Func1091B0(v + 0x52) - 0x13) < 5) k = 7;
    }
    func_00256260(&tmp, func_001A4060(m_unk4, 10) + k);
}

void CMenuCommonSub18D838::Func18D838(s32 v) {
    CMenuCommonTmp tmp;
    func_0010BF88(&tmp);
    tmp.m0 = 0;
    s32 k = D_002A26E4->Func1091B0(v + 0x46);
    k -= 2;
    if ((u32)k >= 3) {
        Func235DE0(D_002DB8F8, k);
        k = 0;
    }
    func_00256260(&tmp, func_001A4060(m_unk4, 0xB) + k);
}

void CMenuCommonSub18E0E0::Update18D8B8() {
    f32 pos[2];
    func_001A3840(m_item, m_index);
    func_001A3CF8(m_item, &pos[0], &pos[1], m_unk1C + m_index);
    D_002A5538->Move1B6488(pos[0], pos[1]);
}

void CMenuCommonSub18D838::Clear18D918() {
    m_unk0 = 0;
    m_unk4 = 0;
    m_unk8 = 0;
    m_unkC = 0;
    m_unk10 = 0;
    m_unk14 = 0;
    m_unk18 = 0;
    m_unk1C = 0;
    m_unk20 = 0;
    m_unk24 = 0;
    m_unk28 = 0;
    m_unk2C = 0;
    m_unk30 = 0;
    m_unk34 = 0;
    m_unk38 = 0;
}

INCLUDE_ASM("asm/nonmatchings/CMenuCommonRes", func_0018D958);

void CMenuCommonSub18E0E0::Func18DF88() {
    if (m_item) {
        m_item->Func1A3628();
        m_unk8 = 1;
    }
}

void CMenuCommonSub18E0E0::Start18DFC8() {
    if (m_item) {
        m_item->Start();
        m_unk8 = 4;
    }
}

void CMenuCommonSub18E0E0::SetIndex(s32 i) {
    if (i < 0 || i > m_count - 1) {
        Func235DE0(D_002DB9D0, i);
        i = 0;
    }
    m_index = i;
    Update18D8B8();
}

void CMenuCommonSub18E0E0::Prev() {
    if (--m_index < 0) {
        m_index = m_count - 1;
    }
    Update18D8B8();
}

void CMenuCommonSub18E0E0::Next() {
    if (++m_index > m_count - 1) {
        m_index = 0;
    }
    Update18D8B8();
}

s32 CMenuCommonSub18E0E0::GetUnk8() {
    return m_unk8;
}

s32 CMenuCommonSub18E0E0::GetItemState() {
    return m_item ? m_item->m_state : -1;
}

void CMenuCommonSub18E0E0::Update18E100() {
    if (!m_item) return;
    m_item->Func1A40C8();
    D_002A5538->SetUnk4C(m_item->m_unk34);
    func_001B6570(D_002A5538);
    m_unk28 += (f32)D_002A4B60->Func1091B0(0x51) / 1000.0f;
    if (m_unk28 > 0.5f) m_unk28 = 0;
    m_unk28 = FracVu0(m_unk28);
}

INCLUDE_ASM("asm/nonmatchings/CMenuCommonRes", func_0018E1E0);

CMenuCommonSub18E638 *CMenuCommonSub18E638::Create() {
    return (CMenuCommonSub18E638 *)new CMenuPTJobMoney;
}

void CMenuCommonSub18E638::SetRate(f32 v) {
    f32 r = Clamp01(v);
    m_unk74 = (s32)(m_unk6C * r);
    m_unk78 = (s32)(f32)m_unk74 + D_002A5358->Func1091B0(0x24D);
}

void CMenuCommonSub18E638::SetScale(f32 v) {
    m_unk7C = 2.0f - Clamp01(v);
}
