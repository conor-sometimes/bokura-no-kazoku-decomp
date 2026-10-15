#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
//@sym strcmp 0x28B190
#include "libc.h"

typedef __builtin_va_list va_list;
#define va_start(ap, last) __builtin_stdarg_start(ap, last)
#define va_end(ap) __builtin_va_end(ap)
class CValueHolder {
public:
    int ValueAsInt();
};
class CSvmWork : public CValueHolder {
public:
    CSvmWork() throw();
    int SlotAsInt(s32 i, s32 def);
    int IsBadSlot(s32 i);
    int Fatal(const char *fmt, ...);
    f32 SlotAsFloat(s32 i, f32 def);
    void SetResultFloat(f32 v);
    void SetResultInt(s32 v);
    void Func12E858();
    void Func130138(const char *s);
    void Func131720();
};
#include "CFlagWork.h"
#include "CGameDBMgr.h"
class CPushBuf {
public:
    CPushBuf() throw();
    void Func248E00();
    int Func248EB0();
    char *Func248D38(const char *s);

    u8 m_data[0xC];
};
struct UserFlagKey20 { const char *name; u8 pad[0x10]; };
struct UserFlagKey8 { const char *name; u8 pad[0x4]; };
struct UserFlagSvmArg { u8 pad[0xC]; s32 flags; s32 lo; s32 hi; s32 flagOfs; };
struct UserFlagTable { const char *name; s32 id; u8 pad[0x18]; };
struct UserFlagEntry { const char *name; s32 m_unk4; u32 type; };
struct UserFlagStrPair { char *key; char *value; };
extern UserFlagTable D_002A0D40[];
extern char *D_002A1954;
extern char D_002A19C8[];
extern char D_002D62A0[];
extern char D_002D6240[];
extern char D_002D6250[];
extern char D_002D6260[];
extern char D_002D6450[];
int Func145738(int name, int flag);
extern char D_002D6458[];
extern char D_002D6488[];
extern "C" void *bsearch(const void *key, const void *base, unsigned int n, unsigned int size, int (*cmp)(const void *, const void *));
extern "C" void *memcpy(void *dst, const void *src, unsigned int n);
void *operator new(unsigned int n);
int CompareUserFlagNames(const char **a, const char **b);
int CompareUserFlagNames2(const char **a, const char **b);
int Func1456A8(int name);
const char *Func24A840(const char *s, char *buf, const char *a, const char *b, int n);
const char *Func24A570(const char *s, char *buf, const char *a, const char *b);
const char *Func24AD10(const char *s, char *buf, int a, int n);
const char *Func24AB90(const char *s, const char *set);
void Func24ABE0(char *s, const char *set);
void Func235DE0(const char *fmt, ...);
class CUserFlagLog {
public:
    void Dummy();
};
class CUserFlagWriter {
public:
    CUserFlagWriter() {}
    CUserFlagWriter(char *p) { m_ptr = p; }
    int Write(const void *src, int n);
    int Func1401B8(int v);
    char *m_ptr;
};
// Interface of CUserFlagMgr (its slots 0-33); slot 0 deletes through the destructor (slot 34).
class IUserFlagMgr {
public:
    virtual void Release();
    virtual void Vf298B20();
    virtual void Vf13F948();
    virtual void Reset140040();
    virtual void Vf298B48();
    virtual void Vf298B68();
    virtual void Vf298B70();
    virtual void Vf298BB0();
    virtual void Vf298C10();
    virtual void Vf298C20();
    virtual void Vf298CC0();
    virtual void Vf298D48();
    virtual void Vf298D68();
    virtual void Vf298D78();
    virtual void Vf298D88();
    virtual void Vf298EE0();
    virtual int Func140088(CUserFlagWriter w, const char *s);
    virtual int RunScript(const char *src, int quiet);
    virtual int RunScriptF(const char *fmt, int quiet, ...);
    virtual int Dispatch1411B8(int a, u32 id, int b);
    virtual int Dispatch141280(int a, u32 id, int b);
    virtual int Vf1412D0(int a, u32 id, int b);
    virtual void Vf298D90();
    virtual void Vf298D98();
    virtual void Vf298E38();
    virtual void Vf298EC0();
    virtual void SetBit(int name);
    virtual int GetBit(int name);
    virtual void Vf298EC8();
    virtual void Vf298ED0();
    virtual void Vf298ED8();
    virtual int Update143328(int name);
    virtual int Update143478(int name);
    virtual int Update1436E0(int name);
};
extern void *(*D_002B91A4)(u32 n);
extern void (*D_002B91B0)(void *p);
// Heap buffer with its allocator and free functions.
class CUserFlagBuf {
public:
    CUserFlagBuf() {
        m_alloc = D_002B91A4;
        m_free = D_002B91B0;
        m_ptr = 0;
        m_cap = 0;
        m_size = 0;
    }

