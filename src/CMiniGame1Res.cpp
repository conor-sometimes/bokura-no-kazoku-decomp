#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CProcess.h"
//@sym memset 0x289FB0
#include "libc.h"
class CMiniGame1ResSub1BDBC0 {
public:
    void Clear();

    u8 pad0[0x870];
    u8 m_data[0x14];          // 0x870
};

extern "C" void func_001B9B30(void *p);
struct CMiniGame1Data {
    u8 pad0[0x40];
    const char *m_text;       // 0x40
};
extern CMiniGame1Data *D_002A59F8;
class CMiniGame1ResObj {
public:
    void Release1BD7C0();
    u8 pad0[0x10];
    u8 m_unk10[0x24];         // 0x10
    u8 m_unk34[0x24];         // 0x34
};

extern "C" void *func_0024F2E8(s32 size);
extern "C" void func_0024F5C0(void *a, void *b, s32 c);

struct CRand {
    u32 m_seed;
    u32 Next() {
        m_seed = m_seed * 0x19660D + 1;
        return (m_seed >> 12) & 0xFFFF;
    }
};
class CMiniGame1ResRand {
public:
    void Fill1BDB38(s32 n);
    u8 pad0[0x7B0];
    CRand m_rand;             // 0x7B0
    u8 pad7B4[0x828 - 0x7B4];
    u32 m_vals[16];           // 0x828
    s32 m_count;              // 0x868
};

extern char D_002E0DE8[];
extern char D_002E0DF0[];
extern char D_002E0DF8[];
extern "C" const char *func_0024AF10(const char *s, const char *key);
extern "C" const char *func_0024AFE8(const char *s, char *buf, s32 k, s32 size);
extern "C" const char *func_0024A710(const char *p, s32 *v, s32 k, const char *s1, const char *s2);
int Func251B88();
int Func235DE0(const char *fmt, ...) throw();
extern char D_002E0DC0[];
// Member classes of CMiniGame1 (library / CLayoutRes code, not named yet): constructors and
// destructors are called explicitly.
extern "C" void func_001B9D40(void *p);
extern "C" void func_001B9D70(void *p, s32 flags);
extern "C" void func_0025C230(void *p);
extern "C" void func_0025C2C0(void *p, s32 flags);

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

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMiniGame1.
class CMiniGame1 : public CProcess {
public:
    CMiniGame1(s32 a, s32 b);
    virtual ~CMiniGame1();
    virtual void Update();
    virtual void Draw();

    u8 pad18[0x14];
    s32 m_unk2C;              // 0x2C
    s32 m_unk30;              // 0x30
    CMiniGameTimer m_timer;   // 0x34
    u8 pad3C[0x44];
    u8 m_layout[5][0x170];    // 0x80
    CRand m_rand;             // 0x7B0
    u8 m_unk7B4[0x70];        // 0x7B4
    s32 m_unk824;             // 0x824
    u8 pad828[0x9C];
    s32 m_unk8C4;             // 0x8C4
    s32 m_unk8C8;             // 0x8C8
    u8 pad8CC[0x44];
};

class CMiniGame1ResCfg {
public:
    int Parse1BDA08();
    u8 pad0[0x30];
    s32 m_unk30;              // 0x30
    u8 pad34[0x8B4 - 0x34];
    s32 m_unk8B4;             // 0x8B4
    s32 m_unk8B8;             // 0x8B8
    s32 m_unk8BC;             // 0x8BC
    s32 m_unk8C0;             // 0x8C0
};

#include "CList.h"
class CLayoutObjPart;
class CLayoutRes {
public:
    CLayoutRes();
    virtual ~CLayoutRes();
    CLayoutObjPart *Func1B9B80(int v);
    u8 pad0[0xC];
    void *m_text;             // 0xC
    u8 pad10[0x10];
};
class CMiniGame1Res : public CListTag {
public:
    CMiniGame1Res() {}
    virtual ~CMiniGame1Res();
    virtual s32 Load();
    virtual void Release();

    CLayoutRes m_lay10;       // 0x10
    CLayoutRes m_lay34;       // 0x34
};

// From CLayoutObj.cpp (lane cv moved its functions 0x1BD188.. here: their literals are this unit's)
struct CLayoutEntry {
    const char *m_name;       // 0x0
    u8 pad4[0x9C];
};
class CLayoutObjPart {
public:


