#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CPushBuf.h"
extern s32 D_002BA218[];
extern s32 D_002BA244;
struct CSndDef { s32 m0; s32 m4; s32 m_type; s32 m_num; };
struct CSndEnt { CSndDef *m_def; s32 m_idx; char m_name[0x20]; s32 m28; s32 m2C; s32 m30; s32 m34; s32 m38; };
struct CSndSeq { s32 m0; const char *m_name; u8 pad8[0x14]; };
struct CPk8 { u64 v __attribute__((packed)); };
extern const char D_002E7748[];
extern const char D_002E7750[];
struct CSndPrm {
    u8 m0, m1, m2, m3, m4;
    s8 m5;
    s16 m6, m8, mA;
    f32 mC, m10, m14, m18;
    f32 m1C;
    s16 m20, m22, m24;
    u8 pad26[2];
    s32 m28, m2C;
    s16 m30, m32;
    u8 m34, m35;
    u8 pad36[0xA];
};
class CSndWork { public: void Func25D130(CSndPrm *p); void Func25C438(struct CSndUnitN *u); };
extern u8 D_41A788[];
void *Func25C220();
void Func25BD60(CSndPrm *p);

struct CSndWorkM { u8 pad[0x6C]; };
class CSndMgr;
typedef s32 (CSndMgr::*CSndSaveFn)(char *buf);
extern const CSndSaveFn D_002E7748f __asm__("D_002E7748");
extern const CSndSaveFn D_002E7750f __asm__("D_002E7750");
class ISndMgr {
public:
    virtual void Release();                          // [0]
};
class CSndMgr : public ISndMgr {
public:
    CSndEnt *Func25A738(s32 i, const char *name);
    void Func25A278();
    CSndMgr();
    virtual void Func1();                            // [1] inline in retail (never defined here: key method)
    virtual void Func2();
    virtual void Func3();
    virtual void Func4();
    virtual void Func5();
    virtual void Func6();
    virtual void Func7();
    virtual void Func8();
    virtual void Func9();
    virtual void Func10();
    virtual void Func11();
    virtual void Func12();
    virtual void Func13();
    virtual void Func14();
    virtual void Func15();
    virtual s32 Func25A338(CSndDef *defs);           // [16] (retail key method)
    virtual void Func25A418();                       // [17]
    virtual void Func18();                           // [18]
    virtual s32 Func25A538(s32 i);                   // [19]
    virtual s32 Func25A568(s32 i);                   // [20]
    virtual char *Func25A590(s32 i);                 // [21]
    virtual void Func25A5C0(s32 i, s32 v);           // [22]
    virtual s32 Func25A600(s32 i);                   // [23]
    virtual s32 Func25A628(const char *name, s32 i); // [24]
    virtual s32 Func25A908(s32 a, const char *name, void *d, s32 b, s32 c); // [25]
    virtual s32 Func25AAD0(s32 a, const char *name, void *d, s32 b); // [26]
    virtual s32 Func25AC38(s32 i);                   // [27]
    virtual s32 Func25AE80(s32 a, const char *name, s32 b, s32 c, void *src, s32 n); // [28]
    virtual s32 Func25AF70(s32 a, const char *name, s32 b, void *src, s32 n); // [29]
    virtual s32 Func25B048(s32 i);                   // [30]
    virtual void Func25B230(s32 i);                  // [31]
    virtual void Func25B460(s32 i, s32 b);           // [32]
    virtual void Func25B608();                       // [33]
    virtual void Func34();                           // [34]
    virtual s32 Func25B698(CSndSeq *seqs);           // [35]
    virtual void Func25B758();                       // [36]
    virtual void Func37();                           // [37]
    virtual CSndSeq *Func25B798(s32 i);              // [38]
    virtual CSndSeq *Func25B7D8(const char *name);   // [39]
    virtual void Func25B860(s32 i, s32 v);           // [40]
    virtual s16 Func25B890(s32 i);                   // [41]
    virtual s32 Func25BAB0(s32 x);                   // [42]
    virtual s32 Func25BAD8(s32 x);                   // [43]
    virtual void Func25BB00();                       // [44]
    virtual ~CSndMgr();                              // [45]
    virtual s32 Func25B8C8(char *buf);               // [46]
    virtual s32 Func25B980(s32 i);                   // [47]
    CSndEnt *Func25A478(s32 i);
    CSndEnt *Func25A4D8(s32 i);
    s32 Func25BB30(CSndSaveFn fn, s32 x);
    s32 Func25BC90(CSndSaveFn fn, s32 x);
    CSndDef *m_defs;          // 0x4
    s32 m_unk8;
    CSndSeq *m_seqs;          // 0xC
    s32 m_numSeqs;            // 0x10
    CSndEnt *m_ents;          // 0x14
    s32 m_numEnts;            // 0x18
    union { s32 m_defValW; u16 m_defVal; }; // 0x1C
    s16 *m_vals;              // 0x20
    s32 m_unk24;
    s32 m_unk28;
    s32 m_unk2C;
    s32 m_unk30;
    void *(*m_alloc)(s32 n); // 0x34
    void (*m_free)(void *p); // 0x38
    CSndWorkM m_w3C;
    CSndWorkM m_wA8;
    CSndWorkM m_w114;
};
s32 Func25ADD0(CPushBuf *p, s32 b, s32 c);
void Func25BDE8(CSndPrm *d, const CSndPrm *s);

