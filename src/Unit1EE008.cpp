#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "libc.h"
struct CRxMcSlot {
    s32 m_port;               // 0x0
    s32 m_busy;               // 0x4
    s32 m_result;             // 0x8
};
extern CRxMcSlot *D_2ED200;
extern CRxMcSlot *D_2ED220;
typedef s32 (*RxMcFn)(s32 a, s32 b, s32 c, s32 d);
extern "C" s32 func_001ED830(s32 nowait, s32 *res);
extern "C" void func_001ED978(void *req);
extern "C" s32 func_001EF210(void (*fn)(void *), CRxMcSlot *slot, RxMcFn f, s32 a, s32 b, s32 c, s32 d);
extern "C" void func_00273420(s32 x);
extern "C" void func_001F1230();
extern "C" s32 func_001ED6E0(...);
extern "C" s32 func_00265D98(s32 port, s32 slot, s32 a, s32 b, s32 c);
extern "C" s32 func_00265AE8(s32 port, s32 slot);
extern "C" s32 func_002660C8(s32 port, s32 slot);
extern "C" s32 func_001EDCF8(const char *name, s32 mode);
extern "C" s32 func_001EDDB0(s32 fd, s32 off, s32 whence);
extern "C" s32 func_001EDE18(s32 fd, void *buf, s32 n);
extern "C" s32 func_001EDD68(s32 fd);
struct CRxCrcHeader {
    char m_magic[4];          // 0x0 "!crc"
    s32 m_value;              // 0x4
};
extern s32 D_002A5C90;
extern u16 D_2ED228[256];
extern "C" s32 func_001EDA30(...);
extern "C" s32 func_001EDB70(...);
extern "C" s32 func_001EDC18(...);
extern "C" s32 func_001EDC90(...);
extern "C" s32 func_001EDE80(...);
extern "C" s32 func_001EDEE8(...);
extern "C" s32 func_001EDF78(...);
extern "C" s32 func_001EE318(...);
extern "C" s32 func_001EE4F8(...);
extern "C" s32 func_001EE668(...);
extern "C" s32 func_001EE940(...);
inline void RxCrcInit() {
    for (u32 i = 0; i < 0xFF; i++) {
        u32 c = i << 8;
        for (u32 j = 0; j < 8; j++) {
            if (c & 0x8000) c = (c << 1) ^ 0x1021;
            else c <<= 1;
        }
        D_2ED228[i] = c;
    }
}
struct CRxMcReq { RxMcFn m_fn; s32 m_a, m_b, m_c, m_d; };
extern "C" s32 func_001EE200(const char *name, s32 strict);
extern "C" s32 func_001EE8D8(CRxMcReq *r);

//@sym D_2FD890 0x2FD890
//@sym D_2FD894 0x2FD894
inline s32 EeGetStatus()
{
    s32 r;
    __asm__ volatile("sync.p\n\tmfc0 %0, $12\n\tsync.p" : "=r"(r));
    return r;
}
struct CRxSemaParam {
    s32 m_count;              // 0x0
    s32 m_maxCount;           // 0x4
    s32 m_initCount;          // 0x8
    s32 m_waitThreads;        // 0xC
    u32 m_attr;               // 0x10
    u32 m_option;             // 0x14
};
extern s32 D_2FD898[2];
extern "C" s32 func_002731A0(CRxSemaParam *p);
extern "C" s32 func_002731B0(s32 sema);
extern "C" s32 func_002731C0(s32 sema);
extern "C" s32 func_002731F0(s32 sema);
extern "C" void func_001F1A80(s32 (*fn)(), s32 a, s32 b, s32 c);
extern "C" s32 func_001EF418();
// DMA work: 0x2FD880 madr, 0x884 remaining, 0x888 chunk, 0x88C handler id, 0x890, 0x894 busy
extern s32 D_2FD880, D_2FD884, D_2FD888, D_2FD88C, D_2FD890, D_2FD894;
extern "C" void func_0027E578();
extern "C" s32 func_00272EB0(s32 cause, s32 (*fn)(), s32 next);
extern "C" s32 func_00272ED0(s32 cause, s32 id);
extern "C" s32 func_0027E498(s32 a, s32 b);
extern "C" s32 func_001EF520();
extern "C" void func_001EF378();
extern "C" void func_001EF3D0();
extern volatile s32 D_002A5C94, D_002A5C98, D_002A5C9C;
extern s32 D_2ED440;
extern u8 D_2ED880[];
extern "C" void func_001EEFA8();
extern "C" s32 func_001F18F0(void (*fn)(), void *stack, s32 size, s32 prio, s32 arg);
extern "C" s32 func_001F18D0(s32 th, s32 x);
extern "C" void func_001F15F0();
extern "C" void func_001F1610();
extern "C" void func_001F1748(s32 th);
extern "C" void func_0027BD78();
s32 Func235DE0(const char *fmt, ...);
extern const char D_002E21C0[];

