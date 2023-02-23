#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"
#include "clib.h"

double alpha = 1.5;
double beta = 2.5;
double gamma = 3.5;

void test_dasum_(int m, int n, int lda, int ldb, int ldc, int inca, int incb, int incc,
                double* A, double* B, double *C, double *a, double *b, double *c)
{
    double* output = (double*)malloc(1*sizeof(double));
    double* output_ = (double*)malloc(1*sizeof(double));
    *output = dasum_(&m, a, &inca, 1);
    From_file(1, 1, output_, 1, "../data/output/dasum");
    printf("Output: %E; Error of dasum_: %E\n", *output, *output_ - *output);
}

void test_daxpy_(int m, int n, int lda, int ldb, int ldc, int inca, int incb, int incc,
                double* A, double* B, double *C, double *a, double *b, double *c)
{
    double* output = (double*)malloc(m*sizeof(double));
    double* output_ = (double*)malloc(m*sizeof(double));
    *output = daxpy_(&m, a, &inca, 1);
    From_file(1, 1, output_, 1, "../data/output/dasum");
    printf("Output: %E; Error of daxpy_: %E\n", *output, *output_ - *output);
}