extern "C" int strcmp(const char *a, const char *b);
extern "C" void *memcpy(void *d, const void *s, unsigned int n);
extern s32 PushBufFunc248EE0(CPushBuf *p, void *d) __asm__("Func248EE0__8CPushBufPv");
void *Func245D00(s32 n);
s32 Func25AD78(CPushBuf *p, void *dst, void *src, s32 n);
extern void (*D_002B91B0)(void *p);
extern "C" s32 func_00209058(s32 a);
extern "C" void func_00208E48(s32 a, s32 b);
extern "C" void func_00219970(s32 h);
extern "C" void *func_0020E2F0(s32 a);
extern "C" void func_0020E1B8(s32 a);
extern "C" void func_00219950(void *p);
extern "C" s32 func_002088B8(s32 a);
extern "C" s32 func_00208948(s32 a);
extern "C" void func_00208670(s32 a, s32 b);
extern "C" void func_00219990(s32 h);

extern const char D_002E7708[];
extern const char D_002E7720[];
extern "C" s32 func_0024B818(char **buf, const char *fmt, ...);

extern "C" void func_0025C230(CSndWorkM *w);
extern "C" void func_0025C2C0(CSndWorkM *w, s32 c);
extern "C" void func_0025C488(CSndWorkM *w);
extern CSndMgr *D_002BA248;
extern void (*D_002B91B0)(void *p);
void *Func245D00(s32 n);
void *Func25AE00(CPushBuf *p, void *src, s32 n);
extern const char D_002E7698[];
extern const char D_002E76B8[];
s32 Func235DE0(const char *fmt, ...);
inline void FreeIf(void *p) { if (p) D_002B91B0(p); }

struct CSndPrmS { s8 m0, m1, m2, m3, m4; u8 m5; s16 m6, m8, mA; f32 mC, m10, m14, m18, m1C; s16 m20, m22, m24; u8 pad26[2]; s32 m28, m2C; s16 m30, m32; };

extern "C" void *func_0024A3D8(s32 n);
extern "C" s32 func_002301B0(s32 fd, void *buf, s32 n);
void *Func24A4C0(const char *name);

extern u8 D_vtCSndUnit[] __asm__("_vt$8CSndUnit");
extern u8 D_vtCListTag[] __asm__("_vt$8CListTag");
void Func25E030(void *p);
struct CSndLinkB { s32 m0; CSndLinkB *m4; CSndLinkB *m8; void *mC; s32 m10; s32 m14; s32 m18; };
// @decl-end

s32 Func25A010(s32 i, s32 v) { return (v / D_002BA218[i]) << 10; }

void Func25A038(s32 v) { D_002BA244 = v; }

s32 Func25A048() { return D_002BA244; }

s32 Func25A058() { return 8; }

CSndMgr *Func25A060() {
    CSndMgr *p = new CSndMgr;
    return p;
}

INCLUDE_ASM("asm/nonmatchings/Dk25A010", __7CSndMgr);

CSndMgr::~CSndMgr() {
    func_0025C488(&m_w114);
    func_0025C488(&m_wA8);
    func_0025C488(&m_w3C);
    Func25B608();
    Func25B758();
    Func25A418();
    D_002BA248 = 0;
    func_0025C2C0(&m_w114, 2);
    func_0025C2C0(&m_wA8, 2);
    func_0025C2C0(&m_w3C, 2);
}

