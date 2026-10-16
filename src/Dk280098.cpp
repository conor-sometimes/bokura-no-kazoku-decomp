#include "common.h"

// @decl-begin (declarations for the matched functions; scripts regenerate this block)
double func_00280290(double, double);
float func_002806B0(float);

typedef union { float value; u32 word; } W2Fs;
#define GET_FLOAT_WORD(i,d) do { W2Fs gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
#define SET_FLOAT_WORD(d,i) do { W2Fs sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)

float func_00281AE0(float, float);

float func_00281910(float, float, s32);
float func_00280F58(float, float);
s32 func_00280AD8(float, float *);

const s32 D_002EA634[];
const s32 D_002EA320[];
float func_00280070(float);
s32 func_002810A8(float *, float *, s32, s32, s32, const s32 *);
/* from newlib-1.9.0 libm/math/ef_acos.c (fdlibm, Sun Microsystems): __ieee754_acosf */
float func_00280E88(float);
#define W2A_one ((float)1.0000000000e+00)
#define W2A_pi ((float)3.1415925026e+00)
#define W2A_pio2_hi ((float)1.5707962513e+00)
#define W2A_pio2_lo ((float)7.5497894159e-08)
#define W2A_pS0 ((float)1.6666667163e-01)
#define W2A_pS1 ((float)-3.2556581497e-01)
#define W2A_pS2 ((float)2.0121252537e-01)
#define W2A_pS3 ((float)-4.0055535734e-02)
#define W2A_pS4 ((float)7.9153501429e-04)
#define W2A_pS5 ((float)3.4793309169e-05)
#define W2A_qS1 ((float)-2.4033949375e+00)
#define W2A_qS2 ((float)2.0209457874e+00)
#define W2A_qS3 ((float)-6.8828397989e-01)
#define W2A_qS4 ((float)7.7038154006e-02)
/* from newlib-1.9.0 libm/math/e_fmod.c (fdlibm, Sun Microsystems): __ieee754_fmod */
typedef union { double value; struct { u32 lsw; u32 msw; } parts; } W2Ds;
extern const double D_002EA2D8[];
/* from newlib-1.9.0 libm/math/kf_rem_pio2.c (fdlibm, Sun Microsystems): __kernel_rem_pio2f */
extern const s32 D_002EA708[];
extern const float D_002EA718[];
float func_00280098(float);
float func_00281A18(float, s32);
// @decl-end

float func_00280098(float x) { s32 i0, j0; u32 i, ix; GET_FLOAT_WORD(i0, x); ix = (i0 & 0x7fffffff); j0 = (ix >> 23) - 0x7f; if (j0 < 23) { if (j0 < 0) { if (1.0e30f + x > (float)0.0) { if (i0 >= 0) { i0 = 0; } else if (!(ix < 0x800000)) { i0 = 0xbf800000; } } } else { i = (0x007fffff) >> j0; if ((i0 & i) == 0) return x; if (1.0e30f + x > (float)0.0) { if (i0 < 0) i0 += (0x00800000) >> j0; i0 &= (~i); } } } else { return x; } SET_FLOAT_WORD(x, i0); return x; }

s32 func_00280170(void) { return 0; }

float func_00280178(float x) { float y[2], z = 0.0f; s32 n, ix; GET_FLOAT_WORD(ix, x); ix &= 0x7fffffff; if (ix <= 0x3f490fd8) return func_00281910(x, z, 0); else { n = func_00280AD8(x, y); switch (n & 3) { case 0: return func_00281910(y[0], y[1], 1); case 1: return func_00280F58(y[0], y[1]); case 2: return -func_00281910(y[0], y[1], 1); default: return -func_00280F58(y[0], y[1]); } } }

double fmod(double a, double b) { return func_00280290(a, b); }

float func_00280278(float a) { return func_002806B0(a); }

double func_00280290(double x, double y)

