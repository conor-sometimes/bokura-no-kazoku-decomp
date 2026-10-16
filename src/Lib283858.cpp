#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern int func_00283888(void);
extern int func_00288FF8(void);
extern void *func_00283C98(void);
extern void (*D_002BF230)(void);
extern void *func_00285DD0(void *);
extern int func_002893A0(void *);

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
typedef struct W2FpNum W2FpNum;
struct W2FpNum { s32 cls; u32 sign; s32 exp; u32 pad; u64 frac; };
typedef struct W2FpNumS W2FpNumS;
struct W2FpNumS { s32 cls; u32 sign; s32 exp; u32 frac; };
extern double func_002880D0(W2FpNum *);
extern void *func_00289348(u32);
extern void func_00285CA0(void *, void *);
extern void func_00285D38(void *, void *);

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
typedef struct W2Fde W2Fde;
struct W2Fde { u32 length; s32 cie; s32 pc; };

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
typedef struct W2FpNum2 W2FpNum2;
struct W2FpNum2 { s32 cls; u32 sign; s32 exp; u32 pad; u64 frac; };
extern void func_002881A8(void *, W2FpNum2 *);
extern s32 func_00288268(W2FpNum2 *, W2FpNum2 *);

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern s32 D_2EB920;
extern s32 func_002738A0(s32);
extern s32 func_00273978(s32, s32);
extern void *memset(void *, int, unsigned int);
extern W2FpNum2 *func_00284BD8(W2FpNum2 *, W2FpNum2 *, W2FpNum2 *);

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern s32 D_424500;
extern u8 D_424420[];
extern void *D_424508[];
extern s8 D_424518[];
extern void *D_002BE1C4;
extern void *D_424598;
extern void *func_002843A8(s32, void *, void *);
extern void *memcpy(void *, const void *, unsigned int);
extern s32 func_002731E0(void *);
extern s32 func_002731C0(void *);
typedef struct W2FpNumS2 W2FpNumS2;
struct W2FpNumS2 { s32 cls; u32 sign; s32 exp; u32 frac; };
extern void func_00288040(void *, W2FpNumS2 *);
extern double func_00285468(s32, u32, s32, u64);
typedef struct W2Obj W2Obj;
struct W2Obj { void *pc_begin; void *pc_end; void *fde_begin; void *fde_array; s32 count; W2Obj *next; };

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern s32 func_00273090(void);
extern void *D_424FE0[];
extern void *func_002838D8(void);
extern void func_00283958(void);

typedef enum W2FpClass { W2_SNAN, W2_QNAN, W2_ZERO, W2_NUMBER, W2_INF } W2FpClass;
typedef struct W2Fp W2Fp;
struct W2Fp { W2FpClass cls; u32 sign; s32 exp; u32 pad; u64 frac; };
static inline int w2_iszero(W2Fp *x) { return x->cls == W2_ZERO; }
static inline int w2_isnan(W2Fp *x) { return x->cls == W2_SNAN || x->cls == W2_QNAN; }
static inline int w2_isinf(W2Fp *x) { return x->cls == W2_INF; }

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern void *func_00283C30(void);
extern s32 D_002BF234;
extern void func_002839A8(void);

typedef enum W2FpClassL { W2L_SNAN, W2L_QNAN, W2L_ZERO, W2L_NUMBER, W2L_INF } W2FpClassL;
typedef struct W2FpL W2FpL;
struct W2FpL { W2FpClassL cls; u32 sign; s32 exp; u32 pad; u64 frac; };

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
typedef struct W2Obj2 W2Obj2;
struct W2Obj2 { void *pc_begin; void *pc_end; void *fde_begin; void *fde_array; s32 count; W2Obj2 *next; };

typedef struct W2ExcTab W2ExcTab;
struct W2ExcTab { void *start_region; void *end_region; void *exception_handler; };

