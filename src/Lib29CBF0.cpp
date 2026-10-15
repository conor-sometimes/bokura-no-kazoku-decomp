#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "linkonce.h"
extern "C" {
extern TypeInfo D_424E10;
TypeInfo *__tf8CProcess();
extern const char D_002E1F48[];
extern TypeInfo D_424E70;
extern TypeInfo D_2EB8A0;
extern const char D_002E5F50[];
extern TypeInfo D_424E20;
TypeInfo *func_0029CD10();
extern const char D_002E5F60[];
extern TypeInfo D_2EB898;
extern const char D_002E5F68[];
extern TypeInfo D_2EB8A8;
extern const char D_002E6478[];
extern TypeInfo D_2EB8B0;
extern const char D_002E6848[];
extern TypeInfo D_2EB8B8;
extern const char D_002E6870[];
extern TypeInfo D_424E30;
TypeInfo *__tf5CList();
extern const char D_002E6878[];
extern TypeInfo D_424660;
extern TypeInfo D_424E60;
TypeInfo *func_0029D0F0();
extern const char D_002E6890[];
extern TypeInfo D_424E40;
extern TypeInfo D_424E50;
TypeInfo *__tf5CTask();
extern const char D_002E68A0[];
TypeInfo *__tf8CListTag();
extern const char D_002E68B0[];
extern TypeInfo D_2EB708;
extern const char D_002E68D8[];
extern TypeInfo D_424E80;
extern const char D_002E69F0[];
extern TypeInfo D_2EB8C0;
extern const char D_002E6A10[];
extern TypeInfo D_424E90;
TypeInfo *func_0029D478();
extern const char D_002E6A20[];
extern TypeInfo D_424EA0;
extern const char D_002E6A30[];
extern TypeInfo D_424EB0;
TypeInfo *func_0029D570();
extern const char D_002E6AF8[];
extern TypeInfo D_2EB8C8;
extern const char D_002E6B08[];
extern TypeInfo D_2EB8D0;
extern const char D_002E6B50[];
extern TypeInfo D_424EC0;
TypeInfo *func_0029D690();
extern const char D_002E6ED8[];
extern TypeInfo D_2EB8D8;
extern const char D_002E6EE8[];
}
struct VDel_29CCD8 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual ~VDel_29CCD8(); };
struct VDel_29D518 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual ~VDel_29D518(); };
struct VDel_29D640 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual ~VDel_29D640(); };
// @decl-end

extern "C" TypeInfo *__tf8CAppMain()
{
    if (!D_424E10.vptr) {
        __tf8CProcess();
        func_00286BC0(&D_424E10, D_002E1F48, &D_424E70);
    }
    return &D_424E10;
}

extern "C" TypeInfo *__tf7CBgWork()
{
    if (!D_2EB8A0.vptr) func_00286BE0(&D_2EB8A0, D_002E5F50);
    return &D_2EB8A0;
}

extern "C" s32 func_0029CC80(void *p) { return FLD(s32, p, 0x4); }

extern "C" TypeInfo *__tf6CBgMgr()
{
    if (!D_424E20.vptr) {
        func_0029CD10();
        func_00286BC0(&D_424E20, D_002E5F60, &D_2EB898);
    }
    return &D_424E20;
}

extern "C" void func_0029CCD8(VDel_29CCD8 *p) { delete p; }

extern "C" TypeInfo *func_0029CD10()
{
    if (!D_2EB898.vptr) func_00286BE0(&D_2EB898, D_002E5F68);
    return &D_2EB898;
}

extern "C" TypeInfo *__tf8CPushBuf()
{
    if (!D_2EB8A8.vptr) func_00286BE0(&D_2EB8A8, D_002E6478);
    return &D_2EB8A8;
}

extern "C" s32 func_0029CD90(void *p) { return FLD(s32, p, 0x4); }

extern "C" TypeInfo *__tf5CExpr()
{
    if (!D_2EB8B0.vptr) func_00286BE0(&D_2EB8B0, D_002E6848);
    return &D_2EB8B0;
}

extern "C" TypeInfo *__tf5CTask()
{
    if (!D_2EB8B8.vptr) func_00286BE0(&D_2EB8B8, D_002E6870);
    return &D_2EB8B8;
}

INCLUDE_ASM("asm/nonmatchings/Lib29CBF0", func_0029CE18);

extern "C" TypeInfo *__tft5TList1Z8CTaskTag()
{
    if (!D_424E30.vptr) {
        __tf5CList();
        func_00286BC0(&D_424E30, D_002E6878, &D_424660);
    }
    return &D_424E30;
}

extern "C" TypeInfo *__tf8CTaskTag()
{
    if (!D_424E60.vptr) {
        func_0029D0F0();
        func_00286BC0(&D_424E60, D_002E6890, &D_424E40);
    }
    return &D_424E60;
}

extern "C" s32 func_0029CF68(void *p) { return FLD(s32, p, 0x10); }

extern "C" s32 func_0029CF70(void *p) { return FLD(s32, p, 0x14); }

INCLUDE_ASM("asm/nonmatchings/Lib29CBF0", func_0029CF78);

INCLUDE_ASM("asm/nonmatchings/Lib29CBF0", func_0029CF88);

extern "C" void func_0029CF98(void *p, s32 v) { FLD(s32, p, 0x14) = v; }

INCLUDE_ASM("asm/nonmatchings/Lib29CBF0", func_0029CFA0);

INCLUDE_ASM("asm/nonmatchings/Lib29CBF0", func_0029CFE8);

