/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *calculatePushButton;
    QTextBrowser *textBrowser;
    QSpinBox *spinBoxN;
    QSpinBox *spinBoxG;
    QSpinBox *spinBoxP;
    QSpinBox *spinBoxE;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 60, 63, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 90, 63, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 120, 63, 20));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 150, 81, 20));
        calculatePushButton = new QPushButton(centralwidget);
        calculatePushButton->setObjectName(QString::fromUtf8("calculatePushButton"));
        calculatePushButton->setGeometry(QRect(30, 200, 84, 28));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(130, 180, 161, 71));
        spinBoxN = new QSpinBox(centralwidget);
        spinBoxN->setObjectName(QString::fromUtf8("spinBoxN"));
        spinBoxN->setGeometry(QRect(130, 50, 161, 29));
        spinBoxG = new QSpinBox(centralwidget);
        spinBoxG->setObjectName(QString::fromUtf8("spinBoxG"));
        spinBoxG->setGeometry(QRect(130, 80, 161, 29));
        spinBoxP = new QSpinBox(centralwidget);
        spinBoxP->setObjectName(QString::fromUtf8("spinBoxP"));
        spinBoxP->setGeometry(QRect(130, 110, 161, 29));
        spinBoxE = new QSpinBox(centralwidget);
        spinBoxE->setObjectName(QString::fromUtf8("spinBoxE"));
        spinBoxE->setGeometry(QRect(130, 140, 161, 29));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "N points:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "G points:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "P points:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Exam grade:", nullptr));
        calculatePushButton->setText(QCoreApplication::translate("MainWindow", "Calculate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
