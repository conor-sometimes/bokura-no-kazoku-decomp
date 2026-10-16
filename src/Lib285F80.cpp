#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
typedef struct W2Fde2 W2Fde2;
typedef struct W2Upcast W2Upcast;
typedef struct W2UR W2UR;
typedef struct W2CieInfo W2CieInfo;
typedef struct W2DwState W2DwState;
typedef struct W2FdeF W2FdeF;
typedef struct W2ObjF W2ObjF;
#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern int func_00283980(void);
extern int strcmp(const char *, const char *);
extern void *D_002BF244;

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern s32 strcmp(const char *, const char *);

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
struct W2Fde2 { u32 length; s32 cie; u32 pc_begin; u32 pc_range; };
struct W2Upcast { void *obj; s32 access; void *base; };
extern s32 func_00286B58(const char **, const char **);
extern void func_00287920(void) __attribute__((noreturn));

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern void *func_00287EB8(void);

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern void *func_00283D20(u32);
extern void *func_00287A10(void *, void *, void *);
extern u8 W2vt_si[] asm("_vt$14__si_type_info");
extern u8 W2vt_user[] asm("_vt$16__user_type_info");

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern u8 W2vt_class2[] asm("_vt$17__class_type_info");

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern u8 W2vt_ti2[] asm("_vt$9type_info");
extern u8 W2vt_bi[] asm("_vt$19__builtin_type_info");
extern u8 D_002BF248[];
extern const char D_002EAD08[];

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern s32 func_002883B0(void *, void *, void *, void *);

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
struct W2UR { void *obj; s32 access; void *base; };

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))

struct W2CieInfo { char *augmentation; void *eh_ptr; int code_align; int data_align; unsigned ra_regno; };
union W2Unaligned { void *p; unsigned b2 __attribute__ ((mode (HI))); unsigned b4 __attribute__ ((mode (SI))); } __attribute__((packed));
extern u32 strlen(const char *);
extern u8 *func_00285590(u8 *, void *);
extern u8 *func_002855D8(u8 *, void *);
extern const char D_002EABA0[];
extern const char D_002EABA8[];
static inline void *w2_read_pointer(void *p) { union W2Unaligned *up = (union W2Unaligned *)p; return up->p; }
static inline unsigned w2_read_1byte(void *p) { return *(unsigned char *)p; }
static inline unsigned w2_read_2byte(void *p) { union W2Unaligned *up = (union W2Unaligned *)p; return up->b2; }
static inline unsigned w2_read_4byte(void *p) { union W2Unaligned *up = (union W2Unaligned *)p; return up->b4; }

struct W2DwState { u8 p0[8]; s64 m8; s64 m10; u8 p18[0x3F8 - 0x18]; u16 m3F8; u8 p3FA[0x477 - 0x3FA]; u8 m477; };
extern void func_00288FF8(void) __attribute__((noreturn));

struct W2FdeF { u32 length; s32 CIE_delta; void *pc_begin; u32 pc_range; };
struct W2ObjF { void *pc_begin; void *pc_end; W2FdeF *fde_begin; W2FdeF **fde_array; u32 count; W2ObjF *next; };
extern W2ObjF *D_424598;
extern int D_002BE1C4;
extern s32 func_002731E0(s32);
extern s32 func_002731C0(s32);
extern void func_00285FD8(W2ObjF *);
extern W2FdeF *W2SearchFdes(W2FdeF *, void *) asm("func_00285F80");

