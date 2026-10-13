#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
//@sym memset 0x289FB0
#include "libc.h"
class CMiniGame1ResSub1BDBC0 {
public:
    void Clear();

    u8 pad0[0x870];
    u8 m_data[0x14];          // 0x870
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CMiniGame1Res", func_001BD6A8);

INCLUDE_ASM("asm/nonmatchings/CMiniGame1Res", func_001BD700);

INCLUDE_ASM("asm/nonmatchings/CMiniGame1Res", func_001BD7C0);

INCLUDE_ASM("asm/nonmatchings/CMiniGame1Res", func_001BD7F8);

INCLUDE_ASM("asm/nonmatchings/CMiniGame1Res", func_001BD868);

INCLUDE_ASM("asm/nonmatchings/CMiniGame1Res", func_001BD958);

INCLUDE_ASM("asm/nonmatchings/CMiniGame1Res", func_001BDA08);

INCLUDE_ASM("asm/nonmatchings/CMiniGame1Res", func_001BDB38);

void CMiniGame1ResSub1BDBC0::Clear() {
    memset(m_data, 0, sizeof(m_data));
}

INCLUDE_ASM("asm/nonmatchings/CMiniGame1Res", func_001BDBE8);

INCLUDE_ASM("asm/nonmatchings/CMiniGame1Res", func_001C3960);
