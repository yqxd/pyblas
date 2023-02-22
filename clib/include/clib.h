#ifndef CLIB_H
#define CLIB_H

#ifdef __cplusplus
extern "C"{
#endif

// double
extern double dasum_(int *, double [], int *, int); 

// test
void test_dasum_(int m, int n, int lda, int ldb, int ldc, int inca, int incb, int incc,
                double* A, double* B, double *C, double *a, double *b, double *c);

#ifdef __cplusplus
}
#endif


#endif