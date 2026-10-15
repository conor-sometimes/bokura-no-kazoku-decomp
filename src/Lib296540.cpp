#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "linkonce.h"
extern "C" {
extern TypeInfo D_2EB7D0;
extern const char D_002D4E48[];
extern TypeInfo D_2EB7C8;
extern const char D_002D4E88[];
extern TypeInfo D_2EB7D8;
extern const char D_002D4EC8[];
extern TypeInfo D_4247D0;
TypeInfo *__tf9CResCache();
extern const char D_002D4F40[];
extern TypeInfo D_2EB8C0;
extern TypeInfo D_4247C0;
TypeInfo *func_00295D00();
extern const char D_002D4F50[];
extern TypeInfo D_424700;
extern TypeInfo D_4247B0;
TypeInfo *__tf12ICharaResMgr();
extern const char D_002D4F60[];
extern TypeInfo D_424800;
extern const char D_002D5010[];
extern TypeInfo D_4247E0;
extern const char D_002D5020[];
extern TypeInfo D_4247F0;
TypeInfo *__tf10IMapResMgr();
extern const char D_002D5030[];
extern TypeInfo D_424820;
extern const char D_002D5130[];
extern TypeInfo D_424830;
extern const char D_002D5140[];
extern TypeInfo D_424810;
TypeInfo *__tf10IEnvResMgr();
extern const char D_002D5150[];
}
struct VDel_297208 { u8 pad[0x13c]; virtual ~VDel_297208(); };
struct VDel_297448 { u8 pad[0x13c]; virtual ~VDel_297448(); };
// @decl-end

extern "C" void func_00296540(void *p, f32 v) { FLD(f32, p, 0x54) = v; }

extern "C" f32 func_00296548(void *p) { return FLD(f32, p, 0x54); }

extern "C" void func_00296550(void *p, f32 v) { FLD(f32, p, 0x98) = v; }

extern "C" f32 func_00296558(void *p) { return FLD(f32, p, 0x98); }

extern "C" void func_00296560(void *p, s32 v) { FLD(s32, p, 0x9C) = v; }

extern "C" s32 func_00296568(void *p) { return FLD(s32, p, 0xC); }

extern "C" s32 Func296570__7CDkList(void *p) { return FLD(s32, p, 0xC); }

INCLUDE_ASM("asm/nonmatchings/Lib296540", func_00296578);

INCLUDE_ASM("asm/nonmatchings/Lib296540", func_002965A0);

INCLUDE_ASM("asm/nonmatchings/Lib296540", func_002965F8);

INCLUDE_ASM("asm/nonmatchings/Lib296540", func_00296620);

INCLUDE_ASM("asm/nonmatchings/Lib296540", func_00296678);

INCLUDE_ASM("asm/nonmatchings/Lib296540", func_00296698);

INCLUDE_ASM("asm/nonmatchings/Lib296540", func_002966B0);

INCLUDE_ASM("asm/nonmatchings/Lib296540", func_002966D0);

INCLUDE_ASM("asm/nonmatchings/Lib296540", func_002966E8);

INCLUDE_ASM("asm/nonmatchings/Lib296540", func_00296700);

INCLUDE_ASM("asm/nonmatchings/Lib296540", func_002968E0);

INCLUDE_ASM("asm/nonmatchings/Lib296540", func_00296900);

INCLUDE_ASM("asm/nonmatchings/Lib296540", func_00296AC0);

INCLUDE_ASM("asm/nonmatchings/Lib296540", func_00296AD8);

INCLUDE_ASM("asm/nonmatchings/Lib296540", func_00296AF0);

INCLUDE_ASM("asm/nonmatchings/Lib296540", func_00296B28);

INCLUDE_ASM("asm/nonmatchings/Lib296540", func_00296B58);

INCLUDE_ASM("asm/nonmatchings/Lib296540", func_00296BC0);

INCLUDE_ASM("asm/nonmatchings/Lib296540", func_00296C18);

INCLUDE_ASM("asm/nonmatchings/Lib296540", func_00296C60);

INCLUDE_ASM("asm/nonmatchings/Lib296540", func_00296C90);

INCLUDE_ASM("asm/nonmatchings/Lib296540", func_00296CC0);

INCLUDE_ASM("asm/nonmatchings/Lib296540", func_00296D28);

INCLUDE_ASM("asm/nonmatchings/Lib296540", func_00296D80);

INCLUDE_ASM("asm/nonmatchings/Lib296540", func_00296DC0);

