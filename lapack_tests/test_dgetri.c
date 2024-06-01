#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <float.h>
#include <math.h>
#include "funs.h"

// https://numericalalgorithmsgroup.github.io/LAPACK_Examples/examples/doc/dgetri_example.html
// ZGETRI computes the inverse of a matrix using the LU factorization
// computed by DGETRF.

// This method inverts U and then computes inv(A) by solving the system
// inv(A)*L = inv(U) for inv(A).

void print_column_major_matrix(double* matrix, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // Access element using column-major indexing
            int index = j * m + i;
            printf("%f   ", matrix[index]);
        }
        printf("\n"); // Move to the next line after each row
    }
}


int main()
{

    int n = 4; 
    double A[16] = {1.8, 5.25, 1.58, -1.11, 
                    2.88, -2.95, -2.69, -0.66, 
                    2.05, -0.95, -2.9, -0.59, 
                    -0.89, -3.8, -1.04, 0.8};  // target matrix A
    int lda = 4;          // leading dimension of the array A
    int ipiv[4];          // IPIV is INTEGER array. The pivot indices from DGETRF
    double work[4];
    int    lwork = 4;
    int    info;

    dgetrf_(&n, &n, A, &lda, ipiv, &info);

    if (info == 0)
    {
        dgetri_(&n, A, &lda, ipiv, work, &lwork, &info);
        print_column_major_matrix(A, n, n);
    }
    else
    {
        printf("The factor U is singular!");
    }

    return 0;
}

/*
1.771998   0.575691   0.084325   4.815502   
-0.117466   -0.445615   0.411363   -1.712581
0.179856   0.452662   -0.667565   1.482400
2.494382   0.764977   -0.035954   7.611900
*/