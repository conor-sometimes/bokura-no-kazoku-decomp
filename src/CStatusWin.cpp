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
    void Func1A1B38();
    int Func1A1AA0();
    void Fade(s32 mode, s32 total);
    void Func1A3378();
    void SetText(s32 i, const char *s);
    int GetUnk10(f32 *x, f32 *y, s32 i);
    void Func1A40C8();
    int Func1A38D0(s32 i);
    void GetPos(f32 *x, f32 *y, s32 i);
    void Func1A3628();
    void SetUnk34(f32 v);
    void Start();
    void ResetColors();
    s32 GetUnkE4(s32 i);
    int Select(s32 n);
    void SetMappedColor(s32 n, const CVec4 *v);
    void GetMappedUnkC0(f32 *x, f32 *y, s32 n);
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

#include "CProcess.h"

// Not the CStatusWin of the vtable (that one has its vptr at 0x58, see 0x19CD98): the class of
// the methods from 0x19F200 on, with the same first fields, no virtuals and 0x58 a plain field.
class CStatusWin {
public:
    void Func19E8B0(const char *a, const char *b);
    void Draw19FC30();
    void Draw19FA50();
    CStatusWin(s32 kind, s32 a, s32 b);
    int SetUnk4C(u32 v);
    void StartItem1();
    void StartItem5();
    void SetUnk64(u32 i, s32 v);
    int SetUnk50(u32 i);
    void Func19F4A8();
    void Func19F668();
    void GetSlotPos(f32 *x, f32 *y, s32 k);
    void Update1A03E8();
    void Func19FE18();
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

    CStateMachine m_sm;       // 0x0
    CStatusItem* m_item;      // 0x48
    s32 m_state;              // 0x4C
    u32 m_unk50;              // 0x50
    s32 m_unk54;              // 0x54
    s32 m_unk58;              // 0x58
    s32 m_unk5C;              // 0x5C
    s32 m_unk60;              // 0x60
    s32 m_unk64;              // 0x64
    s32 m_unk68;              // 0x68
    s32 m_unk6C;              // 0x6C
    f32 m_unk70;              // 0x70
    s32 m_unk74;              // 0x74
    f32 m_unk78;              // 0x78
    f32 m_unk7C;              // 0x7C
    char m_name[0x100];       // 0x80
    s32 m_unk180;             // 0x180
};

class CStatusWinSub1A1BF0 {
public:
    CStatusWinSub1A1BF0();
    ~CStatusWinSub1A1BF0();
    int Load1A1CF0(const char *p, char *line);

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
    int LoadTable(const char *name);

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
    void Func1A4BA8();
    void Func1A4D28();

    u8 pad0[0x58];
    CStatusItem *m_item;      // 0x58
    u8 pad5C[0x10];
    s32 m_unk6C;              // 0x6C
    s32 m_unk70;              // 0x70
    s32 m_unk74;              // 0x74
    u8 pad78[0x4];
    void *m_unk7C;            // 0x7C
    char m_str[0x804];        // 0x80
    char m_unk884;            // 0x884
    char m_unk885;            // 0x885
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

extern const char D_002DDF10[], D_002DDF68[], D_002DDF70[], D_002DDF78[];

//@sym Func19FE18__10CStatusWin 0x19FE18
//@sym Func1A40C8__11CStatusItem 0x1A40C8
extern const char D_002DE018[];

class CMenuMgrSub1B6418 {
public:
    void Move1B6488(f32 x, f32 y);
};
extern const char D_002DEB60[], D_002DEBA0[];

extern "C" char *func_0024BA08(char *buf, s32 v);
class CGameDBRec24 {
public:
    s32 m_unk0;               // 0x0
    s32 m_unk4;               // 0x4
};

class CUnk237E90 {
public:
    int Func237E90(int v);
};
class CUnk1A4298 {
public:
    int Func1A4298();
};
class CMenuMgrSub1B4768 {
public:
    int GetEntry0(int k);
    void Reset1B4D28();
    void SetUnk20(f32 x, f32 y, f32 z);
    void SetUnk30(f32 x, f32 y, f32 z, f32 w);
    void SetUnk40(f32 x, f32 y, f32 z, f32 w);
    void SetUnk50(int v);
};
class CMenuMgr {
public:
    int Func1B4ED0(int v);
};
extern CMenuMgrSub1B4768 *D_002A5530;
extern "C" int func_001B50B0(CMenuMgrSub1B4768 *p, int k);
void *Func237570(int size);
void Func237A88(void *p, int n);
void *Func237C30(void *p);
void Func238158(void *p, int v);
void Func225088();
int Func2250C0();
void Func225240(int v);
// The status window base (CStatusBase.cpp): fields up to 0x58, then its vptr (7 pure slots).
class CStatusBase {
public:
    f32 GetItemUnk34();
    virtual void V0() = 0;
    virtual void V1() = 0;
    virtual void V2() = 0;
    virtual void V3() = 0;
    virtual void V4() = 0;
    virtual void V5() = 0;
    virtual void V6() = 0;

