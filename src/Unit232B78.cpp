#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" unsigned int strlen(const char *s);
extern "C" char *strcpy(char *d, const char *s);
extern "C" int strcmp(const char *a, const char *b);
extern const char _ctype_[];
#define isupper(c) ((_ctype_+1)[(unsigned)(c)]&01)
s32 Func235DE0(const char *fmt, ...);
inline u32 GetSR() { u32 r; __asm__ volatile("sync.p"); __asm__ volatile("mfc0 %0, $12" : "=r"(r)); __asm__ volatile("sync.p"); return r; }
inline void SetSR(u32 v) { __asm__ volatile("sync.p"); __asm__ volatile("mtc0 %0, $12" : : "r"(v)); __asm__ volatile("sync.p"); }
inline void SetSRWait(u32 v) { do SetSR(v); while (GetSR() != v); }
inline u32 DisableIntr() { u32 st; __asm__ volatile("sync.p"); __asm__ volatile("sync"); st = GetSR(); SetSRWait(st & ~1); return st; }
inline void RestoreIntr(u32 st) { __asm__ volatile("sync.p"); __asm__ volatile("sync"); SetSRWait(st); }
extern s32 D_002B8C50;
struct FsSub { char m0[0x80]; char m80[0x800]; s32 m880; char m884[0x80]; };
struct FsEnt { s32 m0; char m4[0x80]; FsSub sub[2]; };
struct FsSlot { s32 m0; void *m4; void *m8; };
struct FsRoot { s32 m0; FsSlot m4[2]; FsEnt e[4]; };
extern FsRoot D_3574C0;
struct Req { volatile s32 m0; s32 m4; s32 m8; s32 mC; s32 m10; s32 m14; s32 m18; s32 m1C; s32 m20; void (*m24)(s32, s32, s32); s32 m28; };
struct ReqQ { Req r[64]; s32 mB00; s32 mB04; };
struct Worker { s32 m0; volatile s32 m4; volatile s32 m8; volatile s32 mC; u8 stack[0x10000]; ReqQ q[2]; };
extern Worker D_35BF10[];
extern s32 D_002B8CC8[4];
extern s32 D_002B8CD8[4];
typedef void (*ErrCb)(const char *, s32);
extern ErrCb D_002B8CE8;
extern s32 D_002B8CF0[];
extern void *D_002B91A4;
extern void *D_002B91A8;
extern void *D_002B91AC;
extern void *D_002B91B0;
extern s32 D_002B8EFC;
extern char D_36D580[32][32];
extern const char D_002E4A90[];
extern const char D_002E4AB8[];
extern const char D_002E4AC8[];
extern const char D_002E4AF0[];
extern const char D_002E4B20[];
extern const char D_002E4B40[];
extern const char D_002E4BF8[];
extern "C" void func_0027BD78(void);
extern "C" s32 func_00234938(void);
extern "C" void func_001F1748(s32);
extern "C" void func_001F1830(s32, s32);
extern "C" s32 func_001F18F0(void (*)(Worker *), void *, s32, s32, Worker *);
extern "C" s32 func_001F18D0(s32, s32);
extern "C" FsSlot *func_00233050(void);
extern "C" FsEnt *func_00232FD8(s32);
extern "C" FsSub *func_00233010(s32);
extern "C" char *func_00233078(char *, char *);
extern "C" void func_002330E0(char *);
extern "C" s32 func_00233168(char *);
extern "C" s32 func_002333C0(s32, s32, void (*)(s32));
extern "C" void func_002334B0(Worker *);
extern "C" void func_00233830(ReqQ *);
extern "C" s32 func_00233840(ReqQ *, s32, s32, s32, s32, s32, s32, s32, void *, s32);
extern "C" Req *func_002339B8(ReqQ *);
extern "C" void func_00233A00(ReqQ *);
extern "C" s32 func_00233A58(ReqQ *);
extern "C" s32 func_00233A78(ReqQ *);
extern "C" void func_00233AA8(ReqQ *, s32, s32);
extern "C" s32 func_00233DD0(void);
extern "C" s32 func_00233DE0(void);
extern "C" void func_00230B30(s32);
extern "C" char *func_00234108(char *);
extern "C" s32 func_00234070(const char *);
extern "C" s32 func_00234248(const char *);
extern "C" void func_00234008(char *, const char *, s32);
extern "C" void D_00233808(s32);
inline s32 IsEol(char c) { s32 r = 0; if (c == '\r' || c == '\n') r = 1; return r; }
inline s32 IsSp(char c) { s32 r = 0; if (c == ' ' || c == '\t') r = 1; return r; }
// @decl-end

