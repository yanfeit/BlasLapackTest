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

zgeev:
	$(CC) $(CFLAGS) $(LDFLAGS) -c test_zgeev.c -o test_zgeev.o
	$(CC) $(CFLAGS) $(LDFLAGS) test_zgeev.o -o test_zgeev $(LD)

clean:
	rm -f *.o
	rm -f test_sgesv
	rm -f test_zgesv
	rm -f test_zgeev