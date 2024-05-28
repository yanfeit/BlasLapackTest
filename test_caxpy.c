#include <stdio.h>
#include <complex.h> // For complex number support
#include "funs.h"

// Assuming complex float (float complex) for this example

int main()
{
    int n = 2;                             // Vector size
    float complex alpha = 2.0f + 3.0f * I; // Complex scalar
    float complex x[2] = {1.0f + 2.0f * I, 3.0f + 4.0f * I};
    float complex y[2] = {5.0f - 6.0f * I, 7.0f - 8.0f * I};
    int incx = 1, incy = 1; // Strides (accessing elements consecutively)

    caxpy_(&n, &alpha, x, &incx, y, &incy);

    printf("y after adding 2+3i times x to it: ");
    for (int i = 0; i < n; i++)
    {
        printf("(%f, %f) ", creal(y[i]), cimag(y[i]));
    }
    printf("\n");

    return 0;
}

/*
y after adding 2+3i times x to it: (1.000000, 1.000000) (1.000000, 9.000000)
*/