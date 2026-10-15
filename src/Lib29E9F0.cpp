#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "linkonce.h"
extern "C" {
extern TypeInfo D_425410;
TypeInfo *__tf16__user_type_info();
extern const char D_002EACB8[];
extern TypeInfo D_425400;
extern TypeInfo D_425420;
extern const char D_002EACD0[];
extern TypeInfo D_2EB918;
extern const char D_002EACE8[];
extern TypeInfo D_425430;
TypeInfo *__tf9exception();
extern const char D_002EACF8[];
extern TypeInfo D_425480;
TypeInfo *__tf9type_info();
extern const char D_002EADA0[];
extern TypeInfo D_2EB910;
extern TypeInfo D_425450;
extern const char D_002EADB8[];
extern TypeInfo D_4254A0;
extern const char D_002EADD0[];
extern TypeInfo D_425440;
extern const char D_002EADE8[];
extern TypeInfo D_425460;
extern const char D_002EAE00[];
extern TypeInfo D_425490;
extern const char D_002EAE18[];
}

#include "linkonce.h"
extern "C" {
extern char _vt$16__user_type_info[];
void func_00286B20(void *, s32);
extern char _vt$19__pointer_type_info[];
extern char _vt$16__attr_type_info[];
extern char _vt$19__builtin_type_info[];
extern char _vt$16__func_type_info[];
extern char _vt$16__ptmf_type_info[];
extern char _vt$16__ptmd_type_info[];
extern char _vt$17__array_type_info[];
extern TypeInfo D_425470;
TypeInfo *__tf9type_info();
extern const char D_002EAE30[];
extern TypeInfo D_2EB910;
}
// @decl-end

INCLUDE_ASM("asm/nonmatchings/Lib29E9F0", func_0029E9F0);

extern "C" void func_0029EA58(void *p, s32 flag)
{
    FLD(void *, p, 0x4) = _vt$16__user_type_info;
    func_00286B20(p, 0);
    if (flag & 1) return __builtin_delete(p);
}

extern "C" TypeInfo *__tf14__si_type_info()
{
    if (!D_425410.vptr) {
        __tf16__user_type_info();
        func_00286BC0(&D_425410, D_002EACB8, &D_425400);
    }
    return &D_425410;
}

INCLUDE_ASM("asm/nonmatchings/Lib29E9F0", func_0029EB10);

extern "C" void func_0029EB28(void *p, s32 flag)
{
    FLD(void *, p, 0x4) = _vt$16__user_type_info;
    func_00286B20(p, 0);
    if (flag & 1) return __builtin_delete(p);
}

extern "C" TypeInfo *__tf17__class_type_info()
{
    if (!D_425420.vptr) {
        __tf16__user_type_info();
        func_00286BC0(&D_425420, D_002EACD0, &D_425400);
    }
    return &D_425420;
}

INCLUDE_ASM("asm/nonmatchings/Lib29E9F0", func_0029EBE0);

extern "C" TypeInfo *__tf9exception()
{
    if (!D_2EB918.vptr) func_00286BE0(&D_2EB918, D_002EACE8);
    return &D_2EB918;
}

INCLUDE_ASM("asm/nonmatchings/Lib29E9F0", func_0029EC40);

INCLUDE_ASM("asm/nonmatchings/Lib29E9F0", func_0029EC50);

extern "C" TypeInfo *__tf13bad_exception()
{
    if (!D_425430.vptr) {
        __tf9exception();
        func_00286BC0(&D_425430, D_002EACF8, &D_2EB918);
    }
    return &D_425430;
}

INCLUDE_ASM("asm/nonmatchings/Lib29E9F0", func_0029ECD8);

INCLUDE_ASM("asm/nonmatchings/Lib29E9F0", func_0029ECE8);

extern "C" void func_0029ED20(void *p, s32 flag)
{
    FLD(void *, p, 0x4) = _vt$19__pointer_type_info;
    func_00286B20(p, 0);
    if (flag & 1) return __builtin_delete(p);
}

extern "C" TypeInfo *__tf19__pointer_type_info()
{
    if (!D_425480.vptr) {
        __tf9type_info();
        func_00286BC0(&D_425480, D_002EADA0, &D_2EB910);
    }
    return &D_425480;
}

extern "C" void func_0029EDD8(void *p, s32 flag)
{
    FLD(void *, p, 0x4) = _vt$16__attr_type_info;
    func_00286B20(p, 0);
    if (flag & 1) return __builtin_delete(p);
}

extern "C" TypeInfo *__tf16__attr_type_info()
{
    if (!D_425450.vptr) {
        __tf9type_info();
        func_00286BC0(&D_425450, D_002EADB8, &D_2EB910);
    }
    return &D_425450;
}

extern "C" void func_0029EE90(void *p, s32 flag)
{
    FLD(void *, p, 0x4) = _vt$19__builtin_type_info;
    func_00286B20(p, 0);
    if (flag & 1) return __builtin_delete(p);
}

extern "C" TypeInfo *__tf19__builtin_type_info()
{
    if (!D_4254A0.vptr) {
        __tf9type_info();
        func_00286BC0(&D_4254A0, D_002EADD0, &D_2EB910);
    }
    return &D_4254A0;
}

extern "C" void func_0029EF48(void *p, s32 flag)
{
    FLD(void *, p, 0x4) = _vt$16__func_type_info;
    func_00286B20(p, 0);
    if (flag & 1) return __builtin_delete(p);
}

extern "C" TypeInfo *__tf16__func_type_info()
{
    if (!D_425440.vptr) {
        __tf9type_info();
        func_00286BC0(&D_425440, D_002EADE8, &D_2EB910);
    }
    return &D_425440;
}

extern "C" void func_0029F000(void *p, s32 flag)
{
    FLD(void *, p, 0x4) = _vt$16__ptmf_type_info;
    func_00286B20(p, 0);
    if (flag & 1) return __builtin_delete(p);
}

extern "C" TypeInfo *__tf16__ptmf_type_info()
{
    if (!D_425460.vptr) {
        __tf9type_info();
        func_00286BC0(&D_425460, D_002EAE00, &D_2EB910);
    }
    return &D_425460;
}

extern "C" void func_0029F0B8(void *p, s32 flag)
{
    FLD(void *, p, 0x4) = _vt$16__ptmd_type_info;
    func_00286B20(p, 0);
    if (flag & 1) return __builtin_delete(p);
}

extern "C" TypeInfo *__tf16__ptmd_type_info()
{
    if (!D_425490.vptr) {
        __tf9type_info();
        func_00286BC0(&D_425490, D_002EAE18, &D_2EB910);
    }
    return &D_425490;
}

extern "C" void func_0029F170(void *p, s32 flag)
{
    FLD(void *, p, 0x4) = _vt$17__array_type_info;
    func_00286B20(p, 0);
    if (flag & 1) return __builtin_delete(p);
}

extern "C" TypeInfo *__tf17__array_type_info()
{
    if (!D_425470.vptr) {
        __tf9type_info();
        func_00286BC0(&D_425470, D_002EAE30, &D_2EB910);
    }
    return &D_425470;
}

// end of .text: retail pads to 0x29F230
asm(".section .text\n.space 8");
