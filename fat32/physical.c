#include "physical.h"

FILE *file = NULL;

int readSector (uint32_t sector, uint8_t *out) {
    if (file == NULL) {
        return -1;
    }
    fseek(file, sector * SECTOR_SIZE, SEEK_SET);
    return fread(out, 1, SECTOR_SIZE, file);
}

int setFile (FILE *device_file) {
    file = device_file;
    return 0;
}