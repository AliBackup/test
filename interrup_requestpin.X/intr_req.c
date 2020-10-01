/*
 * File:   intr_req.c
 * Author: Abid
 *
 * Created on 14 August, 2020, 6:30 PM
 */

#include "config.h"
#define _XTAL_FREQ 4000000
#include <xc.h>


void main(void) 
{
  //--[ Configure The IO pins ]--
  TRISC1 = 0;
  TRISC2 = 0;
  // Set The LEDs To Be Initially Off
  RC1 = 0;
  RC2 = 0;
  // Set The GPIO Pin RB1 To Be Input Pin
  TRISB1 = 1;
  //--[ Configure The RB0 IRQ Interrupt ]--
  INTEDG = 0;
  INTE = 1;
  GIE = 1;
  // Create The Main loop
  while(1)
  {
    // Green LED Blinking Routine
    RC2 = 1;
    __delay_ms(1000);
    RC2 = 0;
    __delay_ms(1000);
    // Check For The RB1 Button (Polling)
    if (RB1)
    {
      // Toggle The Yellow LED
      RC1 = ~ RC1;
    }
  }
  return;
}
//--[ The ISR Handler ]--
void __interrupt() ISR()
{
  if(INTF)
  {
    // Toggle The Yellow LED
    RC1 = ~ RC1;
    INTF = 0;
  }
}