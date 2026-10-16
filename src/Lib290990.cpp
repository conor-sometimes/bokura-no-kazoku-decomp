#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern "C" int func_00291590(void *, void *);
struct W2File2;
extern "C" int func_00290990(W2File2 *);
extern "C" int func_00290C78(void *);
extern "C" void *func_002916B8(void *);
extern "C" s32 func_00292CA8(s32 *, s32);
extern "C" int func_00292E20(u32, u32);
extern "C" int func_00292F60(u32, u32);
extern "C" void *D_002BF5D0;
extern "C" u8 D_002EB4B8[];

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
struct W2Big { W2Big *next; s32 k; };
struct W2Re { u8 pad[0x4C]; W2Big **fl; };
extern "C" void *D_002BF5D0;
extern "C" int func_00291628(void *, void *, void *);

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern "C" void *func_00291980(void *, s32);
union W2Dbl { double d; struct { u32 lo; s32 hi; } w; };

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern "C" s32 D_2EB920;
extern "C" s32 func_00273888(s32);
extern "C" s32 func_00273768(s32, s32, s32);
extern "C" s32 func_00273958(s32, s32);
extern "C" s32 func_00273898(s32, s32, s32);
extern "C" s32 func_00292A20(void *, char *, s32);
extern "C" s32 func_00292A88(void *, const char *, s32);
extern "C" long func_00292B90(s32 *, s32, s32, s32);
extern "C" long func_00292B08(void *, s32, s32);
extern "C" int func_00292B70(void *);
struct W2File2 { u8 *p; s32 r; s32 w; s16 flags; s16 file; u8 *base; s32 size; s32 lbfsize; void *cookie; void *rd; void *wr; void *sk; void *cl; u8 pad30[0x54 - 0x30]; void *data; };

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
union W2Dbl2 { double d; struct { u32 lo; s32 hi; } w; };
extern "C" s32 func_002737E8(s32, s32, s32);

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern "C" long func_00292DC0(s32 *, s32, s32, s32);
extern "C" s32 func_00292D60(s32 *, s32, s32, s32);
typedef long (*W2LseekFn)(s32 *, s32, s32, s32);
extern "C" void *func_00289640(void *, u32);
extern "C" void *memset(void *, int, unsigned int);
extern "C" double func_00292928(s32);
extern "C" const double D_002EB510[];

typedef union { double value; struct { u32 lsw; u32 msw; } parts; } W2Ieee;
#define EXTRACT_WORDS(ix0,ix1,d) do { W2Ieee ew_u; ew_u.value = (d); (ix0) = ew_u.parts.msw; (ix1) = ew_u.parts.lsw; } while (0)

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern "C" int strcmp(const char *, const char *);
extern "C" const char D_002EB4F8[];
extern "C" const char D_002EB4E8[];
struct W2File2;
extern "C" void func_00290AA8(W2File2 *, s32, s32, void *);

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern "C" void *func_00292BF0(void *, u32, u32);
struct W2Big2 { W2Big2 *next; s32 k; s32 maxwds; s32 sign; s32 wds; u32 x[1]; };

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
union W2DU { double d; u32 i[2]; };
extern "C" double func_00292538(void *, s32 *);

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
struct W2Bg { W2Bg *next; s32 k; s32 maxwds; s32 sign; s32 wds; u32 x[1]; };
extern "C" void *memcpy(void *, const void *, unsigned int);
extern "C" void func_00291A28(W2Re *, W2Big *);
struct W2Glue { W2Glue *next; s32 niobs; u8 *iobs; };

struct W2Bg2 { W2Bg2 *next; s32 k; s32 maxwds; s32 sign; s32 wds; u32 x[1]; };
extern "C" W2Bg2 *func_00291A58(void *, W2Bg2 *, s32, s32);
extern "C" W2Bg2 *func_00291E08(void *, W2Bg2 *, W2Bg2 *);
extern "C" const s32 D_002EB4FC[];
extern "C" void *func_00291DD0(void *, s32);

