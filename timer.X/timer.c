/*
 * File:   timer.c
 * Author: Abid
 *
 * Created on 13 August, 2020, 9:26 PM
 */


#include <xc.h>
#include "config.h"

#define _XTAL_FREQ 4000000
#include <xc.h>
unsigned char C;

void main(void) {
    TRISB0=0;
 // -- [[ Configure Timer1 To Operate In Timer Mode&nbsp; ]] --
  // Clear The Timer1 Register. To start counting from 0
  TMR1 = 0;
  // Choose the local clock source (timer mode)
  TMR1CS = 0;
  // Choose the desired prescaler ratio (1:1)
  T1CKPS0 = 0;
  T1CKPS1 = 0;
  // Event1 = LED ON
  RB0 = 1;
  // Switch ON Timer1 Module!
  
  // -- [[ Interrupts Configurations ]] --
  TMR1IE = 1; // Timer1 Interrupt Enable Bit
  TMR1IF = 0; // Clear The Interrupt Flag Bit
  PEIE = 1;   // Peripherals Interrupts Enable Bit
  GIE = 1;    // Global Interrupts Enable Bit
  TMR1ON = 1;
while(1){
    
    
}
}

void __interrupt() ISR(void){
    
     if (TMR1IF)
   {
      C++;
      if(C==15)
      {
        // Event2 = Toggle LED
        RB0 = ~RB0;
        // Clear The Global Counter
        C = 0;
      }
      TMR1IF = 0; // Clear The Flag Bit
   }
}