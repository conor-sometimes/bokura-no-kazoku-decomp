#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "ISnapMgr.h"

void *Func245D00(int size);

// Vtable 0x2BFE10 (still asm); the methods are in ISnapMgr.cpp (one object with this unit).
class CSnapMgr : public ISnapMgr {
public:
    CSnapMgr();
    virtual ~CSnapMgr();

    u8 *m_buf;                // 0x8
    f32 m_unkC;               // 0xC
    f32 m_unk10;              // 0x10
    f32 m_unk14;              // 0x14
    s32 m_unk18;              // 0x18
    s32 m_unk1C;              // 0x1C
    s32 m_unk20;              // 0x20
    s32 m_unk24;              // 0x24
    s32 m_unk28;              // 0x28
    s32 m_unk2C;              // 0x2C
    s32 m_unk30;              // 0x30
    void *m_unk34;            // 0x34
};
// @decl-end

CSnapMgr::CSnapMgr() {
    D_0029F398 = this;
    m_buf = (u8 *)Func245D00(0x118000);
    m_unkC = 0;
    m_unk10 = 0;
    m_unk14 = 0;
    m_unk18 = 0;
    m_unk20 = 0;
    m_unk24 = 0;
    m_unk28 = 0;
    m_unk30 = -1;
    m_unk2C = 0;
    m_unk34 = 0;
}
