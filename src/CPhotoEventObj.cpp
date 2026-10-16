#pragma interface
#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CPhotoEventObj {
public:
    int Func16D3A0();


};

//@sym __nw__5CTaskUi 0x24F2E8
#include "CTask.h"
#include "CBgWork.h"
class CTaskList24F5C0 {
public:
    s32 Func24F5C0(void *task, s32 pri);
};
class CPhotoEventObjSub8;
class CPhotoEventObj2 {
public:
    void Func16D448(s32 v);
    s32 GetName16D2D8(s32 k, char *buf, s32 d);
    s32 Run16D3A8(int a, u32 id, int b);

    u8 pad0[0x8];
    CPhotoEventObjSub8 *m_unk8; // 0x8
    u8 padC[0xFCFC];
    s32 m_unkFD08;            // 0xFD08
    s32 m_unkFD0C;            // 0xFD0C
};

#include "IUserFlagMgr.h"
class CUnk2A28D8 {
public:
    virtual void Vf0();
    virtual void Vf1();
    virtual void Vf2();
    virtual s32 GetName(s32 k, char *buf, s32 d);
};
extern CUnk2A28D8 *D_002A28D8;
void GetAlbumName16DEE8(char *buf, s32 a, s32 b);
void GetPhotoName16DFA8(char *dst, s32 a, s32 b, s32 c);
#pragma interface
#include "common.h"

extern "C" void func_001704F8(void *p);
class CPhotoDBMgr {
public:
    static CPhotoDBMgr *Create();
};

struct CAlbumSub8 {
    CAlbumSub8() {
        m_unk4 = -1;
        m_unk2 = 0;
        m_unk0 = 0;
    }
    s16 m_unk0;
    s16 m_unk2;
    s32 m_unk4;
    void Init() {
        m_unk0 = 0x80;
        m_unk4 = -1;
        m_unk2 = 0;
    }
    void Clear() {
        m_unk4 = -1;
        m_unk0 = 0;
        m_unk2 = 0;
    }
};
class CAlbumMgrSub16D618 {
public:
    void Reset();
    u8 pad0[0x8];
    CAlbumSub8 m_unk8;        // 0x8
    u8 pad10[0x5C - 0x10];
    s32 m_unk5C;              // 0x5C
    s32 m_unk60;              // 0x60
    s32 m_unk64;              // 0x64
    u8 pad68[0xD8 - 0x68];
    s32 m_unkD8;              // 0xD8
    u8 padDC[0x200 - 0xDC];
    s32 m_unk200;             // 0x200
    s32 m_unk204;             // 0x204
    s32 m_unk208;             // 0x208
    s32 m_unk20C;             // 0x20C
    s32 m_unk210;             // 0x210
    s32 m_unk214;             // 0x214
    s32 m_unk218;             // 0x218
};

extern "C" s32 func_002539A0(s32 psm);
extern "C" void func_00227BF0(u64 tex, s32 a, s32 b, s32 w, s32 h, u8 *src);

extern "C" void *func_00251488();
extern "C" void func_00227CB8(void *ctx, s32 x, s32 y, s32 w, s32 h, void *src);
int Func225088();
int Func2250C0();

#include "CTask.h"
class CEventObj {
public:
    void ClearScene();
    void Func132D30();
    virtual ~CEventObj();

    u8 pad0[0xFEC4];
    // vptr 0xFEC4
};
class CEventRes {
public:
    CEventRes();
    ~CEventRes();
    u8 pad0[0x6C];
};
class CSndWorkReal {
public:
    CSndWorkReal();
    ~CSndWorkReal();
    u8 pad0[0x2C];
    s32 m_unk2C;              // 0x2C
    u8 pad30[0xB0];
};
struct CSceneMapItem;
struct CSceneCharaItem;
class CSceneSet {
public:
    CSceneSet();
    ~CSceneSet();
    CSceneMapItem *FindA(s32 id);
    CSceneCharaItem *FindB(s32 id);
    u8 pad0[0x38];
    s32 m_unk38;              // 0x38
    u8 pad3C[0x4];
};
// Album manager interface (vtable _vt$9IAlbumMgr, slots 7-8 pure).
// #pragma interface (top) keeps this unit from emitting the vtables (asm data), so the key method
// ~CAlbumMgr can be C++; ~IAlbumMgr is inline in retail.
class IAlbumMgr : public CTask {
public:
    virtual ~IAlbumMgr() {}
    virtual void Init16D660() = 0;
    virtual void Term16D768() = 0;
};
// CPhotoEventObj.cpp and IAlbumMgr.cpp were one object (merged by lane lb).
class CAlbumMgr : public IAlbumMgr {
public:
    CAlbumMgr();
    void Func16E960();
    virtual ~CAlbumMgr();
    virtual void Update();
    virtual void Draw();
    virtual void Init16D660();
    virtual void Term16D768();
    virtual s32 GetCur();
    virtual s32 IsBusy();
    virtual s32 Request16D870(s32 k);
    virtual void Cancel16D940();
    virtual s32 Wait16D988(s32 wait);
    virtual void Vf16DAD0();
    virtual void Vf29A250();

