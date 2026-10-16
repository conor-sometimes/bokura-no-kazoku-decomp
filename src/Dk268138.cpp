#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "sceMpeg.h"
struct Q4 { s32 m0, m4, m8, mC, m10; };
extern "C" void func_0026AA48(s32);
extern "C" s32 func_00274F10(const char *, ...);
extern const char D_002E95A8[];
extern "C" s32 func_002683A0(MpegSys *, const char *);
extern const char D_002E9618[];
extern const char D_002E9648[];
extern const char D_002E9660[];
extern const char D_002E9698[];
extern "C" void func_0027E260(u8 *);
extern "C" void func_0027E348(u8 *);

extern "C" s32 sprintf(char *, const char *, ...);
extern "C" s32 func_00267A98(SceMpeg *, void *);
extern "C" void func_00268290(MpegSys *);
extern "C" void func_002681B0(MpegSys *);
extern "C" void func_00268358(const char *);

extern "C" s32 func_0026C4A8(MpegSys *, s32);

extern "C" void func_0027E498(s32, s32);
extern "C" s32 func_0027BD20(void);
extern "C" s32 func_0027BD78(void);
#define REG(a) (*(volatile u32 *)(a))

extern "C" void func_0026C8E8(MpegSys *);
extern "C" void func_0026BD18(MpegSys *);
extern "C" void func_0026BCE8(MpegSys *, u32);
extern "C" void func_00268640(SceMpeg *);
extern "C" void func_002689C8(MpegSys *, u32, u32);
extern u8 D_002BD880[];
extern u8 D_002BD8C0[];
extern const char D_002E95B8[];
extern const char D_002E95D0[];
extern const char D_002E95F8[];

#define UNC(x) (((x) & 0x0FFFFFFF) | 0x20000000)

extern "C" void func_0026D898(MpegSys *, MpegBuf *, s32);
extern "C" void func_0026D9A8(MpegSys *, MpegBuf *, MpegBuf *, s32);
extern const char D_002E9588[];
// @decl-end

extern "C" s32 func_00268138(SceMpeg *p) { MpegSys *o = p->sys; s32 r = 0; if (o->m4 && o->m8) { func_002681B0(o); r = 1; p->frameCount = o->m130 - o->mC4; o->m4 = 0; } return r; }

extern "C" void func_002681A0(MpegSys *s) { s->m860 = 0; func_0026AA48(1); return; }

extern "C" void func_002681B0(MpegSys *m) { s32 n = m->m130; if (m->m138) { func_002683A0(m, D_002E9588); m->m138 = 0; return; } if (m->m18C == 3) func_0026D898(m, m->m1D0[0].m4, n - 1); else func_0026D9A8(m, m->m1D0[1].m4, m->m1D0[2].m4, n - 1); m->m138 = 0; }

extern "C" void func_00268230(MpegSys *o) { u32 spr = 0x70000000; func_0026AA48(1); o->m5A8 = spr; o->m5AC = 0x70001800; o->m6E8 = 0x70001B00; o->m6EC = 0x70003300; o->m828 = 0; }

extern "C" void func_00268290(MpegSys *s) {
    s32 r;
    s->m830 = 1; s->m1C8 = 0;
    r = func_0027BD20();
    REG(0x1000F590) = REG(0x1000F520) | 0x10000;
    REG(0x1000B000) = 0; REG(0x1000B400) = 0; REG(0x1000D400) = 0;
    REG(0x1000F590) = REG(0x1000F520) & ~0x10000;
    if (r) func_0027BD78();
    REG(0x1000B020) = 0; REG(0x1000B420) = 0; REG(0x1000D420) = 0;
    REG(0x10002010) = 0x40000000;
    func_0027E498(0, 0);
}

extern "C" void func_00268358(const char *msg) { func_00274F10(D_002E95A8, msg); }

extern "C" s32 func_00268368(MpegSys *x, const char *fmt, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) { char buf[0x100]; sprintf(buf, fmt, a, b, c, d, e, f); return func_002683A0(x, buf); }

extern "C" s32 func_002683A0(MpegSys *s, const char *msg) {
    SceMpeg *mp = s->m870;
    if (mp && s && s->mC[0].m0) { struct { s32 m0; const char *m4; } m; m.m0 = 0; m.m4 = msg; return func_00267A98(mp, &m); }
    func_00268358(msg);
}

INCLUDE_ASM("asm/nonmatchings/Dk268138", func_002683F8);

extern "C" s32 func_002684F8(Q4 *p, s32 a, s32 b) { p->m4 = a; p->m8 = b; p->mC = a >> 4; p->m10 = b >> 4; return 1; }

extern "C" void func_00268518(MpegSys *s) {
    u32 v;
    s->mEC = 0;
    v = func_0026C4A8(s, 32);
    s->m13C = v >> 20; s->m140 = (v >> 8) & 0xFFF;
    if (s->m140 > 0xAF0) func_002683A0(s, D_002E95B8);
    v = func_0026C4A8(s, 30);
    s->m14C = v >> 12; s->m150 = (v >> 1) & 0x3FF;
    if ((s->m858 = func_0026C4A8(s, 1))) { func_0026BD18(s); func_0026BCE8(s, 0x50000000); func_0026BD18(s); }
    else func_002689C8(s, 0x50000000, (u32)D_002BD880);
    if ((s->m85C = func_0026C4A8(s, 1))) { func_0026BD18(s); func_0026BCE8(s, 0x58000000); func_0026BD18(s); }
    else func_002689C8(s, 0x58000000, (u32)D_002BD8C0);
    func_0026C8E8(s);
    func_00268640(s->m870);
}