struct W2Bg3 { W2Bg3 *next; s32 k; s32 maxwds; s32 sign; s32 wds; u32 x[1]; };
extern "C" s32 func_00291C90(u32);
extern "C" s32 func_00292270(void *, void *);

extern "C" s32 func_00291D10(u32 *);

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
struct W2Glue2 { W2Glue2 *next; s32 niobs; W2File2 *iobs; };
struct W2Stat { u32 dev; u32 mode; u8 pad[0x70 - 8]; };
extern "C" s32 func_00273950(s32);
extern "C" void func_00290CB8(void *);
extern "C" void *func_00290B08(void *, s32);
extern "C" int func_00290C78(void *);
extern "C" s32 func_00292D00(s32 *, s32, s32);
// @decl-end

extern "C" int func_00290990(W2File2 *fp) { u8 *p; s32 n, t; if (fp == 0) return func_00291590(D_002BF5D0, (void *)func_00290990); do { if (fp->data == 0) fp->data = D_002BF5D0; if (!FLD(s32, fp->data, 0x38)) func_00290CB8(fp->data); } while (0); t = fp->flags; if ((t & 8) == 0 || (p = fp->base) == 0) return 0; n = fp->p - p; fp->p = p; fp->w = t & 3 ? 0 : fp->size; while (n > 0) { t = ((s32 (*)(void *, u8 *, s32))fp->wr)(fp->cookie, p, n); if (t <= 0) { fp->flags |= 0x40; return -1; } p += t; n -= t; } return 0; }

extern "C" void func_00290AA8(W2File2 *ptr, s32 flags, s32 file, void *data) { ptr->p = 0; ptr->r = 0; ptr->w = 0; ptr->flags = flags; ptr->file = file; ptr->base = 0; ptr->size = 0; ptr->lbfsize = 0; ptr->cookie = ptr; ptr->rd = (void *)func_00292A20; ptr->wr = (void *)func_00292A88; ptr->sk = (void *)func_00292B08; ptr->cl = (void *)func_00292B70; ptr->data = data; }

extern "C" void *func_00290B08(void *d, s32 n) { u8 *g; u8 *p; g = (u8 *)func_00289640(d, 0xC + n * 0x58); if (g == 0) return 0; p = g + 0xC; FLD(void *, g, 0) = 0; FLD(s32, g, 4) = n; FLD(void *, g, 8) = p; memset(p, 0, n * 0x58); return g; }

extern "C" W2File2 *func_00290B80(void *d) { W2File2 *fp; s32 n; W2Glue2 *g; if (!FLD(s32, d, 0x38)) func_00290CB8(d); for (g = (W2Glue2 *)((u8 *)d + 0x1D8);; g = g->next) { for (fp = g->iobs, n = g->niobs; --n >= 0; fp = (W2File2 *)((u8 *)fp + 0x58)) if (fp->flags == 0) goto found; if (g->next == 0 && (g->next = (W2Glue2 *)func_00290B08(d, 4)) == 0) break; } *(s32 *)d = 12; return 0; found: fp->flags = 1; fp->p = 0; fp->w = 0; fp->r = 0; fp->base = 0; fp->size = 0; fp->lbfsize = 0; FLD(void *, fp, 0x30) = 0; FLD(s32, fp, 0x34) = 0; FLD(void *, fp, 0x44) = 0; FLD(s32, fp, 0x48) = 0; fp->file = -1; fp->data = d; return fp; }

extern "C" int func_00290C78(void *p) { return func_00291590(p, (void *)func_00290990); }

extern "C" int func_00290C98(void) { return func_00290C78(D_002BF5D0); }

extern "C" void func_00290CB8(void *s) { FLD(void *, s, 0x3C) = (void *)func_00290C78; FLD(s32, s, 0x38) = 1; func_00290AA8((W2File2 *)((u8 *)s + 0x1E4), 4, 0, s); func_00290AA8((W2File2 *)((u8 *)s + 0x23C), 9, 1, s); func_00290AA8((W2File2 *)((u8 *)s + 0x294), 0xA, 2, s); FLD(void *, s, 0x1D8) = 0; FLD(s32, s, 0x1DC) = 3; FLD(void *, s, 0x1E0) = (u8 *)s + 0x1E4; }

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00290D48);

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00291040);

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_002911B0);

