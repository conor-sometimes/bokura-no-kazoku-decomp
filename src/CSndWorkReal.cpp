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
};

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
    u8 pad38[0x4];
    s32 m_unk3C;              // 0x3C
    s32 m_unk40;              // 0x40
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

class CSndWorkReal {
public:
    void CallFunc129458(const char *s);
    void Func129458(const char *s);
    int IsUnkA4Set();
    void SetUnkA8(s32 v);
    void SetChara(CCharaObj **pp);
    void MoveToList(CSndNode *n);
    void FadeIn(s32 on, s32 dur);
    void FadeTo(s32 dur, f32 v);
    void SetPlaying(s32 on, s32 dur);
    void Func1292E0(const char *name, s32 v);
    void StartAll();
    void Func1295E8();
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
    u8 pad14[0x10];
    s32 m_unk24;              // 0x24
    s32 m_unk28;              // 0x28
    s32 m_unk2C;              // 0x2C
    u8 pad30[0xC];
    CSndFade m_fade3C;        // 0x3C
    u8 pad50[0x1C];
    CSndFade m_fade6C;        // 0x6C
    u8 pad80[0x4];
    CSndEntry *m_entries;     // 0x84
    CSndEntry *m_free;        // 0x88
    s32 m_playing;            // 0x8C
    s32 m_unk90;              // 0x90
    s32 m_unk94;              // 0x94
    u8 pad98[0x8];
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
int Func235DE0(const char *fmt, ...);
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

void CSndWorkReal::CallFunc129458(const char *s) {
    if (s[0]) {
        Func129458(s);
    }
}

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_001291B8);

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
INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", Func1292E0__12CSndWorkRealPCci);
INCLUDE_RODATA("asm/nonmatchings/CSndWorkReal", D_002D4CD8);

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", Func129458__12CSndWorkRealPCc);

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

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_001296F0);

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_00129848);

void CSndWorkReal::StopSound() {
    if (m_unkA0 && m_unkA4) {
        m_unkA0->Func25C840(m_unkA4, 0, 0);
    }
    m_unkA0 = 0;
    m_unkA4 = 0;
}

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_00129900);

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_00129AE0);
INCLUDE_RODATA("asm/nonmatchings/CSndWorkReal", D_002D4D40);
INCLUDE_RODATA("asm/nonmatchings/CSndWorkReal", D_002D4D48);

s32 CSndWorkReal::GetVolume(const char *s) {
    return IsSndPrefixed(s) ? m_unk28 : m_unk24;
}

int CSndWorkReal::IsUnkA4Set() {
    return m_unkA0 != 0 && m_unkA4 != 0;
}

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_00129CC8);

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

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", Func129EB0__12CSndWorkReal);

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", Func12A0F0__12CSndWorkReal);

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_0012A2F0);

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_0012A340);

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

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_0012AFA8);

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
