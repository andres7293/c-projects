#include <stdio.h>
#include <stdint.h>

void printHex (uint8_t number);
void hex	   (uint8_t nibble);

int main (void) {
	printf("0x");
	printHex(0xAA);
	printf("\n");
	return 0;
}

void printHex (uint8_t number) {
	uint8_t msn = number >> 4;
	uint8_t lsn = number & 0x0F;
	hex(msn);
	hex(lsn);
}

void hex (uint8_t nibble) {
	if (nibble < 10) {
		printf("%c", nibble);
	}
	else {
		printf("%c", nibble + 'A' - 10);
	}
}
