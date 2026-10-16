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
typedef void *(*Y1match_fn)(void *, void *, void *);
struct Y1eh_info { Y1match_fn match_function; short language; short version; };
typedef void (*Y1cleanup_fn)(void *);
struct Y1cp_eh_info { Y1eh_info eh_info; void *value; void *type; Y1cleanup_fn cleanup; bool caught; Y1cp_eh_info *next; long handlers; void *original_value; };
extern "C" Y1cp_eh_info **Y1GetEhInfo(void) asm("func_00283980");
extern "C" int func_002888E8(void *);
extern "C" void func_00283E00(void *);
struct Y1dyncast_result { void *target_obj; int whole2target; int whole2src; int whole_details; };
enum W2Access { W2_PUBLIC = 1, W2_VIRTUAL, W2_PROTECTED, W2_PRIVATE };
struct W2BaseInfo { W2UTI *base; int offset : 29; bool is_virtual : 1; W2Access access : 2; };
struct W2ClassTI : W2UTI { W2BaseInfo *base_list; u32 n_bases; };
inline bool w2_contained_p(W2UTI::sub_kind access_path) { return access_path >= W2UTI::contained_mask; }
extern "C" s32 W2TiEq(const W2TI *, const W2TI *) asm("func_00286B58");
inline void *y1_convert_to_base(void *addr, bool is_virtual, int offset)
{
  if (!addr)
    return 0;
  if (!is_virtual)
    return (char *)addr + offset;
  return *(void **)((char *)addr + offset);
}
extern "C" bool Y1TiEq(const W2TI *, const W2TI *) throw() asm("func_00286B58");
struct Y1upcast_result {
    void *target_obj;
    W2UTI::sub_kind whole2target;
    const W2TI *base_type;
    Y1upcast_result() : target_obj(0), whole2target(W2UTI::unknown), base_type(0) {}
};
#define Y1_nonvirtual_base_type ((const W2TI *)8)
inline bool y1_contained_virtual_p(W2UTI::sub_kind access_path) { return (access_path & (W2UTI::contained_mask | W2UTI::contained_virtual_mask)) == (W2UTI::contained_mask | W2UTI::contained_virtual_mask); }
inline bool y1_contained_nonpublic_p(W2UTI::sub_kind access_path) { return (access_path & W2UTI::contained_public) == W2UTI::contained_mask; }
inline bool y1_contained_p(W2UTI::sub_kind access_path) { return access_path >= W2UTI::contained_mask; }
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

extern "C" bool func_00286E20(const char **self, int, int access_path, const char **target, void *objptr, const char **subtype, void *subptr, Y1dyncast_result *__restrict result)
{
  if (objptr == subptr && func_00286B58(self, subtype))
    {
      result->whole2src = access_path;
      return false;
    }
  if (func_00286B58(self, target))
    {
      result->target_obj = objptr;
      result->whole2target = access_path;
      result->whole_details = 1;
      return false;
    }
  return false;
}

extern "C" s32 func_00286EB8(void *a, void *b, void *c, s32 x, s32 y) { return y == x ? 6 : 1; }

extern "C" s32 func_00286ED0(void *self, s32 access, void *target, void *obj, W2UR *res) { if (func_00286B58((const char **)self, (const char **)target)) { res->obj = obj; res->base = (void *)8; res->access = access; return (access & 6) == 4; } return FLD(W2TI2 *, self, 8)->v1(access, target, obj, (s32 *)res); }

extern "C" s32 func_00286F80(void *self, s32 boff, s32 access, void *target, void *obj, void *sub, void *subptr, s32 *res) { if (obj == subptr && func_00286B58((const char **)self, (const char **)sub)) { res[2] = access; return 0; } if (func_00286B58((const char **)self, (const char **)target)) { res[0] = (s32)obj; res[1] = access; if (boff >= 0) res[3] = ((u8 *)subptr - (u8 *)obj) == boff ? 6 : 1; else if (boff == -2) res[3] = 1; return 0; } return FLD(W2TI3 *, self, 8)->v2(boff, access, target, obj, sub, subptr, res); }

