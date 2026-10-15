#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CStatusBase {
public:
    f32 GetItemUnk34();
};
#include "CFlagWork.h"
#include "CProcess.h"
extern CFlagWork *D_002A464C;

class CStatusBaseSub19AE68 {
public:
    void Set(s32 v);
};

struct CChrBodyEntry {
    s32 m0;                   // 0x0
    void *m4;                 // 0x4
    u8 pad8[0x20];
    void *m28;                // 0x28
    u8 pad2C[0x20];
};
class CChrBodyWin {
public:
    void SetUnk384(f32 v);
    ~CChrBodyWin();
    void Init1883D0();
    void Clear1884B0();
    void GetColor(s32 *rgb, s32 *a);
    int GetFlag187A00(s32 id);
    int Check1888B8();
    void Set189348(s32 a, s32 b);
    void SetChar(s32 c);
    int GetFlag187610(s32 id, s32 k);
    int GetFlag187680(s32 id, s32 k);
    int GetLevel1878F8(s32 id, s32 k);
    void Func188778(f32 *a, f32 *b, f32 *c, f32 *d);
    int Func188F30(f32 x, f32 y);
    int Func1889F8();
    int Func187ED0(s32 k);
    void Func188CD8();
    void Init189018(s32 mode);
    void Func188098(f32 x, f32 y, f32 s, f32 t);
    int Func187D68(s32 i, s32 f, s32 k);
    void Func187A68(char *buf, s32 i, s32 f, s32 k);
    void Open(s32 i);
    int CallFunc1091B0(s32 id);
    void CallFunc188BA8();
    void Func188BA8();
    void SetUnk6C(s32 v);
    void SetMode1();
    void SetMode2();
    void SetMode6();
    void CallSetMode2();
    void Check2To3();
    void Check3To4();
    void SetMode5();
    f32 GetStatusUnk34();

    CStateMachine m_sm;       // 0x0
    s32 m_unk48;              // 0x48
    s32 m_mode;               // 0x4C
    s32 m_unk50;              // 0x50
    s32 m_unk54;              // 0x54
    s32 m_unk58b;             // 0x58
    u8 pad5C[0x4];
    void *m_unk60;            // 0x60
    CStatusBase* m_status;    // 0x64
    void *m_unk68;            // 0x68
    CStatusBaseSub19AE68* m_unk6C; // 0x6C
    void *m_unk70;            // 0x70
    u8 pad74[0x114];
    u64 m_unk188;             // 0x188
    u64 m_unk190;             // 0x190
    CChrBodyEntry m_ent[6];   // 0x198
    s32 m_unk360;             // 0x360
    s32 m_unk364;             // 0x364
    s32 m_unk368;             // 0x368
    u8 pad36C[0x4];
    s32 m_unk370;             // 0x370
    f32 m_unk374;             // 0x374
    f32 m_unk378;             // 0x378
    s32 m_unk37C;             // 0x37C
    s32 m_unk380;             // 0x380
    f32 m_unk384;             // 0x384
    s32 m_unk388;             // 0x388
    f32 m_unk38C;             // 0x38C
    f32 m_unk390;             // 0x390
    f32 m_unk394;             // 0x394
    f32 m_unk398;             // 0x398
};

class CChrBodyWinSub188748 {
public:
    u64 SwapUnk188(u64 v);
    u64 SwapUnk190(u64 v);
    void SetUnk388(s32 v);
    void SetUnk380(s32 v);
    void SetUnk374(f32 v);
    void SetUnk378(f32 v);

    u8 pad0[0x188];
    u64 m_unk188;             // 0x188
    u64 m_unk190;             // 0x190
    u8 pad198[0x1DC];
    f32 m_unk374;             // 0x374
    f32 m_unk378;             // 0x378
    u8 pad37C[0x4];
    s32 m_unk380;             // 0x380
    u8 pad384[0x4];
    s32 m_unk388;             // 0x388
};

//@sym memset 0x289FB0
#include "libc.h"
void *operator new(unsigned int n);
int Func235DE0(const char *fmt, ...);
extern CFlagWork *D_002A4638[6];
extern CFlagWork *D_002A5358;
extern CChrBodyWin *D_002A4308;
extern void (*D_002B91B0)(void *p);
extern char D_002DB400[], D_002DB380[], D_002DB310[];
class CChrBodySub189270 {
public:
    void Func189270(int v);
};
class CChrBodySub245818 {
public:
    void Func245818(int v);
};
class CChrBodyWinSub18A410 {
public:
    void Init18A480();
    void Close();
    u8 pad0[0x58];
    CChrBodySub245818 m58;    // 0x58
    u8 pad59[0xB];
    CChrBodySub189270 *m64;   // 0x64
    void *m68;                // 0x68
};
CChrBodyWin *NewChrBodyWin();
CChrBodyWinSub18A410 *NewChrBodyWinSub18A410();

