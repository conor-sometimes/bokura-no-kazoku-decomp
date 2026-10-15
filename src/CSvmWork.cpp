#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
struct CSvmRand {
    CSvmRand() { m_seed = 1; }
    u32 m_seed;
    u32 Next() {
        m_seed = m_seed * 0x19660D + 1;
        return (m_seed >> 12) & 0xFFFF;
    }
};
#include "libc.h"
//@sym SetInt__6CValuei 0x12E0C8
//@sym SetFloat__6CValuef 0x12E130
//@sym Set12E1D8__6CValuei 0x12E1D8
// A tagged value: 0 = int, 1 = float, 2 = string-like (converted by a helper).
class CValue {
public:
    void Reset();                // 0x12E0B8
    void SetInt(s32 v);          // 0x12E0C8
    void SetFloat(f32 v);        // 0x12E130
    void Set12E1D8(s32 v);       // 0x12E1D8, argument type unknown
    int AsInt();                 // 0x12E260
    float AsFloat();             // 0x12E2D8
    int Get12E350();             // 0x12E350, return type unknown

    s32 m_type;                  // 0x0
    s32 m_value;                 // 0x4
    u8 pad8[0xFC];
};

class CValueHolder {
public:
    s32 GetField5F0();
    int ValueAsInt();
    float ValueAsFloat();
    int Value12E350();

    u8 pad0[0x5F0];
    s32 m_field5F0;              // 0x5F0
    CValue m_value;              // 0x5F4
};

// Script data: 0xC = size of the work buffer, 0x10/0x14 = table of buffer slots.
class CSvmSlotDef {
public:
    s8 m_type;                // 0x0
    s8 m_size;                // 0x1
    s16 m_offset;             // 0x2
};

class CSvmData {
public:
    u8 pad0[0x4];
    s32 *m_labels;            // 0x4
    s32 m_numLabels;          // 0x8
    s32 m_bufSize;            // 0xC
    CSvmSlotDef *m_slots;     // 0x10
    s32 m_numSlots;           // 0x14
    s32 m_codeBase;           // 0x18
};

class CSvmWorkSub5A4 {
public:
    CSvmWorkSub5A4() { m4 = -1; m2 = 0; m0 = 0; }
    void Init() { m4 = -1; m2 = 0; m0 = 0; }
    s16 m0;                   // 0x0
    s16 m2;                   // 0x2
    s32 m4;                   // 0x4
    s32 m8[16];               // 0x8
};

// Script host object called back through a pointer to member (m_host->*m_cb).
class CSvmWork;
class CSvmHost {
public:
    virtual void V0();
};
typedef int (CSvmHost::*CSvmCallback)(CSvmWork *w, int a, int b);
class CSvmWork {
public:
    CSvmWork();
    virtual ~CSvmWork();
    int Callback130048(int a, int b);
    f32 SlotAsFloat(s32 i, f32 def);
    void Restore12FF48();
    void Save12FE60();
    void StoreSlot(s32 i, CValue *v);
    void LoadSlot(s32 i, CValue *v);
    void *SlotPtr(s32 i);
    s32 SlotType(s32 i);
    void Pop12EC18(s32 a, CValue *v);
    void Push12EB68(s32 a, CValue *v);
    void Jump12ECE0(s32 k, s32 push);
    int Fatal(const char *fmt, ...);
    void Trace(const char *fmt, ...);
    int IsListActive() { return m_list && m_listMax > 0; }
    void Init130138(s32 x);
    void Push131E90(s32 v);
    s32 Lookup131E20(s32 v);
    s32 Find131D90(s32 v);
    void CopyFrom(CSvmWork *o);
    void WriteBuf(s32 i, void *src, s32 n);
    s32 SlotGetStr(s32 i, char *dst, s32 n, char *def);
    int SlotAsInt(s32 i, s32 def);
    s32 GetSlotUnk708(s32 i);
    int IsBadSlot(s32 i);
    void Func12E858();
    void Unload12E968();
    int Load12E910(CSvmData *data);
    int IsVarZero(u32 i);
    void CallFunc12E9D8(s32 a, s32 v);
    void Func12E9D8(s32 a, s32 *p, s32 n);
    void ClearVar(u32 i);
    void Func12EA98(s32 a, s32 b, s32 c);
    void CallFunc12EA98(s32 a, s32 b);
    void ClearUnk47C();
    void SetResultInt(s32 v);
    void SetResultFloat(f32 v);
    void SetResult12E1D8(s32 v);

