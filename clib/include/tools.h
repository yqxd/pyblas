#ifndef TOOLS_H
#define TOOLS_H

int DIM_M(int x, int y, int lda);
int DIM_V(int x, int lda);
int DIM_N(int x);

// multi-argument DIM overload by DIM_N, DIM_V, DIM_M
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define DIM(...) GET_MACRO(__VA_ARGS__, DIM_M, DIM_V, DIM_N)(__VA_ARGS__)

// other function
void Init_rand(int m, int n, double *A, int ldA);
void From_file(int m, int n, double *A, int ldA, char *matrix);


#endif