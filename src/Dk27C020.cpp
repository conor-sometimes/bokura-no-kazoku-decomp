#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
//@sym __floatdisf 0x2833A8
//@sym __fixunssfdi 0x2835A8
#define SYSCALL(name, n) int name() { asm volatile("addiu $3,$0," #n "\n\tsyscall"); }
typedef struct Pair { int a, b; } Pair;
typedef struct AlarmEnt { struct AlarmEnt *next; struct AlarmEnt *prev; int seq; int flags; unsigned long long start; unsigned long long elapsed; unsigned long long target; void *handler; void *gp; void *arg; int x34, x38, x3C; } AlarmEnt;
typedef struct AlarmSys { unsigned long long counter; int id; int seq; int used; AlarmEnt *free; AlarmEnt *head; int cur; } AlarmSys;
extern AlarmSys D_002BF138;
extern AlarmEnt *D_002BF150;
extern AlarmEnt D_421B00[128];
extern int D_002BF140;
extern Pair D_002BE970[3];
extern Pair D_002BF0F8[8];
extern char D_002BE1C8[];
extern char D_002BE990[];
extern char D_002BF0D0[];
extern Pair D_002BE988;
extern char *D_002BDED0;
extern const char D_002EA110[];
extern int func_0027C020();
extern int func_0027C030();
extern int func_0027C078();
extern int func_0027C1A0();
extern int func_0027C1E0();
extern int func_0027C440();
extern int func_0027C450();
extern int func_0027C498();
extern void func_00273420(int);
extern void func_00273240(unsigned int *);
extern void func_00273250(unsigned int *);
extern int func_0027B758(void);
extern char *func_0027C1F0(const char *, int, char **);
extern int func_00272DF0(int, int, int, char *);
extern void func_00272DE0(char *, int, char *);
extern void func_00272DC0(int);
extern void func_002735C0(int, char *);
extern void func_0027C580(unsigned int, int);
extern int func_0027BD20(void);
extern int func_0027BD78(void);
extern void *memset(void *, int, unsigned int);
extern unsigned int strlen(const char *);
extern int func_0027D8E8(void);
extern void func_0027CBC0(void);
extern int func_00272E90(int, void *, int, int);
extern int func_00272EA0(int, int);
extern void func_00273A68(int);
extern void func_00273A00(int);
extern void func_0027C5F0(int);
extern void func_0027C600(int);
extern void func_0027C610(int);
extern unsigned long long func_0027CE60(void);
extern int func_0027C970(unsigned long long);
extern int func_0027CF30(void);
extern int func_0027CFE8(int);
extern int func_0027D0D8(int *, int *);
extern AlarmEnt *func_0027CB88(AlarmEnt *);
extern void func_0027CB00(AlarmEnt *);
extern unsigned long long func_002828C0(unsigned long long, unsigned long long);
extern int func_0027D5C8(int, unsigned long long, void *, void *);
#define ENT(id) ((AlarmEnt *)(((unsigned int)(id) >> 10) << 6))

int func_0027D188(int);
int func_0027D288(int);
unsigned long long func_0027D470(int);
unsigned long long func_0027D508(int);

typedef struct FreeEnt { struct FreeEnt *next; int p[3]; } FreeEnt;
extern FreeEnt D_423B00[64];
extern FreeEnt *D_423F00;

int func_0027D938();
static __inline__ FreeEnt *W2AllocEnt(void) { FreeEnt *e = D_423F00; if (e) D_423F00 = e->next; return e; }

int func_0027D938();
#define DL_GETTIME(t) asm volatile( \
    ".set noreorder\n\t" \
    "lui $3, 0x1000\n\t" \
    "lui $4, %%hi(D_002BF138)\n\t" \
    "ori $3, $3, 0x1000\n\t" \
    "lwu %0, 0x0($3)\n\t" \
    "lw $8, 0x10($3)\n\t" \
    "ld $10, %%lo(D_002BF138)($4)\n\t" \
    "andi $9, $8, 0x800\n\t" \
    "beqz $9, 1f\n\t" \
    "addiu $9, $0, 0x2\n\t" \
    "lwu %0, 0x0($3)\n\t" \
    "daddiu $10, $10, 0x1\n" \
    "1:\n\t" \
    "andi $8, $8, 0x3\n\t" \
    "dsll $10, $10, 16\n\t" \
    "movz $9, $0, $8\n\t" \
    "or %0, %0, $10\n\t" \
    "dsllv $9, $9, $8\n\t" \
    "dsllv %0, %0, $9\n\t" \
    ".set reorder" \
    : "=&r"(t) : : "$3", "$4", "$8", "$9", "$10")
