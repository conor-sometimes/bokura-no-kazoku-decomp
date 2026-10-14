#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" void func_001B9B30(void *p);
struct CMiniGame4Data {
    u8 pad0[0x40];
    const char *m_text;       // 0x40
};
extern CMiniGame4Data *D_002A5A04;
struct CRand {
    u32 m_seed;
    u32 Next() {
        m_seed = m_seed * 0x19660D + 1;
        return (m_seed >> 12) & 0xFFFF;
    }
};
struct CMiniGame4Pair {
    f32 a;
    f32 b;
    u8 pad8[0x8];
};
struct CMiniGame4Layout {
    u8 pad0[0x20];
    s32 m_id;                 // 0x20
};
class CMiniGame4ResObj {
public:
    void Release1D4C68();
    int Parse1D5360();
    int ParseCfg1D4FA8();
    u8 pad0[0x10];
    CMiniGame4Layout m_unk10; // 0x10
    u8 m_unk34[0x24];         // 0x34
    u8 pad58[0x1330 - 0x58];
    CRand m_rand;             // 0x1330
    u8 pad1334[0x13A0 - 0x1334];
    s32 m_vals[14];           // 0x13A0
    u8 pad13D8[0x13EC - 0x13D8];
    s32 m_must[2];            // 0x13EC
    s32 m_numMust;            // 0x13F4
    s32 m_unk13F8;            // 0x13F8
    s32 m_unk13FC;            // 0x13FC
    s32 m_unk1400;            // 0x1400
    s32 m_order[11];          // 0x1404
    u8 pad1430[0x144C - 0x1430];
    f32 m_tbl144C[5][4];      // 0x144C
    u8 pad149C[0x8];
    f32 m_unk14A4[3];         // 0x14A4
    u8 pad14B0[0x10];
    CMiniGame4Pair m_pairs[4]; // 0x14C0
    f32 m_unk1500;            // 0x1500
    u8 pad1504[0x4];
    f32 m_unk1508;            // 0x1508
};

extern "C" void *func_0024F2E8(s32 size);
extern "C" void func_0024F5C0(void *a, void *b, s32 c);
extern "C" void func_001D4D10(void *p, s32 a, s32 b);

extern char D_002E14A0[];
extern "C" const char *func_0024AF10(const char *s, const char *key);
extern "C" const char *func_0024AFE8(const char *s, char *buf, s32 k, s32 size);
extern "C" long atol(const char *s);
//@sym atol 0x289140

extern char D_002E1460[];
extern char D_002E1468[];
extern char D_002E1470[];
extern char D_002E1478[];
extern "C" const char *func_0024A710(const char *p, s32 *v, s32 k, const char *s1, const char *s2);
void Func235DE0(const char *fmt, ...);
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CMiniGame4Res", func_001D4B50);

INCLUDE_ASM("asm/nonmatchings/CMiniGame4Res", func_001D4BA8);

void CMiniGame4ResObj::Release1D4C68() {
    D_002A5A04 = 0;
    func_001B9B30(m_unk34);
    func_001B9B30(&m_unk10);
}

void Func1D4CA0(void *a, s32 b, s32 c) {
    void *p = func_0024F2E8(0x1520);
    func_001D4D10(p, b, c);
    func_0024F5C0(a, p, 0);
}

INCLUDE_ASM("asm/nonmatchings/CMiniGame4Res", func_001D4D10);

INCLUDE_ASM("asm/nonmatchings/CMiniGame4Res", func_001D4E98);

int CMiniGame4ResObj::ParseCfg1D4FA8() {
    char key[256];
    s32 id;
    const char *p = func_0024AF10(D_002A5A04->m_text, D_002E1460);
    if (*p == 0) return 0;
    while ((p = func_0024AFE8(p, key, 1, 0x100), *p != 0) || key[0] != 0) {
        const char *q = func_0024A710(key, &id, 0, D_002E1468, D_002E1470);
        q = func_0024A710(q, &m_unk13F8, 0, D_002E1468, D_002E1470);
        q = func_0024A710(q, &m_unk1400, 0, D_002E1468, D_002E1470);
        q = func_0024A710(q, &m_unk13FC, 0, D_002E1468, D_002E1470);
        m_numMust = 0;
        for (s32 i = 0; i < 2; i++) {
            q = func_0024A710(q, &m_must[i], 0, D_002E1468, D_002E1470);
            m_numMust++;
            if (*q == 0) break;
        }
        if (id == m_unk10.m_id) return 1;
    }
    Func235DE0(D_002E1478);
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/CMiniGame4Res", func_001D5140);

int CMiniGame4ResObj::Parse1D5360() {
    char buf[256];
    const char *p = func_0024AF10(D_002A5A04->m_text, D_002E14A0);
    if (*p == 0) return 0;
    s32 *out = m_vals;
    for (s32 i = 0; i < 14; i++) {
        p = func_0024AFE8(p, buf, 1, 0x100);
        if (*p == 0) break;
        if (buf[0] == 0) break;
        *out++ = atol(buf);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/CMiniGame4Res", func_001D5420);

INCLUDE_ASM("asm/nonmatchings/CMiniGame4Res", func_001D5550);

INCLUDE_ASM("asm/nonmatchings/CMiniGame4Res", func_001DE060);
