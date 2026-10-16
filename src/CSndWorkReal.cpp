#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern void *D_002A0BE0;

class CVec4 {
public:
    f32 x, y, z, w;
};

class CSndWork {
public:
    void Func25C840(s32 a, s32 b = 0, s32 c = 0);
    int Func25C990(s32 a);
    int Func25CAC0(s32 a);
    void Func25CB90(s32 a, s32 b, s32 c);
    void Func25C648(s32 a, s32 b);
    void SetVol(s32 h, s32 x) {
        if (x >= 0) Func25CB90(h, x, x);
        else Func25CB90(h, x, -x);
    }
};
class CResCache {
public:
    void Func250840(void *p);

    u8 pad0[0x13C];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual s32 Open(const char *name);   // slot 3
};
extern "C" void func_00250828(void *cache, const char *name);
extern "C" s32 func_0025CEA0(void *snd);
extern "C" s32 func_0025CEE8(void *snd, s32 i);
extern CResCache *D_002A0BEC;

// Linear fade: value moves from m_from to m_to over m_dur frames.
class CSndFade {
public:
    void Start(f32 v, s32 dur) {
        if (dur > 0) {
            m_from = m_cur;
            m_dur = dur;
            m_to = v;
            m_t = 0;
        } else {
            m_t = 0;
            m_to = v;
            m_from = v;
            m_dur = 0;
            m_cur = v;
        }
    }
    void Update() {
        if (m_t < m_dur) {
            m_t++;
            m_cur = m_from + (m_to - m_from) * (f32)m_t / (f32)m_dur;
        }
    }

    f32 m_cur;                // 0x0
    f32 m_from;               // 0x4
    f32 m_to;                 // 0x8
    s32 m_t;                  // 0xC
    s32 m_dur;                // 0x10
};

class CSndNode {
public:
    u32 m_unk0;               // 0x0
    CSndNode *m_prev;         // 0x4
    CSndNode *m_next;         // 0x8
};

// Sound request entry (singly linked).
class CSndEntry {
public:
    CSndEntry *m_next;        // 0x0
    char m_name[0x20];        // 0x4
    s32 m_unk24;              // 0x24
    s32 m_unk28;              // 0x28
    s32 m_unk2C;              // 0x2C
    s32 m_unk30;              // 0x30
    s32 m_unk34;              // 0x34
    s32 m_unk38;              // 0x38
    s32 m_unk3C;              // 0x3C
    s32 m_unk40;              // 0x40
    u8 m_snd[4];              // 0x44: CSndWork
};

class CCharaObj;
class CCharaObjName {
public:
    u8 pad0[0x20];
    char m_name[1];           // 0x20
};
class CCharaObj {
public:
    void Func116AE0();
    s32 Func117AC8(s32 a, s32 b);

    s32 m_unk0;               // 0x0
    u8 pad4[0x4];
    CCharaObj *m_next;        // 0x8
    u8 padC[0x8];
    CCharaObjName *m_name;    // 0x14
};
inline CCharaObj *LiveChara(CCharaObj *p) {
    return p->m_unk0 ? 0 : p;
}

class CSndOwner {
public:
    void Func11B118(void *p, s32 v);
};

class CSndTarget {
public:
    u8 pad0[0xE0];
    CVec4 m_unkE0;            // 0xE0
    u8 padF0[0xB8];
    char m_name[0x10];        // 0x1A8
    s32 m_unk1B8;             // 0x1B8
    u8 pad1BC[0xC];
    s32 m_unk1C8;             // 0x1C8
};