extern "C" int func_00291590(void *ptr, void *fnv) { s32 (*function)(void *) = (s32 (*)(void *))fnv; u8 *fp; s32 n, ret = 0; W2Glue *g; for (g = (W2Glue *)((u8 *)ptr + 0x1D8); g != 0; g = g->next) for (fp = g->iobs, n = g->niobs; --n >= 0; fp += 0x58) if (FLD(s16, fp, 0xC) != 0) ret |= (*function)(fp); return ret; }

extern "C" int func_00291628(void *r, void *cat, void *loc) { if (loc) { if (strcmp((char *)loc, D_002EB4F8) && strcmp((char *)loc, D_002EB4E8)) return 0; FLD(void *, r, 0x30) = cat; FLD(void *, r, 0x34) = loc; } return (int)D_002EB4F8; }

extern "C" void *func_002916B8(void *) { return D_002EB4B8; }

extern "C" int func_002916C8(void *a, void *b) { return func_00291628(D_002BF5D0, a, b); }

extern "C" void *func_002916F0(void) { return func_002916B8(D_002BF5D0); }

extern "C" void func_00291710(W2File2 *fp) { u32 size, couldbetty; void *p; W2Stat st; if (fp->flags & 2) { fp->base = fp->p = (u8 *)fp + 0x43; fp->size = 1; return; } if (fp->file < 0 || func_00292D00((s32 *)fp->data, fp->file, (s32)&st) < 0) { couldbetty = 0; size = 0x400; fp->flags |= 0x800; } else { couldbetty = (st.mode & 0xF000) == 0x2000; size = 0x400; if ((st.mode & 0xF000) == 0x8000 && fp->sk == (void *)func_00292B08) { fp->flags |= 0x400; FLD(s32, fp, 0x4C) = size; } else fp->flags |= 0x800; } if ((p = func_00289640(fp->data, size)) == 0) { fp->flags |= 2; fp->base = fp->p = (u8 *)fp + 0x43; fp->size = 1; } else { FLD(void *, fp->data, 0x3C) = (void *)func_00290C78; fp->flags |= 0x80; fp->base = fp->p = (u8 *)p; fp->size = size; if (couldbetty && func_00273950(fp->file)) fp->flags |= 1; } }

extern "C" int func_00291868(void *r, u32 *pwc, const u8 *s, u32 n) { u32 dummy; if (pwc == 0) pwc = &dummy; if (s == 0) return 0; if (n == 0) return -1; *pwc = *s; return *s != 0; }

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_0029189C);

extern "C" void *func_00291980(void *ptr, s32 k) { s32 x; W2Big2 *rv; if (FLD(W2Big2 **, ptr, 0x4C) == 0) { FLD(W2Big2 **, ptr, 0x4C) = (W2Big2 **)func_00292BF0(ptr, 4, 16); if (FLD(W2Big2 **, ptr, 0x4C) == 0) return 0; } if ((rv = FLD(W2Big2 **, ptr, 0x4C)[k]) != 0) { FLD(W2Big2 **, ptr, 0x4C)[k] = rv->next; } else { x = 1 << k; rv = (W2Big2 *)func_00292BF0(ptr, 1, sizeof(W2Big2) + (x - 1) * 4); if (rv == 0) return 0; rv->k = k; rv->maxwds = x; } rv->sign = rv->wds = 0; return rv; }

extern "C" void func_00291A28(W2Re *r, W2Big *v) { if (v) { s32 k = v->k; W2Big **fl = r->fl; v->next = fl[k]; fl[k] = v; } }

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00291A58);

