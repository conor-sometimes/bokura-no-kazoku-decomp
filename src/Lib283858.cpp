#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern "C" int func_00283888(void);
extern "C" int func_00288FF8(void);
extern "C" void *func_00283C98(void);
extern "C" void (*D_002BF230)(void);
extern "C" void *func_00285DD0(void *);
extern "C" int func_002893A0(void *);

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
struct W2FpNum { s32 cls; u32 sign; s32 exp; u32 pad; u64 frac; };
struct W2FpNumS { s32 cls; u32 sign; s32 exp; u32 frac; };
extern "C" double func_002880D0(W2FpNum *);
extern "C" void *func_00289348(u32);
extern "C" void func_00285CA0(void *, void *);
extern "C" void func_00285D38(void *, void *);

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
struct W2Fde { u32 length; s32 cie; s32 pc; };

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
struct W2FpNum2 { s32 cls; u32 sign; s32 exp; u32 pad; u64 frac; };
extern "C" void func_002881A8(void *, W2FpNum2 *);
extern "C" s32 func_00288268(W2FpNum2 *, W2FpNum2 *);

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern "C" s32 D_2EB920;
extern "C" s32 func_002738A0(s32);
extern "C" s32 func_00273978(s32, s32);
extern "C" void *memset(void *, int, unsigned int);
extern "C" W2FpNum2 *func_00284BD8(W2FpNum2 *, W2FpNum2 *, W2FpNum2 *);

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern "C" s32 D_424500;
extern "C" u8 D_424420[];
extern "C" void *D_424508[];
extern "C" s8 D_424518[];
extern "C" void *D_002BE1C4;
extern "C" void *D_424598;
extern "C" void *func_002843A8(s32, void *, void *);
extern "C" void *memcpy(void *, const void *, unsigned int);
extern "C" s32 func_002731E0(void *);
extern "C" s32 func_002731C0(void *);
struct W2FpNumS2 { s32 cls; u32 sign; s32 exp; u32 frac; };
extern "C" void func_00288040(void *, W2FpNumS2 *);
extern "C" double func_00285468(s32, u32, s32, u64);
struct W2Obj { void *pc_begin; void *pc_end; void *fde_begin; void *fde_array; s32 count; W2Obj *next; };

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern "C" s32 func_00273090(void);
extern "C" void *D_424FE0[];
extern "C" void *func_002838D8(void);
extern "C" void func_00283958(void);

enum W2FpClass { W2_SNAN, W2_QNAN, W2_ZERO, W2_NUMBER, W2_INF };
struct W2Fp { W2FpClass cls; u32 sign; s32 exp; u32 pad; u64 frac; };
static inline int w2_iszero(W2Fp *x) { return x->cls == W2_ZERO; }
static inline int w2_isnan(W2Fp *x) { return x->cls == W2_SNAN || x->cls == W2_QNAN; }
static inline int w2_isinf(W2Fp *x) { return x->cls == W2_INF; }

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern "C" void *func_00283C30(void);
extern "C" s32 D_002BF234;
extern "C" void func_002839A8(void);

enum W2FpClassL { W2L_SNAN, W2L_QNAN, W2L_ZERO, W2L_NUMBER, W2L_INF };
struct W2FpL { W2FpClassL cls; u32 sign; s32 exp; u32 pad; u64 frac; };

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
struct W2Obj2 { void *pc_begin; void *pc_end; void *fde_begin; void *fde_array; s32 count; W2Obj2 *next; };

struct W2ExcTab { void *start_region; void *end_region; void *exception_handler; };

struct W2ExcTab2 { void *start_region; void *end_region; void *exception_handler; void *match_info; };
struct W2ExcDesc { void *runtime_id_field; void *pad; W2ExcTab2 table[1]; };
typedef void *(*W2Matcher)(void *, void *, void *);
struct W2EhInfo { W2Matcher match_function; };
// @decl-end

extern "C" void __pure_virtual(void) { func_00283888(); return; }

extern "C" void func_00283870(void) { func_00288FF8(); return; }

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_00283888);

extern "C" void func_002838D0(void) {
}

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_002838D8);

extern "C" void func_00283930(void *p) { if (p) { func_002893A0(p); return; } }

extern "C" void func_00283958(void) { ((s32 (*)(void))D_002BF230)(); }

extern "C" s32 func_00283980(void) { return (s32)(((u8 *(*)(void))D_002BF230)() + 8); }

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_002839A8);

extern "C" void func_00283BB0(void) { D_002BF230 = (void (*)(void))func_00283C98; }

extern "C" void *func_00283BC8(void) { if (D_002BF230 == (void (*)(void))func_00283BC8) D_002BF230 = (void (*)(void))func_00283C30; if (!D_002BF234) func_002839A8(); return ((void *(*)(void))D_002BF230)(); }