class CSndObj18 {
public:
    u8 pad0[0x34];
    u8 m_unk34;               // 0x34
    u8 pad35[0x7];
    s16 m_unk3C;              // 0x3C
    s16 m_unk3E;              // 0x3E
};
class CSndDrvB {
public:
    virtual void Vf0();
    virtual void Vf1();
    virtual void Vf2();
    virtual void Vf3();
    virtual void Vf4();
    virtual void Vf5();
    virtual void Vf6();
    virtual void Vf7();
    virtual void Vf8();
    virtual void Vf9();
    virtual void Vf10();
    virtual void Vf11();
    virtual void Vf12();
    virtual void Vf13();
    virtual void Vf14();
    virtual void Vf15();
    virtual void Vf16();
    virtual void Vf17();
    virtual void Vf18();
    virtual s32 Find19(s32 kind);
    virtual void Vf20();
    virtual void Vf21();
    virtual void Vf22();
    virtual void Vf23();
    virtual void Vf24();
    virtual void Vf25();
    virtual void Vf26();
    virtual void Vf27();
    virtual void Vf28();
    virtual void Vf29();
    virtual void Vf30();
    virtual void Vf31();
    virtual void Vf32();
    virtual void Vf33();
    virtual void Vf34();
    virtual void Vf35();
    virtual void Vf36();
    virtual void Vf37();
    virtual void Vf38();
    virtual s32 *Get39(const char *name);
};
extern CSndDrvB *D_002BA248;
extern "C" int func_0020E698(s32 h, const char *name);
s32 IsSndPrefixed(const char *s);
extern "C" unsigned int strlen(const char *);

class CSndWorkReal {
public:
    void Func1291B8(s32 on, s32 dur);
    s32 Func129CC8(const char *name);
    void CallFunc129458(const char *s, s32 v);
    void Func129458(const char *s, s32 v);
    int IsUnkA4Set();
    void SetUnkA8(s32 v);
    void SetChara(CCharaObj **pp);
    void MoveToList(CSndNode *n);
    void FadeIn(s32 on, s32 dur);
    void FadeTo(s32 dur, f32 v);
    void SetPlaying(s32 on, s32 dur);
    CSndEntry *Func1292E0(const char *name, s32 v);
    void Stop129AE0(const char *name, s32 t);
    void Play129900(const char *name, f32 f, s32 a, s32 b, s32 pan);
    void StartAll();
    void Func1295E8() throw();  // compiled before its callers in retail: nothrow calls (docs/lessons.md, nm)
    int Func129848();
    void StopSound();
    s32 GetVolume(const char *s);
    void Func129D90();
    void UpdateOwner();
    void UpdateCharas();
    void Func129EB0();
    void Func12A0F0();
    void SetPos(const CVec4 *a, const CVec4 *b, f32 f);

    CCharaObj *m_unk0;        // 0x0
    CCharaObj **m_unk4;       // 0x4
    CSndNode m_list;          // 0x8
    u8 pad14[0x4];
    CSndObj18 *m_unk18;       // 0x18
    void *m_unk1C;            // 0x1C
    CSndObj18 *m_unk20;       // 0x20
    s32 m_unk24;              // 0x24
    s32 m_unk28;              // 0x28
    s32 m_unk2C;              // 0x2C
    u8 pad30[0xC];
    CSndFade m_fade3C;        // 0x3C
    u8 pad50[0x8];
    CSndFade m_fade58;        // 0x58
    CSndFade m_fade6C;        // 0x6C
    u8 pad80[0x4];
    CSndEntry *m_entries;     // 0x84
    CSndEntry *m_free;        // 0x88
    s32 m_playing;            // 0x8C
    s32 m_unk90;              // 0x90
    s32 m_unk94;              // 0x94
    f32 m_unk98;              // 0x98
    s32 m_unk9C;              // 0x9C
    CSndWork *m_unkA0;        // 0xA0
    s32 m_unkA4;              // 0xA4
    s32 m_unkA8;              // 0xA8
    u8 padAC[0x4];
    CVec4 m_unkB0;            // 0xB0
    CVec4 m_unkC0;            // 0xC0
    f32 m_unkD0;              // 0xD0
};

