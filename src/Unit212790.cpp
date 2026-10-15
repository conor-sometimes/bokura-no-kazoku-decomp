#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" int strcmp(const char *, const char *);
extern "C" char *strcpy(char *, const char *);
struct Seq20 { Seq20 *next; s32 m4; s32 m8; s32 mC; s32 m10; s32 m14; s32 m18; s32 m1C; };
struct S335568 { Seq20 e[64]; Seq20 *active; Seq20 *free; };
extern S335568 D_335568;
struct SndFns { void *(*alloc)(s32); void (*free)(void *); void (*f8)(void *); void *(*fC)(s32); void (*f10)(void *); void (*f14)(void *); void (*cb)(void); };
extern SndFns D_335D70;
extern void *D_002B91A4;
extern void *D_002B91A8;
extern void *D_002B91B0;
extern s32 D_002A61D0;
struct Rec { s16 m0; u8 m2; u8 m3; const char *m4; s16 m8; u8 mA; u8 mB; s16 mC; s16 mE; s32 m10; s32 m14; s16 m18; s16 m1A; s16 m1C; };
struct Ops { s32 (*f0)(Rec *, s32, s32); s32 (*f1)(Rec *, s32, s32); s32 (*f2)(Rec *, s32, s32); };
struct Slot { s32 used; Ops ops; };
struct S335D90 { Rec **tbl; s32 n; char name[0x100]; Slot slots[257]; };
extern char D_335D98[];
extern S335D90 D_335D90;
extern Ops D_002A61D8;
extern const char D_002E37D0[];
extern const char D_002E3808[];
extern const char D_002E3840[];
extern "C" void func_00210880(u32);
extern "C" s32 func_002108E0(u32, s32);
extern "C" s32 func_001F1180(void);
extern "C" s32 func_001F1200(void);
extern "C" s32 func_001F0C08(void);
void Func235DE0(const char *, ...);
extern "C" void func_0023EB18(void);
extern "C" void func_00211338(void);
extern "C" void func_002129E0(void);
extern "C" void func_00219AA0(void);
extern "C" void func_002132A0(void);
extern "C" void func_00214938(void);
extern "C" void func_00215C68(void);
extern "C" void func_00214F70(void);
extern "C" void func_00218E20(void);
extern "C" void func_00218E60(void);
extern "C" void func_00214FC0(void);
extern "C" void func_00215CE0(void);
extern "C" void func_00214958(void);
extern "C" void func_00213308(void);
extern "C" void func_00219B20(void);
extern "C" void func_00212A20(void);
extern "C" void func_002113B0(void);
extern "C" void func_0023EB48(void);
extern "C" void func_00212A28(void);
extern "C" void func_00219B60(void);
extern "C" void func_00213340(void);
extern "C" void func_002149B8(void);
extern "C" void func_00215D20(void);
extern "C" void func_00215008(void);
extern "C" void func_00218E68(void);
extern "C" void func_00205F00(void);
extern "C" void func_002113E0(void);
extern "C" s32 func_00212918(void);
extern "C" void *func_00212AE0(s32);
extern "C" void func_00212B30(void *);
extern "C" Rec *func_00213348(s32);
extern "C" Ops *func_00213388(s32);
extern "C" s32 func_002133C8(Rec *, s32, s32);
extern "C" void func_002133D0(void);
extern "C" s32 func_002133D8(Rec *, s32, s32);
extern "C" s32 func_002133E0(s32, s32, s32, s32);
extern "C" s32 func_00213558(s32, s32, s32, s32);
extern "C" void func_00213898(void);
extern "C" void func_002139E8(void);
extern "C" void func_00213B90(void);

