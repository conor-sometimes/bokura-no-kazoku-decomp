#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
s32 Func235DE0(const char *fmt, ...);
extern "C" s32 func_001F1180();
extern "C" void *memset(void *d, int c, unsigned int n);
extern "C" char *strcpy(char *d, const char *s);
extern "C" unsigned int strlen(const char *s);
extern "C" char *strstr(const char *s, const char *f);
extern "C" s32 func_00235648(char *buf, const char *sec, const char *key);
extern void *(*D_002B91A4)(u32 n);
extern void (*D_002B91AC)(void *p, s32 n);
extern void (*D_002B91B0)(void *p);
struct CMemHeap;
struct CMemNode;
struct CMemBlk {
    CMemNode *m_node;         // 0x0
    s32 m_size;               // 0x4
    s32 m_req;                // 0x8
    s32 m_tag;                // 0xC
};
struct CMemNode {
    CMemBlk *m_blk;           // 0x0
    CMemNode *m_prev;         // 0x4
    CMemNode *m_next;         // 0x8
    CMemHeap *m_heap;         // 0xC
};
struct CMemHeap {
    CMemNode *m_nodes;        // 0x00
    s32 m_numNodes;           // 0x04
    s32 m_usedNodes;          // 0x08
    s32 m_liveNodes;          // 0x0C
    u8 *m_data;               // 0x10
    s32 m_size;               // 0x14
    s32 m_used;               // 0x18
    s32 m_tag;                // 0x1C
    CMemNode m_list;          // 0x20
    CMemNode m_free;          // 0x30
    CMemNode *m_first;        // 0x40
    CMemNode *m_last;         // 0x44
    s32 m_count;              // 0x48
    s32 m_magic;              // 0x4C
};
struct CMemSlot { CMemHeap *m_heap; s32 m_used; };
struct CMemGlobal {
    CMemSlot m_slot[2];       // 0x00
    s32 m_flags;              // 0x10
    f32 m_ratio[2];           // 0x14
    s32 m_lo;                 // 0x1C
    s32 m_hi;                 // 0x20
};
extern CMemGlobal D_38F188;
extern "C" CMemBlk *func_00246C18(void *p);
extern "C" s32 func_00246008();
extern "C" s32 func_00246018();
extern const char D_002E6108[];
extern const char D_002E6120[];
extern const char D_002E6150[];
extern const char D_002E6178[];
extern const char D_002E6198[];
extern const char D_002E61D0[];
extern const char D_002E61F8[];
extern const char D_002E6218[];
extern const char D_002E6248[];
extern const char D_002E6260[];
extern const char D_002E6278[];
extern const char D_002E62B0[];
extern const char D_002E62E0[];
extern const char D_002E62E8[];
extern const char D_002E62F0[];
extern const char D_002E6388[];
extern const char D_002E63A8[];
extern const char D_002E63D8[];
extern const char D_002E63E0[];
extern const char D_002E63E8[];
extern const char D_002E63F0[];
extern const char D_002E63F8[];
extern const char D_002E6400[];
extern const char D_002E6428[];
extern const char D_002E6450[];
extern const char D_002E6488[];
extern const char D_002E64A8[];
extern const char D_002E64D0[];
extern const char D_002E64D8[];
extern const char D_002E64F0[];
extern const char D_002E6508[];
extern const char D_002E6520[];
extern const char D_002E6530[];
extern "C" s32 func_00247210(void *lo, void *p, s32 align);
extern "C" s32 func_00247280(CMemHeap *h, s32 verbose);
extern "C" s32 func_002473D8(CMemHeap *h, CMemNode *head, const char *name, s32 verbose);
extern "C" s32 func_00247578(CMemHeap *h, s32 verbose);
extern "C" s32 func_002477F0(CMemNode *head);
extern "C" void func_00247828(CMemHeap *h);
extern "C" void func_002478C8(CMemHeap *h, CMemNode *head, const char *name);
extern "C" void func_002479F0(CMemHeap *h);
#include "CPushBuf.h"
extern "C" void *func_002303C0(const char *name);
extern "C" void *func_002303E0(const char *name);
extern "C" s32 func_0022DD20(const char *name);
extern "C" s32 func_0022FF58(void *name);
extern "C" s32 func_002301B0(const char *name);
extern "C" s32 func_0022FF18(void *name, void *buf);
extern "C" void *func_00248D98(CPushBuf *p);
extern "C" void *func_00248DA8(CPushBuf *p);
extern "C" s32 FileSize248EB0(const char *name) asm("Func248EB0__8CPushBuf");
extern "C" s32 FileRead248EE0(const char *name, void *buf) asm("Func248EE0__8CPushBufPv");
typedef void *(*LoadFn)(const char *name, s32 *size);
typedef void (*UnloadFn)(void *p);
extern LoadFn D_002B9E40;
extern UnloadFn D_002B9E44;
extern "C" void *func_00248EF8(const char *name, s32 *size);
extern "C" void func_00248FA8(void *p);
extern "C" void *func_00248E60(const char *name);
extern "C" void *func_00228C00();
extern "C" void func_00228C38(void *p);
extern s32 D_002B9E48[];
struct CDbgGlobal {
    u64 *m_pkt;               // 0x38F1B0
    s32 m_unk4;               // 0x38F1B4
    void *m_xpf[2][32];       // 0x38F1B8
};
extern CDbgGlobal D_38F1B0;
extern s32 D_38F2B8[2][4];
extern s32 D_002B9E50;
extern const char *D_002B9E54;
extern const char *D_002B9E58;
extern "C" s32 func_00249070(const char *name);
extern "C" void func_002490F8();
extern "C" s32 func_0024A000(const char *name);
extern "C" void func_0024A098();
extern "C" void func_0022DCE0();
extern "C" void func_0022DC90(const char *name);
extern "C" void func_0022DD00();
extern "C" s32 func_0024A128(const char *a, const char *b);
extern "C" void func_0024A2E0(const char *name);
struct CDirEntry { u8 m_data[0x228]; };
struct CDirStack {
    CDirEntry m_entries[8];   // 0x0
    s32 m_count;              // 0x1140
};
struct CDirNode {
    CDirNode *m_next;         // 0x0
    char m_name[0x204];       // 0x4
};
struct CDirGlobal {
    CDirStack m_stack[2];     // 0x0
    CDirNode m_nodes[16];     // 0x2288
    CDirNode *m_open;         // 0x4308
    CDirNode *m_free;         // 0x430C
    s32 m_unk4310;            // 0x4310
};
extern CDirGlobal D_38F2D8;
extern "C" CDirStack *func_00249510();
extern "C" CDirEntry *func_00249550();

