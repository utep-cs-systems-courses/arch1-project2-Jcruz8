#include <msp430.h>
#include "led.h"
#include "buzzer.h"
#include "switches.h"

char state1_lights(){
  green_on = 1;
  red_on = 1;
  return 1;
}

char state2_sounds(){
  buzzer_set_period(1000);
  return 1;
}

void state_advance(){
  char changed = 0;

  switch(currentState){
  case 1: changed = state1_lights(); break;
  case 2: changed = state2_sounds(); break;
  }
  led_changed = changed;
  led_update();
}