typedef struct W2ExcTab2 W2ExcTab2;
struct W2ExcTab2 { void *start_region; void *end_region; void *exception_handler; void *match_info; };
typedef struct W2ExcDesc W2ExcDesc;
struct W2ExcDesc { void *runtime_id_field; void *pad; W2ExcTab2 table[1]; };
typedef void *(*W2Matcher)(void *, void *, void *);
typedef struct W2EhInfo W2EhInfo;
struct W2EhInfo { W2Matcher match_function; };
typedef struct W2EhCtx W2EhCtx;
struct W2EhCtx { void *handler_label; void **dynamic_handler_chain; void *info; void *table_index; };
typedef struct W2FrameStateT W2FrameStateT;
struct W2FrameStateT { void *cfa; u8 rest[0x478 - 4]; } __attribute__((aligned(8)));
extern W2FrameStateT *func_00286968(void *, W2FrameStateT *);
extern void *func_00284558(W2EhCtx *, void *, W2FrameStateT *, long *);
extern void W2Terminate(void) asm("func_00283888") __attribute__((noreturn));
extern W2Fp D_002EAB80;
static inline W2Fp *w2_fpdiv_parts(W2Fp *a, W2Fp *b)
{
    u64 bit;
    u64 numerator;
    u64 denominator;
    u64 quotient;

    if (w2_isnan(a)) {
        return a;
    }
    if (w2_isnan(b)) {
        return b;
    }

    a->sign = a->sign ^ b->sign;

    if (w2_isinf(a) || w2_iszero(a)) {
        if (a->cls == b->cls)
            return &D_002EAB80;
        return a;
    }

    if (w2_isinf(b)) {
        a->frac = 0;
        a->exp = 0;
        return a;
    }
    if (w2_iszero(b)) {
        a->cls = W2_INF;
        return a;
    }

    {
        a->exp = a->exp - b->exp;
        numerator = a->frac;
        denominator = b->frac;

        if (numerator < denominator) {
            numerator *= 2;
            a->exp -= 1;
        }
        bit = 1ULL << 60;
        quotient = 0;
        while (bit) {
            if (numerator >= denominator) {
                quotient |= bit;
                numerator -= denominator;
            }
            bit >>= 1;
            numerator *= 2;
        }

        a->frac = quotient;
        return (a);
    }
}

#define W2LSHIFT(X) { X = ((X) & 1) | ((X) >> 1); }
extern void func_00283EB8(void) __attribute__((noreturn));

extern f32 func_002880A0(s32, u32, s32, u32);

typedef struct Y1Fde { u32 length; s32 CIE_delta; void *pc_begin; void *pc_range; } Y1Fde;
typedef struct { Y1Fde **array; u32 count; } Y1FdeVec;
static __inline__ int y1_fde_compare(Y1Fde *x, Y1Fde *y) { return (int)x->pc_begin - (int)y->pc_begin; }
extern void (*D_002BF22C)(void) __attribute__((noreturn));
extern int strcmp(const char *, const char *);
// @decl-end

extern void __pure_virtual(void) { func_00283888(); return; }

extern void func_00283870(void) { func_00288FF8(); return; }

/* __terminate; defined under its own name so the callers below (declared W2Terminate) stay as retail saw them */
void Y1Terminate(void) asm("func_00283888");
void Y1Terminate(void)
{
    (*D_002BF22C)();
}

void *func_002838A0(void *catch_type, void *throw_type, void *obj)
{
    if (strcmp((const char *)catch_type, (const char *)throw_type) == 0)
        return obj;
    return 0;
}

extern void func_002838D0(void) {
}

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_002838D8);

extern void func_00283930(void *p) { if (p) { func_002893A0(p); return; } }

extern void func_00283958(void) { ((s32 (*)(void))D_002BF230)(); }

extern s32 func_00283980(void) { return (s32)(((u8 *(*)(void))D_002BF230)() + 8); }

extern void func_002839A8(void)
{
    __builtin_init_dwarf_reg_size_table(D_424518);
    D_002BF234 = 1;
}

extern void func_00283BB0(void) { D_002BF230 = (void (*)(void))func_00283C98; }

