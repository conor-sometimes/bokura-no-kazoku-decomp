#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
struct CMotionRec {
    char m_name[0x10];        // 0x0
    s32 m_id;                 // 0x10
    void *m_data;             // 0x14
    s32 m_unk18;              // 0x18
};
class CMotionTbl {
public:
    void Release();
    int Init(s32 a, s32 b);
    CMotionRec *Find(s32 id);
    void Regist110FD8(s32 cur, s32 *handles, s32 count, s32 lo, s32 hi);
    s32 Load110DC8(const char *path, s32 b);
    s32 m_num;                // 0x0
    CMotionRec *m_recs;       // 0x4
    s32 m_max;                // 0x8
};

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMotionRes.
class CMotionRes {
public:
    CMotionRes();
    virtual ~CMotionRes();

    CMotionTbl m_tbl;         // 0x0
    // vptr 0xC
};

//@sym memset 0x289FB0
#include "libc.h"
extern "C" s32 func_00110B30(CMotionRec *recs, s32 a, s32 b);
extern "C" void *func_00245678(u32 size);

extern void (*D_002B91B0)(void *p);

extern char D_002D3258[], D_002D3260[], D_002D3268[], D_002D3288[], D_002D3290[];
const char *Func24AF10(void *src, const char *key);
const char *Func24AFE8(const char *src, char *buf, s32 a, s32 n);
const char *Func24A570(const char *src, char *buf, const char *a, const char *b);
void *Func248E48(const char *name);
int Func235DE0(const char *fmt, ...) throw();
extern "C" char *func_0024A710(const char *p, s32 *v, s32 def, const char *s1, const char *s2);
extern "C" void func_0024B650(const char *path, s32 a, char *out, s32 b);
extern "C" char *strncpy(char *d, const char *s, unsigned int n);
extern "C" int func_001ECCA8(s32 h);
extern "C" s32 func_001EB920(void *p, s32 i);

extern "C" char *strstr(const char *s, const char *t);
extern "C" unsigned int strlen(const char *s);
extern "C" void func_0022DCE0();
extern "C" void func_0022DD00();
extern "C" void func_0022DC90(const char *dir);
extern "C" void func_0024B7B8(const char *path, char *dir, char *name);
extern "C" s32 func_00249070(const char *path);
extern "C" void func_002490F8();
char *Func24A4C0(const char *name);
extern const char *D_002A03DC, *D_002A03E4;
inline void StrCat(char *d, const char *s) { strcpy(d + strlen(d), s); }
// @decl-end

CMotionRes::CMotionRes() {
    m_tbl.m_recs = 0;
    m_tbl.m_num = 0;
    m_tbl.m_max = 0;
}

CMotionRes::~CMotionRes() {
    m_tbl.Release();
}

extern "C" s32 func_00110B30(CMotionRec *recs, s32 src, s32 key) {
    char buf0[0x100];
    char buf1[0x40];
    char buf2[0x100];
    s32 n;
    CMotionRec *r;
    const char *p;
    if (!key) key = (s32)"MOTION";
    n = 0;
    p = Func24AF10((void *)src, (const char *)key);
    r = recs;
    for (; (p = Func24AFE8(p, buf0, 1, 0x100), *p) || buf0[0]; n++) {
        if (recs) {
            const char *q;
            q = func_0024A710(buf0, &r->m_id, 0, D_002D3258, D_002D3260);
            q = Func24A570(q, buf1, D_002D3258, D_002D3260);
            r->m_data = Func248E48(buf1);
            if (!r->m_data) {
                Func235DE0(D_002D3268, buf1);
            } else {
                while ((q = Func24A570(q, buf2, D_002D3258, D_002D3260), *q) || buf2[0]) {
                    if (strcmp(buf2, D_002D3288) == 0) {
                        r->m_unk18 = 1;
                    } else {
                        Func235DE0(D_002D3290, buf2);
                    }
                }
                func_0024B650(buf1, 0, buf2, 0);
                strncpy(r->m_name, buf2, 0x10);
            }
        }
        r++;
    }
    return n;
}
INCLUDE_RODATA("asm/nonmatchings/CMotionRes", D_002D3258);
INCLUDE_RODATA("asm/nonmatchings/CMotionRes", D_002D3260);
INCLUDE_RODATA("asm/nonmatchings/CMotionRes", D_002D3268);
INCLUDE_RODATA("asm/nonmatchings/CMotionRes", D_002D3288);
INCLUDE_RODATA("asm/nonmatchings/CMotionRes", D_002D3290);
INCLUDE_RODATA("asm/nonmatchings/CMotionRes", D_002D32B0);
INCLUDE_RODATA("asm/nonmatchings/CMotionRes", D_002D32B8);
INCLUDE_RODATA("asm/nonmatchings/CMotionRes", D_002D32C0);

