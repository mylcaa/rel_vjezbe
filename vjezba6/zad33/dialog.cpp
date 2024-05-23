#include "dialog.h"
#include "ui_dialog.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define SEK 0X02
#define MINU 0x03
#define SAT 0x04

#define changetohex(hex) ((((hex)>>4)*10)+((hex)%16))

unsigned char store[3]={0x00, 0x59, 0x08};

unsigned char writebuf[2];
unsigned char readbuf;
unsigned char g[3];

void settime(){

    writebuf[0]= SEK;
    writebuf[1]=g[0];
    bcm2835_i2c_write(writebuf,2);

    writebuf[0]= MINU;
    writebuf[1]=g[1];
    bcm2835_i2c_write(writebuf,2);

    writebuf[0]= SAT;
    writebuf[1]=g[2];
    bcm2835_i2c_write(writebuf,2);
}

void init(){

    unsigned char i;

    for(i=0; i<=3; ++i) g[i]=store[i];

    settime();

    writebuf[0]=0x0;
    writebuf[1]=0x00;
    bcm2835_i2c_write(writebuf,2);

}

void readtime(){

    unsigned char time[7];

    writebuf[0]=SEK;
    bcm2835_i2c_write_read_rs(writebuf,1, time, 7);

    g[0]= time[0]&0x7F;
    g[1]= time[1]&0x7F;
    g[2]= time[2]&0x3F;

    g[0]=changetohex(g[0]);
    g[1]=changetohex(g[1]);
    g[2]=changetohex(g[2]);

}

QString format = "hh:mm:ss";
int i = 1;


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    vreme = new QTime();

    timer = new QTimer(this);

    trenutno2 = new QTime();

    connect(timer, SIGNAL(timeout()), this, SLOT(lcdSlot()));

    timer -> start(1000);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{
    QString str;
    str = ui -> lineEdit -> text();

    *vreme = QTime::fromString(str, "hh:mm:ss");

     if(!(vreme -> isValid())) QMessageBox::warning(this, "Upozorenje", "ne valja!");

     /*lcdClear(lcd_h);

     l1 = ui -> lineEdit -> text();
     l2 = ui -> lineEdit -> text();

     qDebug() << l1;
     qDebug() << l2;

     const char *r1 = l1.toStdString().c_str();
     const char *r2 = l2.toStdString().c_str();

     qDebug() << "r1 " << r1;
     qDebug() << "r2 " << r2;

     lcdPosition(lcd_h, 0, 0);
     lcdPrintf(lcd_h, r1);


     lcdPosition(lcd_h, 0, 1);
     lcdPrintf(lcd_h, r2);

     delay(200);*/

}

void Dialog::lcdSlot()
{
    lcdClear(lcd_h);

    QString time = vreme->toString(format);

    trenutno = QTime::currentTime();

    QString tr = trenutno.toString(format);

    //trenutno2 = trenutno;

    ui->label_3->setText(time);

    //if(trenutno.toString(format) == vreme->toString(format)) {qDebug() << "dosao";
     //digitalWrite(25, 1);
    //}
    qDebug() << trenutno.toString(format);
    qDebug() << vreme->toString(format);

    //lcdPosition(lcd_h, 0, 0);

     const char *r3 = time.toStdString().c_str();

     //lcdPosition(lcd_h, 0, 0);
     lcdPosition(lcd_h, 0, i);
     lcdPuts(lcd_h, r3);

    *vreme = vreme -> addSecs(1);
}

void Dialog::on_radio1_clicked()
{
    lcdClear(lcd_h);
    format = "hh:mm:ss";
}

void Dialog::on_radio2_clicked()
{
    format = "h:m:s a";
}

void Dialog::on_checkBox_clicked()
{

    i = !i;
}
