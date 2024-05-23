#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/fcntl.h>
#include <wiringPi.h>
#include <lcd.h>

const int RS = 3;
const int EN = 14;
const int D0 = 4;
const int D1 = 12;
const int D2 = 13;
const int D3 = 6;
//char* tmp1, tmp2[10], ch='t';


long read_from_driver(char *dev_name) {
	
	char* tmp1, tmp2[10], ch='t';
	char buffer[100];
	int fd = -1, ret;
	if((fd = open(dev_name, O_RDONLY)) < 0)
	{
		perror("Greska pri otvaranju!");
		exit(1);
	}	
	
	ret = read(fd, buffer, sizeof(buffer));
	
	if(ret < 0) {
	perror("Greska pri citanju!"); 
	exit(1);	
	}
	
	tmp1 = strchr(buffer, ch);
	sscanf(tmp1, "t=%s", tmp2);
	close(fd);
	return atoi(tmp2);
}


int main(int argc, char *argv[]) {

	char devname_head[50] = "/sys/devices/w1_bus_master1/28-00000";
	char devname_end[10] = "/w1_slave";
	char dev_name[100];
	long value;
	int integer, decimal;
	int i, j;
	int prag = 24;
	int lcd_h;
	
	wiringPiSetup();

	lcd_h = lcdInit(2, 16, 4, RS, EN, D0, D1, D2, D3, D0, D1, D2, D3);
	
	
	
	strcpy(dev_name, devname_head);
	strcat(dev_name, argv[1]);
	strcat(dev_name, devname_end);

	char value2[5];
	int temp;

	while(1) {
		
	value = read_from_driver(dev_name);
	temp = value/10000;
	value2[0] = temp + '0';
	value = value-temp*10000;
	temp = value/1000;
	value2[1] = temp + '0';
	value2[2] = '.';
	value = value-temp*1000;
	temp = value / 100;
	value2[3] = temp + '0';
	//value2[3] = value/10000 + '0';
	
	lcdPosition(lcd_h, 0, 0);
	lcdPrintf(lcd_h, value2);
	delay(2000);
	

	}
	return 0;

}
