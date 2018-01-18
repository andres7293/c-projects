#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "fifo.h"

int fifo_push_test (void);
int fifo_pop_test  (void);
int fifo_cant_pop_test (void);
int fifo_push_overflow_test (void);

int main (void) {
	int num_of_test = 4;
	int push_test_ret;
	int pop_test_ret;
	int cant_pop_test_ret;
	int push_overflow_test_ret;

	push_test_ret = fifo_push_test();
	pop_test_ret  = fifo_pop_test();
	cant_pop_test_ret = fifo_cant_pop_test();
	push_overflow_test_ret = fifo_push_overflow_test();

	int result = push_test_ret + pop_test_ret + cant_pop_test_ret + push_overflow_test_ret;

	printf("%i/%i test passed\n", result, num_of_test);

	return 0;
}

//check if number of bytes pushed is equal to our message bytes
int fifo_push_test (void) {
	fifo_t fifo;
	uint8_t buffer[512];
	uint8_t str_test[] = {"This is a test message\n"};
	fifo_init(&fifo, buffer, sizeof(buffer));
	int ret = fifo_push(&fifo, str_test, sizeof(str_test));
	if (ret != sizeof(str_test)) {
		return 0;
	}
	return 1;
}

//Check pop operations
int fifo_pop_test (void) {
	fifo_t fifo;
	uint8_t buffer[512];
	uint8_t str_test[] = {"This is a test message\n"};
	uint8_t str_poped[512];
	int ret;
	fifo_init(&fifo, buffer, sizeof(buffer));
	fifo_push(&fifo, str_test, sizeof(str_test));
	ret = fifo_pop(&fifo, str_poped, sizeof(str_test));
	//check if bytes poped is equal to pushed
	if (ret != sizeof(str_test)) {
		return 0;
	}
	//check if content poped is equal to pushed
	if (memcmp(str_poped, str_test, sizeof(str_test)) != 0) {
		return 0;
	}
	return 1;
}

int fifo_cant_pop_test (void) {
	fifo_t fifo;
	uint8_t buffer[512];
	uint8_t push_value = 0xAA;
	uint8_t pop_str[512];
	int ret;

	fifo_init(&fifo, buffer, sizeof(buffer));
	fifo_push(&fifo, &push_value, 1);

	ret = fifo_pop(&fifo, pop_str, 512);
	//check number of bytes poped
	if (ret != 1) {
		return 0;
	}
}

int fifo_push_overflow_test (void) {
	fifo_t fifo;
	uint8_t buffer[4];
	uint8_t push_value = 0xDD;
	uint8_t pop_value;

	fifo_init(&fifo, buffer, sizeof(buffer));
	fifo_push(&fifo, &push_value, 1);
	fifo_push(&fifo, &push_value, 1);
	fifo_push(&fifo, &push_value, 1);
	fifo_push(&fifo, &push_value, 1);

	push_value = 0xAA;
	fifo_push(&fifo, &push_value, 1);

	//pop all content
	while (fifo_pop(&fifo, &pop_value, 1) != 0) {
	}
	//should be 0xAA value in pop_str
	if (pop_value != 0xAA) {
		return 0;
	}
	return 1;
}
