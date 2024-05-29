#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include "funs.h"

// Hypothetical declaration for a gemv function (not real)
// C <--- alpha * op(A) * op(B) + beta * C, op(X) = X, X^T, X^H, C --- m*n

void print_column_major_matrix(double *matrix, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // Access element using column-major indexing
            int index = j * m + i;
            printf("%f ", matrix[index]);
        }
        printf("\n"); // Move to the next line after each row
    }
}

int main()
{
    char transA = 'N'; // No Transpose for A and B
    char transB = 'N';
    int m = 3, k = 2, n = 4; // Matrix dimension
    double alpha = 2.5, beta = 1.2;
    int lda = 3; // TransA='N', then lda must be at least max(1,m), otherwise max(1,k)
    int ldb = 2; // TransB='N', then ldb must be at least max(1,k), otherwise max(1,n)
    int ldc = 3; // ldc must be at least max(1,m)

    double A[6] = {1, 3, 5, 2, 4, 6};
    double B[8] = {7, 11, 8, 12, 9, 13, 10, 14};
    double C[12] = {1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 5, 6};

    dgemm_(&transA, &transB, &m, &n, &k, &alpha, A, &lda, B, &ldb, &beta, C, &ldc);

    // Print the results

    printf("C in one-dimension\n");
    for (int i = 0; i < 12; i++)
        printf("C[%d] = %f\t", i, C[i]);

    printf("\n");

    print_column_major_matrix(C, m, n);
}

/*
array([[ 73.7,  82.4,  91.1,  99.8],
       [163.7, 182.4, 201.1, 221. ],
       [253.7, 282.4, 311.1, 342.2]])
*/