{
        s32 n,hx,hy,hz,ix,iy,sx,i;
        u32 lx,ly,lz;

        do { W2Ds ew_u; ew_u.value = (x); (hx) = ew_u.parts.msw; (lx) = ew_u.parts.lsw; } while (0);
        do { W2Ds ew_u; ew_u.value = (y); (hy) = ew_u.parts.msw; (ly) = ew_u.parts.lsw; } while (0);
        sx = hx&0x80000000;
        hx ^=sx;
        hy &= 0x7fffffff;

        if((hy|ly)==0||(hx>=0x7ff00000)||
          ((hy|((ly|-ly)>>31))>0x7ff00000))
            return (x*y)/(x*y);
        if(hx<=hy) {
            if((hx<hy)||(lx<ly)) return x;
            if(lx==ly)
                return D_002EA2D8[(u32)sx>>31];
        }

        if(hx<0x00100000) {
            if(hx==0) {
                for (ix = -1043, i=lx; i>0; i<<=1) ix -=1;
            } else {
                for (ix = -1022,i=(hx<<11); i>0; i<<=1) ix -=1;
            }
        } else ix = (hx>>20)-1023;

        if(hy<0x00100000) {
            if(hy==0) {
                for (iy = -1043, i=ly; i>0; i<<=1) iy -=1;
            } else {
                for (iy = -1022,i=(hy<<11); i>0; i<<=1) iy -=1;
            }
        } else iy = (hy>>20)-1023;

        if(ix >= -1022)
            hx = 0x00100000|(0x000fffff&hx);
        else {
            n = -1022-ix;
            if(n<=31) {
                hx = (hx<<n)|(lx>>(32-n));
                lx <<= n;
            } else {
                hx = lx<<(n-32);
                lx = 0;
            }
        }
        if(iy >= -1022)
            hy = 0x00100000|(0x000fffff&hy);
        else {
            n = -1022-iy;
            if(n<=31) {
                hy = (hy<<n)|(ly>>(32-n));
                ly <<= n;
            } else {
                hy = ly<<(n-32);
                ly = 0;
            }
        }

        n = ix - iy;
        while(n--) {
            hz=hx-hy;lz=lx-ly; if(lx<ly) hz -= 1;
            if(hz<0){hx = hx+hx+(lx>>31); lx = lx+lx;}
            else {
                if((hz|lz)==0)
                    return D_002EA2D8[(u32)sx>>31];
                hx = hz+hz+(lz>>31); lx = lz+lz;
            }
        }
        hz=hx-hy;lz=lx-ly; if(lx<ly) hz -= 1;
        if(hz>=0) {hx=hz;lx=lz;}

        if((hx|lx)==0)
            return D_002EA2D8[(u32)sx>>31];
        while(hx<0x00100000) {
            hx = hx+hx+(lx>>31); lx = lx+lx;
            iy -= 1;
        }
        if(iy>= -1022) {
            hx = ((hx-0x00100000)|((iy+1023)<<20));
            do { W2Ds iw_u; iw_u.parts.msw = (hx|sx); iw_u.parts.lsw = (lx); (x) = iw_u.value; } while (0);
        } else {
            n = -1022 - iy;
            if(n<=20) {
                lx = (lx>>n)|((u32)hx<<(32-n));
                hx >>= n;
            } else if (n<=31) {
                lx = (hx<<(32-n))|(lx>>n); hx = sx;
            } else {
                lx = hx>>(n-32); hx = sx;
            }
            do { W2Ds iw_u; iw_u.parts.msw = (hx|sx); iw_u.parts.lsw = (lx); (x) = iw_u.value; } while (0);
            x *= 1.0;
        }
        return x;
}

float func_002806B0(float x)

