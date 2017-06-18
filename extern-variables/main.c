#include "stdio.h"
#include "variables.h"

int add(int a,int b);

extern int a;

void main(void)
{
 int result; 
 result= add(a,5);
 printf("The result is %i\n\r",result);
}

int add(int a,int b)
{
 return (a+b);
}
