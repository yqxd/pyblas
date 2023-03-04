#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "clib.h"
#include "tools.h"
#include "test_correctness.h"


int main(int argc, char *argv[])
{
    int m = 100, n = 100;
    double *A = (double*) malloc(m*n*sizeof(double));
    double *B = (double*) malloc(m*n*sizeof(double));
    double *C = (double*) malloc(m*n*sizeof(double));
    double *a = (double*) malloc(m*sizeof(double));
    double *b = (double*) malloc(m*sizeof(double));
    double *c = (double*) malloc(m*sizeof(double));

    int lda = m, ldb = m, ldc = m, inca = 1, incb = 1, incc = 1;
    From_file(m, n, A, lda, ".././data/A");
    From_file(m, n, B, ldb, ".././data/B");
    From_file(m, n, C, ldc, ".././data/C");
    From_file(m, 1, a, inca, ".././data/a");
    From_file(m, 1, b, incb, ".././data/b");
    From_file(m, 1, c, incc, ".././data/c");

    // blas 1
    if (strcmp(argv[1], "daxpy") == 0)
        test_daxpy_(m, n, lda, ldb, ldc, inca, incb, incc, A, B, C, a, b, c);
    else if (strcmp(argv[1], "dnrm2") == 0)
        test_dnrm2_(m, n, lda, ldb, ldc, inca, incb, incc, A, B, C, a, b, c);
    else if (strcmp(argv[1], "dasum") == 0)
        test_dasum_(m, n, lda, ldb, ldc, inca, incb, incc, A, B, C, a, b, c);
    else if (strcmp(argv[1], "idamax") == 0)
        test_idamax_(m, n, lda, ldb, ldc, inca, incb, incc, A, B, C, a, b, c);

    // blas 2
    if (strcmp(argv[1], "dlange") == 0)
        test_dlange_(m, n, lda, ldb, ldc, inca, incb, incc, A, B, C, a, b, c);

    // blas 3
    if (strcmp(argv[1], "dtrsm") == 0)
        test_dtrsm_(m, n, lda, ldb, ldc, inca, incb, incc, A, B, C, a, b, c);
    else if (strcmp(argv[1], "dgetrf") == 0)
        test_dgetrf_(m, n, lda, ldb, ldc, inca, incb, incc, A, B, C, a, b, c);

    return 0;
}