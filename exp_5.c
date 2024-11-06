// Experiment 5 -  Interfacing push buttons, Let's, Relay and Buzzer to PIC microcontroller

#include<p18f4550.h>
#include "vector_relocate.h"

void msDelay(unsigned int time);

void main(void) {
    unsigned int i;
    unsigned int val = 0;
    INTCON2bits.RBPU = 0;
    ADCON1 = 0x0F;
    TRISD = 0x00;
    PORTD = 0;
    TRISBbits.TRISB0 = 1;
    TRISBbits.TRISB1 = 1;
    TRISCbits.TRISC0 = 0;
    TRISCbits.TRISC1 = 0;

    PORTCbits.RC1 = 0;
    PORTCbits.RC0 = 0;
    while (1) {
        if(PORTBbits.RB0 == 0) {
            val = 1;
        } 

        if(PORTBbits.RB1 == 0) {
            val = 2;
        }

        if(val == 1){
            PORTCbits.RC1 = 1;
            PORTCbits.RC2 = 1;

            PORTD = 0x80;
            msDelay(100);

            for(int i=0; i<8; i++) {
                PORTD = PORTD >> 1;
                msDelay(100);
            }
        }

        if(val == 2) {
            PORTCbits.RC1 = 0;
            PORTCbits.RC2 = 0;
            PORTD = 0x01;
            msDelay(100);

            for(int i=0; i<8; i++) {
                PORTD = PORT << 1;
                msDelay(100);
            }
        }
    }
    
}