extern void *func_00283BC8(void) { if (D_002BF230 == (void (*)(void))func_00283BC8) D_002BF230 = (void (*)(void))func_00283C30; if (!D_002BF234) func_002839A8(); return ((void *(*)(void))D_002BF230)(); }

extern void *func_00283C30(void) { if (!D_424500) { D_424500 = 1; memset(D_424420, 0, 0xE0); FLD(void *, D_424420, 4) = D_424508; } return D_424420; }

extern void *func_00283C98(void) { void *eh = D_424FE0[func_00273090()]; if (!eh) { void *old; eh = func_002838D8(); old = D_424FE0[func_00273090()]; if (old) func_002893A0(old); D_424FE0[func_00273090()] = eh; } return eh; }

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_00283D20);

extern void func_00283E00(void *p) { u8 *eh = ((u8 *(*)(void))func_00283958)(); s32 diff = (u8 *)p - (eh + 0x10); if (diff >= 0 && diff < 0xC0) { s32 mask = FLD(s32, eh, 0xD0); s32 bit = 1 << (diff / 16); do { mask ^= bit; bit <<= 1; } while (mask & bit); FLD(s32, eh, 0xD0) = mask; } else { func_002893A0(p); return; } }

extern s32 func_00283E90(void) { return (s32)(((u8 *(*)(void))D_002BF230)() + 4); }

extern void func_00283EB8(void)
{
    W2EhCtx *eh = ((W2EhCtx *(*)(void))D_002BF230)();
    void ***dhc = &eh->dynamic_handler_chain;
    void *jmpbuf;
    void (*func)(void *, int);
    void *arg;
    void ***cleanup = (void ***)&(*dhc)[1];

    if (cleanup[0]) {
        double store[200];
        void **buf = (void **)store;
        buf[1] = 0;
        buf[0] = (*dhc);

        if (!__builtin_setjmp(&buf[2])) {
            *dhc = buf;
            while (cleanup[0]) {
                func = (void (*)(void *, int))cleanup[0][1];
                arg = (void *)cleanup[0][2];

                cleanup[0] = (void **)cleanup[0][0];

                (*func)(arg, 2);
            }
            *dhc = buf[0];
        } else {
            W2Terminate();
        }
    }

    if (!eh->info || (*dhc)[0] == 0)
        W2Terminate();

    jmpbuf = &(*dhc)[2];

    *dhc = (void **)(*dhc)[0];

    __builtin_longjmp(jmpbuf, 1);
}

extern void func_00284018(void)
{
    W2EhCtx *eh = ((W2EhCtx *(*)(void))D_002BF230)();
    void ***dhc = &eh->dynamic_handler_chain;
    void (*func)(void *, int);
    void *arg;
    void ***cleanup = (void ***)&(*dhc)[1];

    if (cleanup[0]) {
        double store[200];
        void **buf = (void **)store;
        buf[1] = 0;
        buf[0] = (*dhc);

        if (!__builtin_setjmp(&buf[2])) {
            *dhc = buf;
            while (cleanup[0]) {
                func = (void (*)(void *, int))cleanup[0][1];
                arg = (void *)cleanup[0][2];

                cleanup[0] = (void **)cleanup[0][0];

                (*func)(arg, 2);
            }
            *dhc = buf[0];
        } else {
            W2Terminate();
        }
    }

    *dhc = (void **)(*dhc)[0];

    func_00283EB8();
}

extern int func_00284140(void *rtime)
{
    void *info;
    W2Matcher matcher;
    void *ret;

    info = *(void **)func_00283980();
    matcher = ((W2EhInfo *)info)->match_function;
    if (!matcher) {
        return 0;
    }
    ret = (*matcher)(info, rtime, (void *)0);
    return (ret != 0);
}

extern s16 func_00284188(void *p) { return FLD(s16, p, 6); }

extern s16 func_00284190(void *p) { return FLD(s16, p, 4); }

extern void *func_00284198(void *pc, W2ExcTab *table)
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

extern void *func_00284268(void *pc, W2ExcDesc *table, W2EhInfo *eh_info, int rethrow, int *cleanup)
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

