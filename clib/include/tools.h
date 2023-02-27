#ifndef TOOLS_H
#define TOOLS_H

//
int DIM_M(int x, int y, int lda);
int DIM_V(int x, int lda);
int DIM_N(int x);

// multi-argument
// DIM overloaded by DIM_N, DIM_V, DIM_M
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define DIM(...) GET_MACRO(__VA_ARGS__, DIM_M, DIM_V, DIM_N)(__VA_ARGS__)

// min and max overload by other
#define __START(op, A, B, C, D, N, ...) __ARGS_##N(op, A, B, C, D)
#define __ARGS_1(op, A, B, C, D) A
#define __ARGS_2(op, A, B, C, D) __##op(A, B)
#define __ARGS_3(op, A, B, C, D) __##op(A, __##op(B, C))
#define __ARGS_4(op, A, B, C, D) __##op(__##op(A, B), __##op(C, D))

#define __MIN(A, B) ((A) < (B) ? (A) : (B))
#define __MAX(A, B) ((A) > (B) ? (A) : (B))

#define min(...) __START(MIN, __VA_ARGS__, 4, 3, 2, 1)
#define max(...) __START(MAX, __VA_ARGS__, 4, 3, 2, 1)


// other function
void Init_rand(int m, int n, double *A, int ldA);
void From_file(int m, int n, double *A, int ldA, char *matrix);
void Matrix_add(int m, int n, double alpha, double* A, double* B, int lda, int ldb);
void From_file_int(int m, int n, int *A, int ldA, char *matrix);

#endif