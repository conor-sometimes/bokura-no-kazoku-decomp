#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "linkonce.h"
extern "C" {
extern TypeInfo D_2EB808;
extern const char D_002D5858[];
extern TypeInfo D_2EB800;
extern const char D_002D58A0[];
extern TypeInfo D_424870;
TypeInfo *func_00298970();
extern const char D_002D5CF0[];
extern TypeInfo D_424860;
extern TypeInfo D_424850;
TypeInfo *__tf5CList();
extern const char D_002D5D00[];
extern TypeInfo D_424660;
extern TypeInfo D_424840;
TypeInfo *func_002989C0();
extern const char D_002D5D18[];
extern TypeInfo D_2EB810;
TypeInfo *__tf8CListTag();
extern const char D_002D5D28[];
extern TypeInfo D_2EB708;
extern const char D_002D5D48[];
extern TypeInfo D_2EB818;
extern const char D_002D5EC8[];
}
struct VDel_298910 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual ~VDel_298910(); };

#include "linkonce.h"
extern "C" {
extern void *(*D_002B91A4)(u32 n);
extern void *(*D_002B91AC)(void *p, u32 n);
extern void (*D_002B91B0)(void *p);
void *memcpy(void *, const void *, u32);
void *memset(void *, s32, u32);
}
void Func235DE0(const char *fmt, ...);
extern "C" const char D_002D5560[], D_002D5820[], D_002DA2B8[];
struct ConstPtr { s32 w[0x4 / 4]; };
struct TArrConstPtr { s32 m0; ConstPtr *m_data; s32 m_cap; s32 m_count; s32 m_grow; void *vptr; };
extern "C" {
extern char _vt$t6TArray3ZPCvi_16_Zt10TAllocator1ZPCv[];
void func_00297768(TArrConstPtr *a, s32 n, s32 keep);
ConstPtr *func_002978F8(TArrConstPtr *a, s32 i);
ConstPtr *func_00297958(TArrConstPtr *a, s32 n);
void func_00297980(TArrConstPtr *a, ConstPtr *p);
void func_002979B0(TArrConstPtr *a, ConstPtr *p, const ConstPtr &v, s32 n);
void func_00297A18(TArrConstPtr *a, ConstPtr *p, s32 n);
ConstPtr *func_00297A70(TArrConstPtr *a, ConstPtr *p, s32 n);
void func_00297BD0(TArrConstPtr *a, ConstPtr *p, const ConstPtr &v);
void func_00297BE8(TArrConstPtr *a, ConstPtr *p);
void Func2976E8__FPvi(TArrConstPtr *a, s32 n);
}
struct EventCharaResName { s32 w[0x20 / 4]; };
struct TArrEventCharaResName { s32 m0; EventCharaResName *m_data; s32 m_cap; s32 m_count; s32 m_grow; void *vptr; };
extern "C" {
extern char _vt$t6TArray3Z18CEventCharaResNamei_16_Zt10TAllocator1Z18CEventCharaResName[];
void func_00297FB8(TArrEventCharaResName *a, s32 n, s32 keep);
EventCharaResName *func_00298158(TArrEventCharaResName *a, s32 i);
EventCharaResName *func_00298168(TArrEventCharaResName *a, s32 n);
void func_00298190(TArrEventCharaResName *a, EventCharaResName *p);
void func_002981C0(TArrEventCharaResName *a, EventCharaResName *p, const EventCharaResName &v, s32 n);
void func_00298228(TArrEventCharaResName *a, EventCharaResName *p, s32 n);
EventCharaResName *func_00298280(TArrEventCharaResName *a, EventCharaResName *p, s32 n);
void func_002982B8(TArrEventCharaResName *a, EventCharaResName *p, const EventCharaResName &v);
void func_00298308(TArrEventCharaResName *a, EventCharaResName *p);
void Func297F78__8CDkArrayi(TArrEventCharaResName *a, s32 n);
}
struct MapDBExprReg { s32 w[0x24 / 4]; };
struct TArrMapDBExprReg { s32 m0; MapDBExprReg *m_data; s32 m_cap; s32 m_count; s32 m_grow; void *vptr; };
extern "C" {
extern char _vt$t6TArray3Z13CMapDBExprRegi_16_Zt10TAllocator1Z13CMapDBExprReg[];
void func_0029A5E0(TArrMapDBExprReg *a, s32 n, s32 keep);
MapDBExprReg *func_0029A578(TArrMapDBExprReg *a, s32 i);
MapDBExprReg *func_0029A948(TArrMapDBExprReg *a, s32 n);
void func_0029A978(TArrMapDBExprReg *a, MapDBExprReg *p);
void func_0029A9A8(TArrMapDBExprReg *a, MapDBExprReg *p, const MapDBExprReg &v, s32 n);
void func_0029AA10(TArrMapDBExprReg *a, MapDBExprReg *p, s32 n);
MapDBExprReg *func_0029AA68(TArrMapDBExprReg *a, MapDBExprReg *p, s32 n);
void func_0029AAA8(TArrMapDBExprReg *a, MapDBExprReg *p, const MapDBExprReg &v);
void func_0029AB00(TArrMapDBExprReg *a, MapDBExprReg *p);
void Func29A558__10CUnk29A558i(TArrMapDBExprReg *a, s32 n);
}

