/*
 * File:   main.c
 * Author: Mostafa
 *
 * Created on April 24, 2023, 3:03 AM
 */


#include <xc.h>
#include <stdint.h>
#include "config.h"
#define _XTAL_FREQ 4000000
#define Read RB0 // Read EEPROM Memory Blocks
#define W_3  RB1 // Write 0x03
#define W_5  RB2 // Write 0x05
#define W_7  RB3 // Write 0x07

void EEPROM_Write(uint8_t, uint8_t);
uint8_t EEPROM_Read(uint8_t);

void main(void) {
    TRISB|=0b00001111;
    TRISA&=0b11110000;
    PORTA=0x00;
    uint8_t Address=0;
    while(1){
        if(W_3) // Write 0x03
        {
            EEPROM_Write(Address++, 3);
            __delay_ms(500);
        }
        if(W_5) // Write 0x05
        {
            EEPROM_Write(Address++, 5);
            __delay_ms(500);
        }
        if(W_7) // Write 0x07
        {
            EEPROM_Write(Address++, 7);
            __delay_ms(500);
        }
        if(Address == 3)
            Address = 0;
        if(Read)
        {
        // Read The EEPROM Data Out To PORTD LEDs
        for (uint8_t i=0; i<3; i++)
        {
            PORTA = EEPROM_Read(i);
            __delay_ms(1000);
         }
        }
    }
    return;
}

/////////////////////////////////////

void EEPROM_Write(uint8_t Address, uint8_t Data){
    while(EECON1bits.WR);  // Waits Until Last Attempt To Write Is Finished
    EEADR = Address;       // Writes The Addres To Which We'll Wite Our Data
    EEDATA = Data;         // Write The Data To Be Saved
//    EECON1bits.EEPGD = 0;  // Cleared To Point To EEPROM Not The Program Memory
    EECON1bits.WREN = 1;   // Enable The Operation !
    INTCONbits.GIE = 0;    // Disable All Interrupts Untill Writting Data Is Done
    EECON2 = 0x55;         // Part Of Writing Mechanism..
    EECON2 = 0xAA;         // Part Of Writing Mechanism..
    EECON1bits.WR = 1;     // Part Of Writing Mechanism..
    INTCONbits.GIE = 1;    // Re-Enable Interrupts
    EECON1bits.WREN = 0;   // Disable The Operation
    EECON1bits.WR = 0;     // Ready For Next Writting Operation
}

  
  
  
  
  ////////////////////////////////
  
uint8_t EEPROM_Read(uint8_t Address){
    uint8_t Data;
    EEADR = Address;       // Write The Address From Which We Wonna Get Data
//    EECON1bits.EEPGD = 0;  // Cleared To Point To EEPROM Not The Program Memory
    EECON1bits.RD = 1;     // Start The Read Operation
    Data = EEDATA;         // Read The Data
    return Data;
    
}