extern void func_00284438(s32 reg, void *u, void *t) { void *p = func_002843A8(reg, u, 0); void *q = func_002843A8(reg, t, 0); memcpy(q, p, D_424518[reg]); return; }

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_002844A0);

extern void func_00284550(void) {
}

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_00284558);

extern void func_002848E8(void)
{
    W2EhCtx *eh = ((W2EhCtx *(*)(void))D_002BF230)();
    void *pc, *handler;
    long offset;
    W2FrameStateT my_ustruct, *my_udata = &my_ustruct;

    if (!eh->info)
        W2Terminate();

label:
    my_udata = func_00286968(&&label, my_udata);
    if (!my_udata)
        W2Terminate();

    my_udata->cfa = __builtin_dwarf_cfa();

    __builtin_unwind_init();

    pc = (char *)__builtin_extract_return_addr(__builtin_return_address(0)) - 1;

    handler = func_00284558(eh, pc, my_udata, &offset);

    __builtin_eh_return((void *)eh, offset, handler);
}

extern void func_00284A38(void *index)
{
    W2EhCtx *eh = ((W2EhCtx *(*)(void))D_002BF230)();
    void *pc, *handler;
    long offset;
    W2FrameStateT my_ustruct, *my_udata = &my_ustruct;

    if (!eh->info)
        W2Terminate();

    eh->table_index = index;

label:
    my_udata = func_00286968(&&label, my_udata);
    if (!my_udata)
        W2Terminate();

    my_udata->cfa = __builtin_dwarf_cfa();

    __builtin_unwind_init();

    pc = (char *)__builtin_extract_return_addr(__builtin_return_address(0)) - 1;

    handler = func_00284558(eh, pc, my_udata, &offset);

    __builtin_eh_return((void *)eh, offset, handler);
}

extern double fptodp(f32 a) { W2FpNumS2 in; union { f32 f; u32 i; } au; au.f = a; func_00288040(&au, &in); return func_00285468(in.cls, in.sign, in.exp, (u64)in.frac << 30); }

extern W2FpNum2 *func_00284BD8(W2FpNum2 *a_, W2FpNum2 *b_, W2FpNum2 *tmp_)
{
    W2Fp *a = (W2Fp *)a_;
    W2Fp *b = (W2Fp *)b_;
    W2Fp *tmp = (W2Fp *)tmp_;
    s64 tfraction;

    int a_normal_exp;
    int b_normal_exp;
    u64 a_fraction;
    u64 b_fraction;

    if (w2_isnan(a)) {
        return (W2FpNum2 *)a;
    }
    if (w2_isnan(b)) {
        return (W2FpNum2 *)b;
    }
    if (w2_isinf(a)) {
        if (w2_isinf(b) && a->sign != b->sign)
            return (W2FpNum2 *)&D_002EAB80;
        return (W2FpNum2 *)a;
    }
    if (w2_isinf(b)) {
        return (W2FpNum2 *)b;
    }
    if (w2_iszero(b)) {
        if (w2_iszero(a)) {
            *tmp = *a;
            tmp->sign = a->sign & b->sign;
            return (W2FpNum2 *)tmp;
        }
        return (W2FpNum2 *)a;
    }
    if (w2_iszero(a)) {
        return (W2FpNum2 *)b;
    }

    {
        int diff;

        a_normal_exp = a->exp;
        b_normal_exp = b->exp;
        a_fraction = a->frac;
        b_fraction = b->frac;

        diff = a_normal_exp - b_normal_exp;

        if (diff < 0)
            diff = -diff;
        if (diff < 64) {
            while (a_normal_exp > b_normal_exp) {
                b_normal_exp++;
                W2LSHIFT(b_fraction);
            }
            while (b_normal_exp > a_normal_exp) {
                a_normal_exp++;
                W2LSHIFT(a_fraction);
            }
        } else {
            if (a_normal_exp > b_normal_exp) {
                b_normal_exp = a_normal_exp;
                b_fraction = 0;
            } else {
                a_normal_exp = b_normal_exp;
                a_fraction = 0;
            }
        }
    }

    if (a->sign != b->sign) {
        if (a->sign) {
            tfraction = -a_fraction + b_fraction;
        } else {
            tfraction = a_fraction - b_fraction;
        }
        if (tfraction >= 0) {
            tmp->sign = 0;
            tmp->exp = a_normal_exp;
            tmp->frac = tfraction;
        } else {
            tmp->sign = 1;
            tmp->exp = a_normal_exp;
            tmp->frac = -tfraction;
        }

        while (tmp->frac < (1ULL << 60) && tmp->frac) {
            tmp->frac <<= 1;
            tmp->exp--;
        }
    } else {
        tmp->sign = a->sign;
        tmp->exp = a_normal_exp;
        tmp->frac = a_fraction + b_fraction;
    }
    tmp->cls = W2_NUMBER;

    if (tmp->frac >= (1ULL << 61)) {
        W2LSHIFT(tmp->frac);
        tmp->exp++;
    }
    return (W2FpNum2 *)tmp;
}

