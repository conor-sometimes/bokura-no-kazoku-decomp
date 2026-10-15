#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
struct Ent12 { Ent12 *next; u8 m4; u8 m5; u8 m6; u8 pad7; s32 m8; };
struct S331B50 { Ent12 e[64]; Ent12 *active; Ent12 *free; };
extern S331B50 D_331B50;
struct Mark { Mark *next; u32 pos; u8 m8; u8 m9; u8 mA; u8 mB; s32 mC; s32 (*m10)(s32, void *); s32 m14; };
struct Mark10 { Mark10 *next; u32 pos; u8 m8; u8 m9; u8 mA; u8 mB; s32 mC; };
struct MemStrm { s32 m0; u8 used; u8 eof; u8 m6; u8 m7; s32 base; u32 pos; u32 size; Mark10 *m14; Mark *m18; s32 m1C; };
struct S331E58 { MemStrm m[64]; Mark n18[256]; Mark *free18; Mark10 n10[256]; Mark10 *free10; };
extern S331E58 D_331E58;
extern "C" void func_001F15F0(void);
extern "C" void func_001F1610(void);
extern "C" s32 func_00211428(void);
void Func235DE0(const char *, ...);
extern const char D_002E3538[];
extern const char D_002E3570[];
extern "C" s32 func_0022DD98(const char *, s32, s32, s32);
extern "C" s32 func_00210A38(s32, u32);
extern "C" void func_0022DE48(s32);
extern "C" void func_0022DDE8(s32);
extern "C" void func_00210B18(u32);
extern "C" void func_0022E230(s32, s32, s32);
extern "C" void func_0022E450(s32, s32);
extern "C" void func_00210B88(u32, u32);
extern "C" void func_0022E398(s32);
extern "C" s32 func_00210E70(u32, void *, s32, s32);
extern "C" void func_0022E7C8(s32);
extern "C" s32 func_00211078(u32, void *, s32);
extern "C" s32 func_0022E880(s32);
extern "C" s32 func_00211260(u32, s32 *, s32, s32);
extern "C" s32 func_0022E5A8(s32);
extern "C" u32 func_00211300(u32);
extern "C" void func_0022E618(s32);
extern "C" void func_00210C58(u32, s32);
extern "C" s32 func_0022E4C8(s32);
extern "C" s32 func_00210DF8(s32);
extern "C" s32 func_0022DEA8(s32);
extern "C" u8 func_00210E38(u32);
extern "C" void func_0022E2C8(s32, s32);
extern "C" s32 func_00210BD8(u32);

struct Pcm { Pcm *next; s32 m4; s32 m8; s32 mC; s32 m10; s32 m14; s32 m18; };
struct S334E60 { Pcm e[64]; Pcm *active; Pcm *free; };
extern S334E60 D_334E60;
extern s32 D_002A618C;
extern "C" void func_0020FF70(void);
extern "C" void func_0020EA70(void);
extern "C" void func_0020FB90(void);
extern "C" s32 func_00206088(void);
extern "C" void func_00206030(s32);
extern "C" s32 func_0020FD00(u32, const char *, void *);
extern const char D_002E35A8[];
extern const char D_002E35B8[];
extern const char D_002E35C8[];
extern u8 D_002A6190[];
extern u8 D_002A61B0[];
extern "C" void func_0020FFC0(void);
extern "C" void func_0020EAB0(void);
extern "C" void func_0020FC18(void);
extern "C" void func_002109F0(void);
extern "C" void func_00210A30(void);
extern "C" void func_00210010(void);
extern "C" void func_0020EAB8(void);
extern "C" void func_0020FC60(void);
extern "C" s32 func_001F1180(void);
extern "C" s32 func_001F1200(void);
extern "C" s32 func_001F0C08(void);
extern "C" void func_00211C48(s32, s32);
extern "C" void *func_0020B740(s32);
extern "C" void func_0020FE20(void *, s32);
extern "C" s32 func_0020FEC0(void *, s32);
extern "C" void func_00210958(void);

