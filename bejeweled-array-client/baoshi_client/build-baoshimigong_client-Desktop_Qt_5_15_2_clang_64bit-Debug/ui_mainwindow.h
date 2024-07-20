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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_3;
    QPushButton *login;
    QPushButton *zhuce;
    QTextEdit *textEdit;
    QLabel *label_2;
    QLineEdit *mima;
    QLineEdit *zhanghao;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 543);
        MainWindow->setStyleSheet(QString::fromUtf8("\n"
"background:rgb(255, 255, 255);\n"
"font-size:18px;\n"
"font-style:MingLiU-ExtB;\n"
"\n"
"\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(-10, 0, 811, 501));
        label_3->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/media/media/stateMainMenu/OIP.jpg);"));
        login = new QPushButton(centralwidget);
        login->setObjectName(QString::fromUtf8("login"));
        login->setGeometry(QRect(460, 430, 171, 41));
        login->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background:#ced1d8;\n"
"border-style:outset;\n"
"border-radius:10px;\n"
"font-style:MingLiU-ExtB;\n"
"}\n"
"QPushButton:pressed{\n"
"background-color:rgb(224,0,0);\n"
"border-style:inset;\n"
"font-style:MingLiU-ExtB;\n"
"}"));
        zhuce = new QPushButton(centralwidget);
        zhuce->setObjectName(QString::fromUtf8("zhuce"));
        zhuce->setGeometry(QRect(150, 430, 181, 41));
        zhuce->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"background:#ced1d8;\n"
"border-style:outset;\n"
"border-radius:10px;\n"
"font-style:MingLiU-ExtB;\n"
"}\n"
"QPushButton:pressed{\n"
"background-color:rgb(224,0,0);\n"
"border-style:inset;\n"
"font-style:MingLiU-ExtB;\n"
"}\n"
"\n"
""));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(230, 290, 331, 121));
        textEdit->setStyleSheet(QString::fromUtf8("background-color :rgba(97, 114, 136,140);\n"
"font-size:16px;\n"
"border-style:outset;\n"
"border-radius:10px;\n"
"font-style:MingLiU-ExtB;"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(190, 190, 61, 61));
        label_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"background:rgba(85,170,255,0);\n"
"color:white;\n"
"font-style:MingLiU-ExtB;\n"
"font-size:20px;\n"
"}"));
        mima = new QLineEdit(centralwidget);
        mima->setObjectName(QString::fromUtf8("mima"));
        mima->setGeometry(QRect(290, 190, 251, 51));
        mima->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"color:#8d98a1;\n"
"background-color :rgba(97, 114, 136,140);\n"
"font-size:16px;\n"
"border-style:outset;\n"
"border-radius:10px;\n"
"font-style:MingLiU-ExtB;\n"
"}"));
        zhanghao = new QLineEdit(centralwidget);
        zhanghao->setObjectName(QString::fromUtf8("zhanghao"));
        zhanghao->setGeometry(QRect(290, 100, 251, 51));
        zhanghao->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"color:#8d98a1;\n"
"background-color :rgba(97, 114, 136,140);\n"
"font-size:16px;\n"
"border-style:outset;\n"
"border-radius:10px;\n"
"font-style:MingLiU-ExtB;\n"
"}"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(190, 80, 51, 81));
        QFont font;
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"background:rgba(85,170,255,0);\n"
"color:white;\n"
"font-style:MingLiU-ExtB;\n"
"font-size:20px;\n"
"}"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 29));
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
        label_3->setText(QString());
        login->setText(QCoreApplication::translate("MainWindow", "\347\231\273\345\275\225", nullptr));
        zhuce->setText(QCoreApplication::translate("MainWindow", "\346\263\250\345\206\214", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\345\257\206\347\240\201", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\350\264\246\345\217\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
