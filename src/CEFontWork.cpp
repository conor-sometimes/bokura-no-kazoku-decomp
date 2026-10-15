#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern s32 D_002A0394;
extern s32 D_002A0398;

// Library font object (0x2561D0 constructor, vtable _vt$9CFontWork); the vptr follows its
// fields at 0x7C.
class CFontWork {
public:
    CFontWork();
    virtual ~CFontWork();
    u8 pad0[0x7C];
};
class CEFontWork : public CFontWork {
public:
    CEFontWork();
    virtual ~CEFontWork();
    void CopyUnk84(const CEFontWork *src);

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
    virtual void Vf5(s32 a, s32 b);
    virtual void Vf6(s32 a);
    virtual void Vf7(s32 a);
    virtual void Vf8();
    virtual void Vf9();
    virtual void Vf10();
    virtual void Vf11();
    virtual void Vf12();
    virtual void Vf13();
    virtual void Vf14();
    virtual void Vf15();
    virtual s32 Vf16(void *p);
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
    virtual void Vf34(s32 a);
    virtual s32 Vf35(void *p);
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
extern "C" void func_001F0C60(void (*f)(s32 *), const char *name, s32 a, s32 b);
void PlayEFontSe(s32 *p);
s32 GetEFontUnk2A0398();
extern char D_002D2BE0[], D_002D2C08[];
struct CFontTable {
    u8 pad0[0x34];
    u8 m34;                   // 0x34
    u8 pad35[0x7];
    s16 m3C;                  // 0x3C
    s16 m3E;                  // 0x3E
    void SetUnk3C(s32 v) {
        if (v >= 0) {
            m3E = v;
            m3C = v;
        } else {
            m3C = v;
            m3E = -v;
        }
        m34 = 1;
    }
};
#include "CFlagWork.h"
extern void *(*D_002B91A4)(u32 size);
extern u32 D_002A0290;
extern u8 D_002A02A0[];
extern u8 D_0029F3A0[], D_0029F470[];
extern char D_002D2B70[];
extern "C" void *func_00206790(u32 size);
extern "C" void *func_002070F8(u32 size);
extern "C" void func_00219620(u32 p, u32 size);
extern "C" void func_002195D8(void *p, u32 size);
extern "C" void func_00219590(void *p, u32 size);
extern "C" void func_00219668(u32 a, u32 b);
extern "C" void func_00219368(s32 a);
extern "C" void func_00219430(void *p);
extern "C" void func_002063B0(s32 a, s32 b);
extern "C" void func_0025C230(void *p);
extern "C" void func_0025C438(s32 a, s32 b);
void LoadEFontSe();
// @decl-end

CEFontWork::CEFontWork() {
    m_unk80 = 0;
}

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

void InitFontTables() {
    CFontTable *t;
    t = (CFontTable *)GetFontTable(1);
    t->SetUnk3C(D_002A26E0->Func1091B0(0x262D));
    t = (CFontTable *)GetFontTable(2);
    t->SetUnk3C(D_002A26E0->Func1091B0(0x262E));
    t = (CFontTable *)GetFontTable(3);
    t->SetUnk3C(D_002A26E0->Func1091B0(0x262F));
    t = (CFontTable *)GetFontTable(4);
    t->SetUnk3C(D_002A26E0->Func1091B0(0x2630));
}

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

int StartEFontSe(const char *name) {
    if (GetEFontUnk2A0398()) {
        Func235DE0(D_002D2BE0);
        return 0;
    }
    if (!name || !*name) name = D_002D2C08;
    func_001F0C60(PlayEFontSe, name, 0, 0);
    D_002A0398 = 1;
    return 1;
}

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
