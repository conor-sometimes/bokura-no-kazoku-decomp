#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern "C" s32 func_002911B0(void *, void *);

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern "C" void *D_002BF5D0;
struct W2File { u8 *p; s32 r; s32 w; s16 flags; s16 file; u8 *base; s32 size; s32 lbfsize; void *cookie; void *rd; void *wr; void *sk; void *cl; u8 pad30[0x54 - 0x30]; void *data; };
extern "C" s32 func_0028D9B0(W2File *, const char *, void *);

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern "C" void func_00290CB8(void *);
extern "C" s32 func_0028DA28(void *, void *, const char *, void *);

struct W2File6 { u8 *p; s32 r; s32 w; s16 flags; s16 file; u8 *base; s32 size; s32 lbfsize; void *cookie; void *rd; void *wr; void *sk; void *cl; u8 *ubbase; s32 ubsize; u8 *up; s32 ur; u8 ubuf[3]; u8 nbuf[1]; u8 lb[8]; s32 blksize; s32 offset; void *data; };
extern "C" void func_00290D48(void *, void *);
extern "C" void func_00291710(W2File6 *);
// @decl-end

extern "C" s32 func_0028D8B0(void *fp, void *uio) { s32 err; if (FLD(s32, uio, 8) == 0) { FLD(s32, uio, 4) = 0; return 0; } err = func_002911B0(fp, uio); FLD(s32, uio, 8) = 0; FLD(s32, uio, 4) = 0; return err; }

INCLUDE_ASM("asm/nonmatchings/Lib28D8B0", func_0028D8F8);

extern "C" s32 func_0028D9B0(W2File *fp, const char *fmt, void *ap) { do { if (fp->data == 0) fp->data = D_002BF5D0; if (!FLD(s32, fp->data, 0x38)) func_00290CB8(fp->data); } while (0); return func_0028DA28(fp->data, fp, fmt, ap); }

INCLUDE_ASM("asm/nonmatchings/Lib28D8B0", func_0028DA28);

INCLUDE_ASM("asm/nonmatchings/Lib28D8B0", func_0028F098);

extern "C" s32 func_0028F258(char *p0, s32 exp, s32 fmtch) { char *p, *t; char expbuf[308]; p = p0; *p++ = fmtch; if (exp < 0) { exp = -exp; *p++ = '-'; } else *p++ = '+'; t = expbuf + 308; if (exp > 9) { do { *--t = exp % 10 + '0'; } while ((exp /= 10) > 9); *--t = exp + '0'; for (; t < expbuf + 308; *p++ = *t++); } else { *p++ = '0'; *p++ = exp + '0'; } return p - p0; }

extern "C" s32 vsprintf(char *str, const char *fmt, void *ap) { s32 ret; W2File f; f.flags = 0x208; f.base = f.p = (u8 *)str; f.size = f.w = 0x7FFFFFFF; f.data = D_002BF5D0; ret = func_0028D9B0(&f, fmt, ap); *f.p = 0; return ret; }

extern "C" s32 func_0028F390(void *ptr, char *str, const char *fmt, void *ap) { s32 ret; W2File f; f.flags = 0x208; f.base = f.p = (u8 *)str; f.size = f.w = 0x7FFFFFFF; f.data = ptr; ret = func_0028D9B0(&f, fmt, ap); *f.p = 0; return ret; }

extern "C" int func_0028F3E8(W2File6 *fp)
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

INCLUDE_ASM("asm/nonmatchings/Lib28D8B0", func_0028F4F8);

INCLUDE_ASM("asm/nonmatchings/Lib28D8B0", func_0028F728);
