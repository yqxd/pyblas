import sys

sys.path.append("/home/zyxu/_projects_/PyBLAS/pyblas")
from utils import *
from data import *


# level 1 lapack

# add vectors, y = αx + y
def daxpy_(m, alpha, a, inca, b, incb, h1):
    for i in range(m):
        b[DIM(i, incb)] += alpha * a[DIM(i, inca)]


def test_daxpy(m, n, lda, ldb, ldc, inca, incb, incc, A, B, C, a, b, c):
    daxpy_(m, alpha, a, inca, b, incb, 1)
    To_file(m, 1, b, 1, data_prefix + "output/daxpy")
    # return b


# vector 2-norm, ||x||2
def dnrm2_(m, a, inca, h1=None):
    output = array([0], dtype=double)
    for i in range(m):
        output[0] += abs(a[DIM(i, inca)]) ** 2
    output[0] = sqrt(output[0])
    return output


def test_dnrm2_(m, n, lda, ldb, ldc, inca, incb, incc, A, B, C, a, b, c):
    output = dnrm2_(m, a, inca, 1)
    To_file(1, 1, output, 1, data_prefix + "output/dnrm2")


# vector 1-norm (pseudo), || Re(x) ||1 + || Im(x) ||1
def dasum_(m, a, inca, h1=None):
    output = array([0], dtype=double)
    for i in range(m):
        output[0] += abs(real(a[DIM(i, inca)])) + abs(imag(a[DIM(i, inca)]))
    return output


def test_dasum_(m, n, lda, ldb, ldc, inca, incb, incc, A, B, C, a, b, c):
    output = dasum_(m, a, inca, 1)
    To_file(1, 1, output, 1, data_prefix + "output/dasum")


# vector inf-norm (pseudo), index with max abs value, argmaxi | Re(xi) | + | Im(xi) |
def idamax_(m, a, inca, h1=None):
    max_val = float("-inf")
    ida = -1
    for i in range(m):
        crt_val = abs(real(a[DIM(i, inca)])) + abs(real(a[DIM(i, inca)]))
        if max_val < crt_val:
            max_val = crt_val
            ida = i
    return array([ida + 1], dtype=int)


def test_idamax_(m, n, lda, ldb, ldc, inca, incb, incc, A, B, C, a, b, c):
    output = idamax_(m, a, inca, 1)
    To_file(1, 1, output, 1, data_prefix + "output/idamax")


# level 2 lapack
# one-norm, inf-norm, Frobenius norm, or max absolute element
def dlange_(norm, m, n, A, lda, work, h1=None):
    output = array([0], dtype=double)
    if norm == 'F':
        for i in range(m):
            work[DIM(i, 1)] = 0
            for j in range(n):
                work[DIM(i, 1)] += A[DIM(i, j, lda)] ** 2
        for i in range(m):
            output[0] += work[DIM(i, 1)]
        output[0] = sqrt(output[0])
    return output


def test_dlange_(m, n, lda, ldb, ldc, inca, incb, incc, A, B, C, a, b, c):
    output = dlange_('F', m, n, A, lda, work, 1)
    To_file(1, 1, output, 1, data_prefix + "output/dlange")


# level 3 lapack
# LU factorization
def dgetrf_(m, n, A, lda, ipiv, info, h1=None):
    # A = deepcopy(A_ori)
    for i in range(min(m, n)):
        ipiv[i] = idamax_(m - i, A[DIM(i, i, lda):], 1) + i - 1
        for j in range(n):
            tmp = A[DIM(i, j, lda)]
            A[DIM(i, j, lda)] = A[DIM(ipiv[i], j, lda)]
            A[DIM(ipiv[i], j, lda)] = tmp
        for j in range(i + 1, n):
            A[DIM(j, i, lda)] /= A[DIM(i, i, lda)]
            for k in range(i + 1, n):
                A[DIM(j, k, lda)] -= A[DIM(j, i, lda)] * A[DIM(i, k, lda)]
        ipiv[i] += 1


def test_dgetrf_(m, n, lda, ldb, ldc, inca, incb, incc, A, B, C, a, b, c):
    dgetrf_(m, n, A, lda, ipiv, info, h1=None)
    To_file(min(m, n), 1, ipiv, 1, data_prefix + "output/dgetrf_ipiv")
    To_file(m, n, A, lda, data_prefix + "output/dgetrf_A")
