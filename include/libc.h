#ifndef LIBC_H
#define LIBC_H

/* C library functions linked into the game (newlib, EE-optimised). */
extern "C" {
int strcmp(const char *a, const char *b);   /* 0x28B190 */
char *strcpy(char *dst, const char *src);   /* 0x28B2D4 */
void *memset(void *dst, int c, unsigned int n); /* 0x289FB0 */
}

#endif
