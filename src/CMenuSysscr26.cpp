#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

class CUnk1A4298 {
public:
    int Func1A4298();
};

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuSysscr26.
// Its .rodata starts with literals of the CMenuSysscr27Win helpers (0x1A98F8-0x1A9ED8, moved here
// from CMenuSysscr27.cpp) and of .data tables: those come in through INCLUDE_RODATA.
class CMenuSysscr26 : public CMenuProcess {
public:
    CMenuSysscr26();
    static CMenuSysscr26 *Create();
    virtual ~CMenuSysscr26();
    virtual void Update();
    virtual s32 Draw();

    CUnk1A4298 *m_unk58;    // 0x58
    s32 m_unk5C;              // 0x5C
    s32 m_unk60;              // 0x60
    s32 m_unk64;              // 0x64
    s32 m_unk68;              // 0x68
    s32 m_unk6C;              // 0x6C
    s32 m_unk70;              // 0x70
    s32 m_unk74;              // 0x74
};

//@sym __13CMenuSysscr25 0x1AA710
//@sym __builtin_new 0x245648
class CMenuSysscr25 {
public:
    CMenuSysscr25() throw();

    u8 pad0[0x60];
};

// From CMenuSysscr27.cpp (lane cv moved its functions 0x1A98C0.. here: their literals are this unit's)
#include "CMenuProcess.h"
#include "CBgWork.h"
class CMenuRecordWin;
extern "C" void func_001AA118(void *p);

#include "CMenuRecordWin.h"
extern "C" const char *func_001A36B0(CMenuRecordWin *w, s32 v);
extern "C" s32 func_0024BA08(char *buf, s32 v);
extern "C" int sprintf(char *buf, const char *fmt, ...);
//@sym sprintf 0x28AF70
class CMenuSysscr27Win {
public:
    void Func1A98F8();
    void Func1A9BF8();
    void Func1A9D30();
    void Func1A9ED8(s32 k);
    void Func1A9E60();
    void Func1AA0B0(f32 t);
    void Func1A9FA0(f32 t, s32 a, s32 b);
    void Func1A9FA0_8_9(f32 t);
    void Func1A9FA0_10_11(f32 t);
    void Func1A9FA0_6_7(f32 t);
    u8 pad0[0x58];
    CMenuRecordWin *m_unk58;  // 0x58
    s32 m_unk5C;              // 0x5C
    s32 m_unk60;              // 0x60
};

extern char D_002DF258[];

class CUnk237E90 {
public:
    int Func237E90(int v);
};
extern "C" u8 *func_00237570(s32 v);
extern "C" void func_00237A88(void *p, s32 v);
extern "C" void *func_00237C30(void *p);
extern "C" int func_00238158(void *p, s32 v);
extern "C" int func_001A0510(void *p);
extern "C" int func_0018A1F0(void *p);
void Func225240(s32 v);
class CMenuSysscr31 {
public:
    void Release1A8DC0();
};
// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuSysscr27.
class CMenuSysscr27 : public CMenuProcess {
public:
    CMenuSysscr27();
    virtual ~CMenuSysscr27();
    virtual void Update();
    virtual s32 Draw();

    CBgWork m_bg;             // 0x58
    void *m_unk64;            // 0x64
    void *m_unk68;            // 0x68
    s32 m_unk6C;              // 0x6C
    u8 pad70[0x4];
    s32 m_unk74;              // 0x74
};

extern "C" void func_001A3AF8(CMenuRecordWin *w, s32 k, f32 x, f32 y);

extern char D_002DF230[];

class CStatusItem {
public:
    void Func1A3378();
    void Func1A3628();
    void Start();
    void Func1A40C8();
    void Select(s32 i);
    const char *GetUnkE4(s32 i);
    void SetText(s32 i, const char *s);
    u8 pad0[0x20];
    s32 m_state;              // 0x20
};
class CStatusWinSub1A0A10 {
public:
    CStatusItem *Find(const char *name);
};
extern CStatusWinSub1A0A10 *D_002A5408;
extern const char *D_002A5460;
extern const char *D_002A5464;
class CSndIf {
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual int V7(s32 *a, s32 *b, s32 *c);
};
extern CSndIf *D_002A5468;
#include "CFlagWork.h"
extern CFlagWork *D_002A4B60;
extern CFlagWork *D_002A5358;
#include "CMenuMgrSub1B6418.h"
extern CMenuMgrSub1B6418 *D_002A5538;
extern "C" void func_001A98F8(void *p);
extern "C" void func_001A9BF8(void *p);
// @decl-end

