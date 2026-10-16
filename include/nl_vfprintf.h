/*
 * newlib's vfprintf.c (_vfprintf_r, and _vfiprintf_r with INTEGER_ONLY) as Sony shipped it:
 * newlib-1.9.0 plus the later `if (expt || ndig)` fix, no {0}/NULL initialisers for _double,
 * expsize and xdigs, and EE va_arg (the va-mips.h __va_next_addr as a post-increment). Only the
 * _NO_LONGLONG/_NO_LONGDBL code is kept. Units built with -g (cc1's scheduling differs without it).
 *
 * Copyright (c) 1990 The Regents of the University of California. All rights reserved.
 * This code is derived from software contributed to Berkeley by Chris Torek.
 * Redistribution and use in source and binary forms, with or without modification, are permitted
 * provided that the conditions of the 4-clause BSD license (see newlib's vfprintf.c) are met.
 *
 * The including unit defines NL_VFPRINTF_R, NL_FILE (its FILE struct with flags, file and base),
 * NL_SPRINT, NL_SBPRINTF and, with FLOATING_POINT, NL_CVT, NL_EXPONENT, NL_LOCALECONV, NL_ISINF,
 * NL_ISNAN.
 */
#ifndef NL_VFPRINTF_H
#define NL_VFPRINTF_H
struct W2Siov { const void *iov_base; s32 iov_len; };
struct W2Suio { struct W2Siov *uio_iov; s32 uio_iovcnt; s32 uio_resid; };
#ifdef FLOATING_POINT
struct W2Lconv { char *decimal_point; };
#endif
#endif
extern int func_00291868(void *, int *, const char *, int, int *); /* _mbtowc_r */
extern void *func_0029189C(const void *, int, unsigned int);    /* memchr */
extern unsigned int strlen(const char *);
extern int func_0028F3E8();                                     /* __swsetup */
extern void *D_002BF5D0;                                        /* _impure_ptr */
extern int D_002BFA38;                                          /* __mb_cur_max */
#define W2_VA_ARG(ap, T) (*(T *)({ char *__t = (ap); (ap) = __t + 8; __t; }))
#define	to_digit(c)	((c) - '0')
#define is_digit(c)	((unsigned)to_digit(c) <= 9)
#define	to_char(n)	((n) + '0')
#define	ALT		0x001
#define	HEXPREFIX	0x002
#define	LADJUST		0x004
#define	LONGDBL		0x008
#define	LONGINT		0x010
#define	QUADINT		0x020
#define	SHORTINT	0x040
#define	ZEROPAD		0x080
#define FPT		0x100
#define	DEFPREC		6
#define NIOV 8
#define	PADSIZE	16
#ifdef FLOATING_POINT
#define	BUF		(308 + 39 + 1)
#else
#define	BUF		40
#endif
int NL_VFPRINTF_R(void *data, NL_FILE *fp, const char *fmt0, char *ap)
{
	register char *fmt;
	register int ch;
	register int n, m;
	register char *cp;
	register struct W2Siov *iovp;
	register int flags;
	int ret;
	int width;
	int prec;
	char sign;
	int wc;
#ifdef FLOATING_POINT
	char *decimal_point = NL_LOCALECONV()->decimal_point;
	char softsign;
	double _double;
	int expt;
	int expsize;
	int ndig;
	char expstr[7];
#endif
	unsigned long _uquad;
	enum { OCT, DEC, HEX } base;
	int dprec;
	int realsz;
	int size;
	char *xdigs;
	struct W2Suio uio;
	struct W2Siov iov[NIOV];
	char buf[BUF];
	char ox[2];
	int state = 0;
	static const char blanks[PADSIZE] =
	 {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
	static const char zeroes[PADSIZE] =
	 {'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'};

#define	PRINT(ptr, len) { \
	iovp->iov_base = (ptr); \
	iovp->iov_len = (len); \
	uio.uio_resid += (len); \
	iovp++; \
	if (++uio.uio_iovcnt >= NIOV) { \
		if (NL_SPRINT(fp, &uio)) \
			goto error; \
		iovp = iov; \
	} \
}
#define	PAD(howmany, with) { \
	if ((n = (howmany)) > 0) { \
		while (n > PADSIZE) { \
			PRINT(with, PADSIZE); \
			n -= PADSIZE; \
		} \
		PRINT(with, n); \
	} \
}
#define	FLUSH() { \
	if (uio.uio_resid && NL_SPRINT(fp, &uio)) \
		goto error; \
	uio.uio_iovcnt = 0; \
	iovp = iov; \
}
#define	SARG() \
	(flags&LONGINT ? W2_VA_ARG(ap, long) : \
	    flags&SHORTINT ? (long)(short)W2_VA_ARG(ap, int) : \
	    (long)W2_VA_ARG(ap, int))