extern "C" void *func_00283C30(void) { if (!D_424500) { D_424500 = 1; memset(D_424420, 0, 0xE0); FLD(void *, D_424420, 4) = D_424508; } return D_424420; }

extern "C" void *func_00283C98(void) { void *eh = D_424FE0[func_00273090()]; if (!eh) { void *old; eh = func_002838D8(); old = D_424FE0[func_00273090()]; if (old) func_002893A0(old); D_424FE0[func_00273090()] = eh; } return eh; }

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_00283D20);

extern "C" void func_00283E00(void *p) { u8 *eh = ((u8 *(*)(void))func_00283958)(); s32 diff = (u8 *)p - (eh + 0x10); if (diff >= 0 && diff < 0xC0) { s32 mask = FLD(s32, eh, 0xD0); s32 bit = 1 << (diff / 16); do { mask ^= bit; bit <<= 1; } while (mask & bit); FLD(s32, eh, 0xD0) = mask; } else { func_002893A0(p); return; } }

extern "C" s32 func_00283E90(void) { return (s32)(((u8 *(*)(void))D_002BF230)() + 4); }

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_00283EB8);

extern "C" s16 func_00284188(void *p) { return FLD(s16, p, 6); }

extern "C" s16 func_00284190(void *p) { return FLD(s16, p, 4); }

extern "C" void *func_00284198(void *pc, W2ExcTab *table)
{
    if (table) {
        int pos;
        int best = -1;

        for (pos = 0; table[pos].start_region != (void *)-1; ++pos) {
            if (table[pos].start_region <= pc && table[pos].end_region > pc) {
                if (best == -1 || (table[pos].end_region <= table[best].end_region
                                   && table[pos].start_region >= table[best].start_region))
                    best = pos;
            }
            else if (best >= 0 && table[pos].start_region > pc)
                break;
        }
        if (best != -1)
            return table[best].exception_handler;
    }

    return (void *)0;
}

extern "C" void *func_00284268(void *pc, W2ExcDesc *table, W2EhInfo *eh_info, int rethrow, int *cleanup)
{
    void *retval = 0;
    *cleanup = 1;
    if (table) {
        int pos = 0;
        W2ExcTab2 *tab = &(table->table[0]);

        if (rethrow) {
            pos = ((W2ExcTab2 *)pc) - tab;
            pc = (char *)((W2ExcTab2 *)pc)->end_region - 1;

            if (tab[pos].start_region != (void *)-1)
                pos++;
        } else
            pc = (char *)pc - 1;

        for (; tab[pos].start_region != (void *)-1; pos++) {
            if (tab[pos].start_region <= pc && tab[pos].end_region > pc) {
                if (tab[pos].match_info) {
                    W2Matcher matcher = eh_info->match_function;
                    if (matcher) {
                        void *ret = (*matcher)((void *)eh_info, tab[pos].match_info, table);
                        if (ret) {
                            if (retval == 0)
                                retval = tab[pos].exception_handler;
                            *cleanup = 0;
                            return retval;
                        }
                    }
                } else {
                    if (retval == 0)
                        retval = tab[pos].exception_handler;
                }
            }
        }
    }
    return retval;
}

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_002843A8);

extern "C" void func_00284438(s32 reg, void *u, void *t) { void *p = func_002843A8(reg, u, 0); void *q = func_002843A8(reg, t, 0); memcpy(q, p, D_424518[reg]); return; }

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_002844A0);

extern "C" void func_00284550(void) {
}

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_00284558);

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_002848E8);

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_00284A38);

extern "C" double fptodp(f32 a) { W2FpNumS2 in; union { f32 f; u32 i; } au; au.f = a; func_00288040(&au, &in); return func_00285468(in.cls, in.sign, in.exp, (u64)in.frac << 30); }

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_00284BD8);

extern "C" double func_00284E38(double a, double b) { W2FpNum2 x, y, t; union { double d; u64 l; } au, bu; au.d = a; bu.d = b; func_002881A8(&au, &x); func_002881A8(&bu, &y); return func_002880D0((W2FpNum *)func_00284BD8(&x, &y, &t)); }

extern "C" double func_00284E90(double a, double b) { W2FpNum2 x, y, t; union { double d; u64 l; } au, bu; au.d = a; bu.d = b; func_002881A8(&au, &x); func_002881A8(&bu, &y); y.sign ^= 1; return func_002880D0((W2FpNum *)func_00284BD8(&x, &y, &t)); }

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_00284EF8);

INCLUDE_ASM("asm/nonmatchings/Lib283858", dpdiv);

extern "C" s32 dpcmp(double a, double b) { W2FpNum2 x, y; union { double d; u64 l; } au, bu; au.d = a; bu.d = b; func_002881A8(&au, &x); func_002881A8(&bu, &y); return func_00288268(&x, &y); }

