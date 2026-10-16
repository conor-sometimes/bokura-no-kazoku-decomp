#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "Xmn.h"
s32 Func235DE0(const char *fmt, ...);
struct CXmnModel {
    void *m_unk0;             // 0x0
    void *m_unk4;             // 0x4
    s32 m_unk8;               // 0x8
    s32 m_unkC;               // 0xC
    s32 m_unk10;              // 0x10
    s32 m_unk14;              // 0x14
    void (*m_draw)();         // 0x18
    s32 m_unk1C;              // 0x1C
    s32 m_unk20;              // 0x20
    s32 m_unk24;              // 0x24
    s32 m_unk28;              // 0x28
    s32 m_unk2C;              // 0x2C
    s32 m_unk30;              // 0x30
};
extern "C" void func_00202D68();
inline void XmnModelClear(CXmnModel *m)
{
    m->m_unk8 = 0;
    m->m_unk0 = 0;
    m->m_unk4 = 0;
    m->m_unk10 = 0;
    m->m_unk14 = 0;
    m->m_unk20 = 0;
    m->m_unk24 = 0;
    m->m_unk28 = 0;
    m->m_unk2C = 0;
    m->m_unk30 = 0;
    m->m_unk1C = 0;
    m->m_draw = func_00202D68;
}
extern CXmnModel *D_002A5D0C;
extern s32 D_002A5D08, D_002A5D10, D_002A5CD0;
struct CXmnModelBlock {
    CXmnModelBlock *m_next;   // 0x0
    s32 m_first;              // 0x4
    s32 m_count;              // 0x8
    s32 m_texCount;           // 0xC
    s32 m_tex[1];             // 0x10
};
extern CXmnModelBlock *D_30E108;
extern void *D_30E104;
extern const char D_002E22A8[], D_002E22B8[], D_002E22F0[], D_002E2318[];
extern "C" void func_00224EB8();
extern "C" void func_00222D38();
extern "C" void func_0021C6D8();
extern "C" void func_0021E7A0();
extern "C" void func_00221068();
extern "C" void func_001F1D10();
extern "C" void func_00201770(s32 x);
extern "C" void func_00201710(s32 x);
extern "C" void func_00201740(s32 x);
extern "C" void func_00202430();
extern "C" void func_00223FA0();
extern "C" void func_0021BE80();
extern "C" void func_0021D8F0();
extern "C" void func_00220620();
void Func23B1D0(int x);
extern "C" void func_0023E720(void *p, s32 first);
extern "C" s32 func_0023E768(void *p, s32 first);
extern "C" void func_001F1D80(const char *who);
extern "C" s32 func_001F1E50();
extern "C" s32 func_001F1D38();
extern "C" void func_00220678();
extern "C" void func_0021D968();
extern "C" void func_0021BEC0();
extern "C" void func_00223FC0();
extern "C" void func_002025E0();
extern "C" void func_0023E5F0(void *p, s32 n);
extern "C" void func_001F1F78(CXmnModelBlock **pp);

struct CXmnGroup {
    s16 m_count;              // 0x0
    s16 m_max;                // 0x2
    s16 m_unk4;               // 0x4
    s16 m_unk6;               // 0x6
    s32 m_a[16];              // 0x8
    s32 m_b[16];              // 0x48
    s32 m_idx[0x180];         // 0x88
};
struct CXmnRendG {
    u8 pad0[0x94];
    CXmnGroup *m_groups;      // 0x94
    s32 m_unk98;              // 0x98
};
extern CXmnRendG D_30E170;
extern s32 D_30E144, D_30E148;
inline void XmnGroupInit(CXmnGroup *g, u32 size, u32 unit)
{
    g->m_max = size / unit;
    g->m_unk6 = 0;
    g->m_count = 0;
    g->m_unk4 = 0;
    s32 *a = g->m_a;
    s32 *b = g->m_b;
    for (s32 i = 0; i < 32; i += 2) {
        *a++ = -1;
        *b++ = -1;
    }
}
inline void XmnGroupFill(CXmnGroup *g, s32 n)
{
    g->m_unk6 = 1;
    if (g->m_max < n) n = g->m_max;
    g->m_count = n;
    for (s32 i = 0; i < n; i++) g->m_idx[i] = i;
}
// @decl-end

extern "C" void func_001F1EC0()
{
    func_00224EB8();
    func_00222D38();
    func_0021C6D8();
    func_0021E7A0();
    return func_00221068();
}

extern "C" void func_001F1EF8()
{
    func_001F1D10();
    D_002A5D08 = 0;
    D_002A5D10 = 0;
    D_002A5D0C = 0;
    D_30E108 = 0;
    D_30E104 = 0;
    func_00201770(0);
    func_00201710(0);
    func_00201740(0);
    func_00202430();
    func_00223FA0();
    func_0021BE80();
    func_0021D8F0();
    return func_00220620();
}

extern "C" void func_001F1F78(CXmnModelBlock **pp)
{
    CXmnModelBlock *b = *pp;
    s32 i;
    for (i = 0; i < b->m_count; i++) XmnModelClear(&D_002A5D0C[b->m_first + i]);
    for (i = 0; i < b->m_texCount; i++) Func23B1D0(b->m_tex[i]);
    func_0023E720(D_30E104, b->m_first);
    *pp = b->m_next;
    D_002B91B0(b);
}

INCLUDE_ASM("asm/nonmatchings/Unit1F1EC0", func_001F2090);

extern "C" s32 func_001F20F8(s32 idx)
{
    func_001F1D80(D_002E22A8);
    for (CXmnModelBlock **pp = &D_30E108; *pp; pp = &(*pp)->m_next) {
        CXmnModelBlock *b = *pp;
        if (idx >= b->m_first && idx < b->m_first + b->m_count) {
            func_001F1F78(pp);
            break;
        }
    }
    return func_001F1E50();
}

extern "C" s32 func_001F2170()
{
    CXmnModelBlock **pp = &D_30E108;
    while (*pp) func_001F1F78(pp);
    func_00220678();
    func_0021D968();
    func_0021BEC0();
    func_00223FC0();
    func_002025E0();
    if (D_002A5D0C) {
        D_002B91B0(D_002A5D0C);
        D_002A5D0C = 0;
        D_002A5D08 = 0;
        D_002A5D10 = 0;
        D_002B91B0(D_30E104);
    }
    return func_001F1D38();
}

INCLUDE_RODATA("asm/nonmatchings/Unit1F1EC0", D_002E22A8);
INCLUDE_ASM("asm/nonmatchings/Unit1F1EC0", func_001F2230);
INCLUDE_RODATA("asm/nonmatchings/Unit1F1EC0", D_002E2318);

extern "C" void func_001F23E8()
{
    XmnGroupInit(&D_30E170.m_groups[0], 0x600, 6);
    XmnGroupInit(&D_30E170.m_groups[1], 0x600, 6);
    XmnGroupInit(&D_30E170.m_groups[2], 0x600, 6);
    XmnGroupInit(&D_30E170.m_groups[3], 0x600, 6);
    if (D_30E170.m_unk98) {
        XmnGroupFill(&D_30E170.m_groups[0], D_30E144);
        XmnGroupFill(&D_30E170.m_groups[1], D_30E148);
    }
}

INCLUDE_ASM("asm/nonmatchings/Unit1F1EC0", func_001F2628);

INCLUDE_ASM("asm/nonmatchings/Unit1F1EC0", func_001F2838);

INCLUDE_ASM("asm/nonmatchings/Unit1F1EC0", func_001F36D0);

INCLUDE_ASM("asm/nonmatchings/Unit1F1EC0", func_001F3AC0);
