/*
 * File:   main.c
 * Author: Mostafa
 *
 * Created on April 9, 2023, 2:08 AM
 */


#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 4000000

void main(void) {
    TRISA&=0b11111100;
    PORTA=0x00;
    TRISB0=1;
    GIE=1;
    INTE=1;
    INTEDG=1;
    while(1){
        RA0=1;
        __delay_ms(1000);
        RA0=0;
        __delay_ms(1000);
    }
    return;
}

void __interrupt() ISR(){
    if(INTF){
        RA1=~RA1;
        INTF=0;
    }
}