#define PKT(v) { *p = (v); p++; D_38F1B0.m_pkt = p; }
#define RGBAQ(r, g, b, a, q) (((u64)(r) & 0xFF) | (((u64)(g) & 0xFF) << 8) | (((u64)(b) & 0xFF) << 16) | (((u64)(a) & 0xFF) << 24) | ((u64)(q) << 32))
// @decl-end

extern "C" s32 func_002470E8(void *p) {
    CMemBlk *b = func_00246C18(p);
    if (b) return b->m_req;
    return 0;
}

extern "C" void func_00247110() {
    D_38F188.m_slot[func_001F1180()].m_used = 0;
}

extern "C" s32 func_00247140() {
    return D_38F188.m_slot[func_001F1180()].m_used;
}

extern "C" f32 func_00247178(f32 v) {
    f32 old = D_38F188.m_ratio[func_001F1180()];
    D_38F188.m_ratio[func_001F1180()] = v;
    return old;
}

extern "C" f32 func_002471D8() {
    return D_38F188.m_ratio[func_001F1180()];
}

INCLUDE_ASM("asm/nonmatchings/Dk2470E8", func_00247210);

extern "C" s32 func_00247280(CMemHeap *h, s32 verbose) {
    if (!func_00247210(0, h, 4) || h->m_magic != 0x484D454D) {
        if (verbose) Func235DE0(D_002E6108, h);
        return 0;
    }
    if (!func_00247210(h, h->m_nodes, 4) || h->m_numNodes < h->m_usedNodes || h->m_liveNodes < 0 ||
        h->m_numNodes < h->m_liveNodes) {
        if (verbose) Func235DE0(D_002E6120, h->m_nodes, h->m_numNodes, h->m_usedNodes, h->m_liveNodes);
        return 0;
    }
    if (!func_00247210(h, h->m_data, 0x10) || (s32)(h->m_data + h->m_size) < (s32)h ||
        func_00246018() < (s32)(h->m_data + h->m_size) || h->m_size < h->m_used) {
        if (verbose) Func235DE0(D_002E6150, h->m_data, h->m_size, h->m_used);
        return 0;
    }
    return 1;
}

