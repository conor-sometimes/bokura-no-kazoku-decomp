#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "linkonce.h"
extern "C" {
extern TypeInfo D_424F30;
TypeInfo *func_0029E0A8();
extern const char D_002E77C8[];
extern TypeInfo D_424F10;
extern TypeInfo D_424F40;
TypeInfo *func_0029E0F8();
extern const char D_002E77D8[];
extern TypeInfo D_424F60;
TypeInfo *__tf8CListTag();
extern const char D_002E77E8[];
extern TypeInfo D_2EB708;
extern const char D_002E7800[];
extern TypeInfo D_424F70;
TypeInfo *__tf8CSndWork();
extern const char D_002E7818[];
extern TypeInfo D_424F80;
TypeInfo *__tf8CSndUnit();
extern const char D_002E7880[];
extern TypeInfo D_424F90;
TypeInfo *__tf10CSndUnitTg();
extern const char D_002E7890[];
extern TypeInfo D_424FB0;
extern const char D_002E7908[];
extern TypeInfo D_424FA0;
TypeInfo *__tf11CSndUnitSeq();
extern const char D_002E7918[];
extern TypeInfo D_424FC0;
extern const char D_002E79A8[];
extern TypeInfo D_424FD0;
TypeInfo *__tf11CSndUnitStr();
extern const char D_002E79B8[];
extern TypeInfo D_2EB910;
extern const char D_002EAC70[];
extern TypeInfo D_4253F0;
TypeInfo *__tf9exception();
extern const char D_002EAC80[];
extern TypeInfo D_2EB918;
extern TypeInfo D_4253E0;
extern const char D_002EAC90[];
extern TypeInfo D_425400;
TypeInfo *__tf9type_info();
extern const char D_002EACA0[];
}

#include "linkonce.h"
extern "C" {
extern char _vt$12CSndWorkReal[];
void func_0025C2C0(void *, s32);
extern char _vt$16__user_type_info[];
void func_00286B20(void *, s32);
}

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern "C" void Func25DB88__FP7CSndObjP5CVec4(void *, void *);
extern "C" int func_00286B58(void *, void *);
struct W2Snd70 { u8 m0; u8 m1; u8 m2; u8 m3; };

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern "C" s32 SW_Func25CB90(void *, s32, s32, s32) asm("Func25CB90__8CSndWorkiii");

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern "C" void SW_Func25CC18(void *, s32, s32, s32) asm("Func25CC18__8CSndWorkiii");

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern u8 W2vt_bad_cast[] asm("_vt$8bad_cast");
extern u8 W2vt_bad_typeid[] asm("_vt$10bad_typeid");

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern u8 W2vt_ti[] asm("_vt$9type_info");
extern u8 W2vt_user2[] asm("_vt$16__user_type_info");

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern u8 W2vt_exc[] asm("_vt$9exception");

extern u8 W2s__vt_t12TSndUnitReal1Z11CSndUnitSeq[] asm("_vt$t12TSndUnitReal1Z11CSndUnitSeq");
extern "C" void W2s_func_0025EDB8(void *, s32) asm("func_0025EDB8");
extern "C" void W2s_Func25E030__FPv(void *) asm("Func25E030__FPv");
extern u8 W2s__vt_t12TSndUnitReal1Z11CSndUnitStr[] asm("_vt$t12TSndUnitReal1Z11CSndUnitStr");
extern "C" void W2s_func_0025F9A8(void *, s32) asm("func_0025F9A8");
extern u8 W2s__vt_t12TSndUnitReal1Z10CSndUnitTg[] asm("_vt$t12TSndUnitReal1Z10CSndUnitTg");
extern "C" void W2s_func_0025E340(void *, s32) asm("func_0025E340");

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern "C" void *W2F25DBF8(void *) asm("Func25DBF8__FP8CSndObj2");
extern "C" void func_0025D608(void *, void *, s32);
struct W2SO { s32 a, b, c; virtual void v0(); virtual void *v1(); };

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
// @decl-end

extern "C" TypeInfo *__tf8CSndWork()
{
    if (!D_424F30.vptr) {
        func_0029E0A8();
        func_00286BC0(&D_424F30, D_002E77C8, &D_424F10);
    }
    return &D_424F30;
}

extern "C" s32 func_0029DEB8(void *p) { return FLD(s32, p, 0x10); }

extern "C" void func_0029DEC0(void *p, s32 a, s32 b) { if (b >= 0) { SW_Func25CB90(p, a, b, b); return; } SW_Func25CB90(p, a, b, -b); }

extern "C" void func_0029DEF8(void *p, s32 id, f32 x) { s32 v = (s32)(x * 128.0f); if (v >= 0) { SW_Func25CB90(p, id, v, v); return; } SW_Func25CB90(p, id, v, -v); }

extern "C" void func_0029DF48(void *p, s32 id, f32 v, s32 b) { SW_Func25CC18(p, id, (s32)(v * 128.0f), b); }

extern "C" void func_0029DF80(void *p, u8 v) { FLD(u8, p, 0x36) = v; FLD(u8, p, 0x34) = 1; }

