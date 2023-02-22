TOPDIR     = /home/zyxu/_projects_/PyBLAS/clib
BLASLIB    = /opt/OpenBLAS/0.3.19/lib64/libopenblas.so
SHAREDLIB  = -Wl,-rpath=/opt/OpenBLAS/0.3.19/lib64/

LIBS      = $(LAPACKLIB) $(BLASLIB) -lgfortran -lm

INC        = -I $(TOPDIR)/include

CC        = gcc
CFLAGS    = $(DEFS) -fopenmp -O3 $(INC)
RANLIB     = ranlib

LOADER    = $(CC)
LDFLAGS   = -fopenmp -O3

RM        = rm -f
