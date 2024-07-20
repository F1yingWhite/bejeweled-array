/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QGraphicsView *graphicsView;
    QPushButton *start;
    QPushButton *pushButton_2;
    QGraphicsView *graphicsView_2;
    QLineEdit *lineEdit_Ip;
    QPushButton *pushButton_Listen;
    QLabel *label;
    QLCDNumber *ziji;
    QLCDNumber *timer;
    QLCDNumber *ziji_2;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(1486, 858);
        Form->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"background-color: rgb(255, 252, 247);\n"
"color: black; /*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"}\n"
"\n"
"/*\346\214\211\351\222\256\346\255\243\345\270\270\347\212\266\346\200\201*/\n"
"QPushButton\n"
"{\n"
"background-color:rgba(198,198,198,0.6);/*\350\203\214\346\231\257\350\211\262*/\n"
"\n"
"border-style:solid;\n"
"border-width:4px;\n"
"border-radius:10px;/*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\345\203\217\347\264\240*/\n"
"border-color:rgba(205,205,205,0.8);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"\n"
"padding:6px; /*\345\241\253\350\241\254*/\n"
"}\n"
"/*\351\274\240\346\240\207\346\214\211\344\270\213\347\212\266\346\200\201*/\n"
"QPushButton:pressed\n"
"{\n"
"background-color:rgba(198,198,220,06);/*\350\203\214\346\231\257\350\211\262*/\n"
"border-color:rgba(205,205,205,1);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"border-style:solid;/*\350\276\271\346\241\206\346\240\267\345\274\217 solid\345\256\236\347"
                        "\272\277 none\346\227\240\350\276\271\346\241\206 inset/outset 3D\350\276\271\346\241\206*/\n"
"color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"}\n"
"/*\351\274\240\346\240\207\346\202\254\345\201\234\347\212\266\346\200\201*/\n"
"QPushButton:hover\n"
"{\n"
"background-color:rgba(198,198,190,0.7);/*\350\203\214\346\231\257\350\211\262*/\n"
"border-color:rgba(205,205,205,0.9);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"}\n"
"QLineEdit\n"
"{\n"
"background-color:rgb(240,240,240);/*\350\203\214\346\231\257\350\211\262*/\n"
"min-height:30px; /*\346\234\200\345\260\217\351\253\230\345\272\246*/\n"
"min-width:180px; /*\346\234\200\345\260\217\345\256\275\345\272\246*/\n"
"border-style:solid;/*\350\276\271\346\241\206\346\240\267\345\274\217 solid\345\256\236\347\272\277 none\346\227\240\350\276\271\346\241\206 inset/outset 3D\350\276\271\346\241\206*/\n"
"border-width:4px; /*\350\276\271\346\241\206\345\256\275\345"
                        "\272\246\345\203\217\347\264\240*/\n"
"border-radius:10px;/*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\345\203\217\347\264\240*/\n"
"border-color:rgba(205,205,205,0.4);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"font-size:10pt;/*\345\255\227\344\275\223 \345\255\227\344\275\223\345\244\247\345\260\217*/\n"
"color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"padding:6px;/*\345\241\253\350\241\254*/\n"
"}\n"
"QCheckBox\n"
"{\n"
"color:black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"background-color:rgb(240,240,240);/*\350\203\214\346\231\257\350\211\262*/\n"
"}\n"
"QComboBox\n"
"{\n"
"background-color:rgb(240,240,240);\n"
"color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"border-style:solid;/*\350\276\271\346\241\206\346\240\267\345\274\217 solid\345\256\236\347\272\277 none\346\227\240\350\276\271\346\241\206 inset/outset 3D\350\276\271\346\241\206*/\n"
"border-width:4px;/*\350\276\271\346\241\206\345\256\275\345\272"
                        "\246\345\203\217\347\264\240*/\n"
"border-radius:10px;/*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\345\203\217\347\264\240*/\n"
"border-color:rgba(205,205,205);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"min-height:35px; /*\346\234\200\345\260\217\351\253\230\345\272\246*/\n"
"font-size:10pt;\n"
"}\n"
"/*\345\220\221\344\270\213\347\232\204\344\270\211\350\247\222\345\275\242\347\256\255\345\244\264\346\240\267\345\274\217*/\n"
"QComboBox::drop-down\n"
"{\n"
"width:20px;\n"
"border:none;\n"
"background:transparent;\n"
"}\n"
"/*\345\220\221\344\270\213\347\232\204\344\270\211\350\247\222\345\275\242\347\256\255\345\244\264*/\n"
"QComboBox::down-arrow\n"
"{\n"
"image:url(:/image/array_down.png);\n"
"}\n"
"/*\344\270\213\346\213\211\345\220\216\347\232\204\346\225\264\344\270\252\344\270\213\346\213\211\347\252\227\344\275\223*/\n"
"QComboBox QAbstractItemView\n"
"{\n"
"background-color: rgb(240,240,240); /*\350\203\214\346\231\257\350\211\262*/\n"
"color: black;/*\345\255"
                        "\227\344\275\223\351\242\234\350\211\262*/\n"