extern "C" char *strstr(const char *s, const char *sub);
#include "libc.h"
int Func235DE0(const char *fmt, ...) throw();
void Func270C50(CVec4 *dst, const CVec4 *src);
void Func270CA0(CVec4 *dst, void *m);
void Func270E48(CVec4 *v);
void Func271960(CVec4 *dst, const CVec4 *src, f32 s);
void *Func237570(s32 size);
void Func237A88(void *p, s32 n);
void *Func237C30(void *p);
void Func238158(void *p, s32 v);
void Func225088();
int Func2250C0();
void Func2250E8(s32 v);
void Func227A20();
void Func226DF8(s32 a, s32 b);
void Func227AA8();
void Func2251E8();
extern const char *D_002A0BB0;
extern const char D_002D4CD8[];

//@sym strstr 0x28B8E8
//@sym strcmp 0x28B190

extern "C" int func_0025CAC0(void *snd, s32 h);
extern "C" void func_002250E8(s32 v);
extern "C" void func_00227A20();
extern "C" void func_00226DF8(s32 a, u64 b);
extern "C" void func_00227AA8();

extern "C" void func_00270A98(CVec4 *d, const CVec4 *a, const CVec4 *b);
extern "C" void func_00270B00(CVec4 *d, const CVec4 *a, const CVec4 *b);
inline f32 VuSqrt(f32 x) {
    f32 r;
    asm volatile("mfc1 $8, %1\n\tqmtc2.ni $8, $vf2\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(r) : "f"(x) : "$8");
    return r;
}

extern f32 D_002A6800[];
inline s32 Ftoi15(f32 x) {
    s32 i;
    asm volatile(
        "mfc1 %0, %1\n"
        "qmtc2.ni %0, $vf2\n"
        "vftoi15.x $vf2, $vf2\n"
        "qmfc2.ni %0, $vf2\n"
        : "=r"(i) : "f"(x));
    return i;
}
extern "C" void func_00201C20(f32 x, f32 y, f32 z);
extern "C" void func_00201C88(f32 x, f32 y, f32 z);
extern "C" void func_00201EB0(f32 a);
extern "C" void func_00201ED8(f32 x, f32 y);
extern "C" void func_00201FF8(f32 a, f32 b, f32 c, f32 d);
extern "C" void func_00201F18(f32 x, f32 y);
extern "C" void func_00201E70(f32 a, f32 b);
extern "C" CVec4 *func_00202368(void);
CVec4 *Func2022A0();
struct CSndCam {
    f32 m_eye[3];             // 0x0
    u8 padC[4];
    f32 m_at[3];              // 0x10
    u8 pad1C[4];
    f32 m20, m24;             // 0x20
    u8 pad28[8];
    f32 m_fov;                // 0x30
    f32 m34;                  // 0x34
    f32 m38, m3C;             // 0x38
};

// VU0 micro subroutine with cos in vf4 and sin in vf5 (the angle in turns).
#define VU_ROT(mic, ang) do { \
        s32 i_ = (Ftoi15(ang) >> 1) & 0x3FFF; \
        s32 s_ = ((s32 *)D_002A6800)[i_]; \
        s32 c_ = ((s32 *)D_002A6800)[(i_ + 0x1000) & 0x3FFF]; \
        asm volatile("qmtc2.i %0, $vf4\n\tqmtc2.ni %1, $vf5\n\tvnop\n\tvnop\n\tvcallms " #mic : : "r"(c_), "r"(s_)); \
    } while (0)
struct CSndView {
    u8 pad0[0x10];
    f32 m_pos[3];             // 0x10
    u8 pad1C[4];
    f32 m_rot[3];             // 0x20
};
struct CSndOwnerB {
    u8 pad0[8];
    void *m8;                 // 0x8
};
struct CSndMat { f32 m[4][4]; } __attribute__((aligned(16)));
#define VU_GET_MAT(m) \
    asm volatile("la $2, %0\n\tvcallms 0x0\n\tqmfc2.i $0, $vf0\n\tsqc2 $vf24, 0x0($2)\n\tsqc2 $vf25, 0x10($2)\n\tsqc2 $vf26, 0x20($2)\n\tsqc2 $vf27, 0x30($2)\n\tvcallms 0x40" : "=m"(m) : : "$2")
struct CSndVec { f32 x, y, z, w; } __attribute__((aligned(16)));
extern "C" void func_0025DBB8(void *p, CSndMat *m);
extern "C" void func_00128528(void *a, void *b, void *c, s32 d);
class CSndObj18B : public CSndObj18 {
public:
    void SetVol(f32 v) {
        m_unk34 = 1;
        m_unk3C = m_unk3E = (s32)(v * 128.0f);
    }
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_00128870);

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_00128BB0);

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_00128E78);

