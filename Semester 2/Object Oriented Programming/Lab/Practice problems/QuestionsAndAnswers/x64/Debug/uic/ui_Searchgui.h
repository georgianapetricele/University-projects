/********************************************************************************
** Form generated from reading UI file 'Searchgui.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHGUI_H
#define UI_SEARCHGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchguiClass
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QListWidget *listWidget;
    QLabel *label_3;

    void setupUi(QWidget *SearchguiClass)
    {
        if (SearchguiClass->objectName().isEmpty())
            SearchguiClass->setObjectName("SearchguiClass");
        SearchguiClass->resize(600, 400);
        label = new QLabel(SearchguiClass);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 40, 49, 16));
        lineEdit = new QLineEdit(SearchguiClass);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(150, 40, 171, 21));
        lineEdit_2 = new QLineEdit(SearchguiClass);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(150, 80, 113, 21));
        label_2 = new QLabel(SearchguiClass);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 80, 81, 16));
        listWidget = new QListWidget(SearchguiClass);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(40, 130, 256, 192));
        label_3 = new QLabel(SearchguiClass);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 110, 91, 16));

        retranslateUi(SearchguiClass);

        QMetaObject::connectSlotsByName(SearchguiClass);
    } // setupUi

    void retranslateUi(QWidget *SearchguiClass)
    {
        SearchguiClass->setWindowTitle(QCoreApplication::translate("SearchguiClass", "Searchgui", nullptr));
        label->setText(QCoreApplication::translate("SearchguiClass", "Search q", nullptr));
        label_2->setText(QCoreApplication::translate("SearchguiClass", "Best match", nullptr));
        label_3->setText(QCoreApplication::translate("SearchguiClass", "Top 3 answers", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchguiClass: public Ui_SearchguiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHGUI_H
