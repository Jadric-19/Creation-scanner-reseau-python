/********************************************************************************
** Form generated from reading UI file 'Mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTextBrowser *textBrowser;
    QTextBrowser *textBrowser_2;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLineEdit *lineIp1;
    QLabel *label;
    QPushButton *btnScan1;
    QLabel *label_2;
    QTextBrowser *textHost1;
    QLabel *label_11;
    QPushButton *next1;
    QWidget *page_2;
    QTextBrowser *textHost2;
    QLineEdit *lineIp2;
    QLabel *label_4;
    QPushButton *btnScan2;
    QLabel *label_5;
    QLabel *label_24;
    QPushButton *next2;
    QWidget *page_3;
    QTextBrowser *textHost3;
    QLineEdit *lineIp3;
    QLabel *label_6;
    QPushButton *btnScan3;
    QLabel *label_7;
    QLabel *label_12;
    QPushButton *next3;
    QWidget *page_4;
    QTextBrowser *textHost4;
    QLineEdit *lineIp4;
    QLabel *label_8;
    QPushButton *btnScan4;
    QLabel *label_9;
    QLabel *label_10;
    QPushButton *next4;
    QLabel *label_3;
    QTextBrowser *textResult;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1058, 704);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(49, 28, 971, 601));
        textBrowser->setStyleSheet(QString::fromUtf8("background-color: #121214;\n"
"    color: #ffffff;\n"
"    border: 1px solid #3f3f46;\n"
"    border-radius: 4px;\n"
"    padding: 4px;"));
        textBrowser_2 = new QTextBrowser(centralwidget);
        textBrowser_2->setObjectName("textBrowser_2");
        textBrowser_2->setGeometry(QRect(410, 39, 601, 561));
        textBrowser_2->setStyleSheet(QString::fromUtf8("background-color: #3f3f46;\n"
"    border-color: #007acc;\n"
"\n"
"background-color: #2a2a32;\n"
"    color: #ffffff;\n"
"    border: 1px solid #3f3f46;\n"
"    border-radius: 4px;\n"
"    padding: 6px 12px;"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(50, 39, 361, 561));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: #2a2a32;\n"
"    color: #ffffff;\n"
"    border: 1px solid #3f3f46;\n"
"    border-radius: 4px;\n"
"    padding: 6px 12px;"));
        page = new QWidget();
        page->setObjectName("page");
        lineIp1 = new QLineEdit(page);
        lineIp1->setObjectName("lineIp1");
        lineIp1->setGeometry(QRect(100, 65, 211, 27));
        label = new QLabel(page);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 63, 81, 31));
        btnScan1 = new QPushButton(page);
        btnScan1->setObjectName("btnScan1");
        btnScan1->setGeometry(QRect(100, 117, 106, 27));
        label_2 = new QLabel(page);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 236, 151, 41));
        textHost1 = new QTextBrowser(page);
        textHost1->setObjectName("textHost1");
        textHost1->setGeometry(QRect(10, 287, 311, 251));
        label_11 = new QLabel(page);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(10, 23, 211, 31));
        next1 = new QPushButton(page);
        next1->setObjectName("next1");
        next1->setGeometry(QRect(101, 170, 181, 27));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        textHost2 = new QTextBrowser(page_2);
        textHost2->setObjectName("textHost2");
        textHost2->setGeometry(QRect(10, 291, 311, 251));
        lineIp2 = new QLineEdit(page_2);
        lineIp2->setObjectName("lineIp2");
        lineIp2->setGeometry(QRect(105, 60, 211, 27));
        label_4 = new QLabel(page_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 240, 151, 41));
        btnScan2 = new QPushButton(page_2);
        btnScan2->setObjectName("btnScan2");
        btnScan2->setGeometry(QRect(107, 110, 106, 27));
        label_5 = new QLabel(page_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(15, 60, 81, 31));
        label_24 = new QLabel(page_2);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(13, 20, 211, 31));
        next2 = new QPushButton(page_2);
        next2->setObjectName("next2");
        next2->setGeometry(QRect(110, 170, 181, 27));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        textHost3 = new QTextBrowser(page_3);
        textHost3->setObjectName("textHost3");
        textHost3->setGeometry(QRect(20, 291, 311, 251));
        lineIp3 = new QLineEdit(page_3);
        lineIp3->setObjectName("lineIp3");
        lineIp3->setGeometry(QRect(100, 60, 211, 27));
        label_6 = new QLabel(page_3);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 240, 151, 41));
        btnScan3 = new QPushButton(page_3);
        btnScan3->setObjectName("btnScan3");
        btnScan3->setGeometry(QRect(100, 110, 106, 27));
        label_7 = new QLabel(page_3);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 60, 81, 31));
        label_12 = new QLabel(page_3);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(10, 20, 211, 31));
        next3 = new QPushButton(page_3);
        next3->setObjectName("next3");
        next3->setGeometry(QRect(100, 170, 181, 27));
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        textHost4 = new QTextBrowser(page_4);
        textHost4->setObjectName("textHost4");
        textHost4->setGeometry(QRect(10, 291, 311, 251));
        lineIp4 = new QLineEdit(page_4);
        lineIp4->setObjectName("lineIp4");
        lineIp4->setGeometry(QRect(100, 60, 211, 27));
        label_8 = new QLabel(page_4);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 240, 151, 41));
        btnScan4 = new QPushButton(page_4);
        btnScan4->setObjectName("btnScan4");
        btnScan4->setGeometry(QRect(103, 110, 106, 27));
        label_9 = new QLabel(page_4);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 60, 81, 31));
        label_10 = new QLabel(page_4);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(10, 20, 211, 31));
        next4 = new QPushButton(page_4);
        next4->setObjectName("next4");
        next4->setGeometry(QRect(100, 170, 181, 27));
        stackedWidget->addWidget(page_4);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(420, 49, 581, 51));
        label_3->setStyleSheet(QString::fromUtf8("background-color: #121214;\n"
"    color: #ffffff;\n"
"    border: 1px solid #3f3f46;\n"
"    border-radius: 4px;\n"
"    padding: 4px;\n"
""));
        textResult = new QTextBrowser(centralwidget);
        textResult->setObjectName("textResult");
        textResult->setGeometry(QRect(440, 120, 541, 461));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1058, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Taget :", nullptr));
        btnScan1->setText(QCoreApplication::translate("MainWindow", "scan", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Hotes scanner :", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Host Discovery", nullptr));
        next1->setText(QCoreApplication::translate("MainWindow", "Autre scan >", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Hotes scanner :", nullptr));
        btnScan2->setText(QCoreApplication::translate("MainWindow", "scan", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Taget :", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "Services Scan", nullptr));
        next2->setText(QCoreApplication::translate("MainWindow", "Autre scan >", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Hotes scanner :", nullptr));
        btnScan3->setText(QCoreApplication::translate("MainWindow", "scan", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Taget :", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "OS Detection", nullptr));
        next3->setText(QCoreApplication::translate("MainWindow", "Autre scan >", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Hotes scanner :", nullptr));
        btnScan4->setText(QCoreApplication::translate("MainWindow", "scan", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Taget :", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "SYN Scan", nullptr));
        next4->setText(QCoreApplication::translate("MainWindow", "Autre scan >", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "                                        RESULTAT ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
