#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
struct Bits { u8 pad[0x6800]; u8 *m6800; u8 pad6804[0x68C8 - 0x6804]; s32 m68C8; };
extern "C" s32 func_002613E8(s32, Bits *);

extern "C" s32 strcmp(const char *, const char *);
extern const char D_002E8FD0[];
extern const char D_002E8FD8[];
extern const char D_002E8FE0[];
extern const char D_002E8FE8[];
extern const char D_002E8FF0[];
// @decl-end

INCLUDE_ASM("asm/nonmatchings/Dk260A60", func_00260A60);

INCLUDE_ASM("asm/nonmatchings/Dk260A60", func_00261068);

INCLUDE_ASM("asm/nonmatchings/Dk260A60", func_002612F0);

extern "C" s32 func_002613E8(s32 n, Bits *b) { s32 mask = (1 << n) - 1; s32 pos = b->m68C8; u8 *p = b->m6800 + (pos >> 3); n += pos & 7; return (((p[0] << 8) | p[1]) >> (16 - n)) & mask; }

extern "C" s32 func_00261430(s32 n, Bits *b) { s32 v = func_002613E8(n, b); b->m68C8 += n; return v; }

INCLUDE_ASM("asm/nonmatchings/Dk260A60", func_00261470);

INCLUDE_ASM("asm/nonmatchings/Dk260A60", func_00261668);

INCLUDE_ASM("asm/nonmatchings/Dk260A60", func_00261888);

INCLUDE_ASM("asm/nonmatchings/Dk260A60", func_00261AB0);

INCLUDE_ASM("asm/nonmatchings/Dk260A60", func_00261C18);

INCLUDE_ASM("asm/nonmatchings/Dk260A60", func_00262108);

INCLUDE_ASM("asm/nonmatchings/Dk260A60", func_0026228C);

INCLUDE_ASM("asm/nonmatchings/Dk260A60", func_00262448);

INCLUDE_ASM("asm/nonmatchings/Dk260A60", func_0026296C);

INCLUDE_ASM("asm/nonmatchings/Dk260A60", func_002629CC);

INCLUDE_ASM("asm/nonmatchings/Dk260A60", func_00262A0C);

INCLUDE_ASM("asm/nonmatchings/Dk260A60", func_00262A8C);

INCLUDE_ASM("asm/nonmatchings/Dk260A60", func_00262AF0);

INCLUDE_ASM("asm/nonmatchings/Dk260A60", func_00262B18);

extern "C" s32 func_00262BE0(s32 a) { return a & 0xF; }

extern "C" s32 func_00262BE8(const char *s) {
    if (!strcmp(s, D_002E8FD0)) return 1;
    if (!strcmp(s, D_002E8FD8)) return 2;
    if (!strcmp(s, D_002E8FE0)) return 4;
    if (!strcmp(s, D_002E8FE8)) return 8;
    return strcmp(s, D_002E8FF0) ? 0 : 0x12;
}

INCLUDE_ASM("asm/nonmatchings/Dk260A60", func_00262CA0);
