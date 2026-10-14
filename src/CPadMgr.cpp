#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CTask.h"
// Pad manager interface (vtable _vt$7IPadMgr, slots 7-12 pure).
class IPadMgr : public CTask {
public:
    virtual ~IPadMgr();
    virtual s32 Vf293408() = 0;
    virtual s32 Vf293410() = 0;
    virtual s32 Vf293420() = 0;
    virtual s32 Vf293418() = 0;
    virtual void SetUnk18(s32 v) = 0;
    virtual s32 Vf293428() = 0;
};
class CPadMgr : public IPadMgr {
public:
    CPadMgr();
    virtual ~CPadMgr();
    virtual s32 Vf293408();
    virtual s32 Vf293410();
    virtual s32 Vf293420();
    virtual s32 Vf293418();
    virtual void SetUnk18(s32 v);
    virtual s32 Vf293428();

    s32 m_unk8;               // 0x8
    s32 m_unkC;               // 0xC
    s32 m_unk10;              // 0x10
    s32 m_unk14;              // 0x14
    s32 m_unk18;              // 0x18
};
extern CPadMgr *D_0029F390;
// @decl-end

CPadMgr::CPadMgr() {
    D_0029F390 = this;
    m_unk18 = 1;
    m_unkC = 0;
    m_unk10 = 0;
    m_unk14 = 0;
    m_unk8 = 0;
}
