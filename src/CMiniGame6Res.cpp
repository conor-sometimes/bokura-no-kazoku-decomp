#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CMiniGame6Obj {
public:
    s32 GetRemaining();
    int Func247B00();

    u8 pad0[0x14];
    s32 m_unk14;              // 0x14
    u8 pad18[0x30];
    s32 m_unk48;              // 0x48
};
extern CMiniGame6Obj *D_002A5BAC;
extern CMiniGame6Obj *D_002A5BB0;
extern s32 D_002A5BB8;
extern s32 D_002A5B90;
extern s32 D_002A5B94;

s32 Func23E290();
extern void (*D_002B91B0)();

extern "C" void func_001B9B30(void *p);
extern void *D_002A5A40;
class CMiniGame6ResObj {
public:
    void Release1E35A8();
    u8 pad0[0x10];
    u8 m_unk10[0x24];         // 0x10
    u8 m_unk34[0x24];         // 0x34
};

extern "C" void *func_0024F2E8(s32 size);
extern "C" void func_0024F5C0(void *a, void *b, s32 c);
extern "C" void func_001E91B8(void *p);

extern "C" s32 func_0022D0A0(s32 v);
extern s32 D_002A5BBC;
extern s32 D_002A5B98;
extern s32 D_002A5B9C;
extern "C" void *func_00246088(void *heap);
extern "C" void *func_00245DD0(s32 size);

extern "C" void *func_0024F2E8(s32 size);
extern "C" void func_0024F5C0(void *a, void *b, s32 c);
extern "C" void func_001E3660(void *p, s32 a, s32 b, s32 c);

struct CMiniGame6Sprite {
    u8 pad0[0x20];
    f32 m_r;                  // 0x20
    f32 m_g;                  // 0x24
    f32 m_b;                  // 0x28
    f32 m_a;                  // 0x2C
    u8 pad30[0x10];
    f32 m_x;                  // 0x40
    f32 m_y;                  // 0x44
    f32 m_w;                  // 0x48
    f32 m_h;                  // 0x4C
    u8 pad50[0x170 - 0x50];
    void SetRect(f32 x, f32 y, f32 w, f32 h) {
        m_x = x;
        m_y = y;
        m_w = w;
        m_h = h;
    }
    void SetColor(f32 r, f32 g, f32 b, f32 a) {
        m_r = r;
        m_g = g;
        m_b = b;
        m_a = a;
    }
};
class CMiniGame6Board {
public:
    void SetPos(f32 v);
    void SetAlpha(f32 v);
    f32 Wrap(f32 v);
    s32 GetCell(s32 row, s32 col);
    u8 pad0[0x100];
    CMiniGame6Sprite m_spr[6]; // 0x100
    f32 m_unk9A0;             // 0x9A0
    f32 m_unk9A4;             // 0x9A4
    u8 pad9A8[0xA18 - 0x9A8];
    s32 m_cells[3][20];       // 0xA18
    u8 padB08[0xC];
    f32 m_unkB14[8];          // 0xB14
};

extern "C" void func_002491A8(char *buf, const char *name, const char *a, const char *b, const char *c);
extern "C" int func_001B8760(void *p, const char *path);
extern char D_002E18E0[];
extern char D_002E18E8[];
extern char D_002E18F8[];
extern char D_002E1910[];
extern char D_002E1920[];
extern s32 D_002A5BA0;
extern void *D_002A5BB4;
extern "C" void func_0022CAB0();
extern "C" void func_0024F738(void *p, s32 a, s32 b);
extern "C" s32 func_00251B88();
extern "C" void func_00251B78(s32 v);
extern "C" s32 func_00251BA8();
extern "C" void func_00251B98(s32 v);
extern "C" void func_001E80A0();
void Func1E8030();
class CMiniGame6ResLoader {
public:
    int Load1E34E8(const char *name);
    u8 pad0[0x10];
    u8 m_unk10[0x24];         // 0x10
    u8 m_unk34[0x24];         // 0x34
};

