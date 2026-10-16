#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" void func_0026AA48(s32);
extern "C" s32 func_0026C008(u8 *, s32);
extern s32 D_002BD940[];

extern "C" s32 func_0026C4A8(u8 *, s32);
extern "C" void func_0026C398(u8 *, u32);
extern "C" void func_0026CC00(u8 *);

extern "C" void func_0026BD18(u8 *);
extern "C" u32 func_0026C278(u8 *, s32);

extern "C" void func_0026C8E8(u8 *);

extern "C" void func_0026CC48(u8 *, s32);

extern "C" void func_0026BCE8(u8 *, u32);
extern "C" s32 func_002683A0(u8 *, const char *);
extern const char D_002E98D0[];
extern const char D_002E98F8[];

extern "C" u64 func_0026BE80(u8 *);
extern "C" s32 func_00267B10(void *);
extern "C" void func_00268518(u8 *);
extern "C" void func_0026CCC0(u8 *);
extern "C" void func_0026C820(u8 *);
extern "C" void func_0026C618(u8 *);
extern "C" s32 func_00267A98(void *, void *);
#define IPU_CTRL (*(volatile u32 *)0x10002010)
#define IPU_CMD (*(volatile u32 *)0x10002000)

extern "C" s32 func_0026B208(u8 *, s32);
extern "C" s32 func_0026AA70(u8 *);
extern "C" void func_00269A78(u8 *, s32);
extern const char D_002E97C8[];

extern "C" s32 func_00268368(u8 *, const char *, ...);
extern "C" s32 func_0026C698(u8 *);
extern "C" s32 func_0026AEB0(u8 *);
extern const char D_002E97E8[];
extern const char D_002E9810[];

#define REG(a) (*(volatile u32 *)(a))
#define WREG(a) (*(u32 *)(a))
extern "C" s32 func_0027BD20(void);
extern "C" s32 func_0027BD78(void);
extern "C" void func_0026B970(s32 *, s32, s32, s32, s32);
extern "C" s32 func_0026AD08(u8 *);

#define REG(a) (*(volatile u32 *)(a))
#define WREG(a) (*(u32 *)(a))
extern "C" s32 func_0027BD20(void);
extern "C" s32 func_0027BD78(void);
extern "C" void func_0026B970(s32 *, s32, s32, s32, s32);
extern "C" s32 func_0026AD08(u8 *);

extern const char D_002E9770[];

extern "C" void func_0026BB98(u8 *, s32 *, s32 *, s32, s32, s32, s32, s32);

extern const char D_002E9850[];

extern const char D_002E9790[];
// @decl-end

INCLUDE_ASM("asm/nonmatchings/Dk26A870", func_0026A870);

INCLUDE_ASM("asm/nonmatchings/Dk26A870", func_0026A988);

INCLUDE_ASM("asm/nonmatchings/Dk26A870", func_0026A9E8);

extern "C" void func_0026AA48(s32 a) { u32 *r = (u32 *)0x10002010; *r = (*r & 0xFF7FFFFF) | (a << 23); }

extern "C" s32 func_0026AA70(u8 *d) {
    struct { s32 m0; s32 pad[7]; } cb, cb2;
    s32 ok = 1;
    s64 top; u32 bp;
    func_0026BD18(d);
    while (REG(0x1000B020) && !(IPU_CTRL & 0x4000)) {
        {
            if (!REG(0x1000B420) && !(REG(0x1000B400) & 0x100)) { cb.m0 = 1; func_00267A98(*(void **)(d + 0x870), &cb); }
            if (*(s32 *)(d + 0x10A0)) {
                s32 r = func_0027BD20();
                REG(0x1000F590) = REG(0x1000F520) | 0x10000;
                REG(0x1000B400) = 0; REG(0x1000B000) = 0;
                REG(0x1000F590) = REG(0x1000F520) & ~0x10000;
                if (r) func_0027BD78();
                REG(0x1000B020) = 0; REG(0x1000B420) = 0;
                IPU_CTRL = 0x40000000;
                return 0;
            }
        }
    }
    bp = REG(0x10002020);
    top = *(s64 *)0x10002030;
    *(s32 *)(d + 0x850) = (s32)top;
    { s32 k; if (top < 0) { u32 n = bp & 0x1F; if (n) k = 32 - n; else k = 0; } else k = 32; *(s32 *)(d + 0x854) = k; }
    if (IPU_CTRL & 0x4000) {
        s32 r;
        func_002683A0(d, D_002E9770);
        cb2.m0 = 2; func_00267A98(*(void **)(d + 0x870), &cb2);
        *(u32 *)0x10002010 = 0x40000000;
        cb2.m0 = 3; func_00267A98(*(void **)(d + 0x870), &cb2);
        r = func_0027BD20();
        REG(0x1000F590) = REG(0x1000F520) | 0x10000;
        REG(0x1000B000) = 0;
        REG(0x1000F590) = REG(0x1000F520) & ~0x10000;
        if (r) func_0027BD78();
        ok = 0;
        REG(0x1000B020) = 0;
    }
    return ok;
}

