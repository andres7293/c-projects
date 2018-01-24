#include "stdio.h"
#include "stdint.h"

#include "bpacket.h"

void print (uint8_t *msg, int size);

bpacket_t bpacket;
uint8_t msg [] = {"Hello world!\n"};

int main (void) {
	bpacket_init(&bpacket, msg, sizeof(msg), sizeof(msg) - 5);
	int bytesOut;
	do {
		uint8_t *msgIn = bpacket_getNextBytes(&bpacket, &bytesOut);
		print(msgIn, bytesOut);
	}
	while (bytesOut != 0);
	return 0;
}

void print (uint8_t *msg, int size) {
	for (int i = 0; i < size; i++) {
		printf("%c", msg[i]);
	}
}
