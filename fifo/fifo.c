#include "fifo.h"

int fifo_init (fifo_t *fifo, uint8_t *buffer, int size) {
    if (buffer == NULL) {
        return -1;
    }
    if (size < 0) {
        return -2;
    }
	fifo->Buffer = buffer;
	fifo->Head	 = 0;
	fifo->Tail	 = 0;
	fifo->Size	 = size;
    return 0;
}

int fifo_available (fifo_t *fifo) {
    if (fifo->Tail != fifo->Head) {
        return 1;
    }
    else {
        return 0;
    }
}

/*
 * Overwrite old data
 * */
int fifo_push (fifo_t *fifo, uint8_t *in, int length) {
	int i = 0;
    for (i = 0; i < length; i++) {
        if (fifo->Head > fifo->Size) {
            fifo->Buffer[0] = in[i];
            fifo->Head = 1;
        }
        else {
            fifo->Buffer[fifo->Head++] = in[i];
        }
    }
    return i;
}

int fifo_pop (fifo_t *fifo, uint8_t *out, int length) {
	int i = 0;
    for (i = 0; i < length; i++) {
        if (fifo->Tail == fifo->Head) {
            return i;
        }
        if (fifo->Tail > fifo->Size) {
            out[i] = fifo->Buffer[0];
            fifo->Tail = 1;
        }
        else {
            out[i] = fifo->Buffer[fifo->Tail++];
        }
    }
    return i;
}