extern "C" double func_00285310(s32 arg) { W2FpL in; in.cls = W2L_NUMBER; in.sign = arg < 0; if (!arg) { in.cls = W2L_ZERO; } else { in.exp = 60; if (in.sign) { if (arg == (-0x7FFFFFFF) - 1) return (double)((-0x7FFFFFFF) - 1); in.frac = -arg; } else in.frac = arg; while (in.frac < (1ULL << 60)) { in.frac <<= 1; in.exp -= 1; } } return func_002880D0((W2FpNum *)&in); }

extern "C" s32 func_002853C8(double arg) { W2Fp a; union { double d; u64 l; } au; s32 tmp; au.d = arg; func_002881A8(&au, (W2FpNum2 *)&a); if (w2_iszero(&a)) return 0; if (w2_isnan(&a)) return 0; if (w2_isinf(&a)) return a.sign ? (-0x7FFFFFFF) - 1 : 0x7FFFFFFF; if (a.exp < 0) return 0; if (a.exp > 30) return a.sign ? (-0x7FFFFFFF) - 1 : 0x7FFFFFFF; tmp = a.frac >> (60 - a.exp); return a.sign ? -tmp : tmp; }

extern "C" double func_00285468(s32 c, u32 s, s32 e, u64 f) { W2FpNum n; n.cls = c; n.sign = s; n.exp = e; n.frac = f; return func_002880D0(&n); }

INCLUDE_ASM("asm/nonmatchings/Lib283858", dptofp);

extern "C" u32 func_002854F0(double arg) { W2Fp a; union { double d; u64 l; } au; au.d = arg; func_002881A8(&au, (W2FpNum2 *)&a); if (w2_iszero(&a)) return 0; if (w2_isnan(&a)) return 0; if (a.sign) return 0; if (w2_isinf(&a)) return 0xFFFFFFFF; if (a.exp < 0) return 0; if (a.exp > 31) return 0xFFFFFFFF; if (a.exp > 60) return a.frac << (a.exp - 60); else return a.frac >> (60 - a.exp); }

extern "C" u8 *func_00285590(u8 *buf, u32 *r) { u32 shift = 0; u32 result = 0; while (1) { u32 byte = *buf++; result |= (byte & 0x7f) << shift; if ((byte & 0x80) == 0) break; shift += 7; } *r = result; return buf; }

extern "C" u8 *func_002855D8(u8 *buf, s32 *r) { u32 shift = 0; u32 result = 0; u32 byte; while (1) { byte = *buf++; result |= (byte & 0x7f) << shift; shift += 7; if ((byte & 0x80) == 0) break; } if (shift < 32 && (byte & 0x40) != 0) result |= -(1 << shift); *r = result; return buf; }

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_00285630);

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_00285728);

extern "C" void func_00285CA0(void *begin, void *o) { W2Obj *ob = (W2Obj *)o; ob->fde_begin = begin; ob->pc_begin = ob->pc_end = 0; ob->fde_array = 0; ob->count = 0; func_002731E0(D_002BE1C4); ob->next = (W2Obj *)D_424598; D_424598 = ob; func_002731C0(D_002BE1C4); }

extern "C" void func_00285D08(void *p) { func_00285CA0(p, func_00289348(0x18)); return; }

extern "C" void func_00285D38(void *begin, void *o) { W2Obj *ob = (W2Obj *)o; ob->fde_begin = begin; ob->fde_array = begin; ob->pc_begin = ob->pc_end = 0; ob->count = 0; func_002731E0(D_002BE1C4); ob->next = (W2Obj *)D_424598; D_424598 = ob; func_002731C0(D_002BE1C4); }

extern "C" void func_00285DA0(void *p) { func_00285D38(p, func_00289348(0x18)); return; }

extern "C" void *func_00285DD0(void *begin) { W2Obj2 **ob; func_002731E0(D_002BE1C4); ob = (W2Obj2 **)&D_424598; while (*ob) { if ((*ob)->fde_begin == begin) { W2Obj2 *obj = *ob; *ob = (*ob)->next; if (obj->fde_array && obj->fde_array != begin) func_002893A0(obj->fde_array); func_002731C0(D_002BE1C4); return obj; } ob = &(*ob)->next; } func_002731C0(D_002BE1C4); return (void *)func_00288FF8(); }

extern "C" void func_00285E90(void *b) { func_002893A0(func_00285DD0(b)); return; }

extern "C" u32 func_00285EB0(W2Fde *f) { u32 n; for (n = 0; f->length != 0; f = (W2Fde *)((u8 *)f + f->length + 4)) { if (f->cie == 0 || f->pc == 0) continue; ++n; } return n; }

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_00285EF0);
