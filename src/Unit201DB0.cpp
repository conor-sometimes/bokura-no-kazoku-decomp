#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CVec4 { public: f32 x, y, z, w; };
extern "C" void func_00201820(void);
extern "C" void func_002042C0(s32, s32, s32, s32, s32, s32, s32);
extern "C" void func_00201998(void);
extern "C" void func_00201B38(void);
extern f32 D_30E440[4];
extern u8 D_30E490[4];
extern s32 D_30E3C4;
extern CVec4 D_30E210, D_30E220, D_30E230, D_30E240, D_30E2C0, D_30E300, D_30E380, D_30E430;
extern CVec4 D_30E3D0[3];
extern CVec4 D_30E400[3];
extern f32 D_002A5D14;
extern f32 D_002A5D18;
extern f32 D_002A5D1C;
extern f32 D_002A5D20;
extern f32 D_002A5D24;
extern f32 D_002A5D28;
extern f32 D_002A5D2C;
extern f32 D_002A5D30;
extern f32 D_002A5D34;
extern f32 D_002A5D38;
extern f32 D_002A5D3C;
extern f32 D_002A5D40;
extern f32 D_002A5D44;
extern f32 D_002A5D48;
extern f32 D_002A5D4C;
extern s32 D_002A5D50;
extern s32 D_002A5D54;
extern s32 D_002A5D58;
extern s32 D_002A5D5C;
extern s32 D_002A5D60;
extern s32 D_002A5D64;

struct GsSub { u64 m0; u64 m8; u64 m10; u64 m18; };
struct GsCtx { u8 pad0[0x20]; GsSub m20; };
extern "C" s32 func_0023A0E8(void);
extern "C" s32 func_0023A2F0(s32);
extern "C" void func_00227A20(void);
extern "C" void func_00226DF8(u64, u64);
extern "C" s32 func_00227AA8(void);
extern "C" s32 func_00202C08(s32, void *, s32);
struct Ent2A5D0C { char *m0; s32 m4; s32 m8; u8 padC[0x34 - 0xC]; };
extern Ent2A5D0C *D_002A5D0C;
// @decl-end

extern "C" void func_00201DB0(f32 *v) {
    D_30E440[0] = v[0]; D_30E440[1] = v[1]; D_30E440[2] = v[2]; D_30E440[3] = v[3];
}

void Func201DE0(int r, int g, int b) {
    *(s32 *)D_30E490 = (s64)r | ((s64)g << 8) | ((s64)b << 16);
}

extern "C" void func_00201E08(s32 *r, s32 *g, s32 *b) {
    *r = D_30E490[0]; *g = D_30E490[1]; *b = D_30E490[2];
}

void Func201E30(f32 a, f32 b) { D_002A5D3C = a; D_002A5D40 = b; D_30E3C4 = 1; }

extern "C" void func_00201E50(f32 *a, f32 *b) { *a = D_002A5D3C; *b = D_002A5D40; }

extern "C" void func_00201E70(f32 a, f32 b) { D_002A5D44 = a; D_002A5D48 = b; D_30E3C4 = 1; }

extern "C" void func_00201E90(f32 *a, f32 *b) { *a = D_002A5D44; *b = D_002A5D48; }

extern "C" void func_00201EB0(f32 a) { D_002A5D4C = a; D_30E3C4 = 1; }

extern "C" f32 func_00201EC8(void) { return D_002A5D4C; }

extern "C" void func_00201ED8(f32 a, f32 b) { D_002A5D14 = a; D_002A5D18 = b; D_30E3C4 = 1; }

extern "C" void func_00201EF8(f32 *a, f32 *b) { *a = D_002A5D14; *b = D_002A5D18; }

extern "C" void func_00201F18(f32 a, f32 b) { D_002A5D1C = a; D_002A5D20 = b; D_30E3C4 = 1; }

extern "C" void func_00201F38(f32 *a, f32 *b) { *a = D_002A5D1C; *b = D_002A5D20; }

extern "C" void func_00201F58(f32 a, f32 b, f32 c, f32 d, f32 e, f32 f) {
    D_002A5D34 = c; D_002A5D38 = d; D_002A5D24 = a; D_002A5D28 = b; D_002A5D2C = e; D_002A5D30 = f;
    D_30E3C4 = 1;
}

extern "C" void func_00201F98(f32 *a, f32 *b) { *a = D_002A5D24; *b = D_002A5D28; }

extern "C" void func_00201FB8(f32 *a, f32 *b) { *a = D_002A5D34; *b = D_002A5D38; }

extern "C" void func_00201FD8(f32 *a, f32 *b) { *a = D_002A5D2C; *b = D_002A5D30; }

extern "C" void func_00201FF8(f32 a, f32 b, f32 c, f32 d) {
    func_00201F58(a, b, c, d, a, b);
    return;
}

extern "C" void func_00202018(s32 v) { D_002A5D50 = v; D_30E3C4 = 1; }

