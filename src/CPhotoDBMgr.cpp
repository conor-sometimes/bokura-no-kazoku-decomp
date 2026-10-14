#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CPushBuf {
public:
    void Func248E00();
    int Func248EB0();

    u8 m_data[0xC];
};
class CPhotoDBMgrSub1705B0 {
public:
    void Init();
    void Clear();

    u8 pad0[0x4];
    CPushBuf m_buf;           // 0x4
    u8 pad10[0x8];
    s32 m_unk18;              // 0x18
    s32 m_unk1C;              // 0x1C
    s32 m_unk20;              // 0x20
};

extern "C" void func_00171D18(void *p);
class CResortDBMgr {
public:
    static CResortDBMgr *Create();
};

struct CPhotoRec {
    const char *m_name;       // 0x0
    s32 m_id;                 // 0x4
    u8 pad8[0x18];
};
template <class T> inline T *FindById(T *tbl, s32 n, s32 id) {
    for (s32 i = 0; i < n; i++, tbl++) {
        if (tbl->m_id == id) {
            return tbl;
        }
    }
    return 0;
}
class CPhotoDBMgrSub1714C8 {
public:
    CPhotoRec *Find(s32 id);
    int Parse170758(const char *text);
    u8 pad0[0x4];
    u8 m_buf[0xC];            // 0x4
    u8 pad10[0x8];
    CPhotoRec *m_table;       // 0x18
    s32 m_count;              // 0x1C
    const char *m_unk20;      // 0x20
};

//@sym memset 0x289FB0
//@sym strcpy 0x28B2D4
#include "libc.h"
struct CPhotoNameRec {
    u8 pad0[0x8];
    const char *m_names[1];   // 0x8
};
extern "C" CPhotoNameRec *func_00171980(void *tbl, s32 n, s32 id);
class CPhotoDBMgrSub171448 {
public:
    int GetName(char *out, s32 id, s32 idx);
    u8 pad0[0x10];
    void *m_unk10;            // 0x10
    s32 m_unk14;              // 0x14
};

extern "C" s32 func_0024A570(void *a, char *buf, const char *s1, const char *s2);
extern "C" char *func_0024A710(char *p, s32 *v, s32 k, const char *s1, const char *s2);
extern char D_002D9F90[];
extern char D_002D9F98[];
extern char D_002D9FC0[];

s32 Func170900(void *a, s32 *b, s32 *c);
extern "C" char *func_0024A778(char *p, f32 *v, f32 def, const char *s1, const char *s2);
struct CPhotoPosRec {
    s32 m0;
    s32 m4;
    f32 m8;
    f32 mC;
};
struct CPhotoPosTbl {
    u8 pad0[0x18];
    CPhotoPosRec *m_recs;     // 0x18
};
class CPhotoDBMgrSub171378 {
public:
    int Parse(CPhotoPosTbl *tbl, s32 i, void *src);
};

extern char D_002D9F88[];
extern char D_002D9FC8[];
extern char D_002D9FD0[];
extern "C" const char *func_0024AF10(const char *s, const char *key);
extern "C" s32 func_0024B040(const char *s, s32 k);
extern "C" const char *func_0024AFE8(const char *s, char *buf, s32 k, s32 size);
extern "C" void *func_00248CC8(void *buf, s32 size, s32 a, s32 b);
extern "C" char *func_00248DA8(void *buf);
extern "C" const char *func_00248DC0(void *buf);
extern "C" char *func_0024A6B0(char *s, char *out, const char *def, const char *a, const char *b);
void Func235DE0(const char *fmt, ...);
struct CPhotoStrRec {
    s32 m0;
    s32 m4;
    const char *m_str[2];
};
class CPhotoDBMgrSub1709A0 {
public:
    int Parse(const char *text);
    u8 pad0[0x4];
    u8 m_buf[0xC];            // 0x4
    CPhotoStrRec *m_recs;     // 0x10
    s32 m_num;                // 0x14
};

extern char D_002D9F60[];
extern char D_002D9F68[];
extern char D_002D9F80[];
extern char D_002D9FA0[];
extern char D_002D9FB8[];
extern "C" void func_0024B190(const char *s, const char *key, char *out, const char *def, s32 size);
extern "C" s32 func_0024A7D8(const char *s, const char *a, const char *b);
extern "C" s32 func_00145808(const char *name);