extern "C" void func_00232B78(s32 i, const char *s) {
    char *d = func_00232FD8(i)->m4;
    s32 n, x, y;
    char *p, *q;
    if (s == 0) {
        d[0] = 0;
        return;
    }
    for (n = 0; *s; s++) {
        p = &d[n++];
        x = *s;
        y = isupper(x) ? x + 0x20 : x;
        *p = y;
        if ((char)y == 0x5C) *p = 0x2F;
    }
    q = &d[n];
    *q = 0;
    if (n > 0 && q[-1] != 0x2F) {
        q[0] = 0x2F;
        q[1] = 0;
    }
}

extern "C" char *func_00232C40(s32 i) {
    return func_00232FD8(i)->m4;
}

INCLUDE_ASM("asm/nonmatchings/Unit232B78", func_00232C60);

extern "C" FsSub *func_00232D90(s32 i) {
    return func_00233010(i);
}

extern "C" void func_00232DA8(s32 i) {
    FsSub *s = func_00233010(i);
    s32 len = strlen(s->m0) + 1;
    s32 n = s->m880 - len;
    if (n >= 0) {
        s->m880 = n;
        return (void)strcpy(&s->m80[n], s->m0);
    }
    if (D_002B8C50) return (void)Func235DE0(D_002E4A90);
}

extern "C" void func_00232E30(s32 i) {
    FsSub *s = func_00233010(i);
    if (s->m880 < 0x7FF) {
        strcpy(s->m0, &s->m80[s->m880]);
        s->m880 += strlen(&s->m80[s->m880]) + 1;
    }
}

extern "C" void func_00232E98(s32 i, const char *name) {
    return (void)strcpy(func_00233010(i)->m884, name);
}

extern "C" char *func_00232EC8(s32 i) {
    return func_00233010(i)->m884;
}

extern "C" s32 func_00232EE8(s32 i, s32 v) {
    FsEnt *e = func_00232FD8(i);
    s32 old = e->m0;
    e->m0 = v;
    return old;
}

extern "C" s32 func_00232F18(s32 i) {
    return func_00232FD8(i)->m0;
}

extern "C" void *func_00232F38(void) {
    return func_00233050()->m4;
}

extern "C" void *func_00232F58(void *v) {
    FsSlot *t = func_00233050();
    void *old = t->m4;
    t->m4 = v;
    return old;
}

extern "C" void *func_00232F88(void) {
    return func_00233050()->m8;
}

extern "C" void *func_00232FA8(void *v) {
    FsSlot *t = func_00233050();
    void *old = t->m8;
    t->m8 = v;
    return old;
}

extern "C" FsEnt *func_00232FD8(s32 i) {
    func_00233050();
    return &D_3574C0.e[i];
}

extern "C" FsSub *func_00233010(s32 i) {
    return &func_00232FD8(i)->sub[D_3574C0.m0];
}

extern "C" FsSlot *func_00233050(void) {
    return &D_3574C0.m4[D_3574C0.m0];
}

extern "C" char *func_00233078(char *dst, char *src) {
    char c;
    if (*src == 0) return src;
    while ((c = *src) != 0) {
        *dst++ = *src++;
        if (c == '/') break;
    }
    if (*dst == '.' && dst[1] == '/') dst -= 2;
    *dst = 0;
    return src;
}

extern "C" void func_002330E0(char *s) {
    s32 n = strlen(s);
    if (n >= 2) {
        s[n - 1] = 0;
        for (n--; n > 0; n--) {
            if (s[n - 1] == '/') break;
            s[n - 1] = 0;
        }
    }
}

