#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include "funs.h"

// 
// x <----- A^-1 x, etc

int main()
{
    char uplo = 'L'; // Lower triangular matrix
    char trans = 'N'; // No Transpose
    char diag = 'N'; // Unit triangular matrix

    int n = 3; // Square Matrix dimension 3
    int lda = 3; // LDA must at least max(1,n)
    int incx = 1; // stride

    double complex A[9] = {1.0 + 1.0*I, 0.5 + 0.5 * I, 1.0 + 2.0*I, 0.0, 1.0+2.0*I, 0.2+0.3*I, 0.0, 0.0, 1.0+1.0*I};
    double complex x[3] = {1.0+1.0*I, 2.0+ 2.0*I, 3.0+3.0*I};

    ztrsv_(&uplo, &trans, &diag, &n, A, &lda, x, &incx);

    // Print the result (assuming it worked correctly)
    for (int i = 0; i < n; i++)
    {
        printf("x[%d] = (%f, %f)\n", i, creal(x[i]), cimag(x[i]));
    }

    return 0;
}
/*
x[0] = (1.000000, 0.000000)
x[1] = (0.900000, -0.300000)
x[2] = (1.260000, -0.470000)
*/