inline f32 Clamp01(f32 v) { return (v < 1.0f ? v : 1.0f) < 0.0f ? 0.0f : (v < 1.0f ? v : 1.0f); }

extern char D_002DB358[], D_002DB3B0[];
extern const char *D_002A430C;
extern s32 D_002A4310;
extern s32 D_002A4314;
void Func2491A8(void *buf, const char *path, s32 a, s32 b, s32 c);
s32 Func249248(void *buf);
void Func249348();
void Func225088();
int Func2250C0();

extern CFlagWork *D_002A4B60;

struct CChrBodySub {
    void *m0;
    s32 m4, m8, mC, m10, m14, m18, m1C, m20;
};
void Func2251E8();
void Func227DC8(long a, s32 b, s32 c);
extern "C" void func_00227BF0(u64 a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern "C" void func_00227A20();
extern "C" void func_00227AA8();
extern "C" void func_00226DF8(s32 reg, u64 v);
#define GS_SET_TEX0(tbp, tbw, psm, tw, th, tcc, tfx, cbp, cpsm, csm, csa, cld) \
    ((u64)(tbp) | ((u64)(tbw) << 14) | ((u64)(psm) << 20) | ((u64)(tw) << 26) | ((u64)(th) << 30) | \
     ((u64)(tcc) << 34) | ((u64)(tfx) << 35) | ((u64)(cbp) << 37) | ((u64)(cpsm) << 51) | \
     ((u64)(csm) << 55) | ((u64)(csa) << 56) | ((u64)(cld) << 61))
#define GS_SET_CLAMP(wms, wmt, minu, maxu, minv, maxv) \
    ((u64)(wms) | ((u64)(wmt) << 2) | ((u64)(minu) << 4) | ((u64)(maxu) << 14) | \
     ((u64)(minv) << 24) | ((u64)(maxv) << 34))

class CMenuRecordWin {
public:
    void Func1A39A8(f32 *a, s32 *b, s32 k);
};
struct CChrSprPkt {
    s32 u0, v0, u1, v1;
    s32 x0, y0, x1, y1;
    s32 r, g, b, a;
};
extern "C" void func_001866D0(s32 *xy, f32 x, f32 y, f32 w, f32 h);
inline void PutRGBA(CChrSprPkt *p) { func_00226DF8(1, (u64)p->r | ((u64)p->g << 8) | ((u64)p->b << 16) | ((u64)p->a << 24)); }
inline void PutXYZ(s32 x, s32 y) { func_00226DF8(5, (u64)x | ((u64)y << 16)); }
inline void PutUV(s32 u, s32 v) { func_00226DF8(3, (u64)u | ((u64)v << 16)); }
// @decl-end

INCLUDE_RODATA("asm/nonmatchings/CChrBodyWin", D_002DAFD0);
INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_00187038);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_00187088);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_001870B8);

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_001871C0() {
}

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_001871C8() {
}

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_001871D0);

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_001872D8() {
}

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_001872E0);
INCLUDE_RODATA("asm/nonmatchings/CChrBodyWin", D_002DB018);

CChrBodyWin *NewChrBodyWin() {
    CChrBodyWin *p = (CChrBodyWin *)operator new(0x3A0);
    p->Init1883D0();
    return p;
}

int CChrBodyWin::GetFlag187610(s32 id, s32 k) {
    if (m_unk380) {
        if (k == 1) return D_002A464C->Func1091B0(id + 0xB4);
        return D_002A4638[0]->Func1091B0(id + 0xB4);
    }
    return D_002A5358->Func1091B0(id + 0xA0);
}

int CChrBodyWin::GetFlag187680(s32 id, s32 k) {
    if (m_unk380) {
        if (k == 1) {
            if (D_002A4638[5]->Func1091B0(id + 0xC0) == 0) return -1;
            return D_002A4638[5]->Func1091B0(id + 0xC6);
        }
        if (D_002A4638[0]->Func1091B0(id + 0xC0) == 0) return -1;
        return D_002A4638[0]->Func1091B0(id + 0xC6);
    }
    if (D_002A5358->Func1091B0(id + 0xAC) != 0) {
        return D_002A5358->Func1091B0(id + 0xB2);
    }
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_00187758);