    CSvmData *m_data;         // 0x0
    CSvmRand m_rand;          // 0x4
    CSvmWorkSub5A4 m_unk8;    // 0x8
    CSvmHost *m_host;         // 0x50
    CSvmCallback m_cb;        // 0x54
    s32 m_unk5C;              // 0x5C
    u8 m_unk60[0x8];          // 0x60
    s32 m_trace;              // 0x68
    s32 m_unk6C;              // 0x6C
    char m_msg[0x400];        // 0x70
    s32 m_unk470;             // 0x470
    s32 *m_bases;             // 0x474
    s32 *m_vars;              // 0x478
    s32 m_unk47C;             // 0x47C
    s32 m_unk480;             // 0x480
    s32 m_unk484;             // 0x484
    u8 pad488[0x114];
    void *m_buf;              // 0x59C
    s32 m_unk5A0;             // 0x5A0
    CSvmWorkSub5A4 m_unk5A4;  // 0x5A4
    s32 m_unk5EC;             // 0x5EC
    s32 m_unk5F0;             // 0x5F0
    CValue m_unk5F4;          // 0x5F4
    s32 m_unk6F8;             // 0x6F8
    s32 m_unk6FC;             // 0x6FC
    s32 m_unk700;             // 0x700
    s32 m_numSlots;           // 0x704
    s32 m_unk708[32];         // 0x708
    CValue m_slots[32];       // 0x788
    CValue m_result;          // 0x2808
    s32 m_unk290C;            // 0x290C
    s32 m_unk2910;            // 0x2910
    s32 m_unk2914;            // 0x2914
    s32 m_unk2918;            // 0x2918
    s32 m_randInt;            // 0x291C
    f32 m_randFloat;          // 0x2920
    s32 m_debug;              // 0x2924
    s32 *m_list;              // 0x2928
    s32 m_listMax;            // 0x292C
    s32 m_listNum;            // 0x2930
    s32 m_unk2934;            // 0x2934
    u8 m_unk2938[0x18];       // 0x2938 (a TArray; its inline ctor/dtor are library code)
    // vptr 0x2950
};

extern char D_002D5418[];
extern char D_002D5420[];

extern "C" unsigned int strlen(const char *s);
extern "C" void *memcpy(void *dst, const void *src, unsigned int n);
//@sym strlen 0x28B3E8
//@sym memcpy 0x289DFC
void *Func245D00(s32 size);
void Func24B600(char *dst, const char *src, s32 n);
void Func297728(void *list, s32 *v);
extern void (*D_002B91B0)(void *p);

typedef __builtin_va_list va_list;
extern "C" int vsprintf(char *buf, const char *fmt, va_list ap);
//@sym vsprintf 0x28F338
extern "C" double fmod(double x, double y);
//@sym fmod 0x280260
//@sym __extendsfdf2 0x284B98
//@sym __truncdfsf2 0x285498
int Func235DE0(const char *fmt, ...);
s32 Func297708(void *list);
s32 *Func297710(void *list, s32 i);
void Func2976E8(void *list, s32 v);
extern s32 D_002A0BF0[];
extern char D_002D5218[];
extern char D_002D5240[];
extern char D_002D5268[];
extern char D_002D52A0[];
extern char D_002D53D0[];
extern char D_002D53F0[];
extern char D_002D5400[];
// Random integer in [lo, hi] from two 16-bit LCG draws (inlined at each use).
inline s32 RandRange(CSvmRand *rnd, s32 lo, s32 hi) {
    if (lo == hi) return lo;
    return ((rnd->Next() << 16) | rnd->Next()) % (u32)(hi - lo + 1) + lo;
}