extern "C" s32 func_002473D8(CMemHeap *h, CMemNode *head, const char *name, s32 verbose) {
    s32 cnt, pass;
    CMemNode *n;
    for (pass = 0; pass < 2; pass++) {
        for (n = pass ? head->m_next : head->m_prev, cnt = 0; n != head; n = pass ? n->m_next : n->m_prev, cnt++) {
            if (!func_00247210(h, n, 4)) {
                if (verbose) Func235DE0(D_002E6178, n);
                return 0;
            }
            if (!func_00247210(h, n->m_prev, 4) || !func_00247210(h, n->m_next, 4) ||
                (n->m_heap && !func_00247210(h, n->m_heap, 4)) || (n->m_blk && !func_00247210(h, n->m_blk, 0x10))) {
                if (verbose) Func235DE0(D_002E6198, n, n->m_prev, n->m_next, n->m_heap, n->m_blk);
                return 0;
            }
            if (h->m_usedNodes < cnt) {
                if (verbose) Func235DE0(D_002E61D0, n, cnt, h->m_usedNodes);
                return 0;
            }
        }
    }
    return 1;
}

extern "C" s32 func_00247578(CMemHeap *h, s32 verbose) {
    CMemNode *lastFree = 0;
    s32 used = 0;
    CMemNode *firstFree = 0;
    CMemNode *end = &h->m_list;
    s32 free = 0;
    s32 prevFree = 0;
    CMemNode *n;
    for (n = h->m_list.m_next; n != end; n = n->m_next) {
        CMemBlk *b = n->m_blk;
        if (!func_00247210(h, b, 0x10)) {
            if (verbose) Func235DE0(D_002E61F8, b);
            return 0;
        }
        if (b->m_node != n) {
            if (verbose) Func235DE0(D_002E6218, b, b->m_node, n);
            return 0;
        }
        if (b->m_size <= 0) {
            if (verbose) Func235DE0(D_002E6248, b);
            return 0;
        }
        if (b->m_req == 0 && prevFree == 1) {
            if (verbose) Func235DE0(D_002E6260, b);
            return 0;
        }
        if (b->m_req > 0) {
            used += b->m_size;
            prevFree = 0;
        } else {
            free += b->m_size;
            prevFree = 1;
            if (!firstFree) firstFree = n;
            lastFree = n;
        }
        used += 16;
    }
    if (h->m_size != used + free || h->m_used != used) {
        if (verbose) Func235DE0(D_002E6278, h->m_size, h->m_used, used, free);
        return 0;
    }
    if (h->m_first != firstFree || h->m_last != lastFree) {
        if (verbose) Func235DE0(D_002E62B0, h->m_first, h->m_last, firstFree, lastFree);
        return 0;
    }
    return 1;
}

extern "C" s32 func_00247768(CMemHeap *h, s32 verbose) {
    if (!func_00247280(h, verbose)) return 0;
    if (!func_002473D8(h, &h->m_list, D_002E62E0, verbose)) return 0;
    if (!func_002473D8(h, &h->m_free, D_002E62E8, verbose)) return 0;
    return func_00247578(h, verbose) != 0;
}

extern "C" s32 func_002477F0(CMemNode *head) {
    s32 n = 0;
    CMemNode *p;
    for (p = head->m_next; p != head; p = p->m_next) n++;
    return n;
}

extern "C" void func_00247828(CMemHeap *h) {
    s32 nu = func_002477F0(&h->m_list);
    s32 nf = func_002477F0(&h->m_free);
    Func235DE0(D_002E62F0, h, h->m_numNodes, h->m_usedNodes, h->m_data, h->m_size, h->m_used, h->m_tag, nu, nf,
               h->m_first, h->m_first ? h->m_first->m_blk : 0, h->m_last, h->m_last ? h->m_last->m_blk : 0);
}

extern "C" void func_002478C8(CMemHeap *h, CMemNode *head, const char *name) {
    CMemNode *n;
    Func235DE0(D_002E6388, name);
    for (n = head->m_next; n != head; n = n->m_next) {
        CMemBlk *b = n->m_blk;
        Func235DE0(D_002E63A8, n == h->m_first ? D_002E63D8 : D_002E63E0, n == h->m_last ? D_002E63E8 : D_002E63E0, n, b,
                   b && b->m_req > 0 ? D_002E63F0 : D_002E63E0, b ? b->m_size : 0, n->m_heap,
                   n->m_prev == head ? 0 : n->m_prev, n->m_next == head ? 0 : n->m_next);
    }
    Func235DE0(D_002E63F8);
}

