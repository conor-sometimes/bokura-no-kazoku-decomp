#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "CTask.h"
extern "C" void CTask_dtor(CTask *, s32) asm("_$_5CTask");
extern "C" void func_00286BC0(void *, const char *, void *);
extern "C" void func_00286BE0(void *, const char *);
extern "C" char D_002D4978[];
extern "C" char D_002D4990[];
extern "C" char D_002D49A8[];
extern "C" char D_002D49C0[];
extern "C" char D_002D49D8[];
extern "C" char D_002D49F0[];
extern "C" char D_002D4A38[];
extern "C" char D_002D4A48[];
extern "C" char D_002D4BE0[];
extern "C" char D_002D4C28[];
extern "C" char D_002D4CA8[];
extern "C" char D_002D4DE8[];
extern "C" char D_002D4E00[];
extern "C" u8 D_2EB708[];
extern "C" u8 D_2EB798[];
extern "C" u8 D_2EB7A8[];
extern "C" u8 D_2EB7B0[];
extern "C" u8 D_2EB7B8[];
extern "C" u8 D_2EB7C0[];
extern "C" u8 D_424660[];
extern "C" u8 D_4246E0[];
extern "C" u8 D_4246F0[];
extern "C" u8 D_424700[];
extern "C" u8 D_424710[];
extern "C" u8 D_424720[];
extern "C" u8 D_424730[];
extern "C" u8 D_424770[];
extern "C" u8 D_424780[];
extern "C" u8 D_4247A0[];
extern "C" void *__tf11CMapEffWork(void);
extern "C" void *__tf5CList(void);
extern "C" void *__tf8CListTag(void);
extern "C" void *func_00295D50(void);
// @decl-end

// CMapEffFlyWork[1]
extern "C" s32 func_002959A8(u8 *p, s32 id) { return id == -300; }

extern "C" void *__tf15CMapEffRainWork(void) {
    if (*(s32 *)D_4246F0 == 0) {
        __tf11CMapEffWork();
        func_00286BC0(D_4246F0, D_002D4978, D_2EB798);
    }
    return D_4246F0;
}

// CMapEffRainWork[1]
extern "C" s32 func_00295A08(u8 *p, s32 id) { return id == -400; }

extern "C" void *__tf15CMapEffSnowWork(void) {
    if (*(s32 *)D_424720 == 0) {
        __tf11CMapEffWork();
        func_00286BC0(D_424720, D_002D4990, D_2EB798);
    }
    return D_424720;
}

// CMapEffSnowWork[1]
extern "C" s32 func_00295A68(u8 *p, s32 id) { return id == -500; }

INCLUDE_ASM("asm/nonmatchings/Lib2959A8", func_00295A78);

extern "C" void *__tf19CMapEffAquariumWork(void) {
    if (*(s32 *)D_4246E0 == 0) {
        __tf11CMapEffWork();
        func_00286BC0(D_4246E0, D_002D49A8, D_2EB798);
    }
    return D_4246E0;
}

// CMapEffAquariumWork[1]
extern "C" s32 func_00295B00(u8 *p, s32 id) { return id == -600; }

INCLUDE_ASM("asm/nonmatchings/Lib2959A8", func_00295B10);

extern "C" void *__tf17CMapEffMirrorWork(void) {
    if (*(s32 *)D_424730 == 0) {
        __tf11CMapEffWork();
        func_00286BC0(D_424730, D_002D49C0, D_2EB798);
    }
    return D_424730;
}

INCLUDE_ASM("asm/nonmatchings/Lib2959A8", func_00295B98);

// CMapEffMirrorWork[1]
extern "C" s32 func_00295BB0(u8 *p, s32 id) { return id == -900; }

INCLUDE_ASM("asm/nonmatchings/Lib2959A8", func_00295BC0);

extern "C" void *__tf17CMapEffBreathWork(void) {
    if (*(s32 *)D_424780 == 0) {
        __tf11CMapEffWork();
        func_00286BC0(D_424780, D_002D49D8, D_2EB798);
    }
    return D_424780;
}

// CMapEffBreathWork[1]
extern "C" s32 func_00295C48(u8 *p, s32 id) { return id == -1000; }

INCLUDE_ASM("asm/nonmatchings/Lib2959A8", func_00295C58);

extern "C" void *__tf16CMapEffSwingWork(void) {
    if (*(s32 *)D_424770 == 0) {
        __tf11CMapEffWork();
        func_00286BC0(D_424770, D_002D49F0, D_2EB798);
    }
    return D_424770;
}

// CMapEffSwingWork[1]
extern "C" s32 func_00295CE0(u8 *p, s32 id) { return id == -1100; }

INCLUDE_ASM("asm/nonmatchings/Lib2959A8", func_00295CF0);

extern "C" void *func_00295D00(void) {
    if (*(s32 *)D_424700 == 0) {
        func_00295D50();
        func_00286BC0(D_424700, D_002D4A38, D_424710);
    }
    return D_424700;
}

