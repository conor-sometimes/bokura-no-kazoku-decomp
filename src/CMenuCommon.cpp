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

INCLUDE_RODATA("asm/nonmatchings/CMenuCommon", D_002DB558);
INCLUDE_RODATA("asm/nonmatchings/CMenuCommon", D_002DB560);
INCLUDE_RODATA("asm/nonmatchings/CMenuCommon", D_002DB568);
INCLUDE_RODATA("asm/nonmatchings/CMenuCommon", D_002DB570);
INCLUDE_RODATA("asm/nonmatchings/CMenuCommon", D_002DB590);
INCLUDE_ASM("asm/nonmatchings/CMenuCommon", Update__11CMenuCommon);

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
