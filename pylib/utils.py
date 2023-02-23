from numpy import *
data_prefix = "/home/zyxu/_projects_/PyBLAS/data/"

DIM = lambda x, y, lda: y*lda + x

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
                if i != m-1 or j != n-1:
                    f.write(" ")



alpha = 1.5
beta = 2.5
gamma = 3.5