extern "C" void func_00297668(void *arr);
// @decl-end


CSvmWork::CSvmWork() {
    s32 i;
    func_00297668(m_unk2938);
    m_data = 0;
    m_trace = 0;
    m_unk470 = 0;
    m_host = 0;
    memset(&m_cb, 0, sizeof(m_cb));
    m_unk5C = 0;
    memset(m_unk60, 0, 8);
    m_bases = (s32 *)Func245D00(0xC);
    m_vars = (s32 *)Func245D00(0xC);
    for (i = 0; i < 3; i++) {
        m_bases[i] = (s32)Func245D00(D_002A0BF0[i]);
        m_vars[i] = 0;
    }
    m_unk290C = 1;
    m_randInt = -1;
    m_randFloat = -1.0f;
    m_buf = 0;
    m_unk2910 = 0;
    m_debug = 0;
    m_list = 0;
    m_listMax = 0;
    m_listNum = 0;
    m_unk2934 = 0;
    Func2976E8(m_unk2938, 0);
    Func12E858();
}

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_0012E768);

void CSvmWork::Func12E858() {
    m_unk8.Init();
    m_unk6C = 0;
    for (s32 i = 0; i < 3; i++) {
        m_vars[i] = 0;
    }
    if (m_buf) {
        memset(m_buf, 0, m_data->m_bufSize);
    }
    m_unk47C = 1;
    m_unk480 = m_data ? m_data->m_codeBase : 0;
    m_unk484 = -1;
    m_unk2914 = 0;
    m_unk2918 = 0;
    m_listNum = 0;
    m_unk2934 = 0;
    Func2976E8(m_unk2938, 0);
}

int CSvmWork::Load12E910(CSvmData *data) {
    Unload12E968();
    m_data = data;
    m_buf = Func245D00(data->m_bufSize);
    Func12E858();
    if (m_unk480 == 0) {
        m_unk47C = 0;
    }
    return 1;
}

void CSvmWork::Unload12E968() {
    Func12E858();
    if (m_buf) {
        D_002B91B0(m_buf);
        m_buf = 0;
    }
    m_data = 0;
}

void CSvmWork::ClearVar(u32 i) {
    if (i < 3) {
        m_vars[i] = 0;
    }
}

void CSvmWork::Func12E9D8(s32 i, s32 *p, s32 n) {
    if ((u32)i < 3) {
        if (D_002A0BF0[i] < m_vars[i] + n) {
            return (void)Fatal(D_002D5218, i);
        }
        memcpy((void *)(m_bases[i] + m_vars[i]), p, n);
        m_vars[i] += n;
    }
}

void CSvmWork::Func12EA98(s32 i, s32 dst, s32 n) {
    if ((u32)i < 3) {
        s32 r = m_vars[i] - n;
        if (r < 0) {
            return (void)Fatal(D_002D5240, i);
        }
        m_vars[i] = r;
        memcpy((void *)dst, (void *)(m_bases[i] + m_vars[i]), n);
    }
}

void CSvmWork::CallFunc12E9D8(s32 a, s32 v) {
    Func12E9D8(a, &v, 4);
}

void CSvmWork::CallFunc12EA98(s32 a, s32 b) {
    Func12EA98(a, b, 4);
}

void CSvmWork::Push12EB68(s32 a, CValue *v) {
    switch (v->m_type) {
    case 0:
    case 1:
        CallFunc12E9D8(a, v->m_value);
        break;
    case 2: {
        s32 len = strlen((char *)&v->m_value) + 1;
        Func12E9D8(a, &v->m_value, len);
        CallFunc12E9D8(a, len);
        break;
    }
    }
    CallFunc12E9D8(a, v->m_type);
}

void CSvmWork::Pop12EC18(s32 a, CValue *v) {
    CallFunc12EA98(a, (s32)v);
    switch (v->m_type) {
    case 0:
    case 1:
        CallFunc12EA98(a, (s32)&v->m_value);
        break;
    case 2: {
        s32 len;
        CallFunc12EA98(a, (s32)&len);
        Func12EA98(a, (s32)&v->m_value, len);
        break;
    }
    }
}