#define	UARG() \
	(flags&LONGINT ? W2_VA_ARG(ap, unsigned long) : \
	    flags&SHORTINT ? (unsigned long)(unsigned short)W2_VA_ARG(ap, int) : \
	    (unsigned long)W2_VA_ARG(ap, unsigned int))

	if (((fp->flags & 0x8) == 0 || fp->base == 0) && func_0028F3E8(fp))
		return (-1);

	if ((fp->flags & (0x2|0x8|0x10)) == (0x2|0x8) &&
	    fp->file >= 0)
		return (NL_SBPRINTF(fp, fmt0, ap));

	fmt = (char *)fmt0;
	uio.uio_iov = iovp = iov;
	uio.uio_resid = 0;
	uio.uio_iovcnt = 0;
	ret = 0;

	for (;;) {
	        cp = fmt;
	        while ((n = func_00291868(D_002BF5D0, &wc, fmt, D_002BFA38, &state)) > 0) {
			fmt += n;
			if (wc == '%') {
				fmt--;
				break;
			}
		}
		if ((m = fmt - cp) != 0) {
			PRINT(cp, m);
			ret += m;
		}
		if (n <= 0)
			goto done;
		fmt++;

		flags = 0;
		dprec = 0;
		width = 0;
		prec = -1;
		sign = '\0';

rflag:		ch = *fmt++;
reswitch:	switch (ch) {
		case ' ':
			if (!sign)
				sign = ' ';
			goto rflag;
		case '#':
			flags |= ALT;
			goto rflag;
		case '*':
			if ((width = W2_VA_ARG(ap, int)) >= 0)
				goto rflag;
			width = -width;
		case '-':
			flags |= LADJUST;
			goto rflag;
		case '+':
			sign = '+';
			goto rflag;
		case '.':
			if ((ch = *fmt++) == '*') {
				n = W2_VA_ARG(ap, int);
				prec = n < 0 ? -1 : n;
				goto rflag;
			}
			n = 0;
			while (is_digit(ch)) {
				n = 10 * n + to_digit(ch);
				ch = *fmt++;
			}
			prec = n < 0 ? -1 : n;
			goto reswitch;
		case '0':
			flags |= ZEROPAD;
			goto rflag;
		case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			n = 0;
			do {
				n = 10 * n + to_digit(ch);
				ch = *fmt++;
			} while (is_digit(ch));
			width = n;
			goto reswitch;
#ifdef FLOATING_POINT
		case 'L':
			flags |= LONGDBL;
			goto rflag;
#endif
		case 'h':
			flags |= SHORTINT;
			goto rflag;
		case 'l':
			if (*fmt == 'l') {
				fmt++;
				flags |= QUADINT;
			} else {
				flags |= LONGINT;
			}
			goto rflag;
		case 'q':
			flags |= QUADINT;
			goto rflag;
		case 'c':
			*(cp = buf) = W2_VA_ARG(ap, int);
			size = 1;
			sign = '\0';
			break;
		case 'D':
			flags |= LONGINT;
		case 'd':
		case 'i':
			_uquad = SARG();
			if ((long) _uquad < 0)
			{

				_uquad = -_uquad;
				sign = '-';
			}
			base = DEC;
			goto number;
#ifdef FLOATING_POINT
		case 'e':
		case 'E':
		case 'f':
		case 'g':
		case 'G':
			if (prec == -1) {
				prec = DEFPREC;
			} else if ((ch == 'g' || ch == 'G') && prec == 0) {
				prec = 1;
			}

			if (flags & LONGDBL) {
				_double = (double) W2_VA_ARG(ap, double);
			} else {
				_double = W2_VA_ARG(ap, double);
			}

			if (NL_ISINF(_double)) {
				if (_double < 0)
					sign = '-';
				cp = "Inf";
				size = 3;
				break;
			}
			if (NL_ISNAN(_double)) {
				cp = "NaN";
				size = 3;
				break;
			}

			flags |= FPT;

			cp = NL_CVT(data, _double, prec, flags, &softsign,
				&expt, ch, &ndig);

			if (ch == 'g' || ch == 'G') {
				if (expt <= -4 || expt > prec)
					ch = (ch == 'g') ? 'e' : 'E';
				else
					ch = 'g';
			} 
			if (ch <= 'e') {
				--expt;
				expsize = NL_EXPONENT(expstr, expt, ch);
				size = expsize + ndig;
				if (ndig > 1 || flags & ALT)
					++size;
			} else if (ch == 'f') {
				if (expt > 0) {
					size = expt;
					if (prec || flags & ALT)
						size += prec + 1;
				} else
					size = prec + 2;
			} else if (expt >= ndig) {
				size = expt;
				if (flags & ALT)
					++size;
			} else
				size = ndig + (expt > 0 ?
					1 : 2 - expt);

			if (softsign)
				sign = '-';
			break;
#endif /* FLOATING_POINT */
		case 'n':
			if (flags & LONGINT)
				*W2_VA_ARG(ap, long *) = ret;
			else if (flags & SHORTINT)
				*W2_VA_ARG(ap, short *) = ret;
			else
				*W2_VA_ARG(ap, int *) = ret;
			continue;
		case 'O':
			flags |= LONGINT;
		case 'o':
			_uquad = UARG();
			base = OCT;
			goto nosign;
		case 'p':
			_uquad = (unsigned long)W2_VA_ARG(ap, void *);
			base = HEX;
			xdigs = "0123456789abcdef";
			flags |= HEXPREFIX;
			ch = 'x';
			goto nosign;
		case 's':
			if ((cp = W2_VA_ARG(ap, char *)) == 0)
				cp = "(null)";
			if (prec >= 0) {
				char *p = func_0029189C(cp, 0, prec);

				if (p != 0) {
					size = p - cp;
					if (size > prec)
						size = prec;
				} else
					size = prec;
			} else
				size = strlen(cp);
			sign = '\0';
			break;
		case 'U':
			flags |= LONGINT;
		case 'u':
			_uquad = UARG();
			base = DEC;
			goto nosign;
		case 'X':
			xdigs = "0123456789ABCDEF";
			goto hex;
		case 'x':
			xdigs = "0123456789abcdef";
hex:			_uquad = UARG();
			base = HEX;
			if (flags & ALT && _uquad != 0)
				flags |= HEXPREFIX;

nosign:			sign = '\0';
number:			if ((dprec = prec) >= 0)
				flags &= ~ZEROPAD;

			cp = buf + BUF;
			if (_uquad != 0 || prec != 0) {
				switch (base) {
				case OCT:
					do {
						*--cp = to_char(_uquad & 7);
						_uquad >>= 3;
					} while (_uquad);
					if (flags & ALT && *cp != '0')
						*--cp = '0';
					break;

				case DEC:
					while (_uquad >= 10) {
						*--cp = to_char(_uquad % 10);
						_uquad /= 10;
					}
					*--cp = to_char(_uquad);
					break;

				case HEX:
					do {
						*--cp = xdigs[_uquad & 15];
						_uquad >>= 4;
					} while (_uquad);
					break;

				default:
					cp = "bug in vfprintf: bad base";
					size = strlen(cp);
					goto skipsize;
				}
			}
			size = buf + BUF - cp;
		skipsize:
			break;
		default:
			if (ch == '\0')
				goto done;
			cp = buf;
			*cp = ch;
			size = 1;
			sign = '\0';
			break;
		}

		realsz = dprec > size ? dprec : size;
		if (sign)
			realsz++;
		else if (flags & HEXPREFIX)
			realsz+= 2;

		if ((flags & (LADJUST|ZEROPAD)) == 0)
			PAD(width - realsz, blanks);

		if (sign) {
			PRINT(&sign, 1);
		} else if (flags & HEXPREFIX) {
			ox[0] = '0';
			ox[1] = ch;
			PRINT(ox, 2);
		}

		if ((flags & (LADJUST|ZEROPAD)) == ZEROPAD)
			PAD(width - realsz, zeroes);

		PAD(dprec - size, zeroes);

#ifdef FLOATING_POINT
		if ((flags & FPT) == 0) {
			PRINT(cp, size);
		} else {
			if (ch >= 'f') {
				if (_double == 0) {
					PRINT("0", 1);
					if (expt < ndig || (flags & ALT) != 0) {
						PRINT(decimal_point, 1);
						PAD(ndig - 1, zeroes);
					}
				} else if (expt <= 0) {
					PRINT("0", 1);
					if (expt || ndig) {
						PRINT(decimal_point, 1);
						PAD(-expt, zeroes);
						PRINT(cp, ndig);
					}
				} else if (expt >= ndig) {
					PRINT(cp, ndig);
					PAD(expt - ndig, zeroes);
					if (flags & ALT)
						PRINT(".", 1);
				} else {
					PRINT(cp, expt);
					cp += expt;
					PRINT(".", 1);
					PRINT(cp, ndig-expt);
				}
			} else {
				if (ndig > 1 || flags & ALT) {
					ox[0] = *cp++;
					ox[1] = '.';
					PRINT(ox, 2);
					if (_double) {
						PRINT(cp, ndig-1);
					} else
						PAD(ndig - 1, zeroes);
				} else
					PRINT(cp, 1);
				PRINT(expstr, expsize);
			}
		}
#else
		PRINT(cp, size);
#endif
		if (flags & LADJUST)
			PAD(width - realsz, blanks);

		ret += width > realsz ? width : realsz;

		FLUSH();
	}
done:
	FLUSH();
error:
	return ((fp->flags & 0x40) ? -1 : ret);
}
