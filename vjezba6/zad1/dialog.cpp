#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    vreme = new QTime(QTime::currentTime());

    timer1 = new QTimer(this);
    timer2 = new QTimer(this);

    connect(timer1, SIGNAL(timeout()), this, SLOT(rtcReadTimeSlot()));
    connect(timer2, SIGNAL(timeout()), this, SLOT(lcdSlot()));

    timer1 -> start(1000);
    timer2 -> start(500);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "HELLO", "update to Windows11?", QMessageBox::Yes | QMessageBox::No);

    if(reply==QMessageBox::Yes){
        qDebug() << "siguran si?";
    }else{
        qDebug() << "normalno da neces";
    }
}

void Dialog::rtcReadTimeSlot()
{
     *vreme = vreme -> addSecs(1);
}

void Dialog::lcdSlot()
{
    QString format = "hh:mm:ss";
    QString str = vreme->toString(format);

    ui->label->setText(str);
}