int CSvmWork::IsVarZero(u32 i) {
    if (i >= 3) {
        return 0;
    }
    return m_vars[i] < 1;
}

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_0012ECE0);

void CSvmWork::Trace(const char *fmt, ...) {
    if (m_trace) {
        char buf[1024];
        va_list ap;
        __builtin_stdarg_start(ap, fmt);
        vsprintf(buf, fmt, ap);
        Func235DE0(buf);
    }
}

int CSvmWork::Fatal(const char *fmt, ...) {
    va_list ap;
    __builtin_stdarg_start(ap, fmt);
    vsprintf(m_msg, fmt, ap);
    Func235DE0(m_msg);
    m_unk6C = 1;
    ClearUnk47C();
}

void CSvmWork::ClearUnk47C() {
    if (m_unk47C) {
        m_unk47C = 0;
    }
}

u32 ReadVarInt12EED0(u8 **pp) {
    u32 v = 0;
    u8 c;
    do {
        c = *(*pp)++;
        v = (v << 7) | (c & 0x7F);
    } while (c & 0x80);
    return v;
}

void ReadStr12EF08(u8 **pp, char *dst, s32 n) {
    while (**pp) {
        if (--n > 0) {
            *dst++ = **pp;
        }
        (*pp)++;
    }
    *dst = 0;
    (*pp)++;
}

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_0012EF68);

void CSvmWork::WriteBuf(s32 i, void *src, s32 n) {
    CSvmData *p = m_data;
    if (p == 0) {
        return;
    }
    if (i < 0 || i > p->m_numSlots - 1) {
        return;
    }
    s32 size = p->m_slots[i].m_size;
    if (n < size) size = n;
    memcpy((u8 *)m_buf + p->m_slots[i].m_offset, src, size);
}

s32 CSvmWork::SlotType(s32 i) {
    CSvmData *d = m_data;
    if (d == 0 || i < 0 || i > d->m_numSlots - 1) {
        return -1;
    }
    return d->m_slots[i].m_type;
}

void *CSvmWork::SlotPtr(s32 i) {
    CSvmData *d = m_data;
    if (d == 0 || i < 0 || i > d->m_numSlots - 1) {
        return 0;
    }
    return (u8 *)m_buf + d->m_slots[i].m_offset;
}

void CSvmWork::StoreSlot(s32 i, CValue *v) {
    switch (SlotType(i)) {
    case 0: {
        s32 x = v->AsInt();
        WriteBuf(i, &x, 4);
        break;
    }
    case 1: {
        f32 f = v->AsFloat();
        WriteBuf(i, &f, 4);
        break;
    }
    case 2: {
        char *s = (char *)v->Get12E350();
        WriteBuf(i, s, strlen(s) + 1);
        break;
    }
    }
}

void CSvmWork::LoadSlot(s32 i, CValue *v) {
    switch (SlotType(i)) {
    case 0:
        return v->SetInt(*(s32 *)SlotPtr(i));
    case 1:
        return v->SetFloat(*(f32 *)SlotPtr(i));
    case 2:
        v->Set12E1D8((s32)SlotPtr(i));
        break;
    }
}

int CSvmWork::SlotAsInt(s32 i, s32 def) {
    if (IsBadSlot(i)) {
        return def;
    }
    return m_slots[i].AsInt();
}

f32 CSvmWork::SlotAsFloat(s32 i, f32 def) {
    if (IsBadSlot(i)) {
        return def;
    }
    return m_slots[i].AsFloat();
}

s32 CSvmWork::SlotGetStr(s32 i, char *dst, s32 n, char *def) {
    char *s;
    if (IsBadSlot(i)) s = def; else s = (char *)m_slots[i].Get12E350();
    Func24B600(dst, s, n);
    return strlen(dst);
}

s32 CSvmWork::GetSlotUnk708(s32 i) {
    s32 r;
    if (IsBadSlot(i)) r = 0; else r = m_unk708[i];
    return r;
}

int CSvmWork::IsBadSlot(s32 i) {
    if (i < 0 || i > m_numSlots - 1 || m_slots[i].m_type < 0) {
        return 1;
    }
    return 0;
}

