#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern void *D_002A5408;

class CVec4 {
public:
    f32 x, y, z, w;
};

// One entry (0x100 bytes) of a CStatusItem.
class CStatusEntry {
public:
    f32 m_pos[2];             // 0x0
    u8 pad8[0x8];
    f32 m_unk10[2];           // 0x10
    u8 pad18[0x8];
    CVec4 m_col[4];           // 0x20
    f32 m_unk60[2];           // 0x60
    u8 pad68[0x8];
    f32 m_unk70[2];           // 0x70
    u8 pad78[0x8];
    CVec4 m_cur[4];           // 0x80
    f32 m_unkC0[2];           // 0xC0
    u8 padC8[0x8];
    s32 m_unkD0;              // 0xD0
    u8 padD4[0x4];
    s32 m_unkD8;              // 0xD8
    f32 m_unkDC;              // 0xDC
    s32 m_unkE0;              // 0xE0
    s32 m_unkE4;              // 0xE4
    char *m_text;             // 0xE8
    s32 m_unkEC;              // 0xEC
    s32 m_unkF0;              // 0xF0
    s32 m_unkF4;              // 0xF4
    u8 padF8[0x8];
};

class CStatusItem {
public:
    void Func1A3378();
    void SetText(s32 i, const char *s);
    int GetUnk10(f32 *x, f32 *y, s32 i);
    int Func1A38D0(s32 i);
    int GetPos(f32 *x, f32 *y, s32 i);
    void Func1A3628();
    void SetUnk34(f32 v);
    void Start();
    void ResetColors();
    s32 GetUnkE4(s32 i);
    int Select(s32 n);
    void SetMappedColor(s32 n, const CVec4 *v);
    int GetMappedUnkC0(f32 *x, f32 *y, s32 n);
    int SetPos(s32 i, f32 x, f32 y);
    int GetUnk60Ofs(f32 *x, f32 *y, s32 i);
    int SetUnk60(s32 i, f32 x, f32 y);
    int SetUnk10(s32 i, f32 x, f32 y);
    int GetUnk70(f32 *x, f32 *y, s32 i);
    int SetUnk70(s32 i, f32 x, f32 y);
    int GetUnkC0(f32 *x, f32 *y, s32 i);
    int SetUnkC0(s32 i, f32 x, f32 y);
    void SetUnkF0(s32 i, s32 v);
    int SetColor(s32 i, const CVec4 *v);
    int GetColor(CVec4 *out, s32 i);
    int ScaleAlpha(s32 i, f32 s);
    int SetUnkD0(s32 i, s32 v);
    s32 GetUnkD0(s32 i);
    s32 GetUnkEC(s32 i);

    u8 pad0[0x20];
    s32 m_state;              // 0x20
    s32 m_count;              // 0x24
    CStatusEntry *m_entries;  // 0x28
    u8 pad2C[0x4];
    s32 m_unk30;              // 0x30
    f32 m_unk34;              // 0x34
    s32 m_mapCount;           // 0x38
    s32 m_sel;                // 0x3C
    u8 *m_map;                // 0x40
    u8 pad44[0x3C];
    f32 m_unk80;              // 0x80
    f32 m_unk84;              // 0x84
};

#include "CFlagWork.h"
extern CFlagWork *D_002A4B60;
int Func235DE0(const char *fmt, ...);
void Func270C50(CVec4 *dst, const CVec4 *src);

class CStatusWin {
public:
    int SetUnk4C(u32 v);
    void StartItem1();
    void StartItem5();
    void SetUnk64(u32 i, s32 v);
    int SetUnk50(u32 i);
    void Func19F4A8();
    void Func19F668();
    void Func19E008();
    void Func19E0B8();
    void Func19E148(f32 v);
    s32 Func19E5C8(f32 v, s32 n);
    s32 Func19E300(char *out, s32 n);
    void Func19E6A0(f32 v);
    void Func19E780(f32 v);
    void Func19ECB0(f32 x, f32 y);
    void CallFunc19F400();
    void Func19F400();
    f32 GetItemUnk34();
    s32 GetItemState();
    void Advance2To3();
    void Advance2To4();
    void ItemFunc1A3628();
    void ItemStart();
    void SetUnk5C(s32 v);
    s32 GetItemState2();
    f32 GetItemUnk34_2();

