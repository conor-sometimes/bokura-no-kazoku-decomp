#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "linkonce.h"
extern "C" {
extern TypeInfo D_424F30;
TypeInfo *func_0029E0A8();
extern const char D_002E77C8[];
extern TypeInfo D_424F10;
extern TypeInfo D_424F40;
TypeInfo *func_0029E0F8();
extern const char D_002E77D8[];
extern TypeInfo D_424F60;
TypeInfo *__tf8CListTag();
extern const char D_002E77E8[];
extern TypeInfo D_2EB708;
extern const char D_002E7800[];
extern TypeInfo D_424F70;
TypeInfo *__tf8CSndWork();
extern const char D_002E7818[];
extern TypeInfo D_424F80;
TypeInfo *__tf8CSndUnit();
extern const char D_002E7880[];
extern TypeInfo D_424F90;
TypeInfo *__tf10CSndUnitTg();
extern const char D_002E7890[];
extern TypeInfo D_424FB0;
extern const char D_002E7908[];
extern TypeInfo D_424FA0;
TypeInfo *__tf11CSndUnitSeq();
extern const char D_002E7918[];
extern TypeInfo D_424FC0;
extern const char D_002E79A8[];
extern TypeInfo D_424FD0;
TypeInfo *__tf11CSndUnitStr();
extern const char D_002E79B8[];
extern TypeInfo D_2EB910;
extern const char D_002EAC70[];
extern TypeInfo D_4253F0;
TypeInfo *__tf9exception();
extern const char D_002EAC80[];
extern TypeInfo D_2EB918;
extern TypeInfo D_4253E0;
extern const char D_002EAC90[];
extern TypeInfo D_425400;
TypeInfo *__tf9type_info();
extern const char D_002EACA0[];
}

#include "linkonce.h"
extern "C" {
extern char _vt$12CSndWorkReal[];
void func_0025C2C0(void *, s32);
extern char _vt$16__user_type_info[];
void func_00286B20(void *, s32);
}
// @decl-end

extern "C" TypeInfo *__tf8CSndWork()
{
    if (!D_424F30.vptr) {
        func_0029E0A8();
        func_00286BC0(&D_424F30, D_002E77C8, &D_424F10);
    }
    return &D_424F30;
}

extern "C" s32 func_0029DEB8(void *p) { return FLD(s32, p, 0x10); }

INCLUDE_ASM("asm/nonmatchings/Lib29DE68", func_0029DEC0);

INCLUDE_ASM("asm/nonmatchings/Lib29DE68", func_0029DEF8);

INCLUDE_ASM("asm/nonmatchings/Lib29DE68", func_0029DF48);

extern "C" void func_0029DF80(void *p, s32 a) { FLD(u8, p, 0x36) = a; FLD(u8, p, 0x34) = 1; }

INCLUDE_ASM("asm/nonmatchings/Lib29DE68", func_0029DF90);

INCLUDE_ASM("asm/nonmatchings/Lib29DE68", func_0029DFC0);

INCLUDE_ASM("asm/nonmatchings/Lib29DE68", func_0029DFE8);

extern "C" void func_0029E000(void *p, f32 a) { FLD(f32, p, 0x4C) = a; FLD(u8, p, 0x34) = 1; }

extern "C" void func_0029E010(void *p, s32 a, s32 b) { FLD(s16, p, 0x3C) = a; FLD(s16, p, 0x3E) = b; FLD(u8, p, 0x34) = 1; }

extern "C" s32 func_0029E028(void) { return 0; }

extern "C" TypeInfo *__tf8CSndUnit()
{
    if (!D_424F40.vptr) {
        func_0029E0F8();
        func_00286BC0(&D_424F40, D_002E77D8, &D_424F60);
    }
    return &D_424F40;
}

extern "C" s32 func_0029E080(void *p) { return FLD(s32, p, 0x54) & 4 ? 2 : 1; }

extern "C" void func_0029E098(void) {
}

extern "C" s32 func_0029E0A0(void) { return 0; }

extern "C" TypeInfo *func_0029E0A8()
{
    if (!D_424F10.vptr) {
        __tf8CListTag();
        func_00286BC0(&D_424F10, D_002E77E8, &D_2EB708);
    }
    return &D_424F10;
}

extern "C" TypeInfo *func_0029E0F8()
{
    if (!D_424F60.vptr) {
        __tf8CListTag();
        func_00286BC0(&D_424F60, D_002E7800, &D_2EB708);
    }
    return &D_424F60;
}

extern "C" void func_0029E148(void *p, s32 flag)
{
    FLD(void *, p, 0xC) = _vt$12CSndWorkReal;
    func_0025C2C0(p, 0);
    if (flag & 1) return __builtin_delete(p);
}

extern "C" TypeInfo *__tf12CSndWorkReal()
{
    if (!D_424F70.vptr) {
        __tf8CSndWork();
        func_00286BC0(&D_424F70, D_002E7818, &D_424F30);
    }
    return &D_424F70;
}

extern "C" void func_0029E200(void *p, s32 v) { u8 *q = (u8 *)p + 0x70; *q = (*q & 0x8F) | v; }

INCLUDE_ASM("asm/nonmatchings/Lib29DE68", func_0029E218);

INCLUDE_ASM("asm/nonmatchings/Lib29DE68", func_0029E238);