    CStateMachine m_sm;       // 0x0
    CStatusItem *m_item;      // 0x48
    s32 m_state;              // 0x4C
    u32 m_unk50;              // 0x50
    s32 m_unk54;              // 0x54
    // vptr 0x58
};
class CMenuLoadMemorialSub179568 {
public:
    void SetUnk64(u32 i, f32 v);
    void SetUnk60(f32 v);
};
class CMenuLoadMemorialSub178778 {
public:
    void SetUnk64(u32 i, f32 v);
    void SetUnk60(f32 v);
};
// The class of _vt$10CStatusWin (vptr 0x58, constructor 0x19CD98). Named CStatusWinV here because
// "CStatusWin" in this file is the vtable-less window class of the methods from 0x19F200 on.
// The destructor (slot 7, key method, not defined yet) is declared first so it stays the key
// method; the override order does not change the slots.
class CStatusWinV : public CStatusBase {
public:
    virtual ~CStatusWinV();
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();

    CMenuLoadMemorialSub179568 *m_unk5C; // 0x5C
    CMenuLoadMemorialSub178778 *m_unk60; // 0x60
    u8 pad64[0x200 - 0x64];
    f32 m_unk200;             // 0x200
    f32 m_unk204;             // 0x204
};
extern "C" void func_0019C428(void *p);
extern "C" void func_001795F8(void *p);
extern "C" void func_001789B8(void *p);
extern void *D_002A53D4;

//@sym Load1A1CF0__19CStatusWinSub1A1BF0PCcPc 0x1A1CF0
//@sym __19CStatusWinSub1A1BF0 0x1A1BE8
//@sym __builtin_vec_new 0x245678
const char *Func24ADE0(const char *p, char *buf, int n);
extern const char D_002DE040[], D_002DE070[], D_002DE088[];
extern void (*D_002B91B0)(void *p);

//@sym Func19FE18__10CStatusWin 0x19FE18

extern "C" int func_00179198(void *p);
extern "C" int func_0017A370(void *p);
extern "C" int func_0019C730(void *p, f32 x, f32 y, f32 a);

extern "C" int strcmp(const char *a, const char *b);
extern const char D_002DDF30[];

void Func1862F8(char *dst, s32 k);
void Func186358(char *dst, s32 a, s32 b);
extern const char D_002DDF58[];
struct CStatusWinNameRec {
    s32 m0;
    const char *m4;
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

void CStatusWinV::V0() {
    V1();
}

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019D5A0);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDE30);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDE48);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDE60);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDE80);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDEA0);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019DBA0);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019DD48);

void CStatusWinV::V5() {
    s32 i;
    func_0019C428(D_002A53D4);
    if (m_unk5C) func_001795F8(m_unk5C);
    if (m_unk60) func_001789B8(m_unk60);
    if (m_state != 3) {
        for (i = 0; i < 5; i++) m_unk60->SetUnk64(i, m_item->m_unk34);
        for (i = 0; i < 8; i++) m_unk5C->SetUnk64(i, m_item->m_unk34);
    }
}

