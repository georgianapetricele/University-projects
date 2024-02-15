/********************************************************************************
** Form generated from reading UI file 'Gui.ui'
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
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GuiClass
{
public:
    QLineEdit *lineEdit;
    QLabel *label;
    QListWidget *listWidget;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton;
    QListWidget *listWidget_2;
    QSlider *verticalSlider;

    void setupUi(QWidget *GuiClass)
    {
        if (GuiClass->objectName().isEmpty())
            GuiClass->setObjectName("GuiClass");
        GuiClass->resize(600, 472);
        lineEdit = new QLineEdit(GuiClass);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(120, 40, 241, 21));
        label = new QLabel(GuiClass);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 40, 71, 16));
        listWidget = new QListWidget(GuiClass);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(20, 80, 256, 192));
        lineEdit_2 = new QLineEdit(GuiClass);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(340, 90, 113, 21));
        lineEdit_3 = new QLineEdit(GuiClass);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(340, 130, 113, 21));
        lineEdit_4 = new QLineEdit(GuiClass);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(340, 170, 113, 21));
        label_2 = new QLabel(GuiClass);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(280, 90, 49, 16));
        label_3 = new QLabel(GuiClass);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(280, 130, 49, 16));
        label_4 = new QLabel(GuiClass);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(280, 170, 49, 16));
        pushButton = new QPushButton(GuiClass);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(490, 90, 75, 24));
        listWidget_2 = new QListWidget(GuiClass);
        listWidget_2->setObjectName("listWidget_2");
        listWidget_2->setGeometry(QRect(20, 290, 221, 151));
        verticalSlider = new QSlider(GuiClass);
        verticalSlider->setObjectName("verticalSlider");
        verticalSlider->setGeometry(QRect(260, 290, 18, 160));
        verticalSlider->setOrientation(Qt::Vertical);

        retranslateUi(GuiClass);

        QMetaObject::connectSlotsByName(GuiClass);
    } // setupUi

    void retranslateUi(QWidget *GuiClass)
    {
        GuiClass->setWindowTitle(QCoreApplication::translate("GuiClass", "Gui", nullptr));
        label->setText(QCoreApplication::translate("GuiClass", "Driver's info", nullptr));
        label_2->setText(QCoreApplication::translate("GuiClass", "Description", nullptr));
        label_3->setText(QCoreApplication::translate("GuiClass", "Longitude", nullptr));
        label_4->setText(QCoreApplication::translate("GuiClass", "Latitude", nullptr));
        pushButton->setText(QCoreApplication::translate("GuiClass", "Add report", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GuiClass: public Ui_GuiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
