#include <stdio.h>
#include <stdint.h>

void printBits (uint8_t byte);

int main (void) {
	uint8_t number = 0x0C;
	printf("0x%X\n", number);
	printBits(number);
	return 0;
}

void printBits (uint8_t byte) {
	//little endian
	printf("0b");
	for (int i = 7; i >= 0 ; i--) {
		(byte & (1 << i)) ? printf("1") : printf("0");
	}
	printf("\n");
}
