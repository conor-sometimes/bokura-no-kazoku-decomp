#pragma interface
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
extern "C" void *memcpy(void *dst, const void *src, unsigned int n);
extern char D_002E1998[], D_002E19B0[];
int Func235DE0(const char *fmt, ...);
// Byte queue (ring buffer) inside the board at 0x9EC.
struct CMg6Queue {
    u8 pad0[0x8];
    u8 *m_buf;                // 0x8
    s32 m_wr;                 // 0xC
    s32 m_rd;                 // 0x10
    s32 m_size;               // 0x14
    s32 m_count;              // 0x18
    s32 Peek(void *dst, s32 n) {
        s32 rd, done, k;
        if (m_count <= 0) {
            Func235DE0(D_002E1998);
            return 0;
        }
        rd = m_rd;
        done = 0;
        do {
            k = n - done;
            if (!(k < m_size - rd)) k = m_size - rd;
            if (dst) memcpy((u8 *)dst + done, m_buf + rd, k);
            rd = (rd + k) % m_size;
            done += k;
        } while (done < n);
        return 1;
    }
    void Pop(void *dst, s32 n) {
        if (Peek(dst, n)) {
            m_rd = (m_rd + n) % m_size;
            m_count -= n;
        }
    }
    s32 Write(const void *src, s32 n) {
        s32 wr, done, k;
        if (m_size - m_count <= 0) {
            Func235DE0(D_002E19B0);
            return 0;
        }
        wr = m_wr;
        done = 0;
        do {
            k = m_size - wr;
            if (n - done < k) k = n - done;
            memcpy(m_buf + wr, (const u8 *)src + done, k);
            wr = (wr + k) % m_size;
            done += k;
        } while (done < n);
        return 1;
    }
    void Push(const void *src, s32 n) {
        if (Write(src, n)) {
            m_wr = (m_wr + n) % m_size;
            m_count += n;
        }
    }
};
class CMiniGame6Board {
public:
    s32 CheckLine(s32 *out);
    s32 FindFree(s32 row, s32 v);
    void SetPos(f32 v);
    void SetAlpha(f32 v);
    static f32 Wrap(f32 v);
    s32 GetCell(s32 row, s32 col);
    void UpdateReel(s32 k);
    s32 Score();
    u8 pad0[0x100];
    CMiniGame6Sprite m_spr[6]; // 0x100
    f32 m_unk9A0;             // 0x9A0
    f32 m_unk9A4;             // 0x9A4
    u8 pad9A8[0x9EC - 0x9A8];
    CMg6Queue m_queue;        // 0x9EC
    s32 m_unkA08;             // 0xA08
    u8 padA0C[0x8];
    s32 m_unkA14;             // 0xA14
    s32 m_cells[3][20];       // 0xA18
    s32 m_state[3];           // 0xB08
    f32 m_unkB14[3];          // 0xB14 (reel position)
    f32 m_speed[3];           // 0xB20
    s32 m_want[3];            // 0xB2C
    s32 m_target[3];          // 0xB38
    s32 m_row[3];             // 0xB44
    f32 m_acc[3];             // 0xB50
    f32 m_lim[3];             // 0xB5C
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

// CListTag as in CList.h, but with the destructor inline (retail inlines the unlink into
// ~CMiniGame6Res); #pragma interface at the top keeps the vtables in the asm data.
class CListTag {
public:
    CListTag() {
        m_isHead = 0;
        m_next = this;
        m_prev = this;
    }
    virtual ~CListTag() {
        m_prev->m_next = m_next;
        m_next->m_prev = m_prev;
        m_next = this;
        m_prev = this;
    }

    s32 m_isHead;             // 0x0
    CListTag *m_prev;         // 0x4
    CListTag *m_next;         // 0x8
    // vptr 0xC
};
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

class CUnk237E90 {
public:
    int Func237E90(int v);
};
class CMenuMgrSub1B4768 {
public:
    int GetEntry0(int k);
    int Func1B4ED0(int v);
    void Reset1B4D28();
    void SetUnk20(f32 x, f32 y, f32 z);
    void SetUnk30(f32 x, f32 y, f32 z, f32 w);
    void SetUnk4C(f32 v);
};
// Func1B4ED0 is a CMenuMgr method on the same object (D_002A5530).
class CMenuMgr {
public:
    int Func1B4ED0(int v);
};
extern CMenuMgrSub1B4768 *D_002A5530;
extern "C" int func_001B50B0(CMenuMgrSub1B4768 *p, int k);
struct CMg6Main {
    u8 pad0[0x90];
    CUnk237E90 m_unk90;       // 0x90
};
extern CMg6Main *D_002A5BC0;
// @decl-end

CMiniGame6Res *CreateMiniGame6Res() {
    return new CMiniGame6Res;
}

CMiniGame6Res::~CMiniGame6Res() {
    ((CMiniGame6ResObj *)this)->Release1E35A8();
}

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

s32 CMiniGame6Board::CheckLine(s32 *out) {
    s32 g[3][3];
    s32 i, j, best, line;
    *out = -1;
    line = -1;
    if (m_unkA14 < 2) return -1;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) g[i][j] = GetCell(i, j);
    }
    best = *out;
    for (i = 0; i < 3; i++) {
        if (g[0][i] == g[1][i] && (best < 0 || g[0][i] < best)) {
            *out = g[0][i];
            best = g[0][i];
            line = i;
        }
    }
    if (g[1][1] == g[0][0] && (best < 0 || g[1][1] < best)) {
        *out = g[1][1];
        line = 2;
        best = g[1][1];
    }
    if (g[1][1] == g[0][2] && (best < 0 || g[1][1] < best)) {
        *out = g[1][1];
        best = g[1][1];
        line = 0;
    }
    return best != 4 ? line : -1;
}

s32 CMiniGame6Board::FindFree(s32 row, s32 v) {
    s32 c = (s32)m_unkB14[row];
    for (;;) {
        s32 i;
        for (i = 0; i < 3; i++) {
            if (m_cells[row][(c + i) % 20] == v) break;
        }
        if (i >= 3) return c;
        c = (c + 19) % 20;
    }
}

INCLUDE_ASM("asm/nonmatchings/CMiniGame6Res", func_001E3FF8);

INCLUDE_ASM("asm/nonmatchings/CMiniGame6Res", func_001E4630);

INCLUDE_ASM("asm/nonmatchings/CMiniGame6Res", func_001E4C70);

INCLUDE_ASM("asm/nonmatchings/CMiniGame6Res", func_001E6E80);

int DrawMg6Sprite(f32 x, f32 y, f32 s, f32 t, f32 a) {
    f32 px = (x - 320.0f) * s + 320.0f;
    f32 py = (y - 224.0f) * s + 224.0f;
    D_002A5BC0->m_unk90.Func237E90(((CMenuMgr *)D_002A5530)->Func1B4ED0(D_002A5530->GetEntry0(0x18)));
    D_002A5530->Reset1B4D28();
    D_002A5530->SetUnk20(px, py, 0.0f);
    D_002A5530->SetUnk30(s * t, s * t, 0.0f, 0.0f);
    D_002A5530->SetUnk4C(a);
    return D_002A5BC0->m_unk90.Func237E90(func_001B50B0(D_002A5530, 0x18));
}

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