INCLUDE_ASM("asm/nonmatchings/Dk268138", func_00268640);

INCLUDE_ASM("asm/nonmatchings/Dk268138", func_002688E8);

extern "C" void func_002689C8(MpegSys *s, u32 cmd, u32 addr) {
    struct { s32 m0; s32 pad[7]; } cb;
    s32 r;
    cb.m0 = 2; func_00267A98(s->m870, &cb);
    func_0026BD18(s);
    *(volatile u32 *)0x10002000 = 0;
    func_0026BD18(s);
    r = func_0027BD20();
    *(volatile u32 *)0x1000B410 = addr & 0x0FFFFFFF;
    *(volatile u32 *)0x1000B420 = 4;
    *(volatile u32 *)0x1000B400 = 0x101;
    if (r) func_0027BD78();
    func_0026BCE8(s, cmd);
    func_0026BD18(s);
    cb.m0 = 3; func_00267A98(s->m870, &cb);
}

extern "C" void func_00268AA8(MpegSys *s) {
    u32 v, w, prof;
    s32 hext, vext, brext, vbvext;
    s->m860 = 1; func_0026AA48(0);
    v = func_0026C4A8(s, 0x1C);
    brext = (v >> 1) & 0xFFF; vext = (v >> 13) & 3; hext = (v >> 15) & 3;
    s->m158 = (v >> 17) & 3;
    if (s->m158 != 1) func_002683A0(s, D_002E95D0);
    s->m154 = (v >> 19) & 1;
    prof = v >> 20;
    w = func_0026C4A8(s, 16);
    vbvext = w >> 8;
    if (prof != 0x48 && prof != 0x58 && prof != 0x44) func_002683A0(s, D_002E95F8);
    s->m13C = (hext << 12) | (s->m13C & 0xFFF);
    s->m140 = (vext << 12) | (s->m140 & 0xFFF);
    s->m14C += brext << 18;
    s->m150 += vbvext << 10;
}

extern "C" void func_00268BD8(MpegSys *d) {
    func_0026C4A8(d, 3);
    if (func_0026C4A8(d, 1)) { func_0026C4A8(d, 8); func_0026C4A8(d, 8); d->m15C = func_0026C4A8(d, 8); }
    d->m160 = func_0026C4A8(d, 0xE);
    func_0026C4A8(d, 1);
    d->m164 = func_0026C4A8(d, 0xE);
}

extern "C" void func_00268C68(MpegSys *s) { func_002683A0(s, D_002E9618); }

extern "C" void func_00268C78(MpegSys *s) { func_002683A0(s, D_002E9648); }

extern "C" void func_00268C88(MpegSys *s) { func_002683A0(s, D_002E9660); }

extern "C" void func_00268C98(MpegSys *s) { func_002683A0(s, D_002E9698); }

extern "C" s32 func_00268CA8(SceMpeg *p) { func_0027E260(p->sys->m68); return 1; }

extern "C" s32 func_00268CD0(SceMpeg *p) { func_0027E348(p->sys->m68); return 1; }

// Two padding nops: 0x268D00 is 16-byte aligned, probably the start of another object (.p2align 4
// here would raise this object's alignment and move it).
asm(".space 8");

INCLUDE_ASM("asm/nonmatchings/Dk268138", func_00268D00);

INCLUDE_ASM("asm/nonmatchings/Dk268138", func_00268F50);

INCLUDE_ASM("asm/nonmatchings/Dk268138", func_00269658);

INCLUDE_ASM("asm/nonmatchings/Dk268138", func_00269A78);

INCLUDE_ASM("asm/nonmatchings/Dk268138", func_00269C98);

INCLUDE_ASM("asm/nonmatchings/Dk268138", func_00269D10);

INCLUDE_ASM("asm/nonmatchings/Dk268138", func_00269DA8);

INCLUDE_ASM("asm/nonmatchings/Dk268138", func_00269E60);

INCLUDE_ASM("asm/nonmatchings/Dk268138", func_00269F30);

INCLUDE_ASM("asm/nonmatchings/Dk268138", func_00269FE0);

INCLUDE_ASM("asm/nonmatchings/Dk268138", func_0026A098);

INCLUDE_ASM("asm/nonmatchings/Dk268138", func_0026A190);

INCLUDE_ASM("asm/nonmatchings/Dk268138", func_0026A290);

INCLUDE_ASM("asm/nonmatchings/Dk268138", func_0026A330);

INCLUDE_ASM("asm/nonmatchings/Dk268138", func_0026A3E0);

INCLUDE_ASM("asm/nonmatchings/Dk268138", func_0026A4C0);

INCLUDE_ASM("asm/nonmatchings/Dk268138", func_0026A5A8);

INCLUDE_ASM("asm/nonmatchings/Dk268138", func_0026A680);

INCLUDE_ASM("asm/nonmatchings/Dk268138", func_0026A750);
