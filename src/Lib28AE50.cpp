#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern int func_0028AD50(void *, int);
extern int func_00273970(void);
extern void *D_002BF5D0;

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern void *D_002BF5D0;
extern double func_0028B970(void *, const char *, char **);
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
extern s32 func_0028CCB8(void *, void *, const char *, void *);
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

INCLUDE_ASM("asm/nonmatchings/Lib28AE50", func_0028B970);
INCLUDE_RODATA("asm/nonmatchings/Lib28AE50", D_002EB048);
INCLUDE_RODATA("asm/nonmatchings/Lib28AE50", D_002EB050);
INCLUDE_RODATA("asm/nonmatchings/Lib28AE50", D_002EB058);

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

INCLUDE_RODATA("asm/nonmatchings/Lib28AE50", D_002EB060);
INCLUDE_RODATA("asm/nonmatchings/Lib28AE50", D_002EB070);
INCLUDE_RODATA("asm/nonmatchings/Lib28AE50", D_002EB080);
INCLUDE_ASM("asm/nonmatchings/Lib28AE50", func_0028CCB8);
