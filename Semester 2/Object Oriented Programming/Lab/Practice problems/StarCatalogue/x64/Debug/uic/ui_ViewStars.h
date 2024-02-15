/********************************************************************************
** Form generated from reading UI file 'ViewStars.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWSTARS_H
#define UI_VIEWSTARS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewStarsClass
{
public:

    void setupUi(QWidget *ViewStarsClass)
    {
        if (ViewStarsClass->objectName().isEmpty())
            ViewStarsClass->setObjectName("ViewStarsClass");
        ViewStarsClass->resize(600, 400);

        retranslateUi(ViewStarsClass);

        QMetaObject::connectSlotsByName(ViewStarsClass);
    } // setupUi

    void retranslateUi(QWidget *ViewStarsClass)
    {
        ViewStarsClass->setWindowTitle(QCoreApplication::translate("ViewStarsClass", "ViewStars", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ViewStarsClass: public Ui_ViewStarsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWSTARS_H