void CSvmWork::SetResultInt(s32 v) {
    m_result.SetInt(v);
}

void CSvmWork::SetResultFloat(f32 v) {
    m_result.SetFloat(v);
}

void CSvmWork::SetResult12E1D8(s32 v) {
    m_result.Set12E1D8(v);
}

void CSvmWork::Save12FE60() {
    s32 i;
    if (m_unk6FC < 0) {
        return;
    }
    for (i = m_numSlots - 1; i >= 0; i--) {
        Push12EB68(0, &m_slots[i]);
    }
    for (i = m_numSlots - 1; i >= 0; i--) {
        CallFunc12E9D8(0, m_unk708[i]);
    }
    CallFunc12E9D8(0, m_numSlots);
    CallFunc12E9D8(0, m_unk700);
    CallFunc12E9D8(0, m_unk6FC);
}

void CSvmWork::Restore12FF48() {
    s32 i;
    if (IsVarZero(0)) {
        m_numSlots = 0;
        m_unk700 = 0;
        m_unk6FC = -1;
        return;
    }
    CallFunc12EA98(0, (s32)&m_unk6FC);
    CallFunc12EA98(0, (s32)&m_unk700);
    CallFunc12EA98(0, (s32)&m_numSlots);
    for (i = 0; i < m_numSlots; i++) {
        CallFunc12EA98(0, (s32)&m_unk708[i]);
    }
    for (i = 0; i < m_numSlots; i++) {
        Pop12EC18(0, &m_slots[i]);
    }
}

int CSvmWork::Callback130048(int a, int b) {
    if (m_host && m_cb) {
        return (m_host->*m_cb)(this, a, b);
    }
    return 0;
}

s32 CValueHolder::GetField5F0() {
    return m_field5F0;
}

int CValueHolder::ValueAsInt() {
    return m_value.AsInt();
}

float CValueHolder::ValueAsFloat() {
    return m_value.AsFloat();
}

int CValueHolder::Value12E350() {
    return m_value.Get12E350();
}

void CSvmWork::Init130138(s32 x) {
    ClearVar(0);
    ClearVar(1);
    m_unk5A0 = x;
    m_unk5A4.Init();
    m_unk5EC = -1;
    m_unk5F0 = 1;
    m_unk5F4.Reset();
    m_unk6F8 = 1;
    m_unk6FC = -1;
    m_numSlots = 0;
    m_unk700 = 0;
}

void OpIntOr1301C0(CValue *a, CValue *b) {
    a->SetInt(a->AsInt() || b->AsInt());
}

void OpIntAnd130228(CValue *a, CValue *b) {
    a->SetInt(a->AsInt() && b->AsInt());
}

void OpIntEq130288(CValue *a, CValue *b) {
    a->SetInt(a->AsInt() == b->AsInt());
}

void OpIntNe1302E0(CValue *a, CValue *b) {
    a->SetInt(a->AsInt() != b->AsInt());
}

void OpIntGt130338(CValue *a, CValue *b) {
    a->SetInt(a->AsInt() > b->AsInt());
}

void OpIntLt130388(CValue *a, CValue *b) {
    a->SetInt(a->AsInt() < b->AsInt());
}

void OpIntGe1303D8(CValue *a, CValue *b) {
    a->SetInt(a->AsInt() >= b->AsInt());
}

void OpIntLe130430(CValue *a, CValue *b) {
    a->SetInt(a->AsInt() <= b->AsInt());
}

void OpIntMul130488(CValue *a, CValue *b) {
    a->SetInt(a->AsInt() * b->AsInt());
}

void OpIntDiv1304E0(CValue *a, CValue *b) {
    if (b->AsInt() == 0) {
        return (void)Func235DE0(D_002D53D0);
    }
    a->SetInt(a->AsInt() / b->AsInt());
}

void OpIntMod130578(CValue *a, CValue *b) {
    if (b->AsInt() == 0) {
        return (void)Func235DE0(D_002D53D0);
    }
    a->SetInt(a->AsInt() % b->AsInt());
}

