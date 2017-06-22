#include "stdio.h"
#include "led.h"

typedef enum{
  evt_any,
  evt_none,
  evt_button_pushed,
  evt_timeout,
}event_t;

typedef enum{
  state_init,
  state_idle,
  state_led_on,
  state_led_off,
}state_t;

typedef struct{
  state_t current_state;
  event_t event;
  state_t next_state;
}transition_t;

typedef struct{
  char *name;
  void (*function)(void);
}function_t;

int main(void)
{
  //init transition table
  transition_t transition[]=
  {
    //current state     //events            //next state
    {state_init,       evt_any              state_idle   },
    {state_idle,       evt_button_pushed,   state_led_on },
    {state_led_on,     evt_timeout,         state_led_off},
    {state_led_off,    evt_button_pushed,   state_idle   },
    {state_idle,       evt_timeout,         state_led_on },
    {state_led_on,     evt_button_pushed,   state_idle   }
  };

  //init function table
  function_t functions[]{
    {"led_idle", &led_init},
    {"led_init", &led_init},
    {"led_on",   &led_on},
    {"led_off",  &led_off}
  };

  
  return 0;
}
