#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CMapAttr {
public:
    void Func1182B8();
    void CallFunc1182B8();
    s32 Load119230(const char *src);
    s32 Save118448(char *out);

    s32 m_flags;              // 0x0
    u8 pad4[0xC];
    f32 m10, m14, m18;        // 0x10
    u8 pad1C[0x4];
    f32 m20, m24, m28;        // 0x20
    u8 pad2C[0x4];
    f32 m30, m34;             // 0x30
    u8 pad38[0x8];
    f32 m40;                  // 0x40
    u8 pad44[0xC];
    s32 m50[3];               // 0x50
    u8 pad5C[0x4];
    f32 m60[3][4];            // 0x60
    f32 m90[3][4];            // 0x90
    f32 mC0[4];               // 0xC0
    u8 mD0[0x18];             // 0xD0 (array object)
    s32 mE8;                  // 0xE8
    u8 padEC[0x4];
    f32 mF0, mF4;             // 0xF0
    u8 padF8[0x8];
    s32 m100[4];              // 0x100
    s32 m110[3];              // 0x110
    u8 pad11C[0x4];
    s32 m120[3];              // 0x120
    u8 pad12C[0x4];
    s32 m130[4];              // 0x130
    s32 m140[4];              // 0x140
    s32 m150;                 // 0x150
};

struct CVec4 {
    f32 x, y, z, w;
};
extern char D_002D3AB0[], D_002D3AB8[], D_002D3AC0[], D_002D3AC8[];
const char *Func24A570(const char *src, char *buf, const char *a, const char *b);
extern "C" char *func_0024A778(char *p, f32 *v, f32 def, const char *s1, const char *s2);

struct CMapAttrLight {
    char m_name[0x10];        // 0x0
    f32 m10, m14, m18, m1C;   // 0x10
    f32 m20, m24;             // 0x20
    u8 m28[0x18];             // 0x28 (array object)
    f32 m40;                  // 0x40
    s32 m44;                  // 0x44
    u8 pad48[0x8];
    f32 m50, m54, m58, m5C;   // 0x50
    s32 m60;                  // 0x60
    u8 pad64[0xC];
    f32 m70, m74, m78, m7C;   // 0x70
    f32 m80;                  // 0x80
    s32 m84;                  // 0x84
    u8 pad88[0x8];
    f32 m90, m94, m98, m9C;   // 0x90
    s32 mA0;                  // 0xA0
    u8 padA4[0xC];
    f32 mB0, mB4, mB8, mBC;   // 0xB0
};
extern const char *D_002A05EC, *D_002A05F0, *D_002A05F4, *D_002A05F8, *D_002A05FC, *D_002A0600;
extern const char *D_002A0604, *D_002A0608, *D_002A060C, *D_002A0610, *D_002A0614;
extern char D_002D3AD0[];
s32 Func118CE0(CVec4 *out, const char *src);
const char *Func24AF10(void *src, const char *key);
extern "C" char *func_0024B298(const char *src, const char *key, char *dst, s32 a);
extern "C" s32 func_0024B190(const char *src, const char *key, char *buf, const char *fmt, s32 n);
extern "C" void func_0024B300(const char *src, const char *key, f32 *dst, f32 def);
extern "C" void func_002943E8(void *arr, s32 n);
extern "C" CVec4 *func_00294408(void *arr, s32 i);

extern char D_002D38C8[], D_002D38D0[], D_002D38D8[], D_002D38E0[], D_002D38E8[], D_002D38F0[];
extern char D_002D3930[], D_002D3838[], D_002D3938[], D_002D3958[], D_002D3970[], D_002D3980[];
extern char D_002D39A0[], D_002D39B0[], D_002D39D0[], D_002D39F8[], D_002D3A00[], D_002D3A10[], D_002D3A20[];
extern const char *D_002A0618, *D_002A061C;
s32 Func118E10(CMapAttrLight *out, const char *src);
extern "C" f32 func_0024B3B8(const char *src, const char *key, f32 def);
extern "C" s32 func_0024B368(const char *src, const char *key, s32 def);
extern "C" char *func_0024A710(char *p, s32 *v, s32 def, const char *s1, const char *s2);
extern "C" void func_00294388(void *arr, s32 n);
extern "C" CMapAttrLight *func_00294420(void *arr, s32 i);
extern "C" int sprintf(char *buf, const char *fmt, ...);

