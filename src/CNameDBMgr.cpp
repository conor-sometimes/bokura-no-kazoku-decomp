#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CPushBuf.h"
#include "CFlagWork.h"
//@sym memset 0x289FB0
#include "libc.h"
// Interface without fields (its RTTI name only): the vptr is at 0.
class INameDBMgr {
public:
    virtual void Release() = 0;
    virtual int Func16C848(const char *path) = 0;
    virtual void Init() = 0;
    virtual void Func16CBD0(s32 kind) = 0;
    virtual void Push16CDC0(s32 kind, const char *name) = 0;
};
// Vtable 0x2C1398: slot 0 is an inline `delete this` (emitted elsewhere), the destructor is slot
// 5. Release is declared, not defined, so it is the key method and the vtable stays asm.
class CNameDBMgr : public INameDBMgr {
public:
    CNameDBMgr();
    virtual void Release();
    virtual int Func16C848(const char *path);
    virtual void Init();
    virtual void Func16CBD0(s32 kind);
    virtual void Push16CDC0(s32 kind, const char *name);
    virtual ~CNameDBMgr();
    static CNameDBMgr *Create(void *a);

    CPushBuf m_buf;           // 0x4
    char **m_tables[10];      // 0x10
    s32 m_counts[10];         // 0x38
};
extern "C" void func_0016CF98(void *p, void *a);
extern CNameDBMgr *D_002A35B0;

extern CFlagWork *D_002A5358;
extern "C" void func_00108EA0(CFlagWork *w, s32 id, const char *s);
extern "C" const char *func_00109158(CFlagWork *w, s32 id);
extern "C" void *func_0024A570(void *a, char *buf, const char *s1, const char *s2);
extern char D_002D9CD8[];
extern char D_002D9CE0[];

extern s32 D_002A3640[];
extern s32 D_002A3610[];
extern char D_002D9CE8[];
extern "C" s32 func_0016C6D8(s32 kind);

extern "C" unsigned int strlen(const char *s);
void Func2491A8(void *buf, const char *path, s32 a, s32 b, s32 c);
s32 Func249248(void *buf);
void Func249348();
void *Func24A4C0(const char *name);
extern void (*D_002B91B0)(void *p);
const char *Func24AF10(void *p, const char *key);
const char *Func24AFE8(const char *s, char *buf, s32 k, s32 size);
extern "C" s32 func_0024B040(const char *s, s32 k);
extern "C" void func_00248C30(void *buf);
extern "C" void func_00248C70(void *buf);
extern "C" char *func_00248DA8(void *buf);
extern "C" char *func_00248DC0(void *buf);
extern s32 D_002A366C, D_002A3670, D_002A3674;
extern const char *D_002A3678;
extern const char *D_002A35B8[];
extern "C" int strcmp(const char *, const char *);
void Func16CB08(s32 type, s32 base, void *src);
// @decl-end
INCLUDE_RODATA("asm/nonmatchings/CNameDBMgr", D_002D9C30);
INCLUDE_RODATA("asm/nonmatchings/CNameDBMgr", D_002D9C58);
INCLUDE_RODATA("asm/nonmatchings/CNameDBMgr", D_002D9C60);
INCLUDE_RODATA("asm/nonmatchings/CNameDBMgr", D_002D9C68);
INCLUDE_RODATA("asm/nonmatchings/CNameDBMgr", D_002D9C70);
INCLUDE_RODATA("asm/nonmatchings/CNameDBMgr", D_002D9C78);
INCLUDE_RODATA("asm/nonmatchings/CNameDBMgr", D_002D9C80);
INCLUDE_RODATA("asm/nonmatchings/CNameDBMgr", D_002D9C88);
INCLUDE_RODATA("asm/nonmatchings/CNameDBMgr", D_002D9C90);
INCLUDE_RODATA("asm/nonmatchings/CNameDBMgr", D_002D9C98);
INCLUDE_RODATA("asm/nonmatchings/CNameDBMgr", D_002D9CA0);
INCLUDE_RODATA("asm/nonmatchings/CNameDBMgr", D_002D9CA8);
INCLUDE_RODATA("asm/nonmatchings/CNameDBMgr", D_002D9CB0);
INCLUDE_RODATA("asm/nonmatchings/CNameDBMgr", D_002D9CB8);
INCLUDE_RODATA("asm/nonmatchings/CNameDBMgr", D_002D9CC8);
INCLUDE_RODATA("asm/nonmatchings/CNameDBMgr", D_002D9CD8);
INCLUDE_RODATA("asm/nonmatchings/CNameDBMgr", D_002D9CE0);
INCLUDE_RODATA("asm/nonmatchings/CNameDBMgr", D_002D9CE8);

CNameDBMgr::CNameDBMgr() {
    D_002A35B0 = this;
    memset(m_counts, 0, 0x28);
    memset(m_tables, 0, 0x28);
}