    u8 pad0[0x4];
    CLayoutEntry *m_entries;  // 0x4
    s32 m_unk8;               // 0x8
};
class CLayoutObjSub1B9E60 {
public:
    s32 GetPartUnk8();

    u8 pad0[0x4];
    CLayoutObjPart* m_part;   // 0x4
};
class CLayoutObjSub1BA0A0 {
public:
    void Reset();

    u8 pad0[0x50];
    s32 m_unk50;              // 0x50
    s32 m_unk54;              // 0x54
    f32 m_unk58;              // 0x58
    f32 m_unk5C;              // 0x5C
    s32 m_unk60;              // 0x60
};
class CLayoutHourglass;
// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CLayoutObj, its
// only virtual. The vptr follows its fields at 0x164.
class CLayoutObj {
public:
    CLayoutObj();
    virtual ~CLayoutObj();
    void Func1B9E28();
    void CallFunc1B9E28();
    void SetUnk30(f32 x, f32 y);
    void SetUnk1DC(s32 v);
    void CopyUnk1DC();
    void ResetUnk1E0();
    int Func1BA0C0();
    void Func1B9FF0();
    void Func1BA0F0();
    int Func1BA1A0();
    void Func1B9F60();
    int Set(CLayoutRes *res, int v);
    void Func1B9D40();
    void Init1BD188();
    void Func1BA210(CLayoutEntry *e, int a, f32 x, f32 y, f32 z, f32 w);
    void Draw1BA1D0(CLayoutEntry *e, int a, f32 x, f32 y, f32 z, f32 w, f32 sx, f32 sy);
    void Func1BA440(int a, f32 x, f32 y, f32 z, f32 w);
    int Func1BA520(CLayoutEntry *e, int a, f32 x, f32 y, f32 z, f32 w, f32 sx, f32 sy);
    int Draw1BA5D0(int a, f32 x, f32 y, f32 z, f32 w);
    void Printf(const char *fmt, ...);
    CLayoutEntry *FindEntry(const char *name);
    CLayoutEntry *GetEntry(int i);
    void Text1BC6A8(class CLayoutObjSub1BC320 *st, const char *s, s32 flags, f32 x, f32 y);
    const char *Text1BC900(class CLayoutObjSub1BC320 *st, const char *s, s32 flags, f32 x, f32 y);
    // The 0x1BD188 object (CLayoutHourglass) starts with a CLayoutObj; some of its methods are
    // still declared here.
    CLayoutHourglass *Hg() { return (CLayoutHourglass *)this; }

    s32 m_unk0;               // 0x0
    CLayoutObjPart *m_part;   // 0x4
    s32 m_unk8;               // 0x8
    u8 padC[0x14];
    f32 m_unk20;              // 0x20
    f32 m_unk24;              // 0x24
    f32 m_unk28;              // 0x28
    f32 m_unk2C;              // 0x2C
    f32 m_unk30;              // 0x30
    f32 m_unk34;              // 0x34
    u8 pad38[0x8];
    f32 m_unk40;              // 0x40
    f32 m_unk44;              // 0x44
    s32 m_unk48;              // 0x48
    s32 m_unk4C;              // 0x4C
    f32 m_unk50;              // 0x50
    f32 m_unk54;              // 0x54
    u8 pad58[0xC];
    char m_text[0x100];       // 0x64
    // vptr 0x164; 16-byte aligned (size 0x170)
} __attribute__((aligned(16)));
// Sound object (library, 0x25C230 constructor, 0x25C2C0 destructor), 0x6C bytes.
class CSndWork {
public:
    void Func25C648(s32 a, s32 b);
    u8 pad0[0x6C];
};
extern "C" void func_0025C230(void *p);
class CLayoutHourglass {
public:
    CLayoutHourglass();
    int Load(CLayoutRes *res, const char *name);
    void Update();
    int Draw1BD420();

    CLayoutObj m_obj;         // 0x000
    CSndWork m_snd;           // 0x170
    s32 m_unk1DC;             // 0x1DC
    s32 m_unk1E0;             // 0x1E0
    s32 m_unk1E4;             // 0x1E4
    s32 m_unk1E8;             // 0x1E8
    s32 m_unk1EC;             // 0x1EC
    s32 m_unk1F0;             // 0x1F0
    s32 m_unk1F4;             // 0x1F4
    s32 m_unk1F8;             // 0x1F8
    s32 m_unk1FC;             // 0x1FC
    s32 m_unk200;             // 0x200
};