{
        float z,p,q,r,w,s,c,df;
        s32 hx,ix;
        do { W2Fs gf_u; gf_u.value = (x); (hx) = gf_u.word; } while (0);
        ix = hx&0x7fffffff;
        if(ix==0x3f800000) {
            if(hx>0) return 0.0;
            else return W2A_pi+(float)2.0*W2A_pio2_lo;
        } else if(ix>0x3f800000) {
            return (x-x)/(x-x);
        }
        if(ix<0x3f000000) {
            if(ix<=0x23000000) return W2A_pio2_hi+W2A_pio2_lo;
            z = x*x;
            p = z*(W2A_pS0+z*(W2A_pS1+z*(W2A_pS2+z*(W2A_pS3+z*(W2A_pS4+z*W2A_pS5)))));
            q = W2A_one+z*(W2A_qS1+z*(W2A_qS2+z*(W2A_qS3+z*W2A_qS4)));
            r = p/q;
            return W2A_pio2_hi - (x - (W2A_pio2_lo-x*r));
        } else if (hx<0) {
            z = (W2A_one+x)*(float)0.5;
            p = z*(W2A_pS0+z*(W2A_pS1+z*(W2A_pS2+z*(W2A_pS3+z*(W2A_pS4+z*W2A_pS5)))));
            q = W2A_one+z*(W2A_qS1+z*(W2A_qS2+z*(W2A_qS3+z*W2A_qS4)));
            s = func_00280E88(z);
            r = p/q;
            w = r*s-W2A_pio2_lo;
            return W2A_pi - (float)2.0*(s+w);
        } else {
            s32 idf;
            z = (W2A_one-x)*(float)0.5;
            s = func_00280E88(z);
            df = s;
            do { W2Fs gf_u; gf_u.value = (df); (idf) = gf_u.word; } while (0);
            do { W2Fs sf_u; sf_u.word = (idf&0xfffff000); (df) = sf_u.value; } while (0);
            c = (z-df*df)/(s+df);
            p = z*(W2A_pS0+z*(W2A_pS1+z*(W2A_pS2+z*(W2A_pS3+z*(W2A_pS4+z*W2A_pS5)))));
            q = W2A_one+z*(W2A_qS1+z*(W2A_qS2+z*(W2A_qS3+z*W2A_qS4)));
            r = p/q;
            w = r*s+c;
            return (float)2.0*(df+w);
        }
}

s32 func_00280AD8(float x, float *y) { float z, w, t, r, fn; float tx[3]; s32 i, j, n, ix, hx; s32 e0, nx; GET_FLOAT_WORD(hx, x); ix = hx & 0x7fffffff; if (ix <= 0x3f490fd8) { y[0] = x; y[1] = 0; return 0; } if (ix < 0x4016cbe4) { if (hx > 0) { z = x - 1.5707855225e+00f; if ((ix & 0xfffffff0) != 0x3fc90fd0) { y[0] = z - 1.0804334124e-05f; y[1] = (z - y[0]) - 1.0804334124e-05f; } else { z -= 1.0804273188e-05f; y[0] = z - 6.0770999344e-11f; y[1] = (z - y[0]) - 6.0770999344e-11f; } return 1; } else { z = x + 1.5707855225e+00f; if ((ix & 0xfffffff0) != 0x3fc90fd0) { y[0] = z + 1.0804334124e-05f; y[1] = (z - y[0]) + 1.0804334124e-05f; } else { z += 1.0804273188e-05f; y[0] = z + 6.0770999344e-11f; y[1] = (z - y[0]) + 6.0770999344e-11f; } return -1; } } if (ix <= 0x43490f80) { t = func_00280070(x); n = (s32)(t * 6.3661980629e-01f + 0.5f); fn = (float)n; r = t - fn * 1.5707855225e+00f; w = fn * 1.0804334124e-05f; if (n < 32 && (ix & 0xffffff00) != D_002EA634[n]) { y[0] = r - w; } else { u32 high; j = ix >> 23; y[0] = r - w; GET_FLOAT_WORD(high, y[0]); i = j - ((high >> 23) & 0xff); if (i > 8) { t = r; w = fn * 1.0804273188e-05f; r = t - w; w = fn * 6.0770999344e-11f - ((t - r) - w); y[0] = r - w; GET_FLOAT_WORD(high, y[0]); i = j - ((high >> 23) & 0xff); if (i > 25) { t = r; w = fn * 6.0770943833e-11f; r = t - w; w = fn * 6.1232342629e-17f - ((t - r) - w); y[0] = r - w; } } } y[1] = (r - y[0]) - w; if (hx < 0) { y[0] = -y[0]; y[1] = -y[1]; return -n; } else return n; } e0 = (s32)((ix >> 23) - 134); SET_FLOAT_WORD(z, ix - ((s32)(e0 << 23))); for (i = 0; i < 2; i++) { tx[i] = (float)((s32)(z)); z = (z - tx[i]) * 2.5600000000e+02f; } tx[2] = z; nx = 3; while (tx[nx - 1] == 0.0f) nx--; n = func_002810A8(tx, y, e0, nx, 2, D_002EA320); if (hx < 0) { y[0] = -y[0]; y[1] = -y[1]; return -n; } return n; }

