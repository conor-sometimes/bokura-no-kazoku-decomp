#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern u32 D_002BDAA8;
extern s32 D_002BDB3C;
typedef struct G { s32 m0, m4, m8, mC, m10, m14, m18; } G;
extern G D_41D198;
void func_00275268();
void func_00276CE8();
s32 func_002731E0(s32);
s32 func_002731C0(s32);
typedef struct E { u8 b[64]; } E;
typedef struct P { s32 m0, m4, m8, mC; u32 m10; E *m14; s32 m18; s32 m1C, m20; s32 m24; } P;

s32 func_0027BD20(void);
s32 func_0027BD78(void);
typedef struct { void *func; void *arg; void *gp; } Hnd;
typedef struct { s32 m0, m4, m8; Hnd *mC; s32 m10; Hnd *m14; } HTab;
extern HTab D_41D198_h __asm__("D_41D198");
int func_00275398(int, int, int, int, int, int, int);
int func_00275510(int, int, int, int, int, int);
E *func_002759D8(P *p);
typedef struct { u8 p0[0x1C]; E *m1C; int m20; } P2;
typedef struct { u8 p0[0x24]; int m24, m28, m2C; } Req;
typedef struct Ent { int m0; u8 p4[0x34]; struct Ent *m38; } Ent;
typedef struct Grp { u8 p0[8]; Ent *m8; u8 pC[8]; struct Grp *m14; } Grp;
typedef struct { u8 p0[0x28]; Grp *m28; } Ctx;
typedef struct Cmd { u8 p0[0xC]; int mC; u8 p10[0xC]; int m1C, m20, m24, m28, m2C, m30, m34; u8 p38[4]; struct Cmd *m3C; struct CQ *m40; } Cmd;
typedef struct CQ { int m0, m4, m8; Cmd *mC; Cmd *m10; } CQ;
typedef struct { u8 p0[0x10]; int m10, m14, m18, m1C, m20, m24, m28, m2C, m30; Cmd *m34; } Src;
s32 func_00273DD0(s32);
typedef struct { void *m0; int m4; } Chk;
typedef struct { u8 p0[0x10]; u32 m10; u8 p14[4]; int m18; } ChkO;
typedef struct Node { int m0, m4, m8, mC, m10; struct Node *m14; } Node;
typedef struct { u8 p0[0x28]; Node *m28; } NodeList;
extern NodeList D_41EBC0;
typedef struct Lnk { u8 p0[0x38]; struct Lnk *m38; } Lnk;
typedef struct { u8 p0[8]; Lnk *m8; } LnkList;
typedef struct Wq { u8 p0[0x3C]; struct Wq *m3C; } Wq;
typedef struct { int m0, m4, m8; Wq *mC; } WqHead;
void func_002765D0(Wq *);
Wq *func_00276578(WqHead *);
void func_002730C0(void);
typedef struct { int count, max_count, init_count, wait_threads; u32 attr, option; } SemaParam;
int func_002731A0(SemaParam *);
extern int D_002BDB40;
extern int D_002BDB44;
void func_002767D8(void);
typedef struct { int m0, m4, m8, mC; } Slot;
extern Slot D_420140[32];
extern void *D_420400;
int strncmp(const char *, const char *, int);
void *memset(void *, int, int);
extern char D_420368[];
extern char D_002BDA8C[];
extern char *D_002BDB48;
extern int D_002BDB34;

s32 func_0027BD20(void);
s32 func_0027BD78(void);
typedef struct { int m0, m4, m8, mC; u32 m10; void *m14; int m18; u8 p1C[0x24]; } PE;
typedef struct { int m0; PE *m4; int m8; } Pool;
typedef struct { void *m0; int m4; int m8; int mC; int m10; int m14; void *m18; void (*m1C)(void *); void *m20; int m24; } RC;
typedef struct { u8 p0[0x1C]; RC *m1C; u32 m20; int m24; int m28; } Rq;
typedef struct { u8 p0[0x10]; u32 m10; int m14; u8 p18[4]; int m1C, m20, m24, m28; } Cm;
typedef struct { u8 p0[0x14]; int m14; u8 p18[4]; int m1C; u32 m20; void *m24; int m28; int m2C; } EE;
EE *func_00275A08b(void *pool, int i) __asm__("func_00275A08");
EE *func_002759D8b(void *pool) __asm__("func_002759D8");
void *func_00275D80b(int id, void *c) __asm__("func_00275D80");
void func_0027DAC8(int, void *, void *);
int func_00275B18();
int func_00275DD0();
typedef struct C2 { int m0, m4, m8, mC, m10, m14; u8 p18[0x20]; struct C2 *m38; int m3C; void *m40; } C2;
typedef struct { int m0, m4; C2 *m8; } C2Q;

