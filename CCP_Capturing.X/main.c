/*
 * File:   main.c
 * Author: Mostafa
 *
 * Created on April 18, 2023, 5:10 PM
 */


#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 4000000
void main(void) {
    TRISA=0x00;
    PORTA=0x00;
    GIE=1;
    PEIE=1;
    CCP1IE=1;
    //timer 1 configurations
    TMR1=0;
    T1CKPS0=0;
    T1OSCEN=1;
    nT1SYNC=0;
    T1CKPS0=0;
    T1CKPS1=0;
    TMR1ON=1;
    CCP1M0=1;
    CCP1M1=0;
    CCP1M2=1;
    CCP1M3=0;
    while(1){
//        PORTA=TMR1;
    }
    return;
}

void __interrupt() ISR(){
    if(CCP1IF){
        PORTA=CCPR1;
        CCP1IF=0;
    }
}