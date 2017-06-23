#include "stdio.h"
#include "stdint.h"

typedef enum{
 IDLE,
 ON,
 OFF
}state_n;

void print_state(state_n state);

void main(void)
{
  state_n state;
  state=ON;
  print_state(state);
}

void print_state(state_n state)
{
  switch(state){
    case ON:
      printf("State = ON\n\r");
      break;
    case OFF:
      printf("State = OFF\n\r");
      break;
    case IDLE:
      printf("State = Idle\n\r");
      break;
  }
}