extern "C" void func_002479F0(CMemHeap *h) {
    s32 lock = 0;
    s32 unlock = 0;
    CMemNode *n;
    Func235DE0(D_002E6400, h->m_data, h->m_used, h->m_size);
    for (n = h->m_list.m_next; n != &h->m_list; n = n->m_next) {
        CMemBlk *b = n->m_blk;
        Func235DE0(D_002E6428, b->m_req > 0 ? D_002E63F0 : D_002E63E0, b, (u8 *)b + 16, b->m_size, b->m_req, b->m_tag);
        if (n->m_blk->m_req > 0) lock += n->m_blk->m_size;
        else unlock += n->m_blk->m_size;
        lock += 16;
    }
    Func235DE0(D_002E6450, lock, unlock, lock + unlock);
    Func235DE0(D_002E63F8);
}

void Dump247B00(CMemHeap *h) asm("Func247B00__13CMiniGame6Obj");
void Dump247B00(CMemHeap *h) {
    if (h) {
        func_00247828(h);
        func_002478C8(h, &h->m_list, D_002E62E0);
        func_002478C8(h, &h->m_free, D_002E62E8);
        func_002479F0(h);
    }
}

INCLUDE_ASM("asm/nonmatchings/Dk2470E8", func_00247B60);

extern "C" void func_00247C00(s32 x0, s32 y0, s32 x1, s32 y1, u32 c) {
    s32 v[4];
    u64 *p;
    u64 col;
    v[0] = (x0 << 4) + 0x8000;
    v[1] = (y0 << 4) + 0x8000;
    v[2] = (x1 << 4) + 0x8000;
    v[3] = (y1 << 4) + 0x8000;
    col = RGBAQ(c >> 24, c >> 16, c >> 8, c, 0);
    p = D_38F1B0.m_pkt;
    *p++ = 0x1000000000000004;
    D_38F1B0.m_pkt = p;
    p[0] = 0xE;
    D_38F1B0.m_pkt = p + 1;
    p[1] = 0x46;
    D_38F1B0.m_pkt = p + 2;
    p[2] = 0;
    D_38F1B0.m_pkt = p + 3;
    p[3] = col;
    D_38F1B0.m_pkt = p + 4;
    p[4] = 1;
    D_38F1B0.m_pkt = p + 5;
    p[5] = (u64)v[0] | ((u64)v[1] << 16);
    D_38F1B0.m_pkt = p + 6;
    p[6] = 5;
    D_38F1B0.m_pkt = p + 7;
    p[7] = (u64)v[2] | ((u64)v[3] << 16);
    D_38F1B0.m_pkt = p + 8;
    p[8] = 5;
    D_38F1B0.m_pkt = p + 9;
}

extern "C" void func_00247D38(s32 x0, s32 y0, s32 x1, s32 y1, u32 c0, u32 c1, u32 c2, u32 c3) {
    s32 v[4];
    u64 *p;
    v[0] = (x0 << 4) + 0x8000;
    v[1] = (y0 << 4) + 0x8000;
    v[2] = (x1 << 4) + 0x8000;
    v[3] = (y1 << 4) + 0x8000;
    p = D_38F1B0.m_pkt;
    *p++ = 0x1000000000000009;
    D_38F1B0.m_pkt = p;
    p[0] = 0xE;
    D_38F1B0.m_pkt = p + 1;
    p[1] = 0x4D;
    D_38F1B0.m_pkt = p + 2;
    p[2] = 0;
    D_38F1B0.m_pkt = p + 3;
    p[3] = RGBAQ(c0 >> 24, c0 >> 16, c0 >> 8, c0, 0);
    D_38F1B0.m_pkt = p + 4;
    p[4] = 1;
    D_38F1B0.m_pkt = p + 5;
    p[5] = (u64)v[0] | ((u64)v[1] << 16);
    D_38F1B0.m_pkt = p + 6;
    p[6] = 5;
    D_38F1B0.m_pkt = p + 7;
    p[7] = RGBAQ(c1 >> 24, c1 >> 16, c1 >> 8, c1, 0);
    D_38F1B0.m_pkt = p + 8;
    p[8] = 1;
    D_38F1B0.m_pkt = p + 9;
    p[9] = (u64)v[2] | ((u64)v[1] << 16);
    D_38F1B0.m_pkt = p + 10;
    p[10] = 5;
    D_38F1B0.m_pkt = p + 11;
    p[11] = RGBAQ(c2 >> 24, c2 >> 16, c2 >> 8, c2, 0);
    D_38F1B0.m_pkt = p + 12;
    p[12] = 1;
    D_38F1B0.m_pkt = p + 13;
    p[13] = (u64)v[2] | ((u64)v[3] << 16);
    D_38F1B0.m_pkt = p + 14;
    p[14] = 5;
    D_38F1B0.m_pkt = p + 15;
    p[15] = RGBAQ(c3 >> 24, c3 >> 16, c3 >> 8, c3, 0);
    D_38F1B0.m_pkt = p + 16;
    p[16] = 1;
    D_38F1B0.m_pkt = p + 17;
    p[17] = (u64)v[0] | ((u64)v[3] << 16);
    D_38F1B0.m_pkt = p + 18;
    p[18] = 5;
    D_38F1B0.m_pkt = p + 19;
}

