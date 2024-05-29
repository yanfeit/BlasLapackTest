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
    char diag = 'U'; // Unit triangular matrix

    int n = 3; // Square Matrix dimension 3
    int lda = 3; // LDA must at least max(1,n)
    int incx = 1; // stride

    double A[9] = {1.0, 0.5, 1.0, 0.0, 1.0, 0.2, 0.0, 0.0, 1.0};
    double x[3] = {1.0, 2.0, 3.0};

    dtrsv_(&uplo, &trans, &diag, &n, A, &lda, x, &incx);

    // Print the result (assuming it worked correctly)
    for (int i = 0; i < n; i++)
    {
        printf("x[%d] = %f\n", i, x[i]);
    }

    return 0;
}
/*
x[0] = 1.000000
x[1] = 1.500000
x[2] = 1.700000
*/