#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "linkonce.h"
extern "C" {
extern TypeInfo D_2EB830;
extern const char D_002D8920[];
extern TypeInfo D_4248F0;
TypeInfo *__tf8CProcess();
extern const char D_002D8C98[];
extern TypeInfo D_424E70;
extern TypeInfo D_424900;
extern const char D_002D8E90[];
extern TypeInfo D_424910;
extern const char D_002D8F08[];
extern TypeInfo D_424930;
TypeInfo *func_00299CB0();
extern const char D_002D9528[];
extern TypeInfo D_424920;
extern TypeInfo D_424940;
TypeInfo *__tf5CList();
extern const char D_002D9540[];
extern TypeInfo D_424660;
extern TypeInfo D_424950;
extern const char D_002D9560[];
TypeInfo *__tf8CListTag();
extern const char D_002D9570[];
extern TypeInfo D_2EB708;
extern TypeInfo D_424960;
TypeInfo *__tf9CEventObj();
extern const char D_002D98E8[];
extern TypeInfo D_2EB800;
extern TypeInfo D_424970;
extern const char D_002D9AC0[];
extern TypeInfo D_424990;
TypeInfo *__tf5CTask();
extern const char D_002D9C00[];
extern TypeInfo D_2EB8B8;
extern TypeInfo D_4249A0;
TypeInfo *func_00295D00();
extern const char D_002D9C10[];
extern TypeInfo D_424700;
extern TypeInfo D_424980;
TypeInfo *__tf10IInterfMgr();
extern const char D_002D9C20[];
extern TypeInfo D_4249B0;
TypeInfo *func_0029A028();
extern const char D_002D9CF0[];
extern TypeInfo D_2EB838;
extern const char D_002D9D00[];
extern TypeInfo D_4249C0;
extern const char D_002D9E90[];
extern TypeInfo D_4249E0;
extern const char D_002D9EA0[];
extern TypeInfo D_4249D0;
TypeInfo *__tf9IAlbumMgr();
extern const char D_002D9EB8[];
extern TypeInfo D_4249F0;
TypeInfo *func_0029A328();
extern const char D_002DA038[];
extern TypeInfo D_2EB840;
extern const char D_002DA048[];
extern TypeInfo D_424A00;
TypeInfo *func_0029A438();
extern const char D_002DA1E0[];
extern TypeInfo D_2EB848;
extern const char D_002DA1F0[];
}
struct VDel_299FF0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual ~VDel_299FF0(); };
struct VDel_29A2A8 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual ~VDel_29A2A8(); };
struct VDel_29A3B8 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual ~VDel_29A3B8(); };
// @decl-end

extern "C" s32 func_00299948(void *p) { return FLD(s32, p, 0x23C); }

extern "C" TypeInfo *func_00299950()
{
    if (!D_2EB830.vptr) func_00286BE0(&D_2EB830, D_002D8920);
    return &D_2EB830;
}

extern "C" TypeInfo *__tf9CGameMain()
{
    if (!D_4248F0.vptr) {
        __tf8CProcess();
        func_00286BC0(&D_4248F0, D_002D8C98, &D_424E70);
    }
    return &D_4248F0;
}

extern "C" void func_002999E0(void *p, s32 v) { FLD(s32, p, 0x13C) = v; }

extern "C" s32 func_002999E8(void *p) { return FLD(s32, p, 0x13C); }

extern "C" void func_002999F0(void *p, s32 v) { FLD(s32, p, 0x140) = v; }

extern "C" s32 func_002999F8(void *p) { return FLD(s32, p, 0x140); }

extern "C" s32 func_00299A00(void *p) { return FLD(s32, p, 0x4C4); }

extern "C" void *func_00299A08(void *p) { return (u8 *)p + 0xC8; }

extern "C" TypeInfo *__tf15CGameSeasonPrev()
{
    if (!D_424900.vptr) {
        __tf8CProcess();
        func_00286BC0(&D_424900, D_002D8E90, &D_424E70);
    }
    return &D_424900;
}