extern "C" void func_0029DF90(void *p, s32 v) { if (v >= 0) { FLD(s16, p, 0x3E) = v; FLD(s16, p, 0x3C) = v; } else { FLD(s16, p, 0x3C) = v; FLD(s16, p, 0x3E) = -v; } FLD(u8, p, 0x34) = 1; }

extern "C" void func_0029DFC0(void *p, f32 f) { FLD(u8, p, 0x34) = 1; s32 v = (s32)(f * 128.0f); FLD(s16, p, 0x3E) = v; FLD(s16, p, 0x3C) = v; }

extern "C" void func_0029DFE8(void *p, f32 f) { FLD(u8, p, 0x34) = 1; FLD(f32, p, 0x44) = f; FLD(f32, p, 0x40) = f; }

extern "C" void func_0029E000(void *p, f32 f) { FLD(u8, p, 0x34) = 1; FLD(f32, p, 0x4C) = f; }

extern "C" void func_0029E010(void *p, s16 a, s16 b) { FLD(u8, p, 0x34) = 1; FLD(s16, p, 0x3E) = b; FLD(s16, p, 0x3C) = a; }

extern "C" s32 func_0029E028(void *p) { return 0; }

extern "C" TypeInfo *__tf8CSndUnit()
{
    if (!D_424F40.vptr) {
        func_0029E0F8();
        func_00286BC0(&D_424F40, D_002E77D8, &D_424F60);
    }
    return &D_424F40;
}

extern "C" s32 func_0029E080(void *p) { return (FLD(s32, p, 0x54) & 4) ? 2 : 1; }

extern "C" void func_0029E098(void) {
}

extern "C" s32 func_0029E0A0(void *p) { return 0; }

extern "C" TypeInfo *func_0029E0A8()
{
    if (!D_424F10.vptr) {
        __tf8CListTag();
        func_00286BC0(&D_424F10, D_002E77E8, &D_2EB708);
    }
    return &D_424F10;
}

extern "C" TypeInfo *func_0029E0F8()
{
    if (!D_424F60.vptr) {
        __tf8CListTag();
        func_00286BC0(&D_424F60, D_002E7800, &D_2EB708);
    }
    return &D_424F60;
}

extern "C" void func_0029E148(void *p, s32 flag)
{
    FLD(void *, p, 0xC) = _vt$12CSndWorkReal;
    func_0025C2C0(p, 0);
    if (flag & 1) return __builtin_delete(p);
}

extern "C" TypeInfo *__tf12CSndWorkReal()
{
    if (!D_424F70.vptr) {
        __tf8CSndWork();
        func_00286BC0(&D_424F70, D_002E7818, &D_424F30);
    }
    return &D_424F70;
}

extern "C" void func_0029E200(void *p, s32 v) { W2Snd70 *s = (W2Snd70 *)((u8 *)p + 0x70); s->m0 = (s->m0 & 0x8F) | v; }

extern "C" void func_0029E218(void *p, void *v) { Func25DB88__FP7CSndObjP5CVec4((u8 *)p + 0x70, v); }

extern "C" void func_0029E238(void *p, u8 a, f32 b, f32 c, f32 d, f32 e) { u8 *s = (u8 *)p + 0x70;  s[1] = a; FLD(f32, s, 4) = b; FLD(f32, s, 8) = c; FLD(f32, s, 0xC) = d; FLD(f32, s, 0x10) = e; s[0] |= 0x10; }

extern "C" void func_0029E260(void *p, u8 v) { W2Snd70 *s = (W2Snd70 *)((u8 *)p + 0x70); s->m2 = v; s->m0 |= 0x20; }

extern "C" void func_0029E278(void *p, u8 v) { W2Snd70 *s = (W2Snd70 *)((u8 *)p + 0x70); s->m3 = v; s->m0 |= 0x40; }

extern "C" void *func_0029E290(void *p) { return p; }

extern "C" void *func_0029E298(void *p) { return (u8 *)p + 0x70; }

extern "C" TypeInfo *__tf10CSndUnitTg()
{
    if (!D_424F80.vptr) {
        __tf8CSndUnit();
        func_00286BC0(&D_424F80, D_002E7880, &D_424F40);
    }
    return &D_424F80;
}

extern "C" void func_0029E2F0(void *p, s32 c) { *(void **)((u8 *)p + 0xc) = W2s__vt_t12TSndUnitReal1Z10CSndUnitTg; W2s_func_0025E340(p, 0); if (c & 1) { W2s_Func25E030__FPv(p); return; } }

extern "C" TypeInfo *__tft12TSndUnitReal1Z10CSndUnitTg()
{
    if (!D_424F90.vptr) {
        __tf10CSndUnitTg();
        func_00286BC0(&D_424F90, D_002E7890, &D_424F80);
    }
    return &D_424F90;
}

extern "C" void func_0029E3A8(void *p, s32 x) { void *r = FLD(W2SO *, p, 0x10)->v1(); if (r) { void *s = W2F25DBF8(r); if (s) func_0025D608((u8 *)p + 0xC0, s, x); } }

extern "C" void *func_0029E418(void *p) { return (u8 *)p + 0xC0; }