extern "C" s32 func_00212DF8(u32, Ops *);
struct ReqHdr { u8 m0; u8 m1; u16 m2; u16 stack[2]; };
struct Req { s32 m0[6]; s32 m18; ReqHdr hdr; s32 m24; s32 m28; s32 m2C; s32 m30; void *m34; void *m38; void *m3C; s32 m40; s32 m44; s32 m48; s32 m4C; };
struct Req40 { s32 m0[6]; s16 m18; s16 m1A; s16 m1C; s16 m1E; s32 m20; s32 m24; s32 m28; s32 m2C; s32 m30; s32 m34; s32 m38; s32 m3C; };
extern "C" void func_00205F00(void);
extern "C" void func_00212A58(void);
extern "C" void func_00213C98(Req *);
extern "C" s32 func_00213D68(Req *);
extern "C" void func_00213CD0(Req *);
extern "C" void *func_00214A30(void *, s32, s32);
extern u8 D_002A61E8[];
extern u8 D_002A61F8[];
extern u8 D_002A6208[];
extern u8 D_002A6218[];
extern u8 D_002A6228[];
extern u8 D_002A6238[];
extern u8 D_002A6248[];
extern u8 D_002A6258[];
extern "C" void func_00213850(void);
extern "C" void func_00214B50(Rec *);
extern "C" void func_00214080(void *);
extern "C" s32 func_002140A0(void *);
extern "C" void func_00214098(void);
extern "C" void func_00214180(void *);
extern "C" s32 func_00214238(void *);
extern "C" void func_002141B8(void *);
extern "C" void func_00214528(void *);
extern "C" s32 func_00214548(void *);
extern "C" void func_00214540(void);
extern "C" void func_00214610(void *);
extern "C" s32 func_002146B0(void *);
extern "C" void func_00214640(void *);
extern "C" s32 func_0020E2F0(s32);
extern "C" void func_0020E1B8(s32);
extern "C" void func_00219950(s32);
extern "C" void func_0022DDE8(s32);
extern "C" s32 func_00208670(s32, s32);
extern "C" void func_00219970(void *);
extern "C" void func_00219990(void *);

#define CLAMPZ(x) ((x) < 0 ? 0 : (x))
extern "C" void func_001F15F0(void);
extern "C" void func_001F1610(void);
typedef s32 (*Ops2)(Rec *, s32);
inline u8 RecF1(Rec *p) { return p->mA & 1; }
extern "C" void func_002136E8(s32, s32);
extern "C" void func_00212FD8(s32, s32);
extern "C" void func_00215F10(s32);

#define PT_BEGIN(h) u16 _lc = (h)->m2; u16 *_sp = &(h)->stack[(h)->m1]; if ((h)->m0 & 0x80) goto _yield; switch (_lc) { case 0:
#define PT_WAIT_WHILE(h, line, cond) while (cond) { (h)->m2 = line; goto _yield; case line:; }
#define PT_END(h) } _yield: (h)->m1 = _sp - (h)->stack; return 0;
struct ReqB { s32 m0[6]; s32 m18; ReqHdr hdr; s32 m24; s32 m28; s32 m2C; s32 m30; void *m34; void *m38; s32 m3C; s32 m40; };
struct ReqE { s32 m0[6]; s32 m18; ReqHdr hdr; s32 m24; s32 m28; s32 m2C; s32 m30; s32 m34; s32 m38; s32 m3C; };
extern "C" s32 func_002088B8(s32);
extern "C" s32 func_00208948(s32);
extern "C" s32 func_00209058(s32);
extern "C" s32 func_00208E48(s32, s32);
extern "C" void func_00212BA8(void *);

#define PT2_BEGIN(h) u16 _nlc; u16 _lc = (h)->m2; u16 *_sp = &(h)->stack[(h)->m1]; if ((h)->m0 & 0x80) goto _out; switch (_lc) { case 0:
#define PT2_WAIT_WHILE(h, line, cond) while (cond) { _nlc = line; goto _wait; case line:; }
#define PT2_YIELD(h, line) { _nlc = line; goto _wait; }
#define PT2_END(h) } goto _out; _wait: (h)->m2 = _nlc; _out: (h)->m1 = _sp - (h)->stack; return 0;
extern "C" void func_0022DCE0(void);
extern "C" void func_0022DC90(const char *);
extern "C" s32 func_0022DD78(s32, s32);
extern "C" void func_0022DD00(void);
extern "C" s32 func_0022E2C8(s32, s32);
extern "C" s32 func_0022E230(s32, s32, s32);
extern "C" void func_0022DF28(s32, void *, s32);
extern "C" s32 func_002090E8(void *);
extern "C" void *func_00219880(s32, s32);
extern "C" s32 func_00208B30(s32, void *, void *);
extern "C" void func_00208F98(s32, s32, s32);
extern "C" s32 func_00213238(s32);
extern "C" s32 func_002089E0(void *);
extern "C" s32 func_00208B00(void *);
extern "C" void *func_002198E8(s32, s32);
extern "C" s32 func_00208260(s32, void *, void *, void *);
extern "C" s32 func_002087E8(s32, s32);
extern "C" s32 func_00219818(s32, s32);
extern "C" s32 func_0020DFD8(s32, s32);
extern "C" void func_0020E210(s32, const char *);
struct RecW { s16 m0; u8 m2; u8 m3; const char *m4; s16 m8; u8 mA; u8 mB; s16 mC; s16 mE; s32 m10; s32 m14; const char *m18; s16 m1C; };
extern "C" s32 func_00212B80(void *);
extern "C" s32 func_00212F20(s32);
inline s32 OpenSnd(ReqB *r, Rec *p) {
    func_0022DCE0();
    func_0022DC90(0);
    func_0022DC90(D_335D98);
    r->m2C = func_0022DD78(p->m14, 0x8001);
    func_0022DD00();
    return r->m2C;
}
inline s32 AllReady(Rec *p) {
    s32 i;
    for (i = 0; i < p->m1C; i++) {
        if (!func_00213238(p->m1A + i)) return 0;
    }
    return 1;
}
// @decl-end

