#ifndef  __PHYSICAL_H__
#define  __PHYSICAL_H__

#include "stdint.h"
#include "stdio.h"
#include "string.h"
#include "fat32.h"

int readSector (uint32_t sector, uint8_t *out);
int setFile     (FILE *device_file);

#endif