#include "stdio.h"
#include "stdint.h"

/*split integer into two bytes*/
/*little endian format!!!!*/

uint8_t get_msb(int integer);
uint8_t get_lsb(int integer);

void main(void)
{
  int integer = 0xAADD;
  printf("The entire integer is = %i\n\r",integer);
  printf("MSB = 0x%X\n\r",get_msb(integer));
  printf("LSB = 0x%X\n\r",get_lsb(integer));
}

uint8_t get_msb(int integer)
{
  uint8_t msb = (integer >>  8);
  return msb;
}

uint8_t get_lsb(int integer)
{
  uint8_t lsb = integer & 0x00FF;
  return lsb;
}

