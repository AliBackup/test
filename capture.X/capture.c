/*
 * File:   capture.c
 * Author: Abid
 *
 * Created on 14 August, 2020, 8:49 PM
 */

#include "config.h"
#define _XTAL_FREQ 4000000
#include <xc.h>

void main(void) 
{
  //--[ Configure The IO Ports ]--
  // Set The Output Port For The Capture Operation (CCPR1 register)
  TRISB = 0x00;
  PORTB = 0x00; // Initial State
  // Set The Output Port For The TMR1 Module (TMR1 register)
  TRISD = 0x00;
  PORTD = 0x00; // Initial State
  //--[ Configure The Timer1 Module To Operate In Counter Mode ]--
  TMR1 = 0;
  T1CKPS0 = 0;
  T1CKPS1 = 0;
  TMR1CS = 1;
  T1OSCEN = 0;// osc disabled( use when  you want to connect a oscilator)
  T1SYNC = 0; // external  clock synchronised
  TMR1ON = 1;
  //--[ Configure The CCP1 Module To Operate in Capture Mode ]--
  CCP1M0 = 1;
  CCP1M1 = 0;
  CCP1M2 = 1;
  CCP1M3 = 0;
  // Enable CCP1 Interrupt
  CCP1IE = 1;
  PEIE = 1;
  GIE = 1;
  // Create The Main Loop Of The System
  while (1)
  {
    // Read & Print Out The TMR1 Counts
    PORTD = TMR1;
  }
  return;
}
// Write The ISR Handler
void __interrupt() ISR()
{
  if (CCP1IF)
  {
    // If Capture Event Occurs, Write the CCPR1 register's value to PORTB
    PORTB = CCPR1;
    CCP1IF = 0;
  }
}