typedef struct { PE *m0; int m4; int m8; int mC; int m10; u8 p14[0x10]; int m24; } RpcClient;
typedef struct { u8 p0[0x14]; void *m14; int m18; void *m1C; int m20, m24, m28; } RpcPkt;
PE *func_00275910(Pool *p);
void func_002759B8(P *p);
int func_002754D0(int a, int b, int c, int d, int e, int f);
int func_002731B0(int);
typedef struct { int m0; void *m4; int m8, mC, m10; void *m14; int m18; void *m1C; int m20, m24; } RpcData;
extern RpcData D_41EBC0_r __asm__("D_41EBC0");
extern u8 D_41D3C0[];
extern u8 D_41DBC0[];
extern u8 D_41E3C0[];
void func_002752D0(int n, void *func, void *arg);
void func_00274FE8(void);
int func_002735B0(int);
int func_002735A0(int, int);
s32 func_00274FA0(s32 n);
void func_00275A48();
void func_00275E10();
void func_00276020();
void func_00275B58();

typedef struct { int sema; void *buf; int size; int mC; int m10; } W2RpcReq;
extern W2RpcReq D_41EC40;
extern u8 D_41F880[];
extern u8 D_420340[];
s32 func_002760B0(void *, s32, s32, void *, s32, void *, s32, void *, void *);
s32 W2Lock(s32) __asm__("func_00276D38");

typedef struct W2RpcCdS { int m0; int m4; int m8; int mC; int m10; int m14; int m18; int m1C; void *m20; int m24; } W2RpcCd;
typedef struct { int p0[5]; void * m14; int m18; void * m1C; int m20; int m24; int m28; int m2C; int m30; int m34; } W2RpcPkt;
void func_00275698(void *p, int n);
typedef struct { int m0; void *(*func)(int, void *, int); void *buf; int size; int m10, m14, m18; void * m1C; void *m20; int m24; void *m28; int m2C; int m30; unsigned int m34; } W2RpcSd;
typedef struct { int m0, m4, m8, mC, m10, m14, m18; int m1C; int m20; } W2RpcRp;
typedef struct { int src; int dest; int size; int attr; } W2DmaT;
int func_00273560(W2DmaT *, int);

typedef struct { u8 p0[0x10]; u32 m10; void *m14; int m18; struct Y1Rcv *m1C; int m20; int m24; int m28; } Y1In;
typedef struct { u8 p0[0x10]; u32 m10; int m14; int m18; int m1C; u32 m20; int m24; int m28; int m2C; } Y1Out;

typedef struct Y1Srv { int m0, m4, m8; int size; int m10, m14, m18; void *client; int pkt_addr; int rpc_number; int receive; int rsize; int rmode; int rid; u8 p38[4]; struct Y1Srv *link; struct Y1Base *base; } Y1Srv;
typedef struct Y1Base { int thread_id; int active; int m8; Y1Srv *start; void *end; } Y1Base;
typedef struct { u8 p0[0x10]; int rec_id; void *pkt_addr; int m18; void *client; int rpc_number; int send_size; int receive; int recv_size; int rmode; Y1Srv *server; } Y1Call;

typedef struct { int m0, m4, m8, mC; unsigned int rec_id; int m14; int rpc_id; } Y1Pk;
typedef struct { Y1Pk *pkt; int rpc_id; } Y1Cd;

typedef struct Y1Cmd { int m0; int m4; int m8, mC, m10, m14; char p18[0x38 - 0x18]; void * m38; void * m3C; struct Y1CQs * m40; } Y1Cmd;
typedef struct Y1CQs { int m0, m4; void * m8; } Y1CQ;
// @decl-end

s32 func_002752B8(s32 a, s32 b) { s32 old = D_41D198.mC; D_41D198.mC = a; D_41D198.m10 = b; return old; }

void func_002752D0(int cid, void *func, void *data)
{
    void *gp;
    if (cid & 0x80000000) {
        D_41D198_h.mC[cid & 0x7FFFFFFF].func = func;
        D_41D198_h.mC[cid & 0x7FFFFFFF].arg = data;
        asm volatile("move %0, $28" : "=r"(gp) : : "memory");
        D_41D198_h.mC[cid & 0x7FFFFFFF].gp = gp;
    } else {
        D_41D198_h.m14[cid].func = func;
        D_41D198_h.m14[cid].arg = data;
        asm volatile("move %0, $28" : "=r"(gp) : : "memory");
        D_41D198_h.m14[cid].gp = gp;
    }
}

