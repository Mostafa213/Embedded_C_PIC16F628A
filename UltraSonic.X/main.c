/*
 * File:   main.c
 * Author: Mostafa
 *
 * Created on April 7, 2023, 11:27 PM
 */


#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 4000000

unsigned char distance=0;
float calculate_distance();

void main(void) {
    TRISB4=0;
    TRISB5=1;
    RB4=0;
    TRISA&=0b11110000;
//    TRISA=0x00;
    PORTA=0x00;
    TMR1CS=0;
    T1CKPS0=0;
    T1CKPS1=0;
    while(1){
        distance=calculate_distance()/5;
        switch(distance){
            case 1:{
                PORTA=0b00000001;
                break;
            }
            case 2:{
                PORTA=0b00000011;
                break;
            }
            case 3:{
                PORTA=0b00000111;
                break;
            }
            case 4:{
                PORTA=0b00001111;
                break;
            }
            default: {
                PORTA=0x00;
                break;
            }

        }
    }
    return;
}

float calculate_distance(){
    TMR1=0;
    __delay_us(10);
    RB4=1;
    __delay_us(10);
    RB4=0;
    while(!RB5);
    TMR1ON=1;
    while(RB5);
    TMR1ON=0;
    return TMR1/58.8;
//    return 20;    //testing a case
}
