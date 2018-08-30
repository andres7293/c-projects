#include "fat32.h"
#include "physical.h"

int  fat32_mount (fat32_t *fat32) {
    uint8_t sector_buffer[SECTOR_SIZE];
    fat32_readPartition(fat32, sector_buffer);
    fat32_readBootRecord(fat32, sector_buffer);
    //Calculate begin LBA
    fat32->fatBeginLBA     = fat32->firstLBA    + fat32->reservedSectors;
    fat32->fat2BeginLBA     = fat32->fatBeginLBA + fat32->sectorsPerFat;
    fat32->clusterBeginLBA = fat32->firstLBA    + (fat32->reservedSectors + (2 * fat32->sectorsPerFat));
    return 0;
}

int  fat32_readPartition  (fat32_t *fat32, uint8_t *sector_buffer) {
    //Read partition sector inside MBR
    readSector(0, sector_buffer);
    //Get LBA Begin and LBA Length from MBR
    memcpy((uint8_t *)&fat32->firstLBA,  &sector_buffer[446 + 10], 4);
    memcpy((uint8_t *)&fat32->lastLBA,   &sector_buffer[446 + 14], 4);
    return 0;
}

int  fat32_readBootRecord (fat32_t *fat32, uint8_t *sector_buffer) {
    //Read BootRecord
    readSector(fat32->firstLBA, sector_buffer);
    memcpy((uint8_t *) &fat32->oemName,             &sector_buffer[0x003], 8);
    memcpy((uint8_t *) &fat32->sectorSize,          &sector_buffer[0x00B], 2);
    memcpy((uint8_t *) &fat32->sectorsPerCluster,   &sector_buffer[0x00D], 1);
    memcpy((uint8_t *) &fat32->reservedSectors,     &sector_buffer[0x00E], 1);
    memcpy((uint8_t *) &fat32->NumberOfFats,        &sector_buffer[0x010], 1);
    memcpy((uint8_t *) &fat32->sectorsPerFat,       &sector_buffer[0x024], 4);
    memcpy((uint8_t *) &fat32->RootDirFirstCluster, &sector_buffer[0x02C], 4);
    memcpy((uint8_t *) &fat32->signature,           &sector_buffer[0x1FE], 2);
    //Only check boot signature for now...
    if (fat32->signature != 0xAA55) {
        return -1;
    }
    return 0;
}

uint32_t fat32_getClusterLBA   (fat32_t *fat32, uint8_t cluster) {
    return (fat32->clusterBeginLBA + (cluster - 2) * fat32->sectorsPerCluster);
}

int fat32_showDirectoryEntries (fat32_t *fat32, uint32_t cluster, uint8_t *sector_buffer) {
    uint32_t current_cluster = cluster;
    while (1) {
        uint32_t cluster_lba = fat32_getClusterLBA(fat32, current_cluster);
        printf("cluster = %i\n", current_cluster);
        //Iterate over sectors of current cluster
        for (int clusterSector = 0; clusterSector < fat32->sectorsPerCluster; clusterSector++) {
            readSector(cluster_lba, sector_buffer);
            //Iterate over 16 entries of sector
            int offset = 0;
            for (int entry = 0; entry < 16; entry++) {
                offset = entry * 32 ;
                uint8_t *status      = &sector_buffer[offset];
                dirEntry_t *dirEntry = (dirEntry_t *) &sector_buffer[offset];
                if (*status == 0) {
                    //end of directory
                    //printf("End of dir\n");
                    return 0;
                }
                if (*status == 0xE5) {
                    //printf("unusued entry\n");
                    continue;
                }
                fat32_printDirectoryInfo(fat32, dirEntry);
            }
        }
        //Advance next cluster
        break;
    }
    return 0;
}

void fat32_printDirectoryInfo (fat32_t *fat32, dirEntry_t *dirEntry) {
    if (dirEntry->attrib & (1 << 4)) {
        printf("is a subdirectory --- ");
        printf("%s\n", dirEntry->fileName);
        return;
    }
    if (dirEntry->attrib & (1 << 1)) {
        //hidden dir, not show in ls
        return;
    }
    printf("%s", dirEntry->fileName);
    printf(" --- fileSize = %i\n", dirEntry->fileSize);
}
