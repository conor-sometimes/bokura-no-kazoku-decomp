#pragma interface
#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CProcess.h"
extern "C" void func_001B9B30(void *p);
struct CMiniGame4Data {
    u8 pad0[0x40];
    const char *m_text;       // 0x40
};
extern CMiniGame4Data *D_002A5A04;
struct CRand {
    CRand() { m_seed = 1; }
    u32 m_seed;
    u32 Next() {
        m_seed = m_seed * 0x19660D + 1;
        return (m_seed >> 12) & 0xFFFF;
    }
    u32 Rand(u32 n) { return ((Next() << 16) | Next()) % n; }
};
struct CMiniGame4Pair {
    f32 a;
    f32 b;
    u8 pad8[0x8];
};
struct CMiniGame4Layout {
    u8 pad0[0x20];
    s32 m_id;                 // 0x20
};
class CMiniGame4ResObj {
public:
    void Release1D4C68();
    int Parse1D5360();
    int ParseCfg1D4FA8();
    void Shuffle1D5420();
    u8 pad0[0x10];
    CMiniGame4Layout m_unk10; // 0x10
    u8 m_unk34[0x24];         // 0x34
    u8 pad58[0x1330 - 0x58];
    CRand m_rand;             // 0x1330
    u8 pad1334[0x13A0 - 0x1334];
    s32 m_vals[14];           // 0x13A0
    u8 pad13D8[0x13EC - 0x13D8];
    s32 m_must[2];            // 0x13EC
    s32 m_numMust;            // 0x13F4
    s32 m_unk13F8;            // 0x13F8
    s32 m_unk13FC;            // 0x13FC
    s32 m_unk1400;            // 0x1400
    s32 m_order[11];          // 0x1404
    u8 pad1430[0x144C - 0x1430];
    f32 m_tbl144C[5][4];      // 0x144C
    u8 pad149C[0x8];
    f32 m_unk14A4[3];         // 0x14A4
    u8 pad14B0[0x10];
    CMiniGame4Pair m_pairs[4]; // 0x14C0
    f32 m_unk1500;            // 0x1500
    u8 pad1504[0x4];
    f32 m_unk1508;            // 0x1508
};

extern "C" void func_0024F5C0(void *a, void *b, s32 c);

int Func251B88();
extern char D_002E1438[];
// Member classes of CMiniGame4 (library / CLayoutRes code, not named yet): constructors are
// called explicitly.
extern "C" void func_001B9D40(void *p);
extern "C" void *func_0025C230(void *p);

// Same layout as the state block at the start of CMenuProcess.
class CMiniGameTimer {
public:
    CMiniGameTimer() {
        m_unk4 = -1;
        m_unk2 = 0;
        m_unk0 = 0;
    }

    s16 m_unk0;               // 0x0
    s16 m_unk2;               // 0x2
    s32 m_unk4;               // 0x4
};

// Member objects of CMiniGame4: CLayoutObj (0x170 bytes) and the sound handle; their
// constructors live in other units.
extern "C" void *CLayoutObjCtor4(void *p) asm("__10CLayoutObj");
struct CMg4Layout {
    CMg4Layout() { CLayoutObjCtor4(this); }
    u8 pad[0x170];
};
struct CMg4Snd {
    CMg4Snd() { func_0025C230(this); }
    u8 pad[0x74];
};
// The mini game task (vtable 0x2C21A8, still asm; ~CMiniGame4 stays INCLUDE_ASM).
// CMiniGame4ResObj above is the same object.
class CMiniGame4 : public CProcess {
public:
    CMiniGame4(s32 a, s32 b);
    virtual ~CMiniGame4();
    virtual void Update();
    virtual void Draw();

