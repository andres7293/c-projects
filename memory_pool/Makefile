CC=gcc
CFLAGS=-g -Wall

test.out:	test.c memory_pool.o
	${CC} ${CFLAGS} test.c memory_pool.o -o test.out

memory_pool.o:	memory_pool.c
	${CC} ${CFLAGS} -c memory_pool.c -o memory_pool.o

clean:
	rm -f *.o *.out