#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern "C" void func_001704F8(void *p);
class CPhotoDBMgr {
public:
    static CPhotoDBMgr *Create();
};

struct CAlbumSub8 {
    s16 m_unk0;
    s16 m_unk2;
    s32 m_unk4;
    void Init() {
        m_unk0 = 0x80;
        m_unk4 = -1;
        m_unk2 = 0;
    }
};
class CAlbumMgrSub16D618 {
public:
    void Reset();
    u8 pad0[0x8];
    CAlbumSub8 m_unk8;        // 0x8
    u8 pad10[0x5C - 0x10];
    s32 m_unk5C;              // 0x5C
    s32 m_unk60;              // 0x60
    s32 m_unk64;              // 0x64
    u8 pad68[0xD8 - 0x68];
    s32 m_unkD8;              // 0xD8
    u8 padDC[0x200 - 0xDC];
    s32 m_unk200;             // 0x200
    s32 m_unk204;             // 0x204
    s32 m_unk208;             // 0x208
    s32 m_unk20C;             // 0x20C
    s32 m_unk210;             // 0x210
    s32 m_unk214;             // 0x214
    s32 m_unk218;             // 0x218
};

extern "C" s32 func_002539A0(s32 psm);
extern "C" void func_00227BF0(u64 tex, s32 a, s32 b, s32 w, s32 h, u8 *src);

extern "C" void *func_00251488();
extern "C" void func_00227CB8(void *ctx, s32 x, s32 y, s32 w, s32 h, void *src);
int Func225088();
int Func2250C0();
// @decl-end

INCLUDE_ASM("asm/nonmatchings/IAlbumMgr", func_0016D548);

void CAlbumMgrSub16D618::Reset() {
    m_unk5C = 0;
    m_unk64 = 0;
    m_unk60 = 0;
    m_unk200 = -1;
    m_unk20C = 0;
    m_unk204 = 0;
    m_unk208 = 0;
    m_unk210 = 0;
    m_unk214 = 0;
    m_unk218 = 0;
    m_unk8.Init();
    m_unkD8 = 0;
}

INCLUDE_ASM("asm/nonmatchings/IAlbumMgr", func_0016D660);

INCLUDE_ASM("asm/nonmatchings/IAlbumMgr", func_0016D768);

INCLUDE_ASM("asm/nonmatchings/IAlbumMgr", func_0016D870);

INCLUDE_ASM("asm/nonmatchings/IAlbumMgr", func_0016D940);

INCLUDE_ASM("asm/nonmatchings/IAlbumMgr", func_0016D988);

void Blit16DA20(u64 tex, s32 a, s32 b, s32 w, s32 y, s32 h, u8 *base) {
    func_00227BF0(tex, a, b, w, h, base + y * func_002539A0((s32)((tex >> 32) & 0x3F)) * w / 8);
}

INCLUDE_ASM("asm/nonmatchings/IAlbumMgr", func_0016DAD0);

INCLUDE_ASM("asm/nonmatchings/IAlbumMgr", func_0016DEE8);

INCLUDE_ASM("asm/nonmatchings/IAlbumMgr", func_0016DFA8);

INCLUDE_ASM("asm/nonmatchings/IAlbumMgr", Func16E008__18CPhotoEventObjSub8iii);

INCLUDE_ASM("asm/nonmatchings/IAlbumMgr", Func16E280__10CUnk16E280);

INCLUDE_ASM("asm/nonmatchings/IAlbumMgr", Func16E518__10CUnk16E280);

INCLUDE_ASM("asm/nonmatchings/IAlbumMgr", func_0016E688);

void FillBorder16E830(u32 *buf, s32 w, s32 h, s32 t, u32 val) {
    u32 *p = buf;
    u32 *q = buf + (h - t - 1) * w;
    s32 i, j;
    for (i = w * t; i > 0; i--) {
        *p++ = val;
        *q++ = val;
    }
    p = buf;
    q = buf + w - t - 1;
    for (i = h; i > 0; i--) {
        for (j = t; j > 0; j--) {
            *p++ = val;
            *q++ = val;
        }
        p += w - t;
        q += w - t;
    }
}

void ClearBorder16E8E0(u32 *buf, s32 w, s32 h) {
    u32 *p = buf;
    u32 *q = buf + (h - 1) * w;
    s32 i;
    for (i = w; i > 0; i--) {
        *p++ = 0;
        *q++ = 0;
    }
    p = buf;
    q = buf + w - 1;
    for (i = h; i > 0; i--) {
        *p = 0;
        *q = 0;
        p += w;
        q += w;
    }
}

INCLUDE_ASM("asm/nonmatchings/IAlbumMgr", func_0016E960);

INCLUDE_ASM("asm/nonmatchings/IAlbumMgr", func_0016EB68);

INCLUDE_ASM("asm/nonmatchings/IAlbumMgr", func_0016F568);

INCLUDE_ASM("asm/nonmatchings/IAlbumMgr", func_0016FBF8);

int Blit16FE20(u32 *buf, s32 x, s32 y, s32 w, s32 h) {
    u32 *lower = buf + w * h / 2;
    Func225088();
    func_00227CB8(func_00251488(), x, y, w, h / 2, buf);
    func_00227CB8(func_00251488(), x, y + h / 2, w, h / 2, lower);
    return Func2250C0();
}

INCLUDE_ASM("asm/nonmatchings/IAlbumMgr", func_0016FEE0);

INCLUDE_ASM("asm/nonmatchings/IAlbumMgr", func_001702E0);

CPhotoDBMgr *CPhotoDBMgr::Create() {
    CPhotoDBMgr *p = (CPhotoDBMgr *)operator new(0x24);
    func_001704F8(p);
    return p;
}
