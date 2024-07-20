/********************************************************************************
** Form generated from reading UI file 'port.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PORT_H
#define UI_PORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_port
{
public:
    QPushButton *start;
    QGraphicsView *graphicsView;
    QLabel *label;
    QPushButton *pushButton_2;
    QLCDNumber *ziji;
    QLCDNumber *timer;

    void setupUi(QWidget *port)
    {
        if (port->objectName().isEmpty())
            port->setObjectName(QString::fromUtf8("port"));
        port->resize(861, 801);
        start = new QPushButton(port);
        start->setObjectName(QString::fromUtf8("start"));
        start->setGeometry(QRect(80, 360, 81, 41));
        graphicsView = new QGraphicsView(port);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 170, 851, 631));
        graphicsView->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/media/media/board.png);"));
        label = new QLabel(port);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(-10, 10, 871, 161));
        label->setAutoFillBackground(false);
        label->setStyleSheet(QString::fromUtf8("\n"
"border-image: url(:/new/prefix1/media/media/pk3.jpeg);"));
        pushButton_2 = new QPushButton(port);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(80, 460, 81, 41));
        ziji = new QLCDNumber(port);
        ziji->setObjectName(QString::fromUtf8("ziji"));
        ziji->setGeometry(QRect(50, 250, 161, 81));
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(7);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        ziji->setFont(font);
        ziji->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/media/media/timeBackground.png);\n"
"font: 7pt \"Agency FB\";\n"
"color: rgb(255, 0, 0);"));
        timer = new QLCDNumber(port);
        timer->setObjectName(QString::fromUtf8("timer"));
        timer->setGeometry(QRect(50, 550, 141, 51));
        timer->setFocusPolicy(Qt::NoFocus);
        timer->setLayoutDirection(Qt::RightToLeft);
        timer->setAutoFillBackground(false);
        timer->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"font: 14pt \"Agency FB\";\n"
"color: rgb(255, 249, 233);\n"
""));
        graphicsView->raise();
        timer->raise();
        ziji->raise();
        start->raise();
        pushButton_2->raise();
        label->raise();

        retranslateUi(port);

        QMetaObject::connectSlotsByName(port);
    } // setupUi

    void retranslateUi(QWidget *port)
    {
        port->setWindowTitle(QCoreApplication::translate("port", "Form", nullptr));
        start->setText(QCoreApplication::translate("port", "\345\274\200\345\247\213", nullptr));
        label->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("port", "\345\210\267\346\226\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class port: public Ui_port {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PORT_H
