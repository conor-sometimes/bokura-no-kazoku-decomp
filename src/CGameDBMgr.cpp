#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
#include "IGameDBMgr.h"

// Library class (0x248Bxx); its constructor and destructor link through aliases.ld.
class CPushBuf {
public:
    CPushBuf();
    ~CPushBuf();
    void Func248E00();
    int Func248EB0();
    void *Func248CC8(s32 size, s32 a, s32 b);
    s32 GetUsed() { return *(s32 *)(m_data + 4); }

    u8 m_data[0xC];
};
class CGameDBRec8 {
public:
    s32 m_id;                 // 0x0
    s32 m4;                   // 0x4
};
class CGameDBRec14 {
public:
    s32 m_id;                 // 0x0
    const char *m4;           // 0x4
    const char *m8;           // 0x8
    s32 mC;                   // 0xC
    s32 m10;                  // 0x10
};
class CGameDBRec1C {
public:
    s32 m_id;                 // 0x0
    const char *m4;           // 0x4
    const char *m8;           // 0x8
    s32 mC;                   // 0xC
    s32 m10;                  // 0x10
    s32 m14;                  // 0x14
    s32 m18;                  // 0x18
};
class CGameDBRec20 {
public:
    s32 m_id;                 // 0x0
    s32 m4;                   // 0x4
    char *m8;                 // 0x8
    const char *mC;           // 0xC
    s32 m10;                  // 0x10
    s32 m14;                  // 0x14
    s32 m18;                  // 0x18
    s32 m1C;                  // 0x1C
};
class CGameDBRec24 {
public:
    s32 m_id;                 // 0x0
    const char *m4;           // 0x4
    const char *m8;           // 0x8
    s32 mC;                   // 0xC
    u8 pad10[0x14];
};
class CGameDBRec28 {
public:
    s32 m_id;                 // 0x0
    const char *m4;           // 0x4
    const char *m8;           // 0x8
    s32 mC;                   // 0xC (bit mask)
    const char *m10;          // 0x10 (condition script)
    u8 pad14[0x14];
};
class CGameDBRec34 {
public:
    s32 m_id;                 // 0x0
    u8 pad4[0x30];
};
class CGameDBRec48 {
public:
    s32 m_id;                 // 0x0
    const char *m_names[17];  // 0x4
};
class CGameDBRec5C {
public:
    s32 m_id;                 // 0x0
    const char *m4;           // 0x4
    const char *m8;           // 0x8
    const char *mC;           // 0xC
    s32 m10;                  // 0x10
    s32 m14;                  // 0x14
    s32 m18;                  // 0x18
    s32 m1C;                  // 0x1C
    s32 m20;                  // 0x20
    s32 m24;                  // 0x24
    s32 m28;                  // 0x28
    s32 m2C;                  // 0x2C
    const char *m30;          // 0x30
    s32 m34;                  // 0x34
    s32 m38[3];               // 0x38
    s32 m44[3];               // 0x44
    s32 m50[3];               // 0x50
};
class CGameDBBits {
public:
    s32 m0;                   // 0x0
    s32 m_bits[5];            // 0x4
};
class CGameDBRec74 {
public:
    s32 m_id;                 // 0x0
    const char *m_names[13];  // 0x4
    s32 m38;                  // 0x38
    const char *m3C;          // 0x3C (condition script)
    const char *m40[13];      // 0x40 (condition scripts per name)
};
class CGameDBRecB0 {
public:
    s32 m_id;                 // 0x0
    u8 pad4[0x8];
    s32 mC;                   // 0xC
    s32 m10;                  // 0x10
    s32 m14;                  // 0x14
    s32 m18;                  // 0x18
    u8 pad1C[0x94];
};
class CGameDBRec24b {
public:
    s32 m0;                   // 0x0
    const char *m4;           // 0x4
    s32 m8[2][3];             // 0x8
    s32 m20;                  // 0x20
};
class CGameDBRec0C {
public:
    s32 m0;                   // 0x0
    CGameDBRec24b *m4;        // 0x4
    s32 m8;                   // 0x8
};
class CGameDBRec4C {
public:
    s32 m0;                   // 0x0
    s32 m4;                   // 0x4
    s32 m8[17];               // 0x8
};
class CGameDBItem14 {
public:
    s32 m0;                   // 0x0
    u8 pad4[0x10];
};
class CGameDBChara {
public:
    char *m_name;             // 0x0
    s32 m4;                   // 0x4
    CGameDBItem14 *m8;        // 0x8
    s32 mC;                   // 0xC
    s32 m10[36][23];          // 0x10
    u8 padD00[0x8];
    u8 mD08[0x14];            // 0xD08
    u8 mD1C[0x14];            // 0xD1C
    s32 mD30;                 // 0xD30
    s32 mD34;                 // 0xD34
    s32 mD38;                 // 0xD38
};
class CFlagWork {
public:
    int Func1091B0(s32 id);
    void Func108FF0(s32 id, s32 v);
};
extern CFlagWork *D_002A26E4;
// Vtable 0x2C0CC8 still asm. Release is declared first and never defined (it is the inline slot 0
// at 0x2998B8), so this unit never emits the vtable.
#include "IFlags.h"
#include "CUserFlagMgr.h"
extern s32 D_002A2D50[];
int Func1456A8(int name);
int IsFlagKind(int v);

class CGameDBMgr : public IGameDBMgr {
public:
    s32 Func14A620(void *data, const char *key, CGameDBRec4C **tbl, s32 *num);
    s32 Func148238(CGameDBRec34 *out, const char *text);
    s32 Func1485E8(CGameDBRec34 *out, char *name, s32 idx, s32 k, s32 k8);
    virtual void Release();
    s32 Func14EE18(s32 name);
    s32 Func14BD00(s32 a, s32 b, s32 *out, s32 max);
    void Func14FF30();
    s32 Func14CF78(s32 name);
    s32 Func14CC00(s32 *out, s32 name);
    s32 Func150680();
    s32 Func14F550(s32 name, s32 kind, s32 bit);
    s32 Func14F760(s32 name, s32 kind);
    s32 Func14FA08(s32 v, s32 flag);
    s32 Func14F830(s32 name, s32 kind, s32 bit);
    s32 Func14C048(s32 *ids, s32 *flags, s32 name);
    s32 Func14E660(s32 id, s32 a, s32 b);
    void Func14DB70(f32 *out, s32 name);
    s32 Func147130(const char *path);
    int Func1473B0();
    int Func147500();
    int Func1478E8();
    int Func148110();
    int Func148C50();
    int Func1490F8();
    int Func149670();
    int Func149DC8();
    int Func14A0F8();
    int Func14A370();
    int Func14A8C0();
    int Func14AAD0();
    int Func14AE30();
    int Func14B4C8();
    int Func14B890();
    s32 Func14D430(s32 *out, s32 name);
    s32 Func14D5F8(s32 *out, s32 name);
    s32 Func14C2B0(s32 *ids, s32 *flags, s32 name);
    s32 Func14C490(s32 *ids, s32 *flags, s32 name);
    CGameDBMgr();
    virtual ~CGameDBMgr();
    s32 Func14C998(s32 name);
    const char *Func14CA38(s32 name);
    const char *Func14D378(s32 name);
    s32 Func14FBB0(s32 name);
    s32 Func14FE60(s32 arg);
    s32 Func14FCC8(s32 i, s32 arg);
    s32 Func14F2A0(s32 name);
    s32 Func14F380(s32 name, s32 type);
    s32 Func14F918(s32 a, s32 b);
    int Func14CAF0(s32 id, s32 mask);
    s32 Func14F638(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
    s32 Func14C800(s32 *out, s32 name);
    s32 Func14C648(s32 *out, s32 name);
    s32 ParseTable148D70(const char ***out, const char *text, const char *key, s32 ncol);
    s32 Collect14BC20(s32 *out, s32 max);
    int TestBits14F478(s32 id);
    s32 Find20(s32 id);
    const char *GetName248(u32 a, s32 b);
    s32 FindType8();
    s32 FindType2();
    CGameDBRec24b *Get240(s32 i, s32 j);
    s32 GetNum240(s32 i);
    s32 Get150630(s32 a, s32 b, s32 c, s32 d);
    s32 Get1505E0(s32 a, s32 b, s32 c, s32 d);
    s32 Get150590(s32 a, s32 b, s32 c, s32 d);
    s32 Get150550(s32 a, s32 b, s32 c);
    s32 Func150348(s32 *out, s32 a, s32 b, s32 c, s32 d);
    s32 Func14ECD0(s32 key, s32 idx);
    s32 Func14EC50(s32 key, s32 idx);
    s32 Func14EDE0(CGameDBRec4C *tbl, s32 n, s32 key, s32 val, s32 idx);
    CGameDBRec4C *Find14ED50(CGameDBRec4C *tbl, s32 n, s32 key, s32 val);
    CGameDBRec74 *Find1C4(s32 id);
    CGameDBRec48 *Find38(s32 id);
    CGameDBRec24 *Find234(s32 id);
    CGameDBRec14 *Find220(s32 id);
    CGameDBRec1C *Find20C(s32 id);
    CGameDBRec28 *Find200(s32 id);
    CGameDBRecB0 *Find1E8(s32 id);
    CGameDBRec5C *Find1DC(s32 id);
    CGameDBRec34 *Find1D0(s32 id);
    s32 Func14C9F8(s32 v);
    CGameDBItem14 *GetCharaItem(s32 id, s32 j);
    s32 GetCharaD38(s32 id);
    s32 GetCharaD34(s32 id);
    s32 GetCharaD30(s32 id);
    u8 *GetCharaD1C(s32 id);
    u8 *GetCharaD08(s32 id);
    s32 GetChara4(s32 id);
    char *GetCharaName(s32 id);
    CGameDBRec20 *GetTbl250(s32 i);
    s32 GetUnk14(s32 i);
    CGameDBRec8 *GetUnk20(s32 i);
    void Func147020();
    void Init();
    s32 GetUnk24();
    int Func14EB20(s32 a, s32 b, s32 c);
    int CallFunc14EB20Minus(s32 a, s32 b);
    int CallFunc14EB20Plus(s32 a, s32 b);

    // vptr 0x0
    CPushBuf m_buf;           // 0x4
    s32 m_unk10;              // 0x10
    s32 *m_unk14;             // 0x14
    s32 m_unk18;              // 0x18
    s32 m_unk1C;              // 0x1C
    CGameDBRec8 *m_unk20;     // 0x20
    s32 m_unk24;              // 0x24
    s32 m_unk28;              // 0x28
    s32 m_unk2C;              // 0x2C
    CGameDBChara *m_charas;   // 0x30
    s32 m_unk34;              // 0x34
    CGameDBRec48 *m_tbl38;    // 0x38
    s32 m_num38;              // 0x3C
    s32 m_unk40;              // 0x40
    CGameDBBits m_bits[8];    // 0x44
    CGameDBBits m_bits104[8]; // 0x104
    CGameDBRec74 *m_tbl1C4;   // 0x1C4
    s32 m_num1C4;             // 0x1C8
    s32 m_unk1CC;             // 0x1CC
    CGameDBRec34 *m_tbl1D0;   // 0x1D0
    s32 m_num1D0;             // 0x1D4
    s32 m_max1D8;             // 0x1D8
    CGameDBRec5C *m_tbl1DC;   // 0x1DC
    s32 m_num1DC;             // 0x1E0
    s32 m_unk1E4;             // 0x1E4
    CGameDBRecB0 *m_tbl1E8;   // 0x1E8
    s32 m_num1E8;             // 0x1EC
    s32 m_unk1F0;             // 0x1F0
    s32 m_unk1F4;             // 0x1F4
    s32 m_unk1F8;             // 0x1F8
    s32 m_unk1FC;             // 0x1FC
    CGameDBRec28 *m_tbl200;   // 0x200
    s32 m_num200;             // 0x204
    s32 m_unk208;             // 0x208
    CGameDBRec1C *m_tbl20C;   // 0x20C
    s32 m_num20C;             // 0x210
    s32 m_unk214;             // 0x214
    CGameDBRec4C *m_tbl218;   // 0x218
    s32 m_num218;             // 0x21C
    CGameDBRec14 *m_tbl220;   // 0x220
    s32 m_num220;             // 0x224
    s32 m_unk228;             // 0x228
    CGameDBRec4C *m_tbl22C;   // 0x22C
    s32 m_num22C;             // 0x230
    CGameDBRec24 *m_tbl234;   // 0x234
    s32 m_num234;             // 0x238
    s32 m_unk23C;             // 0x23C
    CGameDBRec0C *m_tbl240;   // 0x240
    s32 m_num240;             // 0x244
    const char ***m_names248; // 0x248
    s32 *m_counts24C;         // 0x24C
    CGameDBRec20 *m_tbl250;   // 0x250
    s32 m_num250;             // 0x254
};

class CGameDBEntry {
public:


    s32 m_id;                 // 0x0
    u8 pad4[0x34];
    s32 m_order;              // 0x38
};

#include "libc.h"
//@sym Func14BB28__Fi 0x14BB28
extern char D_002D7D80[];
extern s32 D_002A2D30[];
extern char D_002D81F8[];
extern char D_002D8200[];
extern char D_002D8208[];
extern char D_002D8210[];
extern char D_002D8218[];
extern char D_002D8260[];
s32 Func14BB28(s32 id);
extern "C" s32 func_001456A8(s32 id);
s32 Func145738(s32 a, s32 b);
extern "C" char *strstr(const char *s, const char *sub);
extern "C" void *func_0024F2E8(s32 size);
extern "C" void func_00150A70(void *p, s32 v);
extern "C" void func_0024F5C0(void *a, void *b, s32 c);

// Linear search of a record table by its first field (inlined at each use).
template <class T> inline T *FindById(T *tbl, s32 n, s32 id) {
    for (s32 i = 0; i < n; i++, tbl++) {
        if (tbl->m_id == id) {
            return tbl;
        }
    }
    return 0;
}

extern char D_002D7D80[];

extern char D_002D8110[];
void Func235DE0(const char *fmt, ...);
extern s32 D_002A2D98[];
struct CGameDBNameRec {
    s32 m_id;                 // 0x0
    u8 pad4[0x10];
    const char *m_name;       // 0x14
};
struct CGameDBNameGroup {
    u8 pad0[0x2C];
    s32 m_num;                // 0x2C
    CGameDBNameRec *m_recs;   // 0x30
};

extern "C" void *func_00248CC8(void *buf, s32 size, s32 a, s32 b);
extern "C" char *func_00248DA8(void *buf);
extern "C" const char *func_00248DC0(void *buf);
extern "C" const char *func_0024AF10(const char *s, const char *key);
extern "C" s32 func_0024B040(const char *s, s32 k);
extern "C" const char *func_0024AFE8(const char *s, char *buf, s32 k, s32 size);
extern "C" const char *func_0024A570(const char *s, char *out, const char *a, const char *b);
extern char D_002D7EC0[];
extern char D_002D7EC8[];

// CFlagWork seen with its vptr (at 0x1C); slot 9 here.
class CFlagWorkV {
public:
    u8 pad0[0x1C];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual s32 V6();
    virtual void V7();
    virtual void V8();
    virtual s32 V9(s32 a, s32 b);
};

struct CGameDBRec18 {
    s32 m0;                   // 0x0
    s32 m4;                   // 0x4
    s32 m8;                   // 0x8
    s32 mC;                   // 0xC
    s32 m10;                  // 0x10
    s32 m14;                  // 0x14
};
int Func14FC70(s32 i, s32 bit);

extern "C" unsigned int strlen(const char *s);
extern "C" const char *func_0024AD10(const char *p, char *buf, s32 a, s32 n);
extern "C" char *func_00148400(char *s);

s32 Func147340(char **tbl, char *name);
const char *Func24A570(const char *s, char *out, const char *a, const char *b);
extern char *D_002A2998[];
extern s32 D_002A2A08[];
extern char D_002D80E0[];
extern char D_002D80E8[];
extern char D_002D80F8[];
extern "C" const char *func_0024AD10(const char *p, char *buf, s32 a, s32 n);

void *Func24A4C0(const char *name);
extern void (*D_002B91B0)(void *p);
const char *Func24AF10(void *p, const char *key);
const char *Func24AFE8(const char *s, char *buf, s32 k, s32 size);
extern "C" const char *func_0024A710(const char *p, s32 *v, s32 k, const char *s1, const char *s2);
const char *Func24A570(const char *s, char *out, const char *a, const char *b);
s32 Func147340(char **tbl, char *name);
extern "C" s32 func_002996C0(void *self, void *data, const char *key, void *tbl, s32 n, s32 z);
extern const char *D_002A2C90;
extern const char *D_002A2C94;
extern char *D_002A2A70[];
extern char D_002D84B8[];
extern char D_002D83D0[];

u32 Func149618(char *s);
extern const char *D_002A2C60;
extern const char *D_002A2C64;
extern char D_002D8410[];
extern char D_002D8420[];

extern const char *D_002A2C70;
extern const char *D_002A2C74;
extern char D_002D8478[];
extern char D_002D8488[];

const char *Func24A840(const char *s, char *out, const char *a, const char *b, int n);
extern char *D_002A2B98[];
extern s32 D_002A2BD8[];
extern char D_002D8268[];
extern char D_002D8270[];
extern char D_002D8288[];
extern char D_002D82A0[];
extern char D_002D82A8[];

extern "C" char *func_00248D98(void *buf);
s32 Func148EC8(s32 *types, s32 *vals, s32 *mults, s32 max, const char *s);

s32 Func24B998(const char **tbl, const char *s);
extern const char *D_002A2D08[];
extern const char *D_002A2D18[];
extern char D_002D7F38[];
extern char D_002D8658[];

extern const char *D_002A2A9C;
extern const char *D_002A2AA0;
extern char D_002D7ED0[];

extern "C" void *func_0024A4A0(const char *name);
extern const char *D_002A2B60;
extern const char *D_002A2B68[];
extern s32 D_002A2B80[];
extern char D_002D81E8[];

class CGameDBEntry;
int CompareGameDBEntries(const CGameDBEntry *a, const CGameDBEntry *b);
extern "C" void func_0028A140(void *base, s32 n, s32 size, int (*cmp)(const CGameDBEntry *, const CGameDBEntry *));
extern const char *D_002A2CC4;
extern const char *D_002A2CC8;
extern const char *D_002A2CD0[];
extern char D_002D85F8[];

extern "C" s32 func_00299510(void *self, void *data, const char *key, void *tbl, s32 n, s32 z);
extern const char *D_002A2C50;
extern const char *D_002A2C54;
extern const char *D_002A2C58;
extern char D_002D83C0[];

extern "C" void func_0024B190(const char *s, const char *key, char *out, const char *def, s32 size);
extern "C" s32 func_00248D38(void *buf, const char *s);
int FindFlagIdByName(const char *s);
extern const char *D_002A2AA8[];
extern const char *D_002A2AD0;
extern const char *D_002A2AD4;
extern const char *D_002A2AD8;
extern char *D_002A2AB8[];
extern char D_002D7F50[], D_002D7F68[], D_002D7F70[], D_002D7F90[];

// The system flags (D_002A26E0) seen with their vptr (at 0x1C); slot 9 tests a bit.
class CSysFlagV {
public:
    u8 pad0[0x1C];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual int GetBit144070(u32 a, u32 b, u32 c, u32 bit);
};
extern CSysFlagV *D_002A26E0;
extern "C" int strncmp(const char *a, const char *b, unsigned int n);
struct CGameDBEvSub {
    u8 pad0[0xC];
    s32 mC;
    u8 pad10[0x4];
    const char *m14;
};
struct CGameDBEv34 {
    s32 m_id;
    s32 m4;
    u8 pad8[0x4];
    s32 mC;
    s32 m10;
    s32 m14;
    s32 m18;
    u8 pad1C[0x10];
    s32 m2C;
    CGameDBEvSub *m30;
};

int CompareGameDBIds(const s32 *a, const s32 *b);
struct CGameDBRec48v {
    s32 m_id;
    u8 pad4[0x18];
    s32 m1C;
    u8 pad20[0x4];
    s32 m24;
    s32 m28;
    const char *m2C;
};
struct CGameDBSortEnt {
    s32 key;
    CGameDBRec48v *rec;
};

extern s32 D_002A2D70[];
#define GN(b) ((ICurFlag *)D_002A26E4)->GetNamed(b, k)

extern char D_002D88C8[];

int IsFlagKind(int k);
struct CGameDBEv34b {
    s32 m_id;
    s32 m4;
    u8 pad8[0xC];
    s32 m14;
    s32 m18;
    s32 m1C;
    s32 m20;
};

extern const char *D_002A2C9C;
extern const char D_002D82D0[], D_002D82D8[], D_002D82F8[], D_002D8318[];
extern s32 D_002A29D0[], D_002A2A58[];
extern char *D_002A2A40[];
// @decl-end

CGameDBMgr::CGameDBMgr() {
    D_002A2988 = this;
    m_unk10 = 0;
    Func147020();
}

CGameDBMgr::~CGameDBMgr() {
    Init();
    D_002A2988 = 0;
}

void CGameDBMgr::Func147020() {
    m_unk14 = 0;
    m_unk18 = 0;
    m_unk1C = (s32)D_002D7D80;
    m_unk20 = 0;
    m_unk24 = 0;
    m_unk28 = 0;
    m_unk2C = 0;
    m_charas = 0;
    m_unk34 = 0;
    m_tbl38 = 0;
    m_num38 = 0;
    m_unk40 = 0;
    memset(m_bits, 0, sizeof(m_bits));
    memset(m_bits104, 0, sizeof(m_bits104));
    m_tbl1C4 = 0;
    m_num1C4 = 0;
    m_unk1CC = 0;
    m_tbl1D0 = 0;
    m_num1D0 = 0;
    m_max1D8 = 0;
    m_tbl1DC = 0;
    m_num1DC = 0;
    m_unk1E4 = 0;
    m_tbl1E8 = 0;
    m_num1E8 = 0;
    m_unk1F0 = 0;
    m_unk1F4 = 0;
    m_unk1F8 = 0;
    m_unk1FC = 0;
    m_tbl200 = 0;
    m_num200 = 0;
    m_unk208 = 0;
    m_tbl20C = 0;
    m_num20C = 0;
    m_unk214 = 0;
    m_tbl218 = 0;
    m_num218 = 0;
    m_tbl220 = 0;
    m_num220 = 0;
    m_unk228 = 0;
    m_tbl22C = 0;
    m_num22C = 0;
    m_tbl234 = 0;
    m_num234 = 0;
    m_unk23C = 0;
    m_tbl240 = 0;
    m_num240 = 0;
    m_names248 = 0;
    m_counts24C = 0;
    m_tbl250 = 0;
    m_num250 = 0;
}

INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7D80);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7D88);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7D90);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7D98);
INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_00147130);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7DD0);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7DD8);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7DE0);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7DE8);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7DF0);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7DF8);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7E00);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7E08);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7E10);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7E18);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7E20);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7E28);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7E30);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7E38);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7E40);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7E48);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7E50);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7E58);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7E60);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7E68);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7E70);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7E78);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7E80);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7E88);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7E90);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7E98);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7EA0);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7EB0);