extern "C" TypeInfo *__tf15CGameSeasonPost()
{
    if (!D_424910.vptr) {
        __tf8CProcess();
        func_00286BC0(&D_424910, D_002D8F08, &D_424E70);
    }
    return &D_424910;
}

INCLUDE_ASM("asm/nonmatchings/Lib299948", func_00299AB0);

extern "C" TypeInfo *__tf17CGameScheduleUnit()
{
    if (!D_424930.vptr) {
        func_00299CB0();
        func_00286BC0(&D_424930, D_002D9528, &D_424920);
    }
    return &D_424930;
}

INCLUDE_ASM("asm/nonmatchings/Lib299948", func_00299B60);

extern "C" TypeInfo *__tft5TList1Z17CGameScheduleUnit()
{
    if (!D_424940.vptr) {
        __tf5CList();
        func_00286BC0(&D_424940, D_002D9540, &D_424660);
    }
    return &D_424940;
}

extern "C" TypeInfo *__tf13CGameSchedule()
{
    if (!D_424950.vptr) {
        __tf8CProcess();
        func_00286BC0(&D_424950, D_002D9560, &D_424E70);
    }
    return &D_424950;
}

extern "C" TypeInfo *func_00299CB0()
{
    if (!D_424920.vptr) {
        __tf8CListTag();
        func_00286BC0(&D_424920, D_002D9570, &D_2EB708);
    }
    return &D_424920;
}

extern "C" TypeInfo *__tf13CGameEventObj()
{
    if (!D_424960.vptr) {
        __tf9CEventObj();
        func_00286BC0(&D_424960, D_002D98E8, &D_2EB800);
    }
    return &D_424960;
}

extern "C" TypeInfo *__tf11CGameResort()
{
    if (!D_424970.vptr) {
        __tf8CProcess();
        func_00286BC0(&D_424970, D_002D9AC0, &D_424E70);
    }
    return &D_424970;
}

INCLUDE_ASM("asm/nonmatchings/Lib299948", func_00299DA0);

extern "C" TypeInfo *__tf10IInterfMgr()
{
    if (!D_424990.vptr) {
        __tf5CTask();
        func_00286BC0(&D_424990, D_002D9C00, &D_2EB8B8);
    }
    return &D_424990;
}

extern "C" TypeInfo *__tf10CInterfRes()
{
    if (!D_4249A0.vptr) {
        func_00295D00();
        func_00286BC0(&D_4249A0, D_002D9C10, &D_424700);
    }
    return &D_4249A0;
}

extern "C" TypeInfo *__tf10CInterfMgr()
{
    if (!D_424980.vptr) {
        __tf10IInterfMgr();
        func_00286BC0(&D_424980, D_002D9C20, &D_424990);
    }
    return &D_424980;
}

INCLUDE_ASM("asm/nonmatchings/Lib299948", func_00299EF8);

extern "C" s32 func_00299F28(void *p) { return FLD(s32, p, 0xC0); }

INCLUDE_ASM("asm/nonmatchings/Lib299948", func_00299F30);

extern "C" f32 func_00299F68(void *p) { return FLD(f32, p, 0x918); }

extern "C" void func_00299F70(void *p, s32 v) { FLD(s32, p, 0x920) = v; }

INCLUDE_ASM("asm/nonmatchings/Lib299948", func_00299F78);

extern "C" s32 func_00299F88(void *p) { return FLD(s32, p, 0x8EC); }

extern "C" s32 func_00299F90(void *p) { return FLD(s32, p, 0xDE0); }

extern "C" s32 func_00299F98(void *p) { return FLD(s32, p, 0xDE4); }

extern "C" TypeInfo *__tf10CNameDBMgr()
{
    if (!D_4249B0.vptr) {
        func_0029A028();
        func_00286BC0(&D_4249B0, D_002D9CF0, &D_2EB838);
    }
    return &D_4249B0;
}

