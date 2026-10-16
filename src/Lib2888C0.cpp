#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern int func_0028ADE8(int);
extern void func_00100248(int) __attribute__((noreturn));
extern int func_002883B0(void *, void *, void *, s32 *);
extern double func_0028C888(const char *, char **);
extern float func_0028C8B0(const char *, char **);
extern long func_0028CB10(const char *, char **, int);
extern void *D_002BF5D0;
extern int func_0028AC78(void *, int);
extern int func_0028AB88(void *);

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern void *D_002BF5D0;
typedef void (*W2SigFn)(s32);
extern W2SigFn func_0028ABF8(s32 *, s32, W2SigFn);

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern int func_002892F0(void *, const char *, ...);
extern const char D_002EAE48[];
extern void func_00288FF8(void);

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern void func_0028A070(void *);
extern void func_00290D48(void *, void *);
extern void func_0028A0F0(void *);
typedef struct W2VtEnt W2VtEnt;
struct W2VtEnt { s16 delta; s16 index; void *pfn; };
extern s32 func_00288A88(void *, void *, s32, void *, void *, void *);
extern u8 __tf19__pointer_type_info[];
extern u8 __tf9type_info[];
extern s32 D_002BFA34;
extern s32 D_002BFA30;
extern s32 D_002BE1C0;
extern s32 func_002731C0(s32);

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern s32 D_2EB920;
extern void func_0028A070(void *);
extern void *func_00289640(void *, u32);
extern s32 func_002738A0(s32);

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern void *func_00289640(void *, u32);
typedef void (*W2Sig)(s32);

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
typedef __builtin_va_list W2VaList;
extern s32 func_0028CC40(void *, const char *, void *);
extern s32 func_00273090(void);
extern s32 D_002BFA30;
extern s32 D_002BFA34;
extern s32 D_002BE1C0;
extern s32 func_002731E0(s32);
extern s32 func_0028AB88(void *);

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern u8 W2vt_ptr[] asm("_vt$19__pointer_type_info");
extern u8 W2vt_func[] asm("_vt$16__func_type_info");

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern u8 W2vt_ptmf[] asm("_vt$16__ptmf_type_info");
extern u8 W2vt_ptmd[] asm("_vt$16__ptmd_type_info");
extern u8 W2vt_arr[] asm("_vt$17__array_type_info");
extern u8 W2vt_attr[] asm("_vt$16__attr_type_info");

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern void *func_00289348(u32);
typedef struct W2Atexit W2Atexit;
struct W2Atexit { W2Atexit *next; s32 ind; void (*fns[32])(void); };

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern u8 W2vt_bi[] asm("_vt$19__builtin_type_info");
extern u8 D_002BF248[];
extern const char D_002EAD08[];

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern u8 W2_vt_19__builtin_type_info[] asm("_vt$19__builtin_type_info");
extern u8 D_002BF2C8[];
extern const char D_002EAD88[];
extern u8 D_002BF2C0[];
extern const char D_002EAD80[];
extern u8 D_002BF250[];
extern const char D_002EAD10[];
extern u8 D_002BF298[];
extern const char D_002EAD58[];
extern u8 D_002BF2A0[];
extern const char D_002EAD60[];
extern u8 D_002BF280[];
extern const char D_002EAD40[];
extern u8 D_002BF260[];
extern const char D_002EAD20[];
extern u8 D_002BF2D8[];
extern const char D_002EAD98[];
extern u8 D_002BF258[];
extern const char D_002EAD18[];
extern u8 D_002BF2D0[];
extern const char D_002EAD90[];
extern u8 D_002BF290[];
extern const char D_002EAD50[];
extern u8 D_002BF270[];
extern const char D_002EAD30[];
extern u8 D_002BF278[];
extern const char D_002EAD38[];
extern u8 D_002BF2B8[];
extern const char D_002EAD78[];
extern u8 D_002BF2A8[];
extern const char D_002EAD68[];
extern u8 D_002BF268[];
extern const char D_002EAD28[];
extern u8 D_002BF2B0[];
extern const char D_002EAD70[];
extern u8 D_002BF288[];
extern const char D_002EAD48[];

typedef void *(*W2TiFn2)(void);
extern s32 func_00286C78(void *, s32, void *, void *, void *, void *);

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
typedef void (*W2CleanFn)(void *);
typedef void (*W2ExitFn)(s32);

