#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CPushBuf {
public:
    void Func248E00();
    int Func248EB0();

    u8 m_data[0xC];
};
class CGameDBRec8 {
public:
    s32 m_id;                 // 0x0
    s32 m4;                   // 0x4
};
class CGameDBRec14 {
public:
    s32 m_id;                 // 0x0
    u8 pad4[0x10];
};
class CGameDBRec1C {
public:
    s32 m_id;                 // 0x0
    u8 pad4[0x18];
};
class CGameDBRec20 {
public:
    s32 m_id;                 // 0x0
    s32 m4;                   // 0x4
    char *m8;                 // 0x8
    u8 padC[0x14];
};
class CGameDBRec24 {
public:
    s32 m_id;                 // 0x0
    u8 pad4[0x20];
};
class CGameDBRec28 {
public:
    s32 m_id;                 // 0x0
    u8 pad4[0x24];
};
class CGameDBRec34 {
public:
    s32 m_id;                 // 0x0
    u8 pad4[0x30];
};
class CGameDBRec48 {
public:
    s32 m_id;                 // 0x0
    u8 pad4[0x44];
};
class CGameDBRec5C {
public:
    s32 m_id;                 // 0x0
    u8 pad4[0x58];
};
class CGameDBBits {
public:
    s32 m0;                   // 0x0
    s32 m_bits[5];            // 0x4
};
class CGameDBRec74 {
public:
    s32 m_id;                 // 0x0
    const char *m_names[13];  // 0x4
    u8 pad38[0x3C];
};
class CGameDBRecB0 {
public:
    s32 m_id;                 // 0x0
    u8 pad4[0x8];
    s32 mC;                   // 0xC
    u8 pad10[0xA0];
};
class CGameDBRec24b {
public:
    u8 data[0x24];
};
class CGameDBRec0C {
public:
    s32 m0;                   // 0x0
    CGameDBRec24b *m4;        // 0x4
    s32 m8;                   // 0x8
};
class CGameDBRec4C {
public:
    s32 m0;                   // 0x0
    s32 m4;                   // 0x4
    s32 m8[17];               // 0x8
};
class CGameDBItem14 {
public:
    s32 m0;                   // 0x0
    u8 pad4[0x10];
};
class CGameDBChara {
public:
    char *m_name;             // 0x0
    s32 m4;                   // 0x4
    CGameDBItem14 *m8;        // 0x8
    s32 mC;                   // 0xC
    u8 pad10[0xCF8];
    u8 mD08[0x14];            // 0xD08
    u8 mD1C[0x14];            // 0xD1C
    s32 mD30;                 // 0xD30
    s32 mD34;                 // 0xD34
    s32 mD38;                 // 0xD38
};
class CFlagWork {
public:
    int Func1091B0(s32 id);
};
extern CFlagWork *D_002A26E4;
class CGameDBMgr {
public:
    s32 ParseTable148D70(const char ***out, const char *text, const char *key, s32 ncol);
    s32 Collect14BC20(s32 *out, s32 max);
    int TestBits14F478(s32 id);
    s32 Find20(s32 id);
    const char *GetName248(u32 a, s32 b);
    s32 FindType8();
    s32 FindType2();
    CGameDBRec24b *Get240(s32 i, s32 j);
    s32 GetNum240(s32 i);
    s32 Get150630(s32 a, s32 b, s32 c, s32 d);
    s32 Get1505E0(s32 a, s32 b, s32 c, s32 d);
    s32 Get150590(s32 a, s32 b, s32 c, s32 d);
    s32 Get150550(s32 a, s32 b, s32 c);
    s32 Func150348(s32 *out, s32 a, s32 b, s32 c, s32 d);
    s32 Func14ECD0(s32 key, s32 idx);
    s32 Func14EC50(s32 key, s32 idx);
    s32 Func14EDE0(CGameDBRec4C *tbl, s32 n, s32 key, s32 val, s32 idx);
    CGameDBRec4C *Find14ED50(CGameDBRec4C *tbl, s32 n, s32 key, s32 val);
    CGameDBRec74 *Find1C4(s32 id);
    CGameDBRec48 *Find38(s32 id);
    CGameDBRec24 *Find234(s32 id);
    CGameDBRec14 *Find220(s32 id);
    CGameDBRec1C *Find20C(s32 id);
    CGameDBRec28 *Find200(s32 id);
    CGameDBRecB0 *Find1E8(s32 id);
    CGameDBRec5C *Find1DC(s32 id);
    CGameDBRec34 *Find1D0(s32 id);
    s32 Func14C9F8(s32 v);
    CGameDBItem14 *GetCharaItem(s32 id, s32 j);
    s32 GetCharaD38(s32 id);
    s32 GetCharaD34(s32 id);
    s32 GetCharaD30(s32 id);
    u8 *GetCharaD1C(s32 id);
    u8 *GetCharaD08(s32 id);
    s32 GetChara4(s32 id);
    char *GetCharaName(s32 id);
    CGameDBRec20 *GetTbl250(s32 i);
    s32 GetUnk14(s32 i);
    CGameDBRec8 *GetUnk20(s32 i);
    void Func147020();
    void Init();
    s32 GetUnk24();
    int Func14EB20(s32 a, s32 b, s32 c);
    int CallFunc14EB20Minus(s32 a, s32 b);
    int CallFunc14EB20Plus(s32 a, s32 b);