extern "C" s32 func_00212790(s32 i) {
    return D_335568.e[i].m10;
}

extern "C" void func_002127A8(s32 i) {
    func_00210880(D_335568.e[i].mC);
    return;
}

extern "C" s32 func_002127D0(s32 i, s32 a) {
    return func_002108E0(D_335568.e[i].mC, a);
}

extern "C" void func_002127F8(void) {
    func_0023EB18();
    func_00211338();
    func_002129E0();
    func_00219AA0();
    func_002132A0();
    func_00214938();
    func_00215C68();
    func_00214F70();
    func_00218E20();
    return;
}

extern "C" void func_00212850(void) {
    func_00218E60();
    func_00214FC0();
    func_00215CE0();
    func_00214958();
    func_00213308();
    func_00219B20();
    func_00212A20();
    func_002113B0();
    func_0023EB48();
    return;
}

extern "C" void func_002128A8(void) {
    func_00212A28();
    func_00219B60();
    func_00213340();
    func_002149B8();
    func_00215D20();
    func_00215008();
    func_00218E68();
    func_00205F00();
    func_002113E0();
    return;
}

extern "C" s32 func_00212900(s32 v) {
    s32 old = D_002A61D0;
    D_002A61D0 = v;
    return old;
}

extern "C" s32 func_00212918(void) {
    return D_002A61D0;
}

extern "C" void *func_00212928(void *v) {
    void *old = (void *)D_335D70.alloc;
    D_335D70.alloc = (void *(*)(s32))v;
    return old;
}

extern "C" void *func_00212940(void *v) {
    void *old = (void *)D_335D70.free;
    D_335D70.free = (void (*)(void *))v;
    return old;
}

extern "C" void *func_00212958(void *v) {
    void *old = (void *)D_335D70.f8;
    D_335D70.f8 = (void (*)(void *))v;
    return old;
}

extern "C" void *func_00212970(void *v) {
    void *old = (void *)D_335D70.fC;
    D_335D70.fC = (void *(*)(s32))v;
    return old;
}

extern "C" void *func_00212988(void *v) {
    void *old = (void *)D_335D70.f10;
    D_335D70.f10 = (void (*)(void *))v;
    return old;
}

extern "C" void *func_002129A0(void *v) {
    void *old = (void *)D_335D70.f14;
    D_335D70.f14 = (void (*)(void *))v;
    return old;
}

extern "C" void *func_002129B8(void *v) {
    void *old = (void *)D_335D70.cb;
    D_335D70.cb = (void (*)(void))v;
    return old;
}

extern "C" void *func_002129D0(void) {
    return (void *)D_335D70.cb;
}

extern "C" void func_002129E0(void) {
    D_335D70.cb = 0;
    D_335D70.alloc = (void *(*)(s32))D_002B91A4;
    D_335D70.free = (void (*)(void *))D_002B91A8;
    D_335D70.f10 = (void (*)(void *))D_002B91A8;
    D_335D70.f8 = (void (*)(void *))D_002B91B0;
    D_335D70.f14 = (void (*)(void *))D_002B91B0;
    D_335D70.fC = (void *(*)(s32))D_002B91A4;
}