CMenuSysscr26 *CMenuSysscr26::Create() {
    CMenuSysscr26 *p = (CMenuSysscr26 *)operator new(0x78);
    func_001AA118(p);
    return p;
}

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr26", func_001A98F8);

INCLUDE_ASM("asm/nonmatchings/CMenuSysscr26", func_001A9BF8);

void CMenuSysscr27Win::Func1A9D30() {
    char str[256];
    char buf[256];
    if (m_unk60 == 0) {
        func_0024BA08(buf, 25);
        sprintf(str, func_001A36B0(m_unk58, 10), buf);
        m_unk58->Func1A3740(10, str);
        str[0] = D_002DF230[0];
        m_unk58->Func1A3740(11, str);
    } else {
        func_0024BA08(buf, m_unk60 / 4 + 24);
        sprintf(str, func_001A36B0(m_unk58, 10), buf);
        m_unk58->Func1A3740(10, str);
        func_0024BA08(buf, m_unk60 / 4 + 25);
        sprintf(str, func_001A36B0(m_unk58, 11), buf);
        m_unk58->Func1A3740(11, str);
    }
}

void CMenuSysscr27Win::Func1A9E60() {
    char str[256];
    char buf[256];
    const char *fmt = func_001A36B0(m_unk58, 3);
    sprintf(str, fmt, func_0024BA08(buf, m_unk60 / 4 + 25));
    m_unk58->Func1A3740(3, str);
}

void CMenuSysscr27Win::Func1A9ED8(s32 k) {
    char str[256];
    if ((u32)(k - 1) >= 3) {
        Func235DE0(D_002DF258, k);
        k = 1;
    }
    sprintf(str, func_001A36B0(m_unk58, 6), func_001A36B0(m_unk58, k + 7));
    m_unk58->Func1A3740(6, str);
    sprintf(str, func_001A36B0(m_unk58, 7), func_001A36B0(m_unk58, k + 8));
    m_unk58->Func1A3740(7, str);
}

void CMenuSysscr27Win::Func1A9FA0(f32 t, s32 a, s32 b) {
    f32 v[4];
    m_unk58->Func1A39A8(&v[0], (s32 *)&v[2], a);
    m_unk58->Func1A39A8(&v[1], (s32 *)&v[3], b);
    f32 d = (v[3] - v[2]) * t;
    func_001A3AF8(m_unk58, a, v[0], v[2] - d);
    func_001A3AF8(m_unk58, b, v[1], v[3] - d);
}

void CMenuSysscr27Win::Func1A9FA0_8_9(f32 t) {
    Func1A9FA0(t, 8, 9);
}

void CMenuSysscr27Win::Func1A9FA0_10_11(f32 t) {
    Func1A9FA0(t, 10, 11);
}

void CMenuSysscr27Win::Func1A9FA0_6_7(f32 t) {
    Func1A9FA0(t, 6, 7);
}

void CMenuSysscr27Win::Func1AA0B0(f32 t) {
    if (m_unk5C == 0) {
        Func1A9FA0_8_9(t);
        Func1A9FA0_10_11(t);
    } else {
        Func1A9FA0_6_7(t);
    }
}

INCLUDE_RODATA("asm/nonmatchings/CMenuSysscr26", D_002DF208);
INCLUDE_RODATA("asm/nonmatchings/CMenuSysscr26", D_002DF218);
INCLUDE_RODATA("asm/nonmatchings/CMenuSysscr26", D_002DF228);
INCLUDE_RODATA("asm/nonmatchings/CMenuSysscr26", D_002DF230);
INCLUDE_RODATA("asm/nonmatchings/CMenuSysscr26", D_002DF238);
INCLUDE_RODATA("asm/nonmatchings/CMenuSysscr26", D_002DF258);
CMenuSysscr26::CMenuSysscr26() {
    m_unk58 = 0;
}

CMenuSysscr26::~CMenuSysscr26() {
}