int CMotionTbl::Init(s32 a, s32 b) {
    Release();
    m_num = func_00110B30(0, a, b);
    m_recs = (CMotionRec *)func_00245678(m_num * sizeof(CMotionRec));
    memset(m_recs, 0, m_num * sizeof(CMotionRec));
    func_00110B30(m_recs, a, b);
    m_max = 0;
    for (s32 i = 0; i < m_num; i++) {
        s32 v = m_recs[i].m_id + 1;
        if (v < m_max) v = m_max;
        m_max = v;
    }
    return 1;
}

s32 CMotionTbl::Load110DC8(const char *path, s32 b) {
    char b0[0x100];
    char b1[0x100];
    char *text = 0;
    s32 ok = 0;
    func_0022DCE0();
    if (strstr(path, D_002A03DC)) {
        func_0024B7B8(path, b0, b1);
        func_0022DC90(b0);
        text = Func24A4C0(b1);
        if (!text) {
            Func235DE0(D_002D3268, path);
        } else {
            ok = Init((s32)text, b);
        }
    } else if (strstr(path, D_002A03E4)) {
        if (!func_00249070(path)) {
            Func235DE0(D_002D3268, path);
        } else {
            func_0024B650(path, 0, b0, 0);
            StrCat(b0, D_002A03DC);
            ok = Load110DC8(b0, b);
            func_002490F8();
        }
    } else {
        Func235DE0("*** unknown model file path %s\n", path);
    }
    if (text) D_002B91B0(text);
    func_0022DD00();
    return ok;
}

void CMotionTbl::Release() {
    if (m_recs == 0) return;
    for (s32 i = 0; i < m_num; i++) {
        if (m_recs[i].m_data) D_002B91B0(m_recs[i].m_data);
    }
    operator delete(m_recs);
    m_recs = 0;
    m_num = 0;
}

void CMotionTbl::Regist110FD8(s32 cur, s32 *handles, s32 count, s32 lo, s32 hi) {
    s32 i;
    for (i = 0; i < m_num; i++) {
        CMotionRec *rec = &m_recs[i];
        s32 id = rec->m_id;
        if (!rec->m_data) continue;
        if (id < 0) continue;
        if (count - 1 < id) continue;
        if (lo >= 0 && lo < hi) {
            if (id < lo) continue;
            if (hi < id) continue;
        }
        s32 *h = (s32 *)(id * 4 + (u32)handles);
        if (*h >= 0) {
            Func235DE0("warning : over write XMN [%d]=%d\n", id, *h);
            func_001ECCA8(*h);
            *h = -1;
        }
        s32 r = func_001EB920(rec->m_data, cur);
        *h = r;
        if (r < 0) {
            Func235DE0("*** failed to regist XMN (index=%d)\n", id);
        }
    }
}

CMotionRec *CMotionTbl::Find(s32 id) {
    for (s32 i = 0; i < m_num; i++) {
        CMotionRec *r = &m_recs[i];
        if (r->m_id < 0) continue;
        if (id < 0 || r->m_id == id) return r;
    }
    return 0;
}
