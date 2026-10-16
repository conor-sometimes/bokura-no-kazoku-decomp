#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" s32 D_424418;
extern "C" void func_00283760(void);

typedef void (*W2Fp)(void);
extern "C" W2Fp *D_002BF224;
extern "C" s32 D_002BF228;
extern "C" u8 D_002C2C98[];
extern "C" void *func_00285DD0(void *);

extern "C" double func_00284E38(double, double);

typedef void (*W2Ctor)(void);
extern "C" W2Ctor D_0029F230[];
extern "C" u8 D_424400[];
extern "C" void func_00285CA0(void *, void *);
extern "C" s32 func_00289048(void (*)(void));
extern "C" void func_002836D0(void);

typedef int Y1SI __attribute__ ((mode (SI)));
typedef unsigned int Y1USI __attribute__ ((mode (SI)));
typedef int Y1DI __attribute__ ((mode (DI)));
typedef unsigned int Y1UDI __attribute__ ((mode (DI)));
struct Y1DIstruct { Y1SI low, high; };
typedef union { struct Y1DIstruct s; Y1DI ll; } Y1DIunion;
extern const u8 D_002EA980[];
extern const u8 D_002EAA80[];
static __inline__
Y1UDI
Y1UdivmodA (Y1UDI n, Y1UDI d, Y1UDI *rp)
{
  Y1DIunion ww;
  Y1DIunion nn, dd;
  Y1DIunion rr;
  Y1USI d0, d1, n0, n1, n2;
  Y1USI q0, q1;
  Y1USI b, bm;
  nn.ll = n;
  dd.ll = d;
  d0 = dd.s.low;
  d1 = dd.s.high;
  n0 = nn.s.low;
  n1 = nn.s.high;
  if (d1 == 0)
    {
      if (d0 > n1)
        {
          do { Y1USI __xr = (d0); Y1USI __a; if ((sizeof (Y1SI) * 8) <= 32) { __a = __xr < ((Y1USI)1<<2*((sizeof (Y1SI) * 8) / 4)) ? (__xr < ((Y1USI)1<<((sizeof (Y1SI) * 8) / 4)) ? 0 : ((sizeof (Y1SI) * 8) / 4)) : (__xr < ((Y1USI)1<<3*((sizeof (Y1SI) * 8) / 4)) ? 2*((sizeof (Y1SI) * 8) / 4) : 3*((sizeof (Y1SI) * 8) / 4)); } else { for (__a = (sizeof (Y1SI) * 8) - 8; __a > 0; __a -= 8) if (((__xr >> __a) & 0xff) != 0) break; } (bm) = (sizeof (Y1SI) * 8) - (D_002EA980[__xr >> __a] + __a); } while (0);
          if (bm != 0)
            {
              d0 = d0 << bm;
              n1 = (n1 << bm) | (n0 >> ((sizeof (Y1SI) * 8) - bm));
              n0 = n0 << bm;
            }
          do { Y1USI __d1, __d0, __q1, __q0; Y1USI __r1, __r0, __m; __d1 = ((Y1USI) (d0) / ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2))); __d0 = ((Y1USI) (d0) % ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2))); __r1 = (n1) % __d1; __q1 = (n1) / __d1; __m = (Y1USI) __q1 * __d0; __r1 = __r1 * ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2)) | ((Y1USI) (n0) / ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2))); if (__r1 < __m) { __q1--, __r1 += (d0); if (__r1 >= (d0)) if (__r1 < __m) __q1--, __r1 += (d0); } __r1 -= __m; __r0 = __r1 % __d1; __q0 = __r1 / __d1; __m = (Y1USI) __q0 * __d0; __r0 = __r0 * ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2)) | ((Y1USI) (n0) % ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2))); if (__r0 < __m) { __q0--, __r0 += (d0); if (__r0 >= (d0)) if (__r0 < __m) __q0--, __r0 += (d0); } __r0 -= __m; (q0) = (Y1USI) __q1 * ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2)) | __q0; (n0) = __r0; } while (0);
          q1 = 0;
        }
      else
        {
          if (d0 == 0)
            d0 = 1 / d0;
          do { Y1USI __xr = (d0); Y1USI __a; if ((sizeof (Y1SI) * 8) <= 32) { __a = __xr < ((Y1USI)1<<2*((sizeof (Y1SI) * 8) / 4)) ? (__xr < ((Y1USI)1<<((sizeof (Y1SI) * 8) / 4)) ? 0 : ((sizeof (Y1SI) * 8) / 4)) : (__xr < ((Y1USI)1<<3*((sizeof (Y1SI) * 8) / 4)) ? 2*((sizeof (Y1SI) * 8) / 4) : 3*((sizeof (Y1SI) * 8) / 4)); } else { for (__a = (sizeof (Y1SI) * 8) - 8; __a > 0; __a -= 8) if (((__xr >> __a) & 0xff) != 0) break; } (bm) = (sizeof (Y1SI) * 8) - (D_002EA980[__xr >> __a] + __a); } while (0);
          if (bm == 0)
            {
              n1 -= d0;
              q1 = 1;
            }
          else
            {
              b = (sizeof (Y1SI) * 8) - bm;
              d0 = d0 << bm;
              n2 = n1 >> b;
              n1 = (n1 << bm) | (n0 >> b);
              n0 = n0 << bm;
              do { Y1USI __d1, __d0, __q1, __q0; Y1USI __r1, __r0, __m; __d1 = ((Y1USI) (d0) / ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2))); __d0 = ((Y1USI) (d0) % ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2))); __r1 = (n2) % __d1; __q1 = (n2) / __d1; __m = (Y1USI) __q1 * __d0; __r1 = __r1 * ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2)) | ((Y1USI) (n1) / ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2))); if (__r1 < __m) { __q1--, __r1 += (d0); if (__r1 >= (d0)) if (__r1 < __m) __q1--, __r1 += (d0); } __r1 -= __m; __r0 = __r1 % __d1; __q0 = __r1 / __d1; __m = (Y1USI) __q0 * __d0; __r0 = __r0 * ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2)) | ((Y1USI) (n1) % ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2))); if (__r0 < __m) { __q0--, __r0 += (d0); if (__r0 >= (d0)) if (__r0 < __m) __q0--, __r0 += (d0); } __r0 -= __m; (q1) = (Y1USI) __q1 * ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2)) | __q0; (n1) = __r0; } while (0);
            }
          do { Y1USI __d1, __d0, __q1, __q0; Y1USI __r1, __r0, __m; __d1 = ((Y1USI) (d0) / ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2))); __d0 = ((Y1USI) (d0) % ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2))); __r1 = (n1) % __d1; __q1 = (n1) / __d1; __m = (Y1USI) __q1 * __d0; __r1 = __r1 * ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2)) | ((Y1USI) (n0) / ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2))); if (__r1 < __m) { __q1--, __r1 += (d0); if (__r1 >= (d0)) if (__r1 < __m) __q1--, __r1 += (d0); } __r1 -= __m; __r0 = __r1 % __d1; __q0 = __r1 / __d1; __m = (Y1USI) __q0 * __d0; __r0 = __r0 * ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2)) | ((Y1USI) (n0) % ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2))); if (__r0 < __m) { __q0--, __r0 += (d0); if (__r0 >= (d0)) if (__r0 < __m) __q0--, __r0 += (d0); } __r0 -= __m; (q0) = (Y1USI) __q1 * ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2)) | __q0; (n0) = __r0; } while (0);
        }
      if (rp != 0)
        {
          rr.s.low = n0 >> bm;
          rr.s.high = 0;
          *rp = rr.ll;
        }
    }
  else
    {
      if (d1 > n1)
        {
          q0 = 0;
          q1 = 0;
          if (rp != 0)
            {
              rr.s.low = n0;
              rr.s.high = n1;
              *rp = rr.ll;
            }
        }
      else
        {
          do { Y1USI __xr = (d1); Y1USI __a; if ((sizeof (Y1SI) * 8) <= 32) { __a = __xr < ((Y1USI)1<<2*((sizeof (Y1SI) * 8) / 4)) ? (__xr < ((Y1USI)1<<((sizeof (Y1SI) * 8) / 4)) ? 0 : ((sizeof (Y1SI) * 8) / 4)) : (__xr < ((Y1USI)1<<3*((sizeof (Y1SI) * 8) / 4)) ? 2*((sizeof (Y1SI) * 8) / 4) : 3*((sizeof (Y1SI) * 8) / 4)); } else { for (__a = (sizeof (Y1SI) * 8) - 8; __a > 0; __a -= 8) if (((__xr >> __a) & 0xff) != 0) break; } (bm) = (sizeof (Y1SI) * 8) - (D_002EA980[__xr >> __a] + __a); } while (0);
          if (bm == 0)
            {
              if (n1 > d1 || n0 >= d0)
                {
                  q0 = 1;
                  do { Y1USI __x; __x = (n0) - (d0); (n1) = (n1) - (d1) - (__x > (n0)); (n0) = __x; } while (0);
                }
              else
                q0 = 0;
              q1 = 0;
              if (rp != 0)
                {
                  rr.s.low = n0;
                  rr.s.high = n1;
                  *rp = rr.ll;
                }
            }
          else
            {
              Y1USI m1, m0;
              b = (sizeof (Y1SI) * 8) - bm;
              d1 = (d1 << bm) | (d0 >> b);
              d0 = d0 << bm;
              n2 = n1 >> b;
              n1 = (n1 << bm) | (n0 >> b);
              n0 = n0 << bm;
              do { Y1USI __d1, __d0, __q1, __q0; Y1USI __r1, __r0, __m; __d1 = ((Y1USI) (d1) / ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2))); __d0 = ((Y1USI) (d1) % ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2))); __r1 = (n2) % __d1; __q1 = (n2) / __d1; __m = (Y1USI) __q1 * __d0; __r1 = __r1 * ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2)) | ((Y1USI) (n1) / ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2))); if (__r1 < __m) { __q1--, __r1 += (d1); if (__r1 >= (d1)) if (__r1 < __m) __q1--, __r1 += (d1); } __r1 -= __m; __r0 = __r1 % __d1; __q0 = __r1 / __d1; __m = (Y1USI) __q0 * __d0; __r0 = __r0 * ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2)) | ((Y1USI) (n1) % ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2))); if (__r0 < __m) { __q0--, __r0 += (d1); if (__r0 >= (d1)) if (__r0 < __m) __q0--, __r0 += (d1); } __r0 -= __m; (q0) = (Y1USI) __q1 * ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2)) | __q0; (n1) = __r0; } while (0);
              __asm__ ("multu %2,%3" : "=l" (m0), "=h" (m1) : "d" ((Y1USI) (q0)), "d" ((Y1USI) (d0)));
              if (m1 > n1 || (m1 == n1 && m0 > n0))
                {
                  q0--;
                  do { Y1USI __x; __x = (m0) - (d0); (m1) = (m1) - (d1) - (__x > (m0)); (m0) = __x; } while (0);
                }
              q1 = 0;
              if (rp != 0)
                {
                  do { Y1USI __x; __x = (n0) - (m0); (n1) = (n1) - (m1) - (__x > (n0)); (n0) = __x; } while (0);
                  rr.s.low = (n1 << b) | (n0 >> bm);
                  rr.s.high = n1 >> bm;
                  *rp = rr.ll;
                }
            }
        }
    }
  ww.s.low = q0;
  ww.s.high = q1;
  return ww.ll;
}
static __inline__
Y1UDI
Y1UdivmodB (Y1UDI n, Y1UDI d, Y1UDI *rp)
{
  Y1DIunion ww;
  Y1DIunion nn, dd;
  Y1DIunion rr;
  Y1USI d0, d1, n0, n1, n2;
  Y1USI q0, q1;
  Y1USI b, bm;
  nn.ll = n;
  dd.ll = d;
  d0 = dd.s.low;
  d1 = dd.s.high;
  n0 = nn.s.low;
  n1 = nn.s.high;
  if (d1 == 0)
    {
      if (d0 > n1)
        {
          do { Y1USI __xr = (d0); Y1USI __a; if ((sizeof (Y1SI) * 8) <= 32) { __a = __xr < ((Y1USI)1<<2*((sizeof (Y1SI) * 8) / 4)) ? (__xr < ((Y1USI)1<<((sizeof (Y1SI) * 8) / 4)) ? 0 : ((sizeof (Y1SI) * 8) / 4)) : (__xr < ((Y1USI)1<<3*((sizeof (Y1SI) * 8) / 4)) ? 2*((sizeof (Y1SI) * 8) / 4) : 3*((sizeof (Y1SI) * 8) / 4)); } else { for (__a = (sizeof (Y1SI) * 8) - 8; __a > 0; __a -= 8) if (((__xr >> __a) & 0xff) != 0) break; } (bm) = (sizeof (Y1SI) * 8) - (D_002EAA80[__xr >> __a] + __a); } while (0);
          if (bm != 0)
            {
              d0 = d0 << bm;
              n1 = (n1 << bm) | (n0 >> ((sizeof (Y1SI) * 8) - bm));
              n0 = n0 << bm;
            }
          do { Y1USI __d1, __d0, __q1, __q0; Y1USI __r1, __r0, __m; __d1 = ((Y1USI) (d0) / ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2))); __d0 = ((Y1USI) (d0) % ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2))); __r1 = (n1) % __d1; __q1 = (n1) / __d1; __m = (Y1USI) __q1 * __d0; __r1 = __r1 * ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2)) | ((Y1USI) (n0) / ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2))); if (__r1 < __m) { __q1--, __r1 += (d0); if (__r1 >= (d0)) if (__r1 < __m) __q1--, __r1 += (d0); } __r1 -= __m; __r0 = __r1 % __d1; __q0 = __r1 / __d1; __m = (Y1USI) __q0 * __d0; __r0 = __r0 * ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2)) | ((Y1USI) (n0) % ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2))); if (__r0 < __m) { __q0--, __r0 += (d0); if (__r0 >= (d0)) if (__r0 < __m) __q0--, __r0 += (d0); } __r0 -= __m; (q0) = (Y1USI) __q1 * ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2)) | __q0; (n0) = __r0; } while (0);
          q1 = 0;
        }
      else
        {
          if (d0 == 0)
            d0 = 1 / d0;
          do { Y1USI __xr = (d0); Y1USI __a; if ((sizeof (Y1SI) * 8) <= 32) { __a = __xr < ((Y1USI)1<<2*((sizeof (Y1SI) * 8) / 4)) ? (__xr < ((Y1USI)1<<((sizeof (Y1SI) * 8) / 4)) ? 0 : ((sizeof (Y1SI) * 8) / 4)) : (__xr < ((Y1USI)1<<3*((sizeof (Y1SI) * 8) / 4)) ? 2*((sizeof (Y1SI) * 8) / 4) : 3*((sizeof (Y1SI) * 8) / 4)); } else { for (__a = (sizeof (Y1SI) * 8) - 8; __a > 0; __a -= 8) if (((__xr >> __a) & 0xff) != 0) break; } (bm) = (sizeof (Y1SI) * 8) - (D_002EAA80[__xr >> __a] + __a); } while (0);
          if (bm == 0)
            {
              n1 -= d0;
              q1 = 1;
            }
          else
            {
              b = (sizeof (Y1SI) * 8) - bm;
              d0 = d0 << bm;
              n2 = n1 >> b;
              n1 = (n1 << bm) | (n0 >> b);
              n0 = n0 << bm;
              do { Y1USI __d1, __d0, __q1, __q0; Y1USI __r1, __r0, __m; __d1 = ((Y1USI) (d0) / ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2))); __d0 = ((Y1USI) (d0) % ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2))); __r1 = (n2) % __d1; __q1 = (n2) / __d1; __m = (Y1USI) __q1 * __d0; __r1 = __r1 * ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2)) | ((Y1USI) (n1) / ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2))); if (__r1 < __m) { __q1--, __r1 += (d0); if (__r1 >= (d0)) if (__r1 < __m) __q1--, __r1 += (d0); } __r1 -= __m; __r0 = __r1 % __d1; __q0 = __r1 / __d1; __m = (Y1USI) __q0 * __d0; __r0 = __r0 * ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2)) | ((Y1USI) (n1) % ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2))); if (__r0 < __m) { __q0--, __r0 += (d0); if (__r0 >= (d0)) if (__r0 < __m) __q0--, __r0 += (d0); } __r0 -= __m; (q1) = (Y1USI) __q1 * ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2)) | __q0; (n1) = __r0; } while (0);
            }
          do { Y1USI __d1, __d0, __q1, __q0; Y1USI __r1, __r0, __m; __d1 = ((Y1USI) (d0) / ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2))); __d0 = ((Y1USI) (d0) % ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2))); __r1 = (n1) % __d1; __q1 = (n1) / __d1; __m = (Y1USI) __q1 * __d0; __r1 = __r1 * ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2)) | ((Y1USI) (n0) / ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2))); if (__r1 < __m) { __q1--, __r1 += (d0); if (__r1 >= (d0)) if (__r1 < __m) __q1--, __r1 += (d0); } __r1 -= __m; __r0 = __r1 % __d1; __q0 = __r1 / __d1; __m = (Y1USI) __q0 * __d0; __r0 = __r0 * ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2)) | ((Y1USI) (n0) % ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2))); if (__r0 < __m) { __q0--, __r0 += (d0); if (__r0 >= (d0)) if (__r0 < __m) __q0--, __r0 += (d0); } __r0 -= __m; (q0) = (Y1USI) __q1 * ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2)) | __q0; (n0) = __r0; } while (0);
        }
      if (rp != 0)
        {
          rr.s.low = n0 >> bm;
          rr.s.high = 0;
          *rp = rr.ll;
        }
    }
  else
    {
      if (d1 > n1)
        {
          q0 = 0;
          q1 = 0;
          if (rp != 0)
            {
              rr.s.low = n0;
              rr.s.high = n1;
              *rp = rr.ll;
            }
        }
      else
        {
          do { Y1USI __xr = (d1); Y1USI __a; if ((sizeof (Y1SI) * 8) <= 32) { __a = __xr < ((Y1USI)1<<2*((sizeof (Y1SI) * 8) / 4)) ? (__xr < ((Y1USI)1<<((sizeof (Y1SI) * 8) / 4)) ? 0 : ((sizeof (Y1SI) * 8) / 4)) : (__xr < ((Y1USI)1<<3*((sizeof (Y1SI) * 8) / 4)) ? 2*((sizeof (Y1SI) * 8) / 4) : 3*((sizeof (Y1SI) * 8) / 4)); } else { for (__a = (sizeof (Y1SI) * 8) - 8; __a > 0; __a -= 8) if (((__xr >> __a) & 0xff) != 0) break; } (bm) = (sizeof (Y1SI) * 8) - (D_002EAA80[__xr >> __a] + __a); } while (0);
          if (bm == 0)
            {
              if (n1 > d1 || n0 >= d0)
                {
                  q0 = 1;
                  do { Y1USI __x; __x = (n0) - (d0); (n1) = (n1) - (d1) - (__x > (n0)); (n0) = __x; } while (0);
                }
              else
                q0 = 0;
              q1 = 0;
              if (rp != 0)
                {
                  rr.s.low = n0;
                  rr.s.high = n1;
                  *rp = rr.ll;
                }
            }
          else
            {
              Y1USI m1, m0;
              b = (sizeof (Y1SI) * 8) - bm;
              d1 = (d1 << bm) | (d0 >> b);
              d0 = d0 << bm;
              n2 = n1 >> b;
              n1 = (n1 << bm) | (n0 >> b);
              n0 = n0 << bm;
              do { Y1USI __d1, __d0, __q1, __q0; Y1USI __r1, __r0, __m; __d1 = ((Y1USI) (d1) / ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2))); __d0 = ((Y1USI) (d1) % ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2))); __r1 = (n2) % __d1; __q1 = (n2) / __d1; __m = (Y1USI) __q1 * __d0; __r1 = __r1 * ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2)) | ((Y1USI) (n1) / ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2))); if (__r1 < __m) { __q1--, __r1 += (d1); if (__r1 >= (d1)) if (__r1 < __m) __q1--, __r1 += (d1); } __r1 -= __m; __r0 = __r1 % __d1; __q0 = __r1 / __d1; __m = (Y1USI) __q0 * __d0; __r0 = __r0 * ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2)) | ((Y1USI) (n1) % ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2))); if (__r0 < __m) { __q0--, __r0 += (d1); if (__r0 >= (d1)) if (__r0 < __m) __q0--, __r0 += (d1); } __r0 -= __m; (q0) = (Y1USI) __q1 * ((Y1USI) 1 << ((sizeof (Y1SI) * 8) / 2)) | __q0; (n1) = __r0; } while (0);
              __asm__ ("multu %2,%3" : "=l" (m0), "=h" (m1) : "d" ((Y1USI) (q0)), "d" ((Y1USI) (d0)));
              if (m1 > n1 || (m1 == n1 && m0 > n0))
                {
                  q0--;
                  do { Y1USI __x; __x = (m0) - (d0); (m1) = (m1) - (d1) - (__x > (m0)); (m0) = __x; } while (0);
                }
              q1 = 0;
              if (rp != 0)
                {
                  do { Y1USI __x; __x = (n0) - (m0); (n1) = (n1) - (m1) - (__x > (n0)); (n0) = __x; } while (0);
                  rr.s.low = (n1 << b) | (n0 >> bm);
                  rr.s.high = n1 >> bm;
                  *rp = rr.ll;
                }
            }
        }
    }
  ww.s.low = q0;
  ww.s.high = q1;
  return ww.ll;
}
extern "C" s32 dpcmp(double, double);
extern "C" u32 func_002854F0(double);
// @decl-end

