#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" void func_0012DC10(void *p);
class CEnvResObj {
public:
    static CEnvResObj *Create();
};
// @decl-end

INCLUDE_ASM("asm/nonmatchings/CEnvResObj", __10CEnvResObj);

INCLUDE_ASM("asm/nonmatchings/CEnvResObj", func_0012D910);

INCLUDE_ASM("asm/nonmatchings/CEnvResObj", func_0012D9A0);

INCLUDE_ASM("asm/nonmatchings/CEnvResObj", func_0012DB68);

CEnvResObj *CEnvResObj::Create() {
    CEnvResObj *p = (CEnvResObj *)operator new(0x140);
    func_0012DC10(p);
    return p;
}

INCLUDE_ASM("asm/nonmatchings/CEnvResObj", func_0012DC10);