void func_00275348(int n)
{
    if (n < 0) D_41D198_h.mC[n & 0x7FFFFFFF].func = 0;
    else D_41D198_h.m14[n].func = 0;
}

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00275398);

int func_002754D0(int a, int b, int c, int d, int e, int f)
{
    return func_00275398(a, 0, b, c, d, e, f);
}

int func_00275510(int a, int b, int c, int d, int e, int f)
{
    return func_00275398(a, 1, b, c, d, e, f);
}

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00275550);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00275698);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00275744);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00275748);

void func_002758E8(void) { func_00275268(); D_002BDAA8 = 0; }

PE *func_00275910(Pool *p)
{
    PE *e;
    int i;
    func_0027BD20();
    e = p->m4;
    for (i = 0; i < p->m8; i++, e++) {
        if (!(e->m10 & 1)) {
            int s;
            e->m10 = (i << 16) | 5;
            if (++p->m0 == 1) { p->m0++; s = 1; } else s = p->m0;
            e->m14 = e;
            e->m18 = s;
            func_0027BD78();
            return e;
        }
    }
    func_0027BD78();
    return 0;
}

void func_002759B8(P *p) { p->m18 = 0; p->m10 &= ~1; }

E *func_002759D8(P *p) { s32 i = p->m24 % p->m18; E *e = &p->m14[i]; p->m24 = i + 1; return e; }

E *func_00275A08(P2 *p, int i)
{
    if (i < 0 || i >= p->m20) return func_002759D8((P *)p);
    return &p->m1C[i];
}

void func_00275A48(Rq *q)
{
    RC *c;
    switch (q->m20) {
    case 0x8000000A:
        c = q->m1C;
        if (c->m1C) {
            void *gp, *t;
            asm volatile("move %0, $28\n\tmove $28, %1" : "=&r"(gp) : "r"(c->m18) : "memory");
            c->m1C(c->m20);
            asm volatile("move %0, $28\n\tmove $28, %1" : "=&r"(t) : "r"(gp));
        }
        break;
    case 0x80000009:
        c = q->m1C;
        c->m24 = q->m24;
        c->m14 = q->m28;
        break;
    case 0x8000000B:
        break;
    }
    c = q->m1C;
    if (c->m8 >= 0) func_002731D0(c->m8);
    func_002759B8((P *)c->m0);
    c->m0 = 0;
}

int func_00275B18(int a, int b, int c, Req *r)
{
    return func_00275510(0x80000008, (int)r, 0x40, r->m24, r->m28, r->m2C) ? 0 : 0x800;
}

void func_00275B58(Y1In *rd, void *pool)
{
    Y1Out *pkt;
    if (rd->m10 & 4) pkt = (Y1Out *)func_00275A08b(pool, rd->m10 >> 16);
    else pkt = (Y1Out *)func_002759D8b(pool);
    pkt->m14 = (int)rd->m14;
    pkt->m1C = (int)rd->m1C;
    pkt->m20 = 0x8000000C;
    pkt->m24 = rd->m20;
    pkt->m28 = rd->m24;
    pkt->m2C = rd->m28;
    if (!func_00275510(0x80000008, (int)pkt, 0x40, rd->m20, rd->m24, rd->m28))
        func_0027DAC8(0x800, func_00275B18, pkt);
}

int func_00275C28(RpcClient *cd, int a, int b, int c, int mode)
{
    RpcPkt *p;
    SemaParam s;
    p = (RpcPkt *)func_00275910((Pool *)&D_41EBC0);
    if (!p) return -1;
    cd->m0 = (PE *)p;
    cd->m4 = p->m18;
    p->m20 = a;
    p->m24 = b;
    p->m28 = c;
    p->m14 = p;
    p->m1C = cd;
    if (!(mode & 1)) {
        s.init_count = 0;
        s.max_count = 1;
        cd->m8 = func_002731A0(&s);
        if (cd->m8 < 0) {
            func_002759B8((P *)p);
            return -3;
        }
        if (func_002754D0(0x8000000C, (int)p, 0x40, 0, 0, 0) == 0) {
            func_002759B8((P *)p);
            func_002731B0(cd->m8);
            return -2;
        }
        func_002731E0(cd->m8);
        func_002731B0(cd->m8);
        return 0;
    }
    cd->m8 = -1;
    if (func_002754D0(0x8000000C, (int)p, 0x40, 0, 0, 0) == 0) {
        func_002759B8((P *)p);
        return -2;
    }
    return 0;
}