void CSndMgr::Func25A278() {
    s32 n = 0;
    CSndEnt *e = m_ents;
    for (s32 i = 0; m_defs[i].m0 >= 0; i++) {
        CSndDef *d = &m_defs[i];
        e->m_idx = n++;
        e->m_def = d;
        e->m_name[0] = 0;
        e->m28 = -1;
        e->m2C = -1;
        e->m30 = 0;
        e->m38 = 0;
        e->m34 = 0;
        e++;
        if (d->m_type == 3) {
            for (s32 j = 0; j < d->m_num; j++) {
                e->m_idx = n++;
                e->m_def = 0;
                e->m_name[0] = 0;
                e->m28 = -1;
                e->m2C = -1;
                e->m30 = 0;
                e->m38 = 0;
                e->m34 = 0;
                e++;
            }
        }
    }
}

s32 CSndMgr::Func25A338(CSndDef *defs) {
    s32 n = 0;
    s32 cnt = 0;
    Func25A418();
    for (s32 i = 0; defs[i].m0 >= 0; i++) {
        cnt++;
        if (defs[i].m_type == 3) n = defs[i].m0 + defs[i].m_num + 2;
        else n = defs[i].m0 + 1;
    }
    CSndEnt *e = new CSndEnt[n];
    if (!e) return 0;
    m_defs = defs;
    m_unk8 = cnt;
    m_ents = e;
    m_numEnts = n;
    Func25A278();
    return 1;
}

void CSndMgr::Func25A418() {
    Func25B608();
    if (m_ents) {
        delete[] m_ents;
        m_ents = 0;
        m_numEnts = 0;
    }
    m_defs = 0;
    m_unk8 = 0;
}

CSndEnt *CSndMgr::Func25A478(s32 i) {
    if (i < 0 || m_numEnts - 1 < i) return 0;
    if (m_ents[i].m2C < 0 || m_ents[i].m28 < 0) return 0;
    return &m_ents[i];
}

CSndEnt *CSndMgr::Func25A4D8(s32 i) {
    if (i < 0 || m_numEnts - 1 < i) return 0;
    if (m_ents[i].m2C < 0 || m_ents[i].m28 < 0) return 0;
    return &m_ents[i];
}

s32 CSndMgr::Func25A538(s32 i) {
    CSndEnt *e = Func25A4D8(i);
    if (!e) return -1;
    return e->m28;
}

s32 CSndMgr::Func25A568(s32 i) {
    CSndEnt *e = Func25A4D8(i);
    if (e) return e->m38;
    return 0;
}

char *CSndMgr::Func25A590(s32 i) {
    CSndEnt *e = Func25A4D8(i);
    if (!e) return 0;
    return e->m_name;
}

void CSndMgr::Func25A5C0(s32 i, s32 v) {
    CSndEnt *e = Func25A478(i);
    if (e) e->m34 += v;
}

s32 CSndMgr::Func25A600(s32 i) {
    CSndEnt *e = Func25A4D8(i);
    if (e) return e->m34;
    return 0;
}

