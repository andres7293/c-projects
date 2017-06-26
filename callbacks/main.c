#include "stdint.h"
#include "stdio.h"
#include "time.h"
#include "stdlib.h"

//struct to store callback data
struct callback_data_t{
  void (*callback)(int x);
  int  return_number;
};

void process(void (*callback)(int num));
void mycallback(int x);
void process2(struct callback_data_t *callback_data);

void main(void)
{ 
  //declare function pointer
  void (*func_ptr)(int x);
  //assign function pointer to our callback function
  func_ptr=mycallback;
  process(func_ptr);
  //another way to do this, is to use directly our callback
  process(mycallback);
  //third way to do this, is use struct to subscribe to callback
  struct callback_data_t callback_data;
  //subscribe to event
  callback_data.callback=mycallback;
  process2(&callback_data);
}


void mycallback(int x)
{
  printf("The result is = %i\n\r",x);
}

void process(void (*callback)(int num))
{
  srand(time(NULL));
  int random = rand() % 50;
  int i,x=0;
  //do whatever processing
  for(i=0;i<random;i++)
  {
    x=i*i*i*2+i*i*4+i*3+78;
  }
  //call callback function
  callback(x);
}

void process2(struct callback_data_t *callback_data)
{
  srand(time(NULL));
  int random = rand() % 50;
  int i,x=0;
  //do whatever processing
  for(i=0;i<random;i++)
  {
    x=i*i*i*2+i*i*4+i*3+78;
  }
  //call callback function
  //look struct 
  if(callback_data->callback != NULL){
     (callback_data->callback)(x);
  }
}
