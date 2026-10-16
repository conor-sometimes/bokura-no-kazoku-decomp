#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
typedef union { float value; u32 word; } W2Fs;
#define GET_FLOAT_WORD(i,d) do { W2Fs gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
#define SET_FLOAT_WORD(d,i) do { W2Fs sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)

extern "C" float func_00281910(float, float, s32);
extern "C" float func_00280F58(float, float);
extern "C" s32 func_00280AD8(float, float *);

extern "C" const float D_002EA270[];
extern "C" const float D_002EA280[];
extern "C" const float D_002EA290[];
extern "C" const float D_002EA27C;
extern "C" const float D_002EA28C;
extern "C" float func_00280070(float);
// @decl-end
INCLUDE_RODATA("asm/nonmatchings/Dk27FC30", D_002EA270);
INCLUDE_RODATA("asm/nonmatchings/Dk27FC30", D_002EA27C);
INCLUDE_RODATA("asm/nonmatchings/Dk27FC30", D_002EA280);
INCLUDE_RODATA("asm/nonmatchings/Dk27FC30", D_002EA28C);
INCLUDE_RODATA("asm/nonmatchings/Dk27FC30", D_002EA290);

extern "C" float func_0027FC30(float x) { float w, s1, s2, z; s32 ix, hx, id; GET_FLOAT_WORD(hx, x); ix = hx & 0x7fffffff; if (ix >= 0x50800000) { if (hx > 0) return D_002EA27C + D_002EA28C; else return -D_002EA27C - D_002EA28C; } if (ix < 0x3ee00000) { if (ix < 0x31000000) { if (1.0e30f + x > 1.0f) return x; } id = -1; } else { x = func_00280070(x); if (ix < 0x3f980000) { if (ix < 0x3f300000) { id = 0; x = ((float)2.0 * x - 1.0f) / ((float)2.0 + x); } else { id = 1; x = (x - 1.0f) / (x + 1.0f); } } else { if (ix < 0x401c0000) { id = 2; x = (x - (float)1.5) / (1.0f + (float)1.5 * x); } else { id = 3; x = -(float)1.0 / x; } } } z = x * x; w = z * z; s1 = z * (D_002EA290[0] + w * (D_002EA290[2] + w * (D_002EA290[4] + w * (D_002EA290[6] + w * (D_002EA290[8] + w * D_002EA290[10]))))); s2 = w * (D_002EA290[1] + w * (D_002EA290[3] + w * (D_002EA290[5] + w * (D_002EA290[7] + w * D_002EA290[9])))); if (id < 0) return x - x * (s1 + s2); else { z = D_002EA270[id] - ((x * (s1 + s2) - D_002EA280[id]) - x); return (hx < 0) ? -z : z; } }

extern "C" float func_0027FEC0(float x) { s32 i0, j0; u32 i, ix; GET_FLOAT_WORD(i0, x); ix = (i0 & 0x7fffffff); j0 = (ix >> 23) - 0x7f; if (j0 < 23) { if (j0 < 0) { if (1.0e30f + x > (float)0.0) { if (i0 < 0) { i0 = 0x80000000; } else if (!(ix < 0x800000)) { i0 = 0x3f800000; } } } else { i = (0x007fffff) >> j0; if ((i0 & i) == 0) return x; if (1.0e30f + x > (float)0.0) { if (i0 > 0) i0 += (0x00800000) >> j0; i0 &= (~i); } } } else { return x; } SET_FLOAT_WORD(x, i0); return x; }

extern "C" float func_0027FF98(float x) { float y[2], z = 0.0f; s32 n, ix; GET_FLOAT_WORD(ix, x); ix &= 0x7fffffff; if (ix <= 0x3f490fd8) return func_00280F58(x, z); else { n = func_00280AD8(x, y); switch (n & 3) { case 0: return func_00280F58(y[0], y[1]); case 1: return -func_00281910(y[0], y[1], 1); case 2: return -func_00280F58(y[0], y[1]); default: return func_00281910(y[0], y[1], 1); } } }

extern "C" float func_00280070(float x) { u32 ix; GET_FLOAT_WORD(ix, x); SET_FLOAT_WORD(x, ix & 0x7fffffff); return x; }
