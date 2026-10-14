#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CPushBuf {
public:
    void Func248E00();
    u8 m_data[0xC];
};
//@sym memset 0x289FB0
#include "libc.h"
class CNameDBMgr {
public:
    void Push16CDC0(s32 kind, const char *name);
    void Init();
    static CNameDBMgr *Create(void *a);
    u8 pad0[0x4];
    CPushBuf m_buf;           // 0x4
    u8 m_unk10[0x28];         // 0x10
    u8 m_unk38[0x28];         // 0x38
};
extern "C" void func_0016CF98(void *p, void *a);

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

INCLUDE_ASM("asm/nonmatchings/CNameDBMgr", __10CNameDBMgr);

INCLUDE_ASM("asm/nonmatchings/CNameDBMgr", func_0016C7D0);

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