extern int func_0028AED0(void *);
extern int func_0028AE70(void *, int, int);
typedef void (*W2Sig2)(s32);
/* from newlib-1.9.0 libc/stdlib/qsort.c (BSD) */
static inline char *W2med3 (char *, char *, char *, int (*)());
static inline void W2swapfunc (char *, char *, int, int);

static inline void

W2swapfunc(char *a ,
        char *b ,
        int n ,
        int swaptype)
{
        if(swaptype <= 1)
                { long i = (n) / sizeof (long); register long *pi = (long *) (a); register long *pj = (long *) (b); do { register long t = *pi; *pi++ = *pj; *pj++ = t; } while (--i > 0); }
        else
                { long i = (n) / sizeof (char); register char *pi = (char *) (a); register char *pj = (char *) (b); do { register char t = *pi; *pi++ = *pj; *pj++ = t; } while (--i > 0); }
}

static inline char *

W2med3(char *a ,
        char *b ,
        char *c ,
        int (*cmp)())
{
        return cmp(a, b) < 0 ?
               (cmp(b, c) < 0 ? b : (cmp(a, c) < 0 ? c : a ))
              :(cmp(b, c) > 0 ? b : (cmp(a, c) < 0 ? a : c ));
}
/* from newlib-1.9.0 libc/stdlib/mallocr.c (Doug Lea malloc 2.6.4, public domain): malloc_extend_top */
struct _reent;
struct W2malloc_chunk { unsigned int prev_size; unsigned int size; struct W2malloc_chunk *fd; struct W2malloc_chunk *bk; };
typedef struct W2malloc_chunk *W2mchunkptr;
typedef struct W2malloc_chunk *W2mbinptr;
struct W2mallinfo { int arena, ordblks, smblks, hblks, hblkhd, usmblks, fsmblks, uordblks, fordblks, keepcost; };
extern W2mbinptr W2_av_[] __asm__("D_002BF5D8");
extern unsigned long W2_top_pad __asm__("D_002BF9E8");
extern char *W2_sbrk_base __asm__("D_002BF9F0");
extern unsigned long W2_max_sbrked_mem __asm__("D_002BF9F8");
extern unsigned long W2_max_total_mem __asm__("D_002BFA00");
extern struct W2mallinfo W2_cur_mallinfo __asm__("D_002BFA08");
typedef enum W2FCf W2FCf_t;
enum W2FCf { W2Cf_SNAN, W2Cf_QNAN, W2Cf_ZERO, W2Cf_NUMBER, W2Cf_INF };
typedef struct W2FpF W2FpF;
struct W2FpF { enum W2FCf cls; u32 sign; s32 exp; u32 frac; };
typedef union W2FBits W2FBits;
union W2FBits { float f; u32 l; struct { unsigned int frac : 23 __attribute__((packed)); unsigned int exp : 8 __attribute__((packed)); unsigned int sign : 1 __attribute__((packed)); } b; };
static inline int w2f_iszero(W2FpF *x) { return x->cls == W2Cf_ZERO; }
extern void Y1Abort3(void) asm("func_00288FF8") __attribute__((noreturn));
extern void *Y1UtiDyncast(const void *self, int boff, const void *target, void *objptr, const void *subtype, void *subptr) asm("func_00286C78");
typedef const void *(*Y1TiFn)(void);
// @decl-end

extern s32 func_002888C0(void *a, void *b, void *c) { s32 x; if (func_002883B0(a, b, c, &x)) return x; return 0; }

extern s32 func_002888E8(void *p) { s32 r = 0; if (p) { W2VtEnt *v = FLD(W2VtEnt *, p, 4); r = func_00288A88(v->pfn, __tf19__pointer_type_info, 0, (u8 *)p + v->delta, __tf9type_info, p); } return r != 0; }

extern void func_00288938(void *p, const char *n, void *ti) { if (p) { FLD(const char *, p, 0) = n; FLD(void *, p, 4) = W2vt_ptr; FLD(void *, p, 8) = ti; } }

extern void func_00288958(void *p, const char *n, s32 attr, void *ti) { if (p) { FLD(const char *, p, 0) = n; FLD(void *, p, 4) = W2vt_attr; FLD(void *, p, 8) = ti; FLD(s32, p, 0xC) = attr; } }

extern void func_00288980(void *p, const char *n) { if (p) { FLD(const char *, p, 0) = n; FLD(void *, p, 4) = W2vt_func; } }