#include "Xmn.h"
extern "C" s32 func_001EF700(s32 i);
extern "C" void *memcpy(void *d, const void *s, u32 n);
struct CIpuObj {
    const void *m_src;        // 0x0
    u32 m_size;               // 0x4
    u32 m_magic;              // 0x8 "ipu"
    u32 m_unkC;               // 0xC
    u16 m_width;              // 0x10
    u16 m_height;             // 0x12
    u32 m_frames;             // 0x14
    u32 m_frame;              // 0x18
    void *m_buf;              // 0x1C
    u8 m_unk20[0x24];         // 0x20
    s32 m_unk44;              // 0x44
    s32 m_unk48;              // 0x48
};
extern "C" void *func_001EF420(const void *src, u32 size);
extern "C" s32 func_001EF8D8(CIpuObj *p, s32 a, s32 b, u8 c, u8 d);
extern "C" s32 func_001EFB58(CIpuObj *p);
extern "C" s32 func_00239698(s32 a, s32 b);
extern "C" s32 func_00273AD0(s32 a);
extern "C" s32 func_0027E260(void *p);

extern "C" s32 func_001F1610s() asm("func_001F1610");
struct CRxJobHead {
    void (*m_fn)(void *args);  // 0x0
    CRxMcSlot *m_slot;        // 0x4
    RxMcFn m_func;            // 0x8
};
struct CRxJob {
    CRxJobHead m_head;        // 0x0
    s32 m_a, m_b, m_c, m_d;   // 0xC
    s32 pad1C;                // 0x1C
};
extern CRxJob D_2ED448[32];
extern void *(*D_002B91AC)(void *p, u32 n);
extern "C" s32 func_002390A0();
extern "C" void func_00239088(void *p);
extern "C" void func_002375C0();
extern "C" void func_00237860(s32 qwc, const u8 *src);
extern "C" void *func_002377D8();
// @decl-end

extern "C" s32 func_001EE008(s32 a, s32 b, s32 c)
{
    func_00273420(0);
    while (func_00265D98(D_2ED220->m_port, 0, a, c, b)) func_001F1230();
    return func_001ED6E0();
}

extern "C" s32 func_001EE088()
{
    func_00273420(0);
    while (func_00265AE8(D_2ED220->m_port, 0)) func_001F1230();
    return func_001ED6E0();
}

extern "C" s32 func_001EE0D8()
{
    func_00273420(0);
    while (func_002660C8(D_2ED220->m_port, 0)) func_001F1230();
    return func_001ED6E0();
}

extern "C" void func_001EE128(CRxCrcHeader *h, s32 v)
{
    h->m_magic[0] = '!';
    h->m_magic[1] = 'c';
    h->m_magic[2] = 'r';
    h->m_magic[3] = 'c';
    h->m_value = v;
}

extern "C" s32 func_001EE150(const char *p)
{
    if (p[0] != '!') return 0;
    if (p[1] != 'c') return 0;
    if (p[2] != 'r') return 0;
    return p[3] == p[1];
}

extern "C" s32 func_001EE198(s32 a, s32 n)
{
    if (n <= 0) return a;
    return a + (a + n - 1) / n * 4 + 8;
}

extern "C" s32 func_001EE1D0(s32 a, s32 n)
{
    n += 4;
    a -= 8;
    return a - (a + n - 1) / n * 4;
}

INCLUDE_ASM("asm/nonmatchings/Unit1EE008", func_001EE200);

INCLUDE_ASM("asm/nonmatchings/Unit1EE008", func_001EE318);

INCLUDE_ASM("asm/nonmatchings/Unit1EE008", func_001EE4F8);

INCLUDE_ASM("asm/nonmatchings/Unit1EE008", func_001EE668);

INCLUDE_ASM("asm/nonmatchings/Unit1EE008", func_001EE8D8);

INCLUDE_ASM("asm/nonmatchings/Unit1EE008", func_001EE940);

extern "C" s32 func_001EEA80(RxMcFn fn, s32 a, s32 b, s32 c, s32 d)
{
    func_001ED830(0, 0);
    D_2ED200->m_busy = 1;
    return func_001EF210(func_001ED978, D_2ED200, fn, a, b, c, d);
}

extern "C" s32 func_001EEB10(s32 a)
{
    return func_001EEA80((RxMcFn)func_001EDA30, a, 0, 0, 0);
}

