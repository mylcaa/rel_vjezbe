#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/fcntl.h>
#include <wiringPi.h>

long read_from_driver(char *dev_name) {
	
	char* tmp1, tmp2[10], ch='t';
	char buffer[100];
	int fd = -1, ret;
	if((fd = open(dev_name, O_RDONLY)) < 0)
	{
		perror("GRESKA PRI OTVARANJU!");
		exit(1);
	}	
	
	ret = read(fd, buffer, sizeof(buffer));
	
	if(ret < 0) {
	perror("GRESKA PRI CITANJU!");
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
	
	wiringPiSetup();
	
	pinMode(25, OUTPUT);
	pinMode(21, INPUT);
	pinMode(22, INPUT);
	
	strcpy(dev_name, devname_head);
	strcat(dev_name, argv[1]);
	strcat(dev_name, devname_end);

	
	int taster_pritisnut = 0;
	int r_value = 1;
	int r_value2 = 1;

	while(1) {

	r_value = digitalRead(21);
	r_value2 = digitalRead(22);
	value = read_from_driver(dev_name);
	integer = value / 1000;
	decimal = value % 1000;
	
	printf("Temperatura je %d.%d\n", integer, decimal);	
	
	if(!r_value && !taster_pritisnut) {
		taster_pritisnut = 1;
		prag++;
		printf("Prag je: %d", prag);
	}
	

	if(!r_value2 && !taster_pritisnut) {
		taster_pritisnut = 1;
		prag--;
		printf("Prag je: %d", prag);
	}
	if(r_value && r_value2)taster_pritisnut = 0;

	if(integer > prag) { 
		digitalWrite(25, HIGH);
		delay(200);
		digitalWrite(25, LOW);
		delay(200);
	}
	else digitalWrite(25, LOW);
	}
	return 0;

}
