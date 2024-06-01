#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <float.h>
#include <math.h>
#include "funs.h"

// https://numericalalgorithmsgroup.github.io/LAPACK_Examples/examples/doc/zgetri_example.html
// ZGETRI computes the inverse of a matrix using the LU factorization
// computed by ZGETRF.

// This method inverts U and then computes inv(A) by solving the system
// inv(A)*L = inv(U) for inv(A).

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

    int n = 4; 
    double complex A[16] = {-1.34+2.55*I, -0.17-1.41*I, -3.29-2.39*I, 2.41+0.39*I, 
                            0.28+3.17*I, 3.31-0.15*I, -1.91+4.42*I, -0.56+1.47*I, 
                            -6.39-2.2*I, -0.15+1.34*I, -0.14-1.35*I, -0.83-0.69*I, 
                            0.72-0.92*I, 1.29+1.38*I, 1.72+1.35*I, -1.96+0.67*I};  // target matrix A
    int lda = 4;          // leading dimension of the array A
    int ipiv[4];          // IPIV is INTEGER array. The pivot indices from ZGETRF
    double complex work[4];
    int    lwork = 4;
    int    info;

    zgetrf_(&n, &n, A, &lda, ipiv, &info);

    if (info == 0)
    {
        zgetri_(&n, A, &lda, ipiv, work, &lwork, &info);
        print_column_major_matrix(A, n, n);
    }
    else
    {
        printf("The factor U is singular!");
    }

    return 0;
}

/*
./test_zgetri
(0.075662, -0.432358)  (1.651236, -3.134178)  (1.266317, 0.041789)  (3.818132, 1.119522)  
(-0.194153, 0.079808)  (-1.189968, -0.142637)  (-0.240144, -0.588872)  (-0.010076, -1.496878)
(-0.095676, -0.049102)  (0.737108, -0.428972)  (0.322421, 0.077566)  (0.688745, 0.789104)
(0.370184, -0.503968)  (3.725285, -3.181317)  (1.701354, 0.726729)  (3.936678, 3.325481)
*/