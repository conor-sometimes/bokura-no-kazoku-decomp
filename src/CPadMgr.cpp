#pragma interface
#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CTask.h"
// Pad manager interface (vtable _vt$7IPadMgr, slots 7-12 pure).
class IPadMgr : public CTask {
public:
    virtual ~IPadMgr() {}
    virtual s32 Vf293408() = 0;
    virtual s32 Vf293410() = 0;
    virtual s32 Vf293420() = 0;
    virtual s32 Vf293418() = 0;
    virtual void SetUnk18(s32 v) = 0;
    virtual s32 Vf293428() = 0;
};
class CPadMgr : public IPadMgr {
public:
    CPadMgr();
    virtual ~CPadMgr();
    virtual s32 Vf293408();
    virtual s32 Vf293410();
    virtual s32 Vf293420();
    virtual s32 Vf293418();
    virtual void SetUnk18(s32 v);
    virtual s32 Vf293428();
    void Update();

    s32 m_unk8;               // 0x8
    s32 m_unkC;               // 0xC
    s32 m_unk10;              // 0x10
    s32 m_unk14;              // 0x14
    s32 m_unk18;              // 0x18
};
extern CPadMgr *D_0029F390;

// From CFlagWork.cpp (lane cv moved its functions 0x109508.. here: their literals are this unit's)
extern "C" void *memcpy(void *dst, const void *src, unsigned int n);

// Byte stream over a buffer (save data).
class CFlagStream {
public:
    s32 Write(const void *src, s32 n);
    s32 Write32(s32 v);
    void Read(void *dst, s32 n);
    void Read32(s32 *dst);

    u8 *m_cur;                // 0x0
};

// Flag id range (16 bytes).
class CFlagRange {
public:
    s16 m_lo;                 // 0x0
    s16 m_hi;                 // 0x2
    const char *m_unk4;       // 0x4
    u8 m_type;                // 0x8
    u8 pad9;
    s16 m_unkA;               // 0xA
    s32 m_unkC;               // 0xC
    int Has(s32 i) { return i >= m_lo && i <= m_hi; }
};

// Flag definition (4 bytes): offset into the data, type in the low nibble, size.
class CFlagDef {
public:
    u16 m_off;                // 0x0
    u8 m_type;                // 0x2
    u8 m_size;                // 0x3
};

class CTaskList24F5C0 {
public:
    s32 Func24F5C0(void *task, s32 pri);
};

void *Func245D00(s32 n);
void *Func24A4C0(const char *name);
void Func235DE0(const char *fmt, ...) throw();
extern void (*D_002B91B0)(void *p);


// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CFlagWork. Slots 1
// and 2 are empty inline notifications (0x2932F0, 0x2932F8; names in aliases.ld).
class CFlagWork {
public:
    CFlagWork(s32 a, s32 b);
    virtual ~CFlagWork();
    virtual void Notify1(s32 id);
    virtual void Notify2(s32 id);
    int Func108448(s32 a, s32 b);
    s32 Load(u8 *buf);
    void SetStr(s32 id, const char *s);
    void Func108FF0(s32 id, s32 v);
    void Func109738();
    void CallFunc109738();
    void Func10ACF0();
    void CallFunc10ACF0();
    void Reset();
    void Func108700();
    int Func108AA8(char *buf);
    int Func108C30(char *text);
    int Func108E10(const char *name);
    int Func108E38(const char *name);
    int Func1092B0(int (CFlagWork::*fn)(char *), const char *name);
    int Func109410(int (CFlagWork::*fn)(char *), const char *name);
    void Func109108(s32 id, s32 delta);
    void Func109248(s32 id, s32 lo, s32 hi);
    s32 CopyData(CFlagWork *o);
    s32 CopyFrom(CFlagWork *o);
    s32 Save(u8 *buf);
    s32 GetType(s32 id);
    s32 Func1091B0(s32 id);
    const char *GetStr(s32 id);

    s32 m_unk0;               // 0x0
    CFlagRange *m_ranges;     // 0x4
    s32 m_numRanges;          // 0x8
    CFlagDef *m_defs;         // 0xC
    s32 m_numDefs;            // 0x10
    u8 *m_data;               // 0x14
    s32 m_dataSize;           // 0x18
    // vptr 0x1C
};