extern "C" void func_00212A20(void) {
}

extern "C" void func_00212A28(void) {
}

extern "C" void func_00212A30(void) {
    if (D_335D70.cb) D_335D70.cb();
}

extern "C" void func_00212A58(void) {
}

extern "C" void func_00212A60(const char *name) {
    if (func_001F1180() == 1 && !func_001F1200() && !func_001F0C08() && (func_00212918() & 2)) {
        Func235DE0(D_002E37D0, name);
        return;
    }
}

extern "C" void *func_00212AE0(s32 n) {
    return D_335D70.alloc(n);
}

extern "C" s32 func_00212B08(void *p) {
    return ((s32 (*)(void *))D_335D70.free)(p);
}

extern "C" void func_00212B30(void *p) {
    D_335D70.f8(p);
}

extern "C" void *func_00212B58(s32 n) {
    return D_335D70.fC(n);
}

extern "C" s32 func_00212B80(void *p) {
    return ((s32 (*)(void *))D_335D70.f10)(p);
}

extern "C" void func_00212BA8(void *p) {
    D_335D70.f14(p);
}

extern "C" s32 func_00212BD0(s32 n) {
    s32 i;
    if (D_335D90.tbl) {
        func_00212B30(D_335D90.tbl);
        D_335D90.tbl = 0;
    }
    if (n > 0) {
        D_335D90.tbl = (Rec **)func_00212AE0(n * 4);
        if (D_335D90.tbl == 0) {
            if (func_00212918() & 2) Func235DE0(D_002E3808);
            return 0;
        }
    }
    D_335D90.n = n;
    for (i = 0; i < n; i++) D_335D90.tbl[i] = 0;
    return 1;
}

extern "C" void func_00212C98(Rec *p) {
    s32 k;
    for (; p->m3; p = (Rec *)((u8 *)p + p->m3)) {
        k = p->m0;
        if (k >= 0 && !(D_335D90.n - 1 < k)) D_335D90.tbl[k] = p;
    }
}

extern "C" Rec *func_00212CF8(s32 i) {
    return func_00213348(i);
}

extern "C" const char *func_00212D10(s32 i) {
    Rec *p = func_00213348(i);
    return p ? p->m4 : D_002E3840;
}

INCLUDE_ASM("asm/nonmatchings/Unit212790", func_00212D40);

extern "C" s32 func_00212D70(const char *name) {
    s32 i;
    Rec *p;
    for (i = 0; i < D_335D90.n; i++) {
        p = func_00213348(i);
        if (p && !strcmp(p->m4, name)) return i;
    }
    return -1;
}

extern "C" s32 func_00212DF8(u32 idx, Ops *ops) {
    s32 r = 0;
    if (idx <= 256) {
        D_335D90.slots[idx].used = 1;
        D_335D90.slots[idx].ops.f0 = ops->f0 ? ops->f0 : func_002133C8;
        D_335D90.slots[idx].ops.f1 = ops->f1 ? ops->f1 : (s32 (*)(Rec *, s32, s32))func_002133D0;
        D_335D90.slots[idx].ops.f2 = ops->f2 ? ops->f2 : func_002133D8;
        r = 1;
    }
    return r;
}

extern "C" s32 func_00212E90(s32 id) {
    s32 i;
    Rec *p;
    if (func_00213348(id)) return id;
    for (i = 0; i < D_335D90.n; i++) {
        p = D_335D90.tbl[i];
        if (p && (p->mA & 1) && p->m8 == id) return p->m0;
    }
    return -1;
}

extern "C" s32 func_00212F20(s32 i) {
    Rec *p = func_00213348(i);
    if (p) return p->m10;
}

extern "C" s32 func_00212F48(s32 i, s32 a, s32 b) {
    Rec *p = func_00213348(i);
    if (p) return func_00213388(i)->f2(p, a, b);
}

extern "C" s32 func_00212FB8(s32 i, s32 a) {
    return func_002133E0(i, a, 1, -1);
}

