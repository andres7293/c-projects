#include <stdio.h>
#include <stdint.h>

int main (void) {
	uint64_t number = 123456789;
	int digito = 100000000;
	do {
		//get digit
		uint8_t d = (uint8_t) ((number / digito) % 10);
		digito /= 10;
		printf("%i", d);
	} while (digito);
	printf("\n");
	return 0;
}
