CC=gcc
CFLAGS=-Wall -g

SRC += \
	test.c \
	memory_pool.c \

OBJECTS=$(SRC:.c=.o)

test.out : $(OBJECTS)
	$(CC) $(CFLAGS) -o test.out $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm *.out *.o