    u8 pad0[0x4];
    CPushBuf m_buf;           // 0x4
    s32 m_unk10;              // 0x10
    s32 *m_unk14;             // 0x14
    s32 m_unk18;              // 0x18
    s32 m_unk1C;              // 0x1C
    CGameDBRec8 *m_unk20;     // 0x20
    s32 m_unk24;              // 0x24
    s32 m_unk28;              // 0x28
    s32 m_unk2C;              // 0x2C
    CGameDBChara *m_charas;   // 0x30
    s32 m_unk34;              // 0x34
    CGameDBRec48 *m_tbl38;    // 0x38
    s32 m_num38;              // 0x3C
    s32 m_unk40;              // 0x40
    CGameDBBits m_bits[8];    // 0x44
    CGameDBBits m_bits104[8]; // 0x104
    CGameDBRec74 *m_tbl1C4;   // 0x1C4
    s32 m_num1C4;             // 0x1C8
    s32 m_unk1CC;             // 0x1CC
    CGameDBRec34 *m_tbl1D0;   // 0x1D0
    s32 m_num1D0;             // 0x1D4
    s32 m_max1D8;             // 0x1D8
    CGameDBRec5C *m_tbl1DC;   // 0x1DC
    s32 m_num1DC;             // 0x1E0
    s32 m_unk1E4;             // 0x1E4
    CGameDBRecB0 *m_tbl1E8;   // 0x1E8
    s32 m_num1E8;             // 0x1EC
    s32 m_unk1F0;             // 0x1F0
    s32 m_unk1F4;             // 0x1F4
    s32 m_unk1F8;             // 0x1F8
    s32 m_unk1FC;             // 0x1FC
    CGameDBRec28 *m_tbl200;   // 0x200
    s32 m_num200;             // 0x204
    s32 m_unk208;             // 0x208
    CGameDBRec1C *m_tbl20C;   // 0x20C
    s32 m_num20C;             // 0x210
    s32 m_unk214;             // 0x214
    CGameDBRec4C *m_tbl218;   // 0x218
    s32 m_num218;             // 0x21C
    CGameDBRec14 *m_tbl220;   // 0x220
    s32 m_num220;             // 0x224
    s32 m_unk228;             // 0x228
    CGameDBRec4C *m_tbl22C;   // 0x22C
    s32 m_num22C;             // 0x230
    CGameDBRec24 *m_tbl234;   // 0x234
    s32 m_num234;             // 0x238
    s32 m_unk23C;             // 0x23C
    CGameDBRec0C *m_tbl240;   // 0x240
    s32 m_num240;             // 0x244
    const char ***m_names248; // 0x248
    s32 *m_counts24C;         // 0x24C
    CGameDBRec20 *m_tbl250;   // 0x250
    s32 m_num250;             // 0x254
};

class CGameDBEntry {
public:


    s32 m_id;                 // 0x0
    u8 pad4[0x34];
    s32 m_order;              // 0x38
};

