#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
// CSwingBoneObj.cpp: vptr at 0x30.
class CSwingBoneObj {
public:
    virtual ~CSwingBoneObj();
    void Release();

    u8 pad0[0x2C];
    f32 m_unk2C;              // 0x2C
};
// CDiffMotionObj unit (another lane's): vptr at 0x24; 0x10FC98 releases it.
class CDiffMotionObj {
public:
    virtual ~CDiffMotionObj();

    u8 pad0[0x18];
    f32 m_unk18;              // 0x18
    u8 pad1C[0x8];
};
extern "C" void func_0010FC98(CDiffMotionObj *p);
// CFaceObj.cpp: vptr at 0x50.
class CFaceObj {
public:
    virtual ~CFaceObj();
    void Release();
    void Func10DC80();
    void Func10DBD8();
    void Func10DB70();

    u8 pad0[0x18];
    s32 m_unk18;              // 0x18
    u8 pad1C[0x34];
};
class CVec4 {
public:
    f32 x, y, z, w;
};

class CCharaRes {
public:
    s32 GetCur8();
    s32 Get44(s32 v);
};

class CCharaObjSub48 {
public:
    void Func252BB8();
};

// CModelAccResMgr (its unit starts after this file); only its size is needed here.
class CModelAccResMgr {
public:
    CModelAccResMgr();

    u8 pad0[0x40];
};

void Func270C50(CVec4 *dst, const CVec4 *src);
void Func24B600(char *dst, const char *src, s32 n);
f32 Func1EAC30(s32 i);
s32 Func113368(s32 i, s32 v);
void Func117E38(void *dst, s32 *src);
CModelAccResMgr *CreateSub117F98();
extern void (*D_002B91B0)(void *p);
extern "C" int func_001ECCA8(s32 h);
extern u8 *D_002A5D0C;
extern "C" void *memcpy(void *dst, const void *src, unsigned int n);

class CCharaObj {
public:
    void Part24Func10DC80();
    void Part24Func10DBD8();
    void Part24Func10DB70();
    void SetPart1CUnk2C(f32 v);
    void SetPart20Unk18(f32 v);
    void Func114050(s32 a, s32 b);
    void CallFunc114050(s32 b);
    void SetUnk150(s32 v);
    void SetPart24Unk18(s32 v);
    s32 GetPart24Unk18();
    void SetUnk354(u32 i, s32 v);
    s32 GetUnk354(u32 i);
    s32 Func113860(s32 v);
    void Release113758();
    void ReleaseSwing();
    void ReleaseDiff();
    void Func113128();
    void Func114D70(s32 a, s32 b);
    void Func113898();
    s32 Func1138E8();
    s32 GetResIndex();
    s32 Func113F38();
    f32 Func114670();
    void Func114828(CVec4 *a, CVec4 *b);
    void Func1159A0(s32 a, s32 i);
    void Func116A40(u32 i);
    void Func116A98(s32 *src, s32 n);
    s32 Func115388();
    void Func1158C0(s32 id, const char *name, s32 a, s32 b);
    void Func1159E8(const CVec4 *v, s32 n);
    void Func115830(CVec4 *v, s32 n, s32 m);
    void Func115938(s32 a, s32 b, f32 x, f32 y);
    s32 Func117898(s32 a, s32 b);
    s32 Func117AC8(s32 a, s32 b);
    s32 Func117B48(s32 a, s32 b, s32 c);
    s32 Func117DA0(s32 a, s32 b, s32 c);
    s32 Func117F10(s32 v);
    void Func117E78();