void CSndWorkReal::MoveToList(CSndNode *n) {
    CSndNode *h = &m_list;
    n->m_prev->m_next = n->m_next;
    n->m_next->m_prev = n->m_prev;
    n->m_next = n;
    n->m_prev = n;
    CSndNode *p = h->m_prev;
    n->m_next = h;
    n->m_prev = p;
    p->m_next = n;
    n->m_next->m_prev = n;
}

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_00128F10);

void CSndWorkReal::FadeIn(s32 on, s32 dur) {
    m_fade3C.Start(on ? 1.0f : 0.0f, dur);
}

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_00129020);

void CSndWorkReal::CallFunc129458(const char *s, s32 v) {
    if (s[0]) {
        Func129458(s, v);
    }
}

void CSndWorkReal::Func1291B8(s32 on, s32 dur) {
    if (dur <= 0) {
        s32 v;
        f32 f;
        CSndObj18 *o;
        m_fade58.m_cur = on ? 0.0f : 1.0f;
        f = m_fade58.m_cur;
        m_fade58.m_from = f;
        m_fade58.m_to = f;
        o = m_unk18;
        o->m_unk34 = 1;
        v = (s32)(f * 128.0f);
        o->m_unk3E = v; //@p
        o->m_unk3C = v; //@p
        m_fade58.m_t = 0; //@p
        m_fade58.m_dur = 0; //@p
    } else {
        m_fade58.m_from = m_fade58.m_cur;
        m_fade58.m_to = on ? 0.0f : 1.0f;
        m_fade58.m_dur = dur;
        m_fade58.m_t = 0;
    }
}

void CSndWorkReal::SetPlaying(s32 on, s32 dur) {
    if (m_playing == on) {
        return;
    }
    m_playing = on;
    if (on) {
        StartAll();
    } else if (dur <= 0) {
        Func1295E8();
    } else {
        m_unk94 = dur;
        m_unk90 = 0;
    }
}

void CSndWorkReal::FadeTo(s32 dur, f32 v) {
    m_fade6C.Start(v, dur);
}

INCLUDE_RODATA("asm/nonmatchings/CSndWorkReal", D_002D4CB8);
CSndEntry *CSndWorkReal::Func1292E0(const char *name, s32 v) {
    CSndEntry *e;
    for (e = m_entries; e; e = e->m_next) {
        if (strcmp(e->m_name, name) == 0 && e->m_unk24 == v) break;
    }
    if (e) {
        e->m_unk40++;
    } else {
        e = m_free;
        if (e) {
            s32 h;
            m_free = e->m_next;
            strcpy(e->m_name, name);
            e->m_unk24 = v;
            func_00250828(D_002A0BEC, e->m_name);
            h = D_002A0BEC->Open(e->m_name);
            e->m_unk2C = 0;
            e->m_unk28 = h;
            e->m_unk40 = 1;
            e->m_unk30 = 0;
            e->m_unk34 = 0;
            e->m_unk3C = 0;
            if (h && !m_unk9C) {
                ((CSndWork *)e->m_snd)->Func25C648(h, 0);
                ((CSndWork *)e->m_snd)->SetVol(e->m_unk28, e->m_unk2C * e->m_unk38);
            }
            e->m_next = m_entries;
            m_entries = e;
        } else {
            Func235DE0("*** empty env unit\n");
        }
    }
    return e;
}
INCLUDE_RODATA("asm/nonmatchings/CSndWorkReal", D_002D4CD8);

