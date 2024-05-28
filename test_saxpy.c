#include <stdio.h>
#include "funs.h"

// Assuming single precision (float) for this example

int main()
{
    int n = 3;          // Vector size
    float alpha = 2.0f; // Scalar value
    float x[3] = {1.0f, 2.0f, 3.0f};
    float y[3] = {4.0f, 5.0f, 6.0f};
    int incx = 1, incy = 1; // Strides (accessing elements consecutively)

    saxpy_(&n, &alpha, x, &incx, y, &incy);

    printf("y after adding 2x to it: ");
    for (int i = 0; i < n; i++)
    {
        printf("%f ", y[i]);
    }
    printf("\n");

    return 0;
}

/*
y after adding 2x to it: 6.000000 9.000000 12.000000
*/