#include "libc.h"
//@sym Func14BB28__Fi 0x14BB28
extern char D_002D7D80[];
extern s32 D_002A2D30[];
extern char D_002D81F8[];
extern char D_002D8200[];
extern char D_002D8208[];
extern char D_002D8210[];
extern char D_002D8218[];
extern char D_002D8260[];
s32 Func14BB28(s32 id);
extern "C" s32 func_001456A8(s32 id);
s32 Func145738(s32 a, s32 b);
extern "C" char *strstr(const char *s, const char *sub);
extern "C" void *func_0024F2E8(s32 size);
extern "C" void func_00150A70(void *p, s32 v);
extern "C" void func_0024F5C0(void *a, void *b, s32 c);

// Linear search of a record table by its first field (inlined at each use).
template <class T> inline T *FindById(T *tbl, s32 n, s32 id) {
    for (s32 i = 0; i < n; i++, tbl++) {
        if (tbl->m_id == id) {
            return tbl;
        }
    }
    return 0;
}

extern char D_002D7D80[];

extern char D_002D8110[];
void Func235DE0(const char *fmt, ...);
extern s32 D_002A2D98[];
struct CGameDBNameRec {
    s32 m_id;                 // 0x0
    u8 pad4[0x10];
    const char *m_name;       // 0x14
};
struct CGameDBNameGroup {
    u8 pad0[0x2C];
    s32 m_num;                // 0x2C
    CGameDBNameRec *m_recs;   // 0x30
};

extern "C" void *func_00248CC8(void *buf, s32 size, s32 a, s32 b);
extern "C" char *func_00248DA8(void *buf);
extern "C" const char *func_00248DC0(void *buf);
extern "C" const char *func_0024AF10(const char *s, const char *key);
extern "C" s32 func_0024B040(const char *s, s32 k);
extern "C" const char *func_0024AFE8(const char *s, char *buf, s32 k, s32 size);
extern "C" const char *func_0024A570(const char *s, char *out, const char *a, const char *b);
extern char D_002D7EC0[];
extern char D_002D7EC8[];
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", Init146F60__11CResNameMgr);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_00146FA8);

void CGameDBMgr::Func147020() {
    m_unk14 = 0;
    m_unk18 = 0;
    m_unk1C = (s32)D_002D7D80;
    m_unk20 = 0;
    m_unk24 = 0;
    m_unk28 = 0;
    m_unk2C = 0;
    m_charas = 0;
    m_unk34 = 0;
    m_tbl38 = 0;
    m_num38 = 0;
    m_unk40 = 0;
    memset(m_bits, 0, sizeof(m_bits));
    memset(m_bits104, 0, sizeof(m_bits104));
    m_tbl1C4 = 0;
    m_num1C4 = 0;
    m_unk1CC = 0;
    m_tbl1D0 = 0;
    m_num1D0 = 0;
    m_max1D8 = 0;
    m_tbl1DC = 0;
    m_num1DC = 0;
    m_unk1E4 = 0;
    m_tbl1E8 = 0;
    m_num1E8 = 0;
    m_unk1F0 = 0;
    m_unk1F4 = 0;
    m_unk1F8 = 0;
    m_unk1FC = 0;
    m_tbl200 = 0;
    m_num200 = 0;
    m_unk208 = 0;
    m_tbl20C = 0;
    m_num20C = 0;
    m_unk214 = 0;
    m_tbl218 = 0;
    m_num218 = 0;
    m_tbl220 = 0;
    m_num220 = 0;
    m_unk228 = 0;
    m_tbl22C = 0;
    m_num22C = 0;
    m_tbl234 = 0;
    m_num234 = 0;
    m_unk23C = 0;
    m_tbl240 = 0;
    m_num240 = 0;
    m_names248 = 0;
    m_counts24C = 0;
    m_tbl250 = 0;
    m_num250 = 0;
}

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_00147130);

s32 Func147340(char **tbl, char *name) {
    for (s32 i = 0; tbl[i]; i++) {
        if (strcmp(tbl[i], name) == 0) {
            return i;
        }
    }
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_001473B0);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_00147500);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_001478E8);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_00148110);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_00148238);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_00148400);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_00148450);

