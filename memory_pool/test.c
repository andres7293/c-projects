#include <stdio.h>
#include <stdint.h>
#include "memory_pool.h"
#include <string.h>

const int MemSize = 1024 * 10;

int main (void) {
    uint8_t memory [MemSize];
    uint8_t memCtrl [MemSize / 32];
    mem_pool_t mem;
    //memory_pool_init(&mem, MemSize, 32);
    mem_pool_init_fixed(&mem, memory, memCtrl, MemSize, 32);
    char str[] = {"Hello world!!\n"};
    int Size = 30;
    void *ptr[Size];
    for (int i = 0; i < Size; i++) {
        ptr[i] = mem_pool_alloc(&mem);
        if (ptr[i] != NULL) {
            memcpy(ptr[i], str, sizeof(str));
        } 
        else {
            printf("Cant alloc memory\n");
        }
    }
    for (int i = 0; i < Size; i++) {
        if (ptr[i] != NULL) {
            printf("%s", (char *)ptr[i]);
            mem_pool_free(&mem, ptr[i]);
        }
    }
    return 0;
}