#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern s32 func_002911B0(void *, void *);

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern void *D_002BF5D0;
typedef struct W2File W2File;
struct W2File { u8 *p; s32 r; s32 w; s16 flags; s16 file; u8 *base; s32 size; s32 lbfsize; void *cookie; void *rd; void *wr; void *sk; void *cl; u8 pad30[0x54 - 0x30]; void *data; };
extern s32 func_0028D9B0(W2File *, const char *, void *);

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern void func_00290CB8(void *);
extern s32 func_0028DA28(void *, void *, const char *, void *);

typedef struct W2File6 W2File6;
struct W2File6 { u8 *p; s32 r; s32 w; s16 flags; s16 file; u8 *base; s32 size; s32 lbfsize; void *cookie; void *rd; void *wr; void *sk; void *cl; u8 *ubbase; s32 ubsize; u8 *up; s32 ur; u8 ubuf[3]; u8 nbuf[1]; u8 lb[8]; s32 blksize; s32 offset; void *data; };
extern void func_00290D48(void *, void *);
extern void func_00291710(W2File6 *);

extern char *func_0028F728(void *, double, int, int, int *, int *, char **);

typedef struct W2Bi W2Bi;
struct W2Bi { W2Bi *_next; s32 _k, _maxwds, _sign, _wds; u32 _x[1]; };
extern int func_00292270(W2Bi *, W2Bi *);
#define W2Storeinc(a,b,c) (((unsigned short *)a)[1] = (unsigned short)b, ((unsigned short *)a)[0] = (unsigned short)c, a++)
// @decl-end

extern s32 func_0028D8B0(void *fp, void *uio) { s32 err; if (FLD(s32, uio, 8) == 0) { FLD(s32, uio, 4) = 0; return 0; } err = func_002911B0(fp, uio); FLD(s32, uio, 8) = 0; FLD(s32, uio, 4) = 0; return err; }

INCLUDE_ASM("asm/nonmatchings/Lib28D8B0", func_0028D8F8);

extern s32 func_0028D9B0(W2File *fp, const char *fmt, void *ap) { do { if (fp->data == 0) fp->data = D_002BF5D0; if (!FLD(s32, fp->data, 0x38)) func_00290CB8(fp->data); } while (0); return func_0028DA28(fp->data, fp, fmt, ap); }

INCLUDE_RODATA("asm/nonmatchings/Lib28D8B0", D_002EB250);
INCLUDE_RODATA("asm/nonmatchings/Lib28D8B0", D_002EB260);
INCLUDE_ASM("asm/nonmatchings/Lib28D8B0", func_0028DA28);
INCLUDE_RODATA("asm/nonmatchings/Lib28D8B0", D_002EB280);
INCLUDE_RODATA("asm/nonmatchings/Lib28D8B0", D_002EB298);
INCLUDE_RODATA("asm/nonmatchings/Lib28D8B0", D_002EB2A0);
INCLUDE_RODATA("asm/nonmatchings/Lib28D8B0", D_002EB2B8);
INCLUDE_RODATA("asm/nonmatchings/Lib28D8B0", D_002EB2D8);
INCLUDE_RODATA("asm/nonmatchings/Lib28D8B0", D_002EB2E0);
INCLUDE_RODATA("asm/nonmatchings/Lib28D8B0", jtbl_002EB2F0);

extern char *func_0028F098(void *data, double value, int ndigits, int flags, char *sign, int *decpt, int ch, int *length)
{
    int mode, dsgn;
    char *digits, *bp, *rve;
    union { double d; u32 i[2]; } tmp;

    if (ch == 'f') {
        mode = 3;
    } else {
        if (ch == 'e' || ch == 'E') {
            ndigits++;
        }
        mode = 2;
    }

    tmp.d = value;
    if (tmp.i[1] & 0x80000000) {
        value = -value;
        *sign = '-';
    } else
        *sign = '\000';
    digits = func_0028F728(data, value, mode, ndigits, decpt, &dsgn, &rve);
    if ((ch != 'g' && ch != 'G') || flags & 1) {
        bp = digits + ndigits;
        if (ch == 'f') {
            if (*digits == '0' && value)
                *decpt = -ndigits + 1;
            bp += *decpt;
        }
        if (value == 0)
            rve = bp;
        while (rve < bp)
            *rve++ = '0';
    }
    *length = rve - digits;
    return (digits);
}

