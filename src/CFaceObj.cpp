#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CFaceObjSub10DC60Item {
public:


    u8 pad0[0x14];
    s32 m_unk14;              // 0x14
};
class CFaceObjSub10DC60 {
public:
    s32 GetItemUnk14();
    s32 Func10DD38();

    s32 m_unk0;               // 0x0
    CFaceObjSub10DC60Item* m_item; // 0x4
    u8 pad8[0x8];
    s32 m_unk10;              // 0x10
};

void *Func245D00(int size);
extern void (*D_002B91B0)(void *p);
// One key of a face animation (0x34 bytes).
struct CFaceKey {
    u8 pad0[0x24];
    s16 m_unk24;              // 0x24
    s16 m_dur;                // 0x26
    s16 m_unk28;              // 0x28
    s16 m_unk2A;              // 0x2A
    u8 pad2C[0x8];
};
struct CFaceAnim {
    s32 m_id;                 // 0x0
    s32 m_num;                // 0x4
    CFaceKey *m_keys;         // 0x8
};
// A face animation being played: current key and frame.
class CFaceTrack {
public:
    int Step(int loop);

    CFaceAnim *m_anim;        // 0x0
    s32 m_key;                // 0x4
    s32 m_frame;              // 0x8
};
struct CFaceSet {
    s32 m_id;                 // 0x00
    CFaceAnim **m_anims[3];   // 0x04
    s32 m_num[3];             // 0x10
};
class CFaceResSub10F8F0 {
public:
    CFaceSet *Find(s32 id);

    u8 pad0[0x8];
    CFaceAnim *m_anims;       // 0x08
    s32 m_numAnims;           // 0x0C
};
struct CFaceInit {
    u8 pad0[0x18];
    s32 m_num[3];             // 0x18
};
struct CFacePart {
    CFaceTrack *m_tracks;     // 0x0
    s32 m_num;                // 0x4
};
// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CFaceObj, its only
// virtual. The vptr follows its fields at 0x50. (CCharaObj.cpp called it CCharaObjPart24.)
class CFaceObj {
public:
    CFaceObj();
    virtual ~CFaceObj();
    void Release();
    int Init(CFaceInit *init);
    void SetSet(s32 id);
    void Func10DB70();
    void Func10DBD8(s32 k);
    void Func10DC80(s32 *ids, s32 n);
    void Update();
    int Draw(void *p, s32 a, s32 b, s32 c, s32 d);
    int DrawTrack(CFaceTrack *t, u8 *base, s32 c, s32 d);

    CFaceResSub10F8F0 *m_res; // 0x00
    CFacePart *m_parts;       // 0x04
    s32 m_unk8;               // 0x08
    s32 m_unkC;               // 0x0C
    s32 m_unk10;              // 0x10
    s32 m_unk14;              // 0x14
    s32 m_unk18;              // 0x18
    CFaceTrack m_extra[4];    // 0x1C
    s32 m_unk4C;              // 0x4C
};

//@sym Find__17CFaceResSub10F8F0i 0x10F8F0
//@sym Draw__8CFaceObjPviiii 0x10DFD0
//@sym Init__8CFaceObjP9CFaceInit 0x10D8F8
// @decl-end

CFaceObj::CFaceObj() {
    s32 i;
    m_parts = (CFacePart *)Func245D00(0x18);
    for (i = 0; i < 3; i++) {
        m_parts[i].m_tracks = 0;
        m_parts[i].m_num = 0;
    }
    m_unk18 = -1;
    m_unk8 = 0;
    m_unkC = 0;
    m_unk10 = 0;
    m_unk14 = 0;
    m_unk4C = 0;
}

CFaceObj::~CFaceObj() {
    Release();
    if (m_parts) {
        D_002B91B0(m_parts);
    }
}

int CFaceObj::Init(CFaceInit *init) {
    s32 i;
    Release();
    for (i = 0; i < 3; i++) {
        m_parts[i].m_tracks = (CFaceTrack *)Func245D00(init->m_num[i] * sizeof(CFaceTrack));
        m_parts[i].m_num = 0;
    }
    m_res = (CFaceResSub10F8F0 *)init;
    return 1;
}

void CFaceObj::Release() {
    s32 i;
    for (i = 0; i < 3; i++) {
        if (m_parts[i].m_tracks) {
            D_002B91B0(m_parts[i].m_tracks);
            m_parts[i].m_tracks = 0;
            m_parts[i].m_num = 0;
        }
    }
    m_unk18 = -1;
    m_unk8 = 0;
    m_unkC = 0;
    m_unk10 = 0;
    m_unk14 = 0;
    m_unk4C = 0;
    m_res = 0;
}