inline void Set2928(void *p, s32 a, s32 b) { FLD(s32, p, 0x2928) = a; FLD(s32, p, 0x292C) = b; FLD(s32, p, 0x2930) = 0; }
// @decl-end

extern "C" void func_00298190(TArrEventCharaResName *a, EventCharaResName *p) { if (p) D_002B91B0(p); }

extern "C" void func_002981C0(TArrEventCharaResName *a, EventCharaResName *p, const EventCharaResName &v, s32 n)
{
    for (s32 i = 0; i < n; i++) func_002982B8(a, &p[i], v);
}

extern "C" void func_00298228(TArrEventCharaResName *a, EventCharaResName *p, s32 n)
{
    for (s32 i = 0; i < n; i++) func_00298308(a, &p[i]);
}

extern "C" EventCharaResName *func_00298280(TArrEventCharaResName *a, EventCharaResName *p, s32 n)
{
    D_002B91AC(p, n * sizeof(EventCharaResName));
    return p;
}

extern "C" void func_002982B8(TArrEventCharaResName *a, EventCharaResName *p, const EventCharaResName &v) { if (p) *p = v; }

extern "C" void func_00298308(TArrEventCharaResName *a, EventCharaResName *p) {
}

extern "C" TypeInfo *__tft6TArray3Z18CEventCharaResNamei_16_Zt10TAllocator1Z18CEventCharaResName()
{
    if (!D_2EB808.vptr) func_00286BE0(&D_2EB808, D_002D5858);
    return &D_2EB808;
}

extern "C" TypeInfo *__tf9CEventObj()
{
    if (!D_2EB800.vptr) func_00286BE0(&D_2EB800, D_002D58A0);
    return &D_2EB800;
}

extern "C" s32 func_00298390(void *p) { return FLD(s32, p, 0x0); }

extern "C" s32 func_00298398(void *p) { return FLD(s32, p, 0x4); }

extern "C" s32 func_002983A0(void *p) { return FLD(s32, p, 0x8); }

INCLUDE_ASM("asm/nonmatchings/Lib298190", func_002983A8);

INCLUDE_ASM("asm/nonmatchings/Lib298190", func_002983D8);

INCLUDE_ASM("asm/nonmatchings/Lib298190", func_00298410);

INCLUDE_ASM("asm/nonmatchings/Lib298190", func_00298448);

INCLUDE_ASM("asm/nonmatchings/Lib298190", func_00298480);

INCLUDE_ASM("asm/nonmatchings/Lib298190", func_002984B8);

INCLUDE_ASM("asm/nonmatchings/Lib298190", func_002984F0);

INCLUDE_ASM("asm/nonmatchings/Lib298190", func_00298530);

extern "C" s32 func_00298570(void *p) { return FLD(s32, p, 0x488); }

extern "C" s32 func_00298578(void *p) { return FLD(s32, p, 0xFB48); }

extern "C" s32 func_00298590(void *p) { return FLD(s32, p, 0xFB2C); }

INCLUDE_ASM("asm/nonmatchings/Lib298190", func_002985A8);

extern "C" void func_002985D0(void *p, s32 v) { FLD(s32, p, 0xFC04) = v; }

extern "C" s32 func_002985E8(void *p) { return FLD(s32, p, 0xFC04); }

