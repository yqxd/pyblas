#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"
#include "clib.h"


double ONE = 1;
double ZERO = 1;
double NEG_ONE = -1;

char M = 'M';
char F = 'F';
char O = 'O';
char I = 'I';
char* SIDE = "R";
char* UPLO = "U";
char* TRANSA = "N";
char* DIAG = "N";

double alpha = 1.5;
double beta = 2.5;

double work[100000];
int ipiv[10000];
int info;


// level 1 blas
void test_daxpy_(int m, int n, int lda, int ldb, int ldc, int inca, int incb, int incc,
                double* A, double* B, double *C, double *a, double *b, double *c)
{
    double* b_ = (double*)malloc(m*sizeof(double));
    From_file(m, 1, b_, 1, "../data/output/daxpy");

    daxpy_(&m, &alpha, a, &inca, b, &incb, 1);

    daxpy_(&m, &NEG_ONE, b, &inca, b_, &inca, 1);
    double* output = (double*)malloc(1*sizeof(double));
    *output = dasum_(&m, b_, &inca, 1);

    printf("Error of test_daxpy_: %E\n", *output);
}

void test_dnrm2_(int m, int n, int lda, int ldb, int ldc, int inca, int incb, int incc,
                double* A, double* B, double *C, double *a, double *b, double *c)
{
    double* output_ = (double*)malloc(1*sizeof(double));
    From_file(1, 1, output_, 1, "../data/output/dnrm2");

    double* output = (double*)malloc(1*sizeof(double));
    *output = dnrm2_(&m, a, &inca, 1);
    printf("Output: %E; Error of dnrm2_: %E\n", *output, *output_ - *output);
}


void test_dasum_(int m, int n, int lda, int ldb, int ldc, int inca, int incb, int incc,
                double* A, double* B, double *C, double *a, double *b, double *c)
{
    double* output_ = (double*)malloc(1*sizeof(double));
    From_file(1, 1, output_, 1, "../data/output/dasum");

    double* output = (double*)malloc(1*sizeof(double));
    *output = dasum_(&m, a, &inca, 1);
    printf("Output: %E; Error of dasum_: %E\n", *output, *output_ - *output);
}

void test_idamax_(int m, int n, int lda, int ldb, int ldc, int inca, int incb, int incc,
                double* A, double* B, double *C, double *a, double *b, double *c)
{
    double* output_ = (double*)malloc(1*sizeof(double));
    From_file(1, 1, output_, 1, "../data/output/idamax");
    int *output_int = (int*)malloc(1*sizeof(int));
    *output_int = *output_ + 0.5;

    int* output = (int*)malloc(1*sizeof(int));
    *output = idamax_(&m, a, &inca, 1);
    printf("Output: %d; Error of dasum_: %d\n", *output, *output - *output_int);
}

// level 2 blas
void test_dlange_(int m, int n, int lda, int ldb, int ldc, int inca, int incb, int incc,
                double* A, double* B, double *C, double *a, double *b, double *c)
{
    double* output_ = (double*)malloc(1*sizeof(double));
    From_file(1, 1, output_, 1, "../data/output/dlange");

    double* output = (double*)malloc(1*sizeof(double));
    *output = dlange_(&F, &m, &n, A, &lda, work, 1);
    printf("Output: %E; Error of dlange_: %E\n", *output, *output - *output_);
}

// level 3 blas
void test_dtrsm_(int m, int n, int lda, int ldb, int ldc, int inca, int incb, int incc,
                double* A, double* B, double *C, double *a, double *b, double *c)
{
    double* output_B = (double*)malloc(m*n*sizeof(double));
    From_file(m, n, output_B, ldb, "../data/output/dtrsm");
    dtrsm_(SIDE, UPLO, TRANSA, DIAG, &m, &n, &alpha, A, &lda, B, &ldb, 1, 1, 1, 1);
    Matrix_add(m, n, -1, output_B, B, lda, ldb);

    double* error = (double*)malloc(1*sizeof(double));
    *error = dlange_(&F, &m, &n, B, &ldb, work, 1);

    printf("\n%E\n", *error);
}

void test_dgetrf_(int m, int n, int lda, int ldb, int ldc, int inca, int incb, int incc,
                double* A, double* B, double *C, double *a, double *b, double *c)
{
    double* output_A = (double*)malloc(m*n*sizeof(double));
    From_file(m, n, output_A, lda, "../data/output/dgetrf_A");
    int* output_ipiv = (int*)malloc(min(m,n)*sizeof(int));

    dgetrf_(&m, &n, A, &lda, ipiv, &info, 1);
    Matrix_add(m, n, -1, output_A, A, lda, ldb);

    printf("\nasd %d asd \n", ipiv[0]);

    double* error = (double*)malloc(1*sizeof(double));
    *error = dlange_(&F, &m, &n, A, &lda, work, 1);
    printf("\n%E\n", *error);
}