    u8 pad18[0x14];
    s32 m_unk2C;              // 0x2C
    s32 m_unk30;              // 0x30
    CMiniGameTimer m_timer;   // 0x34
    u8 pad3C[0x44];
    // 13 layout objects at 0x80 + i * 0x170 (separate members: retail constructs them one by one)
    CMg4Layout m_l0, m_l1, m_l2, m_l3, m_l4, m_l5, m_l6, m_l7, m_l8, m_l9, m_l10, m_l11, m_l12;
    CRand m_rand;             // 0x1330
    CMg4Snd m_snd;            // 0x1334
    u8 pad13A8[0x3C];
    s32 m_unk13E4;            // 0x13E4
    u8 pad13E8[0x4];
    s32 m_must[2];            // 0x13EC
    s32 m_unk13F4;            // 0x13F4
    u8 pad13F8[0x38];
    s32 m_unk1430;            // 0x1430
    s32 m_unk1434;            // 0x1434
    s32 m_unk1438;            // 0x1438
    s32 m_unk143C;            // 0x143C
    s32 m_unk1440;            // 0x1440
    s32 m_unk1444;            // 0x1444
    s32 m_unk1448;            // 0x1448
    u8 pad144C[0x50];
    s32 m_unk149C;            // 0x149C
    s32 m_unk14A0;            // 0x14A0
    u8 pad14A4[0x8];
    s32 m_unk14AC;            // 0x14AC
    s32 m_unk14B0;            // 0x14B0
    s32 m_unk14B4;            // 0x14B4
    u8 pad14B8[0x4C];
    s32 m_unk1504;            // 0x1504
    s32 m_unk1508;            // 0x1508
    s32 m_unk150C;            // 0x150C
    s32 m_unk1510;            // 0x1510
    s32 m_unk1514;            // 0x1514
    u8 pad1518[0x8];
};

extern char D_002E14A0[];
extern "C" const char *func_0024AF10(const char *s, const char *key);
extern "C" const char *func_0024AFE8(const char *s, char *buf, s32 k, s32 size);
extern "C" long atol(const char *s);
//@sym atol 0x289140

extern char D_002E1460[];
extern char D_002E1468[];
extern char D_002E1470[];
extern char D_002E1478[];
extern "C" const char *func_0024A710(const char *p, s32 *v, s32 k, const char *s1, const char *s2);
void Func235DE0(const char *fmt, ...) throw();

#include "CList.h"
class CLayoutRes {
public:
    CLayoutRes();
    virtual ~CLayoutRes();
    u8 pad0[0x20];
};
class CMiniGame4Res : public CListTag {
public:
    CMiniGame4Res() {}
    // The retail destructor is inline (library 0x29C9B8), so Load is the real key method;
    // declaring the destructor non-inline here keeps this unit from emitting the vtable.
    virtual ~CMiniGame4Res();
    virtual s32 Load();
    virtual void Release();
    CLayoutRes m10;           // 0x10
    CLayoutRes m34;           // 0x34
};

void Func2491A8(void *buf, const char *path, s32 a, s32 b, s32 c);
extern char D_002E13E0[], D_002E13E8[], D_002E13F8[], D_002E1410[], D_002E1420[];
class CLayoutResSub1B8748 {
public:
    s32 Load(const char *dir);
};
// @decl-end

CMiniGame4Res *NewMiniGame4Res() {
    return new CMiniGame4Res;
}

s32 CMiniGame4Res::Load() {
    char path[256];
    Release();
    Func2491A8(path, 0, (s32)D_002E13E0, (s32)D_002E13E8, (s32)D_002E13F8);
    if (((CLayoutResSub1B8748 *)&m10)->Load(path)) {
        Func2491A8(path, 0, (s32)D_002E13E0, (s32)D_002E1410, (s32)D_002E1420);
        if (((CLayoutResSub1B8748 *)&m34)->Load(path)) {
            D_002A5A04 = (CMiniGame4Data *)this;
        }
    }
    return D_002A5A04 != 0;
}

void CMiniGame4ResObj::Release1D4C68() {
    D_002A5A04 = 0;
    func_001B9B30(m_unk34);
    func_001B9B30(&m_unk10);
}

void Func1D4CA0(void *a, s32 b, s32 c) {
    CMiniGame4 *p = new CMiniGame4(b, c);
    func_0024F5C0(a, p, 0);
}

CMiniGame4::CMiniGame4(s32 a, s32 b) {
    s32 i;
    if (!D_002A5A04) Func235DE0(D_002E1438);
    m_rand.m_seed = Func251B88();
    m_unk2C = a;
    m_unk30 = b;
    m_unk13E4 = 0;
    for (i = 0; i < 2; i++) m_must[i] = 0;
    m_unk1444 = 0;
    m_unk1448 = 0;
    m_unk1438 = 0;
    m_unk143C = 0;
    m_unk1440 = 0;
    m_unk149C = 0;
    m_unk14A0 = 0;
    m_unk1504 = 0;
    m_unk1508 = 0;
    m_unk1430 = 0;
    m_unk1434 = 0;
    m_unk14AC = 0;
    m_unk14B0 = 0;
    m_unk150C = 0;
    m_unk14B4 = -1;
    m_unk1510 = 1;
    m_unk1514 = 1;
    m_unk13F4 = 0;
}

