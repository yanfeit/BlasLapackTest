CC=gcc
CFLAGS=-g -Wall -I ../
LDFLAGS=-L /opt/lapack/lib/
LD=-llapack -lblas -lm -lgfortran

# BLAS FUNCTIONS
# Level 1 BLAS
sdot:
	$(CC) $(CFLAGS) $(LDFLAGS) -c test_sdot.c -o test_sdot.o
	$(CC) $(CFLAGS) $(LDFLAGS) test_sdot.o -o test_sdot $(LD)
	./test_sdot

cdotc:
	$(CC) $(CFLAGS) $(LDFLAGS) -c test_cdotc.c -o test_cdotc.o
	$(CC) $(CFLAGS) $(LDFLAGS) test_cdotc.o -o test_cdotc $(LD)
	./test_cdotc

saxpy:
	$(CC) $(CFLAGS) $(LDFLAGS) -c test_saxpy.c -o test_saxpy.o
	$(CC) $(CFLAGS) $(LDFLAGS) test_saxpy.o -o test_saxpy $(LD)
	./test_saxpy

caxpy:
	$(CC) $(CFLAGS) $(LDFLAGS) -c test_caxpy.c -o test_caxpy.o
	$(CC) $(CFLAGS) $(LDFLAGS) test_caxpy.o -o test_caxpy $(LD)
	./test_caxpy

# LEVEL 2 BLAS
dgemv:
	$(CC) $(CFLAGS) $(LDFLAGS) -c test_dgemv.c -o test_dgemv.o
	$(CC) $(CFLAGS) $(LDFLAGS) test_dgemv.o -o test_dgemv $(LD)
	./test_dgemv

cgemv:
	$(CC) $(CFLAGS) $(LDFLAGS) -c test_cgemv.c -o test_cgemv.o
	$(CC) $(CFLAGS) $(LDFLAGS) test_cgemv.o -o test_cgemv $(LD)
	./test_cgemv

zgemv:
	$(CC) $(CFLAGS) $(LDFLAGS) -c test_zgemv.c -o test_zgemv.o
	$(CC) $(CFLAGS) $(LDFLAGS) test_zgemv.o -o test_zgemv $(LD)
	./test_zgemv

dtrsv:
	$(CC) $(CFLAGS) $(LDFLAGS) -c test_dtrsv.c -o test_dtrsv.o
	$(CC) $(CFLAGS) $(LDFLAGS) test_dtrsv.o -o test_dtrsv $(LD)
	./test_dtrsv

ztrsv:
	$(CC) $(CFLAGS) $(LDFLAGS) -c test_ztrsv.c -o test_ztrsv.o
	$(CC) $(CFLAGS) $(LDFLAGS) test_ztrsv.o -o test_ztrsv $(LD)
	./test_ztrsv

# LEVEL 3 BLAS
dgemm:
	$(CC) $(CFLAGS) $(LDFLAGS) -c test_dgemm.c -o test_dgemm.o
	$(CC) $(CFLAGS) $(LDFLAGS) test_dgemm.o -o test_dgemm $(LD)
	./test_dgemm

zgemm:
	$(CC) $(CFLAGS) $(LDFLAGS) -c test_zgemm.c -o test_zgemm.o
	$(CC) $(CFLAGS) $(LDFLAGS) test_zgemm.o -o test_zgemm $(LD)
	./test_zgemm

# LAPACK FUNCTIONS
sgesv:
	$(CC) $(CFLAGS) $(LDFLAGS) -c test_sgesv.c -o test_sgesv.o
	$(CC) $(CFLAGS) $(LDFLAGS) test_sgesv.o -o test_sgesv $(LD)
	./test_sgesv

zgeev:
	$(CC) $(CFLAGS) $(LDFLAGS) -c test_zgeev.c -o test_zgeev.o
	$(CC) $(CFLAGS) $(LDFLAGS) test_zgeev.o -o test_zgeev $(LD)

clean:
	rm -f *.o
	rm -f test_sgesv
	rm -f test_zgeev
	rm -f test_sdot
	rm -f test_saxpy
	rm -f test_cdotc
	rm -f test_caxpy
	rm -f test_dgemv
	rm -f test_cgemv
	rm -f test_zgemv
	rm -f test_dtrsv
	rm -f test_ztrsv
	rm -f test_dgemm
	rm -f test_zgemm