INCLUDE_ASM("asm/nonmatchings/Dk2470E8", func_00247FA8);

INCLUDE_ASM("asm/nonmatchings/Dk2470E8", func_00248298);

INCLUDE_ASM("asm/nonmatchings/Dk2470E8", func_00248760);

CPushBuf::CPushBuf() {
    m_unk0 = 0;
    m_unk4 = 0;
}

INCLUDE_ASM("asm/nonmatchings/Dk2470E8", _$_8CPushBuf);

extern "C" void func_00248C30(CPushBuf *p) {
    p->Func248E00();
    p->m_unk0 = (s32)(*D_002B91A4)(0);
    p->m_unk4 = 0;
}

extern "C" void func_00248C70(CPushBuf *p) {
    if (p->m_unk0) {
        if (p->m_unk4 > 0) (*D_002B91AC)((void *)p->m_unk0, p->m_unk4);
        else p->Func248E00();
    }
}

void *CPushBuf::Func248CC8(s32 size, s32 clear, s32 align) {
    void *p;
    if (align) m_unk4 = (m_unk4 + 15) & ~15;
    if (size <= 0) return 0;
    p = (void *)(m_unk0 + m_unk4);
    m_unk4 += size;
    if (clear) memset(p, 0, size);
    return p;
}

extern "C" char *func_00248D38(CPushBuf *b, const char *s) {
    char *p = (char *)b->Func248CC8(strlen(s) + 1, 0, 0);
    strcpy(p, s);
    return p;
}

extern "C" void *func_00248D98(CPushBuf *p) {
    return (void *)(p->m_unk0 + p->m_unk4);
}

extern "C" void *func_00248DA8(CPushBuf *p) {
    return func_00248D98(p);
}

extern "C" void *func_00248DC0(CPushBuf *p) {
    return p->Func248CC8(strlen((char *)func_00248DA8(p)) + 1, 0, 0);
}

void CPushBuf::Func248E00() {
    if (m_unk0) {
        (*D_002B91B0)((void *)m_unk0);
        m_unk0 = 0;
        m_unk4 = 0;
    }
}

void *Func248E48(const char *name) {
    return func_002303C0(name);
}

extern "C" void *func_00248E60(const char *name) {
    return func_002303E0(name);
}

extern "C" s32 func_00248E78(const char *name) {
    return func_0022DD20(name);
}

extern "C" s32 func_00248E90(CPushBuf *p) {
    return p->Func248EB0() > 0;
}

int CPushBuf::Func248EB0() {
    return func_0022FF58(this);
}

extern "C" s32 func_00248EC8(const char *name) {
    return func_002301B0(name);
}

void CPushBuf::Func248EE0(void *p) {
    return (void)func_0022FF18(this, p);
}

extern "C" void *func_00248EF8(const char *name, s32 *outSize) {
    void *buf = 0;
    s32 size, r;
    *outSize = 0;
    size = FileSize248EB0(name);
    if (size) {
        buf = (*D_002B91A4)(size);
        if (buf) {
            r = FileRead248EE0(name, buf);
            if (r == size) {
                *outSize = r;
                return buf;
            }
        }
    }
    if (buf) (*D_002B91B0)(buf);
    return 0;
}

extern "C" void func_00248FA8(void *p) {
    if (p) (*D_002B91B0)(p);
}

