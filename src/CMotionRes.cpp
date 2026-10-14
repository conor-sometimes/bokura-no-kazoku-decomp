#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
struct CMotionRec {
    u8 pad0[0x10];
    s32 m_id;                 // 0x10
    void *m_data;             // 0x14
    u8 pad18[0x4];
};
class CMotionTbl {
public:
    void Release();
    int Init(s32 a, s32 b);
    CMotionRec *Find(s32 id);
    s32 m_num;                // 0x0
    CMotionRec *m_recs;       // 0x4
    s32 m_max;                // 0x8
};

//@sym memset 0x289FB0
#include "libc.h"
extern "C" s32 func_00110B30(CMotionRec *recs, s32 a, s32 b);
extern "C" void *func_00245678(u32 size);

extern void (*D_002B91B0)(void *p);
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CMotionRes", func_00110AB0);

INCLUDE_ASM("asm/nonmatchings/CMotionRes", func_00110AD0);

INCLUDE_ASM("asm/nonmatchings/CMotionRes", func_00110B30);

int CMotionTbl::Init(s32 a, s32 b) {
    Release();
    m_num = func_00110B30(0, a, b);
    m_recs = (CMotionRec *)func_00245678(m_num * sizeof(CMotionRec));
    memset(m_recs, 0, m_num * sizeof(CMotionRec));
    func_00110B30(m_recs, a, b);
    m_max = 0;
    for (s32 i = 0; i < m_num; i++) {
        s32 v = m_recs[i].m_id + 1;
        if (v < m_max) v = m_max;
        m_max = v;
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/CMotionRes", func_00110DC8);

void CMotionTbl::Release() {
    if (m_recs == 0) return;
    for (s32 i = 0; i < m_num; i++) {
        if (m_recs[i].m_data) D_002B91B0(m_recs[i].m_data);
    }
    operator delete(m_recs);
    m_recs = 0;
    m_num = 0;
}

INCLUDE_ASM("asm/nonmatchings/CMotionRes", func_00110FD8);

CMotionRec *CMotionTbl::Find(s32 id) {
    for (s32 i = 0; i < m_num; i++) {
        CMotionRec *r = &m_recs[i];
        if (r->m_id < 0) continue;
        if (id < 0 || r->m_id == id) return r;
    }
    return 0;
}
