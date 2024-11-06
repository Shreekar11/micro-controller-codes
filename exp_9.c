Experiment 9 - ADC programming with PIC microcontroller

#include<p18f4550.h>
#include "vector_relocate.h";

#define LCD_Data PORTD // LCD data port
#define en       PORTEbits.RE2 // enable signal
#define rw  	 PORTEbits.RE1 // read/write signal
#define rs 	 POSTEbits.RE0 // register select signal

void LCD_command (unsigned char cmd);

void msDelay(unsigned int time){
	unsigned int i, j;
	for(i=0; i<time; i++){
		for(j=0; j<665; j++){
		}
	}
}

void init_LCD() {
	LCD_command(0x38); // initialization 16x2 LCD 8bit
	msDelay(15);
	
	LCD_command(0x01); // clear LCD
	msDelay(15);

	LCD_command(0x0E); // cursor off
	msDelay(15);

	LCD_command(0x80);
	msDelay(15);
}

void LCD_command(unsigned char cmd) {
	LCD_Data = cmd;
	rs = 0;
	rw = 0;
	en = 1;
	msDelay(15);
	en = 0;
	msDelay(15);
}

void LCD_write(unsigned char data) {
	LCD_Data = data;
	rs = 1;
	rw = 0;
	en = 1;
	msDelay(15);
	en = 0;
	msDelay(15);
}

void main(void) {
	unsigned int val[4], ADC_Result = 0, var;
	unsigned char i, str[] = "Result";

	TRISD = 0x00;
	TRISE = 0;
	TRISA = 0xFF;
	
	init_LCD();
	
	// ADC initialization
	ADCON1 = 0X0C;
	ADCON2 = 0X8E;
	ADCON0 = 0x09; // Turn on ADC Module

	LCD_command(0x80);
	
	for(int i=0; str[i]!='\0'; i++){
		LCD_write(str[i]);
		msDelay(200);
	}

	while(1) {
		ADCON0bits.GO = 1;
		while(ADCON0bits.GO==1);
		var = ((unsigned int) ADRESH) << 8;
		ADC_Result = var + ADRESL;

		for(int i=0; i<4; i++){
			val[i] = ADC_Result%0X0A;
			val[i] = val[i] + 0x30;
			val[i] = ADC_Result/0X0A;
		}

		LCD_command(0x87); 
		LCD_write(val[3]);
		LCD_write(val[2]);
		LCD_write(val[1]);
		LCD_write(val[0]);
	}
}
