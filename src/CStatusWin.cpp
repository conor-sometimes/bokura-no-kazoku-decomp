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
    void Func1A1B38() throw();  // throw(): retail compiled both before their callers (nothrow calls)
    int Func1A1AA0() throw();
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
    void SetPos(s32 i, f32 x, f32 y);
    int GetUnk60Ofs(f32 *x, f32 *y, s32 i);
    void SetUnk60(s32 i, f32 x, f32 y);
    void SetUnk10(s32 i, f32 x, f32 y);
    int GetUnk70(f32 *x, f32 *y, s32 i);
    void SetUnk70(s32 i, f32 x, f32 y);
    int GetUnkC0(f32 *x, f32 *y, s32 i);
    void SetUnkC0(s32 i, f32 x, f32 y);
    void SetUnkF0(s32 i, s32 v);
    void SetColor(s32 i, const CVec4 *v);
    int GetColor(CVec4 *out, s32 i);
    void ScaleAlpha(s32 i, f32 s);
    void SetUnkD0(s32 i, s32 v);
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
int Func235DE0(const char *fmt, ...) throw();
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
    CStatusWin();
    void Select1A01C8(s32 k);
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

struct CStatusWinEnt { u8 pad0[0xE4]; void *m_unkE4; void *m_unkE8; u8 padEC[0x14]; };
class CStatusWinSub1A1BF0 {
public:
    CStatusWinSub1A1BF0();
    ~CStatusWinSub1A1BF0();
    int Load1A1CF0(const char *p, char *line);

    u8 pad0[0x24] __attribute__((aligned(16)));
    s32 m_num;                // 0x24
    CStatusWinEnt *m_ents;    // 0x28
    u8 pad2C[0x14];
    void *m_unk40;            // 0x40
    u8 pad44[0x4C];
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

#include "CMenuMgrSub1B6418.h"
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
#include "CMenuMgrSub1B4768.h"
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
    CStatusBase();
    f32 GetItemUnk34();
    virtual void V0() = 0;
    virtual void V1() = 0;
    virtual void V2(f32 t) = 0;
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
    int SetUnk4(u32 i, s32 v);
    int SetUnk34(u32 i, s32 v);
    void SetUnk64(u32 i, f32 v);
    void SetUnk60(f32 v);
    int Create();
    int Reset();
    void SetUnk44(u32 v);
    void SetUnk50(f32 x, f32 y);
    u8 pad0[0xC0];
};
class CMenuLoadMemorialSub178778 {
public:
    void SetUnk4(s32 v);
    void SetUnk8(u32 i, u32 v);
    void SetUnk64(u32 i, f32 v);
    void SetUnk60(f32 v);
    int Create();
    int Reset();
    void SetUnk44(u32 v);
    void SetUnk50(f32 x, f32 y);
    void SetUnkAC(s32 v);
    u8 pad0[0xB0];
};
struct CStatusWinSlot {
    s32 m0, m4, m8, mC, m10, m14, m18;
};
// The class of _vt$10CStatusWin (vptr 0x58, constructor 0x19CD98). Named CStatusWinV here because
// "CStatusWin" in this file is the vtable-less window class of the methods from 0x19F200 on.
// The destructor (slot 7, key method, not defined yet) is declared first so it stays the key
// method; the override order does not change the slots.
class CStatusWinV : public CStatusBase {
public:
    virtual ~CStatusWinV();
    CStatusWinV(s32 kind);
    virtual void V0();
    virtual void V1();
    virtual void V2(f32 t);
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();

