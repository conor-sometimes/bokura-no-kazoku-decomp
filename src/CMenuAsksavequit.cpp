#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

class CMenuAsksavequitSub193E18 {
public:
    void ClearUnk10();

    u8 pad0[0x10];
    s32 m_unk10;              // 0x10
};
class CMenuAsksavequitSub193FC0 {
public:
    u64 SwapUnk0(u64 v);
    u64 SwapUnk8(u64 v);

    u64 m_unk0;               // 0x0
    u64 m_unk8;               // 0x8
};

extern "C" void func_00194490(void *p);
class CMenuRecord {
public:
    static CMenuRecord *Create();
};

extern void (*D_002B91B0)(void *p);
class CMenuAsksavequitSub193F80 {
public:
    void Free();
    u8 pad0[0x10];
    void *m_unk10;            // 0x10
};

#include "CChrBodyWin.h"
extern CChrBodyWin *D_002A4308;
extern "C" void func_00189270(void *p, s32 v);
class CMenuLoadMemorialSub17A8D8 {
public:
    ~CMenuLoadMemorialSub17A8D8();
};
class CMenuLoadMemorialSub17CAB8 {
public:
    ~CMenuLoadMemorialSub17CAB8();
};
class CMenuAsksavequitObj {
public:
    void Release194300();
    u8 pad0[0x64];
    void *m_unk64;            // 0x64
    void *m_unk68;            // 0x68
    u8 pad6C[0x4];
    CMenuLoadMemorialSub17CAB8 *m_unk70; // 0x70
    u8 pad74[0x8];
    CMenuLoadMemorialSub17A8D8 *m_unk7C; // 0x7C
};

#include "CMenuMgrSub1B6418.h"
class CUnk1A4298 {
public:
    int Func1A4298();
    u8 pad0[0x34];
    f32 m_unk34;              // 0x34
    f32 GetUnk34() { return m_unk34; }
};
class CUnk237E90 {
public:
    int Func237E90(int v);
};
extern CMenuMgrSub1B6418 *D_002A5538;
extern "C" u8 *func_00237570(s32 v);
extern "C" void func_00237A88(void *p, s32 v);
extern "C" void *func_00237C30(void *p);
extern "C" int func_00238158(void *p, s32 v);
extern "C" int func_001B66E8(void *p);
void Func225240(s32 v);
class CMenuAsksavequitWin {
public:
    CMenuAsksavequitWin(int n);
    int Func193D68();
    u8 pad0[0x48];
    CUnk1A4298 *m_unk48;     // 0x48
};

#include "CMenuMgrSub1B4768.h"
extern CMenuMgrSub1B4768 *D_002A5530;
extern "C" int func_001B4ED0(CMenuMgrSub1B4768 *p, s32 v);
extern "C" int func_001B50B0(CMenuMgrSub1B4768 *p, s32 v);
#include "CMenuRecordWin.h"
// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuAsksavequit.
class CMenuAsksavequit : public CMenuProcess {
public:
    CMenuAsksavequit();
    virtual ~CMenuAsksavequit();
    virtual void Update();
    virtual s32 Draw();

    CUnk1A4298 *m_unk58;      // 0x58
    s32 m_unk5C;              // 0x5C
};

extern char D_002DD5F0[];
extern char D_002DD600[];
extern char D_002DD610[];
extern char D_002DD630[];
extern char D_002DD648[];
extern "C" int sprintf(char *buf, const char *fmt, ...);
extern "C" void *func_00248E48(const char *name);
extern "C" void func_00253048(void *p, s32 *a, s32 *b, s32 *c, s32 *d, s32 *e, s32 *f, s32 *g, s32 *h);
extern "C" void func_0023C048(s32 a, s32 b, s32 c);
class CMiniGame6Obj {
public:
    int Func247B00();
};
extern "C" CMiniGame6Obj *func_002460C8();
class CMenuAsksavequitImg {
public:
    int Load193E28(const char *name);
    u8 pad0[0x10];
    void *m_handle;           // 0x10
    s32 m_unk14;              // 0x14
    s32 m_unk18;              // 0x18
    s32 m_unk1C;              // 0x1C
    s32 m_unk20;              // 0x20
    s32 m_unk24;              // 0x24
    s32 m_unk28;              // 0x28
    s32 m_unk2C;              // 0x2C
    s32 m_unk30;              // 0x30
};

