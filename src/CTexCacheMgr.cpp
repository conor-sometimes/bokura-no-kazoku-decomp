#include "common.h"

// CTexCacheMgr unit: the end of the font code (0x10C710-0x10CEE8, from CEFontWork.cpp), the
// font sub-object init (0x10CEE8) and the texture cache (CList.cpp): one object (lane cv).

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
int Func235DE0(const char *fmt, ...) throw();
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

// From CList.cpp
#include "CList.h"
// Texture cache entry (vtable _vt$10CCacheInfo), on the cache's list.
class CCacheInfo : public CListTag {
public:
    virtual ~CCacheInfo();
    s32 m10;                  // 0x10
    s32 m14;                  // 0x14
    s32 m18;                  // 0x18
    s32 m1C;                  // 0x1C
};
// The node list at 0x20 (TList<CCacheInfo>: CListTag fields, vptr at 0xC).
struct CTexCacheList { s32 m_isHead; CTexCacheList *m_prev; CTexCacheList *m_next; void *m_vt; };
// Vtable _vt$12CTexCacheMgr (in asm): slot 0 is an inline library function, slot 1
// (func_0010D028) the key method; the destructor is the last slot.
class ITexCacheMgr {
public:
    virtual void V0() = 0;
    virtual void V1() = 0;
    virtual void Release10D200() = 0;
    virtual void Clear() = 0;
    virtual void Age() = 0;
    virtual void V5() = 0;
};
class CTexCacheMgr : public ITexCacheMgr {
public:
    virtual void V0();
    virtual void V1();
    virtual void Release10D200();
    virtual void Clear();
    virtual void Age();
    virtual void V5();
    virtual ~CTexCacheMgr();
    // vptr 0x0
    void *m4;                 // 0x4
    s32 m8;                   // 0x8
    s32 mC;                   // 0xC
    s32 m10;                  // 0x10
    s32 m14;                  // 0x14
    s32 m18;                  // 0x18
    CCacheInfo *m1C;        // 0x1C
    CTexCacheList m20;        // 0x20
};
extern void (*D_002B91B0)(void *p);
void BlitFlip8(u8 *dst, u8 *src, int stride, int x, int y, int w, int h);
void BlitFlip32(u32 *dst, u32 *src, int stride, int x, int y, int w, int h);
void BlitFlip16(u16 *dst, u16 *src, int stride, int x, int y, int w, int h);

extern char D_vt5CList[] asm("_vt$5CList");
extern char D_vt8CListTag[] asm("_vt$8CListTag");
extern char D_vtTcMgr[] asm("_vt$12CTexCacheMgr");
extern char D_vtTcTList[] asm("_vt$t5TList1Z10CCacheInfo");
extern void *D_002A039C;
inline CTexCacheList *TcFirst(CTexCacheList *l) { CTexCacheList *n = l->m_next; return n->m_isHead ? 0 : n; }
inline CTexCacheList *TcRemove(CTexCacheList *t) { if (t) { t->m_prev->m_next = t->m_next; t->m_next->m_prev = t->m_prev; t->m_next = t; t->m_prev = t; } return t; }

s32 Func253A18(s32 a);
void *Func245D00(s32 n);
inline void TcInsert(CTexCacheList *n, CTexCacheList *h) { CTexCacheList *p = h->m_prev; n->m_next = h; n->m_prev = p; p->m_next = n; n->m_next->m_prev = n; }
inline void TcUnlink(CTexCacheList *t) { t->m_prev->m_next = t->m_next; t->m_next->m_prev = t->m_prev; t->m_next = t; t->m_prev = t; }

