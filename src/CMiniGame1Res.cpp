#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
//@sym memset 0x289FB0
#include "libc.h"
class CMiniGame1ResSub1BDBC0 {
public:
    void Clear();

    u8 pad0[0x870];
    u8 m_data[0x14];          // 0x870
};

extern "C" void func_001B9B30(void *p);
struct CMiniGame1Data {
    u8 pad0[0x40];
    const char *m_text;       // 0x40
};
extern CMiniGame1Data *D_002A59F8;
class CMiniGame1ResObj {
public:
    void Release1BD7C0();
    u8 pad0[0x10];
    u8 m_unk10[0x24];         // 0x10
    u8 m_unk34[0x24];         // 0x34
};

extern "C" void *func_0024F2E8(s32 size);
extern "C" void func_0024F5C0(void *a, void *b, s32 c);
extern "C" void func_001BD868(void *p, s32 a, s32 b);

struct CRand {
    u32 m_seed;
    u32 Next() {
        m_seed = m_seed * 0x19660D + 1;
        return (m_seed >> 12) & 0xFFFF;
    }
};
class CMiniGame1ResRand {
public:
    void Fill1BDB38(s32 n);
    u8 pad0[0x7B0];
    CRand m_rand;             // 0x7B0
    u8 pad7B4[0x828 - 0x7B4];
    u32 m_vals[16];           // 0x828
    s32 m_count;              // 0x868
};

extern char D_002E0DE8[];
extern char D_002E0DF0[];
extern char D_002E0DF8[];
extern "C" const char *func_0024AF10(const char *s, const char *key);
extern "C" const char *func_0024AFE8(const char *s, char *buf, s32 k, s32 size);
extern "C" const char *func_0024A710(const char *p, s32 *v, s32 k, const char *s1, const char *s2);
class CMiniGame1ResCfg {
public:
    int Parse1BDA08();
    u8 pad0[0x30];
    s32 m_unk30;              // 0x30
    u8 pad34[0x8B4 - 0x34];
    s32 m_unk8B4;             // 0x8B4
    s32 m_unk8B8;             // 0x8B8
    s32 m_unk8BC;             // 0x8BC
    s32 m_unk8C0;             // 0x8C0
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CMiniGame1Res", func_001BD6A8);

INCLUDE_ASM("asm/nonmatchings/CMiniGame1Res", func_001BD700);

void CMiniGame1ResObj::Release1BD7C0() {
    D_002A59F8 = 0;
    func_001B9B30(m_unk34);
    func_001B9B30(m_unk10);
}

void Func1BD7F8(void *a, s32 b, s32 c) {
    void *p = func_0024F2E8(0x910);
    func_001BD868(p, b, c);
    func_0024F5C0(a, p, 0);
}

INCLUDE_ASM("asm/nonmatchings/CMiniGame1Res", func_001BD868);

INCLUDE_ASM("asm/nonmatchings/CMiniGame1Res", func_001BD958);

int CMiniGame1ResCfg::Parse1BDA08() {
    char key[256];
    s32 id;
    const char *p = func_0024AF10(D_002A59F8->m_text, D_002E0DE8);
    if (*p == 0) return 0;
    while ((p = func_0024AFE8(p, key, 1, 0x100), *p != 0) || key[0] != 0) {
        const char *q = func_0024A710(key, &id, 0, D_002E0DF0, D_002E0DF8);
        q = func_0024A710(q, &m_unk8B4, 0, D_002E0DF0, D_002E0DF8);
        q = func_0024A710(q, &m_unk8B8, 0, D_002E0DF0, D_002E0DF8);
        q = func_0024A710(q, &m_unk8BC, 0, D_002E0DF0, D_002E0DF8);
        func_0024A710(q, &m_unk8C0, 0, D_002E0DF0, D_002E0DF8);
        if (id == m_unk30) return 1;
    }
    return 0;
}

void CMiniGame1ResRand::Fill1BDB38(s32 n) {
    for (s32 i = 0; i < n; i++) {
        m_vals[m_count] = ((m_rand.Next() << 16) | m_rand.Next()) % 5;
        m_count++;
    }
}

void CMiniGame1ResSub1BDBC0::Clear() {
    memset(m_data, 0, sizeof(m_data));
}

INCLUDE_ASM("asm/nonmatchings/CMiniGame1Res", func_001BDBE8);

INCLUDE_ASM("asm/nonmatchings/CMiniGame1Res", func_001C3960);