s32 CSndMgr::Func25A628(const char *name, s32 i) {
    s32 end;
    if (i < 0 || m_numEnts - 1 < i) {
        end = m_numEnts;
        i = 0;
    } else {
        CSndDef *d = m_ents[i].m_def;
        if (d && d->m_type == 3) {
            i++;
            end = i + d->m_num + 1;
        } else {
            end = i + 1;
        }
    }
    for (s32 j = i; j < end; j++) {
        if (!strcmp(m_ents[j].m_name, name)) return j;
    }
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/Dk25A010", func_0025A738);

INCLUDE_ASM("asm/nonmatchings/Dk25A010", func_0025A838);

INCLUDE_ASM("asm/nonmatchings/Dk25A010", func_0025A908);

INCLUDE_ASM("asm/nonmatchings/Dk25A010", func_0025AAD0);

INCLUDE_ASM("asm/nonmatchings/Dk25A010", func_0025AC38);

s32 Func25AD78(CPushBuf *p, void *dst, void *src, s32 n) {
    if (src && n > 0) {
        memcpy(dst, src, n);
        return n;
    }
    return PushBufFunc248EE0(p, dst);
}

s32 Func25ADD0(CPushBuf *p, s32 b, s32 c) {
    if (b && c > 0) return c;
    return p->Func248EB0();
}

void *Func25AE00(CPushBuf *p, void *src, s32 n) {
    s32 sz = Func25ADD0(p, (s32)src, n);
    if (sz < 0) return 0;
    void *d = Func245D00(sz);
    if (!d) return d;
    Func25AD78(p, d, src, n);
    return d;
}

s32 CSndMgr::Func25AE80(s32 a, const char *name, s32 b, s32 c, void *src, s32 n) {
    void *d = Func25AE00((CPushBuf *)name, src, n);
    if (d && (a = Func25A908(a, name, d, b, c)) >= 0) {
        D_002B91B0(d);
        return a;
    }
    FreeIf(d);
    Func235DE0(D_002E7698, name);
    return -1;
}

s32 CSndMgr::Func25AF70(s32 a, const char *name, s32 b, void *src, s32 n) {
    void *d = Func25AE00((CPushBuf *)name, src, n);
    if (d && (a = Func25AAD0(a, name, d, b)) >= 0) {
        D_002B91B0(d);
        return a;
    }
    FreeIf(d);
    Func235DE0(D_002E76B8, name);
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/Dk25A010", func_0025B048);

void CSndMgr::Func25B230(s32 i) {
    CSndEnt *e = Func25A478(i);
    if (e) e->m38++;
}

INCLUDE_ASM("asm/nonmatchings/Dk25A010", func_0025B260);

void Func25B308(s32 a, u32 fl) {
    s32 x = func_002088B8(a);
    s32 y = func_00208948(a);
    func_00208670(a, 1);
    if (fl & 2) func_00219970(x);
    if (fl & 1) func_00219990(y);
}

void Func25B390(s32 a, u32 fl) {
    s32 h = func_00209058(a);
    func_00208E48(a, 1);
    if (fl & 2) func_00219970(h);
}

void Func25B3F0(s32 a, u32 fl) {
    void *p = func_0020E2F0(a);
    func_0020E1B8(a);
    if (fl & 4) func_00219950(p);
    if (fl & 8) D_002B91B0(p);
}

INCLUDE_ASM("asm/nonmatchings/Dk25A010", func_0025B460);

void CSndMgr::Func25B608() {
    for (s32 i = 0; i < m_numEnts; i++) {
        if (m_ents[i].m2C >= 0) Func25B460(i, 1);
    }
}

s32 CSndMgr::Func25B698(CSndSeq *seqs) {
    s32 n = 0;
    Func25B758();
    while (seqs[n].m0 >= 0) n++;
    m_seqs = seqs;
    m_numSeqs = n;
    m_vals = new s16[n];
    for (s32 i = 0; i < n; i++) m_vals[i] = m_defVal;
    return 1;
}

void CSndMgr::Func25B758() {
    if (m_vals) {
        delete[] m_vals;
        m_vals = 0;
    }
    m_seqs = 0;
    m_numSeqs = 0;
}

CSndSeq *CSndMgr::Func25B798(s32 i) {
    if (i < 0 || m_numSeqs - 1 < i) return 0;
    return &m_seqs[i];
}

CSndSeq *CSndMgr::Func25B7D8(const char *name) {
    for (s32 i = 0; i < m_numSeqs; i++) {
        if (!strcmp(m_seqs[i].m_name, name)) return &m_seqs[i];
    }
    return 0;
}

void CSndMgr::Func25B860(s32 i, s32 v) {
    if (i < 0 || m_numSeqs - 1 < i) return;
    m_vals[i] = v;
}

s16 CSndMgr::Func25B890(s32 i) {
    if (i < 0 || m_numSeqs - 1 < i) return 0;
    return m_vals[i];
}

s32 CSndMgr::Func25B8C8(char *h) {
    s32 n = func_0024B818(&h, D_002E7708);
    for (s32 i = 0; i < m_numSeqs; i++) n += func_0024B818(&h, D_002E7720, m_seqs[i].m_name, m_vals[i]);
    return n;
}

INCLUDE_ASM("asm/nonmatchings/Dk25A010", func_0025B980);

s32 CSndMgr::Func25BAB0(s32 x) { return Func25BB30(D_002E7748f, x); }

s32 CSndMgr::Func25BAD8(s32 x) { return Func25BC90(D_002E7750f, x); }

void CSndMgr::Func25BB00() {
    CSndPrm p;
    Func25BD60(&p);
    ((CSndWork *)Func25C220())->Func25D130(&p);
}

s32 CSndMgr::Func25BB30(CSndSaveFn fn, s32 fd) {
    s32 ok = 0;
    char *buf = 0;
    s32 n = (this->*fn)(0);
    if (n < 0) goto done;
    buf = (char *)func_0024A3D8(n);
    if (!buf) goto ret;
    if ((this->*fn)(buf) == n) ok = func_002301B0(fd, buf, n) == n;
done:
    if (buf) D_002B91B0(buf);
ret:
    return ok;
}

s32 CSndMgr::Func25BC90(CSndSaveFn fn, s32 name) {
    s32 ok = 0;
    char *buf = (char *)Func24A4C0((const char *)name);
    if (!buf) goto ret;
    ok = (this->*fn)(buf) != 0;
    if (buf) D_002B91B0(buf);
ret:
    return ok;
}

void Func25BD60(CSndPrm *p) {
    p->m0 = 0;
    p->m1 = 0;
    p->m2 = 0;
    p->m3 = 0;
    p->m4 = 0;
    p->m34 = 0;
    p->m35 = 0;
    p->m6 = 0x80;
    p->m8 = 0x80;
    p->mA = 0x80;
    p->mC = 1.0f;
    p->m10 = 1.0f;
    p->m14 = 1.0f;
    p->m1C = 0;
    p->m20 = 0x80;
    p->m22 = 0;
    p->m24 = 0;
    p->m28 = 0;
    p->m2C = 0;
    p->m5 = -1;
    p->m18 = 1.0f;
    p->m30 = 0x80;
    p->m32 = 0;
}

void Func25BDD0(CSndPrm *d, const CSndPrm *s) { return Func25BDE8(d, s); }

void Func25BDE8(CSndPrm *d, const CSndPrm *s) {
    d->m0 = s->m0;
    d->m1 = s->m1;
    d->m2 = s->m2;
    d->m3 = s->m3;
    d->m4 = s->m4;
    d->m5 = s->m5;
    d->m6 = s->m6;
    d->m8 = s->m8;
    d->mA = s->mA;
    d->mC = s->mC;
    d->m10 = s->m10;
    d->m14 = s->m14;
    d->m18 = s->m18;
    d->m1C = s->m1C;
    d->m20 = s->m20;
    d->m22 = s->m22;
    d->m24 = s->m24;
    d->m28 = s->m28;
    d->m2C = s->m2C;
    d->m30 = s->m30;
    d->m32 = s->m32;
}

void Func25BE98(CSndPrm *dp, const CSndPrm *sp) {
    CSndPrmS *d = (CSndPrmS *)dp;
    const CSndPrmS *s = (const CSndPrmS *)sp;
    d->m0 = d->m0 || s->m0;
    d->m1 = d->m1 || s->m1;
    d->m2 = d->m2 || s->m2;
    d->m3 = d->m3 || s->m3;
    d->m4 = d->m4 || s->m4;
    d->m5 = s->m5;
    d->m6 = d->m6 * s->m6 >> 7;
    d->m8 = d->m8 * s->m8 >> 7;
    d->mA = d->mA * s->mA >> 7;
    d->mC *= s->mC;
    d->m10 *= s->m10;
    d->m14 *= s->m14;
    d->m18 *= s->m18;
    d->m1C = s->m1C;
    d->m20 = d->m20 * s->m20 >> 7;
    d->m22 = 0;
    d->m24 = 0;
    d->m28 = 0;
    d->m2C = 0;
    d->m30 = d->m30 * s->m30 >> 7;
    d->m32 = 0;
}

void Func25C010(CSndPrm *p) {
    s32 n = p->m2C;
    if (!n) return;
    s32 t = p->m28 + 1;
    p->m28 = t;
    f32 b = p->m24;
    f32 a = p->m22;
    p->m20 = (s32)((b - a) * ((f32)t / (f32)n) + a);
    if (t == n) {
        p->m2C = 0;
        p->m28 = 0;
    }
    p->m0 = 1;
}

INCLUDE_ASM("asm/nonmatchings/Dk25A010", func_0025C098);

extern "C" void func_0025C138(CSndLinkB *u, s32 chrg) {
    u->mC = D_vtCSndUnit;
    D_002BA248->Func25A5C0(u->m18, -1);
    u->mC = D_vtCListTag;
    u->m4->m8 = u->m8;
    u->m8->m4 = u->m4;
    u->m8 = u;
    u->m4 = u;
    if (chrg & 1) return Func25E030(u);
}

INCLUDE_ASM("asm/nonmatchings/Dk25A010", func_0025C1E8);

void *Func25C220() { return D_41A788; }

INCLUDE_ASM("asm/nonmatchings/Dk25A010", func_0025C230);

INCLUDE_ASM("asm/nonmatchings/Dk25A010", func_0025C2C0);
