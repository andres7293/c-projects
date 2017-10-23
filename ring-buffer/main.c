#include "stdio.h"
#include "ring_buffer.h"

char a;

int main (void) 
{
  char buffer[2];
  ringBuffer_t ringBuffer;
  //Init ring buffer
  ringBufferInit (&ringBuffer,buffer,sizeof(buffer));
  ringBufferPush (&ringBuffer,'a');
  if (ringBufferIsData (&ringBuffer) == RINGBUFFER_DATA_AVAILABLE) {
     printf ("Data available\n\r");
     ringBufferPop(&ringBuffer,&a);
     printf ("a = %c\n\r",a);
  }
  else {
     printf ("empty\n\r");
  }
  return 0;
}