void CMenuSysscr26::Update() {
    char tmp[0x100];
    char buf[0x300];
    s32 a, b, c;
    s32 done;
    if (m_state == 6) {
        m_state = 5;
        m_unk4C = -1;
        goto end;
    }
    D_002A5468->V7(&a, &b, &c);
    done = 0;
loop:
    if (done) goto out;
    {
        u32 fl = (u16)m_unk0;
        if ((fl >> 7) & 1) goto out;
    }
    switch (m_unk4) {
    case -1:
        m_unk60 = D_002A26E4->Func1091B0(0x17);
        if (!(D_002A26E4->Func1091B0(0x17) & 3)) {
            const char *fmt;
            const char *s1, *s2, *s3;
            m_unk5C = 0;
            m_unk58 = (CUnk1A4298 *)D_002A5408->Find(D_002A5460);
            ((CStatusItem *)m_unk58)->Func1A3378();
            fmt = ((CStatusItem *)m_unk58)->GetUnkE4(5);
            s1 = D_002A26E4->GetStr(0x23);
            s2 = D_002A26E4->GetStr(0x24);
            s3 = D_002A26E4->GetStr(0x25);
            sprintf(buf, fmt, s1, s2, s3);
            ((CStatusItem *)m_unk58)->SetText(5, buf);
            func_001A98F8(this);
            ((CMenuSysscr27Win *)this)->Func1A9D30();
            m_unk68 = D_002A4B60->Func1091B0(0x41);
            m_unk6C = D_002A4B60->Func1091B0(0x42);
            m_unk70 = D_002A4B60->Func1091B0(0x43);
        } else {
            m_unk5C = 1;
            m_unk58 = (CUnk1A4298 *)D_002A5408->Find(D_002A5464);
            ((CStatusItem *)m_unk58)->Func1A3378();
            func_001A9BF8(this);
            ((CMenuSysscr27Win *)this)->Func1A9E60();
            m_unk74 = m_unk60 % 4 - D_002A5358->Func1091B0(0x2C6);
            ((CMenuSysscr27Win *)this)->Func1A9ED8(m_unk74);
            m_unk68 = D_002A4B60->Func1091B0(0x44);
            m_unk6C = D_002A4B60->Func1091B0(0x45);
            m_unk70 = D_002A4B60->Func1091B0(0x46);
        }
        ((CStatusItem *)m_unk58)->Select(-1);
        D_002A5538->SetUnkE0(0);
        ((CStatusItem *)m_unk58)->Func1A3628();
        do {
    case -0x1EC:
        if (((CStatusItem *)m_unk58)->m_state != 2) {
            m_unk4 = -0x1EC; done = 1; goto loop;
        }
        if (m_unk60 == 0) {
            m_unk4 = -0x230; done = 1; goto loop;
        }
        } while (0);
        m_unk64 = 0;
        do {
    case -0x1F7:
        if (m_unk68 >= ++m_unk64) {
            m_unk4 = -0x1F7; done = 1; goto loop;
        }
        } while (0);
    y1FB:
        m_unk4 = -0x1FB; done = 1; goto loop;
    case -0x1FB:
        m_unk64 = 0;
    case -0x209:
        ((CMenuSysscr27Win *)this)->Func1AA0B0((f32)m_unk64 / (f32)m_unk6C);
        if (m_unk70 >= ++m_unk64) {
            m_unk4 = -0x209; done = 1; goto loop;
        }
        if (!(D_002A26E4->Func1091B0(0x17) & 3)) goto y21F;
        if (m_unk74 == m_unk60 % 4) goto y21F;
        ((CMenuSysscr27Win *)this)->Func1A9ED8(++m_unk74);
        ((CMenuSysscr27Win *)this)->Func1AA0B0(0.0f);
        goto y1FB;
    y21F:
        m_unk4 = -0x21F; done = 1; goto loop;
    case -0x21F:
        ((CMenuSysscr27Win *)this)->Func1AA0B0(1.0f);
        m_unk64 = 0;
    case -0x22B:
        if (m_unk70 >= ++m_unk64) {
            m_unk4 = -0x22B; done = 1; goto loop;
        }
        goto s4;
    case -0x230:
        m_unk64 = 0;
    case -0x237:
        if (m_unk70 + m_unk6C + m_unk68 >= ++m_unk64) {
            m_unk4 = -0x237; done = 1; goto loop;
        }
    s4:
        ((CStatusItem *)m_unk58)->Start();
        do {
    case -0x246:
        if (((CStatusItem *)m_unk58)->m_state != 0) {
            m_unk4 = -0x246; done = 1; goto loop;
        }
        } while (0);
        m_state = 5;
        m_unk4 = -0x24C;
    case -0x24C:
        done = 1; goto loop;
    }
out:
    ((CStatusItem *)m_unk58)->Func1A40C8();
end:;
}

s32 CMenuSysscr26::Draw() {
    if (!m_unk58) {
        Func225088();
        return Func2250C0();
    }
    return m_unk58->Func1A4298();
}

CMenuSysscr25 *CreateCMenuSysscr25() {
    return new CMenuSysscr25;
}
