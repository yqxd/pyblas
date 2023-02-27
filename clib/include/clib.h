#ifndef CLIB_H
#define CLIB_H

#ifdef __cplusplus
extern "C"{
#endif

//
// blas 1
extern void daxpy_(int *, double *, double [], int *, double [], int *, int);
extern double dnrm2_(int *, double [], int *, int);
extern double dasum_(int *, double [], int *, int);
extern int idamax_(int *, double [], int *, int);

// blas 2
extern double dlange_(char *, int *, int *, double [], int *, double [], int);

// blas 3
extern void dgetrf_(int *, int *, double [], int *, int [], int *, int);


//
// blas 1
void test_daxpy_(int m, int n, int lda, int ldb, int ldc, int inca, int incb, int incc,
                double* A, double* B, double *C, double *a, double *b, double *c);
void test_dnrm2_(int m, int n, int lda, int ldb, int ldc, int inca, int incb, int incc,
                double* A, double* B, double *C, double *a, double *b, double *c);
void test_dasum_(int m, int n, int lda, int ldb, int ldc, int inca, int incb, int incc,
                double* A, double* B, double *C, double *a, double *b, double *c);
void test_idamax_(int m, int n, int lda, int ldb, int ldc, int inca, int incb, int incc,
                double* A, double* B, double *C, double *a, double *b, double *c);

// blas 2
void test_dlange_(int m, int n, int lda, int ldb, int ldc, int inca, int incb, int incc,
                double* A, double* B, double *C, double *a, double *b, double *c);

// blas 3
void test_dgetrf_(int m, int n, int lda, int ldb, int ldc, int inca, int incb, int incc,
                double* A, double* B, double *C, double *a, double *b, double *c);


#ifdef __cplusplus
}
#endif


#endif