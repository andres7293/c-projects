CC=gcc
TARGET=fifo_test.out

SRC += \
	fifo_test.c \
	fifo.c \

fifo_test: fifo_test.o fifo.o
	gcc -o $(TARGET) fifo_test.o fifo.o

fifo.o: fifo.c fifo.h
	gcc -c fifo.c

fifo_test.o: fifo.o fifo_test.c
	gcc -c fifo_test.c

run:
	./$(TARGET)

clean:
	rm -r *.o *.out
