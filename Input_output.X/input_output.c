/*
 * File:   input_output.c
 * Author: Abid
 *
 * Created on 16 July, 2020, 4:04 PM
 */


#include <xc.h>
#include "input_ouput.h"
#define _XTAL_FREQ 4000000
void main(void) {
TRISB0 = 0;
TRISB1 = 0;
TRISB2 = 0;

while(1)
    
{
 // Flash LED1
    RB0 = 1;
   // __delay_ms(1000);
    RB1 = 1;
    //__delay_ms(1000);

}

}
