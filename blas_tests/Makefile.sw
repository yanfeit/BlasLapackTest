CC=sw9gcc
FC=sw9gfortran
CFLAGS=-g -Wall -I../ -mhost
FFLAGS=-mhybrid
LDFLAGS=/home/export/online1/apps/xMath-SACA/latest/libswblas.a /home/export/online1/apps/xMath-SACA/latest/libswlapack.a
LD=-lgfortran -lm_slave
#LDFLAGS=-L/home/export/online1/apps/xMath-SACA/latest/
#LD=-lgfortran -lm_slave -lswblas -lswlapack

SUBMIT=bsub -I -b -N 1 -q q_4 -cgsp 64 -cache_size 0

# compiler sw7gcc -mhost -o test.o test.c
# link sw7gfortran -mhybrid -o test test.o -L/path/to/xMath -lxMath
# you can use Fortran or GCC compiler to do hybrid link

# BLAS FUNCTIONS
# Level 1 BLAS
# sdot:
# 	$(CC) $(CFLAGS) -c test_sdot.c -o test_sdot.o
# 	$(FC) $(FFLAGS) test_sdot.o -o test_sdot $(LDFLAGS)  $(LD)
# 	bsub -I -b -N 1 -q q_4 -cgsp 64 -cache_size 0 ./test_sdot

objects := $(patsubst %.c, %.o, $(wildcard *.c))
targets := $(patsubst %.c, %, $(wildcard *.c))

all : $(targets)

$(targets): % : %.o 
	$(FC) $(FFLAGS) $< -o $@ $(LDFLAGS)  $(LD)
#$(SUBMIT) ./$@

$(objects): %.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

run_tests:
	-$(SUBMIT) ./test_caxpy
	$(SUBMIT) ./test_cdotc
	$(SUBMIT) ./test_cgemv
	$(SUBMIT) ./test_dgemm
	$(SUBMIT) ./test_dgemv
	$(SUBMIT) ./test_dtrsv
	$(SUBMIT) ./test_saxpy
	$(SUBMIT) ./test_sdot
	$(SUBMIT) ./test_zgemm
	$(SUBMIT) ./test_zgemv
	$(SUBMIT) ./test_ztrsv


clean:
	rm -f $(objects) $(targets)