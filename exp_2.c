// Experiment 2 - LED chasing and blinking using 8051

#include<reg51.h>

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

// flashing / blinking
void main(void) {
    while(1) {
        P1 = 0x55;
        msdelay(100);

        P1 = 0xAA;
        msdelay(100);
    }
}

// right chasing
void main(void) {
    P1 = 0x80;
    unsigned int i;
    for(i = 0; i<8; i++) {
        P1 = P1 >> 1;
        msdelay(100);
    }

    // left chasing
    P1 = 0x01;
    unsigned int i;
    for(i = 0; i<8; i++) {
        P1 = P1 << 1;
        msdelay(100);
    }
}

// ascii values a to z
void main(void) {
    while(1){
        unsigned int z;
        for(z='A'; z<='Z'; z++) {
            msdelay(100);
            P1 = z;
        }
    }
}

// hex values
void main(void) {
    while(1){
        unsigned int z;
        for(z=0; z<=255; z++) {
            msdelay(100);
            P1 = z;
        }
    }
}
