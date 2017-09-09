#ifndef QUEUE_H
#define QUEUE_H

#define QUEUE_SIZE 10

typedef struct{
 int *Queue; //Pointer where queue is allocated
 int Ptr;    //Pointer to keep track where queue is written
 int Size;  // size of queue array
}queue_t;

typedef enum{
 QUEUE_SUCCESS,
 QUEUE_FULL,
 QUEUE_EMPTY
}queue_ret_n;

queue_ret_n queueInit (queue_t *queue, int *array,int size);
queue_ret_n  queuePush (queue_t *queue,int in);
queue_ret_n  queuePop  (queue_t *queue,int *out);

#endif
