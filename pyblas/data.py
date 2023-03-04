from utils import *

m = 100
n = 100

lda = m
ldb = m
ldc = m

inca = 1
incb = 1
incc = 1

A = zeros(m * n)
B = zeros(m * n)
C = zeros(m * n)
a = zeros(m)
b = zeros(m)
c = zeros(m)

From_file(m, n, A, lda, data_prefix + "A")
From_file(m, n, B, ldb, data_prefix + "B")
From_file(m, n, C, ldc, data_prefix + "C")
From_file(m, 1, a, inca, data_prefix + "a")
From_file(m, 1, b, incb, data_prefix + "b")
From_file(m, 1, c, incc, data_prefix + "c")

work = zeros(m + n)
ipiv = zeros(min(m, n), dtype=int)

SIDE = 'R'
UPLO = 'U'
TRANSA = 'N'
DIAG = 'N'

alpha = 1.5
beta = 2.5
gamma = 3.5

if __name__ == "__main__":
    random.seed(123)
    A = random.rand(m * n)
    B = random.rand(m * n)
    C = random.rand(m * n)
    a = random.rand(m * 1)
    b = random.rand(m * 1)
    c = random.rand(m * 1)
    To_file(m, n, A, lda, data_prefix + "A")
    To_file(m, n, B, ldb, data_prefix + "B")
    To_file(m, n, C, ldc, data_prefix + "C")
    To_file(m, 1, a, inca, data_prefix + "a")
    To_file(m, 1, b, incb, data_prefix + "b")
    To_file(m, 1, c, incc, data_prefix + "c")
