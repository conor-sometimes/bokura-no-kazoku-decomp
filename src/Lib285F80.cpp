#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern "C" int func_00283980(void);
extern "C" int strcmp(const char *, const char *);
extern "C" void *D_002BF244;

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
struct W2FpNumS { s32 cls; u32 sign; s32 exp; u32 frac; };
extern "C" float func_00288F40(W2FpNumS *);

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern "C" s32 strcmp(const char *, const char *);

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
struct W2Fde2 { u32 length; s32 cie; u32 pc_begin; u32 pc_range; };
struct W2Upcast { void *obj; s32 access; void *base; };
extern "C" s32 func_00286B58(const char **, const char **);
extern "C" void func_00287920(void) __attribute__((noreturn));
struct W2EhInfo { u8 pad[0x14]; s32 caught; W2EhInfo *next; };

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern "C" void *func_00287EB8(void);

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern "C" void *func_00283D20(u32);
extern "C" void *func_00287A10(void *, void *, void *);
extern u8 W2vt_si[] asm("_vt$14__si_type_info");
extern u8 W2vt_user[] asm("_vt$16__user_type_info");

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern u8 W2vt_class2[] asm("_vt$17__class_type_info");

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern u8 W2vt_ti2[] asm("_vt$9type_info");
extern u8 W2vt_bi[] asm("_vt$19__builtin_type_info");
extern "C" u8 D_002BF248[];
extern "C" const char D_002EAD08[];

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
struct W2FpS { s32 cls; u32 sign; s32 exp; u32 frac; };
extern "C" s32 func_002883B0(void *, void *, void *, void *);
struct W2TI2 { const char *name; virtual void v0(); virtual s32 v1(s32, void *, void *, s32 *); virtual void v2(); virtual s32 v3(s32, void *, void *, void *); };

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
enum W2FC { W2C_SNAN, W2C_QNAN, W2C_ZERO, W2C_NUMBER, W2C_INF };
struct W2FpD { W2FC cls; u32 sign; s32 exp; u32 pad; u64 frac; };
union W2DBits { double d; u64 l; struct { u64 frac : 52 __attribute__((packed)); unsigned int exp : 11 __attribute__((packed)); unsigned int sign : 1 __attribute__((packed)); } b; };
static inline int w2d_isnan(W2FpD *x) { return x->cls == W2C_SNAN || x->cls == W2C_QNAN; }
static inline int w2d_isinf(W2FpD *x) { return x->cls == W2C_INF; }
static inline int w2d_iszero(W2FpD *x) { return x->cls == W2C_ZERO; }
struct W2UR { void *obj; s32 access; void *base; };

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
struct W2TI3 { const char *name; virtual void v0(); virtual void v1(); virtual s32 v2(s32, s32, void *, void *, void *, void *, s32 *); };

struct W2CieInfo { char *augmentation; void *eh_ptr; int code_align; int data_align; unsigned ra_regno; };
union W2Unaligned { void *p; } __attribute__((packed));
extern "C" u32 strlen(const char *);
extern "C" u8 *func_00285590(u8 *, void *);
extern "C" u8 *func_002855D8(u8 *, void *);
extern const char D_002EABA0[];
extern const char D_002EABA8[];
static inline void *w2_read_pointer(void *p) { union W2Unaligned *up = (union W2Unaligned *)p; return up->p; }

struct W2DwState { u8 p0[8]; s64 m8; s64 m10; u8 p18[0x3F8 - 0x18]; u16 m3F8; u8 p3FA[0x477 - 0x3FA]; u8 m477; };
extern "C" void func_00288FF8(void) __attribute__((noreturn));
// @decl-end

extern "C" W2Fde2 *func_00285F80(W2Fde2 *f, u32 pc) { for (; f->length != 0; f = (W2Fde2 *)((u8 *)f + f->length + 4)) { if (f->cie == 0) continue; if (f->pc_begin == 0) continue; if (pc - f->pc_begin < f->pc_range) return f; } return 0; }

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_00285FD8);

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_00286140);

extern "C" u8 *func_002862E8(W2Fde2 *f, W2CieInfo *c)
{
    u8 *p;
    int i;

    c->augmentation = (char *)&f->cie - f->cie + 9;

    if (strcmp(c->augmentation, D_002EABA0) != 0
        && strcmp(c->augmentation, D_002EABA8) != 0
        && c->augmentation[0] != 'z')
        return 0;

    p = (u8 *)c->augmentation + strlen(c->augmentation) + 1;

    if (strcmp(c->augmentation, D_002EABA8) == 0) {
        c->eh_ptr = w2_read_pointer(p);
        p += sizeof(void *);
    } else
        c->eh_ptr = 0;

    p = func_00285590(p, &c->code_align);
    p = func_002855D8(p, &c->data_align);
    c->ra_regno = *(unsigned char *)p++;

    if (c->augmentation[0] == 'z') {
        p = func_00285590(p, &i);
        p += i;
    }

    return p;
}

