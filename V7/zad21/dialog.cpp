#include "dialog.h"
#include "ui_dialog.h"
#include <QTimer>
#include <QDial>
#include <stdlib.h>
#include <stdio.h>
#include <QDebug>


const char PCF8591 = 0X48;
int fd;

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);


    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(plocica()));
    timer -> start(1000);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::plocica()
{
    fd = wiringPiI2CSetup(PCF8591);

    //potenciometar - napon

    wiringPiI2CReadReg8(fd, PCF8591 + 3); //dummy
    adcVal = wiringPiI2CReadReg8(fd, PCF8591 + 3);
    qDebug() << "napon: " << adcVal << endl;


    ui -> dial -> setValue(adcVal);

    //osvjetljenje

    wiringPiI2CReadReg8(fd, PCF8591 + 0); //dummy
    adcVal = wiringPiI2CReadReg8(fd, PCF8591 + 0);
    qDebug() << "svjetlo: " << adcVal << endl;

    ui -> verticalSlider -> setValue(255-adcVal);

    //temp

    wiringPiI2CReadReg8(fd, PCF8591 + 1); //dummy
    adcVal = wiringPiI2CReadReg8(fd, PCF8591 + 1);

    ui -> lcdNumber -> display(adcVal);
    qDebug() << "temp: " << adcVal << endl;



}