extern "C" void func_00298600(void *p, s32 v) { FLD(s32, p, 0xFC08) = v; }

extern "C" s32 func_00298618(void *p) { return FLD(s32, p, 0xFC08); }

extern "C" s32 func_00298630(void *p) { return FLD(s32, p, 0x2924); }

extern "C" void func_00298638(void *p, s32 v) { FLD(s32, p, 0xFC0C) = v; }

extern "C" s32 func_00298650(void *p) { return FLD(s32, p, 0xFC0C); }

extern "C" void func_00298668(void *p, s32 v) { FLD(s32, p, 0xFC10) = v; }

extern "C" s32 func_00298680(void *p) { return FLD(s32, p, 0xFC10); }

extern "C" void func_00298698(void *p, s32 v) { FLD(s32, p, 0x2928) = v; }

extern "C" s32 func_002986A0(void *p) { return FLD(s32, p, 0x2928); }

extern "C" void func_002986A8(void *p, s32 v) { FLD(s32, p, 0x10) = v; }

extern "C" s32 func_002986B0(void *p) { return FLD(s32, p, 0xFC18); }

extern "C" void func_002986C8(void *p, s32 v) { FLD(s32, p, 0xFC50) = v; }

extern "C" s32 func_002986E0(void *p) { return FLD(s32, p, 0xFC50); }

extern "C" void func_002986F8(void *p, s32 a, s32 b) { Set2928((u8 *)p + 0xC, a, b); }

extern "C" s32 func_00298710(void *p) { return FLD(s32, p, 0xFC54); }

extern "C" void func_00298728(void *p, s32 v) { FLD(s32, p, 0xFC58) = v; }

extern "C" void func_00298740(void *p, s32 v) { FLD(s32, p, 0xFC5C) = v; }

extern "C" s32 func_00298758(void *p) { return FLD(s32, p, 0xFBFC); }

extern "C" TypeInfo *__tf12CEventMesRes()
{
    if (!D_424870.vptr) {
        func_00298970();
        func_00286BC0(&D_424870, D_002D5CF0, &D_424860);
    }
    return &D_424870;
}

INCLUDE_ASM("asm/nonmatchings/Lib298190", func_002987C0);

extern "C" TypeInfo *__tft5TList1Z12CEventMesRes()
{
    if (!D_424850.vptr) {
        __tf5CList();
        func_00286BC0(&D_424850, D_002D5D00, &D_424660);
    }
    return &D_424850;
}

extern "C" TypeInfo *__tf12CEventMesMgr()
{
    if (!D_424840.vptr) {
        func_002989C0();
        func_00286BC0(&D_424840, D_002D5D18, &D_2EB810);
    }
    return &D_424840;
}

extern "C" void func_00298910(VDel_298910 *p) { delete p; }

INCLUDE_ASM("asm/nonmatchings/Lib298190", func_00298948);

extern "C" void *func_00298968(void *p) { return (u8 *)p + 0x14; }

extern "C" TypeInfo *func_00298970()
{
    if (!D_424860.vptr) {
        __tf8CListTag();
        func_00286BC0(&D_424860, D_002D5D28, &D_2EB708);
    }
    return &D_424860;
}

extern "C" TypeInfo *func_002989C0()
{
    if (!D_2EB810.vptr) func_00286BE0(&D_2EB810, D_002D5D48);
    return &D_2EB810;
}

extern "C" TypeInfo *__tf9CMovieObj()
{
    if (!D_2EB818.vptr) func_00286BE0(&D_2EB818, D_002D5EC8);
    return &D_2EB818;
}

extern "C" s32 func_00298A40(void *p) { return FLD(s32, p, 0x158); }

extern "C" s32 func_00298A48(void *p) { return FLD(s32, p, 0x15C); }

extern "C" void func_00298A50(void *p, s32 v) { FLD(s32, p, 0x168) = v; }

extern "C" s32 func_00298A58(void *p) { return FLD(s32, p, 0x168); }

extern "C" void func_00298A60(void *p, s32 v) { FLD(s32, p, 0x164) = v; }

extern "C" s32 func_00298A68(void *p) { return FLD(s32, p, 0x164); }

extern "C" void func_00298A70(void *p, f32 v) { FLD(f32, p, 0x16C) = v; }
