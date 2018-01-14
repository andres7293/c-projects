#include <stdio.h>
#include <stdint.h>

#include "fifo.h"

fifo_t fifo;
uint8_t buffer[5];
uint8_t save[5];

int main (void) {
	int i;
	fifo_init(&fifo, buffer, 5);
	fifo_push(&fifo, save, 5);
	i = fifo_pop(&fifo, save, 4);
	return 0;
}