extern "C" void MG4LayoutDtor(void *p, s32 flags) asm("_$_10CLayoutObj");
extern "C" void func_0025C2C0(void *p, s32 flags);

// Key method: #pragma interface (top) keeps this unit from emitting the vtables (asm data). The
// member objects are raw storage here, destroyed explicitly (last declared first).
CMiniGame4::~CMiniGame4() {
    func_0025C2C0((u8 *)this + 0x1334, 2);
    MG4LayoutDtor((u8 *)this + 0x11C0, 2);
    MG4LayoutDtor((u8 *)this + 0x1050, 2);
    MG4LayoutDtor((u8 *)this + 0xEE0, 2);
    MG4LayoutDtor((u8 *)this + 0xD70, 2);
    MG4LayoutDtor((u8 *)this + 0xC00, 2);
    MG4LayoutDtor((u8 *)this + 0xA90, 2);
    MG4LayoutDtor((u8 *)this + 0x920, 2);
    MG4LayoutDtor((u8 *)this + 0x7B0, 2);
    MG4LayoutDtor((u8 *)this + 0x640, 2);
    MG4LayoutDtor((u8 *)this + 0x4D0, 2);
    MG4LayoutDtor((u8 *)this + 0x360, 2);
    MG4LayoutDtor((u8 *)this + 0x1F0, 2);
    MG4LayoutDtor((u8 *)this + 0x80, 2);
}

int CMiniGame4ResObj::ParseCfg1D4FA8() {
    char key[256];
    s32 id;
    const char *p = func_0024AF10(D_002A5A04->m_text, D_002E1460);
    if (*p == 0) return 0;
    while ((p = func_0024AFE8(p, key, 1, 0x100), *p != 0) || key[0] != 0) {
        const char *q = func_0024A710(key, &id, 0, D_002E1468, D_002E1470);
        q = func_0024A710(q, &m_unk13F8, 0, D_002E1468, D_002E1470);
        q = func_0024A710(q, &m_unk1400, 0, D_002E1468, D_002E1470);
        q = func_0024A710(q, &m_unk13FC, 0, D_002E1468, D_002E1470);
        m_numMust = 0;
        for (s32 i = 0; i < 2; i++) {
            q = func_0024A710(q, &m_must[i], 0, D_002E1468, D_002E1470);
            m_numMust++;
            if (*q == 0) break;
        }
        if (id == m_unk10.m_id) return 1;
    }
    Func235DE0(D_002E1478);
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/CMiniGame4Res", D_002E13A8);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame4Res", D_002E13E0);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame4Res", D_002E13E8);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame4Res", D_002E13F8);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame4Res", D_002E1410);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame4Res", D_002E1420);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame4Res", D_002E1438);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame4Res", D_002E1460);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame4Res", D_002E1468);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame4Res", D_002E1470);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame4Res", D_002E1478);
INCLUDE_ASM("asm/nonmatchings/CMiniGame4Res", func_001D5140);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame4Res", D_002E14A0);

int CMiniGame4ResObj::Parse1D5360() {
    char buf[256];
    const char *p = func_0024AF10(D_002A5A04->m_text, D_002E14A0);
    if (*p == 0) return 0;
    s32 *out = m_vals;
    for (s32 i = 0; i < 14; i++) {
        p = func_0024AFE8(p, buf, 1, 0x100);
        if (*p == 0) break;
        if (buf[0] == 0) break;
        *out++ = atol(buf);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/CMiniGame4Res", func_001D5420);

INCLUDE_ASM("asm/nonmatchings/CMiniGame4Res", func_001D5550);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame4Res", D_002E1510);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame4Res", D_002E1530);

INCLUDE_ASM("asm/nonmatchings/CMiniGame4Res", func_001DE060);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame4Res", D_002E15A8);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame4Res", D_002E15B8);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame4Res", D_002E15C8);   // func_001D5550's const table: after the RTTI names, still this object
