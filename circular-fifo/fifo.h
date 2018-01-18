#ifndef FIFO_H
#define FIFO_H

#include <stdio.h>
#include <stdint.h>

typedef struct {
	uint8_t *buffer;
	int 	head;
	int 	tail;
	int 	size;
}fifo_t;

void fifo_init (fifo_t *fifo, uint8_t *buffer, int size);
int  fifo_push (fifo_t *fifo, uint8_t *in, int length);
int  fifo_pop (fifo_t *fifo, uint8_t *out, int length);

static void fifo_pushByte (fifo_t *fifo, uint8_t in);
static int fifo_popByte (fifo_t *fifo, uint8_t *out);

#endif