extern void func_002889A0(void *p, const char *n) { if (p) { FLD(const char *, p, 0) = n; FLD(void *, p, 4) = W2vt_ptmf; } }

extern void func_002889C0(void *p, const char *n) { if (p) { FLD(const char *, p, 0) = n; FLD(void *, p, 4) = W2vt_ptmd; } }

extern void func_002889E0(void *p, const char *n) { if (p) { FLD(const char *, p, 0) = n; FLD(void *, p, 4) = W2vt_arr; } }

void *func_00288A00(Y1TiFn from, Y1TiFn to, int require_public, void *address, Y1TiFn sub, void *subptr)
{
  if (!require_public) Y1Abort3();
  return Y1UtiDyncast(from (), -1, to (), address, sub (), subptr);
}

extern s32 func_00288A88(void *from, void *to, s32 boff, void *addr, void *sub, void *subptr) { return func_00286C78(((W2TiFn2)from)(), boff, ((W2TiFn2)to)(), addr, ((W2TiFn2)sub)(), subptr); }

extern void *func_00288B18(void) { if (!FLD(const char *, D_002BF248, 0)) { FLD(const char *, D_002BF248, 0) = D_002EAD08; FLD(void *, D_002BF248, 4) = W2vt_bi; } return D_002BF248; }

extern void *func_00288B50(void) { if (!FLD(const char *, D_002BF250, 0)) { FLD(const char *, D_002BF250, 0) = D_002EAD10; FLD(void *, D_002BF250, 4) = W2_vt_19__builtin_type_info; } return D_002BF250; }

extern void *func_00288B88(void) { if (!FLD(const char *, D_002BF258, 0)) { FLD(const char *, D_002BF258, 0) = D_002EAD18; FLD(void *, D_002BF258, 4) = W2_vt_19__builtin_type_info; } return D_002BF258; }

extern void *func_00288BC0(void) { if (!FLD(const char *, D_002BF260, 0)) { FLD(const char *, D_002BF260, 0) = D_002EAD20; FLD(void *, D_002BF260, 4) = W2_vt_19__builtin_type_info; } return D_002BF260; }

extern void *func_00288BF8(void) { if (!FLD(const char *, D_002BF268, 0)) { FLD(const char *, D_002BF268, 0) = D_002EAD28; FLD(void *, D_002BF268, 4) = W2_vt_19__builtin_type_info; } return D_002BF268; }

extern void *func_00288C30(void) { if (!FLD(const char *, D_002BF270, 0)) { FLD(const char *, D_002BF270, 0) = D_002EAD30; FLD(void *, D_002BF270, 4) = W2_vt_19__builtin_type_info; } return D_002BF270; }

extern void *func_00288C68(void) { if (!FLD(const char *, D_002BF278, 0)) { FLD(const char *, D_002BF278, 0) = D_002EAD38; FLD(void *, D_002BF278, 4) = W2_vt_19__builtin_type_info; } return D_002BF278; }

extern void *func_00288CA0(void) { if (!FLD(const char *, D_002BF280, 0)) { FLD(const char *, D_002BF280, 0) = D_002EAD40; FLD(void *, D_002BF280, 4) = W2_vt_19__builtin_type_info; } return D_002BF280; }

extern void *func_00288CD8(void) { if (!FLD(const char *, D_002BF288, 0)) { FLD(const char *, D_002BF288, 0) = D_002EAD48; FLD(void *, D_002BF288, 4) = W2_vt_19__builtin_type_info; } return D_002BF288; }

extern void *func_00288D10(void) { if (!FLD(const char *, D_002BF290, 0)) { FLD(const char *, D_002BF290, 0) = D_002EAD50; FLD(void *, D_002BF290, 4) = W2_vt_19__builtin_type_info; } return D_002BF290; }

extern void *func_00288D48(void) { if (!FLD(const char *, D_002BF298, 0)) { FLD(const char *, D_002BF298, 0) = D_002EAD58; FLD(void *, D_002BF298, 4) = W2_vt_19__builtin_type_info; } return D_002BF298; }

extern void *func_00288D80(void) { if (!FLD(const char *, D_002BF2A0, 0)) { FLD(const char *, D_002BF2A0, 0) = D_002EAD60; FLD(void *, D_002BF2A0, 4) = W2_vt_19__builtin_type_info; } return D_002BF2A0; }

