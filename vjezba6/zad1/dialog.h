#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QTime>
#include<QTimer>
#include<QMessageBox>
#include<QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

    int sati=1, minuti=2, sekunde=3, milisekunde=4;
    QTime *vreme;

    QTimer *timer1, *timer2;

public slots:
    void rtcReadTimeSlot();
    void lcdSlot();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
