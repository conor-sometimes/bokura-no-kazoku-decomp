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
    u8 pad8[0x3C];
    s32 m_unk44;              // 0x44
    s32 m_unk48;              // 0x48
    u8 pad4C[0xCC];
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
    void Func11CD60(s32 i, s32 v);
    s32 Func11CE50();

    s32 m_tables[31];         // 0x10
    s32 m_handles[13];        // 0x8C
    CMapEffEntry m_entries[7]; // 0xC0
};
extern CMapEffObjRes *D_002A06F0;

class CMapEffLeafWork {
public:
    s32 IsHit(s32 id);
    void FreeAll();
    void Func11FE20(s32 unused, CMapEffTarget *t);
    void Func11FE88(CMapEffTarget *t);
    void Func120298(CMapEffTarget *t);

    CMapEffObjRes *m_res;     // 0x0
    CMapEffParam *m_param;    // 0x4
    u8 pad8[0x3C];
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
    u8 pad114[0x8];
    s32 m_unk11C;             // 0x11C
    s32 m_unk120;             // 0x120
    s32 m_unk124;             // 0x124
    s32 m_unk128;             // 0x128
};
struct CMapEffRect {
    f32 x0, z0, x1, z1;
};
struct CMapEffDrop {
    u8 pad0[0x20];
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

class CMapEffAquariumSlot {
public:
    u8 pad0[0x110];
    CMapEffAquariumFish m_fish; // 0x110
    u8 pad11C[0x14];
    s32 m_busy;               // 0x130
    u8 pad134[0xC];
};

class CMapEffAquariumWork : public CMapEffWork {
public:
    CMapEffAquariumWork(CMapEffAquariumSub *sub);
    virtual ~CMapEffAquariumWork();
    void Func1236C8(s32 i);
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

    u8 pad4[0x380C];
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

class CMapEffCurtainWork {
public:
    void Func11E548();
    void Func11D8C8();
    void Func11E1C0();

    CMapEffObjRes *m_res;     // 0x0
    CMapEffParam *m_param;    // 0x4
    u8 pad8[0x8];
    f32 m_unk10;              // 0x10
    s32 m_unk14;              // 0x14
};

struct CMapEffBreathNode {
    CMapEffBreathNode *m_next; // 0x0
    s32 m_unk4;               // 0x4
    s32 m_unk8;               // 0x8
};
struct CMapEffBreathPart {
    CMapEffBreathPart *m_next; // 0x0
    u8 pad4[0x3C];
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

    CMapEffParam *m_param;    // 0x4
    s32 m_unk8;               // 0x8
    CMapEffBreathNode m_nodes[16]; // 0xC
    s32 m_unkCC;              // 0xCC
    CMapEffBreathNode *m_freeNodes; // 0xD0
    u8 padD4[0xC];
    CMapEffBreathPart m_parts[256]; // 0xE0
    s32 m_unk40E0;            // 0x40E0
    CMapEffBreathPart *m_freeParts; // 0x40E4
};

class CMapEffSwingDef {
public:
    u8 pad0[0x4];
    s32 m_count;              // 0x4
    u8 pad8[0x40];
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

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", func_0011CF20);

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

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", func_0011F0F8);

void CMapEffLeafWork::FreeAll() {
    CMapEffNode *p;
    while ((p = m_active) != 0) {
        m_active = p->m_next;
        p->m_next = m_free;
        m_free = p;
    }
}

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", func_0011F2A8);

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", func_0011F390);

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", func_0011F5D8);

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", func_0011F660);

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", func_0011F9C0);

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

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", func_001215B0);

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", func_00121788);

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", func_00121810);

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

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", func_00121AD0);

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", func_00121C18);

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

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", func_00122440);

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", func_001225F0);

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", func_00122660);

void CMapEffSnowWork::FreeAll() {
    CMapEffNode *p;
    while ((p = m_active) != 0) {
        m_active = p->m_next;
        p->m_next = m_free;
        m_free = p;
    }
}

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", func_00122808);

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", func_001228F0);

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", func_00122B38);

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", func_00122BC0);

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

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", func_001235E8);

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", func_00123670);

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", func_001236C8);

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", func_00123850);

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", Func1239E8__19CMapEffAquariumWorki);

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", Func123D88__19CMapEffAquariumWorki);

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", Func123E28__19CMapEffAquariumWorki);

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", Func123F40__19CMapEffAquariumWorki);

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", Func124000__19CMapEffAquariumWorki);

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

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", func_00124460);

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

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", func_001245C8);

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", func_001246A8);

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

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", func_00124888);

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", func_00124AA0);

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

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", Func125A18__17CMapEffBreathWorki);

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", Func125BA8__17CMapEffBreathWorki);

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", Func125C38__17CMapEffBreathWork);

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", func_00125DB8);

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", Func126068__17CMapEffBreathWork);

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

INCLUDE_ASM("asm/nonmatchings/CMapEffObjRes", Func126AC0__16CMapEffSwingWork);

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
