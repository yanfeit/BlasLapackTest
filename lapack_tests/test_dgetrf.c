#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <float.h>
#include <math.h>
#include "funs.h"

// https://numericalalgorithmsgroup.github.io/LAPACK_Examples/examples/doc/dgetrf_example.html
// DGETRF computes an LU factorization of a general M-by-N matrix A
// using partial pivoting with row interchanges.


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

    int m = 4;
    int n = 4; 
    double A[16] = {1.8, 5.25, 1.58, -1.11, 
                    2.88, -2.95, -2.69, -0.66, 
                    2.05, -0.95, -2.9, -0.59, 
                    -0.89, -3.8, -1.04, 0.8};  // target matrix A
    int lda = 4;          // leading dimension of the array A
    int ipiv[4];          // IPIV is INTEGER array. The pivot indices from DGETRF
    int    info;

    dgetrf_(&m, &n, A, &lda, ipiv, &info);

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
DGETRF Example Program Results

 Details of factorization
             1          2          3          4
 1      5.2500    -2.9500    -0.9500    -3.8000
 2      0.3429     3.8914     2.3757     0.4129
 3      0.3010    -0.4631    -1.5139     0.2948
 4     -0.2114    -0.3299     0.0047     0.1314

 IPIV
             2          2          3          4
*/