typedef struct Y1fde_vector { W2FdeF **array; unsigned int count; } Y1fde_vector;
typedef struct Y1fde_accumulator { Y1fde_vector linear; Y1fde_vector erratic; } Y1fde_accumulator;
extern W2FdeF **Y1end_fde_sort(Y1fde_accumulator *, unsigned int) asm("func_00285728");
extern unsigned int Y1count_fdes(W2FdeF *) asm("func_00285EB0");
extern void Y1add_fdes(W2FdeF *, Y1fde_accumulator *, void **, void **) asm("func_00285EF0");
extern void *Y1malloc(unsigned int) asm("func_00289348");
static inline int
Y1start_fde_sort (Y1fde_accumulator *accu, unsigned int count)
{
  accu->linear.array = count ? (W2FdeF **) Y1malloc (sizeof (W2FdeF *) * count) : 0;
  accu->erratic.array = accu->linear.array ?
      (W2FdeF **) Y1malloc (sizeof (W2FdeF *) * count) : 0;
  accu->linear.count = 0;
  accu->erratic.count = 0;
  return accu->linear.array != 0;
}
typedef struct W2FrameState W2FrameState;
typedef struct W2FrameStateInt W2FrameStateInt;
struct W2FrameState { void *cfa; void *eh_ptr; u8 p8[0x3FA - 8]; u16 retaddr_column; u8 p3FC[0x478 - 0x3FC]; } __attribute__((aligned(8)));
struct W2FrameStateInt { W2FrameState s; void *saved_state; u32 pad; };
extern u8 *func_00286518(u8 *, W2FrameStateInt *, W2CieInfo *, void **);
extern void *memset(void *, int, unsigned int);
typedef struct W2FS W2FS;
struct W2FS {
    void *cfa;                // 0x0
    void *eh_ptr;             // 0x4
    long cfa_offset;          // 0x8
    long cfa_exp;             // 0x10
    long args_size;           // 0x18
    long reg_or_offset[123];  // 0x20
    unsigned short cfa_reg;   // 0x3F8
    unsigned short retaddr_column; // 0x3FA
    char saved[123];          // 0x3FC
    char cfa_how;             // 0x477
    W2FS *saved_state;        // 0x478
};
extern void *func_00289348(unsigned int n);       /* malloc */
extern void func_002893A0(void *p);               /* free */
extern void *memcpy(void *, const void *, unsigned int);
u8 *Y1execute_cfa_insn(u8 *p, W2FS *state, W2CieInfo *info, void **pc) asm("func_00286518");
// @decl-end

extern W2Fde2 *func_00285F80(W2Fde2 *f, u32 pc) { for (; f->length != 0; f = (W2Fde2 *)((u8 *)f + f->length + 4)) { if (f->cie == 0) continue; if (f->pc_begin == 0) continue; if (pc - f->pc_begin < f->pc_range) return f; } return 0; }

void func_00285FD8(W2ObjF *ob)
{
  Y1fde_accumulator accu;
  unsigned int count;

  if (ob->pc_begin)
    count = ob->count;
  else
    {
      if (ob->fde_array)
	{
	  W2FdeF **p = ob->fde_array;
	  for (count = 0; *p; ++p)
	    count += Y1count_fdes (*p);
	}
      else
	count = Y1count_fdes (ob->fde_begin);
    }
  ob->count = count;

  if (!Y1start_fde_sort (&accu, count) && ob->pc_begin)
    return;

  {
    W2FdeF **array;
    void *pc_begin = (void *)-1;
    void *pc_end = 0;

    if (ob->fde_array)
      {
	W2FdeF **p = ob->fde_array;
	for (; *p; ++p)
	  Y1add_fdes (*p, &accu, &pc_begin, &pc_end);
      }
    else
      Y1add_fdes (ob->fde_begin, &accu, &pc_begin, &pc_end);

    array = Y1end_fde_sort (&accu, count);
    if (array)
      ob->fde_array = array;
    ob->pc_begin = pc_begin;
    ob->pc_end = pc_end;
  }
}

