#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern s32 D_002A0394;
extern s32 D_002A0398;

class CEFontWork {
public:
    void CopyUnk84(const CEFontWork *src);

    u8 pad0[0x80];
    s32 m_unk80;              // 0x80
    s32 m_unk84;              // 0x84
};

void *operator new(unsigned int n);
int Func235DE0(const char *fmt, ...);
extern char D_002D2BA8[];
extern s32 D_002A0380[];
extern void *D_002A028C;
extern void *D_002A0294;
extern void *D_002A0298;
extern void (*D_002B91B0)(void *p);
void Func2067E0(void *p);
void Func207148(void *p);
class CEFontWorkSub10CEE8 { public: void Init10CEE8(); };
CEFontWorkSub10CEE8 *NewEFontWorkSub();
int GetFontTable(u32 i);
int ScaleNeg(int a, int b);
int ScalePos(int a, int b);
void FreeFontData();

// Sound driver at D_002BA248 (library side); only the slots called here are typed.
class CSndDrv2BA248 {
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
    virtual void Vf19();
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
    virtual s32 Play(s32 kind, s32 id, s32 a, s32 b, s32 c);
    virtual void Vf31();
    virtual void Stop(s32 h, s32 a);
    virtual void Vf33();
    virtual void Vf34();
    virtual void Vf35();
    virtual void Vf36();
    virtual void Vf37();
    virtual void Vf38();
    virtual void Vf39();
    virtual void Vf40();
    virtual void Vf41();
    virtual void Vf42();
    virtual s32 Load(const char *name);
};
extern CSndDrv2BA248 *D_002BA248;
extern char D_002D2B90[], D_002D2BC8[];
void StopEFontSe();
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CEFontWork", func_0010BF88);

void CEFontWork::CopyUnk84(const CEFontWork *src) {
    m_unk80 = src->m_unk84;
}

INCLUDE_RODATA("asm/nonmatchings/CEFontWork", D_002D2008);
INCLUDE_ASM("asm/nonmatchings/CEFontWork", func_0010BFD0);
INCLUDE_RODATA("asm/nonmatchings/CEFontWork", D_002D2028);

int GetEFontUnkC() {
    return 0xC;
}

INCLUDE_ASM("asm/nonmatchings/CEFontWork", func_0010C710);

INCLUDE_ASM("asm/nonmatchings/CEFontWork", func_0010C798);

void FreeFontData() {
    if (D_002A028C) D_002B91B0(D_002A028C);
    if (D_002A0294) Func2067E0(D_002A0294);
    if (D_002A0298) Func207148(D_002A0298);
}

INCLUDE_ASM("asm/nonmatchings/CEFontWork", func_0010CA90);

void LoadEFontSe() {
    D_002BA248->Load(D_002D2B90);
}

int GetFontTable(u32 i) {
    if (i >= 5) {
        Func235DE0(D_002D2BA8, i);
        return 0;
    }
    return D_002A0380[i];
}

void PlayEFontSe(s32 *p) {
    s32 id = *p;
    StopEFontSe();
    D_002A0394 = D_002BA248->Play(9, id, -1, 0, 0);
    if (!D_002A0394) Func235DE0(D_002D2BC8, id);
    D_002A0398 = 0;
}

INCLUDE_ASM("asm/nonmatchings/CEFontWork", func_0010CCC8);

void StopEFontSe() {
    if (D_002A0394 >= 0) {
        D_002BA248->Stop(D_002A0394, 0);
        D_002A0394 = -1;
    }
}

s32 GetEFontUnk2A0398() {
    return D_002A0398;
}

s32 GetEFontUnk2A0394() {
    return D_002A0394 < 0 ? 0 : 0x8090000;
}

INCLUDE_ASM("asm/nonmatchings/CEFontWork", func_0010CDD0);

INCLUDE_ASM("asm/nonmatchings/CEFontWork", func_0010CE40);

CEFontWorkSub10CEE8 *NewEFontWorkSub() {
    CEFontWorkSub10CEE8 *p = (CEFontWorkSub10CEE8 *)operator new(0x30);
    p->Init10CEE8();
    return p;
}
