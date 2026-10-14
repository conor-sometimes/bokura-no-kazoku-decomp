#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" void func_001704F8(void *p);
class CPhotoDBMgr {
public:
    static CPhotoDBMgr *Create();
};

struct CAlbumSub8 {
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
struct CAlbumScene {
    u8 pad0[0x38];
    s32 m_unk38;              // 0x38
    u8 pad3C[0x4];
};
struct CAlbumSceneSet {
    u8 pad0[0x2C];
    s32 m_unk2C;              // 0x2C
    u8 pad30[0xB0];
};
// Album manager interface (vtable _vt$9IAlbumMgr, slots 7-8 pure).
class IAlbumMgr : public CTask {
public:
    virtual ~IAlbumMgr();
    virtual void Init16D660() = 0;
    virtual void Term16D768() = 0;
};
class CAlbumMgr : public IAlbumMgr {
public:
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
    u8 pad10[0x4C];
    void *m_buf;              // 0x5C
    void *m_bufA;             // 0x60
    void *m_bufB;             // 0x64
    u8 m_obj68[0x6C];         // 0x68
    CEventObj *m_event;       // 0xD4
    u8 padD8[0x8];
    CAlbumSceneSet m_sceneSet; // 0xE0
    CAlbumScene m_scene;      // 0x1C0
    s32 m_unk200[3];          // 0x200
    s32 m_unk20C;             // 0x20C
    s32 m_unk210;             // 0x210
    s32 m_unk214;             // 0x214
    s32 m_unk218;             // 0x218
};
extern "C" s32 func_00251BA8();
extern "C" void func_00251B98(s32 v);
extern "C" void func_001F1BD8(s32 v);
class CPhotoDBMgr2 {
public:
    virtual void Vf29A2A8();
    virtual void Vf1705C0();
    virtual void Init();
    virtual void Vf29A2E0();
    virtual void Vf29A2E8();
    virtual void Vf29A320();
    virtual void GetName(char *buf, s32 a, s32 b);
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
int Func235DE0(const char *fmt, ...);
class CNameDBMgr {
public:
    static CEventObj *Create(void *p);
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/IAlbumMgr", func_0016D548);

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

INCLUDE_ASM("asm/nonmatchings/IAlbumMgr", func_0016D660);

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

INCLUDE_ASM("asm/nonmatchings/IAlbumMgr", func_0016D870);

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

INCLUDE_ASM("asm/nonmatchings/IAlbumMgr", func_0016DAD0);

INCLUDE_ASM("asm/nonmatchings/IAlbumMgr", func_0016DEE8);

void GetPhotoName16DFA8(char *dst, s32 a, s32 b, s32 c) {
    char buf[0x50];
    D_002A36C0->Vf171510(buf, a, b, c);
    strcpy(dst, buf);
}

INCLUDE_ASM("asm/nonmatchings/IAlbumMgr", Func16E008__18CPhotoEventObjSub8iii);

INCLUDE_ASM("asm/nonmatchings/IAlbumMgr", Func16E280__10CUnk16E280);

INCLUDE_ASM("asm/nonmatchings/IAlbumMgr", Func16E518__10CUnk16E280);

INCLUDE_ASM("asm/nonmatchings/IAlbumMgr", func_0016E688);

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

INCLUDE_ASM("asm/nonmatchings/IAlbumMgr", func_0016E960);

INCLUDE_ASM("asm/nonmatchings/IAlbumMgr", func_0016EB68);

INCLUDE_ASM("asm/nonmatchings/IAlbumMgr", func_0016F568);

INCLUDE_ASM("asm/nonmatchings/IAlbumMgr", func_0016FBF8);

int Blit16FE20(u32 *buf, s32 x, s32 y, s32 w, s32 h) {
    u32 *lower = buf + w * h / 2;
    Func225088();
    func_00227CB8(func_00251488(), x, y, w, h / 2, buf);
    func_00227CB8(func_00251488(), x, y + h / 2, w, h / 2, lower);
    return Func2250C0();
}

INCLUDE_ASM("asm/nonmatchings/IAlbumMgr", func_0016FEE0);

INCLUDE_ASM("asm/nonmatchings/IAlbumMgr", func_001702E0);

CPhotoDBMgr *CPhotoDBMgr::Create() {
    CPhotoDBMgr *p = (CPhotoDBMgr *)operator new(0x24);
    func_001704F8(p);
    return p;
}