extern W2FdeF *func_00286140(void *pc)
{
    W2ObjF *ob;
    u32 lo, hi;

    func_002731E0(D_002BE1C4);

    for (ob = D_424598; ob; ob = ob->next) {
        if (ob->pc_begin == 0)
            func_00285FD8(ob);
        if (pc >= ob->pc_begin && pc < ob->pc_end)
            break;
    }

    if (ob == 0) {
        func_002731C0(D_002BE1C4);
        return 0;
    }

    if (!ob->fde_array || (void *)ob->fde_array == (void *)ob->fde_begin)
        func_00285FD8(ob);

    if (ob->fde_array && (void *)ob->fde_array != (void *)ob->fde_begin) {
        func_002731C0(D_002BE1C4);

        for (lo = 0, hi = ob->count; lo < hi;) {
            u32 i = (lo + hi) / 2;
            W2FdeF *f = ob->fde_array[i];

            if (pc < f->pc_begin)
                hi = i;
            else if (pc >= (char *)f->pc_begin + f->pc_range)
                lo = i + 1;
            else
                return f;
        }
    } else {
        W2FdeF *f;
        if (ob->fde_array) {
            W2FdeF **p = ob->fde_array;
            do {
                f = W2SearchFdes(*p, pc);
                if (f)
                    break;
                p++;
            } while (*p);
        } else
            f = W2SearchFdes(ob->fde_begin, pc);
        func_002731C0(D_002BE1C4);
        return f;
    }
    return 0;
}

extern u8 *func_002862E8(W2Fde2 *f, W2CieInfo *c)
{
    u8 *p;
    int i;

    c->augmentation = (char *)&f->cie - f->cie + 9;

    if (strcmp(c->augmentation, D_002EABA0) != 0
        && strcmp(c->augmentation, D_002EABA8) != 0
        && c->augmentation[0] != 'z')
        return 0;

    p = (u8 *)c->augmentation + strlen(c->augmentation) + 1;

    if (strcmp(c->augmentation, D_002EABA8) == 0) {
        c->eh_ptr = w2_read_pointer(p);
        p += sizeof(void *);
    } else
        c->eh_ptr = 0;

    p = func_00285590(p, &c->code_align);
    p = func_002855D8(p, &c->data_align);
    c->ra_regno = *(unsigned char *)p++;

    if (c->augmentation[0] == 'z') {
        p = func_00285590(p, &i);
        p += i;
    }

    return p;
}

extern u8 *func_002863F8(u8 *p, W2DwState *s)
{
    unsigned int op = *p++;
    int tmp;
    switch (op) {
    case 0x50 ... 0x6F:
        s->m3F8 = op - 0x50;
        break;
    case 0x90:
        p = func_002855D8(p, &tmp);
        s->m3F8 = tmp;
    case 0x70 ... 0x8F:
        s->m3F8 = op - 0x70;
        p = func_002855D8(p, &tmp);
        s->m10 = tmp;
        break;
    case 0x92:
        p = func_002855D8(p, &tmp);
        s->m3F8 = tmp;
        p = func_002855D8(p, &tmp);
        s->m10 = tmp;
        break;
    case 0x06:
        s->m477 = 1;
        break;
    case 0x23:
        p = func_00285590(p, &tmp);
        s->m8 = tmp;
        break;
    default:
        func_00288FF8();
    }
    return p;
}