INCLUDE_RODATA("asm/nonmatchings/Dk2828C0", D_002EA980);
extern "C" Y1UDI func_002828C0 (Y1UDI n, Y1UDI d)
{
  return Y1UdivmodA (n, d, (Y1UDI *) 0);
}

INCLUDE_RODATA("asm/nonmatchings/Dk2828C0", D_002EAA80);
extern "C" Y1UDI func_00282E40 (Y1UDI u, Y1UDI v)
{
  Y1UDI w;
  (void) Y1UdivmodB (u, v, &w);
  return w;
}

extern "C" float __floatdisf(s64 u) { double f; if (!(-((s64)1 << 53) < u && u < ((s64)1 << 53))) { if ((u64)u & (0x800 - 1)) u |= 0x800; } f = (s32)(u >> 32); f *= 65536.0; f *= 65536.0; f += (u32)(u & 0xFFFFFFFF); return (float)f; }

extern "C" u64 func_00283490(double a)
{
    double b;
    u64 v;
    if (a < 0) return 0;
    b = (a / 4294967296.0);
    v = (u32)b;
    v <<= 32;
    a -= (double)v;
    if (a < 0) v -= (u32)(-a); else v += (u32)a;
    return v;
}

extern "C" u64 __fixunssfdi(float original_a)
{
    double a = original_a;
    double b;
    u64 v;
    if (a < 0) return 0;
    b = (a / 4294967296.0);
    v = (u32)b;
    v <<= 32;
    a -= (double)v;
    if (a < 0) v -= (u32)(-a); else v += (u32)a;
    return v;
}

extern "C" void func_002836D0(void) { while (*D_002BF224) { D_002BF224++; (*(D_002BF224 - 1))(); } if (!D_002BF228) { D_002BF228 = 1; func_00285DD0(D_002C2C98); return; } }

extern "C" void func_00283760(void) { unsigned long nptrs; u32 i; func_00285CA0(D_002C2C98, D_424400); nptrs = (unsigned long)(s32)D_0029F230[0]; if (nptrs == (unsigned long)-1) for (nptrs = 0; D_0029F230[nptrs + 1] != 0; nptrs++); for (i = nptrs; i >= 1; i--) D_0029F230[i](); func_00289048(func_002836D0); return; }

extern "C" void func_00283820(void) { if (!D_424418) { D_424418 = 1; func_00283760(); return; } }