extern "C" void func_00212FD8(s32 id, s32 a) {
    s32 i;
    Rec *p;
    if (func_00213348(id)) {
        func_00213558(id, a, 1, 0);
        return;
    }
    for (i = 0; i < D_335D90.n; i++) {
        p = D_335D90.tbl[i];
        if (p && RecF1(p) && p->m8 == id) func_00213558(p->m0, a, 1, 0);
    }
}

extern "C" s32 func_002130D8(s32 i, s32 a) {
    return func_002133E0(i, a, 0, -1);
}

extern "C" void func_002130F8(s32 id, s32 a) {
    s32 i;
    Rec *p;
    if (func_00213348(id)) {
        func_00213558(id, a, 0, 0);
        return;
    }
    for (i = 0; i < D_335D90.n; i++) {
        p = D_335D90.tbl[i];
        if (p && RecF1(p) && p->m8 == id) func_00213558(p->m0, a, 0, 0);
    }
}

extern "C" s32 func_002131F8(s32 i, s32 a) {
    return func_002133E0(i, 0, 1, a);
}

extern "C" s32 func_00213218(s32 i) {
    return func_00213558(i, 0, 1, 1);
}

INCLUDE_ASM("asm/nonmatchings/Unit212790", func_00213238);

extern "C" char *func_00213280(const char *s) {
    return strcpy(D_335D98, s);
}

extern "C" void func_002132A0(void) {
    s32 i;
    D_335D90.tbl = 0;
    D_335D90.n = 0;
    for (i = 0; i < 256; i++) D_335D90.slots[i].used = 0;
    D_335D98[0] = D_002E3840[0];
    func_00213898();
    func_002139E8();
    func_00213B90();
    return;
}

extern "C" void func_00213308(void) {
    if (D_335D90.tbl) {
        func_00212B30(D_335D90.tbl);
        return;
    }
}

extern "C" void func_00213340(void) {
}

extern "C" Rec *func_00213348(s32 i) {
    if (i >= 0 && !(D_335D90.n - 1 < i)) goto found;
    return 0;
found:
    return D_335D90.tbl[i];
}

extern "C" Ops *func_00213388(s32 i) {
    Rec *p = func_00213348(i);
    Ops *r = &D_002A61D8;
    if (p) r = &D_335D90.slots[p->m2].ops;
    return r;
}

extern "C" s32 func_002133C8(Rec *, s32, s32) {
    return 1;
}

extern "C" void func_002133D0(void) {
}

extern "C" s32 func_002133D8(Rec *, s32, s32) {
    return 0;
}

extern "C" s32 func_002133E0(s32 id, s32 a, s32 c, s32 b) {
    Rec *p = func_00213348(id);
    s32 n;
    s32 *buf;
    s32 i;
    if (!p) return 0;
    if (!RecF1(p)) {
        n = func_00213388(p->m0)->f2(p, 0, 0);
        buf = (s32 *)__builtin_alloca(n * 4);
        func_00213388(p->m0)->f2(p, (s32)buf, n);
        for (i = 0; i < n; i++) func_002133E0(buf[i], a, 0, -1);
        if (b >= 0) {
            p->m10 = b;
            p->mA |= 2;
        } else {
            ((s32 (*)(Rec *, s32))func_00213388(id)->f0)(p, a);
        }
        p->mA |= 1;
    }
    if (c) p->mB = 1;
    else p->mC++;
    return 1;
}

extern "C" s32 func_00213558(s32 id, s32 a, s32 c, s32 d) {
    Rec *p = func_00213348(id);
    s32 ret = -1;
    s32 n;
    s32 *buf;
    s32 i;
    if (!p) return -1;
    if (c) {
        p->mB = 0;
        p->mC = 0;
    } else {
        p->mC = CLAMPZ(p->mC - 1);
    }
    if (p->mC + p->mB <= 0 && RecF1(p)) {
        p->mA &= ~1;
        func_002136E8(id, a);
        ret = p->m10;
        if (d) {
            p->m10 = -1;
            p->mA &= ~2;
        } else {
            ((void (*)(Rec *, s32))func_00213388(id)->f1)(p, a);
        }
        n = func_00213388(p->m0)->f2(p, 0, 0);
        buf = (s32 *)__builtin_alloca(n * 4);
        func_00213388(p->m0)->f2(p, (s32)buf, n);
        for (i = 0; i < n; i++) func_00213558(buf[i], a, 0, 0);
    }
    return ret;
}