extern "C" s32 func_001EEB40(s32 a, s32 b, s32 c, s32 d)
{
    return func_001EEA80((RxMcFn)func_001EDB70, a, b, c, d);
}

extern "C" s32 func_001EEB78(s32 a, s32 b)
{
    return func_001EEA80((RxMcFn)func_001EDC18, a, b, 0, 0);
}

extern "C" s32 func_001EEBA8(s32 a, s32 b)
{
    return func_001EEA80((RxMcFn)func_001EDCF8, a, b, 0, 0);
}

extern "C" s32 func_001EEBD8(s32 a)
{
    return func_001EEA80((RxMcFn)func_001EDD68, a, 0, 0, 0);
}

extern "C" s32 func_001EEC08(s32 a, s32 b, s32 c)
{
    return func_001EEA80((RxMcFn)func_001EDDB0, a, b, c, 0);
}

extern "C" s32 func_001EEC38(s32 a, s32 b, s32 c)
{
    return func_001EEA80((RxMcFn)func_001EDE18, a, b, c, 0);
}

extern "C" s32 func_001EEC68(s32 a, s32 b, s32 c)
{
    return func_001EEA80((RxMcFn)func_001EDE80, a, b, c, 0);
}

extern "C" s32 func_001EEC98(s32 a, s32 b)
{
    return func_001EEA80((RxMcFn)func_001EDEE8, a, b, 0, 0);
}

extern "C" s32 func_001EECC8(s32 a, s32 b)
{
    return func_001EEA80((RxMcFn)func_001EDF78, a, b, 0, 0);
}

extern "C" s32 func_001EECF8(s32 a, s32 b, s32 c)
{
    return func_001EEA80((RxMcFn)func_001EE008, a, b, c, 0);
}

extern "C" s32 func_001EED28()
{
    return func_001EEA80((RxMcFn)func_001EE088, 0, 0, 0, 0);
}

extern "C" s32 func_001EED58()
{
    return func_001EEA80((RxMcFn)func_001EE0D8, 0, 0, 0, 0);
}

extern "C" s32 func_001EED88(s32 a, s32 b)
{
    return func_001EEA80((RxMcFn)func_001EE200, a, b, 0, 0);
}

extern "C" s32 func_001EEDB8(s32 a)
{
    return func_001EEA80((RxMcFn)func_001EDC90, a, 0, 0, 0);
}

extern "C" s32 func_001EEDE8(s32 a, s32 b, s32 c)
{
    return func_001EEA80((RxMcFn)func_001EE318, a, b, c, 0);
}

extern "C" s32 func_001EEE18(s32 a, s32 b, s32 c, s32 d)
{
    return func_001EEA80((RxMcFn)func_001EE4F8, a, b, c, d);
}

extern "C" s32 func_001EEE50(s32 a, s32 b)
{
    return func_001EEA80((RxMcFn)func_001EE668, a, b, 0, 0);
}

extern "C" s32 func_001EEE80(s32 a)
{
    return func_001EEA80((RxMcFn)func_001EE8D8, a, 0, 0, 0);
}

extern "C" s32 func_001EEEB0(s32 a)
{
    return func_001EEA80((RxMcFn)func_001EE940, a, 0, 0, 0);
}

extern "C" u32 func_001EEEE0(const void *data, s32 n)
{
    const u8 *p = (const u8 *)data;
    s32 *f = &D_002A5C90;
    if (*f == 0) {
        *f = 1;
        RxCrcInit();
    }
    u32 crc = 0xFFFF;
    while (--n >= 0) crc = (crc << 8) ^ D_2ED228[(*p++ ^ (crc >> 8)) & 0xFF];
    return ~crc;
}

INCLUDE_ASM("asm/nonmatchings/Unit1EE008", func_001EEFA8);

extern "C" s32 func_001EF0D8()
{
    D_002A5C9C = 0;
    D_002A5C94 = 0;
    D_002A5C98 = 0;
    D_2ED440 = func_001F18F0(func_001EEFA8, D_2ED880, 0x10000, 2, 0);
    return func_001F18D0(D_2ED440, 1);
}

extern "C" void func_001EF140()
{
    D_002A5C9C = 1;
    func_001F15F0();
    func_001F18D0(D_2ED440, 1);
    func_001F1610();
    while (D_002A5C9C > 0) {
        if (!(EeGetStatus() & 0x10000)) {
            func_0027BD78();
            Func235DE0(D_002E21C0);
            func_0027BD78();
        }
    }
    func_001F1748(D_2ED440);
    D_2ED440 = -1;
}

INCLUDE_ASM("asm/nonmatchings/Unit1EE008", func_001EF210);