extern "C" void func_0029E260(void *p, s32 v) { u8 *q = (u8 *)p + 0x70; q[2] = v; q[0] |= 0x20; }

extern "C" void func_0029E278(void *p, s32 v) { u8 *q = (u8 *)p + 0x70; q[3] = v; q[0] |= 0x40; }

extern "C" void *func_0029E290(void *p) { return p; }

extern "C" void *func_0029E298(void *p) { return (u8 *)p + 0x70; }

extern "C" TypeInfo *__tf10CSndUnitTg()
{
    if (!D_424F80.vptr) {
        __tf8CSndUnit();
        func_00286BC0(&D_424F80, D_002E7880, &D_424F40);
    }
    return &D_424F80;
}

INCLUDE_ASM("asm/nonmatchings/Lib29DE68", func_0029E2F0);

extern "C" TypeInfo *__tft12TSndUnitReal1Z10CSndUnitTg()
{
    if (!D_424F90.vptr) {
        __tf10CSndUnitTg();
        func_00286BC0(&D_424F90, D_002E7890, &D_424F80);
    }
    return &D_424F90;
}

INCLUDE_ASM("asm/nonmatchings/Lib29DE68", func_0029E3A8);

extern "C" void *func_0029E418(void *p) { return (u8 *)p + 0xC0; }

extern "C" TypeInfo *__tf11CSndUnitSeq()
{
    if (!D_424FB0.vptr) {
        __tf8CSndUnit();
        func_00286BC0(&D_424FB0, D_002E7908, &D_424F40);
    }
    return &D_424FB0;
}

INCLUDE_ASM("asm/nonmatchings/Lib29DE68", func_0029E470);

extern "C" TypeInfo *__tft12TSndUnitReal1Z11CSndUnitSeq()
{
    if (!D_424FA0.vptr) {
        __tf11CSndUnitSeq();
        func_00286BC0(&D_424FA0, D_002E7918, &D_424FB0);
    }
    return &D_424FA0;
}

INCLUDE_ASM("asm/nonmatchings/Lib29DE68", func_0029E528);

extern "C" void *func_0029E598(void *p) { return (u8 *)p + 0xC0; }

extern "C" TypeInfo *__tf11CSndUnitStr()
{
    if (!D_424FC0.vptr) {
        __tf8CSndUnit();
        func_00286BC0(&D_424FC0, D_002E79A8, &D_424F40);
    }
    return &D_424FC0;
}

INCLUDE_ASM("asm/nonmatchings/Lib29DE68", func_0029E5F0);

extern "C" TypeInfo *__tft12TSndUnitReal1Z11CSndUnitStr()
{
    if (!D_424FD0.vptr) {
        __tf11CSndUnitStr();
        func_00286BC0(&D_424FD0, D_002E79B8, &D_424FC0);
    }
    return &D_424FD0;
}

INCLUDE_ASM("asm/nonmatchings/Lib29DE68", func_0029E6A8);

extern "C" void *func_0029E718(void *p) { return (u8 *)p + 0xE0; }

extern "C" TypeInfo *__tf9type_info()
{
    if (!D_2EB910.vptr) func_00286BE0(&D_2EB910, D_002EAC70);
    return &D_2EB910;
}

INCLUDE_ASM("asm/nonmatchings/Lib29DE68", func_0029E760);

extern "C" s32 func_0029E778(void *p) { return FLD(s32, p, 0x0); }

INCLUDE_ASM("asm/nonmatchings/Lib29DE68", func_0029E780);

extern "C" TypeInfo *__tf8bad_cast()
{
    if (!D_4253F0.vptr) {
        __tf9exception();
        func_00286BC0(&D_4253F0, D_002EAC80, &D_2EB918);
    }
    return &D_4253F0;
}

INCLUDE_ASM("asm/nonmatchings/Lib29DE68", func_0029E7F0);

INCLUDE_ASM("asm/nonmatchings/Lib29DE68", func_0029E800);

extern "C" TypeInfo *__tf10bad_typeid()
{
    if (!D_4253E0.vptr) {
        __tf9exception();
        func_00286BC0(&D_4253E0, D_002EAC90, &D_2EB918);
    }
    return &D_4253E0;
}

INCLUDE_ASM("asm/nonmatchings/Lib29DE68", func_0029E888);

INCLUDE_ASM("asm/nonmatchings/Lib29DE68", func_0029E898);

extern "C" void func_0029E8D0(void *p, s32 flag)
{
    FLD(void *, p, 0x4) = _vt$16__user_type_info;
    func_00286B20(p, 0);
    if (flag & 1) return __builtin_delete(p);
}

extern "C" TypeInfo *__tf16__user_type_info()
{
    if (!D_425400.vptr) {
        __tf9type_info();
        func_00286BC0(&D_425400, D_002EACA0, &D_2EB910);
    }
    return &D_425400;
}

INCLUDE_ASM("asm/nonmatchings/Lib29DE68", func_0029E988);

extern "C" s32 func_0029E9A0(s32 a) { return a >= 4; }

extern "C" s32 func_0029E9B0(s32 a) { return a >= 6; }

extern "C" s32 func_0029E9C0(s32 a) { return (a & 6) == 4; }

extern "C" s32 func_0029E9D0(s32 a) { return (a & 5) == 4; }

extern "C" s32 func_0029E9E0(s32 a) { return (a & 5) == 5; }
