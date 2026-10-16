#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern void *D_002A07DC;

class CVec4 {
public:
    f32 x, y, z, w;
};

class CUnk237E90 {
public:
    void Func237E90(int v);
};

// Particle / effect node, kept on an active and a free list.
class CMapEffNode {
public:
    CMapEffNode *m_next;      // 0x0
    u8 pad4[0xC];
    f32 m_unk10;              // 0x10
    f32 m_unk14;              // 0x14
    f32 m_unk18;              // 0x18
    f32 m_unk1C;              // 0x1C
    f32 m_unk20;              // 0x20
};

class CMapEffParam {
public:
    u8 pad0[0x4];
    u32 m_unk4;               // 0x4
    u8 pad8[0x8];
    char m_name[0x34];        // 0x10
    s32 m_unk44;              // 0x44
    s32 m_unk48;              // 0x48
    u8 pad4C[0xC4];
    s32 m_unk110;             // 0x110
    f32 m_unk114;             // 0x114
    f32 m_unk118;             // 0x118
    u8 pad11C[0x10];
    s32 m_unk12C;             // 0x12C
};

class CMapEffTarget {
public:
    u8 pad0[0x220];
    CUnk237E90 m_unk220;      // 0x220
};

class CMapEffEntry {
public:
    s32 m_handle;             // 0x0
    s32 m_unk4;               // 0x4
    s32 m_unk8;               // 0x8
};

#include "CList.h"
class CMapEffObjRes : public CListTag {
public:
    CMapEffObjRes();
    virtual ~CMapEffObjRes();
    virtual s32 Load(const char *path);
    virtual void Vf11CF20();
    void Init();
    s32 Func11CC28();
    s32 LoadHandles();
    s32 LoadTables();
    s32 LoadEntries();
    s32 Func11CD60(s32 i, s32 v);
    s32 Func11CE50();

    s32 m_tables[31];         // 0x10
    s32 m_handles[13];        // 0x8C
    CMapEffEntry m_entries[7]; // 0xC0
};
extern CMapEffObjRes *D_002A06F0;

struct CMapEffRect {
    f32 x0, z0, x1, z1;
};
class CMapEffLeafWork {
public:
    s32 IsHit(s32 id);
    void FreeAll();
    void Func11FE20(s32 unused, CMapEffTarget *t);
    void Func11FE88(CMapEffTarget *t);
    void Func120298(CMapEffTarget *t);
    void Func11F5D8();
    void Func11F2A8();
    int Func11F390(f32 t);
    void Func11F0F8();
    void Func11F660();
    void Func11F9C0();

    CMapEffObjRes *m_res;     // 0x0
    CMapEffParam *m_param;    // 0x4
    u8 pad8[0x8];
    CMapEffRect m_rect;       // 0x10
    f32 m_unk20;              // 0x20
    f32 m_unk24;              // 0x24
    f32 m_unk28;              // 0x28
    f32 m_unk2C;              // 0x2C
    f32 m_unk30;              // 0x30
    f32 m_unk34;              // 0x34
    f32 m_unk38;              // 0x38
    f32 m_unk3C;              // 0x3C
    u8 pad40[0x4];
    CMapEffNode *m_active;    // 0x44
    CMapEffNode *m_free;      // 0x48
};

// Effect work base: vptr at 0, no fields of its own (vtable _vt$11CMapEffWork).
class CMapEffWork {
public:
    virtual ~CMapEffWork();
    virtual void Vf295830();
    virtual void Vf295838();
    virtual void Vf295840();
    virtual void Vf295848();
};

// The effect area as the work constructors read it (same object as CMapEffParam).
struct CMapEffArea {
    u8 pad0[0x10];
    CVec4 m_pts[16];          // 0x10
    s32 m_count;              // 0x110
    f32 m_unk114;             // 0x114
    f32 m_unk118;             // 0x118
    s32 m_unk11C;             // 0x11C
    s32 m_unk120;             // 0x120
    s32 m_unk124;             // 0x124
    s32 m_unk128;             // 0x128
};
struct CMapEffDrop {
    f32 x, y, z, w;           // 0x0
    s32 m10;                  // 0x10
    u8 pad14[0xC];
};
struct CMapEffFlake {
    CMapEffFlake *m_next;     // 0x0
    u8 pad4[0x18];
    f32 m_unk1C;              // 0x1C
    u8 pad20[0x10];
};
extern "C" void *func_00245678(u32 n);
class CMapEffRainWork : public CMapEffWork {
public:
    CMapEffRainWork(CMapEffArea *p);
    virtual ~CMapEffRainWork();
    void Func121810(CMapEffDrop *d, s32 v);
    void Spawn(const CVec4 *v);
    void Step();
    void Func121DE8(s32 unused, CMapEffTarget *t);
    void Func121E28(CMapEffTarget *t);
    void Func122088(CMapEffTarget *t);
    void Func121AD0();
    void Func121C18();

    CMapEffParam *m_param;    // 0x4
    s32 m_unk8;               // 0x8
    u8 padC[0x4];
    CMapEffRect m_rect;       // 0x10
    f32 m_unk20;              // 0x20
    f32 m_unk24;              // 0x24
    CMapEffDrop *m_drops;     // 0x28
    s32 m_unk2C;              // 0x2C
    CMapEffFlake *m_flakes;   // 0x30
    CMapEffNode *m_active;    // 0x34
    CMapEffNode *m_free;      // 0x38
};

class CMapEffSnowWork : public CMapEffWork {
public:
    CMapEffSnowWork(CMapEffArea *p);
    virtual ~CMapEffSnowWork();
    void Func122DD8(s32 v);
    void CallFunc122DD8(s32 unused, s32 v);
    void FreeAll();
    void Func122B38();
    void Func122808();
    int Func1228F0(f32 t);
    void Func122660();
    void Func122BC0();

    CMapEffArea *m_param;     // 0x4
    s32 m_unk8;               // 0x8
    u8 padC[0x4];
    CMapEffRect m_rect;       // 0x10
    f32 m_unk20;              // 0x20
    f32 m_unk24;              // 0x24
    f32 m_unk28;              // 0x28
    f32 m_unk2C;              // 0x2C
    f32 m_unk30;              // 0x30
    f32 m_unk34;              // 0x34
    CMapEffFlake *m_flakes;   // 0x38
    CMapEffNode *m_active;    // 0x3C
    CMapEffNode *m_free;      // 0x40
};

class CMapEffAquariumSub {
public:
    u8 pad0[0x4];
    s32 m_count;              // 0x4
};

class CMapEffAquariumFish {
public:
    CMapEffAquariumFish() {
        m_unk0 = 0;
        m_unk4 = 0;
        m_unk8 = 0;
    }
    s32 m_unk0;               // 0x0
    s32 m_unk4;               // 0x4
    s32 m_unk8;               // 0x8
};

