#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "../demos/timerLib/libTimer.h"

int main(){
  configureClocks();
  buzzer_init();
  switch_init();
  led_init();
  

  or_sr(0x18);
}
