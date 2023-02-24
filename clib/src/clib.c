#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"
#include "clib.h"


double ONE = 1;
double ZERO = 1;
double NEG_ONE = -1;

double alpha = 1.5;
double beta = 2.5;

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
    double* a_ = (double*)malloc(m*sizeof(double));
    daxpy_(&m, &alpha, a, &inca, b, &incb, 1);
    From_file(m, 1, a_, 1, "../data/output/daxpy");

    daxpy_(&m, &NEG_ONE, a, &inca, a_, &inca, 1);
    double* output = (double*)malloc(1*sizeof(double));
    *output = dasum_(&m, a_, &inca, 1);

    printf("Error of test_daxpy_: %E\n", *output);
}