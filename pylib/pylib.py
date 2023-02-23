import sys
sys.path.append("/home/zyxu/_projects_/PyBLAS/pylib")
from utils import *

def test_dasum_(m, n, lda, ldb, ldc, inca, incb, incc, A, B, C, a, b, c):
    output = array([0], dtype=double)
    for i in range(m):
        output[0] += a[DIM(i, 0, inca)]
    To_file(1, 1, output, 1, data_prefix + "output/dasum")
    return output

def test_daxpy(m, n, lda, ldb, ldc, inca, incb, incc, A, B, C, a, b, c):
    for i in range(m):
        b[i] += alpha * a[i]
    To_file(m, 1, b, 1, data_prefix + "output/daxpy")
    return b