"outline:none;\n"
"}\n"
"/*\344\270\213\346\213\211\346\241\206\344\270\213\351\235\242\347\232\204item*/\n"
"QComboBox QAbstractItemView::item\n"
"{\n"
"height:30px;\n"
"color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"}\n"
"/*\344\270\213\346\213\211\346\241\206item\351\200\211\344\270\255*/\n"
"QComboBox QAbstractItemView::item:selected\n"
"{\n"
"background-color: rgb(240,240,240); /*\350\203\214\346\231\257\350\211\262*/\n"
"color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"}\n"
"QTabWidget\n"
"{\n"
"background-color: rgb(240,240,240); /*\350\203\214\346\231\257\350\211\262*/\n"
"color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"}\n"
"QTabBar::tab\n"
"{\n"
"background-color: rgb(240,240,240); /*\350\203\214\346\231\257\350\211\262*/\n"
"color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"font-size:10pt;/*\345\255\227\344\275\223\345\244\247\345\260\217*/\n"
"height:30px; /*\351\253\230"
                        "\345\272\246*/\n"
"min-width:100px;/*\345\256\275\345\272\246*/\n"
"border-top-left-radius:4px;/*\345\267\246\344\270\212\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\345\203\217\347\264\240*/\n"
"border-top-right-radius:4px;/*\345\217\263\344\270\212\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\345\203\217\347\264\240*/\n"
"margin-right: 5px;/*\345\217\263\350\276\271\350\267\235 \345\217\263\345\244\226\350\276\271\350\267\235*/\n"
"padding-left:5px;/*\345\267\246\345\241\253\345\205\205--\345\267\246\345\206\205\350\276\271\350\267\235*/\n"
"padding-right:5px;/*\345\217\263\345\241\253\345\205\205--\345\217\263\345\206\205\350\276\271\350\267\235*/\n"
"}\n"
"QTabBar::tab:hover\n"
"{\n"
"background-color: rgb(198,198,208); /*\350\203\214\346\231\257\350\211\262*/\n"
"}\n"
"QTabBar::tab:selected\n"
"{\n"
"background-color: rgb(198,198,198); /*\350\203\214\346\231\257\350\211\262*/\n"
"}\n"
"QTableView,QTableWidget{\n"
"background-color: rgb(240,240,240); /"
                        "*\350\203\214\346\231\257\350\211\262*/\n"
"color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"selection-background-color:rgba(192,221,244);/*\350\203\214\346\231\257\350\211\262*/;/*\347\202\271\345\207\273\351\200\211\344\270\255\351\242\234\350\211\262*/\n"
"border:1px solid #E0DDDC;/*\350\276\271\346\241\206\344\270\2721\345\203\217\347\264\240\357\274\214\347\201\260\350\211\262*/\n"
"gridline-color:lightgray;/*\350\277\231\344\270\252\346\230\257\350\241\250\346\240\274\347\232\204\346\240\274\345\255\220\347\272\277\347\232\204\351\242\234\350\211\262\357\274\214\344\270\272\344\272\256\347\201\260*/\n"
"font:bold 10pt;/*\345\255\227\344\275\223 \345\255\227\344\275\223\345\244\247\345\260\217*/\n"
"}\n"
"/*\350\241\250\346\240\274\350\241\250\345\244\264\346\240\267\345\274\217*/\n"
"QHeaderView::section{\n"
"background-color:rgb(240,240,240); /*\350\203\214\346\231\257\350\211\262*/\n"
"border:0px solid #E0DDDC;/*\345\205\210\346\212\212\350\276\271\346\241\206\345\256\275\345\272\246"
                        "\350\256\276\344\270\2720\357\274\214\345\215\263\351\232\220\350\227\217\346\211\200\346\234\211\350\241\250\345\244\264\350\276\271\346\241\206*/\n"
"border-bottom:1px solid #E0DDDC;/*\347\204\266\345\220\216\345\217\252\346\230\276\347\244\272\344\270\213\350\276\271\346\241\206\357\274\214\345\233\240\344\270\272\344\270\212\350\276\271\346\241\206\345\222\214\345\267\246\345\217\263\350\276\271\346\241\206\346\230\257\346\225\264\344\270\252Table\347\232\204\350\276\271\346\241\206\357\274\214\351\203\275\346\230\276\347\244\272\344\274\232\346\234\2112px\347\232\204\350\276\271\346\241\206\345\256\275\345\272\246*/\n"
"min-height:30px;;/*\350\241\250\345\244\264\351\253\230\345\272\246*/\n"
"font-size:10pt;/*\345\255\227\344\275\223\345\244\247\345\260\217*/\n"
"}\n"
"QTreeWidget,QTreeView\n"
"{\n"
"background-color: rgb(240,240,240); /*\350\203\214\346\231\257\350\211\262*/\n"
"color: rgb(79,129,168);/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"selection-background-color:rgba(5,23,200);/*\347"
                        "\202\271\345\207\273\351\200\211\344\270\255\351\242\234\350\211\262*/\n"
