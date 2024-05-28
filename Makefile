CC=gcc
CFLAGS=-g -Wall
LDFLAGS=-L /opt/lapack/lib/
LD=-llapack -lblas -lm -lgfortran

# BLAS FUNCTIONS
sdot:
	$(CC) $(CFLAGS) $(LDFLAGS) -c test_sdot.c -o test_sdot.o
	$(CC) $(CFLAGS) $(LDFLAGS) test_sdot.o -o test_sdot $(LD)

cdotc:
	$(CC) $(CFLAGS) $(LDFLAGS) -c test_cdotc.c -o test_cdotc.o
	$(CC) $(CFLAGS) $(LDFLAGS) test_cdotc.o -o test_cdotc $(LD)

saxpy:
	$(CC) $(CFLAGS) $(LDFLAGS) -c test_saxpy.c -o test_saxpy.o
	$(CC) $(CFLAGS) $(LDFLAGS) test_saxpy.o -o test_saxpy $(LD)


# LAPACK FUNCTIONS
sgesv:
	$(CC) $(CFLAGS) $(LDFLAGS) -c test_sgesv.c -o test_sgesv.o
	$(CC) $(CFLAGS) $(LDFLAGS) test_sgesv.o -o test_sgesv $(LD)

zgeev:
	$(CC) $(CFLAGS) $(LDFLAGS) -c test_zgeev.c -o test_zgeev.o
	$(CC) $(CFLAGS) $(LDFLAGS) test_zgeev.o -o test_zgeev $(LD)

clean:
	rm -f *.o
	rm -f test_sgesv
	rm -f test_zgeev
	rm -f test_sdot
	rm -f test_saxpy