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
    u8 pad2F89[0x58E0 - 0x2F89];
    CUserFlagBuf m_buf58E0;   // 0x58E0
    s32 m_unk58F4;            // 0x58F4
    u8 pad58F8[0x5910 - 0x58F8];
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

INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D5ED8);
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

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", Func141560__12CUserFlagMgriUii);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", Func141768__12CUserFlagMgriUii);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6520);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", D_002D6548);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", jtbl_002D6570);
INCLUDE_RODATA("asm/nonmatchings/CUserFlagMgr", jtbl_002D65B0);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", Func141F68__12CUserFlagMgriUii);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", Func142318__12CUserFlagMgriUii);

INCLUDE_ASM("asm/nonmatchings/CUserFlagMgr", Func1425D8__12CUserFlagMgriUii);

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
