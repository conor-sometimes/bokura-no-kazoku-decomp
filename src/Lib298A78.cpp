#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "linkonce.h"
extern "C" {
extern TypeInfo D_424880;
TypeInfo *func_00298EF0();
extern const char D_002D6920[];
extern TypeInfo D_2EB820;
extern const char D_002D6960[];
extern TypeInfo D_4248B0;
TypeInfo *__tf9CFlagWork();
extern const char D_002D7B50[];
extern TypeInfo D_2EB700;
extern TypeInfo D_4248C0;
extern const char D_002D7B60[];
extern TypeInfo D_4248A0;
TypeInfo *__tf8ISysFlag();
extern const char D_002D7B70[];
extern TypeInfo D_424890;
TypeInfo *__tf8ICurFlag();
extern const char D_002D7B80[];
extern TypeInfo D_4248D0;
TypeInfo *func_002994D0();
extern const char D_002D7D60[];
extern TypeInfo D_2EB828;
extern const char D_002D7D70[];
extern TypeInfo D_4248E0;
TypeInfo *func_00299950();
extern const char D_002D8910[];
extern TypeInfo D_2EB830;
}
struct VDel_298AE8 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual ~VDel_298AE8(); };
struct VDel_2990F0 { u8 pad[0x1c]; virtual ~VDel_2990F0(); };
struct VDel_299178 { u8 pad[0x1c]; virtual ~VDel_299178(); };
struct VDel_299498 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual ~VDel_299498(); };
struct VDel_2998B8 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79(); virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83(); virtual ~VDel_2998B8(); };

#include "linkonce.h"
extern "C" {
extern char _vt$8ISysFlag[];
void _$_9CFlagWork(void *, s32);
extern char _vt$8ICurFlag[];
}
// @decl-end

extern "C" f32 func_00298A78(void *p) { return FLD(f32, p, 0x16C); }

extern "C" void func_00298A80(void *p, f32 v) { FLD(f32, p, 0x170) = v; }

extern "C" f32 func_00298A88(void *p) { return FLD(f32, p, 0x170); }

extern "C" s32 func_00298A90(void *p) { return FLD(s32, p, 0x160); }

extern "C" TypeInfo *__tf12CUserFlagMgr()
{
    if (!D_424880.vptr) {
        func_00298EF0();
        func_00286BC0(&D_424880, D_002D6920, &D_2EB820);
    }
    return &D_424880;
}

extern "C" void func_00298AE8(VDel_298AE8 *p) { delete p; }

INCLUDE_ASM("asm/nonmatchings/Lib298A78", func_00298B20);

INCLUDE_ASM("asm/nonmatchings/Lib298A78", func_00298B48);

extern "C" void func_00298B68(void *p) { FLD(s32, p, 0x58DC) = 0; }

INCLUDE_ASM("asm/nonmatchings/Lib298A78", func_00298B70);

INCLUDE_ASM("asm/nonmatchings/Lib298A78", func_00298BB0);

extern "C" void func_00298C10(void *p) { FLD(s32, p, 0x58DC) = 0xFF; }

INCLUDE_ASM("asm/nonmatchings/Lib298A78", func_00298C20);

INCLUDE_ASM("asm/nonmatchings/Lib298A78", func_00298CC0);

INCLUDE_ASM("asm/nonmatchings/Lib298A78", func_00298D48);

extern "C" void func_00298D68(void *p, s32 a) { FLD(s32, p, 0x5908) = a; FLD(s32, p, 0x590C) = 1; }

extern "C" void func_00298D78(void *p, s32 a) { FLD(s32, p, 0x590C) = a; FLD(s32, p, 0x2F44) = a; FLD(s32, p, 0x5898) = a; }

extern "C" s32 func_00298D88(void *p) { return FLD(s32, p, 0x590C); }

extern "C" void func_00298D90(void *p, s32 v) { FLD(s32, p, 0x5928) = v; }

INCLUDE_ASM("asm/nonmatchings/Lib298A78", func_00298D98);

INCLUDE_ASM("asm/nonmatchings/Lib298A78", func_00298E38);

extern "C" void func_00298EC0(void *p) { FLD(s32, p, 0x5910) = 0; }

extern "C" void func_00298EC8(void *p, s32 v) { FLD(s32, p, 0x58FC) = v; }

extern "C" void func_00298ED0(void *p, s32 v) { FLD(s32, p, 0x5900) = v; }

extern "C" void func_00298ED8(void *p, s32 v) { FLD(s32, p, 0x5904) = v; }

extern "C" void func_00298EE0(void *p, s32 a) { FLD(s32, p, 0x2F40) = a; FLD(s32, p, 0x5894) = a; }

