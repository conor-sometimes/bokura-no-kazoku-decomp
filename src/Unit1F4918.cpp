#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
s32 Func235DE0(const char *fmt, ...);
struct CXmnPktEnt {
    s16 m_type;               // 0x0
    u16 m_qwc;                // 0x2
    u16 m_a;                  // 0x4
    u16 m_b;                  // 0x6
    u8 *m_start;              // 0x8
    void *m_src;              // 0xC
};
struct CXmnSurf {
    f32 m_r;                  // 0x0
    f32 m_g;                  // 0x4
    f32 m_b;                  // 0x8
    f32 m_unkC;               // 0xC
    f32 m_alpha;              // 0x10
    f32 m_unk14;              // 0x14
    s32 m_kind;               // 0x18
    s32 m_flags;              // 0x1C
};
struct CXmnRend {
    s32 m_unk0;               // 0x0
    void (*m_onOpen)();       // 0x4
    void (*m_onOpenHi)();     // 0x8
    void (*m_onClose)();      // 0xC
    s32 m_mode10;             // 0x10
    s32 m_mode14;             // 0x14
    s32 m_busy;               // 0x18
    u8 pad1C[0x1C];
    s32 m_unk38;              // 0x38
    CXmnSurf *m_surf;         // 0x3C
    s32 m_unk40;              // 0x40
    u8 *m_unk44;              // 0x44
    u8 *m_cur;                // 0x48
    u8 *m_unk4C;              // 0x4C
    u8 *m_unk50;              // 0x50
    u8 *m_start;              // 0x54
    s32 m_unk58;              // 0x58
    s32 m_unk5C;              // 0x5C
    s32 m_unk60;              // 0x60
    s32 m_unk64;              // 0x64
    s32 m_unk68;              // 0x68
    s32 m_unk6C;              // 0x6C
    s32 m_unk70;              // 0x70
    s32 m_unk74;              // 0x74
    s32 m_count;              // 0x78
    CXmnPktEnt *m_ents;       // 0x7C
    s32 m_open;               // 0x80
    s32 m_hi;                 // 0x84
    s32 m_type;               // 0x88
    s32 m_a;                  // 0x8C
    s32 m_b;                  // 0x90
};
extern CXmnRend D_30E170;
extern s32 D_30E124;
extern u8 *D_002B94E4;
extern s32 D_002A5CD0;
extern const char D_002E2390[];
extern "C" void func_00237350(s32 x);
extern "C" void func_001F4F88();
extern "C" s32 func_001FB6C0(s32 a, s32 b);
extern "C" s32 func_001FD0A8(s32 a, s32 b);
extern "C" s32 func_001FD5C8(s32 a, s32 b);
extern "C" s32 func_001FDC40(s32 a, s32 b);
extern "C" s32 func_001FE888(s32 a, s32 b);

extern const char D_002E2468[];
extern "C" void func_001F5038(s32 type, s32 a, s32 b);
extern "C" void func_00226DF8(s32 a, s32 b);
extern "C" void func_0021EA40(s32 a, s32 b);
extern "C" s32 func_0021DE68();
extern "C" void func_0021DE78(s32 x);
extern "C" s32 func_0021DE88();
extern "C" void func_0021DE98(s32 x);
extern "C" void func_00221340(s32 a, s32 b);
extern "C" f32 func_00220A78();
extern "C" f32 func_00220A88();
extern "C" f32 func_00220A98();
extern "C" void func_00220A38(s32 x);
#define XMN_SURF_BEGIN(i, s, code)                                              \
    CXmnRend *r = &D_30E170;                                                    \
    if (r->m_busy) return;                                                      \
    if (r->m_surf == 0) {                                                       \
        if (D_002A5CD0) return (void)Func235DE0(D_002E2468);                    \
        return;                                                                 \
    }                                                                           \
    s = &r->m_surf[i];                                                          \
    s32 kind = s->m_kind;                                                       \
    if (r->m_type != 14 || r->m_a != kind || r->m_b != 0)                       \
        func_001F5038(14, kind, 0);                                             \
    switch (s->m_kind) {                                                        \
    case 1: code = 0x48; break;                                                 \
    case 2: code = 0x42; break;                                                 \
    default: code = 0x44; break;                                                \
    }
// @decl-end

INCLUDE_ASM("asm/nonmatchings/Unit1F4918", func_001F4918);

INCLUDE_ASM("asm/nonmatchings/Unit1F4918", func_001F4AA0);

INCLUDE_ASM("asm/nonmatchings/Unit1F4918", func_001F4E40);

extern "C" void func_001F4F88()
{
    if (D_30E170.m_open == 0) return;
    if (D_30E170.m_hi && D_30E170.m_onClose) D_30E170.m_onClose();
    func_00237350(0x10);
    CXmnPktEnt *e = &D_30E170.m_ents[D_30E170.m_count - 1];
    e->m_qwc = (D_002B94E4 - e->m_start) / 16;
    D_30E170.m_open = 0;
    D_30E170.m_hi = 0;
    D_30E170.m_type = -1;
    D_30E170.m_a = -1;
    D_30E170.m_b = -1;
}

INCLUDE_ASM("asm/nonmatchings/Unit1F4918", func_001F5038);

