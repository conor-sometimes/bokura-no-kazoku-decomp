#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "Xmn.h"
#include "libc.h"
typedef int (*XmnCmpFn)(const char *a, const char *b);
extern XmnCmpFn D_002A5BDC;
extern XmnCmpFn D_002A5BE0;
extern s32 D_002A5BE4;
extern "C" int func_001EC120(const char *a, const char *b);
extern "C" int func_0028B570(const void *a, const void *b, u32 n);
extern const char D_002E20F0[];
inline void *XmnRel(s32 *o) { return *o ? (char *)o + *o : 0; }
inline void *XmnRel2(s32 *o) { char *r = 0; if (*o) r = (char *)o + *o; return r; }
struct CXmnHeader {
    char m_magic[0x10];       // 0x0
    s32 m_off10;              // 0x10
    s32 m_off14;              // 0x14
    s32 m_off18;              // 0x18
    s32 m_off1C;              // 0x1C
};

struct CRxMcSlot {
    s32 m_port;               // 0x0
    s32 m_busy;               // 0x4
    s32 m_result;             // 0x8
};
extern CRxMcSlot D_2ED208[2];
extern volatile CRxMcSlot *D_2ED200;
extern volatile CRxMcSlot *D_2ED220;
extern s32 D_002A5C8C;
extern const char D_002E2128[], D_002E2138[], D_002E2118[], D_002E2148[];
s32 Func235DE0(const char *fmt, ...);
extern "C" void func_001F1230();
extern "C" s32 func_002654B8(s32 mode, s32 *cmd, s32 *result);
extern "C" void func_00264AA8();
extern "C" void func_001EF0D8();
extern "C" void func_001F10C8(void (*fn)(s32));
extern "C" void func_001F1150(void (*fn)(s32));
extern "C" s32 func_001EF140();
extern "C" void func_0027BD78();
extern "C" void func_00273420(s32 x);
extern "C" s32 func_002655D8(s32 port, s32 slot, s32 *type, s32 *free, s32 *format);
extern "C" s32 func_002657C8(s32 port, s32 slot, s32 a, s32 b, s32 c, s32 d);
extern "C" s32 func_002659A8(s32 port, s32 slot, const char *a, s32 b);
extern "C" s32 func_00266198(s32 port, s32 slot, const char *a);
extern "C" s32 func_00264E90(s32 port, s32 slot, s32 a, s32 b);
extern "C" s32 func_00264FF0(s32 fd);
extern "C" s32 func_002650B0(s32 fd, s32 a, s32 b);
extern "C" s32 func_00265228(s32 fd, s32 a, s32 b);
extern "C" s32 func_00265340(s32 fd, s32 a, s32 b);
extern "C" s32 func_00265BB8(s32 port, s32 slot, s32 a);
extern "C" s32 func_00264FB8(s32 port, s32 slot, s32 a);
extern "C" s32 func_001ED6E0();
extern "C" void func_001ED730(s32 i);

extern "C" s32 func_001ED830(s32 nowait, s32 *res);
inline u32 EeGetStatus()
{
    u32 r;
    __asm__ volatile("sync.p");
    __asm__ volatile("mfc0 %0, $12" : "=r"(r));
    __asm__ volatile("sync.p");
    return r;
}
extern "C" void func_0027BD78();
struct CRxMcReqArgs {
    CRxMcSlot *m_slot;        // 0x0
    s32 (*m_fn)(s32 a, s32 b, s32 c, s32 d); // 0x4
    s32 m_a, m_b, m_c, m_d;   // 0x8
};
struct CRxMcInfo { s32 m_type; s32 m_free; s32 m_format; };
extern "C" s32 func_001EDA30(CRxMcInfo *info);
// @decl-end

extern "C" void func_001EB8E8(s32 nocase)
{
    if (nocase) { D_002A5BDC = func_001EC120; D_002A5BE0 = func_001EC120; }
    else { D_002A5BDC = (XmnCmpFn)strcmp; D_002A5BE0 = (XmnCmpFn)strcmp; }
}

