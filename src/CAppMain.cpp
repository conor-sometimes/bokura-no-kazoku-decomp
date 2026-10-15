#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "libc.h"
extern "C" unsigned int strlen(const char *s);
s32 Func235DE0(const char *fmt, ...);
class CTaskList24F5C0;
void AddFadeMgr(CTaskList24F5C0 *l);
void AddSnapMgr(CTaskList24F5C0 *l);
void AddPadMgr(CTaskList24F5C0 *l);
void AddInterfResSub169090(CTaskList24F5C0 *l);
void AddPhotoEventObjSub16D4D8(CTaskList24F5C0 *l);
extern s32 D_002A5BD4;
extern s32 D_002A5BD8;
extern char D_2EC1F0[][64];
extern const char D_002E1FD0[];
extern const char D_002E1FF8[];
typedef void (*VoidFn)();
extern VoidFn D_002A5BC4;
extern "C" void func_001EB1E8();
extern "C" void func_001EB4B0();
struct CAnim1EA {
    u16 m_unk0;               // 0x0
    u16 m_id;                 // 0x2
    s32 m_unk4;               // 0x4
    u16 m_unk8;               // 0x8
    u16 m_unkA;               // 0xA
    f32 m_rate;               // 0xC
    s32 m_unk10;              // 0x10
    s32 m_unk14;              // 0x14
    s32 m_unk18;              // 0x18
    s32 m_unk1C;              // 0x1C
};
extern s32 D_002A5BCC;
extern CAnim1EA **D_002A5BD0;
inline CAnim1EA *GetAnim(s32 i) { return (i >= 0 && i < D_002A5BCC) ? D_002A5BD0[i] : 0; }
extern void *(*D_002B91A4)(u32 n);
extern void (*D_002B91B0)(void *p);
void Func1EB828(int x);
extern "C" void func_001EB8E8(s32 x);
extern "C" void func_001ECCA8(s32 i);
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CAppMain", func_001E91B8);

INCLUDE_ASM("asm/nonmatchings/CAppMain", func_001E95C0);

INCLUDE_ASM("asm/nonmatchings/CAppMain", func_001E9968);

INCLUDE_ASM("asm/nonmatchings/CAppMain", func_001E9CB0);

extern "C" void func_001E9E00(CTaskList24F5C0 *l)
{
    AddFadeMgr(l);
    AddSnapMgr(l);
    AddPadMgr(l);
    AddInterfResSub169090(l);
    AddPhotoEventObjSub16D4D8(l);
}

INCLUDE_ASM("asm/nonmatchings/CAppMain", func_001E9E48);

INCLUDE_ASM("asm/nonmatchings/CAppMain", func_001EA728);

INCLUDE_ASM("asm/nonmatchings/CAppMain", func_001EA780);

INCLUDE_ASM("asm/nonmatchings/CAppMain", func_001EA838);

extern "C" s32 func_001EAAF0(s32 n)
{
    D_002A5BCC = n;
    D_002A5BD0 = (CAnim1EA **)D_002B91A4(n * 4);
    if (D_002A5BD0 == 0) return 0;
    for (s32 i = 0; i < D_002A5BCC; i++) D_002A5BD0[i] = 0;
    Func1EB828(0);
    func_001EB8E8(0);
    return 1;
}

extern "C" s32 func_001EAB90()
{
    if (D_002A5BD0 == 0) return 0;
    for (s32 i = 0; i < D_002A5BCC; i++) {
        if (D_002A5BD0[i]) func_001ECCA8(i);
    }
    D_002B91B0(D_002A5BD0);
    D_002A5BD0 = 0;
    return 1;
}

f32 Func1EAC30(int i)
{
    CAnim1EA *p = GetAnim(i);
    if (p == 0) return -1.0f;
    return p->m_unk8 * (60.0f / p->m_rate) * p->m_unkA;
}

extern "C" s32 func_001EACB8(CAnim1EA *p)
{
    if (p == 0) return -1;
    if (p->m_unk14) return 0;
    if (p->m_unk18) return 1;
    if (p->m_unk1C) return 2;
    return -1;
}

extern "C" s32 func_001EACF0(s32 i)
{
    CAnim1EA *p = GetAnim(i);
    if (p == 0) return -1;
    return p->m_id;
}

extern "C" f32 func_001EAD38(s32 i, f32 t)
{
    CAnim1EA *p = GetAnim(i);
    if (p == 0) return -1.0f;
    return t * p->m_rate / 60.0f;
}

INCLUDE_ASM("asm/nonmatchings/CAppMain", func_001EADA0);

INCLUDE_ASM("asm/nonmatchings/CAppMain", func_001EAE70);

INCLUDE_ASM("asm/nonmatchings/CAppMain", func_001EAF10);

INCLUDE_ASM("asm/nonmatchings/CAppMain", func_001EAFF0);

INCLUDE_ASM("asm/nonmatchings/CAppMain", func_001EB0C0);

extern "C" s32 func_001EB178(s32 mode)
{
    s32 ok = 1;
    switch (mode) {
    case 0: D_002A5BC4 = func_001EB1E8; break;
    case 1: D_002A5BC4 = func_001EB4B0; break;
    default: ok = 0; break;
    }
    return ok;
}

extern "C" s32 func_001EB1C0() { return ((s32 (*)())D_002A5BC4)(); }

INCLUDE_ASM("asm/nonmatchings/CAppMain", func_001EB1E8);

INCLUDE_ASM("asm/nonmatchings/CAppMain", func_001EB4B0);

void Func1EB828(int x) { D_002A5BD4 = x; }

void Func1EB838(void *p)
{
    const char *name = (const char *)p;
    if (name == 0) {
        D_002A5BD8 = 0;
        return;
    }
    if (strlen(name) >= 0x40) return (void)Func235DE0(D_002E1FD0, name);
    if (D_002A5BD8 >= 0x20) return (void)Func235DE0(D_002E1FF8);
    return (void)strcpy(D_2EC1F0[D_002A5BD8++], name);
}
