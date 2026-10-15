#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "sceMpeg.h"
struct Q4 { s32 m0, m4, m8, mC, m10; };
extern "C" s32 func_002669C0(s32, s32, s32, s32, s32);
extern "C" void func_00267A98(s32, void *);

extern "C" s32 func_002683F8(MpegSys *, s32, s32);
extern "C" s32 func_00267CA0(SceMpeg *);
extern "C" s32 func_00267FC0(SceMpeg *, s32, s32);
extern "C" s32 func_00267E58(SceMpeg *, s32, s32);
extern "C" s32 func_00268290(MpegSys *);
extern "C" void func_002681A0(MpegSys *);
extern "C" void func_002662A8(const char *, ...);
extern "C" s32 func_002760B0(void *, s32, s32, void *, s32, void *, s32, void *, void *);
extern u8 D_41C160[];
extern s32 D_41C1C0[];
extern const char D_002E9418[];

extern "C" s32 func_002760B0(void *, s32, s32, void *, s32, void *, s32, void *, void *);
extern u8 D_41C0C0[];
extern u8 D_41C0E8[];
extern u8 D_41C110[];
extern u8 D_41C138[];
extern s32 D_41C1C0[];
extern const char D_002E9388[];
extern const char D_002E93A8[];
extern const char D_002E93C8[];
extern const char D_002E93F0[];
extern "C" s32 func_0026E5D8(void *, s32);
extern "C" s32 func_0026E520(void *, s32);
extern "C" s32 func_002683A0(MpegSys *, const char *);
extern const char D_002E94A8[];
struct Reg64 { u64 m0; u64 m8; };
extern Reg64 D_002BD7A8[];
// @decl-end

INCLUDE_ASM("asm/nonmatchings/Dk265918", func_00265918);

INCLUDE_ASM("asm/nonmatchings/Dk265918", func_002659A8);

INCLUDE_ASM("asm/nonmatchings/Dk265918", func_00265AE8);

INCLUDE_ASM("asm/nonmatchings/Dk265918", func_00265BB8);

INCLUDE_ASM("asm/nonmatchings/Dk265918", func_00265CD8);

INCLUDE_ASM("asm/nonmatchings/Dk265918", func_00265D98);

INCLUDE_ASM("asm/nonmatchings/Dk265918", func_00265F68);

INCLUDE_ASM("asm/nonmatchings/Dk265918", func_002660C8);

INCLUDE_ASM("asm/nonmatchings/Dk265918", func_00266198);

extern "C" void func_002662A8(const char *fmt, ...) { }

INCLUDE_ASM("asm/nonmatchings/Dk265918", func_002662D0);

extern "C" s32 func_00266510(s32 port) { D_41C1C0[0] = port; if (func_002760B0(D_41C0C0, 1, 0, D_41C1C0, 0x80, D_41C1C0, 0x80, 0, 0) < 0) { func_002662A8(D_002E9388); return 0; } return D_41C1C0[1]; }

extern "C" s32 func_00266580(s32 port) { D_41C1C0[0] = port; if (func_002760B0(D_41C0E8, 1, 0, D_41C1C0, 0x80, D_41C1C0, 0x80, 0, 0) < 0) { func_002662A8(D_002E93A8); return 0; } return D_41C1C0[1]; }

extern "C" s32 func_002665F0(s32 port) { D_41C1C0[0] = port; if (func_002760B0(D_41C110, 1, 0, D_41C1C0, 0x80, D_41C1C0, 0x80, 0, 0) < 0) { func_002662A8(D_002E93C8); return 0; } return D_41C1C0[1]; }

extern "C" s32 func_00266660(s32 port, s32 slot) { D_41C1C0[0] = port; D_41C1C0[1] = slot; if (func_002760B0(D_41C138, 1, 0, D_41C1C0, 0x80, D_41C1C0, 0x80, 0, 0) < 0) { func_002662A8(D_002E93F0); return 0; } return D_41C1C0[2]; }

extern "C" s32 func_002666D0(void) { if (func_002760B0(D_41C160, 1, 0, D_41C1C0, 0x80, D_41C1C0, 0x80, 0, 0) < 0) { func_002662A8(D_002E9418); return 0; } return D_41C1C0[0]; }

INCLUDE_ASM("asm/nonmatchings/Dk265918", func_00266738);

INCLUDE_ASM("asm/nonmatchings/Dk265918", func_002667C0);

INCLUDE_ASM("asm/nonmatchings/Dk265918", func_002669C0);

extern "C" s32 func_00266CD0(s32 a, s32 b, s32 c) { return func_002669C0(a, b, c, 0, -1); }

INCLUDE_ASM("asm/nonmatchings/Dk265918", func_00266CF0);

INCLUDE_ASM("asm/nonmatchings/Dk265918", func_00266DE8);

extern "C" s32 func_00266F38(void *p) { func_0026E5D8(p, 0x38); func_0026E5D8(p, 0x28); while (func_0026E520(p, 1) == 1) func_0026E5D8(p, 0x18); return 1; }

INCLUDE_ASM("asm/nonmatchings/Dk265918", func_00266FA8);

INCLUDE_ASM("asm/nonmatchings/Dk265918", func_00267558);

INCLUDE_ASM("asm/nonmatchings/Dk265918", func_00267608);

