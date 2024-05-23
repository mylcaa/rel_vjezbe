#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <wiringPiI2C.h>
#include<wiringPi.h>


QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

     QTimer *timer;
     int adcVal;

private slots:
    void plocica();


private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
