/*
 * newlib mprec.h, resolved for the EE (IEEE_8087, Pack_32) and with Sony's float.h values
 * (FLT_ROUNDS is 0: strtod's exact fast path is compiled out). mprec.c's functions are named by
 * address (Lib290990 is still asm); the tables are its asm labels.
 *
 * The author of this software is David M. Gay. Copyright (c) 1991 by AT&T. Permission to use,
 * copy, modify, and distribute this software for any purpose without fee is hereby granted,
 * provided that this entire notice is included in all copies of any software which is or includes
 * a copy or modification of this software and in all copies of the supporting documentation for
 * such software. THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED WARRANTY.
 */
#ifndef NL_MPREC_H
#define NL_MPREC_H
#define DBL_DIG 15
#define DBL_MAX 1.7976931348623157e+308
#define DBL_MAX_10_EXP 308
#define DBL_MAX_EXP 1024
#define FLT_RADIX 2
#define FLT_ROUNDS 0
#define ERANGE 34
extern const double __nl_infinity asm("D_002EB628");   /* newlib __infinity (math.h HUGE_VAL) */
#define HUGE_VAL (__nl_infinity)
#define _DEFUN(name, arglist, args) name(args)
#define _AND ,
#define _CONST const
typedef unsigned int __uint32_t;
typedef unsigned int __ULong;
typedef int __Long;
typedef struct _Bigint _Bigint;
struct _Bigint { struct _Bigint *_next; int _k, _maxwds, _sign, _wds; __ULong _x[1]; };
struct _reent { int _errno; u8 pad4[0x40 - 4]; struct _Bigint *_result; int _result_k; };
union double_union { double d; __uint32_t i[2]; };
#define word0(x) (x.i[1])
#define word1(x) (x.i[0])
#define Storeinc(a,b,c) (((unsigned short *)a)[1] = (unsigned short)b, \
((unsigned short *)a)[0] = (unsigned short)c, a++)
#define Exp_shift  20
#define Exp_shift1 20
#define Exp_msk1    ((__uint32_t)0x100000L)
#define Exp_msk11   ((__uint32_t)0x100000L)
#define Exp_mask  ((__uint32_t)0x7ff00000L)
#define P 53
#define Bias 1023
#define Emin (-1022)
#define Exp_1  ((__uint32_t)0x3ff00000L)
#define Exp_11 ((__uint32_t)0x3ff00000L)
#define Ebits 11
#define Frac_mask  ((__uint32_t)0xfffffL)
#define Frac_mask1 ((__uint32_t)0xfffffL)
#define Ten_pmax 22
#define Bletch 0x10
#define Bndry_mask  ((__uint32_t)0xfffffL)
#define Bndry_mask1 ((__uint32_t)0xfffffL)
#define LSB 1
#define Sign_bit ((__uint32_t)0x80000000L)
#define Log2P 1
#define Tiny0 0
#define Tiny1 1
#define Quick_max 14
#define Int_max 14
#define Infinite(x) (word0(x) == ((__uint32_t)0x7ff00000L))
#define rounded_product(a,b) a *= b
#define rounded_quotient(a,b) a /= b
#define Big0 (Frac_mask1 | Exp_msk1*(DBL_MAX_EXP+Bias-1))
#define Big1 ((__uint32_t)0xffffffffL)
#define Sign_Extend(a,b) /*no-op*/
#define n_bigtens 5
#define Bcopy(x,y) memcpy((char *)&x->_sign, (char *)&y->_sign, y->_wds*sizeof(__Long) + 2*sizeof(int))
#define Balloc   func_00291980
#define Bfree    func_00291A28
#define multadd  func_00291A58
#define hi0bits  func_00291C90
#define i2b      func_00291DD0
#define mult     func_00291E08
#define pow5mult func_00292018
#define lshift   func_00292118
#define cmp      func_00292270
#define diff     func_002922D8
#define d2b      func_002926D0
#define s2b      func_00291B60
#define ulp      func_00292468
#define ratio    func_00292858
_Bigint *Balloc(struct _reent *p, int k);
void Bfree(struct _reent *p, _Bigint *v);
_Bigint *multadd(struct _reent *p, _Bigint *, int, int);
_Bigint *i2b(struct _reent *, int);
_Bigint *mult(struct _reent *, _Bigint *, _Bigint *);
_Bigint *pow5mult(struct _reent *, _Bigint *, int k);
int hi0bits(__ULong);
_Bigint *d2b(struct _reent *p, double d, int *e, int *bits);
_Bigint *lshift(struct _reent *p, _Bigint *b, int k);
_Bigint *diff(struct _reent *p, _Bigint *a, _Bigint *b);
int cmp(_Bigint *a, _Bigint *b);
_Bigint *s2b(struct _reent *, const char *, int, int, __ULong);
double ulp(double x);
double ratio(_Bigint *a, _Bigint *b);
extern void *memcpy(void *, const void *, unsigned int);
extern const double tens[] asm("D_002EB510");       /* __mprec_tens (mprec.c, ro_Lib290990) */
extern const double bigtens[] asm("D_002EB5D8");    /* __mprec_bigtens */
extern const double tinytens[] asm("D_002EB600");   /* __mprec_tinytens */
#endif
