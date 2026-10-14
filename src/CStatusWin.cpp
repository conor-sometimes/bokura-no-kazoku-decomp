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
    u8 padE8[0x4];
    s32 m_unkEC;              // 0xEC
    s32 m_unkF0;              // 0xF0
    s32 m_unkF4;              // 0xF4
    u8 padF8[0x8];
};

class CStatusItem {
public:
    void Func1A3628();
    void SetUnk34(f32 v);
    void Start();
    void ResetColors();
    s32 GetUnkE4(s32 i);
    int Select(s32 n);
    int SetMappedColor(s32 n, const CVec4 *v);
    int GetMappedUnkC0(f32 *x, f32 *y, s32 n);
    int SetPos(s32 i, f32 x, f32 y);
    int GetUnk60Ofs(f32 *x, f32 *y, s32 i);
    int SetUnk60(s32 i, f32 x, f32 y);
    int SetUnk10(s32 i, f32 x, f32 y);
    int GetUnk70(f32 *x, f32 *y, s32 i);
    int SetUnk70(s32 i, f32 x, f32 y);
    int GetUnkC0(f32 *x, f32 *y, s32 i);
    int SetUnkC0(s32 i, f32 x, f32 y);
    int SetUnkF0(s32 i, s32 v);
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

class CFlagWork {
public:
    int Func1091B0(s32 id);
};
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
    void Func19E5C8(f32 v, s32 n);
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
    u8 pad50[0x4];
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

class CStatusWinSub1A0A10 {
public:
    ~CStatusWinSub1A0A10();
    void Release();
    int Init();
    void Clear();
    u64 SwapUnk0(u64 v);
    u64 SwapUnk8(u64 v);

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

//@sym __19CStatusWinSub1A4F20i 0x1A4F20
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
class CStatusWinSub1A4F20 {
public:
    CStatusWinSub1A4F20(s32 kind) throw();

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

    u8 pad0[0x58];
    CStatusItem *m_item;      // 0x58
    u8 pad5C[0x10];
    s32 m_unk6C;              // 0x6C
    u8 pad70[0xC];
    void *m_unk7C;            // 0x7C
};
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

INCLUDE_ASM("asm/nonmatchings/CStatusWin", Func19E008__10CStatusWin);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", Func19E0B8__10CStatusWin);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", Func19E148__10CStatusWinf);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019E300);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", Func19E5C8__10CStatusWinfi);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", Func19E6A0__10CStatusWinf);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", Func19E780__10CStatusWinf);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019E8B0);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", Func19ECB0__10CStatusWinff);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019F200);

int CStatusWin::SetUnk50(u32 i) {
    if (i >= 6) {
        return Func235DE0(D_002DDF98, i);
    }
    if (*(u32 *)&pad50 != i) {
        *(u32 *)&pad50 = i;
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

INCLUDE_ASM("asm/nonmatchings/CStatusWin", Func19F4A8__10CStatusWin);

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

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A09D8);

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

INCLUDE_ASM("asm/nonmatchings/CStatusWin", Func1A0CF0__10CStatusWinPCc);

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

INCLUDE_ASM("asm/nonmatchings/CStatusWin", Func1A3378__11CStatusItem);

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

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A36B0);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", Func1A3740__14CMenuRecordWiniPCc);

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

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A38D0);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A3930);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", Func1A39A8__14CMenuRecordWinPfPii);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A3A18);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A3A78);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A3AF8);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", Func1A3B58__14CMenuRecordWinPfPii);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A3BC8);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A3C28);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A3C98);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A3CF8);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A3D68);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A3DC8);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A3E28);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A3EA8);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A3F20);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A3FA8);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A4008);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A4060);

void CStatusWinSub1A40B8::SetUnk80(f32 x, f32 y) {
    m_unk80 = x;
    m_unk84 = y;
}

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A40C8);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", Func1A4298__10CUnk1A4298);

CStatusWinSub1A4F20 *CreateStatusWinSub1A4F20(u32 kind) {
    if (kind >= 3) {
        Func235DE0(D_002DEAC0, kind);
        kind = 0;
    }
    return new CStatusWinSub1A4F20(kind);
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

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A4AE0);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A4BA8);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A4D28);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A4E88);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDEC0);
