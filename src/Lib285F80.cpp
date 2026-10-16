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
union W2Unaligned { void *p; unsigned b2 __attribute__ ((mode (HI))); unsigned b4 __attribute__ ((mode (SI))); } __attribute__((packed));
extern "C" u32 strlen(const char *);
extern "C" u8 *func_00285590(u8 *, void *);
extern "C" u8 *func_002855D8(u8 *, void *);
extern const char D_002EABA0[];
extern const char D_002EABA8[];
static inline void *w2_read_pointer(void *p) { union W2Unaligned *up = (union W2Unaligned *)p; return up->p; }
static inline unsigned w2_read_1byte(void *p) { return *(unsigned char *)p; }
static inline unsigned w2_read_2byte(void *p) { union W2Unaligned *up = (union W2Unaligned *)p; return up->b2; }
static inline unsigned w2_read_4byte(void *p) { union W2Unaligned *up = (union W2Unaligned *)p; return up->b4; }

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

extern "C" W2Fde2 *func_00285F80(W2Fde2 *f, u32 pc) { for (; f->length != 0; f = (W2Fde2 *)((u8 *)f + f->length + 4)) { if (f->cie == 0) continue; if (f->pc_begin == 0) continue; if (pc - f->pc_begin < f->pc_range) return f; } return 0; }

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_00285FD8);

extern "C" W2FdeF *func_00286140(void *pc)
{
    W2ObjF *ob;
    u32 lo, hi;

    func_002731E0(D_002BE1C4);

    for (ob = D_424598; ob; ob = ob->next) {
        if (ob->pc_begin == 0)
            func_00285FD8(ob);
        if (pc >= ob->pc_begin && pc < ob->pc_end)
            break;
    }

    if (ob == 0) {
        func_002731C0(D_002BE1C4);
        return 0;
    }

    if (!ob->fde_array || (void *)ob->fde_array == (void *)ob->fde_begin)
        func_00285FD8(ob);

    if (ob->fde_array && (void *)ob->fde_array != (void *)ob->fde_begin) {
        func_002731C0(D_002BE1C4);

        for (lo = 0, hi = ob->count; lo < hi;) {
            u32 i = (lo + hi) / 2;
            W2FdeF *f = ob->fde_array[i];

            if (pc < f->pc_begin)
                hi = i;
            else if (pc >= (char *)f->pc_begin + f->pc_range)
                lo = i + 1;
            else
                return f;
        }
    } else {
        W2FdeF *f;
        if (ob->fde_array) {
            W2FdeF **p = ob->fde_array;
            do {
                f = W2SearchFdes(*p, pc);
                if (f)
                    break;
                p++;
            } while (*p);
        } else
            f = W2SearchFdes(ob->fde_begin, pc);
        func_002731C0(D_002BE1C4);
        return f;
    }
    return 0;
}

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

INCLUDE_RODATA("asm/nonmatchings/Lib285F80", D_002EABA0);
INCLUDE_RODATA("asm/nonmatchings/Lib285F80", D_002EABA8);
INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_00286518);

INCLUDE_ASM("asm/nonmatchings/Lib285F80", func_00286968);