extern void *func_00288DB8(void) { if (!FLD(const char *, D_002BF2A8, 0)) { FLD(const char *, D_002BF2A8, 0) = D_002EAD68; FLD(void *, D_002BF2A8, 4) = W2_vt_19__builtin_type_info; } return D_002BF2A8; }

extern void *func_00288DF0(void) { if (!FLD(const char *, D_002BF2B0, 0)) { FLD(const char *, D_002BF2B0, 0) = D_002EAD70; FLD(void *, D_002BF2B0, 4) = W2_vt_19__builtin_type_info; } return D_002BF2B0; }

extern void *func_00288E28(void) { if (!FLD(const char *, D_002BF2B8, 0)) { FLD(const char *, D_002BF2B8, 0) = D_002EAD78; FLD(void *, D_002BF2B8, 4) = W2_vt_19__builtin_type_info; } return D_002BF2B8; }

extern void *func_00288E60(void) { if (!FLD(const char *, D_002BF2C0, 0)) { FLD(const char *, D_002BF2C0, 0) = D_002EAD80; FLD(void *, D_002BF2C0, 4) = W2_vt_19__builtin_type_info; } return D_002BF2C0; }

extern void *func_00288E98(void) { if (!FLD(const char *, D_002BF2C8, 0)) { FLD(const char *, D_002BF2C8, 0) = D_002EAD88; FLD(void *, D_002BF2C8, 4) = W2_vt_19__builtin_type_info; } return D_002BF2C8; }

extern void *func_00288ED0(void) { if (!FLD(const char *, D_002BF2D0, 0)) { FLD(const char *, D_002BF2D0, 0) = D_002EAD90; FLD(void *, D_002BF2D0, 4) = W2_vt_19__builtin_type_info; } return D_002BF2D0; }

extern void *func_00288F08(void) { if (!FLD(const char *, D_002BF2D8, 0)) { FLD(const char *, D_002BF2D8, 0) = D_002EAD98; FLD(void *, D_002BF2D8, 4) = W2_vt_19__builtin_type_info; } return D_002BF2D8; }

float func_00288F40(W2FpF *src) { u32 fraction = src->frac; s32 sign = src->sign; s32 exp = 0; W2FBits dst; if (w2f_iszero(src)) { fraction = 0; } else if (fraction == 0) { exp = 0; } else { if (src->exp < -126) { fraction = 0; } else if (src->exp > 128) { exp = 0xFF; fraction = 0; } else { if (src->exp == 128 && (s32)fraction < 0) { exp = 0xFF; fraction = 0; } else { exp = src->exp + 127; fraction >>= 7; } } } dst.b.frac = fraction; dst.b.exp = exp; dst.b.sign = sign; return dst.f; }

extern void func_00288FF8(void) { func_0028ADE8(6); func_00100248(1); __asm__(""); }

extern void func_00289010(const char *file, s32 line, const char *expr) { func_002892F0(FLD(void *, D_002BF5D0, 0xC), D_002EAE48, expr, file, line); func_00288FF8(); return; }

extern s32 func_00289048(void (*fn)(void)) { W2Atexit *p; if ((p = FLD(W2Atexit *, D_002BF5D0, 0x148)) == 0) FLD(W2Atexit *, D_002BF5D0, 0x148) = p = (W2Atexit *)((u8 *)D_002BF5D0 + 0x14C); if (p->ind >= 32) { if ((p = (W2Atexit *)func_00289348(0x88)) == 0) return -1; p->ind = 0; p->next = FLD(W2Atexit *, D_002BF5D0, 0x148); FLD(W2Atexit *, D_002BF5D0, 0x148) = p; } p->fns[p->ind++] = fn; return 0; }

extern double func_002890E8(const char *s) { return func_0028C888(s, 0); }

extern float atoff(const char *s) { return func_0028C8B0(s, 0); }

extern int atoi(const char *s) { return func_0028CB10(s, 0, 10); }

extern long atol(const char *s) { return func_0028CB10(s, 0, 10); }

extern void *bsearch(const void *key, const void *base, unsigned int nmemb, unsigned int size, int (*compar)(const void *, const void *))
{
    void *current;
    unsigned int lower = 0;
    unsigned int upper = nmemb;
    unsigned int index;
    int result;

    if (nmemb == 0 || size == 0)
        return 0;

    while (lower < upper) {
        index = (lower + upper) / 2;
        current = (void *)(((char *)base) + (index * size));
        result = compar(key, current);
        if (result < 0)
            upper = index;
        else if (result > 0)
            lower = index + 1;
        else
            return current;
    }
    return 0;
}