extern "C" TypeInfo *__tf11CSndUnitSeq()
{
    if (!D_424FB0.vptr) {
        __tf8CSndUnit();
        func_00286BC0(&D_424FB0, D_002E7908, &D_424F40);
    }
    return &D_424FB0;
}

extern "C" void func_0029E470(void *p, s32 c) { *(void **)((u8 *)p + 0xc) = W2s__vt_t12TSndUnitReal1Z11CSndUnitSeq; W2s_func_0025EDB8(p, 0); if (c & 1) { W2s_Func25E030__FPv(p); return; } }

extern "C" TypeInfo *__tft12TSndUnitReal1Z11CSndUnitSeq()
{
    if (!D_424FA0.vptr) {
        __tf11CSndUnitSeq();
        func_00286BC0(&D_424FA0, D_002E7918, &D_424FB0);
    }
    return &D_424FA0;
}

extern "C" void func_0029E528(void *p, s32 x) { void *r = FLD(W2SO *, p, 0x10)->v1(); if (r) { void *s = W2F25DBF8(r); if (s) func_0025D608((u8 *)p + 0xC0, s, x); } }

extern "C" void *func_0029E598(void *p) { return (u8 *)p + 0xC0; }

extern "C" TypeInfo *__tf11CSndUnitStr()
{
    if (!D_424FC0.vptr) {
        __tf8CSndUnit();
        func_00286BC0(&D_424FC0, D_002E79A8, &D_424F40);
    }
    return &D_424FC0;
}

extern "C" void func_0029E5F0(void *p, s32 c) { *(void **)((u8 *)p + 0xc) = W2s__vt_t12TSndUnitReal1Z11CSndUnitStr; W2s_func_0025F9A8(p, 0); if (c & 1) { W2s_Func25E030__FPv(p); return; } }

extern "C" TypeInfo *__tft12TSndUnitReal1Z11CSndUnitStr()
{
    if (!D_424FD0.vptr) {
        __tf11CSndUnitStr();
        func_00286BC0(&D_424FD0, D_002E79B8, &D_424FC0);
    }
    return &D_424FD0;
}

extern "C" void func_0029E6A8(void *p, s32 x) { void *r = FLD(W2SO *, p, 0x10)->v1(); if (r) { void *s = W2F25DBF8(r); if (s) func_0025D608((u8 *)p + 0xE0, s, x); } }

extern "C" void *func_0029E718(void *p) { return (u8 *)p + 0xE0; }

extern "C" TypeInfo *__tf9type_info()
{
    if (!D_2EB910.vptr) func_00286BE0(&D_2EB910, D_002EAC70);
    return &D_2EB910;
}

extern "C" void *func_0029E760(void *p, const char *n) { FLD(const char *, p, 0) = n; FLD(void *, p, 4) = W2vt_ti; }

extern "C" s32 func_0029E778(void *p) { return FLD(s32, p, 0x0); }

extern "C" s32 func_0029E780(void *a, void *b) { return func_00286B58(a, b) ^ 1; }

extern "C" TypeInfo *__tf8bad_cast()
{
    if (!D_4253F0.vptr) {
        __tf9exception();
        func_00286BC0(&D_4253F0, D_002EAC80, &D_2EB918);
    }
    return &D_4253F0;
}

extern "C" void *func_0029E7F0(void *p) { *(void **)p = W2vt_bad_cast; }

extern "C" void func_0029E800(void *p, s32 c) { *(void **)p = W2vt_exc; if (c & 1) { __builtin_delete(p); return; } }

extern "C" TypeInfo *__tf10bad_typeid()
{
    if (!D_4253E0.vptr) {
        __tf9exception();
        func_00286BC0(&D_4253E0, D_002EAC90, &D_2EB918);
    }
    return &D_4253E0;
}

extern "C" void *func_0029E888(void *p) { *(void **)p = W2vt_bad_typeid; }

extern "C" void func_0029E898(void *p, s32 c) { *(void **)p = W2vt_exc; if (c & 1) { __builtin_delete(p); return; } }

extern "C" void func_0029E8D0(void *p, s32 flag)
{
    FLD(void *, p, 0x4) = _vt$16__user_type_info;
    func_00286B20(p, 0);
    if (flag & 1) return __builtin_delete(p);
}

extern "C" TypeInfo *__tf16__user_type_info()
{
    if (!D_425400.vptr) {
        __tf9type_info();
        func_00286BC0(&D_425400, D_002EACA0, &D_2EB910);
    }
    return &D_425400;
}

extern "C" void *func_0029E988(void *p, const char *n) { FLD(const char *, p, 0) = n; FLD(void *, p, 4) = W2vt_user2; }

extern "C" s32 func_0029E9A0(s32 x) { return x >= 4; }

extern "C" s32 func_0029E9B0(s32 x) { return x >= 6; }

extern "C" s32 func_0029E9C0(s32 x) { return (x & 6) == 4; }

extern "C" s32 func_0029E9D0(s32 x) { return (x & 5) == 4; }

extern "C" s32 func_0029E9E0(s32 x) { return (x & 5) == 5; }
