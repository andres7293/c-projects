#include "stdio.h"
#include "stdlib.h"//malloc,free,etc

void fill_buffer(char *buffer,int len,int value);
void print_buffer(char *buffer,int len);

void main()
{
  int size=10;
  char *buffer =(char *) malloc(size);

  if(buffer != NULL)
  { 
     fill_buffer(buffer,size,'#');
     print_buffer(buffer,size);
     free(buffer);
  }
  else
  {
     printf("Cannot malloc\n\r");
  }

}

void fill_buffer(char *buffer,int len, int value)
{
  int i=0;
  for(i=0;i<len;i++)
  {
    buffer[i]=value;
  }
  buffer[len]='\0';
}

void print_buffer(char *buffer,int len)
{
  int i=0;
  for(i=0;i<len;i++)
  {
    printf("Content of buffer[%i] : 0x%X\n\r",i,buffer[i]);
    //printf("Content of buffer[%i]   : %c\n\r",i,buffer[i]);
  }
}