struct CMapEffAquariumKey {
    f32 x;
    f32 m_time;               // 0x4
    f32 z;
    f32 w;
};
class CMapEffAquariumSlot {
public:
    CMapEffAquariumKey m_keys[16]; // 0x0
    CVec4 m_unk100;           // 0x100
    CMapEffAquariumFish m_fish; // 0x110
    f32 m_unk11C;             // 0x11C
    f32 m_unk120;             // 0x120
    f32 m_unk124;             // 0x124
    s32 m_unk128;             // 0x128
    s32 m_unk12C;             // 0x12C
    s32 m_busy;               // 0x130
    u8 pad134[0xC];
};

struct CMapEffAquaObj {
    CVec4 m_pos;              // 0x0
    CVec4 m_rot;              // 0x10
    u8 pad20[0x10];
    CVec4 m_col;              // 0x30
    f32 m_unk40;              // 0x40
    u8 pad44[0xC];
    f32 m_scale;              // 0x50
    f32 m_unk54;              // 0x54
    u8 pad58[0x4];
    s32 m_unk5C;              // 0x5C
    u8 pad60[0x4];
    s32 m_unk64;              // 0x64
    u8 pad68[0x8];
};
struct CMapEffAquaArg {
    u8 pad0[0x4];
    s32 m_unk4;               // 0x4
};
struct CMapEffAquaTarget {
    u8 pad0[0xF0];
    CUnk237E90 m_unkF0;       // 0xF0
};
class CMapEffAquariumWork : public CMapEffWork {
public:
    CMapEffAquariumWork(CMapEffAquariumSub *sub);
    virtual ~CMapEffAquariumWork();
    void Func1236C8(s32 i) throw();  // retail compiled it before its callers (nothrow calls)
    void CirclePos(CVec4 *out, CVec4 *c, f32 ang, f32 r);
    void Func1247F8();
    void Func123590();
    void Func1239E8(s32 i);
    void Func123D88(s32 i);
    void Func123E28(s32 i);
    void Func123F40(s32 i);
    void Func124000(s32 i);
    void UpdateOne(s32 i);
    void Func124160(s32 i);
    void UpdateAll();
    void Func124540();
    void Func124460(s32 i);
    void Func1245C8(CMapEffAquaArg *a, CMapEffAquaTarget *t);
    void Func1246A8();
    void Func124888(CMapEffAquaTarget *t, s32 i);
    void Func124AA0(CMapEffAquaTarget *t);
    void Func123850(s32 i, s32 k);

    u8 pad4[0xC];
    CMapEffAquaObj m_objs[128]; // 0x10
    CMapEffAquariumSlot m_slots[8]; // 0x3810
    u32 m_seed;               // 0x4210
    CMapEffAquariumSub *m_sub; // 0x4214
    s32 m_unk4218;            // 0x4218
    s32 m_unk421C;            // 0x421C
    s32 m_unk4220;            // 0x4220
    s32 m_count;              // 0x4224
    u8 pad4228[0x8];
    CVec4 m_unk4230[3];       // 0x4230
    CVec4 m_unk4260[3];       // 0x4260
    CVec4 m_unk4290;          // 0x4290
    f32 m_unk42A0;            // 0x42A0
    f32 m_unk42A4;            // 0x42A4
    s32 m_unk42A8;            // 0x42A8
    s32 m_unk42AC;            // 0x42AC
    s32 m_unk42B0;            // 0x42B0
};

struct CMapEffCurtainPt {
    CVec4 m0;                 // 0x0
    u8 pad10[0x30];
    CVec4 m40;                // 0x40
    s32 m50;                  // 0x50
    s32 m54;                  // 0x54
    f32 m58;                  // 0x58
    u8 pad5C[0x14];
};
class CMapEffCurtainWork {
public:
    void Func11E548();
    void Func11D8C8();
    void Func11E1C0();
    void Func11D6E0();

    CMapEffObjRes *m_res;     // 0x0
    CMapEffParam *m_param;    // 0x4
    u8 pad8[0x8];
    f32 m_unk10;              // 0x10
    s32 m_unk14;              // 0x14
    u8 pad18[0x8];
    CMapEffCurtainPt *m_pts;  // 0x20
};

struct CMapEffBreathNode {
    CMapEffBreathNode *m_next; // 0x0
    s32 m_unk4;               // 0x4
    s32 m_unk8;               // 0x8
};
struct CMapEffBreathPart {
    CMapEffBreathPart *m_next; // 0x0
    u8 pad4[0xC];
    CVec4 m10;                // 0x10
    f32 m20, m24, m28, m2C;   // 0x20
    f32 m30, m34;             // 0x30
    u8 pad38[0x8];
};
class CMapEffBreathWork : public CMapEffWork {
public:
    CMapEffBreathWork(CMapEffParam *p);
    virtual ~CMapEffBreathWork();
    void Func1259C8(s32 v);
    void Func125A18(s32 v);
    void Func125BA8(s32 v);
    void Func125C38();
    void Func126068();
    void Func125DB8(CMapEffBreathNode *n, s32 v);

    CMapEffParam *m_param;    // 0x4
    s32 m_unk8;               // 0x8
    CMapEffBreathNode m_nodes[16]; // 0xC
    s32 m_unkCC;              // 0xCC
    CMapEffBreathNode *m_freeNodes; // 0xD0
    u8 padD4[0xC];
    CMapEffBreathPart m_parts[256]; // 0xE0
    CMapEffBreathPart *m_unk40E0; // 0x40E0 (active list)
    CMapEffBreathPart *m_freeParts; // 0x40E4
};

class CMapEffSwingDef {
public:
    s32 m_id;                 // 0x0
    s32 m_count;              // 0x4
    u8 pad8[0x10];
    s32 m_kind[4];            // 0x18
    u8 pad28[0x10];
    f32 m_times[4];           // 0x38
};
extern CMapEffSwingDef D_002A0998[];

class CMapEffSwingParam {
public:
    u8 pad0[0x4];
    s32 m_unk4;               // 0x4
};

class CMapEffSwingWork : public CMapEffWork {
public:
    CMapEffSwingWork(CMapEffSwingParam *p);
    virtual ~CMapEffSwingWork();
    void Func126BD8();
    void Func1266B0();
    void Func126860(s32 i);
    void Func126970();
    void Func126A20(s32 unused, s32 a);
    void Func126AC0();
    void Func126C48(s32 a, s32 i);

    s32 m_unk4;               // 0x4
    CMapEffSwingParam *m_unk8; // 0x8
    s32 m_unkC;               // 0xC
    s32 m_def;                // 0x10
    u8 pad14[0xC];
    CVec4 m_unk20[3];         // 0x20
    CVec4 m_unk50[3];         // 0x50
    CVec4 m_unk80;            // 0x80
    s32 m_unk90;              // 0x90
};

class CMapEffWork126640 {
public:
    f32 GetKindTime(CMapEffWork126640 *w, s32 i);
    u8 pad0[0x18];
    s32 m_kind[1];            // 0x18
};

