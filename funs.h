#ifndef __FUNS_H__
#define __FUNS_H__

#include "complex.h"

// BLAS FUNCTIONS

// Level 1 BLAS
extern float sdot_(const int *n, const float *x, const int *incx, const float *y, const int *incy);
extern float complex cdotc_(const int *n, const float complex *x, const int *incx, const float complex *y, const int *incy);
extern void  saxpy_(const int *n, const float *alpha, const float *x, const int *incx, float *y, const int *incy);
extern void  caxpy_(const int *n, const float complex *alpha, const float complex *x, const int *incx, float complex *y, const int *incy);

// Level 2 BLAS
extern void dgemv_(char *trans, int *m, int *n, double *alpha, double *A, int *lda, double *x, int *incx, double *beta, double *y, int *incy);
extern void cgemv_(char *trans, int *m, int *n, float complex *alpha, float complex *A, int *lda, float complex *x, int *incx, float complex *beta, float complex *y, int *incy);
extern void zgemv_(char *trans, int *m, int *n, double complex *alpha, double complex *A, int *lda, double complex *x, int *incx, double complex *beta, double complex *y, int *incy);



// LAPACK FUNCTIONS
extern void sgesv_(int*, int*, float*, int*, int*, float*, int*, int*);
extern void zgeev_(char*, char*, int*, double*, int*, double*, double*, int*, double*, int*, double*, int*, double*, int*);



#endif