    CMenuLoadMemorialSub179568 *m_unk5C; // 0x5C
    CMenuLoadMemorialSub178778 *m_unk60; // 0x60
    CStatusWinSlot m_slots64[5]; // 0x64
    CStatusWinSlot m_slotsF0[8]; // 0xF0
    s32 m_unk1D0;             // 0x1D0
    s32 m_unk1D4;             // 0x1D4
    s32 m_unk1D8;             // 0x1D8
    s32 m_unk1DC;             // 0x1DC
    s32 m_unk1E0;             // 0x1E0
    s32 m_unk1E4;             // 0x1E4
    s32 m_unk1E8;             // 0x1E8
    s32 m_unk1EC[4];          // 0x1EC
    u8 pad1FC[0x4];
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

class CStatusBaseSub19B8C8 {
public:
    void SetUnk18(u32 v);
    void SetUnk14(s32 v);
    void SetUnk8(u32 v);
};

int LerpInt(int a, int b, f32 t);
extern "C" int func_0019CCF8(s32 *cur, s32 *p, s32 a, s32 b, f32 t);
extern "C" void func_001787E8(void *p, s32 i, s32 a, s32 b);
extern "C" void func_00179438(void *p, s32 i, s32 a);
extern "C" void func_0019C278(void *p, s32 v);
extern "C" s32 func_00251BA8();
class CStatusBaseSub19C400 {
public:
    void Init(s32 v);
};
class CSePlayer {
public:
    virtual ~CSePlayer();
    virtual void F1();
    virtual void F2();
    virtual void F3();
    virtual void F4();
    virtual void F5();
    virtual void F6();
    virtual void F7();
    virtual void F8();
    virtual void F9();
    virtual void F10();
    virtual void F11();
    virtual void F12();
    virtual void F13();
    virtual void Play(s32 id);
};
extern CSePlayer *D_002A5468;

extern char D_002DDFE0[];

// May-throw aliases of two methods defined above: retail compiled Func1A4D28 without seeing their
// definitions (bnel there, docs/lessons.md nm), so CStatusWinSub1A4A40 was probably its own .cpp.
extern "C" int SelMT(CStatusItem *, s32) asm("Select__11CStatusItemi");
extern "C" void GetMT(CStatusItem *, f32 *, f32 *, s32) asm("GetMappedUnkC0__11CStatusItemPfT1i");
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
CStatusWinV::CStatusWinV(s32 kind) {
    s32 i;
    f32 x, y;
    m_item = (CStatusItem *)((CStatusWinSub1A0A10 *)D_002A5408)->Find("status");
    m_item->Func1A3378();
    CMenuLoadMemorialSub179568 *p5C = new CMenuLoadMemorialSub179568;
    p5C->Create();
    m_unk5C = p5C;
    p5C->Reset();
    m_unk5C->SetUnk44(2);
    CMenuLoadMemorialSub178778 *p60 = new CMenuLoadMemorialSub178778;
    p60->Create();
    m_unk60 = p60;
    p60->Reset();
    m_unk60->SetUnk44(2);
    switch (kind) {
    case 0:
        m_unk200 = 0.0f;
        m_unk204 = 0.0f;
        ((CStatusBaseSub19B8C8 *)D_002A53D4)->SetUnk8(0);
        m_item->GetPos(&x, &y, 9);
        m_unk60->SetUnk50(x, y);
        m_item->GetPos(&x, &y, 10);
        m_unk5C->SetUnk50(x, y);
        break;
    case 1:
        ((CStatusItem *)((CStatusWinSub1A0A10 *)D_002A5408)->Find("status2"))->GetPos(&m_unk200, &m_unk204, 0);
        ((CStatusWinSub1A40B8 *)m_item)->SetUnk80(m_unk200, m_unk204);
        ((CStatusBaseSub19B8C8 *)D_002A53D4)->SetUnk8(1);
        m_item->GetPos(&x, &y, 9);
        m_unk60->SetUnk50(x + m_unk200, y + m_unk204);
        m_item->GetPos(&x, &y, 10);
        m_unk5C->SetUnk50(x + m_unk200, y + m_unk204);
        ((CMenuLoadMemorialSub178778 *)m_unk5C)->SetUnkAC(1);
        break;
    default:
        Func235DE0("*** mode is out of range.(%d)\n", kind);
        break;
    }
    for (s32 j = 0; j < 5; j++) {
        m_slots64[j].m0 = 0;
        m_slots64[j].m4 = 0;
        m_slots64[j].m8 = 0;
        m_slots64[j].mC = 0;
        m_slots64[j].m14 = 0;
        m_slots64[j].m10 = 0;
        m_slots64[j].m18 = 0;
    }
    for (s32 k = 0; k < 8; k++) {
        m_slotsF0[k].m0 = 0;
        m_slotsF0[k].m4 = 0;
        m_slotsF0[k].m8 = 0;
        m_slotsF0[k].mC = 0;
        m_slotsF0[k].m14 = 0;
        m_slotsF0[k].m10 = 0;
        m_slotsF0[k].m18 = 0;
    }
    m_unk1D0 = 0;
    m_unk1D4 = 0;
    m_unk1D8 = 0;
    m_unk1DC = 0;
    m_unk1E4 = 0;
    m_unk1E0 = 0;
    m_unk1E8 = 0;
    s32 m1 = -1;
    for (s32 n = 3; n >= 0; n--) m_unk1EC[n] = m1;
}

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019D0A8);

