/*
 * File:   main.c
 * Author: Mostafa
 *
 * Created on April 24, 2023, 11:58 PM
 */


#include <xc.h>
#include <stdint.h>
#include "config.h"
#define _XTAL_FREQ 4000000
#define UP RB0
#define Down RB3
#define Send RB4
//#define Swap RB5

void TX_Sender_Init();
void UART_Write(uint8_t);

void main(void) {
    TX_Sender_Init();
    TRISA&=0b00000000;
    PORTA=0x00;
//    TRISB|=0b00111001;  //for Swap Button
    TRISB|=0b00011001;
    uint8_t Data = 0;
    while(1){
        if(UP){
            Data++;
            __delay_ms(250);
        }
        if(Down){
            Data--;
            __delay_ms(250);
        }
//        if(Swap){
//            //swap the pos
//        }
        if(Send){
            UART_Write(Data);
            __delay_ms(250);
        }
        PORTA = Data; // Display The Current Data Value @ PORTD
    }
    return;
}

void TX_Sender_Init(){
    BRGH = 1;   // Set For High-Speed Baud Rate
    SPBRG = 25; // Set The Baud Rate To Be 9600 bps
    SYNC = 0;
    SPEN = 1;
    TRISB1=1;  // Set TX
    TRISB2=1;  // Set RX
    TXEN=1; // Enable UART Transmission
}

void UART_Write(uint8_t data){
    while(!TRMT);
    TXREG = data;
}
