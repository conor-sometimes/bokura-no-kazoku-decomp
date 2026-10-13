#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern void *D_002A0BE0;

class CSndWorkReal {
public:
    void CallFunc129458(const char *s);
    void Func129458(const char *s);
    int IsUnkA4Set();
    void SetUnkA8(s32 v);

    u8 pad0[0xA0];
    s32 m_unkA0;              // 0xA0
    s32 m_unkA4;              // 0xA4
    s32 m_unkA8;              // 0xA8
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_00128870);

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_00128BB0);

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_00128E78);

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_00128ED0);

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_00128F10);

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_00128FD0);

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_00129020);

void CSndWorkReal::CallFunc129458(const char *s) {
    if (s[0]) {
        Func129458(s);
    }
}

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_001291B8);

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_00129250);

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_001292A8);

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_001292E0);

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", Func129458__12CSndWorkRealPCc);

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_00129548);

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_001295E8);

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_001296B8);

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_001296F0);

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_00129848);

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_001298B0);

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_00129900);

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_00129AE0);

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_00129C70);

int CSndWorkReal::IsUnkA4Set() {
    return m_unkA0 != 0 && m_unkA4 != 0;
}

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_00129CC8);

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_00129D90);

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_00129E28);

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_00129E68);

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_00129EB0);

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_0012A0F0);

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_0012A2F0);

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_0012A340);

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_0012A420);

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_0012A510);

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_0012A610);

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_0012A6B0);

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_0012AB18);

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_0012AF50);

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_0012AFA8);

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_0012B180);

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_0012C3E0);

void SetSndWorkRealInstance(void *p) {
    D_002A0BE0 = p;
}

void *GetSndWorkRealInstance() {
    return D_002A0BE0;
}

void CSndWorkReal::SetUnkA8(s32 v) {
    m_unkA8 = v;
}

INCLUDE_ASM("asm/nonmatchings/CSndWorkReal", func_0012C458);