struct Seq20 { Seq20 *next; s32 m4; s32 m8; s32 mC; s32 m10; s32 m14; s32 m18; s32 m1C; };
struct S335568 { Seq20 e[64]; Seq20 *active; Seq20 *free; };
extern S335568 D_335568;
extern "C" void func_002101B0(s32, s32);
extern "C" void func_0020AF80(s32);
extern "C" void func_00210880(u32);
extern "C" s32 func_002108E0(u32, s32);
extern "C" void func_00212708(s32, s32);
extern "C" void *func_0020CF90(s32);

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define CLAMPZ(x) ((x) < 0 ? 0 : (x))
extern "C" s32 func_0022E560(s32);
extern "C" s32 func_0022E518(s32);
struct MarkData { u32 pos; u8 m8; u8 m9; u8 mA; u8 mB; s32 mC; s32 (*m10)(s32, void *); s32 m14; };
struct Mark10Data { u32 pos; u8 m8; u8 m9; u8 mA; u8 mB; s32 mC; };
extern "C" void func_0020C100(s32);
// @decl-end

extern "C" s32 func_00210070(s32 type, const char *name, s32 a, s32 b) {
    Ent12 *e;
    s32 r;
    s32 h;
    func_001F15F0();
    e = D_331B50.free;
    if (e == 0) {
        if (func_00211428() & 1) Func235DE0(D_002E3538);
        r = -1;
        goto out;
    }
    e->m6 = type;
    e->m5 = 1;
    switch (e->m6) {
    case 0:
        h = func_0022DD98(name, a, b, (b / 2) & ~0xF);
        e->m8 = h;
        if (h < 0) { r = -1; goto out; }
        break;
    case 1:
        h = func_00210A38(a, b);
        e->m8 = h;
        if (h < 0) goto fail;
        break;
    }
    D_331B50.free = e->next;
    e->next = D_331B50.active;
    D_331B50.active = e;
    r = e->m4;
    goto out;
fail:
    r = -1;
out:
    func_001F1610();
    return r;
}

extern "C" void func_002101B0(s32 id, s32 mode) {
    Ent12 **pp;
    Ent12 *e;
    func_001F15F0();
    pp = &D_331B50.active;
    for (e = *pp; e; e = e->next) {
        if (e->m4 == id) {
            *pp = e->next;
            e->m5 = 0;
            break;
        }
        pp = &e->next;
    }
    func_001F1610();
    if (e == 0) return;
    switch (e->m6) {
    case 0:
        if (mode) func_0022DE48(e->m8);
        else func_0022DDE8(e->m8);
        break;
    case 1:
        func_00210B18(e->m8);
        break;
    }
    func_001F15F0();
    e->next = D_331B50.free;
    D_331B50.free = e;
    func_001F1610();
    return;
}

extern "C" void func_002102B0(u32 i, u32 pos) {
    Ent12 *e;
    if (i < 64 && (e = &D_331B50.e[i])->m5) {
        do {
            switch (e->m6) {
            case 0:
                func_0022E230(e->m8, pos, 0);
                func_0022E450(e->m8, 0);
                break;
            case 1:
                func_00210B88(e->m8, pos);
                break;
            }
        } while (0);
    }
}

extern "C" void func_00210340(u32 i) {
    Ent12 *e;
    if (i < 64 && (e = &D_331B50.e[i])->m5) {
        do {
            switch (e->m6) {
            case 0:
            default:
                func_0022E398(e->m8);
                break;
            case 1:
                ((s32 (*)(u32))func_00210E70)(e->m8);
                break;
            }
        } while (0);
    }
}

extern "C" void func_002103B0(u32 i) {
    Ent12 *e;
    if (i < 64 && (e = &D_331B50.e[i])->m5) {
        do {
            switch (e->m6) {
            case 0:
            default:
                func_0022E7C8(e->m8);
                break;
            case 1:
                ((s32 (*)(u32))func_00211078)(e->m8);
                break;
            }
        } while (0);
    }
}

extern "C" s32 func_00210420(u32 i) {
    Ent12 *e;
    s32 r;
    if (i < 64 && (e = &D_331B50.e[i])->m5) goto found;
    return 0;
found:
    switch (e->m6) {
    case 0:
    default:
        r = func_0022E880(e->m8);
        break;
    case 1:
        r = ((s32 (*)(u32))func_00211260)(e->m8);
        break;
    }
    return r;
}