void Func225088();
int Func2250C0();
void Func225240(s32 v);

typedef __builtin_va_list va_list;
#define va_start(ap, last) __builtin_stdarg_start(ap, last)
#define va_end(ap) __builtin_va_end(ap)
//@sym strcmp 0x28B190
#include "libc.h"
//@sym vsprintf 0x28F338
extern "C" int vsprintf(char *buf, const char *fmt, va_list ap);
class CUnk237E90 {
public:
    void Func237E90(int v);
};
struct CLayoutDrawObj { u8 pad0[0x10]; CUnk237E90 m10; };
struct CLayoutImage { u8 pad0[0x18]; s32 m18; u8 pad1C[4]; s32 m20; s32 m24; };
struct CLayoutImageRef { u8 pad0[0xC]; CLayoutImage *m_image; };
void Func227DC8(s64 a, int size, int b);
class CLayoutDraw {
public:
    void Upload(CLayoutImageRef *r);
    u8 pad0[8];
    CLayoutDrawObj *m8;       // 0x8
    u8 padC[0xC];
    s64 m18;                  // 0x18
};
class CLayoutObjSub1BC320 {
public:
    void Init();
    s32 m0; f32 m4, m8; s32 mC; f32 m10; u8 pad14[0xC]; f32 m20, m24, m28, m2C, m30, m34; s32 m38, m3C;
} __attribute__((aligned(8)));
int LayoutFlagX(int v);
int LayoutFlagY(int v);
const char *ParseUInt(const char *s, int *out);
const char *ParseSjis(const char *s, s16 *out);
void Func2251E8();
extern "C" void func_00227A20();
extern "C" void func_00227AA8();
extern "C" void func_00226DF8(s32 reg, u64 v);
extern "C" s32 func_0023A0E8();
extern "C" s32 func_0023A2F0(s32 a);
extern "C" u64 func_0023C650(s32 a);
extern "C" u64 func_0023C658(s32 a);
void *Func237570(s32 size);
void Func237A88(void *p, s32 n);
void *Func237C30(void *p);
void Func238158(void *p, s32 v);
class CDisp2BA128 {
public:
    virtual void Vf0();
    virtual void Vf1();
    virtual void Vf2();
    virtual void Vf3();
    virtual u64 GetFrame();
    virtual u64 GetZBuf();
};
extern CDisp2BA128 *D_002BA128;
extern "C" CLayoutEntry *func_001B9E78(CLayoutObj *o, s32 i);
const char *Func24AF10(void *p, const char *key);
extern "C" const char *func_0024AD10(const char *p, char *buf, s32 k, s32 n);
extern "C" long atol(const char *s);
extern char D_002E0D50[];

//@sym Text1BC900__10CLayoutObjP19CLayoutObjSub1BC320PCciff 0x1BC900

struct CLayoutGlyph {
    s16 m0;
    u8 pad2[0x1FE];
};
extern "C" const char *func_001BC870(const char *s, CLayoutGlyph *g);
extern "C" void func_001BCAF8(CLayoutObj *o, CLayoutObjSub1BC320 *st, CLayoutGlyph *g, s32 flags, f32 x, f32 y);
extern "C" int func_001BCFB0(CLayoutObj *o, CLayoutObjSub1BC320 *st, const char **pp, f32 *w);
// Float view of the s32 fields of CLayoutObjSub1BC320.
#define LF(v) (*(f32 *)&(v))

extern char D_002E0D60[];
// Reset() is defined earlier in this file; called through this alias (config/aliases.ld) the
// delay slots of Draw1BD420 come out like retail's (GCC fills differently around calls to
// functions it has already compiled).
extern "C" void func_001BA0A0(CLayoutObjSub1BA0A0 *p);