extern "C" s32 func_00233168(char *s) {
    s32 n = 0;
    char c;
    if (*s != '.') return 0;
    c = '.';
    s++;
    for (;;) {
        if (c != '.') return 0;
        c = *s++;
        n++;
        if (c == 0 || c == '/') break;
    }
    return n;
}

extern "C" void func_002331B8(void) {
    return (void)func_002333C0(0, 2, D_00233808);
}

extern "C" void func_002331E0(void) {
    Worker *w = D_35BF10;
    w->mC = 1;
    while (w->mC > 0) {
        if (!(GetSR() & 0x10000)) {
            func_0027BD78();
            Func235DE0(D_002E4AB8);
            func_0027BD78();
        }
    }
    func_001F1748(w->m8);
}

extern "C" s32 func_00233278(s32 i, s32 k, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, void *cb, s32 x) {
    return func_00233840(&D_35BF10[D_002B8CF0[k]].q[i], k, a2, a3, a4, a5, a6, a7, cb, x);
}

extern "C" void func_002332C0(s32 k, s32 x, s32 f) {
    u32 st = DisableIntr();
    ReqQ *q = D_35BF10[D_002B8CF0[k]].q;
    s32 i;
    for (i = 0; i < 2; i++, q++) func_00233AA8(q, x, f);
    RestoreIntr(st);
}

INCLUDE_ASM("asm/nonmatchings/Unit232B78", func_002333C0);

INCLUDE_ASM("asm/nonmatchings/Unit232B78", func_002334B0);

extern "C" void func_00233820(void) {
}

extern "C" void func_00233828(void) {
}

extern "C" void func_00233830(ReqQ *q) {
    q->mB00 = 0;
    q->mB04 = 0;
}

extern "C" s32 func_00233840(ReqQ *q, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, void *cb, s32 x) {
    u32 st;
    s32 h;
    Req *r;
    if (func_00233A78(q) > 0) {
        st = DisableIntr();
        r = &q->r[q->mB00];
        q->mB00 = (q->mB00 + 1) % 64;
        r->m0 = 0;
        r->m4 = a1;
        r->m8 = a2;
        r->mC = a3;
        r->m10 = a4;
        r->m14 = a5;
        r->m18 = a6;
        r->m1C = a7;
        r->m20 = 0;
        r->m24 = (void (*)(s32, s32, s32))cb;
        r->m28 = x;
        RestoreIntr(st);
        return 1;
    }
    Func235DE0(D_002E4B40);
    return 0;
}

extern "C" Req *func_002339B8(ReqQ *q) {
    if (func_00233A58(q) > 0) return &q->r[q->mB04];
    return 0;
}

extern "C" void func_00233A00(ReqQ *q) {
    if (func_00233A58(q) > 0) q->mB04 = (q->mB04 + 1) % 64;
}

extern "C" s32 func_00233A58(ReqQ *q) {
    s32 n = q->mB00 - q->mB04;
    if (n < 0) n += 64;
    return n;
}

extern "C" s32 func_00233A78(ReqQ *q) {
    s32 n = 64 - func_00233A58(q);
    return n - (n > 0);
}

extern "C" void func_00233AA8(ReqQ *q, s32 x, s32 force) {
    u32 st = DisableIntr();
    s32 i = q->mB04;
    s32 h = q->mB00;
    Req *r;
    while (i != h) {
        r = &q->r[i];
        if (r->m28 == x && r->m0 != 1 && (r->m20 != 1 || force)) {
            if (r->m24) r->m24(r->m28, r->m10, r->m18);
            r->m0 = 1;
            r->m28 = 0;
            r->m24 = 0;
            h = q->mB00;
        }
        i = (i + 1) % 64;
    }
    RestoreIntr(st);
}

extern "C" void func_00233C10(s32 a, s32 b) {
    s32 i, j;
    if (a == -1) i = func_00234938(); else i = a;
    if (b == -1) j = func_00234938(); else j = b;
    i = i < 0 ? 0 : (i > 3 ? 3 : i);
    j = j < 0 ? 0 : (j > 3 ? 3 : j);
    D_002B8CC8[i] = j;
}

