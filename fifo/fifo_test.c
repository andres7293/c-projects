#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "fifo.h"

int test_InitReturnValue(void);
int test_PushReturnValue (void);
int test_PushContent (void);
int test_PopReturnValue (void);
int test_PopContent (void);
int test_PushMoreBytesThanBufferSizeReturnValue (void);
int test_PushMoreBytesThanBufferSizeContent (void);
int test_AvailableReturnValue (void);
int test_NoBytesAvailableReturnValue (void);
int test_PopMoreBytesThanPushedReturnValue (void);
int test_PopMoreBytesThanPushedContent (void);

int main (void) {
    int num_tests = 10;
    int success = 0;
    success += test_InitReturnValue();
    success += test_PushReturnValue();
    success += test_PushContent();
    success += test_PopReturnValue();
    success += test_PushMoreBytesThanBufferSizeReturnValue();
    success += test_PushMoreBytesThanBufferSizeContent();
    success += test_AvailableReturnValue();
    success += test_NoBytesAvailableReturnValue();
    success += test_PopMoreBytesThanPushedReturnValue();
    success += test_PopMoreBytesThanPushedContent();
    printf("%i/%i test passed\n", success, num_tests);
	return 0;
}

int test_InitReturnValue(void) {
    fifo_t fifo;
    uint8_t buffer[5];
    int ret = fifo_init(&fifo, buffer, sizeof(buffer));
    if (ret != 0) {
        printf("test_FifoInitReturnValue failed\n");
        return 0;
    }
    return 1;
}

int test_PushReturnValue (void) {
    fifo_t fifo;
    uint8_t buffer[64];
    fifo_init(&fifo, buffer, sizeof(buffer));
    uint8_t msg[] = {"This is a test\n"};
    int ret = fifo_push(&fifo, msg, sizeof(msg));
    if (ret != sizeof(msg)) {
        printf("test_FifoPushReturnValue failed\n");
        return 0;
    }
    return 1;
}

int test_PushContent (void) {
    fifo_t fifo;
    uint8_t buffer[64];
    fifo_init(&fifo, buffer, sizeof(buffer));
    uint8_t msg[] = {"This is a test\n"};
    fifo_push(&fifo, msg, sizeof(msg));
    int ret = memcmp(buffer, msg, sizeof(msg));
    if (ret != 0) {
        printf("test_fifoPushContent failed\n");
        return 0;
    }
    return 1;
}

int test_PopReturnValue (void) {
    fifo_t fifo;
    uint8_t buffer[64];
    fifo_init(&fifo, buffer, sizeof(buffer));
    uint8_t msg[] = {"This is a test\n"};
    fifo_push(&fifo, msg, sizeof(msg));
    int ret = fifo_pop(&fifo, msg, sizeof(msg));
    if (ret != sizeof(msg)) {
        printf("test_FifoPopReturnValue failed\n");
        return 0;
    }
    return 1;
}

int test_PopContent (void) {
    fifo_t fifo;
    uint8_t buffer[64];
    fifo_init(&fifo, buffer, sizeof(buffer));
    uint8_t msg[] = {"This is a test\n"};
    fifo_push(&fifo, msg, sizeof(msg));
    memset(msg, 0, sizeof(msg));
    fifo_pop(&fifo, msg, sizeof(msg));
    int ret = memcmp(buffer, msg, sizeof(msg));
    if (ret != 0) {
        printf("test_FifoPopContent failed\n");
        return 0;
    }
    return 1;
}

int test_PushMoreBytesThanBufferSizeReturnValue (void) {
    fifo_t fifo;
    uint8_t buffer[8];
    fifo_init(&fifo, buffer, sizeof(buffer));
    uint8_t msg[] = {"This is a test\n"};
    int ret = fifo_push(&fifo, msg, sizeof(msg));
    if (ret != sizeof(msg)) {
        printf("test_PushMoreBytesThanBufferSizeReturnValue failed\n");
        return 0;
    }
    return 1;
}

int test_PushMoreBytesThanBufferSizeContent (void) {
    fifo_t fifo;
    uint8_t buffer[8];
    fifo_init(&fifo, buffer, sizeof(buffer));
    uint8_t msg[] = {"This is a test\n"};
    fifo_push(&fifo, msg, sizeof(msg));
    int ret = memcmp(buffer, msg, sizeof(msg));
    if (ret == 0) {
        printf("test_PushMoreBytesThanBufferSizeContent failed\n");
        return 0;
    }
    return 1;
}

int test_AvailableReturnValue (void) {
    fifo_t fifo;
    uint8_t buffer[64];
    fifo_init(&fifo, buffer, sizeof(buffer));
    uint8_t msg[] = {"This is a test\n"};
    fifo_push(&fifo, msg, sizeof(msg));
    int ret = fifo_available(&fifo);
    if (ret != 1) {
        printf("test_AvailableReturnValue failed\n");
        return 0;
    }
    return 1;
}

int test_NoBytesAvailableReturnValue (void) {
    fifo_t fifo;
    uint8_t buffer[64];
    fifo_init(&fifo, buffer, sizeof(buffer));
    uint8_t msg[] = {"This is a test\n"};
    int ret = fifo_available(&fifo);
    if (ret != 0) {
        printf("test_NoBytesAvailableReturnValue failed\n");
        return 0;
    }
    return 1;
}

int test_PopMoreBytesThanPushedReturnValue (void) {
    fifo_t fifo;
    uint8_t buffer[4];
    fifo_init(&fifo, buffer, sizeof(buffer));
    uint8_t msg[] = {"This is a test\n"};
    fifo_push(&fifo, msg, sizeof(msg));
    int ret = fifo_pop(&fifo, msg, sizeof(msg));
    if (ret == sizeof(msg)) {
        printf("test_PopMoreBytesThanPushedReturnValue failed\n");
        return 0;
    }
    return 1;
}

int test_PopMoreBytesThanPushedContent (void) {
    fifo_t fifo;
    uint8_t buffer[4];
    fifo_init(&fifo, buffer, sizeof(buffer));
    uint8_t msg[] = {"This is a test\n"};
    fifo_push(&fifo, msg, sizeof(msg));
    memset(msg, 0, sizeof(msg));
    fifo_pop(&fifo, msg, sizeof(msg));
    int ret = memcmp(buffer, msg, sizeof(msg));
    if (ret == 0) {
        printf("test_PopMoreBytesThanPushedContent failed\n");
        return 0;
    }
    return 1;
}
