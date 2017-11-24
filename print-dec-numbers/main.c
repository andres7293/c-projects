#include <stdio.h>
#include <stdint.h>

void printDec_uint8   (uint8_t number);
void printDec_uint16  (uint16_t number);
void printDec_uint32  (uint32_t number);
void printDec_uint64  (uint64_t number);

int main (void) {
	printDec_uint8(115);
	printf("\n");


	printDec_uint16(4871);
	printf("\n");

	printDec_uint32(65465465);
	printf("\n");

	printDec_uint64(78165465465);
	printf("\n");
	return 0;
}

void printDec_uint8  (uint8_t number) {
	uint8_t n = 100;
	uint8_t digit;
	do {
		digit  = (number / n) % 10;
		digit += '0';
		printf("%c", digit);
		n /= 10;
	}
	while (n);
}

void printDec_uint16 (uint16_t number) {
	uint16_t n = 10000;
	uint8_t digit;
	do {
		digit  = (number / n) % 10;
		digit += '0';
		printf("%c", digit);
		n /= 10;
	}
	while (n);
}

void printDec_uint32 (uint32_t number) {
	uint32_t n = 1000000000;
	uint8_t digit;
	do {
		digit  = (number / n) % 10;
		digit += '0';
		printf("%c", digit);
		n /= 10;
	}
	while (n);
}
void printDec_uint64 (uint64_t number) {
	uint64_t n = 1000000000000;
	uint8_t digit;
	do {
		digit  = (number / n) % 10;
		digit += '0';
		printf("%c", digit);
		n /= 10;
	}
	while (n);
}