extern "C" void func_002136E8(s32 id, s32 a) {
    s32 i;
    s32 j;
    s32 n;
    s32 *buf;
    Rec *p;
    for (i = 0; i < D_335D90.n; i++) {
        p = D_335D90.tbl[i];
        if (p && RecF1(p)) {
            n = func_00213388(i)->f2(p, 0, 0);
            buf = (s32 *)__builtin_alloca(n * 4);
            func_00213388(i)->f2(p, (s32)buf, n);
            for (j = 0; j < n; j++) {
                if (buf[j] == id) {
                    func_00212FD8(p->m0, a);
                    break;
                }
            }
        }
    }
    func_001F15F0();
    func_00215F10(id);
    func_001F1610();
}

extern "C" void func_00213850(void) {
    s32 i;
    if (func_001F1180() == 0) func_00205F00();
    for (i = 0; i < 10000; i++) func_00212A58();
}

extern "C" void func_00213898(void) {
    func_00212DF8(0, (Ops *)D_002A61E8);
    return;
}

extern "C" s32 func_002138B8(s32 a, s32 wait) {
    Req r;
    if (wait) {
        r.m18 = a;
        func_00213C98(&r);
        while (!func_00213D68(&r)) func_00213850();
        func_00213CD0(&r);
    } else if (!func_00214A30(D_002A61F8, 0x48, a)) {
        return 0;
    }
    return 1;
}

extern "C" void func_00213930(Rec *p, s32 wait) {
    s32 r[16];
    s32 *q;
    func_00214B50(p);
    if (p->m10 >= 0) {
        if (wait) {
            r[11] = p->m10;
            func_00214080(r);
            while (!func_002140A0(r)) func_00213850();
            ((void (*)(void *))func_00214098)(r);
        } else {
            q = (s32 *)func_00214A30(D_002A6208, 0x38, 0);
            if (!q) return;
            q[11] = p->m10;
        }
    }
    p->m10 = -1;
    p->mA &= ~2;
}

extern "C" void func_002139E8(void) {
    func_00212DF8(1, (Ops *)D_002A6218);
    return;
}

extern "C" s32 func_00213A08(s32 a, s32 wait) {
    s32 r[20];
    if (wait) {
        r[6] = a;
        func_00214180(r);
        while (!func_00214238(r)) func_00213850();
        func_002141B8(r);
    } else if (!func_00214A30(D_002A6228, 0x44, a)) {
        return 0;
    }
    return 1;
}

extern "C" void func_00213A80(Rec *p, s32 wait) {
    Rec *r[16];
    s32 *q;
    func_00214B50(p);
    if (p->m10 >= 0) {
        if (wait) {
            r[6] = p;
            func_00214528(r);
            while (!func_00214548(r)) func_00213850();
            ((void (*)(void *))func_00214540)(r);
        } else {
            q = (s32 *)func_00214A30(D_002A6238, 0x34, 0);
            if (!q) return;
            q[11] = p->m10;
        }
    }
    p->m10 = -1;
    p->mA &= ~2;
}

extern "C" s16 func_00213B38(Req40 *p, s32 *out, s32 max) {
    s32 i;
    for (i = 0; i < p->m1C && i < max; i++) *out++ = p->m1A + i;
    return p->m1C;
}

extern "C" void func_00213B90(void) {
    func_00212DF8(2, (Ops *)D_002A6248);
    return;
}

extern "C" s32 func_00213BB0(s32 a, s32 wait) {
    s32 r[16];
    if (wait) {
        r[6] = a;
        func_00214610(r);
        while (!func_002146B0(r)) func_00213850();
        func_00214640(r);
    } else if (!func_00214A30(D_002A6258, 0x40, a)) {
        return 0;
    }
    return 1;
}

extern "C" void func_00213C28(Rec *p) {
    s32 h;
    if (p->mA & 2) {
        h = func_0020E2F0(p->m10);
        func_0020E1B8(p->m10);
        if (h) func_00219950(h);
        p->m10 = -1;
        p->mA &= ~2;
    }
}

extern "C" void func_00213C98(Req *r) {
    ReqHdr *h = &r->hdr;
    h->m0 = 0;
    h->m2 = 0;
    h->m1 = 6;
    r->m2C = -1;
    r->m30 = 0;
    r->m34 = (void *)0;
    r->m38 = (void *)0;
    r->m3C = (void *)0;
    r->m40 = -1;
    r->m44 = 0;
}