    CAlbumSub8 m_unk8;        // 0x8
    u8 pad10[0x40];
    CBgWork m_bg;             // 0x50
    void *m_buf;              // 0x5C
    void *m_bufA;             // 0x60
    void *m_bufB;             // 0x64
    CEventRes m_obj68;        // 0x68
    CEventObj *m_event;       // 0xD4
    u8 padD8[0x8];
    CSndWorkReal m_sceneSet;  // 0xE0
    CSceneSet m_scene;        // 0x1C0
    s32 m_unk200[3];          // 0x200
    s32 m_unk20C;             // 0x20C
    s32 m_unk210;             // 0x210
    s32 m_unk214;             // 0x214
    s32 m_unk218;             // 0x218
    u8 pad21C[0x4];           // (sizeof 0x220: new CAlbumMgr)
};
extern "C" s32 func_00251BA8();
extern "C" void func_00251B98(s32 v);
extern "C" void func_001F1BD8(s32 v);
struct CPhotoEntry {
    u8 pad0[0x4];
    s32 m_id;                 // 0x4
};
class CPhotoDBMgr2 {
public:
    virtual void Vf29A2A8();
    virtual void Vf1705C0();
    virtual void Init();
    virtual s32 GetNum();
    virtual CPhotoEntry *GetEntry(s32 i);
    virtual void Vf29A320();
    virtual s32 GetName(char *buf, s32 a, s32 b);
    virtual s32 Vf171510(char *buf, s32 a, s32 b, s32 c);
};
extern CPhotoDBMgr2 *D_002A36C0;
#include "libc.h"

struct CResHeap {
    u8 pad0[0x8];
    s32 m_free;               // 0x8
};
extern CResHeap *D_002A0BE8;
extern "C" void *func_00250D28(CResHeap *h);
extern "C" void func_00250DD8(CResHeap *h, void *p);
extern "C" void func_0012C630(void *p, s32 a, s32 b);
extern "C" void func_0012C578(void *p, s32 a);
extern "C" void func_0012C6F8(void *p, void *q);
extern "C" void func_0012C7E0(void *p);
extern "C" void func_0012C6A8(void *p);
extern "C" void func_0012C5F0(void *p);
extern "C" void func_00132208(void *p);
void SetSndWorkRealInstance(void *p);
extern char D_002D9D50[];
int Func235DE0(const char *fmt, ...) throw();
class CNameDBMgr {
public:
    static CEventObj *Create(void *p);
};

#include "CFlagWork.h"
struct CStr6 { char c[6]; };
extern CStr6 D_002D9D78;

