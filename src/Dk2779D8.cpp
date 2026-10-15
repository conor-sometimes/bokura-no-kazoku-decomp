#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern int func_002781F0(const char *, int);
extern char D_420440[];
extern int D_002BDB4C;
extern int D_002BDB34;
extern int D_002BDB40;
extern int D_4204C0[];
extern int D_420480[];
int func_0027A068(int);
typedef struct SemaParam { int count, max_count, init_count, wait_threads; unsigned int attr, option; } SemaParam;
typedef struct McCmd {
    int sema; int *dst; int size;
    union {
        char name[0x400];
        int arg;
        struct { int fd; char name[0x400]; } fn;
        struct { int fd; int b; } f2;
        struct { int fd; int b; char name[0x400]; } g;
        struct { char a[0x400]; char b[0x400]; char data[0x400]; int len; } n3;
        struct { char a[0x400]; char b[0x400]; char data[0x400]; int c; int len; } n4;
        struct { int fd; int b; char data[0x400]; int f, e, len; } io;
        struct { char a[0x400]; char data[0x400]; int b, len, e, f; } n5;
        struct { int fd; int off[2]; int whence, idx; } sk;
        struct { int fd; void *buf; int size; int n; unsigned char data[16]; int idx; } rd;
    } u;
} McCmd;
extern McCmd D_41EC40;
extern char D_420340[];
extern int D_41F880[];
typedef struct Fd { int fd, flag, a, b; } Fd;
extern Fd D_420140[];
extern int func_002760B0(void *, int, int, void *, int, void *, int, void *, void *);
extern int func_00275EE0(void *, unsigned int, int);
extern void func_00275698(void *, int);
extern int func_00276D38(int);
extern void func_00276D68(void);
extern void func_00276E68(void);
extern Fd *func_00276838(void);
extern Fd *func_002768C0(int);
extern int func_002731A0(SemaParam *);
extern int func_002731B0(int);
extern int func_002731C0(int);
extern int func_002731E0(int);
extern void *memcpy(void *, const void *, unsigned int);
#define RPC_TAIL(CMD, SZ, ERR) \
    if (func_002760B0(D_420340, CMD, 0, &D_41EC40, SZ, D_41F880, 4, 0, 0) < 0) { \
        func_002731B0(sema); func_00276D68(); return ERR; } \
    ok = *(int *)((unsigned int)D_41F880 | 0x20000000); \
    func_00276D68(); \
    if (ok == 0) { func_002731B0(sema); return ERR; } \
    func_002731E0(sema); func_002731B0(sema);
extern int D_002BDB44;
extern int D_002BDAB0[32];
// @decl-end

INCLUDE_ASM("asm/nonmatchings/Dk2779D8", func_002779D8);

INCLUDE_ASM("asm/nonmatchings/Dk2779D8", func_00277C98);

int func_00278010(int fd, int b, const void *data, unsigned int len, int f, unsigned int e)
{
    SemaParam sp;
    int res;
    int sema, ok;
    McCmd *c = &D_41EC40;
    Fd *p = func_002768C0(fd);
    func_00276D38(0x1A);
    if (D_002BDB34 == 0) func_00276E68();
    if (p == 0 || p->flag == 0) { func_00276D68(); return -9; }
    if (len > 0x400 || e > 0x400) { func_00276D68(); return -22; }
    if (data == 0) c->u.io.len = 0;
    else memcpy(c->u.io.data, data, len);
    c->u.io.fd = p->fd;
    c->u.io.b = b;
    c->u.io.len = len;
    sp.max_count = 1;
    sp.init_count = 0;
    sp.option = 0;
    sema = func_002731A0(&sp);
    c->u.io.e = e;
    c->dst = &res;
    c->size = 4;
    c->u.io.f = f;
    c->sema = sema;
    func_00275698(&D_41EC40, 0x420);
    RPC_TAIL(0x1A, 0x420, -11)
    return res;
}

int func_002781F0(const char *name, int cmd)
{
    SemaParam sp;
    int res;
    int i, sema, ok;
    McCmd *c = &D_41EC40;
    func_00276D38(cmd);
    if (D_002BDB34 == 0) func_00276E68();
    for (i = 0; i < 0x400; i++) {
        if ((c->u.name[i] = name[i]) == 0) break;
    }
    if (i == 0x400) {
        c->u.name[0x3FF] = 0;
        i = 0x3FF;
    }
    sp.init_count = 0;
    sp.max_count = 1;
    sp.option = 0;
    sema = func_002731A0(&sp);
    c->sema = sema;
    c->dst = &res;
    c->size = 4;
    RPC_TAIL(cmd, i + 0xD, -11)
    return res;
}