"font-size:10pt;/*\345\255\227\344\275\223\345\244\247\345\260\217*/\n"
"}\n"
"/*\346\224\266\350\265\267\347\212\266\346\200\201*/\n"
"QTreeWidget::branch:has-children:!has-siblings:closed,\n"
"QTreeWidget::branch:closed:has-children:has-siblings {\n"
"border-image: none;\n"
"image: url(:/image/add-line_horizontal.png);\n"
"}\n"
"/*\345\261\225\345\274\200\347\212\266\346\200\201*/\n"
"QTreeWidget::branch:open:has-children:!has-siblings,\n"
"QTreeWidget::branch:open:has-children:has-siblings {\n"
"border-image: none;\n"
"image: url(:/image/array_down.png);\n"
"}\n"
"/*\346\224\266\350\265\267\347\212\266\346\200\201*/\n"
"QTreeView::branch:has-children:!has-siblings:closed,\n"
"QTreeView::branch:closed:has-children:has-siblings {\n"
"border-image: none;\n"
"image: url(:/image/add-line_horizontal.png);\n"
"}\n"
"/*\345\261\225\345\274\200\347\212\266\346\200\201*/\n"
"QTreeView::branch:open:has-children:!has-siblings,\n"
"QTreeView::bran"
                        "ch:open:has-children:has-siblings {\n"
"border-image: none;\n"
"image: url(:/image/array_down.png);\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
""));
        graphicsView = new QGraphicsView(Form);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 160, 851, 631));
        graphicsView->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/media/media/board.png);"));
        start = new QPushButton(Form);
        start->setObjectName(QString::fromUtf8("start"));
        start->setGeometry(QRect(50, 260, 131, 41));
        pushButton_2 = new QPushButton(Form);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(50, 340, 131, 41));
        graphicsView_2 = new QGraphicsView(Form);
        graphicsView_2->setObjectName(QString::fromUtf8("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(840, 160, 651, 631));
        graphicsView_2->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/media/media/board2.png);"));
        lineEdit_Ip = new QLineEdit(Form);
        lineEdit_Ip->setObjectName(QString::fromUtf8("lineEdit_Ip"));
        lineEdit_Ip->setGeometry(QRect(30, 550, 200, 50));
        pushButton_Listen = new QPushButton(Form);
        pushButton_Listen->setObjectName(QString::fromUtf8("pushButton_Listen"));
        pushButton_Listen->setGeometry(QRect(30, 620, 151, 81));
        label = new QLabel(Form);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(-20, 0, 1611, 161));
        label->setAutoFillBackground(false);
        label->setStyleSheet(QString::fromUtf8("\n"
"border-image: url(:/new/prefix1/media/media/pk.jpeg);"));
        ziji = new QLCDNumber(Form);
        ziji->setObjectName(QString::fromUtf8("ziji"));
        ziji->setGeometry(QRect(23, 52, 201, 101));
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(7);
        font.setBold(false);
        font.setItalic(false);
        ziji->setFont(font);
        ziji->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/media/media/timeBackground.png);\n"
"font: 7pt \"Agency FB\";\n"
"color: rgb(255, 0, 0);"));
        timer = new QLCDNumber(Form);
        timer->setObjectName(QString::fromUtf8("timer"));
        timer->setGeometry(QRect(690, 110, 141, 51));
        timer->setFocusPolicy(Qt::NoFocus);
        timer->setLayoutDirection(Qt::RightToLeft);
        timer->setAutoFillBackground(false);
        timer->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"font: 14pt \"Agency FB\";\n"
"color: rgb(255, 249, 233);\n"
""));
        ziji_2 = new QLCDNumber(Form);
        ziji_2->setObjectName(QString::fromUtf8("ziji_2"));
        ziji_2->setGeometry(QRect(1270, 60, 201, 101));
        ziji_2->setFont(font);
        ziji_2->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/media/media/timeBackground.png);\n"
"font: 7pt \"Agency FB\";\n"
"color: rgb(255, 0, 0);"));
        label->raise();
        graphicsView->raise();
        start->raise();
        pushButton_2->raise();
        graphicsView_2->raise();
        lineEdit_Ip->raise();
        pushButton_Listen->raise();
        ziji->raise();
        timer->raise();
        ziji_2->raise();

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        start->setText(QCoreApplication::translate("Form", "\345\274\200\345\247\213", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Form", "\345\210\267\346\226\260", nullptr));
        pushButton_Listen->setText(QCoreApplication::translate("Form", "OpenServer", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