struct CPhotoSceneInfo {
    s8 m_flag;                // 0x0
    u8 pad1[0x1F];
    s32 m_map;                // 0x20
    s32 m_unk24;              // 0x24
    f32 m_unk28;              // 0x28
    f32 m_pos[3];             // 0x2C
    f32 m_unk38;              // 0x38
    f32 m_unk3C;              // 0x3C
    f32 m_unk40;              // 0x40
    s32 m_unk44;              // 0x44
    s32 m_unk48;              // 0x48
    s32 m_link;               // 0x4C
};
struct CSceneVec { f32 x, y, z; };
struct CSceneCam {
    u8 pad0[0x10];
    CSceneVec m_pos;          // 0x10
    u8 pad1C[0x4];
    CSceneVec m_at;           // 0x20
};
struct CSceneMapRes { u8 pad0[0x18]; CSceneCam *m_cam; };
struct CSceneMapItem {
    u8 pad0[0x4C];
    CSceneMapRes *m_res;      // 0x4C
    s32 m_obj;                // 0x50
};
class CCharaObj {
public:
    void CallFunc114050(s32 v, f32 t);
    void SetPart24Unk18(s32 v);
    void SetUnk150(s32 v);
};
struct CSceneCharaF {
    u8 pad0[0x64];
    s32 m_unk64;              // 0x64
    u8 pad68[0x4];
    s32 m_unk6C;              // 0x6C
    u8 pad70[0x10];
    f32 m_unk80;              // 0x80
    u8 pad84[0x1C];
    f32 m_unkA0;              // 0xA0
    f32 m_unkA4;              // 0xA4
    f32 m_unkA8;              // 0xA8
    u8 padAC[0x18];
    f32 m_unkC4;              // 0xC4
    u8 padC8[0x8];
    f32 m_unkD0;              // 0xD0
    f32 m_unkD4;              // 0xD4
    f32 m_unkD8;              // 0xD8
    u8 padDC[0x64];
    s32 m_unk140;             // 0x140
};
struct CSceneCharaItem { u8 pad0[0x24]; CSceneCharaF *m_chara; };
class CMapObj {
public:
    void SetFlag11B070(s32 i);
};
extern "C" void func_00201C20(f32 x, f32 y, f32 z);
extern "C" void func_00201C88(f32 x, f32 y, f32 z);
extern "C" s32 func_001170F0(CSceneCharaF *c);
extern "C" void func_00115278(CSceneCharaF *c, CSceneCharaF *d, const char *s);
extern char D_002D9D80[];
class CPhotoEventObjSub8 {
public:
    void Func16E008(s32 a, s32 b, s32 c);
};

struct CAlbumSlots { u8 pad[0x200]; s32 slot[2]; };
inline void AlbClr(CAlbumSub8 *c) { c->m_unk4 = -1; c->m_unk2 = 0; c->m_unk0 = 0; }
extern CAlbumMgr *D_002A3680;
// @decl-end

INCLUDE_RODATA("asm/nonmatchings/CPhotoEventObj", D_002D9D10);
INCLUDE_RODATA("asm/nonmatchings/CPhotoEventObj", D_002D9D18);
INCLUDE_RODATA("asm/nonmatchings/CPhotoEventObj", D_002D9D20);
INCLUDE_RODATA("asm/nonmatchings/CPhotoEventObj", D_002D9D28);
INCLUDE_ASM("asm/nonmatchings/CPhotoEventObj", func_0016CF98);

s32 CPhotoEventObj2::GetName16D2D8(s32 k, char *buf, s32 d) {
    switch (k) {
    case 1:
        GetPhotoName16DFA8(buf, m_unkFD08, m_unkFD0C, d);
        return 1;
    case 0:
        GetAlbumName16DEE8(buf, m_unkFD08, m_unkFD0C);
        break;
    }
    return D_002A28D8->GetName(k, buf, d);
}

int CPhotoEventObj::Func16D3A0() {
    return 0;
}

s32 CPhotoEventObj2::Run16D3A8(int a, u32 id, int b) {
    D_002A0D38->Vf298D90(m_unkFD08 * 4);
    return D_002A0D38->Vf1412D0(a, id, b);
}

void CPhotoEventObj2::Func16D448(s32 v) {
    if (v == 0) {
        m_unk8->Func16E008(m_unkFD08, m_unkFD0C, 0);
    }
}

void AddPhotoEventObjSub16D4D8(CTaskList24F5C0 *list) {
    CAlbumMgr *t = new CAlbumMgr;
    list->Func24F5C0(t, 0);
}

CAlbumMgr::CAlbumMgr() {
    D_002A3680 = this;
    ((CAlbumMgrSub16D618 *)this)->Reset();
}

CAlbumMgr::~CAlbumMgr() {
    func_00245818(&m_bg, 1);
    CAlbumMgr::Term16D768();
    D_002A3680 = 0;
}

void CAlbumMgrSub16D618::Reset() {
    m_unk5C = 0;
    m_unk64 = 0;
    m_unk60 = 0;
    m_unk200 = -1;
    m_unk20C = 0;
    m_unk204 = 0;
    m_unk208 = 0;
    m_unk210 = 0;
    m_unk214 = 0;
    m_unk218 = 0;
    m_unk8.Init();
    m_unkD8 = 0;
}

