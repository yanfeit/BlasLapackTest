#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <float.h>
#include <math.h>
#include "funs.h"

// https://numericalalgorithmsgroup.github.io/LAPACK_Examples/examples/doc/zgetrf_example.html
// ZGETRF computes an LU factorization of a general M-by-N matrix A
// using partial pivoting with row interchanges.


void print_column_major_matrix(double complex* matrix, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // Access element using column-major indexing
            int index = j * m + i;
            printf("(%f, %f)  ", creal(matrix[index]), cimag(matrix[index]));
        }
        printf("\n"); // Move to the next line after each row
    }
}


int main()
{

    int m = 4;
    int n = 4; 
    double complex A[16] = {-1.34+2.55*I, -0.17-1.41*I, -3.29-2.39*I, 2.41+0.39*I, 
                    0.28+3.17*I, 3.31-0.15*I, -1.91+4.42*I , -0.56+1.47*I, 
                    -6.39-2.2*I, -0.15+1.34*I, -0.14-1.35*I, -0.83-0.69*I, 
                    0.72-0.92*I, 1.29+1.38*I, 1.72+1.35*I, -1.96+0.67*I};  // target matrix A
    int lda = 4;          // leading dimension of the array A
    int ipiv[4];          // IPIV is INTEGER array. The pivot indices from DGETRF
    int    info;

    zgetrf_(&m, &n, A, &lda, ipiv, &info);

    if (info == 0)
    {
        printf("successful exit!\n");
    }
    else{
        printf("info : %d", info);
    }

    printf("\n");

    print_column_major_matrix(A, m, n);

    return 0;
}

/*
successful exit!

(-3.290000, -2.390000)  (-1.910000, 4.420000)  (-0.140000, -1.350000)  (1.720000, 1.350000)  
(0.237612, 0.255960)  (4.895181, -0.711362)  (-0.462280, 1.696611)  (1.226853, 0.618973)  
(-0.101952, -0.701014)  (-0.669150, 0.368870)  (-5.141411, -1.129970)  (0.998258, 0.385015)
(-0.535855, 0.270727)  (-0.204022, 0.860118)  (0.008233, 0.121064)  (0.148239, -0.125224)
*/