#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTime>
#include <QTimer>
#include <QMessageBox>
#include <lcd.h>
#include <QDebug>
#include "bcm2835.h"


const int RS = 3;
const int EN = 14;
const int D0 = 4;
const int D1 = 12;
const int D2 = 13;
const int D3 = 6;

//QString format = "hh:mm:ss";

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

    QTime *vreme;
    QTime trenutno;// (QTime::currentTime());
    QTime *trenutno2;
    QTimer *timer;

    QString l1, l2;
    int lcd_h = lcdInit(2, 16, 4, RS, EN, D0, D1, D2, D3, D0, D1, D2, D3);

public slots:
    void lcdSlot();
    //void alarm();

private slots:
    void on_pushButton_clicked();


    void on_radio1_clicked();

    void on_radio2_clicked();

    void on_checkBox_clicked();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
