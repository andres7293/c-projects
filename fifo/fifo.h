#ifndef FIFO_H
#define FIFO_H

#include <stdio.h>
#include <stdint.h>

typedef struct {
	uint8_t *Buffer;
	int 	Head;
	int 	Tail;
	int 	Size;
}fifo_t;

int  fifo_init (fifo_t *fifo, uint8_t *buffer, int size);
int  fifo_push (fifo_t *fifo, uint8_t *in, int length);
int  fifo_pop  (fifo_t *fifo, uint8_t *out, int length);
int  fifo_available (fifo_t *fifo);

#endif