// @decl-end
INCLUDE_RODATA("asm/nonmatchings/Dk27C020", D_002EA110);

SYSCALL(func_0027C020, 0x74)

SYSCALL(func_0027C030, 0x5A)

int func_0027C040(unsigned int *dst, unsigned int *src, unsigned int n)
{
    unsigned int i;
    n >>= 2;
    for (i = 0; i < n; i++) *dst++ = *src++;
    return 0;
}

SYSCALL(func_0027C078, 0x5B)

int func_0027C088(void)
{
    unsigned int old, v;
    func_00273250(&old);
    v = (old & 0xFFFF1FFF) | 0x2000;
    func_00273240(&v);
    func_00273250(&v);
    func_00273240(&old);
    return ((v >> 13) & 7) == 0;
}

void func_0027C0F0(void) { unsigned int i; if (func_0027C088()) { func_0027C020(D_002BE970[0].a, D_002BE970[0].b); func_0027C030(0x80074000, D_002BE1C8, 0x7A8); func_00273420(0); func_00273420(2); func_0027C020(D_002BE970[1].a, D_002BE970[1].b); for (i = 2; i < 3; i++) ((void (*)(int, int))func_0027C020)(D_002BE970[i].a, func_0027C078(D_002BE970[i].a)); } }

SYSCALL(func_0027C1A0, 0x5A)

int func_0027C1B0(unsigned char *dst, unsigned char *src, unsigned int n)
{
    unsigned int i;
    for (i = 0; i < n; i++) *dst++ = *src++;
    return 0;
}

SYSCALL(func_0027C1E0, 0x74)

char *func_0027C1F0(const char *name, int argc, char **argv)
{
    char *p = D_002BDED0;
    char *s = p + 0x40;
    char *ret = s;
    int len, i;
    func_0027C1E0(D_002BE988.a, D_002BE988.b);
    if (argc >= 16) argc = 15;
    func_0027C1A0(p, &s, 4);
    p += 4;
    len = strlen(name) + 1;
    func_0027C1A0(s, name, len);
    s += len;
    for (i = 0; i < argc; i++) {
        func_0027C1A0(p, &s, 4);
        p += 4;
        len = strlen(argv[i]) + 1;
        func_0027C1A0(s, argv[i], len);
        s += len;
    }
    return ret;
}

void func_0027C308(void) { func_0027B758(); }

int func_0027C310(int a, int b, int c, char **d)
{
    func_0027C1F0(D_002EA110, c, d);
    func_0027C308();
    return func_00272DF0(a, b, c, D_002BDED0 + 4);
}

void func_0027C380(const char *a, int b, char **c)
{
    char *s = func_0027C1F0(a, b, c);
    func_0027C308();
    func_00272DE0(s, b, D_002BDED0 + 4);
}

void func_0027C3C8(int a)
{
    func_0027C308();
    func_00272DC0(a);
}

void func_0027C3F0(int a, char **b)
{
    func_0027C1F0(D_002EA110, a, b);
    func_0027C308();
    func_002735C0(a, D_002BDED0 + 4);
}

SYSCALL(func_0027C440, 0x74)

SYSCALL(func_0027C450, 0x5A)

int func_0027C460(unsigned int *dst, unsigned int *src, unsigned int n)
{
    unsigned int i;
    n >>= 2;
    for (i = 0; i < n; i++) *dst++ = *src++;
    return 0;
}

SYSCALL(func_0027C498, 0x5B)

void func_0027C4A8(void) { unsigned int i; if (!(*(volatile unsigned int *)0x10001810 & 0x100)) { func_0027C440(D_002BF0F8[0].a, D_002BF0F8[0].b); func_0027C450(0x80076000, D_002BE990, 0x740); func_0027C450(0x82000, D_002BF0D0, 0x28); func_00273420(0); func_00273420(2); func_0027C440(D_002BF0F8[1].a, D_002BF0F8[1].b); for (i = 2; i < 8; i++) ((void (*)(int, int))func_0027C440)(D_002BF0F8[i].a, func_0027C498(D_002BF0F8[i].a)); } }

