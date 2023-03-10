from numpy import *
from typing import *
import scipy
from scipy.linalg import lapack
from copy import deepcopy

data_prefix = "/home/zyxu/_projects_/PyBLAS/data/"


def DIM(x, y, lda=None):
    if lda is not None:
        return y * lda + x
    else:
        return x * y


def From_file(m, n, A, lda, matrix):
    with open(matrix, "r") as f:
        data = f.read().strip()
        data = data.split(" ")
    idx = 0
    for i in range(m):
        for j in range(n):
            A[DIM(i, j, lda)] = double(data[idx])
            idx += 1


def To_file(m, n, A, lda, matrix):
    with open(matrix, "w+") as f:
        for i in range(m):
            for j in range(n):
                f.write("%10.8E" % A[DIM(i, j, lda)])
                if i != m - 1 or j != n - 1:
                    f.write(" ")
