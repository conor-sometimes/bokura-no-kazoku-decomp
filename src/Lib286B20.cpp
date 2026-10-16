#include "common.h"

// libgcc tinfo.cc / tinfo2.cc / exception.cc (C++), split off Lib285F80 (frame.c) by lane cv.

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

struct W2FdeF { u32 length; s32 CIE_delta; void *pc_begin; u32 pc_range; };
struct W2ObjF { void *pc_begin; void *pc_end; W2FdeF *fde_begin; W2FdeF **fde_array; u32 count; W2ObjF *next; };
extern "C" W2ObjF *D_424598;
extern "C" int D_002BE1C4;
extern "C" s32 func_002731E0(s32);
extern "C" s32 func_002731C0(s32);
extern "C" void func_00285FD8(W2ObjF *) throw();
extern "C" W2FdeF *W2SearchFdes(W2FdeF *, void *) asm("func_00285F80");

struct W2TI { const char *_name; virtual ~W2TI(); };
struct W2UTI : W2TI {
    enum sub_kind { unknown = 0, not_contained, contained_ambig, contained_virtual_mask = 1, contained_public_mask = 2, contained_mask = 4, contained_private = 4, contained_public = 6 };
    struct dyncast_result {
        void *target_obj;
        sub_kind whole2target, whole2sub, target2sub;
        dyncast_result() : target_obj(0), whole2target(unknown), whole2sub(unknown), target2sub(unknown) {}
    };
    virtual bool do_upcast(sub_kind, const W2TI &, void *, void *) const;
    virtual bool do_dyncast(int boff, sub_kind access_path, const W2TI &target, void *objptr, const W2TI &subtype, void *subptr, dyncast_result &result) const;
    virtual sub_kind do_find_public_subobj(int boff, const W2TI &subtype, void *objptr, void *subptr) const;
    sub_kind find_public_subobj(int boff, const W2TI &subtype, void *objptr, void *subptr) const
    {
        if (boff >= 0)
            return ((char *)subptr - (char *)objptr) == boff ? contained_public : not_contained;
        if (boff == -2)
            return not_contained;
        return do_find_public_subobj(boff, subtype, objptr, subptr);
    }
};
inline bool w2_contained_public_p(W2UTI::sub_kind access_path) { return access_path >= W2UTI::contained_public; }
inline bool w2_contained_nonvirtual_p(W2UTI::sub_kind access_path) { return (access_path & (W2UTI::contained_mask | W2UTI::contained_virtual_mask)) == W2UTI::contained_mask; }
// @decl-end

extern "C" void func_00286B20(void *p, s32 c) { FLD(void *, p, 4) = W2vt_ti2; if (c & 1) { __builtin_delete(p); return; } }

extern "C" s32 func_00286B58(const char **a, const char **b) { return b == a || strcmp(*a, *b) == 0; }

extern "C" void func_00286B98(void *p, const char *n, void *bl, s32 bn) { if (p) { FLD(const char *, p, 0) = n; FLD(void *, p, 4) = W2vt_class2; FLD(void *, p, 8) = bl; FLD(s32, p, 0xC) = bn; } }

extern "C" void func_00286BC0(void *p, const char *n, void *ti) { if (p) { FLD(const char *, p, 0) = n; FLD(void *, p, 4) = W2vt_si; FLD(void *, p, 8) = ti; } }

extern "C" void func_00286BE0(void *p, const char *n) { if (p) { FLD(const char *, p, 0) = n; FLD(void *, p, 4) = W2vt_user; } }

extern "C" s32 func_00286C00(W2TI2 *self, void *target, void *obj, void **adj) { s32 r[3]; r[0] = 0; r[1] = 0; r[2] = 0; if (self->v1(6, target, obj, r)) return 0; *adj = (void *)r[0]; return r[1] >= 6; }