extern "C" s32 func_00267818(void) { return 1; }

extern "C" s32 func_00267820(SceMpeg *p, s32 a, s32 n) { func_002683F8(p->sys, a, (n + 19) / 16 * 16); return 1; }

extern "C" s32 func_00267860(SceMpeg *p, u32 a, s32 n) { MpegSys *o = p->sys; o->mC8 = 1; o->mF0 = (a & 0x0FFFFFFF) | 0x20000000; o->mFC = n; o->mF8 = 0; o->mF4 = 0; return func_00267CA0(p); }

INCLUDE_ASM("asm/nonmatchings/Dk265918", func_002678A8);

extern "C" s32 func_002678F0(SceMpeg *p, u32 a, s32 w, s32 h) { MpegSys *o = p->sys; o->mF8 = h << 4; o->mF0 = (a & 0x0FFFFFFF) | 0x20000000; o->mFC = w * h; o->mF4 = w << 4; o->mC8 = 0; return func_00267CA0(p); }

extern "C" void func_00267940(SceMpeg *p) { p->sys->m10A0 = 1; }

extern "C" void func_00267950(SceMpeg *p, s32 a, s32 b, s32 c) { MpegSys *o = p->sys; o->mAC = a; o->mB0 = b; o->mB4 = c; }

extern "C" void func_00267968(SceMpeg *p, s32 *a, s32 *b, s32 *c) { MpegSys *o = p->sys; *a = o->mAC; *b = o->mB0; *c = o->mB4; }

extern "C" s32 func_00267988(SceMpeg *p) { return p->sys->m0; }

extern "C" s32 func_00267998(SceMpeg *p) { return p->sys->m4 == 0; }

extern "C" s32 func_002679A8(SceMpeg *p) {
    MpegSys *o = p->sys;
    o->m10A0 = 0; o->m0 = 0; o->m4 = 0; o->m8 = 0;
    p->frameCount = 0; o->mC4 = 0; o->m98 = -1;
    func_00268290(o); o->m130 = 0; func_002681A0(o); return 1;
}

extern "C" s32 func_00267A08(SceMpeg *p) {
    MpegSys *o = p->sys; MpegBuf *q;
    if ((q = o->m1D0[0].m0) != 0) q->m28 = 0;
    if ((q = o->m1D0[1].m0) != 0) q->m28 = 0;
    if ((q = o->m1D0[2].m0) != 0) q->m28 = 0;
    if ((q = o->m1D0[0].m4) != 0) q->m28 = 0;
    if ((q = o->m1D0[1].m4) != 0) q->m28 = 0;
    if ((q = o->m1D0[2].m4) != 0) q->m28 = 0;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/Dk265918", func_00267A60);

INCLUDE_ASM("asm/nonmatchings/Dk265918", func_00267A98);

extern "C" s32 func_00267B10(s32 a) { struct { s32 m0; s32 pad[7]; } t; t.m0 = 1; func_00267A98(a, &t); return 1; }

extern "C" s32 func_00267B38(SceMpeg *p, s64 a) { p->sys->m8C = 1; p->sys->m90 = a; return 1; }

extern "C" s32 func_00267B50(SceMpeg *p) { p->sys->m8C = 0; p->sys->m90 = 0; return 1; }

extern "C" s32 func_00267B68(SceMpeg *p, s32 a) { p->sys->mF0 = a; return 1; }

extern "C" s32 func_00267B78(SceMpeg *p) { return p->sys->mE4; }

extern "C" s32 func_00267B88(SceMpeg *p) { return p->sys->mE8; }

extern "C" s32 *func_00267B98(SceMpeg *p) { return &p->sys->mCC; }

extern "C" s32 *func_00267BA8(SceMpeg *p) { return &p->sys->mCC; }

extern "C" s32 func_00267BB8(SceMpeg *p, s32 a) { s32 old = p->sys->m100; p->sys->m100 = a; return old; }

extern "C" s32 func_00267BC8(SceMpeg *p, s64 a) { MpegSys *o = p->sys; o->m108 = a; o->m110 = 1; return 1; }

extern "C" void func_00267BE0(Q4 *p, s32 a, s32 b) { p->m0 = a; p->m4 = b; p->m8 = a; p->mC = a; }

extern "C" void func_00267BF8(Q4 *p) { p->mC = p->m8; }

extern "C" void func_00267C08(Q4 *p) { p->m8 = p->mC; }

extern "C" u32 func_00267C18(MpegSys *s, Q4 *q, s32 size, u32 align) {
    u32 p = (q->m8 + align - 1) / align * align;
    if ((u32)(q->m0 + q->m4) >= p + size) { q->m8 = p + size; return p; }
    func_002683A0(s, D_002E94A8); return 0;
}

extern "C" s32 func_00267C88(Q4 *p) { return p->m0 + p->m4 - p->m8; }

INCLUDE_ASM("asm/nonmatchings/Dk265918", func_00267CA0);

INCLUDE_ASM("asm/nonmatchings/Dk265918", func_00267E58);

extern "C" s32 func_00267F78(SceMpeg *p, s32 a, s32 b) { if (p->sys->m18C != 3) return func_00267FC0(p, a, b); return func_00267E58(p, a, b); }

INCLUDE_ASM("asm/nonmatchings/Dk265918", func_00267FC0);