extern "C" u8 *func_002863F8(u8 *p, W2DwState *s)
{
    unsigned int op = *p++;
    int tmp;
    switch (op) {
    case 0x50 ... 0x6F:
        s->m3F8 = op - 0x50;
        break;
    case 0x90:
        p = func_002855D8(p, &tmp);
        s->m3F8 = tmp;
    case 0x70 ... 0x8F:
        s->m3F8 = op - 0x70;
        p = func_002855D8(p, &tmp);
        s->m10 = tmp;
        break;
    case 0x92:
        p = func_002855D8(p, &tmp);
        s->m3F8 = tmp;
        p = func_002855D8(p, &tmp);
        s->m10 = tmp;
        break;
    case 0x06:
        s->m477 = 1;
        break;
    case 0x23:
        p = func_00285590(p, &tmp);
        s->m8 = tmp;
        break;
    default:
        func_00288FF8();
    }
    return p;
}

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_00286518);

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_00286968);

extern "C" void func_00286B20(void *p, s32 c) { FLD(void *, p, 4) = W2vt_ti2; if (c & 1) { __builtin_delete(p); return; } }

extern "C" s32 func_00286B58(const char **a, const char **b) { return b == a || strcmp(*a, *b) == 0; }

extern "C" void func_00286B98(void *p, const char *n, void *bl, s32 bn) { if (p) { FLD(const char *, p, 0) = n; FLD(void *, p, 4) = W2vt_class2; FLD(void *, p, 8) = bl; FLD(s32, p, 0xC) = bn; } }

extern "C" void func_00286BC0(void *p, const char *n, void *ti) { if (p) { FLD(const char *, p, 0) = n; FLD(void *, p, 4) = W2vt_si; FLD(void *, p, 8) = ti; } }

extern "C" void func_00286BE0(void *p, const char *n) { if (p) { FLD(const char *, p, 0) = n; FLD(void *, p, 4) = W2vt_user; } }

extern "C" s32 func_00286C00(W2TI2 *self, void *target, void *obj, void **adj) { s32 r[3]; r[0] = 0; r[1] = 0; r[2] = 0; if (self->v1(6, target, obj, r)) return 0; *adj = (void *)r[0]; return r[1] >= 6; }

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_00286C78);

extern "C" s32 func_00286DC0(void *self, s32 access, void *target, void *obj, W2Upcast *res) { if (func_00286B58((const char **)self, (const char **)target)) { res->obj = obj; res->base = (void *)8; res->access = access; return (access & 6) == 4; } return 0; }

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_00286E20);

extern "C" s32 func_00286EB8(void *a, void *b, void *c, s32 x, s32 y) { return y == x ? 6 : 1; }

extern "C" s32 func_00286ED0(void *self, s32 access, void *target, void *obj, W2UR *res) { if (func_00286B58((const char **)self, (const char **)target)) { res->obj = obj; res->base = (void *)8; res->access = access; return (access & 6) == 4; } return FLD(W2TI2 *, self, 8)->v1(access, target, obj, (s32 *)res); }

extern "C" s32 func_00286F80(void *self, s32 boff, s32 access, void *target, void *obj, void *sub, void *subptr, s32 *res) { if (obj == subptr && func_00286B58((const char **)self, (const char **)sub)) { res[2] = access; return 0; } if (func_00286B58((const char **)self, (const char **)target)) { res[0] = (s32)obj; res[1] = access; if (boff >= 0) res[3] = ((u8 *)subptr - (u8 *)obj) == boff ? 6 : 1; else if (boff == -2) res[3] = 1; return 0; } return FLD(W2TI3 *, self, 8)->v2(boff, access, target, obj, sub, subptr, res); }

extern "C" s32 func_002870A0(void *self, s32 boff, void *sub, void *obj, void *subptr) { if (subptr == obj && func_00286B58((const char **)sub, (const char **)self)) return 6; return FLD(W2TI2 *, self, 8)->v3(boff, sub, obj, subptr); }

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_00287138);

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_00287378);

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_002877B8);