INCLUDE_ASM("asm/nonmatchings/CPhotoEventObj", func_0016D660);
INCLUDE_RODATA("asm/nonmatchings/CPhotoEventObj", D_002D9D78);
INCLUDE_RODATA("asm/nonmatchings/CPhotoEventObj", D_002D9D80);
INCLUDE_RODATA("asm/nonmatchings/CPhotoEventObj", D_002D9D90);
INCLUDE_RODATA("asm/nonmatchings/CPhotoEventObj", D_002D9DA0);
INCLUDE_RODATA("asm/nonmatchings/CPhotoEventObj", D_002D9DB0);
INCLUDE_RODATA("asm/nonmatchings/CPhotoEventObj", D_002D9DC0);
INCLUDE_RODATA("asm/nonmatchings/CPhotoEventObj", D_002D9DD0);
INCLUDE_RODATA("asm/nonmatchings/CPhotoEventObj", D_002D9DE0);
INCLUDE_RODATA("asm/nonmatchings/CPhotoEventObj", D_002D9DF0);
INCLUDE_RODATA("asm/nonmatchings/CPhotoEventObj", D_002D9E00);

void CAlbumMgr::Term16D768() {
    Cancel16D940();
    Wait16D988(1);
    if (m_buf) {
        func_00250DD8(D_002A0BE8, m_buf);
        m_bufB = 0;
        m_bufA = 0;
        m_buf = 0;
    }
    if (m_event) {
        CEventObj *ev = m_event;
        ev->ClearScene();
        ev->Func132D30();
        if (m_event) delete m_event;
        m_event = 0;
    }
    func_00132208(&m_obj68);
    func_0012C7E0(&m_scene);
    func_0012C6A8(&m_scene);
    func_0012C5F0(&m_scene);
    SetSndWorkRealInstance(0);
    ((CAlbumMgrSub16D618 *)this)->Reset();
}

s32 CAlbumMgr::Request16D870(s32 k) {
    s32 i;
    CAlbumSlots *s;
    if (IsBusy()) return -1;
    if (GetCur() && m_unk200[0] == k) return m_unk214;
    s = (CAlbumSlots *)((u8 *)this + 4);
    if (s->slot[m_unk214]) m_unk214 = m_unk214 == 0;
    i = m_unk214;
    m_unk200[0] = k;
    m_unk20C = 1;
    s->slot[i] = 0;
    m_unk210 = 0;
    m_unk218 = 0;
    AlbClr(&m_unk8);
    return m_unk214;
}

void CAlbumMgr::Cancel16D940() {
    if (IsBusy()) m_unk210 = 1;
}

s32 CAlbumMgr::Wait16D988(s32 wait) {
    if (wait) {
        while (IsBusy()) {
            Update();
            func_00251B98(func_00251BA8() + 1);
            func_001F1BD8(0);
        }
    }
    return IsBusy();
}

void Blit16DA20(u64 tex, s32 a, s32 b, s32 w, s32 y, s32 h, u8 *base) {
    func_00227BF0(tex, a, b, w, h, base + y * func_002539A0((s32)((tex >> 32) & 0x3F)) * w / 8);
}

INCLUDE_ASM("asm/nonmatchings/CPhotoEventObj", func_0016DAD0);

void GetAlbumName16DEE8(char *dst, s32 a, s32 b) {
    char buf[32];
    D_002A36C0->GetName(buf, a, b);
    strcpy(dst, buf);
    if (a == 0x23 && b == 1 && D_002A26E4->Func1091B0(0x3B64)) {
        *(CStr6 *)dst = D_002D9D78;
    }
}

void GetPhotoName16DFA8(char *dst, s32 a, s32 b, s32 c) {
    char buf[0x50];
    D_002A36C0->Vf171510(buf, a, b, c);
    strcpy(dst, buf);
}