INCLUDE_ASM("asm/nonmatchings/Dk27C020", func_0027C580);

void func_0027C5F0(int v) { func_0027C580(0xB0001000, v); }

void func_0027C600(int v) { func_0027C580(0xB0001010, v); }

void func_0027C610(int v) { func_0027C580(0xB0001020, v); }

int func_0027C620(int mode)
{
    int i, id, st;
    unsigned int v;
    if (D_002BF138.id >= 0) return 0x80008001;
    D_002BF138.counter = 0;
    D_002BF138.used = 0;
    memset(D_421B00, 0, sizeof(D_421B00));
    D_002BF138.free = D_421B00;
    for (i = 127; i >= 0; i--) D_421B00[i].next = &D_421B00[i + 1];
    D_421B00[127].next = 0;
    func_0027D8E8();
    id = func_00272E90(0xB, (void *)func_0027CBC0, 0, 0);
    if (id < 0) return 0x80009021;
    D_002BF138.id = id;
    st = func_0027BD20();
    v = *(volatile unsigned int *)0x10001010;
    v = (v & ~3) | mode;
    v |= 0x300;
    if (!(v & 0x80)) {
        func_0027C5F0(0);
        v |= 0xC80;
        func_0027C610(0xFFFF);
    }
    func_0027C600(v);
    func_00273A68(0xB);
    if (st) func_0027BD78();
    return 0;
}

int func_0027C778(void)
{
    volatile AlarmSys *s = &D_002BF138;
    int st;
    if (s->id < 0) return 0x80008001;
    if (s->used != 0) return 0x80000010;
    st = func_0027BD20();
    if (!func_00272EA0(0xB, s->id)) { func_00273A00(0xB); func_0027C600(0xC00); func_0027C5F0(0); }
    D_002BF138.counter = 0;
    D_002BF138.id = -1;
    if (st) func_0027BD78();
    return 0;
}

int func_0027C830(void)
{
    if (D_002BF140 < 0) return 0x80008001;
    return *(volatile unsigned int *)0x10001010 & 3;
}

int func_0027C860(void)
{
    int st = func_0027BD20();
    unsigned int v = *(volatile unsigned int *)0x10001010;
    if (v & 0x80) {
        if (st) func_0027BD78();
        return 1;
    }
    func_0027C600((v & 0xFFFFF3FF) | 0x80);
    func_0027C970(func_0027CE60());
    if (st) func_0027BD78();
    return 0;
}

