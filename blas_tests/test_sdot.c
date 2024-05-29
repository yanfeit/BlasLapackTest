#include <stdio.h>
#include "funs.h"

int main()
{
    int n = 4; // Vector size
    float x[4] = {1.0f, 2.0f, 3.0f, 4.0f};
    float y[4] = {5.0f, 6.0f, 7.0f, 8.0f};
    int incx = 1, incy = 1; // Strides (accessing elements consecutively)

    float dot_product = sdot_(&n, x, &incx, y, &incy);

    printf("The dot product of x and y is: %f\n", dot_product);

    return 0;
}

/*
  The dot product of x and y is: 70.000000
*/
