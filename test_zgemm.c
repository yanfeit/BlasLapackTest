#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include "funs.h"

// Hypothetical declaration for a gemv function (not real)
// C <--- alpha * op(A) * op(B) + beta * C, op(X) = X, X^T, X^H, C --- m*n


void print_column_major_matrix(double complex *matrix, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // Access element using column-major indexing
            int index = j * m + i;
            printf("(%f+%f*I)   ", creal(matrix[index]), cimag(matrix[index]));
        }
        printf("\n"); // Move to the next line after each row
    }
}


int main()
{
    char transA = 'N'; // No Transpose for A and B
    char transB = 'N'; 
    int m = 3, k = 2, n = 4; // Matrix dimension
    double complex alpha = 2.5, beta = 1.2;
    int lda = 3; // TransA='N', then lda must be at least max(1,m), otherwise max(1,k)
    int ldb = 2; // TransB='N', then ldb must be at least max(1,k), otherwise max(1,n)
    int ldc = 3; // ldc must be at least max(1,m)

    double complex A[6] = {1+1.0*I, 3+3.0*I, 5+5.0*I, 2+2.0*I, 4+1.0*I, 6+1.8*I};
    double complex B[8] = {7+14*I, 11+10*I, 8+13*I, 12+9*I, 9+12.1*I, 13+8.1*I, 10+11.9*I, 14+7.2*I};
    double complex C[12] = {1+1*I, 1+2*I, 1+3*I, 2+4*I, 2+5*I, 2+6*I, 3+7*I, 3+9*I, 3+10*I, 4+11*I, 5+12*I, 6+13*I};

    zgemm_(&transA, &transB, &m, &n, &k, &alpha, A, &lda, B, &ldb, &beta, C, &ldc);

    // Print the results

    printf("C in one-dimension\n");
    for (int i = 0; i < 12; i++)
        printf("C[%d] = (%f %f)\n", i, creal(C[i]), cimag(C[i]));

    printf("\n");

    print_column_major_matrix(C, m, n);
}

/*
C[0] = (-11.300000 158.700000)
C[1] = (33.700000 287.400000)
C[2] = (33.700000 465.600000)
C[3] = (4.900000 162.300000)
C[4] = (62.400000 283.500000)
C[5] = (79.400000 458.700000)
C[6] = (20.350000 166.650000)
C[7] = (90.100000 282.550000)
C[8] = (123.400000 455.750000)
C[9] = (34.050000 173.950000)
C[10] = (113.750000 285.650000)
C[11] = (161.050000 460.350000)

(-11.300000+158.700000*I)   (4.900000+162.300000*I)   (20.350000+166.650000*I)   (34.050000+173.950000*I)
(33.700000+287.400000*I)   (62.400000+283.500000*I)   (90.100000+282.550000*I)   (113.750000+285.650000*I)
(33.700000+465.600000*I)   (79.400000+458.700000*I)   (123.400000+455.750000*I)   (161.050000+460.350000*I)
*/