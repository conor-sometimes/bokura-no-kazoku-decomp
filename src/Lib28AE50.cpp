#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern int func_0028AD50(void *, int);
extern int func_00273970(void);
extern void *D_002BF5D0;

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern void *D_002BF5D0;
extern double func_0028B970();   /* _strtod_r, defined below */
extern double func_0028C888(const char *, char **);
extern long func_0028C8D8(void *, const char *, char **, int);

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern s32 func_002911B0(void *, void *);
extern const char _ctype_[];

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern s32 D_2EB920;
extern s32 func_00273978(s32, s32);

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern void func_00290CB8(void *);
extern s32 func_0028CCB8();   /* defined below with its real types */
typedef struct W2Re W2Re;
struct W2Re { u8 pad[0x38]; s32 sdidinit; };
typedef struct W2F W2F;
struct W2F { u8 pad[0x54]; W2Re *data; };

typedef struct W2File5 W2File5;
struct W2File5 { u8 *p; s32 r; s32 w; s16 flags; s16 file; u8 *base; s32 size; s32 lbfsize; void *cookie; void *rd; void *wr; void *sk; void *cl; u8 pad30[0x54 - 0x30]; void *data; };
extern s32 func_0028D9B0(W2File5 *, const char *, char *);
extern unsigned long func_00282E40(unsigned long, unsigned long);
extern unsigned long func_002828C0(unsigned long, unsigned long);
// @decl-end

extern int func_0028AE50(int s) { return func_0028AD50(D_002BF5D0, s); }

extern s32 func_0028AE70(s32 *ptr, s32 a, s32 b) { s32 ret; D_2EB920 = 0; if ((ret = func_00273978(a, b)) == -1 && D_2EB920 != 0) *ptr = D_2EB920; return ret; }

extern int func_0028AED0(void) { return func_00273970(); }

extern s32 func_0028AEE8(void *ptr, char *str, const char *fmt, ...) { s32 ret; W2File5 f; char *ap; f.flags = 0x208; f.base = f.p = (u8 *)str; f.size = f.w = 0x7FFFFFFF; f.data = ptr; ap = (char *)__builtin_next_arg(fmt) - (8 - __builtin_args_info(2)) * 8; ret = func_0028D9B0(&f, fmt, ap); *f.p = 0; return ret; }

extern s32 sprintf(char *str, const char *fmt, ...) { s32 ret; W2File5 f; char *ap; f.flags = 0x208; f.base = f.p = (u8 *)str; f.size = f.w = 0x7FFFFFFF; f.data = D_002BF5D0; ap = (char *)__builtin_next_arg(fmt) - (8 - __builtin_args_info(2)) * 8; ret = func_0028D9B0(&f, fmt, ap); *f.p = 0; return ret; }

INCLUDE_ASM("asm/nonmatchings/Lib28AE50", func_0028B000);

INCLUDE_ASM("asm/nonmatchings/Lib28AE50", strcmp);

INCLUDE_ASM("asm/nonmatchings/Lib28AE50", strcpy);

INCLUDE_ASM("asm/nonmatchings/Lib28AE50", strlen);

extern char *func_0028B520(char *a) { char *ret = a; while (*a != 0) { int c = *a; if ((_ctype_ + 1)[c] & 1) *a = c - 0x41 + 0x61; ++a; } return ret; }

INCLUDE_ASM("asm/nonmatchings/Lib28AE50", func_0028B570);

INCLUDE_ASM("asm/nonmatchings/Lib28AE50", func_0028B728);

extern char *strstr(const char *searchee, const char *lookfor)
{
    if (*searchee == 0) {
        if (*lookfor)
            return (char *)0;
        return (char *)searchee;
    }

    while (*searchee) {
        unsigned int i;
        i = 0;

        while (1) {
            if (lookfor[i] == 0) {
                return (char *)searchee;
            }

            if (lookfor[i] != searchee[i]) {
                break;
            }
            i++;
        }
        searchee++;
    }

    return (char *)0;
}

/* _strtod_r: newlib-1.9.0 strtod.c as is (with Sony's FLT_ROUNDS of 0), see include/nl_mprec.h.
 * The author of this software is David M. Gay. Copyright (c) 1991 by AT&T (notice in nl_mprec.h). */
