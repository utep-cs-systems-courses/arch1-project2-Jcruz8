#include <msp430.h>
#include "stateMachine.h"
#include "switches.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){
  static char blink_count = 0;
  if(++blink_count == 125){
    state_advance();
    blink_count = 0;
  }
}

void __interrupt_vec(PORT2_VECTOR) Port_2(){
  if(P2IFG & SWITCHES){
    P2IFG &= ~SWITCHES;
    switch_interrupt_handler();
  }
}
