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
extern "C" s32 func_00268290(MpegSys *);
extern "C" void func_002681B0(MpegSys *);
extern "C" void func_00268358(const char *);
// @decl-end

INCLUDE_ASM("asm/nonmatchings/Dk268138", func_00268138);

extern "C" void func_002681A0(MpegSys *s) { s->m860 = 0; func_0026AA48(1); return; }

INCLUDE_ASM("asm/nonmatchings/Dk268138", func_002681B0);

extern "C" void func_00268230(MpegSys *o) { u32 spr = 0x70000000; func_0026AA48(1); o->m5A8 = spr; o->m5AC = 0x70001800; o->m6E8 = 0x70001B00; o->m6EC = 0x70003300; o->m828 = 0; }

INCLUDE_ASM("asm/nonmatchings/Dk268138", func_00268290);

extern "C" void func_00268358(const char *msg) { func_00274F10(D_002E95A8, msg); }

extern "C" s32 func_00268368(MpegSys *x, const char *fmt, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) { char buf[0x100]; sprintf(buf, fmt, a, b, c, d, e, f); return func_002683A0(x, buf); }

extern "C" s32 func_002683A0(MpegSys *s, const char *msg) {
    SceMpeg *mp = s->m870;
    if (mp && s && s->mC[0].m0) { struct { s32 m0; const char *m4; } m; m.m0 = 0; m.m4 = msg; return func_00267A98(mp, &m); }
    func_00268358(msg);
}

INCLUDE_ASM("asm/nonmatchings/Dk268138", func_002683F8);

extern "C" s32 func_002684F8(Q4 *p, s32 a, s32 b) { p->m4 = a; p->m8 = b; p->mC = a >> 4; p->m10 = b >> 4; return 1; }

INCLUDE_ASM("asm/nonmatchings/Dk268138", func_00268518);

INCLUDE_ASM("asm/nonmatchings/Dk268138", func_00268640);

INCLUDE_ASM("asm/nonmatchings/Dk268138", func_002688E8);

INCLUDE_ASM("asm/nonmatchings/Dk268138", func_002689C8);

INCLUDE_ASM("asm/nonmatchings/Dk268138", func_00268AA8);

INCLUDE_ASM("asm/nonmatchings/Dk268138", func_00268BD8);

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
