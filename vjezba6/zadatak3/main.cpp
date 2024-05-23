#include "dialog.h"
//#include <wiringPi.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    wiringPiSetup();
    //pinMode(25, OUTPUT);
    //digitalWrite(25, 0);
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    return a.exec();
}