Ent *func_00275D80(int id, Ctx *c)
{
    Grp *g;
    Ent *e;
    for (g = c->m28; g; g = g->m14)
        for (e = g->m8; e; e = e->m38)
            if (e->m0 == id) return e;
    return 0;
}

int func_00275DD0(int a, int b, int c, Req *r)
{
    return func_00275510(0x80000008, (int)r, 0x40, 0, 0, 0) ? 0 : 0x800;
}

void func_00275E10(Y1In *rd, void *pool)
{
    Y1Out *pkt = (Y1Out *)func_002759D8b(pool);
    int *e;
    pkt->m14 = (int)rd->m14;
    pkt->m1C = (int)rd->m1C;
    pkt->m20 = 0x80000009;
    e = (int *)func_00275D80b(rd->m20, pool);
    if (!e) { pkt->m24 = 0; pkt->m28 = 0; }
    else { pkt->m24 = (int)e; pkt->m28 = e[2]; }
    if (!func_00275510(0x80000008, (int)pkt, 0x40, 0, 0, 0))
        func_0027DAC8(0x800, func_00275DD0, pkt);
}

int func_00275EE0(RpcClient *cd, int rpc, int mode)
{
    RpcPkt *p;
    SemaParam s;
    cd->m10 = 0;
    cd->m24 = 0;
    p = (RpcPkt *)func_00275910((Pool *)&D_41EBC0);
    if (!p) return -1;
    cd->m0 = (PE *)p;
    cd->m4 = p->m18;
    p->m20 = rpc;
    p->m14 = p;
    p->m1C = cd;
    if (!(mode & 1)) {
        s.init_count = 0;
        s.max_count = 1;
        cd->m8 = func_002731A0(&s);
        if (cd->m8 < 0) {
            func_002759B8((P *)p);
            return -3;
        }
        if (func_002754D0(0x80000009, (int)p, 0x40, 0, 0, 0) == 0) {
            func_002759B8((P *)p);
            func_002731B0(cd->m8);
            return -2;
        }
        func_002731E0(cd->m8);
        func_002731B0(cd->m8);
        return 0;
    }
    cd->m8 = -1;
    if (func_002754D0(0x80000009, (int)p, 0x40, 0, 0, 0) == 0) {
        func_002759B8((P *)p);
        return -2;
    }
    return 0;
}

void func_00276020(Y1Call *request)
{
    Y1Srv *server = request->server;
    Y1Base *base = server->base;
    if (base->start == 0) base->start = server; else ((Y1Srv *)base->end)->link = server;
    base->end = (__typeof__(base->end))server;
    server->pkt_addr = (__typeof__(server->pkt_addr))request->pkt_addr;
    server->client = (__typeof__(server->client))request->client;
    server->rpc_number = request->rpc_number;
    server->size = request->send_size;
    server->receive = request->receive;
    server->rsize = request->recv_size;
    server->rmode = request->rmode;
    server->rid = request->rec_id;
    if (base->thread_id >= 0 && base->active == 0) func_00273DD0(base->thread_id);
}

s32 func_002760B0(void *vcd, s32 fno, s32 mode, void *send, s32 ssize, void *recv, s32 rsize, void *endfunc, void *efarg)
{
    W2RpcCd *cd = (W2RpcCd *)vcd;
    void *gp;
    W2RpcPkt *call;
    SemaParam sp;
    call = (W2RpcPkt *)func_00275910((Pool *)&D_41EBC0);
    if (call == 0) return -1;
    cd->m20 = efarg;
    cd->m4 = call->m18;
    cd->m0 = (int)call;
    cd->m1C = (int)endfunc;
    asm volatile("move %0, $28" : "=r"(gp));
    cd->m18 = (int)gp;
    call->m20 = fno;
    call->m24 = ssize;
    call->m28 = (int)recv;
    call->m2C = rsize;
    call->m14 = (void *)call;
    call->m1C = (void *)cd;
    call->m34 = (int)cd->m24;
    if (!(mode & 2)) {
        if (send == recv) {
            func_00275698(send, ssize < rsize ? rsize : ssize);
        } else {
            if (ssize > 0) func_00275698(send, ssize);
            if (rsize > 0) func_00275698(recv, rsize);
        }
    }
    if (mode & 1) {
        if (endfunc == 0) call->m30 = 0;
        else call->m30 = 1;
        cd->m8 = -1;
        if (func_002754D0(0x8000000A, (int)call, 0x40, (int)send, cd->m14, ssize)) return 0;
        func_002759B8((P *)call);
        return -2;
    }
    sp.init_count = 0;
    sp.max_count = 1;
    cd->m8 = func_002731A0(&sp);
    if (cd->m8 < 0) {
        func_002759B8((P *)call);
        return -3;
    }
    call->m30 = 1;
    if (func_002754D0(0x8000000A, (int)call, 0x40, (int)send, cd->m14, ssize) == 0) {
        func_002731B0(cd->m8);
        func_002759B8((P *)call);
        return -2;
    }
    func_002731E0(cd->m8);
    func_002731B0(cd->m8);
    return 0;
}

