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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GuiClass
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *GuiClass)
    {
        if (GuiClass->objectName().isEmpty())
            GuiClass->setObjectName("GuiClass");
        GuiClass->resize(600, 400);
        horizontalLayout_2 = new QHBoxLayout(GuiClass);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName("verticalLayout_2");
        tableView = new QTableView(GuiClass);
        tableView->setObjectName("tableView");

        verticalLayout_2->addWidget(tableView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName("formLayout");
        label = new QLabel(GuiClass);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit = new QLineEdit(GuiClass);
        lineEdit->setObjectName("lineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        label_2 = new QLabel(GuiClass);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        lineEdit_2 = new QLineEdit(GuiClass);
        lineEdit_2->setObjectName("lineEdit_2");

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_2);


        horizontalLayout->addLayout(formLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        pushButton = new QPushButton(GuiClass);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(GuiClass);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout->addWidget(pushButton_2);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout_2);


        retranslateUi(GuiClass);

        QMetaObject::connectSlotsByName(GuiClass);
    } // setupUi

    void retranslateUi(QWidget *GuiClass)
    {
        GuiClass->setWindowTitle(QCoreApplication::translate("GuiClass", "Gui", nullptr));
        label->setText(QCoreApplication::translate("GuiClass", "Descrition", nullptr));
        label_2->setText(QCoreApplication::translate("GuiClass", "Act", nullptr));
        pushButton->setText(QCoreApplication::translate("GuiClass", "Add idea", nullptr));
        pushButton_2->setText(QCoreApplication::translate("GuiClass", "Save plot", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GuiClass: public Ui_GuiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
