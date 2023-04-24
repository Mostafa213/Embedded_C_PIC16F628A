/*
 * File:   main.c
 * Author: Mostafa
 *
 * Created on April 23, 2023, 11:13 PM
 */


#include <xc.h>
#include <stdint.h>
#include "config.h"
#define _XTAL_FREQ 4000000
#define Re RB7
#define Ze RB6
#define Fif RB5
#define SeFi RB4
#define On RB2

uint16_t Duty=0;
void Set_Duty();
void main(void) {
    TRISB=0b11110100;
    RB0=1;
    RB1=0;
    RB3=0;
    CCP1M2=1;
    CCP1M3=1;
    PR2=124;    //PWM Frequancy = 2K
    T2CKPS0=1;  //prescaler =4
    T2CKPS1=0;  //prescaler = 4
    TMR2ON=1;
    while(1){
        if(Re){
            RB0=~RB0;
            RB1=~RB1;
        }
        if(Ze){
            Duty=0;
            Set_Duty();
        }
        if(Fif){
            Duty=250;
            Set_Duty();
        }
        if(SeFi){
            Duty=350;
            Set_Duty();
        }
        if(On){
            Duty=500;
            Set_Duty();
        }
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