    void *(*m_alloc)(u32 n);  // 0x00
    void (*m_free)(void *p);  // 0x04
    void *m_ptr;              // 0x08
    s32 m_size;               // 0x0C
    s32 m_cap;                // 0x10
};
class CUserFlagMgr : public IUserFlagMgr {
public:
    CUserFlagMgr() throw();
    virtual ~CUserFlagMgr();
    virtual int RunScriptF(const char *fmt, int quiet, ...);
    virtual int Dispatch141280(int a, u32 id, int b);
    virtual int Vf1412D0(int a, u32 id, int b);
    virtual int Update143328(int name);
    virtual int Update143478(int name);
    virtual int Update1436E0(int name);
    virtual int Func140088(CUserFlagWriter w, const char *s);
    int Func140EE0(CUserFlagWriter *w, const char **s);
    void *FindFlag(const char *name);
    void *FindFlag2(const char *name);
    virtual void Reset140040();
    void Func13F488(int v) throw();
    void Func1432E0(CSvmWork *w, UserFlagSvmArg *p, int n);
    virtual void SetBit(int name);
    virtual int GetBit(int name);
    int Func140EA0(CUserFlagWriter *w, const char **s);
    int Func140D40(CUserFlagWriter *w, const char **s);
    UserFlagTable *FindTable(int id);
    void Func140938(int a, const char **s);
    void Func1409A8(int a, char *buf, const char **s);
    void Print13F740(const char *fmt, ...);
    void Print13F7B0(const char *fmt, ...);
    void Print13F820(const char *fmt, ...);
    void Func13F648Vprint(const char *tag, const char *fmt, va_list ap);
    int ParseToken(char *dst, const char **s);
    int SingleBit(u32 mask, int exact);
    virtual int RunScript(const char *src, int quiet);
    int Clamp142BD8(UserFlagSvmArg *p, int ofs, int v);
    virtual int Dispatch1411B8(int a, u32 id, int b);
    int Func141560(int a, u32 id, int b);
    int Func141768(int a, u32 id, int b);
    int Func141F68(int a, u32 id, int b);
    int Func142318(int a, u32 id, int b);
    int Func1425D8(int a, u32 id, int b);
    int CheckId(int id, int a2);
    int ParsePairs(const char *s, UserFlagStrPair *out);

    // vptr 0x0
    CUserFlagLog *m_logObj;   // 0x4: message sink (Print13F740 etc.)
    void (CUserFlagLog::*m_log)(const char *msg); // 0x8
    UserFlagEntry *m_entries[0x180]; // 0x10
        CPushBuf m_buf;           // 0x610
    s32 m_unk61C;             // 0x61C
    s32 m_unk620;             // 0x620
    void *m_unk624;           // 0x624
    s32 m_unk628;             // 0x628
    void *m_unk62C;           // 0x62C
    s32 m_unk630;             // 0x630
    CSvmWork m_svm;           // 0x634
    u8 pad635[0x2F88 - 0x635];
    CSvmWork m_svm2;          // 0x2F88
    u8 pad2F89[0x58DC - 0x2F89];
    s32 m_unk58DC;            // 0x58DC
    CUserFlagBuf m_buf58E0;   // 0x58E0
    s32 m_unk58F4;            // 0x58F4
    s32 m_unk58F8;            // 0x58F8
    s32 m_unk58FC;            // 0x58FC
    s32 m_unk5900;            // 0x5900: current event id
    s32 m_unk5904;            // 0x5904: current event group
    s32 m_unk5908;            // 0x5908
    s32 m_unk590C;            // 0x590C
    u32 m_unk5910;            // 0x5910
    CUserFlagBuf m_buf5914;   // 0x5914
    s32 m_unk5928;            // 0x5928
};
//@sym bsearch 0x289160
//@sym memcpy 0x289DFC
//@sym __builtin_new 0x245648

//@sym bsearch 0x289160

extern "C" int vsprintf(char *buf, const char *fmt, va_list ap);

extern CUserFlagMgr *D_002A0D38;

extern "C" unsigned int strlen(const char *s);

extern "C" int func_00142CE8(CUserFlagMgr *m, CSvmWork *w, UserFlagEntry *e, s32 id, s32 a, s32 v);

