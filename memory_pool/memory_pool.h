#ifndef __MEMORY_POOL_H__
#define __MEMORY_POOL_H__

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct {
    uint8_t *memory;
    uint8_t *controlBlock;
    int     memSize;
    int     blockSize;
    int     numBlocks;
}mem_pool_t;

int   memory_pool_init (mem_pool_t *mem_pool, int mem_size, int block_size);
int   mem_pool_init_fixed (mem_pool_t *mem_pool, uint8_t *memory, uint8_t *memory_ctrl, int mem_size, int block_size);
void* mem_pool_alloc   (mem_pool_t *mem_pool);
void  mem_pool_free    (mem_pool_t *mem_pool, void *ptr);

#endif