void CStatusWinV::V6() {
    f32 x, y;
    u8 *p = (u8 *)Func237570(0x40);
    Func237A88(p, 4);
    Func238158(Func237C30(p + 0x30), 1);
    ((CUnk237E90 *)(p + 0x10))->Func237E90(((CUnk1A4298 *)m_item)->Func1A4298());
    D_002A5530->Reset1B4D28();
    D_002A5530->SetUnk30(1.0f, 1.0f, 0.0f, 0.0f);
    D_002A5530->SetUnk40(1.0f, 1.0f, 1.0f, m_item->m_unk34);
    m_unk60->SetUnk60(m_item->m_unk34);
    ((CUnk237E90 *)(p + 0x20))->Func237E90(func_00179198(m_unk60));
    m_unk5C->SetUnk60(m_item->m_unk34);
    ((CUnk237E90 *)(p + 0x20))->Func237E90(func_0017A370(m_unk5C));
    D_002A5530->Reset1B4D28();
    m_item->GetPos(&x, &y, 0xB);
    {
        f32 a = m_item->m_unk34;
        ((CUnk237E90 *)(p + 0x20))->Func237E90(func_0019C730(D_002A53D4, x + m_unk200, y + m_unk204, a));
    }
    Func225088();
    Func225240((int)p);
    Func2250C0();
}

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

void CStatusWin::Func19E148(f32 v) {
    char buf[0x100];
    char num[0x100];
    s32 c = (s32)(v * 128.0f);
    c = c < 0 ? 0 : (c < 0x100 ? c : 0xFF);
    switch (m_unk60) {
    case 0: {
        const char *fmt = (const char *)m_item->GetUnkE4(12);
        sprintf(buf, fmt, func_0024BA08(num, D_002A5358->Func1091B0(m_unk50 + 0x2E)));
        sprintf(num, D_002DDF00, c, buf);
        m_item->SetText(12, num);
        m_item->SetUnkF0(6, 1);
        sprintf(buf, D_002DDF00, c, (const char *)m_item->GetUnkE4(6));
        m_item->SetText(6, buf);
        m_item->SetUnkF0(12, 1);
        break;
    }
    case 1: {
        const char *fmt = (const char *)m_item->GetUnkE4(6);
        sprintf(buf, fmt, func_0024BA08(num, D_002A26E4->Func1091B0(m_unk50 + 0x34)));
        m_item->SetText(6, buf);
        m_item->SetUnkF0(6, 1);
        break;
    }
    }
}

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

void CStatusWin::Func19E780(f32 v) {
    char buf[0x100];
    char out[0x100];
    CGameDBRec24 *rec;
    s32 c = (s32)(v * 128.0f);
    c = c < 0 ? 0 : (c < 0x100 ? c : 0xFF);
    m_unk70 = v;
    rec = D_002A2988->Find234(D_002A26E4->Func1091B0(m_unk50 + 0x166));
    if (rec) {
        sprintf(buf, (const char *)m_item->GetUnkE4(9), rec->m_unk4);
        sprintf(out, D_002DDF00, c, buf);
        m_unk6C = 1;
    } else {
        sprintf(buf, D_002DDF10);
        m_unk6C = 0;
        m_unk70 = 1.0f;
    }
    m_item->SetText(9, out);
    m_item->SetUnkF0(9, m_unk6C);
}