extern char D_002D3890[], D_002D3900[], D_002D3940[], D_002D3960[], D_002D3988[], D_002D39B8[], D_002D39E0[];
extern char D_002D3A30[], D_002D3A58[], D_002D3A68[], D_002D3A80[], D_002D3A88[], D_002D3AA0[], D_002D3AA8[];
extern "C" s32 func_0024B818(char **pp, const char *fmt, ...);
extern "C" s32 func_002943A8(void *arr);
extern "C" CMapAttrLight *func_002943B0(void *arr, s32 i);
extern "C" s32 func_002943C8(void *arr);
extern "C" CVec4 *func_002943D0(void *arr, s32 i);
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CMapAttr", func_00118210);

INCLUDE_ASM("asm/nonmatchings/CMapAttr", func_00118248);

INCLUDE_ASM("asm/nonmatchings/CMapAttr", Func1182B8__8CMapAttr);

s32 CMapAttr::Save118448(char *out) {
    char key[0x100];
    s32 n;
    s32 i;
    n = func_0024B818(&out, D_002D3890, D_002D38C8, D_002D38D0, m10, m14, m18, D_002D38D8, m20, m24, m28,
                      D_002D38E0, m30, m34, D_002D38E8, m40);
    for (i = 0; i < 3; i++) {
        if (!((m_flags >> i) & 1)) continue;
        sprintf(key, D_002D38F0, i);
        n += func_0024B818(&out, D_002D3900, key, D_002D3930, m50[i], D_002D3838, m60[i][0], m60[i][1],
                           m60[i][2], m60[i][3], D_002D3938, m90[i][0], m90[i][1], m90[i][2], m90[i][3]);
    }
    if (m_flags & 0x10) {
        n += func_0024B818(&out, D_002D3940, D_002D3958, D_002D3938, mC0[0], mC0[1], mC0[2], mC0[3]);
    }
    if (m_flags & 0x20) {
        n += func_0024B818(&out, D_002D3960, D_002D3970, D_002D3980, mE8);
    }
    if (m_flags & 0x40) {
        n += func_0024B818(&out, D_002D3988, D_002D39A0, D_002D39B0, mF0, mF4);
    }
    if (m_flags & 0x80) {
        n += func_0024B818(&out, D_002D39B8, D_002D39D0, D_002D3938, m100[0], m100[1], m100[2], m100[3]);
    }
    if (m_flags & 0x100) {
        n += func_0024B818(&out, D_002D39E0, D_002D39F8, D_002D3938, m110[0], m110[1], m110[2]);
    }
    if (m_flags & 0x200) {
        n += func_0024B818(&out, D_002D39E0, D_002D3A00, D_002D3938, m120[0], m120[1], m120[2]);
    }
    if (m_flags & 0x400) {
        n += func_0024B818(&out, D_002D39B8, D_002D3A10, D_002D3938, m130[0], m130[1], m130[2], m130[3]);
    }
    if (m_flags & 0x800) {
        n += func_0024B818(&out, D_002D39B8, D_002D3A20, D_002D3938, m140[0], m140[1], m140[2], m140[3]);
    }
    for (i = 0; i < func_002943A8(mD0); i++) {
        CMapAttrLight *e = func_002943B0(mD0, i);
        n += func_0024B818(&out, D_002D3A30, D_002A05EC, D_002A05F0, *(char **)e->m_name, D_002A05F4,
                           e->m10, e->m14, e->m18, D_002A05F8, e->m20, e->m24);
        if (e->m44) {
            n += func_0024B818(&out, D_002D3A58, D_002A0604, e->m50, e->m54, e->m58);
        }
        if (e->m60) {
            n += func_0024B818(&out, D_002D3A68, D_002A0608, e->m70, e->m74, e->m78, e->m7C, D_002A060C, e->m80);
        }
        if (e->m84) {
            n += func_0024B818(&out, D_002D3A58, D_002A0610, e->m90, e->m94, e->m98);
        }
        if (e->mA0) {
            n += func_0024B818(&out, D_002D3A58, D_002A0614, e->mB0, e->mB4, e->mB8);
        }
        if (func_002943C8(e->m28) > 0) {
            s32 j;
            n += func_0024B818(&out, D_002D3A80, D_002A05FC);
            for (j = 0; j < func_002943C8(e->m28); j++) {
                CVec4 *v = func_002943D0(e->m28, j);
                n += func_0024B818(&out, D_002D3A88, v->x, v->y, v->z);
            }
            n += func_0024B818(&out, D_002D3AA0);
            n += func_0024B818(&out, D_002D3AA8, D_002A0600, e->m40);
        }
        n += func_0024B818(&out, D_002D3AA0);
    }
    return n + func_0024B818(&out, D_002D3960, D_002A0618, D_002A061C, m150);
}

