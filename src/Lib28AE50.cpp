#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern "C" int func_0028AD50(void *, int);
extern "C" int func_00273970(void);
extern "C" void *D_002BF5D0;

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern "C" void *D_002BF5D0;
extern "C" double func_0028B970(void *, const char *, char **);
extern "C" double func_0028C888(const char *, char **);
extern "C" long func_0028C8D8(void *, const char *, char **, int);

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern "C" s32 func_002911B0(void *, void *);
extern "C" const char _ctype_[];

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern "C" s32 D_2EB920;
extern "C" s32 func_00273978(s32, s32);

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern "C" void func_00290CB8(void *);
extern "C" s32 func_0028CCB8(void *, void *, const char *, void *);
struct W2Re { u8 pad[0x38]; s32 sdidinit; };
struct W2F { u8 pad[0x54]; W2Re *data; };

struct W2File5 { u8 *p; s32 r; s32 w; s16 flags; s16 file; u8 *base; s32 size; s32 lbfsize; void *cookie; void *rd; void *wr; void *sk; void *cl; u8 pad30[0x54 - 0x30]; void *data; };
extern "C" s32 func_0028D9B0(W2File5 *, const char *, char *);
// @decl-end

extern "C" int func_0028AE50(int s) { return func_0028AD50(D_002BF5D0, s); }

extern "C" s32 func_0028AE70(s32 *ptr, s32 a, s32 b) { s32 ret; D_2EB920 = 0; if ((ret = func_00273978(a, b)) == -1 && D_2EB920 != 0) *ptr = D_2EB920; return ret; }

extern "C" int func_0028AED0(void) { return func_00273970(); }

extern "C" s32 func_0028AEE8(void *ptr, char *str, const char *fmt, ...) { s32 ret; W2File5 f; char *ap; f.flags = 0x208; f.base = f.p = (u8 *)str; f.size = f.w = 0x7FFFFFFF; f.data = ptr; ap = (char *)__builtin_next_arg(fmt) - (8 - __builtin_args_info(2)) * 8; ret = func_0028D9B0(&f, fmt, ap); *f.p = 0; return ret; }

extern "C" s32 sprintf(char *str, const char *fmt, ...) { s32 ret; W2File5 f; char *ap; f.flags = 0x208; f.base = f.p = (u8 *)str; f.size = f.w = 0x7FFFFFFF; f.data = D_002BF5D0; ap = (char *)__builtin_next_arg(fmt) - (8 - __builtin_args_info(2)) * 8; ret = func_0028D9B0(&f, fmt, ap); *f.p = 0; return ret; }

INCLUDE_ASM("asm/nonmatchings/Lib28AE50", func_0028B000);

INCLUDE_ASM("asm/nonmatchings/Lib28AE50", strcmp);

INCLUDE_ASM("asm/nonmatchings/Lib28AE50", strcpy);

INCLUDE_ASM("asm/nonmatchings/Lib28AE50", strlen);

extern "C" char *func_0028B520(char *a) { char *ret = a; while (*a != 0) { int c = *a; if ((_ctype_ + 1)[c] & 1) *a = c - 0x41 + 0x61; ++a; } return ret; }

INCLUDE_ASM("asm/nonmatchings/Lib28AE50", func_0028B570);

INCLUDE_ASM("asm/nonmatchings/Lib28AE50", func_0028B728);

extern "C" char *strstr(const char *searchee, const char *lookfor)
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

extern "C" double func_0028C888(const char *s, char **e) { return func_0028B970(D_002BF5D0, s, e); }

extern "C" float func_0028C8B0(const char *s, char **e) { return func_0028C888(s, e); }

INCLUDE_ASM("asm/nonmatchings/Lib28AE50", func_0028C8D8);

extern "C" long func_0028CB10(const char *s, char **e, int b) { return func_0028C8D8(D_002BF5D0, s, e, b); }

extern "C" s32 func_0028CB40(void *fp, void *uio) { s32 err; if (FLD(s32, uio, 8) == 0) { FLD(s32, uio, 4) = 0; return 0; } err = func_002911B0(fp, uio); FLD(s32, uio, 8) = 0; FLD(s32, uio, 4) = 0; return err; }

INCLUDE_ASM("asm/nonmatchings/Lib28AE50", func_0028CB88);

extern "C" s32 func_0028CC40(W2F *fp, const char *fmt, void *ap) { do { if (fp->data == 0) fp->data = (W2Re *)D_002BF5D0; if (!fp->data->sdidinit) func_00290CB8(fp->data); } while (0); return func_0028CCB8(fp->data, fp, fmt, ap); }

INCLUDE_ASM("asm/nonmatchings/Lib28AE50", func_0028CCB8);