int ApplyDefaultLights();
void Func225088();
int Func2250C0();
s32 Func202308();
s32 Func202338();
void Func225470(s32 v);
void Func2255A8(s32 v);
s32 Func251B88();
s32 Func205598(const char *name);
void Func235DE0(const char *fmt, ...);
f32 Func1EAC30(s32 h);
void Func201D78(CVec4 *v);
void Func201CC0(s32 i, CVec4 *v);
void Func201D18(s32 i, CVec4 *v);
void Func201E30(f32 a, f32 b);
void Func201DE0(s32 a, s32 b, s32 c);
CVec4 *Func2023B8(s32 i);
CVec4 *Func2023A0(s32 i);
CVec4 *Func202390();
void Func270C50(CVec4 *dst, const CVec4 *src);
void *Func248E48(const char *name);
s32 Func205BA0(void *p);
extern void (*D_002B91B0)(void *p);
extern const char *D_002A06F8[31];
extern const char *D_002A07B0[7];
extern s32 D_002D4A08[7];
extern const char D_002D4588[];
extern const char D_002D4618[];
extern CVec4 D_002D4640, D_002D4650, D_002D4660;
extern CVec4 D_002D4670, D_002D4680, D_002D4690;
extern CVec4 D_002D46A0;
void Func2491A8(void *buf, const char *path, s32 a, s32 b, s32 c);
s32 Func249248(void *buf);
void Func249348();
extern const char *D_002A0778[13];
extern const char D_002D45A8[];
extern s32 D_002A07D0;
extern s32 D_002A07D4;
extern s32 D_002A07D8;

extern const double D_002D4750;
extern const double D_002D47D0;
extern "C" void func_001ECE18(s32 a, s32 b, f32 t);
extern "C" s32 func_0011B428(s32 a, f32 t, s32 b);

extern "C" void func_00201E50(f32 *a, f32 *b);
extern "C" void func_00201E08(s32 *a, s32 *b, s32 *c);
extern CVec4 D_002D4890, D_002D48A0, D_002D48B0, D_002D48C0, D_002D48D0, D_002D48E0, D_002D48F0;
extern CVec4 D_002D47E0, D_002D47F0, D_002D4800, D_002D4810, D_002D4820, D_002D4830;
extern CVec4 D_002A0830[];
inline s32 RingEmpty(CMapEffAquariumFish *f) { return f->m_unk8 ? f->m_unk0 == f->m_unk4 : 1; }
inline s32 RingFull(CMapEffAquariumFish *f) { return f->m_unk8 ? f->m_unk0 == (f->m_unk4 + 1) % f->m_unk8 : 1; }
inline s32 RingPeek(CMapEffAquariumFish *f) { return RingEmpty(f) ? -1 : f->m_unk0; }
inline void RingPop(CMapEffAquariumFish *f) { if (!RingEmpty(f)) f->m_unk0 = (f->m_unk0 + 1) % f->m_unk8; }
inline s32 RingPush(CMapEffAquariumFish *f) {
    if (RingFull(f)) return -1;
    s32 k = f->m_unk4;
    f->m_unk4 = (f->m_unk4 + 1) % f->m_unk8;
    return k;
}
inline s32 RingNext(CMapEffAquariumFish *f, s32 k) {
    if (RingEmpty(f) || k < 0 || f->m_unk8 - 1 < k) return -1;
    s32 n = (k + 1) % f->m_unk8;
    return n == f->m_unk4 ? -1 : n;
}
struct CMapEffRand {
    u32 m_seed;
    u32 Next() {
        m_seed = m_seed * 0x19660D + 1;
        return (m_seed >> 12) & 0xFFFF;
    }
    u32 Next32() {
        u32 r = Next() << 16;
        r |= Next();
        return r;
    }
    f32 Range(f32 lo, f32 hi) {
        return (f32)(s32)(Next32() & 0xFFFF) / 65535.0f * (hi - lo) + lo;
    }
};

inline void CalcRect(CMapEffRect *r, CMapEffArea *a) {
    CVec4 *p = a->m_pts;
    s32 n = a->m_count;
    s32 i;
    r->x0 = r->x1 = p->x;
    r->z0 = r->z1 = p->z;
    for (i = 1; i < n; i++) {
        CVec4 *q = &p[i];
        f32 x = q->x;
        f32 z = q->z;
        if (x < r->x0) r->x0 = x;
        if (z < r->z0) r->z0 = z;
        if (r->x1 < x) r->x1 = x;
        if (r->z1 < z) r->z1 = z;
    }
}

void Func23B1D0(s32 h);
extern "C" void func_001F20F8(s32 h);
extern "C" s32 func_001EB920(s32 p, s32 i);
extern "C" s32 func_001EADA0(s32 a);
extern "C" void func_001ECCA8(s32 h);
extern const char D_002D45C8[];
extern const char D_002D45F0[];
inline CListTag *ListNext(CListTag *t) {
    CListTag *n = t->m_next;
    return n->m_isHead ? 0 : n;
}
inline CListTag *ListFirst(CListTag *h) {
    CListTag *r;
    if (!h->m_next->m_isHead) r = h->m_next; else r = 0;
    return r;
}
inline s32 ListIndexOf(CListTag *head, void *x) {
    CListTag *t = ListFirst(head);
    s32 i = 0;
    while (t) {
        if (t == x) return i;
        t = ListNext(t);
        i++;
    }
    return -1;
}

struct CMapEffBreathRes {
    u8 pad0[0x20];
    char m_name[0x10];        // 0x20
};
struct CMapEffBreathObj {
    u8 pad0[0x14];
    CMapEffBreathRes *m_res;  // 0x14
    u8 pad18[0x154];
    s32 m_flags;              // 0x16C
};
extern const char *D_002A08B0[];
extern "C" int strncmp(const char *a, const char *b, unsigned int n);
inline s32 RandInt(CMapEffRand *r, s32 lo, s32 hi) {
    if (hi < lo) hi = lo;
    if (lo == hi) return lo;
    return r->Next32() % (hi - lo + 1) + lo;
}

extern f32 D_002A6800[];
inline s32 FtoI15(f32 f) {
    s32 r;
    asm volatile("mfc1 %0, %1\n\tqmtc2.ni %0, $vf2\n\tvftoi15.x $vf2, $vf2\n\tqmfc2.ni %0, $vf2" : "=r"(r) : "f"(f));
    return r;
}

inline f32 TblSin(f32 a) { return D_002A6800[(FtoI15(a) >> 1) & 0x3FFF]; }
inline f32 TblCos(f32 a) { return D_002A6800[(((FtoI15(a) >> 1) & 0x3FFF) + 0x1000) & 0x3FFF]; }