int InRange(int v, int lo, int hi);
int OutOfRange(int v, int lo, int hi);
int Clamp(int v, int lo, int hi);
int Min(int a, int b);
int Max(int a, int b);
int Abs(int x);
int InRangeF(f32 v, f32 lo, f32 hi);
int OutOfRangeF(f32 v, f32 lo, f32 hi);
f32 ClampF(f32 v, f32 lo, f32 hi);
f32 MinF(f32 a, f32 b);
f32 MaxF(f32 a, f32 b);
f32 AbsF(f32 x);
struct CSvmRand {
    u32 m_seed;
    u32 Next() {
        m_seed = m_seed * 0x19660D + 1;
        return (m_seed >> 12) & 0xFFFF;
    }
    u32 Rand(u32 n) { return ((Next() << 16) | Next()) % n; }
    s32 RangeA(s32 lo, s32 hi) {
        if (hi < lo) hi = lo;
        if (hi == lo) return 0;
        return lo + Rand(hi - lo + 1);
    }
    s32 RangeB(s32 lo, s32 hi) {
        s32 k;
        hi = hi < lo ? lo : hi;
        k = 0;
        if (hi != lo) k = lo + Rand(hi - lo + 1);
        return k;
    }
    s32 RangeC(s32 lo, s32 hi) {
        s32 k = 0;
        if (hi < lo) hi = lo;
        if (hi != lo) k = Rand(hi - lo + 1) + lo;
        return k;
    }
};
struct CSvmWorkF {
    u8 pad0[4];
    CSvmRand m_rand;          // 0x4
    u8 pad8[0x704 - 8];
    s32 m_numSlots;           // 0x704
    u8 pad708[0x291C - 0x708];
    s32 m_forced;             // 0x291C
};
// @decl-end

CUserFlagMgr::CUserFlagMgr() throw() {
    D_002A0D38 = this;
    Func13F488(1);
    return;
}

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_0013F390);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", Func13F488__12CUserFlagMgri);

void CUserFlagMgr::Func13F648Vprint(const char *tag, const char *fmt, va_list ap) {
    char buf[0x100];
    char msg[0x100];
    strcpy(buf, tag);
    vsprintf(msg, fmt, ap);
    strcpy(buf + strlen(buf), msg);
    if (m_logObj && m_log) {
        (m_logObj->*m_log)(buf);
    } else {
        Func235DE0(buf);
    }
}

void CUserFlagMgr::Print13F740(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    Func13F648Vprint(D_002D6240, fmt, ap);
    va_end(ap);
}

void CUserFlagMgr::Print13F7B0(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    Func13F648Vprint(D_002D6250, fmt, ap);
    va_end(ap);
}

void CUserFlagMgr::Print13F820(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    Func13F648Vprint(D_002D6260, fmt, ap);
    va_end(ap);
}

int FindUserFlagName(const char *s) {
    int i;
    for (i = 0; D_002A0D40[i].name; i++) {
        if (!strcmp(D_002A0D40[i].name, s)) return i;
    }
    return -1;
}

int CompareUserFlagNames(const char **a, const char **b) {
    return strcmp(*a, *b);
}

int CompareUserFlagNames2(const char **a, const char **b) {
    return strcmp(*a, *b);
}

INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D5EE0);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D5EE8);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D5EF0);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D5EF8);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D5F00);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D5F08);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D5F10);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D5F20);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D5F28);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D5F30);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D5F38);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D5F40);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D5F48);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D5F50);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D5F58);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D5F60);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D5F68);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D5F70);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D5F78);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D5F80);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D5F88);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D5F90);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D5F98);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D5FA0);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D5FA8);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D5FB0);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D5FB8);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D5FC0);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D5FC8);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D5FD0);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D5FD8);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D5FE0);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D5FE8);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D5FF0);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D5FF8);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6000);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6008);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6010);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6018);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6020);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6028);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6030);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6038);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6040);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6048);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6050);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6058);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6060);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6068);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6070);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6078);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6080);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6088);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6090);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D60A0);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D60B0);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D60B8);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D60C0);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D60C8);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D60D8);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D60E0);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D60F0);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D60F8);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6100);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6108);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6118);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6120);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6128);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6138);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6148);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6150);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6160);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6168);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6170);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6178);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6180);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6188);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6190);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6198);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D61A8);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D61B0);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D61B8);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D61C0);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D61C8);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D61D8);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D61E8);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D61F0);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D61F8);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6200);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6208);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6210);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6218);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6220);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6228);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6230);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6238);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6240);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6250);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6260);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6268);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6270);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6278);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6280);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6290);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D62A0);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D62A8);
INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_0013F948);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D62C8);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D62D0);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D62D8);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D62E0);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D62E8);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_0013FD00);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_0013FF08);

void CUserFlagMgr::Reset140040() {
    m_unk61C = -1;
    m_unk620 = -1;
    m_unk624 = 0;
    m_unk628 = 0;
    m_buf.Func248E00();
    Func13F488(1);
}

int CUserFlagMgr::Func140088(CUserFlagWriter w, const char *s) {
    return Func140EE0(&w, &s);
}

