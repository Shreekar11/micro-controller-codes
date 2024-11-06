// Experiment 7 - LCD interfacing with PIC 18F4550

#include <p18f4550.h>
#include "vector_relocate.h"

#define LCD_Data PORTD // LCD data to PORTD
#define ctrl PORTE
#define en PORTEbits.RE2 // enable signal
#define rw PORTEbits.RE1 // read/write signal
#define rs POSTEbits.R0  // register select signal

void init_LCD();
void LCD_command(unsigned char cmd);
void LCD_write(unsigned char data);

void init_LCD()
{
    LCD_command(0x38);
    msDelay(15);

    LCD_command(0x01);
    msDelay(15);

    LCD_command(0x0E);
    msDelay(15);

    LCD_command(0x80);
    msDelay(15);
}

void LCD_command(unsigned char cmd)
{
    LCD_Data = cmd;
    rs = 0;
    rw = 0;
    en = 1;
    msDelay(15);
    en = 0;
    msDelay(15);
}

void LCD_write(unsigned char data)
{
    LCD_Data = data;
    rs = 1;
    rw = 0;
    en = 1;
    msDelay(15);
    en = 0;
    msDelay(15);
}

void main(void)
{
    char var1[] = "PICT";
    char var2[] = "COLLEGE";

    TRISD = 0x00;
    TRISE = 0x00;
    ADCON1 = 0x0F; // Configuring the PORTE pins as digital I/O

    init_LCD();
    msDelay(50);

    int i = 0;
    while (val1[i] != '\0')
    {
        LCD_write(str[i]);
        i++;
    }

    LCD_command(0xC0);

    int j = 0;
    while (val2[j] != '\0')
    {
        LCD_write(str[j]);
        j++;
    }

    while (1)
        ;
}

void msdelay(unsigned int time) // Function to generate delay
{
    unsigned int i, j;
    for (i = 0; i < time; i++)
    {
        for (j = 0; j < 710; j++)
        {
        }
    }
}; // Calibrated for a 1 ms delay in MPLAB }
