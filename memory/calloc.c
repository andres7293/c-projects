#include "stdio.h"
#include "stdlib.h"//malloc,free,etc


void fill_buffer(char *buffer,int len,int value);
void print_buffer(char *buffer,int len);

void main()
{
  int size=10;
  char *buffer =(char *) calloc(size,sizeof(char));

  if(buffer != NULL)
  { 
     printf("Buffer after filled\n\r");
     //print buffer before fill it
     print_buffer(buffer,size);
     //fill buffer
     fill_buffer(buffer,size,'#');
     //fill buffer before fill it
     printf("Buffer before filled\n\r");
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