void CStatusWin::Func19E8B0(const char *a, const char *b) {
    char buf[256];
    if (!a || !b) {
        Func235DE0(D_002DDF30);
        return;
    }
    if (m_unk60 == 0) {
        if (strcmp(a, D_002DDF10) && strcmp(b, D_002DDF10)) {
            sprintf(buf, (const char *)m_item->GetUnkE4(10), a, b);
            m_item->SetText(10, buf);
            m_item->SetUnkF0(10, 1);
            m_item->SetUnkF0(11, 0);
        } else if (!strcmp(a, D_002DDF10) && strcmp(b, D_002DDF10)) {
            sprintf(buf, (const char *)m_item->GetUnkE4(11), b);
            m_item->SetText(11, buf);
            m_item->SetUnkF0(10, 0);
            m_item->SetUnkF0(11, 1);
        } else if (strcmp(a, D_002DDF10) && !strcmp(b, D_002DDF10)) {
            sprintf(buf, (const char *)m_item->GetUnkE4(11), a);
            m_item->SetText(11, buf);
            m_item->SetUnkF0(10, 0);
            m_item->SetUnkF0(11, 1);
        } else {
            m_item->SetUnkF0(10, 0);
            m_item->SetUnkF0(11, 0);
        }
    } else if (m_unk60 == 1) {
        if (strcmp(a, D_002DDF10) && strcmp(b, D_002DDF10)) {
            sprintf(buf, (const char *)m_item->GetUnkE4(8), a);
            m_item->SetText(8, buf);
            m_item->SetUnkF0(8, 1);
            sprintf(buf, (const char *)m_item->GetUnkE4(9), b);
            m_item->SetText(9, buf);
            m_item->SetUnkF0(9, 1);
        } else if (!strcmp(a, D_002DDF10) && strcmp(b, D_002DDF10)) {
            sprintf(buf, (const char *)m_item->GetUnkE4(8), b);
            m_item->SetText(8, buf);
            m_item->SetUnkF0(8, 1);
            sprintf(buf, (const char *)m_item->GetUnkE4(9), D_002DDF10);
            m_item->SetText(9, buf);
            m_item->SetUnkF0(9, 0);
        } else if (strcmp(a, D_002DDF10) && !strcmp(b, D_002DDF10)) {
            sprintf(buf, (const char *)m_item->GetUnkE4(8), a);
            m_item->SetText(8, buf);
            m_item->SetUnkF0(8, 1);
            sprintf(buf, (const char *)m_item->GetUnkE4(9), D_002DDF10);
            m_item->SetText(9, buf);
            m_item->SetUnkF0(9, 0);
        } else {
            sprintf(buf, (const char *)m_item->GetUnkE4(8), D_002DDF10);
            m_item->SetText(8, buf);
            m_item->SetUnkF0(8, 0);
            sprintf(buf, (const char *)m_item->GetUnkE4(9), D_002DDF10);
            m_item->SetText(9, buf);
            m_item->SetUnkF0(9, 0);
        }
    }
}

void CStatusWin::Func19ECB0(f32 x, f32 y) {
    char tmp[0x200];
    char a[0x100];
    char b[0x100];
    s32 ix = (s32)(x * 128.0f);
    s32 iy = (s32)(y * 128.0f);
    s32 cx = ix < 0 ? 0 : (ix < 0x100 ? ix : 0xFF);
    s32 cy = iy < 0 ? 0 : (iy < 0x100 ? iy : 0xFF);
    s32 st = D_002A5358->Func1091B0(m_unk50 + 0x34);
    D_002A5358->Func1091B0(m_unk50 + 0x40);
    CStatusWinNameRec *r1 = (CStatusWinNameRec *)D_002A2988->Find20C(D_002A26E4->Func1091B0(m_unk50 + 0xE2));
    CStatusWinNameRec *r2 = (CStatusWinNameRec *)D_002A2988->Find220(D_002A26E4->Func1091B0(m_unk50 + 0xDC));
    a[0] = D_002DDF10[0];
    b[0] = D_002DDF10[0];
    if (m_unk60 == 0) {
        if (st == 1) {
            m_item->SetUnkF0(10, 0);
            m_item->SetUnkF0(11, 0);
        }
        if (r1) sprintf(a, D_002DDF58, cx, r1->m4);
        if (r2) sprintf(b, D_002DDF58, cy, r2->m4);
        if (D_002A5358->Func1091B0(m_unk50 + 0xA0)) {
            Func1862F8(tmp, m_unk50);
            sprintf(a, D_002DDF58, cx, tmp);
        }
        if (D_002A5358->Func1091B0(m_unk50 + 0xA6)) {
            s32 t = D_002A26E4->Func1091B0(m_unk50 + 0x28);
            u32 u = D_002A26E4->Vf2991B0();
            if (t != 0x16 && u == 0) {
                sprintf(b, D_002DDF10);
            } else if (t == 0x11 && u < 2) {
                sprintf(b, D_002DDF10);
            } else {
                Func186358(tmp, 1, D_002A26E4->Func1091B0(m_unk50 + 0x3A));
                sprintf(b, D_002DDF58, cy, tmp);
            }
        }
        if (D_002A5358->Func1091B0(m_unk50 + 0xAC)) {
            Func186358(tmp, 0, D_002A26E4->Func1091B0(m_unk50 + 0x3A));
            sprintf(b, D_002DDF58, cy, tmp);
        }
        Func19E8B0(a, b);
    } else if (m_unk60 == 1) {
        if (st == 1) {
            m_item->SetUnkF0(8, 0);
            m_item->SetUnkF0(9, 0);
        }
        if (r1) strcpy(a, r1->m4);
        if (r2) strcpy(b, r2->m4);
        if (D_002A5358->Func1091B0(m_unk50 + 0xA0)) {
            Func1862F8(tmp, m_unk50);
            sprintf(a, D_002DDF58, cx, tmp);
        }
        if (D_002A5358->Func1091B0(m_unk50 + 0xA6)) {
            s32 t = D_002A26E4->Func1091B0(m_unk50 + 0x28);
            u32 u = D_002A26E4->Vf2991B0();
            if (t != 0x16 && u == 0) {
                sprintf(b, D_002DDF10);
            } else if (t == 0x11 && u < 2) {
                sprintf(b, D_002DDF10);
            } else {
                Func186358(tmp, 1, D_002A26E4->Func1091B0(m_unk50 + 0x3A));
                sprintf(b, D_002DDF58, cy, tmp);
            }
        }
        if (D_002A5358->Func1091B0(m_unk50 + 0xAC)) {
            Func186358(tmp, 0, D_002A26E4->Func1091B0(m_unk50 + 0x3A));
            sprintf(b, D_002DDF58, cy, tmp);
        }
        Func19E8B0(a, b);
    }
}