extern "C" s32 func_00210498(u32 i, s32 n) {
    Ent12 *e;
    if (i < 64 && (e = &D_331B50.e[i])->m5) goto found;
    return 0;
found:
    switch (e->m6) {
    case 0:
    default:
        n = CLAMPZ(MIN(n, func_0022E5A8(e->m8)));
        n = CLAMPZ(MIN(n, func_0022E560(e->m8) - func_0022E518(e->m8)));
        break;
    case 1:
        n = CLAMPZ(MIN(n, func_00210BD8(e->m8)));
        break;
    }
    return n;
}

extern "C" s32 func_00210670(u32 i) {
    Ent12 *e;
    s32 r;
    if (i < 64 && (e = &D_331B50.e[i])->m5) goto found;
    return 0;
found:
    switch (e->m6) {
    case 0:
    default:
        r = func_0022E5A8(e->m8);
        break;
    case 1:
        r = func_00211300(e->m8);
        break;
    }
    return r;
}

extern "C" void func_002106E8(u32 i, s32 a) {
    Ent12 *e;
    if (i < 64 && (e = &D_331B50.e[i])->m5) {
        do {
            switch (e->m6) {
            case 0:
            default:
                func_0022E618(e->m8);
                break;
            case 1:
                ((void (*)(u32))func_00210C58)(e->m8);
                break;
            }
        } while (0);
    }
}

extern "C" s32 func_00210758(u32 i) {
    Ent12 *e;
    s32 r;
    if (i < 64 && (e = &D_331B50.e[i])->m5) goto found;
    return 0;
found:
    switch (e->m6) {
    case 0:
    default:
        r = func_0022E4C8(e->m8);
        break;
    case 1:
        r = func_00210DF8(e->m8);
        break;
    }
    return r;
}

extern "C" s32 func_002107D0(u32 i) {
    Ent12 *e;
    s32 r;
    if (i < 64 && (e = &D_331B50.e[i])->m5) goto found;
    return 0;
found:
    switch (e->m6) {
    case 0:
    default:
        r = 0;
        if (func_0022E5A8(e->m8) == 0) {
            if (func_0022DEA8(e->m8) & 8) r = 1;
        }
        break;
    case 1:
        r = func_00210E38(e->m8);
        break;
    }
    return r;
}

extern "C" void func_00210880(u32 i) {
    Ent12 *e;
    if (i < 64 && (e = &D_331B50.e[i])->m5) {
        do {
            switch (e->m6) {
            case 0:
            default:
                ((void (*)(s32))func_0022E450)(e->m8);
                break;
            case 1:
                break;
            }
        } while (0);
    }
}

extern "C" s32 func_002108E0(u32 i, s32 a) {
    Ent12 *e;
    s32 r;
    if (i < 64 && (e = &D_331B50.e[i])->m5) goto found;
    return 0;
found:
    switch (e->m6) {
    case 0:
    default:
        r = ((s32 (*)(s32, s32))func_0022E2C8)(e->m8, a == 0);
        break;
    case 1:
        r = 0;
        break;
    }
    return r;
}

extern "C" void func_00210958(void) {
    s32 i;
    s32 j;
    s32 k;
    Mark *n;
    Mark10 *m;
    MemStrm *s = D_331E58.m;
    for (i = 0; i < 64; i++, s++) s->used = 0;
    D_331E58.free18 = 0;
    n = D_331E58.n18;
    for (j = 0; j < 256; j++, n++) {
        n->next = D_331E58.free18;
        D_331E58.free18 = n;
    }
    D_331E58.free10 = 0;
    m = D_331E58.n10;
    for (k = 0; k < 256; k++, m++) {
        m->next = D_331E58.free10;
        D_331E58.free10 = m;
    }
}

extern "C" void func_002109F0(void) {
    s32 i;
    for (i = 0; i < 64; i++) func_00210B18(i);
}

extern "C" void func_00210A30(void) {
}

extern "C" s32 func_00210A38(s32 base, u32 size) {
    s32 i;
    MemStrm *m;
    func_001F15F0();
    for (i = 1, m = &D_331E58.m[1]; i < 64; i++, m++) {
        if (!m->used) break;
    }
    func_001F1610();
    if (i == 64) {
        if (func_00211428() & 1) Func235DE0(D_002E3570);
        return -1;
    }
    m->base = base;
    m->size = size;
    m->m1C = 0;
    m->eof = 0;
    m->pos = 0;
    m->m14 = 0;
    m->m18 = 0;
    m->used = 1;
    return i;
}

