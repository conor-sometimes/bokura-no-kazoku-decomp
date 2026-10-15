#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
void *Func25DFE0(s32 n);
void *Func25ED28(void *p, s32 a, s32 b);
struct CSndFlt;
void Func25D478(CSndFlt *f);
extern u8 D_vtSndUnitSeq[] __asm__("_vt$t12TSndUnitReal1Z11CSndUnitSeq");
extern "C" s32 func_0020E338(s32 a);
extern "C" s32 func_0020E488(void);
extern "C" void func_0020A1E0(s32 h, s32 x);
extern "C" void func_002094A0(s32 h, s32 x);
struct CSndUnitH { u8 pad0[0x20]; u8 m20; u8 pad21[0x37]; s32 m_num; s32 m_h[1]; };

extern "C" void *memset(void *d, int c, unsigned int n);
void *Func25F7B8(void *p, s32 a, s32 b, s32 c, s32 d);
extern u8 D_vtSndUnitStr[] __asm__("_vt$t12TSndUnitReal1Z11CSndUnitStr");
extern u8 D_vtCSndUnitSeq[] __asm__("_vt$11CSndUnitSeq");
extern "C" void func_0020F480(s32 h, s32 x);
extern "C" void func_00219950(s32 h);
extern "C" void func_00219970(s32 h);
extern "C" void func_00219990(s32 h);
extern "C" void *func_0025C098(void *p, s32 a);
extern "C" s32 func_00262B18(u32 ch, u32 md, u32 n, void *buf);
class CSndMgrV2 {
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual s32 GetId(s32 i);
};
extern CSndMgrV2 *D_002BA248;
struct CSndUnitStrH { u8 pad0[0x20]; u8 m20; u8 pad21[0x37]; s32 m_num; s32 m_h[0x1C]; s32 mCC; s32 mD0; s32 mD4; };
struct CSndSub68 { s16 m0; s16 m2; s32 m4; CSndSub68() { m4 = -1; m2 = 0; m0 = 0; } };
struct CSndUnitSeqH { u8 pad0[0x50]; u8 m50; u8 pad51[3]; s32 m54; u8 pad58[0x10]; CSndSub68 m68; u8 pad70[0x40]; s32 mB0; };
inline void *operator new(unsigned int, void *p) { return p; }
struct CSndStrBuf { u8 pad0[8]; u32 m_mode; void *m_buf; };

struct CSndLinkB { s32 m0; CSndLinkB *m4; CSndLinkB *m8; void *mC; };
extern u8 D_vtCSndUnitTg[] __asm__("_vt$10CSndUnitTg");
extern u8 D_vtCSndUnitSeqD[] __asm__("_vt$11CSndUnitSeq");
extern u8 D_vtCSndUnitStrD[] __asm__("_vt$11CSndUnitStr");
extern "C" void func_0025C138(CSndLinkB *u, s32 chrg);
void Func25E030(void *p);
void Func25E3B0(CSndUnitH *u, s32 x);
void Func25EE28(CSndUnitH *u, s32 x);
void Func25FA18(CSndUnitStrH *u, s32 x);
// @decl-end

extern "C" void func_0025E340(CSndLinkB *u, s32 chrg) {
    u->mC = D_vtCSndUnitTg;
    Func25E3B0((CSndUnitH *)u, 0);
    func_0025C138(u, 0);
    if (chrg & 1) return Func25E030(u);
}

void Func25E3B0(CSndUnitH *u, s32 x) {
    for (s32 i = 0; i < u->m_num; i++) {
        func_0020A1E0(u->m_h[i], x);
        u->m_h[i] = -1;
    }
    u->m_num = 0;
    u->m20 = 0;
}

INCLUDE_ASM("asm/nonmatchings/Dk25E340", func_0025E438);

INCLUDE_ASM("asm/nonmatchings/Dk25E340", func_0025E590);

void *Func25EC68(s32 a, s32 b, s32 c, s32 d) {
    void *p = Func25DFE0(0xB4);
    Func25ED28(p, a, d);
    return p;
}

