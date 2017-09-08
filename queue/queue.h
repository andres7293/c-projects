#ifndef QUEUE_H
#define QUEUE_H

#define QUEUE_SIZE 10

typedef struct{
 int Queue [QUEUE_SIZE];
 int Ptr;
}queue_t;

typedef enum{
 QUEUE_SUCCESS,
 QUEUE_FULL,
 QUEUE_EMPTY
}queue_ret_n;

queue_ret_n queueInit (queue_t *queue);
queue_ret_n  queuePush (queue_t *queue,int in);
queue_ret_n  queuePop  (queue_t *queue,int *out);

#endif
