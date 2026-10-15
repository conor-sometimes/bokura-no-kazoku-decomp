#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CPushBuf.h"
extern s32 D_002BA218[];
extern s32 D_002BA244;
struct CSndEnt { u8 pad0[8]; char m_name[0x20]; s32 m28; s32 m2C; u8 pad30[4]; s32 m34; s32 m38; };
struct CSndSeq { u8 pad0[0x1C]; };
struct CPk8 { u64 v __attribute__((packed)); };
extern const char D_002E7748[];
extern const char D_002E7750[];
struct CSndPrm { u8 pad[0x40]; };
class CSndWork { public: void Func25D130(CSndPrm *p); };
extern u8 D_41A788[];
void *Func25C220();
void Func25BD60(CSndPrm *p);

class ISndMgr {
public:
    virtual void Release();                          // [0]
};
class CSndMgr : public ISndMgr {
public:
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
    virtual s32 Func25A338(s32 a);                   // [16]
    virtual void Func25A418();                       // [17]
    virtual void Func18();                           // [18]
    virtual s32 Func25A538(s32 i);                   // [19]
    virtual s32 Func25A568(s32 i);                   // [20]
    virtual char *Func25A590(s32 i);                 // [21]
    virtual s32 Func25A5C0(s32 i);                   // [22]
    virtual s32 Func25A600(s32 i);                   // [23]
    virtual s32 Func25A628(s32 i);                   // [24]
    virtual s32 Func25A908(s32 i);                   // [25]
    virtual s32 Func25AAD0(s32 i);                   // [26]
    virtual s32 Func25AC38(s32 i);                   // [27]
    virtual s32 Func25AE80(s32 i);                   // [28]
    virtual s32 Func25AF70(s32 i);                   // [29]
    virtual s32 Func25B048(s32 i);                   // [30]
    virtual void Func25B230(s32 i);                  // [31]
    virtual s32 Func25B460(s32 i);                   // [32]
    virtual void Func25B608();                       // [33]
    virtual void Func34();                           // [34]
    virtual s32 Func25B698(s32 i);                   // [35]
    virtual void Func25B758();                       // [36]
    virtual void Func37();                           // [37]
    virtual CSndSeq *Func25B798(s32 i);              // [38]
    virtual s32 Func25B7D8(s32 i);                   // [39]
    virtual void Func25B860(s32 i, s32 v);           // [40]
    virtual s16 Func25B890(s32 i);                   // [41]
    virtual s32 Func25BAB0(s32 x);                   // [42]
    virtual s32 Func25BAD8(s32 x);                   // [43]
    virtual void Func25BB00();                       // [44]
    virtual s32 Func25A190(s32 i);                   // [45]
    virtual s32 Func25B8C8(s32 i);                   // [46]
    virtual s32 Func25B980(s32 i);                   // [47]
    CSndEnt *Func25A478(s32 i);
    CSndEnt *Func25A4D8(s32 i);
    s32 Func25BB30(u64 n, s32 x);
    s32 Func25BC90(u64 n, s32 x);
    s32 m_unk4;
    s32 m_unk8;
    CSndSeq *m_seqs;          // 0xC
    s32 m_numSeqs;            // 0x10
    CSndEnt *m_ents;          // 0x14
    s32 m_numEnts;            // 0x18
    u8 pad1C[4];
    s16 *m_vals;              // 0x20
};
s32 Func25ADD0(CPushBuf *p, s32 b, s32 c);
s32 Func25BDE8();
// @decl-end

s32 Func25A010(s32 i, s32 v) { return (v / D_002BA218[i]) << 10; }

void Func25A038(s32 v) { D_002BA244 = v; }

s32 Func25A048() { return D_002BA244; }

s32 Func25A058() { return 8; }

INCLUDE_ASM("asm/nonmatchings/Dk25A010", func_0025A060);

INCLUDE_ASM("asm/nonmatchings/Dk25A010", func_0025A098);

INCLUDE_ASM("asm/nonmatchings/Dk25A010", func_0025A190);

INCLUDE_ASM("asm/nonmatchings/Dk25A010", func_0025A278);

INCLUDE_ASM("asm/nonmatchings/Dk25A010", func_0025A338);