s32 Func147340(char **tbl, char *name) {
    for (s32 i = 0; tbl[i]; i++) {
        if (strcmp(tbl[i], name) == 0) {
            return i;
        }
    }
    return -1;
}

int CGameDBMgr::Func1473B0() {
    char line[256];
    char tok[256];
    s32 i;
    int ok = 0;
    m_unk18 = 0;
    m_unk14 = 0;
    void *data = Func24A4C0(D_002A2A9C);
    if (data) {
        const char *p = Func24AF10(data, D_002A2AA0);
        if (*p) {
            m_unk18 = 4;
            m_unk14 = (s32 *)func_00248CC8(&m_buf, m_unk18 * 4, 1, 1);
            for (i = 0; i < m_unk18; i++) {
                p = Func24AFE8(p, line, 1, 0x100);
                Func24A570(line, func_00248DA8(&m_buf), D_002D7EC0, D_002D7EC8);
                m_unk14[i] = (s32)func_00248DC0(&m_buf);
            }
        }
        ok = 1;
    }
    if (data) D_002B91B0(data);
    Func235DE0(D_002D7ED0, ok);
    return ok;
}

INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7EC0);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7EC8);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7ED0);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7EE0);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7EF0);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7F00);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7F10);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7F18);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7F20);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7F28);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7F38);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7F40);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7F48);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7F50);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7F68);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7F70);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7F90);
int CGameDBMgr::Func147500() {
    char line[256];
    char tok[256];
    void *data;
    int ok;
    s32 i, j;
    const char *p;
    const char *q;
    data = 0;
    ok = 0;
    u32 k = D_002A26E4->Func1091B0(0x16);
    if (k < 3) {
        data = Func24A4C0(D_002A2AA8[k]);
        if (!data) goto out;
        p = Func24AF10(data, D_002A2AD0);
        if (*p) {
            func_0024B190(p, D_002A2AD4, line, D_002D7D80, 0x100);
            m_unk1C = func_00248D38(&m_buf, line);
        }
        p = Func24AF10(data, D_002A2AD8);
        if (*p) {
            m_unk24 = func_0024B040(p, 1);
            m_unk20 = (CGameDBRec8 *)func_00248CC8(&m_buf, m_unk24 * sizeof(CGameDBRec8), 1, 1);
            for (i = 0; i < m_unk24; i++) {
                CGameDBRec8 *r = &m_unk20[i];
                p = Func24AFE8(p, line, 1, 0x100);
                q = func_0024A710(line, &r->m_id, 0, D_002D7EC0, D_002D7EC8);
                Func24A570(q, tok, D_002D7EC0, D_002D7EC8);
                r->m4 = FindFlagIdByName(tok);
                if (r->m4 < 0) {
                    Func235DE0(D_002D7F50, tok);
                    goto end;
                }
            }
        }
        p = Func24AF10(data, D_002D7F68);
        if (*p) {
            m_unk2C = func_0024B040(p, 1);
            m_unk28 = (s32)func_00248CC8(&m_buf, m_unk2C * sizeof(CGameDBRec18), 1, 1);
            for (j = 0; j < m_unk2C; j++) {
                CGameDBRec18 *r = &((CGameDBRec18 *)m_unk28)[j];
                p = Func24AFE8(p, line, 1, 0x100);
                q = func_0024A710(line, &r->m0, 0, D_002D7EC0, D_002D7EC8);
                q = func_0024A710(q, &r->m4, 0, D_002D7EC0, D_002D7EC8);
                q = Func24A570(q, tok, D_002D7EC0, D_002D7EC8);
                r->m8 = Func147340(D_002A2AB8, tok);
                if (r->m8 < 0) {
                    Func235DE0(D_002D7F70, tok);
                    goto end;
                }
                q = Func24A570(q, tok, D_002D7EC0, D_002D7EC8);
                r->mC = FindFlagIdByName(tok);
                if (r->mC < 0) {
                    Func235DE0(D_002D7F50, tok);
                    goto end;
                }
                q = Func24A570(q, tok, D_002D7EC0, D_002D7EC8);
                r->m10 = FindFlagIdByName(tok);
                if (r->m10 < 0) {
                    Func235DE0(D_002D7F50, tok);
                    goto end;
                }
                func_0024A710(q, &r->m14, 0, D_002D7EC0, D_002D7EC8);
            }
        }
        ok = 1;
    }
end:
    if (data) D_002B91B0(data);
out:
    Func235DE0(D_002D7F90, ok);
    return ok;
}
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7FA0);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7FB0);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7FC0);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7FD0);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7FE0);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7FF0);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D7FF8);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8000);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8008);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8010);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8018);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8020);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8030);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8038);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8048);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8058);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8068);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8078);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_001478E8);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8098);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D80A8);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D80B8);

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_00148110);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D80E0);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D80E8);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D80F8);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8110);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8130);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8138);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8140);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8148);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8150);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8158);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8160);

s32 CGameDBMgr::Func148238(CGameDBRec34 *out, const char *text) {
    char line[256];
    char name[256];
    char tok[256];
    s32 total = 0;
    while (text = func_0024AD10(text, line, 1, 0x100), *text || line[0]) {
        const char *p = Func24A570(line, name, D_002D7EC0, D_002D7EC8);
        Func24A570(p, tok, D_002D7EC0, D_002D7EC8);
        s32 k;
        s32 idx = Func147340(D_002A2998, tok);
        if (idx >= 0) {
            idx = D_002A2A08[idx];
            k = idx - 11;
        } else if (strcmp(tok, D_002D80E0) == 0) {
            k = 4;
        } else if (strcmp(tok, D_002D80E8) == 0) {
            k = D_002A26E4->Func1091B0(0x16) + 1;
        } else {
            Func235DE0(D_002D80F8, tok);
            continue;
        }
        s32 r = Func1485E8(out ? out + total : 0, name, idx, k, k << 8);
        if (r < 0) return -1;
        total += r;
    }
    return total;
}

char *func_00148400(char *s) {
    while (*s) {
        s8 c = *(u8 *)s;
        if (c >= 0) {
            if (c == 0x5C && s[1] == 0) return s;
            s++;
        } else {
            s += 2;
        }
    }
    return 0;
}

const char *func_00148450(const char *s, char *buf, s32 n) {
char *p;
while (1) {
  s = func_0024AD10(s, buf, 1, n);
  p = func_00148400(buf);
  if (p) { n -= strlen(buf); buf = p; }
  else if (*buf == 0x5B) { *buf = 0; s += strlen(s); break; }
  else if (*s == 0 || *buf != 0) break;
}
return s;
}

s32 FindIdByName148510(CGameDBNameGroup *groups, s32 n, const char *name) {
    for (s32 i = 0; i < n; i++) {
        CGameDBNameGroup *g = &groups[i];
        for (s32 j = 0; j < g->m_num; j++) {
            CGameDBNameRec *r = &g->m_recs[j];
            if (strcmp(r->m_name, name) == 0) return r->m_id;
        }
    }
    Func235DE0(D_002D8110, name);
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", Func1485E8__10CGameDBMgrP12CGameDBRec34Pciii);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8188);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8190);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8198);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D81A8);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D81B8);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D81C8);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D81D8);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D81E8);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D81F8);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8200);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8208);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8210);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8218);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8220);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8228);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8230);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8238);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8240);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8248);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8250);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8258);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8260);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8268);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8270);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8288);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D82A0);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D82A8);

int CGameDBMgr::Func148C50() {
    s32 i;
    int ok = 0;
    m_counts24C = 0;
    m_names248 = 0;
    void *data = func_0024A4A0(D_002A2B60);
    if (data) {
        m_counts24C = (s32 *)func_00248CC8(&m_buf, 0x10, 1, 1);
        m_names248 = (const char ***)func_00248CC8(&m_buf, 0x10, 1, 1);
        for (i = 0; i < 4; i++) {
            m_counts24C[i] = ParseTable148D70(&m_names248[i], (const char *)data, D_002A2B68[i], D_002A2B80[i]);
        }
        ok = 1;
    }
    if (data) D_002B91B0(data);
    Func235DE0(D_002D81E8, ok);
    return ok;
}

s32 CGameDBMgr::ParseTable148D70(const char ***out, const char *text, const char *key, s32 ncol) {
    char line[256];
    const char *p = func_0024AF10(text, key);
    if (*p == 0) return 0;
    s32 n = func_0024B040(p, 1);
    s32 cnt = 0;
    *out = (const char **)func_00248CC8(&m_buf, n * ncol * 4, 1, 1);
    for (s32 i = 0; i < n; i++) {
        p = func_0024AFE8(p, line, 1, 0x100);
        const char *q = line;
        for (s32 j = 0; j < ncol; j++) {
            q = func_0024A570(q, func_00248DA8(&m_buf), D_002D7EC0, D_002D7EC8);
            (*out)[cnt++] = func_00248DC0(&m_buf);
        }
    }
    return cnt;
}

s32 Func148EC8(s32 *types, s32 *vals, s32 *mults, s32 max, const char *s) {
    char tok[256];
    char name[256];
    char word[256];
    s32 v;
    s32 n = 0;
    while (s = Func24A570(s, tok, D_002D8268, D_002D7EC8), *s || tok[0]) {
        if (n >= max) {
            Func235DE0(D_002D8270, n);
            return -1;
        }
        const char *q = Func24A840(tok, name, 0, D_002D7EC8, 0x100);
        s32 idx = Func147340(D_002A2B98, name);
        if (idx < 0) {
            Func235DE0(D_002D8288, tok);
            return -1;
        }
        s32 t = D_002A2BD8[idx];
        types[n] = t;
        if (t == 13) {
            q = Func24A570(q, 0, D_002D82A0, D_002D7EC8);
            func_0024A710(q, &vals[n], 0, D_002D7EC0, D_002D7EC8);
        } else {
            q = Func24A570(q, word, D_002D82A0, D_002D7EC8);
            s32 sign = 1;
            if (strcmp(word, D_002D82A8) == 0) sign = -1;
            func_0024A710(q, &v, 0, D_002D7EC0, D_002D7EC8);
            if (v < 0) sign = -sign;
            if (sign < 0) vals[n] = 0;
            else vals[n] = 1;
            mults[n] = sign * (v < 0 ? -v : v);
        }
        n++;
    }
    return n;
}

int CGameDBMgr::Func1490F8() {
    char line[256];
    char tok[256];
    char w[256];
    const char *p;
    void *data;
    s32 i;
    int ok;
    s32 k, n, idx;
    ok = 0;
    data = Func24A4C0("action.txt");
    if (data) {
        p = Func24AF10(data, "ACTION_INFO");
        if (*p) {
            m_num1DC = func_0024B040(p, 1);
            m_tbl1DC = (CGameDBRec5C *)m_buf.Func248CC8(m_num1DC * sizeof(CGameDBRec5C), 1, 1);
            m_unk1E4 = 0;
            for (i = 0; i < m_num1DC; i++) {
                CGameDBRec5C *r = &m_tbl1DC[i];
                const char *q, *s;
                p = Func24AFE8(p, line, 1, 0x100);
                for (k = 0; k < 3; k++) {
                    r->m38[k] = -1;
                    r->m44[k] = -1;
                    r->m50[k] = 0;
                }
                q = func_0024A710(line, &r->m_id, 0, D_002D7EC0, D_002D7EC8);
                m_unk1E4 = r->m_id < m_unk1E4 ? m_unk1E4 : r->m_id;
                q = Func24A570(q, func_00248DA8(&m_buf), D_002D7EC0, D_002D7EC8);
                r->m4 = func_00248DC0(&m_buf);
                q = Func24A570(q, func_00248DA8(&m_buf), D_002D7EC0, D_002D7EC8);
                r->m8 = func_00248DC0(&m_buf);
                q = func_0024A710(q, &r->m10, 1, D_002D7EC0, D_002D7EC8);
                q = Func24A570(q, func_00248DA8(&m_buf), D_002D7EC0, D_002D7EC8);
                r->mC = func_00248DC0(&m_buf);
                q = Func24A570(q, tok, D_002D7EC0, D_002D7EC8);
                s = tok;
                while ((s = Func24A570(s, w, D_002D82D0, D_002D7EC8), *s) || w[0]) {
                    idx = Func147340(D_002A2998, w);
                    if (idx < 0) {
                        Func235DE0(D_002D82D8, w);
                        idx = 0;
                    }
                    r->m14 |= D_002A29D0[idx];
                    r->m18 = D_002A2A08[idx];
                }
                q = func_0024A710(q, &r->m1C, 0, D_002D7EC0, D_002D7EC8);
                q = func_0024A710(q, &r->m20, 0, D_002D7EC0, D_002D7EC8);
                q = Func24A570(q, tok, D_002D7EC0, D_002D7EC8);
                if (tok[0]) {
                    s = tok;
                    while ((s = Func24A570(s, w, D_002D82D0, D_002D7EC8), *s) || w[0]) {
                        s32 kind = Func147340(D_002A2A40, w);
                        if (kind < 0) {
                            Func235DE0(D_002D82F8, w);
                            kind = 0;
                        }
                        r->m24 |= D_002A2A58[kind];
                        r->m28 = kind;
                    }
                } else {
                    r->m24 = 0xF;
                    r->m28 = 4;
                }
                q = func_0024A710(q, &r->m2C, 0, D_002D7EC0, D_002D7EC8);
                Func24A570(q, tok, D_002D7EC0, D_002D7EC8);
                n = D_002A0D38->V16(func_00248D98(&m_buf), tok);
                if (n >= 2) {
                    r->m30 = (const char *)m_buf.Func248CC8(n, 0, 0);
                    r->m34 = Func148EC8(r->m38, r->m44, r->m50, 3, tok);
                }
            }
            ok = 1;
        }
    }
    if (data) D_002B91B0(data);
    Func235DE0(D_002D8318, ok);
    return ok;
}
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D82D0);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D82D8);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D82F8);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8318);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8328);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8338);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8348);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8358);