    u8 pad0[0x48];
    CStatusItem* m_item;      // 0x48
    s32 m_state;              // 0x4C
    u32 m_unk50;              // 0x50
    s32 m_unk54;              // 0x54
    u8 pad58[0x4];
    s32 m_unk5C;              // 0x5C
    s32 m_unk60;              // 0x60
    s32 m_unk64;              // 0x64
    s32 m_unk68;              // 0x68
};

class CStatusWinSub1A1BF0 {
public:
    ~CStatusWinSub1A1BF0();

    u8 pad0[0x90] __attribute__((aligned(16)));
};

void *operator new(unsigned int n);
class CStatusWinSub1A0A10 {
public:
    ~CStatusWinSub1A0A10();
    void Release();
    int Init();
    void Clear();
    u64 SwapUnk0(u64 v);
    u64 SwapUnk8(u64 v);
    CStatusWinSub1A1BF0 *Find(const char *name);

    u64 m_unk0;               // 0x0
    u64 m_unk8;               // 0x8
    s32 m_unk10;              // 0x10
    CStatusWinSub1A1BF0 *m_unk14; // 0x14
};

class CStatusWinSub1A40B8 {
public:
    void SetUnk80(f32 x, f32 y);

    u8 pad0[0x80];
    f32 m_unk80;              // 0x80
    f32 m_unk84;              // 0x84
};

//@sym __builtin_new 0x245648
//@sym __builtin_vec_delete 0x2456D0
//@sym _$_19CStatusWinSub1A1BF0 0x1A1BF0
extern const char D_002DDFE8[];
extern const char D_002DDFB8[];
extern const char D_002DDF98[];
extern const char D_002DEAC0[];
extern const char D_002DEB10[];
extern const char D_002DEB20[];
extern const char D_002DEB60[];
extern const char D_002DE660[];
extern const char D_002DE680[];
extern const char D_002DE6F0[];
extern const char D_002DE720[];
extern const char D_002DE758[];
extern const char D_002DE7B8[];
extern const char D_002DE7E8[];
extern const char D_002DE818[];
extern const char D_002DE878[];
extern const char D_002DE8A8[];
extern const char D_002DE8D8[];
extern const char D_002DE908[];
extern const char D_002DE938[];
extern const char D_002DE968[];
extern const char D_002DE9A0[];
extern const char D_002DE9D0[];
extern const char D_002DEA00[];
extern const char D_002DEA30[];
extern const char D_002DEA60[];
extern s32 D_002A540C;
extern s32 D_002A5410;
extern s32 D_002A5414;
void Func2491A8(void *buf, const char *path, s32 a, s32 b, s32 c);
s32 Func249248(void *buf);
void Func249348();
void *Func24A4C0(const char *name);
// The kanji input window (CMenuInputKanji.cpp); only its size is needed here.
class CMenuInputKanji {
public:
    CMenuInputKanji(s32 kind);

    u8 pad0[0x894];
};
class CUnk1B6488 {
public:
    void Func1B6488(f32 x, f32 y);
};
extern CUnk1B6488 *D_002A5538;
class CStatusWinSub1A4A40 {
public:
    s32 Load();
    void Func1A4E88();
    s32 Func1A4AE0(u32 k);

    u8 pad0[0x58];
    CStatusItem *m_item;      // 0x58
    u8 pad5C[0x10];
    s32 m_unk6C;              // 0x6C
    u8 pad70[0xC];
    void *m_unk7C;            // 0x7C
    char m_str[0x100];        // 0x80
};

//@sym SetColor__11CStatusItemiPC5CVec4 0x1A3E28
extern const char D_002DE848[];
extern const char D_002DE788[];

//@sym SetUnkF0__11CStatusItemii 0x1A3DC8
#include "libc.h"
extern CFlagWork *D_002A5358;
extern "C" void func_00185AA0(void *p, s32 k, s32 a, s32 b, s32 c, s32 d, s32 e);
extern const char D_002DDEE0[];
extern const char D_002DE090[];
extern const char D_002DEF20[][8];
const char *Func24AF10(void *p, const char *key);
const char *Func24AFE8(const char *p, char *buf, s32 a, s32 n);
extern "C" unsigned int strlen(const char *s);
extern const char D_002DEB40[];
inline char *StrCat(char *d, const char *s) { strcpy(d + strlen(d), s); return d; }