extern "C" s32 func_0026AD08(u8 *d) { return func_0026C008(d, 3); }

INCLUDE_ASM("asm/nonmatchings/Dk26A870", func_0026AD28);

extern "C" s32 func_0026AEB0(u8 *d) {
    s32 val = 0, cont; u32 code;
    do {
        code = func_0026C008(d, 0);
        switch (code) {
        case 0x22: cont = 1; break;
        case 0x23: cont = 1; val += 0x21; break;
        case 0: {
            s32 v = func_0026C278(d, 0xB);
            if (*(s32 *)(d + 0x860) && v == 0xF) { func_0026C398(d, 0xB); cont = 1; break; }
            func_00268368(d, D_002E9790, code); *(s32 *)(d + 0x134) = 1; return 1;
        }
        default: val += code; cont = 0; break;
        }
    } while (cont);
    return val;
}

extern "C" s32 func_0026AFC0(u8 *d) {
    s32 n, r;
    *(s32 *)(d + 0x828) = 0; *(s32 *)(d + 0x82C) = 0;
    n = *(s32 *)(d + 0x144) * *(s32 *)(d + 0x148);
    if (*(s32 *)(d + 0x18C) != 3) n >>= 1;
    while ((r = func_0026B208(d, n)) == 1 || r == 3);
    func_0026BD18(d);
    if (!func_0026AA70(d)) { if (*(s32 *)(d + 0x10A0)) return 4; r = 2; }
    while ((*(volatile u32 *)0x1000D400 >> 8) & 1);
    if (r == 0) func_00269A78(d, *(s32 *)(d + 0x828) == 0);
    if (r == 1 || r == 2) func_002683A0(d, D_002E97C8);
    return r == 0;
}