INCLUDE_RODATA("asm/nonmatchings/Lib285F80", D_002EABA0);
INCLUDE_RODATA("asm/nonmatchings/Lib285F80", D_002EABA8);
asm(".p2align 3");
u8 *Y1execute_cfa_insn(u8 *p, W2FS *state, W2CieInfo *info, void **pc)
{
    unsigned insn = *p++;
    int offset;
    unsigned reg;

    if (insn & 0x40)
        *(char **)pc += ((insn & 0x3f) * info->code_align);
    else if (insn & 0x80) {
        reg = (insn & 0x3f);
        p = func_00285590(p, &offset);
        if (reg == state->cfa_reg)
            ;
        else {
            offset *= info->data_align;
            state->saved[reg] = 1;
            state->reg_or_offset[reg] = offset;
        }
    } else if (insn & 0xc0) {
        reg = (insn & 0x3f);
        state->saved[reg] = 0;
    } else switch (insn) {
    case 1:
        *pc = w2_read_pointer(p);
        p += sizeof(void *);
        break;
    case 2:
        *(char **)pc += w2_read_1byte(p);
        p += 1;
        break;
    case 3:
        *(char **)pc += w2_read_2byte(p);
        p += 2;
        break;
    case 4:
        *(char **)pc += w2_read_4byte(p);
        p += 4;
        break;
    case 5:
        p = func_00285590(p, &reg);
        p = func_00285590(p, &offset);
        if (reg == state->cfa_reg)
            ;
        else {
            offset *= info->data_align;
            state->saved[reg] = 1;
            state->reg_or_offset[reg] = offset;
        }
        break;
    case 6:
        p = func_00285590(p, &reg);
        state->saved[reg] = 0;
        break;
    case 0:
    case 7:
    case 8:
        break;
    case 9: {
        unsigned reg2;
        p = func_00285590(p, &reg);
        p = func_00285590(p, &reg2);
        state->saved[reg] = 2;
        state->reg_or_offset[reg] = reg2;
        break;
    }
    case 0xc:
        p = func_00285590(p, &reg);
        p = func_00285590(p, &offset);
        state->cfa_reg = reg;
        state->cfa_offset = offset;
        break;
    case 0xd:
        p = func_00285590(p, &reg);
        state->cfa_reg = reg;
        break;
    case 0xe:
        p = func_00285590(p, &offset);
        state->cfa_offset = offset;
        break;
    case 0xf: {
        u8 *end;
        state->cfa_reg = 0;
        state->cfa_offset = 0;
        state->cfa_exp = 0;
        state->cfa_how = 0;
        p = func_00285590(p, &offset);
        end = p + offset;
        while (p < end)
            p = func_002863F8(p, (W2DwState *)state);
        return p;
    }
    case 0xa: {
        W2FS *save = (W2FS *)func_00289348(sizeof(W2FS));
        memcpy(save, state, sizeof(W2FS));
        state->saved_state = save;
        break;
    }
    case 0xb: {
        W2FS *save = state->saved_state;
        memcpy(state, save, sizeof(W2FS));
        func_002893A0(save);
        break;
    }
    case 0x2d:
        for (reg = 16; reg < 32; ++reg) {
            state->saved[reg] = 1;
            state->reg_or_offset[reg] = (reg - 16) * sizeof(void *);
        }
        break;
    case 0x2e:
        p = func_00285590(p, &offset);
        state->args_size = offset;
        break;
    case 0x2f:
        p = func_00285590(p, &reg);
        p = func_00285590(p, &offset);
        offset *= info->data_align;
        state->saved[reg] = 1;
        state->reg_or_offset[reg] = -offset;
        break;
    default:
        func_00288FF8();
    }
    return p;
}

extern W2FrameState *func_00286968(void *pc_target, W2FrameState *state_in)
{
    W2CieInfo info;
    W2FrameStateInt state;
    W2FdeF *f;
    u8 *insn, *end;
    int i;
    void *pc;

    f = func_00286140(pc_target);
    if (f == 0)
        return 0;

    insn = func_002862E8((W2Fde2 *)f, &info);
    if (insn == 0)
        return 0;

    memset(&state, 0, sizeof(state));
    state.s.retaddr_column = info.ra_regno;
    state.s.eh_ptr = info.eh_ptr;

    {
        W2FdeF *cie = (W2FdeF *)((char *)&f->CIE_delta - f->CIE_delta);
        end = (u8 *)cie + cie->length + sizeof(cie->length);
    }
    while (insn < end)
        insn = func_00286518(insn, &state, &info, 0);

    insn = (u8 *)(f + 1);

    if (info.augmentation[0] == 'z') {
        insn = func_00285590(insn, &i);
        insn += i;
    }

    end = (u8 *)f + f->length + sizeof(f->length);
    pc = f->pc_begin;
    while (insn < end && pc <= pc_target)
        insn = func_00286518(insn, &state, &info, &pc);

    *state_in = state.s;
    return state_in;
}