extern "C" void *func_00248FD0(const char *name, s32 *size) {
    return D_002B9E40(name, size);
}

extern "C" void func_00248FF8(void *p) {
    D_002B9E44(p);
}

extern "C" LoadFn func_00249020(LoadFn f) {
    LoadFn old = D_002B9E40;
    if (!f) f = func_00248EF8;
    D_002B9E40 = f;
    return old;
}

extern "C" UnloadFn func_00249048(UnloadFn f) {
    UnloadFn old = D_002B9E44;
    if (!f) f = func_00248FA8;
    D_002B9E44 = f;
    return old;
}

extern "C" s32 func_00249070(const char *name) {
    void *f = func_00248E60(name);
    if (!f) return 0;
    s32 t = func_001F1180();
    D_38F1B0.m_xpf[t][D_002B9E48[t]++] = func_00228C00();
    func_00228C38(f);
    return 1;
}

extern "C" void func_002490F8() {
    void *f = func_00228C00();
    if (!f) return (void)Func235DE0(D_002E6488);
    (*D_002B91B0)(f);
    s32 t = func_001F1180();
    s32 *pc = &D_002B9E48[t];
    if (*pc <= 0) return (void)Func235DE0(D_002E64A8);
    (*pc)--;
    func_00228C38(D_38F1B0.m_xpf[t][*pc]);
}

void Func2491A8(void *pbuf, const char *s, int isec, int ikey, int idef) {
    char *buf = (char *)pbuf;
    const char *sec = (const char *)isec;
    const char *key = (const char *)ikey;
    buf[0] = 0;
    if (s && *s) return (void)strcpy(buf, s);
    if (!sec || !*sec || !key || !*key) return;
    if (func_00235648(buf, sec, key) > 0) return;
    strcpy(buf, (const char *)idef);
}

s32 Func249248(void *pname) {
    const char *name = (const char *)pname;
    s32 type;
    if (D_002B9E50 >= 4) {
        Func235DE0(D_002E64D8);
        return 0;
    }
    if (strstr(name, D_002B9E54)) {
        if (!func_00249070(name)) return 0;
        type = 0;
    } else if (strstr(name, D_002B9E58)) {
        if (!func_0024A000(name)) return 0;
        type = 1;
    } else {
        func_0022DCE0();
        func_0022DC90(0);
        func_0022DC90(name);
        type = 2;
    }
    D_38F2B8[func_001F1180()][D_002B9E50++] = type;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/Dk2470E8", Func249348__Fv);

INCLUDE_ASM("asm/nonmatchings/Dk2470E8", func_00249428);

extern "C" void func_002494B0(const char *sec, const char *key) {
    char buf[0x100];
    if (func_00235648(buf, sec, key) >= 0 && strstr(buf, D_002E64D0)) {
        Func235DE0(D_002E6530, buf);
        func_0024A2E0(buf);
    }
}

extern "C" CDirStack *func_00249510() {
    return &D_38F2D8.m_stack[func_001F1180()];
}

extern "C" CDirEntry *func_00249550() {
    CDirStack *s = func_00249510();
    if (s->m_count <= 0) return 0;
    return &s->m_entries[s->m_count - 1];
}

extern "C" void func_00249598() {
    s32 i;
    memset(&D_38F2D8, 0, sizeof(CDirGlobal));
    for (i = 0; i < 16; i++) {
        D_38F2D8.m_nodes[i].m_next = D_38F2D8.m_free;
        D_38F2D8.m_free = &D_38F2D8.m_nodes[i];
    }
}

extern "C" void func_00249600() {
    s32 i;
    for (i = 0; i < 2; i++) {
        while (D_38F2D8.m_stack[i].m_count > 0) func_0024A098();
    }
    while (D_38F2D8.m_open) func_0024A2E0(D_38F2D8.m_open->m_name);
}

extern "C" void func_002496C0(s32 v) {
    D_38F2D8.m_unk4310 = v;
}

extern "C" s32 func_002496D0(u32 *p) {
    if (p && !((u32)p & 3) && *p == 0x46504158) return 1;
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/Dk2470E8", func_00249700);

extern "C" CDirEntry *func_00249748() {
    CDirStack *s = func_00249510();
    s32 n = s->m_count;
    if (n < 8) {
        s->m_count = n + 1;
        return func_00249550();
    }
    return 0;
}

extern "C" void func_00249790() {
    CDirStack *s = func_00249510();
    if (s->m_count > 0) s->m_count--;
}