extern s32 func_0028F258(char *p0, s32 exp, s32 fmtch) { char *p, *t; char expbuf[308]; p = p0; *p++ = fmtch; if (exp < 0) { exp = -exp; *p++ = '-'; } else *p++ = '+'; t = expbuf + 308; if (exp > 9) { do { *--t = exp % 10 + '0'; } while ((exp /= 10) > 9); *--t = exp + '0'; for (; t < expbuf + 308; *p++ = *t++); } else { *p++ = '0'; *p++ = exp + '0'; } return p - p0; }

extern s32 vsprintf(char *str, const char *fmt, void *ap) { s32 ret; W2File f; f.flags = 0x208; f.base = f.p = (u8 *)str; f.size = f.w = 0x7FFFFFFF; f.data = D_002BF5D0; ret = func_0028D9B0(&f, fmt, ap); *f.p = 0; return ret; }

extern s32 func_0028F390(void *ptr, char *str, const char *fmt, void *ap) { s32 ret; W2File f; f.flags = 0x208; f.base = f.p = (u8 *)str; f.size = f.w = 0x7FFFFFFF; f.data = ptr; ret = func_0028D9B0(&f, fmt, ap); *f.p = 0; return ret; }

extern int func_0028F3E8(W2File6 *fp)
{
    do { if (fp->data == 0) fp->data = D_002BF5D0; if (!FLD(s32, fp->data, 0x38)) func_00290CB8(fp->data); } while (0);
    if ((fp->flags & 0x8) == 0) {
        if ((fp->flags & 0x10) == 0)
            return -1;
        if (fp->flags & 0x4) {
            if (fp->ubbase != 0) {
                if (fp->ubbase != fp->ubuf)
                    func_00290D48(fp->data, fp->ubbase);
                fp->ubbase = 0;
            }
            fp->flags &= ~(0x4 | 0x20);
            fp->r = 0;
            fp->p = fp->base;
        }
        fp->flags |= 0x8;
    }
    if (fp->base == 0)
        func_00291710(fp);
    if (fp->flags & 0x1) {
        fp->w = 0;
        fp->lbfsize = -fp->size;
    } else
        fp->w = fp->flags & 0x2 ? 0 : fp->size;
    return 0;
}

extern int func_0028F4F8(W2Bi *b, W2Bi *S)
{
    int n;
    s32 borrow, y;
    u32 carry, q, ys;
    u32 *bx, *bxe, *sx, *sxe;
    s32 z;
    u32 si, zs;

    n = S->_wds;
    if (b->_wds < n)
        return 0;
    sx = S->_x;
    sxe = sx + --n;
    bx = b->_x;
    bxe = bx + n;
    q = *bxe / (*sxe + 1);
    if (q) {
        borrow = 0;
        carry = 0;
        do {
            si = *sx++;
            ys = (si & 0xffff) * q + carry;
            zs = (si >> 16) * q + (ys >> 16);
            carry = zs >> 16;
            y = (*bx & 0xffff) - (ys & 0xffff) + borrow;
            borrow = y >> 16;
            z = (*bx >> 16) - (zs & 0xffff) + borrow;
            borrow = z >> 16;
            W2Storeinc(bx, z, y);
        } while (sx <= sxe);
        if (!*bxe) {
            bx = b->_x;
            while (--bxe > bx && !*bxe)
                --n;
            b->_wds = n;
        }
    }
    if (func_00292270(b, S) >= 0) {
        q++;
        borrow = 0;
        carry = 0;
        bx = b->_x;
        sx = S->_x;
        do {
            si = *sx++;
            ys = (si & 0xffff) + carry;
            zs = (si >> 16) + (ys >> 16);
            carry = zs >> 16;
            y = (*bx & 0xffff) - (ys & 0xffff) + borrow;
            borrow = y >> 16;
            z = (*bx >> 16) - (zs & 0xffff) + borrow;
            borrow = z >> 16;
            W2Storeinc(bx, z, y);
        } while (sx <= sxe);
        bx = b->_x;
        bxe = bx + n;
        if (!*bxe) {
            while (--bxe > bx && !*bxe)
                --n;
            b->_wds = n;
        }
    }
    return q;
}

INCLUDE_RODATA("asm/nonmatchings/Lib28D8B0", D_002EB460);
INCLUDE_RODATA("asm/nonmatchings/Lib28D8B0", D_002EB470);
INCLUDE_ASM("asm/nonmatchings/Lib28D8B0", func_0028F728);
INCLUDE_RODATA("asm/nonmatchings/Lib28D8B0", D_002EB480);
INCLUDE_RODATA("asm/nonmatchings/Lib28D8B0", D_002EB488);
INCLUDE_RODATA("asm/nonmatchings/Lib28D8B0", D_002EB490);
INCLUDE_RODATA("asm/nonmatchings/Lib28D8B0", jtbl_002EB4A0);