//@sym Func19E300__10CStatusWinPci 0x19E300
#include "IGameDBMgr.h"
extern "C" int sprintf(char *buf, const char *fmt, ...);
void Func185F18(char *buf, s32 a, s32 b);
void Func185E80(char *buf, s32 a);
extern const char D_002DDF00[];
extern const char D_002DE6A8[], D_002DE6C8[];
extern const char D_002DE480[];
extern "C" unsigned int strlen(const char *s);
#include "libc.h"
// @decl-end

INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDA28);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDA38);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDA70);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDA78);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDA88);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDA98);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDAB8);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDAE8);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDB18);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDB40);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", jtbl_002DDB70);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDB88);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDBA0);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDBA8);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDBB0);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDBB8);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDBC0);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDBC8);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDBD0);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDBD8);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDBE8);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDBF8);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDC08);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDC18);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDC20);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDC28);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDC40);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDC48);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDC50);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDC58);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDC60);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDC68);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDC90);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDCB8);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDCE0);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDCE8);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDD10);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDD30);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDD50);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDD70);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDD90);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDDB0);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDDD0);
INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019CD98);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019D0A8);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019D138);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019D570);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019D5A0);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDE30);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDE48);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDE60);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDE80);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDEA0);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019DBA0);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019DD48);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019DDC0);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019DE80);

void CStatusWin::Func19E008() {
    s32 i;
    switch (m_unk60) {
    case 0:
        for (i = 5; i < 15; i++) m_item->SetUnkF0(i, 0);
        break;
    case 1:
        for (i = 5; i < 11; i++) m_item->SetUnkF0(i, 0);
        break;
    default:
        Func235DE0(D_002DDEE0, m_unk60);
    }
}

void CStatusWin::Func19E0B8() {
    char buf[0x200];
    char *name = D_002A2988->GetCharaName(m_unk50);
    sprintf(buf, (const char *)m_item->GetUnkE4(5), (char *)this + 0x80, name);
    m_item->SetText(5, buf);
    m_item->SetUnkF0(5, 1);
}

INCLUDE_ASM("asm/nonmatchings/CStatusWin", Func19E148__10CStatusWinf);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", Func19E300__10CStatusWinPci);

s32 CStatusWin::Func19E5C8(f32 v, s32 n) {
    char buf[0x100];
    char tmp[0x100];
    s32 r = Func19E300(tmp, n);
    s32 c;
    sprintf(buf, (const char *)m_item->GetUnkE4(7), tmp);
    c = (s32)(v * 128.0f);
    c = c < 0 ? 0 : (c < 0x100 ? c : 0xFF);
    sprintf(tmp, D_002DDF00, c, buf);
    m_item->SetText(7, tmp);
    m_item->SetUnkF0(7, 1);
    return r;
}

void CStatusWin::Func19E6A0(f32 v) {
    char buf[0x100];
    char a[0x100];
    char b[0x100];
    s32 c = (s32)(v * 128.0f);
    c = c < 0 ? 0 : (c < 0x100 ? c : 0xFF);
    Func185F18(a, m_unk50, 1);
    Func185E80(b, m_unk50);
    sprintf(buf, (const char *)m_item->GetUnkE4(8), c, a, b);
    m_item->SetText(8, buf);
    m_item->SetUnkF0(8, 1);
}

INCLUDE_ASM("asm/nonmatchings/CStatusWin", Func19E780__10CStatusWinf);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019E8B0);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", Func19ECB0__10CStatusWinff);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019F200);

int CStatusWin::SetUnk50(u32 i) {
    if (i >= 6) {
        return Func235DE0(D_002DDF98, i);
    }
    if (m_unk50 != i) {
        m_unk50 = i;
        Func19F4A8();
        CallFunc19F400();
    }
}

void CStatusWin::SetUnk64(u32 i, s32 v) {
    if (i >= 6) {
        Func235DE0(D_002DDFB8, i);
        i = 0;
    }
    m_unk68 = v;
    m_unk64 = i;
}

