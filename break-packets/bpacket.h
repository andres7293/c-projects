#ifndef BPACKET_H__
#define BPACKET_H__

#include "stdio.h"
#include "stdint.h"

typedef struct {
	uint8_t *buffer;
	int		size;
	int     bytesLeft;
	int		pointer;
	int 	mtu;
}bpacket_t;

int 	  bpacket_init         (bpacket_t *bpacket, uint8_t *buffer, int size, int mtu);
uint8_t * bpacket_getNextBytes (bpacket_t *bpacket, int *bytesOut);

#endif
