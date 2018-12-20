#include "memory_pool.h"

int memory_pool_init (mem_pool_t *mem_pool, int mem_size, int block_size) {
    if (mem_size <= 0 || block_size <= 0) {
        return -2;
    }
    mem_pool->memSize = mem_size;
    mem_pool->blockSize = block_size;
    mem_pool->numBlocks = mem_pool->memSize / mem_pool->blockSize;

    mem_pool->memory = malloc(mem_pool->memSize);
    if (mem_pool->memory == 0) {
        return -1;
    }
    mem_pool->controlBlock = malloc(mem_pool->numBlocks);
    if (mem_pool->controlBlock == 0) {
        return -1;
    }
    return 0;
}

int mem_pool_init_fixed (mem_pool_t *mem_pool, uint8_t *memory, uint8_t *memory_ctrl, int mem_size, int block_size) {
    if (mem_size <= 0 || block_size <= 0) {
        return -2;
    }
    if (memory == NULL || memory_ctrl == NULL) {
        return -3;
    } 
    mem_pool->memSize = mem_size;
    mem_pool->blockSize = block_size;
    mem_pool->numBlocks = mem_pool->memSize / mem_pool->blockSize;
    mem_pool->memory = memory;
    mem_pool->controlBlock = memory_ctrl;
    return 0;
}

void* mem_pool_alloc (mem_pool_t *mem_pool) {
    for (int i = 0; i < mem_pool->numBlocks; i++) {
        if (mem_pool->controlBlock[i] == 0) {
            mem_pool->controlBlock[i] = 0xff;
            return (mem_pool->memory + (i * mem_pool->blockSize));
        }
    }
    return NULL;
}

void mem_pool_free (mem_pool_t *mem_pool, void *ptr) {
    if (ptr == NULL) {
        return;
    }
    int index = (ptr - (void *)mem_pool->memory) / mem_pool->blockSize;
    mem_pool->controlBlock[index] = 0;
}