void CStatusWin::CallFunc19F400() {
    Func19F400();
}

void CStatusWin::Func19F400() {
    Func19E008();
    Func19E0B8();
    Func19E148(1.0f);
    *(s32 *)&pad58 = -1;
    Func19E5C8(1.0f, -1);
    if (m_unk60 == 0) {
        Func19E6A0(1.0f);
        Func19E780(1.0f);
    }
    Func19ECB0(1.0f, 1.0f);
}

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_0019F498() {
}

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_0019F4A0() {
}

void CStatusWin::Func19F4A8() {
    s32 a = D_002A5358->Func1091B0(m_unk50 + 0x52);
    s32 b = D_002A5358->Func1091B0(m_unk50 + 0x58);
    s32 c = D_002A5358->Func1091B0(m_unk50 + 0x5E);
    s32 d = D_002A5358->Func1091B0(m_unk50 + 0x4C);
    func_00185AA0((u8 *)this + 0x80, m_unk50, a, b, c, d, D_002A5358->Func1091B0(m_unk50 + 0x46));
}

void CStatusWin::StartItem1() {
    if (m_item) {
        m_item->Func1A3628();
        m_state = 1;
    }
}

void CStatusWin::StartItem5() {
    if (m_item) {
        m_item->Start();
        m_state = 5;
    }
}

f32 CStatusWin::GetItemUnk34() {
    return m_item ? m_item->m_unk34 : 0.0f;
}

s32 CStatusWin::GetItemState() {
    return m_item ? m_item->m_state : -1;
}

void CStatusWin::Advance2To3() {
    if (m_state == 2) {
        m_unk54 = 0;
        m_state = 3;
    }
}

void CStatusWin::Advance2To4() {
    if (m_state == 2) {
        m_unk54 = 0;
        m_state = 4;
    }
}

void CStatusWin::Func19F668() {
    if (m_state == 3) {
        m_unk54 = D_002A4B60->Func1091B0(0x22);
    } else if (m_state == 4) {
        m_state = 2;
    }
}

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019F6C0);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019FA50);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019FC30);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019FE18);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A00B0);

int CStatusWin::SetUnk4C(u32 v) {
    if (v >= 2) {
        return Func235DE0(D_002DDFE8, v);
    }
    m_state = v;
}

void CStatusWin::ItemFunc1A3628() {
    if (m_item) {
        m_item->Func1A3628();
    }
}

void CStatusWin::ItemStart() {
    if (m_item) {
        m_item->Start();
    }
}

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A01C8);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A0280);

void CStatusWin::SetUnk5C(s32 v) {
    m_unk5C = v;
}

s32 CStatusWin::GetItemState2() {
    return m_item ? m_item->m_state : -1;
}

f32 CStatusWin::GetItemUnk34_2() {
    return m_item ? m_item->m_unk34 : 0.0f;
}

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A03E8);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A0510);

CStatusWinSub1A0A10 *NewStatusWinSub1A0A10() {
    CStatusWinSub1A0A10 *p = (CStatusWinSub1A0A10 *)operator new(0x18);
    p->Init();
    return p;
}

// Returns int but has no return statement (that is why $v1 holds the address).
int CStatusWinSub1A0A10::Init() {
    D_002A5408 = this;
}

CStatusWinSub1A0A10::~CStatusWinSub1A0A10() {
    Release();
    D_002A5408 = 0;
}

void CStatusWinSub1A0A10::Clear() {
    m_unk0 = 0;
    m_unk8 = 0;
    m_unk10 = 0;
    m_unk14 = 0;
}

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A0A98);

void CStatusWinSub1A0A10::Release() {
    if (m_unk14) {
        delete[] m_unk14;
        m_unk14 = 0;
    }
}

u64 CStatusWinSub1A0A10::SwapUnk0(u64 v) {
    u64 old = m_unk0;
    m_unk0 = v;
    return old;
}

u64 CStatusWinSub1A0A10::SwapUnk8(u64 v) {
    u64 old = m_unk8;
    m_unk8 = v;
    return old;
}

