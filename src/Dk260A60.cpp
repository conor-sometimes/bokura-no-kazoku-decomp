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

extern u8 D_002E7C64[];
extern u8 D_002E7C24[];
struct W2AudBand { u8 p0[4]; s32 m4; s32 m8; u8 pC[0x34]; };
struct W2AudChan { u8 p0[0x32D0]; W2AudBand band[4]; u8 p33D0[0x10]; };
struct W2AudTab { void *p[4]; void *m10; s32 m14; };
struct W2AudDec2 { W2AudTab t[2]; W2AudChan ch[2]; u8 p67F0[4]; s32 nch; s32 mode; s32 fsize; };
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

extern "C" void func_00262B18(s32 nch, s32 mode, s32 fsize, W2AudDec2 *d)
{
    s32 i, k;
    d->mode = mode;
    d->fsize = fsize;
    d->t[0].m10 = D_002E7C64;
    d->t[0].m14 = 4;
    d->nch = nch;
    for (i = 0; i < 4; i++) {
        d->t[0].p[i] = D_002E7C24;
        for (k = 0; k < nch; k++) {
            d->ch[k].band[i].m8 = 4;
            d->ch[k].band[i].m4 = 0xFF;
        }
    }
    d->t[1] = d->t[0];
}

extern "C" s32 func_00262BE0(s32 a) { return a & 0xF; }

extern "C" s32 func_00262BE8(const char *s) {
    if (!strcmp(s, D_002E8FD0)) return 1;
    if (!strcmp(s, D_002E8FD8)) return 2;
    if (!strcmp(s, D_002E8FE0)) return 4;
    if (!strcmp(s, D_002E8FE8)) return 8;
    return strcmp(s, D_002E8FF0) ? 0 : 0x12;
}

INCLUDE_ASM("asm/nonmatchings/Dk260A60", func_00262CA0);
