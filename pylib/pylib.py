import sys
sys.path.append("/home/zyxu/_projects_/PyBLAS/pylib")
from utils import *
from data import *


def dasum_(m, a, inca, h1=None):
    output = array([0], dtype=double)
    for i in range(m):
        output[0] += abs(a[DIM(i, 0, inca)])
    return output

def test_dasum_(m, n, lda, ldb, ldc, inca, incb, incc, A, B, C, a, b, c):
    output = dasum_(m, a, inca, 1)
    To_file(1, 1, output, 1, data_prefix + "output/dasum")
    return output


def daxpy_(m, alpha, a, inca, b, incb, h1):
    for i in range(m):
        b[DIM(i, 0, incb)] += alpha * a[DIM(i, 0, inca)]

def test_daxpy(m, n, lda, ldb, ldc, inca, incb, incc, A, B, C, a, b, c):
    daxpy_(m, alpha, a, inca, b, incb, 1)
    To_file(m, 1, b, 1, data_prefix + "output/daxpy")
    return b