    u8 pad0[0x14];
    CCharaRes *m_res;         // 0x14
    s32 m_unk18;              // 0x18
    CSwingBoneObj* m_part1C;  // 0x1C
    CDiffMotionObj* m_part20; // 0x20
    CFaceObj* m_part24;       // 0x24
    void *m_unk28;            // 0x28
    void *m_unk2C;            // 0x2C
    void *m_unk30;            // 0x30
    void *m_unk34;            // 0x34
    u8 pad38[0x10];
    CCharaObjSub48 m_unk48;   // 0x48
    u8 pad49[0x27];
    s32 m_unk70;              // 0x70
    s32 m_unk74;              // 0x74
    u8 pad78[0x8];
    f32 m_unk80;              // 0x80
    u8 pad84[0x2C];
    CVec4 m_unkB0;            // 0xB0
    u8 padC0[0x60];
    CVec4 m_unk120;           // 0x120
    u8 pad130[0x20];
    s32 m_unk150;             // 0x150
    u8 pad154[0x28];
    s32 m_unk17C[2];          // 0x17C
    s32 m_unk184;             // 0x184
    u8 pad188[0x100];
    s32 m_unk288;             // 0x288
    s32 m_unk28C;             // 0x28C
    u8 pad290[0x10];
    CVec4 m_unk2A0;           // 0x2A0
    CVec4 m_unk2B0;           // 0x2B0
    s32 m_unk2C0;             // 0x2C0
    s32 m_unk2C4;             // 0x2C4
    u8 pad2C8[0x8];
    s32 m_unk2D0;             // 0x2D0
    s32 m_unk2D4;             // 0x2D4
    u8 pad2D8[0x8];
    CVec4 m_unk2E0;           // 0x2E0
    CVec4 m_unk2F0;           // 0x2F0
    s32 m_unk300;             // 0x300
    s32 m_unk304;             // 0x304
    s32 m_unk308;             // 0x308
    s32 m_unk30C;             // 0x30C
    char m_name[0x20];        // 0x310
    s32 m_unk330;             // 0x330
    s32 m_unk334;             // 0x334
    s32 m_unk338;             // 0x338
    u8 pad33C[0x4];
    CVec4 m_unk340;           // 0x340
    s32 m_unk350;             // 0x350
    s8 m_unk354[6];           // 0x354
    s8 m_unk35A[6][2];        // 0x35A
};

//@sym memcpy 0x289DFC
//@sym __builtin_new 0x245648
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00112FE0);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00113090);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", Func113128__9CCharaObj);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", Func113368__Fii);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00113418);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_001135F0);

void CCharaObj::Release113758() {
    if (m_res) {
        Func114D70(0, -1);
        Func113898();
        ReleaseSwing();
        ReleaseDiff();
        if (m_unk34) {
            D_002B91B0(m_unk34);
            m_unk34 = 0;
        }
        if (m_unk28) {
            D_002B91B0(m_unk28);
            m_unk28 = 0;
        }
        if (m_unk2C) {
            D_002B91B0(m_unk2C);
            m_unk2C = 0;
        }
        if (m_part24) {
            m_part24->Release();
            delete m_part24;
            m_part24 = 0;
        }
        if (m_unk70 >= 0) {
            func_001ECCA8(m_unk70);
            m_unk70 = -1;
        }
        Func113128();
        m_res = 0;
    }
}

s32 CCharaObj::Func113860(s32 v) {
    Func113898();
    m_unk18 = v;
    return Func1138E8();
}

void CCharaObj::Func113898() {
    if (m_unk30) {
        D_002B91B0(m_unk30);
        m_unk30 = 0;
    }
    m_unk48.Func252BB8();
    m_unk18 = 0;
}

INCLUDE_ASM("asm/nonmatchings/CCharaObj", Func1138E8__9CCharaObj);

INCLUDE_RODATA("asm/nonmatchings/CCharaObj", D_002D3588);
INCLUDE_RODATA("asm/nonmatchings/CCharaObj", D_002D3590);
INCLUDE_RODATA("asm/nonmatchings/CCharaObj", D_002D35A0);
INCLUDE_RODATA("asm/nonmatchings/CCharaObj", D_002D35B0);
INCLUDE_RODATA("asm/nonmatchings/CCharaObj", D_002D35C0);
INCLUDE_RODATA("asm/nonmatchings/CCharaObj", D_002D35D0);
INCLUDE_RODATA("asm/nonmatchings/CCharaObj", D_002D35E0);
INCLUDE_RODATA("asm/nonmatchings/CCharaObj", D_002D35F0);
INCLUDE_RODATA("asm/nonmatchings/CCharaObj", D_002D3600);
INCLUDE_RODATA("asm/nonmatchings/CCharaObj", D_002D3610);
INCLUDE_RODATA("asm/nonmatchings/CCharaObj", D_002D3620);
INCLUDE_RODATA("asm/nonmatchings/CCharaObj", D_002D3630);
INCLUDE_RODATA("asm/nonmatchings/CCharaObj", D_002D3638);
INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00113978);

