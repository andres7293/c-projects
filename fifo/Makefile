CC=gcc
TARGET=fifo_test.out

SRC += \
	fifo_test.c \
	fifo.c \

all: $(SRC)
	$(CC) $(SRC) -o $(TARGET)

run:
	./$(TARGET)

clean:
	rm -r *.o *.out
