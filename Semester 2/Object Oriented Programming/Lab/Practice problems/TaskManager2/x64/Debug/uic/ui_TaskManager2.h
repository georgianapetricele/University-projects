/********************************************************************************
** Form generated from reading UI file 'TaskManager2.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKMANAGER2_H
#define UI_TASKMANAGER2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskManager2Class
{
public:
    QListWidget *list_tasks;
    QLabel *label;
    QLineEdit *line_description;
    QLineEdit *line_id;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *button_add;
    QPushButton *button_remove;
    QPushButton *button_start;
    QPushButton *button_done;

    void setupUi(QWidget *TaskManager2Class)
    {
        if (TaskManager2Class->objectName().isEmpty())
            TaskManager2Class->setObjectName("TaskManager2Class");
        TaskManager2Class->resize(600, 400);
        list_tasks = new QListWidget(TaskManager2Class);
        list_tasks->setObjectName("list_tasks");
        list_tasks->setGeometry(QRect(30, 40, 256, 192));
        label = new QLabel(TaskManager2Class);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 10, 49, 16));
        line_description = new QLineEdit(TaskManager2Class);
        line_description->setObjectName("line_description");
        line_description->setGeometry(QRect(380, 50, 113, 21));
        line_id = new QLineEdit(TaskManager2Class);
        line_id->setObjectName("line_id");
        line_id->setGeometry(QRect(380, 90, 113, 21));
        label_2 = new QLabel(TaskManager2Class);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(290, 50, 71, 16));
        label_3 = new QLabel(TaskManager2Class);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(290, 90, 101, 16));
        button_add = new QPushButton(TaskManager2Class);
        button_add->setObjectName("button_add");
        button_add->setGeometry(QRect(300, 130, 75, 24));
        button_remove = new QPushButton(TaskManager2Class);
        button_remove->setObjectName("button_remove");
        button_remove->setGeometry(QRect(410, 130, 75, 24));
        button_start = new QPushButton(TaskManager2Class);
        button_start->setObjectName("button_start");
        button_start->setGeometry(QRect(300, 180, 75, 24));
        button_done = new QPushButton(TaskManager2Class);
        button_done->setObjectName("button_done");
        button_done->setGeometry(QRect(410, 180, 75, 24));

        retranslateUi(TaskManager2Class);

        QMetaObject::connectSlotsByName(TaskManager2Class);
    } // setupUi

    void retranslateUi(QWidget *TaskManager2Class)
    {
        TaskManager2Class->setWindowTitle(QCoreApplication::translate("TaskManager2Class", "TaskManager2", nullptr));
        label->setText(QCoreApplication::translate("TaskManager2Class", "Tasks", nullptr));
        label_2->setText(QCoreApplication::translate("TaskManager2Class", "Description", nullptr));
        label_3->setText(QCoreApplication::translate("TaskManager2Class", "Programmer's id", nullptr));
        button_add->setText(QCoreApplication::translate("TaskManager2Class", "ADD", nullptr));
        button_remove->setText(QCoreApplication::translate("TaskManager2Class", "REMOVE", nullptr));
        button_start->setText(QCoreApplication::translate("TaskManager2Class", "START", nullptr));
        button_done->setText(QCoreApplication::translate("TaskManager2Class", "DONE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TaskManager2Class: public Ui_TaskManager2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKMANAGER2_H