int CChrBodyWin::GetLevel1878F8(s32 id, s32 k) {
    int a;
    int b;
    if (m_unk380) {
        if (k == 1) {
            a = D_002A4638[5]->Func1091B0(id + 6);
            b = D_002A4638[5]->Func1091B0(id + 0xC);
        } else {
            a = D_002A4638[0]->Func1091B0(id + 6);
            b = D_002A4638[0]->Func1091B0(id + 0xC);
        }
    } else {
        a = D_002A5358->Func1091B0(id + 0x2E);
        b = D_002A5358->Func1091B0(id + 0x34);
    }
    if (a == 0) return 0;
    if (a >= 1 && a <= 6) return 1;
    if (a >= 7 && a <= 12) return 2;
    if (a >= 13 && a <= 15) return 3;
    if (a >= 16 && a <= 18) return 4;
    return b == 9 ? 6 : 5;
}

int CChrBodyWin::GetFlag187A00(s32 id) {
    if (m_unk380) return D_002A4638[0]->Func1091B0(id + 0xAE);
    return D_002A5358->Func1091B0(id + 0x9A);
}

int CChrBodyWin::CallFunc1091B0(s32 id) {
    return D_002A464C->Func1091B0(id + 0xAE);
}

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", Func187A68__11CChrBodyWinPciii);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", Func187D68__11CChrBodyWiniii);

int CChrBodyWin::Func187ED0(s32 k) {
    CChrBodySub *e;
    if (k == 1 && m_ent[m_unk37C].m28) {
        e = (CChrBodySub *)&m_ent[m_unk37C].m28;
    } else {
        if (k != 0) return 0;
        e = (CChrBodySub *)&m_ent[m_unk37C].m4;
    }
    if (e->m1C > 0) {
        Func227DC8(m_unk190, e->m1C * e->m20, e->m14);
    }
    m_unk188 = (m_unk188 & ~((u64)0x3F << 32)) | ((u64)(e->m8 & 0x3F) << 32);
    func_00227BF0(m_unk188, 0, 0, e->mC, e->m10, e->m4);
    func_00227A20();
    func_00226DF8(0x14, 0x60);
    func_00226DF8(6, GS_SET_TEX0(m_unk188 & 0x3FFF, (m_unk188 >> 14) & 0x3F, (m_unk188 >> 32) & 0x3F, 10, 10, 1, 0, m_unk190 & 0x3FFF, (m_unk190 >> 32) & 0x3F, 0, 0, 1));
    func_00226DF8(8, GS_SET_CLAMP(2, 2, 0, e->mC - 1, 0, e->m10 - 1));
    func_00227AA8();
    Func2251E8();
    return 1;
}

void CChrBodyWin::Func188098(f32 x, f32 y, f32 s, f32 t) {
    CChrSprPkt pkt;
    f32 o0;
    f32 c0;
    f32 o1;
    f32 c1;
    ((CMenuRecordWin *)m_unk388)->Func1A39A8(&o0, (s32 *)&c0, 0);
    ((CMenuRecordWin *)m_unk388)->Func1A39A8(&o1, (s32 *)&c1, 1);
    pkt.a = (s32)(s * 128.0f);
    func_00227A20();
    pkt.u0 = 8;
    pkt.v0 = 8;
    pkt.u1 = 0xC08;
    pkt.v1 = 0xB08;
    x -= (t * 192.0f - 192.0f) * 0.5f;
    y -= (t * 176.0f - 176.0f) * 0.5f;
    f32 w = m_unk378 * 192.0f * t;
    f32 h = m_unk378 * 176.0f * t;
    func_001866D0(&pkt.x0, x - o0 + o1, y - o0 + o1, w + (o0 + o0), h + (o0 + o0));
    pkt.r = pkt.g = pkt.b = (s32)c1;
    func_00226DF8(0, 0x46);
    PutRGBA(&pkt);
    PutXYZ(pkt.x0, pkt.y0);
    PutXYZ(pkt.x1, pkt.y1);
    func_001866D0(&pkt.x0, x - o0, y - o0, w + (o0 + o0), h + (o0 + o0));
    pkt.r = pkt.g = pkt.b = (s32)c0;
    func_00226DF8(0, 0x46);
    PutRGBA(&pkt);
    PutXYZ(pkt.x0, pkt.y0);
    PutXYZ(pkt.x1, pkt.y1);
    func_001866D0(&pkt.x0, x, y, w, h);
    pkt.r = pkt.g = pkt.b = 0x80;
    func_00226DF8(0, 0x156);
    PutRGBA(&pkt);
    PutUV(pkt.u0, pkt.v0);
    PutXYZ(pkt.x0, pkt.y0);
    PutUV(pkt.u1, pkt.v1);
    PutXYZ(pkt.x1, pkt.y1);
    func_00227AA8();
    Func2251E8();
}

