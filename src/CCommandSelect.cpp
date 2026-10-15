#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
//@sym memset 0x289FB0
#include "libc.h"
class CCommandSelectSub1990E0 {
public:
    void Clear();

    u8 pad0[0x4F0];
    u8 m_data[0x40];          // 0x4F0
};

#include "CCommandBase.h"
#include "CFlagWork.h"
extern CFlagWork *D_002A4B60;
extern "C" void func_00196B50(void *p);
// Vtable 0x2C1A60: Update (key method, 0x1986A8) and Draw.
class CCommandSelect : public CCommandBase {
public:
    CCommandSelect();
    virtual s32 Update();
    virtual s32 Draw();
    void Func199108(s32 k, f32 x, f32 y, f32 w, f32 h);
    void Func199150(f32 *x, f32 *y, f32 *w, f32 *h, s32 n);
    void Func1992E0(s32 a, s32 b);
    void Func1993A0(s32 k, s32 n);

    u8 pad4EC[0x54];
};

// The command list's records as CCommandSelect's code sees them (CCommandBaseRec, 0x48 bytes).
struct CCmdRec {
    s32 m0;                   // 0x00
    s32 m4;                   // 0x04
    s32 m8;                   // 0x08
    s32 mC;                   // 0x0C
    u8 pad10[0x28];
    s32 m38;                  // 0x38
    u8 pad3C[0xC];
};
class CCommandRecs {
public:
    void ClearRec(s32 i);
    u8 pad0[0x50];
    CCmdRec m_recs[16];       // 0x50
};

class CMenuRecordList {
public:
    s32 PageCol(s32 n);
};
class CMenuRecordSub196E68 {
public:
    f32 GetWinValueA();
    f32 GetWinValueB();
};
class CMenuRecordWin {
public:
    void Func1A39A8(f32 *v, s32 *n, s32 k);
    void Func1A3B58(f32 *v, s32 *n, s32 k);
};
// @decl-end

INCLUDE_RODATA("asm/nonmatchings/CCommandSelect", D_002DD928);
INCLUDE_RODATA("asm/nonmatchings/CCommandSelect", D_002DD940);
INCLUDE_RODATA("asm/nonmatchings/CCommandSelect", D_002DD960);
INCLUDE_RODATA("asm/nonmatchings/CCommandSelect", D_002DD9A0);
CCommandSelect::CCommandSelect() {
    func_00196B50(this);
}

INCLUDE_ASM("asm/nonmatchings/CCommandSelect", Update__14CCommandSelect);

INCLUDE_ASM("asm/nonmatchings/CCommandSelect", Draw__14CCommandSelect);

void CCommandRecs::ClearRec(s32 i) {
    memset(&m_recs[i], 0, sizeof(CCmdRec));
    m_recs[i].m38 = 4;
    m_recs[i].mC = -1;
    m_recs[i].m8 = -1;
}

INCLUDE_ASM("asm/nonmatchings/CCommandSelect", func_00198CE0);

#if 0 // DIFF 1 (g1): retail bnez with the next index's sll in the slot, ours bnezl; Insert 0x198CE0 is the mirror (k >= 16 is an unsigned test)
void CCommandRecs::Remove(s32 k) {
    s32 i, n;
    if (k < 0 || m_num - 1 < k || (u32)k >= 16) return (void)Func235DE0(D_002DD9C8, k);
    for (i = k; i < m_num; i++) m_recs[i] = m_recs[i + 1];
    ClearRec(m_num - 1);
    n = m_num - 1;
    if (n < 0) n = 0;
    m_num = n;
}
#endif
INCLUDE_ASM("asm/nonmatchings/CCommandSelect", func_00198E40);

INCLUDE_ASM("asm/nonmatchings/CCommandSelect", func_00198FA0);

void CCommandSelectSub1990E0::Clear() {
    memset(m_data, 0, sizeof(m_data));
}

INCLUDE_ASM("asm/nonmatchings/CCommandSelect", Func199108__14CCommandSelectiffff);

void CCommandSelect::Func199150(f32 *x, f32 *y, f32 *w, f32 *h, s32 n) {
    f32 v[3];
    f32 sx, sy;
    s32 col = ((CMenuRecordList *)this)->PageCol(n);
    *x = ((CMenuRecordSub196E68 *)this)->GetWinValueA();
    *w = ((CMenuRecordSub196E68 *)this)->GetWinValueB();
    (*(CMenuRecordWin **)((u8 *)this + 0x48))->Func1A39A8(&v[2], (s32 *)y, col);
    (*(CMenuRecordWin **)((u8 *)this + 0x48))->Func1A3B58(&v[2], (s32 *)&v[0], col);
    (*(CMenuRecordWin **)((u8 *)this + 0x48))->Func1A3B58(&v[2], (s32 *)&v[1], col + 1);
    *h = v[0] + v[1];
    sx = (f32)D_002A4B60->Func1091B0(0x3F) / 100.0f;
    sy = (f32)D_002A4B60->Func1091B0(0x40) / 100.0f;
    *x = *x - (*w * sx - *w) * 0.5f;
    *y = *y - (*h * sy - *h) * 0.5f;
    *w = *w * sx;
    *h = *h * sy;
}

void CCommandSelect::Func1992E0(s32 a, s32 b) {
    f32 x, y, w, h;
    f32 t;
    Func199150(&x, &y, &w, &h, m_cursor - 3);
    t = (f32)a / (f32)b;
    if (t > 1.0f) t = 1.0f;
    Func199108(0, x + w * 0.5f * (1.0f - t), y, w * t, h);
}

void CCommandSelect::Func1993A0(s32 k, s32 n) {
    f32 x, y, w, h;
    if (k == 0) {
        Func199150(&x, &y, &w, &h, m_cursor - 3);
        h = (f32)D_002A4B60->Func1091B0(0x3D);
        Func199108(0, x, y, w, h);
    } else {
        f32 t = 1.0f - (f32)k / (f32)n;
        if (t < 0.0f) t = 0.0f;
        Func199150(&x, &y, &w, &h, m_cursor - 3);
        h = (f32)D_002A4B60->Func1091B0(0x3D);
        w *= 0.5f;
        Func199108(0, x, y, w * t, h);
        Func199108(1, x + w + w * (1.0f - t), y, w * t, h);
    }
}

INCLUDE_ASM("asm/nonmatchings/CCommandSelect", func_00199500);

INCLUDE_ASM("asm/nonmatchings/CCommandSelect", func_00199BC0);

INCLUDE_ASM("asm/nonmatchings/CCommandSelect", func_0019A480);
