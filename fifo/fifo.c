#include "fifo.h"

void fifo_init (fifo_t *fifo, uint8_t *buffer, int size) {
	fifo->buffer = buffer;
	fifo->head	 = 0;
	fifo->tail	 = 0;
	fifo->count	 = 0;
	fifo->size	 = size;
}

int fifo_push (fifo_t *fifo, uint8_t *in, int length) {
	int i = 0;
	if (fifo->head < fifo->size) {
		do {
			fifo->buffer[fifo->head++] = in[i++];
		}
		while (fifo->head < fifo->size && i < length);
		return i;
	}
	else {
		return 0;
	}
}

int fifo_pop (fifo_t *fifo, uint8_t *out, int length) {
	int i = 0;
	if (fifo->tail < fifo->head) {
		do {
			out[i++] = fifo->buffer[fifo->tail++];
		}
		while (fifo->tail < fifo->head && i < length && fifo->tail < fifo->size);
		return i;
	}
	else {
		return 0;
	}
}
