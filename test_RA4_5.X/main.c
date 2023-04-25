/*
 * File:   main.c
 * Author: Mostafa
 *
 * Created on April 25, 2023, 2:00 AM
 */


#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 4000000

void main(void) {
    TRISA&=0b11001111;
    PORTA=0x00;
    while(1){
        RA4=1;
        RA5=1;
        __delay_ms(1000);
        RA4=0;
        RA5=0;
        __delay_ms(1000);
    }
    return;
}
