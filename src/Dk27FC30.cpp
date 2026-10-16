#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
typedef union { f32 value; u32 word; } ieee_float_shape_type;
#define GET_FLOAT_WORD(i,d) do { ieee_float_shape_type gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
#define SET_FLOAT_WORD(d,i) do { ieee_float_shape_type sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)
// @decl-end

INCLUDE_ASM("asm/nonmatchings/Dk27FC30", func_0027FC30);

INCLUDE_ASM("asm/nonmatchings/Dk27FC30", func_0027FEC0);

INCLUDE_ASM("asm/nonmatchings/Dk27FC30", func_0027FF98);

extern "C" f32 func_00280070(f32 x) { u32 ix; GET_FLOAT_WORD(ix, x); SET_FLOAT_WORD(x, ix & 0x7fffffff); return x; }