INCLUDE_ASM("asm/nonmatchings/Lib29CBF0", func_0029D018);

INCLUDE_ASM("asm/nonmatchings/Lib29CBF0", func_0029D038);

extern "C" TypeInfo *__tf9CRootTask()
{
    if (!D_424E50.vptr) {
        __tf5CTask();
        func_00286BC0(&D_424E50, D_002E68A0, &D_2EB8B8);
    }
    return &D_424E50;
}

extern "C" TypeInfo *func_0029D0F0()
{
    if (!D_424E40.vptr) {
        __tf8CListTag();
        func_00286BC0(&D_424E40, D_002E68B0, &D_2EB708);
    }
    return &D_424E40;
}

extern "C" TypeInfo *__tf8CProcess()
{
    if (!D_424E70.vptr) {
        __tf5CTask();
        func_00286BC0(&D_424E70, D_002E68D8, &D_2EB8B8);
    }
    return &D_424E70;
}

extern "C" s32 func_0029D190(void *p) { return FLD(s32, p, 0xC); }

INCLUDE_ASM("asm/nonmatchings/Lib29CBF0", func_0029D198);

extern "C" TypeInfo *__tft5TList1Z13CResCacheUnit()
{
    if (!D_424E80.vptr) {
        __tf5CList();
        func_00286BC0(&D_424E80, D_002E69F0, &D_424660);
    }
    return &D_424E80;
}

extern "C" TypeInfo *__tf9CResCache()
{
    if (!D_2EB8C0.vptr) func_00286BE0(&D_2EB8C0, D_002E6A10);
    return &D_2EB8C0;
}

INCLUDE_ASM("asm/nonmatchings/Lib29CBF0", func_0029D2D8);

INCLUDE_ASM("asm/nonmatchings/Lib29CBF0", func_0029D2E8);

extern "C" s32 func_0029D300(void *p) { return FLD(s32, p, 0x4); }

INCLUDE_ASM("asm/nonmatchings/Lib29CBF0", func_0029D308);

INCLUDE_ASM("asm/nonmatchings/Lib29CBF0", func_0029D340);

extern "C" s32 func_0029D378(void *p) { return FLD(s32, p, 0x8); }

INCLUDE_ASM("asm/nonmatchings/Lib29CBF0", func_0029D380);

extern "C" void *func_0029D3A0(void *p) { return (u8 *)p + 0x3C; }

extern "C" TypeInfo *__tf13CResCacheUnit()
{
    if (!D_424E90.vptr) {
        func_0029D478();
        func_00286BC0(&D_424E90, D_002E6A20, &D_424EA0);
    }
    return &D_424E90;
}

INCLUDE_ASM("asm/nonmatchings/Lib29CBF0", func_0029D3F8);

extern "C" void *func_0029D410(void *p) { return (u8 *)p + 0x30; }

extern "C" s32 func_0029D418(void *p) { return FLD(s32, p, 0x50); }

extern "C" s32 func_0029D420(void *p) { return FLD(s32, p, 0x1C); }

INCLUDE_ASM("asm/nonmatchings/Lib29CBF0", func_0029D428);

INCLUDE_ASM("asm/nonmatchings/Lib29CBF0", func_0029D438);

extern "C" void func_0029D450(void *p, s32 v) { FLD(s32, p, 0x58) = v; }

extern "C" s32 func_0029D458(void *p) { return FLD(s32, p, 0x58); }

INCLUDE_ASM("asm/nonmatchings/Lib29CBF0", func_0029D460);

extern "C" TypeInfo *func_0029D478()
{
    if (!D_424EA0.vptr) {
        __tf8CListTag();
        func_00286BC0(&D_424EA0, D_002E6A30, &D_2EB708);
    }
    return &D_424EA0;
}

extern "C" TypeInfo *__tf7CDebOut()
{
    if (!D_424EB0.vptr) {
        func_0029D570();
        func_00286BC0(&D_424EB0, D_002E6AF8, &D_2EB8C8);
    }
    return &D_424EB0;
}

extern "C" void func_0029D518(VDel_29D518 *p) { delete p; }

INCLUDE_ASM("asm/nonmatchings/Lib29CBF0", func_0029D550);

INCLUDE_ASM("asm/nonmatchings/Lib29CBF0", func_0029D560);

extern "C" TypeInfo *func_0029D570()
{
    if (!D_2EB8C8.vptr) func_00286BE0(&D_2EB8C8, D_002E6B08);
    return &D_2EB8C8;
}

extern "C" TypeInfo *__tf11CBoneDupMap()
{
    if (!D_2EB8D0.vptr) func_00286BE0(&D_2EB8D0, D_002E6B50);
    return &D_2EB8D0;
}

extern "C" TypeInfo *__tf9CShareTex()
{
    if (!D_424EC0.vptr) {
        func_0029D690();
        func_00286BC0(&D_424EC0, D_002E6ED8, &D_2EB8D8);
    }
    return &D_424EC0;
}

extern "C" void func_0029D640(VDel_29D640 *p) { delete p; }

extern "C" s32 func_0029D678(void *p) { return FLD(s32, p, 0x4); }

INCLUDE_ASM("asm/nonmatchings/Lib29CBF0", func_0029D680);

INCLUDE_ASM("asm/nonmatchings/Lib29CBF0", func_0029D688);

extern "C" TypeInfo *func_0029D690()
{
    if (!D_2EB8D8.vptr) func_00286BE0(&D_2EB8D8, D_002E6EE8);
    return &D_2EB8D8;
}