INCLUDE_ASM("asm/nonmatchings/Dk280098", func_00280E88);

float func_00280F58(float x, float y) { float a, hz, z, r, qx; s32 ix; GET_FLOAT_WORD(ix, x); ix &= 0x7fffffff; if (ix < 0x32000000) { if (((s32)x) == 0) return 1.0f; } z = x * x; r = z * (4.1666667908e-02f + z * (-1.3888889225e-03f + z * (2.4801587642e-05f + z * (-2.7557314297e-07f + z * (2.0875723372e-09f + z * -1.1359647598e-11f))))); if (ix < 0x3e99999a) return 1.0f - ((float)0.5 * z - (z * r - x * y)); else { if (ix > 0x3f480000) { qx = (float)0.28125; } else { SET_FLOAT_WORD(qx, ix - 0x01000000); } hz = (float)0.5 * z - qx; a = 1.0f - qx; return a - (hz - (z * r - x * y)); } }

s32 func_002810A8(float *x, float *y, s32 e0, s32 nx, s32 prec, const s32 *ipio2)

{
        s32 jz,jx,jv,jp,jk,carry,n,iq[20],i,j,k,m,q0,ih;
        float z,fw,f[20],fq[20],q[20];

        jk = D_002EA708[prec];
        jp = jk;

        jx = nx-1;
        jv = (e0-3)/8; if(jv<0) jv=0;
        q0 = e0-8*(jv+1);

        j = jv-jx; m = jx+jk;
        for(i=0;i<=m;i++,j++) f[i] = (j<0)? ((float)0.0) : (float) ipio2[j];

        for (i=0;i<=jk;i++) {
            for(j=0,fw=0.0;j<=jx;j++) fw += x[j]*f[jx+i-j]; q[i] = fw;
        }

        jz = jk;
recompute:

        for(i=0,j=jz,z=q[jz];j>0;i++,j--) {
            fw = (float)((s32)(((float)3.9062500000e-03)* z));
            iq[i] = (s32)(z-((float)2.5600000000e+02)*fw);
            z = q[j-1]+fw;
        }

        z = func_00281A18(z,(int)q0);
        z -= (float)8.0*func_00280098(z*(float)0.125);
        n = (s32)(z);
        z -= (float)n;
        ih = 0;
        if(q0>0) {
            i = (iq[jz-1]>>(8-q0)); n += i;
            iq[jz-1] -= i<<(8-q0);
            ih = iq[jz-1]>>(7-q0);
        }
        else if(q0==0) ih = iq[jz-1]>>8;
        else if(z>=(float)0.5) ih=2;

        if(ih>0) {
            n += 1; carry = 0;
            for(i=0;i<jz ;i++) {
                j = iq[i];
                if(carry==0) {
                    if(j!=0) {
                        carry = 1; iq[i] = 0x100- j;
                    }
                } else iq[i] = 0xff - j;
            }
            if(q0>0) {
                switch(q0) {
                case 1:
                   iq[jz-1] &= 0x7f; break;
                case 2:
                   iq[jz-1] &= 0x3f; break;
                }
            }
            if(ih==2) {
                z = ((float)1.0) - z;
                if(carry!=0) z -= func_00281A18(((float)1.0),(int)q0);
            }
        }

        if(z==((float)0.0)) {
            j = 0;
            for (i=jz-1;i>=jk;i--) j |= iq[i];
            if(j==0) {
                for(k=1;iq[jk-k]==0;k++);

                for(i=jz+1;i<=jz+k;i++) {
                    f[jx+i] = (float) ipio2[jv+i];
                    for(j=0,fw=0.0;j<=jx;j++) fw += x[j]*f[jx+i-j];
                    q[i] = fw;
                }
                jz += k;
                goto recompute;
            }
        }

        if(z==(float)0.0) {
            jz -= 1; q0 -= 8;
            while(iq[jz]==0) { jz--; q0-=8;}
        } else {
            z = func_00281A18(z,-(int)q0);
            if(z>=((float)2.5600000000e+02)) {
                fw = (float)((s32)(((float)3.9062500000e-03)*z));
                iq[jz] = (s32)(z-((float)2.5600000000e+02)*fw);
                jz += 1; q0 += 8;
                iq[jz] = (s32)(fw);
            } else iq[jz] = (s32)(z) ;
        }

        fw = func_00281A18(((float)1.0),(int)q0);
        for(i=jz;i>=0;i--) {
            q[i] = fw*(float)iq[i]; fw*=((float)3.9062500000e-03);
        }

        for(i=jz;i>=0;i--) {
            for(fw=0.0,k=0;k<=jp&&k<=jz-i;k++) fw += D_002EA718[k]*q[i+k];
            fq[jz-i] = fw;
        }

        switch(prec) {
            case 0:
                fw = 0.0;
                for (i=jz;i>=0;i--) fw += fq[i];
                y[0] = (ih==0)? fw: -fw;
                break;
            case 1:
            case 2:
                fw = 0.0;
                for (i=jz;i>=0;i--) fw += fq[i];
                y[0] = (ih==0)? fw: -fw;
                fw = fq[0]-fw;
                for (i=1;i<=jz;i++) fw += fq[i];
                y[1] = (ih==0)? fw: -fw;
                break;
            case 3:
                for (i=jz;i>0;i--) {
                    fw = fq[i-1]+fq[i];
                    fq[i] += fq[i-1]-fw;
                    fq[i-1] = fw;
                }
                for (i=jz;i>1;i--) {
                    fw = fq[i-1]+fq[i];
                    fq[i] += fq[i-1]-fw;
                    fq[i-1] = fw;
                }
                for (fw=0.0,i=jz;i>=2;i--) fw += fq[i];
                if(ih==0) {
                    y[0] = fq[0]; y[1] = fq[1]; y[2] = fw;
                } else {
                    y[0] = -fq[0]; y[1] = -fq[1]; y[2] = -fw;
                }
        }
        return n&7;
}