typedef void (*W2NoRet)(void) __attribute__((noreturn));
extern "C" W2NoRet D_002BF22C;
// splat merged three functions here: __terminate, __default_unexpected, set_terminate
extern "C" void func_00287920(void) { D_002BF22C(); }
extern "C" void func_00287938(void) { func_00287920(); }
extern "C" W2NoRet func_00287948(W2NoRet f) { W2NoRet o = D_002BF22C; D_002BF22C = f; return o; }

extern "C" void *func_00287960(void *p) { void *o = D_002BF244; D_002BF244 = p; return o; }

// splat merged two functions here: __unexpected, __cp_exception_info
extern "C" void func_00287978(void) { ((W2NoRet)D_002BF244)(); }
extern "C" void *func_00287990(void) { return *(u8 **)func_00283980() + 8; }

extern "C" s32 func_002879B8(void) { return *(s32 *)func_00283980(); }

extern "C" void *func_002879D8(void) { u8 *p = *(u8 **)func_00283980(); FLD(s32, p, 0x14) = 1; FLD(s64, p, 0x20) = FLD(s64, p, 0x20) + 1; return p; }

extern "C" void *func_00287A10(void *info, void *match, void *tbl) { if (tbl && FLD(s16, tbl, 4) != 4) return 0; if (match == (void *)-1) return (void *)1; match = ((void *(*)(void))match)(); return (void *)(func_002883B0(match, FLD(void *, info, 0xC), FLD(void *, info, 0x28), (u8 *)info + 8) != 0); }

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_00287A70);

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_00287B00);

extern "C" void func_00287C28(void) { W2EhInfo **stack = (W2EhInfo **)func_00283980(); W2EhInfo **q = stack; W2EhInfo *p; for (;;) { p = *q; if (p == 0) func_00287920(); if (p->caught) break; q = &p->next; } if (q != stack) { *q = p->next; p->next = *stack; *stack = p; } p->caught = 0; }

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_00287C88);

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_00287E50);

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_00287EB8);

extern "C" const char *func_00287F58(void *self) { void *t; if (self) t = ((void *(*)(void))FLD(void *, *(void **)self, 4))(); else t = func_00287EB8(); return *(const char **)t; }

extern "C" double func_00287F98(s64 u) { double d; d = (s32)(u >> 32); d *= 65536.0; d *= 65536.0; d += (u32)(u & 0xFFFFFFFF); return d; }

extern "C" void func_00288040(u32 *src, W2FpS *dst) { u32 v = *src; u32 frac = v & 0x7FFFFF; s32 exp = (v >> 23) & 0xFF; dst->sign = v >> 31; if (exp == 0) { dst->cls = 2; return; } dst->exp = exp - 127; dst->cls = 3; dst->frac = (frac << 7) | 0x40000000; }

extern "C" float func_002880A0(s32 c, u32 s, s32 e, u32 f) { W2FpNumS n; n.cls = c; n.sign = s; n.exp = e; n.frac = f; return func_00288F40(&n); }

extern "C" double func_002880D0(W2FpD *src) { u64 fraction = src->frac; s32 sign = src->sign; s32 exp = 0; W2DBits dst; if (w2d_isnan(src)) { exp = 0x7FF; fraction |= 1ULL << 51; } else if (w2d_isinf(src)) { exp = 0x7FF; fraction = 0; } else if (w2d_iszero(src)) { exp = 0; fraction = 0; } else if (fraction == 0) { exp = 0; } else { if (src->exp < -1022) { exp = 0; fraction = 0; } else if (src->exp > 1023) { exp = 0x7FF; fraction = 0; } else { exp = src->exp + 1023; fraction >>= 8; } } dst.b.frac = fraction; dst.b.exp = exp; dst.b.sign = sign; return dst.d; }

extern "C" void func_002881A8(W2DBits *src, W2FpD *dst) { u64 fraction = src->b.frac; s32 exp = src->b.exp; dst->sign = src->b.sign; if (exp == 0) { dst->cls = W2C_ZERO; return; } if (exp == 0x7FF) { dst->exp = 0x3FF; if (fraction == 0) { dst->cls = W2C_INF; dst->frac = 1ULL << 60; return; } if (fraction & (1ULL << 51)) dst->cls = W2C_QNAN; else dst->cls = W2C_SNAN; dst->frac = fraction; return; } dst->exp = exp - 0x3FF; dst->cls = W2C_NUMBER; dst->frac = (fraction << 8) | (1ULL << 60); }

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_00288268);

extern "C" s32 func_00288388(const char **a, const char **b) { return strcmp(*a, *b) < 0; }

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_002883B0);