extern double func_00284E38(double a, double b) { W2FpNum2 x, y, t; union { double d; u64 l; } au, bu; au.d = a; bu.d = b; func_002881A8(&au, &x); func_002881A8(&bu, &y); return func_002880D0((W2FpNum *)func_00284BD8(&x, &y, &t)); }

extern double func_00284E90(double a, double b) { W2FpNum2 x, y, t; union { double d; u64 l; } au, bu; au.d = a; bu.d = b; func_002881A8(&au, &x); func_002881A8(&bu, &y); y.sign ^= 1; return func_002880D0((W2FpNum *)func_00284BD8(&x, &y, &t)); }

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_00284EF8);

extern double dpdiv(double arg_a, double arg_b)
{
    W2Fp a;
    W2Fp b;
    W2Fp *res;
    union { double d; u64 l; } au, bu;

    au.d = arg_a;
    bu.d = arg_b;

    func_002881A8(&au, (W2FpNum2 *)&a);
    func_002881A8(&bu, (W2FpNum2 *)&b);

    res = w2_fpdiv_parts(&a, &b);

    return func_002880D0((W2FpNum *)res);
}

extern s32 dpcmp(double a, double b) { W2FpNum2 x, y; union { double d; u64 l; } au, bu; au.d = a; bu.d = b; func_002881A8(&au, &x); func_002881A8(&bu, &y); return func_00288268(&x, &y); }

extern double func_00285310(s32 arg) { W2FpL in; in.cls = W2L_NUMBER; in.sign = arg < 0; if (!arg) { in.cls = W2L_ZERO; } else { in.exp = 60; if (in.sign) { if (arg == (-0x7FFFFFFF) - 1) return (double)((-0x7FFFFFFF) - 1); in.frac = -arg; } else in.frac = arg; while (in.frac < (1ULL << 60)) { in.frac <<= 1; in.exp -= 1; } } return func_002880D0((W2FpNum *)&in); }

extern s32 func_002853C8(double arg) { W2Fp a; union { double d; u64 l; } au; s32 tmp; au.d = arg; func_002881A8(&au, (W2FpNum2 *)&a); if (w2_iszero(&a)) return 0; if (w2_isnan(&a)) return 0; if (w2_isinf(&a)) return a.sign ? (-0x7FFFFFFF) - 1 : 0x7FFFFFFF; if (a.exp < 0) return 0; if (a.exp > 30) return a.sign ? (-0x7FFFFFFF) - 1 : 0x7FFFFFFF; tmp = a.frac >> (60 - a.exp); return a.sign ? -tmp : tmp; }

extern double func_00285468(s32 c, u32 s, s32 e, u64 f) { W2FpNum n; n.cls = c; n.sign = s; n.exp = e; n.frac = f; return func_002880D0(&n); }

/* from gcc-2.95.2 config/fp-bit.c (GPL): df_to_sf (__truncdfsf2), double build */
extern f32 dptofp(double arg_a) { W2FpNum2 in; u32 sffrac; func_002881A8(&arg_a, &in); sffrac = in.frac >> 30; if ((in.frac & (((u32)1 << 30) - 1)) != 0) sffrac |= 1; return func_002880A0(in.cls, in.sign, in.exp, sffrac); }

