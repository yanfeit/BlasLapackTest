#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include "funs.h"

// Hypothetical declaration for a gemv function (not real)
// A * X = B


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
    int n = 4;
    int nrhs = 1;

    double complex A[16] = {-1.34+2.55*I, -0.17-1.41*I, -3.29-2.39*I, 2.41+0.39*I,
                            0.28+3.17*I, 3.31-0.15*I, -1.91+4.42*I, -0.56+1.47*I, 
                            -6.39-2.2*I, -0.15+1.34*I, -0.14-1.35*I, -0.83-0.69*I,
                            0.72-0.92*I, 1.29+1.38*I, 1.72+1.35*I, -1.96+0.67*I};
    int lda = 4;
    int ipiv[4];
    double complex B[4] = {26.26+51.78*I, 6.43-8.68*I, -5.75+25.31*I, 1.16+2.57*I};
    int ldb=4;
    int info;

    zgesv_(&n, &nrhs, A, &lda, ipiv, B, &ldb, &info);

    if (info == 0)
    {
        printf("successful exit!\n");
    }

    for (int i = 0; i < n; i++)
    {
        printf("(%e, %e)\n", creal(B[i]), cimag(B[i]));
    }
    
    printf("Details of factorization\n");

    print_column_major_matrix(A, 4, 4);

    printf("Pivot indices: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", ipiv[i]);
    }
    printf("\n");

    return 0;
}

/*
ZGESV Example Program Results

 Solution
    ( 1.0000, 1.0000) ( 2.0000,-3.0000) (-4.0000,-5.0000) ( 0.0000, 6.0000)

 Details of factorization
                    1                 2                 3                 4
 1  (-3.2900,-2.3900) (-1.9100, 4.4200) (-0.1400,-1.3500) ( 1.7200, 1.3500)
 2  ( 0.2376, 0.2560) ( 4.8952,-0.7114) (-0.4623, 1.6966) ( 1.2269, 0.6190)
 3  (-0.1020,-0.7010) (-0.6691, 0.3689) (-5.1414,-1.1300) ( 0.9983, 0.3850)
 4  (-0.5359, 0.2707) (-0.2040, 0.8601) ( 0.0082, 0.1211) ( 0.1482,-0.1252)

 Pivot indices
           3          2          3          4
*/