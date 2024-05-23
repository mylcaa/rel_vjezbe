#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    vreme = new QTime();

    timer = new QTimer(this);

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
}

void Dialog::lcdSlot()
{
    QString format = "hh:mm:ss";
    QString time = vreme->toString(format);

    ui->label_3->setText(time);

    *vreme = vreme -> addSecs(1);
}