extern "C" s32 func_00202030(void) { return D_002A5D50; }

INCLUDE_ASM("asm/nonmatchings/Unit201DB0", func_00202040);

INCLUDE_ASM("asm/nonmatchings/Unit201DB0", func_00202168);

extern "C" s32 func_00202280(void) { return D_002A5D54; }

extern "C" void func_00202290(s32 v) { D_002A5D54 = v; }

CVec4 *Func2022A0(void) { func_00201820(); return &D_30E240; }

extern "C" CVec4 *func_002022C8(void) { return &D_30E220; }

extern "C" CVec4 *func_002022D8(void) { return &D_30E210; }

extern "C" f32 *func_002022E8(void) { return D_30E440; }

extern "C" CVec4 *func_002022F8(void) { return &D_30E230; }

CVec4 *Func202308(void) { func_00201998(); func_00201B38(); return &D_30E300; }

CVec4 *Func202338(void) { func_00201998(); func_00201B38(); return &D_30E380; }

extern "C" CVec4 *func_00202368(void) { func_00201998(); return &D_30E2C0; }

CVec4 *Func202390(void) { return &D_30E430; }

CVec4 *Func2023A0(int i) { return &D_30E400[i]; }

CVec4 *Func2023B8(int i) { return &D_30E3D0[i]; }

extern "C" void func_002023D0(s32 v) { D_002A5D58 = v; }

extern "C" s32 func_002023E0(void) { return D_002A5D58; }

extern "C" void func_002023F0(s32 v) { D_002A5D5C = v; }

extern "C" s32 func_00202400(void) { return D_002A5D5C; }

extern "C" void func_00202410(s32 v) { D_002A5D60 = v; }

extern "C" s32 func_00202420(void) { return D_002A5D60; }

INCLUDE_RODATA("asm/nonmatchings/Unit201DB0", D_002E2990);
INCLUDE_RODATA("asm/nonmatchings/Unit201DB0", D_002E29A0);
INCLUDE_RODATA("asm/nonmatchings/Unit201DB0", D_002E29B0);
INCLUDE_RODATA("asm/nonmatchings/Unit201DB0", D_002E29C0);
INCLUDE_RODATA("asm/nonmatchings/Unit201DB0", D_002E29D0);
INCLUDE_RODATA("asm/nonmatchings/Unit201DB0", D_002E29E0);
INCLUDE_RODATA("asm/nonmatchings/Unit201DB0", D_002E29F0);
INCLUDE_RODATA("asm/nonmatchings/Unit201DB0", D_002E2A00);
INCLUDE_ASM("asm/nonmatchings/Unit201DB0", func_00202430);

extern "C" void func_002025E0(void) {
}

extern "C" s32 func_002025E8(s32 v) { s32 old = D_002A5D64; D_002A5D64 = v; return old; }

INCLUDE_ASM("asm/nonmatchings/Unit201DB0", func_00202600);

INCLUDE_ASM("asm/nonmatchings/Unit201DB0", func_00202A60);

INCLUDE_ASM("asm/nonmatchings/Unit201DB0", func_00202C08);

INCLUDE_ASM("asm/nonmatchings/Unit201DB0", func_00202D68);

INCLUDE_ASM("asm/nonmatchings/Unit201DB0", func_00203108);

INCLUDE_ASM("asm/nonmatchings/Unit201DB0", func_002032F8);

INCLUDE_ASM("asm/nonmatchings/Unit201DB0", func_00203500);

INCLUDE_ASM("asm/nonmatchings/Unit201DB0", func_00203708);

extern "C" s32 func_00203910(s32 a) {
    GsCtx *p = (GsCtx *)D_002A5D58;
    GsSub *q;
    u64 lo, hi;
    if (!p) p = (GsCtx *)func_0023A2F0(func_0023A0E8());
    q = &p->m20;
    lo = q->m10 | ((u64)a << 32);
    hi = q->m18;
    func_00227A20();
    func_00226DF8(hi, lo);
    return func_00227AA8();
}

extern "C" s32 func_00203978(s32 i, s32 a, void *b) {
    Ent2A5D0C *e = &D_002A5D0C[i];
    if (!e || !e->m8) return 0;
    func_00201998();
    return func_00202C08(e->m4, b ? b : e->m0 + 0x10, a);
}

INCLUDE_ASM("asm/nonmatchings/Unit201DB0", func_00203A18);

INCLUDE_ASM("asm/nonmatchings/Unit201DB0", func_002042C0);

extern "C" void func_00204380(s32 a, s32 b, s32 c, s32 d) {
    func_002042C0(a, b, c, d, 0, 0, 0);
    return;
}

extern "C" void func_002043A0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    func_002042C0(a, b, c, d, e, f, 0);
    return;
}

INCLUDE_ASM("asm/nonmatchings/Unit201DB0", func_002043B8);