u32 Func149618(char *s) {
    u32 r = 0;
    char *base = s;
    while (*s) {
        if (*s == '1') {
            r |= 1 << (s - base);
        }
        s++;
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_00149670);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8398);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D83A0);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D83B0);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D83C0);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D83D0);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D83E0);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D83F0);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8400);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8410);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8420);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8430);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8440);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8450);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8460);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8468);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8470);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8478);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8488);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8498);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D84A8);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D84B8);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D84C8);

int CGameDBMgr::Func149DC8() {
    char line[256];
    char tok[256];
    void *data;
    int ok;
    s32 i, n;
    ok = 0;
    data = Func24A4C0(D_002A2C50);
    if (data) {
        const char *p = Func24AF10(data, D_002A2C54);
        if (*p) {
            m_num200 = func_0024B040(p, 1);
            m_tbl200 = (CGameDBRec28 *)func_00248CC8(&m_buf, m_num200 * sizeof(CGameDBRec28), 1, 1);
            m_unk208 = 0;
            for (i = 0; i < m_num200; i++) {
                CGameDBRec28 *r = &m_tbl200[i];
                p = Func24AFE8(p, line, 1, 0x100);
                const char *q = func_0024A710(line, &r->m_id, 0, D_002D7EC0, D_002D7EC8);
                m_unk208 = r->m_id < m_unk208 ? m_unk208 : r->m_id;
                q = Func24A570(q, func_00248DA8(&m_buf), D_002D7EC0, D_002D7EC8);
                r->m4 = func_00248DC0(&m_buf);
                q = Func24A570(q, func_00248DA8(&m_buf), D_002D7EC0, D_002D7EC8);
                r->m8 = func_00248DC0(&m_buf);
            }
            p = Func24AF10(data, D_002A2C58);
            if (*p) {
                for (i = 0; i < m_num200; i++) {
                    CGameDBRec28 *r = &m_tbl200[i];
                    p = Func24AFE8(p, line, 1, 0x100);
                    const char *q = Func24A570(line, 0, D_002D7EC0, D_002D7EC8);
                    q = Func24A570(q, 0, D_002D7EC0, D_002D7EC8);
                    q = Func24A570(q, tok, D_002D7EC0, D_002D7EC8);
                    r->mC = Func149618(tok);
                    Func24A570(q, tok, D_002D7EC0, D_002D7EC8);
                    n = D_002A0D38->V16(func_00248D98(&m_buf), tok);
                    if (n >= 2) r->m10 = (const char *)func_00248CC8(&m_buf, n, 0, 0);
                }
                func_00299510(this, data, D_002D83C0, m_tbl200, m_num200, 0);
                ok = 1;
            }
        }
    }
    if (data) D_002B91B0(data);
    Func235DE0(D_002D83D0, ok);
    return ok;
}

int CGameDBMgr::Func14A0F8() {
    char line[256];
    char tok[256];
    s32 i;
    int ok = 0;
    void *data = Func24A4C0(D_002A2C60);
    if (data) {
        const char *p = Func24AF10(data, D_002A2C64);
        if (*p) {
            m_num20C = func_0024B040(p, 1);
            m_tbl20C = (CGameDBRec1C *)func_00248CC8(&m_buf, m_num20C * sizeof(CGameDBRec1C), 1, 1);
            m_unk214 = 0;
            for (i = 0; i < m_num20C; i++) {
                CGameDBRec1C *r = &m_tbl20C[i];
                p = Func24AFE8(p, line, 1, 0x100);
                const char *q = func_0024A710(line, &r->m_id, 0, D_002D7EC0, D_002D7EC8);
                m_unk214 = r->m_id < m_unk214 ? m_unk214 : r->m_id;
                q = Func24A570(q, func_00248DA8(&m_buf), D_002D7EC0, D_002D7EC8);
                r->m8 = func_00248DC0(&m_buf);
                q = Func24A570(q, func_00248DA8(&m_buf), D_002D7EC0, D_002D7EC8);
                r->m4 = func_00248DC0(&m_buf);
                q = Func24A570(q, tok, D_002D7EC0, D_002D7EC8);
                r->mC = Func149618(tok);
                q = func_0024A710(q, &r->m10, 0, D_002D7EC0, D_002D7EC8);
                q = func_0024A710(q, &r->m14, 0, D_002D7EC0, D_002D7EC8);
                func_0024A710(q, &r->m18, 0, D_002D7EC0, D_002D7EC8);
            }
            Func14A620(data, D_002D8410, &m_tbl218, &m_num218);
            ok = 1;
        }
    }
    if (data) D_002B91B0(data);
    Func235DE0(D_002D8420, ok);
    return ok;
}

int CGameDBMgr::Func14A370() {
    char line[256];
    char tok[256];
    s32 bit;
    s32 i;
    int ok = 0;
    void *data = Func24A4C0(D_002A2C70);
    if (data) {
        const char *p = Func24AF10(data, D_002A2C74);
        if (*p) {
            m_num220 = func_0024B040(p, 1);
            m_tbl220 = (CGameDBRec14 *)func_00248CC8(&m_buf, m_num220 * sizeof(CGameDBRec14), 1, 1);
            m_unk228 = 0;
            for (i = 0; i < m_num220; i++) {
                CGameDBRec14 *r = &m_tbl220[i];
                p = Func24AFE8(p, line, 1, 0x100);
                const char *q = func_0024A710(line, &r->m_id, 0, D_002D7EC0, D_002D7EC8);
                m_unk228 = r->m_id < m_unk228 ? m_unk228 : r->m_id;
                q = Func24A570(q, func_00248DA8(&m_buf), D_002D7EC0, D_002D7EC8);
                r->m8 = func_00248DC0(&m_buf);
                q = Func24A570(q, func_00248DA8(&m_buf), D_002D7EC0, D_002D7EC8);
                r->m4 = func_00248DC0(&m_buf);
                q = func_0024A710(q, &bit, 0, D_002D7EC0, D_002D7EC8);
                if (bit > 0) r->mC |= 1 << bit;
                q = func_0024A710(q, &bit, 0, D_002D7EC0, D_002D7EC8);
                if (bit > 0) r->mC |= 1 << bit;
                Func24A570(q, tok, D_002D7EC0, D_002D7EC8);
                r->m10 = Func149618(tok);
            }
            Func14A620(data, D_002D8478, &m_tbl22C, &m_num22C);
            ok = 1;
        }
    }
    if (data) D_002B91B0(data);
    Func235DE0(D_002D8488, ok);
    return ok;
}

s32 CGameDBMgr::Func14A620(void *data, const char *key, CGameDBRec4C **tbl, s32 *num) {
    char line[256];
    char tok[256];
    s32 i, k;
    const char *p = Func24AF10(data, key);
    if (*p == 0) return 0;
    *num = func_0024B040(p, 1);
    *tbl = (CGameDBRec4C *)func_00248CC8(&m_buf, *num * sizeof(CGameDBRec4C), 1, 1);
    for (i = 0; i < *num; i++) {
        CGameDBRec4C *r = &(*tbl)[i];
        p = Func24AFE8(p, line, 1, 0x100);
        const char *q = func_0024A710(line, &r->m0, 0, D_002D7EC0, D_002D7EC8);
        q = Func24A570(q, 0, D_002D7EC0, D_002D7EC8);
        q = Func24A570(q, tok, D_002D7EC0, D_002D7EC8);
        s32 idx = Func147340(D_002A2998, tok);
        r->m4 = idx;
        r->m4 = idx >= 0 ? D_002A2A08[idx] : -1;
        for (k = 0; k < 4; k++) {
            q = Func24A570(q, tok, D_002D7EC0, D_002D7EC8);
            s32 n = D_002A0D38->V16(func_00248D98(&m_buf), tok);
            if (n >= 2) {
                r->m8[k] = (s32)func_00248CC8(&m_buf, n, 0, 0);
                r->m8[16] += Func148EC8(&r->m8[4 + r->m8[16]], &r->m8[8 + r->m8[16]], &r->m8[12 + r->m8[16]], 4 - r->m8[16], tok);
            }
        }
    }
    return 1;
}