struct CLayoutGroup {
    s32 m0;                   // 0x0
    CLayoutEntry *m_items;    // 0x4
    s32 m_num;                // 0x8
};
struct CLayoutEntryHdr {
    const char *m_name;       // 0x0
    u32 m_flags;              // 0x4
    u8 pad8[0x8];
    CLayoutGroup *m_group;    // 0x10
};
extern "C" void func_001BA7E8(CLayoutObj *o, CLayoutEntry *e, int a, f32 x, f32 y, f32 z, f32 w);
extern "C" void func_001BADB0(CLayoutObj *o, CLayoutEntry *e, int a, f32 x, f32 y, f32 z, f32 w);
extern "C" void func_001BB438(CLayoutObj *o, CLayoutEntry *e, int a, f32 x, f32 y, f32 z, f32 w);
extern "C" void func_001BBDE8(CLayoutObj *o, CLayoutEntry *e, int a, f32 x, f32 y, f32 z, f32 w);
extern "C" void func_001BC360(CLayoutObj *o, CLayoutEntry *e, int a, f32 x, f32 y, f32 z, f32 w);
extern "C" void func_001BBD08(CLayoutObj *o, CLayoutEntry *e, int a);

struct CLayoutTbl { u32 m0; CLayoutEntry *m_entries; s32 m_count; };
// @decl-end

CLayoutHourglass::CLayoutHourglass() {
    func_0025C230(&m_snd);
    m_unk1DC = 0;
    m_unk1E4 = 0;
    m_unk1E8 = 0;
    m_unk1EC = 0;
    m_unk1F0 = 0;
    m_unk1FC = 1;
    m_unk1F4 = -1;
    m_unk200 = 1;
    m_unk1E0 = 0;
}

int CLayoutHourglass::Load(CLayoutRes *res, const char *name) {
    char buf[0x100];
    const char *p = Func24AF10(res->m_text, D_002E0D50);
    if (!*p) return 0;
    s32 i = 0;
    s32 *v = &m_unk1F8;
    for (; i < 1; i++) {
        p = func_0024AD10(p, buf, 1, 0x100);
        if (!buf[0]) break;
        *v++ = atol(buf);
    }
    return m_obj.Set(res, (int)name);
}

void CLayoutObj::CallFunc1B9E28() {
    Func1B9E28();
}

void CLayoutObj::SetUnk30(f32 x, f32 y) {
    if (m_unk0) {
        m_unk30 = x;
        m_unk34 = y;
    }
}

void CLayoutObj::SetUnk1DC(s32 v) {
    Hg()->m_unk1DC = v;
}

void CLayoutObj::CopyUnk1DC() {
    Hg()->m_unk1E0 = Hg()->m_unk1DC;
}

void CLayoutObj::ResetUnk1E0() {
    Hg()->m_unk1E4 = 0;
    Hg()->m_unk1E8 = 0;
    Hg()->m_unk1E0 = 0;
    Hg()->m_unk1F4 = -1;
}

void CLayoutHourglass::Update() {
    if (m_unk1E0) {
        s32 t = --m_unk1E0;
        if (t == 0) {
            m_unk1E0 = 0;
            m_unk1F4 = 0;
        } else if (t < 0xB5) {
            s32 old = m_unk1F4;
            s32 sec = t / 60 + 1;
            m_unk1F4 = sec;
            if (sec != old && m_unk200) m_snd.Func25C648(0x73, 0);
        }
        m_unk1E8 = m_unk1E4 = (s32)((f32)(m_unk1DC - m_unk1E0) / (f32)m_unk1DC * 22.0f);
        if (m_unk1F8 < ++m_unk1EC) {
            if (++m_unk1F0 >= 4) m_unk1F0 = 0;
            m_unk1EC = 0;
        }
    }
}