extern "C" W2Bg2 *func_00291B60(void *ptr, const char *s, s32 nd0, s32 nd, u32 y9) { W2Bg2 *b; s32 i, k; s32 x, y; x = (nd + 8) / 9; for (k = 0, y = 1; x > y; y <<= 1, k++); b = (W2Bg2 *)func_00291980(ptr, k); b->x[0] = y9; b->wds = 1; i = 9; if (9 < nd0) { s += 9; do b = func_00291A58(ptr, b, 10, *s++ - '0'); while (++i < nd0); s++; } else s += 10; for (; i < nd; i++) b = func_00291A58(ptr, b, 10, *s++ - '0'); return b; }

extern "C" s32 func_00291C90(u32 x) { s32 k = 0; if (!(x & 0xffff0000)) { k = 16; x <<= 16; } if (!(x & 0xff000000)) { k += 8; x <<= 8; } if (!(x & 0xf0000000)) { k += 4; x <<= 4; } if (!(x & 0xc0000000)) { k += 2; x <<= 2; } if (!(x & 0x80000000)) { k++; if (!(x & 0x40000000)) return 32; } return k; }

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00291D10);

extern "C" void *func_00291DD0(void *r, s32 i) { void *b = func_00291980(r, 1); FLD(s32, b, 0x14) = i; FLD(s32, b, 0x10) = 1; return b; }

extern "C" W2Bg2 *func_00291E08(void *ptr, W2Bg2 *a, W2Bg2 *b) { W2Bg2 *c; s32 k, wa, wb, wc; u32 carry, y, z; u32 *x, *xa, *xae, *xb, *xbe, *xc, *xc0; u32 z2; if (a->wds < b->wds) { c = a; a = b; b = c; } k = a->k; wa = a->wds; wb = b->wds; wc = wa + wb; if (wc > a->maxwds) k++; c = (W2Bg2 *)func_00291980(ptr, k); for (x = c->x, xa = x + wc; x < xa; x++) *x = 0; xa = a->x; xae = xa + wa; xb = b->x; xbe = xb + wb; xc0 = c->x; for (; xb < xbe; xb++, xc0++) { if ((y = *xb & 0xffff) != 0) { x = xa; xc = xc0; carry = 0; do { z = (*x & 0xffff) * y + (*xc & 0xffff) + carry; carry = z >> 16; z2 = (*x++ >> 16) * y + (*xc >> 16) + carry; carry = z2 >> 16; (((u16 *)xc)[1] = (u16)z2, ((u16 *)xc)[0] = (u16)z, xc++); } while (x < xae); *xc = carry; } if ((y = *xb >> 16) != 0) { x = xa; xc = xc0; carry = 0; z2 = *xc; do { z = (*x & 0xffff) * y + (*xc >> 16) + carry; carry = z >> 16; (((u16 *)xc)[1] = (u16)z, ((u16 *)xc)[0] = (u16)z2, xc++); z2 = (*x++ >> 16) * y + (*xc & 0xffff) + carry; carry = z2 >> 16; } while (x < xae); *xc = z2; } } for (xc0 = c->x, xc = xc0 + wc; wc > 0 && !*--xc; --wc); c->wds = wc; return c; }

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00292018);

extern "C" W2Bg2 *func_00292118(void *ptr, W2Bg2 *b, s32 k) { s32 i, k1, n, n1; W2Bg2 *b1; u32 *x, *x1, *xe, z; n = k >> 5; k1 = b->k; n1 = n + b->wds + 1; for (i = b->maxwds; n1 > i; i <<= 1) k1++; b1 = (W2Bg2 *)func_00291980(ptr, k1); x1 = b1->x; for (i = 0; i < n; i++) *x1++ = 0; x = b->x; xe = x + b->wds; if (k &= 0x1f) { k1 = 32 - k; z = 0; do { *x1++ = *x << k | z; z = *x++ >> k1; } while (x < xe); if ((*x1 = z) != 0) ++n1; } else do *x1++ = *x++; while (x < xe); b1->wds = n1 - 1; func_00291A28((W2Re *)ptr, (W2Big *)b); return b1; }

