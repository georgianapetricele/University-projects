/********************************************************************************
** Form generated from reading UI file 'Presenter.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRESENTER_H
#define UI_PRESENTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PresenterClass
{
public:
    QWidget *centralWidget;
    QListWidget *listWidget_questions;
    QLineEdit *lineEdit_id;
    QLineEdit *lineEdit_text;
    QLineEdit *lineEdit_answer;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_add;
    QLineEdit *lineEdit_score;
    QLabel *label_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PresenterClass)
    {
        if (PresenterClass->objectName().isEmpty())
            PresenterClass->setObjectName("PresenterClass");
        PresenterClass->resize(600, 400);
        centralWidget = new QWidget(PresenterClass);
        centralWidget->setObjectName("centralWidget");
        listWidget_questions = new QListWidget(centralWidget);
        listWidget_questions->setObjectName("listWidget_questions");
        listWidget_questions->setGeometry(QRect(10, 30, 256, 192));
        lineEdit_id = new QLineEdit(centralWidget);
        lineEdit_id->setObjectName("lineEdit_id");
        lineEdit_id->setGeometry(QRect(360, 50, 113, 21));
        lineEdit_text = new QLineEdit(centralWidget);
        lineEdit_text->setObjectName("lineEdit_text");
        lineEdit_text->setGeometry(QRect(360, 90, 113, 21));
        lineEdit_answer = new QLineEdit(centralWidget);
        lineEdit_answer->setObjectName("lineEdit_answer");
        lineEdit_answer->setGeometry(QRect(360, 130, 113, 21));
        label = new QLabel(centralWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(290, 50, 49, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(290, 100, 49, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(280, 130, 81, 16));
        pushButton_add = new QPushButton(centralWidget);
        pushButton_add->setObjectName("pushButton_add");
        pushButton_add->setGeometry(QRect(280, 190, 75, 24));
        lineEdit_score = new QLineEdit(centralWidget);
        lineEdit_score->setObjectName("lineEdit_score");
        lineEdit_score->setGeometry(QRect(370, 160, 113, 21));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(290, 160, 49, 16));
        PresenterClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PresenterClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 600, 22));
        PresenterClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PresenterClass);
        mainToolBar->setObjectName("mainToolBar");
        PresenterClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(PresenterClass);
        statusBar->setObjectName("statusBar");
        PresenterClass->setStatusBar(statusBar);

        retranslateUi(PresenterClass);

        QMetaObject::connectSlotsByName(PresenterClass);
    } // setupUi

    void retranslateUi(QMainWindow *PresenterClass)
    {
        PresenterClass->setWindowTitle(QCoreApplication::translate("PresenterClass", "Presenter", nullptr));
        label->setText(QCoreApplication::translate("PresenterClass", "Id", nullptr));
        label_2->setText(QCoreApplication::translate("PresenterClass", "Text", nullptr));
        label_3->setText(QCoreApplication::translate("PresenterClass", "Correct answer", nullptr));
        pushButton_add->setText(QCoreApplication::translate("PresenterClass", "Add", nullptr));
        label_4->setText(QCoreApplication::translate("PresenterClass", "Score", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PresenterClass: public Ui_PresenterClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRESENTER_H
