#ifndef RING_BUFFER_H
#define RING_BUFFER_H


typedef struct {
  char *Buffer; //Pointer where buffer is allocated
  int  Head;    // Pointer where current write index is
  int  Tail;    // Pointer where current read index is
  int  Size;    //Size of ring buffer
}ringBuffer_t;

void ringBufferInit (ringBuffer_t *ringbuffer,char *buffer,int size);
void ringBufferPush (ringBuffer_t *ringbuffer,char in);
void ringBufferPop  (ringBuffer_t *ringbuffer,char *out);

#endif
