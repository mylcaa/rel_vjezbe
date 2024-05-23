#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{
    lcdClear(lcd_h);

    l1 = ui -> line1 -> text();
    l2 = ui -> line2 -> text();

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
