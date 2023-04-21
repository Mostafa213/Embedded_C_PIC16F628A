/*
 * File:   main.c
 * Author: Mostafa
 *
 * Created on April 18, 2023, 11:06 PM
 */


#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 4000000

unsigned char counter=0;
void main(void) {
    TRISB6=0;
    RB6=0;
    TMR1=0;
    //Timer 1 configrations
    T1CKPS0=0;  //Prescaler pin0
    T1CKPS1=0;  //Prescaler pin1
    TMR1CS=0;   //choosing internal clock sours by setting this pin by 0
    TMR1ON=1;   //make TMR1 work
    
    CCPR1=50000;    //setting the value we want to compare
    //set the configrations of CCP1 to be in compare mode
    CCP1M0=1;
    CCP1M1=1;
    CCP1M2=0;
    CCP1M3=1;
    //set interrupts
    GIE=1;
    PEIE=1;
    CCP1IE=1;
    while(1){
        
    }
    return;
}

void __interrupt() ISR(){
    if(CCP1IF&&counter++==9){
        RB6=~RB6;
    }
    CCP1IF=0;
    counter%=10;
}