extern void *func_00289230(void) { return D_002BF5D0; }

extern void func_00289240(s32 code) { W2Atexit *p; s32 n; for (p = FLD(W2Atexit *, D_002BF5D0, 0x148); p; p = p->next) for (n = p->ind; --n >= 0;) (*p->fns[n])(); if (FLD(void *, D_002BF5D0, 0x3C)) (*FLD(W2CleanFn, D_002BF5D0, 0x3C))(D_002BF5D0); ((W2ExitFn)func_00100248)(code); return; }

extern s32 func_002892F0(void *fp, const char *fmt, ...) { s32 ret; char *ap = (char *)__builtin_next_arg(fmt) - (8 - __builtin_args_info(2)) * 8; ret = func_0028CC40(fp, fmt, ap); return ret; }

extern void *func_00289348(u32 n) { void *r; func_0028A070(D_002BF5D0); r = func_00289640(D_002BF5D0, n); func_0028A0F0(D_002BF5D0); return r; }

extern void func_002893A0(void *p) { func_0028A070(D_002BF5D0); func_00290D48(D_002BF5D0, p); func_0028A0F0(D_002BF5D0); return; }

void func_002893E8(void *reent_ptr, unsigned int nb)

{
  char* brk;
  unsigned int front_misalign;
  unsigned int correction;
  char* new_brk;
  unsigned int top_size;

  W2mchunkptr old_top = (((W2mbinptr)((char*)&(W2_av_[2*(0) + 2]) - 2*(sizeof(unsigned int))))->fd);
  unsigned int old_top_size = ((old_top)->size & ~((0x1|0x2)));
  char* old_end = (char*)(((W2mchunkptr)(((char*)(old_top)) + (old_top_size))));

  unsigned int sbrk_size = nb + W2_top_pad + (sizeof(struct W2malloc_chunk));
  unsigned long pagesz = (4096);

  if (W2_sbrk_base != (char*)(-1))
    sbrk_size = (sbrk_size + (pagesz - 1)) & ~(pagesz - 1);

  brk = (char*)(func_0028AB30((s32 *)reent_ptr, (s32)(sbrk_size)));

  if (brk == (char*)(-1) ||
      (brk < old_end && old_top != ((W2mchunkptr)(((W2mbinptr)((char*)&(W2_av_[2*(0) + 2]) - 2*(sizeof(unsigned int))))))))
    return;

  (W2_cur_mallinfo.arena) += sbrk_size;

  if (brk == old_end)
  {
    top_size = sbrk_size + old_top_size;
    (((((W2mbinptr)((char*)&(W2_av_[2*(0) + 2]) - 2*(sizeof(unsigned int))))->fd))->size = (top_size | 0x1));
  }
  else
  {
    if (W2_sbrk_base == (char*)(-1))
      W2_sbrk_base = brk;
    else
      (W2_cur_mallinfo.arena) += brk - (char*)old_end;

    front_misalign = (unsigned long)((void*)((char*)(brk) + 2*(sizeof(unsigned int)))) & (16 - 1);
    if (front_misalign > 0)
    {
      correction = (16) - front_misalign;
      brk += correction;
    }
    else
      correction = 0;

    correction += pagesz - ((unsigned long)(brk + sbrk_size) & (pagesz - 1));

    new_brk = (char*)(func_0028AB30((s32 *)reent_ptr, (s32)(correction)));
    if (new_brk == (char*)(-1)) return;

    (W2_cur_mallinfo.arena) += correction;

    (((W2mbinptr)((char*)&(W2_av_[2*(0) + 2]) - 2*(sizeof(unsigned int))))->fd) = (W2mchunkptr)brk;
    top_size = new_brk - brk + correction;
    (((((W2mbinptr)((char*)&(W2_av_[2*(0) + 2]) - 2*(sizeof(unsigned int))))->fd))->size = (top_size | 0x1));

    if (old_top != ((W2mchunkptr)(((W2mbinptr)((char*)&(W2_av_[2*(0) + 2]) - 2*(sizeof(unsigned int)))))))
    {

      if (old_top_size < (sizeof(struct W2malloc_chunk)))
      {
        (((((W2mbinptr)((char*)&(W2_av_[2*(0) + 2]) - 2*(sizeof(unsigned int))))->fd))->size = (0x1));
        return;
      }

      old_top_size = (old_top_size - 3*(sizeof(unsigned int))) & ~(16 - 1);
      ((old_top)->size = (((old_top)->size & 0x1) | (old_top_size)));
      ((W2mchunkptr)(((char*)(old_top)) + (old_top_size)))->size =
        (sizeof(unsigned int))|0x1;
      ((W2mchunkptr)(((char*)(old_top)) + (old_top_size + (sizeof(unsigned int)))))->size =
        (sizeof(unsigned int))|0x1;

      if (old_top_size >= (sizeof(struct W2malloc_chunk)))
        func_00290D48(reent_ptr, ((void*)((char*)(old_top) + 2*(sizeof(unsigned int)))));
    }
  }

  if ((unsigned long)(W2_cur_mallinfo.arena) > (unsigned long)W2_max_sbrked_mem)
    W2_max_sbrked_mem = (W2_cur_mallinfo.arena);

  if ((unsigned long)((W2_cur_mallinfo.arena)) > (unsigned long)W2_max_total_mem)
    W2_max_total_mem = (W2_cur_mallinfo.arena);

  ((void)0);
}

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", func_00289640);

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", strncmp);

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", memcpy);

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", func_00289EAC);

