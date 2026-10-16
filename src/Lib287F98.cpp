#include "common.h"

// libgcc2 __floatdidf and the dp-bit/fp-bit helpers (0x287F98-0x288388): C, split off Lib285F80
// (tinfo/exception C++) so __fpcmp_parts_d compiles with the C front end (HARD.md w2 0x288268).

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
typedef struct W2FpS W2FpS;
struct W2FpS { s32 cls; u32 sign; s32 exp; u32 frac; };
typedef struct W2FpNumS W2FpNumS;
struct W2FpNumS { s32 cls; u32 sign; s32 exp; u32 frac; };
extern float func_00288F40(W2FpNumS *);
typedef enum W2FC { W2C_SNAN, W2C_QNAN, W2C_ZERO, W2C_NUMBER, W2C_INF } W2FC;
typedef struct W2FpD W2FpD;
struct W2FpD { W2FC cls; u32 sign; s32 exp; u32 pad; u64 frac; };
typedef union W2DBits { double d; u64 l; struct { u64 frac : 52 __attribute__((packed)); unsigned int exp : 11 __attribute__((packed)); unsigned int sign : 1 __attribute__((packed)); } b; } W2DBits;
static inline int w2d_isnan(W2FpD *x) { return x->cls == W2C_SNAN || x->cls == W2C_QNAN; }
static inline int w2d_isinf(W2FpD *x) { return x->cls == W2C_INF; }
static inline int w2d_iszero(W2FpD *x) { return x->cls == W2C_ZERO; }
// @decl-end

double func_00287F98(s64 u) { double d; d = (s32)(u >> 32); d *= 65536.0; d *= 65536.0; d += (u32)(u & 0xFFFFFFFF); return d; }

void func_00288040(u32 *src, W2FpS *dst) { u32 v = *src; u32 frac = v & 0x7FFFFF; s32 exp = (v >> 23) & 0xFF; dst->sign = v >> 31; if (exp == 0) { dst->cls = 2; return; } dst->exp = exp - 127; dst->cls = 3; dst->frac = (frac << 7) | 0x40000000; }

float func_002880A0(s32 c, u32 s, s32 e, u32 f) { W2FpNumS n; n.cls = c; n.sign = s; n.exp = e; n.frac = f; return func_00288F40(&n); }

double func_002880D0(W2FpD *src) { u64 fraction = src->frac; s32 sign = src->sign; s32 exp = 0; W2DBits dst; if (w2d_isnan(src)) { exp = 0x7FF; fraction |= 1ULL << 51; } else if (w2d_isinf(src)) { exp = 0x7FF; fraction = 0; } else if (w2d_iszero(src)) { exp = 0; fraction = 0; } else if (fraction == 0) { exp = 0; } else { if (src->exp < -1022) { exp = 0; fraction = 0; } else if (src->exp > 1023) { exp = 0x7FF; fraction = 0; } else { exp = src->exp + 1023; fraction >>= 8; } } dst.b.frac = fraction; dst.b.exp = exp; dst.b.sign = sign; return dst.d; }

void func_002881A8(W2DBits *src, W2FpD *dst) { u64 fraction = src->b.frac; s32 exp = src->b.exp; dst->sign = src->b.sign; if (exp == 0) { dst->cls = W2C_ZERO; return; } if (exp == 0x7FF) { dst->exp = 0x3FF; if (fraction == 0) { dst->cls = W2C_INF; dst->frac = 1ULL << 60; return; } if (fraction & (1ULL << 51)) dst->cls = W2C_QNAN; else dst->cls = W2C_SNAN; dst->frac = fraction; return; } dst->exp = exp - 0x3FF; dst->cls = W2C_NUMBER; dst->frac = (fraction << 8) | (1ULL << 60); }

/* from gcc-2.95.2 config/fp-bit.c (GPL): __fpcmp_parts_d */
int func_00288268(W2FpD *a, W2FpD *b)
{
    if (w2d_isnan(a) || w2d_isnan(b)) return 1;
    if (w2d_isinf(a) && w2d_isinf(b)) return b->sign - a->sign;
    if (w2d_isinf(a)) return a->sign ? -1 : 1;
    if (w2d_isinf(b)) return b->sign ? 1 : -1;
    if (w2d_iszero(a) && w2d_iszero(b)) return 0;
    if (w2d_iszero(a)) return b->sign ? 1 : -1;
    if (w2d_iszero(b)) return a->sign ? -1 : 1;
    if (a->sign != b->sign) return a->sign ? -1 : 1;
    if (a->exp > b->exp) return a->sign ? -1 : 1;
    if (a->exp < b->exp) return a->sign ? 1 : -1;
    if (a->frac > b->frac) return a->sign ? -1 : 1;
    if (a->frac < b->frac) return a->sign ? 1 : -1;
    return 0;
}

