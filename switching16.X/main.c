/*
 * File:   main.c
 * Author: Mostafa
 *
 * Created on April 23, 2023, 6:04 AM
 */


#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 4000000

void main(void) {
    TRISB0=0;
    while(1){
        RB0=1;
        __delay_ms(1000);
        RB0=0;
        __delay_ms(1000);
    }
    return;
}