extern "C" void *func_00286C78(const W2UTI *self, int boff, const W2TI &target, void *objptr, const W2TI &subtype, void *subptr)
{
    W2UTI::dyncast_result result;

    self->do_dyncast(boff, W2UTI::contained_public, target, objptr, subtype, subptr, result);
    if (!result.target_obj)
        return 0;
    if (w2_contained_public_p(result.target2sub))
        return result.target_obj;
    if (w2_contained_public_p(W2UTI::sub_kind(result.whole2sub & result.whole2target)))
        return result.target_obj;
    if (w2_contained_nonvirtual_p(result.whole2sub))
        return 0;
    if (result.target2sub == W2UTI::unknown)
        result.target2sub = static_cast<const W2UTI &>(target).find_public_subobj(boff, subtype, result.target_obj, subptr);
    if (w2_contained_public_p(result.target2sub))
        return result.target_obj;
    return 0;
}

extern "C" s32 func_00286DC0(void *self, s32 access, void *target, void *obj, W2Upcast *res) { if (func_00286B58((const char **)self, (const char **)target)) { res->obj = obj; res->base = (void *)8; res->access = access; return (access & 6) == 4; } return 0; }

INCLUDE_ASM("asm/nonmatchings/Lib286B20", func_00286E20);

extern "C" s32 func_00286EB8(void *a, void *b, void *c, s32 x, s32 y) { return y == x ? 6 : 1; }

extern "C" s32 func_00286ED0(void *self, s32 access, void *target, void *obj, W2UR *res) { if (func_00286B58((const char **)self, (const char **)target)) { res->obj = obj; res->base = (void *)8; res->access = access; return (access & 6) == 4; } return FLD(W2TI2 *, self, 8)->v1(access, target, obj, (s32 *)res); }

extern "C" s32 func_00286F80(void *self, s32 boff, s32 access, void *target, void *obj, void *sub, void *subptr, s32 *res) { if (obj == subptr && func_00286B58((const char **)self, (const char **)sub)) { res[2] = access; return 0; } if (func_00286B58((const char **)self, (const char **)target)) { res[0] = (s32)obj; res[1] = access; if (boff >= 0) res[3] = ((u8 *)subptr - (u8 *)obj) == boff ? 6 : 1; else if (boff == -2) res[3] = 1; return 0; } return FLD(W2TI3 *, self, 8)->v2(boff, access, target, obj, sub, subptr, res); }

extern "C" s32 func_002870A0(void *self, s32 boff, void *sub, void *obj, void *subptr) { if (subptr == obj && func_00286B58((const char **)sub, (const char **)self)) return 6; return FLD(W2TI2 *, self, 8)->v3(boff, sub, obj, subptr); }

INCLUDE_ASM("asm/nonmatchings/Lib286B20", func_00287138);

INCLUDE_ASM("asm/nonmatchings/Lib286B20", func_00287378);

INCLUDE_ASM("asm/nonmatchings/Lib286B20", func_002877B8);

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

INCLUDE_ASM("asm/nonmatchings/Lib286B20", func_00287A70);

INCLUDE_ASM("asm/nonmatchings/Lib286B20", func_00287B00);

extern "C" void func_00287C28(void) { W2EhInfo **stack = (W2EhInfo **)func_00283980(); W2EhInfo **q = stack; W2EhInfo *p; for (;;) { p = *q; if (p == 0) func_00287920(); if (p->caught) break; q = &p->next; } if (q != stack) { *q = p->next; p->next = *stack; *stack = p; } p->caught = 0; }

INCLUDE_ASM("asm/nonmatchings/Lib286B20", func_00287C88);

INCLUDE_ASM("asm/nonmatchings/Lib286B20", func_00287E50);

INCLUDE_ASM("asm/nonmatchings/Lib286B20", func_00287EB8);

extern "C" const char *func_00287F58(void *self) { void *t; if (self) t = ((void *(*)(void))FLD(void *, *(void **)self, 4))(); else t = func_00287EB8(); return *(const char **)t; }