void CStatusWinV::V2(f32 t) {
    for (s32 i = 0; i < 5; i++) {
        m_slots64[i].m4 = m_slots64[i].m0;
        int r = func_0019CCF8(&m_slots64[i].m0, &m_slots64[i].m10, m_slots64[i].m8, m_slots64[i].m14, t);
        if (m_slots64[i].m14) {
            m_unk60->SetUnk64(i, (func_00251BA8() & 1) ? 1.0f : 2.0f - t);
        } else {
            m_unk60->SetUnk64(i, 1.0f);
        }
        m_unk60->SetUnk8(i, m_slots64[i].m0);
        if (m_slots64[i].m14 < 0) func_001787E8(m_unk60, i, 2, 0);
        else if (m_slots64[i].m14 > 0) func_001787E8(m_unk60, i, 1, 0);
        else func_001787E8(m_unk60, i, 0, 0);
        if (r) D_002A5468->Play(m_slots64[i].m0 + 0x4E);
    }
    for (s32 i = 0; i < 8; i++) {
        m_slotsF0[i].m4 = m_slotsF0[i].m0;
        m_slotsF0[i].m0 = LerpInt(m_slotsF0[i].m8, m_slotsF0[i].mC, t);
        m_unk5C->SetUnk4(i, m_slotsF0[i].m0);
        if (m_slotsF0[i].mC != m_slotsF0[i].m8 || m_slotsF0[i].m14) {
            m_unk5C->SetUnk64(i, (func_00251BA8() & 1) ? 1.0f : 2.0f - t);
        } else {
            m_unk5C->SetUnk64(i, 1.0f);
        }
    }
    for (s32 i = 0; i < 8; i += 2) {
        s32 da = m_slotsF0[i].mC - m_slotsF0[i].m8;
        s32 db = m_slotsF0[i + 1].mC - m_slotsF0[i + 1].m8;
        if (da < 0 || db < 0 || m_slotsF0[i].m14 < 0 || m_slotsF0[i + 1].m14 < 0) func_00179438(m_unk5C, i / 2, 2);
        else if (da > 0 || db > 0 || m_slotsF0[i].m14 > 0 || m_slotsF0[i + 1].m14 > 0) func_00179438(m_unk5C, i / 2, 1);
        else func_00179438(m_unk5C, i / 2, 0);
    }
    s32 from = m_unk1D8;
    s32 to = m_unk1DC;
    m_unk1D4 = m_unk1D0;
    m_unk1D0 = LerpInt(from, to, t);
    if (to != from && t == 0.0f) {
        func_0019C278(D_002A53D4, to);
        D_002A5468->Play(0x59);
    } else if (m_unk1E4 && t == 0.0f) {
        ((CStatusBaseSub19C400 *)D_002A53D4)->Init(to);
        D_002A5468->Play(0x59);
    }
}

void CStatusWinV::V0() {
    V1();
}

INCLUDE_ASM("asm/nonmatchings/CStatusWin", func_0019D5A0);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDE30);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDE48);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDE60);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDE80);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDEA0);

void CStatusWinV::V3() {
    for (s32 i = 0; i < 5; i++) {
        if (m_slots64[i].mC != m_slots64[i].m8) D_002A5468->Play(m_slots64[i].m8 + 0x4E);
        else if (m_slots64[i].m14) D_002A5468->Play(m_slots64[i].mC + 0x4E);
    }
    s32 sum = 0;
    for (s32 j = 0; j < 8; j += 2) {
        sum += (m_slotsF0[j].mC - m_slotsF0[j].m8) + (m_slotsF0[j + 1].mC - m_slotsF0[j + 1].m8) + m_slotsF0[j].m14 + m_slotsF0[j + 1].m14;
    }
    if (sum < 0) D_002A5468->Play(0x5A);
    else if (sum > 0) D_002A5468->Play(0x59);
}

void CStatusWinV::V4() {
    for (s32 i = 0; i < 5; i++) func_001787E8(m_unk60, i, 0, 0);
    for (s32 j = 0; j < 4; j++) func_00179438(m_unk5C, j, 0);
}

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
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDEC0);
INCLUDE_RODATA("asm/nonmatchings/CStatusWin", D_002DDED0);
