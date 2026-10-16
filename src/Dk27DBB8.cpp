#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
extern int D_002BF158;
extern int D_002BF15C;
extern u8 D_423F08[];
extern const char D_002EA238[];
extern const char *D_002BF1F8[];
void *memset(void *, int, unsigned int);
char *strcpy(char *, const char *);
int func_002735D0(int, void *);

extern const char *D_002BF218[];

extern char D_424108[];
typedef struct { char pad[0x10]; int m10; char pad2[0x58 - 0x14]; int m58; unsigned char pad3[0x71 - 0x5C]; unsigned char m71; } PadSt;
typedef struct { char pad[0x10]; int m10; char pad2[0x1C - 0x14]; } PadPort;
extern PadPort D_424190[][4];
PadSt *func_0027EDC8(int, int);
int func_0027F800(int, int, int);
// @decl-end

INCLUDE_ASM("asm/nonmatchings/Dk27DBB8", func_0027DBB8);

INCLUDE_ASM("asm/nonmatchings/Dk27DBB8", func_0027DC60);

void func_0027DCD8(void) { D_002BF158 = 0; D_002BF15C = 0; memset(D_423F08, 0, 0x200); }

INCLUDE_ASM("asm/nonmatchings/Dk27DBB8", func_0027DD00);

INCLUDE_ASM("asm/nonmatchings/Dk27DBB8", func_0027DD80);

INCLUDE_ASM("asm/nonmatchings/Dk27DBB8", func_0027DE38);

INCLUDE_ASM("asm/nonmatchings/Dk27DBB8", func_0027DE90);

int func_0027DF38(unsigned short a, int x, int y) { int b[4]; b[0] = a; b[1] = x; b[2] = y; b[3] = (int)D_424108 | 0x20000000; return func_002735D0(1, b); }

int func_0027DF80(int a) { int b[1]; b[0] = a; return func_002735D0(2, b); }

int func_0027DFA8(int a, char c) { int b[2]; b[0] = a; b[1] = c; return func_002735D0(3, b); }

int func_0027DFD8(int a) { int b[1]; b[0] = a; return func_002735D0(4, b); }

int func_0027E000(unsigned char a, int x, int y) { int b[8]; b[0] = a; b[1] = x; b[2] = y; return func_002735D0(0x20, b); }

int func_0027E030(int a) { int b[1]; b[0] = a; return func_002735D0(0x21, b); }

int func_0027E058(int a, int x, unsigned short y) { int b[3]; b[0] = a; b[1] = x; b[2] = y; return func_002735D0(-5, b); }

int func_0027E090(int a, int x, unsigned short y) { int b[3]; b[0] = a; b[1] = x; b[2] = y; return func_002735D0(-6, b); }

int func_0027E0C8(int a, char c) { int b[2]; b[0] = a; b[1] = c; return func_002735D0(-7, b); }

int func_0027E0F8(int a) { int b[1]; b[0] = a; return func_002735D0(-8, b); }

int func_0027E120(int a) { int b[1]; b[0] = a; return func_002735D0(-9, b); }

int func_0027E148(int a) { int b[1]; b[0] = a; return func_002735D0(0x10, b); }

INCLUDE_ASM("asm/nonmatchings/Dk27DBB8", func_0027E170);

INCLUDE_ASM("asm/nonmatchings/Dk27DBB8", func_0027E1E8);

INCLUDE_ASM("asm/nonmatchings/Dk27DBB8", func_0027E260);

INCLUDE_ASM("asm/nonmatchings/Dk27DBB8", func_0027E348);

INCLUDE_ASM("asm/nonmatchings/Dk27DBB8", func_0027E498);

INCLUDE_ASM("asm/nonmatchings/Dk27DBB8", func_0027E500);

INCLUDE_ASM("asm/nonmatchings/Dk27DBB8", func_0027E578);

INCLUDE_ASM("asm/nonmatchings/Dk27DBB8", func_0027E7B0);

INCLUDE_ASM("asm/nonmatchings/Dk27DBB8", func_0027E8C8);

INCLUDE_ASM("asm/nonmatchings/Dk27DBB8", func_0027EA08);

INCLUDE_ASM("asm/nonmatchings/Dk27DBB8", func_0027EAA8);

INCLUDE_ASM("asm/nonmatchings/Dk27DBB8", func_0027EB28);

INCLUDE_ASM("asm/nonmatchings/Dk27DBB8", func_0027ED10);

INCLUDE_ASM("asm/nonmatchings/Dk27DBB8", func_0027EDC8);

int func_0027EE28(int a, int b) { if (D_424190[a][b].m10 == 0) return 0; return func_0027EDC8(a, b)->m58; }

INCLUDE_ASM("asm/nonmatchings/Dk27DBB8", func_0027EE78);

INCLUDE_ASM("asm/nonmatchings/Dk27DBB8", func_0027EFE0);

void func_0027F058(unsigned int i, char *d) { if (i < 8) { strcpy(d, D_002BF1F8[i]); return; } *d = D_002EA238[0]; }

INCLUDE_ASM("asm/nonmatchings/Dk27DBB8", func_0027F090);

int func_0027F0F8(int a, int b) { if (D_424190[a][b].m10 == 0) return 0; return func_0027EDC8(a, b)->m71; }

void func_0027F148(unsigned int i, char *d) { if (i < 4) { strcpy(d, D_002BF218[i]); return; } *d = D_002EA238[0]; }

INCLUDE_ASM("asm/nonmatchings/Dk27DBB8", func_0027F180);

INCLUDE_ASM("asm/nonmatchings/Dk27DBB8", func_0027F2A0);

INCLUDE_ASM("asm/nonmatchings/Dk27DBB8", func_0027F3C0);

INCLUDE_ASM("asm/nonmatchings/Dk27DBB8", func_0027F4F8);

INCLUDE_ASM("asm/nonmatchings/Dk27DBB8", func_0027F5B0);

INCLUDE_ASM("asm/nonmatchings/Dk27DBB8", func_0027F670);

INCLUDE_ASM("asm/nonmatchings/Dk27DBB8", func_0027F748);

INCLUDE_ASM("asm/nonmatchings/Dk27DBB8", func_0027F800);

INCLUDE_ASM("asm/nonmatchings/Dk27DBB8", func_0027F8B0);

int func_0027F910(int a, int b) { if (D_424190[a][b].m10 == 0) return 0; return func_0027F800(a, b, 0xFFF); }

int func_0027F968(int a, int b) { if (D_424190[a][b].m10 == 0) return 0; return func_0027F800(a, b, 0); }

INCLUDE_ASM("asm/nonmatchings/Dk27DBB8", func_0027F9C0);

INCLUDE_ASM("asm/nonmatchings/Dk27DBB8", func_0027FA90);

INCLUDE_ASM("asm/nonmatchings/Dk27DBB8", func_0027FAF8);

INCLUDE_ASM("asm/nonmatchings/Dk27DBB8", func_0027FB60);

INCLUDE_ASM("asm/nonmatchings/Dk27DBB8", func_0027FBC8);