int CLayoutHourglass::Draw1BD420() {
    CLayoutObjSub1BA0A0 *st = (CLayoutObjSub1BA0A0 *)this;
    m_obj.Func1B9FF0();
    m_obj.Draw1BA1D0(func_001B9E78(&m_obj, 0), 0, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    if (m_unk1E0) {
        m_obj.Draw1BA1D0(func_001B9E78(&m_obj, 3), 0, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f);
        st->m_unk60 = 0x4000000;
        m_obj.Draw1BA1D0(func_001B9E78(&m_obj, m_unk1F0 + 4), 0, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    }
    if (m_unk1E4 != 0x16) m_obj.Draw1BA1D0(func_001B9E78(&m_obj, m_unk1E4 + 8), 0, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    if (m_unk1E8) m_obj.Draw1BA1D0(func_001B9E78(&m_obj, m_unk1E8 + 0x1D), 0, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    st->m_unk60 = 0;
    m_obj.Draw1BA1D0(func_001B9E78(&m_obj, 1), 0, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    m_obj.Draw1BA1D0(func_001B9E78(&m_obj, 2), 0, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    if (m_unk1F4 >= 0 && m_unk1FC) {
        m_obj.Draw1BA1D0(func_001B9E78(&m_obj, 0x36), 0, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f);
        st->m_unk60 = 0x4000000;
        m_obj.Printf(D_002E0D60, m_unk1F4);
        m_obj.Draw1BA1D0(func_001B9E78(&m_obj, 0x34), 0, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    }
    func_001BA0A0(st);
    return m_obj.Func1BA0C0();
}

CMiniGame1Res *NewMiniGame1Res() {
    return new CMiniGame1Res;
}

INCLUDE_RODATA("asm/nonmatchings/CMiniGame1Res", D_002E0D50);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame1Res", D_002E0D60);
INCLUDE_ASM("asm/nonmatchings/CMiniGame1Res", func_001BD700);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame1Res", D_002E0DC0);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame1Res", D_002E0DE8);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame1Res", D_002E0DF0);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame1Res", D_002E0DF8);

void CMiniGame1ResObj::Release1BD7C0() {
    D_002A59F8 = 0;
    func_001B9B30(m_unk34);
    func_001B9B30(m_unk10);
}

void Func1BD7F8(void *a, s32 b, s32 c) {
    CMiniGame1 *p = new CMiniGame1(b, c);
    func_0024F5C0(a, p, 0);
}

CMiniGame1::CMiniGame1(s32 a, s32 b) {
    CRand *rand = &m_rand;
    func_001B9D40(m_layout[0]);
    func_001B9D40(m_layout[1]);
    func_001B9D40(m_layout[2]);
    func_001B9D40(m_layout[3]);
    func_001B9D40(m_layout[4]);
    rand->m_seed = 1;
    func_0025C230(m_unk7B4);
    if (!D_002A59F8) {
        Func235DE0(D_002E0DC0);
    }
    rand->m_seed = Func251B88();
    m_unk8C4 = 1;
    m_unk2C = a;
    m_unk30 = b;
    m_unk824 = -1;
    m_unk8C8 = 1;
}

INCLUDE_ASM("asm/nonmatchings/CMiniGame1Res", _$_10CMiniGame1);

int CMiniGame1ResCfg::Parse1BDA08() {
    char key[256];
    s32 id;
    const char *p = func_0024AF10(D_002A59F8->m_text, D_002E0DE8);
    if (*p == 0) return 0;
    while ((p = func_0024AFE8(p, key, 1, 0x100), *p != 0) || key[0] != 0) {
        const char *q = func_0024A710(key, &id, 0, D_002E0DF0, D_002E0DF8);
        q = func_0024A710(q, &m_unk8B4, 0, D_002E0DF0, D_002E0DF8);
        q = func_0024A710(q, &m_unk8B8, 0, D_002E0DF0, D_002E0DF8);
        q = func_0024A710(q, &m_unk8BC, 0, D_002E0DF0, D_002E0DF8);
        func_0024A710(q, &m_unk8C0, 0, D_002E0DF0, D_002E0DF8);
        if (id == m_unk30) return 1;
    }
    return 0;
}

void CMiniGame1ResRand::Fill1BDB38(s32 n) {
    for (s32 i = 0; i < n; i++) {
        m_vals[m_count] = ((m_rand.Next() << 16) | m_rand.Next()) % 5;
        m_count++;
    }
}

void CMiniGame1ResSub1BDBC0::Clear() {
    memset(m_data, 0, sizeof(m_data));
}

INCLUDE_ASM("asm/nonmatchings/CMiniGame1Res", Update__10CMiniGame1);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame1Res", D_002E0E48);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame1Res", D_002E0E68);

INCLUDE_ASM("asm/nonmatchings/CMiniGame1Res", Draw__10CMiniGame1);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame1Res", D_002E0EE0);
INCLUDE_RODATA("asm/nonmatchings/CMiniGame1Res", D_002E0EF0);