CNameDBMgr::~CNameDBMgr() {
    Init();
    D_002A35B0 = 0;
}

int CNameDBMgr::Func16C848(const char *path) {
    char buf[256];
    char a[256];
    char b[256];
    void *data;
    int opened;
    s32 i, j, n;
    const char *p;
    const char *q;
    char *s;
    int ok = 0;
    data = 0;
    opened = 0;
    Func2491A8(buf, path, D_002A366C, D_002A3670, D_002A3674);
    if (Func249248(buf)) {
        opened = 1;
        data = Func24A4C0(D_002A3678);
        if (data) {
            func_00248C30(&m_buf);
            for (i = 0; i < 10; i++) {
                p = Func24AF10(data, D_002A35B8[i]);
                if (*p) {
                    n = func_0024B040(p, 1);
                    m_counts[i] = n;
                    m_tables[i] = (char **)m_buf.Func248CC8(n * 4, 1, 1);
                    for (j = 0; j < n; j++) {
                        p = Func24AFE8(p, a, 1, 0x100);
                        q = (const char *)func_0024A570((void *)a, func_00248DA8(&m_buf), D_002D9CD8, D_002D9CE0);
                        if (*q) {
                            func_0024A570((void *)q, b, D_002D9CD8, D_002D9CE0);
                            s = func_00248DA8(&m_buf);
                            strcpy(s + strlen(s), D_002D9CD8);
                            s = func_00248DA8(&m_buf);
                            strcpy(s + strlen(s), b);
                        }
                        m_tables[i][j] = func_00248DC0(&m_buf);
                    }
                }
            }
            func_00248C70(&m_buf);
            ok = 1;
        }
    }
    if (data) D_002B91B0(data);
    if (opened) Func249348();
    return ok;
}

void CNameDBMgr::Init() {
    m_buf.Func248E00();
    memset(m_counts, 0, 0x28);
    memset(m_tables, 0, 0x28);
}

void Func16CB08(s32 type, s32 base, void *src) {
    char buf[256];
    if (type == 0x20) {
        void *p = func_0024A570(src, buf, D_002D9CD8, D_002D9CE0);
        func_00108EA0(D_002A5358, base + 0x10, buf);
        func_0024A570(p, buf, D_002D9CD8, D_002D9CE0);
        func_00108EA0(D_002A5358, base + 0x1A, buf);
    } else {
        func_00108EA0(D_002A5358, base + 0x1A, (const char *)src);
    }
}

void CNameDBMgr::Func16CBD0(s32 kind) {
    const char *names[20];
    s32 idx = func_0016C6D8(kind);
    s32 n, base, cnt, i, k, m;
    if (idx < 0) return;
    n = D_002A3640[idx];
    base = D_002A3610[idx];
    cnt = 0;
    for (i = 0; i < n; i++) {
        if (*D_002A26E0->GetStr(base + i)) {
            Func16CB08(kind, cnt, (void *)D_002A26E0->GetStr(base + i));
            names[cnt++] = D_002A26E0->GetStr(base + i);
        }
    }
    k = cnt;
    for (i = 0; i < m_counts[idx] && cnt < n; i++) {
        for (m = 0; m < k; m++)
            if (!strcmp(names[m], m_tables[idx][i])) goto next;
        Func16CB08(kind, cnt++, m_tables[idx][i]);
    next:;
    }
    D_002A5358->Func108FF0(15, cnt);
}

// GNU as 2.10 bug: without a fresh frag here it assembles the `lui` of `lw $19, D_002A3610($2)`
// as a copy of the following `lw` (position-dependent; appeared when the ctor became C++). The
// function is 8-aligned anyway, so this emits nothing.
asm(".p2align 3");
void CNameDBMgr::Push16CDC0(s32 kind, const char *name) {
    s32 idx = func_0016C6D8(kind);
    if (idx < 0) return;
    s32 n = D_002A3640[idx];
    s32 base = D_002A3610[idx];
    s32 i;
    for (i = 0; i < n; i++) {
        if (strcmp(func_00109158(D_002A26E0, base + i), name) == 0) {
            for (i++; i < n; i++) func_00108EA0(D_002A26E0, base + i - 1, func_00109158(D_002A26E0, base + i));
            func_00108EA0(D_002A26E0, base + n - 1, D_002D9CE8);
            break;
        }
    }
    for (i = n - 1; i > 0; i--) func_00108EA0(D_002A26E0, base + i, func_00109158(D_002A26E0, base + i - 1));
    func_00108EA0(D_002A26E0, base, name);
}

CNameDBMgr *CNameDBMgr::Create(void *a) {
    CNameDBMgr *p = (CNameDBMgr *)operator new(0xFEC8);
    func_0016CF98(p, a);
    return p;
}
INCLUDE_RODATA("asm/nonmatchings/CNameDBMgr", D_002D9CF0);
INCLUDE_RODATA("asm/nonmatchings/CNameDBMgr", D_002D9D00);
