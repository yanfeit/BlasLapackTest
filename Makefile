CC=gcc
CFLAGS=-g -Wall
LDFLAGS=-L /opt/lapack/lib/ -llapack -lblas -lm

sgesv:
	$(CC) $(CFLAGS) $(LDFLAGS) -c test_sgesv.c -o test_sgesv.o
	$(CC) $(CFLAGS) $(LDFLAGS) test_sgesv.o -o test_sgesv