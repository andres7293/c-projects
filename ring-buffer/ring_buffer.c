#include "ring_buffer.h"

void ringBufferInit (ringBuffer_t *ringbuffer,char *buffer,int size)
{
  //Copy the address where buffer is allocated
  ringbuffer->Buffer = buffer;
  //Init the size of buffer
  ringbuffer->Size   = size;
  //Init tail and head pointers
  ringbuffer->Tail   = 0;
  ringbuffer->Head   = 0;
  ringbuffer->Count  = 0;
}

void ringBufferPush (ringBuffer_t *ringbuffer,char in)
{
  if (ringbuffer->Head < ringbuffer->Size) {
	ringbuffer->Buffer[ringbuffer->Head] = in;
	ringbuffer->Head++;
  }
  else {
    //ringbuffer reach end buffer, overwrite old values
    ringbuffer->Buffer[0] = in;
    ringbuffer->Head      = 1;
  }
  ringbuffer->Count++;
}

void ringBufferPop  (ringBuffer_t *ringbuffer,char *out)
{
if (ringbuffer->Count >= 0 ) {
  if (ringbuffer->Tail < ringbuffer->Size) {
	*out = ringbuffer->Buffer[ringbuffer->Tail];
	ringbuffer->Tail++;
  }
  else {
    *out = ringbuffer->Buffer[0];
    ringbuffer->Tail = 1;
  }
  ringbuffer->Count--;
 }
 else {
   *out = 0;
 }
}

ringBuffer_n ringBufferIsData (ringBuffer_t *ringbuffer,int *out)
{
  if (ringbuffer->Count > 0) {
        *out = ringbuffer->Count;
	return RINGBUFFER_DATA_AVAILABLE;	
  }
  else { 
	*out = 0;
	return RINGBUFFER_DATA_AVAILABLE;
  }
}