void *Func25ECC0(s32 a, s32 b, s32 c, s32 d) {
    u8 *p = (u8 *)Func25DFE0(0xF0);
    Func25ED28(p, a, d);
    *(void **)(p + 0xC) = D_vtSndUnitSeq;
    Func25D478((CSndFlt *)(p + 0xC0));
    return p;
}

void *Func25ED28(void *p, s32 a, s32 b) {
    CSndUnitSeqH *u = (CSndUnitSeqH *)p;
    func_0025C098(p, a);
    *(void **)((u8 *)p + 0xC) = D_vtCSndUnitSeq;
    new (&u->m68) CSndSub68;
    u->mB0 = D_002BA248->GetId(a);
    u->m54 = b;
    u->m50 = 1;
}

extern "C" void func_0025EDB8(CSndLinkB *u, s32 chrg) {
    u->mC = D_vtCSndUnitSeqD;
    Func25EE28((CSndUnitH *)u, 0);
    func_0025C138(u, 0);
    if (chrg & 1) return Func25E030(u);
}

void Func25EE28(CSndUnitH *u, s32 x) {
    for (s32 i = 0; i < u->m_num; i++) {
        func_002094A0(u->m_h[i], x);
        u->m_h[i] = -1;
    }
    u->m_num = 0;
    u->m20 = 0;
}

INCLUDE_ASM("asm/nonmatchings/Dk25E340", func_0025EEB0);

INCLUDE_ASM("asm/nonmatchings/Dk25E340", func_0025F028);

void *Func25F6B8(s32 a, s32 b, s32 c, s32 d) {
    void *p = Func25DFE0(0xD8);
    Func25F7B8(p, a, b, c, d);
    return p;
}

void *Func25F730(s32 a, s32 b, s32 c, s32 d) {
    u8 *p = (u8 *)Func25DFE0(0x110);
    Func25F7B8(p, a, b, c, d);
    *(void **)(p + 0xC) = D_vtSndUnitStr;
    Func25D478((CSndFlt *)(p + 0xE0));
    return p;
}

INCLUDE_ASM("asm/nonmatchings/Dk25E340", Func25F7B8__FPviiii);

extern "C" void func_0025F9A8(CSndLinkB *u, s32 chrg) {
    u->mC = D_vtCSndUnitStrD;
    Func25FA18((CSndUnitStrH *)u, 0);
    func_0025C138(u, 0);
    if (chrg & 1) return Func25E030(u);
}

void Func25FA18(CSndUnitStrH *u, s32 x) {
    for (s32 i = 0; i < u->m_num; i++) {
        func_0020F480(u->m_h[i], x);
        u->m_h[i] = -1;
    }
    u->m_num = 0;
    if (u->mCC) {
        func_00219950(u->mCC);
        u->mCC = 0;
    }
    if (u->mD0) {
        func_00219970(u->mD0);
        u->mD0 = 0;
    }
    if (u->mD4) {
        func_00219990(u->mD4);
        u->mD4 = 0;
    }
    u->m20 = 0;
}

s32 Func25FAE0(s32 a, s32 x) {
    s32 t = func_0020E338(a);
    if (!t) return t;
    return t == 1 ? x : 0;
}

s32 Func25FB18() {
    switch (func_0020E488()) {
    case 0: return 0x2800;
    case 1: return 0x5000;
    case 2: return 0x5000;
    }
    return 0;
}

s32 Func25FB70() {
    switch (func_0020E488()) {
    case 0: return 0x2800;
    case 1: return 0;
    case 2: return 0;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/Dk25E340", func_0025FBC8);

INCLUDE_ASM("asm/nonmatchings/Dk25E340", func_0025FD30);

INCLUDE_ASM("asm/nonmatchings/Dk25E340", func_0025FE88);

INCLUDE_ASM("asm/nonmatchings/Dk25E340", func_00260690);

INCLUDE_ASM("asm/nonmatchings/Dk25E340", func_00260758);

INCLUDE_ASM("asm/nonmatchings/Dk25E340", func_00260878);
