/*
 * File:   main.c
 * Author: Mostafa
 *
 * Created on April 23, 2023, 2:54 AM
 */


#include <xc.h>
#include <stdint.h>
#include "config.h"
#define _XTAL_FREQ 4000000

uint16_t Duty=0;
void Set_Duty();
void main(void) {
    CCP1M2=1;
    CCP1M3=1;
    TRISB3=0;
    PR2=124;    //PWM Frequancy = 2K
    T2CKPS0=1;  //prescaler =4
    T2CKPS1=0;  //prescaler = 4
    TMR2ON=1;
    while(1){
        Duty=0;
        while(Duty<500){
            Set_Duty();
            Duty++;
            __delay_ms(2);
        }
        __delay_ms(100);
        while(Duty>0){
            Set_Duty();
            Duty--;
            __delay_ms(2);
        }
        __delay_ms(100);
    }
    return;
}

void Set_Duty(){
    if(Duty<1024){
        CCP1Y=Duty&1;
        CCP1X=Duty&2;
        CCPR1L=Duty>>2;
    }
}