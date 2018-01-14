#include <stdio.h>
#include <stdint.h>

#include "fifo.h"

fifo_t fifo;
uint8_t buffer[5];
uint8_t save[5];

int main (void) {
	fifo_init(&fifo, buffer, 5);
	fifo_push(&fifo, save, 10);
	fifo_push(&fifo, save, 10);
	fifo_pop(&fifo, save, 20);
	return 0;
}