CStatusWinSub1A1BF0 *CStatusWinSub1A0A10::Find(const char *name) {
    s32 i;
    for (i = 0; i < m_unk10; i++) {
        CStatusWinSub1A1BF0 *p = &m_unk14[i];
        if (!strcmp((const char *)p, name)) return p;
    }
    Func235DE0(D_002DE090, name);
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A0D98);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A1040);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A1418);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A18B0);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A1AA0);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A1B38);

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_001A1BE8() {
}

INCLUDE_ASM("asm/nonmatchings/CStatusWin", _$_19CStatusWinSub1A1BF0);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A1CF0);

void CStatusItem::Func1A3378() {
    s32 i;
    m_state = 0;
    m_unk34 = 0;
    m_unk30 = 0;
    m_sel = 0;
    m_unk80 = 0;
    m_unk84 = 0;
    for (i = 0; i < m_count; i++) {
        CStatusEntry *e = &m_entries[i];
        s32 k;
        e->m_unkF0 = 1;
        Func270C50((CVec4 *)e->m_unk60, (CVec4 *)e->m_pos);
        Func270C50((CVec4 *)e->m_unk70, (CVec4 *)e->m_unk10);
        for (k = 0; k < 4; k++) Func270C50(&e->m_cur[k], &e->m_col[k]);
        if (e->m_unkF4 == 8 && e->m_text) e->m_text[0] = D_002DE480[0];
    }
}

void CStatusItem::SetUnk34(f32 v) {
    m_unk34 = v;
}

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A3488);

void CStatusItem::ResetColors() {
    s32 i;
    for (i = 0; i < m_count; i++) {
        CStatusEntry *e = &m_entries[i];
        Func270C50(&e->m_cur[0], &e->m_col[0]);
        Func270C50(&e->m_cur[1], &e->m_col[1]);
        Func270C50(&e->m_cur[2], &e->m_col[2]);
        Func270C50(&e->m_cur[3], &e->m_col[3]);
        e->m_unkD8 = 0;
    }
    m_state = 0;
}

void CStatusItem::Func1A3628() {
    m_state = 1;
    m_unk30 = 0;
    if (m_mapCount) {
        s32 i;
        for (i = 0; i < m_mapCount; i++) {
            m_entries[m_map[i]].m_unkDC = 0.0f;
            m_entries[m_map[i]].m_unkE0 = 0;
        }
    }
}

void CStatusItem::Start() {
    m_state = 4;
    m_unk30 = 0;
}

s32 CStatusItem::GetUnkE4(s32 i) {
    if (i < 0 || m_count - 1 < i) {
        Func235DE0(D_002DE660, this, i);
        return 0;
    }
    CStatusEntry *e = &m_entries[i];
    if (e->m_unkF4 != 8 && e->m_unkF4 != 5) {
        Func235DE0(D_002DE680, this, i);
        return 0;
    }
    return e->m_unkE4;
}

void CStatusItem::SetText(s32 i, const char *s) {
    if (i < 0 || m_count - 1 < i) return (void)Func235DE0(D_002DE660, this, i);
    if (strlen(s) > 0x200) return (void)Func235DE0(D_002DE6A8, this, s);
    CStatusEntry *e = &m_entries[i];
    if (e->m_unkF4 != 8) return (void)Func235DE0(D_002DE6C8, this, i);
    strcpy(e->m_text, s);
}

int CStatusItem::Select(s32 n) {
    if (n == -1) {
        m_sel = n;
    } else {
        if (n < 0 || n > m_mapCount - 1) {
            return Func235DE0(D_002DE6F0, this, n);
        }
        m_sel = n;
        CStatusEntry *e = &m_entries[m_map[n]];
        e->m_unkDC = 1.0f;
        e->m_unkE0 = 15;
    }
}

void CStatusItem::SetMappedColor(s32 n, const CVec4 *v) {
    if (n < 0 || m_mapCount - 1 < n) return (void)Func235DE0(D_002DE720, this, n);
    SetColor(m_map[n], v);
}

int CStatusItem::GetMappedUnkC0(f32 *x, f32 *y, s32 n) {
    if (n < 0 || m_mapCount - 1 < n) return Func235DE0(D_002DE758, this, n);
    CStatusEntry *e = &m_entries[m_map[n]];
    *x = e->m_unkC0[0];
    *y = e->m_unkC0[1];
}