int func_0027C8F0(void)
{
    int st = func_0027BD20();
    unsigned int v = *(volatile unsigned int *)0x10001010;
    if (!(v & 0x80)) {
        if (st) func_0027BD78();
        return 0;
    }
    func_0027C600(v & 0xFFFFF37F);
    if (st) func_0027BD78();
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/Dk27C020", func_0027C970);

void func_0027CB00(AlarmEnt *e)
{
    AlarmEnt *p = 0;
    AlarmEnt *q = D_002BF138.head;
    unsigned long long t = e->target + e->start - e->elapsed;
    while (q != 0 && !(t < q->target + q->start - q->elapsed)) {
        p = q;
        q = p->next;
    }
    e->prev = p;
    e->next = q;
    if (q) q->prev = e;
    if (p) p->next = e;
    else D_002BF138.head = e;
}

AlarmEnt *func_0027CB88(AlarmEnt *p)
{
    AlarmEnt *next = p->next;
    if (p->prev) p->prev->next = next;
    else D_002BF150 = next;
    if (next) next->prev = p->prev;
    p->prev = 0;
    return next;
}

INCLUDE_ASM("asm/nonmatchings/Dk27C020", func_0027CBC0);

unsigned long long func_0027CE60(void)
{
    unsigned long long t;
    DL_GETTIME(t);
    return t;
}

unsigned long long func_0027CEB0(void)
{
    unsigned long long t;
    int intr = func_0027BD20();
    DL_GETTIME(t);
    if (intr) func_0027BD78();
    return t;
}

INCLUDE_ASM("asm/nonmatchings/Dk27C020", func_0027CF30);

int func_0027CFA0(void)
{
    int st = func_0027BD20();
    int r = func_0027CF30();
    if (st) func_0027BD78();
    return r;
}

int func_0027CFE8(int id)
{
    AlarmEnt *a = (AlarmEnt *)(((unsigned int)id >> 10) << 6);
    if (id < 0 || (id & 0x3FF) != a->seq) return 0x80008002;
    if (D_002BF138.cur == id) return 0x80000010;
    if (a->flags & 2) func_0027CB88(a);
    ((volatile AlarmEnt *)a)->seq = 0;
    a->flags = 0;
    a->next = D_002BF138.free;
    D_002BF138.free = a;
    D_002BF138.used--;
    return 0;
}

int func_0027D088(int a)
{
    int st = func_0027BD20();
    int r = func_0027CFE8(a);
    if (st) func_0027BD78();
    return r;
}

int func_0027D0D8(int *a, int *b)
{
    volatile AlarmSys *s = &D_002BF138;
    if (s->id < 0) return 0x80008001;
    if (a) *a = s->used;
    if (b) *b = 0x80 - s->used;
    return 0;
}

int func_0027D128(int *a, int *b)
{
    int st = func_0027BD20();
    int r = func_0027D0D8(a, b);
    if (st) func_0027BD78();
    return r;
}

int func_0027D188(int id)
{
    AlarmEnt *a = (AlarmEnt *)(((unsigned int)id >> 10) << 6);
    unsigned long long t;
    if (id < 0 || (id & 0x3FF) != a->seq) return 0x80008002;
    if (((volatile AlarmSys *)&D_002BF138)->cur == id) return 0x80000010;
    if (a->flags & 1) return 1;
    t = func_0027CE60();
    a->start = t;
    { unsigned int f = a->flags | 1; a->flags = f; if (f & 2) {
        func_0027CB00(a);
        func_0027C970(t);
    } }
    return 0;
}

int func_0027D238(int a) { int s = func_0027BD20(); int r = func_0027D188(a); if (s) func_0027BD78(); return r; }

int func_0027D288(int id)
{
    AlarmEnt *e = ENT(id);
    unsigned long long now;
    unsigned int f;
    if (id < 0 || (id & 0x3FF) != e->seq) return 0x80008002;
    if (((volatile AlarmSys *)&D_002BF138)->cur == id) return 0x80000010;
    if (!(e->flags & 1)) return 0;
    now = func_0027CE60();
    f = e->flags;
    e->elapsed += now - e->start;
    e->flags = f & ~1;
    if (f & 2) {
        func_0027CB88(e);
        func_0027C970(now);
    }
    return 1;
}

int func_0027D350(int a) { int s = func_0027BD20(); int r = func_0027D288(a); if (s) func_0027BD78(); return r; }

unsigned long long func_0027D3A0(int id, unsigned long long t)
{
    AlarmEnt *e = ENT(id);
    unsigned long long old, now;
    int intr = func_0027BD20();
    if (id < 0 || (id & 0x3FF) != e->seq || ((volatile AlarmSys *)&D_002BF138)->cur == id) {
        if (intr) func_0027BD78();
        return -1;
    }
    old = e->elapsed;
    if (e->flags & 1) {
        now = func_0027CE60();
        { unsigned long long st = e->start; e->elapsed = t; e->start = now; old += now - st; }
    } else {
        e->elapsed = t;
    }
    if (intr) func_0027BD78();
    return old;
}

unsigned long long func_0027D470(int id) { AlarmEnt *a = (AlarmEnt *)(((unsigned int)id >> 10) << 6); if (id < 0 || (id & 0x3FF) != a->seq) return -1; if (a->flags & 1) return a->start - a->elapsed; return 0; }

int func_0027D4B8(int a) { int s = func_0027BD20(); int r = ((int (*)(int))func_0027D470)(a); if (s) func_0027BD78(); return r; }

unsigned long long func_0027D508(int id) { AlarmEnt *a = (AlarmEnt *)(((unsigned int)id >> 10) << 6); unsigned long long r; if (id < 0 || (id & 0x3FF) != a->seq) return -1; r = a->elapsed; if (a->flags & 1) r += func_0027CE60() - a->start; return r; }

int func_0027D578(int a) { int s = func_0027BD20(); int r = ((int (*)(int))func_0027D508)(a); if (s) func_0027BD78(); return r; }

int func_0027D5C8(int id, unsigned long long target, void *handler, void *arg)
{
    AlarmEnt *e = ENT(id);
    if (id < 0 || (id & 0x3FF) != e->seq) return 0x80008002;
    if (((volatile AlarmSys *)&D_002BF138)->cur == id) return 0x80000010;
    if (e->flags & 2) func_0027CB88(e);
    e->handler = handler;
    if (!handler) {
        e->flags &= ~2U;
    } else {
        register void *gp asm("$28");
        e->target = target;
        e->flags |= 2;
        e->gp = gp;
        e->arg = arg;
        if (((volatile AlarmEnt *)e)->flags & 1) func_0027CB00(e);
    }
    func_0027C970(func_0027CE60());
    return 0;
}

int func_0027D6C0(int id, unsigned long long target, void *handler, void *arg)
{
    int st = func_0027BD20();
    int r = func_0027D5C8(id, target, handler, arg);
    if (st) func_0027BD78();
    return r;
}

void func_0027D740(unsigned long long t, int *sec, int *usec)
{
    int s = func_002828C0(t, 147456000);
    if (sec) *sec = s;
    if (usec) *usec = func_002828C0((t - (unsigned long long)(unsigned int)s * 147456000) * 1000000, 147456000);
}

unsigned long long func_0027D7E8(unsigned int a, unsigned int b)
{
    unsigned long long x = (unsigned long long)a * 147456000;
    return x + func_002828C0((unsigned long long)b * 147456000, 1000000);
}

float func_0027D858(unsigned long long a)
{
    return 147456000.0f / (float)a;
}

unsigned long long func_0027D8B0(float x)
{
    return (unsigned long long)(147456000.0f / x);
}

int func_0027D8E8(void) { int i; D_423F00 = D_423B00; for (i = 0; i < 64; i++) D_423B00[i].next = &D_423B00[i + 1]; D_423B00[63].next = 0; return 0; }

int func_0027D938(unsigned int id, int a, int b, FreeEnt *e)
{
    int r = ((int (*)(int, int, int, int))e->p[1])(((int)e << 4) | (id & 0xFE) | 1, a, b, e->p[2]);
    if (r) return r;
    {
        FreeEnt *n = D_423F00;
        D_423F00 = e;
        e->next = n;
        ((volatile FreeEnt *)e)->p[0] = 0;
    }
    return -1;
}

int func_0027D998(unsigned long long ticks, void *handler, void *arg)
{
    FreeEnt *e;
    int id, st;
    if (!handler) return 0x80000016;
    st = func_0027BD20();
    e = W2AllocEnt();
    if (!e) {
        if (st) func_0027BD78();
        return 0x80008005;
    }
    id = func_0027CFA0();
    if (id < 0) {
        e->next = D_423F00;
        D_423F00 = e;
        ((volatile FreeEnt *)e)->p[0] = 0;
        if (st) func_0027BD78();
        return id;
    }
    e->p[1] = (int)handler;
    e->p[2] = (int)arg;
    e->p[0] = id;
    func_0027D6C0(id, ticks, (void *)func_0027D938, e);
    func_0027D238(id);
    if (st) func_0027BD78();
    return ((int)e << 4) | (id & 0xFE) | 1;
}

int func_0027DAC8(unsigned long long ticks, void *handler, void *arg)
{
    FreeEnt *e;
    int id;
    if (!handler) return 0x80000016;
    e = W2AllocEnt();
    if (!e) return 0x80008005;
    id = func_0027CF30();
    if (id < 0) {
        e->next = D_423F00;
        D_423F00 = e;
        ((volatile FreeEnt *)e)->p[0] = 0;
        return id;
    }
    e->p[1] = (int)handler;
    e->p[2] = (int)arg;
    e->p[0] = id;
    func_0027D5C8(id, ticks, (void *)func_0027D938, e);
    func_0027D188(id);
    return ((int)e << 4) | (id & 0xFE) | 1;
}