extern "C" void *func_00295D50(void) {
    if (*(s32 *)D_424710 == 0) {
        __tf8CListTag();
        func_00286BC0(D_424710, D_002D4A48, D_2EB708);
    }
    return D_424710;
}

INCLUDE_ASM("asm/nonmatchings/Lib2959A8", func_00295DA0);

INCLUDE_ASM("asm/nonmatchings/Lib2959A8", func_00295DC8);

INCLUDE_ASM("asm/nonmatchings/Lib2959A8", Func295E20__10CUnk295E20i);

extern "C" s32 func_00295E40(u8 *p) { return *(s32 *)(p + 0xC); }

INCLUDE_ASM("asm/nonmatchings/Lib2959A8", func_00295E48);

INCLUDE_ASM("asm/nonmatchings/Lib2959A8", func_00295E60);

INCLUDE_ASM("asm/nonmatchings/Lib2959A8", func_00296040);

INCLUDE_ASM("asm/nonmatchings/Lib2959A8", func_00296060);

INCLUDE_ASM("asm/nonmatchings/Lib2959A8", func_00296098);

INCLUDE_ASM("asm/nonmatchings/Lib2959A8", func_002960C8);

INCLUDE_ASM("asm/nonmatchings/Lib2959A8", func_00296130);

INCLUDE_ASM("asm/nonmatchings/Lib2959A8", func_00296188);

INCLUDE_ASM("asm/nonmatchings/Lib2959A8", func_002961D0);

extern "C" void func_00296228(void) {
}

extern "C" void *__tft6TArray3Z17tagMapSndStepInfoi_16_Zt10TAllocator1Z17tagMapSndStepInfo(void) {
    if (*(s32 *)D_2EB7B0 == 0) {
        func_00286BE0(D_2EB7B0, D_002D4BE0);
    }
    return D_2EB7B0;
}

extern "C" void *__tf10CMapSndRes(void) {
    if (*(s32 *)D_2EB7A8 == 0) {
        func_00286BE0(D_2EB7A8, D_002D4C28);
    }
    return D_2EB7A8;
}

extern "C" void *__tf10CMapSndObj(void) {
    if (*(s32 *)D_2EB7B8 == 0) {
        func_00286BE0(D_2EB7B8, D_002D4CA8);
    }
    return D_2EB7B8;
}

extern "C" s32 func_002962F0(u8 *p) { return *(s32 *)(p + 0x4); }

INCLUDE_ASM("asm/nonmatchings/Lib2959A8", func_002962F8);

extern "C" void *__tft5TList1Z9CCharaObj(void) {
    if (*(s32 *)D_4247A0 == 0) {
        __tf5CList();
        func_00286BC0(D_4247A0, D_002D4DE8, D_424660);
    }
    return D_4247A0;
}

extern "C" void *__tf9CSceneObj(void) {
    if (*(s32 *)D_2EB7C0 == 0) {
        func_00286BE0(D_2EB7C0, D_002D4E00);
    }
    return D_2EB7C0;
}

extern "C" s32 func_00296438(u8 *p) { return *(s32 *)(p + 0x4); }

INCLUDE_ASM("asm/nonmatchings/Lib2959A8", func_00296440);

extern "C" s32 func_00296450(u8 *p) { return *(s32 *)(p + 0x0); }

INCLUDE_ASM("asm/nonmatchings/Lib2959A8", func_00296458);

INCLUDE_ASM("asm/nonmatchings/Lib2959A8", func_002964B8);

extern "C" void func_002964C8(u8 *p, s32 v) { *(s32 *)(p + 0x2C) = v; }

extern "C" s32 func_002964D0(u8 *p) { return *(s32 *)(p + 0x2C); }

extern "C" s32 func_002964D8(u8 *p) { return *(s32 *)(p + 0x24); }

extern "C" s32 func_002964E0(u8 *p) { return *(s32 *)(p + 0x28); }

extern "C" s32 func_002964E8(u8 *p) { return *(s32 *)(p + 0x20); }

extern "C" s32 func_002964F0(u8 *p) { return *(s32 *)(p + 0x1C); }

INCLUDE_ASM("asm/nonmatchings/Lib2959A8", func_002964F8);

INCLUDE_ASM("asm/nonmatchings/Lib2959A8", func_00296508);

extern "C" s32 func_00296518(u8 *p) { return *(s32 *)(p + 0x30); }

extern "C" s32 func_00296520(u8 *p) { return *(s32 *)(p + 0x34); }

extern "C" void func_00296528(u8 *p, s32 v) { *(s32 *)(p + 0x38) = v; }

extern "C" void func_00296530(u8 *p, f32 v) { *(f32 *)(p + 0x50) = v; }

extern "C" f32 func_00296538(u8 *p) { return *(f32 *)(p + 0x50); }
