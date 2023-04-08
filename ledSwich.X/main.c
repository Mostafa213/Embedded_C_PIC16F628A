/*
 * File:   main.c
 * Author: Mostafa
 *
 * Created on April 6, 2023, 6:13 PM
 */


#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 4000000

void main(void) {
    TRISBbits.TRISB0=1;
    TRISBbits.TRISB1=0;
    PORTBbits.RB1=0;
    while(1){
        while(PORTBbits.RB0){
            PORTBbits.RB1=1;
            __delay_ms(250);
            PORTBbits.RB1=0;
            __delay_ms(250);
        }
    }
    return;
}
