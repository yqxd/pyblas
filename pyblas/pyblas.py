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
# triangular solve multiple rhs, TX = αB
def dtrsm_(SIDE, UPLO, TRANSA, DIAG, m, n, alpha, A, lda, B, ldb, h1=1, h2=1, h3=1, h4=1):
    if SIDE == 'L':
        new_A = zeros((m, m))
    elif SIDE == 'R':
        new_A = zeros((n, n))
    else:
        raise Exception()
    if UPLO == 'U':
        for i in range(new_A.shape[0]):
            for j in range(i, new_A.shape[1]):
                new_A[i, j] = A[DIM(i, j, lda)]
    elif UPLO == 'L':
        for i in range(new_A.shape[0]):
            for j in range(new_A.shape[1], i + 1):
                new_A[i, j] = A[DIM(i, j, lda)]
    else:
        raise Exception()
    if DIAG == 'U':
        for i in range(new_A.shape[0]):
            new_A[i, i] = 1
    elif DIAG != 'N':
        raise Exception
    new_B = zeros((m, n))
    for i in range(m):
        for j in range(n):
            new_B[i, j] = B[DIM(i, j, ldb)]
    if TRANSA == 'C' or TRANSA == 'T':
        new_A = new_A.T
    elif TRANSA != 'N':
        raise Exception()
    if SIDE == 'L':
        X = alpha * linalg.solve(new_A, new_B)
    elif SIDE == 'R':
        X = alpha * linalg.solve(new_A.T, new_B.T).T
    else:
        raise Exception()
    for i in range(m):
        for j in range(n):
            B[DIM(i, j, ldb)] = X[i, j]


def test_dtrsm_(m, n, lda, ldb, ldc, inca, incb, incc, A, B, C, a, b, c):
    dtrsm_(SIDE, UPLO, TRANSA, DIAG, m, n, alpha, A, lda, B, ldb)
    To_file(m, n, B, ldb, data_prefix + "output/dtrsm")


# LU factorization
def dgetrf_(m, n, A, lda, ipiv, info, h1=None):
    new_A = zeros((m, n))
    for i in range(m):
        for j in range(n):
            new_A[i, j] = A[DIM(i, j, lda)]
    output_A, output_ipiv, info = lapack.dgetrf(new_A)
    for i in range(m):
        for j in range(n):
            A[DIM(i, j, lda)] = output_A[i, j]
    for i in range(min(m, n)):
        ipiv[i] = output_ipiv[i]
    ipiv += 1


def test_dgetrf_(m, n, lda, ldb, ldc, inca, incb, incc, A, B, C, a, b, c):
    dgetrf_(m, n, A, lda, ipiv, info, h1=None)
    To_file(min(m, n), 1, ipiv, 1, data_prefix + "output/dgetrf_ipiv")
    To_file(m, n, A, lda, data_prefix + "output/dgetrf_A")