extern u32 func_002854F0(double arg) { W2Fp a; union { double d; u64 l; } au; au.d = arg; func_002881A8(&au, (W2FpNum2 *)&a); if (w2_iszero(&a)) return 0; if (w2_isnan(&a)) return 0; if (a.sign) return 0; if (w2_isinf(&a)) return 0xFFFFFFFF; if (a.exp < 0) return 0; if (a.exp > 31) return 0xFFFFFFFF; if (a.exp > 60) return a.frac << (a.exp - 60); else return a.frac >> (60 - a.exp); }

extern u8 *func_00285590(u8 *buf, u32 *r) { u32 shift = 0; u32 result = 0; while (1) { u32 byte = *buf++; result |= (byte & 0x7f) << shift; if ((byte & 0x80) == 0) break; shift += 7; } *r = result; return buf; }

extern u8 *func_002855D8(u8 *buf, s32 *r) { u32 shift = 0; u32 result = 0; u32 byte; while (1) { byte = *buf++; result |= (byte & 0x7f) << shift; shift += 7; if ((byte & 0x80) == 0) break; } if (shift < 32 && (byte & 0x40) != 0) result |= -(1 << shift); *r = result; return buf; }

void func_00285630(Y1FdeVec *v1, const Y1FdeVec *v2)
{
    u32 i1, i2;
    Y1Fde *fde2;

    i2 = v2->count;
    if (i2 > 0) {
        i1 = v1->count;
        do {
            i2--;
            fde2 = v2->array[i2];
            while (i1 > 0 && y1_fde_compare(v1->array[i1 - 1], fde2) > 0) {
                v1->array[i1 + i2] = v1->array[i1 - 1];
                i1--;
            }
            v1->array[i1 + i2] = fde2;
        } while (i2 > 0);
        v1->count += v2->count;
    }
}

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_00285728);

extern void func_00285CA0(void *begin, void *o) { W2Obj *ob = (W2Obj *)o; ob->fde_begin = begin; ob->pc_begin = ob->pc_end = 0; ob->fde_array = 0; ob->count = 0; func_002731E0(D_002BE1C4); ob->next = (W2Obj *)D_424598; D_424598 = ob; func_002731C0(D_002BE1C4); __asm__(""); }

extern void func_00285D08(void *p) { func_00285CA0(p, func_00289348(0x18)); return; }

extern void func_00285D38(void *begin, void *o) { W2Obj *ob = (W2Obj *)o; ob->fde_begin = begin; ob->fde_array = begin; ob->pc_begin = ob->pc_end = 0; ob->count = 0; func_002731E0(D_002BE1C4); ob->next = (W2Obj *)D_424598; D_424598 = ob; func_002731C0(D_002BE1C4); __asm__(""); }

extern void func_00285DA0(void *p) { func_00285D38(p, func_00289348(0x18)); return; }

extern void *func_00285DD0(void *begin) { W2Obj2 **ob; func_002731E0(D_002BE1C4); ob = (W2Obj2 **)&D_424598; while (*ob) { if ((*ob)->fde_begin == begin) { W2Obj2 *obj = *ob; *ob = (*ob)->next; if (obj->fde_array && obj->fde_array != begin) func_002893A0(obj->fde_array); func_002731C0(D_002BE1C4); return obj; } ob = &(*ob)->next; } func_002731C0(D_002BE1C4); return (void *)func_00288FF8(); }

extern void func_00285E90(void *b) { func_002893A0(func_00285DD0(b)); return; }

extern u32 func_00285EB0(W2Fde *f) { u32 n; for (n = 0; f->length != 0; f = (W2Fde *)((u8 *)f + f->length + 4)) { if (f->cie == 0 || f->pc == 0) continue; ++n; } return n; }

INCLUDE_ASM("asm/nonmatchings/Lib283858", func_00285EF0);
