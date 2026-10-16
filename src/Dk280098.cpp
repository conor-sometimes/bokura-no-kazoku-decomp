#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" double func_00280290(double, double);
extern "C" double func_002806B0(double);

typedef union { float value; u32 word; } W2Fs;
#define GET_FLOAT_WORD(i,d) do { W2Fs gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
#define SET_FLOAT_WORD(d,i) do { W2Fs sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)

extern "C" float func_00281AE0(float, float);

extern "C" float func_00281910(float, float, s32);
extern "C" float func_00280F58(float, float);
extern "C" s32 func_00280AD8(float, float *);

extern "C" const s32 D_002EA634[];
extern "C" const s32 D_002EA320[];
extern "C" float func_00280070(float);
extern "C" s32 func_002810A8(float *, float *, s32, s32, s32, const s32 *);
// @decl-end

extern "C" float func_00280098(float x) { s32 i0, j0; u32 i, ix; GET_FLOAT_WORD(i0, x); ix = (i0 & 0x7fffffff); j0 = (ix >> 23) - 0x7f; if (j0 < 23) { if (j0 < 0) { if (1.0e30f + x > (float)0.0) { if (i0 >= 0) { i0 = 0; } else if (!(ix < 0x800000)) { i0 = 0xbf800000; } } } else { i = (0x007fffff) >> j0; if ((i0 & i) == 0) return x; if (1.0e30f + x > (float)0.0) { if (i0 < 0) i0 += (0x00800000) >> j0; i0 &= (~i); } } } else { return x; } SET_FLOAT_WORD(x, i0); return x; }

extern "C" s32 func_00280170(void) { return 0; }

extern "C" float func_00280178(float x) { float y[2], z = 0.0f; s32 n, ix; GET_FLOAT_WORD(ix, x); ix &= 0x7fffffff; if (ix <= 0x3f490fd8) return func_00281910(x, z, 0); else { n = func_00280AD8(x, y); switch (n & 3) { case 0: return func_00281910(y[0], y[1], 1); case 1: return func_00280F58(y[0], y[1]); case 2: return -func_00281910(y[0], y[1], 1); default: return -func_00280F58(y[0], y[1]); } } }

extern "C" double fmod(double a, double b) { return func_00280290(a, b); }

extern "C" double func_00280278(double a) { return func_002806B0(a); }

INCLUDE_ASM("asm/nonmatchings/Dk280098", func_00280290);

INCLUDE_ASM("asm/nonmatchings/Dk280098", func_002806B0);

extern "C" s32 func_00280AD8(float x, float *y) { float z, w, t, r, fn; float tx[3]; s32 i, j, n, ix, hx; s32 e0, nx; GET_FLOAT_WORD(hx, x); ix = hx & 0x7fffffff; if (ix <= 0x3f490fd8) { y[0] = x; y[1] = 0; return 0; } if (ix < 0x4016cbe4) { if (hx > 0) { z = x - 1.5707855225e+00f; if ((ix & 0xfffffff0) != 0x3fc90fd0) { y[0] = z - 1.0804334124e-05f; y[1] = (z - y[0]) - 1.0804334124e-05f; } else { z -= 1.0804273188e-05f; y[0] = z - 6.0770999344e-11f; y[1] = (z - y[0]) - 6.0770999344e-11f; } return 1; } else { z = x + 1.5707855225e+00f; if ((ix & 0xfffffff0) != 0x3fc90fd0) { y[0] = z + 1.0804334124e-05f; y[1] = (z - y[0]) + 1.0804334124e-05f; } else { z += 1.0804273188e-05f; y[0] = z + 6.0770999344e-11f; y[1] = (z - y[0]) + 6.0770999344e-11f; } return -1; } } if (ix <= 0x43490f80) { t = func_00280070(x); n = (s32)(t * 6.3661980629e-01f + 0.5f); fn = (float)n; r = t - fn * 1.5707855225e+00f; w = fn * 1.0804334124e-05f; if (n < 32 && (ix & 0xffffff00) != D_002EA634[n]) { y[0] = r - w; } else { u32 high; j = ix >> 23; y[0] = r - w; GET_FLOAT_WORD(high, y[0]); i = j - ((high >> 23) & 0xff); if (i > 8) { t = r; w = fn * 1.0804273188e-05f; r = t - w; w = fn * 6.0770999344e-11f - ((t - r) - w); y[0] = r - w; GET_FLOAT_WORD(high, y[0]); i = j - ((high >> 23) & 0xff); if (i > 25) { t = r; w = fn * 6.0770943833e-11f; r = t - w; w = fn * 6.1232342629e-17f - ((t - r) - w); y[0] = r - w; } } } y[1] = (r - y[0]) - w; if (hx < 0) { y[0] = -y[0]; y[1] = -y[1]; return -n; } else return n; } e0 = (s32)((ix >> 23) - 134); SET_FLOAT_WORD(z, ix - ((s32)(e0 << 23))); for (i = 0; i < 2; i++) { tx[i] = (float)((s32)(z)); z = (z - tx[i]) * 2.5600000000e+02f; } tx[2] = z; nx = 3; while (tx[nx - 1] == 0.0f) nx--; n = func_002810A8(tx, y, e0, nx, 2, D_002EA320); if (hx < 0) { y[0] = -y[0]; y[1] = -y[1]; return -n; } return n; }

