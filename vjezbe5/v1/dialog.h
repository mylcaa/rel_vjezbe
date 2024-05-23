#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
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

    int n=0;

private slots:
    void on_pushButton_clicked(bool checked);

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