int CStatusItem::GetPos(f32 *x, f32 *y, s32 i) {
    if (i < 0 || m_count - 1 < i) return Func235DE0(D_002DE788, this, i);
    CStatusEntry *e = &m_entries[i];
    *x = e->m_pos[0];
    *y = e->m_pos[1];
}

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A3A18);

int CStatusItem::GetUnk60Ofs(f32 *x, f32 *y, s32 i) {
    if (i < 0 || m_count - 1 < i) return Func235DE0(D_002DE7E8, this, i);
    CStatusEntry *e = &m_entries[i];
    *x = e->m_unk60[0] + m_unk80;
    *y = e->m_unk60[1] + m_unk84;
}

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A3AF8);

int CStatusItem::GetUnk10(f32 *x, f32 *y, s32 i) {
    if (i < 0 || m_count - 1 < i) return Func235DE0(D_002DE848, this, i);
    CStatusEntry *e = &m_entries[i];
    *x = e->m_unk10[0];
    *y = e->m_unk10[1];
}

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A3BC8);

int CStatusItem::GetUnk70(f32 *x, f32 *y, s32 i) {
    if (i < 0 || m_count - 1 < i) return Func235DE0(D_002DE8A8, this, i);
    CStatusEntry *e = &m_entries[i];
    *x = e->m_unk70[0];
    *y = e->m_unk70[1];
}

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A3C98);

int CStatusItem::GetUnkC0(f32 *x, f32 *y, s32 i) {
    if (i < 0 || m_count - 1 < i) return Func235DE0(D_002DE908, this, i);
    CStatusEntry *e = &m_entries[i];
    *x = e->m_unkC0[0];
    *y = e->m_unkC0[1];
}

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A3D68);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", SetUnkF0__11CStatusItemii);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", SetColor__11CStatusItemiPC5CVec4);

int CStatusItem::GetColor(CVec4 *out, s32 i) {
    if (i < 0 || m_count - 1 < i) return Func235DE0(D_002DE9D0, this, i);
    CStatusEntry *e = &m_entries[i];
    out->x = e->m_col[0].x;
    out->y = e->m_col[0].y;
    out->z = e->m_col[0].z;
    out->w = e->m_col[0].w;
}

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A3F20);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A3FA8);

s32 CStatusItem::GetUnkD0(s32 i) {
    if (i < 0 || m_count - 1 < i) {
        Func235DE0(D_002DEA30, this, i);
        return -1;
    }
    CStatusEntry *e = &m_entries[i];
    return e->m_unkD0;
}

s32 CStatusItem::GetUnkEC(s32 i) {
    if (i < 0 || m_count - 1 < i) {
        Func235DE0(D_002DEA60, this, i);
        return -1;
    }
    CStatusEntry *e = &m_entries[i];
    return e->m_unkEC;
}

void CStatusWinSub1A40B8::SetUnk80(f32 x, f32 y) {
    m_unk80 = x;
    m_unk84 = y;
}

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A40C8);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", Func1A4298__10CUnk1A4298);

CMenuInputKanji *CreateStatusWinSub1A4F20(u32 kind) {
    if (kind >= 3) {
        Func235DE0(D_002DEAC0, kind);
        kind = 0;
    }
    return new CMenuInputKanji(kind);
}

s32 CStatusWinSub1A4A40::Load() {
    u8 buf[0x100];
    s32 r = 0;
    Func2491A8(buf, 0, D_002A540C, D_002A5410, D_002A5414);
    if (Func249248(buf)) {
        m_unk7C = Func24A4C0(D_002DEB10);
        if (!m_unk7C) {
            Func235DE0(D_002DEB20);
        } else {
            r = 1;
        }
    }
    Func249348();
    return r;
}

s32 CStatusWinSub1A4A40::Func1A4AE0(u32 k) {
    char buf[0x400];
    const char *p;
    if (k >= 0x30) {
        m_str[0] = 0;
        return 1;
    }
    p = Func24AF10(m_unk7C, D_002DEF20[k]);
    if (!p) {
        Func235DE0(D_002DEB40);
        return 0;
    }
    m_str[0] = 0;
    while ((p = Func24AFE8(p, buf, 1, 0x100), *p) || buf[0]) {
        StrCat(m_str, buf);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A4BA8);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A4D28);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A4E88);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDEC0);
