#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CMenuProcess.h"

//@sym __builtin_new 0x245648
//@sym __8CMenuMgr 0x1B3C68
class CMenuMgr {
public:
    CMenuMgr() throw();

    u8 pad0[0xE0];
};
// @decl-end

CMenuProcess::CMenuProcess() {
    m_unk4 = -1;
    m_unk2 = 0;
    m_unk0 = 0;
    m_state = 0;
    m_unk4C = -1;
}

CMenuProcess::~CMenuProcess() {
}

void CMenuProcess::SetState4() {
    m_state = 4;
}

void CMenuProcess::SetState6() {
    m_state = 6;
}

void CMenuProcess::SetUnk50(s32 v) {
    m_unk50 = v;
}

CMenuMgr *CreateCMenuMgr() {
    return new CMenuMgr;
}
