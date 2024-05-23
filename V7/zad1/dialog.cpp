#include "dialog.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ui_dialog.h"
#include <sys/fcntl.h>
#include <QTimer>
#include <QLCDNumber>
#include <QString>


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

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

     timer = new QTimer(this);

     connect(timer, SIGNAL(timeout()), this, SLOT(lcd()));

     timer -> start(1000);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::lcd()
{
    long value;
    char value2[5];
    int temp;
    char dev_name[100] = "/sys/devices/w1_bus_master1/28-00000e723360/w1_slave";

    value = read_from_driver(dev_name);
        temp = value/10000;
        value2[0] = temp+'0';
        value = value-temp*10000;
        temp = value/1000;
        value2[1] = temp+'0';
        value2[2] = '.';
        value = value-temp*1000;
        temp = value / 100;
        value2[3] = temp+'0';
        value = value-temp*100;
        temp = value / 10;
        value2[4] = temp+'0';



        ui -> lcdNumber -> display(QString::fromStdString(value2));



}


