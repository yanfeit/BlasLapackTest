#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include "funs.h"

// Hypothetical declaration for a gemv function (not real)
// y <--- alpha Ax + beta y

int main()
{
    char trans = 'N'; // Matrix in No Transpose form
    int m = 2, n = 3; // Matrix dimensions
    double complex alpha = 1.1 + 2.2*I;
    double complex beta =  2.0 + 1.2*I;
    double complex A[6] = {1.0 + 1.0*I, 2.0 + 2.0*I, 3.0+ 3.0*I, 4.0+4.0*I, 5.0+5.0*I, 6.0+6.0*I}; // Matrix A (stored in row-major order)
    int lda = 2;                                  // Leading dimension of A (number of columns)
    double complex x[3] = {3.0+3.0*I, 2.0+2.0*I, 4.0+4.0*I};                // Vector x
    int incx = 1;                                 // Increment for x (stride between elements)
    int incy = 1;
    double complex y[2] = {0.0+1.0*I, 1.0+2.0*I};                     // Result vector y

    // Hypothetical function call (assuming correct prototype)
    zgemv_(&trans, &m, &n, &alpha, A, &lda, x, &incx, &beta, y, &incy);

    // Print the result (assuming it worked correctly)
    for (int i = 0; i < m; i++)
    {
        printf("y[%d] = (%f, %f)\n", i, creal(y[i]), cimag(y[i]));
    }

    return 0;
}