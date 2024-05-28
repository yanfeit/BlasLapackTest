#include <stdio.h>
#include <stdlib.h>
#include "funs.h"

// Hypothetical declaration for a gemv function (not real)
// y <--- alpha Ax + beta y

int main()
{
    char trans = 'N'; // Matrix in No Transpose form
    int m = 2, n = 3; // Matrix dimensions
    double alpha = 1.0, beta = 2.0;
    double A[6] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0}; // Matrix A (stored in row-major order)
    int lda = 2;                                  // Leading dimension of A (number of columns)
    double x[3] = {7.0, 8.0, 9.0};                // Vector x
    int incx = 1;                                 // Increment for x (stride between elements)
    int incy = 1;
    double y[2] = {0.0, 0.0};                     // Result vector y

    // Manual memory allocation (assuming double precision)
    double *A_mem = (double *)malloc(m * n * sizeof(double));

    // Copy matrix A into allocated memory (assuming row-major order)
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A_mem[i * n + j] = A[i * n + j];
        }
    }

    // Hypothetical function call (assuming correct prototype)
    dgemv_(&trans, &m, &n, &alpha, A, &lda, x, &incx, &beta, y, &incy);

    for (int i = 0; i < n; i++)
    {
        printf("x[%d] = %f\n", i, x[i]);
    }

    for (int i = 0; i < m*n; i++)
    {
        printf("A_men[%d] = %f\n", i, A_mem[i]);
    }

    // Free allocated memory
    free(A_mem);

    // Print the result (assuming it worked correctly)
    for (int i = 0; i < m; i++)
    {
        printf("y[%d] = %f\n", i, y[i]);
    }

    return 0;
}