extern "C" void func_00299FF0(VDel_299FF0 *p) { delete p; }

extern "C" TypeInfo *func_0029A028()
{
    if (!D_2EB838.vptr) func_00286BE0(&D_2EB838, D_002D9D00);
    return &D_2EB838;
}

INCLUDE_ASM("asm/nonmatchings/Lib299948", func_0029A068);

extern "C" TypeInfo *__tf9IAlbumMgr()
{
    if (!D_4249C0.vptr) {
        __tf5CTask();
        func_00286BC0(&D_4249C0, D_002D9E90, &D_2EB8B8);
    }
    return &D_4249C0;
}

INCLUDE_ASM("asm/nonmatchings/Lib299948", func_0029A120);

extern "C" TypeInfo *__tf14CPhotoEventObj()
{
    if (!D_4249E0.vptr) {
        __tf9CEventObj();
        func_00286BC0(&D_4249E0, D_002D9EA0, &D_2EB800);
    }
    return &D_4249E0;
}

extern "C" TypeInfo *__tf9CAlbumMgr()
{
    if (!D_4249D0.vptr) {
        __tf9IAlbumMgr();
        func_00286BC0(&D_4249D0, D_002D9EB8, &D_4249C0);
    }
    return &D_4249D0;
}

INCLUDE_ASM("asm/nonmatchings/Lib299948", func_0029A230);

extern "C" s32 func_0029A248(void *p) { return FLD(s32, p, 0x20C); }

extern "C" void func_0029A250(void *p, s32 v) { FLD(s32, p, 0xD8) = v; }

extern "C" TypeInfo *__tf11CPhotoDBMgr()
{
    if (!D_4249F0.vptr) {
        func_0029A328();
        func_00286BC0(&D_4249F0, D_002DA038, &D_2EB840);
    }
    return &D_4249F0;
}

extern "C" void Release__11CPhotoDBMgr(VDel_29A2A8 *p) { delete p; }

extern "C" s32 Func29A2E0__11CPhotoDBMgr(void *p) { return FLD(s32, p, 0x1C); }

INCLUDE_ASM("asm/nonmatchings/Lib299948", Func29A2E8__11CPhotoDBMgr);

extern "C" s32 Func29A320__11CPhotoDBMgr(void *p) { return FLD(s32, p, 0x20); }

extern "C" TypeInfo *func_0029A328()
{
    if (!D_2EB840.vptr) func_00286BE0(&D_2EB840, D_002DA048);
    return &D_2EB840;
}

extern "C" TypeInfo *__tf12CResortDBMgr()
{
    if (!D_424A00.vptr) {
        func_0029A438();
        func_00286BC0(&D_424A00, D_002DA1E0, &D_2EB848);
    }
    return &D_424A00;
}

extern "C" void func_0029A3B8(VDel_29A3B8 *p) { delete p; }

INCLUDE_ASM("asm/nonmatchings/Lib299948", func_0029A3F0);

extern "C" s32 func_0029A430(void *p) { return FLD(s32, p, 0x14); }

extern "C" TypeInfo *func_0029A438()
{
    if (!D_2EB848.vptr) func_00286BE0(&D_2EB848, D_002DA1F0);
    return &D_2EB848;
}

INCLUDE_ASM("asm/nonmatchings/Lib299948", func_0029A478);

INCLUDE_ASM("asm/nonmatchings/Lib299948", func_0029A4A0);

extern "C" s32 func_0029A4F8(void *p) { return FLD(s32, p, 0xC); }

INCLUDE_ASM("asm/nonmatchings/Lib299948", func_0029A500);

INCLUDE_ASM("asm/nonmatchings/Lib299948", func_0029A518);

INCLUDE_ASM("asm/nonmatchings/Lib299948", Func29A558__10CUnk29A558i);