s32 Func118CE0(CVec4 *out, const char *src) {
    char buf[0x100];
    s32 n = 0;
    while ((src = Func24A570(src, buf, D_002D3AB0, D_002D3AB8), *src) || buf[0]) {
        if (out) {
            char *p;
            p = func_0024A778(buf, &out[n].x, 0.0f, D_002D3AC0, D_002D3AC8);
            p = func_0024A778(p, &out[n].y, 0.0f, D_002D3AC0, D_002D3AC8);
            p = func_0024A778(p, &out[n].z, 0.0f, D_002D3AC0, D_002D3AC8);
            p = func_0024A778(p, &out[n].w, 1.0f, D_002D3AC0, D_002D3AC8);
        }
        n++;
    }
    return n;
}

s32 Func118E10(CMapAttrLight *out, const char *src) {
    char buf[0x400];
    s32 n = 0;
    while (*(src = Func24AF10((void *)src, D_002A05EC))) {
        if (out) {
            CMapAttrLight *e = &out[n];
            char *p;
            func_0024B298(src, D_002A05F0, e->m_name, 0);
            func_0024B190(src, D_002A05F4, buf, D_002D3AD0, 0x100);
            p = func_0024A778(buf, &e->m10, 0.0f, D_002D3AC0, D_002D3AC8);
            p = func_0024A778(p, &e->m14, 0.0f, D_002D3AC0, D_002D3AC8);
            p = func_0024A778(p, &e->m18, 0.0f, D_002D3AC0, D_002D3AC8);
            e->m1C = 0.0f;
            func_0024B190(src, D_002A05F8, buf, D_002D3AD0, 0x100);
            p = func_0024A778(buf, &e->m20, 0.0f, D_002D3AC0, D_002D3AC8);
            p = func_0024A778(p, &e->m24, 0.0f, D_002D3AC0, D_002D3AC8);
            if (func_0024B190(src, D_002A0604, buf, D_002D3AD0, 0x100)) {
                e->m44 = 1;
                p = func_0024A778(buf, &e->m50, 1.0f, D_002D3AC0, D_002D3AC8);
                p = func_0024A778(p, &e->m54, 1.0f, D_002D3AC0, D_002D3AC8);
                p = func_0024A778(p, &e->m58, 1.0f, D_002D3AC0, D_002D3AC8);
                e->m5C = 0.0f;
            }
            if (func_0024B190(src, D_002A0608, buf, D_002D3AD0, 0x100)) {
                e->m60 = 1;
                p = func_0024A778(buf, &e->m70, 1.0f, D_002D3AC0, D_002D3AC8);
                p = func_0024A778(p, &e->m74, 1.0f, D_002D3AC0, D_002D3AC8);
                p = func_0024A778(p, &e->m78, 1.0f, D_002D3AC0, D_002D3AC8);
                p = func_0024A778(p, &e->m7C, 1.0f, D_002D3AC0, D_002D3AC8);
                func_0024B300(src, D_002A060C, &e->m80, 0.0f);
            }
            if (func_0024B190(src, D_002A0610, buf, D_002D3AD0, 0x100)) {
                e->m84 = 1;
                p = func_0024A778(buf, &e->m90, 1.0f, D_002D3AC0, D_002D3AC8);
                p = func_0024A778(p, &e->m94, 1.0f, D_002D3AC0, D_002D3AC8);
                p = func_0024A778(p, &e->m98, 1.0f, D_002D3AC0, D_002D3AC8);
                e->m9C = 1.0f;
            }
            if (func_0024B190(src, D_002A0614, buf, D_002D3AD0, 0x100)) {
                e->mA0 = 1;
                p = func_0024A778(buf, &e->mB0, 1.0f, D_002D3AC0, D_002D3AC8);
                p = func_0024A778(p, &e->mB4, 1.0f, D_002D3AC0, D_002D3AC8);
                p = func_0024A778(p, &e->mB8, 1.0f, D_002D3AC0, D_002D3AC8);
                e->mBC = 1.0f;
            }
            if (func_0024B190(src, D_002A05FC, buf, D_002D3AD0, 0x400)) {
                func_002943E8(e->m28, Func118CE0(0, buf));
                Func118CE0(func_00294408(e->m28, 0), buf);
                func_0024B300(src, D_002A0600, &e->m40, 0.0f);
            }
        }
        n++;
    }
    return n;
}