void CCharaObj::ReleaseSwing() {
    if (m_part1C) {
        m_part1C->Release();
        delete m_part1C;
        m_part1C = 0;
    }
}

void CCharaObj::SetPart1CUnk2C(f32 v) {
    if (m_part1C) {
        m_part1C->m_unk2C = v;
    }
}

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00113C38);

void CCharaObj::ReleaseDiff() {
    if (m_part20) {
        func_0010FC98(m_part20);
        delete m_part20;
        m_part20 = 0;
    }
}

void CCharaObj::SetPart20Unk18(f32 v) {
    if (m_part20) {
        m_part20->m_unk18 = v;
    }
}

s32 CCharaObj::GetResIndex() {
    if (!m_res) {
        return -1;
    }
    return m_res->GetCur8();
}

s32 CCharaObj::Func113F38() {
    if (!m_res) {
        return -1;
    }
    if (m_unk70 >= 0) {
        return m_unk70;
    }
    return m_res->Get44(m_unk74);
}

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00113F80);

void CCharaObj::CallFunc114050(s32 b) {
    Func114050(0, b);
}

INCLUDE_ASM("asm/nonmatchings/CCharaObj", Func114050__9CCharaObjii);
INCLUDE_RODATA("asm/nonmatchings/CCharaObj", D_002D36B0);
INCLUDE_RODATA("asm/nonmatchings/CCharaObj", D_002D36C0);
INCLUDE_RODATA("asm/nonmatchings/CCharaObj", D_002D36D0);
INCLUDE_RODATA("asm/nonmatchings/CCharaObj", D_002D36E0);
INCLUDE_RODATA("asm/nonmatchings/CCharaObj", D_002D36F0);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_001141F0);

f32 CCharaObj::Func114670() {
    s32 i = Func113F38();
    if (i < 0) {
        return 0.0f;
    }
    return Func1EAC30(i);
}

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_001146A8);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", Func114828__9CCharaObjP5CVec4T1);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00114958);

u32 ReadVarint(u8 **pp) {
    u32 v = 0;
    u8 c;
    do {
        c = *(*pp)++;
        v = (v << 7) | (c & 0x7F);
    } while (c & 0x80);
    return v;
}

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00114C78);

void CCharaObj::Part24Func10DB70() {
    if (m_part24) {
        m_part24->Func10DB70();
    }
}

void CCharaObj::SetUnk150(s32 v) {
    m_unk150 = v;
}

void CCharaObj::Part24Func10DBD8() {
    if (m_part24) {
        m_part24->Func10DBD8();
    }
}

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00114D18);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", Func114D70__9CCharaObjii);

void CCharaObj::SetPart24Unk18(s32 v) {
    if (m_part24) {
        m_part24->m_unk18 = v;
    }
}

s32 CCharaObj::GetPart24Unk18() {
    return m_part24 ? m_part24->m_unk18 : -1;
}

void CCharaObj::Part24Func10DC80() {
    if (m_part24) {
        m_part24->Func10DC80();
    }
}

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00114EA0);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00115278);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00115328);

s32 CCharaObj::Func115388() {
    return m_unk288 < m_unk28C || m_unk2C0 < m_unk2C4 || m_unk2D0 < m_unk2D4 || m_unk300 < m_unk304;
}

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_001153E8);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00115470);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_001156A8);

void CCharaObj::Func115830(CVec4 *v, s32 n, s32 m) {
    Func114828(v, v);
    if (n == 0) {
        Func270C50(&m_unk120, v);
        m_unk304 = 0;
        return;
    }
    Func270C50(&m_unk2E0, &m_unk120);
    Func270C50(&m_unk2F0, v);
    m_unk300 = 0; 
    m_unk304 = n;
    m_unk308 = m;
}