void CChrBodyWin::Init1883D0() {
    D_002A4308 = this;
    m_unk360 = 8;
    m_unk364 = 8;
    m_unk368 = 8;
    m_unk370 = 16;
    m_unk374 = 0.0f;
    m_unk378 = 1.0f;
    m_unk37C = 0;
    m_unk380 = 0;
    m_unk384 = 0.0f;
    m_unk388 = 0;
    m_unk38C = 1.0f;
    m_unk390 = 1.0f;
    m_unk394 = 1.0f;
    m_unk398 = 1.0f;
    memset(this, 0, 0x188);
    return Clear1884B0();
}

CChrBodyWin::~CChrBodyWin() {
    CallFunc188BA8();
    D_002A4308 = 0;
}

void CChrBodyWin::Clear1884B0() {
    int i;
    for (i = 5; i >= 0; i--) m_ent[i].m0 = 0;
    Func188BA8();
}

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_001884F0);

void CChrBodyWin::CallFunc188BA8() {
    Func188BA8();
}

u64 CChrBodyWinSub188748::SwapUnk188(u64 v) {
    u64 old = m_unk188;
    m_unk188 = v;
    return old;
}

u64 CChrBodyWinSub188748::SwapUnk190(u64 v) {
    u64 old = m_unk190;
    m_unk190 = v;
    return old;
}

void CChrBodyWinSub188748::SetUnk388(s32 v) {
    if (v) {
        m_unk388 = v;
    }
}

inline s32 TblGet(CChrBodyWin *w, s32 l, s32 f) { return ((s32 (*)[14])w)[l][f - 1]; }
void CChrBodyWin::Func188778(f32 *a, f32 *b, f32 *c, f32 *d) {
    if (m_unk380) {
        *(s32 *)a = TblGet(this, GetLevel1878F8(m_unk37C, 0), GetFlag187A00(m_unk37C));
        *(s32 *)b = TblGet(this, GetLevel1878F8(m_unk37C, 1), CallFunc1091B0(m_unk37C));
        *c = m_unk394;
        *d = m_unk398;
    } else {
        s32 v = TblGet(this, GetLevel1878F8(m_unk37C, 0), GetFlag187A00(m_unk37C));
        *(s32 *)a = *(s32 *)b = v;
        *c = *d = m_unk394;
    }
}

int CChrBodyWin::Check1888B8() {
    int a = GetFlag187A00(m_unk37C);
    if (a != CallFunc1091B0(m_unk37C) && m_unk380) return 1;
    return 0;
}

void CChrBodyWin::GetColor(s32 *rgb, s32 *a) {
    if (rgb) {
        rgb[0] = m_unk360;
        rgb[1] = m_unk364;
        rgb[2] = m_unk368;
    }
    if (a) *a = m_unk370;
}

void CChrBodyWin::Open(s32 i) {
    if (i < 0 || D_002A26E4->Func1091B0(0x27) - 1 < i) Func235DE0(D_002DB310, i);
    else {
        m_ent[i].m0 = 1;
        Func188BA8();
    }
}

void CChrBodyWinSub188748::SetUnk380(s32 v) {
    m_unk380 = v;
}

void CChrBodyWinSub188748::SetUnk374(f32 v) {
    m_unk374 = v;
}

void CChrBodyWinSub188748::SetUnk378(f32 v) {
    m_unk378 = v;
}

int CChrBodyWin::Func1889F8() {
    char buf0[0x100];
    char buf1[0x100];
    char buf2[0x100];
    int ok = 0;
    Func2491A8(buf0, 0, (s32)D_002A430C, D_002A4310, D_002A4314);
    if (Func249248(buf0)) {
        s32 i;
        for (i = 0; i < 6; i++) {
            if (m_ent[i].m4 || m_ent[i].m28) {
                Func235DE0(D_002DB358, i);
                continue;
            }
            if (m_ent[i].m0) {
                s32 f = GetFlag187A00(i);
                if (Func187D68(i, f, 0) && m_unk380) {
                    s32 g = CallFunc1091B0(i);
                    Func187A68(buf1, i, f, 0);
                    Func187A68(buf2, i, g, 1);
                    if (strcmp(buf1, buf2)) Func187D68(i, g, 1);
                }
            }
        }
        ok = 1;
    }
    Func249348();
    return ok;
}