int func_00278398(const char *a) { return func_002781F0(a, 6); }

int func_002783B8(const char *name, int b)
{
    SemaParam sp;
    int res;
    int i, sema, ok;
    McCmd *c = &D_41EC40;
    func_00276D38(7);
    if (D_002BDB34 == 0) func_00276E68();
    for (i = 0; i < 0x400; i++) {
        if ((c->u.fn.name[i] = name[i]) == 0) break;
    }
    if (i == 0x400) {
        c->u.fn.name[0x3FF] = 0;
        i = 0x3FF;
    }
    c->u.fn.fd = b;
    sp.max_count = 1;
    sp.init_count = 0;
    sp.option = 0;
    sema = func_002731A0(&sp);
    c->sema = sema;
    c->dst = &res;
    c->size = 4;
    RPC_TAIL(7, i + 0x11, -11)
    return res;
}

int func_00278568(const char *a) { return func_002781F0(a, 8); }

int func_00278588(const char *a, const char *b, const char *data, int len)
{
    SemaParam sp;
    int res;
    int i, sema, ok;
    McCmd *c = &D_41EC40;
    func_00276D38(0xE);
    if (D_002BDB34 == 0) func_00276E68();
    for (i = 0; i < 0x400; i++) {
        if ((c->u.n3.a[i] = a[i]) == 0) break;
    }
    if (i == 0x400) c->u.n3.a[0x3FF] = 0;
    if (b == 0) {
        c->u.n3.b[0] = 0;
    } else {
        for (i = 0; i < 0x400; i++) {
            if ((c->u.n3.b[i] = b[i]) == 0) break;
        }
        if (i == 0x400) c->u.n3.b[0x3FF] = 0;
    }
    if (len > 0x400) { func_00276D68(); return -7; }
    for (i = 0; i < len; i++) c->u.n3.data[i] = data[i];
    c->u.n3.len = len;
    sp.max_count = 1;
    sp.init_count = 0;
    sp.option = 0;
    sema = func_002731A0(&sp);
    c->dst = &res;
    c->sema = sema;
    c->size = 4;
    func_00275698(&D_41EC40, 0xC10);
    RPC_TAIL(0xE, 0xC10, -11)
    return res;
}

int func_002787F8(int a)
{
    SemaParam sp;
    int res;
    int sema, ok;
    McCmd *c = &D_41EC40;
    func_00276D38(0xF);
    if (D_002BDB34 == 0) func_00276E68();
    c->u.arg = a;
    sp.max_count = 1;
    sp.init_count = 0;
    sp.option = 0;
    sema = func_002731A0(&sp);
    D_41EC40.sema = sema;
    c->dst = &res;
    c->size = 4;
    if (func_002760B0(D_420340, 0xF, 0, c, 0x10, D_41F880, 4, 0, 0) < 0) {
        func_002731B0(sema); func_00276D68(); return -1; }
    ok = *(int *)((unsigned int)D_41F880 | 0x20000000);
    func_00276D68();
    if (ok == 0) { func_002731B0(sema); return -1; }
    func_002731E0(sema); func_002731B0(sema);
    return res;
}

int func_00278918(const char *a) { return func_002781F0(a, 0x10); }

int func_00278938(const char *a)
{
    Fd *p;
    int r;
    func_00276D38(9);
    if (D_002BDB34 == 0) func_00276E68();
    func_00276D68();
    if ((p = func_00276838()) == 0) return -19;
    if ((r = func_002781F0(a, 9)) < 0) {
        func_002731E0(D_002BDB40);
        p->flag = 0;
        func_002731C0(D_002BDB40);
        return r;
    }
    func_002731E0(D_002BDB40);
    p->fd = r;
    r = p - D_420140;
    func_002731C0(D_002BDB40);
    return r;
}

int func_00278A00(int fd)
{
    SemaParam sp;
    int res;
    int sema, ok;
    McCmd *c = &D_41EC40;
    Fd *p = func_002768C0(fd);
    func_00276D38(0xA);
    if (D_002BDB34 == 0) { func_00276D68(); return -1; }
    if (p == 0 || p->flag == 0) { func_00276D68(); return -9; }
    c->u.arg = p->fd;
    sp.max_count = 1;
    sp.init_count = 0;
    sp.option = 0;
    sema = func_002731A0(&sp);
    D_41EC40.sema = sema;
    c->dst = &res;
    c->size = 4;
    if (func_002760B0(D_420340, 0xA, 0, c, 0x14, D_41F880, 4, 0, 0) < 0) {
        func_002731B0(sema); func_00276D68(); return -11; }
    p->flag = 0;
    ok = *(int *)((unsigned int)D_41F880 | 0x20000000);
    func_00276D68();
    if (ok == 0) { func_002731B0(sema); return -11; }
    func_002731E0(sema); func_002731B0(sema);
    ok = 0;
    if (res < 0) ok = res;
    return ok;
}

