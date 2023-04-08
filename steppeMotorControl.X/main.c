/*
 * File:   main.c
 * Author: Mostafa
 *
 * Created on April 7, 2023, 5:42 PM
 */


#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 4000000

void main(void) {
    unsigned char count=0;
    TRISB&=0b11110000;
//    PORTB=0x01;
    while(1){
        for(unsigned char j=0;j<48;j++){
            PORTB=1<<count++;
            count%=4;
            __delay_ms(50);
        }
        __delay_ms(1000);
        for(unsigned char j=0;j<48;j++){
            PORTB=8>>count++;
            count%=4;
            __delay_ms(50);
        }
    }
    return;
}