void OpIntMulPct130610(CValue *a, CValue *b) {
    a->SetInt(a->AsInt() * b->AsInt() / 100);
}

void OpIntAdd130678(CValue *a, CValue *b) {
    a->SetInt(a->AsInt() + b->AsInt());
}

void OpIntSub1306C8(CValue *a, CValue *b) {
    a->SetInt(a->AsInt() - b->AsInt());
}

void OpIntRand130718(CValue *a, CValue *b, CSvmWork *w) {
    s32 lo = a->AsInt();
    s32 hi = b->AsInt();
    s32 r;
    if (hi < lo) hi = lo;
    if (w->m_randInt >= 0) r = w->m_randInt;
    else r = RandRange(&w->m_rand, lo, hi);
    if (w->m_debug) {
        Func235DE0(D_002D53F0, a->AsInt(), b->AsInt(), r);
    }
    a->SetInt(r);
}

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_00130830);

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_001308C8);

void OpFloatEq130958(CValue *a, CValue *b) {
    a->SetFloat(a->AsFloat() == b->AsFloat() ? 1.0f : 0.0f);
}

void OpFloatNe1309C0(CValue *a, CValue *b) {
    a->SetFloat(a->AsFloat() != b->AsFloat() ? 1.0f : 0.0f);
}

void OpFloatGt130A28(CValue *a, CValue *b) {
    a->SetFloat(a->AsFloat() > b->AsFloat() ? 1.0f : 0.0f);
}

void OpFloatLt130A90(CValue *a, CValue *b) {
    a->SetFloat(a->AsFloat() < b->AsFloat() ? 1.0f : 0.0f);
}

void OpFloatGe130AF8(CValue *a, CValue *b) {
    a->SetFloat(a->AsFloat() >= b->AsFloat() ? 1.0f : 0.0f);
}

void OpFloatLe130B60(CValue *a, CValue *b) {
    a->SetFloat(a->AsFloat() <= b->AsFloat() ? 1.0f : 0.0f);
}

void OpFloatMul130BC8(CValue *a, CValue *b) {
    a->SetFloat(a->AsFloat() * b->AsFloat());
}

void OpFloatDiv130C18(CValue *a, CValue *b) {
    if (b->AsFloat() == 0.0f) {
        return (void)Func235DE0(D_002D53D0);
    }
    a->SetFloat(a->AsFloat() / b->AsFloat());
}

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_00130CB0);

void OpFloatMulPct130D70(CValue *a, CValue *b) {
    a->SetFloat(a->AsFloat() * b->AsFloat() / 100.0f);
}

void OpFloatAdd130DD8(CValue *a, CValue *b) {
    a->SetFloat(a->AsFloat() + b->AsFloat());
}

void OpFloatSub130E28(CValue *a, CValue *b) {
    a->SetFloat(a->AsFloat() - b->AsFloat());
}

INCLUDE_ASM("asm/nonmatchings/CSvmWork", func_00130E78);

void OpStrOr130FB8(CValue *a, CValue *b) {
    a->Set12E1D8((s32)((*(char *)a->Get12E350() || *(char *)b->Get12E350()) ? D_002D5418 : D_002D5420));
}

void OpStrAnd131020(CValue *a, CValue *b) {
    a->Set12E1D8((s32)((*(char *)a->Get12E350() && *(char *)b->Get12E350()) ? D_002D5418 : D_002D5420));
}

void OpStrEq131088(CValue *a, CValue *b) {
    a->Set12E1D8((s32)(strcmp((char *)a->Get12E350(), (char *)b->Get12E350()) == 0 ? D_002D5418 : D_002D5420));
}

void OpStrNe131100(CValue *a, CValue *b) {
    a->Set12E1D8((s32)(strcmp((char *)a->Get12E350(), (char *)b->Get12E350()) != 0 ? D_002D5418 : D_002D5420));
}

void OpStrGt131178(CValue *a, CValue *b) {
    a->Set12E1D8((s32)(strcmp((char *)a->Get12E350(), (char *)b->Get12E350()) > 0 ? D_002D5418 : D_002D5420));
}

