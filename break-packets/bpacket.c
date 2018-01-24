#include "bpacket.h"

int bpacket_init (bpacket_t *bpacket, uint8_t *buffer, int size, int mtu) {
	bpacket->buffer = buffer;
	bpacket->size = size;
	bpacket->mtu = mtu;
	bpacket->pointer = 0;
	bpacket->bytesLeft = size;
	return 0;
}

uint8_t * bpacket_getNextBytes (bpacket_t *bpacket, int *bytesOut) {
	if (bpacket->pointer < bpacket->size) {
		uint8_t *ptr;
		if (bpacket->pointer + bpacket->mtu <= bpacket->size) {
			ptr = &bpacket->buffer[bpacket->pointer];
			bpacket->pointer += bpacket->mtu;
			bpacket->bytesLeft -= bpacket->mtu;
			*bytesOut = bpacket->mtu;
			return ptr;
		}
		else {
			ptr = &bpacket->buffer[bpacket->pointer];
			bpacket->pointer = bpacket->bytesLeft + bpacket->pointer;
			*bytesOut = bpacket->bytesLeft;
			bpacket->bytesLeft = 0;
			return ptr;
		}
	}
	else {
		*bytesOut = 0;
		return NULL;
	}
}
