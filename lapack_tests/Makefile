CC=gcc
CFLAGS=-g -Wall -I ../
LDFLAGS=-L /opt/lapack/lib/
LD=-llapack -lblas -lm -lgfortran

# LAPACK FUNCTIONS
sgesv:
	$(CC) $(CFLAGS) $(LDFLAGS) -c test_sgesv.c -o test_sgesv.o
	$(CC) $(CFLAGS) $(LDFLAGS) test_sgesv.o -o test_sgesv $(LD)
	./test_sgesv

zgesv:
	$(CC) $(CFLAGS) $(LDFLAGS) -c test_zgesv.c -o test_zgesv.o
	$(CC) $(CFLAGS) $(LDFLAGS) test_zgesv.o -o test_zgesv $(LD)
	./test_zgesv

dgeev:
	$(CC) $(CFLAGS) $(LDFLAGS) -c test_dgeev.c -o test_dgeev.o
	$(CC) $(CFLAGS) $(LDFLAGS) test_dgeev.o -o test_dgeev $(LD)
	./test_dgeev

zgeev:
	$(CC) $(CFLAGS) $(LDFLAGS) -c test_zgeev.c -o test_zgeev.o
	$(CC) $(CFLAGS) $(LDFLAGS) test_zgeev.o -o test_zgeev $(LD)
	./test_zgeev

dgetrf:
	$(CC) $(CFLAGS) $(LDFLAGS) -c test_dgetrf.c -o test_dgetrf.o
	$(CC) $(CFLAGS) $(LDFLAGS) test_dgetrf.o -o test_dgetrf $(LD)
	./test_dgetrf

dgetri:
	$(CC) $(CFLAGS) $(LDFLAGS) -c test_dgetri.c -o test_dgetri.o
	$(CC) $(CFLAGS) $(LDFLAGS) test_dgetri.o -o test_dgetri $(LD)
	./test_dgetri


zgetrf:
	$(CC) $(CFLAGS) $(LDFLAGS) -c test_zgetrf.c -o test_zgetrf.o
	$(CC) $(CFLAGS) $(LDFLAGS) test_zgetrf.o -o test_zgetrf $(LD)
	./test_zgetrf


zgetri:
	$(CC) $(CFLAGS) $(LDFLAGS) -c test_zgetri.c -o test_zgetri.o
	$(CC) $(CFLAGS) $(LDFLAGS) test_zgetri.o -o test_zgetri $(LD)
	./test_zgetri


clean:
	rm -f *.o
	rm -f test_sgesv
	rm -f test_zgesv
	rm -f test_dgeev
	rm -f test_zgeev
	rm -f test_dgetrf
	rm -f test_dgetri
	rm -f test_zgetrf
	rm -f test_zgetri

