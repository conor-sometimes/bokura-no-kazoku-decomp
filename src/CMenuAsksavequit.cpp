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

class CChrBodyWin {
public:
    void Func188BA8();
};
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

class CMenuMgrSub1B6418 {
public:
    void SetUnk4C(f32 v);
};
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
    int Func193D68();
    u8 pad0[0x48];
    CUnk1A4298 *m_unk48;     // 0x48
};

class CMenuMgrSub1B4768 {
public:
    s32 GetEntry0(s32 i);
    void Reset1B4D28();
    void SetUnk4C(f32 v);
    void SetUnk20(f32 x, f32 y, f32 z);
};
extern CMenuMgrSub1B4768 *D_002A5530;
extern "C" int func_001B4ED0(CMenuMgrSub1B4768 *p, s32 v);
extern "C" int func_001B50B0(CMenuMgrSub1B4768 *p, s32 v);
class CMenuRecordWin {
public:
    void Func1A39A8(f32 *v, s32 *n, s32 k);
};
// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CMenuAsksavequit.
class CMenuAsksavequit : public CMenuProcess {
public:
    CMenuAsksavequit();
    virtual ~CMenuAsksavequit();
    virtual s32 Update();
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
    virtual void F7();
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
// @decl-end

CMenuAsksavequit::CMenuAsksavequit() {
    m_unk58 = 0;
    m_unk5C = 0;
}

CMenuAsksavequit::~CMenuAsksavequit() {
}

INCLUDE_ASM("asm/nonmatchings/CMenuAsksavequit", Update__16CMenuAsksavequit);

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

INCLUDE_ASM("asm/nonmatchings/CMenuAsksavequit", __19CMenuAsksavequitWini);

INCLUDE_ASM("asm/nonmatchings/CMenuAsksavequit", Func193358__19CMenuAsksavequitWin);

int CMenuAsksavequitWin::Func193D68() {
    u8 *p = func_00237570(0x40);
    func_00237A88(p, 4);
    func_00238158(func_00237C30(p + 0x30), 1);
    ((CUnk237E90 *)(p + 0x10))->Func237E90(m_unk48->Func1A4298());
    D_002A5538->SetUnk4C(m_unk48->GetUnk34());
    ((CUnk237E90 *)(p + 0x20))->Func237E90(func_001B66E8(D_002A5538));
    Func225088();
    Func225240((s32)p);
    return Func2250C0();
}

void CMenuAsksavequitSub193E18::ClearUnk10() {
    m_unk10 = 0;
}

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_00193E20() {
}

int CMenuAsksavequitImg::Load193E28(const char *name) {
    char path[256];
    int ok = 1;
    sprintf(path, D_002DD5F0, D_002DD600, name);
    void *h = func_00248E48(path);
    if (h == 0) {
        Func235DE0(D_002DD610, path);
        ok = 0;
        func_002460C8()->Func247B00();
    } else {
        m_handle = h;
        func_00253048(h, &m_unk14, &m_unk18, &m_unk1C, &m_unk20, &m_unk24, &m_unk28, &m_unk2C, &m_unk30);
        if (m_unk2C >= 17) func_0023C048(m_unk2C * m_unk30, m_unk24, m_unk24);
        Func235DE0(D_002DD630, path, m_unk1C, m_unk20);
        Func235DE0(D_002DD648, m_unk28, m_unk2C, m_unk30);
    }
    return ok;
}

void CMenuAsksavequitSub193F80::Free() {
    if (m_unk10) {
        D_002B91B0(m_unk10);
        m_unk10 = 0;
    }
}

u64 CMenuAsksavequitSub193FC0::SwapUnk0(u64 v) {
    u64 old = m_unk0;
    m_unk0 = v;
    return old;
}

u64 CMenuAsksavequitSub193FC0::SwapUnk8(u64 v) {
    u64 old = m_unk8;
    m_unk8 = v;
    return old;
}

INCLUDE_ASM("asm/nonmatchings/CMenuAsksavequit", func_00193FE0);

INCLUDE_ASM("asm/nonmatchings/CMenuAsksavequit", func_00194140);

CMenuRecord *CMenuRecord::Create() {
    CMenuRecord *p = (CMenuRecord *)operator new(0x158);
    func_00194490(p);
    return p;
}

void CMenuAsksavequitObj::Release194300() {
    if (m_unk68) {
        func_00189270(m_unk68, 3);
        m_unk68 = 0;
    }
    if (m_unk7C) {
        delete m_unk7C;
        m_unk7C = 0;
    }
    if (m_unk70) {
        delete m_unk70;
        m_unk70 = 0;
    }
    if (m_unk64) {
        operator delete(m_unk64);
        m_unk64 = 0;
    }
    D_002A4308->Func188BA8();
}

void CMenuCursorList::Up() {
    if (m_num == 1) {
        return;
    }
    m_prev = m_cur;
    m_cur = m_cur - 1;
    if (m_cur < 0) {
        m_cur = m_num - 1;
    }
    if (m_prev != m_cur && !m_mute) {
        D_002A5468->Play(0x17);
    }
}

void CMenuCursorList::Down() {
    if (m_num == 1) {
        return;
    }
    m_prev = m_cur;
    m_cur = m_cur + 1;
    if (m_num - 1 < m_cur) {
        m_cur = 0;
    }
    if (m_prev != m_cur && !m_mute) {
        D_002A5468->Play(0x17);
    }
}