// Renderer object at D_002BA0B0 and another at D_002B9E10 (vptr at 0).
class CMg6Gfx {
public:
    virtual void Release();
    virtual int SetName(const char *s);
    virtual void V2();
    virtual void SetSize(s32 w, s32 h);
    virtual void SetCell(s32 w, s32 h);
};
extern CMg6Gfx *D_002BA0B0;
extern CMg6Gfx *D_002B9E10;
extern char D_002E1CA0[];
extern "C" void func_00245880();
extern "C" void func_00251BB8();
extern "C" void func_0024F298(void *(*f)(s32));
extern "C" void func_0024F2C0(void (*f)());
extern "C" void *func_0024F420();
extern "C" void func_0024F610(void *p);
void *Alloc1E7E58(s32 size);
void CallMiniGame6Hook();
void Func1E9168(void *a);

#include "CList.h"
class CLayoutRes {
public:
    CLayoutRes();
    ~CLayoutRes();
    u8 pad[0x24];
};
// Vtable _vt$13CMiniGame6Res: destructor (0x1E3440), Load (0x1E34E8), Release (0x1E35A8).
class CMiniGame6Res : public CListTag {
public:
    CMiniGame6Res() {}
    virtual ~CMiniGame6Res();
    virtual s32 Load(const char *path);
    virtual void Release();

    CLayoutRes m_res10;       // 0x10
    CLayoutRes m_res34;       // 0x34
};
// @decl-end

CMiniGame6Res *CreateMiniGame6Res() {
    return new CMiniGame6Res;
}

INCLUDE_ASM("asm/nonmatchings/CMiniGame6Res", func_001E3440);

int CMiniGame6ResLoader::Load1E34E8(const char *name) {
    char buf[256];
    s32 r = 0;
    func_002491A8(buf, 0, D_002E18E0, D_002E18E8, D_002E18F8);
    if (func_001B8760(m_unk10, buf)) {
        func_002491A8(buf, name, D_002E18E0, D_002E1910, D_002E1920);
        if (func_001B8760(m_unk34, buf)) {
            r = 1;
            D_002A5A40 = this;
        }
    }
    return r;
}

void CMiniGame6ResObj::Release1E35A8() {
    D_002A5A40 = 0;
    func_001B9B30(m_unk10);
    func_001B9B30(m_unk34);
}

void Func1E35E0(void *a, s32 b, s32 c, s32 d) {
    void *p = func_0024F2E8(0xBE0);
    func_001E3660(p, b, c, d);
    func_0024F5C0(a, p, 0);
}

INCLUDE_ASM("asm/nonmatchings/CMiniGame6Res", func_001E3660);

INCLUDE_ASM("asm/nonmatchings/CMiniGame6Res", func_001E3978);

void CMiniGame6Board::SetPos(f32 v) {
    m_spr[0].SetRect(v, v, 320.0f, 224.0f);
    m_spr[1].SetRect(v, v, 320.0f, 224.0f);
    m_spr[3].SetRect(v, v, 320.0f, 224.0f);
    m_spr[2].SetRect(v, v, 320.0f, 224.0f);
    m_spr[4].SetRect(v, v, 320.0f, 224.0f);
    m_unk9A0 = v;
}

void CMiniGame6Board::SetAlpha(f32 v) {
    m_spr[0].SetColor(1.0f, 1.0f, 1.0f, v);
    m_spr[1].SetColor(1.0f, 1.0f, 1.0f, v);
    m_spr[3].SetColor(1.0f, 1.0f, 1.0f, v);
    m_spr[2].SetColor(1.0f, 1.0f, 1.0f, v);
    m_spr[4].SetColor(1.0f, 1.0f, 1.0f, v);
    m_spr[5].SetColor(1.0f, 1.0f, 1.0f, v);
    m_unk9A4 = v;
}

f32 CMiniGame6Board::Wrap(f32 v) {
    while (v < 0.0f) v += 20.0f;
    while (v >= 20.0f) v -= 20.0f;
    return v;
}

s32 CMiniGame6Board::GetCell(s32 row, s32 col) {
    return m_cells[row][(s32)Wrap(m_unkB14[row] + col)];
}