INCLUDE_RODATA("asm/nonmatchings/Unit1EB8E8", D_002E2028);
INCLUDE_RODATA("asm/nonmatchings/Unit1EB8E8", D_002E2040);
INCLUDE_ASM("asm/nonmatchings/Unit1EB8E8", func_001EB920);

extern "C" void func_001EC0E0(XmnCmpFn fn)
{
    if (fn) {
        D_002A5BDC = fn;
        D_002A5BE4 = 1;
    } else {
        D_002A5BDC = D_002A5BE0;
        D_002A5BE4 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/Unit1EB8E8", func_001EC120);

INCLUDE_ASM("asm/nonmatchings/Unit1EB8E8", func_001EC250);

INCLUDE_ASM("asm/nonmatchings/Unit1EB8E8", func_001EC570);

extern "C" s32 func_001EC948()
{
    s32 ret = -1;
    for (s32 i = 0; i < D_002A5BCC; i++) {
        if (D_002A5BD0[i] == 0) {
            ret = i;
            break;
        }
    }
    return ret;
}

INCLUDE_ASM("asm/nonmatchings/Unit1EB8E8", func_001EC9A8);

INCLUDE_ASM("asm/nonmatchings/Unit1EB8E8", func_001ECA58);
INCLUDE_RODATA("asm/nonmatchings/Unit1EB8E8", D_002E2118);

extern "C" s32 func_001ECCA8(s32 i)
{
    if (i < 0) return 0;
    if (i >= D_002A5BCC) return 0;
    if (D_002A5BD0[i] == 0) return 0;
    if (D_002A5BD0[i]->m_mask) D_002B91B0(D_002A5BD0[i]->m_mask);
    D_002B91B0(D_002A5BD0[i]);
    D_002A5BD0[i] = 0;
    return 1;
}

extern "C" s32 func_001ECD60(s32 i, s32 flag)
{
    CXmnAnim *p = GetXmnAnim(i);
    if (p == 0) return 0;
    flag &= ~1;
    if (flag == 0) p->m_flags |= 1;
    return 1;
}

extern "C" s32 func_001ECDC8(s32 i)
{
    CXmnAnim *p = GetXmnAnim(i);
    if (p == 0) return 0;
    return !(p->m_flags & 1);
}

INCLUDE_ASM("asm/nonmatchings/Unit1EB8E8", func_001ECE18);

INCLUDE_ASM("asm/nonmatchings/Unit1EB8E8", func_001ECFF8);

INCLUDE_ASM("asm/nonmatchings/Unit1EB8E8", func_001ED318);

INCLUDE_ASM("asm/nonmatchings/Unit1EB8E8", func_001ED4C0);

INCLUDE_ASM("asm/nonmatchings/Unit1EB8E8", func_001ED6E0);

extern "C" void func_001ED730(s32 i)
{
    if (i < 2) {
        if (i >= 0) D_2ED200 = &D_2ED208[i];
    }
}

INCLUDE_ASM("asm/nonmatchings/Unit1EB8E8", func_001ED768);
INCLUDE_RODATA("asm/nonmatchings/Unit1EB8E8", D_002E2148);

extern "C" s32 func_001ED7F8()
{
    func_001F1150(func_001ED730);
    return func_001EF140();
}

extern "C" s32 func_001ED818(s32 x)
{
    s32 old = D_002A5C8C;
    D_002A5C8C = x;
    return old;
}

extern "C" s32 func_001ED830(s32 nowait, s32 *res)
{
    if (nowait == 0) {
        while (D_2ED200->m_busy) {
            if (!(EeGetStatus() & 0x10000)) {
                func_0027BD78();
                Func235DE0(D_002E2118);
                func_0027BD78();
            }
        }
    }
    if (res) {
        if (D_2ED200->m_busy) *res = 0;
        else *res = D_2ED200->m_result;
    }
    return D_2ED200->m_busy;
}

extern "C" s32 func_001ED908(u32 mode)
{
    func_001ED830(0, 0);
    s32 old = D_2ED200->m_port;
    if (mode < 2) D_2ED200->m_port = mode;
    return old;
}

extern "C" s32 func_001ED950() { return D_2ED200->m_port; }

extern "C" void func_001ED960(CRxMcSlot *p)
{
    p->m_busy = 0;
    p->m_result = 0x2000;
    p->m_port = 0;
}

extern "C" void func_001ED978(CRxMcReqArgs *r)
{
    CRxMcInfo info;
    D_2ED220 = r->m_slot;
    s32 (*fn)(s32, s32, s32, s32) = r->m_fn;
    func_00273420(0);
    s32 ret = fn(r->m_a, r->m_b, r->m_c, r->m_d);
    D_2ED220->m_result = ret;
    if (ret < 0 && fn != (s32 (*)(s32, s32, s32, s32))func_001EDA30) {
        func_001EDA30(&info);
        if (info.m_type < 2) {
            if (info.m_type >= 0) D_2ED220->m_result = -200;
        }
    }
    D_2ED220->m_busy = 0;
}

INCLUDE_ASM("asm/nonmatchings/Unit1EB8E8", func_001EDA30);

extern "C" s32 func_001EDB70(s32 a, s32 b, s32 c, s32 d)
{
    func_00273420(0);
    while (func_002657C8(D_2ED220->m_port, 0, a, b, c, d)) func_001F1230();
    s32 r = func_001ED6E0();
    if (r == -4) r = 0;
    return r;
}

extern "C" s32 func_001EDC18(const char *dir, s32 b)
{
    if (dir == 0) dir = D_002E2148;
    func_00273420(0);
    while (func_002659A8(D_2ED220->m_port, 0, dir, b)) func_001F1230();
    return func_001ED6E0();
}

extern "C" s32 func_001EDC90(const char *dir)
{
    if (dir == 0) dir = D_002E2148;
    func_00273420(0);
    while (func_00266198(D_2ED220->m_port, 0, dir)) func_001F1230();
    return func_001ED6E0();
}

extern "C" s32 func_001EDCF8(s32 a, s32 b)
{
    func_00273420(0);
    while (func_00264E90(D_2ED220->m_port, 0, a, b)) func_001F1230();
    return func_001ED6E0();
}

extern "C" s32 func_001EDD68(s32 fd)
{
    func_00273420(0);
    while (func_00264FF0(fd)) func_001F1230();
    return func_001ED6E0();
}

extern "C" s32 func_001EDDB0(s32 fd, s32 a, s32 b)
{
    func_00273420(0);
    while (func_002650B0(fd, a, b)) func_001F1230();
    return func_001ED6E0();
}

extern "C" s32 func_001EDE18(s32 fd, s32 a, s32 b)
{
    func_00273420(0);
    while (func_00265228(fd, a, b)) func_001F1230();
    return func_001ED6E0();
}

extern "C" s32 func_001EDE80(s32 fd, s32 a, s32 b)
{
    func_00273420(0);
    while (func_00265340(fd, a, b)) func_001F1230();
    return func_001ED6E0();
}

extern "C" s32 func_001EDEE8(s32 a, s32 ok)
{
    func_00273420(0);
    while (func_00265BB8(D_2ED220->m_port, 0, a)) func_001F1230();
    s32 r = func_001ED6E0();
    if (ok && r == -4) r = 0;
    return r;
}

extern "C" s32 func_001EDF78(s32 a, s32 ok)
{
    func_00273420(0);
    while (func_00264FB8(D_2ED220->m_port, 0, a)) func_001F1230();
    s32 r = func_001ED6E0();
    if (ok && r == -4) r = 0;
    return r;
}
