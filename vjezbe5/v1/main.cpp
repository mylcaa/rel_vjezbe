#include "dialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    wiringPiSetup();
    pinMode(25, OUTPUT);
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    return a.exec();
}