extern "C" s32 func_00292270(void *a, void *b) { u32 *xa, *xa0, *xb, *xb0; s32 i, j; i = FLD(s32, a, 0x10); j = FLD(s32, b, 0x10); if (i -= j) return i; xa0 = (u32 *)((u8 *)a + 0x14); xa = xa0 + j; xb0 = (u32 *)((u8 *)b + 0x14); xb = xb0 + j; for (;;) { if (*--xa != *--xb) return *xa < *xb ? -1 : 1; if (xa <= xa0) break; } return 0; }

extern "C" W2Bg3 *func_002922D8(void *ptr, W2Bg3 *a, W2Bg3 *b) { W2Bg3 *c; s32 i, wa, wb; s32 borrow, y; u32 *xa, *xae, *xb, *xbe, *xc; s32 z; i = func_00292270(a, b); if (!i) { c = (W2Bg3 *)func_00291980(ptr, 0); c->wds = 1; c->x[0] = 0; return c; } if (i < 0) { c = a; a = b; b = c; i = 1; } else i = 0; c = (W2Bg3 *)func_00291980(ptr, a->k); c->sign = i; wa = a->wds; xa = a->x; xae = xa + wa; wb = b->wds; xb = b->x; xbe = xb + wb; xc = c->x; borrow = 0; do { y = (*xa & 0xffff) - (*xb & 0xffff) + borrow; borrow = y >> 16; z = (*xa++ >> 16) - (*xb++ >> 16) + borrow; borrow = z >> 16; (((u16 *)xc)[1] = (u16)z, ((u16 *)xc)[0] = (u16)y, xc++); } while (xb < xbe); while (xa < xae) { y = (*xa & 0xffff) + borrow; borrow = y >> 16; z = (*xa++ >> 16) + borrow; borrow = z >> 16; (((u16 *)xc)[1] = (u16)z, ((u16 *)xc)[0] = (u16)y, xc++); } while (!*--xc) wa--; c->wds = wa; return c; }

extern "C" double func_00292468(double _x) { W2DU x, a; s32 L; x.d = _x; L = (x.i[1] & 0x7ff00000) - (53 - 1) * 0x100000; if (L > 0) { a.i[1] = L; a.i[0] = 0; } else { L = -L >> 20; if (L < 20) { a.i[1] = 0x80000 >> L; a.i[0] = 0; } else { a.i[1] = 0; L -= 20; a.i[0] = L >= 31 ? 1 : 1 << (31 - L); } } return a.d; }

extern "C" double func_00292538(void *av, s32 *e) { W2Bg3 *a = (W2Bg3 *)av; u32 *xa, *xa0, w, y, z; s32 k; W2DU d; xa0 = a->x; xa = xa0 + a->wds; y = *--xa; k = func_00291C90(y); *e = 32 - k; if (k < 11) { d.i[1] = 0x3ff00000 | y >> (11 - k); w = xa > xa0 ? *--xa : 0; d.i[0] = y << ((32 - 11) + k) | w >> (11 - k); goto ret_d; } z = xa > xa0 ? *--xa : 0; if (k -= 11) { d.i[1] = 0x3ff00000 | y << k | z >> (32 - k); y = xa > xa0 ? *--xa : 0; d.i[0] = z << k | y >> (32 - k); } else { d.i[1] = 0x3ff00000 | y; d.i[0] = z; } ret_d: return d.d; }

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_002926D0);

extern "C" double func_00292858(void *a, void *b) { W2DU da, db; s32 k, ka, kb; da.d = func_00292538(a, &ka); db.d = func_00292538(b, &kb); k = ka - kb + 32 * (FLD(s32, a, 0x10) - FLD(s32, b, 0x10)); if (k > 0) da.i[1] += k * 0x100000; else { k = -k; db.i[1] += k * 0x100000; } return da.d / db.d; }

asm(".p2align 3");
extern "C" double func_00292928(s32 dig) { double v = 1.0; if (dig < 24) return D_002EB510[dig]; while (dig > 0) { v *= 10; dig--; } return v; }

