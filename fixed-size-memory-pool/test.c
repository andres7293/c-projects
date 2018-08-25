#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "memory_pool.h"

int test_mem_pool_init (void);
int test_mem_pool_alloc (int interations);
int test_mem_pool_free  (int iterations);

int main (void) {
    int num_of_tests = 3;
    int test_success = 0;
    test_success += test_mem_pool_init();
    test_success += test_mem_pool_alloc(10000);
    test_success += test_mem_pool_free(10000);
    
    printf("%i/%i tests success\n", test_success, num_of_tests);
    return 0;
}

int test_mem_pool_init (void) {
    mem_pool_t mem_pool;
    int ret = mem_pool_init(&mem_pool, sizeof(uint32_t), 5);
    if (ret < 0) {
        return 0;
    }
    //test ok
    return 1;
}

int test_mem_pool_alloc (int iterations) {
    mem_pool_t mem_pool;
    mem_block_t block[iterations];
    int ret = mem_pool_init(&mem_pool, sizeof(uint32_t), iterations);
    for (int i = 0; i < iterations; i++) {
        ret = mem_pool_alloc(&mem_pool, &block[i]);
        if (ret < 0) {
            return 0;
        }
        memcpy(block[i].mem_block, &i, sizeof(uint32_t));
    }
    //Test content of memory blocks
    for (int i = 0; i < iterations; i++) {
        uint32_t content;
        memcpy(&content, block[i].mem_block, sizeof(uint32_t));
        if (content != i) {
            return 0;
        }
    }
    return 1;
}

int test_mem_pool_free  (int iterations) {
    mem_pool_t mem_pool;
    mem_block_t block;
    int ret = mem_pool_init(&mem_pool, sizeof(uint32_t), 1);
    for (int i = 0; i < iterations; i++) {
        ret = mem_pool_alloc(&mem_pool, &block);
        if (ret < 0) {
            printf("test_mem_pool_free fail allocating");
            return 0;
        }
        memcpy(block.mem_block, &i, sizeof(uint32_t));
        //check content of memory block
        uint32_t content;
        memcpy(&content, block.mem_block, sizeof(uint32_t));
        if (content != i) {
            printf("test_mem_pool_free fail checking content");
            return 0;
        }
        //free memory 
        mem_pool_free(&mem_pool, &block);
    }
    return 1;
}