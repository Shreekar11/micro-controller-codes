// Experiment 8 - Generation of PWM and interfacing DC motor with PIC Microcontroller 

#include<p18f4550.h>

void msDelay(unsigned int time) {
    unsigned int i, j;
    for(i=0; i<time; i++) {
        for(j=0; j<710; j++){

        }
    }
}

void main(void) {
    TRISCbits.TRISC2 = 0;
    TRISD = 0;
    PR2 = 0xBA;
    CCP1CON = 0x0C;
    T2CON = 0x07;
    PORTDbits.RD5 = 1;
    PORTDbits.RD6 = 0;
    while(1) {
        // duty cycle 80%
        CCP1CONbits.DC1B0 = 0;
        CCP1CONbits.DC1B1 = 0;
        CCPR1L = 0x96;
        msDelay(2000);
    }
}