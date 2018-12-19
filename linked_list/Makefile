CC=gcc
CFLAGS=-g -Wall

test.out: test.o linked_list.o
	${CC} ${CFLAGS} test.o linked_list.o -o test.out

test.o:	test.c
	${CC} ${CFLAGS} -c test.c -o test.o

linked_list.o:	linked_list.c
	${CC} ${CFLAGS} -c linked_list.c -o linked_list.o

clean:
	rm -f *.o *.out
