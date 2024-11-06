// Experiment 4 - Stepper motor exp

#include<reg51.h>

void msDelay(unsigned int time);

void main(void) {
    while(1) {
        // infinite loop CW
        P1 = 0x06;
        msDelay(1000);

        P1 = 0x0C;
        msDelay(1000);

        P1 = 0x09;
        msDelay(1000);

        P1 = 0x03;
        msDelay(1000);
    }
}

void main(void) {
    while(1) {
        // infinite loop Anti-CW
        P1 = 0x03;
        msDelay(1000);

        P1 = 0x09;
        msDelay(1000);

        P1 = 0x0C;
        msDelay(1000);

        P1 = 0x06;
        msDelay(1000);
    }
}

void main(void) {
    // 90 degree CW
    unsigned int i;
    for(i=0; i<3; i++) {
        P1 = 0x06;
        msDelay(1000);

        P1 = 0x0C;
        msDelay(1000);

        P1 = 0x09;
        msDelay(1000);

        P1 = 0x03;
        msDelay(1000);
    }
}

void main(void) {
    // 90 degree Anti-CW
    unsigned int i;
    for (i=0; i<3; i++) {
        P1 = 0x03;
        msDelay(1000);

        P1 = 0x09;
        msDelay(1000);

        P1 = 0x0C;
        msDelay(1000);

        P1 = 0x06;
        msDelay(1000);
    }
}

void msdelay(unsigned int time) // Function to generate delay
{
    unsigned int i, j;
    for (i = 0; i < time; i++)
    {
        for (j = 0; j < 1275; j++)
        {
        }
    }
}; // Calibrated for a 1 ms delay in MPLAB }