INCLUDE_ASM("asm/nonmatchings/Unit1F4918", func_001F5158);
INCLUDE_RODATA("asm/nonmatchings/Unit1F4918", D_002E2390);
INCLUDE_RODATA("asm/nonmatchings/Unit1F4918", D_002E23B0);
INCLUDE_RODATA("asm/nonmatchings/Unit1F4918", jtbl_002E23E0);
INCLUDE_RODATA("asm/nonmatchings/Unit1F4918", jtbl_002E2400);

INCLUDE_RODATA("asm/nonmatchings/Unit1F4918", D_002E2420);
INCLUDE_RODATA("asm/nonmatchings/Unit1F4918", D_002E2450);
INCLUDE_ASM("asm/nonmatchings/Unit1F4918", func_001F5B70);

INCLUDE_ASM("asm/nonmatchings/Unit1F4918", func_001F5F28);

INCLUDE_ASM("asm/nonmatchings/Unit1F4918", func_001F62E0);

extern "C" void func_001F6698(s32 i)
{
    CXmnSurf *s;
    s32 code;
    XMN_SURF_BEGIN(i, s, code)
    return func_00226DF8(0x42, code);
}

extern "C" void func_001F6770(s32 i)
{
    CXmnSurf *s;
    s32 code;
    XMN_SURF_BEGIN(i, s, code)
    func_0021EA40(0x42, code);
    if (func_0021DE68() == 1) {
        if (s->m_r == 0.0f) func_0021DE78(0);
        else func_0021DE78(1);
    }
    func_0021DE98(0);
    if (func_0021DE88() == 1 && 0.0f < s->m_unk14) func_0021DE98(1);
}

extern "C" void func_001F68B0(s32 i)
{
    CXmnSurf *s;
    s32 code;
    XMN_SURF_BEGIN(i, s, code)
    func_00221340(0x42, code);
    if (s->m_r == func_00220A78() && s->m_g == func_00220A88() && s->m_b == func_00220A98()) func_00220A38(1);
    else func_00220A38(0);
}

INCLUDE_ASM("asm/nonmatchings/Unit1F4918", func_001F69D8);

INCLUDE_ASM("asm/nonmatchings/Unit1F4918", func_001F6E98);

INCLUDE_ASM("asm/nonmatchings/Unit1F4918", func_001F7278);

INCLUDE_ASM("asm/nonmatchings/Unit1F4918", func_001F7658);

INCLUDE_ASM("asm/nonmatchings/Unit1F4918", func_001F7A38);

INCLUDE_ASM("asm/nonmatchings/Unit1F4918", func_001F7E18);

INCLUDE_ASM("asm/nonmatchings/Unit1F4918", func_001F82E0);

INCLUDE_ASM("asm/nonmatchings/Unit1F4918", func_001F86C0);

INCLUDE_ASM("asm/nonmatchings/Unit1F4918", func_001F8AA0);

INCLUDE_RODATA("asm/nonmatchings/Unit1F4918", D_002E2468);
INCLUDE_ASM("asm/nonmatchings/Unit1F4918", func_001F8E80);

INCLUDE_ASM("asm/nonmatchings/Unit1F4918", func_001F94C8);

INCLUDE_ASM("asm/nonmatchings/Unit1F4918", func_001F9868);

INCLUDE_ASM("asm/nonmatchings/Unit1F4918", func_001F9C08);

INCLUDE_ASM("asm/nonmatchings/Unit1F4918", func_001FA300);

INCLUDE_ASM("asm/nonmatchings/Unit1F4918", func_001FA8A8);

extern "C" s32 func_001FAE50(s32 i)
{
    CXmnRend *r = &D_30E170;
    if (r->m_surf == 0) return 0;
    if (r->m_mode10 == -1) return 0;
    s32 fl = r->m_surf[i].m_flags;
    if (fl & 4) return 0;
    if (r->m_mode10 == 1) return 1;
    return (fl >> 1) & 1;
}

INCLUDE_RODATA("asm/nonmatchings/Unit1F4918", D_002E2480);
INCLUDE_ASM("asm/nonmatchings/Unit1F4918", func_001FAEA8);

extern "C" s32 func_001FB288(s32 i)
{
    CXmnRend *r = &D_30E170;
    if (r->m_surf == 0) return 0;
    if (r->m_mode14 == -1) return 0;
    CXmnSurf *s = &r->m_surf[i];
    if (s->m_flags & 4) return 0;
    if (r->m_mode14 == 1) return 1;
    return s->m_alpha > 70.0f;
}

INCLUDE_ASM("asm/nonmatchings/Unit1F4918", func_001FB2E8);

INCLUDE_ASM("asm/nonmatchings/Unit1F4918", func_001FB6C0);

INCLUDE_ASM("asm/nonmatchings/Unit1F4918", func_001FD0A8);

INCLUDE_ASM("asm/nonmatchings/Unit1F4918", func_001FD5C8);

INCLUDE_ASM("asm/nonmatchings/Unit1F4918", func_001FDC40);

INCLUDE_ASM("asm/nonmatchings/Unit1F4918", func_001FE888);

extern "C" s32 func_001FF290(s32 a, s32 b)
{
    switch (D_30E170.m_unk38) {
    case 2: return func_001FD5C8(a, b);
    case 3: return func_001FDC40(a, b);
    case 4: return func_001FE888(a, b);
    case 1: return func_001FD0A8(a, b);
    default: return func_001FB6C0(a, b);
    }
}

INCLUDE_ASM("asm/nonmatchings/Unit1F4918", func_001FF328);

INCLUDE_ASM("asm/nonmatchings/Unit1F4918", func_001FF4A0);
