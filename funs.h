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
extern void dtrsv_(char *uplo, char* trans, char* diag, int* n, double* A, int* lda, double* x, int* incx);
extern void ztrsv_(char *uplo, char* trans, char* diag, int* n, double complex* A, int* lda, double complex* x, int* incx);


// Level 3 BLAS
extern void dgemm_(char* transA, char* transB, int* m, int* n, int* k, double* alpha, double* A, int* lda, double* B, int* ldb, double* beta, double* C, int* ldc);
extern void zgemm_(char* transA, char* transB, int* m, int* n, int* k, double complex* alpha, double complex* A, int* lda, double complex* B, int* ldb, double complex* beta, double complex* C, int* ldc);


// LAPACK FUNCTIONS
extern void sgesv_(int*, int*, float*, int*, int*, float*, int*, int*);
extern void zgesv_(int* n, int* nrhs, double complex* A, int* lda, int* ipiv, double complex* B, int* ldb, int* info);
extern void dgeev_(char* jobvl, char* jobvr, int* n, double* A, int* lda, double* wr, double* wi, double* vl, int* ldvl, double* vr, int* ldvr, double* work, int* lwork, int* info);
extern void zgeev_(char* jobvl, char* jobvr, int* n, double complex* A, int* lda, double complex* w, double complex* vl, int* ldvl, double complex* vr, int* ldvr, double complex* work, int* lwork, double* rwork, int* info);
extern void dgetrf_(int* m, int* n, double* A, int* lda, int* ipiv, int* info);
extern void dgetri_(int* n, double* A, int* lda, int* ipiv, double* work, int* lwork, int* info);
extern void sgetri_(int* n, float* A, int* lda, int* ipiv, float* work, int* lwork, int* info);

#endif