void OpStrLt1311F0(CValue *a, CValue *b) {
    a->Set12E1D8((s32)(strcmp((char *)a->Get12E350(), (char *)b->Get12E350()) < 0 ? D_002D5418 : D_002D5420));
}

void OpStrGe131268(CValue *a, CValue *b) {
    a->Set12E1D8((s32)(strcmp((char *)a->Get12E350(), (char *)b->Get12E350()) >= 0 ? D_002D5418 : D_002D5420));
}

void OpStrLe1312E0(CValue *a, CValue *b) {
    a->Set12E1D8((s32)(strcmp((char *)a->Get12E350(), (char *)b->Get12E350()) <= 0 ? D_002D5418 : D_002D5420));
}

void OpStrCopy131358(CValue *a, CValue *b) {
    a->Set12E1D8(b->Get12E350());
}

void OpStrCopy131390(CValue *a, CValue *b) {
    a->Set12E1D8(b->Get12E350());
}

void OpStrCopy1313C8(CValue *a, CValue *b) {
    a->Set12E1D8(b->Get12E350());
}

void OpStrCopy131400(CValue *a, CValue *b) {
    a->Set12E1D8(b->Get12E350());
}

void OpStrCat131438(CValue *a, CValue *b) {
    char buf[256];
    strcpy(buf, (char *)a->Get12E350());
    char *s = (char *)b->Get12E350();
    strcpy(buf + strlen(buf), s);
    a->Set12E1D8((s32)buf);
}

void OpStrCopy1314A0(CValue *a, CValue *b) {
    a->Set12E1D8(b->Get12E350());
}

void OpStrCopy1314D8(CValue *a, CValue *b) {
    a->Set12E1D8(b->Get12E350());
}

void OpIntCopy131510(CValue *a, CValue *b) {
    a->SetInt(b->AsInt());
}

void OpIntNeg131548(CValue *a, CValue *b) {
    a->SetInt(-b->AsInt());
}

void OpIntNot131580(CValue *a, CValue *b) {
    a->SetInt(!b->AsInt());
}

void OpFloatCopy1315B8(CValue *a, CValue *b) {
    a->SetFloat(b->AsFloat());
}

void OpFloatNeg1315F0(CValue *a, CValue *b) {
    a->SetFloat(-b->AsFloat());
}

void OpFloatNot131628(CValue *a, CValue *b) {
    a->SetFloat(b->AsFloat() == 0.0f ? 1.0f : 0.0f);
}

void OpStrCopy131678(CValue *a, CValue *b) {
    a->Set12E1D8(b->Get12E350());
}

void OpStrCopy1316B0(CValue *a, CValue *b) {
    a->Set12E1D8(b->Get12E350());
}

void OpStrCopy1316E8(CValue *a, CValue *b) {
    a->Set12E1D8(b->Get12E350());
}

INCLUDE_ASM("asm/nonmatchings/CSvmWork", Func131720__8CSvmWork);

void CSvmWork::CopyFrom(CSvmWork *o) {
    if (m_data != o->m_data) {
        return;
    }
    if (m_buf) {
        memcpy(m_buf, o->m_buf, m_data->m_bufSize);
    }
    m_rand = o->m_rand;
}

s32 CSvmWork::Find131D90(s32 v) {
    for (s32 i = 0; i < Func297708(m_unk2938) && i < m_listNum; i++) {
        if (*Func297710(m_unk2938, i) == v) {
            return i;
        }
    }
    return -1;
}

s32 CSvmWork::Lookup131E20(s32 v) {
    if (IsListActive()) {
        s32 k = Find131D90(v);
        if (k >= 0) {
            return m_list[k];
        }
        if (m_listNum < m_listMax) {
            return m_list[m_listNum];
        }
    }
    return -1;
}

void CSvmWork::Push131E90(s32 v) {
    if (IsListActive()) {
        if (Find131D90(v) < 0 && m_listMax > m_listNum) {
            Func297728(m_unk2938, &v);
            m_listNum++;
        }
    }
}