s32 FindIdByName148510(CGameDBNameGroup *groups, s32 n, const char *name) {
    for (s32 i = 0; i < n; i++) {
        CGameDBNameGroup *g = &groups[i];
        for (s32 j = 0; j < g->m_num; j++) {
            CGameDBNameRec *r = &g->m_recs[j];
            if (strcmp(r->m_name, name) == 0) return r->m_id;
        }
    }
    Func235DE0(D_002D8110, name);
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_001485E8);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_00148C50);

s32 CGameDBMgr::ParseTable148D70(const char ***out, const char *text, const char *key, s32 ncol) {
    char line[256];
    const char *p = func_0024AF10(text, key);
    if (*p == 0) return 0;
    s32 n = func_0024B040(p, 1);
    s32 cnt = 0;
    *out = (const char **)func_00248CC8(&m_buf, n * ncol * 4, 1, 1);
    for (s32 i = 0; i < n; i++) {
        p = func_0024AFE8(p, line, 1, 0x100);
        const char *q = line;
        for (s32 j = 0; j < ncol; j++) {
            q = func_0024A570(q, func_00248DA8(&m_buf), D_002D7EC0, D_002D7EC8);
            (*out)[cnt++] = func_00248DC0(&m_buf);
        }
    }
    return cnt;
}

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_00148EC8);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_001490F8);

u32 Func149618(char *s) {
    u32 r = 0;
    char *base = s;
    while (*s) {
        if (*s == '1') {
            r |= 1 << (s - base);
        }
        s++;
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_00149670);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_00149DC8);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014A0F8);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014A370);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014A620);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014A8C0);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014AAD0);

s32 Func14AD78(char *s) {
    s32 r = strstr(s, D_002D81F8) ? 2 : 0;
    if (strstr(s, D_002D8200)) {
        r |= 4;
    }
    if (strstr(s, D_002D8208)) {
        r |= 8;
    }
    if (strstr(s, D_002D8210)) {
        r |= 0x10;
    }
    if (strstr(s, D_002D8218)) {
        r |= 0x20;
    }
    if (strstr(s, D_002D8260)) {
        r |= 0x40;
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014AE30);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014B4C8);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014B890);

void CGameDBMgr::Init() {
    m_buf.Func248E00();
    Func147020();
}

s32 Func14BB28(s32 id) {
    if (id < D_002A26E4->Func1091B0(0x27)) {
        return D_002A26E4->Func1091B0(id + 0x28) - 0x10;
    }
    return ((u32)(id - 0x10) < 8) ? id - 0x10 : -1;
}

s32 CGameDBMgr::FindType2() {
    for (s32 i = 0; i < m_num1E8; i++) {
        if (m_tbl1E8[i].mC == 2) return m_tbl1E8[i].m_id;
    }
    return -1;
}

s32 CGameDBMgr::FindType8() {
    for (s32 i = 0; i < m_num1E8; i++) {
        if (m_tbl1E8[i].mC == 8) return m_tbl1E8[i].m_id;
    }
    return -1;
}

s32 CGameDBMgr::Collect14BC20(s32 *out, s32 max) {
    if (D_002A26E4->Func1091B0(0x17) & 3) return 0;
    s32 v = D_002A26E4->Func1091B0(0x17) / 4 + 25;
    s32 cnt = 0;
    for (s32 i = 0; i < m_unk24; i++) {
        if (m_unk20[i].m_id == v) {
            if (max > 0) {
                out[cnt] = i;
                max--;
            }
            cnt++;
        }
    }
    return cnt;
}

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014BD00);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014C048);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014C2B0);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014C490);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014C648);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014C800);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014C998);

s32 CGameDBMgr::Func14C9F8(s32 v) {
    s32 i;
    for (i = 0; i < 6; i++) {
        if (v < D_002A2D30[i]) {
            break;
        }
    }
    return i - 1;
}

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014CA38);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014CAF0);

int CompareGameDBIds(const s32 *a, const s32 *b) {
    return *a - *b;
}

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014CC00);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014CF78);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014D378);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014D430);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014D5F8);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014D7C8);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014DB70);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014DCE0);

s32 CGameDBMgr::GetUnk24() {
    return m_unk24;
}

CGameDBRec8 *CGameDBMgr::GetUnk20(s32 i) {
    if (i < 0 || i > m_unk24 - 1) {
        return 0;
    }
    return &m_unk20[i];
}