void *Func237570(int size);
extern "C" void func_0010D360(u8 *dst, u8 *src, int psm, int stride, int unused, int x, int y, int w, int h);
inline CCacheInfo *TcFirstE(CTexCacheList *l) { CTexCacheList *n = l->m_next; return n->m_isHead ? 0 : (CCacheInfo *)n; }
inline CCacheInfo *TcNextE(CCacheInfo *p) { CListTag *n = p->m_next; return n->m_isHead ? 0 : (CCacheInfo *)n; }
inline CCacheInfo *TcLastE(CTexCacheList *l) { CTexCacheList *n = l->m_prev; return n->m_isHead ? 0 : (CCacheInfo *)n; }
inline void TcToFront(CTexCacheList *t, CTexCacheList *h) {
    t->m_prev->m_next = t->m_next; t->m_next->m_prev = t->m_prev; t->m_next = t; t->m_prev = t;
    t->m_prev = h; t->m_next = h->m_next; h->m_next = t; t->m_next->m_prev = t;
}

extern int TexPrintf(const char *fmt, ...) asm("Func235DE0__FPCce");
// @decl-end

INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2040);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2050);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2060);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2070);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2080);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2088);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2098);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D20A0);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D20A8);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D20B8);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D20C8);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D20D8);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D20E8);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D20F8);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2100);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2110);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2118);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2120);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2130);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2140);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2150);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2158);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2168);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2178);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2188);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2198);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D21A8);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D21B8);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D21C8);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D21D8);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D21E8);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D21F8);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2208);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2218);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2228);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2238);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2248);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2258);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2270);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2280);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2298);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D22B0);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D22C8);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D22D8);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D22F0);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2308);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2320);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2330);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2340);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2350);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2360);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2370);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2388);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D23A0);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D23B8);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D23C8);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D23E0);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D23F8);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2410);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2420);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2438);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2450);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2468);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2478);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2490);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D24A8);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D24C0);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D24D0);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D24E8);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2500);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2518);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2528);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2538);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2540);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2550);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2560);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2568);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2578);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2590);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D25A0);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D25B8);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D25C8);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D25E0);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D25F0);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2608);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2618);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2630);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2640);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2658);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2668);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2678);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2690);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D26A0);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D26B8);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D26C8);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D26D8);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D26E8);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D26F8);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2708);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2718);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2728);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2738);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2748);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2758);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2768);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2778);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2788);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2798);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D27A8);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D27B8);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D27C8);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D27D8);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D27E8);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D27F8);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2808);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2810);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2818);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2828);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2838);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2848);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2858);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2868);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2878);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2888);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2898);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D28A8);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D28B8);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D28C8);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D28D8);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D28E8);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D28F8);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2908);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2918);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2928);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2938);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2948);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2960);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2970);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2980);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2990);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D29A0);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D29B8);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D29D0);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D29E8);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D29F8);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2A00);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2A18);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2A20);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2A30);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2A38);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2A48);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2A50);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2A60);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2A68);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2A78);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2A80);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2A90);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2A98);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2AA8);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2AB0);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2AC0);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2AC8);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2AD8);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2AE0);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2AE8);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2AF0);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2AF8);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2B00);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2B08);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2B10);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2B18);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2B20);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2B30);
INCLUDE_ASM("asm/nonmatchings/CTexCacheMgr", func_0010C710);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2B70);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2B90);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2BA8);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2BC8);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2BE0);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2C08);