void CCharaObj::Func1158C0(s32 id, const char *name, s32 a, s32 b) {
    if (id < 0) {
        m_unk30C = -1;
        return;
    }
    m_unk30C = id;
    Func24B600(m_name, name, 0x20);
    Func270C50(&m_unk340, &m_unk120);
    m_unk330 = 0; 
    m_unk334 = a;
    m_unk338 = b;
}

void CCharaObj::Func115938(s32 a, s32 b, f32 x, f32 y) {
    if (b < 0) {
        Func1159A0(a, 0);
        m_unk350 = 0;
        return;
    }
    Func114050(a, b);
    m_unk80 = y;
    Func116A98(0, 0);
    m_unk350 = 1;
}

void CCharaObj::Func1159A0(s32 a, s32 i) {
    Func114050(a, m_unk354[i]);
    Func116A40(i);
}

void CCharaObj::Func1159E8(const CVec4 *v, s32 n) {
    if (n == 0) {
        Func270C50(&m_unkB0, v);
        m_unk2C0 = 0;
        m_unk2C4 = 0;
        return;
    }
    Func270C50(&m_unk2A0, &m_unkB0);
    Func270C50(&m_unk2B0, v);
    m_unk2C0 = 0;
    m_unk2C4 = n;
}

void CCharaObj::SetUnk354(u32 i, s32 v) {
    if (i < 6) {
        m_unk354[i] = v;
    }
}

s32 CCharaObj::GetUnk354(u32 i) {
    s32 r = -1;
    if (i < 6) {
        r = m_unk354[i];
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00115A98);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00115B48);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00115C28);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00115D00);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00115E48);
INCLUDE_RODATA("asm/nonmatchings/CCharaObj", D_002D3758);
INCLUDE_RODATA("asm/nonmatchings/CCharaObj", D_002D3768);

void CCharaObj::Func116A40(u32 i) {
    s32 t[2];
    if (i < 6) {
        t[0] = m_unk35A[i][0];
        t[1] = m_unk35A[i][1];
        Func116A98(t, t[0] != t[1] ? 2 : 0);
    }
}

void CCharaObj::Func116A98(s32 *src, s32 n) {
    s32 i;
    for (i = 0; i < n && i < 2; i++) {
        m_unk17C[i] = src[i];
    }
    m_unk184 = n > 2 ? 2 : n;
}

INCLUDE_ASM("asm/nonmatchings/CCharaObj", Func116AE0__9CCharaObj);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00116B98);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00116D60);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_001170F0);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00117198);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_001173C0);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00117468);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", func_00117668);

INCLUDE_ASM("asm/nonmatchings/CCharaObj", Func117898__9CCharaObjii);

s32 CCharaObj::Func117AC8(s32 a, s32 b) {
    s32 i = GetResIndex();
    if (i < 0) {
        return 0;
    }
    return Func117898(a, Func113368(i, b));
}

INCLUDE_ASM("asm/nonmatchings/CCharaObj", Func117B48__9CCharaObjiii);

s32 CCharaObj::Func117DA0(s32 a, s32 b, s32 c) {
    s32 i = GetResIndex();
    if (i < 0) {
        return 0;
    }
    return Func117B48(a, Func113368(i, b), c);
}

void Func117E38(void *dst, s32 *src) {
    if (dst && src) {
        memcpy(dst, src, *src * 48 + 16);
    }
}

void CCharaObj::Func117E78() {
    s32 i = GetResIndex();
    if (i >= 0) {
        s32 **e = (s32 **)(D_002A5D0C + i * 52);
        if (e) {
            s32 *p = *e;
            if (p) {
                Func117E38(m_unk28, p);
                Func117E38(m_unk2C, p);
                Func117E38(m_unk30, p);
                Func117E38(m_unk34, p);
            }
        }
    }
}

s32 CCharaObj::Func117F10(s32 v) {
    s32 i = GetResIndex();
    if (i < 0) {
        return -1;
    }
    s32 r = Func113368(i, v);
    if (r < 0) {
        r = -1;
    }
    return r;
}

CModelAccResMgr *CreateSub117F98() {
    return new CModelAccResMgr;
}
