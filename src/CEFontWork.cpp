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

INCLUDE_ASM("asm/nonmatchings/CEFontWork", func_0010CBC0);

int GetFontTable(u32 i) {
    if (i >= 5) {
        Func235DE0(D_002D2BA8, i);
        return 0;
    }
    return D_002A0380[i];
}

INCLUDE_ASM("asm/nonmatchings/CEFontWork", func_0010CC48);

INCLUDE_ASM("asm/nonmatchings/CEFontWork", func_0010CCC8);

INCLUDE_ASM("asm/nonmatchings/CEFontWork", func_0010CD48);

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
