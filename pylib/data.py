from utils import *

m = 100
n = 100

lda = m
ldb = m
ldc = m

inca = 1
incb = 1
incc = 1

A = zeros(m*n)
B = zeros(m*n)
C = zeros(m*n)
a = zeros(m)
b = zeros(m)
c = zeros(m)

From_file(m, n, A, lda, data_prefix + "A")
From_file(m, n, B, ldb, data_prefix + "B")
From_file(m, n, C, ldc, data_prefix + "C")
From_file(m, 1, a, inca, data_prefix + "a")
From_file(m, 1, b, incb, data_prefix + "b")
From_file(m, 1, c, incc, data_prefix + "c")