int func_002762A8(void *vcd)
{
    Y1Cd *cd = (Y1Cd *)vcd;
    volatile Y1Pk *p = cd->pkt;
    if (!p || cd->rpc_id != p->rpc_id || !(p->rec_id & 1)) return 0;
    return 1;
}

void func_002762E8(Node *n, int a)
{
    Node *p;
    func_0027BD20();
    n->m0 = a;
    n->m4 = 0;
    n->m8 = 0;
    n->mC = 0;
    n->m10 = 0;
    n->m14 = 0;
    if (D_41EBC0.m28 == 0) D_41EBC0.m28 = n;
    else {
        p = D_41EBC0.m28;
        while (p->m14) p = p->m14;
        p->m14 = n;
    }
    func_0027BD78();
}

void func_00276380(Y1Cmd *c, int a, int b, int d, int e, int f, Y1CQ *q)
{
    Y1Cmd *p;
    func_0027BD20();
    c->m3C = 0;
    c->m38 = 0;
    c->m0 = (__typeof__(c->m0))a;
    c->m4 = (__typeof__(c->m4))b;
    c->m8 = d;
    c->m10 = e;
    c->m14 = f;
    c->m40 = (__typeof__(c->m40))q;
    if (q->m8 == 0) q->m8 = c;
    else { p = (Y1Cmd *)q->m8; while (p->m38) p = (Y1Cmd *)p->m38; p->m38 = (__typeof__(p->m38))c; }
    func_0027BD78();
}

Lnk *func_00276450(Lnk *a, LnkList *l)
{
    Lnk *p;
    func_0027BD20();
    p = l->m8;
    if (p == a) l->m8 = p->m38;
    else {
        for (; p; p = p->m38) {
            if (p->m38 == a) { p->m38 = a->m38; break; }
        }
    }
    func_0027BD78();
    return p;
}

Node *func_002764E8(Node *a)
{
    Node *p;
    func_0027BD20();
    p = D_41EBC0.m28;
    if (p == a) D_41EBC0.m28 = p->m14;
    else {
        for (; p; p = p->m14) {
            if (p->m14 == a) { p->m14 = a->m14; break; }
        }
    }
    func_0027BD78();
    return p;
}

Wq *func_00276578(WqHead *q)
{
    Wq *e;
    func_0027BD20();
    e = q->mC;
    if (!e) q->m4 = 0;
    else { q->m4 = 1; q->mC = e->m3C; }
    func_0027BD78();
    return e;
}

void func_002765D0(Wq *wq)
{
    W2RpcSd *sd = (W2RpcSd *)wq;
    W2DmaT dma[2];
    W2RpcRp *pkt;
    void *rec;
    int size = 0;
    int count, id, i;
    rec = sd->func(sd->m24, sd->buf, sd->size);
    if (rec) size = sd->m2C;
    if (sd->size > 0) func_00275698(sd->buf, sd->size);
    if (size > 0) func_00275698(rec, size);
    func_0027BD20();
    if (sd->m34 & 4) pkt = (W2RpcRp *)func_00275A08b(&D_41EBC0, sd->m34 >> 16);
    else pkt = (W2RpcRp *)func_002759D8b(&D_41EBC0);
    func_0027BD78();
    pkt->m20 = (int)0x8000000A;
    pkt->m1C = (int)sd->m1C;
    if (sd->m30) {
        while (!func_002754D0(0x80000008, (int)pkt, 0x40, (int)rec, (int)sd->m28, size))
            ;
        return;
    }
    pkt->m18 = 0;
    count = 0;
    pkt->m10 = 0;
    if (size > 0) {
        count = 1;
        dma[0].src = (int)rec;
        dma[0].dest = (int)sd->m28;
        dma[0].size = size;
        dma[0].attr = 0;
    }
    dma[count].src = (int)pkt;
    dma[count].dest = (int)sd->m20;
    dma[count].size = 0x40;
    dma[count].attr = 0;
    count++;
    do {
        id = func_00273560(dma, count);
        if (id == 0) {
            i = 0x100000;
            while (i--)
                ;
        }
    } while (id == 0);
}