extern "C" void func_00210B18(u32 i) {
    MemStrm *m = &D_331E58.m[i];
    if (i < 64 && m->used) {
        func_00210E70(i, 0, 0, 0);
        func_00211078(i, 0, 0);
        m->used = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/Unit210070", func_00210B88);

extern "C" s32 func_00210BD8(u32 i) {
    MemStrm *m;
    Mark *n;
    u32 end;
    if (i < 64 && (m = &D_331E58.m[i])->used) goto found;
    return -1;
found:
    n = m->m18;
    end = m->size;
    if (n) {
        for (; n; n = n->next) {
            if (m->pos < n->pos) {
                end = n->pos;
                break;
            }
        }
    }
    return end - m->pos;
}

INCLUDE_ASM("asm/nonmatchings/Unit210070", func_00210C58);

INCLUDE_ASM("asm/nonmatchings/Unit210070", func_00210DF8);

INCLUDE_ASM("asm/nonmatchings/Unit210070", func_00210E38);

extern "C" s32 func_00210E70(u32 i, void *vsrc, s32 n, s32 x) {
    MarkData *src = (MarkData *)vsrc;
    MemStrm *m;
    Mark *p;
    Mark **pp;
    Mark *q;
    s32 k;
    Mark *d;
    if (i < 64 && (m = &D_331E58.m[i])->used) goto found;
    return 0;
found:
    func_001F15F0();
    d = m->m18;
    if (d) {
        for (; d; d = m->m18) {
            m->m18 = d->next;
            d->next = D_331E58.free18;
            D_331E58.free18 = d;
        }
    }
    for (k = 0; k < n && D_331E58.free18; k++) {
        p = D_331E58.free18;
        D_331E58.free18 = p->next;
        pp = &m->m18;
        for (q = *pp; q && !(src[k].pos < q->pos); q = *pp) pp = &q->next;
        p->next = q;
        *pp = p;
        *(MarkData *)&p->pos = src[k];
    }
    func_001F1610();
    m->m1C = x;
    return k;
}

extern "C" void func_00211010(u32 i, s32 k, s32 v) {
    MemStrm *m;
    Mark *n;
    if (i < 64 && (m = &D_331E58.m[i])->used) {
        for (n = m->m18; n; n = n->next) {
            if (n->m9 == k) n->m8 = v;
        }
    }
}

extern "C" s32 func_00211078(u32 i, void *vsrc, s32 n) {
    Mark10Data *src = (Mark10Data *)vsrc;
    MemStrm *m;
    Mark10 *p;
    Mark10 **pp;
    Mark10 *q;
    s32 k;
    Mark10 *d;
    if (i < 64 && (m = &D_331E58.m[i])->used) goto found;
    return 0;
found:
    func_001F15F0();
    d = m->m14;
    if (d) {
        for (; d; d = m->m14) {
            m->m14 = d->next;
            d->next = D_331E58.free10;
            D_331E58.free10 = d;
        }
    }
    for (k = 0; k < n && D_331E58.free10; k++) {
        p = D_331E58.free10;
        D_331E58.free10 = p->next;
        pp = &m->m14;
        for (q = *pp; q && !(src[k].pos < q->pos); q = *pp) pp = &q->next;
        p->next = q;
        *pp = p;
        *(Mark10Data *)&p->pos = src[k];
    }
    func_001F1610();
    return k;
}

extern "C" void func_002111F8(u32 i, s32 k, s32 v) {
    MemStrm *m;
    Mark10 *n;
    if (i < 64 && (m = &D_331E58.m[i])->used) {
        for (n = m->m14; n; n = n->next) {
            if (n->m9 == k) n->m8 = v;
        }
    }
}

extern "C" s32 func_00211260(u32 i, s32 *out, s32 max, s32 len) {
    MemStrm *m;
    Mark10 *n;
    s32 cnt;
    if (i < 64 && (m = &D_331E58.m[i])->used) goto found;
    return 0;
found:
    n = m->m14;
    cnt = 0;
    if (n) {
        for (; n; n = n->next) {
            if (n->m8 == 1 && n->pos >= m->pos && n->pos < m->pos + len) {
                if (cnt < max) {
                    out[0] = n->pos - m->pos;
                    out[1] = n->mC;
                }
                cnt++;
                out += 2;
            }
        }
    }
    return cnt;
}

INCLUDE_ASM("asm/nonmatchings/Unit210070", func_00211300);

extern "C" void func_00211338(void) {
    func_00210958();
    func_0020FF70();
    func_0020EA70();
    func_0020FB90();
    func_00206030(func_00206088() & ~4);
    func_0020FD00(1, D_002E35A8, D_002A6190);
    func_0020FD00(0, D_002E35B8, D_002A61B0);
    return;
}

extern "C" void func_002113B0(void) {
    func_0020FFC0();
    func_0020EAB0();
    func_0020FC18();
    func_002109F0();
    return;
}

extern "C" void func_002113E0(void) {
    func_00210A30();
    func_00210010();
    func_0020EAB8();
    func_0020FC60();
    return;
}

extern "C" s32 func_00211410(s32 v) {
    s32 old = D_002A618C;
    D_002A618C = v;
    return old;
}

extern "C" s32 func_00211428(void) {
    return D_002A618C;
}

extern "C" void func_00211438(const char *name) {
    if (func_001F1180() == 1 && !func_001F1200() && !func_001F0C08() && (func_00211428() & 2)) {
        Func235DE0(D_002E35C8, name);
        return;
    }
}

extern "C" void func_002114B8(void) {
    s32 i;
    Pcm *e;
    D_334E60.active = 0;
    D_334E60.free = 0;
    e = D_334E60.e;
    for (i = 0; i < 64; i++, e++) {
        e->next = D_334E60.free;
        D_334E60.free = e;
        e->m4 = i;
    }
}

extern "C" void func_00211500(void) {
    Pcm *e;
    while ((e = D_334E60.active) != 0) func_00211C48(e->m4, 0);
}

extern "C" void func_00211550(s32 a, s32 b) {
    func_0020FE20(func_0020B740(a), b);
    return;
}

extern "C" s32 func_00211580(void *a, s32 *p) {
    return func_0020FEC0(a, p[4]);
}

INCLUDE_ASM("asm/nonmatchings/Unit210070", func_00211598);

INCLUDE_ASM("asm/nonmatchings/Unit210070", func_002117D8);

extern "C" void func_00211C48(s32 id, s32 x) {
    Pcm **pp;
    Pcm *e;
    pp = &D_334E60.active;
    while ((e = *pp) != 0) {
        if (e->m4 == id) {
            *pp = e->next;
            e->next = D_334E60.free;
            D_334E60.free = e;
            if (e->mC >= 0) func_002101B0(e->mC, x);
            if (e->m10 >= 0) func_0020AF80(e->m10);
            break;
        }
        pp = &e->next;
    }
}

extern "C" s32 func_00211CD0(s32 i) {
    return D_334E60.e[i].m10;
}

extern "C" void func_00211CF0(s32 i) {
    func_00210880(D_334E60.e[i].mC);
    return;
}

extern "C" s32 func_00211D20(s32 i, s32 a) {
    return func_002108E0(D_334E60.e[i].mC, a);
}

extern "C" void func_00211D50(void) {
    s32 i;
    Seq20 *e;
    D_335568.active = 0;
    D_335568.free = 0;
    e = D_335568.e;
    for (i = 0; i < 64; i++, e++) {
        e->next = D_335568.free;
        D_335568.free = e;
        e->m4 = i;
    }
}

extern "C" void func_00211D98(void) {
    Seq20 *e;
    while ((e = D_335568.active) != 0) func_00212708(e->m4, 0);
}

extern "C" void func_00211DE8(s32 a, s32 b) {
    func_0020FE20(func_0020CF90(a), b);
    return;
}

extern "C" s32 func_00211E18(void *a, s32 *p) {
    return func_0020FEC0(a, p[4]);
}

INCLUDE_ASM("asm/nonmatchings/Unit210070", func_00211E30);

INCLUDE_ASM("asm/nonmatchings/Unit210070", func_00212210);

extern "C" void func_00212708(s32 id, s32 x) {
    Seq20 **pp;
    Seq20 *e;
    pp = &D_335568.active;
    while ((e = *pp) != 0) {
        if (e->m4 == id) {
            *pp = e->next;
            e->next = D_335568.free;
            D_335568.free = e;
            if (e->mC >= 0) func_002101B0(e->mC, x);
            if (e->m10 >= 0) func_0020C100(e->m10);
            break;
        }
        pp = &e->next;
    }
}
