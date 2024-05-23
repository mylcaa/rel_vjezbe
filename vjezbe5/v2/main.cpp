#include "dialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
     wiringPiSetup();
     softPwmCreate(25, 0, 100);
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    return a.exec();
}
