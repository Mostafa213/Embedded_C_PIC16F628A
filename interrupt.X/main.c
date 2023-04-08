/*
 * File:   main.c
 * Author: Mostafa
 *
 * Created on April 7, 2023, 9:05 PM
 */


#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 4000000

unsigned char counter=0;

void main(void) {
    TRISB0=0;
    RB0=1;
    TMR1IE=1;
    PEIE=1;
    GIE=1;
    TMR1=15536;
    TMR1CS=0;
    T1CKPS0=0;
    T1CKPS1=0;
    TMR1ON=1;
    while(1){
        
    }
    
    return;
}


void __interrupt() ISR(){
    if(TMR1IF){
        counter++;
        if(counter==20){
            RB0=~RB0;
            counter=0;
        }
        TMR1=15536;
        TMR1IF=0;
    }
}