int FindInt(int *p, int v) {
    int i;
    for (i = 0; p[i] >= 0; i++) {
        if (p[i] == v) return i;
    }
    return -1;
}

int FindString(const char **p, const char *s) {
    int i;
    for (i = 0; p[i]; i++) {
        if (!strcmp(p[i], s)) return i;
    }
    return -1;
}

int CUserFlagWriter::Write(const void *src, int n) {
    if (m_ptr && n > 0) {
        memcpy(m_ptr, src, n);
        m_ptr += n;
    }
    return n;
}

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", Func1401B8__15CUserFlagWriteri);

int IsNumber(const char *s) {
    int n = 0, i;
    for (i = 0; s[i]; i++) {
        n++;
        if ((unsigned)(s[i] - '0') >= 10) return 0;
    }
    return i > 0 && n > 0;
}

int IsFloat(const char *s) {
    int dots = 0, digits = 0, i;
    for (i = 0; s[i]; i++) {
        char c = s[i];
        if ((unsigned)(c - '0') < 10) digits++;
        else if (c == '.') dots++;
        else if (c == 'f' && s[i + 1] == 0) ;
        else return 0;
    }
    return i > 0 && dots == 1 && digits > 0;
}

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_00140358);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_00140440);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6318);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6320);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6328);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6330);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6340);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6350);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6360);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6368);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6370);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6378);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6380);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6388);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6390);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6398);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D63A0);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D63A8);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D63B0);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D63B8);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D63C0);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D63C8);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D63D0);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D63D8);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D63E0);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D63E8);

void *CUserFlagMgr::FindFlag(const char *name) {
    UserFlagKey20 key;
    key.name = name;
    return bsearch(&key, m_unk624, m_unk628, 0x14, (int (*)(const void *, const void *))CompareUserFlagNames);
}

void *CUserFlagMgr::FindFlag2(const char *name) {
    UserFlagKey8 key;
    key.name = name;
    return bsearch(&key, m_unk62C, m_unk630, 0x8, (int (*)(const void *, const void *))CompareUserFlagNames2);
}

void CUserFlagMgr::Func140938(int a, const char **v) {
    char buf[0x20];
    *v = Func24A840(*v, buf, D_002A19C8, D_002D62A0, 0x100);
    Func1409A8(a, buf, v);
}

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", Func1409A8__12CUserFlagMgriPcPPCc);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6400);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6410);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6418);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6420);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", jtbl_002D6430);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6450);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", Func140D40__12CUserFlagMgrP15CUserFlagWriterPPCc);

int CUserFlagMgr::Func140EA0(CUserFlagWriter *a, const char **s) {
    char buf[0x100];
    int r = 0;
    if (**s) {
        int t = Func140D40(a, s);
        if (t < 0) return -1;
        r = t;
    }
    return r;
}

int CUserFlagMgr::Func140EE0(CUserFlagWriter *w, const char **s) {
    char buf[0x100];
    const char *p;
    int total = 0, r;
    for (;;) {
        *s = Func24A570(*s, buf, D_002D6450, D_002D62A0);
        if (**s == 0 && buf[0] == 0) break;
        if (buf[0]) {
            p = buf;
            r = Func140EA0(w, &p);
            if (r < 0) return -1;
            total += r;
        }
    }
    return total + w->Func1401B8(0x20);
}

int CUserFlagMgr::ParseToken(char *dst, const char **s) {
    CUserFlagWriter w;
    const char *start;
    int n;
    w.m_ptr = 0;
    start = *s;
    if (Func140EA0(&w, s) < 0) return -1;
    n = *s - start;
    if (dst) {
        memcpy(dst, start, n);
        dst[n] = 0;
    }
    return n;
}

int CUserFlagMgr::RunScript(const char *src, int quiet) {
    if (!src) return 0;
    if (!quiet) m_unk58F4++;
    m_svm.Func12E858();
    m_svm.Func130138(src);
    m_svm.Func131720();
    if (!quiet) m_unk58F4--;
    return m_svm.ValueAsInt();
}

int CUserFlagMgr::RunScriptF(const char *fmt, int quiet, ...) {
    char src[0x400];
    char out[0x400];
    va_list ap;
    va_start(ap, quiet);
    vsprintf(src, fmt, ap);
    if (Func140088(CUserFlagWriter(out), src) < 0) return -1;
    return RunScript(out, quiet);
}

int CUserFlagMgr::Dispatch1411B8(int a, u32 id, int b) {
    if (id < 0x180) {
        UserFlagEntry *e = m_entries[id];
        if (e) {
            u32 t = e->type;
            if (t < 7) return Func141560(a, id, b);
            if (t - 7 < 0x10) return Func141768(a, id, b);
            if (t - 0x17 < 7) return Func141F68(a, id, b);
            if (t - 0x1E < 7) return Func142318(a, id, b);
            if (t - 0x25 < 0x10) return Func1425D8(a, id, b);
        }
    }
    Func235DE0(D_002D6458, id);
    return 0;
}