INCLUDE_ASM("asm/nonmatchings/Lib2888C0", memset);

extern void func_0028A070(void *r) { s32 tid = func_00273090(); if (D_002BFA30 == tid) { D_002BFA34++; return; } func_002731E0(D_002BE1C0); D_002BFA30 = tid; D_002BFA34++; }

extern void func_0028A0F0(void *r) { if (--D_002BFA34 == 0) { D_002BFA30 = -1; func_002731C0(D_002BE1C0); return; } }

void

func_0028A140(void *a ,
        unsigned int n ,
        unsigned int es ,
        int (*cmp)())
{
        char *pa, *pb, *pc, *pd, *pl, *pm, *pn;
        int d, r, swaptype, swap_cnt;

loop: swaptype = ((char *)a - (char *)0) % sizeof(long) || es % sizeof(long) ? 2 : es == sizeof(long)? 0 : 1;;
        swap_cnt = 0;
        if (n < 7) {
                for (pm = (char *) a + es; pm < (char *) a + n * es; pm += es)
                        for (pl = pm; pl > (char *) a && cmp(pl - es, pl) > 0;
                             pl -= es)
                                if (swaptype == 0) { long t = *(long *)(pl); *(long *)(pl) = *(long *)(pl - es); *(long *)(pl - es) = t; } else W2swapfunc(pl, pl - es, es, swaptype);
                return;
        }
        pm = (char *) a + (n / 2) * es;
        if (n > 7) {
                pl = a;
                pn = (char *) a + (n - 1) * es;
                if (n > 40) {
                        d = (n / 8) * es;
                        pl = W2med3(pl, pl + d, pl + 2 * d, cmp);
                        pm = W2med3(pm - d, pm, pm + d, cmp);
                        pn = W2med3(pn - 2 * d, pn - d, pn, cmp);
                }
                pm = W2med3(pl, pm, pn, cmp);
        }
        if (swaptype == 0) { long t = *(long *)(a); *(long *)(a) = *(long *)(pm); *(long *)(pm) = t; } else W2swapfunc(a, pm, es, swaptype);
        pa = pb = (char *) a + es;

        pc = pd = (char *) a + (n - 1) * es;
        for (;;) {
                while (pb <= pc && (r = cmp(pb, a)) <= 0) {
                        if (r == 0) {
                                swap_cnt = 1;
                                if (swaptype == 0) { long t = *(long *)(pa); *(long *)(pa) = *(long *)(pb); *(long *)(pb) = t; } else W2swapfunc(pa, pb, es, swaptype);
                                pa += es;
                        }
                        pb += es;
                }
                while (pb <= pc && (r = cmp(pc, a)) >= 0) {
                        if (r == 0) {
                                swap_cnt = 1;
                                if (swaptype == 0) { long t = *(long *)(pc); *(long *)(pc) = *(long *)(pd); *(long *)(pd) = t; } else W2swapfunc(pc, pd, es, swaptype);
                                pd -= es;
                        }
                        pc -= es;
                }
                if (pb > pc)
                        break;
                if (swaptype == 0) { long t = *(long *)(pb); *(long *)(pb) = *(long *)(pc); *(long *)(pc) = t; } else W2swapfunc(pb, pc, es, swaptype);
                swap_cnt = 1;
                pb += es;
                pc -= es;
        }
        if (swap_cnt == 0) {
                for (pm = (char *) a + es; pm < (char *) a + n * es; pm += es)
                        for (pl = pm; pl > (char *) a && cmp(pl - es, pl) > 0;
                             pl -= es)
                                if (swaptype == 0) { long t = *(long *)(pl); *(long *)(pl) = *(long *)(pl - es); *(long *)(pl - es) = t; } else W2swapfunc(pl, pl - es, es, swaptype);
                return;
        }

        pn = (char *) a + n * es;
        r = (pa - (char *)a) < (pb - pa) ? pa - (char *)a : pb - pa;
        if ((r) > 0) W2swapfunc(a, pb - r, r, swaptype);
        r = (pd - pc) < (pn - pd - es) ? pd - pc : pn - pd - es;
        if ((r) > 0) W2swapfunc(pb, pn - r, r, swaptype);
        if ((r = pb - pa) > es)
                func_0028A140(a, r / es, es, cmp);
        if ((r = pd - pc) > es) {

                a = pn - r;
                n = r / es;
                goto loop;
        }

}