extern "C" void func_00213CD0(Req *r) {
    if (r->m44 == 0) {
        if (r->m2C >= 0) func_0022DDE8(r->m2C);
        if (r->m34) func_00212B30(r->m34);
        if (r->m40 >= 0) func_00208670(r->m40, 1);
        if (r->m38) func_00219970(r->m38);
        if (r->m3C) {
            func_00219990(r->m3C);
            return;
        }
    }
}

extern "C" s32 func_00213D68(Req *r) {
    ReqHdr *h = &r->hdr;
    Rec *p = (Rec *)r->m18;
    PT_BEGIN(h)
    PT_WAIT_WHILE(h, 0x476, OpenSnd((ReqB *)r, p) < 0)
    PT_WAIT_WHILE(h, 0x47A, func_0022E2C8(r->m2C, 1) == 1)
        r->m30 = func_0022E230(r->m2C, 0, 2);
        func_0022E230(r->m2C, 0, 0);
    PT_WAIT_WHILE(h, 0x480, (r->m34 = (void *)func_00212B80((void *)r->m30)) == 0)
        func_0022DF28(r->m2C, r->m34, r->m30);
    PT_WAIT_WHILE(h, 0x484, func_0022E2C8(r->m2C, 1) == 1)
        func_0022DDE8(r->m2C);
        r->m2C = -1;
    PT_WAIT_WHILE(h, 0x48D, (r->m38 = func_00219880(p->m18, func_002089E0(r->m34))) == 0)
    PT_WAIT_WHILE(h, 0x48F, (r->m3C = func_002198E8(p->m1A, func_00208B00(r->m34))) == 0)
    PT_WAIT_WHILE(h, 0x495, (r->m40 = func_00208260(-1, r->m34, r->m38, r->m3C)) < 0)
    PT_WAIT_WHILE(h, 0x497, func_002087E8(r->m40, 0) == 1)
        func_00212BA8(r->m34);
        r->m34 = 0;
        p->mA |= 2;
        p->m10 = r->m40;
        r->m44 = 1;
        return 1;
    PT_END(h)
}

extern "C" void func_00214080(void *vr) {
    Req *r = (Req *)vr;
    ReqHdr *h = &r->hdr;
    h->m1 = 6;
    h->m2 = 0;
    h->m0 = 0;
}

extern "C" void func_00214098(void) {
}

extern "C" s32 func_002140A0(void *vr) {
    Req *r = (Req *)vr;
    ReqHdr *h = &r->hdr;
    PT_BEGIN(h)
        r->m30 = func_002088B8(r->m2C);
        r->m34 = (void *)func_00208948(r->m2C);
    PT_WAIT_WHILE(h, 0x4C5, func_00208670(r->m2C, 0) == 1)
        func_00219970((void *)r->m30);
        func_00219990(r->m34);
        return 1;
    PT_END(h)
}

extern "C" void func_00214180(void *vr) {
    ReqB *r = (ReqB *)vr;
    ReqHdr *h = &r->hdr;
    h->m0 = 0;
    h->m2 = 0;
    h->m1 = 6;
    r->m2C = -1;
    r->m30 = 0;
    r->m34 = 0;
    r->m38 = 0;
    r->m3C = -1;
    r->m40 = 0;
}

extern "C" void func_002141B8(void *vr) {
    ReqB *r = (ReqB *)vr;
    if (r->m40 == 0) {
        if (r->m2C >= 0) func_0022DDE8(r->m2C);
        if (r->m34) func_00212BA8(r->m34);
        if (r->m3C >= 0) func_00208E48(r->m3C, 1);
        if (r->m38) {
            func_00219970(r->m38);
            return;
        }
    }
}

