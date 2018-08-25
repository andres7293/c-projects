#ifndef __MEMORY_POOL_H__
#define __MEMORY_POOL_H__

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct {
    uint8_t *memory;
    int element_size;  //size allocated element in bytes
    int element_count; //number of elements allocated 
    uint8_t *memory_table; //table to keep track of allocated memory
}mem_pool_t;

typedef struct {
    uint8_t *mem_block;
    int     key; //key to identify alloc memory
}mem_block_t;

int mem_pool_init (mem_pool_t *mem_pool, int element_size, int element_count);
int mem_pool_alloc (mem_pool_t *mem_pool, mem_block_t *block);
void mem_pool_free  (mem_pool_t *mem_pool, mem_block_t *block);

#endif