extern "C" void func_00296E98(void) {
}

INCLUDE_ASM("asm/nonmatchings/Lib296540", func_00296EA0);

extern "C" void func_00296F00(void) {
}

extern "C" TypeInfo *__tft6TArray3Z12CSceneMapSeti_16_Zt10TAllocator1Z12CSceneMapSet()
{
    if (!D_2EB7D0.vptr) func_00286BE0(&D_2EB7D0, D_002D4E48);
    return &D_2EB7D0;
}

extern "C" TypeInfo *__tft6TArray3Z14CSceneCharaSeti_16_Zt10TAllocator1Z14CSceneCharaSet()
{
    if (!D_2EB7C8.vptr) func_00286BE0(&D_2EB7C8, D_002D4E88);
    return &D_2EB7C8;
}

extern "C" TypeInfo *__tf9CSceneSet()
{
    if (!D_2EB7D8.vptr) func_00286BE0(&D_2EB7D8, D_002D4EC8);
    return &D_2EB7D8;
}

INCLUDE_ASM("asm/nonmatchings/Lib296540", func_00296FC8);

INCLUDE_ASM("asm/nonmatchings/Lib296540", func_00296FE0);

extern "C" void func_00296FF8(void *p, s32 v) { FLD(s32, p, 0x38) = v; }

INCLUDE_ASM("asm/nonmatchings/Lib296540", func_00297000);

extern "C" TypeInfo *__tf12ICharaResMgr()
{
    if (!D_4247D0.vptr) {
        __tf9CResCache();
        func_00286BC0(&D_4247D0, D_002D4F40, &D_2EB8C0);
    }
    return &D_4247D0;
}

INCLUDE_ASM("asm/nonmatchings/Lib296540", func_002970B8);

extern "C" TypeInfo *__tf12CCharaResObj()
{
    if (!D_4247C0.vptr) {
        func_00295D00();
        func_00286BC0(&D_4247C0, D_002D4F50, &D_424700);
    }
    return &D_4247C0;
}

INCLUDE_ASM("asm/nonmatchings/Lib296540", func_002971A0);

extern "C" TypeInfo *__tf12CCharaResMgr()
{
    if (!D_4247B0.vptr) {
        __tf12ICharaResMgr();
        func_00286BC0(&D_4247B0, D_002D4F60, &D_4247D0);
    }
    return &D_4247B0;
}

extern "C" void func_00297208(VDel_297208 *p) { delete p; }

INCLUDE_ASM("asm/nonmatchings/Lib296540", func_00297240);

extern "C" TypeInfo *__tf10IMapResMgr()
{
    if (!D_424800.vptr) {
        __tf9CResCache();
        func_00286BC0(&D_424800, D_002D5010, &D_2EB8C0);
    }
    return &D_424800;
}

INCLUDE_ASM("asm/nonmatchings/Lib296540", func_002972F8);

extern "C" TypeInfo *__tf10CMapResObj()
{
    if (!D_4247E0.vptr) {
        func_00295D00();
        func_00286BC0(&D_4247E0, D_002D5020, &D_424700);
    }
    return &D_4247E0;
}

INCLUDE_ASM("asm/nonmatchings/Lib296540", func_002973E0);

extern "C" TypeInfo *__tf10CMapResMgr()
{
    if (!D_4247F0.vptr) {
        __tf10IMapResMgr();
        func_00286BC0(&D_4247F0, D_002D5030, &D_424800);
    }
    return &D_4247F0;
}

extern "C" void func_00297448(VDel_297448 *p) { delete p; }

INCLUDE_ASM("asm/nonmatchings/Lib296540", func_00297480);

extern "C" TypeInfo *__tf10IEnvResMgr()
{
    if (!D_424820.vptr) {
        __tf9CResCache();
        func_00286BC0(&D_424820, D_002D5130, &D_2EB8C0);
    }
    return &D_424820;
}

extern "C" TypeInfo *__tf10CEnvResObj()
{
    if (!D_424830.vptr) {
        func_00295D00();
        func_00286BC0(&D_424830, D_002D5140, &D_424700);
    }
    return &D_424830;
}

INCLUDE_ASM("asm/nonmatchings/Lib296540", func_00297588);

extern "C" TypeInfo *__tf10CEnvResMgr()
{
    if (!D_424810.vptr) {
        __tf10IEnvResMgr();
        func_00286BC0(&D_424810, D_002D5150, &D_424820);
    }
    return &D_424810;
}
