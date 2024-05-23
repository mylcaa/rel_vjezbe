#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    slika2 = new QPixmap(":/new/slike/off.jpg");
    slika1 = new QPixmap(":/new/slike/on.jpg");
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked(bool checked)
{
    if(checked) {ui -> label -> setPixmap(*slika1);}
    else {ui -> label -> setPixmap(*slika2);}
}