struct CPhotoCamRec {
    s32 m0;
    s32 m4;
    u8 pad8[0x8];
    f32 m_from[4];            // 0x10
    f32 m_to[4];              // 0x20
    f32 m30;                  // 0x30
    f32 m34;                  // 0x34
    u8 pad38[0x8];
};
struct CPhotoCamTbl {
    u8 pad0[0x10];
    CPhotoCamRec *m_recs;     // 0x10
};
class CPhotoDBMgrSub1711A0 {
public:
    int Parse(CPhotoCamTbl *tbl, s32 i, void *src);
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CPhotoDBMgr", func_001704F8);

INCLUDE_ASM("asm/nonmatchings/CPhotoDBMgr", func_00170538);

void CPhotoDBMgrSub1705B0::Clear() {
    m_unk18 = 0;
    m_unk1C = 0;
    m_unk20 = 0;
}

INCLUDE_ASM("asm/nonmatchings/CPhotoDBMgr", func_001705C0);

int CPhotoDBMgrSub1714C8::Parse170758(const char *text) {
    char line[256];
    const char *p = func_0024AF10(text, D_002D9F60);
    if (*p == 0) {
        Func235DE0(D_002D9F68);
        return 0;
    }
    func_0024B190(p, D_002D9F80, line, D_002D9F88, 0x100);
    m_count = func_0024A7D8(line, D_002D9F90, D_002D9F98);
    m_table = (CPhotoRec *)func_00248CC8(m_buf, m_count * sizeof(CPhotoRec), 1, 1);
    const char *q = line;
    for (s32 i = 0; i < m_count; i++) {
        CPhotoRec *r = &m_table[i];
        q = (const char *)func_0024A570((void *)q, func_00248DA8(m_buf), D_002D9F90, D_002D9F98);
        r->m_name = func_00248DC0(m_buf);
        r->m_id = func_00145808(r->m_name);
        if (r->m_id < 0) Func235DE0(D_002D9FA0, r->m_name);
    }
    func_0024B190(p, D_002D9FB8, func_00248DA8(m_buf), D_002D9F88, 0x100);
    m_unk20 = func_00248DC0(m_buf);
    return 1;
}

s32 Func170900(void *a, s32 *b, s32 *c) {
    char buf[256];
    s32 r = func_0024A570(a, buf, D_002D9F90, D_002D9F98);
    func_0024A710(func_0024A710(buf, b, 0, D_002D9FC0, D_002D9F98), c, -1, D_002D9FC0, D_002D9F98);
    return r;
}

int CPhotoDBMgrSub1709A0::Parse(const char *text) {
    char line[256];
    const char *p = func_0024AF10(text, D_002D9FC8);
    if (*p == 0) {
        Func235DE0(D_002D9FD0);
        return 0;
    }
    m_num = func_0024B040(p, 1);
    m_recs = (CPhotoStrRec *)func_00248CC8(m_buf, m_num * sizeof(CPhotoStrRec), 1, 1);
    for (s32 i = 0; i < m_num; i++) {
        CPhotoStrRec *r = &m_recs[i];
        p = func_0024AFE8(p, line, 1, 0x100);
        char *q = (char *)Func170900(line, &r->m0, &r->m4);
        r->m_str[0] = D_002D9F88;
        for (s32 k = 0; k < 2; k++) {
            q = func_0024A6B0(q, func_00248DA8(m_buf), r->m_str[0], D_002D9F90, D_002D9F98);
            r->m_str[k] = func_00248DC0(m_buf);
        }
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/CPhotoDBMgr", func_00170B18);

INCLUDE_ASM("asm/nonmatchings/CPhotoDBMgr", func_00170CD8);

INCLUDE_ASM("asm/nonmatchings/CPhotoDBMgr", func_00170E18);

int CPhotoDBMgrSub1711A0::Parse(CPhotoCamTbl *tbl, s32 i, void *src) {
    CPhotoCamRec *r = &tbl->m_recs[i];
    char *p = (char *)Func170900(src, &r->m0, &r->m4);
    p = func_0024A778(p, &r->m_from[0], 0.0f, D_002D9F90, D_002D9F98);
    p = func_0024A778(p, &r->m_from[1], 0.0f, D_002D9F90, D_002D9F98);
    p = func_0024A778(p, &r->m_from[2], 0.0f, D_002D9F90, D_002D9F98);
    p = func_0024A778(p, &r->m_from[3], 0.0f, D_002D9F90, D_002D9F98);
    p = func_0024A778(p, &r->m30, 1.0f, D_002D9F90, D_002D9F98);
    p = func_0024A778(p, &r->m_to[0], r->m_from[0], D_002D9F90, D_002D9F98);
    p = func_0024A778(p, &r->m_to[1], r->m_from[1], D_002D9F90, D_002D9F98);
    p = func_0024A778(p, &r->m_to[2], r->m_from[2], D_002D9F90, D_002D9F98);
    p = func_0024A778(p, &r->m_to[3], r->m_from[3], D_002D9F90, D_002D9F98);
    func_0024A778(p, &r->m34, r->m30, D_002D9F90, D_002D9F98);
    r->m_from[3] /= 360.0f;
    r->m_to[3] /= 360.0f;
    return 1;
}

int CPhotoDBMgrSub171378::Parse(CPhotoPosTbl *tbl, s32 i, void *src) {
    CPhotoPosRec *r = &tbl->m_recs[i];
    char *p = (char *)Func170900(src, &r->m0, &r->m4);
    p = func_0024A778(p, &r->m8, 1.0f, D_002D9F90, D_002D9F98);
    func_0024A778(p, &r->mC, 1.0f, D_002D9F90, D_002D9F98);
    return 1;
}

void CPhotoDBMgrSub1705B0::Init() {
    m_buf.Func248E00();
    Clear();
}

int CPhotoDBMgrSub171448::GetName(char *out, s32 id, s32 idx) {
    memset(out, 0, 0x20);
    CPhotoNameRec *r = func_00171980(m_unk10, m_unk14, id);
    if (r) strcpy(out, r->m_names[idx]);
    return 1;
}

CPhotoRec *CPhotoDBMgrSub1714C8::Find(s32 id) {
    for (s32 i = 0; i < m_count; i++) {
        if (m_table[i].m_id == id) return &m_table[i];
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/CPhotoDBMgr", func_00171510);

INCLUDE_ASM("asm/nonmatchings/CPhotoDBMgr", func_00171838);

INCLUDE_ASM("asm/nonmatchings/CPhotoDBMgr", func_00171980);

INCLUDE_ASM("asm/nonmatchings/CPhotoDBMgr", func_00171A58);

INCLUDE_ASM("asm/nonmatchings/CPhotoDBMgr", func_00171B30);

INCLUDE_ASM("asm/nonmatchings/CPhotoDBMgr", func_00171C08);

CResortDBMgr *CResortDBMgr::Create() {
    CResortDBMgr *p = (CResortDBMgr *)operator new(0x30);
    func_00171D18(p);
    return p;
}