#include "nl_mprec.h"
#define _strtod_r func_0028B970
double
_DEFUN (_strtod_r, (ptr, s00, se),
	struct _reent *ptr _AND
	_CONST char *s00 _AND
	char **se)
{
  int bb2, bb5, bbe, bd2, bd5, bbbits, bs2, c, dsign, e1, esign, i, j,
    k, nd, nd0, nf, nz, nz0, sign;
  long e;
  _CONST char *s, *s0, *s1;
  double aadj, aadj1, adj;
  long L;
  unsigned long z;
  __ULong y;
  union double_union rv, rv0;

  _Bigint *bb, *bb1, *bd, *bd0, *bs, *delta;
  sign = nz0 = nz = 0;
  rv.d = 0.;
  for (s = s00;; s++)
    switch (*s)
      {
      case '-':
	sign = 1;
	/* no break */
      case '+':
	if (*++s)
	  goto break2;
	/* no break */
      case 0:
	s = s00;
	goto ret;
      case '\t':
      case '\n':
      case '\v':
      case '\f':
      case '\r':
      case ' ':
	continue;
      default:
	goto break2;
      }
break2:
  if (*s == '0')
    {
      nz0 = 1;
      while (*++s == '0');
      if (!*s)
	goto ret;
    }
  s0 = s;
  y = z = 0;
  for (nd = nf = 0; (c = *s) >= '0' && c <= '9'; nd++, s++)
    if (nd < 9)
      y = 10 * y + c - '0';
    else if (nd < 16)
      z = 10 * z + c - '0';
  nd0 = nd;
  if (c == '.')
    {
      c = *++s;
      if (!nd)
	{
	  for (; c == '0'; c = *++s)
	    nz++;
	  if (c > '0' && c <= '9')
	    {
	      s0 = s;
	      nf += nz;
	      nz = 0;
	      goto have_dig;
	    }
	  goto dig_done;
	}
      for (; c >= '0' && c <= '9'; c = *++s)
	{
	have_dig:
	  nz++;
	  if (c -= '0')
	    {
	      nf += nz;
	      for (i = 1; i < nz; i++)
		if (nd++ < 9)
		  y *= 10;
		else if (nd <= DBL_DIG + 1)
		  z *= 10;
	      if (nd++ < 9)
		y = 10 * y + c;
	      else if (nd <= DBL_DIG + 1)
		z = 10 * z + c;
	      nz = 0;
	    }
	}
    }
dig_done:
  e = 0;
  if (c == 'e' || c == 'E')
    {
      if (!nd && !nz && !nz0)
	{
	  s = s00;
	  goto ret;
	}
      s00 = s;
      esign = 0;
      switch (c = *++s)
	{
	case '-':
	  esign = 1;
	case '+':
	  c = *++s;
	}
      if (c >= '0' && c <= '9')
	{
	  while (c == '0')
	    c = *++s;
	  if (c > '0' && c <= '9')
	    {
	      e = c - '0';
	      s1 = s;
	      while ((c = *++s) >= '0' && c <= '9')
		e = 10 * e + c - '0';
	      if (s - s1 > 8)
		/* Avoid confusion from exponents
		 * so large that e might overflow.
		 */
		e = 9999999L;
	      if (esign)
		e = -e;
	    }
	  else
	    e = 0;
	}
      else
	s = s00;
    }
  if (!nd)
    {
      if (!nz && !nz0)
	s = s00;
      goto ret;
    }
  e1 = e -= nf;

  /* Now we have nd0 digits, starting at s0, followed by a
   * decimal point, followed by nd-nd0 digits.  The number we're
   * after is the integer represented by those digits times
   * 10**e */

  if (!nd0)
    nd0 = nd;
  k = nd < DBL_DIG + 1 ? nd : DBL_DIG + 1;
  rv.d = y;
  if (k > 9)
    rv.d = tens[k - 9] * rv.d + z;
  bd0 = 0;
  if (nd <= DBL_DIG
      && FLT_ROUNDS == 1
    )
    {
      if (!e)
	goto ret;
      if (e > 0)
	{
	  if (e <= Ten_pmax)
	    {
	      /* rv.d = */ rounded_product (rv.d, tens[e]);
	      goto ret;
	    }
	  i = DBL_DIG - nd;
	  if (e <= Ten_pmax + i)
	    {
	      /* A fancier test would sometimes let us do
				 * this for larger i values.
				 */
	      e -= i;
	      rv.d *= tens[i];
	      /* rv.d = */ rounded_product (rv.d, tens[e]);
	      goto ret;
	    }
	}
      else if (e >= -Ten_pmax)
	{
	  /* rv.d = */ rounded_quotient (rv.d, tens[-e]);
	  goto ret;
	}
    }
  e1 += nd - k;

  /* Get starting approximation = rv.d * 10**e1 */

  if (e1 > 0)
    {
      if ((i = e1 & 15) != 0)
	rv.d *= tens[i];
      if (e1 &= ~15)
	{
	  if (e1 > DBL_MAX_10_EXP)
	    {
	    ovfl:
	      ptr->_errno = ERANGE;
	      rv.d = HUGE_VAL;
	      if (bd0)
		goto retfree;
	      goto ret;
	    }
	  if (e1 >>= 4)
	    {
	      for (j = 0; e1 > 1; j++, e1 >>= 1)
		if (e1 & 1)
		  rv.d *= bigtens[j];
	      /* The last multiplication could overflow. */
	      word0 (rv) -= P * Exp_msk1;
	      rv.d *= bigtens[j];
	      if ((z = word0 (rv) & Exp_mask)
		  > Exp_msk1 * (DBL_MAX_EXP + Bias - P))
		goto ovfl;
	      if (z > Exp_msk1 * (DBL_MAX_EXP + Bias - 1 - P))
		{
		  /* set to largest number */
		  /* (Can't trust DBL_MAX) */
		  word0 (rv) = Big0;
		  word1 (rv) = Big1;
		}
	      else
		word0 (rv) += P * Exp_msk1;
	    }

	}
    }
  else if (e1 < 0)
    {
      e1 = -e1;
      if ((i = e1 & 15) != 0)
	rv.d /= tens[i];
      if (e1 &= ~15)
	{
	  e1 >>= 4;
	  if (e1 >= 1 << n_bigtens)
            goto undfl;
	  for (j = 0; e1 > 1; j++, e1 >>= 1)
	    if (e1 & 1)
	      rv.d *= tinytens[j];
	  /* The last multiplication could underflow. */
	  rv0.d = rv.d;
	  rv.d *= tinytens[j];
	  if (!rv.d)
	    {
	      rv.d = 2. * rv0.d;
	      rv.d *= tinytens[j];
	      if (!rv.d)
		{
		undfl:
		  rv.d = 0.;
		  ptr->_errno = ERANGE;
		  if (bd0)
		    goto retfree;
		  goto ret;
		}
	      word0 (rv) = Tiny0;
	      word1 (rv) = Tiny1;
	      /* The refinement below will clean
	       * this approximation up.
	       */
	    }
	}
    }

  /* Now the hard part -- adjusting rv to the correct value.*/

  /* Put digits into bd: true value = bd * 10^e */

  bd0 = s2b (ptr, s0, nd0, nd, y);

  for (;;)
    {
      bd = Balloc (ptr, bd0->_k);
      Bcopy (bd, bd0);
      bb = d2b (ptr, rv.d, &bbe, &bbbits);	/* rv.d = bb * 2^bbe */
      bs = i2b (ptr, 1);

      if (e >= 0)
	{
	  bb2 = bb5 = 0;
	  bd2 = bd5 = e;
	}
      else
	{
	  bb2 = bb5 = -e;
	  bd2 = bd5 = 0;
	}
      if (bbe >= 0)
	bb2 += bbe;
      else
	bd2 -= bbe;
      bs2 = bb2;
      i = bbe + bbbits - 1;	/* logb(rv.d) */
      if (i < Emin)		/* denormal */
	j = bbe + (P - Emin);
      else
	j = P + 1 - bbbits;
      bb2 += j;
      bd2 += j;
      i = bb2 < bd2 ? bb2 : bd2;
      if (i > bs2)
	i = bs2;
      if (i > 0)
	{
	  bb2 -= i;
	  bd2 -= i;
	  bs2 -= i;
	}
      if (bb5 > 0)
	{
	  bs = pow5mult (ptr, bs, bb5);
	  bb1 = mult (ptr, bs, bb);
	  Bfree (ptr, bb);
	  bb = bb1;
	}
      if (bb2 > 0)
	bb = lshift (ptr, bb, bb2);
      if (bd5 > 0)
	bd = pow5mult (ptr, bd, bd5);
      if (bd2 > 0)
	bd = lshift (ptr, bd, bd2);
      if (bs2 > 0)
	bs = lshift (ptr, bs, bs2);
      delta = diff (ptr, bb, bd);
      dsign = delta->_sign;
      delta->_sign = 0;
      i = cmp (delta, bs);
      if (i < 0)
	{
	  /* Error is less than half an ulp -- check for
	   * special case of mantissa a power of two.
	   */
	  if (dsign || word1 (rv) || word0 (rv) & Bndry_mask)
	    break;
	  delta = lshift (ptr, delta, Log2P);
	  if (cmp (delta, bs) > 0)
	    goto drop_down;
	  break;
	}
      if (i == 0)
	{
	  /* exactly half-way between */
	  if (dsign)
	    {
	      if ((word0 (rv) & Bndry_mask1) == Bndry_mask1
		  && word1 (rv) == 0xffffffff)
		{
		  /*boundary case -- increment exponent*/
		  word0 (rv) = (word0 (rv) & Exp_mask)
		    + Exp_msk1
		    ;
		  word1 (rv) = 0;
		  break;
		}
	    }
	  else if (!(word0 (rv) & Bndry_mask) && !word1 (rv))
	    {
	    drop_down:
	      /* boundary case -- decrement exponent */
	      L = (word0 (rv) & Exp_mask) - Exp_msk1;
	      word0 (rv) = L | Bndry_mask1;
	      word1 (rv) = 0xffffffff;
	      break;
	    }
	  if (!(word1 (rv) & LSB))
	    break;
	  if (dsign)
	    rv.d += ulp (rv.d);
	  else
	    {
	      rv.d -= ulp (rv.d);
	      if (!rv.d)
		goto undfl;
	    }
	  break;
	}
      if ((aadj = ratio (delta, bs)) <= 2.)
	{
	  if (dsign)
	    aadj = aadj1 = 1.;
	  else if (word1 (rv) || word0 (rv) & Bndry_mask)
	    {
	      if (word1 (rv) == Tiny1 && !word0 (rv))
		goto undfl;
	      aadj = 1.;
	      aadj1 = -1.;
	    }
	  else
	    {
	      /* special case -- power of FLT_RADIX to be */
	      /* rounded down... */

	      if (aadj < 2. / FLT_RADIX)
		aadj = 1. / FLT_RADIX;
	      else
		aadj *= 0.5;
	      aadj1 = -aadj;
	    }
	}
      else
	{
	  aadj *= 0.5;
	  aadj1 = dsign ? aadj : -aadj;
	  if (FLT_ROUNDS == 0)
	    aadj1 += 0.5;
	}
      y = word0 (rv) & Exp_mask;

      /* Check for overflow */

      if (y == Exp_msk1 * (DBL_MAX_EXP + Bias - 1))
	{
	  rv0.d = rv.d;
	  word0 (rv) -= P * Exp_msk1;
	  adj = aadj1 * ulp (rv.d);
	  rv.d += adj;
	  if ((word0 (rv) & Exp_mask) >=
	      Exp_msk1 * (DBL_MAX_EXP + Bias - P))
	    {
	      if (word0 (rv0) == Big0 && word1 (rv0) == Big1)
		goto ovfl;
	      word0 (rv) = Big0;
	      word1 (rv) = Big1;
	      goto cont;
	    }
	  else
	    word0 (rv) += P * Exp_msk1;
	}
      else
	{
	  /* Compute adj so that the IEEE rounding rules will
	   * correctly round rv.d + adj in some half-way cases.
	   * If rv.d * ulp(rv.d) is denormalized (i.e.,
	   * y <= (P-1)*Exp_msk1), we must adjust aadj to avoid
	   * trouble from bits lost to denormalization;
	   * example: 1.2e-307 .
	   */
	  if (y <= (P - 1) * Exp_msk1 && aadj >= 1.)
	    {
	      aadj1 = (double) (int) (aadj + 0.5);
	      if (!dsign)
		aadj1 = -aadj1;
	    }
	  adj = aadj1 * ulp (rv.d);
	  rv.d += adj;
	}
      z = word0 (rv) & Exp_mask;
      if (y == z)
	{
	  /* Can we stop now? */
	  L = aadj;
	  aadj -= L;
	  /* The tolerances below are conservative. */
	  if (dsign || word1 (rv) || word0 (rv) & Bndry_mask)
	    {
	      if (aadj < .4999999 || aadj > .5000001)
		break;
	    }
	  else if (aadj < .4999999 / FLT_RADIX)
	    break;
	}
    cont:
      Bfree (ptr, bb);
      Bfree (ptr, bd);
      Bfree (ptr, bs);
      Bfree (ptr, delta);
    }
retfree:
  Bfree (ptr, bb);
  Bfree (ptr, bd);
  Bfree (ptr, bs);
  Bfree (ptr, bd0);
  Bfree (ptr, delta);
ret:
  if (se)
    *se = (char *) s;
  return sign ? -rv.d : rv.d;
}


