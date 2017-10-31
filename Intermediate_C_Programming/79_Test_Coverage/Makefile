# Makefile for gcov

CC = gcc

CFLAGS = -g -Wall -fprofile-arcs -ftest-coverage

cov:	coverage.c
	$(CC) $(CFLAGS) coverage.c -o cov
	./cov
	gcov coverage.c
	grep "#" coverage.c.gcov

clean:
	rm -f *.gcov *.gcno *.gcda cov
