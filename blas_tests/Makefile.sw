CC=sw9gcc
FC=sw9gfortran
CFLAGS=-g -Wall -I../ -mhost
FFLAGS=-mhybrid
LDFLAGS=/home/export/online1/apps/xMath-SACA/latest/libswlapack.a /home/export/online1/apps/xMath-SACA/latest/libswblas.a
LD=-lgfortran -lm_slave

# compiler sw7gcc -mhost -o test.o test.c
# link sw7gfortran -mhybrid -o test test.o -L/path/to/xMath -lxMath


# BLAS FUNCTIONS
# Level 1 BLAS
sdot:
	$(CC) $(CFLAGS) -c test_sdot.c -o test_sdot.o
	$(FC) $(FFLAGS) test_sdot.o -o test_sdot $(LDFLAGS)  $(LD)
	bsub -I -b -N 1 -q q_4 -cgsp 64 -cache_size 0 ./test_sdot
	
clean:
	rm -f *.o
	rm -f test_sdot