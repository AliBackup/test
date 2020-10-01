/*
 * File:   lcd.c
 * Author: Abid
 *
 * Created on 13 August, 2020, 8:24 PM
 */


#include "config.h"

#define _XTAL_FREQ 4000000
#include <xc.h>
void init(void);
void cmd(unsigned char a);
void data(char a);
void singlestring(void);
void display(const char *p);


void main() {
    
int i;
int j;
const char a[]="ABID";
init();
cmd(0x01);//clear lcd
cmd(0x02);// return home
cmd(0x0f);//turn on lcd display cursor on blink on
cmd(0x80);//set cursor  position on first line
cmd(0x06);//entry mode cursor will increse
cmd(0x38);//Second line
 singlestring();
__delay_ms(2000);
display(a);

while(1)
{
   if(RC5==1)
{
while(RC5==1);
j++;
if(j%2==1)
{
cmd(0x0f);
}
else
{
cmd(0x08);// Turn off display(DDRAM content is not lost)
}
}
if(RC6==1)
{
while(RC6==1);
data('a');
}
}
  
    
   


}
   


void init(void) {
    TRISD=0x00;
    TRISB=0x00;
    PORTD=0x00;
    PORTB= 0x00;
    TRISC5=1;
    TRISC6=1;
   
   
}

void cmd(unsigned char a)
{
    RD1=0;
    PORTB=a;
    RD0=1;
    __delay_ms(500);
    RD0=0;
   
}

void data(char a)
{
    RD1=1;
    PORTB=a;
    RD0=1;
    __delay_ms(500);
    RD0=0;
   
}

void singlestring(void){
    
cmd(0x18);//left shift
cmd(0x18);
cmd(0x18);
data('W');
data('e');
data('l');
data('c');
data('o');
data('m');
data('e');
data(' ');

cmd(0x1c);// right shift
cmd(0x1c);
cmd(0x1c);


    
    
}
void display(const char *p)
{
    while(*p){
        data(*p);
        p++;
    }    
}