CStatusWin::CStatusWin(s32 kind, s32 a, s32 b) {
    switch (kind) {
    case 0:
        m_item = (CStatusItem *)((CStatusWinSub1A0A10 *)D_002A5408)->Find(D_002DDF68);
        break;
    case 1:
        m_item = (CStatusItem *)((CStatusWinSub1A0A10 *)D_002A5408)->Find(D_002DDF70);
        break;
    default:
        Func235DE0(D_002DDF78, kind);
        kind = 0;
        m_item = (CStatusItem *)((CStatusWinSub1A0A10 *)D_002A5408)->Find(D_002DDF68);
        break;
    }
    if (m_item) m_item->Func1A3378();
    if (a) m_unk180 = a;
    m_unk60 = kind;
    m_unk74 = b;
    m_unk70 = 1.0f;
    m_unk78 = 1.0f;
    m_unk7C = 1.0f;
    m_name[0] = D_002DDF10[0];
    m_unk64 = 0;
    m_unk68 = 0;
    m_unk6C = 0;
    m_unk50 = 0;
    Func19F4A8();
    m_state = 0;
    m_unk54 = 0;
    m_unk58 = -1;
}

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
    m_unk58 = -1;
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

void CStatusWin::Draw19FA50() {
    u8 *p;
    if (!m_item) {
        Func225088();
        Func2250C0();
        return;
    }
    p = (u8 *)Func237570(0x60);
    Func237A88(p, 6);
    Func238158(Func237C30(p + 0x50), 1);
    ((CUnk237E90 *)(p + 0x10))->Func237E90(((CUnk1A4298 *)m_item)->Func1A4298());
    D_002A5530->Reset1B4D28();
    if (m_unk60 == 0 && m_unk6C == 1 && m_state != 0) {
        f32 x, y;
        D_002A5530->SetUnk50(1);
        ((CUnk237E90 *)(p + 0x20))->Func237E90(((CMenuMgr *)D_002A5530)->Func1B4ED0(D_002A5530->GetEntry0(0x16)));
        m_item->GetPos(&x, &y, 0xD);
        D_002A5530->SetUnk20(x, y, 0.0f);
        D_002A5530->SetUnk30(1.0f, 1.0f, 0.0f, 0.0f);
        if (m_state == 3) D_002A5530->SetUnk40(1.0f, 1.0f, 1.0f, m_unk70);
        else D_002A5530->SetUnk40(1.0f, 1.0f, 1.0f, m_item->m_unk34);
        ((CUnk237E90 *)(p + 0x20))->Func237E90(func_001B50B0(D_002A5530, 0x16));
    }
    Func225088();
    Func225240((int)p);
    Func2250C0();
}