int CGameDBMgr::Func14A8C0() {
    char line[256];
    char tok[256];
    s32 i;
    int ok = 0;
    void *data = Func24A4C0(D_002A2C90);
    if (data) {
        const char *p = Func24AF10(data, D_002A2C94);
        if (*p) {
            m_num234 = func_0024B040(p, 1);
            m_tbl234 = (CGameDBRec24 *)func_00248CC8(&m_buf, m_num234 * sizeof(CGameDBRec24), 1, 1);
            m_unk23C = 0;
            for (i = 0; i < m_num234; i++) {
                CGameDBRec24 *r = &m_tbl234[i];
                p = Func24AFE8(p, line, 1, 0x100);
                const char *q = func_0024A710(line, &r->m_id, 0, D_002D7EC0, D_002D7EC8);
                m_unk23C = r->m_id < m_unk23C ? m_unk23C : r->m_id;
                q = Func24A570(q, func_00248DA8(&m_buf), D_002D7EC0, D_002D7EC8);
                r->m8 = r->m4 = func_00248DC0(&m_buf);
                Func24A570(q, tok, D_002D7EC0, D_002D7EC8);
                r->mC = Func147340(D_002A2A70, tok);
            }
            func_002996C0(this, data, D_002D84B8, m_tbl234, m_num234, 0);
            ok = 1;
        }
    }
    if (data) D_002B91B0(data);
    Func235DE0(D_002D83D0, ok);
    return ok;
}

int CGameDBMgr::Func14AAD0() {
    char line[256];
    int ok;
    void *data;
    s32 i;
    s32 n;
    s32 a, b;
    ok = 0;
    data = Func24A4C0(D_002A2C9C);
    if (data) {
        m_num240 = 10;
        m_tbl240 = (CGameDBRec0C *)m_buf.Func248CC8(0x78, 1, 1);
        for (i = 0; i < m_num240; i++) {
            const char *key = D_002A2A70[i];
            CGameDBRec0C *t = &m_tbl240[i];
            const char *p = Func24AF10(data, key);
            if (!p) continue;
            t->m0 = i;
            n = 0;
            t->m8 = func_0024B040(p, 1);
            t->m4 = (CGameDBRec24b *)m_buf.Func248CC8(t->m8 * sizeof(CGameDBRec24b), 1, 1);
            if (t->m8 <= 0) continue;
            do {
                CGameDBRec24b *r = &t->m4[n];
                const char *q;
                p = Func24AFE8(p, line, 1, 0x100);
                r->m0 = n;
                q = Func24A570(line, func_00248DA8(&m_buf), D_002D7EC0, D_002D7EC8);
                r->m4 = func_00248DC0(&m_buf);
                for (a = 0; a < 2; a++)
                    for (b = 0; b < 3; b++) q = func_0024A710(q, &r->m8[a][b], 0, D_002D7EC0, D_002D7EC8);
                n++;
                func_0024A710(q, &r->m20, 0, D_002D7EC0, D_002D7EC8);
            } while (n < t->m8);
        }
        ok = 1;
    }
    if (data) D_002B91B0(data);
    Func235DE0(" tutor (%d)\n", ok);
    return ok;
}
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D84E8);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D84F8);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8508);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8510);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8518);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8520);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8528);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8530);

s32 Func14AD78(char *s) {
    s32 r = strstr(s, D_002D81F8) ? 2 : 0;
    if (strstr(s, D_002D8200)) {
        r |= 4;
    }
    if (strstr(s, D_002D8208)) {
        r |= 8;
    }
    if (strstr(s, D_002D8210)) {
        r |= 0x10;
    }
    if (strstr(s, D_002D8218)) {
        r |= 0x20;
    }
    if (strstr(s, D_002D8260)) {
        r |= 0x40;
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014AE30);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8570);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8580);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8590);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8598);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D85A0);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D85A8);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D85B8);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D85D0);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D85E0);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D85F8);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8608);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8618);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8628);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8638);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8640);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8648);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8650);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8658);

int CGameDBMgr::Func14B4C8() {
    char line[256];
    char tok[256];
    void *data;
    s32 i, j, n;
    int ok = 0;
    data = Func24A4C0(D_002A2CC4);
    if (data) {
        m_num1C4 = 0;
        m_tbl1C4 = 0;
        m_unk1CC = 0;
        const char *p = Func24AF10(data, D_002A2CC8);
        if (*p) {
            m_num1C4 = func_0024B040(p, 1);
            m_tbl1C4 = (CGameDBRec74 *)func_00248CC8(&m_buf, m_num1C4 * sizeof(CGameDBRec74), 1, 1);
            for (i = 0; i < m_num1C4; i++) {
                CGameDBRec74 *r = &m_tbl1C4[i];
                p = Func24AFE8(p, line, 1, 0x100);
                const char *q = func_0024A710(line, &r->m_id, 0, D_002D7EC0, D_002D7EC8);
                m_unk1CC = m_unk1CC < r->m_id ? r->m_id : m_unk1CC;
                q = Func24A570(q, 0, D_002D7EC0, D_002D7EC8);
                q = func_0024A710(q, &r->m38, 0, D_002D7EC0, D_002D7EC8);
                Func24A570(q, tok, D_002D7EC0, D_002D7EC8);
                n = D_002A0D38->V16(func_00248D98(&m_buf), tok);
                if (n >= 2) r->m3C = (const char *)func_00248CC8(&m_buf, n, 0, 0);
            }
        }
        for (i = 0; i < 13; i++) {
            p = Func24AF10(data, D_002A2CD0[i]);
            if (*p) {
                for (j = 0; j < m_num1C4; j++) {
                    CGameDBRec74 *r = &m_tbl1C4[j];
                    p = Func24AFE8(p, line, 1, 0x100);
                    const char *q = Func24A570(line, 0, D_002D7EC0, D_002D7EC8);
                    q = Func24A570(q, func_00248DA8(&m_buf), D_002D7EC0, D_002D7EC8);
                    r->m_names[i] = func_00248DC0(&m_buf);
                    Func24A570(q, tok, D_002D7EC0, D_002D7EC8);
                    n = D_002A0D38->V16(func_00248D98(&m_buf), tok);
                    if (n >= 2) r->m40[i] = (const char *)func_00248CC8(&m_buf, n, 0, 0);
                }
            }
        }
        func_0028A140(m_tbl1C4, m_num1C4, sizeof(CGameDBRec74), CompareGameDBEntries);
        ok = 1;
    }
    if (data) D_002B91B0(data);
    Func235DE0(D_002D85F8, ok, 0);
    return ok;
}

int CGameDBMgr::Func14B890() {
    char line[256];
    char tok[256];
    s32 i;
    void *data = Func24A4C0(D_002A2D08[D_002A26E4->Func1091B0(0x16)]);
    if (data) {
        const char *p = Func24AF10(data, D_002D7F38);
        if (*p) {
            m_num250 = func_0024B040(p, 1);
            m_tbl250 = (CGameDBRec20 *)func_00248CC8(&m_buf, m_num250 * sizeof(CGameDBRec20), 1, 1);
            for (i = 0; i < m_num250; i++) {
                CGameDBRec20 *r = &m_tbl250[i];
                p = Func24AFE8(p, line, 1, 0x100);
                const char *q = func_0024A710(line, &r->m_id, 0, D_002D7EC0, D_002D7EC8);
                q = func_0024A710(q, &r->m4, 0, D_002D7EC0, D_002D7EC8);
                q = Func24A570(q, func_00248DA8(&m_buf), D_002D7EC0, D_002D7EC8);
                r->m8 = (char *)func_00248DC0(&m_buf);
                q = Func24A570(q, func_00248DA8(&m_buf), D_002D7EC0, D_002D7EC8);
                r->mC = func_00248DC0(&m_buf);
                q = Func24A570(q, tok, D_002D7EC0, D_002D7EC8);
                r->m10 = Func24B998(D_002A2D18, tok);
                q = func_0024A710(q, &r->m14, 0, D_002D7EC0, D_002D7EC8);
                q = func_0024A710(q, &r->m1C, 0, D_002D7EC0, D_002D7EC8);
                func_0024A710(q, &r->m18, 0, D_002D7EC0, D_002D7EC8);
            }
        }
    }
    if (data) D_002B91B0(data);
    Func235DE0(D_002D8658, 1);
    return 1;
}

void CGameDBMgr::Init() {
    m_buf.Func248E00();
    Func147020();
}

s32 Func14BB28(s32 id) {
    if (id < D_002A26E4->Func1091B0(0x27)) {
        return D_002A26E4->Func1091B0(id + 0x28) - 0x10;
    }
    return ((u32)(id - 0x10) < 8) ? id - 0x10 : -1;
}

s32 CGameDBMgr::FindType2() {
    for (s32 i = 0; i < m_num1E8; i++) {
        if (m_tbl1E8[i].mC == 2) return m_tbl1E8[i].m_id;
    }
    return -1;
}

s32 CGameDBMgr::FindType8() {
    for (s32 i = 0; i < m_num1E8; i++) {
        if (m_tbl1E8[i].mC == 8) return m_tbl1E8[i].m_id;
    }
    return -1;
}

s32 CGameDBMgr::Collect14BC20(s32 *out, s32 max) {
    if (D_002A26E4->Func1091B0(0x17) & 3) return 0;
    s32 v = D_002A26E4->Func1091B0(0x17) / 4 + 25;
    s32 cnt = 0;
    for (s32 i = 0; i < m_unk24; i++) {
        if (m_unk20[i].m_id == v) {
            if (max > 0) {
                out[cnt] = i;
                max--;
            }
            cnt++;
        }
    }
    return cnt;
}

s32 CGameDBMgr::Func14BD00(s32 a, s32 b, s32 *out, s32 max) {
    s32 count = 0;
    for (s32 i = 0; i < m_num1D0; i++) {
        CGameDBEv34b *r = (CGameDBEv34b *)&m_tbl1D0[i];
        if (r->m20 != b) continue;
        s32 st = 0, u = 0, lim = 0, cur, x;
        if (r->m4 >= 0) {
            s32 k = Func1456A8(r->m4);
            if (k < 0) continue;
            cur = ((ICurFlag *)D_002A26E4)->GetNamed(0x34, k);
            st = ((ICurFlag *)D_002A26E4)->GetNamed(0x46, k);
            x = ((ICurFlag *)D_002A26E4)->GetNamed(0x52, k);
            u = ((ICurFlag *)D_002A26E4)->GetNamed(0x4C, k);
            if (IsFlagKind(st)) {
                CGameDBRecB0 *t = Find1E8(x);
                if (t) lim = t->m10;
            }
        } else {
            cur = ((ICurFlag *)D_002A26E4)->V6();
        }
        switch (r->m14) {
        case 0:
            if (r->m18 >= 0 && r->m18 != cur) continue;
            break;
        case 3:
            if (!((st == 5 && u == lim - 1) || st == 7 || st == 8)) continue;
            break;
        case 4:
            if (st != 6 || u != lim - r->m18 - 1) continue;
            break;
        case 1:
            if (st != 6) continue;
            if (r->m18 >= 0 && r->m18 - 0x13 != u) continue;
            break;
        case 2:
            if (st != 9) continue;
            if (r->m18 >= 0 && r->m18 - 0x17 != u) continue;
            break;
        case 5:
            if (st != 8) continue;
            break;
        }
        if (r->m1C != a) continue;
        if (out && max > 0) {
            out[count] = r->m_id;
            max--;
        }
        count++;
    }
    return count;
}

