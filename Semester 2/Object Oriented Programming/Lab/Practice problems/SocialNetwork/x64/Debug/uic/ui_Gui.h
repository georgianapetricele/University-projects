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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GuiClass
{
public:
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget_feed;
    QListWidget *listWidget_posts;
    QListWidget *listWidget_subscription;

    void setupUi(QWidget *GuiClass)
    {
        if (GuiClass->objectName().isEmpty())
            GuiClass->setObjectName("GuiClass");
        GuiClass->resize(855, 400);
        lineEdit = new QLineEdit(GuiClass);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(110, 230, 113, 21));
        lineEdit_3 = new QLineEdit(GuiClass);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(280, 230, 113, 21));
        lineEdit_4 = new QLineEdit(GuiClass);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(280, 260, 113, 21));
        lineEdit_5 = new QLineEdit(GuiClass);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(280, 290, 113, 21));
        lineEdit_6 = new QLineEdit(GuiClass);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(410, 230, 113, 21));
        lineEdit_7 = new QLineEdit(GuiClass);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(410, 260, 113, 21));
        label = new QLabel(GuiClass);
        label->setObjectName("label");
        label->setGeometry(QRect(230, 230, 49, 16));
        label_2 = new QLabel(GuiClass);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(230, 260, 49, 16));
        label_3 = new QLabel(GuiClass);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(230, 290, 49, 16));
        label_4 = new QLabel(GuiClass);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(60, 230, 49, 16));
        label_5 = new QLabel(GuiClass);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(530, 230, 49, 16));
        label_6 = new QLabel(GuiClass);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(530, 260, 49, 16));
        pushButton = new QPushButton(GuiClass);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(110, 260, 75, 24));
        widget = new QWidget(GuiClass);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(20, 20, 782, 194));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        listWidget_feed = new QListWidget(widget);
        listWidget_feed->setObjectName("listWidget_feed");

        horizontalLayout->addWidget(listWidget_feed);

        listWidget_posts = new QListWidget(widget);
        listWidget_posts->setObjectName("listWidget_posts");

        horizontalLayout->addWidget(listWidget_posts);

        listWidget_subscription = new QListWidget(widget);
        listWidget_subscription->setObjectName("listWidget_subscription");

        horizontalLayout->addWidget(listWidget_subscription);


        retranslateUi(GuiClass);

        QMetaObject::connectSlotsByName(GuiClass);
    } // setupUi

    void retranslateUi(QWidget *GuiClass)
    {
        GuiClass->setWindowTitle(QCoreApplication::translate("GuiClass", "Gui", nullptr));
        label->setText(QCoreApplication::translate("GuiClass", "Year", nullptr));
        label_2->setText(QCoreApplication::translate("GuiClass", "Month", nullptr));
        label_3->setText(QCoreApplication::translate("GuiClass", "Day", nullptr));
        label_4->setText(QCoreApplication::translate("GuiClass", "Text", nullptr));
        label_5->setText(QCoreApplication::translate("GuiClass", "Hour", nullptr));
        label_6->setText(QCoreApplication::translate("GuiClass", "Minutes", nullptr));
        pushButton->setText(QCoreApplication::translate("GuiClass", "Add post", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GuiClass: public Ui_GuiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