void CStatusWin::Draw19FC30() {
    u8 *p;
    if (!m_item) {
        Func225088();
        Func2250C0();
        return;
    }
    p = (u8 *)Func237570(0x60);
    Func237A88(p, 6);
    Func238158(Func237C30(p + 0x50), 1);
    D_002A5530->Reset1B4D28();
    if (m_unk50 == D_002A26E4->Func1091B0(0x1046) && m_unk74 == 1) {
        f32 x, y;
        ((CUnk237E90 *)(p + 0x20))->Func237E90(((CMenuMgr *)D_002A5530)->Func1B4ED0(D_002A5530->GetEntry0(0x17)));
        D_002A5530->SetUnk30(1.0f, 1.0f, 0.0f, 0.0f);
        if (m_unk60 == 0) m_item->GetPos(&x, &y, 0xE);
        else m_item->GetPos(&x, &y, 0xA);
        D_002A5530->SetUnk20(x, y, 0.0f);
        if (m_state == 3) D_002A5530->SetUnk40(m_unk78, m_unk78, m_unk78, 1.0f);
        else D_002A5530->SetUnk40(1.0f, 1.0f, 1.0f, ((CStatusBase *)m_unk180)->GetItemUnk34());
        ((CUnk237E90 *)(p + 0x20))->Func237E90(func_001B50B0(D_002A5530, 0x17));
    }
    Func225088();
    Func225240((int)p);
    Func2250C0();
}

INCLUDE_ASM("asm/nonmatchings/CStatusWin", Func19FE18__10CStatusWin);

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

void CStatusWin::GetSlotPos(f32 *x, f32 *y, s32 k) {
    s32 n = D_002A26E4->Func1091B0(0x27);
    s32 m = D_002A26E4->Func1091B0(9);
    if (k >= n + m_state * 2 + m) return (void)Func235DE0(D_002DE018, k);
    if (m_item) {
        if (D_002A26E4->Func1091B0(9) && k == n + 2) {
            m_item->GetPos(x, y, n * 2 + 0x2F);
        } else {
            m_item->GetPos(x, y, m_state * 14 + k + 0x1E);
        }
    }
}

void CStatusWin::SetUnk5C(s32 v) {
    m_unk5C = v;
}

s32 CStatusWin::GetItemState2() {
    return m_item ? m_item->m_state : -1;
}

f32 CStatusWin::GetItemUnk34_2() {
    return m_item ? m_item->m_unk34 : 0.0f;
}

void CStatusWin::Update1A03E8() {
    s32 n = D_002A26E4->Func1091B0(0x27);
    s32 done = 0;
loop:
    if (!(!done && !((m_sm.m_flags >> 7) & 1))) goto out;
    switch (m_sm.m_state) {
    case -1: {
        s32 i;
        for (i = 0; i < 0x18; i++) m_item->SetUnkF0(i, 0);
        m_item->SetUnkF0((m_state * 6 + n) * 2 - 2, 1);
        m_item->SetUnkF0((m_state * 6 + n) * 2 - 1, 1);
    }
    case -0x14F:
        Func19FE18();
        m_sm.m_state = -0x14F;
        done = 1;
        goto loop;
    case -0x153:
        done = 1;
        goto loop;
    }
out:
    m_item->Func1A40C8();
}

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

int CStatusWinSub1A0A10::LoadTable(const char *name) {
    char line[0x100];
    int ok = 1;
    const char *p;
    s32 i;
    void *data = Func24A4C0(name);
    if (!data) {
        Func235DE0(D_002DE070, D_002DE040, name);
        ok = 0;
        goto end;
    fail:
        ok = 0;
        goto end;
    }
    m_unk10 = 0;
    p = Func24ADE0((const char *)data, line, 0x100);
    while (strcmp(line, D_002DE088)) {
        m_unk10++;
        p = Func24ADE0(p, line, 0x100);
    }
    m_unk14 = new CStatusWinSub1A1BF0[m_unk10];
    p = Func24ADE0((const char *)data, line, 0x100);
    for (i = 0; i < m_unk10; i++) {
        CStatusWinSub1A1BF0 *e = &m_unk14[i];
        if (!e || !e->Load1A1CF0(p, line)) goto fail;
        p = Func24ADE0(p, line, 0x100);
    }
end:
    if (data) D_002B91B0(data);
    return ok;
}

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

