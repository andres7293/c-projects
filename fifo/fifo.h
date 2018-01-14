#ifndef FIFO_H
#define FIFO_H

#include <stdio.h>
#include <stdint.h>

typedef struct {
	uint8_t *buffer;
	int 	head;
	int 	tail;
	int 	count;
	int 	size;
}fifo_t;

void fifo_init (fifo_t *fifo, uint8_t *buffer, int size);
int  fifo_push (fifo_t *fifo, uint8_t *in, int length);
int  fifo_pop (fifo_t *fifo, uint8_t *out, int length);

#endif