extern "C" void func_0010C798() {
    s32 i;
    s32 *pp;
    if (!D_002BA248) return (void)Func235DE0(D_002D2B70);
    D_002A028C = D_002B91A4(0x200040);
    D_002A0290 = ((u32)D_002A028C + 0x3F) & ~0x3F;
    D_002A0294 = func_00206790(0x20000);
    D_002A0298 = func_002070F8(0x1BAFC0);
    func_00219620(D_002A0290, 0x200000);
    func_002195D8(D_002A0294, 0x20000);
    func_00219590(D_002A0298, 0x1BAFC0);
    func_00219668(0x1C0000, 0x18000);
    func_00219668(0x1E0000, 0x18000);
    func_00219368(0xB);
    func_00219430(D_002A02A0);
    D_002BA248->Vf5(4, 0x40000);
    D_002BA248->Vf6(2);
    D_002BA248->Vf7(1);
    D_002BA248->Vf16(D_0029F3A0);
    D_002BA248->Vf34(100);
    D_002BA248->Vf35(D_0029F470);
    func_002063B0(1, 0);
    LoadEFontSe();
    for (i = 4, pp = D_002A0380; i >= 0; i--, pp++) {
        void *p = operator new(0x6C);
        func_0025C230(p);
        *pp = (s32)p;
    }
    func_0025C438(D_002A0380[0], D_002A0380[1]);
    func_0025C438(D_002A0380[0], D_002A0380[2]);
    func_0025C438(D_002A0380[0], D_002A0380[3]);
    func_0025C438(D_002A0380[0], D_002A0380[4]);
}

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

INCLUDE_ASM("asm/nonmatchings/CTexCacheMgr", func_0010CDD0);

INCLUDE_ASM("asm/nonmatchings/CTexCacheMgr", func_0010CE40);

CEFontWorkSub10CEE8 *NewEFontWorkSub() {
    CEFontWorkSub10CEE8 *p = (CEFontWorkSub10CEE8 *)operator new(0x30);
    p->Init10CEE8();
    return p;
}


void CEFontWorkSub10CEE8::Init10CEE8() {
    CTexCacheMgr *m = (CTexCacheMgr *)this;
    CTexCacheList *l = &m->m20;
    *(void **)m = D_vtTcMgr;
    l->m_vt = D_vtTcTList;
    l->m_isHead = 1;
    l->m_prev = l;
    l->m_next = l;
    D_002A039C = m;
    m->m4 = 0;
    m->m8 = 0;
    m->mC = 0;
    m->m10 = 0;
    m->m14 = 0;
    m->m18 = 0;
    m->m1C = 0;
}


CTexCacheMgr::~CTexCacheMgr() {
    CTexCacheList *l;
    CTexCacheMgr::Release10D200();
    D_002A039C = 0;
    l = &m20;
    l->m_vt = D_vt5CList;
    while (TcRemove(TcFirst(l)));
    l->m_vt = D_vt8CListTag;
    l->m_prev->m_next = l->m_next;
    l->m_next->m_prev = l->m_prev;
    l->m_next = l;
    l->m_prev = l;
}

extern "C" s32 func_0010D028(CTexCacheMgr *m, s32 a, s32 b, s32 c, s32 n) {
    s32 u = Func253A18(a) * b * c;
    s32 total = u * n;
    void *p = Func245D00(total);
    if (!p) {
        Func235DE0("*** can't allocate reverse buffer (size=%d)\n", total);
    } else {
        s32 i;
        m->m4 = p;
        p = 0;
        m->m8 = a;
        m->mC = b;
        m->m10 = c;
        m->m14 = u;
        m->m18 = n;
        m->m1C = new CCacheInfo[n];
        for (i = 0; i < m->m18; i++) {
            m->m1C[i].m10 = -1;
            m->m1C[i].m14 = 0;
            m->m1C[i].m18 = (s32)m->m4 + i * u;
            m->m1C[i].m1C = 0;
            {
                CTexCacheList *e = (CTexCacheList *)&m->m1C[i];
                TcUnlink(e);
                TcInsert(e, &m->m20);
            }
        }
    }
    if (p) D_002B91B0(p);
    return 0;
}

void CTexCacheMgr::Release10D200() {
    if (m4) {
        D_002B91B0(m4);
        m4 = 0;
    }
    if (m1C) {
        delete[] m1C;
        m18 = 0;
    }
    m8 = 0;
    mC = 0;
    m10 = 0;
    m14 = 0;
}

void CTexCacheMgr::Clear() {
    int i;
    for (i = 0; i < m18; i++) {
        m1C[i].m10 = -1;
        m1C[i].m14 = 0;
        m1C[i].m1C = 0;
    }
}

