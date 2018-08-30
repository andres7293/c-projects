#ifndef __FAT32_H__
#define __FAT32_H__

#include "stdint.h"
#include "stdio.h"
#include "string.h"

#define SECTOR_SIZE 512

typedef struct __attribute__((packed)) {
    uint8_t  oemName[8];
    uint32_t firstLBA;
    uint32_t lastLBA;
    uint16_t sectorSize;
    uint8_t  sectorsPerCluster;
    uint16_t reservedSectors;
    uint8_t  NumberOfFats;
    uint32_t sectorsPerFat;
    uint32_t RootDirFirstCluster;
    uint16_t signature;

    uint32_t fatBeginLBA;
    uint32_t fat2BeginLBA;
    uint32_t clusterBeginLBA;
} fat32_t;

typedef struct __attribute__((packed)) {
    uint8_t fileName[11];
    uint8_t attrib;
    uint16_t firstClusterHigh;
    uint16_t firstClusterLow;
    uint32_t fileSize;
} dirEntry_t;

int  fat32_mount          (fat32_t *fat32);
int  fat32_readPartition  (fat32_t *fat32, uint8_t *sector_buffer);
int  fat32_readBootRecord (fat32_t *fat32, uint8_t *sector_buffer);

uint32_t fat32_getClusterLBA   (fat32_t *fat32, uint8_t cluster);

int fat32_showDirectoryEntries  (fat32_t *fat32, uint32_t cluster, uint8_t *sector_buffer);
void fat32_printDirectoryInfo    (fat32_t *fat32, dirEntry_t *dirEntry);

#endif
