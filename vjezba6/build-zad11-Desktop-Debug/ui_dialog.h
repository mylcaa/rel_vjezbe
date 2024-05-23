/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *pushButton;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLineEdit *line1;
    QLineEdit *line2;
    QLabel *red1;
    QLabel *red2;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(800, 600);
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(540, 330, 91, 30));
        widget = new QWidget(Dialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(340, 290, 189, 68));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        line1 = new QLineEdit(widget);
        line1->setObjectName(QString::fromUtf8("line1"));
        line1->setMaxLength(16);

        gridLayout->addWidget(line1, 0, 1, 1, 1);

        line2 = new QLineEdit(widget);
        line2->setObjectName(QString::fromUtf8("line2"));
        line2->setMaxLength(16);

        gridLayout->addWidget(line2, 1, 1, 1, 1);

        red1 = new QLabel(widget);
        red1->setObjectName(QString::fromUtf8("red1"));

        gridLayout->addWidget(red1, 0, 0, 1, 1);

        red2 = new QLabel(widget);
        red2->setObjectName(QString::fromUtf8("red2"));

        gridLayout->addWidget(red2, 1, 0, 1, 1);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialog", "Text2LCD", nullptr));
        red1->setText(QCoreApplication::translate("Dialog", "red 1:", nullptr));
        red2->setText(QCoreApplication::translate("Dialog", "red 2:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
