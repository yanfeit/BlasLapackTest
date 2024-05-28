#ifndef __FUNS_H__
#define __FUNS_H__

#include "complex.h"

// BLAS FUNCTIONS
extern float sdot_(const int *n, const float *x, const int *incx, const float *y, const int *incy);
extern float complex cdotc_(const int *n, const float complex *x, const int *incx, const float complex *y, const int *incy);
extern void  saxpy_(const int *n, const float *alpha, const float *x, const int *incx, float *y, const int *incy);
extern void  caxpy_(const int *n, const float complex *alpha, const float complex *x, const int *incx, float complex *y, const int *incy);

// LAPACK FUNCTIONS
extern void sgesv_(int*, int*, float*, int*, int*, float*, int*, int*);
extern void zgeev_(char*, char*, int*, double*, int*, double*, double*, int*, double*, int*, double*, int*, double*, int*);



#endif