s32 MaxRangeHi(CFlagRange *r, s32 n);
CFlagRange *FindRange(CFlagRange *r, s32 n, s32 id);
s32 Func109508(void *buf, const char *name);
s32 Func10A878(void *buf, const char *name);
extern s32 D_0029F330;
extern s32 D_0029F340;
extern s32 D_0029F348[2];
extern s32 D_0029F350[2];
extern s32 D_0029F380[4];
extern const char D_002D1C98[];
extern const char D_002D1D40[];
extern const char D_002D1E88[];
extern s32 D_002D1EB0[2];
extern s32 D_002D1EB8[2];
extern s32 D_002D1EC0[2];
extern s32 D_002D1EC8[2];
extern s32 D_002D1ED0[2];
extern s32 D_002D1ED8[2];
extern s32 D_002D1EE0[2];
void Func23B1D0(s32 h);
void Func220890(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
s32 Func2022A0();
void Func220680(s32 v);
s32 Func202308();
void Func2206C8(s32 v);
s32 Func202338();
void Func2206E8(s32 v);
void Func220A18(s32 a, s32 b, s32 c, s32 d);
void Func220A58(f32 a, f32 b, f32 c);
void Func1EB828(s32 v);
void Func1EB838(void *p);

//@sym memcpy 0x289DFC
//@sym __nw__5CTaskUi 0x24F2E8
//@sym __7CPadMgr 0x10AEB0

extern "C" unsigned int strlen(const char *s);
extern "C" char *strcpy(char *dst, const char *src);
struct CFlagLimit {
    s32 m_min;
    s32 m_max;
};
extern CFlagLimit D_0029F2F0[];
inline int FlagInRange(CFlagRange *r, s32 i) { return i >= r->m_lo && i <= r->m_hi; }
extern "C" void *func_0024A3D8(s32 n);
extern "C" s32 func_002301B0(const char *name, char *buf, s32 n);
extern "C" s32 func_0024B818(char **buf, const char *fmt, ...);
extern char D_002D1C68[], D_002D1C70[], D_002D1C80[];
class CHeapObj {
public:
    static void *operator new(unsigned int n);
};
const char *Func24A570(const char *s, char *out, const char *sep, const char *ws);
extern "C" const char *func_0024AD10(const char *p, char *buf, s32 k, s32 n);
extern "C" int func_00289118(const char *s);
#include "libc.h"
s32 MaxRangeHi(CFlagRange *r, s32 n);
extern s32 D_0029F2E8[];
inline void FlagDefSize(CFlagDef *dd, CFlagRange *r) { dd->m_size = r->m_unkA > 0 ? (u8)r->m_unkA : *(u8 *)&D_0029F2E8[r->m_type & 0xF]; }

// From IPadMgr.cpp (lane cv merged the IPadMgr text unit: one object with CPadMgr, docs/units.md)
//@sym __8CFadeMgrPvi 0x10B068
class CFadeMgr : public CTask {
public:
    CFadeMgr(void *p, s32 n) throw();

    u8 pad8[0x58];
};
extern u8 D_0029F394[];
s32 Func22D0A0(s32 port);
s32 Func22D008(s32 port);
s32 Func22D1D0(s32 port);
s32 Func22D138(s32 port);
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CPadMgr", Func109508__FPvPCc);
INCLUDE_RODATA("asm/nonmatchings/CPadMgr", D_002D1CC0);
INCLUDE_RODATA("asm/nonmatchings/CPadMgr", D_002D1CC8);
INCLUDE_RODATA("asm/nonmatchings/CPadMgr", D_002D1CE8);
INCLUDE_RODATA("asm/nonmatchings/CPadMgr", D_002D1CF0);
INCLUDE_RODATA("asm/nonmatchings/CPadMgr", D_002D1CF8);
INCLUDE_RODATA("asm/nonmatchings/CPadMgr", D_002D1D00);
INCLUDE_RODATA("asm/nonmatchings/CPadMgr", D_002D1D40);

s32 Load109508(const char *name) {
    void *buf = Func24A4C0(name);
    if (!buf) {
        Func235DE0(D_002D1D40, name);
        return 0;
    }
    s32 r = Func109508(buf, name);
    D_002B91B0(buf);
    return r;
}

void CFlagWork::Func109738() {
    if (D_0029F330 >= 0) {
        Func23B1D0(D_0029F330);
        D_0029F330 = -1;
    }
}

INCLUDE_RODATA("asm/nonmatchings/CPadMgr", D_002D1D70);
INCLUDE_ASM("asm/nonmatchings/CPadMgr", func_00109778);

INCLUDE_ASM("asm/nonmatchings/CPadMgr", func_001098A8);

INCLUDE_ASM("asm/nonmatchings/CPadMgr", func_00109C30);

INCLUDE_ASM("asm/nonmatchings/CPadMgr", func_0010A000);

INCLUDE_ASM("asm/nonmatchings/CPadMgr", func_0010A3E8);

void CallFunc220A58() {
    Func220A58(1.0f, 0.0f, 0.0f);
}

void CFlagWork::CallFunc10ACF0() {
    Func10ACF0();
}

INCLUDE_ASM("asm/nonmatchings/CPadMgr", Func10A878__FPvPCc);
INCLUDE_RODATA("asm/nonmatchings/CPadMgr", D_002D1D90);
INCLUDE_RODATA("asm/nonmatchings/CPadMgr", D_002D1D98);
INCLUDE_RODATA("asm/nonmatchings/CPadMgr", D_002D1DB8);
INCLUDE_RODATA("asm/nonmatchings/CPadMgr", D_002D1DC0);
INCLUDE_RODATA("asm/nonmatchings/CPadMgr", D_002D1DC8);
INCLUDE_RODATA("asm/nonmatchings/CPadMgr", D_002D1DD0);
INCLUDE_RODATA("asm/nonmatchings/CPadMgr", D_002D1DD8);
INCLUDE_RODATA("asm/nonmatchings/CPadMgr", D_002D1DE0);
INCLUDE_RODATA("asm/nonmatchings/CPadMgr", D_002D1DE8);
INCLUDE_RODATA("asm/nonmatchings/CPadMgr", D_002D1DF0);
INCLUDE_RODATA("asm/nonmatchings/CPadMgr", D_002D1E88);
INCLUDE_RODATA("asm/nonmatchings/CPadMgr", D_002D1EB0);
INCLUDE_RODATA("asm/nonmatchings/CPadMgr", D_002D1EB8);
INCLUDE_RODATA("asm/nonmatchings/CPadMgr", D_002D1EC0);
INCLUDE_RODATA("asm/nonmatchings/CPadMgr", D_002D1EC8);
INCLUDE_RODATA("asm/nonmatchings/CPadMgr", D_002D1ED0);
INCLUDE_RODATA("asm/nonmatchings/CPadMgr", D_002D1ED8);
INCLUDE_RODATA("asm/nonmatchings/CPadMgr", D_002D1EE0);

s32 Load10A878(const char *name) {
    void *buf = Func24A4C0(name);
    if (!buf) {
        Func235DE0(D_002D1E88, name);
        return 0;
    }
    s32 r = Func10A878(buf, name);
    D_002B91B0(buf);
    return r;
}

void CFlagWork::Func10ACF0() {
    if (D_0029F340 >= 0) {
        Func23B1D0(D_0029F340);
        D_0029F340 = -1;
    }
}

void Func10AD30() {
    Func220890(D_0029F340, 0, D_0029F348[0], D_0029F348[1], D_0029F350[0], D_0029F350[1]);
    Func220680(Func2022A0());
    Func2206C8(Func202308());
    Func2206E8(Func202338());
    Func220A18(D_0029F380[0], D_0029F380[1], D_0029F380[2], D_0029F380[3]);
}

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_0010ADC0() {
}

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_0010ADC8() {
}

void Func10ADD0() {
    Func1EB828(1);
    Func1EB838(D_002D1EB0);
    Func1EB838(D_002D1EB8);
    Func1EB838(D_002D1EC0);
    Func1EB838(D_002D1EC8);
    Func1EB838(D_002D1ED0);
    Func1EB838(D_002D1ED8);
    Func1EB838(D_002D1EE0);
}

void ClearFunc1EB828And1EB838() {
    Func1EB828(0);
    Func1EB838(0);
}

s32 AddPadMgr(CTaskList24F5C0 *list) {
    CPadMgr *t = new CPadMgr;
    return list->Func24F5C0(t, 0);
}

CPadMgr::CPadMgr() {
    D_0029F390 = this;
    m_unk18 = 1;
    m_unkC = 0;
    m_unk10 = 0;
    m_unk14 = 0;
    m_unk8 = 0;
}

// #pragma interface (top) keeps this unit from emitting the vtables (asm data) for the key method.
CPadMgr::~CPadMgr() {
    D_0029F390 = 0;
}

void CPadMgr::SetUnk18(s32 v) {
    if (m_unk18 != v) {
        m_unk18 = v;
        m_unk8 = 0;
        m_unk10 = 0;
        m_unk14 = 0;
        m_unkC = 0;
    }
}

void CPadMgr::Update() {
    if (m_unk18) {
        m_unkC = Func22D0A0(0);
        m_unk8 = Func22D008(0);
        m_unk10 = Func22D1D0(0);
        m_unk14 = Func22D138(0);
    }
}

void AddFadeMgr(CTaskList24F5C0 *list) {
    u8 *p = D_0029F394;
    CFadeMgr *t = new CFadeMgr(p, 8);
    list->Func24F5C0(t, 0);
}
INCLUDE_RODATA("asm/nonmatchings/CPadMgr", D_002D1EE8);
INCLUDE_RODATA("asm/nonmatchings/CPadMgr", D_002D1EF8);