int CUserFlagMgr::Dispatch141280(int a, u32 id, int b) {
    int r;
    m_unk58F4++;
    r = Dispatch1411B8(a, id, b);
    m_unk58F4--;
    return r;
}

INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6458);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6488);
int CUserFlagMgr::Vf1412D0(int a, u32 id, int b) {
    UserFlagEntry *e;
    if (id < 0x180) {
        e = m_entries[id];
        if (e) {
            s32 t = e->type;
            CSvmWork *w = (CSvmWork *)a;
            if ((u32)t < 7) {
                switch (t) {
                case 2:
                    Func1432E0(w, (UserFlagSvmArg *)e, m_unk5928 / 4);
                    return 0;
                case 3:
                    Func1432E0(w, (UserFlagSvmArg *)e, m_unk5928 % 4);
                    return 0;
                case 4:
                    Func1432E0(w, (UserFlagSvmArg *)e, m_unk5928 / 4 + 0x19);
                    return 0;
                }
            } else if ((u32)(t - 7) < 0x10) {
                switch (t) {
                case 8:
                case 9:
                    if (e->m_unk4 == 0x34) {
                        Func1432E0(w, (UserFlagSvmArg *)e, D_002A2988->Vf14F918(m_unk5928, w->SlotAsInt(0, 0)));
                        return 0;
                    }
                    break;
                case 0xF:
                    Func1432E0(w, (UserFlagSvmArg *)e, D_002A2988->Vf14F918(m_unk5928, w->SlotAsInt(0, 0)) >= 0);
                    return 0;
                }
            } else if ((u32)(t - 0x17) < 7) {
            } else if ((u32)(t - 0x1E) < 7) {
                return Func142318(a, id, b);
            } else if ((u32)(t - 0x25) < 0x10) {
                return Func1425D8(a, id, b);
            } else {
                goto unknown;
            }
            goto prohibit;
        }
    }
unknown:
    Func235DE0(D_002D6458, id);
    return 0;
prohibit:
    Func235DE0(D_002D6488, e->name);
    return 0;
}