extern "C" s32 func_002870A0(void *self, s32 boff, void *sub, void *obj, void *subptr) { if (subptr == obj && func_00286B58((const char **)sub, (const char **)self)) return 6; return FLD(W2TI2 *, self, 8)->v3(boff, sub, obj, subptr); }

extern "C" bool func_00287138(const W2ClassTI *self, W2UTI::sub_kind access_path, const W2TI &target, void *objptr, Y1upcast_result &__restrict result)
{
  if (Y1TiEq(self, &target))
    {
      result.target_obj = objptr;
      result.base_type = Y1_nonvirtual_base_type;
      result.whole2target = access_path;
      return y1_contained_nonpublic_p (access_path);
    }

  for (u32 i = self->n_bases; i--;)
    {
      Y1upcast_result result2;
      void *p = objptr;
      W2UTI::sub_kind sub_access = access_path;
      p = y1_convert_to_base (p,
                           self->base_list[i].is_virtual,
                           self->base_list[i].offset);
      if (self->base_list[i].is_virtual)
	sub_access = W2UTI::sub_kind (sub_access | W2UTI::contained_virtual_mask);
      if (self->base_list[i].access != W2_PUBLIC)
	sub_access = W2UTI::sub_kind (sub_access & ~W2UTI::contained_public_mask);
      if (self->base_list[i].base->do_upcast (sub_access, target, p, &result2)
          && !y1_contained_virtual_p (result2.whole2target))
        return true;
      if (result2.base_type)
        {
          if (result2.base_type == Y1_nonvirtual_base_type
              && self->base_list[i].is_virtual)
            result2.base_type = self->base_list[i].base;
          if (!result.base_type)
            result = result2;
          else if (result.target_obj != result2.target_obj)
            {
	      result.target_obj = 0;
	      result.whole2target = W2UTI::contained_ambig;
	      return true;
            }
          else if (result.target_obj)
            {
              result.whole2target
                  = W2UTI::sub_kind (result.whole2target | result2.whole2target);
            }
          else
            {
              if (result2.base_type == Y1_nonvirtual_base_type
                  || result.base_type == Y1_nonvirtual_base_type
                  || !Y1TiEq (result2.base_type, result.base_type))
                {
                  result.whole2target = W2UTI::contained_ambig;
                  return true;
                }
              result.whole2target
                  = W2UTI::sub_kind (result.whole2target | result2.whole2target);
            }
        }
    }
  return false;
}

