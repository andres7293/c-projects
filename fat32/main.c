#include <stdio.h>
#include <stdint.h>
#include "fat32.h"
#include "physical.h"

int main (int argv, char *argc[]) {
    /*
    if (argv <= 1) {
        return -1;
    }
    */
    //char *path = argc[1];
    //FILE *file = fopen(path, "rb");
    //FILE *file = fopen("fat32.img", "rb");
    FILE *file = fopen("/dev/sdb", "rb");
    if (file == NULL) {
        printf("Cant open file\n");
        return -1;
    }
    fat32_t fat32;
    uint8_t sector_buffer[512];
    setFile(file);
    int ret = fat32_mount(&fat32);
    if (ret < 0) {
        printf("Cant mount fat\n");
        return -1;
    }
    printf("Mount ok !\n");
    fat32_showDirectoryEntries(&fat32, fat32.RootDirFirstCluster, sector_buffer);
    fclose(file);
    return 0;
}
