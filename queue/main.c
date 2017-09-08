#include "stdio.h"
#include "stdint.h"
#include  "queue.h"

void print (int value);
void printRetQueue (queue_ret_n ret);

void main (void)
{
  //Create queue struct
  queue_t queue;
  //Init queue
  queueInit (&queue);
  //push values
  for (int i = 0;i < 11 ;i++) {
    queue_ret_n ret;
    ret = queuePush(&queue,5);
    printRetQueue (ret);
  }
  
  //pop values
  for (int i = 0; i < 11; i++) {
    queue_ret_n ret;
    int value;
    ret = queuePop (&queue,&value);
    printRetQueue(ret);
    print (value);
  }
}

void print (int value)
{
  printf("Queue = %i\n\r",value);
}

void printRetQueue (queue_ret_n ret)
{
  switch (ret) {
    case QUEUE_SUCCESS:	
     printf("QUEUE SUCCESS\n\r");
    break;
  
    case QUEUE_FULL:
     printf("QUEUE FULL\n\r");
    break;
   
    case QUEUE_EMPTY:
     printf("QUEUE EMPTY\n\r");
    break;
  }
}
