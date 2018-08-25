#include "memory_pool.h"

int mem_pool_init (mem_pool_t *mem_pool, int element_size, int element_count) {
    mem_pool->memory = malloc(element_size * element_count);
    if (mem_pool->memory == NULL) {
        return -1;
    }
    mem_pool->memory_table = malloc(element_count);
    if (mem_pool->memory_table == NULL) {
        return -2;
    }
    mem_pool->element_count = element_count;
    mem_pool->element_size  = element_size;
    //Set memory as free
    for (int i = 0; i < element_count; i++) {
        mem_pool->memory_table[i] = 0;
    }
    return 0;
}

int mem_pool_alloc (mem_pool_t *mem_pool, mem_block_t *block) {
    for (int i = 0; i < mem_pool->element_count; i++) {
        if (mem_pool->memory_table[i] == 0) {
            block->mem_block = &mem_pool->memory[mem_pool->element_size * (i + 1)];
            block->key       = i;
            mem_pool->memory_table[i] = 0xff;
            return 0;
        }
    }
    block->mem_block = NULL;
    block->key = -1;
    return -1;
}

void mem_pool_free  (mem_pool_t *mem_pool, mem_block_t *block) {
    mem_pool->memory_table[block->key] = 0;
    block->key = 0;
    block->mem_block = NULL;
}