/*
 * File:   main.c
 * Author: Mostafa
 *
 * Created on April 25, 2023, 4:31 AM
 */


#include <xc.h>
#include <stdint.h>
#include "config.h"
#define _XTAL_FREQ 4000000
#define UP RB0
#define Down RB3
#define Send RB4

void TX_RX_Init();
void UART_Write(uint8_t);
uint8_t Data = 0;

void main(void) {
    TX_RX_Init();
    TRISA&=0b00000000;
    PORTA=0x00;
    TRISB|=0b00011001;
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

void __interrupt() ISR(void){
    if (RCIF){
        Data=RCREG;    // Read The Received Data Buffer
        RCIF = 0;
    }
}

//Send Data
void TX_RX_Init(){
    BRGH = 1;   // Set For High-Speed Baud Rate
    SPBRG = 25; // Set The Baud Rate To Be 9600 bps
    SYNC = 0;
    SPEN = 1;
    TRISB1=1;  // Set TX
    TRISB2=1;  // Set RX
    TXEN=1; // Enable UART Transmission
    RCIE=1; // UART Receving Interrupt Enable Bit
    PEIE=1; // Peripherals Interrupt Enable Bit
    GIE=1; // Global Interrupt Enable Bit
    CREN=1; // Enable Data Continous Reception
}

void UART_Write(uint8_t data){
    while(!TRMT);
    TXREG = data;
}
