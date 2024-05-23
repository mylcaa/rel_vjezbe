#include "dialog.h"
#include "ui_dialog.h"

//QString format = "hh:mm:ss";

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

     lcdClear(lcd_h);

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

     delay(200);

}

void Dialog::lcdSlot()
{
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

    lcdPosition(lcd_h, 0, 0);

     const char *r3 = time.toStdString().c_str();

     lcdPosition(lcd_h, 0, 0);
     lcdPuts(lcd_h, r3);

    *vreme = vreme -> addSecs(1);
}

void Dialog::on_radio1_clicked()
{
    format = "hh:mm:ss";
}

void Dialog::on_radio2_clicked()
{
    format = "h:m:s a";
}
