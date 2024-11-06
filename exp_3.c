// Experiment 3 - Square, triangular and sine wave

#include <reg51.h>

// square wave
void main(void)
{
    P1 = 0x00;
    while (1)
    {
        P1 = 0x55;
        msdelay(500);

        P1 = 0xAA;
        msdelay(500);
    }
}

// triangular wave
void main(void)
{
    while (1)
    {
        unsigned int x, y;
        for (x = 0; x <= 255; x++)
        {
            msdelay(500);
            P1 = x;
        }

        for (y = 255; y >= 0; y--)
        {
            msdelay(500);
            P1 = y;
        }
    }
}

// sine wave
void main(void)
{
    unsigned int x;
    unsigned int val[12] = {128, 192, 238, 255, 238, 192, 128, 64, 17, 0, 17, 64};
    while (1)
    {
        for (x = 0; x < 12; x++)
        {
            msdelay(500);
            P1 = val[x];
        }
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