#include "stdio.h"
#include "ring_buffer.h"

int main (void) 
{
  char buffer[4];
  ringBuffer_t ringBuffer;
  //Init ring buffer
  ringBufferInit (&ringBuffer,buffer,sizeof(buffer));
  while (1) {
    ringBufferPush (&ringBuffer,'a');
    ringBufferPush (&ringBuffer,'b');
    ringBufferPush (&ringBuffer,'c');
    ringBufferPush (&ringBuffer,'d');
    int data;
    if (ringBufferIsData (&ringBuffer,&data) == RINGBUFFER_DATA_AVAILABLE) {
	    char value;
	    ringBufferPop  (&ringBuffer,&value);
	    printf ("%c\n\r",value);
    }
  }
  return 0;
}
