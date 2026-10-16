#include "common.h"

// libgcc exception.cc (C++, built with -fexceptions: __check_eh_spec and __throw_bad_cast/typeid have
// try/catch regions in .gcc_except_table), split off Lib286B20 by lane lb.

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))
extern "C" int func_00283980(void);
extern "C" void *D_002BF244;
extern "C" void func_00287920(void) __attribute__((noreturn));
struct W2EhInfo { u8 pad[0x14]; s32 caught; W2EhInfo *next; };
extern "C" void *func_00287EB8(void);
extern "C" void *func_00283D20(u32);
extern "C" s32 func_002883B0(void *, void *, void *, void *);
typedef void *(*Y1match_fn)(void *, void *, void *);
struct Y1eh_info { Y1match_fn match_function; short language; short version; };
typedef void (*Y1cleanup_fn)(void *);
struct Y1cp_eh_info { Y1eh_info eh_info; void *value; void *type; Y1cleanup_fn cleanup; bool caught; Y1cp_eh_info *next; long handlers; void *original_value; };
extern "C" Y1cp_eh_info **Y1GetEhInfo(void) asm("func_00283980");
extern "C" int func_002888E8(void *);
extern "C" void func_00283E00(void *);
// @decl-end

typedef void (*W2NoRet)(void) __attribute__((noreturn));
extern "C" W2NoRet D_002BF22C;
// splat merged three functions here: __terminate, __default_unexpected, set_terminate
extern "C" void func_00287920(void) { D_002BF22C(); }
extern "C" void func_00287938(void) { func_00287920(); }
extern "C" W2NoRet func_00287948(W2NoRet f) { W2NoRet o = D_002BF22C; D_002BF22C = f; return o; }

extern "C" void *func_00287960(void *p) { void *o = D_002BF244; D_002BF244 = p; return o; }

// splat merged two functions here: __unexpected, __cp_exception_info
extern "C" void func_00287978(void) { ((W2NoRet)D_002BF244)(); }
extern "C" void *func_00287990(void) { return *(u8 **)func_00283980() + 8; }

extern "C" s32 func_002879B8(void) { return *(s32 *)func_00283980(); }

extern "C" void *func_002879D8(void) { u8 *p = *(u8 **)func_00283980(); FLD(s32, p, 0x14) = 1; FLD(s64, p, 0x20) = FLD(s64, p, 0x20) + 1; return p; }

extern "C" void *func_00287A10(void *info, void *match, void *tbl) { if (tbl && FLD(s16, tbl, 4) != 4) return 0; if (match == (void *)-1) return (void *)1; match = ((void *(*)(void))match)(); return (void *)(func_002883B0(match, FLD(void *, info, 0xC), FLD(void *, info, 0x28), (u8 *)info + 8) != 0); }

extern "C" void func_00287A70(void *value, void *type, Y1cleanup_fn cleanup)
{
  Y1cp_eh_info *p = (Y1cp_eh_info *) func_00283D20 (sizeof (Y1cp_eh_info));

  p->value = value;
  p->type = type;
  p->cleanup = cleanup;
  p->handlers = 0;
  p->caught = false;
  p->original_value = value;

  p->eh_info.match_function = (Y1match_fn)func_00287A10;
  p->eh_info.language = 4;
  p->eh_info.version = 1;

  Y1cp_eh_info **q = Y1GetEhInfo ();

  p->next = *q;
  *q = p;
}

extern "C" void func_00287B00(Y1cp_eh_info *p)
{
  Y1cp_eh_info **stack = Y1GetEhInfo ();
  Y1cp_eh_info **q = stack;

  --p->handlers;

  if (p == *q && !p->caught)
    return;

  if (p->handlers != 0)
    {
      if (p == *q && p->next && !p->next->caught)
	{
	  q = &p->next;
	  while (*q && !(*q)->caught)
	    q = &(*q)->next;
	  *stack = p->next;
	  p->next = *q;
	  *q = p;
	}
      return;
    }

  for (; *q; q = &((*q)->next))
    if (*q == p)
      break;

  if (! *q)
    func_00287920 ();

  *q = p->next;

  if (p->cleanup)
    ((void (*)(void *, int))p->cleanup) (p->original_value, 2);

  if (! func_002888E8 (p->type))
    func_00283E00 (p->original_value);

  func_00283E00 (p);
}

extern "C" void func_00287C28(void) { W2EhInfo **stack = (W2EhInfo **)func_00283980(); W2EhInfo **q = stack; W2EhInfo *p; for (;;) { p = *q; if (p == 0) func_00287920(); if (p->caught) break; q = &p->next; } if (q != stack) { *q = p->next; p->next = *stack; *stack = p; } p->caught = 0; }

INCLUDE_ASM("asm/nonmatchings/Lib287920", func_00287C88);

INCLUDE_ASM("asm/nonmatchings/Lib287920", func_00287E50);

INCLUDE_ASM("asm/nonmatchings/Lib287920", func_00287EB8);

extern "C" const char *func_00287F58(void *self) { void *t; if (self) t = ((void *(*)(void))FLD(void *, *(void **)self, 4))(); else t = func_00287EB8(); return *(const char **)t; }