int func_00278B68(int fd, int b)
{
    SemaParam sp;
    int res;
    int sema, ok;
    McCmd *c = &D_41EC40;
    Fd *p = func_002768C0(fd);
    func_00276D38(0xB);
    if (D_002BDB34 == 0) { func_00276D68(); return -1; }
    if (p == 0 || p->flag == 0) { func_00276D68(); return -9; }
    c->u.f2.fd = p->fd;
    c->u.f2.b = b;
    sp.max_count = 1;
    sp.init_count = 0;
    sp.option = 0;
    sema = func_002731A0(&sp);
    D_41EC40.sema = sema;
    c->dst = &res;
    c->size = 4;
    if (func_002760B0(D_420340, 0xB, 0, c, 0x20, D_41F880, 4, 0, 0) < 0) {
        func_002731E0(sema); func_00276D68(); return -11; }
    ok = *(int *)((unsigned int)D_41F880 | 0x20000000);
    func_00276D68();
    if (ok == 0) { func_002731B0(sema); return -11; }
    func_002731E0(sema); func_002731B0(sema);
    return res;
}

INCLUDE_ASM("asm/nonmatchings/Dk2779D8", func_00278CC0);

INCLUDE_ASM("asm/nonmatchings/Dk2779D8", func_00278E60);

int func_002790A0(const char *a, const char *b)
{
    SemaParam sp;
    int res;
    int i, sema, ok;
    McCmd *c = &D_41EC40;
    func_00276D38(0x11);
    if (D_002BDB34 == 0) func_00276E68();
    for (i = 0; i < 0x400; i++) {
        if ((c->u.n3.a[i] = a[i]) == 0) break;
    }
    if (i == 0x400) c->u.n3.a[0x3FF] = 0;
    for (i = 0; i < 0x400; i++) {
        if ((c->u.n3.b[i] = b[i]) == 0) break;
    }
    if (i == 0x400) c->u.n3.b[0x3FF] = 0;
    sp.init_count = 0;
    sp.max_count = 1;
    sp.option = 0;
    sema = func_002731A0(&sp);
    c->dst = &res;
    c->sema = sema;
    c->size = 4;
    func_00275698(&D_41EC40, 0x80C);
    RPC_TAIL(0x11, 0x80C, -11)
    return res;
}

int func_00279290(const char *a) { return func_002781F0(a, 0x12); }

int func_002792B0(const char *name, int b)
{
    SemaParam sp;
    int res;
    int i, sema, ok;
    McCmd *c = &D_41EC40;
    func_00276D38(0x13);
    if (D_002BDB34 == 0) func_00276E68();
    for (i = 0; i < 0x400; i++) {
        if ((c->u.g.name[i] = name[i]) == 0) break;
    }
    if (i == 0x400) c->u.g.name[0x3FF] = 0;
    c->u.g.b = b;
    sp.max_count = 1;
    sp.init_count = 0;
    sp.option = 0;
    sema = func_002731A0(&sp);
    c->sema = sema;
    c->dst = &res;
    c->size = 4;
    RPC_TAIL(0x13, 0x414, -11)
    return res;
}

int func_00279448(const char *a, const char *b, int cc, const char *data, int len)
{
    SemaParam sp;
    int res;
    int i, sema, ok;
    McCmd *c = &D_41EC40;
    func_00276D38(0x14);
    if (D_002BDB34 == 0) func_00276E68();
    for (i = 0; i < 0x400; i++) {
        if ((c->u.n4.a[i] = a[i]) == 0) break;
    }
    if (i == 0x400) c->u.n4.a[0x3FF] = 0;
    for (i = 0; i < 0x400; i++) {
        if ((c->u.n4.b[i] = b[i]) == 0) break;
    }
    if (i == 0x400) c->u.n4.b[0x3FF] = 0;
    if (len > 0x400) { func_00276D68(); return -7; }
    for (i = 0; i < len; i++) c->u.n4.data[i] = data[i];
    c->u.n4.len = len;
    c->u.n4.c = cc;
    sp.max_count = 1;
    sp.init_count = 0;
    sp.option = 0;
    sema = func_002731A0(&sp);
    c->dst = &res;
    c->sema = sema;
    c->size = 4;
    func_00275698(&D_41EC40, 0xC14);
    RPC_TAIL(0x14, 0xC14, -11)
    return res;
}

