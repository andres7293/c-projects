#include "stdio.h"
#include "ring_buffer.h"

int main (void) 
{
  char buffer[3];
  ringBuffer_t ringBuffer;
  //Init ring buffer
  ringBufferInit (&ringBuffer,buffer,sizeof(buffer));
  while (1) {
    ringBufferPush (&ringBuffer,'a');
    char value;
    ringBufferPop  (&ringBuffer,&value);
    printf ("%c\n\r",value);
  }
  return 0;
}
