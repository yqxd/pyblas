#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "clib.h"
#include "tools.h"

// DIM
int DIM_M(int x, int y, int lda) {return y*lda + x;}
int DIM_V(int x, int lda) {return x*lda;}
int DIM_N(int x) {return x;}

// initialize random matrix A
void Init_rand(int m, int n, double *A, int ldA)
{
    int i, j;

    for (j = 0; j < n; j++)
    for (i = 0; i < m; i++)
        A[i + j*ldA] = ((double)rand()/RAND_MAX - 0.5)*2.0;
}

// initialize matrix A from files
void From_file(int m, int n, double *A, int ldA, char *matrix)
{
    int i, j;
    FILE* fpread;

    fpread = fopen(matrix, "r");
    
    if( fpread == NULL )
    {
        printf("can't read the file\n");
        exit(1);
    }  

    for (i = 0; i < m; i++)
    for (j = 0; j < n; j++)
    {
        fscanf(fpread, "%lf", &A[DIM(i, j, ldA)]);
    }
    
    fclose(fpread);
}

// initialize matrix A from files
void From_file_int(int m, int n, int *A, int ldA, char *matrix)
{
    int i, j;
    FILE* fpread;

    fpread = fopen(matrix, "r");

    if( fpread == NULL )
    {
        printf("can't read the file\n");
        exit(1);
    }

    for (i = 0; i < m; i++)
    for (j = 0; j < n; j++)
    {
        fscanf(fpread, "%d", &A[DIM(i, j, ldA)]);
    }

    fclose(fpread);
}


// matrix addition
void Matrix_add(int m, int n, double alpha, double* A, double* B, int lda, int ldb)
{
    int i, j;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            B[DIM(i, j, lda)] += alpha * A[DIM(i, j, ldb)];
}