extern "C" TypeInfo *func_00298EF0()
{
    if (!D_2EB820.vptr) func_00286BE0(&D_2EB820, D_002D6960);
    return &D_2EB820;
}

extern "C" void func_00298F30(void *p, s32 flag)
{
    FLD(void *, p, 0x1C) = _vt$8ISysFlag;
    _$_9CFlagWork(p, 0);
    if (flag & 1) return __builtin_delete(p);
}

extern "C" TypeInfo *__tf8ISysFlag()
{
    if (!D_4248B0.vptr) {
        __tf9CFlagWork();
        func_00286BC0(&D_4248B0, D_002D7B50, &D_2EB700);
    }
    return &D_4248B0;
}

extern "C" void func_00298FE8(void *p, s32 flag)
{
    FLD(void *, p, 0x1C) = _vt$8ICurFlag;
    _$_9CFlagWork(p, 0);
    if (flag & 1) return __builtin_delete(p);
}

extern "C" TypeInfo *__tf8ICurFlag()
{
    if (!D_4248C0.vptr) {
        __tf9CFlagWork();
        func_00286BC0(&D_4248C0, D_002D7B60, &D_2EB700);
    }
    return &D_4248C0;
}

extern "C" TypeInfo *__tf8CSysFlag()
{
    if (!D_4248A0.vptr) {
        __tf8ISysFlag();
        func_00286BC0(&D_4248A0, D_002D7B70, &D_4248B0);
    }
    return &D_4248A0;
}

extern "C" void func_002990F0(VDel_2990F0 *p) { delete p; }

extern "C" TypeInfo *__tf8CCurFlag()
{
    if (!D_424890.vptr) {
        __tf8ICurFlag();
        func_00286BC0(&D_424890, D_002D7B80, &D_4248C0);
    }
    return &D_424890;
}

extern "C" void func_00299178(VDel_299178 *p) { delete p; }

INCLUDE_ASM("asm/nonmatchings/Lib298A78", func_002991B0);

INCLUDE_ASM("asm/nonmatchings/Lib298A78", func_002991E8);

INCLUDE_ASM("asm/nonmatchings/Lib298A78", func_00299218);

INCLUDE_ASM("asm/nonmatchings/Lib298A78", func_00299248);

INCLUDE_ASM("asm/nonmatchings/Lib298A78", func_002992C8);

INCLUDE_ASM("asm/nonmatchings/Lib298A78", func_00299348);

INCLUDE_ASM("asm/nonmatchings/Lib298A78", func_002993C8);

extern "C" TypeInfo *__tf11CResNameMgr()
{
    if (!D_4248D0.vptr) {
        func_002994D0();
        func_00286BC0(&D_4248D0, D_002D7D60, &D_2EB828);
    }
    return &D_4248D0;
}

extern "C" void func_00299498(VDel_299498 *p) { delete p; }

extern "C" TypeInfo *func_002994D0()
{
    if (!D_2EB828.vptr) func_00286BE0(&D_2EB828, D_002D7D70);
    return &D_2EB828;
}

INCLUDE_ASM("asm/nonmatchings/Lib298A78", func_00299510);

INCLUDE_ASM("asm/nonmatchings/Lib298A78", func_002996C0);

extern "C" TypeInfo *__tf10CGameDBMgr()
{
    if (!D_4248E0.vptr) {
        func_00299950();
        func_00286BC0(&D_4248E0, D_002D8910, &D_2EB830);
    }
    return &D_4248E0;
}

extern "C" void func_002998B8(VDel_2998B8 *p) { delete p; }

extern "C" void func_002998F0(void *p, s32 v) { FLD(s32, p, 0x10) = v; }

extern "C" s32 func_002998F8(void *p) { return FLD(s32, p, 0x10); }

extern "C" s32 func_00299900(void *p) { return FLD(s32, p, 0x1C); }

extern "C" s32 func_00299908(void *p) { return FLD(s32, p, 0x1E4); }

extern "C" s32 func_00299910(void *p) { return FLD(s32, p, 0x1D8); }

extern "C" s32 func_00299918(void *p) { return FLD(s32, p, 0x1F0); }

extern "C" s32 func_00299920(void *p) { return FLD(s32, p, 0x208); }

extern "C" s32 func_00299928(void *p) { return FLD(s32, p, 0x1CC); }

extern "C" s32 func_00299930(void *p) { return FLD(s32, p, 0x40); }

extern "C" s32 func_00299938(void *p) { return FLD(s32, p, 0x228); }

extern "C" s32 func_00299940(void *p) { return FLD(s32, p, 0x214); }
