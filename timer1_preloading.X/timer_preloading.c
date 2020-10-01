/*
 * File:   timer_preloading.c
 * Author: Abid
 *
 * Created on 14 August, 2020, 4:59 PM
 */
// 1 second accurate delay designed by assigning X value as 20.
#include "config.h"
#define _XTAL_FREQ 4000000
#include <xc.h>

unsigned char C = 0; // Global Counter Variable
void main()
{
  // -- [[  IO Configurations ]] --
  TRISB0 = 0;
  RB0 = 0;
  // -- [[ Configure Timer1 To Operate In Timer Mode&nbsp; ]] --
  // Preload The Value Which We've Calculated To The TMR1 16-Bit Register!
  TMR1 = 15535;
  // Choose the local clock source (timer mode)
  TMR1CS = 0;
  // Choose the desired prescaler ratio (1:1)
  T1CKPS0 = 0;
  T1CKPS1 = 0;
  // Event1 = LED ON
  RB0 = 1;
  // Switch ON Timer1 Module!
  TMR1ON = 1;
  // -- [[ Interrupts Configurations ]] --
  TMR1IE = 1; // Timer1 Interrupt Enable Bit
  TMR1IF = 0; // Clear The Interrupt Flag Bit
  PEIE = 1;   // Peripherals Interrupts Enable Bit
  GIE = 1;    // Global Interrupts Enable Bit
  
  while(1)
  {
    // Stay IDLE ,, Timer Interrupt Will Handle Everything For Us !
  }
}
// Interrupt Service Routine - ISR
void __interrupt() ISR ()
{
   // Check The Flag Bit
   if (TMR1IF)
   {
      C++;
      if(C==20)  // Note that we're counting up to 20 timer overflows!
      {
        // Event2 = Toggle LED
        RB0 = ~RB0;
        // Clear The Global Counter
        C = 0;
      }
      // Preload The Value To TMR1 Register Every Overflow Interrupt
      TMR1 = 15535;
      TMR1IF = 0; // Clear The Flag Bit
   }
}
