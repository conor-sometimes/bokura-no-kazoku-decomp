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
struct CTaskTag8 {
    CTaskTag8() {
        m_unk4 = -1;
        m_unk2 = 0;
        m_unk0 = 0;
    }
    s16 m_unk0;               // 0x0
    s16 m_unk2;               // 0x2
    s32 m_unk4;               // 0x4
};
class CEventRes {
public:
    CEventRes();
    u8 pad0[0x6C];
};
class CSndWorkReal {
public:
    CSndWorkReal();
    u8 pad0[0xE0];
};
class CSceneSet {
public:
    CSceneSet();
    u8 pad0[0x40];
};
class CAlbumMgrSub16D618 {
public:
    void Reset();
};
class IAlbumMgr : public CTask {
public:
    virtual ~IAlbumMgr();
};
// The album manager (vtable _vt$9CAlbumMgr); its constructor sits in this file.
class CAlbumMgr : public IAlbumMgr {
public:
    CAlbumMgr();
    virtual ~CAlbumMgr();

    CTaskTag8 m_unk8;         // 0x8
    u8 pad10[0x40];
    CBgWork m_bg;             // 0x50
    u8 pad5C[0xC];
    CEventRes m_res;          // 0x68
    u8 padD4[0xC];
    CSndWorkReal m_snd;       // 0xE0
    CSceneSet m_scene;        // 0x1C0
    u8 pad200[0x20];
};
extern CAlbumMgr *D_002A3680;
class CPhotoEventObjSub8 {
public:
    void Func16E008(s32 a, s32 b, s32 c);
};
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
void Func16DEE8(char *buf, s32 a, s32 b);
void GetPhotoName16DFA8(char *dst, s32 a, s32 b, s32 c);
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CPhotoEventObj", func_0016CF98);

INCLUDE_ASM("asm/nonmatchings/CPhotoEventObj", func_0016D2D8);

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
