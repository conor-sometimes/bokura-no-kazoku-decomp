#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CProcess.h"
class CTaskList24F5C0 {
public:
    s32 Func24F5C0(void *task, s32 pri);
};
// CSnapMgr (another lane's unit; constructor through config/aliases.ld).
class CSnapMgr : public CTask {
public:
    CSnapMgr();

    u8 pad8[0x30];
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/IFadeMgr", func_0010B108);

INCLUDE_ASM("asm/nonmatchings/IFadeMgr", func_0010B180);

INCLUDE_ASM("asm/nonmatchings/IFadeMgr", func_0010B2D8);

INCLUDE_ASM("asm/nonmatchings/IFadeMgr", func_0010B350);

s32 AddSnapMgr(CTaskList24F5C0 *list) {
    CSnapMgr *p = new CSnapMgr;
    return list->Func24F5C0(p, 0);
}