int CUserFlagMgr::Func141560(int a, u32 id, int b) {
    UserFlagEntry *e = m_entries[id];
    CSvmWork *w = (CSvmWork *)a;
    s32 v;
    switch (e->type) {
    case 1:
        if (!w->IsBadSlot(0)) {
            if (!func_00142CE8(this, w, e, e->m_unk4, 0, w->SlotAsInt(0, 0))) return 0;
        }
        Func1432E0(w, (UserFlagSvmArg *)e, D_002A26E4->Func1091B0(e->m_unk4));
        break;
    case 2:
        Func1432E0(w, (UserFlagSvmArg *)e, D_002A26E4->Func1091B0(e->m_unk4) / 4);
        break;
    case 3:
        Func1432E0(w, (UserFlagSvmArg *)e, D_002A26E4->Func1091B0(e->m_unk4) % 4);
        break;
    case 4:
        Func1432E0(w, (UserFlagSvmArg *)e, D_002A26E4->Func1091B0(e->m_unk4) / 4 + 0x19);
        break;
    case 5:
        v = D_002A26E4->Func1091B0(e->m_unk4);
        if (v >= 0) v = Func145738(D_002A26E4->Func1091B0(e->m_unk4), 1);
        else v = 0;
        Func1432E0(w, (UserFlagSvmArg *)e, v);
        break;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", Func141768__12CUserFlagMgriUii);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6520);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6548);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", jtbl_002D6570);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", jtbl_002D65B0);

#if 0 // DIFF 3 (g1): only the 'already exist' print's argument moves are scheduled differently (a2 before a1 here)
int CUserFlagMgr::Func141F68(int a, u32 id, int b) {
    UserFlagEntry *e = m_entries[id];
    CSvmWork *w = (CSvmWork *)a;
    s32 n, k, v, c, t;
    CActRec *act;
    switch (e->type) {
    case 0x18:
    case 0x19:
    case 0x1B:
    case 0x1C:
        n = w->SlotAsInt(0, 0);
        if ((u32)(n - 1) >= 0xFF) {
            w->Fatal("*** flag : out of range action ID (%d)\n", n);
            return 0;
        }
        k = n + 0x1062;
        if (D_002A26E4->Func1091B0(k)) {
            s32 x = D_002A26E4->Func1091B0(k);
            Func235DE0("flag : already exist action (%d, %d)\n", n, x);
            return 0;
        }
        act = ((CActDB *)D_002A2988)->Find1DC(n);
        if (!act) {
            w->Fatal("*** flag : unknown action ID (%d)\n", n);
            return 0;
        }
        if ((u32)(e->type - 0x18) < 2) {
            v = w->SlotAsInt(1, act->m20);
            t = act->m18;
            c = e->type == 0x18 ? 2 : 4;
        } else if ((u32)(e->type - 0x1B) < 2) {
            s32 s = func_00142B38(this, m_unk58DC, 0);
            s32 r1 = D_002A26E4->GetNamed(0x46, s);
            s32 r2 = D_002A26E4->GetNamed(0x52, s);
            switch (r1) {
            case 1: case 2: case 4: case 5: case 7: case 8: default: v = 12; break;
            case 6: v = ((CActDB *)D_002A2988)->Find1E8(r2)->m10 * 4; break;
            case 3: v = 24; break;
            case 9: v = 16; break;
            }
            if (e->type == 0x1B) t = Func145738(s, 1);
            else t = 0x18;
            c = 4;
        } else {
            return 0;
        }
        if (v == 0) v = 0x3FFF;
        if (m_unk58F4 <= 0) {
            D_002A26E4->Func108FF0(k, c);
            D_002A26E4->Func108FF0(n + 0x1162, v);
            D_002A26E4->Func108FF0(n + 0x1262, 1);
            D_002A26E4->Func108FF0(n + 0x1362, t);
        }
        Func1432E0(w, (UserFlagSvmArg *)e, 1);
        break;
    case 0x1A:
        v = w->SlotAsInt(0, 0);
        if ((u32)(v - 1) >= 0xFF) {
            w->Fatal("*** flag : out of range action ID %d\n", v);
            return 0;
        }
        if (e->m_unk4 == 0x1262 && D_002A26E4->Func1091B0(v + 0x1062) < 2) {
            Func1432E0(w, (UserFlagSvmArg *)e, 0);
            return 0;
        }
        Func1432E0(w, (UserFlagSvmArg *)e, D_002A26E4->Func1091B0(e->m_unk4 + v));
        break;
    }
    return 0;
}
#endif
INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", Func141F68__12CUserFlagMgriUii);

#if 0 // DIFF 1 (g1): case 0x1F's bgez is bgezl in retail (the lui in its slot); needs m_unk5900/5904/58FC fields
int CUserFlagMgr::Func142318(int a, u32 id, int b) {
    UserFlagEntry *e = m_entries[id];
    CSvmWork *w = (CSvmWork *)a;
    s32 ev;
    switch (e->type) {
    case 0x1F:
        ev = m_unk5900;
        if (ev < 0) {
        unknown:
            Func235DE0("*** flag : unknow event id (%d)\n", ev);
            return 0;
        }
        Func1432E0(w, (UserFlagSvmArg *)e, D_002A26E4->Func1091B0(ev + 0x226A));
        break;
    case 0x20:
        ev = m_unk5900;
        if (ev < 0) goto unknown;
        Func1432E0(w, (UserFlagSvmArg *)e, D_002A26E4->Func1091B0(m_unk5900 + 0x156A) + D_002A26E4->Func1091B0(m_unk5900 + 0x226A));
        break;
    case 0x21: {
        CEvGp *g = ((CEvGpDB *)D_002A2988)->Find1D0(m_unk5904);
        s32 i, sum;
        if (!g) {
            Func235DE0("*** flag : unknow ev-gp (%d)\n", m_unk5904);
            return 0;
        }
        sum = 0;
        for (i = 0; i < g->m_num; i++) {
            sum += D_002A26E4->Func1091B0(g->m_ents[i].m_id + 0x226A);
            sum += D_002A26E4->Func1091B0(g->m_ents[i].m_id + 0x156A);
        }
        Func1432E0(w, (UserFlagSvmArg *)e, sum);
        break;
    }
    case 0x22:
        Func1432E0(w, (UserFlagSvmArg *)e, m_unk58FC);
        break;
    case 0x23: {
        u32 n = w->SlotAsInt(0, -1);
        if (n >= 0x200) {
            Func235DE0("*** flag : out of range eflag (%d)\n", n);
            return 0;
        }
        if (!w->IsBadSlot(1)) func_00142CE8(this, w, e, n + 0x3AAE, 0, w->SlotAsInt(1, 0));
        Func1432E0(w, (UserFlagSvmArg *)e, D_002A26E4->Func1091B0(w->SlotAsInt(0, -1) + 0x3AAE));
        break;
    }
    }
    return 0;
}
#endif
INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", Func142318__12CUserFlagMgriUii);

int CUserFlagMgr::Func1425D8(int a, u32 id, int b) {
    UserFlagEntry *e = m_entries[id];
    CSvmWork *w = (CSvmWork *)a;
    switch (e->type) {
    case 0x26:
        Func1432E0(w, (UserFlagSvmArg *)e, e->m_unk4);
        break;
    case 0x27:
    {
        s32 x = w->SlotAsInt(0, 0);
        s32 y = w->SlotAsInt(1, 0);
        s32 z = w->SlotAsInt(2, 0);
        Func1432E0(w, (UserFlagSvmArg *)e, InRange(x, y, z));
        break;
    }
    case 0x28:
    {
        s32 x = w->SlotAsInt(0, 0);
        s32 y = w->SlotAsInt(1, 0);
        s32 z = w->SlotAsInt(2, 0);
        Func1432E0(w, (UserFlagSvmArg *)e, OutOfRange(x, y, z));
        break;
    }
    case 0x29:
    {
        s32 x = w->SlotAsInt(0, 0);
        s32 y = w->SlotAsInt(1, 0);
        s32 z = w->SlotAsInt(2, 0);
        Func1432E0(w, (UserFlagSvmArg *)e, Clamp(x, y, z));
        break;
    }
    case 0x2B:
    {
        s32 x = w->SlotAsInt(0, 0);
        s32 y = w->SlotAsInt(1, 0);
        Func1432E0(w, (UserFlagSvmArg *)e, Min(x, y));
        break;
    }
    case 0x2A:
    {
        s32 x = w->SlotAsInt(0, 0);
        s32 y = w->SlotAsInt(1, 0);
        Func1432E0(w, (UserFlagSvmArg *)e, Max(x, y));
        break;
    }
    case 0x2C:
        Func1432E0(w, (UserFlagSvmArg *)e, Abs(w->SlotAsInt(0, 0)));
        break;
    case 0x2D:
    {
        f32 fx = w->SlotAsFloat(0, 0.0f);
        f32 fy = w->SlotAsFloat(1, 0.0f);
        f32 fz = w->SlotAsFloat(2, 0.0f);
        Func1432E0(w, (UserFlagSvmArg *)e, InRangeF(fx, fy, fz));
        break;
    }
    case 0x2E:
    {
        f32 fx = w->SlotAsFloat(0, 0.0f);
        f32 fy = w->SlotAsFloat(1, 0.0f);
        f32 fz = w->SlotAsFloat(2, 0.0f);
        Func1432E0(w, (UserFlagSvmArg *)e, OutOfRangeF(fx, fy, fz));
        break;
    }
    case 0x2F:
    {
        f32 fx = w->SlotAsFloat(0, 0.0f);
        f32 fy = w->SlotAsFloat(1, 0.0f);
        f32 fz = w->SlotAsFloat(2, 0.0f);
        w->SetResultFloat(ClampF(fx, fy, fz));
        break;
    }
    case 0x31:
    {
        f32 fx = w->SlotAsFloat(0, 0.0f);
        f32 fy = w->SlotAsFloat(1, 0.0f);
        w->SetResultFloat(MinF(fx, fy));
        break;
    }
    case 0x30:
    {
        f32 fx = w->SlotAsFloat(0, 0.0f);
        f32 fy = w->SlotAsFloat(1, 0.0f);
        w->SetResultFloat(MaxF(fx, fy));
        break;
    }
    case 0x32:
        w->SetResultFloat(AbsF(w->SlotAsFloat(0, 0.0f)));
        break;
    case 0x33: {
        CSvmWorkF *f = (CSvmWorkF *)a;
        s32 n = f->m_numSlots - 1;
        s32 r = f->m_forced >= 0 ? f->m_forced : f->m_rand.RangeA(0, n);
        w->SetResultInt(w->SlotAsInt(r, 0));
        break;
    }
    }
    return 0;
}

int CUserFlagMgr::CheckId(int id, int a2) {
    int i;
    if (id >= 0 && id < D_002A26E4->Func1091B0(0x27)) return id;
    if ((u32)(id - 0x10) < 8) {
        for (i = 0; i < D_002A26E4->Func1091B0(0x27); i++) {
            if (D_002A26E4->Func1091B0(i + 0x28) == id) return i;
        }
        return -1;
    }
    if (id == 0x18 && a2) return id;
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_00142B38);

int CUserFlagMgr::Clamp142BD8(UserFlagSvmArg *p, int ofs, int v) {
    if (p->lo == 0 && p->hi == 0) return v;
    if (p->flags & 0x10) v += D_002A26E4->Func1091B0(p->flagOfs + ofs);
    v = (v < p->hi) ? v : p->hi;
    v = (v < p->lo) ? p->lo : v;
    if (p->flags & 0x10) v -= D_002A26E4->Func1091B0(p->flagOfs + ofs);
    return v;
}

UserFlagTable *CUserFlagMgr::FindTable(int id) {
    int i;
    for (i = 0; D_002A0D40[i].name; i++) {
        if (D_002A0D40[i].id == id) return &D_002A0D40[i];
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", func_00142CE8);

void CUserFlagMgr::Func1432E0(CSvmWork *w, UserFlagSvmArg *p, int n) {
    int r = n;
    if (p->flags & 8) r = n / 4;
    if (p->flags & 2) r++;
    w->SetResultInt(r);
}

int CUserFlagMgr::Update143328(int name) {
    s32 v[0x100];
    s32 i;
    int changed = 0;
    s32 id = Func1456A8(name);
    for (i = 0; i < D_002A26E4->Func1091B0(0x27); i++) {
        if (id >= 0 && i != id) continue;
        if (D_002A26E4->GetNamed(0xBE, i)) {
            D_002A26E4->SetNamed(0xBE, i, 0);
            if (D_002A2988->Vf14CC00(v, i) > 0) {
                D_002A26E4->Func108FF0(i + 0xD6, v[0]);
                changed = 1;
            }
        }
    }
    if (changed) SetBit(name);
    return changed;
}

int CUserFlagMgr::Update143478(int name) {
    s32 v[0x100];
    s32 i;
    int changed = 0;
    s32 id = Func1456A8(name);
    for (i = 0; i < D_002A26E4->Func1091B0(0x27); i++) {
        s32 r;
        if (id >= 0 && i != id) continue;
        r = D_002A26E4->GetNamed(0x166, name);
        if (r) {
            CGameDBRec *p = D_002A2988->Find234(r);
            if (p && p->m_unk14 == 0xD) {
                if (p->m_unk18 != D_002A26E4->GetNamed(0xB8, i)) {
                    D_002A26E4->SetNamed(0xB8, i, p->m_unk18);
                    changed = 1;
                }
                continue;
            }
        }
        if (D_002A2988->Vf14D430(v, i) > 0) {
            if (D_002A26E4->GetNamed(0xB8, i) != v[0]) {
                D_002A26E4->SetNamed(0xB8, i, v[0]);
                changed = 1;
            }
        }
    }
    if (changed) {
        SetBit(name);
        D_002A26E4->SetNamed(0xBE, name, D_002A26E4->GetNamed(0xBE, name) | 0x40);
    }
    return changed;
}

int CUserFlagMgr::Update1436E0(int name) {
    s32 v[0x100];
    s32 i;
    int changed = 0;
    s32 id = Func1456A8(name);
    for (i = 0; i < D_002A26E4->Func1091B0(0x27); i++) {
        if (id >= 0 && i != id) continue;
        if (D_002A2988->Vf14D5F8(v, i) > 0) {
            if (D_002A26E4->Func1091B0(i + 0xB8) != v[0]) {
                D_002A26E4->Func108FF0(i + 0xB8, v[0]);
                changed = 1;
            }
        }
    }
    if (changed) SetBit(name);
    return changed;
}

void CUserFlagMgr::SetBit(int name) {
    int b = Func1456A8(name);
    if (b >= 0) m_unk5910 |= 1 << b;
}

int CUserFlagMgr::GetBit(int name) {
    int b = Func1456A8(name);
    if (b < 0) return m_unk5910 != 0;
    return (m_unk5910 >> b) & 1;
}

int InRange(int v, int lo, int hi) {
    return v >= lo && v <= hi;
}

int OutOfRange(int v, int lo, int hi) {
    return v < lo || v > hi;
}

int Clamp(int v, int lo, int hi) {
    int r = (v < hi) ? v : hi;
    return (r < lo) ? lo : r;
}

int Min(int a, int b) {
    return (a < b) ? a : b;
}

int Max(int a, int b) {
    return (b < a) ? a : b;
}

int Abs(int x) {
    return x < 0 ? -x : x;
}

int InRangeF(f32 v, f32 lo, f32 hi) {
    return v >= lo && v <= hi;
}

int OutOfRangeF(f32 v, f32 lo, f32 hi) {
    return v < lo || hi < v;
}

f32 ClampF(f32 v, f32 lo, f32 hi) {
    return ((v < hi ? v : hi) < lo) ? lo : (v < hi ? v : hi);
}

f32 MinF(f32 a, f32 b) {
    return (a < b) ? a : b;
}

f32 MaxF(f32 a, f32 b) {
    return (b < a) ? a : b;
}

f32 AbsF(f32 x) {
    return x >= 0.0f ? x : -x;
}

CSysFlag *NewUserFlagSub() {
    CSysFlag *p = (CSysFlag *)operator new(0x20);
    p->Init143A30();
    return p;
}
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6920);