extern double func_0028C888(const char *s, char **e) { return func_0028B970(D_002BF5D0, s, e); }

extern float func_0028C8B0(const char *s, char **e) { return func_0028C888(s, e); }

extern long func_0028C8D8(void *rptr_, const char *nptr, char **endptr, int base)
{
    int *rptr = (int *)rptr_;
    register const char *s = nptr;
    register unsigned long acc;
    register int c;
    register unsigned long cutoff;
    register int neg = 0, any, cutlim;

    do {
        c = *s++;
    } while ((_ctype_ + 1)[c] & 8);
    if (c == '-') {
        neg = 1;
        c = *s++;
    } else if (c == '+')
        c = *s++;
    if ((base == 0 || base == 16) &&
        c == '0' && (*s == 'x' || *s == 'X')) {
        c = s[1];
        s += 2;
        base = 16;
    }
    if (base == 0)
        base = c == '0' ? 8 : 10;

    cutoff = neg ? -(unsigned long)(-0x7fffffffffffffffL - 1) : 0x7fffffffffffffffL;
    cutlim = func_00282E40(cutoff, (unsigned long)base);
    cutoff = func_002828C0(cutoff, (unsigned long)base);
    for (acc = 0, any = 0;; c = *s++) {
        if ((_ctype_ + 1)[c] & 4)
            c -= '0';
        else if ((_ctype_ + 1)[c] & 3)
            c -= ((_ctype_ + 1)[c] & 1) ? 'A' - 10 : 'a' - 10;
        else
            break;
        if (c >= base)
            break;
        if (any < 0 || acc > cutoff || (acc == cutoff && c > cutlim))
            any = -1;
        else {
            any = 1;
            acc *= base;
            acc += c;
        }
    }
    if (any < 0) {
        acc = neg ? (-0x7fffffffffffffffL - 1) : 0x7fffffffffffffffL;
        *rptr = 34;
    } else if (neg)
        acc = -acc;
    if (endptr != 0)
        *endptr = (char *)(any ? s - 1 : nptr);
    return (acc);
}

