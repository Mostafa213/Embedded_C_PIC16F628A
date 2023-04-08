/*
 * File:   main.c
 * Author: Mostafa
 *
 * Created on April 8, 2023, 4:05 AM
 */


#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 4000000

void main(void) {
    TRISA=0x00;
    PORTA=0x00;
//    TRISB7=1;
    TMR1=0x00;
    T1OSCEN=1;
    nT1SYNC=0;
    TMR1CS=1;
    T1CKPS0=0;
    T1CKPS1=0;
    TMR1ON=1;
    while(1){
        PORTA=TMR1;
    }
    return;
}