extern "C" s32 func_0026B0D8(u8 *d, s32 unused, s32 *pos, s32 *inc, s32 *dc) {
    u32 code; s32 q, n;
    *(s32 *)(d + 0x134) = 0;
    func_0026C618(d);
    code = func_0026C278(d, 32);
    if (code - 0x101 >= 0xAF) { func_00268368(d, D_002E97E8, code); return 2; }
    func_0026C398(d, 32);
    q = func_0026C698(d);
    n = func_0026AEB0(d); *inc = n;
    if (*(s32 *)(d + 0x134)) { func_002683A0(d, D_002E9810); return 1; }
    *pos = ((q << 7) + (code & 0xFF) - 1) * *(s32 *)(d + 0x144) + n - 1;
    *inc = 1; *(s32 *)(d + 0x1C8) = 1;
    dc[0] = dc[1] = dc[4] = dc[5] = 0; dc[2] = dc[3] = dc[6] = dc[7] = 0;
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/Dk26A870", func_0026B208);

extern "C" s32 func_0026B408(u8 *d, s32 PMV[2][2][2], s32 *motion_type, s32 mvfs[2][2], s32 *macroblock_type) {
    s32 r = 1;
    *(s32 *)(d + *(s32 *)(d + 0x828) * 0x140 + 0x6E4) = 1;
    *(s32 *)(d + 0x1C8) = 1;
    if (*(s32 *)(d + 0x168) == 2) PMV[0][0][0] = PMV[0][0][1] = PMV[1][0][0] = PMV[1][0][1] = 0;
    if (*(s32 *)(d + 0x18C) == 3) *motion_type = 2;
    else { *motion_type = 1; mvfs[0][0] = mvfs[0][1] = *(s32 *)(d + 0x18C) == 2; }
    if (*(s32 *)(d + 0x168) == 1) { func_002683A0(d, D_002E9850); r = 0; }
    *macroblock_type &= ~1;
    return r;
}

INCLUDE_ASM("asm/nonmatchings/Dk26A870", func_0026B4C8);

extern "C" void func_0026B970(s32 *pred, s32 r_size, s32 motion_code, s32 motion_residual, s32 full_pel_vector) {
    s32 lim, vec;
    lim = 16 << r_size;
    vec = full_pel_vector ? (*pred >> 1) : (*pred);
    if (motion_code > 0) {
        vec += ((motion_code - 1) << r_size) + motion_residual + 1;
        if (vec >= lim) vec -= lim + lim;
    } else if (motion_code < 0) {
        vec -= ((-motion_code - 1) << r_size) + motion_residual + 1;
        if (vec < -lim) vec += lim + lim;
    }
    *pred = full_pel_vector ? (vec << 1) : vec;
}

extern "C" void func_0026B9F8(u8 *d, s32 PMV[2][2][2], s32 dmvector[2], s32 mv_field_sel[2][2], s32 s, s32 motion_vector_count, s32 mv_format, s32 h_r_size, s32 v_r_size, s32 dmv, s32 mvscale) {
    if (motion_vector_count == 1) {
        if (mv_format == 0 && !dmv) mv_field_sel[1][s] = mv_field_sel[0][s] = func_0026C4A8(d, 1);
        func_0026BB98(d, PMV[0][s], dmvector, h_r_size, v_r_size, dmv, mvscale, 0);
        PMV[1][s][0] = PMV[0][s][0];
        PMV[1][s][1] = PMV[0][s][1];
    } else {
        mv_field_sel[0][s] = func_0026C4A8(d, 1);
        func_0026BB98(d, PMV[0][s], dmvector, h_r_size, v_r_size, dmv, mvscale, 0);
        mv_field_sel[1][s] = func_0026C4A8(d, 1);
        func_0026BB98(d, PMV[1][s], dmvector, h_r_size, v_r_size, dmv, mvscale, 0);
    }
}

extern "C" void func_0026BB98(u8 *d, s32 *PMV, s32 *dmvector, s32 h_r_size, s32 v_r_size, s32 dmv, s32 mvscale, s32 full_pel_vector) {
    s32 motion_code, motion_residual;
    motion_code = func_0026C008(d, 2);
    motion_residual = (h_r_size != 0 && motion_code != 0) ? func_0026C4A8(d, h_r_size) : 0;
    func_0026B970(&PMV[0], h_r_size, motion_code, motion_residual, full_pel_vector);
    if (dmv) dmvector[0] = func_0026AD08(d);
    motion_code = func_0026C008(d, 2);
    motion_residual = (v_r_size != 0 && motion_code != 0) ? func_0026C4A8(d, v_r_size) : 0;
    if (mvscale) PMV[1] >>= 1;
    func_0026B970(&PMV[1], v_r_size, motion_code, motion_residual, full_pel_vector);
    if (mvscale) PMV[1] <<= 1;
    if (dmv) dmvector[1] = func_0026AD08(d);
}

extern "C" void func_0026BCE8(u8 *p, u32 a) { *(volatile u32 *)0x10002000 = a; *(s32 *)(p + 0x830) = D_002BD940[a >> 28]; }

extern "C" void func_0026BD18(u8 *d) {
    s32 cnt = 0;
    while ((IPU_CTRL & 0x80004000) == 0x80000000) {
        if (*(s32 *)(d + 0x10A0)) {
            s32 r = func_0027BD20();
            REG(0x1000F590) = REG(0x1000F520) | 0x10000;
            REG(0x1000B400) = 0; REG(0x1000B000) = 0;
            REG(0x1000F590) = REG(0x1000F520) & ~0x10000;
            if (r) func_0027BD78();
            REG(0x1000B020) = 0; REG(0x1000B420) = 0;
            IPU_CTRL = 0x40000000;
            return;
        }
        if (cnt++ > 5000) { func_00267B10(*(void **)(d + 0x870)); cnt = 0; }
    }
}

extern "C" u64 func_0026BE80(u8 *d) {
    s32 cnt = 0;
    s64 v = *(volatile s64 *)0x10002000;
    while (v < 0 && !(IPU_CTRL & 0x4000)) {
        if (*(s32 *)(d + 0x10A0)) {
            s32 r = func_0027BD20();
            REG(0x1000F590) = REG(0x1000F520) | 0x10000;
            REG(0x1000B400) = 0; REG(0x1000B000) = 0;
            REG(0x1000F590) = REG(0x1000F520) & ~0x10000;
            if (r) func_0027BD78();
            REG(0x1000B020) = 0; REG(0x1000B420) = 0;
            IPU_CTRL = 0x40000000;
            break;
        }
        if (cnt++ > 5000) { func_00267B10(*(void **)(d + 0x870)); cnt = 0; }
        v = *(volatile s64 *)0x10002000;
    }
    return v;
}

extern "C" s32 func_0026C008(u8 *d, s32 tbl) {
    s32 cnt2 = 0, cnt = 0; u32 cmd; s64 v, top; u32 bp;
    while ((IPU_CTRL & 0x80004000) == 0x80000000 && !*(s32 *)(d + 0x10A0)) {
        if (cnt++ > 5000) { func_00267B10(*(void **)(d + 0x870)); cnt = 0; }
    }
    cmd = (tbl << 26) | 0x30000000;
    IPU_CMD = cmd;
    *(s32 *)(d + 0x830) = D_002BD940[(s32)cmd >> 28];
    v = *(volatile s64 *)0x10002000;
    while (v < 0) {
        if (*(s32 *)(d + 0x10A0)) {
            s32 r = func_0027BD20();
            REG(0x1000F590) = REG(0x1000F520) | 0x10000;
            REG(0x1000B400) = 0; REG(0x1000B000) = 0;
            REG(0x1000F590) = REG(0x1000F520) & ~0x10000;
            if (r) func_0027BD78();
            REG(0x1000B020) = 0; REG(0x1000B420) = 0;
            IPU_CTRL = 0x40000000;
            return 0;
        }
        if (cnt2++ > 5000) { func_00267B10(*(void **)(d + 0x870)); cnt2 = 0; }
        v = *(volatile s64 *)0x10002000;
    }
    bp = REG(0x10002020);
    top = *(s64 *)0x10002030;
    *(s32 *)(d + 0x850) = (s32)top;
    if (top < 0) *(s32 *)(d + 0x854) = -(bp & 0x1F) & 0x1F; else *(s32 *)(d + 0x854) = 32;
    *(s32 *)(d + 0x134) = (s32)v == 0;
    return (s16)v;
}

extern "C" u32 func_0026C278(u8 *d, s32 n) {
    if (*(s32 *)(d + 0x830) || *(s32 *)(d + 0x854) < n) {
        s32 cnt = 0;
        while ((IPU_CTRL & 0x80004000) == 0x80000000 && !*(s32 *)(d + 0x10A0)) {
            if (cnt++ > 5000) { func_00267B10(*(void **)(d + 0x870)); cnt = 0; }
        }
        IPU_CMD = 0x40000000;
        *(s32 *)(d + 0x830) = D_002BD940[4];
        *(s32 *)(d + 0x850) = (s32)func_0026BE80(d);
        *(s32 *)(d + 0x854) = 32;
    }
    return *(u32 *)(d + 0x850) >> (32 - n);
}

extern "C" void func_0026C398(u8 *d, u32 cmd) {
    s32 cnt = 0;
    while ((IPU_CTRL & 0x80004000) == 0x80000000 && !*(s32 *)(d + 0x10A0)) {
        if (cnt++ > 5000) { func_00267B10(*(void **)(d + 0x870)); cnt = 0; }
    }
    IPU_CMD = cmd | 0x40000000;
    *(s32 *)(d + 0x830) = D_002BD940[(cmd | 0x40000000) >> 28];
    *(s32 *)(d + 0x850) = (s32)func_0026BE80(d);
    *(s32 *)(d + 0x854) = 32;
}

extern "C" s32 func_0026C4A8(u8 *d, s32 n)
{
    s32 cnt = 0;
    u32 r;
    while ((IPU_CTRL & 0x80004000) == 0x80000000 && !*(s32 *)(d + 0x10A0)) {
        if (cnt++ > 5000) { func_00267B10(*(void **)(d + 0x870)); cnt = 0; }
    }
    if (*(s32 *)(d + 0x830) || *(s32 *)(d + 0x854) < n) {
        IPU_CMD = 0x40000000;
        *(s32 *)(d + 0x830) = D_002BD940[4];
        *(s32 *)(d + 0x850) = (s32)func_0026BE80(d);
    }
    r = *(u32 *)(d + 0x850) >> (32 - n);
    *(s32 *)(d + 0x854) = 32;
    IPU_CMD = n | 0x40000000;
    *(s32 *)(d + 0x830) = D_002BD940[(u32)(n | 0x40000000) >> 28];
    *(s32 *)(d + 0x850) = (s32)func_0026BE80(d);
    return r;
}

extern "C" void func_0026C618(u8 *d) {
    s32 n;
    func_0026BD18(d);
    n = -(*(volatile u32 *)0x10002020 & 7) & 7;
    if (n) func_0026C398(d, n);
    while (func_0026C278(d, 0x18) != 1 && !*(s32 *)(d + 0x10A0)) func_0026C398(d, 8);
}

extern "C" s32 func_0026C698(u8 *p) { *(s32 *)(p + 0x1CC) = func_0026C4A8(p, 5); if (func_0026C4A8(p, 1)) { func_0026C4A8(p, 1); func_0026C398(p, 7); func_0026CC00(p); } return 0; }

extern "C" s32 func_0026C700(u8 *d) {
    for (;;) {
        if (*(s32 *)(d + 0x10A0)) return -1;
        func_0026C618(d);
        switch ((u32)func_0026C4A8(d, 32)) {
        case 0x1B3: func_00268518(d); break;
        case 0x1B8: func_0026CCC0(d); break;
        case 0x100: {
            struct { s32 m0; s32 m4; s64 m8; s64 m10; } cb;
            func_0026C820(d);
            cb.m0 = 5; cb.m8 = -1; cb.m10 = -1;
            func_00267A98(*(void **)(d + 0x870), &cb);
            *(s64 *)(d + 0x840) = cb.m8; *(s64 *)(d + 0x848) = cb.m10;
            return *(s32 *)(d + 0x168);
        }
        case 0x1B7: return 0;
        }
    }
}

extern "C" void func_0026C820(u8 *d) {
    s32 t = func_0026C4A8(d, 10);
    *(s32 *)(d + 0x168) = func_0026C4A8(d, 3);
    func_0026C4A8(d, 0x10);
    if (*(s32 *)(d + 0x168) == 2 || *(s32 *)(d + 0x168) == 3) { *(s32 *)(d + 0x16C) = func_0026C4A8(d, 1); *(s32 *)(d + 0x170) = func_0026C4A8(d, 3); }
    if (*(s32 *)(d + 0x168) == 3) { *(s32 *)(d + 0x174) = func_0026C4A8(d, 1); *(s32 *)(d + 0x178) = func_0026C4A8(d, 3); }
    func_0026CC00(d); func_0026C8E8(d); func_0026CC48(d, t);
}

INCLUDE_ASM("asm/nonmatchings/Dk26A870", func_0026C8E8);

INCLUDE_ASM("asm/nonmatchings/Dk26A870", func_0026CA10);

extern "C" void func_0026CC00(u8 *p) { while (func_0026C4A8(p, 1)) func_0026C398(p, 8); }

extern "C" void func_0026CC48(u8 *d, s32 tr) {
    s32 wrap = 0, ref = 0;
    if (*(s32 *)(d + 0x168) != 3 && tr != 0) {
        if (tr < 0) wrap = *(s32 *)(d + 0x86C) == 0;
        *(s32 *)(d + 0x86C) = 0;
        ref = tr;
    }
    *(s32 *)(d + 0x1C4) = *(s32 *)(d + 0x864) + tr;
    if (wrap && !(ref < tr)) *(s32 *)(d + 0x1C4) += 0x400;
    *(s32 *)(d + 0x868) = *(s32 *)(d + 0x868) < *(s32 *)(d + 0x1C4) ? *(s32 *)(d + 0x1C4) : *(s32 *)(d + 0x868);
}

extern "C" void func_0026CCC0(u8 *d) {
    *(s32 *)(d + 0x100) = 0;
    *(s32 *)(d + 0x864) = *(s32 *)(d + 0x868) + 1;
    *(s32 *)(d + 0x86C) = 1;
    func_0026C4A8(d, 1); func_0026C4A8(d, 5); func_0026C4A8(d, 6); func_0026C4A8(d, 1); func_0026C4A8(d, 6); func_0026C4A8(d, 6);
    *(s32 *)(d + 0x1BC) = func_0026C4A8(d, 1);
    *(s32 *)(d + 0x1C0) = func_0026C4A8(d, 1);
    func_0026C8E8(d);
}

extern "C" void func_0026CD60(u8 *d) {
    s32 v;
    v = func_0026C4A8(d, 1); *(s32 *)(d + 0x858) = v;
    if (v) { func_0026BD18(d); func_0026BCE8(d, 0x50000000); func_0026BD18(d); }
    v = func_0026C4A8(d, 1); *(s32 *)(d + 0x85C) = v;
    if (v) { func_0026BD18(d); func_0026BCE8(d, 0x58000000); func_0026BD18(d); }
    if (func_0026C4A8(d, 1)) func_002683A0(d, D_002E98D0);
    if (func_0026C4A8(d, 1)) func_002683A0(d, D_002E98F8);
}

INCLUDE_ASM("asm/nonmatchings/Dk26A870", func_0026CE28);

extern "C" void func_0026CF20(u8 *d) {
    func_0026C4A8(d, 1); func_0026C4A8(d, 8); func_0026C4A8(d, 1); func_0026C4A8(d, 7); func_0026C4A8(d, 1);
    func_0026C4A8(d, 0x14); func_0026C4A8(d, 1); func_0026C4A8(d, 0x16); func_0026C4A8(d, 1); func_0026C4A8(d, 0x16);
}