extern s32 func_0028AB30(s32 *ptr, s32 fd) { s32 ret; D_2EB920 = 0; if ((ret = func_002738A0(fd)) == -1 && D_2EB920 != 0) *ptr = D_2EB920; return ret; }

extern s32 func_0028AB88(void *ptr) { s32 i; if (FLD(W2Sig *, ptr, 0x1D4) == 0) { FLD(W2Sig *, ptr, 0x1D4) = (W2Sig *)func_00289640(ptr, 0x80); if (FLD(W2Sig *, ptr, 0x1D4) == 0) return -1; for (i = 0; i < 32; i++) FLD(W2Sig *, ptr, 0x1D4)[i] = 0; } return 0; }

extern W2SigFn func_0028ABF8(s32 *ptr, s32 sig, W2SigFn func) { W2SigFn old; if (sig < 0 || sig >= 32) { *ptr = 22; return (W2SigFn)-1; } if (FLD(W2SigFn *, ptr, 0x1D4) == 0 && func_0028AB88(ptr) != 0) return (W2SigFn)-1; old = FLD(W2SigFn *, ptr, 0x1D4)[sig]; FLD(W2SigFn *, ptr, 0x1D4)[sig] = func; return old; }

extern int func_0028AC78(void *ptr, int sig)
{
    W2SigFn func;

    if (sig < 0 || sig >= 32) {
        FLD(s32, ptr, 0) = 22;
        return -1;
    }

    if (FLD(W2SigFn *, ptr, 0x1D4) == 0 && func_0028AB88(ptr) != 0)
        return -1;

    func = FLD(W2SigFn *, ptr, 0x1D4)[sig];
    if (func == (W2SigFn)0)
        return func_0028AE70(ptr, func_0028AED0(ptr), sig);
    else if (func == (W2SigFn)1)
        return 0;
    else if (func == (W2SigFn)-1) {
        FLD(s32, ptr, 0) = 22;
        return 1;
    } else {
        FLD(W2SigFn *, ptr, 0x1D4)[sig] = (W2SigFn)0;
        func(sig);
        return 0;
    }
}

extern s32 func_0028AD50(s32 *ptr, u32 sig) { W2Sig2 func; if (sig >= 32) return -1; if (FLD(W2Sig2 *, ptr, 0x1D4) == 0 && func_0028AB88(ptr) != 0) return -1; func = FLD(W2Sig2 *, ptr, 0x1D4)[sig]; if (func == 0) return 1; if (func == (W2Sig2)-1) return 2; if (func == (W2Sig2)1) return 3; FLD(W2Sig2 *, ptr, 0x1D4)[sig] = 0; func(sig); return 0; }

extern int func_0028ADE8(int s) { return func_0028AC78(D_002BF5D0, s); }

extern W2SigFn func_0028AE08(s32 a, W2SigFn b) { return func_0028ABF8((s32 *)D_002BF5D0, a, b); }

extern int func_0028AE30(void) { return func_0028AB88(D_002BF5D0); }
