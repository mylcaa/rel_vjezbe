#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTime>
#include <QTimer>
#include <QMessageBox>
#include <QDebug>
#include <wiringPi.h>

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

public slots:
    void lcdSlot();
    //void alarm();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
