#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <float.h>
#include <math.h>
#include "funs.h"


// Hypothetical declaration for a gemv function (not real)
// https://numericalalgorithmsgroup.github.io/LAPACK_Examples/examples/doc/dgeev_example.html
// DGEEV computes the eigenvalues and, optionally, the left and/or right eigenvectors for GE matrices


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
    double A[16] = {0.35, 0.09, -0.44, 0.25,
                    0.45, 0.07, -0.33, -0.32,
                    -0.14, -0.54, -0.03, -0.13,
                    -0.17, 0.35, 0.17, 0.11};  // on exit, A has been overwritten!
    int lda = 4;
    double wr[4];
    double wi[4]; // wr and wi are the real and imaginary part of the eigenvalues

    double vl[4*4];  // left eigenvector , if jobvl='N' then not referenced.
    int ldvl = 4;    // leading dimension of the array vl

    double vr[4*4]; // right eigenvector, 
    int ldvr = 4;   // leading dimension of the array vr

    double work[16];
    int lwork = 16;

    int info;

    dgeev_(&jobvl, &jobvr, &n, A, &lda, wr, wi, vl, &ldvl, vr, &ldvr, work, &lwork, &info);

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
        if (fabs(wi[i]) > DBL_MIN)
        {
            printf("%dth Eigenvalue : (%f, %f)\n", i, wr[i], wi[i]);
            printf("%dth Eigenvector : \n", i);
            for (int j = 0; j < n; j++)
            {
                printf("(%f, %f)\n", vr[i*n + j], vr[(i+1)*n + j]);
            }

            printf("%dth Eigenvalue : (%f, %f)\n", i+1, wr[i+1], wi[i+1]);
            printf("%dth Eigenvector : \n", i+1);
            for (int j = 0; j < n; j++)
            {
                printf("(%f, %f)\n", vr[i*n + j], -vr[(i+1)*n + j]);
            }    
            i++;        
        }
        else
        {
            printf("%dth Eigenvalue : (%f, %f)\n", i, wr[i], wi[i]);
            printf("%dth Eigenvector : \n", i);
            for (int j = 0; j < n; j++)
            {
                printf("%f\n", vr[i*n + j]);
            }
        }

    }


    return 0;
}

/*
successful exit!

0th Eigenvalue : (0.799482, 0.000000)
0th Eigenvector :
-0.655089
-0.523629
0.536218
-0.095607
1th Eigenvalue : (-0.099412, 0.400792)
1th Eigenvector :
(-0.193302, 0.254632)
(0.251857, -0.522405)
(0.097182, -0.308384)
(0.675954, 0.000000)
2th Eigenvalue : (-0.099412, -0.400792)
2th Eigenvector :
(-0.193302, -0.254632)
(0.251857, 0.522405)
(0.097182, 0.308384)
(0.675954, -0.000000)
3th Eigenvalue : (-0.100657, 0.000000)
3th Eigenvector :
0.125333
0.332022
0.593838
0.722087
*/