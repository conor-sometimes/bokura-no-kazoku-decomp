#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CProcess.h"
#include "CMemTex.h"
class CTaskList24F5C0 {
public:
    s32 Func24F5C0(void *task, s32 pri);
};
// Created here; its unit follows.
class CTitleMain : public CProcess {
public:
    CTitleMain();

    u8 pad18[0x7B8];
};

// Vtable and typeinfo name come from this unit (docs/units.md): key method ~CLogoMain.
class CLogoMain : public CProcess {
public:
    CLogoMain();
    virtual ~CLogoMain();
    virtual void Update();
    virtual void Draw();
    virtual s32 Func7();
    virtual void ReleaseTextures();

    u8 pad18[0x14];
    CMemTex m_tex2C;          // 0x2C
    CMemTex m_tex58;          // 0x58
    CStateMachine m_sm;       // 0x84
    u8 padCC[0x4];
    struct CLogoTex *m_texD0; // 0xD0
    f32 m_unkD4;              // 0xD4
    u8 padD8[0x4];
};

class CUnk237E90 {
public:
    void Func237E90(int v);
};
struct CUnk2A5BC0 {
    u8 pad0[0x60];
    CUnk237E90 m60;
};
extern CUnk2A5BC0 *D_002A5BC0;
class CLogoDrawCtx {
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual s32 V3();
};
extern CLogoDrawCtx *D_002BA128;
struct CLogoTex {
    u8 pad0[0x10];
    s32 m_w;
    s32 m_h;
};
struct CLogoVec {
    f32 x, y, z, w;
};
class CMiniGame6Obj;
CMiniGame6Obj *GetMiniGame6ObjB();
extern "C" s32 func_00246088(void *p);
extern "C" s32 func_00254AA8(CLogoTex *t, s32 r, CLogoVec *pos, CLogoVec *col, s32 a, s32 b);
extern "C" s32 func_00254248(CMemTex *t, void *p);
s32 Func249248(void *buf);
void Func249348();
extern void *D_0029F280;
extern void *D_0029F284;
extern void *D_0029F288;
// @decl-end

INCLUDE_RODATA("asm/nonmatchings/CLogoMain", D_002D1870);
INCLUDE_RODATA("asm/nonmatchings/CLogoMain", D_002D1880);
INCLUDE_RODATA("asm/nonmatchings/CLogoMain", D_002D1890);
INCLUDE_RODATA("asm/nonmatchings/CLogoMain", D_002D18A0);
INCLUDE_RODATA("asm/nonmatchings/CLogoMain", D_002D18C0);
CLogoMain::CLogoMain() {
}

CLogoMain::~CLogoMain() {
}

s32 CLogoMain::Func7() {
    s32 ok = 0;
    void *h = (void *)func_00246088(GetMiniGame6ObjB());
    if (Func249248(D_0029F280)) {
        ok = 1;
        func_00254248(&m_tex2C, D_0029F284);
        func_00254248(&m_tex58, D_0029F288);
        Func249348();
    }
    func_00246088(h);
    return ok;
}

void CLogoMain::ReleaseTextures() {
    m_tex2C.Func2546F0();
    m_tex58.Func2546F0();
}

INCLUDE_ASM("asm/nonmatchings/CLogoMain", Update__9CLogoMain);

void CLogoMain::Draw() {
    if (m_texD0 && !(m_unkD4 <= 0.0f)) {
        CLogoVec pos;
        CLogoVec col;
        f32 a = m_unkD4 * 128.0f;
        pos.x = -(f32)m_texD0->m_w * 0.5f;
        pos.y = -(f32)m_texD0->m_h * 0.5f;
        pos.z = 0.0f;
        col.w = a;
        col.y = 128.0f;
        col.z = 128.0f;
        col.x = 128.0f;
        D_002A5BC0->m60.Func237E90(func_00254AA8(m_texD0, D_002BA128->V3(), &pos, &col, 0, 0));
    }
}

void AddTitleMain(CTaskList24F5C0 *list) {
    CTitleMain *p = new CTitleMain;
    list->Func24F5C0(p, 0);
}