INCLUDE_ASM("asm/nonmatchings/Unit232B78", func_00233CC0);

INCLUDE_ASM("asm/nonmatchings/Unit232B78", func_00233D28);

INCLUDE_ASM("asm/nonmatchings/Unit232B78", func_00233D40);

extern "C" void func_00233D58(ErrCb f) {
    D_002B8CE8 = f;
}

extern "C" ErrCb func_00233D68(void) {
    return D_002B8CE8;
}

extern "C" s32 func_00233D78(s32 x) {
    s32 r = func_00233DD0();
    func_001F1830(D_35BF10[0].m8, x);
    D_35BF10[0].m0 = x + 1;
    return r;
}

extern "C" s32 func_00233DD0(void) {
    return D_35BF10[0].m0 - 1;
}

extern "C" s32 func_00233DE0(void) {
    Func235DE0(D_002E4BF8);
    return 0;
}

extern "C" void *func_00233E08(void *f) {
    void *old = D_002B91A4;
    if (!f) D_002B91A4 = (void *)func_00233DE0;
    else D_002B91A4 = f;
    return old;
}

extern "C" void *func_00233E38(void *f) {
    void *old = D_002B91A8;
    if (!f) D_002B91A8 = (void *)func_00233DE0;
    else D_002B91A8 = f;
    return old;
}

extern "C" void *func_00233E68(void *f) {
    void *old = D_002B91AC;
    if (!f) D_002B91AC = (void *)func_00233DE0;
    else D_002B91AC = f;
    return old;
}

extern "C" void *func_00233E98(void *f) {
    void *old = D_002B91B0;
    if (!f) D_002B91B0 = (void *)func_00233DE0;
    else D_002B91B0 = f;
    return old;
}

extern "C" s32 func_00233EC8(const char *s) {
    s32 n;
    for (n = 0; *s; n++) if (IsEol(*s++)) break;
    return n;
}

extern "C" s32 func_00233F08(const char *s) {
    s32 n;
    for (n = 0; *s; n++) if (IsSp(*s++)) break;
    return n;
}

extern "C" const char *func_00233F48(const char *s) {
    while (*s && IsEol(*s)) s++;
    return s;
}

extern "C" const char *func_00233F88(const char *s) {
    while (*s && IsSp(*s)) s++;
    return s;
}

INCLUDE_ASM("asm/nonmatchings/Unit232B78", func_00233FC8);

extern "C" void func_00234008(char *d, const char *s, s32 n) {
    char *p = d;
    s32 i = 0;
    s32 c;
    while (i < n && (c = *s++) != 0) {
        c = c == '\\' ? '/' : c;
        i++;
        c = isupper(c) ? c + 0x20 : c;
        *p++ = c;
    }
    *p = 0;
}

extern "C" s32 func_00234070(const char *name) {
    s32 i;
    char *p;
    if (name == 0) return 0;
    for (i = 0, p = D_36D580[0]; i < D_002B8EFC; i++) {
        if (strcmp(name, p) == 0) return 1;
        p += 32;
    }
    return 0;
}

extern "C" char *func_00234108(char *s) {
    s32 i = strlen(s) - 1;
    char c;
    while (i >= 0 && (c = s[i]) != '/' && c != '\\' && c != ':' && c != ',') i--;
    return s + i + 1;
}

extern "C" char *func_002341C0(char *s) {
    char *b = func_00234108(s);
    s32 n = strlen(b);
    s32 i;
    for (i = n - 1; i >= 0; i--) if (b[i] == '.') break;
    if (i >= 0) return b + i + 1;
    return b + n;
}

extern "C" s32 func_00234248(const char *s) {
    char c = *s;
    if (c == 0) return 1;
    if (c == '-' || c == '#') return 1;
    return 0;
}

extern "C" s32 func_00234278(char *s) {
    if (func_00234248(s)) return 1;
    return func_00234070(func_00234108(s)) != 0;
}

extern "C" void func_002342C8(const char *name) {
    s32 n = D_002B8EFC;
    if (n < 32) {
        D_002B8EFC = n + 1;
        return (void)func_00234008(D_36D580[n], name, 31);
    }
}
