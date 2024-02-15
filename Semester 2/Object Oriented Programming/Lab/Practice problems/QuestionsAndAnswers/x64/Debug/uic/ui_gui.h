/********************************************************************************
** Form generated from reading UI file 'gui.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_guiClass
{
public:
    QListWidget *listWidget;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QListWidget *listWidget_2;

    void setupUi(QWidget *guiClass)
    {
        if (guiClass->objectName().isEmpty())
            guiClass->setObjectName("guiClass");
        guiClass->resize(600, 400);
        listWidget = new QListWidget(guiClass);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(40, 40, 256, 192));
        label = new QLabel(guiClass);
        label->setObjectName("label");
        label->setGeometry(QRect(320, 60, 91, 16));
        lineEdit = new QLineEdit(guiClass);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(410, 60, 171, 21));
        pushButton = new QPushButton(guiClass);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(320, 110, 75, 24));
        listWidget_2 = new QListWidget(guiClass);
        listWidget_2->setObjectName("listWidget_2");
        listWidget_2->setGeometry(QRect(310, 140, 251, 181));

        retranslateUi(guiClass);

        QMetaObject::connectSlotsByName(guiClass);
    } // setupUi

    void retranslateUi(QWidget *guiClass)
    {
        guiClass->setWindowTitle(QCoreApplication::translate("guiClass", "gui", nullptr));
        label->setText(QCoreApplication::translate("guiClass", "Enter text for q", nullptr));
        pushButton->setText(QCoreApplication::translate("guiClass", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class guiClass: public Ui_guiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