s32 CGameDBMgr::Func14C048(s32 *ids, s32 *flags, s32 name) {
    s32 idx = Func1456A8(name);
    s32 bit, v, i, count;
    if (idx < 0) return 0;
    i = 0;
    count = 0;
    D_002A0D38->V9();
    D_002A0D38->V7(idx);
    bit = Func14BB28(idx);
    v = D_002A26E4->Func1091B0(idx + 0x46);
    for (; i < m_num1E8; i++) {
        CGameDBRecB0 *e = &m_tbl1E8[i];
        switch (e->mC) {
        case 2:
            if (v != 1) continue;
            break;
        case 3:
            if (v != 2) continue;
            break;
        case 4:
            if (v != 3) continue;
            break;
        case 5:
            if (v != 4) continue;
            break;
        case 6:
            if (v != 5 && v != 7 && v != 8) continue;
            break;
        case 7:
        case 8:
            continue;
        default:
            Func235DE0("*** unknown school cate (%d)\n", e->mC);
            continue;
        }
        if (!((e->m14 >> bit) & 1)) continue;
        if (ids) ids[count] = e->m_id;
        {
            s32 f = (D_002A26E4->Func1091B0(0x1C) < e->m18) == 0;
            if (flags) flags[count] = f;
        }
        count++;
    }
    D_002A0D38->V10();
    return count;
}

s32 CGameDBMgr::Func14C2B0(s32 *ids, s32 *flags, s32 name) {
    s32 idx = Func1456A8(name);
    s32 v, bit, i, count;
    s32 *pi, *pf;
    if (idx < 0) return 0;
    v = D_002A26E4->Func1091B0(idx + 0x46);
    if (v != 5 && v != 7 && v != 8 && v != 6) return 0;
    bit = Func14BB28(idx);
    count = 0;
    D_002A0D38->V9();
    D_002A0D38->V7(idx);
    for (i = 0; i < m_num200; i++) {
        CGameDBRec28 *e = &m_tbl200[i];
        s32 f = 1;
        if (!((e->mC >> bit) & 1)) continue;
        if (e->m10) f = D_002A0D38->RunScript(e->m10, 0) != 0;
        if (ids) ids[count] = e->m_id;
        if (flags) flags[count] = f;
        count++;
    }
    D_002A0D38->V10();
    return count;
}

s32 CGameDBMgr::Func14C490(s32 *ids, s32 *flags, s32 name) {
    s32 idx = Func1456A8(name);
    s32 i, v, count;
    if (idx < 0) return 0;
    Func14BB28(idx);
    v = D_002A26E4->Func1091B0(idx + 0x46);
    count = 0;
    D_002A0D38->V9();
    D_002A0D38->V7(idx);
    for (i = 0; i < m_num234; i++) {
        CGameDBRec24 *e = &m_tbl234[i];
        if (e->mC == v) {
            s32 q, r, f;
            if (ids) ids[count] = e->m_id;
            q = e->m_id / 7;
            r = e->m_id % 7;
            u32 bb = (D_002A26E4->Func1091B0(q + 0x1006) >> r) & 1;
            f = bb == 0;
            if (flags) flags[count] = f;
            count++;
        }
    }
    D_002A0D38->V10();
    return count;
}

s32 CGameDBMgr::Func14C648(s32 *out, s32 name) {
    s32 k = Func1456A8(name);
    s32 v, x, i, n;
    if (k < 0) {
        return 0;
    }
    v = D_002A26E4->Func1091B0(k + 0x46);
    if (v != 4 && v != 5 && v != 6) {
        return 0;
    }
    x = Func14BB28(k);
    n = 0;
    D_002A0D38->V9();
    D_002A0D38->V7(k);
    for (i = 0; i < m_num20C; i++) {
        CGameDBRec1C *r = &m_tbl20C[i];
        if (!((r->mC >> x) & 1)) {
            continue;
        }
        if (r->m10 == 0 && v == 4) {
            continue;
        }
        if (r->m14 == 0 && v == 5) {
            continue;
        }
        if (r->m18 == 0 && v == 6) {
            continue;
        }
        if (out) {
            out[n] = r->m_id;
        }
        n++;
    }
    D_002A0D38->V10();
    return n;
}

s32 CGameDBMgr::Func14C800(s32 *out, s32 name) {
    s32 k = Func1456A8(name);
    s32 v, x, y, i, n;
    if (k < 0) {
        return 0;
    }
    v = D_002A26E4->Func1091B0(k + 0x46);
    if (v != 4 && v != 5) {
        return 0;
    }
    x = Func14BB28(k);
    y = D_002A26E4->Func1091B0(k + 0x52);
    n = 0;
    D_002A0D38->V9();
    D_002A0D38->V7(k);
    for (i = 0; i < m_num220; i++) {
        CGameDBRec14 *r = &m_tbl220[i];
        if (!((r->mC >> y) & 1)) {
            continue;
        }
        if (!((r->m10 >> x) & 1)) {
            continue;
        }
        if (out) {
            out[n] = r->m_id;
        }
        n++;
    }
    D_002A0D38->V10();
    return n;
}

s32 CGameDBMgr::Func14C998(s32 name) {
    s32 k = Func1456A8(name);
    if (k < 0) {
        return -1;
    }
    return Func14C9F8(D_002A26E4->Func1091B0(k + 0x34));
}

s32 CGameDBMgr::Func14C9F8(s32 v) {
    s32 i;
    for (i = 0; i < 6; i++) {
        if (v < D_002A2D30[i]) {
            break;
        }
    }
    return i - 1;
}

const char *CGameDBMgr::Func14CA38(s32 name) {
    s32 k = Func1456A8(name);
    s32 n;
    CGameDBRec48 *r;
    if (k < 0 || (n = Func14C998(name)) < 0 || (r = Find38(D_002A26E4->Func1091B0(k + 0xD6))) == 0) {
        return D_002D7D80;
    }
    return r->m_names[n];
}

int CGameDBMgr::Func14CAF0(s32 id, s32 mask) {
    s32 k = Func14BB28(id);
    s32 i;
    CGameDBBits *b = &m_bits[k];
    if (k < 0) return 0;
    for (i = 0; i < 7; i++) {
        if (!((mask >> i) & 1)) continue;
        if ((b->m_bits[i] >> ((ICurFlag *)D_002A26E4)->GetNamed(D_002A2D50[i], id)) & 1) return 1;
    }
    return 0;
}

int CompareGameDBIds(const s32 *a, const s32 *b) {
    return *a - *b;
}

s32 CGameDBMgr::Func14CC00(s32 *out, s32 name) {
    CGameDBSortEnt tmp[m_num38];
    s32 i, n, mask, t, idx, bit, sel;
    if (!D_002A26E4 || !D_002A0D38) return 0;
    mask = 0;
    D_002A0D38->V9();
    D_002A0D38->V7(name);
    t = ((ICurFlag *)D_002A26E4)->GetNamed(0xD6, name);
    idx = Func14C998(name);
    bit = 1 << Func14BB28(name);
    sel = ((ICurFlag *)D_002A26E4)->GetNamed(0xC4, name);
    for (i = 0; i < m_num38; i++) {
        CGameDBRec48v *r = (CGameDBRec48v *)&m_tbl38[i];
        if (((CGameDBRec48 *)r)->m_names[idx][0] == 0) continue;
        if (!(r->m28 & bit)) continue;
        if (r->m_id == 1) continue;
        if (r->m2C == 0 || D_002A0D38->RunScript(r->m2C, 0)) mask |= 1 << r->m_id;
    }
    if (mask == 0) mask |= 2;
    if (((mask >> t) & 1) == 0) sel = 0;
    n = 0;
    for (i = 0; i < m_num38; i++) {
        CGameDBRec48v *r = (CGameDBRec48v *)&m_tbl38[i];
        s32 b = 1 << r->m_id;
        if (!(mask & b)) continue;
        if (t != r->m_id && (sel & b) == (mask & b)) continue;
        s32 v = r->m1C;
        if (t == r->m_id) v += 0x32;
        if (r->m24) v -= 0x64;
        tmp[n].key = v;
        tmp[n].rec = r;
        n++;
    }
    func_0028A140(tmp, n, sizeof(CGameDBSortEnt), (int (*)(const CGameDBEntry *, const CGameDBEntry *))CompareGameDBIds);
    if (out) {
        for (i = 0; i < n; i++) out[i] = tmp[i].rec->m_id;
    }
    D_002A0D38->V10();
    ((ICurFlag *)D_002A26E4)->SetNamed(0xC4, name, mask);
    return n;
}

s32 CGameDBMgr::Func14CF78(s32 name) {
    s32 k = Func1456A8(name);
    if (k < 0) return -1;
    if (GN(0x46) == 9 && GN(0xF4) && !GN(0xE8)) return 9;
    if (GN(0x46) == 9 && GN(0xF4) && GN(0xE8)) return 10;
    if (GN(0x46) == 6 && GN(0xF4) && !GN(0xE8)) return 11;
    if (GN(0x46) == 6 && GN(0xF4) && GN(0xE8)) return 12;
    if (GN(0x46) == 9 && GN(0xE8) && !GN(0xF4)) return 7;
    if (GN(0x46) == 9 && GN(0xE8) && GN(0xF4)) return 8;
    if (D_002A26E4->Func1091B0(k + 0x46) == 9) return 6;
    s32 v = D_002A26E4->Func1091B0(k + 0x34);
    s32 i;
    for (i = 0; i < 13; i++) {
        if (v < D_002A2D70[i]) break;
    }
    return i - 1;
}

const char *CGameDBMgr::Func14D378(s32 name) {
    s32 k = Func1456A8(name);
    s32 n;
    CGameDBRec74 *r;
    if (k < 0 || (n = Func14CF78(name)) < 0 || (r = Find1C4(D_002A26E4->Func1091B0(k + 0xB8))) == 0) {
        return D_002D7D80;
    }
    return r->m_names[n];
}

s32 CGameDBMgr::Func14D430(s32 *out, s32 name) {
    s32 n = 0;
    s32 idx, sea, i;
    if (!D_002A26E4 || !D_002A0D38) return 0;
    name = Func1456A8(name);
    if (name < 0) return 0;
    sea = Func14CF78(name);
    D_002A0D38->V9();
    D_002A0D38->V7(name);
    D_002A26E4->Func1091B0(name + 0xB8);
    for (i = 0; i < m_num1C4; i++) {
        CGameDBRec74 *e = &m_tbl1C4[i];
        if (*e->m_names[sea] && e->m3C && D_002A0D38->RunScript(e->m3C, 0)) {
            out[n] = e->m_id;
            n++;
        }
    }
    D_002A0D38->V10();
    return n;
}

