#include "stdio.h"

void print_array(int *array, int len);
void init_array(int *array, int len);

void main(void)
{
  int len=20;
  int array[len];
  init_array(array,len);
  print_array(array,len);
}

void print_array(int *array,int len)
{
  int i=0;
  for(i=0;i<len;i++)
  {
    printf("%i ",array[i]);
  }
  printf("\n\r");
}

void init_array(int *array, int len)
{
  int i=0;
  for(i=0;i<len;i++)
  {
    array[i]=i;
  }
}