// Sound player (global D_002A5468); slot 14 plays a system sound.
class CSePlayer {
public:
    virtual ~CSePlayer();
    virtual void F1();
    virtual void F2();
    virtual void F3();
    virtual void F4();
    virtual void F5();
    virtual void F6();
    virtual int F7(s32 *a, s32 *b, s32 *c);
    virtual void F8();
    virtual void F9();
    virtual void F10();
    virtual void F11();
    virtual void F12();
    virtual void F13();
    virtual void Play(s32 id);
};
extern CSePlayer *D_002A5468;
// Cursor of a selection list (the class is in the next unit; not identified yet).
class CMenuCursorList {
public:
    void Up();
    void Down();

    u8 pad0[0x8C];
    s32 m_cur;                // 0x8C
    s32 m_prev;               // 0x90
    u8 pad94[0x8];
    s32 m_num;                // 0x9C
    u8 padA0[0xA8];
    s32 m_mute;               // 0x148
};

struct CGsTexInfo {
    u64 tbp : 14;
    u64 tbw : 6;
    u64 pad20 : 12;
    u64 psm : 6;
    u64 pad38 : 26;
};
class CMenuAsksavequitTex {
public:
    int Draw193FE0();
    void Draw194140(f32 x, f32 y, f32 s);

    u64 m_tex;                // 0x0
    u64 m_clut;               // 0x8
    u8 pad10[0x4];
    s32 m14;                  // 0x14
    s32 m18;                  // 0x18
    s32 m1C;                  // 0x1C
    s32 m20;                  // 0x20
    s32 m24;                  // 0x24
    u8 pad28[0x4];
    s32 m2C;                  // 0x2C
    s32 m30;                  // 0x30
};
void Func225088();
int Func2250C0();
void Func2251E8();
void Func227DC8(long a, s32 b, s32 c);
extern "C" void func_00227BF0(u64 a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern "C" void func_00227A20();
extern "C" void func_00227AA8();
extern "C" void func_00226DF8(s32 reg, u64 v);
#define GS_SET_TEX0(tbp, tbw, psm, tw, th, tcc, tfx, cbp, cpsm, csm, csa, cld) \
    ((u64)(tbp) | ((u64)(tbw) << 14) | ((u64)(psm) << 20) | ((u64)(tw) << 26) | ((u64)(th) << 30) | \
     ((u64)(tcc) << 34) | ((u64)(tfx) << 35) | ((u64)(cbp) << 37) | ((u64)(cpsm) << 51) | \
     ((u64)(csm) << 55) | ((u64)(csa) << 56) | ((u64)(cld) << 61))
#define GS_SET_CLAMP(wms, wmt, minu, maxu, minv, maxv) \
    ((u64)(wms) | ((u64)(wmt) << 2) | ((u64)(minu) << 4) | ((u64)(maxu) << 14) | \
     ((u64)(minv) << 24) | ((u64)(maxv) << 34))

struct CAqSprPkt {
    s32 u0, v0, u1, v1;
    s32 x0, y0, x1, y1;
    s32 r, g, b, a;
};
inline void PutRGBA2(CAqSprPkt *p) { func_00226DF8(1, (u64)p->r | ((u64)p->g << 8) | ((u64)p->b << 16) | ((u64)p->a << 24)); }
inline void PutXYZ2(s32 x, s32 y) { func_00226DF8(5, (u64)x | ((u64)y << 16)); }
inline void PutUV2(s32 u, s32 v) { func_00226DF8(3, (u64)u | ((u64)v << 16)); }

struct AsqWinV { s16 m0; s16 m2; s32 m4; u8 pad8[0x44]; s32 m4C; s32 m50; s32 m54; s32 m58; s32 m5C; };
extern char D_002DBEB0[];
#include "CFlagWork.h"
extern CFlagWork *D_002A5358;

class CStatusItem {
public:
    void Func1A3378();
    void Func1A3628();
    void Start();
    void Func1A40C8();
    int Select(s32 i);
    void SetUnk34(f32 v);
    u8 pad0[0x20];
    s32 m_state;              // 0x20
};
class CStatusWinSub1A0A10 {
public:
    CStatusItem *Find(const char *name);
};
extern CStatusWinSub1A0A10 *D_002A5408;
#include "CFlagWork.h"
extern CFlagWork *D_002A4B60;
// @decl-end

CMenuAsksavequit::CMenuAsksavequit() {
    m_unk58 = 0;
    m_unk5C = 0;
}

CMenuAsksavequit::~CMenuAsksavequit() {
}

void CMenuAsksavequit::Update() {
    s32 a, b, c;
    s32 done;
    D_002A5468->F7(&a, &b, &c);
    if (m_state == 6) {
        m_state = 5;
        goto end;
    }
    done = 0;
loop:
    if (done) goto out;
    {
        u32 fl = (u16)m_unk0;
        if ((fl >> 7) & 1) goto out;
    }
    switch (m_unk4) {
    case -1:
        m_unk58 = (CUnk1A4298 *)D_002A5408->Find("asksavequit");
        if (!m_unk58) { Func235DE0("*** Can't Get %s Window\n", "asksavequit"); return; }
        if (0) {
    c3:
            D_002A5468->Play(3);
            m_unk4C = -1;
            goto s4;
    c1:
            D_002A5468->Play(1);
            m_unk4C = 1;
            goto s4;
    tmo:
            m_unk4C = -1;
            goto s4;
        }
        ((CStatusItem *)m_unk58)->Func1A3378();
        D_002A5538->SetUnkE0(0);
        ((CStatusItem *)m_unk58)->Func1A3628();
        ((CStatusItem *)m_unk58)->Select(-1);
        do {
    case -0x93:
        if (((CStatusItem *)m_unk58)->m_state != 2) {
            m_unk4 = -0x93; done = 1; goto loop;
        }
        } while (0);
        m_unk4 = -0x98; done = 1; goto loop;
    case -0x98:
        m_unk5C = 0;
        while (m_unk5C++ < D_002A4B60->Func1091B0(0x76)) {
            m_unk4 = -0x9D; done = 1; goto loop;
    case -0x9D:;
        }
        m_unk5C = 0;
        do {
    case -0xC4:
        if (a & 0x800) goto c1;
        if (a & 0x40) goto c3;
        if (a & 0x20) goto c3;
        if (!D_002A26E0->Func1091B0(8)) {
            m_unk5C++;
            if (D_002A4B60->Func1091B0(0x47) < m_unk5C) {
                m_unk4 = -0xC8; done = 1; goto loop;
            }
        }
        m_unk4 = -0xC4; done = 1; goto loop;
        } while (0);
    case -0xC8:
        m_unk5C = 0;
    case -0xE7:
        ((CStatusItem *)m_unk58)->SetUnk34(1.0f - (f32)m_unk5C / (f32)D_002A4B60->Func1091B0(0x48));
        if (a & 0x60) goto c3;
        if (a & 0x800) goto c1;
        m_unk5C++;
        if (D_002A4B60->Func1091B0(0x48) >= m_unk5C) {
            m_unk4 = -0xE7; done = 1; goto loop;
        }
        goto tmo;
    s4:
        m_state = 4;
        ((CStatusItem *)m_unk58)->Start();
    case -0xF8:
        if (((CStatusItem *)m_unk58)->m_state != 0) {
            m_unk4 = -0xF8; done = 1; goto loop;
        }
        m_state = 5;
        m_unk4 = -0xFC;
    case -0xFC:
        done = 1; goto loop;
    }
out:
    ((CStatusItem *)m_unk58)->Func1A40C8();
end:;
}

s32 CMenuAsksavequit::Draw() {
    f32 v[2];
    if (m_unk58 == 0) {
        Func225088();
        Func2250C0();
    } else {
    u8 *p = func_00237570(0x40);
    func_00237A88(p, 4);
    CUnk237E90 *q = (CUnk237E90 *)(p + 0x20);
    func_00238158(func_00237C30(p + 0x30), 1);
    ((CUnk237E90 *)(p + 0x10))->Func237E90(m_unk58->Func1A4298());
    q->Func237E90(func_001B4ED0(D_002A5530, D_002A5530->GetEntry0(0x43)));
    D_002A5530->Reset1B4D28();
    D_002A5530->SetUnk4C(m_unk58->GetUnk34());
    ((CMenuRecordWin *)m_unk58)->Func1A39A8(&v[0], (s32 *)&v[1], 1);
    D_002A5530->SetUnk20(v[0], v[1], 0.0f);
    q->Func237E90(func_001B50B0(D_002A5530, 0x43));
    Func225088();
    Func225240((s32)p);
    Func2250C0();
    }
}