s32 CGameDBMgr::Func14D5F8(s32 *out, s32 name) {
    s32 n = 0;
    s32 idx, sea, i;
    if (!D_002A26E4 || !D_002A0D38) return 0;
    idx = Func1456A8(name);
    if (idx < 0) return 0;
    sea = Func14CF78(idx);
    D_002A0D38->V9();
    D_002A0D38->V7(idx);
    D_002A26E4->Func1091B0(idx + 0xB8);
    for (i = 0; i < m_num1C4; i++) {
        CGameDBRec74 *e = &m_tbl1C4[i];
        if (*e->m_names[sea] && e->m40[sea] && D_002A0D38->RunScript(e->m40[sea], 0)) {
            out[n] = e->m_id;
            n++;
        }
    }
    D_002A0D38->V10();
    return n;
}

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014D7C8);

void CGameDBMgr::Func14DB70(f32 *out, s32 name) {
    s32 idx = Func1456A8(name);
    if (idx < 0) return;
    Func14D7C8(out, idx, D_002A26E4->Func1091B0(idx + 0x34));
    out[0] += (f32)D_002A26E4->Func1091B0(0x76) / 100.0f;
    out[1] += (f32)D_002A26E4->Func1091B0(0x7C) / 100.0f;
    out[2] += (f32)D_002A26E4->Func1091B0(0x82) / 100.0f;
    out[3] += (f32)D_002A26E4->Func1091B0(0x88) / 100.0f;
    out[4] += (f32)D_002A26E4->Func1091B0(0x8E) / 100.0f;
}

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014DCE0);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D86E0);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D86F8);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8718);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8730);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8750);

s32 CGameDBMgr::GetUnk24() {
    return m_unk24;
}

CGameDBRec8 *CGameDBMgr::GetUnk20(s32 i) {
    if (i < 0 || i > m_unk24 - 1) {
        return 0;
    }
    return &m_unk20[i];
}

s32 CGameDBMgr::GetUnk14(s32 i) {
    if (i < 0 || i > m_unk18 - 1) {
        return 0;
    }
    return m_unk14[i];
}

char *CGameDBMgr::GetCharaName(s32 id) {
    s32 k = Func14BB28(id);
    if (k < 0) {
        return D_002D7D80;
    }
    return m_charas[k].m_name;
}

s32 CGameDBMgr::GetChara4(s32 id) {
    s32 k = Func14BB28(id);
    if (k < 0) {
        return 0;
    }
    return m_charas[k].m4;
}

CGameDBItem14 *CGameDBMgr::GetCharaItem(s32 id, s32 j) {
    s32 k = Func14BB28(id);
    if (k < 0) {
        return 0;
    }
    s32 n = m_charas[k].mC - 1;
    if (j >= n) {
        j = n;
    }
    if (j < 0) {
        j = 0;
    }
    return &m_charas[k].m8[j];
}

u8 *CGameDBMgr::GetCharaD08(s32 id) {
    s32 k = Func14BB28(id);
    if (k < 0) {
        return 0;
    }
    return m_charas[k].mD08;
}

u8 *CGameDBMgr::GetCharaD1C(s32 id) {
    s32 k = Func14BB28(id);
    if (k < 0) {
        return 0;
    }
    return m_charas[k].mD1C;
}

s32 CGameDBMgr::Func14E660(s32 id, s32 a, s32 b) {
    s32 k = Func14BB28(id);
    s32 t, season;
    if (k < 0) return 0;
    id = Func1456A8(id);
    if (id < 0) return 0;
    if ((u32)a >= 0x17) return 0;
    t = D_002A26E4->Func1091B0(0x17);
    season = t % 4;
    season = (D_002A26E4->Func1091B0(id + 0x34) * 4 + season + 3) / 4;
    if ((u32)a < 15) {
        if (b < 0) b = ((CFlagWorkV *)D_002A26E4)->V9(0x94, id);
        a += b * 5;
    }
    return m_charas[k].m10[season][a];
}

s32 CGameDBMgr::GetCharaD30(s32 id) {
    s32 k = Func14BB28(id);
    if (k < 0) {
        return 0;
    }
    return m_charas[k].mD30;
}

s32 CGameDBMgr::GetCharaD34(s32 id) {
    s32 k = Func14BB28(id);
    if (k < 0) {
        return 0;
    }
    return m_charas[k].mD34;
}

s32 CGameDBMgr::GetCharaD38(s32 id) {
    s32 k = Func14BB28(id);
    if (k < 0) {
        return 0;
    }
    return m_charas[k].mD38;
}

CGameDBRec34 *CGameDBMgr::Find1D0(s32 id) {
    return FindById(m_tbl1D0, m_num1D0, id);
}

CGameDBRec5C *CGameDBMgr::Find1DC(s32 id) {
    return FindById(m_tbl1DC, m_num1DC, id);
}

CGameDBRecB0 *CGameDBMgr::Find1E8(s32 id) {
    return FindById(m_tbl1E8, m_num1E8, id);
}

CGameDBRec28 *CGameDBMgr::Find200(s32 id) {
    return FindById(m_tbl200, m_num200, id);
}

CGameDBRec1C *CGameDBMgr::Find20C(s32 id) {
    return FindById(m_tbl20C, m_num20C, id);
}

CGameDBRec14 *CGameDBMgr::Find220(s32 id) {
    return FindById(m_tbl220, m_num220, id);
}

CGameDBRec24 *CGameDBMgr::Find234(s32 id) {
    return FindById(m_tbl234, m_num234, id);
}

CGameDBRec48 *CGameDBMgr::Find38(s32 id) {
    return FindById(m_tbl38, m_num38, id);
}

CGameDBRec74 *CGameDBMgr::Find1C4(s32 id) {
    return FindById(m_tbl1C4, m_num1C4, id);
}

int CGameDBMgr::Func14EB20(s32 id, s32 slot, s32 step) {
    CGameDBRec74 *rec;
    if ((u32)slot >= 13) return 0;
    s32 n = m_unk1CC + 1;
    do {
        id = (id + step + n) % n;
        rec = FindById(m_tbl1C4, m_num1C4, id);
    } while (rec == 0 || rec->m_names[slot][0] == 0);
    return (int)rec;
}

int CGameDBMgr::CallFunc14EB20Minus(s32 a, s32 b) {
    return Func14EB20(a, b, -1);
}

int CGameDBMgr::CallFunc14EB20Plus(s32 a, s32 b) {
    return Func14EB20(a, b, 1);
}

const char *CGameDBMgr::GetName248(u32 a, s32 b) {
    if (m_counts24C == 0 || a >= 4 || b < 0 || b > m_counts24C[a] - 1) return D_002D7D80;
    return m_names248[a][b];
}

s32 CGameDBMgr::Func14EC50(s32 key, s32 idx) {
    return Func14EDE0(m_tbl218, m_num218, key, D_002A26E4->Func1091B0(func_001456A8(key) + 0xE2), idx);
}

s32 CGameDBMgr::Func14ECD0(s32 key, s32 idx) {
    return Func14EDE0(m_tbl22C, m_num22C, key, D_002A26E4->Func1091B0(func_001456A8(key) + 0xDC), idx);
}

CGameDBRec4C *CGameDBMgr::Find14ED50(CGameDBRec4C *tbl, s32 n, s32 key, s32 val) {
    s32 k = Func145738(key, 1);
    if (k < 0) {
        return 0;
    }
    for (s32 i = 0; i < n; i++) {
        if (tbl[i].m4 == k && tbl[i].m0 == val) {
            return &tbl[i];
        }
    }
    return 0;
}

s32 CGameDBMgr::Func14EDE0(CGameDBRec4C *tbl, s32 n, s32 key, s32 val, s32 idx) {
    CGameDBRec4C *p = Find14ED50(tbl, n, key, val);
    if (!p) {
        return 0;
    }
    return p->m8[idx];
}

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014EE18);

s32 CGameDBMgr::Func14F2A0(s32 name) {
    if (Func1456A8(name) < 0) {
        return 0;
    }
    if (!Func14F380(name, FindType8())) {
        CGameDBRecB0 *r = Find1E8(FindType8());
        if (D_002A26E4->Func1091B0(0x1C) < r->m18) {
            return 0;
        }
    }
    return 1;
}

s32 CGameDBMgr::Func14F380(s32 name, s32 type) {
    s32 r;
    if (type != FindType8()) {
        return 0;
    }
    D_002A0D38->V9();
    D_002A0D38->V7(Func1456A8(name));
    r = D_002A0D38->RunScript((const char *)m_unk1FC, 0) != 0;
    D_002A0D38->V10();
    return r;
}

int CGameDBMgr::TestBits14F478(s32 id) {
    s32 base = func_001456A8(id);
    if (base < 0) return 0;
    s32 k = Func14BB28(id);
    CGameDBBits *b = &m_bits[k];
    if (k < 0) return 0;
    for (s32 i = 0; i < 5; i++) {
        if ((b->m_bits[i] >> D_002A26E4->Func1091B0(D_002A2D98[i] + base)) & 1) return 1;
    }
    return 0;
}

// GNU as 2.10 assembles a lui here as lw unless the function starts on a fresh .p2align (docs/lessons.md).
asm(".p2align 3");
s32 CGameDBMgr::Func14F550(s32 name, s32 kind, s32 bit) {
    s32 k, j;
    CGameDBBits *b;
    if (Func1456A8(name) < 0) return 0;
    k = Func14BB28(name);
    if (k < 0) return 0;
    b = &m_bits[k];
    switch (kind) {
    case 0xA6: j = 0; break;
    case 0xAC: j = 1; break;
    case 0xB2: j = 2; break;
    case 0xA0: j = 3; break;
    case 0x9A: j = 4; break;
    default: return 0;
    }
    return ((u32)b->m_bits[j] >> bit) & 1;
}

s32 CGameDBMgr::Func14F638(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    if (Func14F550(a, 0xA6, b)) {
        return 1;
    }
    if (Func14F550(a, 0xAC, c)) {
        return 1;
    }
    if (Func14F550(a, 0xB2, d)) {
        return 1;
    }
    if (Func14F550(a, 0xA0, e)) {
        return 1;
    }
    return Func14F550(a, 0x9A, f) != 0;
}

s32 CGameDBMgr::Func14F760(s32 name, s32 kind) {
    s32 k, j;
    CGameDBBits *b;
    if (Func1456A8(name) < 0) return 0;
    k = Func14BB28(name);
    if (k < 0) return 0;
    b = &m_bits[k];
    switch (kind) {
    case 0xA6: j = 0; break;
    case 0xAC: j = 1; break;
    case 0xB2: j = 2; break;
    case 0xA0: j = 3; break;
    case 0x9A: j = 4; break;
    default: return 0;
    }
    return b->m_bits[j];
}

s32 CGameDBMgr::Func14F830(s32 name, s32 kind, s32 bit) {
    s32 k, j;
    CGameDBBits *b;
    if (Func1456A8(name) < 0) return 0;
    k = Func14BB28(name);
    if (k < 0) return 0;
    b = &m_bits104[k];
    switch (kind) {
    case 0xA6: j = 0; break;
    case 0xAC: j = 1; break;
    case 0xB2: j = 2; break;
    case 0xA0: j = 3; break;
    case 0x9A: j = 4; break;
    default: return 0;
    }
    return ((u32)b->m_bits[j] >> bit) & 1;
}