int func_002796B8(const char *a) { return func_002781F0(a, 0x15); }

INCLUDE_ASM("asm/nonmatchings/Dk2779D8", func_002796D8);

int func_00279910(const char *a, int b, const char *data, unsigned int len, int e, unsigned int f)
{
    SemaParam sp;
    int res;
    int sema, ok;
    int i;
    McCmd *c;
    func_00276D38(0x17);
    c = &D_41EC40;
    if (D_002BDB34 == 0) func_00276E68();
    for (i = 0; i < 0x400; i++) {
        if ((c->u.n5.a[i] = a[i]) == 0) break;
    }
    if (i == 0x400) c->u.n5.a[0x3FF] = 0;
    if (len > 0x400 || f > 0x400) { func_00276D68(); return -22; }
    for (i = 0; i < len; i++) c->u.n5.data[i] = data[i];
    c->u.n5.len = len;
    c->u.n5.b = b;
    sp.max_count = 1;
    sp.init_count = 0;
    sp.option = 0;
    sema = func_002731A0(&sp);
    c->u.n5.f = f;
    c->dst = &res;
    c->size = 4;
    c->u.n5.e = e;
    c->sema = sema;
    func_00275698(&D_41EC40, 0x81C);
    RPC_TAIL(0x17, 0x81C, -11)
    return res;
}

int func_00279B48(const char *a, const char *b)
{
    SemaParam sp;
    int res;
    int i, sema, ok;
    McCmd *c = &D_41EC40;
    func_00276D38(0x11);
    if (D_002BDB34 == 0) func_00276E68();
    for (i = 0; i < 0x400; i++) {
        if ((c->u.n3.a[i] = a[i]) == 0) break;
    }
    if (i == 0x400) c->u.n3.a[0x3FF] = 0;
    for (i = 0; i < 0x400; i++) {
        if ((c->u.n3.b[i] = b[i]) == 0) break;
    }
    if (i == 0x400) c->u.n3.b[0x3FF] = 0;
    sp.init_count = 0;
    sp.max_count = 1;
    sp.option = 0;
    sema = func_002731A0(&sp);
    c->dst = &res;
    c->sema = sema;
    c->size = 4;
    RPC_TAIL(0x18, 0x80C, -11)
    return res;
}

int func_00279D28(const char *name, void *buf, unsigned int size)
{
    SemaParam sp;
    int res;
    int i, sema, ok;
    McCmd *c = &D_41EC40;
    func_00276D38(0x11);
    if (D_002BDB34 == 0) func_00276E68();
    for (i = 0; i < 0x400; i++) {
        if ((c->u.g.name[i] = name[i]) == 0) break;
    }
    if (i == 0x400) c->u.g.name[0x3FF] = 0;
    if (size >= 0x400) size = 0x3FF;
    c->u.g.b = (int)buf;
    c->u.g.fd = size;
    func_00275698(buf, size);
    sp.init_count = 0;
    sp.max_count = 1;
    sp.option = 0;
    sema = func_002731A0(&sp);
    c->dst = &res;
    c->sema = sema;
    c->size = 4;
    RPC_TAIL(0x19, 0x80C, -11)
    return res;
}

INCLUDE_ASM("asm/nonmatchings/Dk2779D8", func_00279EF0);

int func_00279F78(int a)
{
    if (D_002BDB4C < 0) return 0;
    D_4204C0[0] = a;
    if (func_002760B0(D_420440, 1, 0, D_4204C0, 4, D_420480, 4, 0, 0) < 0) return 0;
    return D_420480[0];
}

int func_00279FE8(int a, int b, int c)
{
    if (D_002BDB4C < 0) return 0;
    D_4204C0[0] = b;
    D_4204C0[1] = a;
    D_4204C0[2] = c;
    if (func_002760B0(D_420440, 4, 0, D_4204C0, 0xC, D_420480, 4, 0, 0) < 0) return 0;
    return D_420480[0];
}

int func_0027A068(int a)
{
    if (D_002BDB4C < 0) return 0;
    D_4204C0[0] = a;
    if (func_002760B0(D_420440, 2, 0, D_4204C0, 4, D_420480, 4, 0, 0) < 0) return -1;
    return D_420480[0];
}

int func_0027A0E0(int a) { return func_0027A068(a); }