extern "C" bool func_00287378(const W2ClassTI *self, int boff, W2UTI::sub_kind access_path,
            const W2TI &target, void *objptr,
            const W2TI &subtype, void *subptr,
            W2UTI::dyncast_result &__restrict result)
{
  if (objptr == subptr && Y1TiEq(self, &subtype))
    {
      result.whole2sub = access_path;
      return false;
    }
  if (Y1TiEq(self, &target))
    {
      result.target_obj = objptr;
      result.whole2target = access_path;
      if (boff >= 0)
        result.target2sub = ((char *)subptr - (char *)objptr) == boff
              ? W2UTI::contained_public : W2UTI::not_contained;
      else if (boff == -2)
        result.target2sub = W2UTI::not_contained;
      return false;
    }
  bool result_ambig = false;
  for (u32 i = self->n_bases; i--;)
    {
      W2UTI::dyncast_result result2;
      void *p;
      W2UTI::sub_kind sub_access = access_path;
      p = y1_convert_to_base (objptr,
                           self->base_list[i].is_virtual,
                           self->base_list[i].offset);
      if (self->base_list[i].is_virtual)
	sub_access = W2UTI::sub_kind (sub_access | W2UTI::contained_virtual_mask);
      if (self->base_list[i].access != W2_PUBLIC)
	sub_access = W2UTI::sub_kind (sub_access & ~W2UTI::contained_public_mask);

      bool result2_ambig
          = self->base_list[i].base->do_dyncast (boff, sub_access,
                                           target, p, subtype, subptr, result2);
      result.whole2sub = W2UTI::sub_kind (result.whole2sub | result2.whole2sub);
      if (result2.target2sub == W2UTI::contained_public
          || result2.target2sub == W2UTI::contained_ambig)
        {
          result.target_obj = result2.target_obj;
          result.whole2target = result2.whole2target;
          result.target2sub = result2.target2sub;
          return result2_ambig;
        }

      if (!result_ambig && !result.target_obj)
        {
          result.target_obj = result2.target_obj;
          result.whole2target = result2.whole2target;
          result_ambig = result2_ambig;
        }
      else if (result.target_obj && result.target_obj == result2.target_obj)
        {
          result.whole2target =
              W2UTI::sub_kind (result.whole2target | result2.whole2target);
        }
      else if ((result.target_obj && result2.target_obj)
               || (result_ambig && result2.target_obj)
               || (result2_ambig && result.target_obj))
        {
          W2UTI::sub_kind new_sub_kind = result2.target2sub;
          W2UTI::sub_kind old_sub_kind = result.target2sub;

          if (w2_contained_nonvirtual_p (result.whole2sub))
            {
              if (old_sub_kind == W2UTI::unknown)
                old_sub_kind = W2UTI::not_contained;
              if (new_sub_kind == W2UTI::unknown)
                new_sub_kind = W2UTI::not_contained;
            }
          else
            {
              const W2UTI &t =
                  static_cast <const W2UTI &> (target);

              if (old_sub_kind >= W2UTI::not_contained)
                ;
              else if (w2_contained_nonvirtual_p (new_sub_kind))
                old_sub_kind = W2UTI::not_contained;
              else
                old_sub_kind = t.find_public_subobj (boff, subtype,
                                                     result.target_obj, subptr);

              if (new_sub_kind >= W2UTI::not_contained)
                ;
              else if (w2_contained_nonvirtual_p (old_sub_kind))
                new_sub_kind = W2UTI::not_contained;
              else
                new_sub_kind = t.find_public_subobj (boff, subtype,
                                                     result2.target_obj, subptr);
            }

          if (y1_contained_p (W2UTI::sub_kind (new_sub_kind ^ old_sub_kind)))
            {
              if (y1_contained_p (new_sub_kind))
                {
                  result.target_obj = result2.target_obj;
                  result.whole2target = result2.whole2target;
                  result_ambig = false;
                  old_sub_kind = new_sub_kind;
                }
              result.target2sub = old_sub_kind;
              if (result.target2sub == W2UTI::contained_public)
                return false;
            }
          else if (y1_contained_p (W2UTI::sub_kind (new_sub_kind & old_sub_kind)))
            {
              result.target_obj = 0;
              result.target2sub = W2UTI::contained_ambig;
              return true;
            }
          else
            {
              result.target_obj = 0;
              result.target2sub = W2UTI::not_contained;
              result_ambig = true;
            }
        }

      if (result.whole2sub == W2UTI::contained_private)
        return result_ambig;
    }

  return result_ambig;
}

extern "C" W2UTI::sub_kind func_002877B8(const W2ClassTI *self, int boff, const W2TI &subtype, void *objptr, void *subptr)
{
    if (objptr == subptr && W2TiEq(&subtype, self))
        return W2UTI::contained_public;

    for (u32 i = self->n_bases; i--;) {
        if (self->base_list[i].access != W2_PUBLIC)
            continue;

        void *p;

        if (self->base_list[i].is_virtual && boff == -3)
            continue;

        p = y1_convert_to_base(objptr, self->base_list[i].is_virtual, self->base_list[i].offset);

        W2UTI::sub_kind base_kind = self->base_list[i].base->do_find_public_subobj(boff, subtype, p, subptr);
        if (w2_contained_p(base_kind)) {
            if (self->base_list[i].is_virtual)
                base_kind = W2UTI::sub_kind(base_kind | W2UTI::contained_virtual_mask);
            return base_kind;
        }
    }

    return W2UTI::not_contained;
}