float func_00281910(float x, float y, s32 iy) { float z, r, v; s32 ix; GET_FLOAT_WORD(ix, x); ix &= 0x7fffffff; if (ix < 0x32000000) { if ((s32)x == 0) return x; } z = x * x; v = z * x; r = 8.3333337680e-03f + z * (-1.9841270114e-04f + z * (2.7557314297e-06f + z * (-2.5050759689e-08f + z * 1.5896910177e-10f))); if (iy == 0) return x + v * (-1.6666667163e-01f + z * r); else return x - ((z * (0.5f * y - v * r) - y) - v * -1.6666667163e-01f); }

float func_00281A18(float x, s32 n) { s32 k, ix; u32 hx; GET_FLOAT_WORD(ix, x); hx = ix & 0x7fffffff; k = hx >> 23; if (hx <= 0x7FFFFF) return x; k = k + n; if (k > 255) return 1.0e30f * func_00281AE0(1.0e30f, x); if (k > 0) { SET_FLOAT_WORD(x, (ix & 0x807fffff) | (k << 23)); return x; } if (n > 50000) return 1.0e30f * func_00281AE0(1.0e30f, x); else return 1.0e-30f * func_00281AE0(1.0e-30f, x); }

float func_00281AE0(float x, float y) { u32 ix, iy; GET_FLOAT_WORD(ix, x); GET_FLOAT_WORD(iy, y); SET_FLOAT_WORD(x, (ix & 0x7fffffff) | (iy & 0x80000000)); return x; }

/* from gcc-2.95.2 libgcc2.c (GPL): __muldi3 (L_muldi3), with longlong.h's MIPS umul_ppmm */
struct W2DIstruct { s32 low, high; };
typedef union { struct W2DIstruct s; long long ll; } W2DIunion;
long long func_00281B20(long long u, long long v)
{
    W2DIunion w;
    W2DIunion uu, vv;

    uu.ll = u,
    vv.ll = v;

    w.ll = ({ W2DIunion __w; __asm__("multu %2,%3" : "=l"((u32)(__w.s.low)), "=h"((u32)(__w.s.high)) : "d"((u32)(uu.s.low)), "d"((u32)(vv.s.low))); __w.ll; });
    w.s.high += ((u32)uu.s.low * (u32)vv.s.high
                 + (u32)uu.s.high * (u32)vv.s.low);

    return w.ll;
}

INCLUDE_ASM("asm/nonmatchings/Dk280098", func_00281B98);

INCLUDE_ASM("asm/nonmatchings/Dk280098", func_00282230);