void CSndMgr::Func25A418() {
    Func25B608();
    if (m_ents) {
        delete[] m_ents;
        m_ents = 0;
        m_numEnts = 0;
    }
    m_unk4 = 0;
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

INCLUDE_ASM("asm/nonmatchings/Dk25A010", func_0025A5C0);

s32 CSndMgr::Func25A600(s32 i) {
    CSndEnt *e = Func25A4D8(i);
    if (e) return e->m34;
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/Dk25A010", func_0025A628);

INCLUDE_ASM("asm/nonmatchings/Dk25A010", func_0025A738);

INCLUDE_ASM("asm/nonmatchings/Dk25A010", func_0025A838);

INCLUDE_ASM("asm/nonmatchings/Dk25A010", func_0025A908);

INCLUDE_ASM("asm/nonmatchings/Dk25A010", func_0025AAD0);

INCLUDE_ASM("asm/nonmatchings/Dk25A010", func_0025AC38);

INCLUDE_ASM("asm/nonmatchings/Dk25A010", func_0025AD78);

s32 Func25ADD0(CPushBuf *p, s32 b, s32 c) {
    if (b && c > 0) return c;
    return p->Func248EB0();
}

INCLUDE_ASM("asm/nonmatchings/Dk25A010", func_0025AE00);

INCLUDE_ASM("asm/nonmatchings/Dk25A010", func_0025AE80);

INCLUDE_ASM("asm/nonmatchings/Dk25A010", func_0025AF70);

INCLUDE_ASM("asm/nonmatchings/Dk25A010", func_0025B048);

void CSndMgr::Func25B230(s32 i) {
    CSndEnt *e = Func25A478(i);
    if (e) e->m38++;
}

INCLUDE_ASM("asm/nonmatchings/Dk25A010", func_0025B260);

INCLUDE_ASM("asm/nonmatchings/Dk25A010", func_0025B308);

INCLUDE_ASM("asm/nonmatchings/Dk25A010", func_0025B390);

INCLUDE_ASM("asm/nonmatchings/Dk25A010", func_0025B3F0);

INCLUDE_ASM("asm/nonmatchings/Dk25A010", func_0025B460);

INCLUDE_ASM("asm/nonmatchings/Dk25A010", func_0025B608);

INCLUDE_ASM("asm/nonmatchings/Dk25A010", func_0025B698);

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

INCLUDE_ASM("asm/nonmatchings/Dk25A010", func_0025B7D8);

void CSndMgr::Func25B860(s32 i, s32 v) {
    if (i < 0 || m_numSeqs - 1 < i) return;
    m_vals[i] = v;
}

s16 CSndMgr::Func25B890(s32 i) {
    if (i < 0 || m_numSeqs - 1 < i) return 0;
    return m_vals[i];
}

INCLUDE_ASM("asm/nonmatchings/Dk25A010", func_0025B8C8);

INCLUDE_ASM("asm/nonmatchings/Dk25A010", func_0025B980);

s32 CSndMgr::Func25BAB0(s32 x) { return Func25BB30(((const CPk8 *)D_002E7748)->v, x); }

s32 CSndMgr::Func25BAD8(s32 x) { return Func25BC90(((const CPk8 *)D_002E7750)->v, x); }

void CSndMgr::Func25BB00() {
    CSndPrm p;
    Func25BD60(&p);
    ((CSndWork *)Func25C220())->Func25D130(&p);
}

INCLUDE_ASM("asm/nonmatchings/Dk25A010", Func25BB30__7CSndMgrUli);

INCLUDE_ASM("asm/nonmatchings/Dk25A010", Func25BC90__7CSndMgrUli);

INCLUDE_ASM("asm/nonmatchings/Dk25A010", Func25BD60__FP7CSndPrm);

s32 Func25BDD0() { return Func25BDE8(); }

INCLUDE_ASM("asm/nonmatchings/Dk25A010", Func25BDE8__Fv);

INCLUDE_ASM("asm/nonmatchings/Dk25A010", func_0025BE98);

INCLUDE_ASM("asm/nonmatchings/Dk25A010", func_0025C010);

INCLUDE_ASM("asm/nonmatchings/Dk25A010", func_0025C098);

INCLUDE_ASM("asm/nonmatchings/Dk25A010", func_0025C138);

INCLUDE_ASM("asm/nonmatchings/Dk25A010", func_0025C1E8);

void *Func25C220() { return D_41A788; }

INCLUDE_ASM("asm/nonmatchings/Dk25A010", func_0025C230);

INCLUDE_ASM("asm/nonmatchings/Dk25A010", func_0025C2C0);
