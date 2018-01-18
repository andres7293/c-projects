#include "fifo.h"

void fifo_init (fifo_t *fifo, uint8_t *buffer, int size) {
	fifo->buffer = buffer;
	fifo->head	 = 0;
	fifo->tail	 = 0;
	fifo->size	 = size;
}

int fifo_push (fifo_t *fifo, uint8_t *in, int length) {
	int i;
	for (i = 0; i < length; i++) {
		fifo_pushByte(fifo, in[i]);
	}
	return i;
}

int fifo_pop (fifo_t *fifo, uint8_t *out, int length) {
	int i = 0;
	int ret;
	for (i = 0; i < length; i++) {
		ret = fifo_popByte(fifo, &out[i]);
		if (ret != 0) {
			return i;
		}
	}
	return i;
}

static void fifo_pushByte (fifo_t *fifo, uint8_t in) {
	if (fifo->head < fifo->size) {
		fifo->buffer[fifo->head++] = in;
	}
	else {
		fifo->head = 0;
		fifo->buffer[fifo->head++] = in;
	}
}

static int fifo_popByte (fifo_t *fifo, uint8_t *out) {
	if (fifo->tail != fifo->head) {
		if (fifo->tail < fifo->size) {
			*out = fifo->buffer[fifo->tail++];
		}
		else {
			fifo->tail = 0;
			*out = fifo->buffer[fifo->tail++];
		}
		//bytes written succesfully
		return 0;
	}
	//Cant pop bytes
	return 1;
}