void CStatusItem::Fade(s32 mode, s32 total) {
    CStatusEntry *e;
    if (m_unk30 >= 0 && m_unk30 <= total) {
        f32 f;
        if (mode == 0) f = (f32)m_unk30 / (f32)total;
        else f = 1.0f - (f32)m_unk30 / (f32)total;
        if (mode != 1 || !(m_unk34 < f)) m_unk34 = f;
        for (s32 i = 0; i < m_count; i++) {
            e = &m_entries[i];
            e->m_unkD8 = 1;
            e->m_cur[0].w = f * e->m_col[0].w;
            e->m_cur[1].w = f * e->m_col[1].w;
            e->m_cur[2].w = f * e->m_col[2].w;
            e->m_cur[3].w = f * e->m_col[3].w;
        }
    } else if (m_unk30 > total) {
        if (mode == 0) {
            m_state = 2;
            for (s32 i = 0; i < m_count; i++) {
                e = &m_entries[i];
                e->m_unkD8 = 1;
            }
        } else {
            m_state = 0;
            for (s32 i = 0; i < m_count; i++) {
                e = &m_entries[i];
                Func270C50(&e->m_cur[0], &e->m_col[0]);
                Func270C50(&e->m_cur[1], &e->m_col[1]);
                Func270C50(&e->m_cur[2], &e->m_col[2]);
                Func270C50(&e->m_cur[3], &e->m_col[3]);
                e->m_unkD8 = 0;
            }
        }
    }
    m_unk30++;
}

INCLUDE_ASM("asm/nonmatchings/CStatusWin", Func1A1AA0__11CStatusItem);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", Func1A1B38__11CStatusItem);

// The (empty) constructor: new[] in CStatusWinSub1A0A10::LoadTable calls it.
CStatusWinSub1A1BF0::CStatusWinSub1A1BF0() {
}

INCLUDE_ASM("asm/nonmatchings/CStatusWin", _$_19CStatusWinSub1A1BF0);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", Load1A1CF0__19CStatusWinSub1A1BF0PCcPc);

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

void CStatusItem::GetMappedUnkC0(f32 *x, f32 *y, s32 n) {
    if (n < 0 || m_mapCount - 1 < n) return (void)Func235DE0(D_002DE758, this, n);
    CStatusEntry *e = &m_entries[m_map[n]];
    *x = e->m_unkC0[0];
    *y = e->m_unkC0[1];
}

void CStatusItem::GetPos(f32 *x, f32 *y, s32 i) {
    if (i < 0 || m_count - 1 < i) return (void)Func235DE0(D_002DE788, this, i);
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

INCLUDE_ASM("asm/nonmatchings/CStatusWin", Func1A40C8__11CStatusItem);

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

void CStatusWinSub1A4A40::Func1A4BA8() {
    f32 x, y;
    if (m_unk6C >= 0x2E) {
        s32 sel, idx;
        switch (m_unk6C) {
        case 0x2E:
            idx = 0;
            sel = -1;
            break;
        case 0x2F:
            sel = -1;
            idx = 1;
            break;
        case 0x30:
            sel = 2;
            idx = 2;
            break;
        case 0x31:
            sel = 5;
            idx = 5;
            break;
        default:
            idx = 0;
            Func235DE0(D_002DEB60, m_unk6C);
            sel = -1;
            break;
        }
        m_item->Select(sel);
        m_item->GetMappedUnkC0(&x, &y, idx);
        ((CMenuMgrSub1B6418 *)D_002A5538)->Move1B6488(x, y);
    } else {
        s32 col = m_unk6C % 5;
        s32 row = m_unk6C / 5;
        ((CMenuMgrSub1B6418 *)D_002A5538)->Move1B6488((f32)col * 37.0f + 96.0f, (f32)row * 26.0f + 142.0f);
        m_item->Select(-1);
    }
    Func1A4AE0(m_unk6C);
    if (m_str[0]) {
        m_unk884 = m_str[0];
        m_unk885 = m_str[1];
    } else {
        m_unk884 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/CStatusWin", Func1A4D28__19CStatusWinSub1A4A40);

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_001A4E88);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDEC0);