void CSndWorkReal::Func129458(const char *name, s32 v) {
    CSndEntry *prev = (CSndEntry *)&m_entries;
    CSndEntry *e;
    for (e = m_entries; e; prev = e, e = e->m_next) {
        if (strcmp(e->m_name, name) == 0 && e->m_unk24 == v) {
            if (--e->m_unk40 > 0) continue;
            prev->m_next = e->m_next;
            if (e->m_unk28) ((CSndWork *)e->m_snd)->Func25C840(e->m_unk28, 0, 0);
            D_002A0BEC->Func250840(e->m_name);
            e->m_next = m_free;
            m_free = e;
            return;
        }
    }
}

void CSndWorkReal::StartAll() {
    CSndEntry *e;
    for (e = m_entries; e; e = e->m_next) {
        if (e->m_unk3C == 0) {
            Func1292E0(e->m_name, e->m_unk24);
            e->m_unk3C = 1;
            e->m_unk34 = 0;
            e->m_unk30 = e->m_unk2C;
            Func235DE0(D_002D4CD8, e->m_name, e->m_unk40);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", Func1295E8__12CSndWorkReal);
INCLUDE_RODATA("asm/nonmatchings/CSndWorkReal", D_002D4D00);

s32 IsSndPrefixed(const char *s) {
    return strstr(s, D_002A0BB0) == s;
}

#if 0 // DIFF 2 (g1): retail stores m_unkA4 before the printf format lui, ours after
int CSndWorkRealY::Play1296F0(const char *name, f32 f) {
    s32 h;
    CSndWork2 *snd;
    if (!IsSndPrefixed(name)) return 0;
    if (IsUnkA4Set()) return 0;
    h = Func129CC8(name);
    if (!h) return 0;
    snd = GetVolume(name);
    if (!snd) return 0;
    if (!snd->Func25C990(h)) {
        ((CSndDrvC *)D_002BA248)->V5(5, 0x40000);
        snd->Func25C648(h, 0);
        func_0025CDC0(snd, h, f);
        func_0025C910(snd, h, 1, 0);
        ((CSndDrvC *)D_002BA248)->V5(4, 0x40000);
        m_unkA0 = snd;
        m_unkA4 = h;
        Func235DE0("SND Resv %s : %X\n", name, h);
    }
    return 0;
}
#endif
INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_001296F0);

int CSndWorkReal::Func129848() {
    if (!m_unkA0 || !m_unkA4 || !m_unkA0->Func25C990(m_unkA4)) return 1;
    return func_0025CAC0(m_unkA0, m_unkA4);
}

void CSndWorkReal::StopSound() {
    if (m_unkA0 && m_unkA4) {
        m_unkA0->Func25C840(m_unkA4, 0, 0);
    }
    m_unkA0 = 0;
    m_unkA4 = 0;
}

#if 0 // DIFF 3 (g1): arg moves around the m_unkA4/m_unkA0 clears scheduled differently
void CSndWorkReal::Play129900(const char *name, f32 f, s32 a, s32 b, s32 pan) {
    CSndWork *snd = (CSndWork *)GetVolume(name);
    s32 h;
    if (!snd) return;
    h = Func129CC8(name);
    Func235DE0("SND Play %s : %X,%X\n", name, m_unkA4, h);
    if (h == m_unkA4 && func_0025CA58(snd, h)) {
        m_unkA0 = 0;
        m_unkA4 = 0;
        func_0025C910(snd, h, 0, 0);
    } else {
        StopSound();
        ((CSndDrvC *)D_002BA248)->V5(5, 0x40000);
        snd->Func25C648(h, 0);
        func_0025CDC0(snd, h, f);
        ((CSndDrvC *)D_002BA248)->V5(4, 0x40000);
    }
    func_0025CC18(snd, h, 0, 0);
    func_0025CC18(snd, h, a, b);
    return snd->Func25CB90(h, func_0010CDD0(0x80, pan), func_0010CE40(0x80, pan));
}
#endif
INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_00129900);

void CSndWorkReal::Stop129AE0(const char *name, s32 t) {
    CSndWork *snd;
    s32 i, h;
    if (strcmp(name, "BGM") == 0 || strcmp(name, "") == 0) {
        snd = (CSndWork *)m_unk28;
        for (i = func_0025CEA0(snd) - 1; i >= 0; i--) {
            s32 k = func_0025CEE8(snd, i);
            if (m_unkA4 != k) snd->Func25C840(k, 0, t);
        }
    }
    if (strcmp(name, "SE") == 0 || strcmp(name, "") == 0) {
        snd = (CSndWork *)m_unk24;
        for (i = func_0025CEA0(snd) - 1; i >= 0; i--) {
            snd->Func25C840(func_0025CEE8(snd, i), 0, t);
        }
    }
    snd = (CSndWork *)GetVolume(name);
    if (snd) {
        h = Func129CC8(name);
        snd->Func25C840(h, 0, t);
        if (m_unkA4 == h) {
            m_unkA0 = 0;
            m_unkA4 = 0;
        }
    }
}

s32 CSndWorkReal::GetVolume(const char *s) {
    return IsSndPrefixed(s) ? m_unk28 : m_unk24;
}

int CSndWorkReal::IsUnkA4Set() {
    return m_unkA0 != 0 && m_unkA4 != 0;
}

s32 CSndWorkReal::Func129CC8(const char *name) {
    if (IsSndPrefixed(name)) {
        char buf[0x100];
        s32 h;
        strcpy(buf, name + strlen(D_002A0BB0));
        h = D_002BA248->Find19(6);
        if (h >= 0) {
            s32 r = func_0020E698(h, buf);
            if (r >= 0) return r | 0x8060000;
        }
        return 0;
    } else {
        s32 *p = D_002BA248->Get39(name);
        if (p) return *p;
        return 0;
    }
}

void CSndWorkReal::Func129D90() {
    UpdateOwner();
    UpdateCharas();
    Func129EB0();
    Func12A0F0();
    m_fade3C.Update();
}

void CSndWorkReal::UpdateOwner() {
    if (m_unk4) {
        ((CSndOwner *)m_unk4)->Func11B118(this, ((m_unk2C >> 1) ^ 1) & 1);
    }
}

void CSndWorkReal::UpdateCharas() {
    CCharaObj *p;
    for (p = LiveChara((CCharaObj *)m_list.m_next); p; p = LiveChara(p->m_next)) {
        p->Func116AE0();
    }
}

void CSndWorkReal::Func129EB0() {
    CSndView *v = (CSndView *)m_unk0;
    if (v) {
        CSndVec t;
        CSndVec r;
        CSndMat m;
        t.x = -v->m_pos[0];
        t.y = -v->m_pos[1];
        t.z = -v->m_pos[2];
        t.w = 1.0f;
        r.x = -v->m_rot[0];
        r.y = -v->m_rot[1];
        r.z = -v->m_rot[2];
        asm volatile("vcallms 0x30\n\tvcallms 0x20" : : : "memory");
        VU_ROT(0x90, r.z);
        VU_ROT(0xB0, r.x);
        VU_ROT(0xA0, r.y);
        asm volatile("qmfc2.i $0, $vf0\n\tlqc2 $vf4, %0\n\tvnop\n\tvnop\n\tvcallms 0x80" : : "m"(t));
        VU_GET_MAT(m);
        func_0025DBB8(m_unk1C, &m);
    }
    if (m_unk4 && !(m_unk2C & 2)) {
        void *o = ((CSndOwnerB *)m_unk4)->m8;
        CCharaObj *p;
        for (p = LiveChara((CCharaObj *)m_list.m_next); p; p = LiveChara(p->m_next)) {
            if (*(s32 *)((u8 *)p + 0x188)) func_00128528(o, m_unk1C, (u8 *)p + 0xA0, *(s32 *)((u8 *)p + 0x178));
        }
    }
}

void CSndWorkReal::Func12A0F0() {
    m_fade6C.Update();
    ((CSndObj18B *)m_unk20)->SetVol(m_unk98 * m_fade6C.m_cur);
    if (m_fade58.m_t < m_fade58.m_dur) {
        m_fade58.m_t++;
        m_fade58.m_cur = m_fade58.m_from + (m_fade58.m_to - m_fade58.m_from) * (f32)m_fade58.m_t / (f32)m_fade58.m_dur;
        ((CSndObj18B *)m_unk18)->SetVol(m_fade58.m_cur);
    }
    if (m_unk90 < m_unk94) {
        f32 f;
        CSndEntry *e;
        m_unk90++;
        f = (f32)m_unk90 / (f32)m_unk94;
        for (e = m_entries; e; e = e->m_next) {
            e->m_unk2C = (s32)(e->m_unk30 + (e->m_unk34 - e->m_unk30) * f);
            if (e->m_unk28) ((CSndWork *)e->m_snd)->SetVol(e->m_unk28, e->m_unk2C * e->m_unk38);
        }
        if (m_unk90 >= m_unk94) Func1295E8();
    }
}

s32 Func12A2F0() {
    Func225088();
    func_002250E8(0);
    func_00227A20();
    func_00226DF8(0x47, 0x58002);
    func_00227AA8();
    Func2251E8();
    return Func2250C0();
}

f32 SndAtten12A340(const CVec4 *a, const CVec4 *b, f32 nearD, f32 range) {
    CVec4 d, sq;
    f32 dist, r;
    if (nearD == 0.0f && range == 0.0f) return 1.0f;
    func_00270A98(&d, b, a);
    func_00270B00(&sq, &d, &d);
    dist = VuSqrt(sq.x + sq.y + sq.z);
    if (dist < nearD) {
        r = 1.0f;
    } else if (dist < nearD + range) {
        r = 1.0f - (dist - nearD) / range;
    } else {
        r = 0.0f;
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_0012A420);

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_0012A510);

s32 FindCharaFor(CCharaObj *p, CSndTarget *o) {
    u8 m[0x40];
    for (; p; p = LiveChara(p->m_next)) {
        if (p->m_name && strcmp(p->m_name->m_name, o->m_name) == 0
            && p->Func117AC8((s32)m, (s32)&o->m_unk1B8)) {
            Func270CA0(&o->m_unkE0, m);
            return 1;
        }
    }
    Func270E48(&o->m_unkE0);
    return 0;
}

#if 0 // 305 vs 282 insns (g1): content decoded (GIF A+D packet: FRAME with mask, ZBUF, TEST, PRIM/RGBAQ/XYZ2 sprite, FRAME/ZBUF restore, end tag, then the VIF DIRECT header); retail skips some of the per-word stores of the packet pointer D_2EBF8C and reloads it at other points, so the packet macro shape is still unknown
void FadeFill12A6B0(s32 alpha) {
    s32 xy[4];
    u64 fr, zb;
    s32 n;
    xy[0] = 0x6C00;
    xy[1] = 0x7200;
    xy[2] = 0x9400;
    xy[3] = 0x8E00;
    func_002375C0();
    func_00237408(0x10);
    D_2EBF88 = D_2EBF8C = (u64 *)D_002B94E4;
    fr = func_0023C650(func_0023A2F0(func_0023A0E8()));
    PK(0x1000000000000001ULL);
    PK(0xE);
    PK(((fr & 0x3FFF) >> 5) | (((fr >> 14) & 0x3F) << 16) | (((fr >> 32) & 0x3F) << 24) | ((u64)0xFFFFFF << 32));
    PK(0x4C);
    zb = func_0023C658(func_0023A2F0(func_0023A0E8()));
    PK(0x1000000000000001ULL);
    PK(0xE);
    PK(((zb & 0x3FFF) >> 5) | (((zb >> 32) & 0x3F) << 24));
    PK(0x4E);
    PK(0x1000000000000001ULL);
    PK(0xE);
    PK(0x38002);
    PK(0x47);
    PK(0x1000000000000004ULL);
    PK(0xE);
    PK(0x46);
    PK(0);
    PK((u64)alpha << 24);
    PK(1);
    PK(xy[0] | (u64)xy[1] << 16);
    PK(5);
    PK(xy[2] | (u64)xy[3] << 16);
    PK(5);
    fr = func_0023C650(func_0023A2F0(func_0023A0E8()));
    PK(0x1000000000000001ULL);
    PK(0xE);
    PK(((fr & 0x3FFF) >> 5) | (((fr >> 14) & 0x3F) << 16) | (((fr >> 32) & 0x3F) << 24));
    PK(0x4C);
    zb = func_0023C658(func_0023A2F0(func_0023A0E8()));
    PK(0x1000000000000001ULL);
    PK(0xE);
    PK(((zb & 0x3FFF) >> 5) | (((zb >> 32) & 0x3F) << 24));
    PK(0x4E);
    PK(0x1000000000000001ULL);
    PK(0xE);
    PK(0x58002);
    PK(0x47);
    PK(0x8000);
    PK(0);
    func_00237460();
    D_002B94E4 = (u32 *)D_2EBF8C;
    *D_002B94E4++ = 0;
    *D_002B94E4++ = 0;
    *D_002B94E4++ = 0x11000000;
    n = func_00237450();
    *D_002B94E4++ = ((n + 15) / 16 - 1) | 0x50000000;
    func_002374B0();
    func_002377D8();
}
#endif
INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_0012A6B0);

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_0012AB18);