s32 CGameDBMgr::GetUnk14(s32 i) {
    if (i < 0 || i > m_unk18 - 1) {
        return 0;
    }
    return m_unk14[i];
}

char *CGameDBMgr::GetCharaName(s32 id) {
    s32 k = Func14BB28(id);
    if (k < 0) {
        return D_002D7D80;
    }
    return m_charas[k].m_name;
}

s32 CGameDBMgr::GetChara4(s32 id) {
    s32 k = Func14BB28(id);
    if (k < 0) {
        return 0;
    }
    return m_charas[k].m4;
}

CGameDBItem14 *CGameDBMgr::GetCharaItem(s32 id, s32 j) {
    s32 k = Func14BB28(id);
    if (k < 0) {
        return 0;
    }
    s32 n = m_charas[k].mC - 1;
    if (j >= n) {
        j = n;
    }
    if (j < 0) {
        j = 0;
    }
    return &m_charas[k].m8[j];
}

u8 *CGameDBMgr::GetCharaD08(s32 id) {
    s32 k = Func14BB28(id);
    if (k < 0) {
        return 0;
    }
    return m_charas[k].mD08;
}

u8 *CGameDBMgr::GetCharaD1C(s32 id) {
    s32 k = Func14BB28(id);
    if (k < 0) {
        return 0;
    }
    return m_charas[k].mD1C;
}

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014E660);

s32 CGameDBMgr::GetCharaD30(s32 id) {
    s32 k = Func14BB28(id);
    if (k < 0) {
        return 0;
    }
    return m_charas[k].mD30;
}

s32 CGameDBMgr::GetCharaD34(s32 id) {
    s32 k = Func14BB28(id);
    if (k < 0) {
        return 0;
    }
    return m_charas[k].mD34;
}

s32 CGameDBMgr::GetCharaD38(s32 id) {
    s32 k = Func14BB28(id);
    if (k < 0) {
        return 0;
    }
    return m_charas[k].mD38;
}

CGameDBRec34 *CGameDBMgr::Find1D0(s32 id) {
    return FindById(m_tbl1D0, m_num1D0, id);
}

CGameDBRec5C *CGameDBMgr::Find1DC(s32 id) {
    return FindById(m_tbl1DC, m_num1DC, id);
}

CGameDBRecB0 *CGameDBMgr::Find1E8(s32 id) {
    return FindById(m_tbl1E8, m_num1E8, id);
}

CGameDBRec28 *CGameDBMgr::Find200(s32 id) {
    return FindById(m_tbl200, m_num200, id);
}

CGameDBRec1C *CGameDBMgr::Find20C(s32 id) {
    return FindById(m_tbl20C, m_num20C, id);
}

CGameDBRec14 *CGameDBMgr::Find220(s32 id) {
    return FindById(m_tbl220, m_num220, id);
}

CGameDBRec24 *CGameDBMgr::Find234(s32 id) {
    return FindById(m_tbl234, m_num234, id);
}

CGameDBRec48 *CGameDBMgr::Find38(s32 id) {
    return FindById(m_tbl38, m_num38, id);
}

CGameDBRec74 *CGameDBMgr::Find1C4(s32 id) {
    return FindById(m_tbl1C4, m_num1C4, id);
}

int CGameDBMgr::Func14EB20(s32 id, s32 slot, s32 step) {
    CGameDBRec74 *rec;
    if ((u32)slot >= 13) return 0;
    s32 n = m_unk1CC + 1;
    do {
        id = (id + step + n) % n;
        rec = FindById(m_tbl1C4, m_num1C4, id);
    } while (rec == 0 || rec->m_names[slot][0] == 0);
    return (int)rec;
}

int CGameDBMgr::CallFunc14EB20Minus(s32 a, s32 b) {
    return Func14EB20(a, b, -1);
}

int CGameDBMgr::CallFunc14EB20Plus(s32 a, s32 b) {
    return Func14EB20(a, b, 1);
}

const char *CGameDBMgr::GetName248(u32 a, s32 b) {
    if (m_counts24C == 0 || a >= 4 || b < 0 || b > m_counts24C[a] - 1) return D_002D7D80;
    return m_names248[a][b];
}

