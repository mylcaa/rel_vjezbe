// lcd1602.c
// kompajlirati sa -lwiringPi -lwiringPiDev
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <stdlib.h>
#include <lcd.h>
// dodela vrednosti za konkretne pinove
// prema gornjoj tabeli i semi DVK512
const int RS = 3;
const int EN = 14;
const int D0 = 4;
const int D1 = 12;
const int D2 = 13;
const int D3 = 6;
const char PCF8591 = 0x48; // adresa
int fd, adcVal;

float dac(int vr) {
	float calculated;
	calculated = (float)vr * 3.3/255;
	return calculated;
}

void dec2string(char *string, float val) {
	char temp;
	val = val * 10;
	temp = val / 10 + '0';
	string[0] = temp;
	temp = (int)val % 10 + '0';
	string[2] = temp;
	string[1] = ',';
	string[3] = 'V';
	string[4] = 0;

}

int main(){
	int lcd_h;
	if (wiringPiSetup() < 0){
		 fprintf (stderr, "Greška pri inicijalizaciji:, %s\n", strerror (errno)) ;
		 return 1 ;
	}
	lcd_h = lcdInit(2, 16, 4, RS, EN, D0, D1, D2,
	D3, D0, D1, D2, D3);
	fd = wiringPiI2CSetup(PCF8591);
	char napon[5];
	float value;

	while (1) {
		 // procitaj trimer pot sa AIN3 ulaza
		 wiringPiI2CReadReg8(fd, PCF8591 + 0) ; // dummy
		 adcVal = wiringPiI2CReadReg8(fd, PCF8591 + 0) ;
		 value = dac(adcVal);
		 dec2string(napon, value);
		 lcdPosition(lcd_h, 0, 0);
		 printf("Pot ADC vrednost = %d ", adcVal);

		 if (value <= 1) {
			 lcdPrintf(lcd_h, "DAN ");
		 }
		 else if (value <= 2.5) {	
			 lcdPrintf(lcd_h, "SLABO");
		 }
		 else {
		 	lcdPrintf(lcd_h, "NOC");
		}

		 //printf("Pot ADC vrednost = %f ", value);
		 // upisi tu vrednost u DAC reg, 0x04
		 //wiringPiI2CWriteReg8 (fd, PCF8591 + 4, adcVal) ;
		 // procitaj DAC preko AIN2
		 //wiringPiI2CReadReg8(fd, PCF8591 + 2) ; // dummy
		 //adcVal = wiringPiI2CReadReg8(fd, PCF8591 + 2);
		 //printf("DAC vrednost = %d \n\n" , adcVal);
		 delay(2000);
	         lcdClear(lcd_h);	
 	 }
	//lcdPosition(lcd_h, 0,0);
	//lcdPrintf(lcd_h,"Displej sa 16 ch");
	//lcdPosition(lcd_h, 0,1);
	//lcdPrintf(lcd_h, "u 2 reda");
	//delay(2000);
	//lcdClear(lcd_h);
}