void ScaleSndVec(CVec4 *v, s32 id, CSndTarget *t, f32 x) {
    if (x <= 0.0f) {
        return;
    }
    if (t->m_unk1C8 == id) {
        return;
    }
    Func271960(v, v, x * -0.5f + 1.0f);
}

void SetSndCam12AFA8(CSndCam *c) {
    f32 a = c->m_fov / 720.0f;
    f32 x, y;
    u8 *tbl;
    func_00201C20(c->m_eye[0], c->m_eye[1], c->m_eye[2]);
    func_00201C88(c->m_at[0], c->m_at[1], c->m_at[2]);
    tbl = (u8 *)D_002A6800;
    func_00201EB0(*(f32 *)(tbl + ((((Ftoi15(a) >> 1) & 0x3FFF) + 0x1000) & 0x3FFF) * 4) * 320.0f
                  / *(f32 *)(tbl + ((Ftoi15(a) << 1) & 0xFFFC)));
    func_00201ED8(c->m20 + 2048.0f + c->m38, c->m24 + 2048.0f + c->m3C);
    func_00201FF8(1.0f, 65536.0f, 101.0f, 16777115.0f);
    x = c->m20 + c->m38;
    x = (x >= 0.0f ? x + 320.0f : 320.0f - x) + 128.0f;
    y = c->m24 + c->m3C;
    y = (y >= 0.0f ? y + 224.0f : 224.0f - y) + 128.0f;
    func_00201F18(x, y);
    func_00201E70(c->m34, c->m34 * 0.47f + c->m34 * 0.47f);
    func_00202368();
    Func2022A0();
}

