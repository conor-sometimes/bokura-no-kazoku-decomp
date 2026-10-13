#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
class CFaceResSub10F938 {
public:
    s32 GetFirst();

    u8 pad0[0x10];
    s32* m_list;              // 0x10
    s32 m_count;              // 0x14
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CFaceRes", func_0010E4F0);

INCLUDE_ASM("asm/nonmatchings/CFaceRes", func_0010E580);

INCLUDE_ASM("asm/nonmatchings/CFaceRes", func_0010E5E0);

INCLUDE_ASM("asm/nonmatchings/CFaceRes", func_0010E7A8);

INCLUDE_ASM("asm/nonmatchings/CFaceRes", func_0010E8D0);

INCLUDE_ASM("asm/nonmatchings/CFaceRes", func_0010E970);

INCLUDE_ASM("asm/nonmatchings/CFaceRes", func_0010EC18);

INCLUDE_ASM("asm/nonmatchings/CFaceRes", func_0010ED30);

INCLUDE_ASM("asm/nonmatchings/CFaceRes", func_0010EF78);

INCLUDE_ASM("asm/nonmatchings/CFaceRes", func_0010F068);

INCLUDE_ASM("asm/nonmatchings/CFaceRes", func_0010F348);

INCLUDE_ASM("asm/nonmatchings/CFaceRes", func_0010F580);

INCLUDE_ASM("asm/nonmatchings/CFaceRes", func_0010F6F8);

INCLUDE_ASM("asm/nonmatchings/CFaceRes", func_0010F8F0);

s32 CFaceResSub10F938::GetFirst() {
    return m_count > 0 ? m_list[0] : -1;
}

INCLUDE_ASM("asm/nonmatchings/CFaceRes", func_0010F958);

INCLUDE_ASM("asm/nonmatchings/CFaceRes", func_0010F9B8);

INCLUDE_ASM("asm/nonmatchings/CFaceRes", func_0010FA10);
