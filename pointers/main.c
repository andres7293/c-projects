#include "stdio.h"

void main(void)
{
  int *ptr; //pointer to int value
  int variable=5;
  
  //point to variable
  *ptr=variable;
  
  //print the value where ptr points
  printf("The value where *ptr point is : %i\n\r",*ptr);

  //print the address where ptr points
  printf("The address where *ptr points is %p\n\r",&ptr);
}
