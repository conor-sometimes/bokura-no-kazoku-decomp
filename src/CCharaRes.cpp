#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CCharaResRec {
public:
    s32 m_id;                 // 0x0
    s32 m4;                   // 0x4
    s32 m8;                   // 0x8
    s32 mC;                   // 0xC
    s32 m10;                  // 0x10
    s32 m14;                  // 0x14
    s32 m18;                  // 0x18
    s32 m1C;                  // 0x1C
    s32 m20;                  // 0x20
    s32 m24;                  // 0x24
    u8 pad28[0x4];
    s32 m2C;                  // 0x2C
    s32 m30;                  // 0x30
};
class CCharaResData {
public:
    s32 m_num;                // 0x0
    CCharaResRec *m_recs;     // 0x4
};
#include "CList.h"
// Owned parts deleted through their virtual destructors (vptr at 0x1C / 0xC).
class CCharaResPart14 {
public:
    virtual ~CCharaResPart14();
    u8 pad0[0x1C];
};
class CCharaResPart18 : public CListTag {
public:
    virtual ~CCharaResPart18();
};
class CFaceRes {
public:
    CFaceRes();
    u8 pad0[0x54];
    virtual ~CFaceRes();
};
extern "C" void func_0010F6F8(CFaceRes *p);
class CCharaRes {
public:
    CCharaRes();
    virtual ~CCharaRes();
    void Func112A80();
    void Init1121F0();
    s32 GetCurFlags();
    s32 GetCur8();
    s32 GetCurC();
    s32 Get44(s32 i);
    s32 Get48(s32 i);
    char *GetName112030(s32 i);
    int Func1120A0();
    int Set112B60(CCharaResData *d, s32 id);
    void Release112C00();
    void Func112E88(s32 v);
    int Draw1120F8();
    s32 Load112710(const char *path);
    s32 Parse1122C0(char *text);
    s32 Attach112C40(struct CCharaMotMap *m);

    CCharaResData *m_data;    // 0x0
    s32 m_unk4[4];            // 0x4
    CCharaResPart14 *m_unk14; // 0x14
    CCharaResPart18 *m_unk18; // 0x18
    CFaceRes *m_unk1C;        // 0x1C
    char m_unk20;             // 0x20
    u8 pad21[0x1F];
    s32 m_cur;                // 0x40
    s32 *m_unk44;             // 0x44
    s32 *m_unk48;             // 0x48
    s8 *m_unk4C;              // 0x4C
    s32 m_unk50;              // 0x50
    u8 pad54[0xC];
    s32 m_unk60;              // 0x60
    s32 m_unk64;              // 0x64
    s32 m_unk68;              // 0x68
    s32 m_unk6C;              // 0x6C
    s32 m_unk70;              // 0x70
    s32 m_unk74;              // 0x74
    s32 m_unk78;              // 0x78
    f32 m_unk7C;              // 0x7C
    s32 m_unk80;              // 0x80
    s32 m_unk84;              // 0x84
    s32 m_unk88;              // 0x88
    s32 m_unk8C;              // 0x8C
    s32 m_unk90;              // 0x90
    s32 m_unk94;              // 0x94
    s32 m_unk98;              // 0x98
    s32 m_unk9C;              // 0x9C
    s32 m_unkA0;              // 0xA0
    s32 m_unkA4;              // 0xA4
    s32 m_unkA8;              // 0xA8
    s32 m_unkAC;              // 0xAC
    s32 m_unkB0;              // 0xB0
    s32 m_unkB4;              // 0xB4
    s32 m_unkB8;              // 0xB8
};
extern char D_002D3400[];
extern "C" char *func_00111128(void *p);

