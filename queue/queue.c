/*
 FILO Queue
*/

#include "queue.h"

queue_ret_n queueInit (queue_t *queue,int *array,int size)
{
  //Init queue
  queue->Queue = array;
  queue->Ptr   = 0;
  queue->Size  = size;
  return QUEUE_SUCCESS;
}

queue_ret_n queuePush (queue_t *queue, int in)
{
  if (queue->Ptr < queue->Size) {
    queue->Queue[queue->Ptr] = in;
    queue->Ptr++;
    return QUEUE_SUCCESS;
  }
  else {
   return QUEUE_FULL; 
  }
}

queue_ret_n queuePop (queue_t *queue, int *out)
{
  if (queue->Ptr > 0) {
    queue->Ptr--;
    *out = queue->Queue[queue->Ptr];
    return QUEUE_SUCCESS;
  }
  else {
    return QUEUE_EMPTY;
  }
}
