/*
 * File:   compare.c
 * Author: Abid
 *
 * Created on 14 August, 2020, 9:09 PM
 */


#include "config.h"
#define _XTAL_FREQ 4000000
#include <xc.h>
unsigned char X;
void main(void) 
{
  //--[ Configure The IO Ports ]--
  // Set The Output Pin For The LED
  TRISC4=0;
  RC4=0; // Initially OFF
  //--[ Configure The Timer1 Module To Operate In Timer Mode ]--
  TMR1 = 0;
  T1CKPS0 = 0;
  T1CKPS1 = 0;
  TMR1CS = 0;
  TMR1ON = 1;
  //--[ Configure The CCP1 Module To Operate in Compare Mode ]--
  // Preload The CCPR1 Register
  CCPR1 = 50000;
  // CCP in Compare Mode, CCPx Pin Is Unchanged & Trigger Special Event, resets timer 1 automatically
  CCP1M0 = 1;
  CCP1M1 = 1;
  CCP1M2 = 0;
  CCP1M3 = 1;
  // Enable CCP1 Interrupt
  CCP1IE = 1;
  PEIE = 1;
  GIE = 1;
  // Create The Main Loop Of The System
  while (1)
  {
    // Stay Idle, everything is taken care of in the ISR
  }
  return;
}
// Write The ISR Handler
void __interrupt() ISR()
{
  if ( CCP1IF )
  {
    X++;
    if (X==10)
    {
      // Toggle The LED
      RC4 = ~RC4;
      X = 0;
    }
    // Clear The Interrupt Flag Bit
    CCP1IF = 0;
  }
}