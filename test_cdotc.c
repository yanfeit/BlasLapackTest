#include <stdio.h>
#include <complex.h> // For complex number support
#include "funs.h"

// Assuming complex float (float complex) for this example


int main() {
  int n = 3; // Vector size
  float complex x[3] = {1.0f + 2.0f * I, 3.0f + 4.0f * I, 5.0f + 6.0f * I};
  float complex y[3] = {7.0f - 8.0f * I, 9.0f - 1.0f * I, 11.0f + 2.0f * I};
  int incx = 1, incy = 1; // Strides (accessing elements consecutively)
  float complex dot_product;

  dot_product = cdotc_(&n, x, &incx, y, &incy);

  printf("The dot product of x and y is: (%f, %f) \n", creal(dot_product), cimag(dot_product));

  return 0;
}