INCLUDE_RODATA("asm/nonmatchings/CSndWorkReal", D_002D4D50);
INCLUDE_RODATA("asm/nonmatchings/CSndWorkReal", D_002D4D60);
INCLUDE_RODATA("asm/nonmatchings/CSndWorkReal", D_002D4D70);
INCLUDE_RODATA("asm/nonmatchings/CSndWorkReal", D_002D4D80);
INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_0012B180);

void *Func12C3E0() {
    u8 *p = (u8 *)Func237570(0x260);
    Func237A88(p, 0x26);
    Func238158(Func237C30(p + 0x250), 1);
    return p;
}

void SetSndWorkRealInstance(void *p) {
    D_002A0BE0 = p;
}

void *GetSndWorkRealInstance() {
    return D_002A0BE0;
}

void CSndWorkReal::SetUnkA8(s32 v) {
    m_unkA8 = v;
}

void CSndWorkReal::SetPos(const CVec4 *a, const CVec4 *b, f32 f) {
    Func270C50(&m_unkB0, a);
    Func270C50(&m_unkC0, b);
    m_unkD0 = f;
}
INCLUDE_RODATA("asm/nonmatchings/CSndWorkReal", D_002D4DE8);
INCLUDE_RODATA("asm/nonmatchings/CSndWorkReal", D_002D4E00);