INCLUDE_ASM("asm/nonmatchings/CMiniGame6Res", func_001E3DC0);

INCLUDE_ASM("asm/nonmatchings/CMiniGame6Res", func_001E3F20);

INCLUDE_ASM("asm/nonmatchings/CMiniGame6Res", func_001E3FF8);

INCLUDE_ASM("asm/nonmatchings/CMiniGame6Res", func_001E4630);

INCLUDE_ASM("asm/nonmatchings/CMiniGame6Res", func_001E4C70);

INCLUDE_ASM("asm/nonmatchings/CMiniGame6Res", func_001E6E80);

INCLUDE_ASM("asm/nonmatchings/CMiniGame6Res", func_001E71A0);

INCLUDE_ASM("asm/nonmatchings/CMiniGame6Res", func_001E72D0);

s32 GetMiniGame6Remaining() {
    return 0x400000 - Func23E290();
}

s32 CMiniGame6Obj::GetRemaining() {
    return m_unk14 - m_unk48;
}

s32 GetMiniGame6RemainingA() {
    return D_002A5BAC->GetRemaining();
}

s32 GetMiniGame6RemainingB() {
    return D_002A5BB0->GetRemaining();
}

int CallMiniGame6Func247B00A() {
    return D_002A5BAC->Func247B00();
}

int CallMiniGame6Func247B00B() {
    return D_002A5BB0->Func247B00();
}

CMiniGame6Obj *GetMiniGame6ObjA() {
    return D_002A5BAC;
}

CMiniGame6Obj *GetMiniGame6ObjB() {
    return D_002A5BB0;
}

s32 GetMiniGame6Unk2A5BB8() {
    return D_002A5BB8;
}

s32 GetMiniGame6Unk2A5B90() {
    return D_002A5B90;
}

s32 GetMiniGame6Unk2A5B94() {
    return D_002A5B94;
}

void *Alloc1E7E58(s32 size) {
    void *old = func_00246088(D_002A5BB0);
    void *p = func_00245DD0(size);
    func_00246088(old);
    return p;
}

void CallMiniGame6Hook() {
    D_002B91B0();
}

INCLUDE_ASM("asm/nonmatchings/CMiniGame6Res", func_001E7ED8);

void Func1E8030() {
    if (D_002A5BB8) {
        if (func_0022D0A0(0) & 0x200) {
            D_002A5BBC = (D_002A5BBC + 1) % 3;
            if (D_002A5BBC == 0) {
                D_002A5B98 = 0;
                D_002A5B9C = 0;
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/CMiniGame6Res", func_001E80A0);

void InitMiniGame6() {
    func_00245880();
    func_00251BB8();
    D_002BA0B0->SetSize(0x280, 0x1C0);
    D_002BA0B0->SetCell(0x10, 0x10);
    D_002BA0B0->SetName(D_002E1CA0);
    func_0024F298(Alloc1E7E58);
    func_0024F2C0(CallMiniGame6Hook);
    Func1E9168(D_002A5BB4 = func_0024F420());
}

void ExitMiniGame6() {
    if (D_002A5BB4) {
        func_0024F610(D_002A5BB4);
    }
    if (D_002BA0B0) {
        D_002BA0B0->Release();
    }
    if (D_002B9E10) {
        D_002B9E10->Release();
    }
}

void Func1E8CA8() {
    s32 n = D_002A5BA0;
    n = n < 1 ? 1 : n;
    n = n < 5 ? n : 4;
    for (s32 i = 0; i < n; i++) {
        func_0022CAB0();
        func_0024F738(D_002A5BB4, 1, 0);
        Func1E8030();
        func_00251B78(func_00251B88() + 1);
    }
    func_0024F738(D_002A5BB4, 2, 0);
    func_001E80A0();
    func_00251B98(func_00251BA8() + 1);
}

INCLUDE_ASM("asm/nonmatchings/CMiniGame6Res", func_001E8D68);

void Func1E9168(void *a) {
    void *p = func_0024F2E8(0xC0);
    func_001E91B8(p);
    func_0024F5C0(a, p, 0);
}
