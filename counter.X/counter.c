/*
 * File:   counter.c
 * Author: Abid
 *
 * Created on 14 August, 2020, 5:12 PM
 */

//counter toggle led every 2 clicks
#include "config.h"
#define _XTAL_FREQ 4000000
#include <xc.h>


void main(void) {
    TRISB1=0;
 // -- [[ Configure Timer1 To Operate In Timer Mode&nbsp; ]] --
  // Clear The Timer1 Register. To start counting from 0
  TMR1 = 65534;
  // Choose the external     clock source (timer mode)
  TMR1CS = 1;
  T1SYNC=1;
  //T1OSCEN=1;
  // Choose the desired prescaler ratio (1:1)
  T1CKPS0 = 0;
  T1CKPS1 = 0;
  // Event1 = LED ON
  RB1 = 0;

  
  // -- [[ Interrupts Configurations ]] --
  TMR1IE = 1; // Timer1 Interrupt Enable Bit
  TMR1IF = 0; // Clear The Interrupt Flag Bit
  PEIE = 1;   // Peripherals Interrupts Enable Bit
  GIE = 1;    // Global Interrupts Enable Bit
    // Switch ON Timer1 Module!
 TMR1ON = 1;
while(1){
    
    
}
}

void __interrupt() ISR(void){
    
     if (TMR1IF)
   {
     
        // Event2 = Toggle LED
        RB1 = ~RB1;
        // Clear The Global Counter
        
      }
       TMR1IF = 0;// Clear The Flag Bit
       TMR1=65534;
       
   
}
