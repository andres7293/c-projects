#include "stdio.h"
#include "stdint.h"

/*The compiler adds padding bytes between bytes inside struct.
In this example, if we count the bytes of our struct, it must be
5 bytes size. Nevertheless if we do a sizeof, it return 8bytes.
Why? Because compiler add bytes to full 1word of memory in order 
to optimize memory access.
*/

/*
When we print entire struct as array bytes, we can see trash between 
a and b integers. That is because compiler adds bytes to fill memory word address.
*/
void print(uint8_t *data, int len);

struct data_t{
  uint8_t a;
  uint32_t b;	
};

struct data_packed_t{
  uint8_t a;
  uint32_t b;
}__attribute__((packed));


void main(void){

  struct data_t data;
  data.a=0xDD;
  data.b=0xAAAAAAAA;
  printf("Sizeof struct = %lu\n\r",sizeof(struct data_t));
  printf("Content of struct: \n\r");
  //print the content of struct
  print((uint8_t *)&data,sizeof(struct data_t));

  //packed struct
  struct data_packed_t data_p;
  data_p.a=0xDD;
  data_p.b=0xAAAAAAAA;
  printf("Sizeof packed struct = %lu\n\r",sizeof(struct data_packed_t));
  printf("Content of packed struct: \n\r");
  //print the content of struct
  print((uint8_t *)&data_p,sizeof(struct data_packed_t));
}

void print(uint8_t *data,int len)
{
  int i=0;
  for(i=0;i<len;i++){
    printf("%X",data[i]);
  }
  printf("\n\r");
}