extern "C" void func_001EF378()
{
    CRxSemaParam p;
    p.m_maxCount = 1;
    p.m_initCount = 1;
    for (s32 i = 0; i < 2; i++) D_2FD898[i] = func_002731A0(&p);
}

extern "C" void func_001EF3D0()
{
    for (s32 i = 0; i < 2; i++) func_002731B0(D_2FD898[i]);
}

extern "C" s32 func_001EF418() { return 1; }

extern "C" void *func_001EF420(const void *data, u32 size)
{
    const u8 *src = (const u8 *)data;
    s32 n = (size + 15) & ~15;
    s32 old = func_002390A0();
    void *buf = D_002B91A4(0);
    if (buf == 0) return 0;
    n -= 16;
    func_00239088(buf);
    src += 16;
    func_002375C0();
    while (n > 0) {
        s32 c = n > 0xFFF80 ? 0xFFF80 : n;
        n -= c;
        func_00237860(c / 16, src);
        src += c;
    }
    void *r = func_002377D8();
    s32 end = func_002390A0();
    D_002B91AC(buf, end - (s32)buf);
    func_00239088((void *)old);
    return r;
}

extern "C" s32 func_001EF520()
{
    if (D_2FD894) {
        D_2FD884 -= D_2FD888;
        if (D_2FD884 > 0) {
            D_2FD880 += D_2FD888;
            D_2FD888 = D_2FD884 > 0xFFF80 ? 0xFFF80 : D_2FD884;
            *(volatile u32 *)0x1000B010 = D_2FD880;
            *(volatile u32 *)0x1000B020 = D_2FD888 / 16;
            *(volatile u32 *)0x1000B000 = 0x100;
        }
    }
    __asm__ volatile("sync\n\tei");
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/Unit1EE008", func_001EF5C8);

extern "C" void func_001EF638()
{
    *(volatile u32 *)0x1000B000 = 0;
    *(volatile u32 *)0x1000B400 = 0;
    *(volatile u32 *)0x10002010 = 0x40000000;
    func_0027E498(0, 0);
    func_00272ED0(3, D_2FD88C);
    return func_001EF3D0();
}

extern "C" void func_001EF690(s32 i)
{
    while (func_002731F0(D_2FD898[i]) == -1) {
        func_001F1A80(func_001EF418, 0, 0, 0);
        func_001F1230();
    }
}

extern "C" s32 func_001EF700(s32 i) { return func_002731C0(D_2FD898[i]); }

INCLUDE_ASM("asm/nonmatchings/Unit1EE008", func_001EF728);

extern "C" void func_001EF810(CIpuObj *p)
{
    if (p == 0) return;
    if (p->m_buf) D_002B91B0(p->m_buf);
    D_002B91B0(p);
}

extern "C" void *func_001EF878(CIpuObj *p)
{
    if (p == 0) return 0;
    return &p->m_magic;
}

extern "C" s32 func_001EF890(CIpuObj *p, s32 mode)
{
    if (p == 0) return -1;
    s32 bpp;
    if (mode == 0) bpp = 4;
    else if (mode == 2) bpp = 2;
    else return -1;
    return p->m_width * p->m_height * bpp;
}

extern "C" void func_001EF8C8(CIpuObj *p)
{
    if (p) p->m_frame = 0;
}

INCLUDE_ASM("asm/nonmatchings/Unit1EE008", func_001EF8D8);

extern "C" s32 func_001EFB58(CIpuObj *p)
{
    func_0027E498(0, 0);
    func_00239698(3, 0);
    *(volatile u32 *)0x10002000 = 0x40000020;
    func_0027E498(0, 0);
    func_00273AD0(3);
    D_2FD894 = 0;
    func_0027E260(p->m_unk20);
    func_0027E498(0, 0);
    u32 frame = p->m_frame;
    p->m_unk44 = D_2FD880;
    p->m_unk48 = D_2FD884;
    if (++p->m_frame >= p->m_frames) p->m_frame = 0;
    func_001EF700(0);
    return frame;
}

extern "C" s32 func_001EFC20(CIpuObj *p, s32 a, s32 b, u8 c, u8 d)
{
    s32 r = func_001EF8D8(p, a, b, c, d);
    if (r == 0) r = func_001EFB58(p);
    return r;
}

extern "C" s32 func_001EFC60(s32 mode)
{
    if (mode == 0) return 4;
    return mode == 2 ? 2 : 0;
}

INCLUDE_ASM("asm/nonmatchings/Unit1EE008", func_001EFC80);

INCLUDE_ASM("asm/nonmatchings/Unit1EE008", func_001EFF48);

INCLUDE_ASM("asm/nonmatchings/Unit1EE008", func_001F0210);