extern "C" s32 func_00214238(void *vr) {
    ReqB *r = (ReqB *)vr;
    ReqHdr *h = &r->hdr;
    Rec *p = (Rec *)r->m18;
    s32 i;
    PT2_BEGIN(h)
    PT2_WAIT_WHILE(h, 0x51A, OpenSnd(r, p) < 0)
    PT2_WAIT_WHILE(h, 0x51E, func_0022E2C8(r->m2C, 1) == 1)
        r->m30 = func_0022E230(r->m2C, 0, 2);
        func_0022E230(r->m2C, 0, 0);
    PT2_WAIT_WHILE(h, 0x524, (r->m34 = (void *)func_00212B80((void *)r->m30)) == 0)
        func_0022DF28(r->m2C, r->m34, r->m30);
    PT2_WAIT_WHILE(h, 0x528, func_0022E2C8(r->m2C, 1) == 1)
        func_0022DDE8(r->m2C);
        r->m2C = -1;
    PT2_WAIT_WHILE(h, 0x531, (r->m38 = func_00219880(p->m18, func_002090E8(r->m34))) == 0)
    PT2_WAIT_WHILE(h, 0x537, (r->m3C = func_00208B30(-1, r->m34, r->m38)) < 0)
        func_00212BA8(r->m34);
        r->m34 = 0;
    case 0x548:
        for (i = 0; i < p->m1C; i++) {
            if (!func_00213238(p->m1A + i)) PT2_YIELD(h, 0x548)
        }
        for (i = 0; i < p->m1C; i++) func_00208F98(r->m3C, i, func_00212F20(p->m1A + i));
        p->mA |= 2;
        p->m10 = r->m3C;
        r->m40 = 1;
        return 1;
    PT2_END(h)
}

extern "C" void func_00214528(void *vr) {
    Req *r = (Req *)vr;
    ReqHdr *h = &r->hdr;
    h->m1 = 6;
    h->m2 = 0;
    h->m0 = 0;
}

extern "C" void func_00214540(void) {
}

extern "C" s32 func_00214548(void *vr) {
    Req *r = (Req *)vr;
    ReqHdr *h = &r->hdr;
    PT_BEGIN(h)
        r->m30 = func_00209058(r->m2C);
    PT_WAIT_WHILE(h, 0x57B, func_00208E48(r->m2C, 0) == 1)
        func_00219970((void *)r->m30);
        return 1;
    PT_END(h)
}

extern "C" void func_00214610(void *vr) {
    ReqE *r = (ReqE *)vr;
    ReqHdr *h = &r->hdr;
    h->m0 = 0;
    h->m2 = 0;
    h->m1 = 6;
    r->m2C = -1;
    r->m30 = 0;
    r->m34 = 0;
    r->m38 = -1;
    r->m3C = 0;
}

extern "C" void func_00214640(void *vr) {
    ReqE *r = (ReqE *)vr;
    if (r->m3C == 0) {
        if (r->m2C >= 0) func_0022DDE8(r->m2C);
        if (r->m34) func_00219950(r->m34);
        if (r->m38 >= 0) {
            func_0020E1B8(r->m38);
            return;
        }
    }
}

extern "C" s32 func_002146B0(void *vr) {
    ReqE *r = (ReqE *)vr;
    ReqHdr *h = &r->hdr;
    RecW *p = (RecW *)r->m18;
    PT_BEGIN(h)
    PT_WAIT_WHILE(h, 0x5C7, OpenSnd((ReqB *)r, (Rec *)p) < 0)
    PT_WAIT_WHILE(h, 0x5CB, func_0022E2C8(r->m2C, 1) == 1)
        r->m30 = func_0022E230(r->m2C, 0, 2);
        func_0022E230(r->m2C, 0, 0);
    PT_WAIT_WHILE(h, 0x5D1, (r->m34 = func_00219818(p->m1C, r->m30)) == 0)
        func_0022DF28(r->m2C, (void *)r->m34, r->m30);
    PT_WAIT_WHILE(h, 0x5D5, func_0022E2C8(r->m2C, 1) == 1)
        func_0022DDE8(r->m2C);
        r->m2C = -1;
    PT_WAIT_WHILE(h, 0x5DE, (r->m38 = func_0020DFD8(0, r->m34)) < 0)
        if (p->m18 && strcmp(p->m18, D_002E3840)) {
            func_0022DCE0();
            func_0022DC90(0);
            func_0022DC90(D_335D98);
            func_0020E210(r->m38, p->m18);
            func_0022DD00();
        }
        p->mA |= 2;
        p->m10 = r->m38;
        r->m3C = 1;
        return 1;
    PT_END(h)
}