void CChrBodyWin::Func188BA8() {
    int i;
    for (i = 0; i < 6; i++) {
        if (m_ent[i].m4) {
            D_002B91B0(m_ent[i].m4);
            m_ent[i].m4 = 0;
        }
        if (m_ent[i].m28) {
            D_002B91B0(m_ent[i].m28);
            m_ent[i].m28 = 0;
        }
    }
}

void CChrBodyWin::SetChar(s32 c) {
    if (c < 0 || D_002A26E4->Func1091B0(0x27) - 1 < c) {
        Func235DE0(D_002DB380, c);
        c = 0;
    }
    m_unk37C = c;
}

void CChrBodyWin::SetUnk384(f32 v) {
    m_unk384 = Clamp01(v);
}

void CChrBodyWin::Func188CD8() {
    if (m_ent[m_unk37C].m28 == 0) {
        m_unk384 = 0.0f;
        m_unk38C = 1.0f;
        m_unk394 = 1.0f;
        m_unk390 = 0.0f;
        m_unk398 = 0.0f;
    } else {
        f32 a = D_002A4B60->Func1091B0(0x6A) / 100.0f;
        f32 b = D_002A4B60->Func1091B0(0x6B) / 100.0f;
        f32 c = D_002A4B60->Func1091B0(0x6C) / 100.0f;
        f32 d = D_002A4B60->Func1091B0(0x6D) / 100.0f;
        f32 t = m_unk384;
        if (0.0f <= t && t < a) {
            m_unk398 = 0.0f;
            m_unk394 = 1.0f;
            m_unk390 = 0.0f;
            m_unk38C = 1.0f - (1.0f - c) * (t / a);
        } else if (a <= t && t < b) {
            m_unk38C = 0.0f;
            m_unk398 = 1.0f;
            m_unk394 = 0.0f;
            m_unk390 = c + (d - c) * (t - a) / (b - a);
        } else if (b <= t && t <= 1.0f) {
            m_unk38C = 0.0f;
            m_unk394 = 0.0f;
            m_unk398 = 1.0f;
            m_unk390 = d - (d - 1.0f) * (t - b) / (1.0f - b);
        }
    }
    if (m_unk374 != 1.0f) {
        if (m_unk384 == 0.0f) {
            m_unk398 = 0.0f;
            m_unk394 = m_unk374;
        } else {
            m_unk398 = m_unk374;
            m_unk394 = 0.0f;
        }
    }
}

int CChrBodyWin::Func188F30(f32 x, f32 y) {
    if (m_ent[m_unk37C].m0 == 0) {
        Func235DE0(D_002DB3B0, m_unk37C);
        Func225088();
        return Func2250C0();
    }
    Func225088();
    if (Func187ED0(1)) Func188098(x, y, m_unk398, m_unk390);
    if (Func187ED0(0)) Func188098(x, y, m_unk394, m_unk38C);
    return Func2250C0();
}

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_00189018);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", _$_12CChrBodyData);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_00189348);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_001893A0);

void CChrBodyWin::SetUnk6C(s32 v) {
    if (m_unk6C) {
        m_unk6C->Set(v);
    }
}

void CChrBodyWin::SetMode1() {
    m_mode = 1;
}

void CChrBodyWin::SetMode2() {
    m_mode = 2;
}

void CChrBodyWin::SetMode6() {
    m_mode = 6;
}

void CChrBodyWin::CallSetMode2() {
    SetMode2();
}

void CChrBodyWin::Check2To3() {
    if (m_unk48 == 2 && m_unk54) {
        m_mode = 3;
    }
}

void CChrBodyWin::Check3To4() {
    if (m_unk48 == 3) {
        m_mode = 4;
    }
}

void CChrBodyWin::SetMode5() {
    m_mode = 5;
}

f32 CChrBodyWin::GetStatusUnk34() {
    if (m_status) {
        return m_status->GetItemUnk34();
    }
    return 0.0f;
}

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_001895F8);

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_0018A1F0);

CChrBodyWinSub18A410 *NewChrBodyWinSub18A410() {
    CChrBodyWinSub18A410 *p = (CChrBodyWinSub18A410 *)operator new(0x94);
    p->Init18A480();
    return p;
}

INCLUDE_ASM("asm/nonmatchings/CChrBodyWin", func_0018A410);
