#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CPushBuf.h"
//@sym memset 0x289FB0
#include "libc.h"
// Interface without fields (its RTTI name only): the vptr is at 0.
class INameDBMgr {
public:
    virtual void Release() = 0;
    virtual int Func16C848() = 0;
    virtual void Init() = 0;
    virtual int Func16CBD0() = 0;
    virtual void Push16CDC0(s32 kind, const char *name) = 0;
};
// Vtable 0x2C1398: slot 0 is an inline `delete this` (emitted elsewhere), so the key method is
// Func16C848, not the destructor (slot 5).
class CNameDBMgr : public INameDBMgr {
public:
    CNameDBMgr();
    virtual void Release() { delete this; }
    virtual int Func16C848();
    virtual void Init();
    virtual int Func16CBD0();
    virtual void Push16CDC0(s32 kind, const char *name);
    virtual ~CNameDBMgr();
    static CNameDBMgr *Create(void *a);

    CPushBuf m_buf;           // 0x4
    u8 m_unk10[0x28];         // 0x10
    u8 m_unk38[0x28];         // 0x38
};
extern "C" void func_0016CF98(void *p, void *a);
extern CNameDBMgr *D_002A35B0;

class CFlagWork;
extern CFlagWork *D_002A5358;
extern "C" void func_00108EA0(CFlagWork *w, s32 id, const char *s);
extern "C" const char *func_00109158(CFlagWork *w, s32 id);
extern "C" void *func_0024A570(void *a, char *buf, const char *s1, const char *s2);
extern char D_002D9CD8[];
extern char D_002D9CE0[];

extern CFlagWork *D_002A26E0;
extern s32 D_002A3640[];
extern s32 D_002A3610[];
extern char D_002D9CE8[];
extern "C" s32 func_0016C6D8(s32 kind);
// @decl-end

CNameDBMgr::CNameDBMgr() {
    D_002A35B0 = this;
    memset(m_unk38, 0, 0x28);
    memset(m_unk10, 0, 0x28);
}

CNameDBMgr::~CNameDBMgr() {
    Init();
    D_002A35B0 = 0;
}

INCLUDE_ASM("asm/nonmatchings/CNameDBMgr", func_0016C848);

void CNameDBMgr::Init() {
    m_buf.Func248E00();
    memset(m_unk38, 0, 0x28);
    memset(m_unk10, 0, 0x28);
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

INCLUDE_ASM("asm/nonmatchings/CNameDBMgr", func_0016CBD0);

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
