CC=gcc
TARGET=fifo_test.out

SRC += \
	main.c \
	fifo.c \

fifo_test: main.o fifo.o
	gcc -o $(TARGET) main.o fifo.o

fifo.o: fifo.c fifo.h
	gcc -c fifo.c

fifo_test.o: fifo.o main.c
	gcc -c main.c

run:
	./$(TARGET)

clean:
	rm -r *.o *.out