INCLUDE_ASM("asm/nonmatchings/Dk280098", func_00280E88);

extern "C" float func_00280F58(float x, float y) { float a, hz, z, r, qx; s32 ix; GET_FLOAT_WORD(ix, x); ix &= 0x7fffffff; if (ix < 0x32000000) { if (((s32)x) == 0) return 1.0f; } z = x * x; r = z * (4.1666667908e-02f + z * (-1.3888889225e-03f + z * (2.4801587642e-05f + z * (-2.7557314297e-07f + z * (2.0875723372e-09f + z * -1.1359647598e-11f))))); if (ix < 0x3e99999a) return 1.0f - ((float)0.5 * z - (z * r - x * y)); else { if (ix > 0x3f480000) { qx = (float)0.28125; } else { SET_FLOAT_WORD(qx, ix - 0x01000000); } hz = (float)0.5 * z - qx; a = 1.0f - qx; return a - (hz - (z * r - x * y)); } }

INCLUDE_ASM("asm/nonmatchings/Dk280098", func_002810A8);

extern "C" float func_00281910(float x, float y, s32 iy) { float z, r, v; s32 ix; GET_FLOAT_WORD(ix, x); ix &= 0x7fffffff; if (ix < 0x32000000) { if ((s32)x == 0) return x; } z = x * x; v = z * x; r = 8.3333337680e-03f + z * (-1.9841270114e-04f + z * (2.7557314297e-06f + z * (-2.5050759689e-08f + z * 1.5896910177e-10f))); if (iy == 0) return x + v * (-1.6666667163e-01f + z * r); else return x - ((z * (0.5f * y - v * r) - y) - v * -1.6666667163e-01f); }

extern "C" float func_00281A18(float x, s32 n) { s32 k, ix; u32 hx; GET_FLOAT_WORD(ix, x); hx = ix & 0x7fffffff; k = hx >> 23; if (hx <= 0x7FFFFF) return x; k = k + n; if (k > 255) return 1.0e30f * func_00281AE0(1.0e30f, x); if (k > 0) { SET_FLOAT_WORD(x, (ix & 0x807fffff) | (k << 23)); return x; } if (n > 50000) return 1.0e30f * func_00281AE0(1.0e30f, x); else return 1.0e-30f * func_00281AE0(1.0e-30f, x); }

extern "C" float func_00281AE0(float x, float y) { u32 ix, iy; GET_FLOAT_WORD(ix, x); GET_FLOAT_WORD(iy, y); SET_FLOAT_WORD(x, (ix & 0x7fffffff) | (iy & 0x80000000)); return x; }

INCLUDE_ASM("asm/nonmatchings/Dk280098", func_00281B20);

INCLUDE_ASM("asm/nonmatchings/Dk280098", func_00281B98);

INCLUDE_ASM("asm/nonmatchings/Dk280098", func_00282230);
