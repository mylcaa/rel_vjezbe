#include "dialog.h"
//#include <wiringPi.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    bcm2835_init();
    bcm2835_i2c_begin();

    bcm2835_i2c_setSlaveAddress(0x51);
    bcm2835_i2c_set_baudrate(10000);
    init();
    //pinMode(25, OUTPUT);
    //digitalWrite(25, 0);
    //lcdPosition(lcd_h, 0, 0);
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    return a.exec();
}
