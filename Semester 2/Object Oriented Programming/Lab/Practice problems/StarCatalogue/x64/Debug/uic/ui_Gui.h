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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GuiClass
{
public:
    QTableView *tableView;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLabel *label_4;
    QSpinBox *spinBox;
    QCheckBox *checkBox;

    void setupUi(QWidget *GuiClass)
    {
        if (GuiClass->objectName().isEmpty())
            GuiClass->setObjectName("GuiClass");
        GuiClass->resize(709, 400);
        tableView = new QTableView(GuiClass);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(20, 10, 551, 241));
        lineEdit = new QLineEdit(GuiClass);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(120, 270, 113, 21));
        lineEdit_2 = new QLineEdit(GuiClass);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(120, 300, 113, 21));
        label = new QLabel(GuiClass);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 270, 49, 16));
        label_2 = new QLabel(GuiClass);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 300, 71, 16));
        label_3 = new QLabel(GuiClass);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 360, 61, 16));
        pushButton = new QPushButton(GuiClass);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(250, 270, 75, 24));
        lineEdit_3 = new QLineEdit(GuiClass);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(120, 330, 113, 21));
        lineEdit_4 = new QLineEdit(GuiClass);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(120, 360, 113, 21));
        label_4 = new QLabel(GuiClass);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 330, 49, 16));
        spinBox = new QSpinBox(GuiClass);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(260, 320, 42, 22));
        checkBox = new QCheckBox(GuiClass);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(360, 270, 75, 20));

        retranslateUi(GuiClass);

        QMetaObject::connectSlotsByName(GuiClass);
    } // setupUi

    void retranslateUi(QWidget *GuiClass)
    {
        GuiClass->setWindowTitle(QCoreApplication::translate("GuiClass", "Gui", nullptr));
        label->setText(QCoreApplication::translate("GuiClass", "Name", nullptr));
        label_2->setText(QCoreApplication::translate("GuiClass", "RA", nullptr));
        label_3->setText(QCoreApplication::translate("GuiClass", "Diameter", nullptr));
        pushButton->setText(QCoreApplication::translate("GuiClass", "Add star", nullptr));
        label_4->setText(QCoreApplication::translate("GuiClass", "Dec", nullptr));
        checkBox->setText(QCoreApplication::translate("GuiClass", "CheckBox", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GuiClass: public Ui_GuiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