s32 Func24E0F0(const char *a, s32 b, s32 c);
struct CMapEffSnowNode {
    CMapEffSnowNode *m_next;  // 0x0
    s32 m4;                   // 0x4
    u8 pad8[0x8];
    CVec4 m10;                // 0x10
    f32 m20;                  // 0x20
    f32 m24;                  // 0x24
    s32 m28;                  // 0x28
};

inline f32 Rand01(CMapEffRand *r) { return (f32)(s32)(r->Next32() & 0xFFFF) / 65535.0f; }
extern "C" void func_00270A98(CVec4 *d, const CVec4 *a, const CVec4 *b);
extern "C" void func_00270B00(CVec4 *d, const CVec4 *a, const CVec4 *b);
inline f32 VuSqrt(f32 x) {
    f32 r;
    asm volatile("mfc1 $8, %1\n\tqmtc2.ni $8, $vf2\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(r) : "f"(x) : "$8");
    return r;
}
struct CMapEffLeafNode {
    CMapEffLeafNode *m_next;  // 0x0
    u8 pad4[0xC];
    CVec4 m10;                // 0x10
    u8 pad20[0x14];
    f32 m34;                  // 0x34
};

struct CMapEffLeafNode2 {
    CMapEffLeafNode2 *m_next; // 0x0
    s32 m4;                   // 0x4
    u8 pad8[0x8];
    CVec4 m10;                // 0x10
    u8 pad20[0x10];
    s32 m30;                  // 0x30
    f32 m34;                  // 0x34
    f32 m38;                  // 0x38
    s32 m3C;                  // 0x3C
};

#define MIN123(a, b) ((a) < (b) ? (a) : (b))
#define MAX123(a, b) ((a) < (b) ? (b) : (a))

inline u32 RandMod(CMapEffRand *r, u32 n) { return r->Next32() % n; }
// @decl-end

CMapEffObjRes::CMapEffObjRes() {
    s32 i;
    for (i = 0; i < 31; i++) m_tables[i] = -1;
    for (i = 0; i < 13; i++) m_handles[i] = -1;
    for (i = 0; i < 7; i++) {
        m_entries[i].m_handle = -1;
        m_entries[i].m_unk4 = 0;
        m_entries[i].m_unk8 = 0;
    }
}

s32 CMapEffObjRes::Load(const char *path) {
    u8 buf[0x100];
    D_002A06F0 = this;
    Func2491A8(buf, path, D_002A07D0, D_002A07D4, D_002A07D8);
    if (!Func249248(buf)) {
        return 0;
    }
    if (!Func11CC28()) {
        return 0;
    }
    if (!LoadHandles()) {
        return 0;
    }
    if (!Func11CE50()) {
        return 0;
    }
    Func249348();
    return 1;
}

s32 CMapEffObjRes::Func11CC28() {
    s32 i;
    for (i = 0; i < 31; i++) {
        void *p = Func248E48(D_002A06F8[i]);
        if (!p) {
            Func235DE0(D_002D4588, D_002A06F8[i]);
        } else {
            m_tables[i] = Func205BA0(p);
            D_002B91B0(p);
        }
    }
    return 1;
}

s32 CMapEffObjRes::LoadHandles() {
    s32 i;
    for (i = 0; i < 13; i++) {
        m_handles[i] = Func205598(D_002A0778[i]);
        if (m_handles[i] < 0) {
            Func235DE0(D_002D45A8, D_002A0778[i]);
        }
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", Func11CD60__13CMapEffObjResii);

s32 CMapEffObjRes::Func11CE50() {
    s32 i;
    for (i = 0; i < 7; i++) {
        void *p = Func248E48(D_002A07B0[i]);
        m_entries[i].m_unk4 = (s32)p;
        if (!p) {
            Func235DE0(D_002D4618, D_002A07B0[i]);
        } else {
            Func11CD60(i, D_002D4A08[i]);
        }
    }
    return 1;
}

void CMapEffObjRes::Vf11CF20() {
    s32 i;
    for (i = 0; i < 31; i++) {
        if (m_tables[i] >= 0) {
            Func23B1D0(m_tables[i]);
            m_tables[i] = -1;
        }
    }
    for (i = 0; i < 13; i++) {
        if (m_handles[i] >= 0) {
            func_001F20F8(m_handles[i]);
            m_handles[i] = -1;
        }
    }
    for (i = 0; i < 7; i++) {
        if (m_entries[i].m_handle >= 0) {
            func_001ECCA8(m_entries[i].m_handle);
            m_entries[i].m_handle = -1;
        }
        if (m_entries[i].m_unk8) {
            D_002B91B0((void *)m_entries[i].m_unk8);
            m_entries[i].m_unk8 = 0;
        }
        if (m_entries[i].m_unk4) {
            D_002B91B0((void *)m_entries[i].m_unk4);
            m_entries[i].m_unk4 = 0;
        }
    }
    D_002A06F0 = 0;
}

int ApplyDefaultLights() {
    Func201CC0(0, &D_002D4640);
    Func201CC0(1, &D_002D4650);
    Func201CC0(2, &D_002D4660);
    Func201D18(0, &D_002D4670);
    Func201D18(1, &D_002D4680);
    Func201D18(2, &D_002D4690);
    Func201D78(&D_002D46A0);
    Func225088();
    Func225470(Func202308());
    Func2255A8(Func202338());
    return Func2250C0();
}

void GetLights(CVec4 *dir, CVec4 *col, CVec4 *amb) {
    if (dir) {
        Func270C50(&dir[0], Func2023B8(0));
        Func270C50(&dir[1], Func2023B8(1));
        Func270C50(&dir[2], Func2023B8(2));
    }
    if (col) {
        Func270C50(&col[0], Func2023A0(0));
        Func270C50(&col[1], Func2023A0(1));
        Func270C50(&col[2], Func2023A0(2));
    }
    if (amb) {
        Func270C50(amb, Func202390());
    }
}

void SetLights(CVec4 *dir, CVec4 *col, CVec4 *amb) {
    if (dir) {
        Func201CC0(0, &dir[0]);
        Func201CC0(1, &dir[1]);
        Func201CC0(2, &dir[2]);
    }
    if (col) {
        Func201D18(0, &col[0]);
        Func201D18(1, &col[1]);
        Func201D18(2, &col[2]);
    }
    if (amb) {
        Func201D78(amb);
    }
}

int ApplyLights(CVec4 *dir, CVec4 *col, CVec4 *amb) {
    SetLights(dir, col, amb);
    Func225088();
    Func225470(Func202308());
    Func2255A8(Func202338());
    return Func2250C0();
}

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", func_0011D2D8);

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", func_0011D670);

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", func_0011D6E0);

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", Func11D8C8__18CMapEffCurtainWork);

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", Func11E1C0__18CMapEffCurtainWork);

void CMapEffCurtainWork::Func11E548() {
    m_unk10 = (f32)m_param->m_unk48 * 0.2f / 100.0f + 0.0f;
    m_unk14 = m_param->m_unk44 * 70 / 100 + 90;
    Func11D8C8();
    Func11E1C0();
}

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", func_0011E5E8);

void CMapEffObjRes::Init() {
    D_002A07DC = this;
}

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", func_0011ED80);

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", func_0011F038);

s32 CMapEffLeafWork::IsHit(s32 id) {
    if (m_param->m_unk4 < 2 && id == -800) {
        return 1;
    }
    if (m_param->m_unk4 == 2 && id == -700) {
        return 1;
    }
    return id == -200;
}

void CMapEffLeafWork::Func11F0F8() {
    CalcRect(&m_rect, ((CMapEffArea *)m_param));
    m_unk24 = (f32)((CMapEffArea *)m_param)->m_unk120 / 360.0f;
    m_unk28 = (f32)((CMapEffArea *)m_param)->m_unk124 * (0.1f - 0.0f) / 100.0f + 0.0f;
    m_unk2C = (f32)((CMapEffArea *)m_param)->m_unk128 * (0.07f - 1.0f) / 100.0f + 1.0f;
    if (m_unk34 != m_unk2C) {
        Func11F2A8();
        m_unk34 = m_unk2C;
    }
    Func11F5D8();
    Func11F660();
    Func11F9C0();
}

void CMapEffLeafWork::FreeAll() {
    CMapEffNode *p;
    while ((p = m_active) != 0) {
        m_active = p->m_next;
        p->m_next = m_free;
        m_free = p;
    }
}

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", Func11F2A8__15CMapEffLeafWork);

int CMapEffLeafWork::Func11F390(f32 t) {
    CVec4 p;
    CMapEffRand *r;
    CMapEffLeafNode2 *n;
    f32 tz;
    f32 k;
    if (!m_free) return 0;
    r = (CMapEffRand *)pad8;
    tz = Rand01(r);
    p.y = -(m_param->m_unk114 + m_param->m_unk118) * (1.0f - t);
    p.x = r->Range(m_rect.x0, m_rect.x1);
    p.z = m_rect.z0 + (m_rect.z1 - m_rect.z0) * (tz * tz);
    p.w = 1.0f;
    if (!Func24E0F0(m_param->m_name, m_param->m_unk110, (s32)&p)) return 0;
    k = -p.y / m_unk20;
    p.x += -TblSin(m_unk24) * m_unk28 * k * t;
    p.z += -TblCos(m_unk24) * m_unk28 * k * t;
    n = (CMapEffLeafNode2 *)m_free;
    m_free = (CMapEffNode *)n->m_next;
    n->m4 = 0;
    Func270C50(&n->m10, &p);
    n->m30 = 0;
    n->m38 = 1.0f;
    n->m34 = m_unk28;
    n->m3C = 0;
    n->m_next = (CMapEffLeafNode2 *)m_active;
    m_active = (CMapEffNode *)n;
    return 1;
}

void CMapEffLeafWork::Func11F5D8() {
    while (m_unk2C < m_unk30 && m_free) {
        Func11F390(0.0f);
        m_unk30 -= m_unk2C;
    }
    m_unk30 += 1.0f / 59.94f;
}

void CMapEffLeafWork::Func11F660() {
    m_unk3C += m_unk38;
    if (1.0f < m_unk3C) {
        m_unk3C = 0.0f;
        m_unk38 = 1.0f / (f32)(s32)(((CMapEffRand *)pad8)->Next32() % 181 + 120);
    }
    if (0.0f < m_unk3C) {
        CVec4 a;
        CVec4 b;
        CVec4 c;
        CVec4 d;
        f32 r;
        f32 ang;
        f32 hi;
        f32 lo;
        f32 r2;
        CMapEffLeafNode *n;
        a.x = m_rect.x0;
        a.y = 0.0f;
        a.z = m_rect.z0;
        a.w = 1.0f;
        b.x = (m_rect.x0 + m_rect.x1) * 0.5f;
        b.y = 0.0f;
        b.z = (m_rect.z0 + m_rect.z1) * 0.5f;
        b.w = 1.0f;
        func_00270A98(&c, &b, &a);
        func_00270B00(&d, &c, &c);
        r = VuSqrt(d.x + d.y + d.z);
        ang = m_unk24 + 0.25f;
        b.x = -TblSin(ang) * r;
        b.z = -TblCos(ang) * r;
        hi = m_unk3C;
        lo = m_unk3C - m_unk38;
        r2 = r + r;
        for (n = (CMapEffLeafNode *)m_active; n; n = n->m_next) {
            f32 t;
            func_00270A98(&c, &n->m10, &b);
            func_00270B00(&d, &c, &c);
            t = VuSqrt(d.x + d.y + d.z) / r2;
            if (t <= lo || hi < t) continue;
            n->m34 += m_unk28 * ((CMapEffRand *)pad8)->Range(-0.5f, 1.2f);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", Func11F9C0__15CMapEffLeafWork);

void CMapEffLeafWork::Func11FE20(s32 unused, CMapEffTarget *t) {
    t->m_unk220.Func237E90(ApplyDefaultLights());
    if (m_param->m_unk12C == 1) {
        Func11FE88(t);
    }
    Func120298(t);
}

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", Func11FE88__15CMapEffLeafWorkP13CMapEffTarget);

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", Func120298__15CMapEffLeafWorkP13CMapEffTarget);

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", func_001207C0);

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", func_00120AC8);

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", func_00120B38);

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", func_00120CB8);

CMapEffRainWork::CMapEffRainWork(CMapEffArea *p) {
    s32 i;
    m_param = (CMapEffParam *)p;
    m_unk8 = 1;
    CalcRect(&m_rect, p);
    m_unk20 = (f32)((CMapEffArea *)m_param)->m_unk11C / 360.0f;
    m_unk24 = (f32)((CMapEffArea *)m_param)->m_unk120 * 10.0f / 100.0f + 0.0f;
    m_drops = new CMapEffDrop[128];
    m_unk2C = ((((CMapEffArea *)m_param)->m_unk124 > 128 ? 128 : ((CMapEffArea *)m_param)->m_unk124) << 7) / 100;
    for (i = 0; i < 128; i++) Func121810(&m_drops[i], 1);
    m_flakes = new CMapEffFlake[128];
    m_active = 0;
    m_free = 0;
    for (i = 0; i < 128; i++) {
        CMapEffFlake *f = &m_flakes[i];
        f->m_unk1C = 1.0f;
        f->m_next = (CMapEffFlake *)m_free;
        m_free = (CMapEffNode *)f;
    }
}

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", func_00121788);

void CMapEffRainWork::Func121810(CMapEffDrop *d, s32 top) {
    CVec4 p;
    CMapEffRand *r = (CMapEffRand *)&m_unk8;
    f32 t;
    f32 dy;
    p.x = r->Range(m_rect.x0, m_rect.x1);
    if (top) {
        f32 h = -m_param->m_unk114;
        p.y = r->Range(h + h - 50.0f, h);
    } else {
        p.y = -m_param->m_unk114;
    }
    t = (f32)(s32)(r->Next32() & 0xFFFF) / 65535.0f;
    p.z = m_rect.z0 + (m_rect.z1 - m_rect.z0) * (t * t);
    d->m10 = Func24E0F0(m_param->m_name, m_param->m_unk110, (s32)&p);
    dy = (m_param->m_unk118 - p.y) / 5.0f;
    d->x = p.x - TblSin(m_unk20) * m_unk24 * dy;
    d->y = p.y;
    d->z = p.z - TblCos(m_unk20) * m_unk24 * dy;
}

void CMapEffRainWork::Spawn(const CVec4 *v) {
    CMapEffNode *p = m_free;
    if (p) {
        m_free = p->m_next;
        p->m_unk10 = v->x;
        p->m_unk14 = m_param->m_unk118;
        p->m_unk18 = v->z;
        p->m_unk1C = 1.0f;
        p->m_unk20 = 0.0f;
        p->m_next = m_active;
        m_active = p;
    }
}

void CMapEffRainWork::Func121AD0() {
    CalcRect(&m_rect, ((CMapEffArea *)m_param));
    m_unk20 = (f32)((CMapEffArea *)m_param)->m_unk11C / 360.0f;
    m_unk24 = (f32)((CMapEffArea *)m_param)->m_unk120 * 10.0f / 100.0f + 0.0f;
    m_unk2C = ((((CMapEffArea *)m_param)->m_unk124 > 128 ? 128 : ((CMapEffArea *)m_param)->m_unk124) << 7) / 100;
    Func121C18();
    Step();
}

void CMapEffRainWork::Func121C18() {
    s32 i;
    for (i = 0; i < m_unk2C; i++) {
        CMapEffDrop *d = &m_drops[i];
        f32 y = d->y;
        d->x += TblSin(m_unk20) * m_unk24;
        d->y = y + 5.0f;
        d->z += TblCos(m_unk20) * m_unk24;
        if (y < m_param->m_unk118 && m_param->m_unk118 <= d->y && d->m10) Spawn((CVec4 *)d);
        if (m_param->m_unk118 + 50.0f < d->y) Func121810(d, 0);
    }
}

void CMapEffRainWork::Step() {
    CMapEffNode **pp = &m_active;
    CMapEffNode *p;
    while ((p = *pp) != 0) {
        p->m_unk20 += 0.0625f;
        if (p->m_unk20 > 1.0f) {
            *pp = p->m_next;
            p->m_next = m_free;
            m_free = p;
        } else {
            pp = &p->m_next;
        }
    }
}

void CMapEffRainWork::Func121DE8(s32 unused, CMapEffTarget *t) {
    Func121E28(t);
    Func122088(t);
}

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", Func121E28__15CMapEffRainWorkP13CMapEffTarget);

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", Func122088__15CMapEffRainWorkP13CMapEffTarget);

CMapEffSnowWork::CMapEffSnowWork(CMapEffArea *p) {
    s32 i;
    m_param = p;
    m_unk8 = 1;
    CalcRect(&m_rect, p);
    m_unk20 = 0.08f;
    m_unk28 = (f32)m_param->m_unk120 / 360.0f;
    m_unk24 = (f32)m_param->m_unk124 * (0.1f - 0.0f) / 100.0f + 0.0f;
    m_unk2C = 0.0f;
    m_unk30 = (f32)m_param->m_unk128 * (0.05f - 1.0f) / 100.0f + 1.0f;
    m_unk34 = 0.0f;
    m_flakes = new CMapEffFlake[128];
    m_active = 0;
    m_free = 0;
    for (i = 0; i < 128; i++) {
        CMapEffFlake *f = &m_flakes[i];
        f->m_next = (CMapEffFlake *)m_free;
        m_free = (CMapEffNode *)f;
    }
}

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", func_001225F0);

void CMapEffSnowWork::Func122660() {
    CalcRect(&m_rect, m_param);
    m_unk28 = (f32)m_param->m_unk120 / 360.0f;
    m_unk24 = (f32)m_param->m_unk124 * (0.1f - 0.0f) / 100.0f + 0.0f;
    m_unk30 = (f32)m_param->m_unk128 * (0.05f - 1.0f) / 100.0f + 1.0f;
    if (m_unk34 != m_unk30) {
        Func122808();
        m_unk34 = m_unk30;
    }
    Func122B38();
    Func122BC0();
}

void CMapEffSnowWork::FreeAll() {
    CMapEffNode *p;
    while ((p = m_active) != 0) {
        m_active = p->m_next;
        p->m_next = m_free;
        m_free = p;
    }
}

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", Func122808__15CMapEffSnowWork);

int CMapEffSnowWork::Func1228F0(f32 t) {
    CVec4 p;
    CMapEffRand *r;
    CMapEffSnowNode *n;
    f32 tz;
    f32 k;
    if (!m_free) return 0;
    r = (CMapEffRand *)&m_unk8;
    tz = Rand01(r);
    p.x = r->Range(m_rect.x0, m_rect.x1);
    p.y = -m_param->m_unk114 * (1.0f - t);
    p.z = m_rect.z0 + (m_rect.z1 - m_rect.z0) * (tz * tz);
    p.w = 1.0f;
    if (!Func24E0F0((const char *)m_param->m_pts, m_param->m_count, (s32)&p)) return 0;
    k = -p.y / m_unk20;
    p.x += -TblSin(m_unk28) * m_unk24 * k * t;
    p.z += -TblCos(m_unk28) * m_unk24 * k * t;
    n = (CMapEffSnowNode *)m_free;
    m_free = (CMapEffNode *)n->m_next;
    n->m4 = 0;
    Func270C50(&n->m10, &p);
    n->m20 = 0.0f;
    if (t == n->m20) {
        n->m24 = n->m20;
    } else {
        n->m24 = 1.0f;
    }
    n->m28 = 0;
    n->m_next = (CMapEffSnowNode *)m_active;
    m_active = (CMapEffNode *)n;
    return 1;
}

void CMapEffSnowWork::Func122B38() {
    while (m_unk30 < m_unk2C && m_free) {
        Func1228F0(0.0f);
        m_unk2C -= m_unk30;
    }
    m_unk2C += 1.0f / 59.94f;
}

void CMapEffSnowWork::Func122BC0() {
    CMapEffSnowNode **pp = (CMapEffSnowNode **)&m_active;
    CMapEffSnowNode *n;
    while ((n = *pp) != 0) {
        switch (n->m4) {
        case 0:
            n->m24 += 0.011111111f;
            n->m24 = n->m24 < 1.0f ? n->m24 : 1.0f;
            n->m10.x += TblSin(m_unk28) * m_unk24;
            n->m10.y += m_unk20;
            n->m10.z += TblCos(m_unk28) * m_unk24;
            if (n->m10.y < m_param->m_unk118) break;
            n->m4++;
        case 1:
            n->m24 -= 0.0055555555f;
            break;
        }
        if (n->m28) {
            n->m24 -= 0.016666666f;
        } else if (0.0f < n->m10.y && !Func24E0F0((const char *)m_param->m_pts, m_param->m_count, (s32)&n->m10)) {
            n->m28 = 1;
        }
        if (n->m24 <= 0.0f) {
            *pp = n->m_next;
            n->m_next = (CMapEffSnowNode *)m_free;
            m_free = (CMapEffNode *)n;
        } else {
            pp = &n->m_next;
        }
    }
}

void CMapEffSnowWork::CallFunc122DD8(s32 unused, s32 v) {
    Func122DD8(v);
}

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", Func122DD8__15CMapEffSnowWorki);

CMapEffAquariumWork::CMapEffAquariumWork(CMapEffAquariumSub *sub) {
    m_seed = 1;
    m_sub = sub;
    m_unk4220 = -1;
    m_unk421C = -1;
    m_unk4218 = 0;
    m_count = 0;
}

void CMapEffAquariumWork::Func123590() {
    u32 *p = &m_seed;
    if (D_002A06F0) {
        m_unk4220 = D_002A06F0->m_handles[6];
        m_unk421C = D_002A06F0->m_entries[0].m_handle;
        m_unk4218 = D_002A06F0->m_entries[0].m_unk8;
        *p = Func251B88();
    }
}

void CMapEffAquariumWork::CirclePos(CVec4 *out, CVec4 *c, f32 ang, f32 r) {
    out->x = c->x + r * D_002A6800[(FtoI15(ang) >> 1) & 0x3FFF];
    out->z = c->z + r * D_002A6800[(((FtoI15(ang) >> 1) & 0x3FFF) + 0x1000) & 0x3FFF];
    out->w = 1.0f;
}

extern "C" f32 func_00123670(f32 a, f32 b, f32 lim) { f32 d = b - a; f32 t = MAX123(MIN123(d, lim), -lim); return a + t; }

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", Func1236C8__19CMapEffAquariumWorki);

void CMapEffAquariumWork::Func123850(s32 i, s32 k) {
    if ((u32)i < 8 && (u32)k < 16) {
        CMapEffRand *r = (CMapEffRand *)&m_seed;
        CMapEffAquariumSlot *s = &m_slots[i];
        CMapEffAquariumKey *key = &s->m_keys[k];
        f32 a = s->m_unk11C;
        key->x = s->m_unk100.x + r->Range(-a, a);
        key->m_time = s->m_unk100.y + r->Range(-a / 5.0f, a / 5.0f);
        key->z = s->m_unk100.z + r->Range(-a, a);
        key->w = s->m_unk100.w;
    }
}

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", Func1239E8__19CMapEffAquariumWorki);

void CMapEffAquariumWork::Func123D88(s32 i) { if ((u32)i < 8) { CMapEffAquariumSlot *s = &m_slots[i]; if (!s->m_busy) { if (RandMod((CMapEffRand *)&m_seed, 501) == 100) Func1236C8(i); } } }

void CMapEffAquariumWork::Func123E28(s32 i) {
    if ((u32)i < 8) {
        CMapEffAquariumSlot *s = &m_slots[i];
        s32 now = Func251B88();
        s32 n = (s32)((f32)(now - s->m_unk12C) * s->m_unk124);
        if (n != 0) {
            s->m_unk12C = now;
            if (s->m_busy) {
                s32 j;
                for (j = 0; j < n; j++) {
                    Func123850(i, RingPush(&s->m_fish));
                }
            }
        }
    }
}

void CMapEffAquariumWork::Func123F40(s32 i) {
    if ((u32)i < 8) {
        CMapEffAquariumSlot *s = &m_slots[i];
        s32 k;
        while ((k = RingPeek(&s->m_fish)) != -1) {
            if (s->m_unk120 < (s->m_keys + k)->m_time) break;
            RingPop(&s->m_fish);
        }
    }
}

void CMapEffAquariumWork::Func124000(s32 i) {
    if ((u32)i < 8) {
        CMapEffAquariumSlot *s = &m_slots[i];
        s32 k;
        for (k = RingPeek(&s->m_fish); k != -1; k = RingNext(&s->m_fish, k)) {
            s32 o = k * 16 + 4;
            *(f32 *)((u8 *)s + o) += -0.2f;
        }
    }
}

void CMapEffAquariumWork::UpdateOne(s32 i) {
    Func123D88(i);
    Func123E28(i);
    Func123F40(i);
    Func124000(i);
}

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", Func124160__19CMapEffAquariumWorki);

void CMapEffAquariumWork::UpdateAll() {
    s32 i;
    for (i = 0; i < m_count; i++) {
        Func124160(i);
    }
    for (i = 0; i < 8; i++) {
        UpdateOne(i);
    }
}

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", Func124460__19CMapEffAquariumWorki);

void CMapEffAquariumWork::Func124540() {
    if (m_unk421C == -1) {
        Func123590();
    }
    while (m_count < m_sub->m_count) {
        Func1239E8(m_count);
        m_count++;
    }
    UpdateAll();
}

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", Func1245C8__19CMapEffAquariumWorkP14CMapEffAquaArgP17CMapEffAquaTarget);

void CMapEffAquariumWork::Func1246A8() {
    Func270C50(&m_unk4230[0], Func2023B8(0));
    Func270C50(&m_unk4230[1], Func2023B8(1));
    Func270C50(&m_unk4230[2], Func2023B8(2));
    Func270C50(&m_unk4260[0], Func2023A0(0));
    Func270C50(&m_unk4260[1], Func2023A0(1));
    Func270C50(&m_unk4260[2], Func2023A0(2));
    Func270C50(&m_unk4290, Func202390());
    func_00201E50(&m_unk42A0, &m_unk42A4);
    func_00201E08(&m_unk42A8, &m_unk42AC, &m_unk42B0);
    Func201CC0(0, &D_002D47E0);
    Func201CC0(1, &D_002D47F0);
    Func201CC0(2, &D_002D4800);
    Func201D18(0, &D_002D4810);
    Func201D18(1, &D_002D4820);
    Func201D18(2, &D_002D4830);
    Func201E30(150.0f, 1000.0f);
    Func201DE0(0x5F, 0xA6, 0xBC);
}

void CMapEffAquariumWork::Func1247F8() {
    Func201D78(&m_unk4290);
    Func201CC0(0, &m_unk4230[0]);
    Func201CC0(1, &m_unk4230[1]);
    Func201CC0(2, &m_unk4230[2]);
    Func201D18(0, &m_unk4260[0]);
    Func201D18(1, &m_unk4260[1]);
    Func201D18(2, &m_unk4260[2]);
    Func201E30(m_unk42A0, m_unk42A4);
    Func201DE0(m_unk42A8, m_unk42AC, m_unk42B0);
}

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", Func124888__19CMapEffAquariumWorkP17CMapEffAquaTargeti);

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", Func124AA0__19CMapEffAquariumWorkP17CMapEffAquaTarget);

void MapEffToGrid(s32 *out, const CVec4 *v) {
    out[0] = (s32)(v->x * 16.0f) + 0x6C00;
    out[1] = (s32)(v->z * 16.0f) + 0x7200;
}

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", func_00125410);

CMapEffBreathWork::CMapEffBreathWork(CMapEffParam *p) {
    s32 i;
    m_unk8 = 1;
    m_unkCC = 0;
    m_freeNodes = 0;
    m_param = p;
    for (i = 0; i < 16; i++) {
        m_nodes[i].m_next = m_freeNodes;
        m_freeNodes = &m_nodes[i];
    }
    m_unk40E0 = 0;
    m_freeParts = 0;
    for (i = 0; i < 256; i++) {
        m_parts[i].m_next = m_freeParts;
        m_freeParts = &m_parts[i];
    }
}

void CMapEffBreathWork::Func1259C8(s32 v) {
    Func125A18(v);
    Func125BA8(v);
    Func125C38();
    Func126068();
}

void CMapEffBreathWork::Func125A18(s32 v) {
    CListTag *c;
    for (c = ListFirst((CListTag *)(v + 8)); c; c = ListNext(c)) {
        CMapEffBreathNode *n;
        for (n = (CMapEffBreathNode *)m_unkCC; n; n = n->m_next) {
            if ((CListTag *)n->m_unk4 == c) break;
        }
        if (n) continue;
        const char *name = ((CMapEffBreathObj *)c)->m_res->m_name;
        s32 i;
        for (i = 0; D_002A08B0[i]; i++) {
            if (strncmp(D_002A08B0[i], name, 7) == 0) break;
        }
        if (D_002A08B0[i]) continue;
        CMapEffBreathNode *f = m_freeNodes;
        if (f) {
            m_freeNodes = f->m_next;
            f->m_unk4 = (s32)c;
            f->m_unk8 = ((CMapEffRand *)&m_unk8)->Next32() % 0xB5;
            f->m_next = (CMapEffBreathNode *)m_unkCC;
            m_unkCC = (s32)f;
        }
    }
}

void CMapEffBreathWork::Func125BA8(s32 v) {
    CMapEffBreathNode **pp = (CMapEffBreathNode **)&m_unkCC;
    CMapEffBreathNode *n;
    while ((n = *pp) != 0) {
        if (ListIndexOf((CListTag *)(v + 8), (void *)n->m_unk4) < 0) {
            *pp = n->m_next;
            n->m_next = m_freeNodes;
            m_freeNodes = n;
        } else {
            pp = &n->m_next;
        }
    }
}

void CMapEffBreathWork::Func125C38() {
    CMapEffBreathNode *n;
    for (n = (CMapEffBreathNode *)m_unkCC; n; n = n->m_next) {
        CMapEffBreathObj *o = (CMapEffBreathObj *)n->m_unk4;
        if (o->m_flags & 0x80) continue;
        if (n->m_unk8-- >= 0) continue;
        CMapEffRand *r = (CMapEffRand *)&m_unk8;
        Func125DB8(n, RandInt(r, (s32)m_param->m_unk4 * 30 / 100, (s32)m_param->m_unk4 * 60 / 100 + 1));
        n->m_unk8 = RandInt(r, 0xA0, 0xB4);
    }
}

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", Func125DB8__17CMapEffBreathWorkP17CMapEffBreathNodei);

void CMapEffBreathWork::Func126068() {
    CMapEffBreathPart **pp = &m_unk40E0;
    CMapEffBreathPart *p;
    while ((p = *pp) != 0) {
        f32 ang = p->m20;
        f32 amp = p->m24;
        p->m10.x -= TblSin(p->m20) * p->m24;
        p->m10.y -= 0.016666666f;
        p->m10.z -= TblCos(p->m20) * p->m24;
        p->m24 -= p->m24 / 5.0f;
        p->m30 -= p->m34;
        if (p->m30 <= 0.0f) {
            *pp = p->m_next;
            p->m_next = m_freeParts;
            m_freeParts = p;
        } else {
            pp = &p->m_next;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", func_00126170);

CMapEffSwingWork::CMapEffSwingWork(CMapEffSwingParam *p) {
    m_unk4 = 1;
    m_unk8 = p;
    m_unkC = -1;
    m_def = -1;
    m_unk90 = 0;
}

f32 CMapEffWork126640::GetKindTime(CMapEffWork126640 *w, s32 i) {
    f32 r = 0.0f;
    s32 k = w->m_kind[i];
    if (k >= 1 && k <= 6 && D_002A06F0) {
        s32 h = D_002A06F0->m_entries[k].m_handle;
        if (h >= 0) {
            r = Func1EAC30(h) - 1.0f;
        }
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", Func1266B0__16CMapEffSwingWork);

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", Func126860__16CMapEffSwingWorki);

void CMapEffSwingWork::Func126970() {
    if (m_unkC != m_unk8->m_unk4) {
        Func1266B0();
    }
    if (m_def != -1 && m_unk90 == 0) {
        CMapEffSwingDef *d = &D_002A0998[m_def];
        s32 i;
        for (i = 0; i < d->m_count; i++) {
            Func126860(i);
        }
    }
}

void CMapEffSwingWork::Func126A20(s32 unused, s32 a) {
    if (m_def != -1) {
        CMapEffSwingDef *d = &D_002A0998[m_def];
        s32 i;
        Func126AC0();
        for (i = 0; i < d->m_count; i++) {
            Func126C48(a, i);
        }
        Func126BD8();
    }
}

void CMapEffSwingWork::Func126AC0() {
    Func270C50(&m_unk20[0], Func2023B8(0));
    Func270C50(&m_unk20[1], Func2023B8(1));
    Func270C50(&m_unk20[2], Func2023B8(2));
    Func270C50(&m_unk50[0], Func2023A0(0));
    Func270C50(&m_unk50[1], Func2023A0(1));
    Func270C50(&m_unk50[2], Func2023A0(2));
    Func270C50(&m_unk80, Func202390());
    Func201D78(&D_002D4890);
    Func201CC0(0, &D_002D48A0);
    Func201CC0(1, &D_002D48B0);
    Func201CC0(2, &D_002D48C0);
    Func201D18(0, &D_002D48D0);
    Func201D18(1, &D_002D48E0);
    Func201D18(2, &D_002D48F0);
}

void CMapEffSwingWork::Func126BD8() {
    Func201D78(&m_unk80);
    Func201CC0(0, &m_unk20[0]);
    Func201CC0(1, &m_unk20[1]);
    Func201CC0(2, &m_unk20[2]);
    Func201D18(0, &m_unk50[0]);
    Func201D18(1, &m_unk50[1]);
    Func201D18(2, &m_unk50[2]);
}

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", Func126C48__16CMapEffSwingWorkii);
