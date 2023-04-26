/*
 * File:   main.c
 * Author: Mostafa
 *
 * Created on April 25, 2023, 12:29 AM
 */


#include <xc.h>
#include <stdint.h>
#include "config.h"
#define _XTAL_FREQ 4000000

void RX_Reciver_Init();

void main(void){
    RX_Reciver_Init();
    TRISA&=0b00000000;
    PORTA=0x00;
    while(1){
        
    }
    return;
}

void RX_Reciver_Init(){
    BRGH = 1; // Set For High-Speed Baud Rate
    SPBRG = 25; // Set The Baud Rate To Be 9600 bps
    // Enable The Ascynchronous Serial Port
    SYNC = 0;
    SPEN = 1;
    // Set The RX-TX Pins to be in UART mode (not io)
    TRISB1=1; // Set TX
    TRISB2=1; // Set RX
    //--[ Enable UART Receiving Interrupts ]--
    RCIE=1; // UART Receving Interrupt Enable Bit
    PEIE=1; // Peripherals Interrupt Enable Bit
    GIE=1; // Global Interrupt Enable Bit
    //------------------
    CREN=1; // Enable Data Continous Reception
}

void __interrupt() ISR(void){
    if (RCIF){
        PORTA=RCREG;    // Read The Received Data Buffer
        RCIF = 0;
    }
}