void CPhotoEventObjSub8::Func16E008(s32 a, s32 b, s32 c) {
    CPhotoSceneInfo info;
    s32 i, n;
    CSceneMapItem *m = ((CSceneSet *)this)->FindA(0);
    if (m) {
        CSceneCam *cam = m->m_res->m_cam;
        CSceneVec *p = &cam->m_pos;
        CSceneVec *q = &cam->m_at;
        func_00201C20(p->x, p->y, p->z);
        func_00201C88(q->x, q->y, q->z);
    }
    n = D_002A36C0->GetNum();
    for (i = 0; i < n; i++) {
        s32 id = D_002A36C0->GetEntry(i)->m_id;
        if (!D_002A36C0->Vf171510((char *)&info, a, b, id)) continue;
        if (info.m_flag) {
            CSceneCharaItem *ch = ((CSceneSet *)this)->FindB(id);
            if (ch) {
                if (c == 0) {
                    ch->m_chara->m_unkA0 = info.m_pos[0];
                    ch->m_chara->m_unkA4 = info.m_pos[1];
                    ch->m_chara->m_unkA8 = info.m_pos[2];
                    ch->m_chara->m_unkC4 = info.m_unk38;
                }
                ch->m_chara->m_unkD0 = info.m_unk3C;
                ch->m_chara->m_unkD4 = info.m_unk40;
                ch->m_chara->m_unkD8 = info.m_unk3C;
                ((CCharaObj *)ch->m_chara)->CallFunc114050(info.m_unk24, 0.0f);
                ch->m_chara->m_unk80 = info.m_unk28;
                ch->m_chara->m_unk140 = info.m_unk44;
                ((CCharaObj *)ch->m_chara)->SetPart24Unk18(info.m_unk48);
                ((CCharaObj *)ch->m_chara)->SetUnk150(0);
                ch->m_chara->m_unk6C = 0;
                CSceneCharaF *cc = ch->m_chara;
                cc->m_unk64 = func_001170F0(cc);
                if (info.m_link >= 0) {
                    CSceneCharaItem *l = ((CSceneSet *)this)->FindB(info.m_link);
                    if (l) func_00115278(ch->m_chara, l->m_chara, D_002D9D80);
                }
                continue;
            }
        }
        if (info.m_map >= 0 && m) ((CMapObj *)m->m_obj)->SetFlag11B070(info.m_map);
    }
}

INCLUDE_ASM("asm/nonmatchings/CPhotoEventObj", Func16E280__10CUnk16E280);

INCLUDE_ASM("asm/nonmatchings/CPhotoEventObj", Func16E518__10CUnk16E280);

INCLUDE_ASM("asm/nonmatchings/CPhotoEventObj", func_0016E688);

void FillBorder16E830(u32 *buf, s32 w, s32 h, s32 t, u32 val) {
    u32 *p = buf;
    u32 *q = buf + (h - t - 1) * w;
    s32 i, j;
    for (i = w * t; i > 0; i--) {
        *p++ = val;
        *q++ = val;
    }
    p = buf;
    q = buf + w - t - 1;
    for (i = h; i > 0; i--) {
        for (j = t; j > 0; j--) {
            *p++ = val;
            *q++ = val;
        }
        p += w - t;
        q += w - t;
    }
}

void ClearBorder16E8E0(u32 *buf, s32 w, s32 h) {
    u32 *p = buf;
    u32 *q = buf + (h - 1) * w;
    s32 i;
    for (i = w; i > 0; i--) {
        *p++ = 0;
        *q++ = 0;
    }
    p = buf;
    q = buf + w - 1;
    for (i = h; i > 0; i--) {
        *p = 0;
        *q = 0;
        p += w;
        q += w;
    }
}

INCLUDE_ASM("asm/nonmatchings/CPhotoEventObj", func_0016E960);

INCLUDE_RODATA("asm/nonmatchings/CPhotoEventObj", D_002D9E20);
INCLUDE_RODATA("asm/nonmatchings/CPhotoEventObj", D_002D9E28);
INCLUDE_RODATA("asm/nonmatchings/CPhotoEventObj", D_002D9E48);
INCLUDE_RODATA("asm/nonmatchings/CPhotoEventObj", D_002D9E88);
INCLUDE_ASM("asm/nonmatchings/CPhotoEventObj", func_0016EB68);

INCLUDE_ASM("asm/nonmatchings/CPhotoEventObj", func_0016F568);

INCLUDE_ASM("asm/nonmatchings/CPhotoEventObj", func_0016FBF8);

int Blit16FE20(u32 *buf, s32 x, s32 y, s32 w, s32 h) {
    u32 *lower = buf + w * h / 2;
    Func225088();
    func_00227CB8(func_00251488(), x, y, w, h / 2, buf);
    func_00227CB8(func_00251488(), x, y + h / 2, w, h / 2, lower);
    return Func2250C0();
}

INCLUDE_ASM("asm/nonmatchings/CPhotoEventObj", func_0016FEE0);

INCLUDE_ASM("asm/nonmatchings/CPhotoEventObj", func_001702E0);

CPhotoDBMgr *CPhotoDBMgr::Create() {
    CPhotoDBMgr *p = (CPhotoDBMgr *)operator new(0x24);
    func_001704F8(p);
    return p;
}
INCLUDE_RODATA("asm/nonmatchings/CPhotoEventObj", D_002D9E90);
INCLUDE_RODATA("asm/nonmatchings/CPhotoEventObj", D_002D9EA0);
INCLUDE_RODATA("asm/nonmatchings/CPhotoEventObj", D_002D9EB8);