extern long func_0028CB10(const char *s, char **e, int b) { return func_0028C8D8(D_002BF5D0, s, e, b); }

extern s32 func_0028CB40(void *fp, void *uio) { s32 err; if (FLD(s32, uio, 8) == 0) { FLD(s32, uio, 4) = 0; return 0; } err = func_002911B0(fp, uio); FLD(s32, uio, 8) = 0; FLD(s32, uio, 4) = 0; return err; }

INCLUDE_ASM("asm/nonmatchings/Lib28AE50", func_0028CB88);

extern s32 func_0028CC40(W2F *fp, const char *fmt, void *ap) { do { if (fp->data == 0) fp->data = (W2Re *)D_002BF5D0; if (!fp->data->sdidinit) func_00290CB8(fp->data); } while (0); return func_0028CCB8(fp->data, fp, fmt, ap); }

/* _vfiprintf_r: newlib vfprintf.c with INTEGER_ONLY (include/nl_vfprintf.h) */
extern int func_0028CB88(W2File5 *, const char *, char *);      /* __sbprintf */
#define NL_VFPRINTF_R func_0028CCB8
#define NL_FILE W2File5
#define NL_SPRINT func_0028CB40
#define NL_SBPRINTF func_0028CB88
#include "nl_vfprintf.h"