void func_00276798(WqHead *q)
{
    Wq *e;
    for (;;) {
        while ((e = func_00276578(q)) != 0) func_002765D0(e);
        func_002730C0();
    }
}

void func_002767D8(void)
{
    SemaParam p;
    if (D_002BDB40 == -1) {
        p.init_count = 1;
        p.max_count = 1;
        p.option = 0;
        D_002BDB40 = func_002731A0(&p);
        D_002BDB44 = func_002731A0(&p);
    }
}

Slot *func_00276838(void)
{
    Slot *p;
    func_002767D8();
    func_002731E0(D_002BDB40);
    for (p = D_420140; p < D_420140 + 32; p++) {
        if (p->m4 == 0) {
            p->m4 = 0x10000000;
            func_002731C0(D_002BDB40);
            return p;
        }
    }
    func_002731C0(D_002BDB40);
    return 0;
}

Slot *func_002768C0(u32 i)
{
    Slot *p;
    func_002767D8();
    func_002731E0(D_002BDB40);
    if (i >= 32) {
        func_002731C0(D_002BDB40);
        return 0;
    }
    p = &D_420140[i];
    func_002731C0(D_002BDB40);
    return p;
}

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00276930);
INCLUDE_RODATA("asm/nonmatchings/Dk2752B8", D_002EA048);
INCLUDE_RODATA("asm/nonmatchings/Dk2752B8", D_002EA050);

void func_00276CE8(void)
{
    SemaParam p;
    if (D_002BDB3C == -1) {
        p.init_count = 1;
        p.max_count = 1;
        p.option = 0;
        D_002BDB3C = func_002731A0(&p);
    }
}

s32 func_00276D38(void) { func_00276CE8(); func_002731E0(D_002BDB3C); return 0; }

void func_00276D68(void) { func_002731C0(D_002BDB3C); }

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00276D78);

void func_00276E20(int cause, Hnd *h)
{
    if (h->func) {
        void *old;
        asm volatile("move %0, $28\n\tlw $28, %1" : "=r"(old) : "m"(D_420400));
        ((void (*)(void *))h->func)(h->arg);
        asm volatile("move $28, %0" : : "r"(old));
    }
    asm volatile("sync\n\tei");
}

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00276E68);

int func_00277070(void)
{
    char *a = D_002BDA8C;
    char *b = D_420368;
    int r = 0;
    if (strncmp(b, a, 4) && strncmp(b, D_002BDB48, 4))
        r = strncmp(a, D_002BDB48, 4) != 0;
    return r;
}

int func_00277100(void)
{
    D_002BDB34 = 0;
    memset(D_420368, 0, 4);
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00277138);

int func_002773C0(u32 id)
{
    W2RpcReq *rq = &D_41EC40;
    Slot *s;
    SemaParam sp;
    int ret;
    int sema, r;
    s = func_002768C0(id);
    W2Lock(1);
    if (D_002BDB34 == 0) {
        func_00276D68();
        return -1;
    }
    if (s == 0 || s->m4 == 0) {
        func_00276D68();
        return -9;
    }
    rq->mC = s->m0;
    rq->m10 = s - D_420140;
    sp.max_count = 1;
    sp.init_count = 0;
    sp.option = 0;
    sema = func_002731A0(&sp);
    rq->sema = sema;
    rq->buf = &ret;
    rq->size = 4;
    if (func_002760B0(D_420340, 1, 0, rq, 0x14, D_41F880, 4, 0, 0) < 0) {
        func_002731B0(sema);
        func_00276D68();
        return -11;
    }
    s->m4 = 0;
    r = *(int *)((u32)D_41F880 | 0x20000000);
    func_00276D68();
    if (r == 0) {
        func_002731B0(sema);
        return -11;
    }
    func_002731E0(sema);
    func_002731B0(sema);
    { int v = 0; if (ret < 0) v = ret; return v; }
}

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00277540);

INCLUDE_ASM("asm/nonmatchings/Dk2752B8", func_00277778);
