/*
 * File:   main.c
 * Author: Mostafa
 *
 * Created on April 7, 2023, 4:10 PM
 */


#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 4000000

void main(void) {
//    unsigned char segment[] = {0xFC,0x60,0xDA,0xF2,0x66,0xB6,0xBE,0xE0,0xFE,0xF6},counter=0;     //another connection  'toutorail codex '
    unsigned char segment[]={0b01111110,0b00001100,0b10110110,0b10011110,0b11001100,0b11011010,0b10111110,0b00001110,0b11111110,0b11011110},counter=0;  //my codex
    TRISB=0x00;
    PORTB=0x00;
    while(1){
       PORTB=segment[counter++];
       counter=counter%10;
       __delay_ms(1000);
    }
    return;
}