void CFaceObj::SetSet(s32 id) {
    CFaceSet *set;
    s32 i, j;
    if (m_res && (set = m_res->Find(id))) {
        for (i = 0; i < 3; i++) {
            s32 n = set->m_num[i];
            for (j = 0; j < n; j++) {
                m_parts[i].m_tracks[j].m_anim = set->m_anims[i][j];
                m_parts[i].m_tracks[j].m_key = 0;
                m_parts[i].m_tracks[j].m_frame = 0;
            }
            m_parts[i].m_num = n;
        }
        m_unk8 = id;
    } else {
        for (i = 0; i < 3; i++) {
            m_parts[i].m_num = 0;
        }
        m_unk8 = -1;
    }
    m_unkC = 0;
    m_unk10 = -1;
}

void CFaceObj::Func10DB70() {
    if (m_res) {
        CFacePart *p = &m_parts[1];
        s32 j;
        for (j = 0; j < p->m_num; j++) {
            p->m_tracks[j].m_key = 0;
            p->m_tracks[j].m_frame = 0;
        }
        m_unkC = 1;
    }
}

void CFaceObj::Func10DBD8(s32 k) {
    if (m_res) {
        CFacePart *p;
        s32 j;
        if (k < 0 || m_parts[2].m_num - 1 < k) {
            m_unk10 = -1;
            return;
        }
        p = &m_parts[2];
        for (j = 0; j < p->m_num; j++) {
            p->m_tracks[j].m_key = 0;
            p->m_tracks[j].m_frame = 0;
        }
        m_unk10 = k;
    }
}

s32 CFaceObjSub10DC60::GetItemUnk14() {
    return m_unk0 ? m_item->m_unk14 : 0;
}

void CFaceObj::Func10DC80(s32 *ids, s32 n) {
    s32 i, j;
    if (m_res) {
        for (i = 0; i < n && i < 4; i++) {
            CFaceTrack *t = &m_extra[i];
            t->m_anim = 0;
            t->m_key = 0;
            t->m_frame = 0;
            for (j = 0; j < m_res->m_numAnims; j++) {
                if (m_res->m_anims[j].m_id == ids[i]) {
                    t->m_anim = &m_res->m_anims[j];
                    break;
                }
            }
        }
        m_unk4C = i;
    }
}

s32 CFaceObjSub10DC60::Func10DD38() { if (!m_unk0) return -1; s32 k = m_unk10; if (k < 0 || m_item->m_unk14 - 1 < k) return m_item->m_unk14 > 0 ? 0 : -1; return k; }

int CFaceTrack::Step(int loop) {
    CFaceAnim *a = m_anim;
    if (!a) return 1;
    if (m_key >= a->m_num) return 1;
    CFaceKey *k = &a->m_keys[m_key]; if (m_frame++ >= k->m_dur) {
        m_frame = 0;
        m_key++;
        if (loop && m_key >= a->m_num) m_key = a->m_num - 1;
    }
    return 0;
}

void CFaceObj::Update() {
    s32 i, j;
    for (i = 0; i < 3; i++) {
        CFacePart *p = &m_parts[i];
        switch (i) {
        case 0:
            for (j = 0; j < p->m_num; j++) p->m_tracks[j].Step(1);
            break;
        case 1:
            if (m_unkC) {
                s32 done = 1;
                for (j = 0; j < p->m_num; j++) {
                    s32 r = p->m_tracks[j].Step(0) != 0;
                    done &= r;
                }
                if (done) m_unkC = 0;
            }
            break;
        case 2: {
            s32 k = ((CFaceObjSub10DC60 *)this)->Func10DD38();
            if (k >= 0) p->m_tracks[k].Step(1);
            break;
        }
        }
    }
    for (i = 0; i < m_unk4C; i++) m_extra[i].Step(1);
}

INCLUDE_ASM("asm/nonmatchings/CFaceObj", Draw__8CFaceObjPviiii);

int CFaceObj::DrawTrack(CFaceTrack *t, u8 *base, s32 c, s32 d) {
    CFaceAnim *a = t->m_anim;
    CFaceKey *k;
    if (!a) return 0;
    if (t->m_key >= a->m_num) return 0;
    k = &a->m_keys[t->m_key];
    if (k->m_unk24 < 0) return 0;
    return Draw(base + k->m_unk24 * 16, k->m_unk28, k->m_unk2A, c, d);
}

INCLUDE_ASM("asm/nonmatchings/CFaceObj", func_0010E138);
