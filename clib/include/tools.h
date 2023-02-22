#ifndef TOOLS_H
#define TOOLS_H

int DIM_M(int x, int y, int lda) {return y*lda + x;}
int DIM_V(int x, int lda) {return x*lda;}

#define DIM(...) OVERLOAD(DIM, (__VA_ARGS__), \
    (DIM_M, (int, int, int)), \
    (DIM_V, (int, int)) \
)


void Init_rand(int m, int n, double *A, int ldA);
void From_file(int m, int n, double *A, int ldA, char *matrix);


#endif