s32 CGameDBMgr::Func14EC50(s32 key, s32 idx) {
    return Func14EDE0(m_tbl218, m_num218, key, D_002A26E4->Func1091B0(func_001456A8(key) + 0xE2), idx);
}

s32 CGameDBMgr::Func14ECD0(s32 key, s32 idx) {
    return Func14EDE0(m_tbl22C, m_num22C, key, D_002A26E4->Func1091B0(func_001456A8(key) + 0xDC), idx);
}

CGameDBRec4C *CGameDBMgr::Find14ED50(CGameDBRec4C *tbl, s32 n, s32 key, s32 val) {
    s32 k = Func145738(key, 1);
    if (k < 0) {
        return 0;
    }
    for (s32 i = 0; i < n; i++) {
        if (tbl[i].m4 == k && tbl[i].m0 == val) {
            return &tbl[i];
        }
    }
    return 0;
}

s32 CGameDBMgr::Func14EDE0(CGameDBRec4C *tbl, s32 n, s32 key, s32 val, s32 idx) {
    CGameDBRec4C *p = Find14ED50(tbl, n, key, val);
    if (!p) {
        return 0;
    }
    return p->m8[idx];
}

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014EE18);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014F2A0);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014F380);

int CGameDBMgr::TestBits14F478(s32 id) {
    s32 base = func_001456A8(id);
    if (base < 0) return 0;
    s32 k = Func14BB28(id);
    CGameDBBits *b = &m_bits[k];
    if (k < 0) return 0;
    for (s32 i = 0; i < 5; i++) {
        if ((b->m_bits[i] >> D_002A26E4->Func1091B0(D_002A2D98[i] + base)) & 1) return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014F550);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014F638);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014F760);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014F830);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014F918);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014FA08);

CGameDBRec20 *CGameDBMgr::GetTbl250(s32 i) {
    if (i < 0 || i > m_num250 - 1) {
        return 0;
    }
    return &m_tbl250[i];
}

s32 CGameDBMgr::GetNum240(s32 i) {
    if (i < 0 || i > m_num240 - 1) return 0;
    CGameDBRec0C *rec = &m_tbl240[i];
    return rec->m8;
}

CGameDBRec24b *CGameDBMgr::Get240(s32 i, s32 j) {
    if (i < 0 || i > m_num240 - 1) return 0;
    CGameDBRec0C *rec = &m_tbl240[i];
    if (j < 0 || j > rec->m8 - 1) return 0;
    return &rec->m4[j];
}

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014FBB0);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014FC70);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014FCC8);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014FE60);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014FF30);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", Func150348__10CGameDBMgrPiiiii);

s32 CGameDBMgr::Get150550(s32 a, s32 b, s32 c) {
    s32 buf[4];
    if (Func150348(buf, a, b, c, 0)) {
        return buf[0];
    }
    return 0;
}

s32 CGameDBMgr::Get150590(s32 a, s32 b, s32 c, s32 d) {
    s32 buf[4];
    if (Func150348(buf, a, b, c, d)) {
        return buf[1];
    }
    return -1;
}

s32 CGameDBMgr::Get1505E0(s32 a, s32 b, s32 c, s32 d) {
    s32 buf[4];
    if (Func150348(buf, a, b, c, d)) {
        return buf[2];
    }
    return -1;
}

s32 CGameDBMgr::Get150630(s32 a, s32 b, s32 c, s32 d) {
    s32 buf[4];
    if (Func150348(buf, a, b, c, d)) {
        return buf[3];
    }
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_00150680);

s32 CGameDBMgr::Find20(s32 id) {
    if ((u32)(id - 16) >= 8) return -1;
    for (s32 i = 0; i < m_unk24; i++) {
        if (m_unk20[i].m4 == id) return i;
    }
    return -1;
}

int CompareGameDBEntries(const CGameDBEntry *a, const CGameDBEntry *b) {
    int d = a->m_order - b->m_order;
    if (d != 0) {
        return d;
    }
    return a->m_id - b->m_id;
}

void Func150A10(void *a, s32 b) {
    void *p = func_0024F2E8(0x4D0);
    func_00150A70(p, b);
    func_0024F5C0(a, p, 0);
}