extern "C" s32 func_00292998(double x) { s32 hx, lx; EXTRACT_WORDS(hx, lx, x); hx &= 0x7fffffff; hx |= (u32)(lx | (-lx)) >> 31; hx = 0x7ff00000 - hx; return 1 - (s32)((u32)(hx | (-hx)) >> 31); }

extern "C" s32 func_002929E0(double x) { s32 hx, lx; EXTRACT_WORDS(hx, lx, x); hx &= 0x7fffffff; hx |= (u32)(lx | (-lx)) >> 31; hx = 0x7ff00000 - hx; return (s32)(((u32)(hx)) >> 31); }

extern "C" s32 func_00292A20(void *cookie, char *buf, s32 n) { W2File2 *fp = (W2File2 *)cookie; s32 ret; ret = func_00292DC0((s32 *)fp->data, fp->file, (s32)buf, n); if (ret >= 0) FLD(s32, fp, 0x50) += ret; else fp->flags &= ~0x1000; return ret; }

extern "C" s32 func_00292A88(void *cookie, const char *buf, s32 n) { W2File2 *fp = (W2File2 *)cookie; if (fp->flags & 0x100) func_00292D60((s32 *)fp->data, fp->file, 0, 2); fp->flags &= ~0x1000; return func_00292B90((s32 *)fp->data, fp->file, (s32)buf, n); }

extern "C" long func_00292B08(void *cookie, s32 offset, s32 whence) { W2File2 *fp = (W2File2 *)cookie; long ret; ret = ((W2LseekFn)func_00292D60)((s32 *)fp->data, fp->file, offset, whence); if (ret == -1) fp->flags &= ~0x1000; else { fp->flags |= 0x1000; FLD(s32, fp, 0x50) = ret; } return ret; }

extern "C" int func_00292B70(void *p) { return func_00292CA8(FLD(s32 *, p, 0x54), FLD(s16, p, 0xE)); }

extern "C" long func_00292B90(s32 *ptr, s32 a, s32 b, s32 c) { long ret; D_2EB920 = 0; if ((ret = func_00273768(a, b, c)) == -1 && D_2EB920 != 0) *ptr = D_2EB920; return ret; }

extern "C" void *func_00292BF0(void *ptr, u32 n, u32 size) { void *mem; u32 csz; n *= size; mem = func_00289640(ptr, n); if (!mem) return 0; csz = FLD(u32, mem, -4) & ~3; do { u32 mzsz = csz - 4; if (mzsz <= 9 * 4) { u32 *mz = (u32 *)mem; if (mzsz >= 5 * 4) { *mz++ = 0; *mz++ = 0; if (mzsz >= 7 * 4) { *mz++ = 0; *mz++ = 0; if (mzsz >= 9 * 4) { *mz++ = 0; *mz++ = 0; } } } *mz++ = 0; *mz++ = 0; *mz = 0; } else memset(mem, 0, mzsz); } while (0); return mem; }

extern "C" s32 func_00292CA8(s32 *ptr, s32 fd) { s32 ret; D_2EB920 = 0; if ((ret = func_00273888(fd)) == -1 && D_2EB920 != 0) *ptr = D_2EB920; return ret; }

extern "C" s32 func_00292D00(s32 *ptr, s32 a, s32 b) { s32 ret; D_2EB920 = 0; if ((ret = func_00273958(a, b)) == -1 && D_2EB920 != 0) *ptr = D_2EB920; return ret; }

extern "C" s32 func_00292D60(s32 *ptr, s32 a, s32 b, s32 c) { s32 ret; D_2EB920 = 0; if ((ret = func_00273898(a, b, c)) == -1 && D_2EB920 != 0) *ptr = D_2EB920; return ret; }

extern "C" long func_00292DC0(s32 *ptr, s32 a, s32 b, s32 c) { long ret; D_2EB920 = 0; if ((ret = func_002737E8(a, b, c)) == -1 && D_2EB920 != 0) *ptr = D_2EB920; return ret; }

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00292E20);

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00292EC8);

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00292F48);

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00292F60);

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00293008);

INCLUDE_ASM("asm/nonmatchings/Lib290990", func_00293088);