s32 CGameDBMgr::Func14F918(s32 a, s32 b) {
    s32 k = Func145738(b, 0);
    s32 lim = a / 4 + 0x19;
    s32 i;
    if (k < 0) {
        return -1;
    }
    for (i = 0; i < D_002A2988->GetUnk24(); i++) {
        CGameDBRec8 *r = D_002A2988->GetUnk20(i);
        if (r && r->m4 == k && lim >= r->m_id) {
            return lim - r->m_id;
        }
    }
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/CGameDBMgr", func_0014FA08);

CGameDBRec20 *CGameDBMgr::GetTbl250(s32 i) {
    if (i < 0 || i > m_num250 - 1) {
        return 0;
    }
    return &m_tbl250[i];
}

s32 CGameDBMgr::GetNum240(s32 i) {
    if (i < 0 || i > m_num240 - 1) return 0;
    CGameDBRec0C *rec = &m_tbl240[i];
    return rec->m8;
}

CGameDBRec24b *CGameDBMgr::Get240(s32 i, s32 j) {
    if (i < 0 || i > m_num240 - 1) return 0;
    CGameDBRec0C *rec = &m_tbl240[i];
    if (j < 0 || j > rec->m8 - 1) return 0;
    return &rec->m4[j];
}

s32 CGameDBMgr::Func14FBB0(s32 name) {
    s32 k = Func1456A8(name);
    s32 v;
    CGameDBRecB0 *r;
    if (k < 0) {
        return 0;
    }
    v = D_002A26E4->Func1091B0(k + 0x46);
    if (v == 7) {
        return 1;
    }
    if (!IsFlagKind(v)) {
        return 0;
    }
    r = Find1E8(D_002A26E4->Func1091B0(k + 0x52));
    if (!r) {
        return 0;
    }
    return r->m10 - D_002A26E4->Func1091B0(k + 0x4C);
}

int Func14FC70(s32 i, s32 bit) {
    if (i < 0) {
        return D_002A26E4->Func1091B0(bit + 0x3AAE);
    }
    return ((ICurFlag *)D_002A26E4)->GetBit1454F0(i, bit);
}

s32 CGameDBMgr::Func14FCC8(s32 i, s32 arg) {
    s32 v = arg;
    s32 k;
    if (arg < 0) v = ((CFlagWorkV *)D_002A26E4)->V6();
    if ((u32)(i - 0x20) < 3) return 1;
    if (arg < 0) {
        if (Func1456A8(i) >= 0) return 1;
    } else if (i < m_unk24) {
        for (k = 0; k < m_unk24; k++) {
            if (v + 0x19 >= m_unk20[k].m_id) return 1;
        }
    } else if ((u32)(i - 0x10) < 8) {
        for (k = 0; k < m_unk24; k++) {
            if (m_unk20[k].m4 == i && v + 0x19 >= m_unk20[k].m_id) return 1;
        }
    }
    for (k = 0; k < m_unk2C; k++) {
        CGameDBRec18 *e = &((CGameDBRec18 *)m_unk28)[k];
        if (e->mC == i && Func14FC70(arg, e->m14)) return 1;
    }
    return 0;
}

s32 CGameDBMgr::Func14FE60(s32 arg) {
    s32 n = D_002A26E4->Func1091B0(0x27) + 3;
    s32 i;
    for (i = 0; i < D_002A26E4->Func1091B0(0x27); i++) {
        if (D_002A26E4->Func1091B0(i + 0xF4)) {
            n++;
        }
    }
    for (i = 0x28; i < 0x39; i++) {
        if (Func14FCC8(i, arg)) {
            n++;
        }
    }
    return n;
}

INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D88C8);
void CGameDBMgr::Func14FF30() {
    s32 before[8];
    s32 i, v;
    s32 t = ((ICurFlag *)D_002A26E4)->V6();
    for (i = 0; i < D_002A26E4->Func1091B0(0x27); i++) before[i] = Func14CF78(i);
    for (i = 0; i < m_unk2C; i++) {
        CGameDBRec18 *e = &((CGameDBRec18 *)m_unk28)[i];
        switch (e->m8) {
        case 1:
            if (Func1456A8(e->m10) >= 0) {
                v = Func14FC70(-1, e->m14);
                ((ICurFlag *)D_002A26E4)->SetNamed(0xE8, e->m10, v);
            }
            break;
        case 2:
            if (Func1456A8(e->m10) >= 0) {
                v = 0;
                if (Func14FC70(-1, e->m14)) v = e->m0 - 1 == t;
                ((ICurFlag *)D_002A26E4)->SetNamed(0xEE, e->m10, v);
                v = 0;
                if (Func14FC70(-1, e->m14) && !(t < e->m0) && !(e->m4 < t)) v = 1;
                ((ICurFlag *)D_002A26E4)->SetNamed(0xF4, e->m10, v);
                ((ICurFlag *)D_002A26E4)->SetNamed(0xFA, e->m10, (Func14FC70(-1, e->m14) && !(t < e->m0) && !(e->m4 < t)) ? t - e->m0 : 0);
            }
            break;
        case 3:
            if (Func1456A8(e->m10) >= 0) {
                v = 0;
                if (Func14FC70(-1, e->m14)) v = t < e->m0;
                ((ICurFlag *)D_002A26E4)->SetNamed(0xEE, e->m10, v);
                v = 0;
                if (Func14FC70(-1, e->m14) && !(t < e->m0) && !(e->m4 < t)) v = 1;
                ((ICurFlag *)D_002A26E4)->SetNamed(0xF4, e->m10, v);
                ((ICurFlag *)D_002A26E4)->SetNamed(0xFA, e->m10, (Func14FC70(-1, e->m14) && !(t < e->m0) && !(e->m4 < t)) ? t - e->m0 : 0);
            }
            break;
        }
    }
    for (i = 0; i < D_002A26E4->Func1091B0(0x27); i++) {
        if (before[i] != Func14CF78(i)) {
            Func235DE0(D_002D88C8, before[i], Func14CF78(i));
            if (D_002A0D38) D_002A0D38->V33(i);
        }
    }
}

s32 CGameDBMgr::Func150348(s32 *out, s32 kind, s32 key, s32 val, s32 idx) {
    s32 n;
    s32 *a;
    s32 *b;
    s32 *c;
    memset(out, 0, 16);
    switch (kind) {
    case 0: {
        CGameDBRec5C *r = Find1DC(key);
        if (!r) return 0;
        n = r->m34;
        a = r->m38;
        b = r->m44;
        c = r->m50;
        break;
    }
    case 5: {
        u8 *r = (u8 *)Find234(key);
        if (!r) return 0;
        n = *(s32 *)(r + 0x20);
        a = (s32 *)(r + 0x14);
        b = (s32 *)(r + 0x18);
        c = (s32 *)(r + 0x1C);
        break;
    }
    case 2: {
        u8 *r = (u8 *)Find200(key);
        if (!r) return 0;
        n = *(s32 *)(r + 0x24);
        a = (s32 *)(r + 0x18);
        b = (s32 *)(r + 0x1C);
        c = (s32 *)(r + 0x20);
        break;
    }
    case 1: {
        u8 *r = (u8 *)Find1E8(key);
        if (!r) return 0;
        n = *(s32 *)(r + 0xAC);
        a = (s32 *)(r + 0x64);
        b = (s32 *)(r + 0x40);
        c = (s32 *)(r + 0x88);
        break;
    }
    case 4: {
        CGameDBRec4C *r = Find14ED50(m_tbl22C, m_num22C, val, key);
        if (!r) return 0;
        n = r->m8[16];
        a = &r->m8[4];
        b = &r->m8[8];
        c = &r->m8[12];
        break;
    }
    case 3: {
        CGameDBRec4C *r = Find14ED50(m_tbl218, m_num218, val, key);
        if (!r) return 0;
        n = r->m8[16];
        a = &r->m8[4];
        b = &r->m8[8];
        c = &r->m8[12];
        break;
    }
    default:
        return 0;
    }
    out[0] = n;
    if (idx < 0) return 1;
    if (n - 1 < idx) return 0;
    out[1] = a[idx];
    out[2] = b[idx];
    out[3] = c[idx];
    return 1;
}

s32 CGameDBMgr::Get150550(s32 a, s32 b, s32 c) {
    s32 buf[4];
    if (Func150348(buf, a, b, c, 0)) {
        return buf[0];
    }
    return 0;
}

s32 CGameDBMgr::Get150590(s32 a, s32 b, s32 c, s32 d) {
    s32 buf[4];
    if (Func150348(buf, a, b, c, d)) {
        return buf[1];
    }
    return -1;
}

s32 CGameDBMgr::Get1505E0(s32 a, s32 b, s32 c, s32 d) {
    s32 buf[4];
    if (Func150348(buf, a, b, c, d)) {
        return buf[2];
    }
    return -1;
}

s32 CGameDBMgr::Get150630(s32 a, s32 b, s32 c, s32 d) {
    s32 buf[4];
    if (Func150348(buf, a, b, c, d)) {
        return buf[3];
    }
    return -1;
}

s32 CGameDBMgr::Func150680() {
    s32 k = D_002A26E4->Func1091B0(0x16);
    if (k < 0) return 0;
    s32 total = 0;
    s32 i;
    s32 done = 0;
    for (i = 0; i < m_num1D0; i++) {
        CGameDBEv34 *r = (CGameDBEv34 *)&m_tbl1D0[i];
        s32 v = Find20(r->m4);
        if (v >= 0 && r->m14 == 0 && r->m18 >= 0x23 - v * 2) continue;
        for (s32 j = 0; j < r->m2C; j++) {
            const char *s = r->m30[j].m14;
            if (!s) continue;
            if (s[0] == 0 || s[0] == '$') continue;
            if (strncmp(s, "init", 4) == 0) continue;
            if (!((r->m30[j].mC >> k) & 1)) continue;
            total++;
            if (D_002A26E0->GetBit144070(k, r->mC, r->m10, j)) done++;
        }
    }
    for (i = 0; i < m_num1DC; i++) {
        total++;
        CGameDBRec5C *e = &m_tbl1DC[i];
        if (D_002A26E0->GetBit144070(k, 0, e->m_id, 0)) done++;
    }
    total = total < 1 ? 1 : total;
    f32 p = done * 100.0f / total;
    f32 q;
    if (p < 50.0f) q = p / 50.0f * 30.0f;
    else q = (p - 50.0f) / 20.0f * 70.0f + 30.0f;
    s32 res = (s32)q;
    if (done > 0 && res <= 0) res = 1;
    return res < 0 ? 0 : (res < 0x65 ? res : 100);
}

s32 CGameDBMgr::Find20(s32 id) {
    if ((u32)(id - 16) >= 8) return -1;
    for (s32 i = 0; i < m_unk24; i++) {
        if (m_unk20[i].m4 == id) return i;
    }
    return -1;
}

int CompareGameDBEntries(const CGameDBEntry *a, const CGameDBEntry *b) {
    int d = a->m_order - b->m_order;
    if (d != 0) {
        return d;
    }
    return a->m_id - b->m_id;
}

void Func150A10(void *a, s32 b) {
    void *p = func_0024F2E8(0x4D0);
    func_00150A70(p, b);
    func_0024F5C0(a, p, 0);
}
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8910);
INCLUDE_RODATA("asm/nonmatchings/CGameDBMgr", D_002D8920);
