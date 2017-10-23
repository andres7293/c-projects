#ifndef RING_BUFFER_H
#define RING_BUFFER_H


typedef struct {
  char *Buffer; //Pointer where buffer is allocated
  int  Head;    // Pointer where current write index is
  int  Tail;    // Pointer where current read index is
  int  Size;    //Size of ring buffer
  int  Count;
}ringBuffer_t;

typedef enum {
  RINGBUFFER_SUCCESS,
  RINGBUFFER_EMPTY,
  RINGBUFFER_DATA_AVAILABLE
}ringBuffer_n;

void ringBufferInit   (ringBuffer_t *ringbuffer,char *buffer,int size);
void ringBufferPush   (ringBuffer_t *ringbuffer,char in);
void ringBufferPop    (ringBuffer_t *ringbuffer,char *out);
ringBuffer_n ringBufferIsData (ringBuffer_t *ringbuffer);

#endif
