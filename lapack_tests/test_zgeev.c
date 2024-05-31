#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <float.h>
#include <math.h>
#include "funs.h"


// https://numericalalgorithmsgroup.github.io/LAPACK_Examples/examples/doc/zgeev_example.html
// ZGEEV computes the eigenvalues and, optionally, the left and/or right eigenvectors for GE matrices


void print_column_major_matrix(double* matrix, int m, int n)
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
    char jobvl='N';  // 'N': left eigenvectors of A are not computed.
    char jobvr='V'; // 'V' : right eigenvectors of A are computed.

    int n = 4;
    double complex A[16] = {-3.97-5.04*I, 0.34-1.5*I, 3.31-3.85*I, -1.1+0.82*I,
                            -4.11+3.7*I, 1.52-0.43*I, 2.5+3.45*I,   1.81-1.59*I,
                            -0.34+1.01*I, 1.88-5.38*I, 0.88-1.08*I, 3.25+1.33*I,
                            1.29-0.86*I, 3.36+0.65*I, 0.64-1.48*I, 1.57-3.44*I};  // on exit, A has been overwritten!
    int lda = 4;
    double complex w[4]; // w contains the complex eigenvalues

    complex double vl[4*4];  // left eigenvector , if jobvl='N' then not referenced.
    int ldvl = 4;    // leading dimension of the array vl

    complex double vr[4*4]; // right eigenvector, 
    int ldvr = 4;   // leading dimension of the array vr

    complex double work[8];
    int lwork = 8;
    double rwork[8];

    int info;

    zgeev_(&jobvl, &jobvr, &n, A, &lda, w, vl, &ldvl, vr, &ldvr, work, &lwork, rwork, &info);

    if (info == 0)
    {
        printf("successful exit!\n");
    }
    else{
        printf("info : %d", info);
    }

    printf("\n");


    for (int i = 0; i < n; i++)
    {
        printf("%dth Eigenvalue : (%f, %f)\n", i,  creal(w[i]), cimag(w[i]));
        printf("\n");
        printf("%dth Eigenvector : \n", i);

        for (int j= 0; j < n; j++)
        {
            int idx = i*n+j;
            printf("(%f, %f)\n", creal(vr[idx]), cimag(vr[idx]));
        }

    }

    return 0;
}

/*
successful exit!

0th Eigenvalue : (-6.000425, -6.999843)

0th Eigenvector :
(0.845722, 0.000000)
(-0.017723, 0.303607)
(0.087521, 0.311453)
(-0.056147, -0.290598)
1th Eigenvalue : (-5.000033, 2.006027)

1th Eigenvector :
(-0.386549, 0.173235)
(-0.353929, 0.452881)
(0.612370, 0.000000)
(-0.085928, -0.328363)
2th Eigenvalue : (7.998195, -0.996365)

2th Eigenvector :
(-0.172974, 0.266896)
(0.692423, 0.000000)
(0.332402, 0.495980)
(0.250388, -0.014655)
3th Eigenvalue : (3.002264, -3.999819)

3th Eigenvector :
(-0.035614, -0.178218)
(0.126374, 0.266632)
(0.012933, -0.296568)
(0.889824, 0.000000)
*/