void Func225088();
int Func2250C0();
void Func227DC8(long a, s32 b, s32 c);
extern "C" u64 func_0023AA40(s32 h);
extern "C" long func_0023BD80(s32 h);
extern "C" void func_00227BF0(u64 a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern "C" int func_001ECCA8(s32 h);

struct CCharaMotEnt {
    u8 pad0[0x10];
    s32 m10;                  // 0x10
    s32 m14;                  // 0x14
    u8 pad18[0x4];
};
struct CCharaMotMap {
    s32 m_num;                // 0x0
    CCharaMotEnt *m_ents;     // 0x4
};
int Func235DE0(const char *fmt, ...) throw();
void Func10ADD0();
void ClearFunc1EB828And1EB838();
extern "C" s32 func_002462B0();
extern "C" s32 func_001EB920(s32 p, s32 i);

//@sym Parse1122C0__9CCharaResPc 0x1122C0
extern "C" char *strstr(const char *s, const char *t);
extern "C" char *strncpy(char *d, const char *s, unsigned int n);
extern "C" int strncmp(const char *a, const char *b, unsigned int n);
extern "C" unsigned int strlen(const char *s);
extern "C" char *strcpy(char *d, const char *s);
extern "C" int sprintf(char *buf, const char *fmt, ...);
inline void StrCat(char *d, const char *s) { strcpy(d + strlen(d), s); }
extern "C" void func_0022DCE0();
extern "C" void func_0022DD00();
extern "C" void func_0022DC90(const char *dir);
extern "C" void func_0024B7B8(const char *path, char *dir, char *name);
extern "C" char *func_0024A3F8(s32 n);
extern "C" void func_0024B650(const char *path, s32 a, char *out, s32 b);
char *Func24A4C0(const char *name);
const char *Func24A570(const char *src, char *buf, const char *a, const char *b);
s32 Func249248(void *buf);
void Func249348();
extern const char *D_002A041C, *D_002A0420, *D_002A0424, *D_002A0428, *D_002A042C, *D_002A0430;
extern char D_002D3460[], D_002D3468[];
extern void (*D_002B91B0)(void *p);

class CModelRes {
public:
    CModelRes();
    virtual ~CModelRes();
    s32 Load(s32 a, s32 b);

    u8 pad0[0xC];
    s32 m_unkC;               // 0xC
    u8 pad10[0x4];
    s32 m_unk14;              // 0x14
    s32 m_unk18;              // 0x18
};
class CMotionRes {
public:
    CMotionRes();
    virtual ~CMotionRes();
    u8 pad0[0xC];
};
class CMotionTbl {
public:
    int Init(s32 a, s32 b);
    char *Find(s32 id);
};
struct CFaceResFields {
    u8 pad0[0x34];
    s32 m34, m38, m3C, m40;
    s32 m44, m48, m4C, m50;
};
extern s32 D_002A03F4;
extern const char *D_002A03F8, *D_002A03FC, *D_002A0400, *D_002A0404, *D_002A0408, *D_002A040C;
extern const char *D_002A0410, *D_002A0414, *D_002A0418;
const char *Func24AF10(void *src, const char *key);
extern "C" s32 func_0024B368(const char *src, const char *key, s32 def);
extern "C" s32 func_0024B190(const char *src, const char *key, char *buf, const char *fmt, s32 n);
extern "C" char *func_0024A778(char *p, f32 *v, f32 def, const char *s1, const char *s2);
extern "C" char *func_0024A710(char *p, s32 *v, s32 def, const char *s1, const char *s2);
extern "C" f32 func_0024B3B8(const char *src, const char *key, f32 def);
extern "C" void func_00247110();
extern "C" s32 func_00247140();
extern "C" void func_0010F348(CFaceRes *p, char *text);
inline void SetFace1(CFaceRes *p, s32 a, s32 b, s32 c, s32 d) {
    CFaceResFields *f = (CFaceResFields *)p;
    f->m34 = a;
    f->m38 = b;
    f->m3C = c;
    f->m40 = d;
}
inline void SetFace2(CFaceRes *p, s32 *v) {
    CFaceResFields *f = (CFaceResFields *)p;
    f->m44 = v[0];
    f->m48 = v[1];
    f->m4C = v[2];
    f->m50 = v[3];
}
// @decl-end

CCharaRes::CCharaRes() {
    m_unk1C = new CFaceRes;
    m_unkA4 = -1;
    m_unk8C = -1;
    m_unkB4 = 0;
    Init1121F0();
}

CCharaRes::~CCharaRes() {
    Func112A80();
    if (m_unk1C) delete m_unk1C;
}

s32 CCharaRes::GetCurFlags() {
    if (m_data == 0 || m_cur < 0) {
        return -1;
    }
    return m_data->m_recs[m_cur].m4 & 0xF;
}

s32 CCharaRes::GetCur8() {
    if (m_data == 0 || m_cur < 0) {
        return -1;
    }
    return m_data->m_recs[m_cur].m8;
}

s32 CCharaRes::Get44(s32 i) {
    if (i < 0 || i > m_unk50 - 1 || m_unk44 == 0) {
        return -1;
    }
    return m_unk44[i];
}

s32 CCharaRes::Get48(s32 i) {
    if (i < 0 || i > m_unk50 - 1 || m_unk48 == 0) {
        return 0;
    }
    return m_unk48[i];
}

s32 CCharaRes::GetCurC() {
    if (m_data == 0 || m_cur < 0) {
        return -1;
    }
    return m_data->m_recs[m_cur].mC;
}

INCLUDE_RODATA("asm/nonmatchings/CCharaRes", D_002D3400);
INCLUDE_RODATA("asm/nonmatchings/CCharaRes", D_002D3408);
INCLUDE_RODATA("asm/nonmatchings/CCharaRes", D_002D3410);
INCLUDE_RODATA("asm/nonmatchings/CCharaRes", D_002D3418);
INCLUDE_RODATA("asm/nonmatchings/CCharaRes", D_002D3420);
INCLUDE_RODATA("asm/nonmatchings/CCharaRes", D_002D3428);
INCLUDE_RODATA("asm/nonmatchings/CCharaRes", D_002D3430);
INCLUDE_RODATA("asm/nonmatchings/CCharaRes", D_002D3438);
INCLUDE_RODATA("asm/nonmatchings/CCharaRes", D_002D3440);
INCLUDE_RODATA("asm/nonmatchings/CCharaRes", D_002D3448);
INCLUDE_RODATA("asm/nonmatchings/CCharaRes", D_002D3450);
INCLUDE_RODATA("asm/nonmatchings/CCharaRes", D_002D3458);
char *CCharaRes::GetName112030(s32 i) {
    if (i >= 0 && !(m_unk50 - 1 < i) && m_unk48) {
        s32 k = m_unk4C[i];
        if (k >= 0) {
            char *r = ((CMotionTbl *)m_unk4[k])->Find(i);
            if (r) return r;
        }
    }
    return D_002D3400;
}

int CCharaRes::Func1120A0() {
    if (!m_data) return 0;
    if (m_cur < 0) return 0;
    if (m_unk8C >= 0 && m_data->m_recs[m_cur].m10) return 1;
    return 0;
}

int CCharaRes::Draw1120F8() {
    Func225088();
    if (m_data && m_cur >= 0 && m_unk8C >= 0) {
        CCharaResRec *r = &m_data->m_recs[m_cur];
        if (r->m10) {
            u64 a = func_0023AA40(m_unk8C);
            long b = func_0023BD80(m_unk8C);
            a = (a & ~((u64)0x3F << 32)) | ((u64)(r->m18 & 0x3F) << 32);
            func_00227BF0(a, 0, 0, r->m1C, r->m20, r->m14);
            if (r->m2C > 0) {
                Func227DC8(b, r->m2C * r->m30, r->m24);
            }
        }
    }
    return Func2250C0();
}

INCLUDE_ASM("asm/nonmatchings/CCharaRes", Init1121F0__9CCharaRes);

INCLUDE_RODATA("asm/nonmatchings/CCharaRes", D_002D3460);
INCLUDE_RODATA("asm/nonmatchings/CCharaRes", D_002D3468);
INCLUDE_RODATA("asm/nonmatchings/CCharaRes", D_002D3470);
INCLUDE_RODATA("asm/nonmatchings/CCharaRes", D_002D3478);
INCLUDE_RODATA("asm/nonmatchings/CCharaRes", D_002D3480);
INCLUDE_RODATA("asm/nonmatchings/CCharaRes", D_002D3488);
s32 CCharaRes::Parse1122C0(char *text) {
    char buf[0x100];
    s32 *v;
    const char *p;
    char *q;
    s32 i;
    Func112A80();
    m_unkA4 = D_002A03F4++;
    p = Func24AF10(text, D_002A03F8);
    if (*p) {
        m_unk50 = func_0024B368(p, D_002A03FC, 0x30);
        func_0024B190(p, D_002A0400, buf, D_002D3400, 0x100);
        q = func_0024A778(buf, (f32 *)&m_unk70, 0.0f, D_002D3460, D_002D3468);
        q = func_0024A778(q, (f32 *)&m_unk74, 0.0f, D_002D3460, D_002D3468);
        func_0024B190(p, D_002A0404, buf, D_002D3400, 0x100);
        q = func_0024A778(buf, (f32 *)&m_unk70, 0.0f, D_002D3460, D_002D3468);
        q = func_0024A778(q, (f32 *)&m_unk74, 0.0f, D_002D3460, D_002D3468);
        m_unk80 = func_0024B368(p, D_002A0408, -1);
        m_unk84 = func_0024B368(p, D_002A040C, -1);
        m_unk88 = func_0024B368(p, D_002A0410, -1);
        func_0024B190(p, D_002A0414, buf, D_002D3400, 0x100);
        v = &m_unk90;
        q = func_0024A710(buf, &m_unk90, 0, D_002D3460, D_002D3468);
        q = func_0024A710(q, &m_unk94, 0, D_002D3460, D_002D3468);
        q = func_0024A710(q, &m_unk98, 0x50, D_002D3460, D_002D3468);
        q = func_0024A710(q, &m_unk9C, 0x50, D_002D3460, D_002D3468);
        *(f32 *)&m_unkA0 = func_0024B3B8(p, D_002A0418, 0.0f);
    } else {
        v = &m_unk90;
    }
    m_unk44 = new s32[m_unk50];
    m_unk48 = new s32[m_unk50];
    m_unk4C = new s8[m_unk50];
    for (i = 0; i < m_unk50; i++) {
        m_unk44[i] = -1;
        m_unk48[i] = 0;
        m_unk4C[i] = -1;
    }
    CModelRes *mdl = new CModelRes;
    m_unk14 = (CCharaResPart14 *)mdl;
    CMotionRes *mot = new CMotionRes;
    m_unk18 = (CCharaResPart18 *)mot;
    if (m_unk8C >= 0) {
        ((CModelRes *)m_unk14)->m_unkC = m_unk8C;
    }
    ((CModelRes *)m_unk14)->Load((s32)text, (s32)D_002A041C);
    m_unkA8 += ((CModelRes *)m_unk14)->m_unk14;
    m_unkAC += ((CModelRes *)m_unk14)->m_unk18;
    func_00247110();
    ((CMotionTbl *)m_unk18)->Init((s32)text, (s32)D_002A0420);
    m_unkB0 += func_00247140();
    Set112B60((CCharaResData *)m_unk14, -1);
    func_00247110();
    if (m_data && m_cur >= 0 && m_unk8C >= 0) {
        CCharaResRec *r = &m_data->m_recs[m_cur];
        SetFace1(m_unk1C, r->m14, r->m18, r->m1C, r->m20);
    }
    SetFace2(m_unk1C, v);
    func_0010F348(m_unk1C, text);
    m_unkAC += func_00247140();
    Attach112C40((CCharaMotMap *)m_unk18);
    return 1;
}

s32 CCharaRes::Load112710(const char *path) {
    char b0[0x100];
    char b1[0x100];
    char b2[0x100];
    char b3[0x100];
    s32 ok = 0;
    char *text = 0;
    func_0022DCE0();
    if (strstr(path, D_002A0424)) {
        func_0024B7B8(path, b0, b1);
        func_0022DC90(b0);
        text = Func24A4C0(b1);
        if (!text) {
            Func235DE0("*** failed to load '%s'\n", path);
            goto end;
        }
        ok = Parse1122C0(text);
        if (ok == 1) strncpy(&m_unk20, b1, 0x20);
        if (strncmp(&m_unk20 + 3, "5_22", 4) == 0) m_unkB8 = 1;
    } else if (strstr(path, D_002A0428)) {
        const char *p;
        s32 i;
        text = func_0024A3F8(0x400);
        if (!text) {
            Func235DE0("*** failed to make text '%s'", path);
            goto end;
        }
        p = Func24A570(path, b0, D_002D3460, D_002D3468);
        i = 0;
        func_0024B7B8(b0, b2, b3);
        sprintf(text, "[%s]\n0,%s\n[%s]\n", D_002A041C, b3, D_002A0420);
        while ((p = Func24A570(p, b0, D_002D3460, D_002D3468), *p) || b0[0]) {
            sprintf(b1, "%d,%s\n", i, b0);
            StrCat(text, b1);
            i++;
        }
        func_0022DC90(b2);
        ok = Parse1122C0(text);
        if (ok == 1) strncpy(&m_unk20, b3, 0x20);
    } else if (strstr(path, D_002A042C) || strstr(path, D_002A0430)) {
        if (!Func249248((void *)path)) {
            Func235DE0("*** failed to load '%s'\n", path);
            goto end;
        }
        func_0024B650(path, 0, b0, 0);
        StrCat(b0, D_002A0424);
        ok = Load112710(b0);
        if (!ok) {
            func_0024B650(path, 0, b0, 0);
            StrCat(b0, D_002A0428);
            ok = Load112710(b0);
        }
        if (ok) strncpy(&m_unk20, b0, 0x20);
        Func249348();
    } else {
        Func235DE0("*** unknown file path %s\n", path);
    }
end:
    if (text) D_002B91B0(text);
    func_0022DD00();
    return ok;
}

void CCharaRes::Func112A80() {
    func_0010F6F8(m_unk1C);
    Func112E88(0);
    Release112C00();
    if (m_unk44) {
        delete[] m_unk44;
        m_unk44 = 0;
    }
    if (m_unk48) {
        delete[] m_unk48;
        m_unk48 = 0;
    }
    if (m_unk4C) {
        delete[] m_unk4C;
        m_unk4C = 0;
    }
    if (m_unk18) {
        delete m_unk18;
        m_unk18 = 0;
    }
    if (m_unk14) {
        delete m_unk14;
        m_unk14 = 0;
    }
    Init1121F0();
}

int CCharaRes::Set112B60(CCharaResData *d, s32 id) {
    s32 i;
    Release112C00();
    m_data = d;
    for (i = 0; i < m_data->m_num; i++) {
        if (id < 0 || (m_data->m_recs[i].m_id == id && m_data->m_recs[i].m8 >= 0)) {
            m_cur = i;
            break;
        }
    }
    return 1;
}

void CCharaRes::Release112C00() {
    Func112E88(0);
    if (m_data) {
        m_data = 0;
        m_cur = -1;
    }
}

s32 CCharaRes::Attach112C40(CCharaMotMap *m) {
    s32 cur = GetCur8();
    s32 slot;
    s32 i;
    if (cur < 0) return 0;
    i = 0;
    slot = -1;
    for (; i < 4; i++) {
        if (m_unk4[i] == (s32)m) return 1;
        if (m_unk4[i] == 0 && slot < 0) slot = i;
    }
    if (slot < 0) {
        Func235DE0("*** overflow attach motion map\n");
        return 0;
    }
    m_unk4[slot] = (s32)m;
    Func10ADD0();
    for (i = 0; i < m->m_num; i++) {
        CCharaMotEnt *e = &m->m_ents[i];
        if (!e->m14) continue;
        if (e->m10 < 0) continue;
        if (m_unk50 - 1 < e->m10) continue;
        if (m_unk44[e->m10] >= 0) {
            Func235DE0("*** over write motion [%d]=%d\n", e->m10, m_unk44[e->m10]);
            func_001ECCA8(m_unk44[e->m10]);
            m_unk44[e->m10] = -1;
            m_unk48[e->m10] = 0;
            m_unk4C[e->m10] = -1;
        }
        m_unk48[e->m10] = e->m14;
        if (m_unkB4 == 0 && func_002462B0() > 0x8000) {
            s32 r = func_001EB920(e->m14, cur);
            m_unk44[e->m10] = r;
            if (r < 0) {
                Func235DE0("*** failed to regist XMN [%d]=%d\n", e->m10, -1);
                continue;
            }
        }
        m_unk4C[e->m10] = slot;
    }
    ClearFunc1EB828And1EB838();
    return 1;
}

void CCharaRes::Func112E88(s32 v) {
    if (v != 0) {
        s32 k;
        s32 j;
        for (k = 0; k < 4; k++) {
            if (m_unk4[k] == v) break;
        }
        if (k == 4) return;
        for (j = 0; j < m_unk50; j++) {
            if (m_unk4C[j] == k) {
                if (m_unk44[j] >= 0) {
                    func_001ECCA8(m_unk44[j]);
                    m_unk44[j] = -1;
                }
                m_unk48[j] = 0;
                m_unk4C[j] = -1;
            }
        }
        m_unk4[k] = 0;
    } else {
        s32 i;
        for (i = 0; i < 4; i++) {
            if (m_unk4[i]) Func112E88(m_unk4[i]);
        }
    }
}
