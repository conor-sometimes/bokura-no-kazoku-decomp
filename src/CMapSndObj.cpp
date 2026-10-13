#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CMapSndObjSub128190 {
public:
    int SetUnk4(s32 v);
    void ClearUnk4();

    u8 pad0[0x4];
    s32 m_unk4;               // 0x4
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CMapSndObj", func_00128110);

INCLUDE_ASM("asm/nonmatchings/CMapSndObj", func_00128130);

int CMapSndObjSub128190::SetUnk4(s32 v) {
    m_unk4 = v;
    return 1;
}

void CMapSndObjSub128190::ClearUnk4() {
    if (m_unk4) {
        m_unk4 = 0;
    }
}

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_001281B8() {
}

INCLUDE_ASM("asm/nonmatchings/CMapSndObj", func_001281C0);

INCLUDE_ASM("asm/nonmatchings/CMapSndObj", func_00128238);

INCLUDE_ASM("asm/nonmatchings/CMapSndObj", func_001284A8);

INCLUDE_ASM("asm/nonmatchings/CMapSndObj", func_00128528);

// Empty; real name and class unknown (a virtual no-op or a stub).
extern "C" void func_00128868() {
}
