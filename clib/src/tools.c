#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "clib.h"
#include "tools.h"

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