s32 CMapAttr::Load119230(const char *src) {
    char buf[0x100];
    char key[0x100];
    const char *p;
    char *q;
    s32 i;
    CallFunc1182B8();
    m_flags = 0;
    p = Func24AF10((void *)src, D_002D38C8);
    if (*p) {
        func_0024B190(p, D_002D38D0, buf, D_002D3AD0, 0x100);
        q = func_0024A778(buf, &m10, 0.0f, D_002D3AC0, D_002D3AC8);
        q = func_0024A778(q, &m14, 0.0f, D_002D3AC0, D_002D3AC8);
        q = func_0024A778(q, &m18, 0.0f, D_002D3AC0, D_002D3AC8);
        func_0024B190(p, D_002D38D8, buf, D_002D3AD0, 0x100);
        q = func_0024A778(buf, &m20, 0.0f, D_002D3AC0, D_002D3AC8);
        q = func_0024A778(q, &m24, 0.0f, D_002D3AC0, D_002D3AC8);
        q = func_0024A778(q, &m28, 0.0f, D_002D3AC0, D_002D3AC8);
        func_0024B190(p, D_002D38E0, buf, D_002D3AD0, 0x100);
        q = func_0024A778(buf, &m30, 0.0f, D_002D3AC0, D_002D3AC8);
        q = func_0024A778(q, &m34, 0.0f, D_002D3AC0, D_002D3AC8);
        m40 = func_0024B3B8(p, D_002D38E8, 40.0f);
    }
    for (i = 0; i < 3; i++) {
        sprintf(key, D_002D38F0, i);
        p = Func24AF10((void *)src, key);
        if (*p) {
            m50[i] = func_0024B368(p, D_002D3930, 0);
            func_0024B190(p, D_002D3838, buf, D_002D3AD0, 0x100);
            q = func_0024A778(buf, &m60[i][0], 0.0f, D_002D3AC0, D_002D3AC8);
            q = func_0024A778(q, &m60[i][1], 0.0f, D_002D3AC0, D_002D3AC8);
            q = func_0024A778(q, &m60[i][2], 0.0f, D_002D3AC0, D_002D3AC8);
            q = func_0024A778(q, &m60[i][3], 0.0f, D_002D3AC0, D_002D3AC8);
            func_0024B190(p, D_002D3938, buf, D_002D3AD0, 0x100);
            q = func_0024A778(buf, &m90[i][0], 0.0f, D_002D3AC0, D_002D3AC8);
            q = func_0024A778(q, &m90[i][1], m90[i][0], D_002D3AC0, D_002D3AC8);
            q = func_0024A778(q, &m90[i][2], m90[i][0], D_002D3AC0, D_002D3AC8);
            q = func_0024A778(q, &m90[i][3], 0.0f, D_002D3AC0, D_002D3AC8);
            m_flags |= 1 << i;
        }
    }
    p = Func24AF10((void *)src, D_002D3958);
    if (*p) {
        func_0024B190(p, D_002D3938, buf, D_002D3AD0, 0x100);
        q = func_0024A778(buf, &mC0[0], 0.0f, D_002D3AC0, D_002D3AC8);
        q = func_0024A778(q, &mC0[1], mC0[0], D_002D3AC0, D_002D3AC8);
        q = func_0024A778(q, &mC0[2], mC0[0], D_002D3AC0, D_002D3AC8);
        q = func_0024A778(q, &mC0[3], 1.0f, D_002D3AC0, D_002D3AC8);
        m_flags |= 0x10;
    }
    p = Func24AF10((void *)src, D_002D3970);
    if (*p) {
        mE8 = func_0024B368(p, D_002D3980, 0);
        m_flags |= 0x20;
    }
    p = Func24AF10((void *)src, D_002D39A0);
    if (*p) {
        func_0024B190(p, D_002D39B0, buf, D_002D3AD0, 0x100);
        q = func_0024A778(buf, &mF0, 0.0f, D_002D3AC0, D_002D3AC8);
        q = func_0024A778(q, &mF4, 0.0f, D_002D3AC0, D_002D3AC8);
        m_flags |= 0x40;
    }
    p = Func24AF10((void *)src, D_002D39D0);
    if (*p) {
        func_0024B190(p, D_002D3938, buf, D_002D3AD0, 0x100);
        q = func_0024A710(buf, &m100[0], 0, D_002D3AC0, D_002D3AC8);
        q = func_0024A710(q, &m100[1], 0, D_002D3AC0, D_002D3AC8);
        q = func_0024A710(q, &m100[2], 0, D_002D3AC0, D_002D3AC8);
        q = func_0024A710(q, &m100[3], 0, D_002D3AC0, D_002D3AC8);
        m_flags |= 0x80;
    }
    p = Func24AF10((void *)src, D_002D39F8);
    if (*p) {
        func_0024B190(p, D_002D3938, buf, D_002D3AD0, 0x100);
        q = func_0024A710(buf, &m110[0], 0, D_002D3AC0, D_002D3AC8);
        q = func_0024A710(q, &m110[1], 0, D_002D3AC0, D_002D3AC8);
        q = func_0024A710(q, &m110[2], 0, D_002D3AC0, D_002D3AC8);
        m_flags |= 0x100;
    }
    p = Func24AF10((void *)src, D_002D3A00);
    if (*p) {
        func_0024B190(p, D_002D3938, buf, D_002D3AD0, 0x100);
        q = func_0024A710(buf, &m120[0], 0, D_002D3AC0, D_002D3AC8);
        q = func_0024A710(q, &m120[1], 0, D_002D3AC0, D_002D3AC8);
        q = func_0024A710(q, &m120[2], 0, D_002D3AC0, D_002D3AC8);
        m_flags |= 0x200;
    }
    p = Func24AF10((void *)src, D_002D3A10);
    if (*p) {
        func_0024B190(p, D_002D3938, buf, D_002D3AD0, 0x100);
        q = func_0024A710(buf, &m130[0], 0, D_002D3AC0, D_002D3AC8);
        q = func_0024A710(q, &m130[1], 0, D_002D3AC0, D_002D3AC8);
        q = func_0024A710(q, &m130[2], 0, D_002D3AC0, D_002D3AC8);
        q = func_0024A710(q, &m130[3], 0, D_002D3AC0, D_002D3AC8);
        m_flags |= 0x400;
    }
    p = Func24AF10((void *)src, D_002D3A20);
    if (*p) {
        func_0024B190(p, D_002D3938, buf, D_002D3AD0, 0x100);
        q = func_0024A710(buf, &m140[0], 0, D_002D3AC0, D_002D3AC8);
        q = func_0024A710(q, &m140[1], 0, D_002D3AC0, D_002D3AC8);
        q = func_0024A710(q, &m140[2], 0, D_002D3AC0, D_002D3AC8);
        q = func_0024A710(q, &m140[3], 0, D_002D3AC0, D_002D3AC8);
        m_flags |= 0x800;
    }
    func_00294388(mD0, Func118E10(0, src));
    Func118E10(func_00294420(mD0, 0), src);
    m150 = func_0024B368(Func24AF10((void *)src, D_002A0618), D_002A061C, -1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/CMapAttr", func_00119B08);

INCLUDE_ASM("asm/nonmatchings/CMapAttr", func_00119BE0);

void CMapAttr::CallFunc1182B8() {
    Func1182B8();
}