void CTexCacheMgr::Age() {
    int i;
    for (i = 0; i < m18; i++) {
        m1C[i].m1C--;
        m1C[i].m1C = m1C[i].m1C < 0 ? 0 : m1C[i].m1C;
    }
}

extern "C" void func_0010D360(u8 *dst, u8 *src, int psm, int stride, int unused, int x, int y, int w, int h) {
    switch (psm) {
    case 0:
        BlitFlip32((u32 *)dst, (u32 *)src, stride, x, y, w, h);
        return;
    case 1: {
        u8 *d = dst;
        u8 *s = src + (y * stride + x + w) * 3 - 3;
        int i, j = h;
        for (; j > 0; j--) {
            for (i = w; i > 0; i--) {
                u8 r = *s--;
                u8 g = *s--;
                u8 b = *s--;
                *d++ = b;
                *d++ = g;
                *d++ = r;
            }
            s += (stride + w) * 3;
        }
        return;
    }
    case 2:
    case 0xA:
        BlitFlip16((u16 *)dst, (u16 *)src, stride, x, y, w, h);
        return;
    case 0x13:
    case 0x1B:
        BlitFlip8(dst, src, stride, x, y, w, h);
        return;
    case 0x14:
    case 0x24:
    case 0x2C: {
        u8 *s = src + ((y * stride + x + w) >> 1) - 1;
        int i;
        for (; h > 0; h--) {
            for (i = w >> 1; i > 0; i--) {
                u8 c = *s--;
                *dst++ = (c << 4) | (c >> 4);
            }
            s += (stride + w) >> 1;
        }
        return;
    }
    default:
        TexPrintf("*** unknown pixel mode '%X'\n", psm);
        __asm__("");
        return;
    }
}

extern "C" void *func_0010D4F0(CTexCacheMgr *m, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 k) {
    CTexCacheList *l = &m->m20;
    CCacheInfo *p;
    void *buf;
    s32 size;
    for (p = TcFirstE(l); p; p = TcNextE(p)) {
        if (p->m10 == a && p->m14 == b) {
            p->m1C = 2;
            TcToFront((CTexCacheList *)p, l);
            return (void *)p->m18;
        }
    }
    size = Func253A18(c) * h * k;
    if (m->m14 >= size) {
        p = TcLastE(l);
        if (p && !p->m1C) {
            p->m1C = 2;
            p->m10 = a;
            p->m14 = b;
            TcToFront((CTexCacheList *)p, l);
            buf = (void *)p->m18;
            goto blit;
        }
    }
    buf = Func237570(size);
blit:
    func_0010D360((u8 *)buf, (u8 *)b, c, d, e, f, g, h, k);
    return buf;
}

void BlitFlip32(u32 *dst, u32 *src, int stride, int x, int y, int w, int h) {
    u32 *s = src + (y * stride + x) + w - 1;
    int i;
    for (; h > 0; h--) {
        for (i = w; i > 0; i--) *dst++ = *s--;
        s += stride + w;
    }
}

void BlitFlip16(u16 *dst, u16 *src, int stride, int x, int y, int w, int h) {
    u16 *s = src + (y * stride + x) + w - 1;
    int i;
    for (; h > 0; h--) {
        for (i = w; i > 0; i--) *dst++ = *s--;
        s += stride + w;
    }
}

void BlitFlip8(u8 *dst, u8 *src, int stride, int x, int y, int w, int h) {
    u8 *s = src + w + (y * stride + x) - 1;
    int i;
    for (; h > 0; h--) {
        for (i = w; i > 0; i--) *dst++ = *s--;
        s += stride + w;
    }
}
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2D28);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2D38);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2D40);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2D48);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2D58);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2D70);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2D80);
INCLUDE_RODATA("asm/nonmatchings/CTexCacheMgr", D_002D2D90);
